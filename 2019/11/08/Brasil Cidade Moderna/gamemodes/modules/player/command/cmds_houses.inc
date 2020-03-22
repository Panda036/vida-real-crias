    new idhouse = houseid[playerid];

    if(strcmp(cmd, "/criarcasa", true)==0)
    {
        new Float:hPos[3], tmp[128], tmp1[128], Cost, Sell;

        tmp = strtok(cmdtext, idx);
        tmp1 = strtok(cmdtext, idx);

        if(!strlen(tmp) || !strlen(tmp1))
            return SendClientMessage(playerid, 0x0080FFAA, "Uso correto: /Criarcasa [Valor de Compra][Valor de Venda]");

        Cost = strval(tmp);
        Sell = strval(tmp1);

        GetPlayerPos(playerid, hPos[0], hPos[1], hPos[2]);

        new query[500];
        mysql_format(IDConexao, query, sizeof(query), "INSERT INTO `Casas` (`Custo`, `Vender`, `X`, `Y`, `Z`) VALUES ('%d', '%d', '%f', '%f', '%f')", Cost, Sell, hPos[0], hPos[1], hPos[2]);
        mysql_tquery(IDConexao, query, "CreateHouse", "ddfff", Cost, Sell, hPos[0], hPos[1], hPos[2]);
        return 1;
    }
	if(strcmp(cmd, "/menucasa", true)==0)
	{
        new txt[500];

        if(dentrocasa[playerid] != 1)
            return SendClientMessage(playerid, 0xFF4000AA, "| ERRO | Você não está em uma casa!");

        if(strcmp(HouseInfo[idhouse][hNome], PlayerInfo[playerid][Nome], true))
            return SendClientMessage(playerid, 0xFF4000AA, "| ERRO | Esta casa não é sua!");

        strcat(txt, "{FF0000}Funções \t\t {1CEB00}Status \n");
        strcat(txt, "{FFFFFF}Alterar mensagem \t\t Para alterar a mensagem da sua casa\n");

        format(String, sizeof(String), "{FFFFFF}Alterar Senha \t\t Para alterar a atual senha da sua casa: {FF0000}%s \n", HouseInfo[idhouse][hSenha]);
        strcat(txt, String);

        if(strcmp(HouseInfo[idhouse][hTrancada], "Sim", true)==0)
        {
            strcat(txt, "{FFFFFF}Abrir Casa\t\t Para abrir a sua casa\n");
        }
        if(strcmp(HouseInfo[idhouse][hTrancada], "N/A", true)==0)
        {
            strcat(txt, "{FFFFFF}Fechar Casa \t\t Para fechar a sua casa\n");
        }

        strcat(txt, "{FFFFFF}Liberar Casa \t\t Para liberar a sua casa para o servidor\n");
        ShowPlayerDialog(playerid, MAIN_HOUSE, DIALOG_STYLE_TABLIST_HEADERS, "{87CEFF}Menu Casa", txt, "Continuar", "Cancelar");
		return 1;
	}
    if(strcmp(cmd, "/entrarcasa", true)==0)
    {
        if(dentrocasa[playerid] == 1)
            return SendClientMessage(playerid, 0xFF4000AA, "| ERRO | Você já está em uma casa!");

        if(!IsPlayerInRangeOfPoint(playerid, 1.5, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz]))
            return SendClientMessage(playerid, 0xFF4000AA, "| ERRO | Você não está em nenhuma porta de casa!");

        GetPlayerPos(playerid, housex, housey, housez);

        if(strcmp(HouseInfo[idhouse][hNome], PlayerInfo[playerid][Nome], true)==0)
        {
            format(String, sizeof(String), "| INFO | Bem vindo(a) a sua casa %s", HouseInfo[idhouse][hNome]);
        } else {
            if(strcmp(HouseInfo[idhouse][hTrancada], "Sim", true)==0)
                return ShowPlayerDialog(playerid, MAIN_HOUSE_PASS, DIALOG_STYLE_INPUT, "{FF0000}Casa trancada", "{FFFFFF}Digite abaixo a senha da casa para entrar", "Entrar", "Cancelar");

            format(String, sizeof(String), "| INFO | Bem vindo(a) a casa que pertence a %s", HouseInfo[idhouse][hNome]);
        }

        playerworld[playerid] = GetPlayerVirtualWorld(playerid);
        SetPlayerVirtualWorld(playerid, HouseInfo[idhouse][hID]);
        SetPlayerInterior(playerid, HouseInfo[idhouse][hInterior]);
        SetPlayerPos(playerid, HouseInfo[idhouse][hInteriorX], HouseInfo[idhouse][hInteriorY], HouseInfo[idhouse][hInteriorZ]);
        playerinterior[playerid] = HouseInfo[idhouse][hInterior];
        dentrocasa[playerid] = 1;
        SendClientMessage(playerid, 0x87CEFFAA, String);
        return 1;
    }
    if(strcmp(cmd, "/saircasa", true)==0)
    {
        if(dentrocasa[playerid] != 1)
            return SendClientMessage(playerid, 0xFF4000AA, "| ERRO | Você não está em uma casa!");

        if(GetPlayerInterior(playerid) != playerinterior[playerid])
            return 0;

        if(!IsPlayerInRangeOfPoint(playerid, 2.0, HouseInfo[idhouse][hInteriorX], HouseInfo[idhouse][hInteriorY], HouseInfo[idhouse][hInteriorZ]))
            return SendClientMessage(playerid, 0xFF4000AA, "| ERRO | Você está longe da porta!");

        if(strcmp(HouseInfo[idhouse][hNome], PlayerInfo[playerid][Nome], true)==0)
        {
            format(String, sizeof(String), "| INFO | Você saiu da sua casa %s", HouseInfo[idhouse][hNome]);
        } else {
            format(String, sizeof(String), "| INFO | Você saiu da casa que pertence a %s", HouseInfo[idhouse][hNome]);
        }

        SetPlayerPos(playerid, housex, housey, housez);
        SetPlayerInterior(playerid, playerworld[playerid]);
        SetPlayerVirtualWorld(playerid, 0);
        dentrocasa[playerid] = 0;
        SendClientMessage(playerid, 0x87CEFFAA, String);
        return 1;
    }
    if(strcmp(cmd, "/comprarcasa", true)==0)
    {
        if(!IsPlayerInRangeOfPoint(playerid, 1.5, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz]))
            return SendClientMessage(playerid, 0xFF4000AA, "| ERRO | Você não está em nenhuma porta de casa!");

        new ano,mes,dia, _str[500];

        mysql_format(IDConexao, _str, sizeof(_str), "SELECT `Nome` FROM `Casas` WHERE `Nome`='%e'", PlayerInfo[playerid][Nome]);
        mysql_query(IDConexao, _str);

        if(cache_num_rows() > 0)
        return SendClientMessage(playerid, 0xFF4000AA, "| ERRO | Você já tem casa!");

    	if(strcmp(HouseInfo[idhouse][hNome], "N/A", true))
            return SendClientMessage(playerid, 0xFF4000AA, "| ERRO | Esta casa não está a venda!");

        if(PlayerInfo[playerid][Dinheiro] < HouseInfo[idhouse][hCusto])
            return SendClientMessage(playerid, 0xFF4000AA,"| ERRO | Você não tem esse dinheiro em mãos!");

        getdate(ano, mes, dia);
        format(String, sizeof(String), "%d/%d/%d", dia, mes, ano);

        HouseInfo[idhouse][hID] = idhouse;
        format(HouseInfo[idhouse][hNome], 24, PlayerInfo[playerid][Nome]);
        format(HouseInfo[idhouse][hLogin], 24, String);
        format(HouseInfo[idhouse][hTemDono], 5, "Sim");
        PlayerInfo[playerid][Dinheiro] -= HouseInfo[idhouse][hCusto];
        GivePlayerMoney(playerid, -HouseInfo[idhouse][hCusto]);

        GetPlayerPos(playerid, housex, housey, housez);
    	GetPlayer2DZone(zone, MAX_ZONE_NAME, housex, housey);
        format(String, sizeof(String), "| CASAS | O(A) Jogador(a) %s comprou a casa ID %d localizada em %s", PlayerInfo[playerid][Nome], HouseInfo[idhouse][hID], zone);
    	SendClientMessageToAll(-1, String);

        Delete3DTextLabel(HouseLabel[idhouse]);
        DestroyPickup(HousePickup[idhouse]);
        CreateHouseExternal(idhouse);

        mysql_format(IDConexao, _str, sizeof(_str), "UPDATE Casas SET `Nome`='%e', `Login`='%e', `TemDono`='%e' WHERE `ID`='%d'",
        HouseInfo[idhouse][hNome],
        HouseInfo[idhouse][hLogin],
        HouseInfo[idhouse][hTemDono],
        HouseInfo[idhouse][hID]);
        mysql_query(IDConexao, _str);
        return 1;
    }
