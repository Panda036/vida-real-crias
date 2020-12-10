CMD:p(playerid, params[])
{
    if(PlayerInfo[playerid][Profissao] == unemployed)
        return PC_EmulateCommand(playerid, "/profissao");

    new tmp[128];

    if(sscanf(params, "s[128]", tmp))
        return SendClientMessage(playerid, Erro, "Digite: /P [mensagem]");

    for (new i; i < MAX_PLAYERS; i++)
    {
        if(PlayerInfo[i][Profissao] == PlayerInfo[playerid][Profissao])
        {
            format(String, MAX_STRING, "Profissão ~ %s [%d] diz: %s", PlayerInfo[playerid][Nome], playerid, tmp);
            SendClientMessage(i, GetPlayerColor(playerid), String);
        }
    }
    return 1;
}
CMD:lt(playerid)
{
    switch(PlayerInfo[playerid][Profissao])
    {
        case newspaperdelivery:
            CreateCPGPS(playerid, 785.20, -1327.76, 13.54);
        case icecream:
            CreateCPGPS(playerid, 2444.00, 1663.00, 10.82);
        case pizzaboy:
            CreateCPGPS(playerid, 2107.74, -1787.75, 13.56);
        case gari:
            CreateCPGPS(playerid, 2089.53, -2080.92, 13.55);
        case paramedic:
            CreateCPGPS(playerid, 1599.87, 1818.08, 10.82);
        case light:
            CreateCPGPS(playerid, -2516.58, -622.51, 132.75);
        case lawyer:
            CreateCPGPS(playerid, -2051.2988, 459.8927, 35.1719);
        case taxi:
            CreateCPGPS(playerid, 2229.5803,-1368.1969,23.9922);
        case tanker:
            CreateCPGPS(playerid, 285.1086, 1422.3751, 10.5859);
        case loader:
            CreateCPGPS(playerid, 2467.97, -2118.98, 13.54);
        case military..interpol:
            CreateCPGPS(playerid, 1579.5728,-1635.3932,13.5611);
        case navy:
            CreateCPGPS(playerid, -1425.5208, 501.3613, 3.0391);
        case army:
            CreateCPGPS(playerid, 126.1066, 1897.4442, 18.4865);
        case aeronautics:
            CreateCPGPS(playerid, 126.1066, 1897.4442, 18.4865);
        case potplanter:
            CreateCPGPS(playerid, -1184.80, -1136.56, 129.21);
        case burglar:
            CreateCPGPS(playerid, -391.40, 2221.69, 42.42);
        case thief:
            CreateCPGPS(playerid, -391.40, 2221.69, 42.42);
        default:
            PC_EmulateCommand(playerid, "/profissao");
    }
    return 1;
}

CMD:cancelar(playerid)
{
    switch(PlayerInfo[playerid][Profissao])
    {
        case newspaperdelivery:
        {
            if(!Newspaper[playerid])
                return SendClientMessage(playerid, Erro, "Você não tem nenhuma entrega pendente");

            if(IsValidDynamicRaceCP(CPSEJ[playerid])) DestroyDynamicRaceCP(CPSEJ[playerid]);
        }
        case pizzaboy:
        {
            if(!pb_pizzas[playerid])
                return SendClientMessage(playerid, Erro, "Você não tem nenhuma entrega pendente");

            pb_pizzas[playerid] = 0;
            DestroyDynamicPickup(pb_pickup[playerid]);
            DestroyDynamicMapIcon(pb_mapicon[playerid]);
            DestroyDynamic3DTextLabel(pb_label[playerid]);
        }
        case tanker:
        {
            if(!Petroleum[playerid][ptl_value])
                return SendClientMessage(playerid, Erro, "Você não tem nenhuma entrega pendente");

            if(_gpson[playerid]){
                DestroyDynamicMapIcon(_gpsmap[playerid]);
                _gpson[playerid] = false;
            }
            Petroleum[playerid][ptl_value] = 0;
        }
        case strongcardriver:
        {
            new vehicleid = getPlayerVehicleID(playerid);

            if(GetVehicleModel(PublicVehicle[vehicleid][pv_vehicle]) != 428)
                return SendClientMessage(playerid, Erro, "Seu último veículo não é um Carro Forte");

            PublicVehicle[vehicleid][pv_loaded] = false;
        }
        case light:
        {
            if(light_route[playerid] == -1)
                return SendClientMessage(playerid, Erro, "Você não tem consertos pendente");

            light_route[playerid] = -1;
            DestroyDynamicRaceCP(light_cp[playerid]);
            Light_Place_Repair[playerid][lpr_x] = 0;
            Light_Place_Repair[playerid][lpr_y] = 0;
            Light_Place_Repair[playerid][lpr_z] = 0;
        }
        case loader:
        {
            new vehicleid = getPlayerVehicleID(playerid);

            if(!vehicleid)
                return 0;

            if(!PublicVehicle[vehicleid][pv_loaded])
                return SendClientMessage(playerid, Erro, "Seu veículo não está carregado");

            loader_count[playerid] = 0;
            DestroyDynamicRaceCP(loader_cp[playerid]);
            PublicVehicle[vehicleid][pv_loaded] = false;
        }
        case motoboy:
        {
            if(!MotoBoy[playerid][mb_accept])
                return SendClientMessage(playerid, Erro, "Você não tem pedido pendente");

            MotoBoy[playerid][mb_accept] = false;
            MotoBoy[playerid][mb_business] = false;
            DestroyDynamicRaceCP(MotoBoy[playerid][mb_cp]);
        }
        default: return SendClientMessage(playerid, Erro, "Você não tem permissão");
    }

    PlayerInfo[playerid][Dinheiro] -= 500;
    UpdatePlayerMoney(playerid);

    SendClientMessage(playerid, Yellow, "Você cancelou sua(as) entrega(as) e perdeu -$500");
    return 1;
}
CMD:localizar(playerid, params[])
{
    if(!IsPlayerPolice(playerid) && !IsPlayerIntern(playerid) && PlayerInfo[playerid][Profissao] != taxi && PlayerInfo[playerid][Profissao] != paramedic)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(locate[playerid])
        return SendClientMessage(playerid, Erro, "Você já está localizando um(a) jogador(a), digite: /Deslocalizar");

    if((IsPlayerPolice(playerid) && !IsPlayerUniformPM(playerid)) || (PlayerInfo[playerid][Profissao] == paramedic && !IsPlayerUniformParamedic(playerid)))
        return SendClientMessage(playerid, Erro, "Você não está com o uniforme");

    new id;

    if(sscanf(params, "d", id))
        return SendClientMessage(playerid, Erro, "Digite: /Localizar [id]");

    if(!PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) não conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    if(IsPlayerPolice(playerid) && !PlayerInfo[id][Estrelas])
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) não está procurado(a)");

    if(locate[playerid]) KillTimer(TimerProcurando[playerid]);

    locate[playerid] = true;
    TimerProcurando[playerid] = SetTimerEx("OnPlayerLocate", 1000, true, "dd", playerid, id);

    SendClientMessage(playerid, Green, "Jogador(a) localizado(a)");
    return 1;
}
CMD:deslocalizar(playerid)
{
    if(!IsPlayerPolice(playerid) && !IsPlayerIntern(playerid) && PlayerInfo[playerid][Profissao] != taxi && PlayerInfo[playerid][Profissao] != paramedic)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!locate[playerid])
        return SendClientMessage(playerid, Erro, "Você não localizou algum jogador(a)");

    locate[playerid] = false;
    KillTimer(TimerProcurando[playerid]);
    if(IsValidDynamicMapIcon(maplocate[playerid])) DestroyDynamicMapIcon(maplocate[playerid]);

    SendClientMessage(playerid, Green, "Jogador(a) deslocalizado(a)");
    return 1;
}
