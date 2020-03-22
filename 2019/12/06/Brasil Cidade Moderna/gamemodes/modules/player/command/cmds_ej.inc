    if(strcmp(cmdtext, "/Pegarjornais", true)==0)                                    //EntregadorJornal
    {
        if(PlayerInfo[playerid][Profissao] != EntregadorJornais)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não tem permissão!");

        if(GetVehicleModel(GetPlayerVehicleID(playerid)) != 510)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não está em uma Mountain Bike!");

        if(!IsPlayerInRangeOfPoint(playerid, 20.0, 784.9813, -1345.0000, 13.1522))
            return SendClientMessage(playerid, Erro, "| ERRO | Você não está na sua HQ!");

        if(Newspaper[playerid] != 0)
            return SendClientMessage(playerid, Erro, "| ERRO | Você já pegou jornal!");

        BlockNewspaper[playerid] = false;
        Newspaper[playerid] = 20;

        new rand = random(sizeof(NL));

        format(PNL[playerid][RandomLocal], 40, NL[rand][nnLocations]);
        PNL[playerid][RandomX] = NL[rand][nnPosX];
        PNL[playerid][RandomY] = NL[rand][nnPosY];
        PNL[playerid][RandomZ] = NL[rand][nnPosZ];
        PNL[playerid][VaiReceber] = NL[rand][nnGetWork];

        SetPlayerRaceCheckpoint(playerid, 1, NL[rand][nnPosX], NL[rand][nnPosY], NL[rand][nnPosZ], 0, 0, 0, 2.0);

        SendClientMessage(playerid, 0x80FF80AA, "| BCM-News | Você pegou 20 jornais, vá até o checkpoint vermelho marcado no mini-mapa");
        return 1;
    }
    if(strcmp(cmdtext, "/cancelar", true)==0)
    {
        if(PlayerInfo[playerid][Profissao] != EntregadorJornais)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não tem permissão!");

        if(Newspaper[playerid] == 0)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não tem nenhuma entrega pendente!");

        Newspaper[playerid]=0;
        DisablePlayerRaceCheckpoint(playerid);
        SendClientMessage(playerid, 0x80FF80AA, "| BCM-News | Você cancelou suas entregas!");
        return 1;
    }
