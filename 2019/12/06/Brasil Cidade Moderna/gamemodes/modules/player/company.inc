#include YSI\y_hooks

#define MAX_COMPANYS                (102+1)
#define CREATE_COMPANY              10020
#define MAIN_COMPANY                10021
#define MAIN_COMPANY_ALTER_MSG      10022
#define MAIN_COMPANY_SAFE           10023
#define MAIN_COMPANY_RELEASE        10024
#define MAIN_COMPANY_SELL_LIST      10025
#define MAIN_COMPANY_SELL_INPUT     10026
#define MAIN_COMPANY_EMPLOYEE       10027

enum cInfo
{
    cID,
    cName[MAX_PLAYER_NAME],
    cEmployee1[MAX_PLAYER_NAME],
    cEmployee2[MAX_PLAYER_NAME],
    cEmployee3[MAX_PLAYER_NAME],
    cEmployee4[MAX_PLAYER_NAME],
    cDeliveries,
    cEDeliveries1,
    cEDeliveries2,
    cEDeliveries3,
    cEDeliveries4,
    cStatus[30],
    cMessage[30],
    cSelling[5],
    cPrice,
    cCost,
    cStandard,
    cSafe,
    cInterior,
    cIcon,
    cProduction,
    Float:cIconX,
    Float:cIconY,
    Float:cIconZ,
    Float:cInteriorX,
    Float:cInteriorY,
    Float:cInteriorZ
}

new CompanyInfo[MAX_COMPANYS][cInfo],
    Text3D:CompanyLabel[MAX_COMPANYS],
    CompanyMapIcon[MAX_COMPANYS],
    CompanyPickup[MAX_COMPANYS];

new withincompany[MAX_PLAYERS],
    idcompany[MAX_PLAYERS];

new CPS_Bayside;

new bool:Mercadoria[MAX_PLAYERS],
    bool:EntregouMercadoria[MAX_PLAYERS];

hook OnGameModeInit()
{
    new db_company[1000];
    strins(db_company,"CREATE TABLE IF NOT EXISTS Empresas ", strlen(db_company));
    strins(db_company,"(ID int PRIMARY KEY AUTO_INCREMENT,", strlen(db_company));
    strins(db_company,"Nome varchar(24) NOT NULL DEFAULT 'N/A',", strlen(db_company));
    strins(db_company,"Func1 varchar(24) NOT NULL DEFAULT 'N/A',", strlen(db_company));
    strins(db_company,"Func2 varchar(24) NOT NULL DEFAULT 'N/A',", strlen(db_company));
    strins(db_company,"Func3 varchar(24) NOT NULL DEFAULT 'N/A',", strlen(db_company));
    strins(db_company,"Func4 varchar(24) NOT NULL DEFAULT 'N/A',", strlen(db_company));
    strins(db_company,"Entregas int(11) NOT NULL,", strlen(db_company));
    strins(db_company,"Func1Entregas int(11) NOT NULL,", strlen(db_company));
    strins(db_company,"Func2Entregas int(11) NOT NULL,", strlen(db_company));
    strins(db_company,"Func3Entregas int(11) NOT NULL,", strlen(db_company));
    strins(db_company,"Func4Entregas int(11) NOT NULL,", strlen(db_company));
    strins(db_company,"Status varchar(30) NOT NULL DEFAULT 'N/A',", strlen(db_company));
    strins(db_company,"Mensagem varchar(30) NOT NULL DEFAULT 'N/A',", strlen(db_company));
    strins(db_company,"Vendendo varchar(3) NOT NULL DEFAULT 'Sim',", strlen(db_company));
    strins(db_company,"Preco int(11) NOT NULL,", strlen(db_company));
    strins(db_company,"Custo int(11) NOT NULL,", strlen(db_company));
    strins(db_company,"Padrao int(11) NOT NULL,", strlen(db_company));
    strins(db_company,"Cofre int(11) NOT NULL,", strlen(db_company));
    strins(db_company,"Interior int(5) NOT NULL,", strlen(db_company));
    strins(db_company,"Icon int(5) NOT NULL,", strlen(db_company));
    strins(db_company,"Producao int(11) NOT NULL,", strlen(db_company));
    strins(db_company,"X float NOT NULL,", strlen(db_company));
    strins(db_company,"Y float NOT NULL,", strlen(db_company));
    strins(db_company,"Z float NOT NULL,", strlen(db_company));
    strins(db_company,"InteriorX float NOT NULL,", strlen(db_company));
    strins(db_company,"InteriorY float NOT NULL,", strlen(db_company));
    strins(db_company,"InteriorZ float NOT NULL) CHARACTER SET utf8 COLLATE utf8_general_ci", strlen(db_company));
    mysql_query(IDConexao, db_company, false);
    LoadCompany();

    CPS_Bayside = CPS_AddCheckpoint(-2433.9656, 2313.7012, 4.9844, 1.0, 30);  //CPS Bayside
    return 1;
}

hook OnGameModeExit()
{
    for(new i=1; i < MAX_COMPANYS; i++)
	{
        DestroyDynamicMapIcon(CompanyMapIcon[i]);
        Delete3DTextLabel(CompanyLabel[i]);
        DestroyPickup(CompanyPickup[i]);
	}
	return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    withincompany[playerid] = 0;
    idcompany[playerid] = 0;
    Mercadoria[playerid] = false;
    EntregouMercadoria[playerid] = false;
	return 1;
}

hook OnPlayerEnterCheckpoint(playerid)
{
    if(CPS_GetPlayerCheckpoint(playerid) == CPS_Bayside)
    {
        SendClientMessage(playerid, C_PROPERTY, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        SendClientMessage(playerid, 0xFFFFFFAA, "| MERCADORIAS | Para poder pegar mercadoria... ");
        SendClientMessage(playerid, 0xFFFFFFAA, "| MERCADORIAS | Digite: /PegarMercadoria");
        SendClientMessage(playerid, C_PROPERTY, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    }
	return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    new companyid = idcompany[playerid];

    switch(dialogid)
    {
        case CREATE_COMPANY: //10% Loss of Cost / Standard
        {
            if(response)
            {
                new Float:cPos[3], Cost, Standard, CompanyIcon;
                GetPlayerPos(playerid, cPos[0], cPos[1], cPos[2]);

                if(listitem == 0) //Cabarés 950k
                {
                    Cost = 950000;
                    Standard = 855000;
                    CompanyIcon = 21;
                }
                else if(listitem == 1) //Sexshop 750k
                {
                    Cost = 750000;
                    Standard = 675000;
                    CompanyIcon = 21;
                }
                else if(listitem == 2) //Burgue shot 850k
                {
                    Cost = 850000;
                    Standard = 765000;
                    CompanyIcon = 10;
                }
                else if(listitem == 3) //Bar 950k
                {
                    Cost = 950000;
                    Standard = 855000;
                    CompanyIcon = 49;
                }
                else if(listitem == 4) //Utilitarios 850k
                {
                    Cost = 850000;
                    Standard = 765000;
                    CompanyIcon = 17;
                }
                else if(listitem == 5) //Restaurante 950k
                {
                    Cost = 950000;
                    Standard = 855000;
                    CompanyIcon = 50;
                }
                else if(listitem == 6) //Cassino Caligulas 2kk500
                {
                    Cost = 2500000;
                    Standard = 2250000;
                    CompanyIcon = 25;
                }
                else if(listitem == 7) //Hotel 2kk
                {
                    Cost = 2000000;
                    Standard = 1800000;
                    CompanyIcon = 35;
                }
                else if(listitem == 8) //Ammunation 950k
                {
                    Cost = 950000;
                    Standard = 855000;
                    CompanyIcon = 6;
                }
                else if(listitem == 9) //Loja de Skins 850k
                {
                    Cost = 850000;
                    Standard = 765000;
                    CompanyIcon = 45;
                }
                else if(listitem == 10) //Barbearia 750k
                {
                    Cost = 750000;
                    Standard = 675000;
                    CompanyIcon = 7;
                }
                else if(listitem == 11) //Tatto 750k
                {
                    Cost = 750000;
                    Standard = 675000;
                    CompanyIcon = 39;
                }
                else if(listitem == 12) //Academia 850k
                {
                    Cost = 850000;
                    Standard = 765000;
                    CompanyIcon = 54;
                }
                else if(listitem == 13) //Cluckin' Bell 950k
                {
                    Cost = 950000;
                    Standard = 855000;
                    CompanyIcon = 14;
                }
                else if(listitem == 14) //Well Stacked Pizza Co 950k
                {
                    Cost = 950000;
                    Standard = 855000;
                    CompanyIcon = 29;
                }

                new query[500];
                mysql_format(IDConexao, query, sizeof(query), "INSERT INTO `Empresas` (`Icon`, `Custo`, `Padrao`, `X`, `Y`, `Z`) VALUES ('%d', '%d', '%d', '%f', '%f', '%f')", CompanyIcon, Cost, Standard, cPos[0], cPos[1], cPos[2]-0.5);
                mysql_tquery(IDConexao, query, "CreateComapany", "ddddfff", playerid, CompanyIcon, Cost, Standard, cPos[0], cPos[1], cPos[2]-0.5);
            }
        }
        case MAIN_COMPANY:
        {
            if(response)
            {
                if(!strcmp(PlayerInfo[playerid][Nome], CompanyInfo[companyid][cName], true))
                {
                    if(listitem == 0)
                    {
                        ShowPlayerDialog(playerid, MAIN_COMPANY_ALTER_MSG, DIALOG_STYLE_INPUT, "{FFD700}Alterar Mensagem", "{FFFFFF}Digite abaixo a nova mensagem da sua empresa", "Continuar", "Cancelar");
                    }
                    else if(listitem == 1)
                    {
                        format(String, sizeof(String), "{FFD700}%s", CompanyInfo[companyid][cEmployee1]);
                        ShowPlayerDialog(playerid, MAIN_COMPANY_EMPLOYEE, DIALOG_STYLE_LIST, String, "{FFFFFF}Adicionar funcionário\nRemover funcionário", "Continuar", "Cancelar");
                    }
                    else if(listitem == 2)
                    {
                        format(String, sizeof(String), "{FFD700}%s", CompanyInfo[companyid][cEmployee2]);
                        ShowPlayerDialog(playerid, MAIN_COMPANY_EMPLOYEE, DIALOG_STYLE_LIST, String, "{FFFFFF}Adicionar funcionário\nRemover funcionário", "Continuar", "Cancelar");
                    }
                    else if(listitem == 3)
                    {
                        format(String, sizeof(String), "{FFD700}%s", CompanyInfo[companyid][cEmployee3]);
                        ShowPlayerDialog(playerid, MAIN_COMPANY_EMPLOYEE, DIALOG_STYLE_LIST, String, "{FFFFFF}Adicionar funcionário\nRemover funcionário", "Continuar", "Cancelar");
                    }
                    else if(listitem == 4)
                    {
                        format(String, sizeof(String), "{FFD700}%s", CompanyInfo[companyid][cEmployee4]);
                        ShowPlayerDialog(playerid, MAIN_COMPANY_EMPLOYEE, DIALOG_STYLE_LIST, String, "{FFFFFF}Adicionar funcionário\nRemover funcionário", "Continuar", "Cancelar");
                    }
                    else if(listitem == 5)
                    {
                        if(EntregouMercadoria[playerid] == true)
                            return SendClientMessage(playerid, Erro, "| ERRO | Você já entregou mercadoria nesse level!");

                        if(Mercadoria[playerid] == false)
                            return SendClientMessage(playerid, Erro, "| ERRO | Você não tem uma mercadoria!");

                        switch(CompanyInfo[companyid][cCost])
                        {
                            case 750000:
                            {
                                CompanyInfo[companyid][cSafe] += 750;
                            }
                            case 850000:
                            {
                                CompanyInfo[companyid][cSafe] += 850;
                            }
                            case 950000:
                            {
                                CompanyInfo[companyid][cSafe] += 950;
                            }
                            case 1000000:
                            {
                                CompanyInfo[companyid][cSafe] += 1000;
                            }
                            case 2000000:
                            {
                                CompanyInfo[companyid][cSafe] += 2000;
                            }
                            case 2500000:
                            {
                                CompanyInfo[companyid][cSafe] += 2500;
                            }
                        }

                        CompanyInfo[companyid][cDeliveries]++;
                        if(CompanyInfo[companyid][cDeliveries] == 200)
                        {
                            CompanyInfo[companyid][cDeliveries] =  0;
                        }

                        SendClientMessage(playerid, C_PROPERTY, "| EMPRESA | Você entregou uma mercadoria para sua empresa!");

                        Mercadoria[playerid] = false;
                        EntregouMercadoria[playerid] = true;
                        CompanyInfo[companyid][cProduction]++;

                        UpdateCompanys(companyid);
                        UpdateCompanyExternal(companyid);
                        return 1;
                    }
                    else if(listitem == 6)
                    {
                        return ShowPlayerDialog(playerid, MAIN_COMPANY_SAFE, DIALOG_STYLE_MSGBOX, "{FFD700}Cofre", "{FFFFFF}Tem certeza que quer retirar seus lucros?", "Continuar", "Cancelar");
                    }
                    else if(listitem == 7)
                    {
                        new txt[200];

                        strcat(txt, "{FF0000}Funções \t\t {1CEB00}Status \n");

                        if(!strcmp(CompanyInfo[companyid][cSelling], "Sim", true))
                            { strcat(txt, "{FFFFFF}Vendendo: \t\t Sim\n");  }

                        if(!strcmp(CompanyInfo[companyid][cSelling], "N/A", true))
                            { strcat(txt, "{FFFFFF}Vendendo: \t\t Não\n"); }

                        format(String, sizeof(String), "{FFFFFF}Alterar Valor: \t\t $%s \n", IsMoney(CompanyInfo[companyid][cPrice], "."));
                        strcat(txt, String);
                        ShowPlayerDialog(playerid, MAIN_COMPANY_SELL_LIST, DIALOG_STYLE_TABLIST_HEADERS, "{FFD700}Vender Empresa", txt, "Selecionar", "Cancelar");
                        return 1;
                    }
                    else if(listitem == 8)
                    {
                        return ShowPlayerDialog(playerid, MAIN_COMPANY_RELEASE, DIALOG_STYLE_MSGBOX, "{FFD700}Liberar Empresa", "{FFFFFF}Tem certeza que quer liberar sua empresa?", "Sim", "Não");
                    }
                }
                else if(!strcmp(PlayerInfo[playerid][Nome], CompanyInfo[companyid][cEmployee1], true) || !strcmp(PlayerInfo[playerid][Nome], CompanyInfo[companyid][cEmployee2], true) || !strcmp(PlayerInfo[playerid][Nome], CompanyInfo[companyid][cEmployee3], true) || !strcmp(PlayerInfo[playerid][Nome], CompanyInfo[companyid][cEmployee4], true))
                {
                    if(listitem == 0)
                    {
                        ShowPlayerDialog(playerid, MAIN_COMPANY_ALTER_MSG, DIALOG_STYLE_INPUT, "{FFD700}Alterar Mensagem", "{FFFFFF}Digite abaixo a nova mensagem da sua empresa", "Continuar", "Cancelar");
                    }
                    else if(listitem == 1)
                    {
                        if(EntregouMercadoria[playerid] == true)
                            return SendClientMessage(playerid, Erro, "| ERRO | Você já entregou mercadoria nesse level!");

                        if(Mercadoria[playerid] == false)
                            return SendClientMessage(playerid, Erro, "| ERRO | Você não tem uma mercadoria!");

                        switch(CompanyInfo[companyid][cCost])
                        {
                            case 750000:
                            {
                                CompanyInfo[companyid][cSafe] += 750;
                            }
                            case 850000:
                            {
                                CompanyInfo[companyid][cSafe] += 850;
                            }
                            case 950000:
                            {
                                CompanyInfo[companyid][cSafe] += 950;
                            }
                            case 1000000:
                            {
                                CompanyInfo[companyid][cSafe] += 1000;
                            }
                            case 2000000:
                            {
                                CompanyInfo[companyid][cSafe] += 2000;
                            }
                            case 2500000:
                            {
                                CompanyInfo[companyid][cSafe] += 2500;
                            }
                        }

                        if(!strcmp(PlayerInfo[playerid][Nome], CompanyInfo[companyid][cEmployee1], true))
                        {
                            CompanyInfo[companyid][cEDeliveries1]++;
                            if(CompanyInfo[companyid][cEDeliveries1] == 200)
                            {
                                CompanyInfo[companyid][cEDeliveries1] =  0;
                            }
                        }
                        else if(!strcmp(PlayerInfo[playerid][Nome], CompanyInfo[companyid][cEmployee2], true))
                        {
                            CompanyInfo[companyid][cEDeliveries2]++;
                            if(CompanyInfo[companyid][cEDeliveries2] == 200)
                            {
                                CompanyInfo[companyid][cEDeliveries2] =  0;
                            }
                        }
                        else if(!strcmp(PlayerInfo[playerid][Nome], CompanyInfo[companyid][cEmployee3], true))
                        {
                            CompanyInfo[companyid][cEDeliveries3]++;
                            if(CompanyInfo[companyid][cEDeliveries3] == 200)
                            {
                                CompanyInfo[companyid][cEDeliveries3] =  0;
                            }
                        }
                        else if(!strcmp(PlayerInfo[playerid][Nome], CompanyInfo[companyid][cEmployee4], true))
                        {
                            CompanyInfo[companyid][cEDeliveries4]++;
                            if(CompanyInfo[companyid][cEDeliveries4] == 200)
                            {
                                CompanyInfo[companyid][cEDeliveries4] =  0;
                            }
                        }

                        SendClientMessage(playerid, C_PROPERTY, "| EMPRESA | Você entregou uma mercadoria para sua empresa!");
                        SendClientMessage(playerid, C_PROPERTY, "| EMPRESA | Seus bonus de entrega é de $2.250!");
                        PlayerInfo[playerid][Dinheiro] += 2250;
                        UpdatePlayerMoney(playerid);

                        Mercadoria[playerid] = false;
                        EntregouMercadoria[playerid] = true;
                        CompanyInfo[companyid][cProduction]++;

                        UpdateCompanys(companyid);
                        UpdateCompanyExternal(companyid);
                        return 1;
                    }
                    else if(listitem == 2)
                    {
                        return ShowPlayerDialog(playerid, MAIN_COMPANY_SAFE, DIALOG_STYLE_MSGBOX, "{FFD700}Cofre", "{FFFFFF}Tem certeza que quer retirar seus lucros?", "Continuar", "Cancelar");
                    }
                    else if(listitem == 3)
                    {
                        new txt[200];

                        strcat(txt, "{FF0000}Funções \t\t {1CEB00}Status \n");

                        if(!strcmp(CompanyInfo[companyid][cSelling], "Sim", true))
                            { strcat(txt, "{FFFFFF}Vendendo: \t\t Sim\n");  }

                        if(!strcmp(CompanyInfo[companyid][cSelling], "N/A", true))
                            { strcat(txt, "{FFFFFF}Vendendo: \t\t Não\n"); }

                        format(String, sizeof(String), "{FFFFFF}Alterar Valor: \t\t $%s \n", IsMoney(CompanyInfo[companyid][cPrice], "."));
                        strcat(txt, String);
                        ShowPlayerDialog(playerid, MAIN_COMPANY_SELL_LIST, DIALOG_STYLE_TABLIST_HEADERS, "{FFD700}Vender Empresa", txt, "Selecionar", "Cancelar");
                        return 1;
                    }
                    else if(listitem == 4)
                    {
                        return ShowPlayerDialog(playerid, MAIN_COMPANY_RELEASE, DIALOG_STYLE_MSGBOX, "{FFD700}Liberar Empresa", "{FFFFFF}Tem certeza que quer liberar sua empresa?", "Sim", "Não");
                    }
                }
            }
            return 1;
        }
        case MAIN_COMPANY_ALTER_MSG:
        {
            if(response)
            {
                if(withincompany[playerid] == 0)
                    return SendClientMessage(playerid, Erro, "| ERRO | Você não está em uma empresa!");

                if(strcmp(CompanyInfo[companyid][cName], PlayerInfo[playerid][Nome], true))
                    return SendClientMessage(playerid, Erro, "| ERRO | Você não é dono(a) dessa empresa!");

                if(!IsValidMessageHouse(inputtext))
                    return ShowPlayerDialog(playerid, MAIN_COMPANY_ALTER_MSG, DIALOG_STYLE_INPUT, "{FFD700}Alterar Mensagem", "{FFFFFF}Digite abaixo a nova mensagem da sua empresa\n{FF4000}Alguns caracteres especias não são permitidos!", "Continuar", "Cancelar");

                format(CompanyInfo[companyid][cMessage], 30, inputtext);
                format(String, sizeof(String), "| INFO | Agora a mensagem da sua empresa é {FF0000}%s", inputtext);
                SendClientMessage(playerid, -1, String);

                UpdateCompanys(companyid);
                UpdateCompanyExternal(companyid);
            }
        }
        case MAIN_COMPANY_SAFE:
        {
            if(response)
            {
                if(withincompany[playerid] == 0)
                    return SendClientMessage(playerid, Erro, "| ERRO | Você não está em uma empresa!");

                if(strcmp(CompanyInfo[companyid][cName], PlayerInfo[playerid][Nome], true))
                    return SendClientMessage(playerid, Erro, "| ERRO | Você não é dono(a) dessa empresa!");

                if(CompanyInfo[companyid][cSafe] == 0)
                    return SendClientMessage(playerid, Erro, "| ERRO | Você não tem nenhum lucro!");

                PlayerInfo[playerid][Dinheiro] += CompanyInfo[companyid][cSafe];
                CompanyInfo[companyid][cSafe] = 0;

                UpdatePlayerMoney(playerid);
                UpdateCompanys(companyid);

                format(String, sizeof(String), "| INFO | Agora seu cofre está com {2CC06B}$%s", IsMoney(CompanyInfo[companyid][cSafe], "."));
                SendClientMessage(playerid, -1, String);
            }
        }
        case MAIN_COMPANY_RELEASE:
        {
            if(response)
            {
                if(withincompany[playerid] == 0)
                    return SendClientMessage(playerid, Erro, "| ERRO | Você não está em uma empresa!");

                if(strcmp(CompanyInfo[companyid][cName], PlayerInfo[playerid][Nome], true))
                    return SendClientMessage(playerid, Erro, "| ERRO | Você não é dono(a) dessa empresa!");

                if(CompanyInfo[companyid][cSafe] > 0)
                    return SendClientMessage(playerid, Erro, "| ERRO | Você não removeu o dinheiro do seu cofre!");

                format(CompanyInfo[companyid][cName], MAX_PLAYER_NAME, "N/A");
                format(CompanyInfo[companyid][cEmployee1], MAX_PLAYER_NAME, "N/A");
                format(CompanyInfo[companyid][cEmployee2], MAX_PLAYER_NAME, "N/A");
                format(CompanyInfo[companyid][cEmployee3], MAX_PLAYER_NAME, "N/A");
                format(CompanyInfo[companyid][cEmployee4], MAX_PLAYER_NAME, "N/A");

                CompanyInfo[companyid][cDeliveries] = 0;
                CompanyInfo[companyid][cEDeliveries1] = 0;
                CompanyInfo[companyid][cEDeliveries2] = 0;
                CompanyInfo[companyid][cEDeliveries3] = 0;
                CompanyInfo[companyid][cEDeliveries4] = 0;

                format(CompanyInfo[companyid][cMessage], 30, "N/A");
                format(CompanyInfo[companyid][cSelling], 5, "Sim");
                CompanyInfo[companyid][cPrice] = 0;
                CompanyInfo[companyid][cSafe] = 0;
                CompanyInfo[companyid][cProduction] = 0;

                PlayerInfo[playerid][Dinheiro] += CompanyInfo[companyid][cStandard];
                UpdatePlayerMoney(playerid);

                GetPlayer2DZone(zone, MAX_ZONE_NAME, CompanyInfo[companyid][cIconX], CompanyInfo[companyid][cIconY]);
                format(String, sizeof(String), "| EMPRESAS | O(A) Jogador(a) %s liberou a empresa ID %d localizada em %s", PlayerInfo[playerid][Nome], CompanyInfo[companyid][cID], zone);
                SendClientMessageToAll(-1, String);

                SetPlayerPos(playerid, CompanyInfo[companyid][cIconX], CompanyInfo[companyid][cIconY], CompanyInfo[companyid][cIconZ]);
                SetPlayerInterior(playerid, 0);
                SetPlayerVirtualWorld(playerid, 0);
                withincompany[playerid] = 0;

                UpdateCompanys(companyid);
                UpdateCompanyExternal(companyid);
            }
        }
        case MAIN_COMPANY_SELL_LIST:
        {
            if(response)
            {
                if(listitem == 0)
                {
                    if(strcmp(CompanyInfo[companyid][cSelling], "Sim", true)==0)
                    {
                        format(CompanyInfo[companyid][cSelling], 5, "N/A");
                        SendClientMessage(playerid, -1, "| CASA | Agora sua casa não está mas à venda!");
                    }
                    else if(strcmp(CompanyInfo[companyid][cSelling], "N/A", true)==0)
                    {
                        if(CompanyInfo[companyid][cPrice] == 0)
                        {
                            CompanyInfo[companyid][cPrice] = 0;
                            CompanyInfo[companyid][cPrice] += CompanyInfo[companyid][cStandard];
                        }

                        format(CompanyInfo[companyid][cSelling], 5, "Sim");
                        format(String, sizeof(String),"| EMPRESA | Agora sua empresa está à venda no valor de {019303}$%s{FFFFFF}!", IsMoney(CompanyInfo[companyid][cPrice], "."));
                        SendClientMessage(playerid, -1, String);
                    }

                    UpdateCompanys(companyid);
                    UpdateCompanyExternal(companyid);
                }
                else if(listitem == 1)
                {
                    ShowPlayerDialog(playerid, MAIN_COMPANY_SELL_INPUT, DIALOG_STYLE_INPUT, "{FFD700}Vender Empresa", "{FFFFFF}Digite abaixo o valor que será somado com o valor padrão \nde sua empresa automaticamente!", "Continuar", "Cancelar");
                }
            }
        }
        case MAIN_COMPANY_SELL_INPUT:
        {
            if(response)
            {
                CompanyInfo[companyid][cPrice] = 0;
                CompanyInfo[companyid][cPrice] += CompanyInfo[companyid][cStandard] + strval(inputtext);

                format(String, sizeof(String), "| EMPRESA | O valor da sua empresa foi alterado para {019303}$%s{FFFFFF}, agora é só colocar a venda!", IsMoney(CompanyInfo[companyid][cPrice], "."));
                SendClientMessage(playerid, -1, String);

                UpdateCompanys(companyid);
                UpdateCompanyExternal(companyid);
            }
        }
    }
    return 1;
}


hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    new companyid = idcompany[playerid];

    if(newkeys == KEY_SECONDARY_ATTACK)
    {
        if(withincompany[playerid] == 0 && IsPlayerInRangeOfPoint(playerid, 1.5, CompanyInfo[companyid][cIconX], CompanyInfo[companyid][cIconY], CompanyInfo[companyid][cIconZ]))
        {
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
        else if(withincompany[playerid] == 1 && IsPlayerInRangeOfPoint(playerid, 2.0, CompanyInfo[companyid][cInteriorX], CompanyInfo[companyid][cInteriorY], CompanyInfo[companyid][cInteriorZ]))
        {
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
    }
    return 1;
}


hook OnPlayerPickUpPickup(playerid, pickupid)
{
    GetCompanyID(playerid);
    return 1;
}

LoadCompany()
{
    new _str[200];
    for(new i=1; i < MAX_COMPANYS; ++i)
    {
        mysql_format(IDConexao, _str, sizeof(_str), "SELECT * FROM `Empresas` WHERE `ID`='%d'", i);
        mysql_tquery(IDConexao, _str, "LoadCompanys", "d", i);
    }
    return 1;
}

forward CreateComapany(playerid, companyicon, cost, standard, Float:cix, Float:ciy, Float:ciz);
public CreateComapany(playerid, companyicon, cost, standard, Float:cix, Float:ciy, Float:ciz)
{
    new companyid = cache_insert_id();

    CompanyInfo[companyid][cID] = companyid;
    format(CompanyInfo[companyid][cName], MAX_PLAYER_NAME, "N/A");
    format(CompanyInfo[companyid][cEmployee1], MAX_PLAYER_NAME, "N/A");
    format(CompanyInfo[companyid][cEmployee2], MAX_PLAYER_NAME, "N/A");
    format(CompanyInfo[companyid][cEmployee3], MAX_PLAYER_NAME, "N/A");
    format(CompanyInfo[companyid][cEmployee4], MAX_PLAYER_NAME, "N/A");

    CompanyInfo[companyid][cDeliveries] = 0;
    CompanyInfo[companyid][cEDeliveries1] = 0;
    CompanyInfo[companyid][cEDeliveries2] = 0;
    CompanyInfo[companyid][cEDeliveries3] = 0;
    CompanyInfo[companyid][cEDeliveries4] = 0;

    format(CompanyInfo[companyid][cMessage], 30, "N/A");

    CompanyInfo[companyid][cCost] = cost;
    CompanyInfo[companyid][cStandard] = standard;
    CompanyInfo[companyid][cIcon] = companyicon;
    CompanyInfo[companyid][cIconX] = cix;
    CompanyInfo[companyid][cIconY] = ciy;
    CompanyInfo[companyid][cIconZ] = ciz;

    GetPlayer2DZone(zone, MAX_ZONE_NAME, CompanyInfo[companyid][cIconX], CompanyInfo[companyid][cIconY]);
    format(String, sizeof(String), "| BCM-Admin | O(A) %s %s criou a Empresa ID %d localizada em %s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], CompanyInfo[companyid][cID], zone);
    SendClientMessageToAll(adm, String);

    CreateCompanyExternal(companyid);
    return 1;
}

forward LoadCompanys(companyid);
public LoadCompanys(companyid)
{
    if(cache_num_rows() != 0)
    {
        new tmp[128];

        cache_get_value_int(0, "ID", CompanyInfo[companyid][cID]);

        cache_get_value_name(0, "Nome", tmp); format(CompanyInfo[companyid][cName], MAX_PLAYER_NAME, tmp);
        cache_get_value_name(0, "Status", tmp); format(CompanyInfo[companyid][cStatus], 30, tmp);
        cache_get_value_name(0, "Mensagem", tmp); format(CompanyInfo[companyid][cMessage], 30, tmp);
        cache_get_value_name(0, "Vendendo", tmp); format(CompanyInfo[companyid][cSelling], 5, tmp);

        cache_get_value_name(0, "Func1", tmp); format(CompanyInfo[companyid][cEmployee1], MAX_PLAYER_NAME, tmp);
        cache_get_value_name(0, "Func2", tmp); format(CompanyInfo[companyid][cEmployee2], MAX_PLAYER_NAME, tmp);
        cache_get_value_name(0, "Func3", tmp); format(CompanyInfo[companyid][cEmployee3], MAX_PLAYER_NAME, tmp);
        cache_get_value_name(0, "Func4", tmp); format(CompanyInfo[companyid][cEmployee4], MAX_PLAYER_NAME, tmp);

        cache_get_value_int(0, "Entregas", CompanyInfo[companyid][cDeliveries]);
        cache_get_value_int(0, "Func1Entregas", CompanyInfo[companyid][cEDeliveries1]);
        cache_get_value_int(0, "Func2Entregas", CompanyInfo[companyid][cEDeliveries2]);
        cache_get_value_int(0, "Func3Entregas", CompanyInfo[companyid][cEDeliveries3]);
        cache_get_value_int(0, "Func4Entregas", CompanyInfo[companyid][cEDeliveries4]);

        cache_get_value_int(0, "Preco", CompanyInfo[companyid][cPrice]);
        cache_get_value_int(0, "Custo", CompanyInfo[companyid][cCost]);
        cache_get_value_int(0, "Padrao", CompanyInfo[companyid][cStandard]);
        cache_get_value_int(0, "Cofre", CompanyInfo[companyid][cSafe]);
        cache_get_value_int(0, "Interior", CompanyInfo[companyid][cInterior]);
        cache_get_value_int(0, "Icon", CompanyInfo[companyid][cIcon]);
        cache_get_value_int(0, "Producao", CompanyInfo[companyid][cProduction]);

        cache_get_value_float(0, "X", CompanyInfo[companyid][cIconX]);
        cache_get_value_float(0, "Y", CompanyInfo[companyid][cIconY]);
        cache_get_value_float(0, "Z", CompanyInfo[companyid][cIconZ]);

        cache_get_value_float(0, "InteriorX", CompanyInfo[companyid][cInteriorX]);
        cache_get_value_float(0, "InteriorY", CompanyInfo[companyid][cInteriorY]);
        cache_get_value_float(0, "InteriorZ", CompanyInfo[companyid][cInteriorZ]);

        CreateCompanyExternal(companyid);
    }
    return 1;
}

UpdateCompanyExternal(companyid)
{
    DestroyDynamicMapIcon(CompanyMapIcon[companyid]);
    DestroyDynamicPickup(CompanyPickup[companyid]);

    if(strcmp(CompanyInfo[companyid][cName], "N/A", true)==0 && strcmp(CompanyInfo[companyid][cSelling], "Sim", true)==0) //Liberada
    {
        CompanyPickup[companyid] = CreateDynamicPickup(19606, 23, CompanyInfo[companyid][cIconX], CompanyInfo[companyid][cIconY], CompanyInfo[companyid][cIconZ], -1, -1, -1, 30.0);
        CompanyMapIcon[companyid] = CreateDynamicMapIcon(CompanyInfo[companyid][cIconX], CompanyInfo[companyid][cIconY], CompanyInfo[companyid][cIconZ], CompanyInfo[companyid][cIcon], -1, -1, -1, -1, 30.0);
        format(String, sizeof(String), "{31B404}Empresa a Venda ( ID:%d )\n{FFFFFF}%s\n{CE9F01}Valor: {31B404}$%s\n{41619B}/ComprarEmpresa", CompanyInfo[companyid][cID], CompanyInfo[companyid][cStatus], IsMoney(CompanyInfo[companyid][cCost], "."));
        UpdateDynamic3DTextLabelText(CompanyLabel[companyid], 0xFFFFFFFF, String);

    }
    else if(strcmp(CompanyInfo[companyid][cName], "N/A", true) && strcmp(CompanyInfo[companyid][cSelling], "N/A", true)==0) //Dono não vende
    {
        CompanyPickup[companyid] = CreateDynamicPickup(19605, 23, CompanyInfo[companyid][cIconX], CompanyInfo[companyid][cIconY], CompanyInfo[companyid][cIconZ], -1, -1, -1, 30.0);
        CompanyMapIcon[companyid] = CreateDynamicMapIcon(CompanyInfo[companyid][cIconX], CompanyInfo[companyid][cIconY], CompanyInfo[companyid][cIconZ], CompanyInfo[companyid][cIcon], -1, -1, -1, -1, 30.0);
        format(String, sizeof(String), "{FFD700}Empresa de %s ( ID:%d )\n{FFFFFF}%s\n{FFFFFF}%s\n{31B404}Produção: {FFFFFF}%d\n{41619B}/EntrarEmpresa", CompanyInfo[companyid][cName], CompanyInfo[companyid][cID], CompanyInfo[companyid][cMessage], CompanyInfo[companyid][cStatus], CompanyInfo[companyid][cProduction]);
        UpdateDynamic3DTextLabelText(CompanyLabel[companyid], 0xFFFFFFFF, String);
    }
    else if(strcmp(CompanyInfo[companyid][cName], "N/A", true) && strcmp(CompanyInfo[companyid][cSelling], "Sim", true)==0) // Dono vendendo
    {
        CompanyPickup[companyid] = CreateDynamicPickup(19607, 23, CompanyInfo[companyid][cIconX], CompanyInfo[companyid][cIconY], CompanyInfo[companyid][cIconZ], -1, -1, -1, 30.0);
        CompanyMapIcon[companyid] = CreateDynamicMapIcon(CompanyInfo[companyid][cIconX], CompanyInfo[companyid][cIconY], CompanyInfo[companyid][cIconZ], CompanyInfo[companyid][cIcon], -1, -1, -1, -1, 30.0);
        format(String, sizeof(String), "{FFD700}Empresa de %s ( ID:%d )\n{FFFFFF}%s\n{FFFFFF}%s\n{FFFFFF}O(A) proprietário(a) está vendendo a empresa por {019303}$%s\n{31B404}Produção: {FFFFFF}%d\n{41619B}/ComprarEmpresa", CompanyInfo[companyid][cName], CompanyInfo[companyid][cID], CompanyInfo[companyid][cMessage], CompanyInfo[companyid][cStatus], IsMoney(CompanyInfo[companyid][cPrice], "."), CompanyInfo[companyid][cProduction]);
        UpdateDynamic3DTextLabelText(CompanyLabel[companyid], 0xFFFFFFFF, String);
    }
    return 1;
}

CreateCompanyExternal(companyid)
{
    if(strcmp(CompanyInfo[companyid][cName], "N/A", true)==0 && strcmp(CompanyInfo[companyid][cSelling], "Sim", true)==0) //Liberada
    {
        CompanyPickup[companyid] = CreateDynamicPickup(19606, 23, CompanyInfo[companyid][cIconX], CompanyInfo[companyid][cIconY], CompanyInfo[companyid][cIconZ], -1, -1, -1, 30.0);
        CompanyMapIcon[companyid] = CreateDynamicMapIcon(CompanyInfo[companyid][cIconX], CompanyInfo[companyid][cIconY], CompanyInfo[companyid][cIconZ], CompanyInfo[companyid][cIcon], -1, -1, -1, -1, 30.0);
        format(String, sizeof(String), "{31B404}Empresa a Venda ( ID:%d )\n{FFFFFF}%s\n{CE9F01}Valor: {31B404}$%s\n{41619B}/ComprarEmpresa", CompanyInfo[companyid][cID], CompanyInfo[companyid][cStatus], IsMoney(CompanyInfo[companyid][cCost], "."));
        CompanyLabel[companyid] =  CreateDynamic3DTextLabel(String, 0xFFFFFFFF, CompanyInfo[companyid][cIconX], CompanyInfo[companyid][cIconY], CompanyInfo[companyid][cIconZ]+0.50, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1, -1, 20.0, -1, 0);
    }
    else if(strcmp(CompanyInfo[companyid][cName], "N/A", true) && strcmp(CompanyInfo[companyid][cSelling], "N/A", true)==0) //Dono não vende
    {
        CompanyPickup[companyid] = CreateDynamicPickup(19605, 23, CompanyInfo[companyid][cIconX], CompanyInfo[companyid][cIconY], CompanyInfo[companyid][cIconZ], -1, -1, -1, 30.0);
        CompanyMapIcon[companyid] = CreateDynamicMapIcon(CompanyInfo[companyid][cIconX], CompanyInfo[companyid][cIconY], CompanyInfo[companyid][cIconZ], CompanyInfo[companyid][cIcon], -1, -1, -1, -1, 30.0);
        format(String, sizeof(String), "{FFD700}Empresa de %s ( ID:%d )\n{FFFFFF}%s\n{FFFFFF}%s\n{31B404}Produção: {FFFFFF}%d\n{41619B}/EntrarEmpresa", CompanyInfo[companyid][cName], CompanyInfo[companyid][cID], CompanyInfo[companyid][cMessage], CompanyInfo[companyid][cStatus], CompanyInfo[companyid][cProduction]);
        CompanyLabel[companyid] =  CreateDynamic3DTextLabel(String, 0xFFFFFFFF, CompanyInfo[companyid][cIconX], CompanyInfo[companyid][cIconY], CompanyInfo[companyid][cIconZ]+0.50, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1, -1, 20.0, -1, 0);
    }
    else if(strcmp(CompanyInfo[companyid][cName], "N/A", true) && strcmp(CompanyInfo[companyid][cSelling], "Sim", true)==0) // Dono vendendo
    {
        CompanyPickup[companyid] = CreateDynamicPickup(19607, 23, CompanyInfo[companyid][cIconX], CompanyInfo[companyid][cIconY], CompanyInfo[companyid][cIconZ], -1, -1, -1, 30.0);
        CompanyMapIcon[companyid] = CreateDynamicMapIcon(CompanyInfo[companyid][cIconX], CompanyInfo[companyid][cIconY], CompanyInfo[companyid][cIconZ], CompanyInfo[companyid][cIcon], -1, -1, -1, -1, 30.0);
        format(String, sizeof(String), "{FFD700}Empresa de %s ( ID:%d )\n{FFFFFF}%s\n{FFFFFF}%s\n{FFFFFF}O(A) proprietário(a) está vendendo a empresa por {019303}$%s\n{31B404}Produção: {FFFFFF}%d\n{41619B}/ComprarEmpresa", CompanyInfo[companyid][cName], CompanyInfo[companyid][cID], CompanyInfo[companyid][cMessage], CompanyInfo[companyid][cStatus], IsMoney(CompanyInfo[companyid][cPrice], "."), CompanyInfo[companyid][cProduction]);
        CompanyLabel[companyid] = CreateDynamic3DTextLabel(String, 0xFFFFFFFF, CompanyInfo[companyid][cIconX], CompanyInfo[companyid][cIconY], CompanyInfo[companyid][cIconZ]+0.50, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1, -1, 20.0, -1, 0);
    }
    return 1;
}

UpdateCompanys(companyid)
{
    new Query[3000];
    mysql_format(IDConexao, Query, sizeof(Query), "UPDATE `Empresas` SET `Nome`='%e', `Func1`='%e',`Func2`='%e',`Func3`='%e',`Func4`='%e', `Entregas`='%d', `Func1Entregas`='%d', `Func2Entregas`='%d', `Func3Entregas`='%d', `Func4Entregas`='%d', `Status`='%e', `Mensagem`='%e', `Vendendo`='%e', `Preco`='%d', `Custo`='%d', `Padrao`='%d', `Cofre`='%d', `Interior`='%d', `Icon`='%d', `Producao`='%d', `X`='%f', `Y`='%f', `Z`='%f', `InteriorX`='%f', `InteriorY`='%f', `InteriorZ`='%f' WHERE `ID`='%d'",
    CompanyInfo[companyid][cName],
    CompanyInfo[companyid][cEmployee1],
    CompanyInfo[companyid][cEmployee2],
    CompanyInfo[companyid][cEmployee3],
    CompanyInfo[companyid][cEmployee4],
    CompanyInfo[companyid][cDeliveries],
    CompanyInfo[companyid][cEDeliveries1],
    CompanyInfo[companyid][cEDeliveries2],
    CompanyInfo[companyid][cEDeliveries3],
    CompanyInfo[companyid][cEDeliveries4],
    CompanyInfo[companyid][cStatus],
    CompanyInfo[companyid][cMessage],
    CompanyInfo[companyid][cSelling],
    CompanyInfo[companyid][cPrice],
    CompanyInfo[companyid][cCost],
    CompanyInfo[companyid][cStandard],
    CompanyInfo[companyid][cSafe],
    CompanyInfo[companyid][cInterior],
    CompanyInfo[companyid][cIcon],
    CompanyInfo[companyid][cProduction],
    CompanyInfo[companyid][cIconX],
    CompanyInfo[companyid][cIconY],
    CompanyInfo[companyid][cIconZ],
    CompanyInfo[companyid][cInteriorX],
    CompanyInfo[companyid][cInteriorY],
    CompanyInfo[companyid][cInteriorZ],
    CompanyInfo[companyid][cID]);
    mysql_query(IDConexao, Query);
    return 1;
}

GetCompanyID(playerid)
{
    for(new i=1; i < MAX_COMPANYS; i++)
    {
        if(IsPlayerInRangeOfPoint(playerid, 1.5, CompanyInfo[i][cIconX], CompanyInfo[i][cIconY], CompanyInfo[i][cIconZ]))
    	{
            SendClientMessage(playerid, -1, "| EMPRESA | Para entrar na empresa digite {CFCDCD}'/EntrarEmpresa'{FFFFFF} ou pressione a tecla {CFCDCD}'F'");
            return idcompany[playerid] = i;
    	}
    }
    return false;
}
