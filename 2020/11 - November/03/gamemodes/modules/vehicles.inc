#include YSI\y_hooks

new LastVehicle[MAX_PLAYERS] = -1;

enum e_vb
{
    vb_id,
    vb_model,
    bool:vb_connect
};

new VehicleBase[MAX_BASES][MAX_VEHICLE_BASE][e_vb];
new VehicleBaseList[MAX_PLAYERS];

public OnVehiclePaintjob(playerid, vehicleid, paintjobid)
{
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
        {
            if(vehicleid == DataVehicles[slot][i][vvehicle])
            {
                DataVehicles[slot][i][vpaintjob] = paintjobid;
                UpdateVehicleComponent(i, slot);
                return 1;
            }
        }
    }
    return 1;
}

public OnVehicleRespray(playerid, vehicleid, color1, color2)
{
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
        {
            if(vehicleid == DataVehicles[slot][i][vvehicle])
            {
                DataVehicles[slot][i][vcolor1] = color1;
                DataVehicles[slot][i][vcolor2] = color2;
                UpdateVehicleComponent(i, slot);
                return 1;
            }
        }
    }
    return 1;
}

hook OnGameModeInit()
{
    for(new vehicleid = 0; vehicleid < MAX_VEHICLES; vehicleid++)
    {
        PublicVehicle[vehicleid][pv_id] = INVALID_PLAYER_ID;
        PublicVehicle[vehicleid][pv_security] = INVALID_PLAYER_ID;
        PublicVehicle[vehicleid][pv_base] = -1;
        PublicVehicle[vehicleid][pv_slot] = -1;
    }

    for(new baseid = 0; baseid < MAX_BASES; baseid++)
    {
        for(new listid = 0; listid < MAX_VEHICLE_BASE; listid++)
        {
            VehicleBase[baseid][listid][vb_model] = BASE_VEHICLE_MODEL;
        }
    }

    //Policia
    CreateVehicleEx(523,1605.0000,-1605.0000,13.0002,90.0000,-1,-1);
    CreateVehicleEx(523,1604.9994,-1608.0200,13.0002,90.0000,-1,-1);
    CreateVehicleEx(523,1604.9994,-1611.0000,13.0002,90.0000,-1,-1);
    CreateVehicleEx(523,1604.9994,-1614.0000,13.0002,90.0000,-1,-1);
    CreateVehicleEx(523,1604.9994,-1617.0000,13.0002,90.0000,-1,-1);
    CreateVehicleEx(523,1604.9994,-1620.0000,13.0002,90.0000,-1,-1);
    CreateVehicleEx(523,1604.9994,-1623.0000,13.0002,90.0000,-1,-1);
    CreateVehicleEx(523,1604.9994,-1626.0000,13.0002,90.0000,-1,-1);
    CreateVehicleEx(523,1604.9994,-1629.0000,13.0002,90.0000,-1,-1);
    CreateVehicleEx(523,1604.9994,-1632.0000,13.0002,90.0000,-1,-1);
    CreateVehicleEx(598,1551.0000,-1606.0000,13.0802,180.0000,-1,-1);
    CreateVehicleEx(598,1554.9801,-1606.0016,13.0802,180.0000,-1,-1);
    CreateVehicleEx(598,1559.0000,-1605.9719,13.0802,180.0000,-1,-1);
    CreateVehicleEx(598,1563.0000,-1606.0000,13.0802,180.0000,-1,-1);
    CreateVehicleEx(598,1567.0000,-1606.0010,13.0802,180.0000,-1,-1);
    CreateVehicleEx(598,1571.0000,-1606.0010,13.0802,180.0000,-1,-1);
    CreateVehicleEx(598,1575.0000,-1606.0010,13.0802,180.0000,-1,-1);
    CreateVehicleEx(598,1579.0000,-1606.0010,13.0802,180.0000,-1,-1);
    CreateVehicleEx(598,2252.0000, 2476.5591,10.4215,180.0000,-1,-1);
    CreateVehicleEx(598,2255.9714,2476.5591,10.4215,180.0000,-1,-1);
    CreateVehicleEx(598,2260.4031,2476.5591,10.4215,180.0000,-1,-1);
    CreateVehicleEx(598,2269.3093,2476.5591,10.4215,180.0000,-1,-1);
    CreateVehicleEx(598,2273.3691,2476.5591,10.4215,180.0000,-1,-1);
    CreateVehicleEx(598,2277.8213,2476.5591,10.4215,180.0000,-1,-1);
    CreateVehicleEx(598,2282.3047,2476.5940,10.4215,180.0000,-1,-1);
    CreateVehicleEx(497,-220.9945,995.6248,19.7057,-90.0000,-1,-1);
    CreateVehicleEx(599,-209.1601,998.7247,19.7419,180.0000,-1,-1);
    CreateVehicleEx(598,-214.1810,972.8283,18.9690,-90.0000,-1,-1);
    CreateVehicleEx(497,-1680.3081,704.7817,30.9151,0.0000,-1,-1);
    CreateVehicleEx(523,-1581.6348,652.1369,6.6743,0.0000,-1,-1);
    CreateVehicleEx(523,-1587.7535,652.1369,6.6743,0.0000,-1,-1);
    CreateVehicleEx(523,-1593.5933,652.1369,6.6743,0.0000,-1,-1);
    CreateVehicleEx(523,-1599.4490,652.1369,6.6743,0.0000,-1,-1);
    CreateVehicleEx(598,-1610.7079,651.8018,6.8743,0.0000,-1,-1);
    CreateVehicleEx(598,-1616.5802,651.8018,6.8743,0.0000,-1,-1);
    CreateVehicleEx(598,-1622.5671,651.8018,6.8743,0.0000,-1,-1);
    CreateVehicleEx(598,-1628.4109,651.8018,6.8743,0.0000,-1,-1);
    CreateVehicleEx(598,-1634.2976,651.8018,6.8743,0.0000,-1,-1);
    CreateVehicleEx(599, -1400.2013, 2659.6458, 55.7543, 90.0000, -1, -1);
    CreateVehicleEx(598, -1400.2499, 2656.5784, 55.4343, 90.0000, -1, -1);
    CreateVehicleEx(599, -1400.0659, 2628.7180, 55.7543, 90.0000, -1, -1);
    CreateVehicleEx(598, -1400.0209, 2631.6213, 55.4343, 90.0000, -1, -1);
    CreateVehicleEx(523, -1400.0209, 2653.3018, 55.4343, 90.0000, -1, -1);
    CreateVehicleEx(523, -1400.0209, 2634.6067, 55.4343, 90.0000, -1, -1);
    CreateVehicleEx(599, 614.8815, -597.2113, 17.3578, -90.0000, -1, -1);
    CreateVehicleEx(599, 614.8815, -601.4311, 17.3578, -90.0000, -1, -1);
    CreateVehicleEx(598, 623.4308, -608.6873, 16.6298, 0.0000, -1, -1);
    CreateVehicleEx(598, 627.1738, -608.6873, 16.6298, 0.0000, -1, -1);
    CreateVehicleEx(597, 614.0094, -589.2466, 16.9744, -90.0000, -1, -1);
    CreateVehicleEx(599, -2178.3704, -2369.8157, 30.6969, 54.0000, -1, -1);
    CreateVehicleEx(598, -2175.9666, -2366.5017, 30.6969, 54.0000, -1, -1);
    CreateVehicleEx(597, -2173.5701, -2363.1887, 30.6969, 54.0000, -1, -1);

    //Entregador de Jornais
    CreateVehicleEx(510, 784.9813, -1356.2255, 13.1522, 90.0000, 1, 1);
    CreateVehicleEx(510, 784.9813, -1358.1863, 13.1522, 90.0000, 1, 1);
    CreateVehicleEx(510, 784.9813, -1360.1813, 13.1522, 90.0000, 1, 1);
    CreateVehicleEx(510, 784.9813, -1362.1833, 13.1522, 90.0000, 1, 1);
    CreateVehicleEx(510, 784.9813, -1364.1859, 13.1522, 90.0000, 1, 1);
    CreateVehicleEx(510, 784.9813, -1345.0000, 13.1522, 90.0000, 1, 1);
    CreateVehicleEx(510, 784.9813, -1343.0000, 13.1522, 90.0000, 1, 1);
    CreateVehicleEx(510, 784.9813, -1341.0000, 13.1522, 90.0000, 1, 1);
    CreateVehicleEx(510, 784.9810, -1339.0000, 13.1522, 90.0000, 1, 1);
    CreateVehicleEx(510, 784.9810, -1337.0000, 13.1522, 90.0000, 1, 1);
    CreateVehicleEx(510, 784.9813, -1346.8591, 13.1522, 90.0000, 1, 1);
    CreateVehicleEx(510, 784.9813, -1348.7258, 13.1522, 90.0000, 1, 1);
    CreateVehicleEx(510, 784.9813, -1350.6263, 13.1522, 90.0000, 1, 1);
    CreateVehicleEx(510, 784.9813, -1352.5315, 13.1522, 90.0000, 1, 1);
    CreateVehicleEx(510, 784.9813, -1354.4387, 13.1522, 90.0000, 1, 1);

    //Novatos
    CreateVehicleEx(481,828.0000,-1336.0000,13.0416,359.3848,1,1);
    CreateVehicleEx(481,830.0000,-1336.0000,13.0416,359.3848,1,1);
    CreateVehicleEx(481,832.0000,-1336.0000,13.0416,359.3848,1,1);
    CreateVehicleEx(481,834.0000,-1336.0000,13.0416,359.3848,1,1);
    CreateVehicleEx(481,836.0000,-1336.0000,13.0416,359.3848,1,1);

    //Light
    CreateVehicleEx(552, -2531.7886, -602.4160, 132.1792, 0.0000, 1, 128);
    CreateVehicleEx(552, -2509.5198, -602.4155, 132.1792, 0.3000, 1, 128);
    CreateVehicleEx(552, -2524.4075, -602.4162, 132.1792, 0.0000, 1, 128);
    CreateVehicleEx(552, -2502.1787, -602.4156, 132.1792, -0.0600, 1, 128);
    CreateVehicleEx(552, -2517.0022, -602.4160, 132.1792, 0.0000, 1, 128);
    CreateVehicleEx(552, -2494.8149, -602.4154, 132.1792, 0.0000, 1, 128);
    CreateVehicleEx(552, -2498.3752, -602.4114, 132.1792, 0.0000, 1, 128);
    CreateVehicleEx(552, -2505.7744, -602.4114, 132.1792, -0.0600, 1, 128);
    CreateVehicleEx(552, -2513.1523, -602.4114, 132.1792, 0.3000, 1, 128);
    CreateVehicleEx(552, -2520.6697, -602.4114, 132.1792, 0.0000, 1, 128);
    CreateVehicleEx(552, -2528.1113, -602.4114, 132.1792, 0.0000, 1, 128);
    CreateVehicleEx(552, -2535.5291, -602.4114, 132.1792, 0.0000, 1, 128);

    //Petroleiro
    CreateVehicleEx(514, 302.7167, 1474.7983, 10.4853, -117.0000, -1, -1);
    CreateVehicleEx(514, 301.5925, 1464.5660, 10.4129, -119.0000, -1, -1);
    CreateVehicleEx(514, 301.0728, 1459.1483, 9.8414, -117.0000, -1, -1);
    CreateVehicleEx(514, 302.1852, 1453.4656, 10.2672, -117.0000, -1, -1);
    CreateVehicleEx(514, 301.9598, 1448.5229, 10.3889, -119.0000, -1, -1);
    CreateVehicleEx(514, 301.6843, 1469.6198, 10.4388, -119.0000, -1, -1);
    CreateVehicleEx(514, 340.5740, 1446.1991, 9.0670, -179.0000, -1, -1);
    CreateVehicleEx(514, 340.4822, 1467.7844, 7.5528, -178.0000, -1, -1);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    LastVehicle[playerid] = -1;

    DestroyPlayerVehicle(playerid);
    return 1;
}

hook OnVehicleDeath(vehicleid, killerid)
{
    DestroyPlayerVehicle(killerid);
	return 1;
}

hook OnPlayerExitVehicle(playerid, vehicleid)
{
    LastVehicle[playerid] = vehicleid;
    return 1;
}

hook OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    LastVehicle[playerid] = vehicleid;

    if(ispassenger) return 0;

    for(new i = 0; i < MAX_VEHICLES; i++)
    {
        if(vehicleid != PublicVehicle[i][pv_vehicle]) continue;

        if(IsPlayerDriverVehicle(vehicleid))
        {
            SetTimerEx("UnlockedPlayerTheft", 5000, false, "d", playerid);
            TogglePlayerControllable(playerid, false);
            SetPlayerVirtualWorld(playerid, playerid);
            SendClientMessage(playerid, Yellow, "Você foi bloqueado por 5 segundos pela tentativa de roubo");
            return 1;
        }

        if(PublicVehicle[i][pv_id] == INVALID_PLAYER_ID)
        {
            if(PublicVehicle[i][pv_adm] && !IsPlayerIntern(playerid))
            {
                ClearAnimations(playerid);
                SendClientMessage(playerid, Erro, "Veículo exclusivo da administração");
                return 1;
            }
            if(PublicVehicle[i][pv_base] != -1)
            {
                new baseid = PublicVehicle[i][pv_base];

                for(new listid = 0; listid < MAX_VEHICLE_BASE; listid++)
                {
                    if(VehicleBase[baseid][listid][vb_id] != vehicleid) continue;

                    if(!IsPlayerOwnerBase(playerid, baseid) && !IsPlayerMemberBase(playerid, baseid))
                    {
                        ClearAnimations(playerid);
                        SendClientMessage(playerid, Erro, "Você não pertence à está Base");
                        return 1;
                    }

                    format(String, MAX_STRING, "%s veículo Base, seja bem-vindo(a)", BaseInfo[baseid][bi_name], baseid);
                    SendClientMessage(playerid, color_base, String);
                    return 1;
                }
                return 1;
            }

            switch(GetVehicleModel(PublicVehicle[i][pv_vehicle]))
            {
                case 481:
                {
                    if(PlayerInfo[playerid][Level] >= 10)
                    {
                        ClearAnimations(playerid);
                        SendClientMessage(playerid, Erro, "Exclusive para novatos");
                    }
                    return 1;
                }

                case 510: if(PlayerInfo[playerid][Profissao] != newspaperdelivery) return LeftVehicleProfession(playerid);

                case 514: if(PlayerInfo[playerid][Profissao] != tanker) return LeftVehicleProfession(playerid);

                case 552: if(PlayerInfo[playerid][Profissao] != light) return LeftVehicleProfession(playerid);

                case 497, 523, 597, 598, 599:
                {
                    if(!IsPlayerPolice(playerid) && PlayerInfo[playerid][Profissao] != internalaffairs)
                        return LeftVehicleProfession(playerid);

                    else if(IsPlayerPolice(playerid) && !IsPlayerUniformPM(playerid))
                    {
                        ClearAnimations(playerid);
                        SendClientMessage(playerid, Erro, "Você não está com o uniforme");
                    }
                    return 1;
                }
            }
        }
        else if(PublicVehicle[i][pv_slot] != -1)
        {
            new ownerid = PublicVehicle[i][pv_id];
            new slot = PublicVehicle[i][pv_slot];

            if(vehicleid != DataVehicles[slot][ownerid][vvehicle] || !DataVehicles[slot][ownerid][vconnected]) continue;

            if(ownerid == playerid)
            {
                format(String, MAX_STRING, "{00C40A}~~> {FFFFFF}Bem-vindo ao seu veículo %s, %s", getVehicleName(DataVehicles[slot][ownerid][vmodel]), PlayerInfo[ownerid][Nome]);
                SendClientMessage(playerid, White, String);
                return 1;
            }

            if(DataVehicles[slot][ownerid][vlock])
            {
                ClearAnimations(playerid);
                format(String, MAX_STRING, "{FF4000}~~x {FFFFFF}Esse veículo \"%s\" pertence à %s e está trancado!", DataVehicles[slot][ownerid][vmessage], PlayerInfo[ownerid][Nome]);
                SendClientMessage(playerid, White, String);
                return 1;
            }

            format(String, MAX_STRING, "{FF4000}~~x {FFFFFF}Esse veículo \"%s\" pertence à %s e está destrancado!", DataVehicles[slot][ownerid][vmessage], PlayerInfo[ownerid][Nome]);
            SendClientMessage(playerid, White, String);
            return 1;
        }
    }
    return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    new vehicleid = GetPlayerVehicleID(playerid);

    if(newstate == PLAYER_STATE_DRIVER && !IsBike(vehicleid))
    {
        SendClientMessage(playerid, -1, "Para ligar ou desligar o veículo \"{CECECE}/Partida{FFFFFF}\" ou \"{CECECE}Y{FFFFFF}\"");

        if(IsPlayerInVehicleA(vehicleid) && !IsPlayerCnhType(playerid, "a"))
            return SendClientMessage(playerid, Yellow, "Você não possui CNH \"Categoria A\" e poderá ser multado");

        if(IsPlayerInVehicleB(vehicleid) && !IsPlayerCnhType(playerid, "b"))
            return SendClientMessage(playerid, Yellow, "Você não possui CNH \"Categoria B\" e poderá ser multado");

        if(IsPlayerInVehicleC(vehicleid) && !IsPlayerCnhType(playerid, "c"))
            return SendClientMessage(playerid, Yellow, "Você não possui CNH \"Categoria C\" e poderá ser multado");

        if(IsPlayerInVehicleCHT(vehicleid) && !IsPlayerCnhType(playerid, "cht"))
            return SendClientMessage(playerid, Yellow, "Você não possui CNH \"CHT\" e poderá ser multado");

        if(IsPlayerInVehicleArrais(vehicleid) && !IsPlayerCnhType(playerid, "arrais"))
            return SendClientMessage(playerid, Yellow, "Você não possui \"CNH Arrais\" e poderá ser multado");

        return 1;
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys & KEY_FIRE || newkeys & KEY_CROUCH)
	{
        if(Perseguicao[playerid]) return 0;

        if(!IsPlayerIntern(playerid) && !IsPlayerVip(playerid) && !IsPlayerYoutuber(playerid)) return 0;

        if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
        {
            new vehicleid = GetPlayerVehicleID(playerid);

            if(!VehicleSupportNitro(vehicleid) || IsBrokenVehicle(vehicleid)) return 0;

            AddVehicleComponent(vehicleid, 1010);
            RepairVehicle(vehicleid);
            return 1;
        }
        return 1;
    }
    if(PRESSED(KEY_YES))
    {
        new vehicleid = GetPlayerVehicleID(playerid), mot, lu, alar, por, cap, porma, ob;

        GetVehicleParamsEx(vehicleid,  mot, lu, alar, por, cap, porma, ob);

        if(IsBike(vehicleid) || GetPlayerState(playerid) != PLAYER_STATE_DRIVER || !IsPlayerInAnyVehicle(playerid) || IsBrokenVehicle(vehicleid)) return 0;

        if(mot == VEHICLE_PARAMS_OFF)
        {
            for(new i = 0; i < MAX_VEHICLES; i++)
            {
                if(vehicleid != PublicVehicle[i][pv_vehicle]) continue;

                if(!PublicVehicle[i][pv_gasoline])
                    return SendClientMessage(playerid, Erro, "Este veículo não tem Gasolina");
            }

            SetVehicleParamsEx(vehicleid, 1, 1, alar, por, cap, porma, ob);
            SendClientMessage(playerid, Green, "Veiculo ligado");
        }
        else
        {
            SendClientMessage(playerid, Green, "Veiculo desligado");
            SetVehicleParamsEx(vehicleid, 0, 0, alar, por, cap, porma, ob);
        }
        return 1;
    }
	return 1;
}

forward RepairingVehicle(playerid, vehicleid);
public RepairingVehicle(playerid, vehicleid)
{
    new Float:health;

    GetVehicleHealth(vehicleid, health);

    health += 50.0;

    if(health >= 1000.0)
    {
        ClearAnimations(playerid);
        TogglePlayerControllable(playerid, true);
        PlayerRepairVehicle[playerid] = false;

        health = 1000.0;
        SetVehicleHealth(vehicleid, health);

        PlayerTextDrawTextSize(playerid, TDPlayerLoading[playerid][0], (500.4 + ((104.3 * health) / 1000.0)), 0.0);
        PlayerTextDrawShow(playerid, TDPlayerLoading[playerid][0]);

        format(String, 10, "%d%%", returnPorcentage(health, 1000.0));
        PlayerTextDrawSetString(playerid, TDPlayerLoading[playerid][1], String);
        PlayerTextDrawShow(playerid, TDPlayerLoading[playerid][1]);

        RepairVehicle(vehicleid);

        HideTDLoading(playerid);
        return 1;
    }

    PlayerTextDrawTextSize(playerid, TDPlayerLoading[playerid][0], (500.4 + ((104.3 * health) / 1000.0)), 0.0);
    PlayerTextDrawShow(playerid, TDPlayerLoading[playerid][0]);
    SetVehicleHealth(vehicleid, health);

    format(String, 10, "%d%%", returnPorcentage(health, 1000.0));
    PlayerTextDrawSetString(playerid, TDPlayerLoading[playerid][1], String);
    PlayerTextDrawShow(playerid, TDPlayerLoading[playerid][1]);

    SetTimerEx("RepairingVehicle", 1000, false, "dd", playerid, vehicleid);
    return 1;
}
forward UnlockedPlayerTheft(playerid);
public UnlockedPlayerTheft(playerid)
{
    TogglePlayerControllable(playerid, true);
    SetPlayerVirtualWorld(playerid, WORLD_DEFAULT);
    ClearAnimations(playerid);
    return 1;
}

stock IsBike(vehicleid)
{
    switch(GetVehicleModel(vehicleid))
    {
        case 481: return 1;
        case 509..510: return 1;
        default: return 0;
    }
    return 1;
}

stock IsPlayerInVehicleA(vehicleid)
{
    switch(GetVehicleModel(vehicleid))
    {
        case 581: return 1;
        case 462: return 1;
        case 521: return 1;
        case 463: return 1;
        case 522: return 1;
        case 461: return 1;
        case 468: return 1;
        case 586: return 1;
        case 423: return 1;
    }
    return false;
}

stock IsPlayerInVehicleB(vehicleid)
{
    switch(GetVehicleModel(vehicleid))
    {
        case 602: return 1;
        case 496: return 1;
        case 401: return 1;
        case 518: return 1;
        case 527: return 1;
        case 589: return 1;
        case 419: return 1;
        case 587: return 1;
        case 533: return 1;
        case 526: return 1;
        case 474: return 1;
        case 545: return 1;
        case 517: return 1;
        case 410: return 1;
        case 600: return 1;
        case 436: return 1;
        case 439: return 1;
        case 549: return 1;
        case 491: return 1;
        case 445: return 1;
        case 604: return 1;
        case 507: return 1;
        case 585: return 1;
        case 466: return 1;
        case 492: return 1;
        case 546: return 1;
        case 551: return 1;
        case 516: return 1;
        case 467: return 1;
        case 426: return 1;
        case 547: return 1;
        case 580: return 1;
        case 409: return 1;
        case 550: return 1;
        case 566: return 1;
        case 540: return 1;
        case 421: return 1;
        case 529: return 1;
        case 579: return 1;
        case 400: return 1;
        case 404: return 1;
        case 489: return 1;
        case 505: return 1;
        case 479: return 1;
        case 442: return 1;
        case 458: return 1;
        case 536: return 1;
        case 575: return 1;
        case 534: return 1;
        case 567: return 1;
        case 535: return 1;
        case 576: return 1;
        case 412: return 1;
        case 402: return 1;
        case 542: return 1;
        case 603: return 1;
        case 475: return 1;
        case 429: return 1;
        case 541: return 1;
        case 415: return 1;
        case 480: return 1;
        case 562: return 1;
        case 565: return 1;
        case 434: return 1;
        case 494: return 1;
        case 502: return 1;
        case 503: return 1;
        case 411: return 1;
        case 559: return 1;
        case 561: return 1;
        case 506: return 1;
        case 451: return 1;
        case 558: return 1;
        case 555: return 1;
        case 477: return 1;
        case 568: return 1;
        case 424: return 1;
        case 504: return 1;
        case 457: return 1;
        case 571: return 1;
        case 500: return 1;
        case 444: return 1;
        case 556: return 1;
        case 557: return 1;
        case 471: return 1;
        case 495: return 1;
        case 470: return 1;
        case 596: return 1;
        case 598: return 1;
        case 599: return 1;
        case 597: return 1;
        case 601: return 1;
        case 560: return 1;
    }
    return false;
}

stock IsPlayerInVehicleC(vehicleid)
{
    switch(GetVehicleModel(vehicleid))
    {
        case 431: return 1;
        case 437: return 1;
        case 525: return 1;
        case 408: return 1;
        case 552: return 1;
        case 416: return 1;
        case 433: return 1;
        case 427: return 1;
        case 490: return 1;
        case 528: return 1;
        case 407: return 1;
        case 544: return 1;
        case 428: return 1;
        case 499: return 1;
        case 609: return 1;
        case 498: return 1;
        case 524: return 1;
        case 532: return 1;
        case 578: return 1;
        case 406: return 1;
        case 573: return 1;
        case 455: return 1;
        case 588: return 1;
        case 403: return 1;
        case 423: return 1;
        case 414: return 1;
        case 443: return 1;
        case 515: return 1;
        case 514: return 1;
        case 531: return 1;
        case 456: return 1;
        case 459: return 1;
        case 422: return 1;
        case 482: return 1;
        case 605: return 1;
        case 530: return 1;
        case 418: return 1;
        case 572: return 1;
        case 582: return 1;
        case 413: return 1;
        case 440: return 1;
        case 543: return 1;
        case 583: return 1;
        case 478: return 1;
        case 554: return 1;
    }
    return false;
}

stock IsPlayerInVehicleCHT(vehicleid)
{
    switch(GetVehicleModel(vehicleid))
    {
        case 592: return 1;
        case 577: return 1;
        case 512: return 1;
        case 593: return 1;
        case 520: return 1;
        case 553: return 1;
        case 476: return 1;
        case 519: return 1;
        case 460: return 1;
        case 513: return 1;
        case 548: return 1;
        case 425: return 1;
        case 417: return 1;
        case 487: return 1;
        case 488: return 1;
        case 497: return 1;
        case 563: return 1;
        case 447: return 1;
        case 469: return 1;
    }
    return false;
}

stock IsPlayerInVehicleArrais(vehicleid)
{
    switch(GetVehicleModel(vehicleid))
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
        case 539: return 1;
    }
    return false;
}

stock VehicleSupportNitro(vehicleid)
{
    switch(GetVehicleModel(vehicleid))
    {
        case 444: return 0;
        case 581: return 0;
        case 586: return 0;
        case 481: return 0;
        case 509: return 0;
        case 446: return 0;
        case 556: return 0;
        case 443: return 0;
        case 452: return 0;
        case 453: return 0;
        case 454: return 0;
        case 472: return 0;
        case 473: return 0;
        case 484: return 0;
        case 493: return 0;
        case 595: return 0;
        case 462: return 0;
        case 463: return 0;
        case 468: return 0;
        case 521: return 0;
        case 522: return 0;
        case 417: return 0;
        case 425: return 0;
        case 447: return 0;
        case 487: return 0;
        case 488: return 0;
        case 497: return 0;
        case 501: return 0;
        case 548: return 0;
        case 563: return 0;
        case 406: return 0;
        case 520: return 0;
        case 539: return 0;
        case 553: return 0;
        case 557: return 0;
        case 573: return 0;
        case 460: return 0;
        case 593: return 0;
        case 464: return 0;
        case 476: return 0;
        case 511: return 0;
        case 512: return 0;
        case 577: return 0;
        case 592: return 0;
        case 471: return 0;
        case 448: return 0;
        case 461: return 0;
        case 523: return 0;
        case 510: return 0;
        case 430: return 0;
        case 465: return 0;
        case 469: return 0;
        case 513: return 0;
        case 519: return 0;
    }
    return 1;
}

stock CreateVehicleEx(type, Float:x, Float:y, Float:z, Float:angle, color1, color2, vehicleadm = -1, baseid = -1, listvehicleid = 0, slot = -1, ownerid = -1)
{
    for(new i = 0; i < MAX_VEHICLES; i++)
    {
        if(PublicVehicle[i][pv_vehicle])
            continue;

        PublicVehicle[i][pv_vehicle] = AddStaticVehicleEx(type, x, y, z, angle, color1, color2, -1);
        PublicVehicle[i][pv_id] = INVALID_PLAYER_ID;
        PublicVehicle[i][pv_gasoline] = 60;

        if(!IsBike(PublicVehicle[i][pv_vehicle])) SetVehicleParamsEx(PublicVehicle[i][pv_vehicle], 0, 0, 0, 0, 0, 0, 0);

        if(vehicleadm != -1)
        {
            PublicVehicle[i][pv_adm] = true;
        }
        else if(baseid != -1)
        {
            VehicleBase[baseid][listvehicleid][vb_id] = PublicVehicle[i][pv_vehicle];
            VehicleBase[baseid][listvehicleid][vb_model] = BASE_VEHICLE_MODEL;
            VehicleBase[baseid][listvehicleid][vb_connect] = true;

            PublicVehicle[i][pv_listvehicleid] = listvehicleid;
            PublicVehicle[i][pv_base] = baseid;
        }
        else if(slot != -1)
        {
            DataVehicles[slot][ownerid][vvehicle] = PublicVehicle[i][pv_vehicle];
            DataVehicles[slot][ownerid][vconnected] = true;

            PublicVehicle[i][pv_gasoline] = DataVehicles[slot][ownerid][vgasoline];
            PublicVehicle[i][pv_km] = DataVehicles[slot][ownerid][vkm];
            PublicVehicle[i][pv_slot] = slot;
            PublicVehicle[i][pv_id] = ownerid;

            SetVehicleNumberPlate(PublicVehicle[i][pv_vehicle], DataVehicles[slot][ownerid][vplate]);
            SetVehicleToRespawn(PublicVehicle[i][pv_vehicle]);
            TuneThisCar(ownerid, slot);
        }

        return PublicVehicle[i][pv_vehicle];
    }
    return 1;
}

stock DestroyVehicleEx(vehicleid)
{
    for(new i = 0; i < MAX_VEHICLES; i++)
    {
        if(vehicleid == PublicVehicle[i][pv_vehicle])
        {
            if(IsValidDynamicObject(PublicVehicle[i][pv_neon1])) DestroyDynamicObject(PublicVehicle[i][pv_neon1]);
            if(IsValidDynamicObject(PublicVehicle[i][pv_neon2])) DestroyDynamicObject(PublicVehicle[i][pv_neon2]);

            DestroyVehicle(PublicVehicle[i][pv_vehicle]);

            if(IsVehicleAdmin(i))
            {
                PublicVehicle[i][pv_adm] = false;
            }
            else if(IsVehicleBase(i))
            {
                new baseid = PublicVehicle[i][pv_base];
                new listvehicleid = PublicVehicle[i][pv_listvehicleid];

                VehicleBase[baseid][listvehicleid][vb_id] = 0;
                VehicleBase[baseid][listvehicleid][vb_model] = BASE_VEHICLE_MODEL;
                VehicleBase[baseid][listvehicleid][vb_connect] = false;

                PublicVehicle[i][pv_base] = -1;
            }
            else if(IsVehicleSingle(i))
            {
                new ownerid = PublicVehicle[i][pv_id];
                new slot = PublicVehicle[i][pv_slot];

                GetVehicleHealth(DataVehicles[slot][ownerid][vvehicle], DataVehicles[slot][ownerid][vlife]);
                DataVehicles[slot][ownerid][vgasoline] = PublicVehicle[i][pv_gasoline];
                DataVehicles[slot][ownerid][vkm] = PublicVehicle[i][pv_km];

                new query[300];
                mysql_format(IDConexao, query, 300, "UPDATE `Vehicles` SET `km`='%f', `gasoline`='%d', `life`='%f' WHERE `slot`='%d' AND `id_contas`='%d'", DataVehicles[slot][ownerid][vkm], DataVehicles[slot][ownerid][vgasoline], DataVehicles[slot][ownerid][vlife], slot, PlayerInfo[ownerid][ID]);
                mysql_query(IDConexao, query);

                DataVehicles[slot][ownerid][vconnected] = false;
                DataVehicles[slot][ownerid][vvehicle] = 0;

                PublicVehicle[i][pv_slot] = -1;
            }

            PublicVehicle[i][pv_gasoline] = 0;
            PublicVehicle[i][pv_km] = 0;
            PublicVehicle[i][pv_vehicle] = 0;
            return 1;
        }
    }
    return 1;
}

stock CreatePlayerVehicle(playerid, type, Float:x, Float:y, Float:z, Float:angle, color1, color2)
{
    for(new i = 0; i < MAX_VEHICLES; i++)
    {
        if(PublicVehicle[i][pv_vehicle])
            continue;

        PublicVehicle[i][pv_vehicle] = AddStaticVehicleEx(type, x, y, z, angle, color1, color2, -1);

        if(!IsBike(PublicVehicle[i][pv_vehicle])) SetVehicleParamsEx(PublicVehicle[i][pv_vehicle], 0, 0, 0, 0, 0, 0, 0);

        format(String, 50, "{FFFFFF}%s {0080FF}%s", (PlayerInfo[playerid][sexo] == SEX_BOY ? ("Jogador") : ("Jogadora")), PlayerInfo[playerid][Nome]);

        PV_Profission[playerid] = true;
        PublicVehicle[i][pv_id] = playerid;
        PublicVehicle[i][pv_gasoline] = 60;
        PublicVehicle[i][pv_loaded] = false;
        PublicVehicle[i][pv_label] = CreateDynamic3DTextLabel(String, 0xFFFFFFFF, x, y, z, 20.0, INVALID_PLAYER_ID, PublicVehicle[i][pv_vehicle]);
        return PublicVehicle[i][pv_vehicle];
    }
    return 1;
}

stock DestroyPlayerVehicle(playerid)
{
    for(new i = 0; i < MAX_VEHICLES; i++)
    {
        if(PublicVehicle[i][pv_id] == playerid && PublicVehicle[i][pv_slot] == -1)
        {
            if(IsValidDynamicObject(PublicVehicle[i][pv_neon1])) DestroyDynamicObject(PublicVehicle[i][pv_neon1]);
            if(IsValidDynamicObject(PublicVehicle[i][pv_neon2])) DestroyDynamicObject(PublicVehicle[i][pv_neon2]);

            DestroyDynamic3DTextLabel(PublicVehicle[i][pv_label]);
            DestroyVehicle(PublicVehicle[i][pv_vehicle]);

            GasRemoveVehicle(PublicVehicle[i][pv_vehicle]);

            PV_Profission[PublicVehicle[i][pv_id]] = false;
            PublicVehicle[i][pv_adm] = false;
            PublicVehicle[i][pv_loaded] = false;
            PublicVehicle[i][pv_gasoline] = 0;
            PublicVehicle[i][pv_km] = 0;
            PublicVehicle[i][pv_vehicle] = 0;
            PublicVehicle[i][pv_id] = INVALID_PLAYER_ID;
            return 1;
        }
    }
    return 1;
}

stock LoadOrDownload(playerid, vehicleid, bool:loading = true) //Beta load performance computer
{
    TogglePlayerControllable(playerid, false);

    if(loading)
    {
        PublicVehicle[vehicleid][pv_loaded] = true;
    }
    else
    {
        PublicVehicle[vehicleid][pv_loaded] = false;
    }

    TogglePlayerControllable(playerid, true);
    return 1;
}

stock getPlayerVehicleID(playerid)
{
    for(new vehicleid = 0; vehicleid < MAX_VEHICLES; vehicleid++)
    {
        if(PublicVehicle[vehicleid][pv_id] == playerid) return vehicleid;
    }
    return 0;
}

stock LeftVehicleProfession(playerid)
{
    ClearAnimations(playerid);
    SendClientMessage(playerid, Erro, "Veículo exclusivo da profissão");
    return 1;
}

stock IsPlayerInVehicleGovernment(playerid)
{
    switch(GetVehicleModel(GetPlayerVehicleID(playerid)))
    {
        case 416, 433, 427, 490, 528, 407, 544, 523, 470, 596, 598, 599, 597, 432, 601, 428: return 1;
    }
    return 0;
}

stock IsVehicleBase(vehicleid)
{
    return PublicVehicle[vehicleid][pv_base] != -1 ? true : false;
}

stock IsVehicleSingle(vehicleid)
{
    return PublicVehicle[vehicleid][pv_slot] != -1 ? true : false;
}

stock IsVehicleAdmin(vehicleid)
{
    return PublicVehicle[vehicleid][pv_adm] ? true : false;
}

stock IsPlayerDriverVehicle(vehicleid)
{
    for(new player = 0; player < MAX_PLAYERS; player++)
    {
        if(GetPlayerState(player) != PLAYER_STATE_DRIVER) continue;

        if(GetPlayerVehicleID(player) == vehicleid) return 1;
    }
    return 0;
}
