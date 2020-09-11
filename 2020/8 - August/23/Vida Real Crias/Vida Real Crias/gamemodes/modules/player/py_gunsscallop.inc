#include YSI\y_hooks

hook OnPlayerUpdate(playerid)
{
    static armedbody_pTick[MAX_PLAYERS];

    if(GetTickCount() - armedbody_pTick[playerid] > 113)
    {
        new weaponid[13], weaponammo[13];

        GetPlayerWeaponData(playerid, 2, weaponid[2], weaponammo[2]);
        GetPlayerWeaponData(playerid, 3, weaponid[3], weaponammo[3]);
        GetPlayerWeaponData(playerid, 4, weaponid[4], weaponammo[4]);
        GetPlayerWeaponData(playerid, 5, weaponid[5], weaponammo[5]);

        if(weaponid[2] && weaponammo[2] > 0)
        {
            if(GetPlayerWeapon(playerid) != weaponid[2])
            {
                if(!IsPlayerAttachedObjectSlotUsed(playerid, GS_PISTOL))
                {
                    SetPlayerAttachedObject(playerid, GS_PISTOL, GetWeaponModel(weaponid[2]), 8, -0.079999, -0.039999, 0.109999, -90.100006, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000);
                }
            }
            else
            {
                if(IsPlayerAttachedObjectSlotUsed(playerid, GS_PISTOL))
                {
                    RemovePlayerAttachedObject(playerid, GS_PISTOL);
                }
            }
        }
        else if(IsPlayerAttachedObjectSlotUsed(playerid, GS_PISTOL)) RemovePlayerAttachedObject(playerid, GS_PISTOL);


        if(weaponid[4] && weaponammo[4] > 0)
        {
            if(GetPlayerWeapon(playerid) != weaponid[4])
            {
                if(!IsPlayerAttachedObjectSlotUsed(playerid, GS_SHOTGUN))
                {
                    SetPlayerAttachedObject(playerid, GS_SHOTGUN, GetWeaponModel(weaponid[4]), 7, 0.000000, -0.100000, -0.080000, -95.000000, -10.000000, 0.000000, 1.000000, 1.000000, 1.000000);
                }
            }
            else
            {
                if(IsPlayerAttachedObjectSlotUsed(playerid, GS_SHOTGUN))
                {
                    RemovePlayerAttachedObject(playerid, GS_SHOTGUN);
                }
            }
        }
        else if(IsPlayerAttachedObjectSlotUsed(playerid, GS_SHOTGUN)) RemovePlayerAttachedObject(playerid, GS_SHOTGUN);


        if(weaponid[5] && weaponammo[5] > 0)
        {
            if(GetPlayerWeapon(playerid) != weaponid[5])
            {
                if(!IsPlayerAttachedObjectSlotUsed(playerid, GS_SUBMACHINEGUN))
                {
                    SetPlayerAttachedObject(playerid, GS_SUBMACHINEGUN, GetWeaponModel(weaponid[5]),1, 0.200000, -0.119999, -0.059999, 0.000000, 206.000000, 0.000000, 1.000000, 1.000000, 1.000000);
                }
            }
            else
            {
                if(IsPlayerAttachedObjectSlotUsed(playerid, GS_SUBMACHINEGUN))
                {
                    RemovePlayerAttachedObject(playerid, GS_SUBMACHINEGUN);
                }
            }
        }
        else if(IsPlayerAttachedObjectSlotUsed(playerid, GS_SUBMACHINEGUN)) RemovePlayerAttachedObject(playerid, GS_SUBMACHINEGUN);


        if(weaponid[3] && weaponammo[3] > 0)
        {
            if(GetPlayerWeapon(playerid) != weaponid[3])
            {
                if(!IsPlayerAttachedObjectSlotUsed(playerid, GS_MACHINEGUN))
                {
                    SetPlayerAttachedObject(playerid, GS_MACHINEGUN, GetWeaponModel(weaponid[3]), 1, 0.200000, -0.119999, -0.059999, 0.000000, 206.000000, 0.000000, 1.000000, 1.000000, 1.000000);
                }
            }
            else
            {
                if(IsPlayerAttachedObjectSlotUsed(playerid, GS_MACHINEGUN))
                {
                    RemovePlayerAttachedObject(playerid, GS_MACHINEGUN);
                }
            }
        }
        else if(IsPlayerAttachedObjectSlotUsed(playerid, GS_MACHINEGUN)) RemovePlayerAttachedObject(playerid, GS_MACHINEGUN);


        armedbody_pTick[playerid] = GetTickCount();
    }
    return 1;
}

stock GetWeaponModel(weaponid)
{
    switch(weaponid)
    {
        case 1: return 331;
        case 2: return 333;
        case 3: return 334;
        case 4: return 335;
        case 5: return 336;
        case 6: return 337;
        case 7: return 338;
        case 8: return 339;
        case 9: return 341;
        case 10: return 321;
        case 11: return 322;
        case 12: return 323;
        case 13: return 324;
        case 14: return 325;
        case 15: return 326;
        case 16: return 342;
        case 17: return 343;
        case 18: return 344;
        case 22: return 346;
        case 23: return 347;
        case 24: return 348;
        case 25: return 349;
        case 26: return 350;
        case 27: return 351;
        case 28: return 352;
        case 29: return 353;
        case 30: return 355;
        case 31: return 356;
        case 32: return 372;
        case 33: return 357;
        case 34: return 358;
        case 35: return 359;
        case 36: return 360;
        case 37: return 361;
        case 38: return 362;
        case 39: return 363;
        case 40: return 364;
        case 41: return 365;
        case 42: return 366;
        case 43: return 367;
        case 44: return 368;
        case 45: return 369;
        case 46: return 371;
        default: return -1;
    }
    return 1;
}
