#include YSI\y_hooks

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
    Float:cInteriorZ,
    cEmployee
}

new BusinessInfo[MAX_BUSINESS][cInfo];
new Text3D:CompanyLabel[MAX_BUSINESS];
new CompanyMapIcon[MAX_BUSINESS];
new CompanyPickup[MAX_BUSINESS];

new withinbusiness[MAX_PLAYERS];
new idbusiness[MAX_PLAYERS];

new bool:Mercadoria[MAX_PLAYERS];
new bool:EntregouMercadoria[MAX_PLAYERS];

hook OnGameModeInit()
{
    new db_company[1000];
    strins(db_company,"CREATE TABLE IF NOT EXISTS `Business` ", strlen(db_company));
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
    strins(db_company,"IPTU int(2) NOT NULL,", strlen(db_company));
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
    return 1;
}

hook OnGameModeExit()
{
    for(new i=1; i < MAX_BUSINESS; i++)
	{
        DestroyDynamicMapIcon(CompanyMapIcon[i]);
        DestroyDynamic3DTextLabel(CompanyLabel[i]);
        DestroyDynamicPickup(CompanyPickup[i]);
	}
	return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case MAIN_FEED:
        {
            if(response)
            {
                if(listitem == 0)  return false ;

                else if(listitem == 1)
                {
                    if(PlayerInfo[playerid][Dinheiro] < 10)
                        return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

                    Progress[playerid][Fome] -= 40.0;

                    if(Progress[playerid][Fome] < 0.0) Progress[playerid][Fome] = 0.0;

                    AddComponentStore(playerid, "Pizza", 10, idbusiness[playerid]);
                    return 1;
                }
                else if(listitem == 2)
                {
                    if(PlayerInfo[playerid][Dinheiro] < 5)
                        return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

                    Progress[playerid][Fome] -= 30.0;

                    if(Progress[playerid][Fome] < 0.0) Progress[playerid][Fome] = 0.0;

                    AddComponentStore(playerid, "X-Bacon", 5, idbusiness[playerid]);
                    return 1;
                }
                else if(listitem == 3)
                {
                    if(PlayerInfo[playerid][Dinheiro] < 5)
                        return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

                    Progress[playerid][Fome] -= 30.0;

                    if(Progress[playerid][Fome] < 0.0) Progress[playerid][Fome] = 0.0;

                    AddComponentStore(playerid, "X-Tudo", 5, idbusiness[playerid]);
                    return 1;
                }
                else if(listitem == 4)
                {
                    if(PlayerInfo[playerid][Dinheiro] < 5)
                        return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

                    Progress[playerid][Fome] -= 30.0;

                    if(Progress[playerid][Fome] < 0.0) Progress[playerid][Fome] = 0.0;

                    AddComponentStore(playerid, "X-Salada", 5, idbusiness[playerid]);
                    return 1;
                }

                if(listitem == 5)  return false ;

                else if(listitem == 6)
                {
                    if(PlayerInfo[playerid][Dinheiro] < 2)
                        return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

                    Progress[playerid][Sede] -= 30.0;

                    if(Progress[playerid][Sede] < 0.0) Progress[playerid][Sede] = 0.0;

                    AddComponentStore(playerid, "Água", 2, idbusiness[playerid]);
                    return 1;
                }
                else if(listitem == 7)
                {
                    if(PlayerInfo[playerid][Dinheiro] < 5)
                        return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

                    Progress[playerid][Sede] -= 30.0;

                    if(Progress[playerid][Sede] < 0.0) Progress[playerid][Sede] = 0.0;

                    AddComponentStore(playerid, "Fanta", 5, idbusiness[playerid]);
                    return 1;
                }
                else if(listitem == 8)
                {
                    if(PlayerInfo[playerid][Dinheiro] < 10)
                        return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

                    Progress[playerid][Sede] -= 40.0;

                    if(Progress[playerid][Sede] < 0.0) Progress[playerid][Sede] = 0.0;

                    AddComponentStore(playerid, "Coca-Cola", 10, idbusiness[playerid]);
                    return 1;
                }
                else if(listitem == 9)
                {
                    if(PlayerInfo[playerid][Dinheiro] < 5)
                        return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

                    Progress[playerid][Sede] -= 30.0;

                    if(Progress[playerid][Sede] < 0.0) Progress[playerid][Sede] = 0.0;

                    AddComponentStore(playerid, "Dolly", 5, idbusiness[playerid]);
                    return 1;
                }
                else if(listitem == 10)
                {
                    if(PlayerInfo[playerid][Dinheiro] < 5)
                        return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

                    Progress[playerid][Sede] -= 30.0;

                    if(Progress[playerid][Sede] < 0.0) Progress[playerid][Sede] = 0.0;

                    AddComponentStore(playerid, "Sprite", 5, idbusiness[playerid]);
                    return 1;
                }
            }
            return 1;
        }
        case MAIN_UTILITIES:
        {
            if(response)
            {
                if(listitem == 0)
                {
                    if(PlayerInfo[playerid][cellphone] != 0)
                        return SendClientMessage(playerid, Erro, "Você já comprou um celular");

                    if(PlayerInfo[playerid][Dinheiro] < 1000)
                        return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

                    new _str[100];
                    mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Itens` SET `celular`='1' WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
                    mysql_query(IDConexao, _str);

                    if(strcmp(BusinessInfo[idbusiness[playerid]][cName], "N/A"))
                        { BusinessInfo[idbusiness[playerid]][cSafe] += 1000; }

                    PlayerInfo[playerid][Dinheiro] -= 1000;
                    PlayerInfo[playerid][cellphone] = 1;
                    UpdatePlayerMoney(playerid);

                    SendClientMessage(playerid, Green, "Você comprou um celular");
                    return 1;
                }
                else if(listitem == 1)
                {
                    if(PlayerInfo[playerid][sms] != 0)
                        return SendClientMessage(playerid, Erro, "Você já comprou sms, termine de utilizar");

                    if(PlayerInfo[playerid][Dinheiro] < 500)
                        return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

                    new _str[100];
                    mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Itens` SET `sms`='500' WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
                    mysql_query(IDConexao, _str);

                    if(strcmp(BusinessInfo[idbusiness[playerid]][cName], "N/A"))
                        { BusinessInfo[idbusiness[playerid]][cSafe] += 500; }

                    PlayerInfo[playerid][Dinheiro] -= 500;
                    PlayerInfo[playerid][sms] = 500;
                    UpdatePlayerMoney(playerid);

                    SendClientMessage(playerid, Green, "Você comprou Crédito para SMS");
                    return 1;
                }
                else if(listitem == 2)
                {
                    if(PlayerInfo[playerid][credits] != 0)
                        return SendClientMessage(playerid, Erro, "Você já comprou SMS, termine de utilizar");

                    if(PlayerInfo[playerid][Dinheiro] < 500)
                        return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

                    new _str[100];
                    mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Itens` SET `creditos`='500' WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
                    mysql_query(IDConexao, _str);

                    if(strcmp(BusinessInfo[idbusiness[playerid]][cName], "N/A"))
                        { BusinessInfo[idbusiness[playerid]][cSafe] += 500; }

                    PlayerInfo[playerid][Dinheiro] -= 500;
                    PlayerInfo[playerid][credits] = 500;
                    UpdatePlayerMoney(playerid);

                    SendClientMessage(playerid, Green, "Você comprou Crédito para Ligação");
                    return 1;
                }
                else if(listitem == 3)
                {
                    if(PlayerInfo[playerid][havegallon])
                        return SendClientMessage(playerid, Erro, "Você já comprou Galão de Combustível");

                    if(PlayerInfo[playerid][Dinheiro] < 100)
                        return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

                    new _str[100];
                    mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Itens` SET `havegallon`='1' WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
                    mysql_query(IDConexao, _str);

                    if(strcmp(BusinessInfo[idbusiness[playerid]][cName], "N/A"))
                        { BusinessInfo[idbusiness[playerid]][cSafe] += 100; }

                    PlayerInfo[playerid][havegallon] = true;
                    PlayerInfo[playerid][Dinheiro] -= 100;
                    UpdatePlayerMoney(playerid);

                    SendClientMessage(playerid, Green, "Você comprou um Galão de Combustível");
                    return 1;
                }
                else if(listitem == 4)
                {
                    if(PlayerInfo[playerid][nonstop])
                        return SendClientMessage(playerid, Erro, "Você ainda tem Sem Parar");

                    if(PlayerInfo[playerid][Dinheiro] < 5000)
                        return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

                    new _str[100];
                    mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Itens` SET `nonstop`='5000' WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
                    mysql_query(IDConexao, _str);

                    if(strcmp(BusinessInfo[idbusiness[playerid]][cName], "N/A"))
                        { BusinessInfo[idbusiness[playerid]][cSafe] += 5000; }

                    PlayerInfo[playerid][nonstop] = 5000;
                    PlayerInfo[playerid][Dinheiro] -= 5000;
                    UpdatePlayerMoney(playerid);

                    SendClientMessage(playerid, Green, "Você comprou um Sem Parar");
                    return 1;
                }
                else if(listitem == 5)
                {
                    if(PlayerInfo[playerid][bag])
                        return SendClientMessage(playerid, Erro, "Você já tem uma Mochila");

                    if(PlayerInfo[playerid][Dinheiro] < 900)
                        return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

                    new _str[100];
                    mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Itens` SET `bag`='1' WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
                    mysql_query(IDConexao, _str);

                    if(strcmp(BusinessInfo[idbusiness[playerid]][cName], "N/A"))
                        { BusinessInfo[idbusiness[playerid]][cSafe] += 900; }

                    PlayerInfo[playerid][bag] = 1;
                    PlayerInfo[playerid][Dinheiro] -= 900;
                    UpdatePlayerMoney(playerid);

                    new query[100];

                    mysql_format(IDConexao, query, sizeof(query), "INSERT INTO `Bag` (`id_contas`) VALUES ('%d')", PlayerInfo[playerid][ID]);
                    mysql_query(IDConexao, query);

                    SendClientMessage(playerid, Green, "Você comprou uma Mochila");
                    return 1;
                }
                else if(listitem == 6)
                {
                    if(PlayerInfo[playerid][kitrepair])
                        return SendClientMessage(playerid, Erro, "Você ainda tem Kit Reparos");

                    if(PlayerInfo[playerid][Dinheiro] < 1200)
                        return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

                    if(strcmp(BusinessInfo[idbusiness[playerid]][cName], "N/A"))
                        { BusinessInfo[idbusiness[playerid]][cSafe] += 1200; }

                    PlayerInfo[playerid][kitrepair] = 5;
                    PlayerInfo[playerid][Dinheiro] -= 1200;
                    UpdatePlayerMoney(playerid);

                    new query[100];
                    mysql_format(IDConexao, query, 100, "UPDATE `Itens` SET `kitrepair`='5' WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
                    mysql_query(IDConexao, query);

                    SendClientMessage(playerid, Green, "Você comprou 5 Kit Reparos");
                    return 1;
                }
            }
            return 1;
        }
        case MAIN_WEAPON:
        {
            if(!response) return 0;

            switch(listitem)
            {
                case 0: GivePlayerWeaponBussines(playerid, idbusiness[playerid], 30, 750, 3250);
                case 1: GivePlayerWeaponBussines(playerid, idbusiness[playerid], 31, 650, 3500);
                case 2: GivePlayerWeaponBussines(playerid, idbusiness[playerid], 25, 500, 450);
                case 3: GivePlayerWeaponBussines(playerid, idbusiness[playerid], 26, 900, 600);
                case 4: GivePlayerWeaponBussines(playerid, idbusiness[playerid], 27, 500, 550);
                case 5: GivePlayerWeaponBussines(playerid, idbusiness[playerid], 24, 450, 650);
                case 6: GivePlayerWeaponBussines(playerid, idbusiness[playerid], 23, 350, 500);
                case 7: GivePlayerWeaponBussines(playerid, idbusiness[playerid], 22, 300, 350);
                case 8:
                {
                    if(PlayerInfo[playerid][Dinheiro] < 500)
                        return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

                    if(strcmp(BusinessInfo[idbusiness[playerid]][cName], "N/A", true))
                        { BusinessInfo[idbusiness[playerid]][cSafe] += 500; }

                    PlayerInfo[playerid][c4] += 10;
                    PlayerInfo[playerid][Dinheiro] -= 500;

                    UpdatePlayerMoney(playerid);

                    new query[100];
                    mysql_format(IDConexao, query, sizeof(query), "UPDATE `Itens` SET `c4`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][c4], PlayerInfo[playerid][ID]);
                    mysql_query(IDConexao, query);

                    SendClientMessage(playerid, Green, "Você comprou 10 dinamites");
                    return 1;
                }
                case 9:
                {
                    if(PlayerInfo[playerid][Dinheiro] < 2000)
                        return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

                    if(strcmp(BusinessInfo[idbusiness[playerid]][cName], "N/A", true))
                        { BusinessInfo[idbusiness[playerid]][cSafe] += 2000; }

                    PlayerInfo[playerid][Dinheiro] -= 2000;
                    UpdatePlayerMoney(playerid);

                    SetPlayerArmour(playerid, 50.0);

                    SendClientMessage(playerid, Green, "Você comprou Colete 50 porcento");
                    return 1;
                }
                case 10:
                {
                    if(PlayerInfo[playerid][Profissao] != weaponproducer)
                        return SendClientMessage(playerid, Erro, "Você não tem permissão");

                    new wpSell[7], wpOverall;

                    wpSell[0] = GetIntQuery(playerid, "WeaponProducer", "ak");
                    SetIntQuery(playerid, "WeaponProducer", "ak", 0);
                    wpSell[1] = GetIntQuery(playerid, "WeaponProducer", "m4");
                    SetIntQuery(playerid, "WeaponProducer", "m4", 0);
                    wpSell[2] = GetIntQuery(playerid, "WeaponProducer", "pistol");
                    SetIntQuery(playerid, "WeaponProducer", "pistol", 0);
                    wpSell[3] = GetIntQuery(playerid, "WeaponProducer", "uzi");
                    SetIntQuery(playerid, "WeaponProducer", "uzi", 0);
                    wpSell[4] = GetIntQuery(playerid, "WeaponProducer", "sawnoff");
                    SetIntQuery(playerid, "WeaponProducer", "sawnoff", 0);
                    wpSell[5] = GetIntQuery(playerid, "WeaponProducer", "combat");
                    SetIntQuery(playerid, "WeaponProducer", "combat", 0);
                    wpSell[6] = GetIntQuery(playerid, "WeaponProducer", "sniper");
                    SetIntQuery(playerid, "WeaponProducer", "sniper", 0);

                    for(new i = 0; i < sizeof(wpSell); i++)
                    {
                        wpOverall += (wpSell[i] * WP_PRICE_AMMUNATION);
                    }

                    PlayerInfo[playerid][Dinheiro] += wpOverall;
                    UpdatePlayerMoney(playerid);

                    PlayerInfo[playerid][Estrelas] += 1;
                    UpdatePlayerStar(playerid);

                    format(String, MAX_STRING, "Todas suas armas foram vendidas e você recebeu {1B6302}$%s", IsMoney(wpOverall, "."));
                    SendClientMessage(playerid, White, String);
                    SendClientMessage(playerid, Yellow, "Infelizmente te denunciaram e agora você está procurado(a)");

                    GetPlayer2DZone(zone, MAX_ZONE_NAME, BusinessInfo[idbusiness[playerid]][cIconX], BusinessInfo[idbusiness[playerid]][cIconY]);

                    format(String, MAX_STRING, "O(A) Jogador(a) %s[%d] vendeu arma ilícita em uma empresa na localidade ( %s )", PlayerInfo[playerid][Nome], playerid, zone);

                    for(new player = 0; player < MAX_PLAYERS; player++)
                    {
                        if(IsPlayerPolice(player))
                        {
                            SendClientMessage(player, 0x2894FFAA, String);
                        }
                    }
                    return 1;
                }
            }
            return 1;
        }
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
                else if(listitem == 2) //Burger shot 850k
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
                mysql_format(IDConexao, query, sizeof(query), "INSERT INTO `Business` (`Icon`, `Custo`, `Padrao`, `X`, `Y`, `Z`) VALUES ('%d', '%d', '%d', '%f', '%f', '%f')", CompanyIcon, Cost, Standard, cPos[0], cPos[1], cPos[2]-0.5);
                mysql_tquery(IDConexao, query, "CreateComapany", "ddddfff", playerid, CompanyIcon, Cost, Standard, cPos[0], cPos[1], cPos[2]-0.5);
            }
        }
        case MAIN_COMPANY:
        {
            if(response)
            {
                if(!strcmp(PlayerInfo[playerid][Nome], BusinessInfo[idbusiness[playerid]][cName], true))
                {
                    if(listitem == 0)
                    {
                        ShowPlayerDialog(playerid, MAIN_COMPANY_ALTER_MSG, DIALOG_STYLE_INPUT, "{FFD700}Alterar Mensagem", "{FFFFFF}Digite abaixo a nova mensagem da sua empresa", "Continuar", "Cancelar");
                    }
                    else if(listitem == 1)
                    {
                        BusinessInfo[idbusiness[playerid]][cEmployee] = 1;
                        format(String, sizeof(String), "{FFD700}%s", BusinessInfo[idbusiness[playerid]][cEmployee1]);
                        ShowPlayerDialog(playerid, MAIN_COMPANY_EMPLOYEE, DIALOG_STYLE_LIST, String, "{FFFFFF}Ver entregas\nAdicionar funcionário\nRemover funcionário", "Continuar", "Cancelar");
                    }
                    else if(listitem == 2)
                    {
                        BusinessInfo[idbusiness[playerid]][cEmployee] = 2;
                        format(String, sizeof(String), "{FFD700}%s", BusinessInfo[idbusiness[playerid]][cEmployee2]);
                        ShowPlayerDialog(playerid, MAIN_COMPANY_EMPLOYEE, DIALOG_STYLE_LIST, String, "{FFFFFF}Ver entregas\nAdicionar funcionário\nRemover funcionário", "Continuar", "Cancelar");
                    }
                    else if(listitem == 3)
                    {
                        BusinessInfo[idbusiness[playerid]][cEmployee] = 3;
                        format(String, sizeof(String), "{FFD700}%s", BusinessInfo[idbusiness[playerid]][cEmployee3]);
                        ShowPlayerDialog(playerid, MAIN_COMPANY_EMPLOYEE, DIALOG_STYLE_LIST, String, "{FFFFFF}Ver entregas\nAdicionar funcionário\nRemover funcionário", "Continuar", "Cancelar");
                    }
                    else if(listitem == 4)
                    {
                        BusinessInfo[idbusiness[playerid]][cEmployee] = 4;
                        format(String, sizeof(String), "{FFD700}%s", BusinessInfo[idbusiness[playerid]][cEmployee4]);
                        ShowPlayerDialog(playerid, MAIN_COMPANY_EMPLOYEE, DIALOG_STYLE_LIST, String, "{FFFFFF}Ver entregas\nAdicionar funcionário\nRemover funcionário", "Continuar", "Cancelar");
                    }
                    else if(listitem == 5)
                    {
                        if(EntregouMercadoria[playerid] == true)
                            return SendClientMessage(playerid, Erro, "Você já entregou mercadoria nesse level");

                        if(Mercadoria[playerid] == false)
                            return SendClientMessage(playerid, Erro, "Você não tem uma mercadoria");

                        switch(BusinessInfo[idbusiness[playerid]][cCost])
                        {
                            case 750000:
                            {
                                BusinessInfo[idbusiness[playerid]][cSafe] += 750;
                            }
                            case 850000:
                            {
                                BusinessInfo[idbusiness[playerid]][cSafe] += 850;
                            }
                            case 950000:
                            {
                                BusinessInfo[idbusiness[playerid]][cSafe] += 950;
                            }
                            case 1000000:
                            {
                                BusinessInfo[idbusiness[playerid]][cSafe] += 1000;
                            }
                            case 1500000:
                            {
                                BusinessInfo[idbusiness[playerid]][cSafe] += 1500;
                            }
                            case 2000000:
                            {
                                BusinessInfo[idbusiness[playerid]][cSafe] += 2000;
                            }
                            case 2500000:
                            {
                                BusinessInfo[idbusiness[playerid]][cSafe] += 2500;
                            }
                        }

                        BusinessInfo[idbusiness[playerid]][cDeliveries]++;
                        if(BusinessInfo[idbusiness[playerid]][cDeliveries] == 200)
                        {
                            BusinessInfo[idbusiness[playerid]][cDeliveries] =  0;
                        }

                        SendClientMessage(playerid, C_PROPERTY, "Você entregou a mercadoria e a empresa obtever mais 1 produção");

                        Mercadoria[playerid] = false;
                        EntregouMercadoria[playerid] = true;
                        BusinessInfo[idbusiness[playerid]][cProduction]++;

                        UpdateCompanys(idbusiness[playerid]);
                        UpdateCompanyExternal(idbusiness[playerid]);
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

                        if(!strcmp(BusinessInfo[idbusiness[playerid]][cSelling], "Sim", true))
                            { strcat(txt, "{FFFFFF}Vendendo: \t\t Sim\n");  }

                        if(!strcmp(BusinessInfo[idbusiness[playerid]][cSelling], "N/A", true))
                            { strcat(txt, "{FFFFFF}Vendendo: \t\t Não\n"); }

                        format(String, sizeof(String), "{FFFFFF}Alterar Valor: \t\t $%s \n", IsMoney(BusinessInfo[idbusiness[playerid]][cPrice], "."));
                        strcat(txt, String);
                        ShowPlayerDialog(playerid, MAIN_COMPANY_SELL_LIST, DIALOG_STYLE_TABLIST_HEADERS, "{FFD700}Vender Empresa", txt, "Selecionar", "Cancelar");
                        return 1;
                    }
                    else if(listitem == 8)
                    {
                        ShowPlayerDialog(playerid, MAIN_COMPANY_RELEASE, DIALOG_STYLE_INPUT, "{FF0000}Código de Confirmação", "{FFFFFF}Pra liberar sua empresa para o servidor é necessário o código de confirmação\n\n{FF4000}Obs: o código de vericação é o mesmo usado para registrar sua conta!", "Continuar", "Cancelar");
                        return 1;
                    }
                }
                else if(!strcmp(PlayerInfo[playerid][Nome], BusinessInfo[idbusiness[playerid]][cEmployee1], true) || !strcmp(PlayerInfo[playerid][Nome], BusinessInfo[idbusiness[playerid]][cEmployee2], true) || !strcmp(PlayerInfo[playerid][Nome], BusinessInfo[idbusiness[playerid]][cEmployee3], true) || !strcmp(PlayerInfo[playerid][Nome], BusinessInfo[idbusiness[playerid]][cEmployee4], true))
                {
                    if(listitem == 0)
                    {
                        if(EntregouMercadoria[playerid] == true)
                            return SendClientMessage(playerid, Erro, "Você já entregou mercadoria nesse level");

                        if(Mercadoria[playerid] == false)
                            return SendClientMessage(playerid, Erro, "Você não tem uma mercadoria");

                        switch(BusinessInfo[idbusiness[playerid]][cCost])
                        {
                            case 750000:
                            {
                                BusinessInfo[idbusiness[playerid]][cSafe] += 750;
                            }
                            case 850000:
                            {
                                BusinessInfo[idbusiness[playerid]][cSafe] += 850;
                            }
                            case 950000:
                            {
                                BusinessInfo[idbusiness[playerid]][cSafe] += 950;
                            }
                            case 1000000:
                            {
                                BusinessInfo[idbusiness[playerid]][cSafe] += 1000;
                            }
                            case 1500000:
                            {
                                BusinessInfo[idbusiness[playerid]][cSafe] += 1500;
                            }
                            case 2000000:
                            {
                                BusinessInfo[idbusiness[playerid]][cSafe] += 2000;
                            }
                            case 2500000:
                            {
                                BusinessInfo[idbusiness[playerid]][cSafe] += 2500;
                            }
                        }

                        if(!strcmp(PlayerInfo[playerid][Nome], BusinessInfo[idbusiness[playerid]][cEmployee1], true))
                        {
                            BusinessInfo[idbusiness[playerid]][cEDeliveries1]++;
                            if(BusinessInfo[idbusiness[playerid]][cEDeliveries1] == 200)
                            {
                                BusinessInfo[idbusiness[playerid]][cEDeliveries1] =  0;
                            }
                        }
                        else if(!strcmp(PlayerInfo[playerid][Nome], BusinessInfo[idbusiness[playerid]][cEmployee2], true))
                        {
                            BusinessInfo[idbusiness[playerid]][cEDeliveries2]++;
                            if(BusinessInfo[idbusiness[playerid]][cEDeliveries2] == 200)
                            {
                                BusinessInfo[idbusiness[playerid]][cEDeliveries2] =  0;
                            }
                        }
                        else if(!strcmp(PlayerInfo[playerid][Nome], BusinessInfo[idbusiness[playerid]][cEmployee3], true))
                        {
                            BusinessInfo[idbusiness[playerid]][cEDeliveries3]++;
                            if(BusinessInfo[idbusiness[playerid]][cEDeliveries3] == 200)
                            {
                                BusinessInfo[idbusiness[playerid]][cEDeliveries3] =  0;
                            }
                        }
                        else if(!strcmp(PlayerInfo[playerid][Nome], BusinessInfo[idbusiness[playerid]][cEmployee4], true))
                        {
                            BusinessInfo[idbusiness[playerid]][cEDeliveries4]++;
                            if(BusinessInfo[idbusiness[playerid]][cEDeliveries4] == 200)
                            {
                                BusinessInfo[idbusiness[playerid]][cEDeliveries4] =  0;
                            }
                        }

                        SendClientMessage(playerid, C_PROPERTY, "Você entregou a mercadoria e a empresa obtever mais 1 produção");
                        SendClientMessage(playerid, C_PROPERTY, "Seus bonus de entrega é de $2.250");
                        PlayerInfo[playerid][Dinheiro] += 2250;
                        UpdatePlayerMoney(playerid);

                        Mercadoria[playerid] = false;
                        EntregouMercadoria[playerid] = true;
                        BusinessInfo[idbusiness[playerid]][cProduction]++;

                        UpdateCompanys(idbusiness[playerid]);
                        UpdateCompanyExternal(idbusiness[playerid]);
                        return 1;
                    }
                    else if(listitem == 1)
                    {
                        new str_[50];

                        if(!strcmp(BusinessInfo[idbusiness[playerid]][cEmployee1], PlayerInfo[playerid][Nome], true))
                        {
                            format(str_, sizeof(str_), "{FFD700}%s", BusinessInfo[idbusiness[playerid]][cEmployee1]);
                            format(String, sizeof(String), "{FFFFFF}Empresa ID {0080FF}%d \n\n{FFFFFF}Você já efetuou {00C40A}%d{FFFFFF} entrega(s)", BusinessInfo[idbusiness[playerid]][cID], BusinessInfo[idbusiness[playerid]][cEDeliveries1]);
                        }
                        else if(!strcmp(BusinessInfo[idbusiness[playerid]][cEmployee2], PlayerInfo[playerid][Nome], true))
                        {
                            format(str_, sizeof(str_), "{FFD700}%s", BusinessInfo[idbusiness[playerid]][cEmployee2]);
                            format(String, sizeof(String), "{FFFFFF}Empresa ID {0080FF}%d \n\n{FFFFFF}Você já efetuou {00C40A}%d{FFFFFF} entrega(s)", BusinessInfo[idbusiness[playerid]][cID], BusinessInfo[idbusiness[playerid]][cEDeliveries2]);
                        }
                        else if(!strcmp(BusinessInfo[idbusiness[playerid]][cEmployee3], PlayerInfo[playerid][Nome], true))
                        {
                            format(str_, sizeof(str_), "{FFD700}%s", BusinessInfo[idbusiness[playerid]][cEmployee3]);
                            format(String, sizeof(String), "{FFFFFF}Empresa ID {0080FF}%d \n\n{FFFFFF}Você já efetuou {00C40A}%d{FFFFFF} entrega(s)", BusinessInfo[idbusiness[playerid]][cID], BusinessInfo[idbusiness[playerid]][cEDeliveries3]);
                        }
                        else if(!strcmp(BusinessInfo[idbusiness[playerid]][cEmployee4], PlayerInfo[playerid][Nome], true))
                        {
                            format(str_, sizeof(str_), "{FFD700}%s", BusinessInfo[idbusiness[playerid]][cEmployee4]);
                            format(String, sizeof(String), "{FFFFFF}Empresa ID {0080FF}%d \n\n{FFFFFF}Você já efetuou {00C40A}%d{FFFFFF} entrega(s)", BusinessInfo[idbusiness[playerid]][cID], BusinessInfo[idbusiness[playerid]][cEDeliveries4]);
                        }

                        ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, str_, String, "Continuar", "Cancelar");
                        return 1;
                    }
                    else if(listitem == 2)
                    {
                        if(!strcmp(BusinessInfo[idbusiness[playerid]][cEmployee1], PlayerInfo[playerid][Nome], true))
                        {
                            format(String, sizeof(String), "Você se demitiu da empresa ID %d", BusinessInfo[idbusiness[playerid]][cID]);
                            SendClientMessage(playerid, C_PROPERTY, String);
                            format(BusinessInfo[idbusiness[playerid]][cEmployee1], MAX_PLAYER_NAME, "N/A");
                            BusinessInfo[idbusiness[playerid]][cEDeliveries1] =  0;
                            UpdateCompanys(idbusiness[playerid]);
                        }
                        else if(!strcmp(BusinessInfo[idbusiness[playerid]][cEmployee2], PlayerInfo[playerid][Nome], true))
                        {
                            format(String, sizeof(String), "Você se demitiu da empresa ID %d", BusinessInfo[idbusiness[playerid]][cID]);
                            SendClientMessage(playerid, C_PROPERTY, String);
                            format(BusinessInfo[idbusiness[playerid]][cEmployee2], MAX_PLAYER_NAME, "N/A");
                            BusinessInfo[idbusiness[playerid]][cEDeliveries2] =  0;
                            UpdateCompanys(idbusiness[playerid]);
                        }
                        else if(!strcmp(BusinessInfo[idbusiness[playerid]][cEmployee3], PlayerInfo[playerid][Nome], true))
                        {
                            format(String, sizeof(String), "Você se demitiu da empresa ID %d", BusinessInfo[idbusiness[playerid]][cID]);
                            SendClientMessage(playerid, C_PROPERTY, String);
                            format(BusinessInfo[idbusiness[playerid]][cEmployee3], MAX_PLAYER_NAME, "N/A");
                            BusinessInfo[idbusiness[playerid]][cEDeliveries3] =  0;
                            UpdateCompanys(idbusiness[playerid]);
                        }
                        else if(!strcmp(BusinessInfo[idbusiness[playerid]][cEmployee4], PlayerInfo[playerid][Nome], true))
                        {
                            format(String, sizeof(String), "Você se demitiu da empresa ID %d", BusinessInfo[idbusiness[playerid]][cID]);
                            SendClientMessage(playerid, C_PROPERTY, String);
                            format(BusinessInfo[idbusiness[playerid]][cEmployee4], MAX_PLAYER_NAME, "N/A");
                            BusinessInfo[idbusiness[playerid]][cEDeliveries4] =  0;
                            UpdateCompanys(idbusiness[playerid]);
                        }
                        return 1;
                    }
                }
            }
            return 1;
        }
        case MAIN_COMPANY_ALTER_MSG:
        {
            if(response)
            {
                if(withinbusiness[playerid] == 0)
                    return SendClientMessage(playerid, Erro, "Você não está em uma empresa");

                if(strcmp(BusinessInfo[idbusiness[playerid]][cName], PlayerInfo[playerid][Nome], true))
                    return SendClientMessage(playerid, Erro, "Você não é dono(a) dessa empresa");

                if(!IsValidMessageHouse(inputtext))
                    return ShowPlayerDialog(playerid, MAIN_COMPANY_ALTER_MSG, DIALOG_STYLE_INPUT, "{FFD700}Alterar Mensagem", "{FFFFFF}Digite abaixo a nova mensagem da sua empresa\n{FF4000}Alguns caracteres especias não são permitidos!", "Continuar", "Cancelar");

                format(BusinessInfo[idbusiness[playerid]][cMessage], 30, inputtext);
                format(String, sizeof(String), "Agora a mensagem da sua empresa é {FF0000}%s", inputtext);
                SendClientMessage(playerid, -1, String);

                UpdateCompanys(idbusiness[playerid]);
                UpdateCompanyExternal(idbusiness[playerid]);
            }
        }
        case MAIN_COMPANY_SAFE:
        {
            if(response)
            {
                if(withinbusiness[playerid] == 0)
                    return SendClientMessage(playerid, Erro, "Você não está em uma empresa");

                if(strcmp(BusinessInfo[idbusiness[playerid]][cName], PlayerInfo[playerid][Nome], true))
                    return SendClientMessage(playerid, Erro, "Você não é dono(a) dessa empresa");

                if(BusinessInfo[idbusiness[playerid]][cSafe] == 0)
                    return SendClientMessage(playerid, Erro, "Você não tem nenhum lucro");

                PlayerInfo[playerid][Dinheiro] += BusinessInfo[idbusiness[playerid]][cSafe];
                BusinessInfo[idbusiness[playerid]][cSafe] = 0;

                UpdatePlayerMoney(playerid);
                UpdateCompanys(idbusiness[playerid]);

                format(String, sizeof(String), "Agora seu cofre está com {2CC06B}$%s", IsMoney(BusinessInfo[idbusiness[playerid]][cSafe], "."));
                SendClientMessage(playerid, -1, String);
            }
        }
        case MAIN_COMPANY_RELEASE:
        {
            if(response)
            {
                if(!strlen(inputtext))
                    return ShowPlayerDialog(playerid, MAIN_COMPANY_RELEASE, DIALOG_STYLE_INPUT, "{FF0000}Código de Confirmação", "{FFFFFF}Pra liberar sua empresa para o servidor é necessário o código de confirmação\n{FF0000}Código Incorreto!\n\n{FF4000}Obs: o código de vericação é o mesmo usado para registrar sua conta!", "Continuar", "Cancelar");

                if(!IsValidCodingAccount(playerid, inputtext))
                    return ShowPlayerDialog(playerid, MAIN_COMPANY_RELEASE, DIALOG_STYLE_INPUT, "{FF0000}Código de Confirmação", "{FFFFFF}Pra liberar sua empresa para o servidor é necessário o código de confirmação\n{FF0000}Código Incorreto!\n\n{FF4000}Obs: o código de vericação é o mesmo usado para registrar sua conta!", "Continuar", "Cancelar");

                if(withinbusiness[playerid] == 0)
                    return SendClientMessage(playerid, Erro, "Você não está em uma empresa");

                if(strcmp(BusinessInfo[idbusiness[playerid]][cName], PlayerInfo[playerid][Nome], true))
                    return SendClientMessage(playerid, Erro, "Você não é dono(a) dessa empresa");

                if(BusinessInfo[idbusiness[playerid]][cSafe] > 0)
                    return SendClientMessage(playerid, Erro, "Você não removeu o dinheiro do seu cofre");

                PlayerInfo[playerid][Dinheiro] += BusinessInfo[idbusiness[playerid]][cStandard];
                UpdatePlayerMoney(playerid);

                GetPlayer2DZone(zone, MAX_ZONE_NAME, BusinessInfo[idbusiness[playerid]][cIconX], BusinessInfo[idbusiness[playerid]][cIconY]);
                format(String, sizeof(String), "O(A) Jogador(a) %s liberou a empresa ID %d localizada em %s", PlayerInfo[playerid][Nome], BusinessInfo[idbusiness[playerid]][cID], zone);
                SendClientMessageToAll(-1, String);

                SetPlayerPos(playerid, BusinessInfo[idbusiness[playerid]][cIconX], BusinessInfo[idbusiness[playerid]][cIconY], BusinessInfo[idbusiness[playerid]][cIconZ]);
                SetPlayerInterior(playerid, 0);
                SetPlayerVirtualWorld(playerid, 0);
                withinbusiness[playerid] = 0;

                ReleaseBusiness(idbusiness[playerid]);
            }
        }
        case MAIN_COMPANY_SELL_LIST:
        {
            if(response)
            {
                if(listitem == 0)
                {
                    if(strcmp(BusinessInfo[idbusiness[playerid]][cSelling], "Sim", true)==0)
                    {
                        format(BusinessInfo[idbusiness[playerid]][cSelling], 5, "N/A");
                        SendClientMessage(playerid, -1, "Agora sua empresa não está mas à venda");
                    }
                    else if(strcmp(BusinessInfo[idbusiness[playerid]][cSelling], "N/A", true)==0)
                    {
                        if(BusinessInfo[idbusiness[playerid]][cPrice] == 0)
                        {
                            BusinessInfo[idbusiness[playerid]][cPrice] = 0;
                            BusinessInfo[idbusiness[playerid]][cPrice] += BusinessInfo[idbusiness[playerid]][cStandard];
                        }

                        format(BusinessInfo[idbusiness[playerid]][cSelling], 5, "Sim");
                        format(String, sizeof(String),"Agora sua empresa está à venda no valor de {019303}$%s{FFFFFF}!", IsMoney(BusinessInfo[idbusiness[playerid]][cPrice], "."));
                        SendClientMessage(playerid, -1, String);
                    }

                    UpdateCompanys(idbusiness[playerid]);
                    UpdateCompanyExternal(idbusiness[playerid]);
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
                BusinessInfo[idbusiness[playerid]][cPrice] = 0;
                BusinessInfo[idbusiness[playerid]][cPrice] += BusinessInfo[idbusiness[playerid]][cStandard] + strval(inputtext);

                format(String, sizeof(String), "O valor da sua empresa foi alterado para {019303}$%s{FFFFFF}, agora é só colocar a venda!", IsMoney(BusinessInfo[idbusiness[playerid]][cPrice], "."));
                SendClientMessage(playerid, -1, String);

                UpdateCompanys(idbusiness[playerid]);
                UpdateCompanyExternal(idbusiness[playerid]);
            }
        }
        case MAIN_COMPANY_EMPLOYEE:
        {
            if(response)
            {
                switch(listitem)
                {
                    case 0:
                    {
                        new str_[50];

                        if(BusinessInfo[idbusiness[playerid]][cEmployee] == 1)
                        {
                            if(!strcmp(BusinessInfo[idbusiness[playerid]][cEmployee1], "N/A", true))
                                return ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FFD700}N/A", "{FFFFFF}Não tem nenhum funcionário!", "Fechar", #);

                            format(str_, sizeof(str_), "{FFD700}%s", BusinessInfo[idbusiness[playerid]][cEmployee1]);
                            format(String, sizeof(String), "{FFFFFF}Empresa ID {0080FF}%d \n\n{FFFFFF}O(A) Funcionário(a) já efetuou {00C40A}%d{FFFFFF} entrega(s)", BusinessInfo[idbusiness[playerid]][cID], BusinessInfo[idbusiness[playerid]][cEDeliveries1]);
                        }
                        else if(BusinessInfo[idbusiness[playerid]][cEmployee] == 2)
                        {
                            if(!strcmp(BusinessInfo[idbusiness[playerid]][cEmployee2], "N/A", true))
                                return ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FFD700}N/A", "{FFFFFF}Não tem nenhum funcionário!", "Fechar", #);

                            format(str_, sizeof(str_), "{FFD700}%s", BusinessInfo[idbusiness[playerid]][cEmployee2]);
                            format(String, sizeof(String), "{FFFFFF}Empresa ID {0080FF}%d \n\n{FFFFFF}O(A) Funcionário(a) já efetuou {00C40A}%d{FFFFFF} entrega(s)", BusinessInfo[idbusiness[playerid]][cID], BusinessInfo[idbusiness[playerid]][cEDeliveries2]);
                        }
                        else if(BusinessInfo[idbusiness[playerid]][cEmployee] == 3)
                        {
                            if(!strcmp(BusinessInfo[idbusiness[playerid]][cEmployee3], "N/A", true))
                                return ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FFD700}N/A", "{FFFFFF}Não tem nenhum funcionário!", "Fechar", #);

                            format(str_, sizeof(str_), "{FFD700}%s", BusinessInfo[idbusiness[playerid]][cEmployee3]);
                            format(String, sizeof(String), "{FFFFFF}Empresa ID {0080FF}%d \n\n{FFFFFF}O(A) Funcionário(a) já efetuou {00C40A}%d{FFFFFF} entrega(s)", BusinessInfo[idbusiness[playerid]][cID], BusinessInfo[idbusiness[playerid]][cEDeliveries3]);
                        }
                        else if(BusinessInfo[idbusiness[playerid]][cEmployee] == 4)
                        {
                            if(!strcmp(BusinessInfo[idbusiness[playerid]][cEmployee4], "N/A", true))
                                return ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FFD700}N/A", "{FFFFFF}Não tem nenhum funcionário!", "Fechar", #);

                            format(str_, sizeof(str_), "{FFD700}%s", BusinessInfo[idbusiness[playerid]][cEmployee4]);
                            format(String, sizeof(String), "{FFFFFF}Empresa ID {0080FF}%d \n\n{FFFFFF}O(A) Funcionário(a) já efetuou {00C40A}%d{FFFFFF} entrega(s)", BusinessInfo[idbusiness[playerid]][cID], BusinessInfo[idbusiness[playerid]][cEDeliveries4]);
                        }

                        ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, str_, String, "Continuar", "Cancelar");
                        return 1;
                    }
                    case 1:
                    {
                        if(BusinessInfo[idbusiness[playerid]][cEmployee] == 1)
                        {
                            if(strcmp(BusinessInfo[idbusiness[playerid]][cEmployee1], "N/A", true))
                                return SendClientMessage(playerid, Erro, "Essa vaga já tem um funcionário(a)");
                        }
                        else if(BusinessInfo[idbusiness[playerid]][cEmployee] == 2)
                        {
                            if(strcmp(BusinessInfo[idbusiness[playerid]][cEmployee2], "N/A", true))
                                return SendClientMessage(playerid, Erro, "Essa vaga já tem um funcionário(a)");
                        }
                        else if(BusinessInfo[idbusiness[playerid]][cEmployee] == 3)
                        {
                            if(strcmp(BusinessInfo[idbusiness[playerid]][cEmployee3], "N/A", true))
                                return SendClientMessage(playerid, Erro, "Essa vaga já tem um funcionário(a)");
                        }
                        else if(BusinessInfo[idbusiness[playerid]][cEmployee] == 4)
                        {
                            if(strcmp(BusinessInfo[idbusiness[playerid]][cEmployee4], "N/A", true))
                                return SendClientMessage(playerid, Erro, "Essa vaga já tem um funcionário(a)");
                        }

                        ShowPlayerDialog(playerid, MAIN_COMPANY_EMPLOYEE_INPUT, DIALOG_STYLE_INPUT, "{FFD700}Adicionar funcionário(a)", "{FFFFFF}Digite abaixo o {FF0000}id{FFFFFF} do jogador(a)\nque você quer colocar como funcionário(a)", "Continuar", "Cancelar");
                        return 1;
                    }
                    case 2:
                    {
                        if(BusinessInfo[idbusiness[playerid]][cEmployee] == 1)
                        {
                            if(!strcmp(BusinessInfo[idbusiness[playerid]][cEmployee1], "N/A", true))
                                return ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FFD700}N/A", "{FFFFFF}Não tem nenhum funcionário!", "Fechar", #);

                            format(String, sizeof(String), "O(A) funcionário(a) %s foi removido da sua empresa!", BusinessInfo[idbusiness[playerid]][cEmployee1]);
                            SendClientMessage(playerid, C_PROPERTY, String);
                            format(BusinessInfo[idbusiness[playerid]][cEmployee1], MAX_PLAYER_NAME, "N/A");
                        }
                        else if(BusinessInfo[idbusiness[playerid]][cEmployee] == 2)
                        {
                            if(!strcmp(BusinessInfo[idbusiness[playerid]][cEmployee2], "N/A", true))
                                return ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FFD700}N/A", "{FFFFFF}Não tem nenhum funcionário!", "Fechar", #);

                            format(String, sizeof(String), "O(A) funcionário(a) %s foi removido da sua empresa!", BusinessInfo[idbusiness[playerid]][cEmployee2]);
                            SendClientMessage(playerid, C_PROPERTY, String);
                            format(BusinessInfo[idbusiness[playerid]][cEmployee2], MAX_PLAYER_NAME, "N/A");
                        }
                        else if(BusinessInfo[idbusiness[playerid]][cEmployee] == 3)
                        {
                            if(!strcmp(BusinessInfo[idbusiness[playerid]][cEmployee3], "N/A", true))
                                return ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FFD700}N/A", "{FFFFFF}Não tem nenhum funcionário!", "Fechar", #);

                            format(String, sizeof(String), "O(A) funcionário(a) %s foi removido da sua empresa!", BusinessInfo[idbusiness[playerid]][cEmployee3]);
                            SendClientMessage(playerid, C_PROPERTY, String);
                            format(BusinessInfo[idbusiness[playerid]][cEmployee3], MAX_PLAYER_NAME, "N/A");
                        }
                        else if(BusinessInfo[idbusiness[playerid]][cEmployee] == 4)
                        {
                            if(!strcmp(BusinessInfo[idbusiness[playerid]][cEmployee4], "N/A", true))
                                return ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FFD700}N/A", "{FFFFFF}Não tem nenhum funcionário!", "Fechar", #);

                            format(String, sizeof(String), "O(A) funcionário(a) %s foi removido da sua empresa!", BusinessInfo[idbusiness[playerid]][cEmployee4]);
                            SendClientMessage(playerid, C_PROPERTY, String);
                            format(BusinessInfo[idbusiness[playerid]][cEmployee4], MAX_PLAYER_NAME, "N/A");
                        }
                        UpdateCompanys(idbusiness[playerid]);
                        return 1;
                    }
                }
            }
            return 1;
        }
        case MAIN_COMPANY_EMPLOYEE_INPUT:
        {
            if(response)
            {
                new _str[300], id = strval(inputtext);

                if(id < 0 || id >= MAX_PLAYERS)
                    return ShowPlayerDialog(playerid, MAIN_COMPANY_EMPLOYEE_INPUT, DIALOG_STYLE_INPUT, "{FFD700}Adicionar funcionário(a)", "{FFFFFF}Digite abaixo o {FF0000}id{FFFFFF} do jogador(a)\nque você quer colocar como funcionário(a)\n{FF4000}Jogador(a) não conectado(a)!", "Continuar", "Cancelar");

                if(PlayerInfo[id][Logado] == false)
                    return ShowPlayerDialog(playerid, MAIN_COMPANY_EMPLOYEE_INPUT, DIALOG_STYLE_INPUT, "{FFD700}Adicionar funcionário(a)", "{FFFFFF}Digite abaixo o {FF0000}id{FFFFFF} do jogador(a)\nque você quer colocar como funcionário(a)\n{FF4000}Jogador(a) não conectado(a)!", "Continuar", "Cancelar");

                if(id == playerid)
                    return ShowPlayerDialog(playerid, MAIN_COMPANY_EMPLOYEE_INPUT, DIALOG_STYLE_INPUT, "{FFD700}Adicionar funcionário(a)", "{FFFFFF}Digite abaixo o {FF0000}id{FFFFFF} do jogador(a)\nque você quer colocar como funcionário(a)\n{FF4000}Não pode colocar você como funcionário(a)!", "Continuar", "Cancelar");

                mysql_format(IDConexao, _str, sizeof(_str), "SELECT `Nome` FROM `Business` WHERE `Nome`='%e'", PlayerInfo[id][Nome]);
                mysql_query(IDConexao, _str);

                if(cache_num_rows() > 0)
                    return SendClientMessage(playerid, Erro, "O(A) Jogador(a) já tem uma empresa");

                mysql_format(IDConexao, _str, sizeof(_str), "SELECT `Func1` AND `Func2` AND `Func3` AND `Func4` FROM `Business` WHERE `Func1`='%e' OR `Func2`='%e' OR `Func3`='%e' OR `Func4`='%e'", PlayerInfo[id][Nome], PlayerInfo[id][Nome], PlayerInfo[id][Nome], PlayerInfo[id][Nome]);
                mysql_query(IDConexao, _str);

                if(cache_num_rows() > 0)
                    return SendClientMessage(playerid, Erro, "O(A) Jogador(a) já está de funcionário(a) em uma empresa");

                if(!IsPlayerInRangeOfPoint(id, 50.0, BusinessInfo[idbusiness[playerid]][cInteriorX], BusinessInfo[idbusiness[playerid]][cInteriorY], BusinessInfo[idbusiness[playerid]][cInteriorZ]))
                    return SendClientMessage(playerid, Erro, "O(A) Jogador(a) não está dentro da sua empresa");

                if(BusinessInfo[idbusiness[playerid]][cEmployee] == 1)
                {
                    format(BusinessInfo[idbusiness[playerid]][cEmployee1], MAX_PLAYER_NAME, PlayerInfo[id][Nome]);
                    format(String, sizeof(String), "Você colocou o jogador(a) %s para trabalhar em sua empresa!", BusinessInfo[idbusiness[playerid]][cEmployee1]);
                    SendClientMessage(playerid, C_PROPERTY, String);
                    format(String, sizeof(String), "O(A) Jogador(a) %s te colocou para prestar serviços para a empresa ID %d!", BusinessInfo[idbusiness[playerid]][cName], BusinessInfo[idbusiness[playerid]][cID]);
                    SendClientMessage(id, C_PROPERTY, String);
                }
                else if(BusinessInfo[idbusiness[playerid]][cEmployee] == 2)
                {
                    format(BusinessInfo[idbusiness[playerid]][cEmployee2], MAX_PLAYER_NAME, PlayerInfo[id][Nome]);
                    format(String, sizeof(String), "Você colocou o jogador(a) %s para trabalhar em sua empresa!", BusinessInfo[idbusiness[playerid]][cEmployee2]);
                    SendClientMessage(playerid, C_PROPERTY, String);
                    format(String, sizeof(String), "O(A) Jogador(a) %s te colocou para prestar serviços para a empresa ID %d!", BusinessInfo[idbusiness[playerid]][cName], BusinessInfo[idbusiness[playerid]][cID]);
                    SendClientMessage(id, C_PROPERTY, String);
                }
                else if(BusinessInfo[idbusiness[playerid]][cEmployee] == 3)
                {
                    format(BusinessInfo[idbusiness[playerid]][cEmployee3], MAX_PLAYER_NAME, PlayerInfo[id][Nome]);
                    format(String, sizeof(String), "Você colocou o jogador(a) %s para trabalhar em sua empresa!", BusinessInfo[idbusiness[playerid]][cEmployee3]);
                    SendClientMessage(playerid, C_PROPERTY, String);
                    format(String, sizeof(String), "O(A) Jogador(a) %s te colocou para prestar serviços para a empresa ID %d!", BusinessInfo[idbusiness[playerid]][cName], BusinessInfo[idbusiness[playerid]][cID]);
                    SendClientMessage(id, C_PROPERTY, String);
                }
                else if(BusinessInfo[idbusiness[playerid]][cEmployee] == 4)
                {
                    format(BusinessInfo[idbusiness[playerid]][cEmployee4], MAX_PLAYER_NAME, PlayerInfo[id][Nome]);
                    format(String, sizeof(String), "Você colocou o jogador(a) %s para trabalhar em sua empresa!", BusinessInfo[idbusiness[playerid]][cEmployee4]);
                    SendClientMessage(playerid, C_PROPERTY, String);
                    format(String, sizeof(String), "O(A) Jogador(a) %s te colocou para prestar serviços para a empresa ID %d!", BusinessInfo[idbusiness[playerid]][cName], BusinessInfo[idbusiness[playerid]][cID]);
                    SendClientMessage(id, C_PROPERTY, String);
                }

                UpdateCompanys(idbusiness[playerid]);
            }
            return 1;
        }
    }
    return 1;
}


hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_SECONDARY_ATTACK)
    {
        if(withinbusiness[playerid] == 0 && IsPlayerInRangeOfPoint(playerid, 1.5, BusinessInfo[idbusiness[playerid]][cIconX], BusinessInfo[idbusiness[playerid]][cIconY], BusinessInfo[idbusiness[playerid]][cIconZ]))
        {
            if(strcmp(BusinessInfo[idbusiness[playerid]][cName], PlayerInfo[playerid][Nome], true)==0)
            {
                format(String, sizeof(String), "Bem vindo(a) a sua Empresa ID %d, Digite: /MenuEmpresa para acessar o menu!", BusinessInfo[idbusiness[playerid]][cID]);
            }
            else
            {
                format(String, sizeof(String), "Bem vindo(a) a Empresa ID %d que pertence a %s", BusinessInfo[idbusiness[playerid]][cID], BusinessInfo[idbusiness[playerid]][cName]);
            }

            withinbusiness[playerid] = 1;
            SendClientMessage(playerid, C_PROPERTY, String);
            SetPlayerInterior(playerid, BusinessInfo[idbusiness[playerid]][cInterior]);
            SetPlayerPos(playerid, BusinessInfo[idbusiness[playerid]][cInteriorX], BusinessInfo[idbusiness[playerid]][cInteriorY], BusinessInfo[idbusiness[playerid]][cInteriorZ]);
            return 1;
        }
        else if(withinbusiness[playerid] == 1 && IsPlayerInRangeOfPoint(playerid, 2.0, BusinessInfo[idbusiness[playerid]][cInteriorX], BusinessInfo[idbusiness[playerid]][cInteriorY], BusinessInfo[idbusiness[playerid]][cInteriorZ]))
        {
            if(strcmp(BusinessInfo[idbusiness[playerid]][cName], PlayerInfo[playerid][Nome], true)==0)
            {
                format(String, sizeof(String), "Você saiu da sua empresa %s", BusinessInfo[idbusiness[playerid]][cName]);
            }
            else
            {
                format(String, sizeof(String), "Você saiu da empresa que pertence a %s", BusinessInfo[idbusiness[playerid]][cName]);
            }
            withinbusiness[playerid] = 0;
            SendClientMessage(playerid, C_PROPERTY, String);
            SetPlayerInterior(playerid, 0);
            SetPlayerPos(playerid, BusinessInfo[idbusiness[playerid]][cIconX], BusinessInfo[idbusiness[playerid]][cIconY], BusinessInfo[idbusiness[playerid]][cIconZ]);
            return 1;
        }
    }
    return 1;
}

LoadCompany()
{
    new query[100];
    for(new businessid = 1; businessid < MAX_BUSINESS; ++businessid)
    {
        mysql_format(IDConexao, query, sizeof(query), "SELECT * FROM `Business` WHERE `ID`='%d'", businessid);
        mysql_tquery(IDConexao, query, "LoadBusiness", "d", businessid);
    }
    return 1;
}

forward CreateComapany(playerid, companyicon, cost, standard, Float:cix, Float:ciy, Float:ciz);
public CreateComapany(playerid, companyicon, cost, standard, Float:cix, Float:ciy, Float:ciz)
{
    new businessid = cache_insert_id();

    BusinessInfo[businessid][cID] = businessid;
    format(BusinessInfo[businessid][cName], MAX_PLAYER_NAME, "N/A");
    format(BusinessInfo[businessid][cEmployee1], MAX_PLAYER_NAME, "N/A");
    format(BusinessInfo[businessid][cEmployee2], MAX_PLAYER_NAME, "N/A");
    format(BusinessInfo[businessid][cEmployee3], MAX_PLAYER_NAME, "N/A");
    format(BusinessInfo[businessid][cEmployee4], MAX_PLAYER_NAME, "N/A");

    BusinessInfo[businessid][cDeliveries] = 0;
    BusinessInfo[businessid][cEDeliveries1] = 0;
    BusinessInfo[businessid][cEDeliveries2] = 0;
    BusinessInfo[businessid][cEDeliveries3] = 0;
    BusinessInfo[businessid][cEDeliveries4] = 0;

    format(BusinessInfo[businessid][cMessage], 30, "N/A");

    BusinessInfo[businessid][cCost] = cost;
    BusinessInfo[businessid][cStandard] = standard;
    BusinessInfo[businessid][cIcon] = companyicon;
    BusinessInfo[businessid][cIconX] = cix;
    BusinessInfo[businessid][cIconY] = ciy;
    BusinessInfo[businessid][cIconZ] = ciz;

    GetPlayer2DZone(zone, MAX_ZONE_NAME, BusinessInfo[businessid][cIconX], BusinessInfo[businessid][cIconY]);
    format(String, sizeof(String), "| VRC-Admin | O(A) %s %s criou a Empresa ID %d localizada em %s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], BusinessInfo[businessid][cID], zone);
    SendClientMessageToAll(adm, String);

    CreateCompanyExternal(businessid);
    return 1;
}

forward LoadBusiness(businessid);
public LoadBusiness(businessid)
{
    if(cache_num_rows() != 0)
    {
        new tmp[128];

        cache_get_value_int(0, "ID", BusinessInfo[businessid][cID]);

        cache_get_value_name(0, "Nome", tmp); format(BusinessInfo[businessid][cName], MAX_PLAYER_NAME, tmp);
        cache_get_value_name(0, "Status", tmp); format(BusinessInfo[businessid][cStatus], 30, tmp);
        cache_get_value_name(0, "Mensagem", tmp); format(BusinessInfo[businessid][cMessage], 30, tmp);
        cache_get_value_name(0, "Vendendo", tmp); format(BusinessInfo[businessid][cSelling], 5, tmp);

        cache_get_value_name(0, "Func1", tmp); format(BusinessInfo[businessid][cEmployee1], MAX_PLAYER_NAME, tmp);
        cache_get_value_name(0, "Func2", tmp); format(BusinessInfo[businessid][cEmployee2], MAX_PLAYER_NAME, tmp);
        cache_get_value_name(0, "Func3", tmp); format(BusinessInfo[businessid][cEmployee3], MAX_PLAYER_NAME, tmp);
        cache_get_value_name(0, "Func4", tmp); format(BusinessInfo[businessid][cEmployee4], MAX_PLAYER_NAME, tmp);

        cache_get_value_int(0, "Entregas", BusinessInfo[businessid][cDeliveries]);
        cache_get_value_int(0, "Func1Entregas", BusinessInfo[businessid][cEDeliveries1]);
        cache_get_value_int(0, "Func2Entregas", BusinessInfo[businessid][cEDeliveries2]);
        cache_get_value_int(0, "Func3Entregas", BusinessInfo[businessid][cEDeliveries3]);
        cache_get_value_int(0, "Func4Entregas", BusinessInfo[businessid][cEDeliveries4]);

        cache_get_value_int(0, "Preco", BusinessInfo[businessid][cPrice]);
        cache_get_value_int(0, "Custo", BusinessInfo[businessid][cCost]);
        cache_get_value_int(0, "Padrao", BusinessInfo[businessid][cStandard]);
        cache_get_value_int(0, "Cofre", BusinessInfo[businessid][cSafe]);
        cache_get_value_int(0, "Interior", BusinessInfo[businessid][cInterior]);
        cache_get_value_int(0, "Icon", BusinessInfo[businessid][cIcon]);
        cache_get_value_int(0, "Producao", BusinessInfo[businessid][cProduction]);

        cache_get_value_float(0, "X", BusinessInfo[businessid][cIconX]);
        cache_get_value_float(0, "Y", BusinessInfo[businessid][cIconY]);
        cache_get_value_float(0, "Z", BusinessInfo[businessid][cIconZ]);

        cache_get_value_float(0, "InteriorX", BusinessInfo[businessid][cInteriorX]);
        cache_get_value_float(0, "InteriorY", BusinessInfo[businessid][cInteriorY]);
        cache_get_value_float(0, "InteriorZ", BusinessInfo[businessid][cInteriorZ]);

        CreateCompanyExternal(businessid);
    }
    return 1;
}

stock UpdateCompanyExternal(businessid)
{
    DestroyDynamicMapIcon(CompanyMapIcon[businessid]);
    DestroyDynamicPickup(CompanyPickup[businessid]);

    if(strcmp(BusinessInfo[businessid][cName], "N/A", true)==0 && strcmp(BusinessInfo[businessid][cSelling], "Sim", true)==0) //Liberada
    {
        CompanyPickup[businessid] = CreateDynamicPickup(19606, 23, BusinessInfo[businessid][cIconX], BusinessInfo[businessid][cIconY], BusinessInfo[businessid][cIconZ], 0, -1, -1, 100.0);
        CompanyMapIcon[businessid] = CreateDynamicMapIcon(BusinessInfo[businessid][cIconX], BusinessInfo[businessid][cIconY], BusinessInfo[businessid][cIconZ], BusinessInfo[businessid][cIcon], -1, 0, -1, -1, 50.0);
        format(String, sizeof(String), "{31B404}Empresa a Venda ( ID:%d )\n{FFFFFF}%s\n{CE9F01}Valor: {31B404}$%s\n{6495ED}/ComprarEmpresa", BusinessInfo[businessid][cID], BusinessInfo[businessid][cStatus], IsMoney(BusinessInfo[businessid][cCost], "."));
        UpdateDynamic3DTextLabelText(CompanyLabel[businessid], 0xFFFFFFFF, String);

    }
    else if(strcmp(BusinessInfo[businessid][cName], "N/A", true) && strcmp(BusinessInfo[businessid][cSelling], "N/A", true)==0) //Dono não vende
    {
        CompanyPickup[businessid] = CreateDynamicPickup(19605, 23, BusinessInfo[businessid][cIconX], BusinessInfo[businessid][cIconY], BusinessInfo[businessid][cIconZ], 0, -1, -1, 100.0);
        CompanyMapIcon[businessid] = CreateDynamicMapIcon(BusinessInfo[businessid][cIconX], BusinessInfo[businessid][cIconY], BusinessInfo[businessid][cIconZ], BusinessInfo[businessid][cIcon], -1, 0, -1, -1, 50.0);
        format(String, sizeof(String), "{FFD700}Empresa de %s ( ID:%d )\n{FFFFFF}%s\n{FFFFFF}%s\n{31B404}Produção: {FFFFFF}%d\n{6495ED}/EntrarEmpresa", BusinessInfo[businessid][cName], BusinessInfo[businessid][cID], BusinessInfo[businessid][cMessage], BusinessInfo[businessid][cStatus], BusinessInfo[businessid][cProduction]);
        UpdateDynamic3DTextLabelText(CompanyLabel[businessid], 0xFFFFFFFF, String);
    }
    else if(strcmp(BusinessInfo[businessid][cName], "N/A", true) && strcmp(BusinessInfo[businessid][cSelling], "Sim", true)==0) // Dono vendendo
    {
        CompanyPickup[businessid] = CreateDynamicPickup(19607, 23, BusinessInfo[businessid][cIconX], BusinessInfo[businessid][cIconY], BusinessInfo[businessid][cIconZ], 0, -1, -1, 100.0);
        CompanyMapIcon[businessid] = CreateDynamicMapIcon(BusinessInfo[businessid][cIconX], BusinessInfo[businessid][cIconY], BusinessInfo[businessid][cIconZ], BusinessInfo[businessid][cIcon], -1, 0, -1, -1, 50.0);
        format(String, sizeof(String), "{FFD700}Empresa de %s ( ID:%d )\n{FFFFFF}%s\n{FFFFFF}%s\n{FFFFFF}O(A) proprietário(a) está vendendo a empresa por {019303}$%s\n{31B404}Produção: {FFFFFF}%d\n{6495ED}/ComprarEmpresa", BusinessInfo[businessid][cName], BusinessInfo[businessid][cID], BusinessInfo[businessid][cMessage], BusinessInfo[businessid][cStatus], IsMoney(BusinessInfo[businessid][cPrice], "."), BusinessInfo[businessid][cProduction]);
        UpdateDynamic3DTextLabelText(CompanyLabel[businessid], 0xFFFFFFFF, String);
    }
    return 1;
}

stock CreateCompanyExternal(businessid)
{
    if(strcmp(BusinessInfo[businessid][cName], "N/A", true)==0 && strcmp(BusinessInfo[businessid][cSelling], "Sim", true)==0) //Liberada
    {
        CompanyPickup[businessid] = CreateDynamicPickup(19606, 23, BusinessInfo[businessid][cIconX], BusinessInfo[businessid][cIconY], BusinessInfo[businessid][cIconZ], 0, -1, -1, 100.0);
        CompanyMapIcon[businessid] = CreateDynamicMapIcon(BusinessInfo[businessid][cIconX], BusinessInfo[businessid][cIconY], BusinessInfo[businessid][cIconZ], BusinessInfo[businessid][cIcon], -1, 0, -1, -1, 50.0);
        format(String, sizeof(String), "{31B404}Empresa a Venda ( ID:%d )\n{FFFFFF}%s\n{CE9F01}Valor: {31B404}$%s\n{6495ED}/ComprarEmpresa", BusinessInfo[businessid][cID], BusinessInfo[businessid][cStatus], IsMoney(BusinessInfo[businessid][cCost], "."));
        CompanyLabel[businessid] =  CreateDynamic3DTextLabel(String, 0xFFFFFFFF, BusinessInfo[businessid][cIconX], BusinessInfo[businessid][cIconY], BusinessInfo[businessid][cIconZ]+0.50, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, -1, -1, 20.0, -1, 0);
    }
    else if(strcmp(BusinessInfo[businessid][cName], "N/A", true) && strcmp(BusinessInfo[businessid][cSelling], "N/A", true)==0) //Dono não vende
    {
        CompanyPickup[businessid] = CreateDynamicPickup(19605, 23, BusinessInfo[businessid][cIconX], BusinessInfo[businessid][cIconY], BusinessInfo[businessid][cIconZ], 0, -1, -1, 100.0);
        CompanyMapIcon[businessid] = CreateDynamicMapIcon(BusinessInfo[businessid][cIconX], BusinessInfo[businessid][cIconY], BusinessInfo[businessid][cIconZ], BusinessInfo[businessid][cIcon], -1, 0, -1, -1, 50.0);
        format(String, sizeof(String), "{FFD700}Empresa de %s ( ID:%d )\n{FFFFFF}%s\n{FFFFFF}%s\n{31B404}Produção: {FFFFFF}%d\n{6495ED}/EntrarEmpresa", BusinessInfo[businessid][cName], BusinessInfo[businessid][cID], BusinessInfo[businessid][cMessage], BusinessInfo[businessid][cStatus], BusinessInfo[businessid][cProduction]);
        CompanyLabel[businessid] =  CreateDynamic3DTextLabel(String, 0xFFFFFFFF, BusinessInfo[businessid][cIconX], BusinessInfo[businessid][cIconY], BusinessInfo[businessid][cIconZ]+0.50, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, -1, -1, 20.0, -1, 0);
    }
    else if(strcmp(BusinessInfo[businessid][cName], "N/A", true) && strcmp(BusinessInfo[businessid][cSelling], "Sim", true)==0) // Dono vendendo
    {
        CompanyPickup[businessid] = CreateDynamicPickup(19607, 23, BusinessInfo[businessid][cIconX], BusinessInfo[businessid][cIconY], BusinessInfo[businessid][cIconZ], 0, -1, -1, 100.0);
        CompanyMapIcon[businessid] = CreateDynamicMapIcon(BusinessInfo[businessid][cIconX], BusinessInfo[businessid][cIconY], BusinessInfo[businessid][cIconZ], BusinessInfo[businessid][cIcon], -1, 0, -1, -1, 50.0);
        format(String, sizeof(String), "{FFD700}Empresa de %s ( ID:%d )\n{FFFFFF}%s\n{FFFFFF}%s\n{FFFFFF}O(A) proprietário(a) está vendendo a empresa por {019303}$%s\n{31B404}Produção: {FFFFFF}%d\n{6495ED}/ComprarEmpresa", BusinessInfo[businessid][cName], BusinessInfo[businessid][cID], BusinessInfo[businessid][cMessage], BusinessInfo[businessid][cStatus], IsMoney(BusinessInfo[businessid][cPrice], "."), BusinessInfo[businessid][cProduction]);
        CompanyLabel[businessid] = CreateDynamic3DTextLabel(String, 0xFFFFFFFF, BusinessInfo[businessid][cIconX], BusinessInfo[businessid][cIconY], BusinessInfo[businessid][cIconZ]+0.50, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, -1, -1, 20.0, -1, 0);
    }
    return 1;
}

stock UpdateCompanys(businessid)
{
    new Query[3000];
    mysql_format(IDConexao, Query, sizeof(Query), "UPDATE `Business` SET `Nome`='%e', `Func1`='%e',`Func2`='%e',`Func3`='%e',`Func4`='%e', `Entregas`='%d', `Func1Entregas`='%d', `Func2Entregas`='%d', `Func3Entregas`='%d', `Func4Entregas`='%d', `Status`='%e', `Mensagem`='%e', `Vendendo`='%e', `Preco`='%d', `Custo`='%d', `Padrao`='%d', `Cofre`='%d', `Interior`='%d', `Icon`='%d', `Producao`='%d', `X`='%f', `Y`='%f', `Z`='%f', `InteriorX`='%f', `InteriorY`='%f', `InteriorZ`='%f' WHERE `ID`='%d'",
    BusinessInfo[businessid][cName],
    BusinessInfo[businessid][cEmployee1],
    BusinessInfo[businessid][cEmployee2],
    BusinessInfo[businessid][cEmployee3],
    BusinessInfo[businessid][cEmployee4],
    BusinessInfo[businessid][cDeliveries],
    BusinessInfo[businessid][cEDeliveries1],
    BusinessInfo[businessid][cEDeliveries2],
    BusinessInfo[businessid][cEDeliveries3],
    BusinessInfo[businessid][cEDeliveries4],
    BusinessInfo[businessid][cStatus],
    BusinessInfo[businessid][cMessage],
    BusinessInfo[businessid][cSelling],
    BusinessInfo[businessid][cPrice],
    BusinessInfo[businessid][cCost],
    BusinessInfo[businessid][cStandard],
    BusinessInfo[businessid][cSafe],
    BusinessInfo[businessid][cInterior],
    BusinessInfo[businessid][cIcon],
    BusinessInfo[businessid][cProduction],
    BusinessInfo[businessid][cIconX],
    BusinessInfo[businessid][cIconY],
    BusinessInfo[businessid][cIconZ],
    BusinessInfo[businessid][cInteriorX],
    BusinessInfo[businessid][cInteriorY],
    BusinessInfo[businessid][cInteriorZ],
    BusinessInfo[businessid][cID]);
    mysql_query(IDConexao, Query);
    return 1;
}

stock GetCompanyID(playerid, pickupid)
{
    for(new i=1; i < MAX_BUSINESS; i++)
    {
        if(pickupid == CompanyPickup[i] && IsPlayerInRangeOfPoint(playerid, 1.5, BusinessInfo[i][cIconX], BusinessInfo[i][cIconY], BusinessInfo[i][cIconZ]))
        {
            SendClientMessage(playerid, -1, "Para entrar na empresa digite {CFCDCD}'/EntrarEmpresa'{FFFFFF} ou pressione a tecla {CFCDCD}'F'");
            return idbusiness[playerid] = i;
        }
    }
    return false;
}

stock AddComponentStore(playerid, str[], value, businessid)
{
    ApplyAnimation(playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0);

    if(strcmp(BusinessInfo[businessid][cName], "N/A"))
    {
        BusinessInfo[businessid][cSafe] += value;
    }

    PlayerInfo[playerid][Health] += 20.0;
    UpdatePlayerHealth(playerid);

    PlayerInfo[playerid][Dinheiro] -= value;
    UpdatePlayerMoney(playerid);

    format(String, MAX_STRING, "Você comprou um(a) %s por $%d", str, value);
    SendClientMessage(playerid, Green, String);

    UpdateProgressBar(playerid);
    return 1;
}

stock LeftBusiness(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 50.0, BusinessInfo[idbusiness[playerid]][cInteriorX], BusinessInfo[idbusiness[playerid]][cInteriorY], BusinessInfo[idbusiness[playerid]][cInteriorZ]))
    {
        PlayerInfo[playerid][PosX] = BusinessInfo[idbusiness[playerid]][cIconX];
        PlayerInfo[playerid][PosY] = BusinessInfo[idbusiness[playerid]][cIconY];
        PlayerInfo[playerid][PosZ] = BusinessInfo[idbusiness[playerid]][cIconZ];
        PlayerInfo[playerid][PosA] = 0.0;
    }
    return 1;
}

stock ReleaseBusiness(businessid)
{
    format(BusinessInfo[businessid][cName], MAX_PLAYER_NAME, "N/A");
    format(BusinessInfo[businessid][cEmployee1], MAX_PLAYER_NAME, "N/A");
    format(BusinessInfo[businessid][cEmployee2], MAX_PLAYER_NAME, "N/A");
    format(BusinessInfo[businessid][cEmployee3], MAX_PLAYER_NAME, "N/A");
    format(BusinessInfo[businessid][cEmployee4], MAX_PLAYER_NAME, "N/A");

    BusinessInfo[businessid][cDeliveries] = 0;
    BusinessInfo[businessid][cEDeliveries1] = 0;
    BusinessInfo[businessid][cEDeliveries2] = 0;
    BusinessInfo[businessid][cEDeliveries3] = 0;
    BusinessInfo[businessid][cEDeliveries4] = 0;

    format(BusinessInfo[businessid][cMessage], 30, "N/A");
    format(BusinessInfo[businessid][cSelling], 5, "Sim");

    BusinessInfo[businessid][cPrice] = 0;
    BusinessInfo[businessid][cSafe] = 0;
    BusinessInfo[businessid][cProduction] = 0;

    UpdateCompanys(businessid);
    UpdateCompanyExternal(businessid);
    return 1;
}

stock GivePlayerWeaponBussines(playerid, businessid, weaponid, ammun, value)
{
    if(PlayerInfo[playerid][Dinheiro] < value)
        return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

    if(strcmp(BusinessInfo[businessid][cName], "N/A")) BusinessInfo[businessid][cSafe] += value;

    new weaponName[32];

    GetWeaponName(weaponid, weaponName, sizeof(weaponName));

    PlayerInfo[playerid][Dinheiro] -= value;
    GivePlayerWeapon(playerid, weaponid, ammun);
    UpdatePlayerMoney(playerid);

    format(String, MAX_STRING, "Você comprou uma %s de %d balas", weaponName, ammun);
    SendClientMessage(playerid, Green, String);
    return 1;
}

/******************************************************************************/
/****************************| COMMANDS BUSINESS |*****************************/
/******************************************************************************/

CMD:skins(playerid)
{
    if(!IsPlayerInDynamicCP(playerid, CPS_StoreSkins[0]))
        return SendClientMessage(playerid, Erro, "Você não está no checkpoint da loja de skins");

    SetPlayerFacingAngle(playerid, 200.0);
	SetPlayerPos(playerid, 217.3514, -98.5038, 1005.2578);
    InterpolateCameraPos(playerid, 218.7567, -100.4921, 1007.0745, 216.2148, -100.3599, 1006.1741, 3000);
    InterpolateCameraLookAt(playerid, 218.1502, -99.6990, 1006.2838, 216.7630, -99.5255, 1005.7477, 3000);

    ShowTDPlayerSkinsStore(playerid);
    return 1;
}
CMD:menuempresa(playerid)
{
    new txt[2000];

    if(withinbusiness[playerid] != 1)
        return SendClientMessage(playerid, Erro, "Você não está em uma empresa");

    if(!strcmp(PlayerInfo[playerid][Nome], BusinessInfo[idbusiness[playerid]][cName], true) ||
        !strcmp(PlayerInfo[playerid][Nome], BusinessInfo[idbusiness[playerid]][cEmployee1], true) ||
        !strcmp(PlayerInfo[playerid][Nome], BusinessInfo[idbusiness[playerid]][cEmployee2], true) ||
        !strcmp(PlayerInfo[playerid][Nome], BusinessInfo[idbusiness[playerid]][cEmployee3], true) ||
        !strcmp(PlayerInfo[playerid][Nome], BusinessInfo[idbusiness[playerid]][cEmployee4], true) )
    {
        strcat(txt, "{FF0000}Funções \t\t {1CEB00}Status \n");



        if(!strcmp(PlayerInfo[playerid][Nome], BusinessInfo[idbusiness[playerid]][cName], true))
        {
            format(String, sizeof(String), "{FFFFFF}Mensagem \t\t %s\n", BusinessInfo[idbusiness[playerid]][cMessage]);
            strcat(txt, String);
            format(String, sizeof(String), "{FFFFFF}Funcionário 1 \t\t {FF0000}%s \n", BusinessInfo[idbusiness[playerid]][cEmployee1]);
            strcat(txt, String);
            format(String, sizeof(String), "{FFFFFF}Funcionário 2 \t\t {FF0000}%s \n", BusinessInfo[idbusiness[playerid]][cEmployee2]);
            strcat(txt, String);
            format(String, sizeof(String), "{FFFFFF}Funcionário 3 \t\t {FF0000}%s \n", BusinessInfo[idbusiness[playerid]][cEmployee3]);
            strcat(txt, String);
            format(String, sizeof(String), "{FFFFFF}Funcionário 4 \t\t {FF0000}%s \n", BusinessInfo[idbusiness[playerid]][cEmployee4]);
            strcat(txt, String);
            format(String, sizeof(String), "{FFFFFF}Entregar/Mercadoria(s) \t\t {2CC06B}%d \n", BusinessInfo[idbusiness[playerid]][cDeliveries]);
            strcat(txt, String);
            format(String, sizeof(String), "{FFFFFF}Cofre \t\t {2CC06B}$%s\n", IsMoney(BusinessInfo[idbusiness[playerid]][cSafe], "."));
            strcat(txt, String);
            format(String, sizeof(String), "{FFFFFF}Vender Empresa \t\t {2CC06B}$%s\n", IsMoney(BusinessInfo[idbusiness[playerid]][cPrice], "."));
            strcat(txt, String);
            format(String, sizeof(String), "{FFFFFF}Liberar Empresa \t\t {2CC06B}$%s\n", IsMoney(BusinessInfo[idbusiness[playerid]][cStandard], "."));
            strcat(txt, String);
            ShowPlayerDialog(playerid, MAIN_COMPANY, DIALOG_STYLE_TABLIST_HEADERS, "{FFD700}Menu Empresa", txt, "Continuar", "Cancelar");
        }
        else if(!strcmp(PlayerInfo[playerid][Nome], BusinessInfo[idbusiness[playerid]][cEmployee1], true) || !strcmp(PlayerInfo[playerid][Nome], BusinessInfo[idbusiness[playerid]][cEmployee2], true) || !strcmp(PlayerInfo[playerid][Nome], BusinessInfo[idbusiness[playerid]][cEmployee3], true) || !strcmp(PlayerInfo[playerid][Nome], BusinessInfo[idbusiness[playerid]][cEmployee4], true) )
        {
            ShowPlayerDialog(playerid, MAIN_COMPANY, DIALOG_STYLE_LIST, "{FFD700}Menu Empresa", "{FFFFFF}Entregar Mercadoria\nVer Mercadorias Entregues\nPedir demissão\n", "Continuar", "Cancelar");
        }
    }
    else
    {
        SendClientMessage(playerid, Erro, "Você não é dono(a)/funcionário(a) dessa empresa");
    }
    return 1;
}
CMD:salvarempresas(playerid)
{
    for(new id = 1; id < MAX_BUSINESS; id++)
    {
        GetPlayer2DZone(zone, MAX_ZONE_NAME, BusinessInfo[id][cIconX], BusinessInfo[id][cIconY]);
        format(String, 128, "| VRC-Admin | O(A) %s %s[%d] salvou a empresa ID:%d localizada em %s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid, id, zone);
        SendClientMessageToAll(adm, String);

        UpdateCompanys(id);
        UpdateCompanyExternal(id);
    }
    return 1;
}
/*
CMD:editarempresa(playerid)
{
    new tmp[128], tmp1[128], tmp2[128], tmp3[128], tmp4[128], id, icon, cost, standard;

    tmp = strtok(cmdtext, idx);
    tmp1 = strtok(cmdtext, idx);
    tmp2 = strtok(cmdtext, idx);
    tmp3 = strtok(cmdtext, idx);
    tmp4 = strrest(cmdtext, idx);

    if(!strlen(tmp) || !strlen(tmp1) || !strlen(tmp2) || !strlen(tmp3) || !strlen(tmp4))
        return SendClientMessage(playerid, Erro, "Digite: /EditarEmpresa [id-empresa] [id-icone] [custo] [padrão] [status]");

    id = strval(tmp);
    icon = strval(tmp1);
    cost = strval(tmp2);
    standard = strval(tmp3);

    BusinessInfo[id][cIcon] = icon;
    BusinessInfo[id][cCost] = cost;
    BusinessInfo[id][cStandard] = standard;
    format(BusinessInfo[id][cStatus], 30, tmp4);

    GetPlayer2DZone(zone, MAX_ZONE_NAME, BusinessInfo[id][cIconX], BusinessInfo[id][cIconY]);
    format(String, 128, "| VRC-Admin | O(A) %s %s[%d] editou a empresa ID %d localizada em %s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid, id, zone);
    SendClientMessageToAll(adm, String);

    UpdateCompanys(id);
    UpdateCompanyExternal(id);
    return 1;
}
*/
CMD:irempresa(playerid, params[])
{
    if(!IsPlayerHelper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new id;

    if(sscanf(params, "d", id))
        return SendClientMessage(playerid, Erro, "Digite: /IrEmpresa [id-empresa]");

    if(id < 1 || id >= MAX_BUSINESS)
        return SendClientMessage(playerid, Erro, "Esse ID de Empresa não existe");

    SetPlayerInterior(playerid, 0);
    SetPlayerPos(playerid, BusinessInfo[id][cIconX], BusinessInfo[id][cIconY], BusinessInfo[id][cIconZ]);
    format(String, sizeof(String), "| VRC-Admin | Você se teletransportou para a Empresa ID %d", id);
    SendClientMessage(playerid, adm, String);
    return 1;
}
CMD:criarempresa(playerid)
{
    if(!IsPlayerDeveloper(playerid))
		return SendClientMessage(playerid, Erro, "Comando Inválido");

    ShowPlayerDialog(playerid, CREATE_COMPANY, DIALOG_STYLE_LIST, "{FF0000}Criar Empresa", "{FFFFFF}Cabaré\nSexshop\nBurger Shot\nBar\nUtilitários\nRestaurante\nCassino Caligulas\nHotel\nAmmunation\nLoja de Skins\nBarbearia\nTatto\nAcademia\nCluckin' Bell\nWell Stacked Pizza Co", "Criar", "Cancelar");
    return 1;
}
CMD:entrarempresa(playerid)
{
    if(withinbusiness[playerid] == 1)
        return SendClientMessage(playerid, Erro, "Você já está em uma empresa");

    if(!IsPlayerInRangeOfPoint(playerid, 1.5, BusinessInfo[idbusiness[playerid]][cIconX], BusinessInfo[idbusiness[playerid]][cIconY], BusinessInfo[idbusiness[playerid]][cIconZ]))
        return SendClientMessage(playerid, Erro, "Você não está em nenhuma porta de empresa");

    if(!strcmp(BusinessInfo[idbusiness[playerid]][cName], PlayerInfo[playerid][Nome], true))
    {
        format(String, sizeof(String), "Bem vindo(a) a sua Empresa ID %d, Digite: /MenuEmpresa para acessar o menu!", BusinessInfo[idbusiness[playerid]][cID]);
    }
    else
    {
        format(String, sizeof(String), "Bem vindo(a) a Empresa ID %d que pertence a %s", BusinessInfo[idbusiness[playerid]][cID], BusinessInfo[idbusiness[playerid]][cName]);
    }

    withinbusiness[playerid] = 1;
    SendClientMessage(playerid, C_PROPERTY, String);
    SetPlayerInterior(playerid, BusinessInfo[idbusiness[playerid]][cInterior]);
    SetPlayerPos(playerid, BusinessInfo[idbusiness[playerid]][cInteriorX], BusinessInfo[idbusiness[playerid]][cInteriorY], BusinessInfo[idbusiness[playerid]][cInteriorZ]);
    return 1;
}
CMD:sairempresa(playerid)
{
    if(withinbusiness[playerid] != 1)
        return SendClientMessage(playerid, Erro, "Você não está em uma empresa");

    if(!IsPlayerInRangeOfPoint(playerid, 2.0, BusinessInfo[idbusiness[playerid]][cInteriorX], BusinessInfo[idbusiness[playerid]][cInteriorY], BusinessInfo[idbusiness[playerid]][cInteriorZ]))
        return SendClientMessage(playerid, Erro, "Você está longe da porta");

    if(!strcmp(BusinessInfo[idbusiness[playerid]][cName], PlayerInfo[playerid][Nome], true))
    {
        format(String, sizeof(String), "Você saiu da sua empresa %s", BusinessInfo[idbusiness[playerid]][cName]);
    }
    else
    {
        format(String, sizeof(String), "Você saiu da empresa que pertence a %s", BusinessInfo[idbusiness[playerid]][cName]);
    }

    withinbusiness[playerid] = 0;
    SendClientMessage(playerid, C_PROPERTY, String);
    SetPlayerInterior(playerid, 0);
    SetPlayerPos(playerid, BusinessInfo[idbusiness[playerid]][cIconX], BusinessInfo[idbusiness[playerid]][cIconY], BusinessInfo[idbusiness[playerid]][cIconZ]);
    return 1;
}
CMD:comprarempresa(playerid)
{
    if(!IsPlayerInRangeOfPoint(playerid, 1.5, BusinessInfo[idbusiness[playerid]][cIconX], BusinessInfo[idbusiness[playerid]][cIconY], BusinessInfo[idbusiness[playerid]][cIconZ]))
        return SendClientMessage(playerid, Erro, "Você não está em nenhuma porta de empresa");

    if(!Request_RealEstate[playerid][rre_business])
        return SendClientMessage(playerid, Erro, "Vcoê não tem requisição de compra de empresas");

    new query[500], id;

    mysql_format(IDConexao, query, sizeof(query), "SELECT `Nome` FROM `Business` WHERE `Nome`='%e'", PlayerInfo[playerid][Nome]);
    mysql_query(IDConexao, query);

    if(cache_num_rows() > 0)
        return SendClientMessage(playerid, Erro, "Você já é dono(a) de uma empresa");

    if(!strcmp(BusinessInfo[idbusiness[playerid]][cSelling], "N/A", true))
        return SendClientMessage(playerid, Erro, "Essa empresa não está a venda");

    mysql_format(IDConexao, query, sizeof(query), "SELECT `Func1`, `Func2`, `Func3`, `Func4` FROM `Business` WHERE `Func1`='%e' OR `Func2`='%e' OR `Func3`='%e' OR `Func4`='%e'", PlayerInfo[playerid][Nome], PlayerInfo[playerid][Nome], PlayerInfo[playerid][Nome], PlayerInfo[playerid][Nome]);
    mysql_query(IDConexao, query);

    if(cache_num_rows() > 0)
        return SendClientMessage(playerid, Erro, "Você ainda está prestando serviços para uma empresa");

    GetPlayer2DZone(zone, MAX_ZONE_NAME, BusinessInfo[idbusiness[playerid]][cIconX], BusinessInfo[idbusiness[playerid]][cIconY]);

    if(!strcmp(BusinessInfo[idbusiness[playerid]][cName], "N/A", true))
    {
        if(PlayerInfo[playerid][Dinheiro] < BusinessInfo[idbusiness[playerid]][cCost])
            return SendClientMessage(playerid, Erro, "Você não tem esse dinheiro em mãos");

        format(String, sizeof(String), "O(A) Jogador(a) %s comprou a empresa ID %d localizada em %s", PlayerInfo[playerid][Nome], BusinessInfo[idbusiness[playerid]][cID], zone);

        PlayerInfo[playerid][Dinheiro] -= BusinessInfo[idbusiness[playerid]][cCost];
    }
    else if(strcmp(BusinessInfo[idbusiness[playerid]][cName], "N/A", true))
    {
        id = GetPlayerID(BusinessInfo[idbusiness[playerid]][cName]);

        if(id == INVALID_PLAYER_ID)
            return SendClientMessage(playerid, Erro, "O(A) Proprietário(a) dessa empresa não está conectado(a)");

        if(PlayerInfo[playerid][Dinheiro] < BusinessInfo[idbusiness[playerid]][cPrice])
            return SendClientMessage(playerid, Erro, "Você não tem esse dinheiro em mãos");

        format(String, sizeof(String), "O(A) Jogador(a) %s comprou a sua empresa e o seu dinheiro foi transferido direto pra sua conta bancária!", PlayerInfo[playerid][Nome], BusinessInfo[idbusiness[playerid]][cID], BusinessInfo[idbusiness[playerid]][cName], zone);
        SendClientMessage(id, -1, String);
        format(String, sizeof(String), "O(A) Jogador(a) %s comprou a empresa ID %d que pertencia ao jogador(a) %s localizada em %s", PlayerInfo[playerid][Nome], BusinessInfo[idbusiness[playerid]][cID], BusinessInfo[idbusiness[playerid]][cName], zone);

        PlayerInfo[id][SaldoBancario] += BusinessInfo[idbusiness[playerid]][cPrice];
        PlayerInfo[playerid][Dinheiro] -= BusinessInfo[idbusiness[playerid]][cPrice];
    }

    BusinessInfo[idbusiness[playerid]][cID] = idbusiness[playerid];
    format(BusinessInfo[idbusiness[playerid]][cName], MAX_PLAYER_NAME, PlayerInfo[playerid][Nome]);
    format(BusinessInfo[idbusiness[playerid]][cMessage], 30, "N/A");
    format(BusinessInfo[idbusiness[playerid]][cSelling], 5, "N/A");
    BusinessInfo[idbusiness[playerid]][cPrice] = 0;

    SendClientMessageToAll(-1, String);

    UpdateCompanyExternal(idbusiness[playerid]);

    UpdatePlayerMoney(playerid);
    UpdateCompanys(idbusiness[playerid]);
    return 1;
}
