#include YSI\y_hooks

enum PrisonE {
    pResponsavel[MAX_PLAYER_NAME],
    pTempo,
    pMotivo[20],
    pCadeia[15]
}

new PrisonEnum[MAX_PLAYERS][PrisonE];
new PlayerText:TempoPresidio[MAX_PLAYERS][3];

hook OnGameModeInit()
{
    mysql_query(IDConexao, "CREATE TABLE IF NOT EXISTS Prisoes (`ID` int PRIMARY KEY, `Nome` varchar(24) NOT NULL, `Responsavel` varchar(24) NOT NULL, `Cadeia` varchar(15) NOT NULL, `Motivo` varchar(30) NOT NULL, `Tempo` int(10) NOT NULL)", false);
	return 1;
}

hook OnPlayerConnect(playerid)
{
    TempoPresidio[playerid][0] = CreatePlayerTextDraw(playerid, 1.390990, 293.250061, "I");
    PlayerTextDrawLetterSize(playerid, TempoPresidio[playerid][0], 15.084396, 3.670835);
    PlayerTextDrawAlignment(playerid, TempoPresidio[playerid][0], 1);
    PlayerTextDrawColor(playerid, TempoPresidio[playerid][0], 100);
    PlayerTextDrawSetShadow(playerid, TempoPresidio[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, TempoPresidio[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, TempoPresidio[playerid][0], 0);
    PlayerTextDrawFont(playerid, TempoPresidio[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, TempoPresidio[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, TempoPresidio[playerid][0], 0);

    TempoPresidio[playerid][1] = CreatePlayerTextDraw(playerid, 83.016113, 299.666595, "");
    PlayerTextDrawLetterSize(playerid, TempoPresidio[playerid][1], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, TempoPresidio[playerid][1], -24.000000, 23.000000);
    PlayerTextDrawAlignment(playerid, TempoPresidio[playerid][1], 1);
    PlayerTextDrawColor(playerid, TempoPresidio[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, TempoPresidio[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, TempoPresidio[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, TempoPresidio[playerid][1], 0);
    PlayerTextDrawFont(playerid, TempoPresidio[playerid][1], 5);
    PlayerTextDrawSetProportional(playerid, TempoPresidio[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, TempoPresidio[playerid][1], 0);
    PlayerTextDrawSetPreviewModel(playerid, TempoPresidio[playerid][1], 19825);
    PlayerTextDrawSetPreviewRot(playerid, TempoPresidio[playerid][1], 180.000000, 180.000000, 0.000000, 1.000000);

    TempoPresidio[playerid][2] = CreatePlayerTextDraw(playerid, 81.508071, 304.333312, "");
    PlayerTextDrawLetterSize(playerid, TempoPresidio[playerid][2], 0.168549, 1.308331);
    PlayerTextDrawAlignment(playerid, TempoPresidio[playerid][2], 1);
    PlayerTextDrawColor(playerid, TempoPresidio[playerid][2], -74);
    PlayerTextDrawSetShadow(playerid, TempoPresidio[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, TempoPresidio[playerid][2], -1);
    PlayerTextDrawBackgroundColor(playerid, TempoPresidio[playerid][2], 255);
    PlayerTextDrawFont(playerid, TempoPresidio[playerid][2], 2);
    PlayerTextDrawSetProportional(playerid, TempoPresidio[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, TempoPresidio[playerid][2], 0);
}

forward DBLoadPrisons(playerid);
public DBLoadPrisons(playerid)
{
    if(cache_num_rows() > 0)
    {
        new tmp[128];
        cache_get_value_name(0, "Responsavel", tmp); format(PrisonEnum[playerid][pResponsavel], MAX_PLAYER_NAME, tmp);
        cache_get_value_int(0, "Tempo", PrisonEnum[playerid][pTempo]);
        cache_get_value_name(0, "Motivo", tmp); format(PrisonEnum[playerid][pMotivo], 20, tmp);
        cache_get_value_name(0, "Cadeia", tmp); format(PrisonEnum[playerid][pCadeia], 15, tmp);

        GameTextForPlayer(playerid, "~w~~h~PRESO!", 2000, 0);
        SendClientMessage(playerid, 0x2894FFAA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Prisão ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        SendClientMessage(playerid, Branco, "•» Você está preso!");
        format(String, sizeof(String), "•» Foi preso por ( %s )", PrisonEnum[playerid][pResponsavel]);
        SendClientMessage(playerid, Branco, String);
        format(String, sizeof(String), "•» Motivo da prisão ( %s )", PrisonEnum[playerid][pMotivo]);
        SendClientMessage(playerid, Branco, String);
        SendClientMessage(playerid, 0x2894FFAA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Prisão ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

        CheckChain(playerid);
    } else {
        PrisonEnum[playerid][pTempo] = 0;
        PrisonEnum[playerid][pResponsavel] = 0;
        PrisonEnum[playerid][pCadeia] = 0;
    }
    return 1;
}

DBSavePrisons(playerid)
{
    if(PrisonEnum[playerid][pTempo] != 0)
    {
        mysql_format(IDConexao, String, sizeof(String), "UPDATE Prisoes SET Responsavel=%e, Cadeia=%e, Motivo=%e, Tempo=%d WHERE Nome=%e", PrisonEnum[playerid][pResponsavel], PrisonEnum[playerid][pCadeia], PrisonEnum[playerid][pMotivo], PrisonEnum[playerid][pTempo], PlayerInfo[playerid][Nome]);
        mysql_tquery(IDConexao, String);
    }
    return 1;
}

CheckChain(playerid)
{
    if(strcmp(PrisonEnum[playerid][pCadeia], "Federal", true)==0)
    {
        ResetPlayerWeapons(playerid);
        SetPlayerInterior(playerid, 10);
        SetPlayerHealth(playerid, 99999);
        SetPlayerPos(playerid, 223.5335,110.3779,999.0156);
        PlayerTextDrawShow(playerid, TempoPresidio[playerid][1]);
        PlayerTextDrawShow(playerid, TempoPresidio[playerid][0]);
        PrisonSystem(playerid);

    } else if(strcmp(PrisonEnum[playerid][pCadeia], "Municipal", true)==0) {

        ResetPlayerWeapons(playerid);
        SetPlayerInterior(playerid, 6);
        SetPlayerHealth(playerid, 99999);
        SetPlayerFacingAngle(playerid, 1.2072);
        SetPlayerPos(playerid, 264.2374,77.4612,1001.0391);
        PlayerTextDrawShow(playerid, TempoPresidio[playerid][1]);
        PlayerTextDrawShow(playerid, TempoPresidio[playerid][0]);
        PrisonSystem(playerid);
    }
    return 1;
}

forward PrisonSystem(playerid);
public PrisonSystem(playerid)
{
    if(PrisonEnum[playerid][pTempo] != 0)
    {
        TempoPreso[playerid] = SetTimerEx("PrisonSystem", 1000, false, "i", playerid);

        if(strcmp(PrisonEnum[playerid][pCadeia], "Federal", true)==0)
        {
            formatSeconds(PrisonEnum[playerid][pTempo], Hora, Min, Seg);
        } else {
            formatSeconds(PrisonEnum[playerid][pTempo], Hora, Min, Seg);
        }

        format(String,sizeof(String),"%02d:%02d:%02d", Hora, Min, Seg);
        PlayerTextDrawSetString(playerid, TempoPresidio[playerid][2], String);
        PlayerTextDrawShow(playerid, TempoPresidio[playerid][2]);
        PrisonEnum[playerid][pTempo]--;
        mysql_format(IDConexao, String, sizeof(String), "UPDATE `Prisoes` SET `Tempo`='%d' WHERE `Nome`='%e'", PrisonEnum[playerid][pTempo], PlayerInfo[playerid][Nome]);
        mysql_query(IDConexao, String);
    } else {
        KillTimer(TempoPreso[playerid]);
        PrisonEnum[playerid][pCadeia] = 0;
        PlayerInfo[playerid][Estrelas] = 0;

        format(String, sizeof(String), "%d", PlayerInfo[playerid][Estrelas]);
        PlayerTextDrawSetString(playerid, PlayerBarStatus[playerid][1], String);
        PlayerTextDrawShow(playerid, PlayerBarStatus[playerid][1]);

        SetPlayerInterior(playerid, 0);
        SetPlayerHealth(playerid, 100);
        SetPlayerPos(playerid, 1551.6987,-1675.3806,15.9631);

        PlayerTextDrawHide(playerid, TempoPresidio[playerid][2]);
        PlayerTextDrawHide(playerid, TempoPresidio[playerid][1]);
        PlayerTextDrawHide(playerid, TempoPresidio[playerid][0]);
        GameTextForPlayer(playerid, "~w~SOLTO!", 3000, 0);
        SendClientMessage(playerid, 0xA9C4E4AA, "| INFO | Você cumpriu sua pena e está livre novamente!");
        mysql_format(IDConexao, String, sizeof(String), "DELETE FROM `Prisoes` WHERE `Nome`='%e'", PlayerInfo[playerid][Nome]);
        mysql_query(IDConexao, String);
    }
    return 1;
}
