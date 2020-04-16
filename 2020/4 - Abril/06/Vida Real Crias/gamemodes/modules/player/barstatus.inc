#include YSI\y_hooks

hook OnPlayerDisconnect(playerid, reason)
{
    UpdateProgressBar(playerid);

    Progress[playerid][Fome] = 0.0;
    Progress[playerid][Sede] = 0.0;
    Progress[playerid][Sono] = 0.0;
    Progress[playerid][Vida] = 0.0;
    KillTimer(TimerBarStatus[playerid]);
    return 1;
}

forward ProgrecoBar(playerid);
public ProgrecoBar(playerid)
{
    if(PrisonEnum[playerid][pTempo] || IsArena[playerid] || PlayerInfo[playerid][tutorial] || IsPlayerMobile(playerid)) return 0;

    if(Progress[playerid][Fome] < 100.0)
    {
        if(Progress[playerid][Fome] == 95.0 || Progress[playerid][Fome] == 90.0)
        {
            SendClientMessage(playerid, 0xFF8000AA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            SendClientMessage(playerid, 0xFFFFFFAA, "Você está com muita fome!");
            SendClientMessage(playerid, 0xFFFFFFAA, "Vá até o restaurante mais próximo!");
            SendClientMessage(playerid, 0xFF8000AA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        }

        PlayerTextDrawTextSize(playerid, PlayerBarStatus[playerid][2], (593.0 - ((49.0 * (Progress[playerid][Fome] += 1.5)) / 100)), 0.0);
        PlayerTextDrawShow(playerid, PlayerBarStatus[playerid][2]);
    } else {
        SetPlayerHealth(playerid, 0);
        Progress[playerid][Fome] = 95.0;

        SendClientMessage(playerid, 0xFF8000AA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        SendClientMessage(playerid, 0xFFFFFFAA, "Você perdeu a conciência e foi levado pro hospital mais próximo!");
        SendClientMessage(playerid, 0xFFFFFFAA, "Vá até o restaurante mais próximo!");
        SendClientMessage(playerid, 0xFF8000AA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    }

    if(Progress[playerid][Sede] < 100.0)
    {
        if(Progress[playerid][Sede] == 95.0 || Progress[playerid][Sede] == 90.0)
        {
            SendClientMessage(playerid, 0x008000AA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            SendClientMessage(playerid, 0xFFFFFFAA, "Você está com muita sede!");
            SendClientMessage(playerid, 0xFFFFFFAA, "Vá até o restaurante mais próximo!");
            SendClientMessage(playerid, 0x008000AA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        }

        PlayerTextDrawTextSize(playerid, PlayerBarStatus[playerid][3], (593.0 - ((49.0 * (Progress[playerid][Sede] += 1.0)) / 100)), 0.0);
        PlayerTextDrawShow(playerid, PlayerBarStatus[playerid][3]);
    } else {
        SetPlayerHealth(playerid, 0);
        Progress[playerid][Sede] = 95.0;

        SendClientMessage(playerid, 0x008000AA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        SendClientMessage(playerid, 0xFFFFFFAA, "Você perdeu a conciência e foi levado pro hospital mais próximo!");
        SendClientMessage(playerid, 0xFFFFFFAA, "Vá até o restaurante mais próximo!");
        SendClientMessage(playerid, 0x008000AA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    }

    if(Progress[playerid][Sono] < 100.0)
    {
        if(Progress[playerid][Sono] == 90.0)
        {
            SendClientMessage(playerid, 0x0080C0AA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            SendClientMessage(playerid, 0xFFFFFFAA, "Você está com muito sono!");
            SendClientMessage(playerid, 0xFFFFFFAA, "Vá até a sua casa/hotel e digite: /dormir!");
            SendClientMessage(playerid, 0x0080C0AA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        }
        else if(Progress[playerid][Sono] == 95.0)
        {
            SendClientMessage(playerid, 0x0080C0AA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            SendClientMessage(playerid, 0xFFFFFFAA, "Você está com muito sono!");
            SendClientMessage(playerid, 0xFFFFFFAA, "Vá até a sua casa/hotel e digite: /dormir!");
            SendClientMessage(playerid, 0x0080C0AA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        }
        else if(Progress[playerid][Sono] == 98.0)
        {
            TimerEffectSleep[playerid] = SetTimerEx("SleepEffect", 3000, true, "d", playerid);
            SendClientMessage(playerid, 0x0080C0AA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            SendClientMessage(playerid, 0xFFFFFFAA, "Você está com muito sono!");
            SendClientMessage(playerid, 0xFFFFFFAA, "Vá até a sua casa/hotel e digite: /dormir!");
            SendClientMessage(playerid, 0x0080C0AA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        }

        PlayerTextDrawTextSize(playerid, PlayerBarStatus[playerid][4], (593.0 - ((49.0 * (Progress[playerid][Sono] += 0.5)) / 100)), 0.0);
        PlayerTextDrawShow(playerid, PlayerBarStatus[playerid][4]);
    }
    else
    {
        if(Sleeping[playerid] == false)
        {
            TimerSleeping[playerid] = SetTimerEx("Sleep", 1000, true, "d", playerid);
            SendClientMessage(playerid, 0xFFFFFFAA, "Você está com muito sono e acabou perdendo a conciência! {0080C0}zzZZzZZZ");
        }
    }

    UpdateProgressBar(playerid);
    return 1;
}

stock UpdateProgressBar(playerid)
{
    mysql_format(IDConexao, String, sizeof(String), "UPDATE `Status` SET `fome`='%f', `sede`='%f', `sono`='%f', `vida`='%f' WHERE `id_contas`='%d'", Progress[playerid][Fome], Progress[playerid][Sede], Progress[playerid][Sono], Progress[playerid][Vida], PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, String);
    return 1;
}
