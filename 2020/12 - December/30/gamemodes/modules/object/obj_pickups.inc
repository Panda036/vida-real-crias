#include YSI\y_hooks

new PickupDP;
new TimerPickUP[MAX_PLAYERS];

hook OnGameModeInit()
{
    for(new pickupid = 0; pickupid < MAX_PLACE_PUBLIC; pickupid++)
    {
        CreateDynamicPickup(19134, 1, EnterExit[pickupid][ee_x], EnterExit[pickupid][ee_y], EnterExit[pickupid][ee_z], WORLD_DEFAULT, 0);
        CreateDynamicPickup(19132, 1, EnterExit[pickupid][ee_lx], EnterExit[pickupid][ee_ly], EnterExit[pickupid][ee_lz]);
    }

    // DP Weapons
    PickupDP = CreateDynamicPickup(1242, 1, 254.1715 ,74.3339, 1003.6406);
    return 1;
}

public OnPlayerPickUpDynamicPickup(playerid, pickupid)
{
    if((gettime() - TimerPickUP[playerid]) >= 2)
    {
        TimerPickUP[playerid] = gettime();

        if(pickupid == PickupDP)
        {
            SendClientMessage(playerid, Red, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            SendClientMessage(playerid, White, "•» Para retirar o uniforme, digite: /removeruniforme");
            SendClientMessage(playerid, White, "•» Para equipar armas, digite: /equipar");
            SendClientMessage(playerid, Red, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            return 1;
        }

        GetCompanyID(playerid, pickupid);
        GetHouseID(playerid, pickupid);
        GetPickUpProfission(playerid, pickupid);
        GetPickUpPublics(playerid);
        return 1;
    }
    return 1;
}

stock GetPickUpPublics(playerid)
{
    for(new i = 0; i < MAX_PLACE_PUBLIC; ++i)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, EnterExit[i][ee_x], EnterExit[i][ee_y], EnterExit[i][ee_z]))
            return SendClientMessage(playerid, White, "Para entrar digite {CFCDCD}'/Entrar'{FFFFFF} ou pressione a tecla {CFCDCD}'F'");

        //if(IsPlayerInRangeOfPoint(playerid, 2.0, EnterExit[i][ee_lx], EnterExit[i][ee_ly], EnterExit[i][ee_lz])) SendClientMessage(playerid, White, "Para sair digite {CFCDCD}'/Sair'{FFFFFF} ou pressione a tecla {CFCDCD}'F'");
    }
	return 1;
}
