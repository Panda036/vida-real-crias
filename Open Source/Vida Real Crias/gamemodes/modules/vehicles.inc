#include YSI\y_hooks

new LastVehicle[MAX_PLAYERS];

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
                break;
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

    //Novatos
    CreateVehicleEx(481,828.0000,-1336.0000,13.0416,359.3848,1,1);
    CreateVehicleEx(481,830.0000,-1336.0000,13.0416,359.3848,1,1);
    CreateVehicleEx(481,832.0000,-1336.0000,13.0416,359.3848,1,1);
    CreateVehicleEx(481,834.0000,-1336.0000,13.0416,359.3848,1,1);
    CreateVehicleEx(481,836.0000,-1336.0000,13.0416,359.3848,1,1);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    LastVehicle[playerid] = INVALID_VEHICLE_ID;
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

        if(HavePlayerDriverVehicle(vehicleid))
        {
            ClearAnimations(playerid);
            SetPlayerVirtualWorld(playerid, playerid);
            TogglePlayerControllable(playerid, false);
            SendClientMessage(playerid, Yellow, "Você foi bloqueado por 5 segundos pela tentativa de roubo");
            SetTimerEx("UnlockedPlayerTheft", 5000, false, "d", playerid);
            return 1;
        }

        if(PublicVehicle[i][pv_id] == INVALID_PLAYER_ID)
        {
            if(PublicVehicle[i][pv_adm] && !IsPlayerIntern(playerid) && !PlayerInfo[playerid][pds_in])
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
                case 497, 523, 598, 599:
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
        if(vehicleid == PublicVehicle[i][pv_vehicle] && PublicVehicle[i][pv_id] != INVALID_PLAYER_ID)
        {
            if(PublicVehicle[i][pv_id] != playerid)
            {
                ClearAnimations(playerid);
                SendClientMessage(playerid, Erro, "Este veículo não te pertence");
                return 1;
            }

            break;
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
    if(PRESSED(KEY_YES))
    {
        new mot, lu, alar, por, cap, porma, ob, vehicleid = GetPlayerVehicleID(playerid);

        if(!IsPlayerInAnyVehicle(playerid))
            return 0;

        if(IsBike(vehicleid))
            return 0;

        if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
            return 0;

        if(IsBrokenVehicle(vehicleid))
            return 0;

        GetVehicleParamsEx(vehicleid, mot, lu, alar, por, cap, porma, ob);

        for(new i = 0; i < MAX_VEHICLES; i++)
        {
            if(mot) break;

            if(vehicleid != PublicVehicle[i][pv_vehicle]) continue;

            if(!PublicVehicle[i][pv_gasoline])
                return SendClientMessage(playerid, Erro, "Este veículo não tem Gasolina");

            break;
        }

        SendClientMessage(playerid, Green, (mot ? ("Veiculo desligado") : ("Veiculo ligado")));
        SetVehicleParamsEx(vehicleid, (mot ? 0 : 1), (mot ? 0 : 1), alar, por, cap, porma, ob);

        if(Fueling[playerid] && mot){
            Fueling[playerid] = false;
            SendClientMessage(playerid, Yellow, "O abastecimento foi cancelado");
        }
        return 1;
    }
    if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
    {
        new vehicleid = GetPlayerVehicleID(playerid);

        if((IsPlayerIntern(playerid) || IsPlayerVip(playerid) || IsPlayerYoutuber(playerid) || PlayerInfo[playerid][Profissao] == mechanical) && !Perseguicao[playerid] && VehicleSupportNitro(vehicleid) && !IsBrokenVehicle(vehicleid))
        {
            if((newkeys & (KEY_FIRE)) == (KEY_FIRE))
            {
                new Float:health;

                GetVehicleHealth(vehicleid, health);

                if(health < 1000.0) RepairVehicle(vehicleid);

                AddVehicleComponent(vehicleid, 1010);
            }
            else if((oldkeys & (KEY_FIRE)) == (KEY_FIRE))
            {
                RemoveVehicleComponent(vehicleid, 1010);
            }
        }
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
    SetPlayerVirtualWorld(playerid, WORLD_DEFAULT);
    TogglePlayerControllable(playerid, true);
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

            SetVehicleHealth(PublicVehicle[i][pv_vehicle], DataVehicles[slot][ownerid][vlife]);
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
            if(PublicVehicle[i][pv_neon])
            {
                PublicVehicle[i][pv_neon] = false;
                DestroyDynamicObject(PublicVehicle[i][pv_neon1]);
                DestroyDynamicObject(PublicVehicle[i][pv_neon2]);
            }

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

                GetVehicleHealth(PublicVehicle[i][pv_vehicle], DataVehicles[slot][ownerid][vlife]);
                DataVehicles[slot][ownerid][vgasoline] = PublicVehicle[i][pv_gasoline];
                DataVehicles[slot][ownerid][vkm] = PublicVehicle[i][pv_km];

                new query[200];
                mysql_format(IDConexao, query, 200, "UPDATE `Vehicles` SET `km`='%f', `gasoline`='%d', `life`='%f' WHERE `slot`='%d' AND `id_contas`='%d'", DataVehicles[slot][ownerid][vkm], DataVehicles[slot][ownerid][vgasoline], DataVehicles[slot][ownerid][vlife], slot, PlayerInfo[ownerid][ID]);
                mysql_query(IDConexao, query);

                DataVehicles[slot][ownerid][vconnected] = false;
                DataVehicles[slot][ownerid][vvehicle] = 0;
                PublicVehicle[i][pv_slot] = -1;
            }

            DestroyVehicle(PublicVehicle[i][pv_vehicle]);

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
            if(PublicVehicle[i][pv_neon])
            {
                PublicVehicle[i][pv_neon] = false;
                DestroyDynamicObject(PublicVehicle[i][pv_neon1]);
                DestroyDynamicObject(PublicVehicle[i][pv_neon2]);
            }

            GasRemoveVehicle(PublicVehicle[i][pv_vehicle]);
            RemoveWoodsVehicle(PublicVehicle[i][pv_vehicle]);

            DestroyDynamic3DTextLabel(PublicVehicle[i][pv_label]);
            DestroyVehicle(PublicVehicle[i][pv_vehicle]);

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
    return INVALID_VEHICLE_ID;
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

stock HavePlayerDriverVehicle(vehicleid)
{
    for(new playerid = 0; playerid < MAX_PLAYERS; playerid++)
    {
        if(!PlayerInfo[playerid][Logado]) continue;

        if(!IsPlayerInAnyVehicle(playerid)) continue;

        if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) continue;

        if(GetPlayerVehicleID(playerid) == vehicleid) return 1;
    }
    return 0;
}
