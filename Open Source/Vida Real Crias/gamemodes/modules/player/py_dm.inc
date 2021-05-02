#include YSI\y_hooks

hook OnPlayerDisconnect(playerid, reason)
{
/*
    for(new victimid = 0; victimid < MAX_PLAYERS; victimid++)
    {
        if(PlayerInfo[victimid][killeridReborn] != playerid) continue;

        format(String, MAX_STRING, "VRC-Admin ~ O(A) Bot agendou a prisão do(a) jogador(a) %s por 10 minutos ( Motivo: Assasinato recente )", PlayerInfo[playerid][Nome]);
        SendClientMessageToAll(adm, String);

        format(PrisonEnum[playerid][pMotivo], 20, "Assasinato recente");

        new query[300];
        mysql_format(IDConexao, query, 300, "INSERT INTO `Prison` (`responsible`, `chain`, `reason`, `time`, `id_contas`) VALUES ('%e', '%e', '%e', '%d', '%d')", "Bot", "Federal", PrisonEnum[playerid][pMotivo], (10*60), PlayerInfo[playerid][ID]);
        mysql_query(IDConexao, query);

        PlayerInfo[victimid][killeridReborn] = INVALID_PLAYER_ID;
        KillTimer(PlayerInfo[victimid][t_reportMurter]);
        break;
    }
*/

    if(PlayerInfo[playerid][hasReborn]){
        PlayerInfo[playerid][killeridReborn] = INVALID_PLAYER_ID;
        PlayerInfo[playerid][hasReborn] = false;
        KillTimer(PlayerInfo[playerid][t_death]);
    }
    if(PlayerInfo[playerid][killeridReborn] != INVALID_PLAYER_ID){
        KillTimer(PlayerInfo[playerid][t_reportMurter]);
    }

    return 1;
}

hook OnPlayerDeath(playerid, killerid, reason)
{
    if(!PlayerInfo[playerid][Logado]) return 0;

    PlayerInfo[playerid][hasDeath] = true;

    if(IsPlayerInBase(playerid) || IsArena[playerid])
    {
        SendDeathMessage(killerid, playerid, reason);

        TextDrawShowForPlayer(playerid, TDDetonated[0]);
        TextDrawShowForPlayer(playerid, TDDetonated[1]);

        if(IsPlayerInBase(playerid))
        {
            new baseid = GetPlayerBaseID(playerid, true);

            if(IsPlayerMemberBaseEx(playerid, baseid))
            {
                SetSpawnInfo(playerid, 0, PlayerInfo[playerid][skin], BaseEnter[baseid][be_x], BaseEnter[baseid][be_y], BaseEnter[baseid][be_z], BaseEnter[baseid][be_a], 0, 0, 0, 0, 0, 0);
            }
            else
            {
                Cidade_Que_Morreu[playerid] = PickupHospitalNext(playerid);
                SetSpawnInfo(playerid, 0, PlayerInfo[playerid][skin], Hosp[Cidade_Que_Morreu[playerid]][0], Hosp[Cidade_Que_Morreu[playerid]][1], Hosp[Cidade_Que_Morreu[playerid]][2], 0, 0, 0, 0, 0, 0, 0);
            }
        }
        else
        {
            new rand = random(sizeof(RandomSpawns));
            SetSpawnInfo(playerid, 0, PlayerInfo[playerid][skin], RandomSpawns[rand][rs_x], RandomSpawns[rand][rs_y], RandomSpawns[rand][rs_z], RandomSpawns[rand][rs_a], 0, 0, 0, 0, 0, 0);
        }

        Kills[playerid] = 0;

        if(killerid != INVALID_PLAYER_ID)
        {
            TogglePlayerSpectating(playerid, true);

            Kills[killerid]++;
            switch(Kills[killerid])
            {
                case 2: GameTextForPlayer(killerid, "~r~DOUBLE KILL", 1000, 4);
                case 3: GameTextForPlayer(killerid, "~r~TRIPE KILL", 1000, 4);
                case 4..10: GameTextForPlayer(killerid, "~r~CHAIN KILLER", 1000, 4);
            }

            if(IsArena[killerid])
            {
                PlayerInfo[killerid][Matou]++;
                SetIntQuery(killerid, "Identidade", "matou", PlayerInfo[killerid][Matou]);
                HideTextDrawKD(killerid);
                ShowTextDrawKD(killerid);
            }

            if(IsPlayerInBase(killerid) && !IsPlayerInBaseDmOn(killerid))
            {
                PlayerInfo[killerid][Estrelas] += 5;
                UpdatePlayerStar(killerid);

                format(String, MAX_STRING, "O(A) Jogador(a) %s[%d] matou %s[%d] e foi colocado +5 estrelas de procurado(a)", PlayerInfo[killerid][Nome], killerid, PlayerInfo[playerid][Nome], playerid);
            }
            else
            {
                format(String, MAX_STRING, "O(A) Jogador(a) %s[%d] matou %s[%d] e não recebeu estrelas ( DM Liberado )", PlayerInfo[killerid][Nome], killerid, PlayerInfo[playerid][Nome], playerid);
            }
            LocalMessage(50.0, playerid, String, 0xB9FFFFAA);

            if(IsArena[playerid]) HideTextDrawKD(playerid);

            PlayerSpectatePlayer(playerid, killerid);
            SetTimerEx("Spectate", 5000, false, "d", playerid);

        }

        Cidade_Que_Morreu[playerid] = -1;
        PlayerInfo[playerid][Morreu]++;
        SetIntQuery(playerid, "Identidade", "morreu", PlayerInfo[playerid][Morreu]);
    }
    else
    {
        new Float:x, Float:y, Float:z, Float:a;

        GetPlayerFacingAngle(playerid, a);
        GetPlayerPos(playerid, x, y, z);
        SetSpawnInfo(playerid, 0, PlayerInfo[playerid][skin], x, y, z-0.80, a, 0, 0, 0, 0, 0, 0);

        PlayerInfo[playerid][minReborn] = 4;
        PlayerInfo[playerid][secReborn] = 59;
        PlayerInfo[playerid][hasReborn] = true;
        PlayerInfo[playerid][t_death] = SetTimerEx("OnPlayerDeathMatch", 1000, true, "d", playerid);

        if(killerid == INVALID_PLAYER_ID) return 1;

        PlayerInfo[playerid][killeridReborn] = killerid;

        if(IsPlayerPolice(killerid) && IsPlayerUniformPM(killerid) && IsPlayerMafia(playerid) && PlayerInfo[playerid][Estrelas])
        {
            format(String, MAX_STRING, "O(A) Policial %s[%d] feriu %s[%d] e não recebeu estrelas", PlayerInfo[killerid][Nome], killerid, PlayerInfo[playerid][Nome], playerid);
            LocalMessage(50.0, playerid, String, 0xB9FFFFAA);
        }
        else
        {
            PlayerInfo[killerid][Estrelas] += 5;
            UpdatePlayerStar(killerid);

            format(String, MAX_STRING, "O(A) Jogador(a) %s[%d] feriu %s[%d] e foi colocado +5 estrelas de procurado(a)", PlayerInfo[killerid][Nome], killerid, PlayerInfo[playerid][Nome], playerid);
            LocalMessage(50.0, playerid, String, 0xB9FFFFAA);
        }
    }
    return 1;
}

hook OnPlayerSpawn(playerid)
{
    PlayerInfo[playerid][hasDeath] = false;

    if(PlayerInfo[playerid][hasReborn])
    {
        if(PlayerInfo[playerid][killeridReborn] != INVALID_PLAYER_ID){
            PlayerInfo[playerid][t_reportMurter] = SetTimerEx("OnPlayerReportMurder", 15000, false, "d", playerid);
            SendClientMessage(playerid, Yellow, "Você tem alguns segundos para relatar esta tentativa de assasinato ( /190 )");
        }

        PlayAudioStreamForPlayer(playerid, "http://vidarealcrias.com/songs/heart-beats.mp3");
        ApplyAnimation(playerid, "CRACK", "crckdeth4", 4.0, 0, 0, 0, 1, 0);
        OnClearChat(playerid);
        HidePlayerVelocimetro(playerid);
        HideTDStatus(playerid);
        HideTDGift(playerid);
        return 1;
    }
	return 1;
}

hook OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    if(PlayerInfo[playerid][hasReborn])
    {
        ClearAnimations(playerid);
        ApplyAnimation(playerid, "CRACK", "crckdeth4", 4.0, 0, 0, 0, 1, 0);
        return 1;
    }
	return 1;
}

forward OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid);
public OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid)
{
    if(!IsArena[playerid]) return 1;

    format(String, 20, "+Damage %.0f", amount);
    TextDrawSetString(GiveDamage[playerid], String);
    TextDrawShowForPlayer(playerid, GiveDamage[playerid]);
    PlayerPlaySound(playerid, 17802, 0.0, 0.0, 0.0);

    SetTimerEx("HideTextDrawDamage", 1000, false, "i", playerid);
    return 1;
}


forward OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid);
public OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid)
{
    if(!IsArena[playerid]) return 1;

    format(String, 20, "-Damage %.0f", amount);
    TextDrawSetString(TakeDamage[playerid], String);
    TextDrawShowForPlayer(playerid, TakeDamage[playerid]);

    SetTimerEx("HideTextDrawDamage", 1000, false, "i", playerid);
    return 1;
}

forward OnPlayerDeathMatch(playerid);
public OnPlayerDeathMatch(playerid)
{
    if(!PlayerInfo[playerid][hasReborn] || PlayerInfo[playerid][hasDeath]) return 1;

    if(PlayerInfo[playerid][minReborn] == 0 && PlayerInfo[playerid][secReborn] == 0)
    {
        KillTimer(PlayerInfo[playerid][t_death]);
        PlayerInfo[playerid][hasReborn] = false;
        ClearAnimations(playerid);

        StopAudioStreamForPlayer(playerid);

        ShowTDStatus(playerid);
        ShowTDGift(playerid);

        PlayerPlaySound(playerid, 1057, 0, 0, 0);
        SetPlayerHealth(playerid, 100.0);
        return 1;
    }

    if(PlayerInfo[playerid][secReborn] == -1)
    {
        PlayerInfo[playerid][secReborn] = 59;
        PlayerInfo[playerid][minReborn]--;
    }

    SetPlayerHealth(playerid, 99999);
    format(String, MAX_STRING, "~r~Renascendo: ~w~%02d:%02d", PlayerInfo[playerid][minReborn], PlayerInfo[playerid][secReborn]);
    GameTextForPlayer(playerid, String, 1000, 3);
    PlayerInfo[playerid][secReborn]--;
    return 1;
}

forward OnPlayerReportMurder(playerid);
public OnPlayerReportMurder(playerid)
{
    PlayerInfo[playerid][killeridReborn] = INVALID_PLAYER_ID;
    return 1;
}
