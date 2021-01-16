#include YSI\y_hooks

#define takedamage(%1,%2,%3,%4) %1 | (%2 << 1) | (%3 << 2) | (%4 << 3)

hook OnGameModeInit()
{
    SetTimer("wheel", 1000, true);
    return 1;
}

forward wheel();
public wheel()
{
    new Dano[4], Float:x, Float:y, Float:z;

    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerInAnyVehicle(i) && PlayerToPoint(2.0, i, x, y, z))
        {
            GetVehicleDamageStatus(GetPlayerVehicleID(i), Dano[0], Dano[1], Dano[2], Dano[3]);
            UpdateVehicleDamageStatus(GetPlayerVehicleID(i), Dano[0], Dano[1], Dano[2], takedamage(1, 1, 1, 1));
            GameTextForPlayer(i,"~w~Pneu Furado",6000,1);
    	}
    }
    return 1;
}
