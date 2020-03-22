    new companyid = idcompany[playerid];

    if(!strcmp(cmd, "/pegarmercadoria", true))
    {
        if(!CPS_IsPlayerInCheckpoint(playerid, CPS_Bayside))
            return SendClientMessage(playerid, Erro, "| ERRO | Você não está em bayside!");

        new _str[500];
        mysql_format(IDConexao, _str, sizeof(_str), "SELECT `Nome` OR `Func1` OR `Func2` OR `Func3` OR `Func4` FROM `Empresas` WHERE `Nome`='%e' OR `Func1`='%e' OR `Func2`='%e' OR `Func3`='%e' OR `Func4`='%e'", PlayerInfo[playerid][Nome], PlayerInfo[playerid][Nome], PlayerInfo[playerid][Nome], PlayerInfo[playerid][Nome], PlayerInfo[playerid][Nome]);
        mysql_query(IDConexao, _str);

        if(cache_num_rows() == 0)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não é dono(a)/funcionário(a) de uma empresa!");

        if(EntregouMercadoria[playerid] == true)
            return SendClientMessage(playerid, Erro, "| ERRO | Você já entregou mercadoria nesse level!");

        if(Mercadoria[playerid] == true)
            return SendClientMessage(playerid, Erro, "| ERRO | Você já tem uma mercadoria!");

        Mercadoria[playerid] = true;
        SendClientMessage(playerid, C_PROPERTY, "| MERCADORIA | Você pegou uma mercadoria, vá até a sua empresa para entregar!");
        return 1;
    }
    if(!strcmp(cmd, "/menuempresa", true))
    {
        new txt[2000];

        if(withincompany[playerid] != 1)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não está em uma empresa!");

        if(strcmp(CompanyInfo[companyid][cName], PlayerInfo[playerid][Nome], true))
            return SendClientMessage(playerid, Erro, "| ERRO | Você não é dono(a) dessa empresa!");

        strcat(txt, "{FF0000}Funções \t\t {1CEB00}Status \n");

        format(String, sizeof(String), "{FFFFFF}Mensagem \t\t %s\n", CompanyInfo[companyid][cMessage]);
        strcat(txt, String);

        if(!strcmp(PlayerInfo[playerid][Nome], CompanyInfo[companyid][cName], true))
        {
            format(String, sizeof(String), "{FFFFFF}Funcionário 1 \t\t {FF0000}%s \n", CompanyInfo[companyid][cEmployee1]);
            strcat(txt, String);
            format(String, sizeof(String), "{FFFFFF}Funcionário 2 \t\t {FF0000}%s \n", CompanyInfo[companyid][cEmployee2]);
            strcat(txt, String);
            format(String, sizeof(String), "{FFFFFF}Funcionário 3 \t\t {FF0000}%s \n", CompanyInfo[companyid][cEmployee3]);
            strcat(txt, String);
            format(String, sizeof(String), "{FFFFFF}Funcionário 4 \t\t {FF0000}%s \n", CompanyInfo[companyid][cEmployee4]);
            strcat(txt, String);
            format(String, sizeof(String), "{FFFFFF}Entregar/Mercadoria(s) \t\t {2CC06B}%d \n", CompanyInfo[companyid][cDeliveries]);
            strcat(txt, String);
        }
        else if(!strcmp(PlayerInfo[playerid][Nome], CompanyInfo[companyid][cEmployee1], true))
        {
            format(String, sizeof(String), "{FFFFFF}Entregar/Mercadoria(s) \t\t {2CC06B}%d \n", CompanyInfo[companyid][cEDeliveries1]);
            strcat(txt, String);
        }
        else if(!strcmp(PlayerInfo[playerid][Nome], CompanyInfo[companyid][cEmployee2], true))
        {
            format(String, sizeof(String), "{FFFFFF}Entregar/Mercadoria(s) \t\t {2CC06B}%d \n", CompanyInfo[companyid][cEDeliveries2]);
            strcat(txt, String);
        }
        else if(!strcmp(PlayerInfo[playerid][Nome], CompanyInfo[companyid][cEmployee3], true))
        {
            format(String, sizeof(String), "{FFFFFF}Entregar/Mercadoria(s) \t\t {2CC06B}%d \n", CompanyInfo[companyid][cEDeliveries3]);
            strcat(txt, String);
        }
        else if(!strcmp(PlayerInfo[playerid][Nome], CompanyInfo[companyid][cEmployee4], true))
        {
            format(String, sizeof(String), "{FFFFFF}Entregar/Mercadoria(s) \t\t {2CC06B}%d \n", CompanyInfo[companyid][cEDeliveries4]);
            strcat(txt, String);
        }

        format(String, sizeof(String), "{FFFFFF}Cofre \t\t {2CC06B}$%s\n", IsMoney(CompanyInfo[companyid][cSafe], "."));
        strcat(txt, String);
        format(String, sizeof(String), "{FFFFFF}Vender Empresa \t\t {2CC06B}$%s\n", IsMoney(CompanyInfo[companyid][cPrice], "."));
        strcat(txt, String);
        format(String, sizeof(String), "{FFFFFF}Liberar Empresa \t\t {2CC06B}$%s\n", IsMoney(CompanyInfo[companyid][cStandard], "."));
        strcat(txt, String);
        ShowPlayerDialog(playerid, MAIN_COMPANY, DIALOG_STYLE_TABLIST_HEADERS, "{FFD700}Menu Empresa", txt, "Continuar", "Cancelar");
        return 1;
    }
    if(!strcmp(cmd, "/salvarempresas", true))
    {
        for(new id=1; id < MAX_COMPANYS; id++)
        {
            GetPlayer2DZone(zone, MAX_ZONE_NAME, CompanyInfo[id][cIconX], CompanyInfo[id][cIconY]);
            format(String, 128, "| BCM-Admin | O(A) %s %s[%d] salvou a empresa ID:%d localizada em %s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid, id, zone);
            SendClientMessageToAll(adm, String);

            UpdateCompanys(id);
            UpdateCompanyExternal(id);
        }
        return 1;
    }
    if(!strcmp(cmd, "/editarempresa", true))
    {
        new tmp[128], tmp1[128], tmp2[128], tmp3[128], tmp4[128], id, icon, cost, standard;

        tmp = strtok(cmdtext, idx);
        tmp1 = strtok(cmdtext, idx);
        tmp2 = strtok(cmdtext, idx);
        tmp3 = strtok(cmdtext, idx);
        tmp4 = strrest(cmdtext, idx);

        if(!strlen(tmp) || !strlen(tmp1) || !strlen(tmp2) || !strlen(tmp3) || !strlen(tmp4))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /EditarEmpresa [id-empresa] [id-icone] [custo] [padrão] [status]");

        id = strval(tmp);
        icon = strval(tmp1);
        cost = strval(tmp2);
        standard = strval(tmp3);

        CompanyInfo[id][cIcon] = icon;
        CompanyInfo[id][cCost] = cost;
        CompanyInfo[id][cStandard] = standard;
        format(CompanyInfo[id][cStatus], 30, tmp4);

        GetPlayer2DZone(zone, MAX_ZONE_NAME, CompanyInfo[id][cIconX], CompanyInfo[id][cIconY]);
        format(String, 128, "| BCM-Admin | O(A) %s %s[%d] editou a empresa ID %d localizada em %s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid, id, zone);
        SendClientMessageToAll(adm, String);

        UpdateCompanys(id);
        UpdateCompanyExternal(id);
        return 1;
    }
    if(!strcmp(cmd, "/irempresa", true))
    {
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128], id;

        tmp = strtok(cmdtext, idx);

        if(!strlen(tmp))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /IrEmpresa [id-empresa]");

        id = strval(tmp);

        if(id < 1 || id >= MAX_COMPANYS)
            return SendClientMessage(playerid, Erro, "| ERRO | Esse ID de Empresa não existe!");

        SetPlayerInterior(playerid, 0);
        SetPlayerPos(playerid, CompanyInfo[id][cIconX], CompanyInfo[id][cIconY], CompanyInfo[id][cIconZ]);
        format(String, sizeof(String), "| BCM-Admin | Você se teletransportou para a Empresa ID %d", id);
        SendClientMessage(playerid, adm, String);
        return 1;
    }
    if(!strcmp(cmd, "/criarempresa", true))
    {
        if(!IsPlayerDeveloper(playerid))
			return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        ShowPlayerDialog(playerid, CREATE_COMPANY, DIALOG_STYLE_LIST, "{FF0000}Criar Empresa", "{FFFFFF}Cabaré\nSexshop\nBurgue Shot\nBar\nUtilitários\nRestaurante\nCassino Caligulas\nHotel\nAmmunation\nLoja de Skins\nBarbearia\nTatto\nAcademia\nCluckin' Bell\nWell Stacked Pizza Co", "Criar", "Cancelar");
        return 1;
    }
    if(!strcmp(cmd, "/entrarempresa", true))
    {
        if(withincompany[playerid] == 1)
            return SendClientMessage(playerid, Erro, "| ERRO | Você já está em uma empresa!");

        if(!IsPlayerInRangeOfPoint(playerid, 1.5, CompanyInfo[companyid][cIconX], CompanyInfo[companyid][cIconY], CompanyInfo[companyid][cIconZ]))
            return SendClientMessage(playerid, Erro, "| ERRO | Você não está em nenhuma porta de empresa!");

        if(strcmp(CompanyInfo[companyid][cName], PlayerInfo[playerid][Nome], true)==0)
        {
            format(String, sizeof(String), "| EMPRESA | Bem vindo(a) a sua Empresa ID %d, Digite: /MenuEmpresa para acessar o menu!", CompanyInfo[companyid][cID]);
        } else {
            format(String, sizeof(String), "| EMPRESA | Bem vindo(a) a Empresa ID %d que pertence a %s", CompanyInfo[companyid][cID], CompanyInfo[companyid][cName]);
        }

        SetPlayerVirtualWorld(playerid, CompanyInfo[companyid][cID]);
        SetPlayerInterior(playerid, CompanyInfo[companyid][cInterior]);
        SetPlayerPos(playerid, CompanyInfo[companyid][cInteriorX], CompanyInfo[companyid][cInteriorY], CompanyInfo[companyid][cInteriorZ]);
        playerinterior[playerid] = CompanyInfo[companyid][cInterior];
        withincompany[playerid] = 1;
        SendClientMessage(playerid, C_PROPERTY, String);
        return 1;
    }
    if(!strcmp(cmd, "/sairempresa", true))
    {
        if(withincompany[playerid] != 1)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não está em uma empresa!");

        if(GetPlayerInterior(playerid) != playerinterior[playerid])
            return 0;

        if(!IsPlayerInRangeOfPoint(playerid, 2.0, CompanyInfo[companyid][cInteriorX], CompanyInfo[companyid][cInteriorY], CompanyInfo[companyid][cInteriorZ]))
            return SendClientMessage(playerid, Erro, "| ERRO | Você está longe da porta!");

        if(strcmp(CompanyInfo[companyid][cName], PlayerInfo[playerid][Nome], true)==0)
        {
            format(String, sizeof(String), "| EMPRESA | Você saiu da sua empresa %s", CompanyInfo[companyid][cName]);
        } else {
            format(String, sizeof(String), "| EMPRESA | Você saiu da empresa que pertence a %s", CompanyInfo[companyid][cName]);
        }

        SetPlayerPos(playerid, CompanyInfo[companyid][cIconX], CompanyInfo[companyid][cIconY], CompanyInfo[companyid][cIconZ]);
        SetPlayerInterior(playerid, 0);
        SetPlayerVirtualWorld(playerid, 0);
        withincompany[playerid] = 0;
        SendClientMessage(playerid, C_PROPERTY, String);
        return 1;
    }
    if(strcmp(cmd, "/comprarempresa", true)==0)
    {
        if(!IsPlayerInRangeOfPoint(playerid, 1.5, CompanyInfo[companyid][cIconX], CompanyInfo[companyid][cIconY], CompanyInfo[companyid][cIconZ]))
            return SendClientMessage(playerid, Erro, "| ERRO | Você não está em nenhuma porta de empresa!");

        new _str[500], id;

        mysql_format(IDConexao, _str, sizeof(_str), "SELECT `Nome` FROM `Empresas` WHERE `Nome`='%e'", PlayerInfo[playerid][Nome]);
        mysql_query(IDConexao, _str);

        if(cache_num_rows() > 0)
            return SendClientMessage(playerid, Erro, "| ERRO | Você já tem uma empresa!");

        if(!strcmp(CompanyInfo[companyid][cSelling], "N/A", true))
            return SendClientMessage(playerid, Erro, "| ERRO | Essa empresa não está a venda!");

        GetPlayer2DZone(zone, MAX_ZONE_NAME, CompanyInfo[companyid][cIconX], CompanyInfo[companyid][cIconY]);

        if(!strcmp(CompanyInfo[companyid][cName], "N/A", true))
        {
            if(PlayerInfo[playerid][Dinheiro] < CompanyInfo[companyid][cCost])
                return SendClientMessage(playerid, Erro, "| ERRO | Você não tem esse dinheiro em mãos!");

            format(String, sizeof(String), "| EMPRESAS | O(A) Jogador(a) %s comprou a empresa ID %d localizada em %s", PlayerInfo[playerid][Nome], CompanyInfo[companyid][cID], zone);

            PlayerInfo[playerid][Dinheiro] -= CompanyInfo[companyid][cCost];
        }
        else if(strcmp(CompanyInfo[companyid][cName], "N/A", true))
        {
            id = GetPlayerID(CompanyInfo[companyid][cName]);

            if(PlayerInfo[id][Logado] == false)
                return SendClientMessage(playerid, Erro, "| ERRO | O(A) Proprietário(a) dessa empresa não está conectado(a)!");

            if(PlayerInfo[playerid][Dinheiro] < CompanyInfo[companyid][cPrice])
                return SendClientMessage(playerid, Erro, "| ERRO | Você não tem esse dinheiro em mãos!");

            format(String, sizeof(String), "| EMPRESAS | O(A) Jogador(a) %s comprou a sua empresa e o seu dinheiro foi transferido direto pra sua conta bancária!", PlayerInfo[playerid][Nome], CompanyInfo[companyid][cID], CompanyInfo[companyid][cName], zone);
            SendClientMessage(id, -1, String);
            format(String, sizeof(String), "| EMPRESAS | O(A) Jogador(a) %s comprou a empresa ID %d que pertencia ao jogador(a) %s localizada em %s", PlayerInfo[playerid][Nome], CompanyInfo[companyid][cID], CompanyInfo[companyid][cName], zone);

            PlayerInfo[id][SaldoBancario] += CompanyInfo[companyid][cPrice];
            PlayerInfo[playerid][Dinheiro] -= CompanyInfo[companyid][cPrice];
        }

        CompanyInfo[companyid][cID] = companyid;
        format(CompanyInfo[companyid][cName], MAX_PLAYER_NAME, PlayerInfo[playerid][Nome]);
        format(CompanyInfo[companyid][cMessage], 30, "N/A");
        format(CompanyInfo[companyid][cSelling], 5, "N/A");
        CompanyInfo[companyid][cPrice] = 0;

        SendClientMessageToAll(-1, String);

        UpdateCompanyExternal(companyid);

        UpdatePlayerMoney(playerid);
        UpdateCompanys(companyid);
        return 1;
    }
