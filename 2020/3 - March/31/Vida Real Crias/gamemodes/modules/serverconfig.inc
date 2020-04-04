#include YSI\y_hooks

hook OnGameModeInit()
{
    ShowPlayerMarkers(PLAYER_MARKERS_MODE_STREAMED);

    UsePlayerPedAnims();
	EnableStuntBonusForAll(0);
	DisableInteriorEnterExits();

    format(String, sizeof(String), "password %s", GetRandomString(10));

    SetGameModeText("Brasil - VRC v1.0.0");
    SendRconCommand("mapname San Andreas");
    SendRconCommand(String);
	SendRconCommand("hostname Vida Real Crias RPG @ HeavyHost.com.br");
	SendRconCommand("language Português - Brasil");

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
        SendClientMessageToAll(0xB9FFFFAA, "| VRC-Admin | O servidor está programado para reiniciar em 5 minutos");
    }
    else if(hour == 4 && minutes == 59 && secunds == 0)
    {
        SendClientMessageToAll(0xB9FFFFAA, "| VRC-Admin | O servidor está programado para reiniciar em 1 minuto");
    }
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(hour == 4 && minutes == 59 && secunds == 57)
        {
            if(!PlayerInfo[i][Logado]) return 0;

            SaveAccounts(i);
            SendClientMessage(i, 0xB9FFFFAA, "| VRC-Admin | Reiniciando o servidor, voltamos já!");
        }
        else if(hour == 4 && minutes == 59 && secunds == 58)
        {
            Kick(i);
        }
    }
    return 1;
}
