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

new T_PlantingC4[MAX_PLAYERS];
new T_BlockBurglar[MAX_PLAYERS];
new obj_c4[MAX_PLAYERS];
new bool:planting_c4[MAX_PLAYERS];

hook OnGameModeInit()
{
    hackingBank = INVALID_PLAYER_ID;
    hackBank = INVALID_PLAYER_ID;

    GasAllLabel = CreateDynamic3DTextLabel("{FFFFFF}Roubos de Gás\n{F29B0D}0", 0xFFFFFFFF, -350.51, 2210.66, 42.48, 50.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
    GasCP = CreateDynamicRaceCP(2, -350.51, 2210.66, 42.48, -1, -1, -1, 5.0, -1, -1, -1, 200.0);

    for(new gasid = 0; gasid < MAX_GAS_MAP; gasid++)
    {
        RandomGas[gasid][rg_gas] = CreateDynamicObject(1370, RandomGas[gasid][rg_x], RandomGas[gasid][rg_y], RandomGas[gasid][rg_z], 0.0, 0.0, 0.0);
    }

    CreateVehicleLocation(-439.69, 2216.75, 42.42);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    T_BlockBurglar[playerid] = SetTimerEx("OnPlayerUnlockBurglar", 1000, true, "d", playerid);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    KillTimer(T_BlockBurglar[playerid]);

    if(planting_c4[playerid])
    {
        DestroyDynamicObject(obj_c4[playerid]);
        KillTimer(T_PlantingC4[playerid]);
        planting_c4[playerid] = false;
    }
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
            RemovePlayerAttachedObject(playerid, ATTACH_INDEX_PROFISSION);

            SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Gás removido");
            return 1;
        }

        new Float:x, Float:y, Float:z, vehicleid = LastVehicle[playerid];

        GetVehiclePos(vehicleid, x, y, z);

        if(!IsPlayerInRangeOfPoint(playerid, 20.0, x, y, z))
            return SendClientMessage(playerid, Erro, "Seu veículo profissão está longe, aproxime-o");

        if(GetVehicleModel(vehicleid) != 478)
            return SendClientMessage(playerid, Erro, "Este veículo não pertence à profissão profissão");

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

                SetTimerEx("ReloadingGas", 60000, false, "d", gasid);

                SetPlayerSpecialAction(playerid, SPECIAL_ACTION_CARRY);
                SetPlayerAttachedObject(playerid, ATTACH_INDEX_PROFISSION, 1370, 6, 0.027001, 0.236, -0.183, -22.3, 0, 0, 0.886001, 0.776002, 0.784);
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

            RemovePlayerAttachedObject(playerid, ATTACH_INDEX_PROFISSION);
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

            SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Foi criado um veículo profissão no estacionamento");
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

        format(String, 10, "%d%%", returnPorcentage(GasCountVehicle(LastVehicle[playerid]), MAX_GAS_VEHICLE));
        PlayerTextDrawSetString(playerid, TDPlayerLoading[playerid][1], String);
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
    if(RandomGas[gasid][rg_gas] != -1) return 1;

    RandomGas[gasid][rg_gas] = CreateDynamicObject(1370, RandomGas[gasid][rg_x], RandomGas[gasid][rg_y], RandomGas[gasid][rg_z], 0.0, 0.0, 0.0);
    return 1;
}

forward OnPlayerPlantingC4(playerid, cashid, Float:x, Float:y, Float:z);
public OnPlayerPlantingC4(playerid, cashid, Float:x, Float:y, Float:z)
{
    planting_c4[playerid] = false;
    DestroyDynamicObject(obj_c4[playerid]);

    if(!IsPlayerInRangeOfPoint(playerid, 20.0, CashMachine[cashid][cm_x], CashMachine[cashid][cm_y], CashMachine[cashid][cm_z]))
    {
        SendClientMessage(playerid, Erro, "Sua dinamite acabou falhando");
        return 1;
    }

    new value[MAX_PLAYERS];

    value[playerid] = RandomValueMachine();

    PlayerInfo[playerid][Dinheiro] += value[playerid];
    UpdatePlayerMoney(playerid);

    CreateExplosion(x, y, z, 12, 3.0);

    SetIntQuery(playerid, "Timers", "burglarbox", gettime());

    format(String, MAX_STRING, "Caixa Eletrônico explodido e você ganhou $%s", IsMoney(value[playerid], "."));
    SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);

    GetPlayer2DZone(zone, MAX_ZONE_NAME, x, y);

    format(String, MAX_STRING, "O(A) Jogador(a) %s[%d] assaltou um caixa eletrônico na localidade ( %s )", PlayerInfo[playerid][Nome], playerid, zone);

    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerPolice(i))
        {
            SendClientMessage(i, 0x2894FFAA, String);
        }
    }
    return 1;
}

stock RandomValueMachine()
{
    new value = random(2000);

    if(value < 500)
        return RandomValueMachine();

    return value;
}

stock RandomValueBurglar()
{
    new value = random(1000);

    if(value < 200)
        return RandomValueBurglar();

    return value;
}

stock RandomValueBank()
{
    new value = random(20000);

    if(value < 10000)
        return RandomValueBank();

    return value;
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
        SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);

        PlayerInfo[playerid][Dinheiro] += (GasCountVehicle(vehicleid) * 850);
        UpdatePlayerMoney(playerid);

        GasAll += GasCountVehicle(vehicleid);

        format(String, 50, "{FFFFFF}Roubos de Gás\n{F29B0D}%d", GasAll);
        UpdateDynamic3DTextLabelText(GasAllLabel, 0xFFFFFFFF, String);

        GasRemoveVehicle(vehicleid);

        if(IsValidDynamicMapIcon(GasAllMap[playerid])) DestroyDynamicMapIcon(GasAllMap[playerid]);

        format(String, 10, "%d%%", returnPorcentage(GasCountVehicle(LastVehicle[playerid]), MAX_GAS_VEHICLE));
        PlayerTextDrawSetString(playerid, TDPlayerLoading[playerid][1], String);
        PlayerTextDrawTextSize(playerid, TDPlayerLoading[playerid][0], (500.4 + ((104.3 * GasCountVehicle(vehicleid)) / MAX_GAS_VEHICLE)), 0.0);
        PlayerTextDrawShow(playerid, TDPlayerLoading[playerid][0]);
        return 1;
    }
    return 1;
}

stock LeftPfsThief(playerid)
{
    if(PlayerInfo[playerid][Profissao] == thief)
    {
        if(IsValidDynamicMapIcon(GasAllMap[playerid]))
            DestroyDynamicMapIcon(GasAllMap[playerid]);

        new vehicleid = LastVehicle[playerid];

        if(vehicleid != -1)
            GasRemoveVehicle(vehicleid);

        GasCaught[playerid] = false;
        return 1;
    }
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

/******************************************************************************/
/******************************| COMMANDS THIEF |******************************/
/******************************************************************************/

CMD:assaltar(playerid, params[])
{
    if(PlayerInfo[playerid][Profissao] != thief)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if((gettime() - GetIntQuery(playerid, "Timers", "timeburglar")) < 120)
        return SendClientMessage(playerid, Erro, "Você acabou de assaltar, aguarde alguns segundos...");

    new id, Float:x, Float:y, Float:z;

    if(sscanf(params, "d", id))
        return SendClientMessage(playerid, Erro, "/Assaltar [id]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    GetPlayerPos(id, x, y, z);

    if(!IsPlayerInRangeOfPoint(playerid, 3.0, x, y, z))
        return SendClientMessage(playerid, Erro, "Você não está perto da vítima, chegue mais perto");

    SetIntQuery(playerid, "Timers", "timeburglar", gettime());

    new value = RandomValueBurglar();

    if(PlayerInfo[id][Dinheiro] < value)
        return SendClientMessage(playerid, Erro, "Jogador(a) não tem saldo suficiente");

    PlayerInfo[playerid][Dinheiro] += value;
    UpdatePlayerMoney(playerid);
    PlayerInfo[id][Dinheiro] -= value;
    UpdatePlayerMoney(id);

    PlayerInfo[playerid][Estrelas] += 1;
    UpdatePlayerStar(playerid);

    format(String, MAX_STRING, "Você assaltou o jogador(a) %s[%d] e ganhou $%s", PlayerInfo[id][Nome], id, IsMoney(value, "."));
    SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);
    format(String, MAX_STRING, "O(A) Jogador(a) %s[%d] assaltou $%s de você", PlayerInfo[playerid][Nome], playerid, IsMoney(value, "."));
    SendClientMessage(id, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);

    GetPlayer2DZone(zone, MAX_ZONE_NAME, x, y);

    format(String, MAX_STRING, "O(A) Jogador(a) %s[%d] assaltou o jogador(a) %s[%d] na localidade ( %s )", PlayerInfo[playerid][Nome], playerid, PlayerInfo[id][Nome], id, zone);

    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerPolice(i))
        {
            SendClientMessage(i, 0x2894FFAA, String);
        }
    }
    return 1;
}
CMD:assaltarcaixa(playerid)
{
    if(PlayerInfo[playerid][Profissao] != thief)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(planting_c4[playerid])
        return SendClientMessage(playerid, Erro, "Você já está assaltando um caixa");

    for(new cashid = 0; cashid < MAX_CASHMACHINE; cashid++)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, CashMachine[cashid][cm_x], CashMachine[cashid][cm_y], CashMachine[cashid][cm_z]))
        {
            if((gettime() - GetIntQuery(playerid, "Timers", "burglarbox")) < 120)
                return SendClientMessage(playerid, Erro, "Você acabou de assaltar, aguarde alguns segundos...");

            new item_c4 = GetIntQuery(playerid, "Itens", "c4");

            if(!item_c4)
                return SendClientMessage(playerid, Erro, "Você não tem dinamites, vá até alguma Ammunation");

            new Float:x, Float:y, Float:z;

            GetPlayerPos(playerid, x, y, z);

            obj_c4[playerid] = CreateDynamicObject(1654, x, y, z-0.7, 0.0, 0.0, 0.0);
            planting_c4[playerid] = true;

            PlayerInfo[playerid][Estrelas] += 1;
            UpdatePlayerStar(playerid);

            SetIntQuery(playerid, "Itens", "c4", (item_c4 - 1));

            T_PlantingC4[playerid] = SetTimerEx("OnPlayerPlantingC4", 5000, false, "ddfff", playerid, cashid, x, y, z);

            SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "C4 plantada, se afaste e espere explodir");
            return 1;
        }
    }
    return SendClientMessage(playerid, Erro, "Você não está perto de um caixa eletrônico");
}
CMD:assaltarcarroforte(playerid, params[])
{
    if(PlayerInfo[playerid][Profissao] != thief)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(IsPlayerInBankLS(playerid) || IsPlayerInBankLV(playerid) || IsPlayerInBankSF(playerid))
        return SendClientMessage(playerid, Erro, "Não é possível fazer assalto neste local");

    if((gettime() - GetIntQuery(playerid, "Timers", "burglarstrongcar")) < 120)
        return SendClientMessage(playerid, Erro, "Você acabou de assaltar, aguarde alguns segundos...");

    new id;

    if(sscanf(params, "d", id))
        return SendClientMessage(playerid, Erro, "Digite: /AssaltarCarroForte [id]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    if(PlayerInfo[id][Profissao] != strongcardriver)
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) não é Motorista de Carro Forte");

    if(!IsPlayerInAnyVehicle(id))
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) não está em um Carro Forte");

    new Float:x, Float:y, Float:z, vehicleid;

    vehicleid = getPlayerVehicleID(id);

    if(GetVehicleModel(PublicVehicle[vehicleid][pv_vehicle]) != 428)
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) não está em um Carro Forte");

    GetVehiclePos(PublicVehicle[vehicleid][pv_vehicle], x, y, z);

    if(!IsPlayerInRangeOfPoint(playerid, 7.5, x, y, z))
        return SendClientMessage(playerid, Erro, "Carro Forte está longe, chegue mais perto");

    if(!PublicVehicle[vehicleid][pv_loaded])
        return SendClientMessage(playerid, Erro, "Carro Forte não está carregado");

    if(PublicVehicle[vehicleid][pv_security] != INVALID_PLAYER_ID)
        return SendClientMessage(playerid, Erro, "O Carro Forte tem segurança");

    new value = RandomValueBurglar();

    PlayerInfo[playerid][Dinheiro] += value;
    UpdatePlayerMoney(playerid);
    PlayerInfo[playerid][Estrelas] += 1;
    UpdatePlayerStar(playerid);

    PublicVehicle[vehicleid][pv_loaded] = false;

    GameTextForPlayer(playerid, "~g~ASSALTO!", 1000, 1);
    PlayerPlaySound(playerid, 1054, 0, 0, 0);
    GameTextForPlayer(id, "~r~ASSALTO!", 1000, 1);
    PlayerPlaySound(id, 1055, 0, 0, 0);

    SetIntQuery(playerid, "Timers", "burglarstrongcar", gettime());

    format(String, MAX_STRING, "Você assaltou o Carro Forte do(a) jogador(a) %s[%d] e recebeu $%s", PlayerInfo[id][Nome], id, IsMoney(value, "."));
    SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);
    format(String, MAX_STRING, "O(A) Assaltante %s[%d] assaltou seu Carro Forte", PlayerInfo[playerid][Nome], playerid);
    SendClientMessage(id, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);
    return 1;
}
CMD:hackear(playerid, params[])
{
    if(PlayerInfo[playerid][Profissao] != thief)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsPlayerInRangeOfPoint(playerid, 2.0, 921.36, 1649.72, 1101.63))
        return SendClientMessage(playerid, Erro, "Você não está perto do alarme");

    if(hackingBank != INVALID_PLAYER_ID)
        return SendClientMessage(playerid, Erro, "Já estão hackeando o banco");

    if(hackBank != INVALID_PLAYER_ID)
        return SendClientMessage(playerid, Erro, "Já hackearam o banco");

    hackingBank = playerid;
    TogglePlayerControllable(playerid, false);
    ApplyAnimation(playerid, "SHOP", "ROB_Loop_Threat", 4.0, 1, 0, 0, 10000, 0);
    SetTimerEx("OnPlayerHackingBank", 10000, false, "d", playerid);
    return 1;
}
CMD:assaltarcofre(playerid, params[])
{
    if(PlayerInfo[playerid][Profissao] != thief)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(hackBank != playerid)
        return SendClientMessage(playerid, Erro, "Não foi você que hackeou o sistema, tente mais tarde");

    if((gettime() - GetIntQuery(playerid, "Timers", "burglarbank")) < 1800)
        return SendClientMessage(playerid, Erro, "Você acabou de assaltar, aguarde alguns minutos...");

    new Float:x, Float:y, Float:z;

    GetPlayerPos(playerid, x, y, z);

    if(!(x >= 919.2560 && y >= 1642.8801 && x <= 925.2238 && y <= 1649.6013))
        return SendClientMessage(playerid, Erro, "Você não está no cofre");

    PlayerInfo[playerid][Estrelas] += 5;
    UpdatePlayerStar(playerid);

    new value = RandomValueBank();

    PlayerInfo[playerid][Dinheiro] += value;
    UpdatePlayerMoney(playerid);

    SetIntQuery(playerid, "Timers", "burglarbank", gettime());

    format(String, MAX_STRING, "Assalto efetuado e você recebeu $%s", IsMoney(value, "."));
    SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);
    return 1;
}
