#include YSI\y_hooks

new navy_vehicles[2];

hook OnGameModeInit()
{
    //Navy
    navy_vehicles[0] = AddStaticVehicleEx(595, -1441.1146, 510.0490, 0.8029, 90.0000, -1, -1, 100); //Launch
    navy_vehicles[1] = AddStaticVehicleEx(595, -1441.1146, 505.0194, 0.8029, 90.0000, -1, -1, 100); //Launch
	return 1;
}

hook OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    for(new i; i < sizeof(navy_vehicles); i++)
    {
        if(vehicleid == navy_vehicles[i])
        {
            if(!ispassenger && vehicleid != INVALID_VEHICLE_ID && PlayerInfo[playerid][Profissao] != navy)
            {
                ClearAnimations(playerid);
                SendClientMessage(playerid, Erro, "Veiculo exclusivo da Marinha");
                return 1;
            }
        }
    }
    return 1;
}
