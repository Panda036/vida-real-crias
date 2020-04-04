#include YSI\y_hooks

new BKJORNAL[15];
new VCPOLICIA[38];
new BKNOVATOS[5];
new LastVehicle[MAX_PLAYERS] = -1;

public OnVehiclePaintjob(playerid, vehicleid, paintjobid)
{
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
        {
            if(vehicleid == DataVehicles[slot][i][vvehicle])
            {
                DataVehicles[slot][i][vpaintjob] = paintjobid;
                UpdateVehicles(i, slot);
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
                UpdateVehicles(i, slot);
                return 1;
            }
        }
    }
    return 1;
}

hook OnGameModeInit()
{
    BKJORNAL[0] = AddStaticVehicleEx(510, 784.9813, -1356.2255, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[1] = AddStaticVehicleEx(510, 784.9813, -1358.1863, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[2] = AddStaticVehicleEx(510, 784.9813, -1360.1813, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[3] = AddStaticVehicleEx(510, 784.9813, -1362.1833, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[4] = AddStaticVehicleEx(510, 784.9813, -1364.1859, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[5] = AddStaticVehicleEx(510, 784.9813, -1345.0000, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[6] = AddStaticVehicleEx(510, 784.9813, -1343.0000, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[7] = AddStaticVehicleEx(510, 784.9813, -1341.0000, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[8] = AddStaticVehicleEx(510, 784.9810, -1339.0000, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[9] = AddStaticVehicleEx(510, 784.9810, -1337.0000, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[10] = AddStaticVehicleEx(510, 784.9813, -1346.8591, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[11] = AddStaticVehicleEx(510, 784.9813, -1348.7258, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[12] = AddStaticVehicleEx(510, 784.9813, -1350.6263, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[13] = AddStaticVehicleEx(510, 784.9813, -1352.5315, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[14] = AddStaticVehicleEx(510, 784.9813, -1354.4387, 13.1522, 90.0000, 1, 1, 100);

    VCPOLICIA[0] = AddStaticVehicleEx(523,1605.0000,-1605.0000,13.0002,90.0000,-1,-1,100);
    VCPOLICIA[1] = AddStaticVehicleEx(523,1604.9994,-1608.0200,13.0002,90.0000,-1,-1,100);
    VCPOLICIA[2] = AddStaticVehicleEx(523,1604.9994,-1611.0000,13.0002,90.0000,-1,-1,100);
    VCPOLICIA[3] = AddStaticVehicleEx(523,1604.9994,-1614.0000,13.0002,90.0000,-1,-1,100);
    VCPOLICIA[4] = AddStaticVehicleEx(523,1604.9994,-1617.0000,13.0002,90.0000,-1,-1,100);
    VCPOLICIA[5] = AddStaticVehicleEx(523,1604.9994,-1620.0000,13.0002,90.0000,-1,-1,100);
    VCPOLICIA[6] = AddStaticVehicleEx(523,1604.9994,-1623.0000,13.0002,90.0000,-1,-1,100);
    VCPOLICIA[7] = AddStaticVehicleEx(523,1604.9994,-1626.0000,13.0002,90.0000,-1,-1,100);
    VCPOLICIA[8] = AddStaticVehicleEx(523,1604.9994,-1629.0000,13.0002,90.0000,-1,-1,100);
    VCPOLICIA[9] = AddStaticVehicleEx(523,1604.9994,-1632.0000,13.0002,90.0000,-1,-1,100);
    VCPOLICIA[10] = AddStaticVehicleEx(598,1551.0000,-1606.0000,13.0802,180.0000,-1,-1,100);
    VCPOLICIA[11] = AddStaticVehicleEx(598,1554.9801,-1606.0016,13.0802,180.0000,-1,-1,100);
    VCPOLICIA[12] = AddStaticVehicleEx(598,1559.0000,-1605.9719,13.0802,180.0000,-1,-1,100);
    VCPOLICIA[13] = AddStaticVehicleEx(598,1563.0000,-1606.0000,13.0802,180.0000,-1,-1,100);
    VCPOLICIA[14] = AddStaticVehicleEx(598,1567.0000,-1606.0010,13.0802,180.0000,-1,-1,100);
    VCPOLICIA[15] = AddStaticVehicleEx(598,1571.0000,-1606.0010,13.0802,180.0000,-1,-1,100);
    VCPOLICIA[16] = AddStaticVehicleEx(598,1575.0000,-1606.0010,13.0802,180.0000,-1,-1,100);
    VCPOLICIA[17] = AddStaticVehicleEx(598,1579.0000,-1606.0010,13.0802,180.0000,-1,-1,100);
    VCPOLICIA[18] = AddStaticVehicleEx(598,2252.0000, 2476.5591,10.4215,180.0000,-1,-1,100);
    VCPOLICIA[19] = AddStaticVehicleEx(598,2255.9714,2476.5591,10.4215,180.0000,-1,-1,100);
    VCPOLICIA[20] = AddStaticVehicleEx(598,2260.4031,2476.5591,10.4215,180.0000,-1,-1,100);
    VCPOLICIA[21] = AddStaticVehicleEx(598,2269.3093,2476.5591,10.4215,180.0000,-1,-1,100);
    VCPOLICIA[22] = AddStaticVehicleEx(598,2273.3691,2476.5591,10.4215,180.0000,-1,-1,100);
    VCPOLICIA[23] = AddStaticVehicleEx(598,2277.8213,2476.5591,10.4215,180.0000,-1,-1,100);
    VCPOLICIA[24] = AddStaticVehicleEx(598,2282.3047,2476.5940,10.4215,180.0000,-1,-1,100);
    VCPOLICIA[25] = AddStaticVehicleEx(497,-220.9945,995.6248,19.7057,-90.0000,-1,-1,100);
    VCPOLICIA[26] = AddStaticVehicleEx(599,-209.1601,998.7247,19.7419,180.0000,-1,-1,100);
    VCPOLICIA[27] = AddStaticVehicleEx(598,-214.1810,972.8283,18.9690,-90.0000,-1,-1,100);
    VCPOLICIA[28] = AddStaticVehicleEx(497,-1680.3081,704.7817,30.9151,0.0000,-1,-1,100);
    VCPOLICIA[29] = AddStaticVehicleEx(523,-1581.6348,652.1369,6.6743,0.0000,-1,-1,100);
    VCPOLICIA[30] = AddStaticVehicleEx(523,-1587.7535,652.1369,6.6743,0.0000,-1,-1,100);
    VCPOLICIA[31] = AddStaticVehicleEx(523,-1593.5933,652.1369,6.6743,0.0000,-1,-1,100);
    VCPOLICIA[32] = AddStaticVehicleEx(523,-1599.4490,652.1369,6.6743,0.0000,-1,-1,100);
    VCPOLICIA[33] = AddStaticVehicleEx(598,-1610.7079,651.8018,6.8743,0.0000,-1,-1,100);
    VCPOLICIA[34] = AddStaticVehicleEx(598,-1616.5802,651.8018,6.8743,0.0000,-1,-1,100);
    VCPOLICIA[35] = AddStaticVehicleEx(598,-1622.5671,651.8018,6.8743,0.0000,-1,-1,100);
    VCPOLICIA[36] = AddStaticVehicleEx(598,-1628.4109,651.8018,6.8743,0.0000,-1,-1,100);
    VCPOLICIA[37] = AddStaticVehicleEx(598,-1634.2976,651.8018,6.8743,0.0000,-1,-1,100);
    for(new i = 0; i < 38; i++) { SetVehicleParamsEx(VCPOLICIA[i], 0, 0, 0, 0, 0, 0, 0); }

    BKNOVATOS[0] = AddStaticVehicleEx(481,828.0000,-1336.0000,13.0416,359.3848,1,1,100);
    BKNOVATOS[1] = AddStaticVehicleEx(481,830.0000,-1336.0000,13.0416,359.3848,1,1,100);
    BKNOVATOS[2] = AddStaticVehicleEx(481,832.0000,-1336.0000,13.0416,359.3848,1,1,100);
    BKNOVATOS[3] = AddStaticVehicleEx(481,834.0000,-1336.0000,13.0416,359.3848,1,1,100);
    BKNOVATOS[4] = AddStaticVehicleEx(481,836.0000,-1336.0000,13.0416,359.3848,1,1,100);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    LastVehicle[playerid] = -1;
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

    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
        {
            if(!ispassenger && vehicleid != INVALID_VEHICLE_ID && vehicleid == DataVehicles[slot][i][vvehicle] && DataVehicles[slot][i][vconnected])
            {
                if(PlayerInfo[i][Nome] == PlayerInfo[playerid][Nome])
                {
                    format(String, sizeof(String), "{00C40A}~~> {FFFFFF}Bem-vindo ao seu veículo %s, %s", getVehicleName(DataVehicles[slot][i][vmodel]), PlayerInfo[i][Nome]);
                    SendClientMessage(playerid, White, String);
                    return 1;
                }
                else
                {
                    if(DataVehicles[slot][i][vlock])
                    {
                        ClearAnimations(playerid);
                        format(String, sizeof(String), "{FF4000}~~x {FFFFFF}Esse veículo \"%s\" pertence à %s e está trancado!", DataVehicles[slot][i][vmessage], PlayerInfo[i][Nome]);
                        SendClientMessage(playerid, White, String);
                        return 1;
                    }
                    else
                    {
                        format(String, sizeof(String), "{FF4000}~~x {FFFFFF}Esse veículo \"%s\" pertence à %s e está destrancado!", DataVehicles[slot][i][vmessage], PlayerInfo[i][Nome]);
                        SendClientMessage(playerid, White, String);
                        return 1;
                    }
                }
            }
        }
    }
    for(new i; i < sizeof(BKJORNAL); i ++) if(vehicleid == BKJORNAL[i])
    {
        if(!ispassenger && vehicleid != INVALID_VEHICLE_ID && PlayerInfo[playerid][Profissao] != newspaperdelivery)
        {
            ClearAnimations(playerid);
            return SendClientMessage(playerid, Erro, "Veiculo exclusivo da profissão Entregador(a) de Jornal");
        }
    }
    for(new i; i < sizeof(VCPOLICIA); i++) if(vehicleid == VCPOLICIA[i])
    {
        if(!ispassenger && vehicleid != INVALID_VEHICLE_ID && !IsPlayerPolice(playerid) && PlayerInfo[playerid][Profissao] != internalaffairs)
        {
            ClearAnimations(playerid);
            return SendClientMessage(playerid, Erro, "Veiculo exclusivo da profissãoo Policia");
        }
        if(!ispassenger && vehicleid != INVALID_VEHICLE_ID && !IsPlayerUniformPM(playerid) && IsPlayerPolice(playerid))
        {
            ClearAnimations(playerid);
            return SendClientMessage(playerid, Erro, "Você não está com o uniforme");
        }
    }
    for(new i; i < sizeof(BKNOVATOS); i++) if(vehicleid == BKNOVATOS[i])
    {
        if(!ispassenger && vehicleid != INVALID_VEHICLE_ID && PlayerInfo[playerid][Level] > 5)
        {
            ClearAnimations(playerid);
            return SendClientMessage(playerid, Erro, "Bike exclusiva para novatos");
        }
    }
    return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    new vehicleid = GetPlayerVehicleID(playerid);

    if(newstate == PLAYER_STATE_DRIVER && !IsPlayerInAnyBike(vehicleid))
    {
        SendClientMessage(playerid, -1, "Para ligar ou desligar o veículo \"{CECECE}/Partida{FFFFFF}\" ou \"{CECECE}Y{FFFFFF}\"");

        if(IsPlayerInVehicleA(vehicleid) && !PlayerInfo[playerid][cnh_a])
            return SendClientMessage(playerid, Yellow, "Você não possui CNH \"Categoria A\" e poderá ser multado");

        if(IsPlayerInVehicleB(vehicleid) && !PlayerInfo[playerid][cnh_b])
            return SendClientMessage(playerid, Yellow, "Você não possui CNH \"Categoria B\" e poderá ser multado");

        if(IsPlayerInVehicleC(vehicleid) && !PlayerInfo[playerid][cnh_c])
            return SendClientMessage(playerid, Yellow, "Você não possui CNH \"Categoria C\" e poderá ser multado");

        if(IsPlayerInVehicleCHT(vehicleid) && !PlayerInfo[playerid][cnh_cht])
            return SendClientMessage(playerid, Yellow, "Você não possui CNH \"CHT\" e poderá ser multado");

        if(IsPlayerInVehicleArrais(vehicleid) && !PlayerInfo[playerid][cnh_arrais])
            return SendClientMessage(playerid, Yellow, "Você não possui \"CNH Arrais\" e poderá ser multado");

        return 1;
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(PRESSED(KEY_FIRE))
	{
        if(!Perseguicao[playerid])
        {
            if(IsPlayerHelper(playerid) || IsPlayerVip(playerid))
            {
                if(IsPlayerInAnyVehicle(playerid))
                {
                    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
                    {
                        if(NitroInfinito(GetPlayerVehicleID(playerid)))
                        {
                            AddVehicleComponent(GetPlayerVehicleID(playerid), 1010);
                            RepairVehicle(GetPlayerVehicleID(playerid));
                        }
                    }
                }
        	}
        }
        return 1;
    }
    if(PRESSED(KEY_YES))
    {
        new vehicleid = GetPlayerVehicleID(playerid), mot, lu, alar, por, cap, porma, ob;

        GetVehicleParamsEx(vehicleid,  mot, lu, alar, por, cap, porma, ob);

        if(IsPlayerInAnyBike(vehicleid)) return 0;

        if(IsPlayerInAnyVehicle(playerid))
        {
            if(mot == VEHICLE_PARAMS_OFF)
            {
                for(new i = 0; i < MAX_PLAYERS; i++)
                {
                    for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
                    {
                        if(vehicleid == DataVehicles[slot][i][vvehicle] && DataVehicles[slot][i][vconnected])
                        {
                            if(!DataVehicles[slot][i][vgasoline])
                                return SendClientMessage(playerid, Erro, "Este veículo não tem Gasolina");
                        }
                    }
                }


                SetVehicleParamsEx(vehicleid, VEHICLE_PARAMS_ON, 1, alar, por, cap, porma, ob);
                SendClientMessage(playerid, Green, "Veiculo ligado");
            } else {
            	SendClientMessage(playerid, Green, "Veiculo desligado");
                SetVehicleParamsEx(vehicleid, VEHICLE_PARAMS_OFF, 0, alar, por, cap, porma, ob);
            }
        }
        return 1;
    }
	return 1;
}

stock IsPlayerInAnyBike(vehicleid)
{
    if(GetVehicleModel(vehicleid) == 481 || GetVehicleModel(vehicleid) == 509 || GetVehicleModel(vehicleid) == 510)
	{
	    return true;
	}
	return false;
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
