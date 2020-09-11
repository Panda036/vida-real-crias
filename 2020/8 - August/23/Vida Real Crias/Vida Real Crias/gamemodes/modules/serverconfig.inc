#include YSI\y_hooks

hook OnGameModeInit()
{
    ShowPlayerMarkers(PLAYER_MARKERS_MODE_OFF);

    UsePlayerPedAnims();
	EnableStuntBonusForAll(0);
	DisableInteriorEnterExits();



    #if !SERVER_OFFLINE
        SendRconCommand("hostname Vida Real Crias RPG | Android/PC | #HeavyHost");
        format(String, 30, "password %s", GetRandomString(10));
        SendRconCommand(String);
    #else
        SendRconCommand("hostname Vida Real Crias RPG | Offline");
    #endif


	SendRconCommand("language Português - Brasil");
    SendRconCommand("mapname San Andreas");
    format(String, 30, "Brasil - VRC v%s", SERVER_VERSION);
    SetGameModeText(String);

    SetTimer("OnPlayerUnlockServer", 60000, false);
    SetTimer("OnPlayerServerReset", 1000, true);
    return 1;
}

forward OnPlayerUnlockServer();
public OnPlayerUnlockServer()
{
    SendRconCommand("password 0");
    return 1;
}

forward OnPlayerServerReset();
public OnPlayerServerReset()
{
    new hour, minutes, secunds;
    gettime(hour, minutes, secunds);

    if(hour == 5 && minutes == 0 && secunds == 0)
    {
        SendRconCommand("gmx");
    }
    else if(hour == 4 && minutes == 55 && secunds == 0)
    {
        SendClientMessageToAll(0xB9FFFFAA, "O servidor está programado para reiniciar em 5 minutos");
    }
    else if(hour == 4 && minutes == 59 && secunds == 0)
    {
        SendClientMessageToAll(0xB9FFFFAA, "O servidor está programado para reiniciar em 1 minuto");
    }
    if(hour == 4 && minutes == 59 && secunds == 57)
    {
        SendTax();

        for(new playerid = 0; playerid < MAX_PLAYERS; playerid++)
        {
            if(!PlayerInfo[playerid][Logado]) continue;

            SaveAccounts(playerid);
            SendClientMessage(playerid, 0xB9FFFFAA, "Reiniciando o servidor, voltamos já!");
            Kick(playerid);
        }
    }
    return 1;
}
