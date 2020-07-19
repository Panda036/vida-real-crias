#include YSI\y_hooks

hook OnPlayerSpawn(playerid)
{
    UpdatePlayerMoney(playerid); //Remove bug money
	return 1;
}
