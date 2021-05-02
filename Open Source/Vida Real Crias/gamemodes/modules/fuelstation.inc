#include YSI\y_hooks

hook OnGameModeInit()
{
    TDGasStation[0] = TextDrawCreate(260.000000, 421.466674, "Posto_de_Combustivel_~b~/abastecer");
    TextDrawLetterSize(TDGasStation[0], 0.273000, 1.436666);
    TextDrawAlignment(TDGasStation[0], 1);
    TextDrawColor(TDGasStation[0], -1);
    TextDrawSetOutline(TDGasStation[0], 1);
    TextDrawFont(TDGasStation[0], 1);
    TextDrawSetProportional(TDGasStation[0], 1);

    //tankes terrestres
    CreateDynamicObject(3465, 998.81830, -937.53778, 42.63040, 0.00000, 0.00000, 97.00000);
    CreateDynamicObject(3465, 1001.99487, -937.12622, 42.63040, 0.00000, 0.00000, 97.00000);
    CreateDynamicObject(3465, 1006.05127, -936.57892, 42.63040, 0.00000, 0.00000, 97.00000);
    CreateDynamicObject(3465, 1008.82568, -936.15973, 42.63040, 0.00000, 0.00000, 97.00000);
    CreateDynamicObject(3465, 655.62347, -571.19208, 16.69180, 0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3465, 655.66412, -569.60162, 16.69180, 0.00000, 0.00000, 0.00870);
    CreateDynamicObject(3465, 655.66412, -560.54688, 16.69180, 0.00000, 0.00000, 0.00870);
    CreateDynamicObject(3465, 655.66412, -558.92969, 16.69180, 0.00000, 0.00000, 0.00870);
    CreateDynamicObject(3465, 1385.07813, 458.29691, 20.64350, 0.00000, 0.00000, 65.00000);
    CreateDynamicObject(3465, 1383.39844, 459.07031, 20.64350, 0.00000, 0.00000, 65.00000);
    CreateDynamicObject(3465, 1380.63281, 460.27341, 20.64350, 0.00000, 0.00000, 65.00000);
    CreateDynamicObject(3465, 1378.96094, 461.03909, 20.64350, 0.00000, 0.00000, 65.00000);
    CreateDynamicObject(3465, 2120.82031, 914.71881, 11.25780, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(3465, 2114.90625, 914.71881, 11.25780, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(3465, 2109.04688, 914.71881, 11.25780, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(3465, 2120.82031, 925.50781, 11.25780, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(3465, 2114.90625, 925.50781, 11.25780, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(3465, 2109.04688, 925.50781, 11.25780, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(3465, 2207.69531, 2470.25000, 11.31250, 0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3465, 2207.69531, 2474.68750, 11.31250, 0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3465, 2207.69531, 2480.32813, 11.31250, 0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3465, 2196.89844, 2470.25000, 11.31250, 0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3465, 2196.89844, 2474.68750, 11.31250, 0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3465, 2196.89844, 2480.32813, 11.31250, 0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3465, 1602.00000, 2193.71094, 11.31250, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(3465, 1596.13281, 2193.71094, 11.31250, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(3465, 1590.35156, 2193.71094, 11.31250, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(3465, 1602.00000, 2204.50000, 11.31250, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(3465, 1596.13281, 2204.50000, 11.31250, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(3465, 1590.35156, 2204.50000, 11.31250, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(3465, 603.48438, 1707.23438, 7.49640, 0.00000, 0.00000, -53.00000);
    CreateDynamicObject(3465, 606.89838, 1702.21875, 7.49640, 0.00000, 0.00000, -53.00000);
    CreateDynamicObject(3465, 610.25000, 1697.26563, 7.49640, 0.00000, 0.00000, -53.00000);
    CreateDynamicObject(3465, 613.71881, 1692.26563, 7.49640, 0.00000, 0.00000, -53.00000);
    CreateDynamicObject(3465, 617.12500, 1687.45313, 7.49640, 0.00000, 0.00000, -53.00000);
    CreateDynamicObject(3465, 620.53131, 1682.46094, 7.49640, 0.00000, 0.00000, -53.00000);
    CreateDynamicObject(3465, 624.04688, 1677.60156, 7.49640, 0.00000, 0.00000, -53.00000);
    CreateDynamicObject(3465, 67.98980, 1220.99768, 19.45390, 0.00000, 0.00000, -15.00000);
    CreateDynamicObject(3465, 73.93900, 1219.50647, 19.45390, 0.00000, 0.00000, -15.00000);
    CreateDynamicObject(3465, 2141.67188, 2753.32031, 11.27340, 0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3465, 2147.53125, 2753.32031, 11.27340, 0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3465, 2153.31250, 2753.32031, 11.27340, 0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3465, 2153.31250, 2742.52344, 11.27340, 0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3465, 2147.51147, 2742.52588, 11.27340, 0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3465, 2141.67188, 2742.52344, 11.27340, 0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3465, -1327.03125, 2685.59375, 50.76980, 0.00000, 0.00000, 85.00000);
    CreateDynamicObject(3465, -1327.79688, 2680.12500, 50.76980, 0.00000, 0.00000, 85.00000);
    CreateDynamicObject(3465, -1328.57495, 2674.72754, 50.76980, 0.00000, 0.00000, 85.00000);
    CreateDynamicObject(3465, -1329.20313, 2669.28125, 50.76980, 0.00000, 0.00000, 85.00000);
    CreateDynamicObject(3465, -1465.47656, 1868.27344, 33.14650, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(3465, -1464.93750, 1860.56250, 33.14650, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(3465, -1477.85156, 1867.31250, 33.14650, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(3465, -1477.65625, 1859.73438, 33.14650, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(3465, 1941.60000, -1777.50000, 13.94070, 0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3465, 1941.60000, -1775.00000, 13.94070, 0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3465, 1941.60000, -1770.50000, 13.94070, 0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3465, 1941.60000, -1768.00000, 13.94070, 0.00000, 0.00000, 0.00000);

    //Tankes gasolina aquatico e aereo
    CreateDynamicObject(10814, 1552.89685, -2630.27246, 16.54213, 0.00000, 0.00000, 0.00000);
    CreateDynamicObject(10814, 1296.10840, 1398.54028, 14.30969, 0.00000, 0.00000, -90.00000);
    CreateDynamicObject(10814, 206.72815, 2526.25146, 19.83986, 0.00000, 0.00000, 180.00000);
    CreateDynamicObject(10814, -2313.23047, 2310.94458, -19.39908, -90.00000, 0.00000, 90.00000);
    CreateDynamicObject(10814, 2326.21558, 541.53815, -16.91660, -90.00000, 0.00000, 180.00000);
    CreateDynamicObject(10814, 166.36406, -1911.19470, -19.97166, -90.00000, 0.00000, -90.00000);
    CreateDynamicObject(10814, -1556.03345, 1238.40869, -17.34104, 270.00000, 0.00000, 0.00000);

    for(new i = 0; i < sizeof(FuelStationTerrestrial); i++)
    {
        CreateDynamicMapIcon(FuelStationTerrestrial[i][fst_x], FuelStationTerrestrial[i][fst_y], FuelStationTerrestrial[i][fst_z], 55, -1, -1, -1, -1, 200.0);
    }
    for(new i = 0; i < sizeof(FuelStationAquatic); i++)
    {
        CreateDynamicMapIcon(FuelStationAquatic[i][fsa_x], FuelStationAquatic[i][fsa_y], FuelStationAquatic[i][fsa_z], 55, -1, -1, -1, -1, 200.0);
    }
    for(new i = 0; i < sizeof(FuelStationAir); i++)
    {
        CreateDynamicMapIcon(FuelStationAir[i][fsair_x], FuelStationAir[i][fsair_y], FuelStationAir[i][fsair_z], 55, -1, -1, -1, -1, 200.0);
    }
    return 1;
}

hook OnPlayerConnect(playerid)
{
    RemoveBuildingForPlayer(playerid, 1676, 1941.6563, -1778.4531, 14.1406, 0.25);
    RemoveBuildingForPlayer(playerid, 1676, 1941.6563, -1774.3125, 14.1406, 0.25);
    RemoveBuildingForPlayer(playerid, 1676, 1941.6563, -1771.3438, 14.1406, 0.25);
    RemoveBuildingForPlayer(playerid, 1676, 1941.6563, -1767.2891, 14.1406, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, -1685.9688, 409.6406, 6.3828, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, -1679.3594, 403.0547, 6.3828, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, -1681.8281, 413.7813, 6.3828, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, -1675.2188, 407.1953, 6.3828, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, -1676.5156, 419.1172, 6.3828, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, -1669.9063, 412.5313, 6.3828, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, -1672.1328, 423.5000, 6.3828, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, -1665.5234, 416.9141, 6.3828, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, -2410.8047, 970.8516, 44.4844, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, -2410.8047, 976.1875, 44.4844, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, -2410.8047, 981.5234, 44.4844, 0.25);
    RemoveBuildingForPlayer(playerid, 3465, 2141.6719, 2753.3203, 11.2734, 0.25);
    RemoveBuildingForPlayer(playerid, 3465, 2141.6719, 2742.5234, 11.2734, 0.25);
    RemoveBuildingForPlayer(playerid, 3465, 2147.5313, 2753.3203, 11.2734, 0.25);
    RemoveBuildingForPlayer(playerid, 3465, 2147.5313, 2742.5234, 11.2734, 0.25);
    RemoveBuildingForPlayer(playerid, 3465, 2153.3125, 2753.3203, 11.2734, 0.25);
    RemoveBuildingForPlayer(playerid, 3465, 2153.3125, 2742.5234, 11.2734, 0.25);
    RemoveBuildingForPlayer(playerid, 3465, 2196.8984, 2480.3281, 11.3125, 0.25);
    RemoveBuildingForPlayer(playerid, 3465, 2196.8984, 2470.2500, 11.3125, 0.25);
    RemoveBuildingForPlayer(playerid, 3465, 2196.8984, 2474.6875, 11.3125, 0.25);
    RemoveBuildingForPlayer(playerid, 3465, 2207.6953, 2480.3281, 11.3125, 0.25);
    RemoveBuildingForPlayer(playerid, 3465, 2207.6953, 2470.2500, 11.3125, 0.25);
    RemoveBuildingForPlayer(playerid, 3465, 2207.6953, 2474.6875, 11.3125, 0.25);
    RemoveBuildingForPlayer(playerid, 3465, 2114.9063, 925.5078, 11.2578, 0.25);
    RemoveBuildingForPlayer(playerid, 3465, 2109.0469, 925.5078, 11.2578, 0.25);
    RemoveBuildingForPlayer(playerid, 3465, 2109.0469, 914.7188, 11.2578, 0.25);
    RemoveBuildingForPlayer(playerid, 3465, 2114.9063, 914.7188, 11.2578, 0.25);
    RemoveBuildingForPlayer(playerid, 3465, 2120.8203, 925.5078, 11.2578, 0.25);
    RemoveBuildingForPlayer(playerid, 3465, 2120.8203, 914.7188, 11.2578, 0.25);
    RemoveBuildingForPlayer(playerid, 3465, 1590.3516, 2193.7109, 11.3125, 0.25);
    RemoveBuildingForPlayer(playerid, 3465, 1596.1328, 2193.7109, 11.3125, 0.25);
    RemoveBuildingForPlayer(playerid, 3465, 1602.0000, 2193.7109, 11.3125, 0.25);
    RemoveBuildingForPlayer(playerid, 3465, 1596.1328, 2204.5000, 11.3125, 0.25);
    RemoveBuildingForPlayer(playerid, 3465, 1602.0000, 2204.5000, 11.3125, 0.25);
    RemoveBuildingForPlayer(playerid, 3465, 1590.3516, 2204.5000, 11.3125, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, -1477.6563, 1859.7344, 31.8203, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, -1464.9375, 1860.5625, 31.8203, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, -1477.8516, 1867.3125, 31.8203, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, -1465.4766, 1868.2734, 31.8203, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, -1329.2031, 2669.2813, 49.4531, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, -1328.5859, 2674.7109, 49.4531, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, -1327.7969, 2680.1250, 49.4531, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, -1327.0313, 2685.5938, 49.4531, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, 624.0469, 1677.6016, 6.1797, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, 603.4844, 1707.2344, 6.1797, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, 606.8984, 1702.2188, 6.1797, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, 610.2500, 1697.2656, 6.1797, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, 613.7188, 1692.2656, 6.1797, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, 617.1250, 1687.4531, 6.1797, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, 620.5313, 1682.4609, 6.1797, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, -2246.7031, -2559.7109, 31.0625, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, -2241.7188, -2562.2891, 31.0625, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, 655.6641, -571.2109, 15.3594, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, 655.6641, -569.6016, 15.3594, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, 655.6641, -558.9297, 15.3594, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, 655.6641, -560.5469, 15.3594, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, 1378.9609, 461.0391, 19.3281, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, 1380.6328, 460.2734, 19.3281, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, 1385.0781, 458.2969, 19.3281, 0.25);
    RemoveBuildingForPlayer(playerid, 1686, 1383.3984, 459.0703, 19.3281, 0.25);
    RemoveBuildingForPlayer(playerid, 1676, -92.1016, -1161.7891, 2.9609, 0.25);
    RemoveBuildingForPlayer(playerid, 1676, -97.0703, -1173.7500, 3.0313, 0.25);
    RemoveBuildingForPlayer(playerid, 1676, -85.2422, -1165.0313, 2.6328, 0.25);
    RemoveBuildingForPlayer(playerid, 1676, -90.1406, -1176.6250, 2.6328, 0.25);

    SetTimerEx("OnPlayerGasStation", 1000, true, "d", playerid);
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == MAIN_FUEL && response)
    {
        switch(listitem)
        {
            case 0:
            {
                if(!PlayerInfo[playerid][havegallon])
                    return SendClientMessage(playerid, Erro, "Você não tem galão de combustível");

                if(PlayerInfo[playerid][gallon])
                    return SendClientMessage(playerid, Erro, "Seu galão já está cheio");

                if(PlayerInfo[playerid][Dinheiro] < 50)
                    return SendClientMessage(playerid, Erro, "Você não tem $50 em mãos");

                PlayerInfo[playerid][gallon] = 10;
                PlayerInfo[playerid][Dinheiro] -= 50;
                UpdatePlayerMoney(playerid);

                new query[100];
                mysql_format(IDConexao, query, 100, "UPDATE `Itens` SET `gallon`='10' WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
                mysql_query(IDConexao, query);

                SendClientMessage(playerid, Yellow, "Você abasteceu seu galão com 10 litros e gastou $50");
                return 1;
            }
            case 1:
            {
                #define PRICE_GAS 15
                #define LIMIT_GAS 30

                if(PlayerInfo[playerid][jetpackgas] >= LIMIT_GAS)
                    return SendClientMessage(playerid, Erro, "Seu jetpack já está cheio");

                new value[MAX_PLAYERS];

                value[playerid] = ( LIMIT_GAS - PlayerInfo[playerid][jetpackgas] );

                if(PlayerInfo[playerid][Dinheiro] < ( value[playerid] * PRICE_GAS ))
                {
                    format(String, 128, "Dinheiro insuficiente, 1m3 * $%d", PRICE_GAS);
                    SendClientMessage(playerid, Erro, String);
                    return 1;
                }

                PlayerInfo[playerid][jetpackgas] += value[playerid];
                PlayerInfo[playerid][Dinheiro] -= ( value[playerid] * PRICE_GAS );
                UpdatePlayerMoney(playerid);

                new query[100];
                mysql_format(IDConexao, query, 100, "UPDATE `Itens` SET `jetpackgas`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][jetpackgas], PlayerInfo[playerid][ID]);
                mysql_query(IDConexao, query);

                format(String, 128, "Você abasteceu %d M3 em seu Jetpack e lê custou $%s", value[playerid], IsMoney((value[playerid] * PRICE_GAS), "."));
                SendClientMessage(playerid, Yellow, String);
                return 1;
            }
            case 2:
            {
                if(!IsPlayerInAnyVehicle(playerid))
                    return SendClientMessage(playerid, Erro, "Você não está em um veículo");

                if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
                    return SendClientMessage(playerid, Erro, "Você não está como motorista do veículo");

                if(Fueling[playerid])
                    return SendClientMessage(playerid, Erro, "Você já está abastecendo esse veículo");

                new mot, lu, alar, por, cap, porma, ob, vehicleid = GetPlayerVehicleID(playerid);

                GetVehicleParamsEx(vehicleid, mot, lu, alar, por, cap, porma, ob);

                if(mot)
                    return SendClientMessage(playerid, Erro, "O veículo precisa estar desligado");

                for(new i = 0; i < MAX_VEHICLES; i++)
                {
                    if(vehicleid == PublicVehicle[i][pv_vehicle])
                    {
                        if(PublicVehicle[i][pv_gasoline] > 40)
                            return SendClientMessage(playerid, Erro, "Este veículo já está com tanque cheio");

                        if(IsPlayerFuelTerrestrial(playerid) && IsPlayerInVehicleNotTerrestrial(playerid))
                            return SendClientMessage(playerid, Erro, "Esse posto só é permitido veículos terrestres");

                        if(IsPlayerFuelAir(playerid) && !IsPlayerInVehicleAir(playerid))
                            return SendClientMessage(playerid, Erro, "Esse posto só é permitido veículos aéreos");

                        if(IsPlayerFuelAquatic(playerid) && !IsPlayerInVehicleAquatic(playerid))
                            return SendClientMessage(playerid, Erro, "Esse posto só é permitido veículos aquáticos");

                        Fueling[playerid] = true;
                        OnVehicleFuel(playerid, i);
                        return 1;
                    }
                }
                return 1;
            }
        }
        return 1;
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(PRESSED(KEY_YES) && Fueling[playerid])
    {
        Fueling[playerid] = false;
        SendClientMessage(playerid, Yellow, "O abastecimento foi cancelado");
        return 1;
    }
	return 1;
}

forward OnVehicleFuel(playerid, vehicleid);
public OnVehicleFuel(playerid, vehicleid)
{
    if(Fueling[playerid])
    {
        new mot, lu, alar, por, cap, porma, ob;

        GetVehicleParamsEx(PublicVehicle[vehicleid][pv_vehicle], mot, lu, alar, por, cap, porma, ob);

        if(PlayerInfo[playerid][Dinheiro] < 5)
        {
            Spent[playerid] = 0;
            Fueled[playerid] = 0;
            Fueling[playerid] = false;
            format(String, 128, "Você não tem dinheiro suficiente");
            SendClientMessage(playerid, Erro, String);
            return 1;
        }
        if(mot)
        {
            Fueling[playerid] = false;
            OnVehicleFuel(playerid, vehicleid);
            SendClientMessage(playerid, Yellow, "O abastecimento foi cancelado");
            return 1;
        }
        if((!IsPlayerInVehicleNotTerrestrial(playerid) && PublicVehicle[vehicleid][pv_gasoline] >= 60) || (IsPlayerInVehicleAir(playerid) && PublicVehicle[vehicleid][pv_gasoline] >= 400) || (IsPlayerInVehicleAquatic(playerid) && PublicVehicle[vehicleid][pv_gasoline] >= 100))
        {
            Fueling[playerid] = false;
            OnVehicleFuel(playerid, vehicleid);
            return 1;
        }

        Fueled[playerid]++;
        PublicVehicle[vehicleid][pv_gasoline]++;

        Spent[playerid] += 5;
        PlayerInfo[playerid][Dinheiro] -= 5;

        UpdatePlayerMoney(playerid);

        SetTimerEx("OnVehicleFuel", 500, false, "dd", playerid, vehicleid);
    }
    else if(!Fueling[playerid] || !PlayerInfo[playerid][Logado])
    {
        format(String, 128, "Você abasteceu nesse veículo %d litros e gastou $%s", Fueled[playerid], IsMoney(Spent[playerid], "."));
        SendClientMessage(playerid, Yellow, String);

        Spent[playerid] = 0;
        Fueled[playerid] = 0;
        Fueling[playerid] = false;
    }
    return 1;
}

forward OnPlayerGasStation(playerid);
public OnPlayerGasStation(playerid)
{
    if(!PlayerInfo[playerid][Logado]) return 0;

    if(IsPlayerFuelTerrestrial(playerid) || IsPlayerFuelAir(playerid) || IsPlayerFuelAquatic(playerid))
    {
        TextDrawShowForPlayer(playerid, TDGasStation[0]);
    }
    else
    {
        TextDrawHideForPlayer(playerid, TDGasStation[0]);
    }
    return 1;
}

stock IsPlayerFuelTerrestrial(playerid)
{
    for(new i = 0; i < sizeof(FuelStationTerrestrial); i++)
    {
        if(IsPlayerInRangeOfPoint(playerid, FuelStationTerrestrial[i][fst_a], FuelStationTerrestrial[i][fst_x], FuelStationTerrestrial[i][fst_y], FuelStationTerrestrial[i][fst_z])) return true;
    }
    return false;
}

stock IsPlayerFuelAquatic(playerid)
{
    for(new i = 0; i < sizeof(FuelStationAquatic); i++)
    {
        if(IsPlayerInRangeOfPoint(playerid, FuelStationAquatic[i][fsa_a], FuelStationAquatic[i][fsa_x], FuelStationAquatic[i][fsa_y], FuelStationAquatic[i][fsa_z])) return true;
    }
    return false;
}

stock IsPlayerFuelAir(playerid)
{
    for(new i = 0; i < sizeof(FuelStationAir); i++)
    {
        if(IsPlayerInRangeOfPoint(playerid, FuelStationAir[i][fsair_a], FuelStationAir[i][fsair_x], FuelStationAir[i][fsair_y], FuelStationAir[i][fsair_z])) return true;
    }
    return false;
}

stock IsPlayerInVehicleAir(playerid)
{
    switch(GetPlayerVehicleID(playerid))
    {
        case 417: return 1;
        case 425: return 1;
        case 447: return 1;
        case 460: return 1;
        case 469: return 1;
        case 476: return 1;
        case 487: return 1;
        case 488: return 1;
        case 497: return 1;
        case 511..513: return 1;
        case 519: return 1;
        case 520: return 1;
        case 548: return 1;
        case 553: return 1;
        case 563: return 1;
        case 577: return 1;
        case 592: return 1;
        case 593: return 1;
    }
    return 1;
}

stock IsPlayerInVehicleAquatic(playerid)
{
    switch(GetPlayerVehicleID(playerid))
    {
        case 472: return 1;
        case 473: return 1;
        case 493: return 1;
        case 595: return 1;
        case 484: return 1;
        case 430: return 1;
        case 453: return 1;
        case 452: return 1;
        case 446: return 1;
        case 454: return 1;
    }
    return 1;
}

stock IsPlayerInVehicleNotTerrestrial(playerid)
{
    switch(GetPlayerVehicleID(playerid))
    {
        case 472: return 1;
        case 473: return 1;
        case 493: return 1;
        case 595: return 1;
        case 484: return 1;
        case 430: return 1;
        case 453: return 1;
        case 452: return 1;
        case 446: return 1;
        case 454: return 1;
        case 417: return 1;
        case 425: return 1;
        case 447: return 1;
        case 460: return 1;
        case 469: return 1;
        case 476: return 1;
        case 487: return 1;
        case 488: return 1;
        case 497: return 1;
        case 511..513: return 1;
        case 519: return 1;
        case 520: return 1;
        case 548: return 1;
        case 553: return 1;
        case 563: return 1;
        case 577: return 1;
        case 592: return 1;
        case 593: return 1;
    }
	return false;
}

CMD:abastecer(playerid)
{
    if(!IsPlayerFuelTerrestrial(playerid) && !IsPlayerFuelAir(playerid) && !IsPlayerFuelAquatic(playerid))
        return SendClientMessage(playerid, Erro, "Você não está em um posto de combustível");

    ShowPlayerDialog(playerid, MAIN_FUEL, DIALOG_STYLE_LIST, "{FF8000}Abastecer", "{FFFFFF}Galão\nJetpack\nVeículo", "Continuar", "Cancelar");
    return 1;
}
