#include YSI\y_hooks

hook OnGameModeInit()
{
    mysql_query(IDConexao, "CREATE TABLE IF NOT EXISTS `Prison` (`responsible` varchar(24) NOT NULL, `chain` varchar(15) NOT NULL, `reason` varchar(30) NOT NULL, `time` int(10) NOT NULL, `id_contas` int NOT NULL, FOREIGN KEY (`id_contas`) REFERENCES `Contas`(`id`) ON DELETE CASCADE )", false);
	return 1;
}

hook OnPlayerConnect(playerid)
{
    PrisonEnum[playerid][pResponsavel] = 0;
    PrisonEnum[playerid][pTempo] = 0;
    PrisonEnum[playerid][pMotivo] = 0;
    PrisonEnum[playerid][pCadeia] = 0;
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    DBSavePrisons(playerid);
	return 1;
}

forward DB_LoadPrisons(playerid);
public DB_LoadPrisons(playerid)
{
    if(cache_num_rows() == 0)
        return SpawnHouse(playerid);

    new tmp[128];
    cache_get_value_name(0, "responsible", tmp); format(PrisonEnum[playerid][pResponsavel], MAX_PLAYER_NAME, tmp);
    cache_get_value_int(0, "time", PrisonEnum[playerid][pTempo]);
    cache_get_value_name(0, "reason", tmp); format(PrisonEnum[playerid][pMotivo], 20, tmp);
    cache_get_value_name(0, "chain", tmp); format(PrisonEnum[playerid][pCadeia], 15, tmp);

    GameTextForPlayer(playerid, "~w~~h~PRESO!", 2000, 0);
    SendClientMessage(playerid, 0x2894FFAA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Prisão ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    SendClientMessage(playerid, White, "•» Você está preso!");
    format(String, MAX_STRING, "•» Foi preso por ( %s )", PrisonEnum[playerid][pResponsavel]);
    SendClientMessage(playerid, White, String);
    format(String, MAX_STRING, "•» Motivo da prisão ( %s )", PrisonEnum[playerid][pMotivo]);
    SendClientMessage(playerid, White, String);
    SendClientMessage(playerid, 0x2894FFAA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Prisão ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    if(!strcmp(PrisonEnum[playerid][pCadeia], "Federal")){
        SetPlayerInterior(playerid, 10);
        SetSpawnInfo(playerid, 0, PlayerInfo[playerid][skin], 223.5335, 110.3779, 999.0156, 0, 0, 0, 0, 0, 0, 0);
    } else {
        SetPlayerInterior(playerid, 6);
        SetSpawnInfo(playerid, 0, PlayerInfo[playerid][skin], 264.2374, 77.4612, 1001.0391, 0, 0, 0, 0, 0, 0, 0);
    }

    ResetPlayerWeapons(playerid);
    SetPlayerHealth(playerid, 99999);

    PlayerTextDrawShow(playerid, TempoPresidio[playerid][1]);
    PlayerTextDrawShow(playerid, TempoPresidio[playerid][0]);

    PrisonSystem(playerid);
    TogglePlayerSpectating(playerid, false);
    return 1;
}

forward PrisonSystem(playerid);
public PrisonSystem(playerid)
{
    if(PrisonEnum[playerid][pTempo])
    {
        new hours, minutes, seconds;

        formatSeconds(PrisonEnum[playerid][pTempo], hours, minutes, seconds);
        format(String, 50,"%02d:%02d:%02d", hours, minutes, seconds);
        PlayerTextDrawSetString(playerid, TempoPresidio[playerid][2], String);
        PlayerTextDrawShow(playerid, TempoPresidio[playerid][2]);

        SetPlayerHealth(playerid, 99999);

        PrisonEnum[playerid][pTempo]--;

        new query[200];
        mysql_format(IDConexao, query, 200, "UPDATE `Prison` SET `time`='%d' WHERE `id_contas`='%d'", PrisonEnum[playerid][pTempo], PlayerInfo[playerid][ID]);
        mysql_query(IDConexao, query);

        return TempoPreso[playerid] = SetTimerEx("PrisonSystem", 1000, false, "i", playerid);
    }

    KillTimer(TempoPreso[playerid]);
    format(PrisonEnum[playerid][pMotivo], 1, "");
    PrisonEnum[playerid][pCadeia] = 0;
    PlayerInfo[playerid][Estrelas] = 0;
    UpdatePlayerStar(playerid);

    SetPlayerInterior(playerid, 0);
    SetPlayerHealth(playerid, 100);
    SetPlayerPos(playerid, 1551.6987, -1675.3806, 15.9631);

    PlayerTextDrawHide(playerid, TempoPresidio[playerid][2]);
    PlayerTextDrawHide(playerid, TempoPresidio[playerid][1]);
    PlayerTextDrawHide(playerid, TempoPresidio[playerid][0]);

    new query[200];
    mysql_format(IDConexao, query, 200, "DELETE FROM `Prison` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);

    GameTextForPlayer(playerid, "~w~SOLTO!", 3000, 0);
    SendClientMessage(playerid, 0xA9C4E4AA, "Você cumpriu sua pena e está livre novamente");
    return 1;
}

stock DBSavePrisons(playerid)
{
    if(PrisonEnum[playerid][pTempo] != 0)
    {
        KillTimer(TempoPreso[playerid]);

        new query[300];
        mysql_format(IDConexao, query, 300, "UPDATE `Prison` SET `responsible`='%e', `chain`='%e', `reason`='%e', `time`='%d' WHERE `id_contas`='%d'", PrisonEnum[playerid][pResponsavel], PrisonEnum[playerid][pCadeia], PrisonEnum[playerid][pMotivo], PrisonEnum[playerid][pTempo], PlayerInfo[playerid][ID]);
        mysql_query(IDConexao, query);
    }

    PrisonEnum[playerid][pTempo] = 0;
    PrisonEnum[playerid][pResponsavel] = 0;
    PrisonEnum[playerid][pMotivo] = 0;
    PrisonEnum[playerid][pCadeia] = 0;
    return 1;
}

stock IsPlayerArrested(playerid)
{
    if(PrisonEnum[playerid][pTempo] != 0) return true;
    return false;
}

stock SetPlayerPrision(accused[], responsible[], chain[], reason[], time, schedule = false)
{
    new playerid = GetPlayerID(accused), query[300];

    if((playerid == INVALID_PLAYER_ID || !PlayerInfo[playerid][Logado]) && schedule)
    {
        mysql_format(IDConexao, query, 200, "SELECT * FROM `Contas` WHERE `Nome`='%s'", accused);
        mysql_query(IDConexao, query);

        if(cache_num_rows() == 0) return 0;

        new id_account, lastTime;

        cache_get_value_int(0, "ID", id_account);

        mysql_format(IDConexao, query, 200, "SELECT * FROM `Prison` WHERE `id_contas`='%d'", id_account);
        mysql_query(IDConexao, query);

        if(cache_num_rows() == 0){
            mysql_format(IDConexao, query, 300, "INSERT INTO `Prison` (`responsible`, `chain`, `reason`, `time`, `id_contas`) VALUES ('%e', '%e', '%e', '%d', '%d')", responsible, chain, reason, (time*60), id_account);
            mysql_query(IDConexao, query);
            return 1;
        }

        cache_get_value_int(0, "time", lastTime);

        mysql_format(IDConexao, query, 300, "UPDATE `Prison` SET `responsible`='%e', `chain`='%e', `reason`='%e', `time`='%d' WHERE `id_contas`='%d'", responsible, chain, reason, ((time*60)+lastTime), id_account);
        mysql_query(IDConexao, query);
        return 1;
    }

    if(PlayerInfo[playerid][hasReborn])
    {
        KillTimer(PlayerInfo[playerid][t_death]);

        PlayerInfo[playerid][hasReborn] = false;

        ClearAnimations(playerid);
        StopAudioStreamForPlayer(playerid);
        ShowTDStatus(playerid);
        #if EVENT_GIFT
            ShowTDGift(playerid);
        #endif

        SetPlayerHealth(playerid, 100.0);
    }
    if(Perseguicao[playerid])
    {
        Perseguicao[playerid] = false;
        KillTimer(t_persecution[playerid]);
    }
    if(Handcuffed[playerid] != INVALID_PLAYER_ID)
    {
        RemovePlayerAttachedObject(playerid, 4);
        TogglePlayerControllable(playerid, true);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);

        Handcuffed[playerid] = INVALID_PLAYER_ID;
        KillTimer(t_handcuffed[playerid]);
    }
    if(Abordado[playerid])
    {
        Abordado[playerid] = false;
        KillTimer(t_approach[playerid]);
    }

    format(PrisonEnum[playerid][pResponsavel], 24, responsible);
    format(PrisonEnum[playerid][pCadeia], 10, chain);
    format(PrisonEnum[playerid][pMotivo], 50, reason);
    PrisonEnum[playerid][pTempo] = time*60;

    GameTextForPlayer(playerid, "~w~~h~PRESO!", 2000, 0);
    SendClientMessage(playerid, 0x2894FFAA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Prisão ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    SendClientMessage(playerid, White, "•» Você está preso");
    format(String, MAX_STRING, "•» Foi preso por ( %s )", PrisonEnum[playerid][pResponsavel]);
    SendClientMessage(playerid, White, String);
    format(String, MAX_STRING, "•» Motivo da prisão ( %s )", PrisonEnum[playerid][pMotivo]);
    SendClientMessage(playerid, White, String);
    SendClientMessage(playerid, 0x2894FFAA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Prisão ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    mysql_format(IDConexao, query, 300, "INSERT INTO `Prison` (`responsible`, `chain`, `reason`, `time`, `id_contas`) VALUES ('%e', '%e', '%e', '%d', '%d')", PrisonEnum[playerid][pResponsavel], PrisonEnum[playerid][pCadeia], PrisonEnum[playerid][pMotivo], PrisonEnum[playerid][pTempo], PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);

    if(!strcmp(PrisonEnum[playerid][pCadeia], "Federal"))
    {
        PlayerTextDrawSetString(playerid, PlayerBarStatus[playerid][0], "~w~PRESO");
        PlayerTextDrawShow(playerid, PlayerBarStatus[playerid][0]);

        SetPlayerInterior(playerid, 10);
        SetSpawnInfo(playerid, 0, PlayerInfo[playerid][skin], 223.5335, 110.3779, 999.0156, 0, 0, 0, 0, 0, 0, 0);
    } else {
        SetPlayerInterior(playerid, 6);
        SetSpawnInfo(playerid, 0, PlayerInfo[playerid][skin], 264.2374, 77.4612, 1001.0391, 0, 0, 0, 0, 0, 0, 0);
    }

    ResetPlayerWeapons(playerid);
    SetPlayerHealth(playerid, 99999);

    PlayerTextDrawShow(playerid, TempoPresidio[playerid][1]);
    PlayerTextDrawShow(playerid, TempoPresidio[playerid][0]);

    SpawnPlayer(playerid);
    return PrisonSystem(playerid);
}

