    new idhouse = houseid[playerid];

    if(strcmp(cmd, "/continuar", true)==0)
    {
        if(HouseContinue[playerid] == false)
            return SendClientMessage(playerid, Erro, "| ERRO | Seu tempo para usar o comando /continuar acabou!");

        HouseContinue[playerid] = false;
        SetPlayerInterior(playerid, PlayerInfo[playerid][Interior]);
        SetPlayerPos(playerid, PlayerInfo[playerid][PosX], PlayerInfo[playerid][PosY], PlayerInfo[playerid][PosZ]);
        SendClientMessage(playerid, -1, "| INFO | Você foi até sua última posição!");
        KillTimer(HouseContinueTimer[playerid]);
        return 1;
    }
    if(strcmp(cmd, "/ircasa", true)==0)
    {
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128], id;

        tmp = strtok(cmdtext, idx);

        if(!strlen(tmp))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /IrCasa [id-casa]");

        id = strval(tmp);

        if(id < 1 || id >= MAX_HOUSES)
            return SendClientMessage(playerid, Erro, "| ERRO | Esse ID de Casa não existe!");

        SetPlayerInterior(playerid, 0);
        SetPlayerPos(playerid, HouseInfo[id][iconx], HouseInfo[id][icony], HouseInfo[id][iconz]);
        format(String, sizeof(String), "| BCM-Admin | Você se teletransportou para a Casa ID %d", id);
        SendClientMessage(playerid, adm, String);
        return 1;
    }
    if(strcmp(cmd, "/criarcasa", true)==0)
    {
        if(!IsPlayerDeveloper(playerid))
			return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new Float:hPos[3], tmp[128], Cost, Standard, upgrademax;

        tmp = strtok(cmdtext, idx);

        if(!strlen(tmp))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /CriarCasa [Maxímo-Upgrade]");

        upgrademax = strval(tmp);

        GetPlayerPos(playerid, hPos[0], hPos[1], hPos[2]);

        if(!(upgrademax == 3 || upgrademax == 6 || upgrademax == 9 || upgrademax == 12 || upgrademax == 15 || upgrademax == 18))
            return SendClientMessage(playerid, Erro, "| ERRO | Upgrades permitidos: 3, 6, 9, 12, 15 e 18!");

        if(upgrademax == 3)
        {
            Cost = 70000;
            Standard = 63000;
        }
        else if(upgrademax == 6)
        {
            Cost = 150000;
            Standard = 135000;
        }
        else if(upgrademax == 9)
        {
            Cost = 240000;
            Standard = 216000;
        }
        else if(upgrademax == 12)
        {
            Cost = 350000;
            Standard = 315000;
        }
        else if(upgrademax == 15)
        {
            Cost = 400000;
            Standard = 360000;
        }
        else if(upgrademax == 18)
        {
            Cost = 500000;
            Standard = 450000;
        }

        new query[500];
        mysql_format(IDConexao, query, sizeof(query), "INSERT INTO `Casas` (`UpMax`,`Custo`, `Padrao`, `X`, `Y`, `Z`) VALUES ('%d', '%d', '%d', '%f', '%f', '%f')", upgrademax, Cost, Standard, hPos[0], hPos[1], hPos[2]);
        mysql_tquery(IDConexao, query, "CreateHouse", "ddddfff", playerid, upgrademax, Cost, Standard, hPos[0], hPos[1], hPos[2]);
        return 1;
    }
    if(strcmp(cmd, "/editarcasa", true)==0)
    {
        if(!IsPlayerDeveloper(playerid))
			return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128], tmp1[128], id, upgrademax;

        tmp = strtok(cmdtext, idx);
        tmp1 = strtok(cmdtext, idx);

        if(!strlen(tmp) || !strlen(tmp1))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /EditarCasa [id-casa] [máxímo-upgrade]");

        id = strval(tmp);
        upgrademax = strval(tmp1);

        if(id < 1 || id >= MAX_HOUSES)
            return SendClientMessage(playerid, Erro, "| ERRO | Esse id de casa não existe!");

        if(!(upgrademax == 3 || upgrademax == 6 || upgrademax == 9 || upgrademax == 12 || upgrademax == 15 || upgrademax == 18))
            return SendClientMessage(playerid, Erro, "| ERRO | Upgrades permitidos: 3, 6, 9, 12, 15 e 18!");

        if(!IsPlayerInRangeOfPoint(playerid, 15.0, HouseInfo[id][iconx], HouseInfo[id][icony], HouseInfo[id][iconz]))
            return SendClientMessage(playerid, Erro, "| ERRO | Você não está perto da porta dessa casa!");

        switch(upgrademax)
        {
            case 3:
            {
                HouseInfo[id][hCusto] = 70000;
                HouseInfo[id][hPadrao] = 63000;
            }
            case 6:
            {
                HouseInfo[id][hCusto] = 150000;
                HouseInfo[id][hPadrao] = 135000;
            }
            case 9:
            {
                HouseInfo[id][hCusto] = 240000;
                HouseInfo[id][hPadrao] = 216000;
            }
            case 12:
            {
                HouseInfo[id][hCusto] = 350000;
                HouseInfo[id][hPadrao] = 315000;
            }
            case 15:
            {
                HouseInfo[id][hCusto] = 400000;
                HouseInfo[id][hPadrao] = 360000;
            }
            case 18:
            {
                HouseInfo[id][hCusto] = 500000;
                HouseInfo[id][hPadrao] = 450000;
            }
        }

        HouseInfo[id][hUpMax] = upgrademax;
        GetPlayerPos(playerid, HouseInfo[id][iconx], HouseInfo[id][icony], HouseInfo[id][iconz]);

        format(String, sizeof(String), "| BCM-Admin | O(A) %s %s editou a Casa ID %d", CargoAdmin(playerid), PlayerInfo[playerid][Nome], id);
        SendClientMessageToAll(adm, String);
        DestroyDynamicMapIcon(HouseMapIcon[id]);
        Delete3DTextLabel(HouseLabel[id]);
        DestroyPickup(HousePickup[id]);
        CreateHouseExternal(id);
        UpdateHouses(id);
        return 1;
    }
    if(strcmp(cmd, "/liberarcasa", true)==0)
    {
        if(!IsPlayerDeveloper(playerid))
			return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128], idhousee;

        tmp = strtok(cmdtext, idx);

        if(!strlen(tmp))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /LiberarCasa [id-casa]");

        idhousee = strval(tmp);

        if(idhousee < 1 || idhousee >= MAX_HOUSES)
            return SendClientMessage(playerid, Erro, "| ERRO | Esse id de casa não existe!");

        if(strcmp(HouseInfo[idhousee][hNome], "N/A", true)==0)
            return SendClientMessage(playerid, Erro, "| ERRO | Essa casa já está libera e não tem dono(a)!");

        if(dentrocasa[playerid] == 1)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não pode liberar nenhuma casa estando dentro de uma!");

        GetPlayer2DZone(zone, MAX_ZONE_NAME, HouseInfo[idhousee][iconx], HouseInfo[idhousee][icony]);
        format(String, sizeof(String), "| BCM-Admin | O(A) %s %s liberou a Casa ID %d que pertencia a %s localizada em %s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], idhousee, HouseInfo[idhousee][hNome], zone);
        SendClientMessageToAll(adm, String);

        switch(HouseInfo[idhousee][hUpMax])
        {
            case 3:
            {
                HouseInfo[idhousee][hCusto] = 70000;
                HouseInfo[idhousee][hPadrao] = 63000;
            }
            case 6:
            {
                HouseInfo[idhousee][hCusto] = 150000;
                HouseInfo[idhousee][hPadrao] = 135000;
            }
            case 9:
            {
                HouseInfo[idhousee][hCusto] = 240000;
                HouseInfo[idhousee][hPadrao] = 216000;
            }
            case 12:
            {
                HouseInfo[idhousee][hCusto] = 350000;
                HouseInfo[idhousee][hPadrao] = 315000;
            }
            case 15:
            {
                HouseInfo[idhousee][hCusto] = 400000;
                HouseInfo[idhousee][hPadrao] = 360000;
            }
            case 18:
            {
                HouseInfo[idhousee][hCusto] = 500000;
                HouseInfo[idhousee][hPadrao] = 450000;
            }
        }

        HouseInfo[idhousee][hID] = idhousee;
        format(HouseInfo[idhousee][hNome], MAX_PLAYER_NAME, "N/A");
        format(HouseInfo[idhousee][hM1], MAX_PLAYER_NAME, "N/A");
        format(HouseInfo[idhousee][hM2], MAX_PLAYER_NAME, "N/A");
        format(HouseInfo[idhousee][hM3], MAX_PLAYER_NAME, "N/A");
        format(HouseInfo[idhousee][hM4], MAX_PLAYER_NAME, "N/A");
        format(HouseInfo[idhousee][hM5], MAX_PLAYER_NAME, "N/A");
        format(HouseInfo[idhousee][hM6], MAX_PLAYER_NAME, "N/A");
        format(HouseInfo[idhousee][hMensagem], 30, "N/A");
        format(HouseInfo[idhousee][hAlugando], 5, "N/A");
        format(HouseInfo[idhousee][hVendendo], 5, "Sim");
        HouseInfo[idhousee][hPreco] = 0;
        HouseInfo[idhousee][hUp] = 1;
        format(HouseInfo[idhousee][hTrancada], 5, "N/A");
        format(HouseInfo[idhousee][hSenha], 5, "N/A");

        DestroyDynamicMapIcon(HouseMapIcon[idhousee]);
        Delete3DTextLabel(HouseLabel[idhousee]);
        DestroyPickup(HousePickup[idhousee]);
        CreateHouseExternal(idhousee);
        UpdateHouses(idhousee);
        return 1;
    }
	if(strcmp(cmd, "/menucasa", true)==0)
	{
        new txt[500];

        if(dentrocasa[playerid] != 1)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não está em uma casa!");

        if(strcmp(HouseInfo[idhouse][hNome], PlayerInfo[playerid][Nome], true))
            return SendClientMessage(playerid, Erro, "| ERRO | Você não é dono(a)/morador(a) dessa casa!");

        strcat(txt, "{FF0000}Funções \t\t {1CEB00}Status \n");

        format(String, sizeof(String), "{FFFFFF}Mensagem \t\t %s\n", HouseInfo[idhouse][hMensagem]);
        strcat(txt, String);
        format(String, sizeof(String), "{FFFFFF}Senha \t\t {FF4500}%s\n", HouseInfo[idhouse][hSenha]);
        strcat(txt, String);

        if(strcmp(HouseInfo[idhouse][hTrancada], "Sim", true)==0)
            { strcat(txt, "{FFFFFF}Trancada \t\t Sim\n");  }

        if(strcmp(HouseInfo[idhouse][hTrancada], "N/A", true)==0)
            { strcat(txt, "{FFFFFF}Trancada \t\t Não\n"); }

        format(String, sizeof(String), "{FFFFFF}Upgrade \t\t {87CEFF}%d/%d \n", HouseInfo[idhouse][hUp], HouseInfo[idhouse][hUpMax]);
        strcat(txt, String);
        strcat(txt, "{FFFFFF}Moradores \t\t \n");
        format(String, sizeof(String), "{FFFFFF}Vender Casa \t\t {2CC06B}$%s\n", IsMoney(HouseInfo[idhouse][hPreco], "."));
        strcat(txt, String);
        format(String, sizeof(String), "{FFFFFF}Liberar Casa \t\t {2CC06B}$%s\n", IsMoney(HouseInfo[idhouse][hPadrao], "."));
        strcat(txt, String);
        ShowPlayerDialog(playerid, MAIN_HOUSE, DIALOG_STYLE_TABLIST_HEADERS, "{FFD700}Menu Casa", txt, "Continuar", "Cancelar");
        return 1;
	}
    if(strcmp(cmd, "/entrarcasa", true)==0)
    {
        if(dentrocasa[playerid] == 1)
            return SendClientMessage(playerid, Erro, "| ERRO | Você já está em uma casa!");

        if(!IsPlayerInRangeOfPoint(playerid, 1.5, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz]))
            return SendClientMessage(playerid, Erro, "| ERRO | Você não está em nenhuma porta de casa!");

        if(strcmp(HouseInfo[idhouse][hNome], PlayerInfo[playerid][Nome], true)==0)
        {
            format(String, sizeof(String), "| CASA | Bem vindo(a) a Casa ID %d em que você mora, Digite: /MenuCasa para acessar o menu!", HouseInfo[idhouse][hID]);
        } else {
            if(strcmp(HouseInfo[idhouse][hTrancada], "Sim", true)==0)
                return ShowPlayerDialog(playerid, MAIN_HOUSE_PASS, DIALOG_STYLE_INPUT, "{FF0000}Casa trancada", "{FFFFFF}Digite abaixo a senha da casa para entrar", "Entrar", "Cancelar");

            format(String, sizeof(String), "| CASA | Bem vindo(a) a Casa ID %d que pertence a %s", HouseInfo[idhouse][hID], HouseInfo[idhouse][hNome]);
        }

        playerworld[playerid] = GetPlayerVirtualWorld(playerid);
        SetPlayerVirtualWorld(playerid, HouseInfo[idhouse][hID]);
        SetPlayerInterior(playerid, HouseInfo[idhouse][hInterior]);
        SetPlayerPos(playerid, HouseInfo[idhouse][hInteriorX], HouseInfo[idhouse][hInteriorY], HouseInfo[idhouse][hInteriorZ]);
        playerinterior[playerid] = HouseInfo[idhouse][hInterior];
        dentrocasa[playerid] = 1;
        SendClientMessage(playerid, C_PROPERTY, String);
        return 1;
    }
    if(strcmp(cmd, "/saircasa", true)==0)
    {
        if(dentrocasa[playerid] != 1)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não está em uma casa!");

        if(GetPlayerInterior(playerid) != playerinterior[playerid])
            return 0;

        if(!IsPlayerInRangeOfPoint(playerid, 2.0, HouseInfo[idhouse][hInteriorX], HouseInfo[idhouse][hInteriorY], HouseInfo[idhouse][hInteriorZ]))
            return SendClientMessage(playerid, Erro, "| ERRO | Você está longe da porta!");

        if(strcmp(HouseInfo[idhouse][hNome], PlayerInfo[playerid][Nome], true)==0)
        {
            format(String, sizeof(String), "| CASA | Você saiu da sua casa %s", HouseInfo[idhouse][hNome]);
        } else {
            format(String, sizeof(String), "| CASA | Você saiu da casa que pertence a %s", HouseInfo[idhouse][hNome]);
        }

        SetPlayerPos(playerid, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz]);
        SetPlayerInterior(playerid, playerworld[playerid]);
        SetPlayerVirtualWorld(playerid, 0);
        dentrocasa[playerid] = 0;
        SendClientMessage(playerid, C_PROPERTY, String);
        return 1;
    }
    if(strcmp(cmd, "/comprarcasa", true)==0)
    {
        if(!IsPlayerInRangeOfPoint(playerid, 1.5, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz]))
            return SendClientMessage(playerid, Erro, "| ERRO | Você não está em nenhuma porta de casa!");

        new _str[500], id;

        mysql_format(IDConexao, _str, sizeof(_str), "SELECT `Nome` FROM `Casas` WHERE `Nome`='%e'", PlayerInfo[playerid][Nome]);
        mysql_query(IDConexao, _str);

        if(cache_num_rows() > 0)
            return SendClientMessage(playerid, Erro, "| ERRO | Você já tem uma casa!");

        if(strcmp(HouseInfo[idhouse][hVendendo], "N/A", true)==0) //Vendendo
            return SendClientMessage(playerid, Erro, "| ERRO | Essa casa não está a venda!");

        GetPlayer2DZone(zone, MAX_ZONE_NAME, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony]);

        if(strcmp(HouseInfo[idhouse][hNome], "N/A", true)==0) //Liberada
        {
            if(PlayerInfo[playerid][Dinheiro] < HouseInfo[idhouse][hCusto])
                return SendClientMessage(playerid, Erro, "| ERRO | Você não tem esse dinheiro em mãos!");

            format(String, sizeof(String), "| CASAS | O(A) Jogador(a) %s comprou a casa ID %d localizada em %s", PlayerInfo[playerid][Nome], HouseInfo[idhouse][hID], zone);
            HouseInfo[idhouse][hInterior] = 5;

            PlayerInfo[playerid][Dinheiro] -= HouseInfo[idhouse][hCusto];
        }
        else if(strcmp(HouseInfo[idhouse][hNome], "N/A", true)) //Tem Dono
        {
            id = GetPlayerID(HouseInfo[idhouse][hNome]);

            if(PlayerInfo[id][Logado] == false)
                return SendClientMessage(playerid, Erro, "| ERRO | O(A) Proprietário(a) dessa casa não está conectado(a)");

            if(PlayerInfo[playerid][Dinheiro] < HouseInfo[idhouse][hPreco])
                return SendClientMessage(playerid, Erro, "| ERRO | Você não tem esse dinheiro em mãos!");

            format(String, sizeof(String), "| CASAS | O(A) Jogador(a) %s comprou a sua casa e o seu dinheiro foi transferido direto pra sua conta bancária!", PlayerInfo[playerid][Nome], HouseInfo[idhouse][hID], HouseInfo[idhouse][hNome], zone);
            SendClientMessage(id, -1, String);
            format(String, sizeof(String), "| CASAS | O(A) Jogador(a) %s comprou a casa ID %d que pertencia ao jogador(a) %s localizada em %s", PlayerInfo[playerid][Nome], HouseInfo[idhouse][hID], HouseInfo[idhouse][hNome], zone);

            PlayerInfo[id][SaldoBancario] += HouseInfo[idhouse][hPreco];
            PlayerInfo[playerid][Dinheiro] -= HouseInfo[idhouse][hPreco];
        }

        HouseInfo[idhouse][hID] = idhouse;
        format(HouseInfo[idhouse][hNome], MAX_PLAYER_NAME, PlayerInfo[playerid][Nome]);
        format(HouseInfo[idhouse][hM1], MAX_PLAYER_NAME, "N/A");
        format(HouseInfo[idhouse][hM2], MAX_PLAYER_NAME, "N/A");
        format(HouseInfo[idhouse][hM3], MAX_PLAYER_NAME, "N/A");
        format(HouseInfo[idhouse][hM4], MAX_PLAYER_NAME, "N/A");
        format(HouseInfo[idhouse][hM5], MAX_PLAYER_NAME, "N/A");
        format(HouseInfo[idhouse][hM6], MAX_PLAYER_NAME, "N/A");
        format(HouseInfo[idhouse][hMensagem], 15, "N/A");
        format(HouseInfo[idhouse][hAlugando], 15, "N/A");
        format(HouseInfo[idhouse][hVendendo], 5, "N/A");
        HouseInfo[idhouse][hUp] = 1;
        HouseInfo[idhouse][hPreco] = 0;
        format(HouseInfo[idhouse][hTrancada], 5, "N/A");
        format(HouseInfo[idhouse][hSenha], 24, "N/A");

        UpdatePlayerMoney(playerid);
        SendClientMessageToAll(-1, String);
        DestroyDynamicMapIcon(HouseMapIcon[idhouse]);
        Delete3DTextLabel(HouseLabel[idhouse]);
        DestroyPickup(HousePickup[idhouse]);
        CreateHouseExternal(idhouse);
        UpdateHouses(idhouse);
        return 1;
    }
