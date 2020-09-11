#include YSI\y_hooks

hook OnPlayerConnect(playerid)
{
    //Arena Bebidas
    RemoveBuildingForPlayer(playerid, 956, 2139.5156, -1161.4844, 23.3594, 0.25);
    RemoveBuildingForPlayer(playerid, 956, 2153.2344, -1016.1484, 62.2344, 0.25);

    //Gas Montgomery
    RemoveBuildingForPlayer(playerid, 1370, 1399.9219, 341.4766, 18.4844, 0.25);
    RemoveBuildingForPlayer(playerid, 1370, 1373.4531, 469.9688, 19.6953, 0.25);
    RemoveBuildingForPlayer(playerid, 1370, 1373.1719, 471.1016, 19.6953, 0.25);
    RemoveBuildingForPlayer(playerid, 1370, 1358.4844, 483.6563, 19.6953, 0.25);

    /* Door bank */
    RemoveBuildingForPlayer(playerid, 1502, 354.8906, 168.6719, 1018.9766, 0.25);

    /* Bebidas SF Posto */
    RemoveBuildingForPlayer(playerid, 1209, -2420.2188, 984.5781, 44.2969, 0.25);
    RemoveBuildingForPlayer(playerid, 1302, -2420.1797, 985.9453, 44.2969, 0.25);
	return 1;
}
