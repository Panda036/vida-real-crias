#include YSI\y_hooks

#define MAIN_FUEL       5100

new Text:TDGasStation[1];
new bool:Fueling[MAX_PLAYERS];
new Fueled[MAX_PLAYERS];
new Spent[MAX_PLAYERS];

enum e_fst
{
    Float:fst_x,
    Float:fst_y,
    Float:fst_z,
    Float:fst_a
};

enum e_fsa
{
    Float:fsa_x,
    Float:fsa_y,
    Float:fsa_z,
    Float:fsa_a
};

enum e_fsair
{
    Float:fsair_x,
    Float:fsair_y,
    Float:fsair_z,
    Float:fsair_a
};

new FuelStationTerrestrial[17][e_fst] =
{
    {1942.3728, -1772.8689, 13.6406, 20.0},
    {1004.6576, -936.7656, 42.3281, 20.0},
    {655.5648, -565.1674, 16.3359, 20.0},
    {-90.8110, -1168.4828, 2.4241, 30.0},
    {-1606.4144, -2713.7371, 48.5335, 30.0},
    {-2244.3455, -2561.0513, 31.9219, 20.0},
    {1381.6041, 459.9374, 20.3452, 20.0},
    {-1677.2299, 411.9955, 7.1797, 30.0},
    {-2410.0356, 976.0281, 45.4251, 30.0},
    {2114.9490, 920.1870, 10.8203, 30.0},
    {1595.6119, 2199.3965, 10.8203, 30.0},
    {2147.4045, 2747.9360, 10.8203, 30.0},
    {611.9534, 1694.7549, 6.9922, 40.0},
    {70.2273, 1218.1195, 18.8120, 20.0},
    {-737.1921, 2744.6824, 47.2266, 10.0},
    {-1328.4478, 2677.4004, 50.0625, 10.0},
    {-1471.4187, 1862.7681, 32.6328, 10.0}
};

new FuelStationAquatic[4][e_fsa] =
{
    {-2318.9358, 2315.9397, 0.1964, 30.0},
    {176.6720, -1912.6235, -0.5952, 30.0},
    {-1551.2750, 1250.0265, -0.7692, 30.0},
    {2325.2834, 532.4463, -0.5256, 30.0}
};

new FuelStationAir[4][e_fsair] =
{
    {1553.7606, -2624.0488, 13.5469, 50.0},
    {-1129.8385, -169.4834, 14.1484, 50.0},
    {1305.2479, 1395.1956, 10.8203, 50.0},
    {203.5974, 2515.5615, 16.6302, 50.0}
};

hook OnGameModeInit()
{
    TDGasStation[0] = TextDrawCreate(260.000000, 421.466674, "Posto_de_Combustivel_~b~/abastecer");
    TextDrawLetterSize(TDGasStation[0], 0.273000, 1.436666);
    TextDrawAlignment(TDGasStation[0], 1);
    TextDrawColor(TDGasStation[0], -1);
    TextDrawSetOutline(TDGasStation[0], 1);
    TextDrawFont(TDGasStation[0], 1);
    TextDrawSetProportional(TDGasStation[0], 1);

    CreateObject(10814, 1552.89685, -2630.27246, 16.54213, 0.00000, 0.00000, 0.00000);
    CreateObject(10814, 1296.10840, 1398.54028, 14.30969, 0.00000, 0.00000, -90.00000);
    CreateObject(10814, 206.72815, 2526.25146, 19.83986, 0.00000, 0.00000, 180.00000);
    CreateObject(10814, -2313.23047, 2310.94458, -19.39908, -90.00000, 0.00000, 90.00000);
    CreateObject(10814, 2326.21558, 541.53815, -16.91660, -90.00000, 0.00000, 180.00000);
    CreateObject(10814, 166.36406, -1911.19470, -19.97166, -90.00000, 0.00000, -90.00000);
    CreateObject(10814, -1556.03345, 1238.40869, -17.34104, 270.00000, 0.00000, 0.00000);

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
    OnPlayerGasStation(playerid);
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

                if(PlayerInfo[playerid][Dinheiro] < 100)
                    return SendClientMessage(playerid, Erro, "Você não tem $100 em mãos");

                PlayerInfo[playerid][Dinheiro] -= 100;
                PlayerInfo[playerid][gallon] = 10;
                UpdatePlayerMoney(playerid);

                new _str[100];
                mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Itens` SET `gallon`='10' WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
                mysql_query(IDConexao, _str);

                SendClientMessage(playerid, Yellow, "Você abasteceu seu galão com 10 litros");
            }
            case 1:
            {
                if(!IsPlayerInAnyVehicle(playerid))
                    return SendClientMessage(playerid, Erro, "Você não está em um veículo");

                new mot, lu, alar, por, cap, porma, ob;

                GetVehicleParamsEx(GetPlayerVehicleID(playerid), mot, lu, alar, por, cap, porma, ob);

                if(mot == 1)
                    return SendClientMessage(playerid, Erro, "O veículo precisa estar desligado");

                for(new i = 0; i < MAX_PLAYERS; i++)
                {
                    for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
                    {
                        if(GetPlayerVehicleID(playerid) == DataVehicles[slot][i][vvehicle] && DataVehicles[slot][i][vconnected])
                        {
                            if(DataVehicles[slot][i][vgasoline] > 40)
                                return SendClientMessage(playerid, Erro, "Este veículo já está com tanque cheio");

                            if(IsPlayerFuelTerrestrial(playerid) && IsPlayerInVehicleNotTerrestrial(playerid))
                                return SendClientMessage(playerid, Erro, "Esse posto só é permitido veículos terrestres");

                            if(IsPlayerFuelAir(playerid) && !IsPlayerInVehicleAir(playerid))
                                return SendClientMessage(playerid, Erro, "Esse posto só é permitido veículos aéreos");

                            if(IsPlayerFuelAquatic(playerid) && !IsPlayerInVehicleAquatic(playerid))
                                return SendClientMessage(playerid, Erro, "Esse posto só é permitido veículos aquáticos");

                            Fueling[playerid] = true;
                            OnVehicleFuel(playerid, i, slot);
                            return 1;
                        }
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

forward OnVehicleFuel(playerid, ownerid, slot);
public OnVehicleFuel(playerid, ownerid, slot)
{
    if(Fueling[playerid])
    {
        new mot, lu, alar, por, cap, porma, ob;

        GetVehicleParamsEx(DataVehicles[slot][ownerid][vvehicle],  mot, lu, alar, por, cap, porma, ob);

        if(mot == 1)
        {
            Spent[playerid] = 0;
            Fueled[playerid] = 0;
            Fueling[playerid] = false;
            OnVehicleFuel(playerid, ownerid, slot);
            SendClientMessage(playerid, Yellow, "O abastecimento foi cancelado");
            return 1;
        }

        if(!IsPlayerInVehicleNotTerrestrial(playerid) && DataVehicles[slot][ownerid][vgasoline] == 60)
        {
            Spent[playerid] = 0;
            Fueled[playerid] = 0;
            Fueling[playerid] = false;
            OnVehicleFuel(playerid, ownerid, slot);
            return 1;
        }
        else if(IsPlayerInVehicleAir(playerid) && DataVehicles[slot][ownerid][vgasoline] == 400)
        {
            Spent[playerid] = 0;
            Fueled[playerid] = 0;
            Fueling[playerid] = false;
            OnVehicleFuel(playerid, ownerid, slot);
            return 1;
        }
        else if(IsPlayerInVehicleAquatic(playerid) && DataVehicles[slot][ownerid][vgasoline] == 100)
        {
            Spent[playerid] = 0;
            Fueled[playerid] = 0;
            Fueling[playerid] = false;
            OnVehicleFuel(playerid, ownerid, slot);
            return 1;
        }

        if(PlayerInfo[playerid][Dinheiro] < 10)
        {
            Spent[playerid] = 0;
            Fueled[playerid] = 0;
            Fueling[playerid] = false;
            format(String, sizeof(String), "Você não tem dinheiro suficiente");
            SendClientMessage(playerid, Erro, String);
            return 1;
        }

        Fueled[playerid]++;
        DataVehicles[slot][ownerid][vgasoline]++;

        Spent[playerid] += 5;
        PlayerInfo[playerid][Dinheiro] -= 5;

        UpdatePlayerMoney(playerid);

        SetTimerEx("OnVehicleFuel", 500, false, "ddd", playerid, ownerid, slot);
    }
    else if(!Fueling[playerid] || !PlayerInfo[playerid][Logado] || !PlayerInfo[ownerid][Logado])
    {
        format(String, sizeof(String), "Você abasteceu nesse veículo %d litros e gastou $%s", Fueled[playerid], IsMoney(Spent[playerid], "."));
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

    SetTimerEx("OnPlayerGasStation", 1000, true, "d", playerid);
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

    if(!IsPlayerInAnyVehicle(playerid))
        return SendClientMessage(playerid, Erro, "Você não está em um veículo");

    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
        return SendClientMessage(playerid, Erro, "Você não está como motorista do veículo");

    if(Fueling[playerid])
        return SendClientMessage(playerid, Erro, "Você já está abastecendo esse veículo");

    ShowPlayerDialog(playerid, MAIN_FUEL, DIALOG_STYLE_LIST, "{FF8000}Abastecer", "{FFFFFF}Abastecer Galão\nAbastecer Veículo", "Continuar", "Cancelar");
    return 1;
}
