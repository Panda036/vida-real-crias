#include YSI\y_hooks

#define takedamage(%1,%2,%3,%4) %1 | (%2 << 1) | (%3 << 2) | (%4 << 3)

new t_wheel[MAX_PLAYERS];

hook OnPlayerConnect(playerid)
{
    t_wheel[playerid] = SetTimerEx("wheel", 1000, true, "d", playerid);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    KillTimer(t_wheel[playerid]);
    return 1;
}

forward wheel(playerid);
public wheel(playerid)
{
    new Dano[4], Float:x, Float:y, Float:z;

    if(IsPlayerInAnyVehicle(playerid) && PlayerToPoint(2.0, playerid, x, y, z))
    {
        new vehicleid = GetPlayerVehicleID(playerid);

        GetVehicleDamageStatus(vehicleid, Dano[0], Dano[1], Dano[2], Dano[3]);
        UpdateVehicleDamageStatus(vehicleid, Dano[0], Dano[1], Dano[2], takedamage(1, 1, 1, 1));
        GameTextForPlayer(playerid, "~w~Pneu Furado", 6000, 1);
    }
    return 1;
}
