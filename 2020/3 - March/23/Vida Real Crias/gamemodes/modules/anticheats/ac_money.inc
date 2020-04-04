#include YSI\y_hooks

hook OnPlayerConnect(playerid)
{
    SetTimerEx("CheckMoney", 5000, true, "d", playerid);
	return 1;
}

forward CheckMoney(playerid);
public CheckMoney(playerid)
{
    if(!PlayerInfo[playerid][Logado]) return 0;

    if(GetPlayerMoney(playerid) != PlayerInfo[playerid][Dinheiro])
    {
        UpdatePlayerMoney(playerid);
    }
    return 1;
}
