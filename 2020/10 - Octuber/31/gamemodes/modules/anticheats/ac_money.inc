#include YSI\y_hooks

new t_ac_money[MAX_PLAYERS];

hook OnPlayerConnect(playerid)
{
    t_ac_money[playerid] = SetTimerEx("AntiMoneyHack", 1000, true, "d", playerid);
	return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    KillTimer(t_ac_money[playerid]);
	return 1;
}

forward AntiMoneyHack(playerid);
public AntiMoneyHack(playerid)
{
    if(!PlayerInfo[playerid][Logado]) return 0;

    if(!stateanticheat[sac_money]) return 0;

    if(GetPlayerMoney(playerid) > PlayerInfo[playerid][Dinheiro])
    {
        UpdatePlayerMoney(playerid);
    }
    return 1;
}
