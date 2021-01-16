#include YSI\y_hooks

new aeronautics_vehicles[7];

hook OnGameModeInit()
{
    //Aeronautics
    aeronautics_vehicles[0] = AddStaticVehicleEx(548, 308.2000100, 2047.3000000, 19.5000000, 180.0000000, 245, 245, 100); //Cargobob
    aeronautics_vehicles[1] = AddStaticVehicleEx(520, 315.7999900, 2020.8000000, 18.6000000, 90.0000000, -1, -1, 100);    //Hydra
    aeronautics_vehicles[2] = AddStaticVehicleEx(520, 315.2000100, 2004.6000000, 18.6000000, 90.0000000, -1, -1, 100);    //Hydra
    aeronautics_vehicles[3] = AddStaticVehicleEx(520, 314.7000100, 1989.1000000, 18.6000000, 88.0000000, -1, -1, 100);    //Hydra
    aeronautics_vehicles[4] = AddStaticVehicleEx(425, 313.7999900, 1973.1000000, 18.5000000, 90.0000000, 95, 10, 100);    //Hunter
    aeronautics_vehicles[5] = AddStaticVehicleEx(425, 313.3999900, 1958.9000000, 18.5000000, 85.9950000, 95, 10, 100);    //Hunter
    aeronautics_vehicles[6] = AddStaticVehicleEx(425, 313.0000000, 1946.0000000, 18.5000000, 83.9960000, 95, 10, 100);    //Hunter
	return 1;
}

hook OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    for(new i; i < sizeof(aeronautics_vehicles); i++)
    {
        if(vehicleid == aeronautics_vehicles[i])
        {
            if(!ispassenger && vehicleid != INVALID_VEHICLE_ID && PlayerInfo[playerid][Profissao] != aeronautics)
            {
                ClearAnimations(playerid);
                SendClientMessage(playerid, Erro, "Veiculo exclusivo da Aeronáutica");
                return 1;
            }
        }
    }
    return 1;
}
