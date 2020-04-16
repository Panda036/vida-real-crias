#include YSI\y_hooks

hook OnPlayerConnect(playerid)
{
    //Arena Bebidas
    RemoveBuildingForPlayer(playerid, 956, 2139.5156, -1161.4844, 23.3594, 0.25);
    RemoveBuildingForPlayer(playerid, 956, 2153.2344, -1016.1484, 62.2344, 0.25);
	return 1;
}
