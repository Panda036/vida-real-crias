CMD:cp(playerid, params[])
{
    if(PlayerInfo[playerid][Profissao] == unemployed)
        return PC_EmulateCommand(playerid, "/profissao");

    new tmp[128];

    if(sscanf(params, "s[128]", tmp))
        return SendClientMessage(playerid, Erro, "Digite: /Cp [mensagem]");

    for (new i; i < MAX_PLAYERS; i++)
    {
        if(PlayerInfo[i][Profissao] == PlayerInfo[playerid][Profissao])
        {
            format(String, sizeof(String), "| Chat-Profissão | %s [%d] diz: %s", PlayerInfo[playerid][Nome], playerid, tmp);
            SendClientMessage(i, GetPlayerColor(playerid), String);
        }
    }
    return 1;
}
CMD:hq(playerid)
{
    switch(PlayerInfo[playerid][Profissao])
    {
        case newspaperdelivery:
            SetPlayerCheckpoint(playerid, 785.20, -1327.76, 13.54, 1.0);
        case icecream:
            SetPlayerCheckpoint(playerid, 2444.00, 1663.00, 10.82, 1.0);
        case pizzaboy:
            SetPlayerCheckpoint(playerid, 2107.74, -1787.75, 13.56, 1.0);
        case gari:
            SetPlayerCheckpoint(playerid, 2089.53, -2080.92, 13.55, 1.0);
        case lawyer:
            SetPlayerCheckpoint(playerid, -2051.2988, 459.8927, 35.1719, 1.0);
        case taxi:
            SetPlayerCheckpoint(playerid, 2229.5803,-1368.1969,23.9922, 1.0);
        case tanker:
            SetPlayerCheckpoint(playerid, 285.1086, 1422.3751, 10.5859, 1.0);
        case military..interpol:
            SetPlayerCheckpoint(playerid, 1579.5728,-1635.3932,13.5611, 1.0);
        case navy:
            SetPlayerCheckpoint(playerid, -1425.5208, 501.3613, 3.0391, 1.0);
        case army:
            SetPlayerCheckpoint(playerid, 126.1066, 1897.4442, 18.4865, 1.0);
        case aeronautics:
            SetPlayerCheckpoint(playerid, 126.1066, 1897.4442, 18.4865, 1.0);
        case thief:
            SetPlayerCheckpoint(playerid, -453.7872, 2230.1296, 42.4993, 1.0);
        default:
            PC_EmulateCommand(playerid, "/profissao");
    }
    return 1;
}

CMD:cancelar(playerid)
{
    if(PlayerInfo[playerid][Profissao] == newspaperdelivery)
    {
        if(!Newspaper[playerid])
            return SendClientMessage(playerid, Erro, "Você não tem nenhuma entrega pendente");

        Newspaper[playerid] = 0;
        DisablePlayerRaceCheckpoint(playerid);
        SendClientMessage(playerid, color_newspaperdelivery, "Você cancelou suas entregas");
        return 1;
    }
    else if(PlayerInfo[playerid][Profissao] == pizzaboy)
    {
        if(!pb_pizzas[playerid])
            return SendClientMessage(playerid, Erro, "Você não tem nenhuma entrega pendente");

        if(pb_pickup[playerid]) DestroyDynamicPickup(pb_pickup[playerid]);
        if(pb_mapicon[playerid]) DestroyDynamicMapIcon(pb_mapicon[playerid]);
        if(pb_label[playerid]) DestroyDynamic3DTextLabel(pb_label[playerid]);

        pb_pizzas[playerid] = 0;
        SendClientMessage(playerid, color_pizzaboy, "Você cancelou suas entregas");
        return 1;
    }
    else
    {
        SendClientMessage(playerid, Erro, "Você não tem permissão");
    }
    return 1;
}
CMD:uniforme(playerid)
{
    if(IsPlayerPolice(playerid))
    {
        if(!IsPlayerInRangeOfPoint(playerid, 1.5, 254.17, 74.33, 1003.64))
            return SendClientMessage(playerid, Erro, "Você não está no vestiário do Departamento de Polícia");

        if(IsPlayerUniformPM(playerid))
            return SendClientMessage(playerid, Erro, "Você já está em um uniforme");

        ShowTDPlayerSkinList(playerid);
        return 1;
    }
    else if(PlayerInfo[playerid][Profissao] == paramedic)
    {
        if(!IsPlayerInRangeOfPoint(playerid, 1.5, 1027.10, 997.50, 15.11))
            return SendClientMessage(playerid, Erro, "Você não está no vestiário do Hospital");

        if(IsPlayerUniformParamedic(playerid))
            return SendClientMessage(playerid, Erro, "Você já está em um uniforme");

        if(!strcmp(PlayerInfo[playerid][sexo], "Feminino"))
            { SetPlayerSkin(playerid, 308); }
        else
            { SetPlayerSkin(playerid, 276); }

        SendClientMessage(playerid, color_paramedic, "Agora você está uniformizado(a), e poderá exercer sua profissão");
        return 1;
    }
    else
    {
        SendClientMessage(playerid, Erro, "Você não tem permissão");
    }
    return 1;
}
