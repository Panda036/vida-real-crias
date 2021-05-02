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

    if(hour == 05 && minutes == 00 && secunds == 00){
        SendTax();
        SendRconCommand("gmx");
    }

    else if(hour == 04 && minutes == 55 && secunds == 00)
        SendClientMessageToAll(Yellow, "O servidor está programado para reiniciar em 5 minutos");

    else if(hour == 04 && minutes == 59 && secunds == 00)
        SendClientMessageToAll(Yellow, "O servidor está programado para reiniciar em 1 minuto");

    else if(hour == 04 && minutes == 59 && secunds == 59)
    {
        for(new playerid = 0; playerid < MAX_PLAYERS; playerid++)
        {
            if(!PlayerInfo[playerid][Logado]) continue;

            SendClientMessage(playerid, Yellow, "Reiniciando o servidor, voltamos já!");
            Kick(playerid);
        }
    }
    return 1;
}
