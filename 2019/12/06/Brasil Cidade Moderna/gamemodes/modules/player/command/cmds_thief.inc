    if(strcmp(cmd, "/roubargas", true)==0)
    {
        if(PlayerInfo[playerid][Profissao] != LadraoGas)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não tem permissão!");

        if(VehicleSGas[playerid][VSGas] == 0)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não pegou seu veículo de ladrão!");

        if(AmountGas[playerid] != 0)
            return SendClientMessage(playerid, Erro, "| ERRO | Você já pegou informação de roubo de gás!");

        AmountGas[playerid] = 5;
        SendClientMessage(playerid, 0xFF8080AA, "| LADRÃO | Foi informado que tem 5 bujões de gás marcando bobeira!!!");
        SendClientMessage(playerid, 0xFF8080AA, "| LADRÃO | Vá até o checkpoint marcado no mini-mapa para começar a roubar!");

        new i = random(sizeof(LocationsGas));

        format(PLGas[playerid][pLocality], 40, LocationsGas[i][Locality]);
        PLGas[playerid][pGasPosX] = LocationsGas[i][GasPosX];
        PLGas[playerid][pGasPosY] = LocationsGas[i][GasPosY];
        PLGas[playerid][pGasPosZ] = LocationsGas[i][GasPosZ];
        PLGas[playerid][pGetWork] = LocationsGas[i][GetWork];

        CPS_Gas[playerid] = CPS_AddCheckpoint(LocationsGas[i][GasPosX], LocationsGas[i][GasPosY], LocationsGas[i][GasPosZ], 1.0, 999999999);
        ObjectGas[playerid] = CreateObject(1370, LocationsGas[i][GasPosX], LocationsGas[i][GasPosY], LocationsGas[i][GasPosZ], 0.0, 0.0, 0.0);
        return 1;
    }
    if(strcmp(cmd, "/pegargas", true)==0) //{00C40A} {FF8000}
    {
        if(PlayerInfo[playerid][Profissao] != LadraoGas)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não tem permissão!");

        if(AmountGas[playerid] == 0)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não tem pegou nenhuma informação de roubo de gás!");

        if(VehicleSGas[playerid][VSGas] == 0)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não pegou seu veículo de ladrão!");

        if(IsVehicleInRangeOfPoint(playerid, VehicleSGas[playerid][VSGas], 10))
            return SendClientMessage(playerid, Erro, "| ERRO | Seu veículo de ladrão ta muito longe!");

        if(!IsPlayerInRangeOfPoint(playerid, 10.0, PLGas[playerid][pGasPosX], PLGas[playerid][pGasPosY], PLGas[playerid][pGasPosZ]))
            return SendClientMessage(playerid, Erro, "| ERRO | Você não está no local informado!");

        if(!IsPlayerInRangeOfPoint(playerid, 2.0, PLGas[playerid][pGasPosX], PLGas[playerid][pGasPosY], PLGas[playerid][pGasPosZ]))
            return SendClientMessage(playerid, Erro, "| ERRO | Você está longe, vá mas perto do bujão de gás!");

        CaughtGas[playerid] = true;
        DestroyObject(ObjectGas[playerid]);
        SetPlayerAttachedObject(playerid, 3, 1370, 6, 0.339000, 0.235000, 0.090999, 69.699974, 118.899940, 36.300010, 0.699999, 0.699999, 0.699999);
        return 1;
    }
    if(!strcmp(cmdtext, "/edit", true))
    {
        EditAttachedObject(playerid, 3);
        SendClientMessage(playerid, 0xFFFFFFFF, "SERVER: You now edit your attached object on index slot 0!");
        return 1;
    }
    if(strcmp(cmd, "/colocargas", true)==0)
    {
        if(PlayerInfo[playerid][Profissao] != LadraoGas)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não tem permissão!");

        if(CaughtGas[playerid] == false)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não tem nenhum Bujão de Gás na mão!");

        AttachObjectToVehicle(1370, 478, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0);

        //format(String, sizeof(String), "| LADRÃO | Agora tem só mais %d informação de roubo de gás!", AmountGas[playerid]);
        //SendClientMessage(playerid, 0xFF8080AA, String);
        //format(String, sizeof(String), "| LADRÃO | Vá até o próximo roubo de gás localizado em %s", LocationsGas[playerid][Locality]);
        //SendClientMessage(playerid, 0xFF8080AA, String);
        return 1;
    }
    if(strcmp(cmd, "/cancelarroubo", true)==0)
    {
        if(PlayerInfo[playerid][Profissao] != LadraoGas)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não tem permissão!");

        return 1;
    }
