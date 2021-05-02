#include YSI\y_hooks

new SleepingSec[MAX_PLAYERS];

hook OnPlayerDisconnect(playerid, reason)
{
    Sleeping[playerid] = false;
    SleepingSec[playerid] = 0;

    KillTimer(TimerEffectSleep[playerid]);
    return 1;
}

forward SleepEffect(playerid);
public SleepEffect(playerid)
{
    SetPlayerDrunkLevel(playerid, 6000);
    return 1;
}

forward Sleep(playerid);
public Sleep(playerid)
{
    if(SleepingSec[playerid] >= 30)
    {
        Progress[playerid][Sono] = 0.0;
        UpdateProgressBar(playerid);

        HideTDSleep(playerid);
        ShowTDStatus(playerid);
        ShowTDTime(playerid);

        Sleeping[playerid] = false;
        SleepingSec[playerid] = 0;
        TogglePlayerControllable(playerid, true);
        ClearAnimations(playerid);
        SetPlayerDrunkLevel(playerid, 0);

        SendClientMessage(playerid, 0x0080C0AA, "Você acordou!");
        return 1;
    }
    else if(SleepingSec[playerid] == 0)
    {
        RemovePlayerFromVehicle(playerid);

        ShowTDSleep(playerid);
        HideTDStatus(playerid);
        HideTDTime(playerid);

        KillTimer(TimerEffectSleep[playerid]);
        TogglePlayerControllable(playerid, false);

        ApplyAnimation(playerid, "CRACK", "crckdeth4", 4.0, 0, 0, 0, 1, 0);
    }

    SleepingSec[playerid]++;
    return SetTimerEx("Sleep", 1000, false, "d", playerid);
}
