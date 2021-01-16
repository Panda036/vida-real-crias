#include YSI\y_hooks

new army_vehicles[9];

hook OnGameModeInit()
{
    //Army
    army_vehicles[0] = AddStaticVehicleEx(432, 279.7000100, 2030.5000000, 17.8000000, 268.0000000, 95, 10, 100); //Rhino
    army_vehicles[1] = AddStaticVehicleEx(432, 280.1000100, 2024.0000000, 17.8000000, 268.0000000, 95, 10, 100); //Rhino
    army_vehicles[2] = AddStaticVehicleEx(432, 280.3999900, 2017.6000000, 17.8000000, 268.0000000, 95, 10, 100); //Rhino
    army_vehicles[3] = AddStaticVehicleEx(433, 281.0000000, 1996.4000000, 18.2000000, 268.0000000, 95, 10, 100); //Barracks
    army_vehicles[4] = AddStaticVehicleEx(433, 281.0000000, 1990.2000000, 18.2000000, 270.0000000, 95, 10, 100); //Barracks
    army_vehicles[5] = AddStaticVehicleEx(433, 281.1000100, 1983.6000000, 18.2000000, 272.0000000, 95, 10, 100); //Barracks
    army_vehicles[6] = AddStaticVehicleEx(470, 282.7022, 1962.7131, 18.2000, 268.0000, -1, -1, 100); //Patriot
    army_vehicles[7] = AddStaticVehicleEx(470, 282.7181, 1956.1964, 18.2000, 270.0000, -1, -1, 100); //Patriot
    army_vehicles[8] = AddStaticVehicleEx(470, 282.8353, 1949.2556, 18.2000, 272.0000, -1, -1, 100); //Patriot
	return 1;
}

hook OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    for(new i; i < sizeof(army_vehicles); i++)
    {
        if(vehicleid == army_vehicles[i])
        {
            if(!ispassenger && vehicleid != INVALID_VEHICLE_ID && PlayerInfo[playerid][Profissao] != army)
            {
                ClearAnimations(playerid);
                SendClientMessage(playerid, Erro, "Veiculo exclusivo do Exército");
                return 1;
            }
        }
    }
    return 1;
}
