#include YSI\y_hooks

enum e_rg
{
    rg_gas,
    Float:rg_x,
    Float:rg_y,
    Float:rg_z
};

new RandomGas[MAX_GAS_MAP][e_rg] =
{
    {-1, 2288.86572, -1049.11096, 48.97720},
    {-1, 2318.87183, -1050.88062, 51.89790},
    {-1, 2334.54199, -1050.31628, 51.85080},
    {-1, 2356.69141, -1055.07117, 53.58660},
    {-1, 2370.55493, -1049.16211, 53.60160},
    {-1, 2375.72412, -1034.46643, 53.70900},
    {-1, 2357.94897, -1037.86438, 53.60720}, //Favela
    {-1, 15.32501, 948.90826, 19.43990},
    {-1, -37.56480, 968.00812, 19.28860},
    {-1, -61.15980, 935.32593, 20.27170},
    {-1, -59.97190, 918.85022, 21.38200},
    {-1, -58.43860, 893.84192, 21.45000},
    {-1, -145.60698, 934.13281, 18.97950},
    {-1, -147.90199, 906.67432, 18.38680},
    {-1, -119.96430, 875.05127, 18.14990},
    {-1, 64.30770, 996.04633, 13.84770}, //Fort Carson
    {-1, -906.30292, 1511.90662, 25.34900},
    {-1, -888.39783, 1514.27563, 25.38580},
    {-1, -877.27173, 1531.70190, 25.40590},
    {-1, -904.60999, 1532.11987, 25.34660},
    {-1, -882.03833, 1538.10425, 25.40480},
    {-1, -907.67560, 1543.08167, 25.34720},
    {-1, -881.15503, 1553.68677, 25.34950},
    {-1, -883.72540, 1563.28552, 25.32920}, //Las Barrancas
    {-1, -1496.89685, 2685.49268, 55.34640},
    {-1, -1486.51965, 2702.36816, 55.34640},
    {-1, -1466.00635, 2688.75098, 55.34640},
    {-1, -1515.92017, 2693.60034, 55.34640},
    {-1, -1536.88440, 2687.05688, 55.34640},
    {-1, -1550.40271, 2695.10669, 55.34640},
    {-1, -1564.88574, 2705.95825, 55.34640},
    {-1, -1592.65002, 2706.78711, 54.98070} //El Quebrados
};

enum e_vt
{
    Float:vt_x,
    Float:vt_y,
    Float:vt_z
};

new vr_thief[5][e_vt] =
{
    {-447.96, 2203.27, 43.13},
    {-452.11, 2203.31, 43.13},
    {-439.61, 2203.11, 43.13},
    {-443.75, 2203.22, 43.13},
    {-435.39, 2203.08, 43.13}
};

new GasObjects[MAX_GAS_VEHICLE][MAX_VEHICLES];
new bool:GasCaught[MAX_PLAYERS];
new GasCP;
new GasAll;
new Text3D:GasAllLabel;
new GasAllMap[MAX_PLAYERS];

hook OnGameModeInit()
{
    GasAllLabel = CreateDynamic3DTextLabel("{FFFFFF}Roubos de Gás\n{F29B0D}0", 0xFFFFFFFF, -350.51, 2210.66, 42.48, 50.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
    GasCP = CreateDynamicRaceCP(2, -350.51, 2210.66, 42.48, -1, -1, -1, 5.0, -1, -1, -1, 200.0);

    for(new gasid = 0; gasid < MAX_GAS_MAP; gasid++)
    {
        RandomGas[gasid][rg_gas] = CreateDynamicObject(1370, RandomGas[gasid][rg_x], RandomGas[gasid][rg_y], RandomGas[gasid][rg_z], 0.0, 0.0, 0.0);
    }

    CreateVehicleLocation(-439.69, 2216.75, 42.42);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    left_pfs_thief(playerid);
    return 1;
}

hook OnVehicleDeath(vehicleid, killerid)
{
    if(PlayerInfo[killerid][Profissao] == thief)
    {
        GasRemoveVehicle(vehicleid);
        return 1;
    }
	return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(PRESSED(KEY_NO) && PlayerInfo[playerid][Profissao] == thief) //N
    {
        if(GasCaught[playerid])
        {
            GasCaught[playerid] = false;
            SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
            RemovePlayerAttachedObject(playerid, ATTACH_INDEX_THIEF);

            SendClientMessage(playerid, color_thief, "Gás removido");
            return 1;
        }

        new Float:x, Float:y, Float:z, vehicleid = LastVehicle[playerid];

        if(GetVehicleModel(vehicleid) != 478)
            return SendClientMessage(playerid, Erro, "Este veículo não pertence à profissão profissão");

        GetVehiclePos(vehicleid, x, y, z);

        if(!IsPlayerInRangeOfPoint(playerid, 20.0, x, y, z))
            return SendClientMessage(playerid, Erro, "Seu veículo profissão está longe, aproxime-o");


        for(new gasid = 0; gasid < MAX_GAS_MAP; gasid++)
        {
            if(!IsPlayerInRangeOfPoint(playerid, 2.0, RandomGas[gasid][rg_x], RandomGas[gasid][rg_y], RandomGas[gasid][rg_z])) continue;

            if(RandomGas[gasid][rg_gas] == -1) break;

            for(new slot = 0; slot < MAX_GAS_VEHICLE; slot++)
            {
                if(GasCountVehicle(vehicleid) >= MAX_GAS_VEHICLE)
                    return SendClientMessage(playerid, Erro, "Não tem mais espaço em seu veículo, descarregue-o");

                PlayerInfo[playerid][Estrelas] += 1;
                UpdatePlayerStar(playerid);

                GasCaught[playerid] = true;

                DestroyDynamicObject(RandomGas[gasid][rg_gas]);
                RandomGas[gasid][rg_gas] = -1;

                SetTimerEx("ReloadingGas", 300000, false, "d", gasid);

                SetPlayerSpecialAction(playerid, SPECIAL_ACTION_CARRY);
                SetPlayerAttachedObject(playerid, ATTACH_INDEX_THIEF, 1370, 6, 0.027001, 0.236, -0.183, -22.3, 0, 0, 0.886001, 0.776002, 0.784);
                break;
            }
            break;
        }
        return 1;
    }
    if(PRESSED(KEY_CTRL_BACK) && PlayerInfo[playerid][Profissao] == thief) //H
    {
        if(!GasCaught[playerid])
            return 1;

        if(GetVehicleModel(LastVehicle[playerid]) != 478)
            return SendClientMessage(playerid, Erro, "Seu último veículo não é veículo profissão");

        new Float:x, Float:y, Float:z, vehicleid = LastVehicle[playerid];

        GetVehiclePos(vehicleid, x, y, z);

        if(!IsPlayerInRangeOfPoint(playerid, 5.0, x, y, z)) return 1;

        for(new slot = 0; slot < MAX_GAS_VEHICLE; slot++)
        {
            if(IsValidDynamicObject(GasObjects[slot][vehicleid])) continue;

            if(GasCountVehicle(vehicleid) >= MAX_GAS_VEHICLE)
                return SendClientMessage(playerid, Erro, "Não tem mais espaço em seu veículo, descarregue-o");

            GasCaught[playerid] = false;

            RemovePlayerAttachedObject(playerid, ATTACH_INDEX_THIEF);
            SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);

            GasObjects[slot][vehicleid] = CreateDynamicObject(1370, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);

            ApplyAnimation(playerid, "CARRY", "putdwn05", 4.1, 0, 1, 1, 0, 0, 1);

            switch(slot)
            {
                case 0: AttachDynamicObjectToVehicle(GasObjects[slot][vehicleid], vehicleid, -0.67590, -2.17770, 0.50520, 0.0, 0.0, 0.0);
                case 1: AttachDynamicObjectToVehicle(GasObjects[slot][vehicleid], vehicleid, -0.01100, -2.18390, 0.50520, 0.0, 0.0, 0.0);
                case 2: AttachDynamicObjectToVehicle(GasObjects[slot][vehicleid], vehicleid, 0.65120, -2.21210, 0.50520, 0.0, 0.0, 0.0);
                case 3: AttachDynamicObjectToVehicle(GasObjects[slot][vehicleid], vehicleid, 0.68350, -1.49770, 0.50520, 0.0, 0.0, 0.0);
                case 4: AttachDynamicObjectToVehicle(GasObjects[slot][vehicleid], vehicleid, -0.01720, -1.48580, 0.50520, 0.0, 0.0, 0.0);
                case 5: AttachDynamicObjectToVehicle(GasObjects[slot][vehicleid], vehicleid, -0.66570, -1.47920, 0.50520, 0.0, 0.0, 0.0);
            }

            switch(GasCountVehicle(vehicleid))
            {
                case 1:
                {
                    format(String, 128, "Você pegou 1 gás e agora faltam apenas {F29B0D}%d", ( MAX_GAS_VEHICLE - GasCountVehicle(vehicleid) ));
                    SendClientMessage(playerid, White, String);
                }
                case MAX_GAS_VEHICLE:
                {
                    SendClientMessage(playerid, White, "Você pegou último gás, agora vá até o caminhão localizado no mini-mapa");
                }
                default:
                {
                    format(String, 128, "Você pegou +1 gás e agora faltam apenas {F29B0D}%d", ( MAX_GAS_VEHICLE - GasCountVehicle(vehicleid) ));
                    SendClientMessage(playerid, White, String);
                }
            }
            break;
        }
        return 1;
    }
	if(PRESSED(KEY_YES))
	{
        if(IsPlayerInRangeOfPoint(playerid, 2.0, -439.69, 2216.75, 42.42))
        {
            if(PlayerInfo[playerid][Profissao] != thief)
                return SendClientMessage(playerid, Erro, "Você não tem permissão");

            if(PV_Profission[playerid])
                return SendClientMessage(playerid, Erro, "Seu veículo já está criado");

            new rand = random(sizeof(vr_thief));

            CreatePlayerVehicle(playerid, 478, vr_thief[rand][vt_x], vr_thief[rand][vt_y], vr_thief[rand][vt_z], 0.0, 0, 0);

            SendClientMessage(playerid, color_thief, "Foi criado um veículo profissão no estacionamento");
            return 1;
        }
        return 1;
	}
	return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PlayerInfo[playerid][Profissao] == thief && GetVehicleModel(LastVehicle[playerid]) == 478)
    {
        if(GasCountVehicle(LastVehicle[playerid]) && !IsValidDynamicMapIcon(GasAllMap[playerid]))
        {
            GasAllMap[playerid] = CreateDynamicMapIcon(-350.51, 2210.66, 42.48, 51, -1, -1, -1, playerid, -1.0, MAPICON_GLOBAL);
        }

        PlayerTextDrawTextSize(playerid, TDPlayerLoading[playerid][0], (500.4 + ((104.3 * GasCountVehicle(LastVehicle[playerid])) / MAX_GAS_VEHICLE)), 0.0);
        PlayerTextDrawShow(playerid, TDPlayerLoading[playerid][0]);
        ShowTDLoading(playerid);
        return 1;
    }
	return 1;
}

hook OnPlayerExitVehicle(playerid, vehicleid)
{
    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PlayerInfo[playerid][Profissao] == thief && GetVehicleModel(vehicleid) == 478)
    {
        if(IsValidDynamicMapIcon(GasAllMap[playerid])) DestroyDynamicMapIcon(GasAllMap[playerid]);

        HideTDLoading(playerid);
        return 1;
    }
	return 1;
}

forward ReloadingGas(gasid);
public ReloadingGas(gasid)
{
    if(!IsValidDynamicObject(RandomGas[gasid][rg_gas])) return 1;

    RandomGas[gasid][rg_gas] = CreateDynamicObject(1370, RandomGas[gasid][rg_x], RandomGas[gasid][rg_y], RandomGas[gasid][rg_z], 0.0, 0.0, 0.0);
    return 1;
}

stock Thief_DynamicRaceCP(playerid)
{
    if(PlayerInfo[playerid][Profissao] != thief) return 1;

    if(IsValidDynamicRaceCP(GasCP))
    {
        new vehicleid = LastVehicle[playerid];

        if(GetVehicleModel(vehicleid) != 478)
            return SendClientMessage(playerid, Erro, "Seu último veículo não é veículo profissão");

        if(!GasCountVehicle(vehicleid)) return 1;

        format(String, 128, "Você roubou %d gás e conseguiu lucrar $%s", GasCountVehicle(vehicleid), IsMoney(( GasCountVehicle(vehicleid) * 850 ), "."));
        SendClientMessage(playerid, color_thief, String);

        PlayerInfo[playerid][Dinheiro] += (GasCountVehicle(vehicleid) * 850);
        UpdatePlayerMoney(playerid);

        GasAll += GasCountVehicle(vehicleid);

        format(String, 50, "{FFFFFF}Roubos de Gás\n{F29B0D}%d", GasAll);
        UpdateDynamic3DTextLabelText(GasAllLabel, 0xFFFFFFFF, String);

        GasRemoveVehicle(vehicleid);

        if(IsValidDynamicMapIcon(GasAllMap[playerid])) DestroyDynamicMapIcon(GasAllMap[playerid]);

        PlayerTextDrawTextSize(playerid, TDPlayerLoading[playerid][0], (500.4 + ((104.3 * GasCountVehicle(vehicleid)) / MAX_GAS_VEHICLE)), 0.0);
        PlayerTextDrawShow(playerid, TDPlayerLoading[playerid][0]);
        return 1;
    }
    return 1;
}

stock left_pfs_thief(playerid)
{
    if(PlayerInfo[playerid][Profissao] != thief) return 1;

    if(IsValidDynamicMapIcon(GasAllMap[playerid])) DestroyDynamicMapIcon(GasAllMap[playerid]);

    GasCaught[playerid] = false;
    return 1;
}

stock GasRemoveVehicle(vehicleid)
{
    if(GetVehicleModel(vehicleid) != 478) return 0;

    for(new slot = 0; slot < MAX_GAS_VEHICLE; slot++)
    {
        if(!IsValidDynamicObject(GasObjects[slot][vehicleid])) continue;

        DestroyDynamicObject(GasObjects[slot][vehicleid]);
        GasObjects[slot][vehicleid] = -1;
    }
    return 1;
}

stock GasCountVehicle(vehicleid)
{
    if(GetVehicleModel(vehicleid) != 478) return 0;

    new count;

    for(new slot = 0; slot < MAX_GAS_VEHICLE; slot++) if(IsValidDynamicObject(GasObjects[slot][vehicleid])) count++;

    return count;
}
