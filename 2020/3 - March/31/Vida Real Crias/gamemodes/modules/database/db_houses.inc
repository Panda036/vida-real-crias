#include YSI\y_hooks

#define MAX_HOUSES (870+1)
#define MAIN_HOUSE_COMMAND              5001
#define MAIN_HOUSE                      5002
#define MAIN_HOUSE_ALTER_MSG            5003
#define MAIN_HOUSE_ALTER_PASS           5004
#define MAIN_HOUSE_RELEASE_AGREE        5005
#define MAIN_HOUSE_PASS                 5006
#define MAIN_HOUSE_SELL_INPUT           5007
#define MAIN_HOUSE_SELL_LIST            5008
#define MAIN_HOUSE_RESIDENTS            5009
#define MAIN_HOUSE_RESIDENTS_LIST       5010
#define MAIN_HOUSE_RESIDENTS_INPUT      5011
#define MAIN_HOUSE_UPGRADE              5012
#define MAIN_HOUSE_SELF                 5013
#define MAIN_HOUSE_SELF_ADD             5014
#define MAIN_HOUSE_SELF_REMOVE          5015

enum hInfo
{
    hID,
    hNome[MAX_PLAYER_NAME],
    hM1[MAX_PLAYER_NAME],
    hM2[MAX_PLAYER_NAME],
    hM3[MAX_PLAYER_NAME],
    hM4[MAX_PLAYER_NAME],
    hM5[MAX_PLAYER_NAME],
    hM6[MAX_PLAYER_NAME],
    hMensagem[30],
    hAlugando[5],
    hVendendo[5],
    hUp,
    hUpMax,
    hPreco,
    hCusto,
    hReais,
    hPadrao,
    hCofre,
    hInterior,
    hTrancada[5],
    hSenha[24],
    Float:iconx,
    Float:icony,
    Float:iconz,
    Float:hInteriorX,
    Float:hInteriorY,
    Float:hInteriorZ,
    hResidents
}
new HouseInfo[MAX_HOUSES][hInfo];

new Text3D:HouseLabel[MAX_HOUSES];
new HouseMapIcon[MAX_HOUSES];
new HousePickup[MAX_HOUSES];
new houseid[MAX_PLAYERS];
new dentrocasa[MAX_PLAYERS];
new HouseContinueTimer[MAX_PLAYERS];
new bool:HouseContinue[MAX_PLAYERS];

hook OnGameModeInit()
{
    new dbhouse[1000];
    strins(dbhouse,"CREATE TABLE IF NOT EXISTS `Houses` ", strlen(dbhouse));
    strins(dbhouse,"(ID int PRIMARY KEY AUTO_INCREMENT,", strlen(dbhouse));
    strins(dbhouse,"Nome varchar(24) NOT NULL DEFAULT 'N/A',", strlen(dbhouse));
    strins(dbhouse,"M1 varchar(24) NOT NULL DEFAULT 'N/A',", strlen(dbhouse));
    strins(dbhouse,"M2 varchar(24) NOT NULL DEFAULT 'N/A',", strlen(dbhouse));
    strins(dbhouse,"M3 varchar(24) NOT NULL DEFAULT 'N/A',", strlen(dbhouse));
    strins(dbhouse,"M4 varchar(24) NOT NULL DEFAULT 'N/A',", strlen(dbhouse));
    strins(dbhouse,"M5 varchar(24) NOT NULL DEFAULT 'N/A',", strlen(dbhouse));
    strins(dbhouse,"M6 varchar(24) NOT NULL DEFAULT 'N/A',", strlen(dbhouse));
    strins(dbhouse,"Mensagem varchar(80) NOT NULL DEFAULT 'N/A',", strlen(dbhouse));
    strins(dbhouse,"Alugando varchar(3) NOT NULL DEFAULT 'N/A',", strlen(dbhouse));
    strins(dbhouse,"Vendendo varchar(3) NOT NULL DEFAULT 'Sim',", strlen(dbhouse));
    strins(dbhouse,"Up int(2) NOT NULL DEFAULT 1,", strlen(dbhouse));
    strins(dbhouse,"UpMax int(2) NOT NULL,", strlen(dbhouse));
    strins(dbhouse,"Preco int(10) NOT NULL,", strlen(dbhouse));
    strins(dbhouse,"Custo int(10) NOT NULL,", strlen(dbhouse));
    strins(dbhouse,"Padrao int(10) NOT NULL,", strlen(dbhouse));
    strins(dbhouse,"Reais int(10) NOT NULL DEFAULT 0,", strlen(dbhouse));
    strins(dbhouse,"Cofre int(11) NOT NULL,", strlen(dbhouse));
    strins(dbhouse,"Interior int(5) NOT NULL,", strlen(dbhouse));
    strins(dbhouse,"Trancada varchar(3) NOT NULL DEFAULT 'N/A',", strlen(dbhouse));
    strins(dbhouse,"Senha varchar(24) NOT NULL DEFAULT 'N/A',", strlen(dbhouse));
    strins(dbhouse,"X float NOT NULL,", strlen(dbhouse));
    strins(dbhouse,"Y float NOT NULL,", strlen(dbhouse));
    strins(dbhouse,"Z float NOT NULL,", strlen(dbhouse));
    strins(dbhouse,"InteriorX float NOT NULL,", strlen(dbhouse));
    strins(dbhouse,"InteriorY float NOT NULL,", strlen(dbhouse));
    strins(dbhouse,"InteriorZ float NOT NULL)", strlen(dbhouse));
    mysql_query(IDConexao, dbhouse, false);

    new query[100];
    for(new i = 1; i < MAX_HOUSES; ++i)
    {
        mysql_format(IDConexao, query, sizeof(query), "SELECT * FROM `Houses` WHERE `ID`='%d'", i);
        mysql_tquery(IDConexao, query, "LoadHouses", "d", i);
    }
    return 1;
}

hook OnGameModeExit()
{
    for(new i=1; i < MAX_HOUSES; i++)
	{
        DestroyDynamicMapIcon(HouseMapIcon[i]);
        DestroyDynamic3DTextLabel(HouseLabel[i]);
        DestroyDynamicPickup(HousePickup[i]);
	}
	return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    HouseMapIcon[playerid] = 0;
    HousePickup[playerid] = 0;
    houseid[playerid] = 0;
    dentrocasa[playerid] = 0;
    HouseContinue[playerid] = false;
    KillTimer(HouseContinueTimer[playerid]);
	return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    new idhouse = houseid[playerid];

    if(newkeys == KEY_SECONDARY_ATTACK)
    {
        if(dentrocasa[playerid] == 0 && IsPlayerInRangeOfPoint(playerid, 1.5, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz]))
        {
            if(strcmp(HouseInfo[idhouse][hNome], PlayerInfo[playerid][Nome], true)==0)
            {
                format(String, sizeof(String), "Bem vindo(a) a Casa ID %d em que você mora, Digite: /MenuCasa para acessar o menu!", HouseInfo[idhouse][hID]);
            } else {
                if(strcmp(HouseInfo[idhouse][hTrancada], "Sim", true)==0)
                    return ShowPlayerDialog(playerid, MAIN_HOUSE_PASS, DIALOG_STYLE_INPUT, "{FF0000}Casa trancada", "{FFFFFF}Digite abaixo a senha da casa para entrar", "Entrar", "Cancelar");

                format(String, sizeof(String), "Bem vindo(a) a Casa ID %d que pertence a %s", HouseInfo[idhouse][hID], HouseInfo[idhouse][hNome]);
            }

            dentrocasa[playerid] = 1;
            SendClientMessage(playerid, C_PROPERTY, String);
            SetPlayerVirtualWorld(playerid, HouseInfo[idhouse][hID]);
            SetPlayerInterior(playerid, HouseInfo[idhouse][hInterior]);
            SetPlayerPos(playerid, HouseInfo[idhouse][hInteriorX], HouseInfo[idhouse][hInteriorY], HouseInfo[idhouse][hInteriorZ]);
            return 1;
        }
        else if(dentrocasa[playerid] == 1 && IsPlayerInRangeOfPoint(playerid, 2.0, HouseInfo[idhouse][hInteriorX], HouseInfo[idhouse][hInteriorY], HouseInfo[idhouse][hInteriorZ]))
        {
            if(strcmp(HouseInfo[idhouse][hNome], PlayerInfo[playerid][Nome], true)==0)
            {
                format(String, sizeof(String), "Você saiu da sua casa %s", HouseInfo[idhouse][hNome]);
            }
            else
            {
                format(String, sizeof(String), "Você saiu da casa que pertence a %s", HouseInfo[idhouse][hNome]);
            }

            dentrocasa[playerid] = 0;
            SendClientMessage(playerid, C_PROPERTY, String);
            SetPlayerVirtualWorld(playerid, 0);
            SetPlayerInterior(playerid, 0);
            SetPlayerPos(playerid, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz]);
            return 1;
        }
    }
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    new idhouse = houseid[playerid];

    switch(dialogid)
    {
        case MAIN_HOUSE:
        {
            if(response)
            {
                if(!strcmp(PlayerInfo[playerid][Nome], HouseInfo[idhouse][hNome], true))
                {
                    if(listitem == 0)
                    {
                        return ShowPlayerDialog(playerid, MAIN_HOUSE_ALTER_MSG, DIALOG_STYLE_INPUT, "{FFD700}Alterar Mensagem", "{FFFFFF}Digite abaixo a nova mensagem da sua casa", "Selecionar", "Cancelar");
                    }
                    else if(listitem == 1)
                    {
                        return ShowPlayerDialog(playerid, MAIN_HOUSE_ALTER_PASS, DIALOG_STYLE_INPUT, "{FFD700}Alterar Senha", "{FFFFFF}Digite abaixo a nova senha da sua casa", "Selecionar", "Cancelar");
                    }
                    else if(listitem == 2)
                    {
                        if(dentrocasa[playerid] != 1)
                            return SendClientMessage(playerid, 0xFF4000AA, "Você não está em uma casa");

                        if(strcmp(HouseInfo[idhouse][hNome], PlayerInfo[playerid][Nome], true))
                            return SendClientMessage(playerid, 0xFF4000AA, "Você não é dono(a)/morador(a) dessa casa");

                        if(strcmp(HouseInfo[idhouse][hTrancada], "Sim", true)==0)
                        {
                            format(HouseInfo[idhouse][hTrancada], 24, "N/A");
                            format(String, sizeof(String),"| INFO | Agora a sua casa está aberta!", inputtext);
                            SendClientMessage(playerid, -1, String);
                        }
                        else if(strcmp(HouseInfo[idhouse][hTrancada], "N/A", true)==0)
                        {
                            format(HouseInfo[idhouse][hTrancada], 24, "Sim");
                            format(String, sizeof(String),"| INFO | Agora a sua casa está fechada com a senha {FF0000}%s", HouseInfo[idhouse][hSenha]);
                            SendClientMessage(playerid, -1, String);
                        }

                        UpdateHouseExternal(idhouse);
                        UpdateHouses(idhouse);
                        return 1;
                    }
                    else if(listitem == 3)
                    {
                        return ShowPlayerDialog(playerid, MAIN_HOUSE_SELF, DIALOG_STYLE_LIST, "{FFD700}Cofre", "{FFFFFF}Adicionar Dinheiro\nRemover Dinheiro", "Selecionar", "Cancelar");
                    }
                    else if(listitem == 4)
                    {
                        return ShowPlayerDialog(playerid, MAIN_HOUSE_UPGRADE, DIALOG_STYLE_LIST, "{FFD700}Upgrade", "{FFFFFF}Upgrade do Interior\nDowngrade do Interior", "Selecionar", "Cancelar");
                    }
                    else if(listitem == 5)
                    {
                        new txt[300];

                        if(HouseInfo[idhouse][hUp] >= 1 && HouseInfo[idhouse][hUp] <= 2)
                        {
                            ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FFD700}Morador(a)", "{FF4000}Sua casa não tem upgrade necessário para colocar moradores!", "Fechar", #);
                        }
                        else if(HouseInfo[idhouse][hUp] >= 3 && HouseInfo[idhouse][hUp] <= 5)
                        {
                            format(String, sizeof(String), "{FFFFFF}%s \n", HouseInfo[idhouse][hM1]);
                            strcat(txt, String);
                        }
                        else if(HouseInfo[idhouse][hUp] >= 6 && HouseInfo[idhouse][hUp] <= 8)
                        {
                            format(String, sizeof(String), "{FFFFFF}%s \n", HouseInfo[idhouse][hM1]);
                            strcat(txt, String);
                            format(String, sizeof(String), "{FFFFFF}%s \n", HouseInfo[idhouse][hM2]);
                            strcat(txt, String);
                        }
                        else if(HouseInfo[idhouse][hUp] >= 9 && HouseInfo[idhouse][hUp] <= 11)
                        {
                            format(String, sizeof(String), "{FFFFFF}%s \n", HouseInfo[idhouse][hM1]);
                            strcat(txt, String);
                            format(String, sizeof(String), "{FFFFFF}%s \n", HouseInfo[idhouse][hM2]);
                            strcat(txt, String);
                            format(String, sizeof(String), "{FFFFFF}%s \n", HouseInfo[idhouse][hM3]);
                            strcat(txt, String);
                        }
                        else if(HouseInfo[idhouse][hUp] >= 12 && HouseInfo[idhouse][hUp] <= 14)
                        {
                            format(String, sizeof(String), "{FFFFFF}%s \n", HouseInfo[idhouse][hM1]);
                            strcat(txt, String);
                            format(String, sizeof(String), "{FFFFFF}%s \n", HouseInfo[idhouse][hM2]);
                            strcat(txt, String);
                            format(String, sizeof(String), "{FFFFFF}%s \n", HouseInfo[idhouse][hM3]);
                            strcat(txt, String);
                            format(String, sizeof(String), "{FFFFFF}%s \n", HouseInfo[idhouse][hM4]);
                            strcat(txt, String);
                        }
                        else if(HouseInfo[idhouse][hUp] >= 15 && HouseInfo[idhouse][hUp] <= 17)
                        {
                            format(String, sizeof(String), "{FFFFFF}%s \n", HouseInfo[idhouse][hM1]);
                            strcat(txt, String);
                            format(String, sizeof(String), "{FFFFFF}%s \n", HouseInfo[idhouse][hM2]);
                            strcat(txt, String);
                            format(String, sizeof(String), "{FFFFFF}%s \n", HouseInfo[idhouse][hM3]);
                            strcat(txt, String);
                            format(String, sizeof(String), "{FFFFFF}%s \n", HouseInfo[idhouse][hM4]);
                            strcat(txt, String);
                            format(String, sizeof(String), "{FFFFFF}%s \n", HouseInfo[idhouse][hM5]);
                            strcat(txt, String);
                        }
                        else if(HouseInfo[idhouse][hUp] >= 18)
                        {
                            format(String, sizeof(String), "{FFFFFF}%s \n", HouseInfo[idhouse][hM1]);
                            strcat(txt, String);
                            format(String, sizeof(String), "{FFFFFF}%s \n", HouseInfo[idhouse][hM2]);
                            strcat(txt, String);
                            format(String, sizeof(String), "{FFFFFF}%s \n", HouseInfo[idhouse][hM3]);
                            strcat(txt, String);
                            format(String, sizeof(String), "{FFFFFF}%s \n", HouseInfo[idhouse][hM4]);
                            strcat(txt, String);
                            format(String, sizeof(String), "{FFFFFF}%s \n", HouseInfo[idhouse][hM5]);
                            strcat(txt, String);
                            format(String, sizeof(String), "{FFFFFF}%s \n", HouseInfo[idhouse][hM6]);
                            strcat(txt, String);
                        }
                        ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS, DIALOG_STYLE_LIST, "{FFD700}Morador(a)", txt, "Selecionar", "Cancelar");
                        return 1;
                    }
                    else if(listitem == 6)
                    {
                        if(!strcmp(PlayerInfo[playerid][Nome], HouseInfo[idhouse][hM1], true) ||
                         !strcmp(PlayerInfo[playerid][Nome], HouseInfo[idhouse][hM2], true) ||
                         !strcmp(PlayerInfo[playerid][Nome], HouseInfo[idhouse][hM3], true) ||
                         !strcmp(PlayerInfo[playerid][Nome], HouseInfo[idhouse][hM4], true) ||
                         !strcmp(PlayerInfo[playerid][Nome], HouseInfo[idhouse][hM5], true) ||
                         !strcmp(PlayerInfo[playerid][Nome], HouseInfo[idhouse][hM6], true) )
                            return SendClientMessage(playerid, Erro, "Somente dono(a) pode usar essa opção");

                        new txt[200];

                        strcat(txt, "{FF0000}Funções \t\t {1CEB00}Status \n");

                        if(strcmp(HouseInfo[idhouse][hVendendo], "Sim", true)==0)
                            { strcat(txt, "{FFFFFF}Vendendo: \t\t Sim\n");  }

                        if(strcmp(HouseInfo[idhouse][hVendendo], "N/A", true)==0)
                            { strcat(txt, "{FFFFFF}Vendendo: \t\t Não\n"); }

                        format(String, sizeof(String), "{FFFFFF}Alterar Valor: \t\t $%s \n", IsMoney(HouseInfo[idhouse][hPreco], "."));
                        strcat(txt, String);
                        ShowPlayerDialog(playerid, MAIN_HOUSE_SELL_LIST, DIALOG_STYLE_TABLIST_HEADERS, "{FFD700}Vender Casa", txt, "Selecionar", "Cancelar");
                    }
                    else if(listitem == 7)
                    {
                        ShowPlayerDialog(playerid, MAIN_HOUSE_RELEASE_AGREE, DIALOG_STYLE_INPUT, "{FF0000}Código de Confirmação", "{FFFFFF}Pra liberar sua casa para o servidor é necessário o código de confirmação\n\n{FF4000}Obs: o código de vericação é o mesmo usado para registrar sua conta!", "Continuar", "Cancelar");
                        return 1;
                    }
                }
                else if(!strcmp(PlayerInfo[playerid][Nome], HouseInfo[idhouse][hM1], true))
                {
                    if(listitem == 0)
                    {
                        format(HouseInfo[idhouse][hM1], MAX_PLAYER_NAME, "N/A");
                        format(String, sizeof(String), "Você revougou sua moradia na casa ID %d!", HouseInfo[idhouse][hID]);
                        SendClientMessage(playerid, C_PROPERTY, String);
                        UpdateHouses(idhouse);
                    }
                }
                else if(!strcmp(PlayerInfo[playerid][Nome], HouseInfo[idhouse][hM2], true))
                {
                    if(listitem == 0)
                    {
                        format(HouseInfo[idhouse][hM2], MAX_PLAYER_NAME, "N/A");
                        format(String, sizeof(String), "Você revougou sua moradia na casa ID %d!", HouseInfo[idhouse][hID]);
                        SendClientMessage(playerid, C_PROPERTY, String);
                        UpdateHouses(idhouse);
                    }
                }
                else if(!strcmp(PlayerInfo[playerid][Nome], HouseInfo[idhouse][hM3], true))
                {
                    if(listitem == 0)
                    {
                        format(HouseInfo[idhouse][hM3], MAX_PLAYER_NAME, "N/A");
                        format(String, sizeof(String), "Você revougou sua moradia na casa ID %d!", HouseInfo[idhouse][hID]);
                        SendClientMessage(playerid, C_PROPERTY, String);
                        UpdateHouses(idhouse);
                    }
                }
                else if(!strcmp(PlayerInfo[playerid][Nome], HouseInfo[idhouse][hM4], true))
                {
                    if(listitem == 0)
                    {
                        format(HouseInfo[idhouse][hM4], MAX_PLAYER_NAME, "N/A");
                        format(String, sizeof(String), "Você revougou sua moradia na casa ID %d!", HouseInfo[idhouse][hID]);
                        SendClientMessage(playerid, C_PROPERTY, String);
                        UpdateHouses(idhouse);
                    }
                }
                else if(!strcmp(PlayerInfo[playerid][Nome], HouseInfo[idhouse][hM5], true))
                {
                    if(listitem == 0)
                    {
                        format(HouseInfo[idhouse][hM5], MAX_PLAYER_NAME, "N/A");
                        format(String, sizeof(String), "Você revougou sua moradia na casa ID %d!", HouseInfo[idhouse][hID]);
                        SendClientMessage(playerid, C_PROPERTY, String);
                        UpdateHouses(idhouse);
                    }
                }
                else if(!strcmp(PlayerInfo[playerid][Nome], HouseInfo[idhouse][hM6], true))
                {
                    if(listitem == 0)
                    {
                        format(HouseInfo[idhouse][hM6], MAX_PLAYER_NAME, "N/A");
                        format(String, sizeof(String), "Você revougou sua moradia na casa ID %d!", HouseInfo[idhouse][hID]);
                        SendClientMessage(playerid, C_PROPERTY, String);
                        UpdateHouses(idhouse);
                    }
                }
            }
            return 1;
        }
        case MAIN_HOUSE_ALTER_MSG:
        {
            if(response)
            {
                if(dentrocasa[playerid] == 0)
                    return SendClientMessage(playerid, 0xFF4000AA, "Você não está em uma casa");

                if(strcmp(HouseInfo[idhouse][hNome], PlayerInfo[playerid][Nome], true))
                    return SendClientMessage(playerid, 0xFF4000AA, "Você não é dono(a) dessa casa");

                if(!IsValidMessageHouse(inputtext))
                    return ShowPlayerDialog(playerid, MAIN_HOUSE_ALTER_MSG, DIALOG_STYLE_INPUT, "{FFD700}Alterar Mensagem", "{FFFFFF}Digite abaixo a nova mensagem da sua casa \n{FF0000}Alguns caracteres especias não são permitidos!", "Selecionar", "Cancelar");

                format(HouseInfo[idhouse][hMensagem], 30, inputtext);
                format(String, sizeof(String),"| INFO | Agora a mensagem da sua casa é {FF0000}%s", inputtext);
                SendClientMessage(playerid, -1, String);

                UpdateHouseExternal(idhouse);
                UpdateHouses(idhouse);
            }
        }
        case MAIN_HOUSE_ALTER_PASS:
        {
            if(response)
            {
                if(dentrocasa[playerid] == 0)
                    return SendClientMessage(playerid, 0xFF4000AA, "Você não está em uma casa");

                if(strcmp(HouseInfo[idhouse][hNome], PlayerInfo[playerid][Nome], true))
                    return SendClientMessage(playerid, 0xFF4000AA, "Você não é dono(a) dessa casa");

                if(!IsValidUsername(inputtext))
                    return ShowPlayerDialog(playerid, MAIN_HOUSE_ALTER_PASS, DIALOG_STYLE_INPUT, "{FFD700}Alterar Senha", "{FFFFFF}Digite abaixo a nova senha da sua casa \n{FF0000}Alguns caracteres especias não são permitidos!", "Selecionar", "Cancelar");

                format(HouseInfo[idhouse][hSenha], 24, inputtext);
                format(String, sizeof(String),"| INFO | Agora a senha da sua casa é {FF0000}%s", inputtext);
                SendClientMessage(playerid, -1, String);
                UpdateHouses(idhouse);
            }
        }
        case MAIN_HOUSE_RELEASE_AGREE:
        {
            if(response)
            {
                if(!strlen(inputtext))
                    return ShowPlayerDialog(playerid, MAIN_HOUSE_RELEASE_AGREE, DIALOG_STYLE_INPUT, "{FF0000}Código de Confirmação", "{FFFFFF}Pra liberar sua casa para o servidor é necessário o código de confirmação\n{FF0000}Código Incorreto!\n\n{FF4000}Obs: o código de vericação é o mesmo usado para registrar sua conta!", "Continuar", "Cancelar");

                if(!IsValidCodingAccount(playerid, inputtext))
                    return ShowPlayerDialog(playerid, MAIN_HOUSE_RELEASE_AGREE, DIALOG_STYLE_INPUT, "{FF0000}Código de Confirmação", "{FFFFFF}Pra liberar sua casa para o servidor é necessário o código de confirmação\n{FF0000}Código Incorreto!\n\n{FF4000}Obs: o código de vericação é o mesmo usado para registrar sua conta!", "Continuar", "Cancelar");

                if(dentrocasa[playerid] == 0)
                    return SendClientMessage(playerid, 0xFF4000AA, "Você não está em uma casa");

                if(strcmp(HouseInfo[idhouse][hNome], PlayerInfo[playerid][Nome], true))
                    return SendClientMessage(playerid, 0xFF4000AA, "Você não é dono(a) dessa casa");

                if(HouseInfo[houseid[playerid]][hCofre] != 0)
                    return SendClientMessage(playerid, 0xFF4000AA, "Você não removeu o dinheiro do cofre de sua casa");

                if(HouseInfo[idhouse][hUpMax] == 3)
                {
                    HouseInfo[idhouse][hCusto] = 70000;
                    HouseInfo[idhouse][hPadrao] = 63000;
                }
                else if(HouseInfo[idhouse][hUpMax] == 6)
                {
                    HouseInfo[idhouse][hCusto] = 150000;
                    HouseInfo[idhouse][hPadrao] = 135000;
                }
                else if(HouseInfo[idhouse][hUpMax] == 9)
                {
                    HouseInfo[idhouse][hCusto] = 240000;
                    HouseInfo[idhouse][hPadrao] = 216000;
                }
                else if(HouseInfo[idhouse][hUpMax] == 12)
                {
                    HouseInfo[idhouse][hCusto] = 350000;
                    HouseInfo[idhouse][hPadrao] = 315000;
                }
                else if(HouseInfo[idhouse][hUpMax] == 15)
                {
                    HouseInfo[idhouse][hCusto] = 400000;
                    HouseInfo[idhouse][hPadrao] = 360000;
                }
                else if(HouseInfo[idhouse][hUpMax] == 18)
                {
                    HouseInfo[idhouse][hCusto] = 500000;
                    HouseInfo[idhouse][hPadrao] = 450000;
                }

                HouseInfo[idhouse][hID] = idhouse;
                format(HouseInfo[idhouse][hNome], MAX_PLAYER_NAME, "N/A");
                format(HouseInfo[idhouse][hM1], MAX_PLAYER_NAME, "N/A");
                format(HouseInfo[idhouse][hM2], MAX_PLAYER_NAME, "N/A");
                format(HouseInfo[idhouse][hM3], MAX_PLAYER_NAME, "N/A");
                format(HouseInfo[idhouse][hM4], MAX_PLAYER_NAME, "N/A");
                format(HouseInfo[idhouse][hM5], MAX_PLAYER_NAME, "N/A");
                format(HouseInfo[idhouse][hM6], MAX_PLAYER_NAME, "N/A");
                format(HouseInfo[idhouse][hMensagem], 30, "N/A");
                format(HouseInfo[idhouse][hAlugando], 5, "N/A");
                format(HouseInfo[idhouse][hVendendo], 5, "Sim");
                HouseInfo[idhouse][hPreco] = 0;
                HouseInfo[idhouse][hUp] = 1;
                format(HouseInfo[idhouse][hTrancada], 5, "N/A");
                format(HouseInfo[idhouse][hSenha], 5, "N/A");

                PlayerInfo[playerid][Dinheiro] += HouseInfo[idhouse][hPadrao];
                UpdatePlayerMoney(playerid);

                GetPlayer2DZone(zone, MAX_ZONE_NAME, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony]);
                format(String, sizeof(String), "O(A) Jogador(a) %s liberou a casa ID %d localizada em %s", PlayerInfo[playerid][Nome], HouseInfo[idhouse][hID], zone);
                SendClientMessageToAll(-1, String);

                SetPlayerPos(playerid, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz]);
                SetPlayerInterior(playerid, 0);
                SetPlayerVirtualWorld(playerid, 0);
                dentrocasa[playerid] = 0;

                UpgradeHouse(idhouse);
                UpdateHouseExternal(idhouse);
                UpdateHouses(idhouse);
                return 1;
            }
        }
        case MAIN_HOUSE_PASS:
        {
            if(response)
            {
                if(strlen(inputtext) == 0)
                    return ShowPlayerDialog(playerid, MAIN_HOUSE_PASS, DIALOG_STYLE_INPUT, "{FFD700}Senha", "{FFFFFF}Digite abaixo a senha da casa para entrar \n{FF0000}Senha incorreta, tente novamente!", "Entrar", "Cancelar");

                if(strcmp(inputtext, HouseInfo[idhouse][hSenha], true))
                    return ShowPlayerDialog(playerid, MAIN_HOUSE_PASS, DIALOG_STYLE_INPUT, "{FFD700}Senha", "{FFFFFF}Digite abaixo a senha da casa para entrar \n{FF0000}Senha incorreta, tente novamente!", "Entrar", "Cancelar");

                SetPlayerVirtualWorld(playerid, HouseInfo[idhouse][hID]);
                SetPlayerInterior(playerid, HouseInfo[idhouse][hInterior]);
                SetPlayerPos(playerid, HouseInfo[idhouse][hInteriorX], HouseInfo[idhouse][hInteriorY], HouseInfo[idhouse][hInteriorZ]);
                dentrocasa[playerid] = 1;
                format(String, sizeof(String), "Bem vindo(a) a Casa ID %d que pertence a %s", HouseInfo[idhouse][hID], HouseInfo[idhouse][hNome]);
                SendClientMessage(playerid, C_PROPERTY, String);
            }
        }
        case MAIN_HOUSE_SELL_LIST:
        {
            if(response)
            {
                switch(listitem)
                {
                    case 0:
                    {
                        if(!strcmp(HouseInfo[idhouse][hVendendo], "Sim", true))
                        {
                            format(HouseInfo[idhouse][hVendendo], 5, "N/A");
                            SendClientMessage(playerid, -1, "Agora sua casa não está mas à venda");
                        }
                        else if(!strcmp(HouseInfo[idhouse][hVendendo], "N/A", true))
                        {
                            if(HouseInfo[houseid[playerid]][hCofre] != 0)
                                return SendClientMessage(playerid, 0xFF4000AA, "Você não removeu o dinheiro do cofre de sua casa");

                            if(HouseInfo[idhouse][hPreco] == 0)
                            {
                                HouseInfo[idhouse][hPreco] = 0;
                                HouseInfo[idhouse][hPreco] += HouseInfo[idhouse][hPadrao];
                            }

                            format(HouseInfo[idhouse][hVendendo], 5, "Sim");
                            format(String, sizeof(String),"Agora sua casa está à venda no valor de {019303}$%s{FFFFFF}!", IsMoney(HouseInfo[idhouse][hPreco], "."));
                            SendClientMessage(playerid, -1, String);
                        }

                        UpdateHouseExternal(idhouse);
                        UpdateHouses(idhouse);
                    }
                    case 1:
                    {
                        ShowPlayerDialog(playerid, MAIN_HOUSE_SELL_INPUT, DIALOG_STYLE_INPUT, "{FFD700}Vender Casa", "{FFFFFF}Digite abaixo o valor que será somado com o valor padrão \nde sua casa automaticamente!", "Continuar", "Cancelar");
                    }
                }
            }
        }
        case MAIN_HOUSE_SELL_INPUT:
        {
            if(response)
            {
                HouseInfo[idhouse][hPreco] = 0;
                HouseInfo[idhouse][hPreco] += HouseInfo[idhouse][hPadrao] + strval(inputtext);

                format(String, sizeof(String), "O valor da sua casa foi alterado para {019303}$%s{FFFFFF}, agora é só colocar a venda!", IsMoney(HouseInfo[idhouse][hPreco], "."));
                SendClientMessage(playerid, -1, String);

                UpdateHouseExternal(idhouse);
                UpdateHouses(idhouse);
            }
        }
        case MAIN_HOUSE_RESIDENTS:
        {

            if(response)
            {
                if(listitem == 0)
                {
                    HouseInfo[idhouse][hResidents] = 1;
                    ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS_LIST, DIALOG_STYLE_LIST, "{FFD700}Morador(a)", "{FFFFFF}Adicionar morador(a)\nRemover morador(a)", "Selecionar", "Cancelar");
                }
                else if(listitem == 1)
                {
                    HouseInfo[idhouse][hResidents] = 2;
                    ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS_LIST, DIALOG_STYLE_LIST, "{FFD700}Morador(a)", "{FFFFFF}Adicionar morador(a)\nRemover morador(a)", "Selecionar", "Cancelar");
                }
                else if(listitem == 2)
                {
                    HouseInfo[idhouse][hResidents] = 3;
                    ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS_LIST, DIALOG_STYLE_LIST, "{FFD700}Morador(a)", "{FFFFFF}Adicionar morador(a)\nRemover morador(a)", "Selecionar", "Cancelar");
                }
                else if(listitem == 3)
                {
                    HouseInfo[idhouse][hResidents] = 4;
                    ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS_LIST, DIALOG_STYLE_LIST, "{FFD700}Morador(a)", "{FFFFFF}Adicionar morador(a)\nRemover morador(a)", "Selecionar", "Cancelar");
                }
                else if(listitem == 4)
                {
                    HouseInfo[idhouse][hResidents] = 5;
                    ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS_LIST, DIALOG_STYLE_LIST, "{FFD700}Morador(a)", "{FFFFFF}Adicionar morador(a)\nRemover morador(a)", "Selecionar", "Cancelar");
                }
                else if(listitem == 5)
                {
                    HouseInfo[idhouse][hResidents] = 6;
                    ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS_LIST, DIALOG_STYLE_LIST, "{FFD700}Morador(a)", "{FFFFFF}Adicionar morador(a)\nRemover morador(a)", "Selecionar", "Cancelar");
                }
            }
        }
        case MAIN_HOUSE_RESIDENTS_LIST:
        {
            if(response)
            {
                switch(listitem)
                {
                    case 0:
                    {
                        if(!strcmp(PlayerInfo[playerid][Nome], HouseInfo[idhouse][hM1], true) ||
                         !strcmp(PlayerInfo[playerid][Nome], HouseInfo[idhouse][hM2], true) ||
                         !strcmp(PlayerInfo[playerid][Nome], HouseInfo[idhouse][hM3], true) ||
                         !strcmp(PlayerInfo[playerid][Nome], HouseInfo[idhouse][hM4], true) ||
                         !strcmp(PlayerInfo[playerid][Nome], HouseInfo[idhouse][hM5], true) ||
                         !strcmp(PlayerInfo[playerid][Nome], HouseInfo[idhouse][hM6], true) )
                            return SendClientMessage(playerid, Erro, "Somente dono(a) pode usar essa opção");

                        switch(HouseInfo[idhouse][hResidents])
                        {
                            case 1:
                            {
                                if(strcmp(HouseInfo[idhouse][hM1], "N/A", true))
                                    return SendClientMessage(playerid, Erro, "Essa vaga já tem morador(a)");
                            }
                            case 2:
                            {
                                if(strcmp(HouseInfo[idhouse][hM2], "N/A", true))
                                    return SendClientMessage(playerid, Erro, "Essa vaga já tem morador(a)");
                            }
                            case 3:
                            {
                                if(strcmp(HouseInfo[idhouse][hM3], "N/A", true))
                                    return SendClientMessage(playerid, Erro, "Essa vaga já tem morador(a)");
                            }
                            case 4:
                            {
                                if(strcmp(HouseInfo[idhouse][hM4], "N/A", true))
                                    return SendClientMessage(playerid, Erro, "Essa vaga já tem morador(a)");
                            }
                            case 5:
                            {
                                if(strcmp(HouseInfo[idhouse][hM5], "N/A", true))
                                    return SendClientMessage(playerid, Erro, "Essa vaga já tem morador(a)");
                            }
                            case 6:
                            {
                                if(strcmp(HouseInfo[idhouse][hM6], "N/A", true))
                                    return SendClientMessage(playerid, Erro, "Essa vaga já tem morador(a)");
                            }
                        }
                        ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS_INPUT, DIALOG_STYLE_INPUT, "{FFD700}Adicionar Morador(a)", "{FFFFFF}Digite abaixo o {FF0000}id{FFFFFF} do jogador(a)\nque você quer colocar como morador(a)", "Continuar", "Cancelar");
                        return 1;
                    }
                    case 1:
                    {
                        switch(HouseInfo[idhouse][hResidents])
                        {
                            case 1:
                            {
                                if(!strcmp(HouseInfo[idhouse][hM1], "N/A", true))
                                    return SendClientMessage(playerid, Erro, "Não tem nenhum morador(a) para remover");

                                format(String, sizeof(String), "O(A) morador(a) %s foi removido da sua casa!", HouseInfo[idhouse][hM1]);
                                SendClientMessage(playerid, C_PROPERTY, String);
                                format(HouseInfo[idhouse][hM1], MAX_PLAYER_NAME, "N/A");
                            }
                            case 2:
                            {
                                if(!strcmp(HouseInfo[idhouse][hM2], "N/A", true))
                                    return SendClientMessage(playerid, Erro, "Não tem nenhum morador(a) para remover");

                                format(String, sizeof(String), "O(A) morador(a) %s foi removido da sua casa!", HouseInfo[idhouse][hM2]);
                                SendClientMessage(playerid, C_PROPERTY, String);
                                format(HouseInfo[idhouse][hM2], MAX_PLAYER_NAME, "N/A");
                            }
                            case 3:
                            {
                                if(!strcmp(HouseInfo[idhouse][hM3], "N/A", true))
                                    return SendClientMessage(playerid, Erro, "Não tem nenhum morador(a) para remover");

                                format(String, sizeof(String), "O(A) morador(a) %s foi removido da sua casa!", HouseInfo[idhouse][hM3]);
                                SendClientMessage(playerid, C_PROPERTY, String);
                                format(HouseInfo[idhouse][hM3], MAX_PLAYER_NAME, "N/A");
                            }
                            case 4:
                            {
                                if(!strcmp(HouseInfo[idhouse][hM4], "N/A", true))
                                    return SendClientMessage(playerid, Erro, "Não tem nenhum morador(a) para remover");

                                format(String, sizeof(String), "O(A) morador(a) %s foi removido da sua casa!", HouseInfo[idhouse][hM4]);
                                SendClientMessage(playerid, C_PROPERTY, String);
                                format(HouseInfo[idhouse][hM4], MAX_PLAYER_NAME, "N/A");
                            }
                            case 5:
                            {
                                if(!strcmp(HouseInfo[idhouse][hM5], "N/A", true))
                                    return SendClientMessage(playerid, Erro, "Não tem nenhum morador(a) para remover");

                                format(String, sizeof(String), "O(A) morador(a) %s foi removido da sua casa!", HouseInfo[idhouse][hM5]);
                                SendClientMessage(playerid, C_PROPERTY, String);
                                format(HouseInfo[idhouse][hM5], MAX_PLAYER_NAME, "N/A");
                            }
                            case 6:
                            {
                                if(!strcmp(HouseInfo[idhouse][hM6], "N/A", true))
                                    return SendClientMessage(playerid, Erro, "Não tem nenhum morador(a) para remover");

                                format(String, sizeof(String), "O(A) morador(a) %s foi removido da sua casa!", HouseInfo[idhouse][hM6]);
                                SendClientMessage(playerid, C_PROPERTY, String);
                                format(HouseInfo[idhouse][hM6], MAX_PLAYER_NAME, "N/A");
                            }
                        }

                        UpdateHouses(idhouse);
                    }
                }
                return 1;
            }
        }
        case MAIN_HOUSE_RESIDENTS_INPUT:
        {
            if(response)
            {
                new _str[300], id = strval(inputtext);

                if(id < 0 || id >= MAX_PLAYERS)
                    return ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS_INPUT, DIALOG_STYLE_INPUT, "{FFD700}Morador(a)", "{FFFFFF}Digite abaixo o {FF0000}id{FFFFFF} do jogador(a)\nque você quer colocar como morador(a)\n{FF4000}Jogador(a) não conectado(a)!", "Continuar", "Cancelar");

                if(PlayerInfo[id][Logado] == false)
                    return ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS_INPUT, DIALOG_STYLE_INPUT, "{FFD700}Morador(a)", "{FFFFFF}Digite abaixo o {FF0000}id{FFFFFF} do jogador(a)\nque você quer colocar como morador(a)\n{FF4000}Jogador(a) não conectado(a)!", "Continuar", "Cancelar");

                if(id == playerid)
                    return ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS_INPUT, DIALOG_STYLE_INPUT, "{FFD700}Morador(a)", "{FFFFFF}Digite abaixo o {FF0000}id{FFFFFF} do jogador(a)\nque você quer colocar como morador(a)\n{FF4000}Não pode colocar você como morador(a)!", "Continuar", "Cancelar");

                mysql_format(IDConexao, _str, sizeof(_str), "SELECT `Nome` FROM `Houses` WHERE `Nome`='%e'", PlayerInfo[id][Nome]);
                mysql_query(IDConexao, _str);

                if(cache_num_rows() > 0)
                    return SendClientMessage(playerid, Erro, "O(A) Jogador(a) já tem uma casa");

                mysql_format(IDConexao, _str, sizeof(_str), "SELECT `M1` OR `M2` OR `M3` OR `M4` OR `M5` OR `M6` FROM `Houses` WHERE `M1`='%e' OR `M2`='%e' OR `M3`='%e' OR `M4`='%e' OR `M5`='%e' OR `M6`='%e'", PlayerInfo[id][Nome], PlayerInfo[id][Nome], PlayerInfo[id][Nome], PlayerInfo[id][Nome], PlayerInfo[id][Nome], PlayerInfo[id][Nome]);
                mysql_query(IDConexao, _str);

                if(cache_num_rows() > 0)
                    return SendClientMessage(playerid, Erro, "O(A) Jogador(a) já está de morador(a) em uma casa");

                if(!IsPlayerInRangeOfPoint(id, 10.0, HouseInfo[idhouse][hInteriorX], HouseInfo[idhouse][hInteriorY], HouseInfo[idhouse][hInteriorZ]))
                    return SendClientMessage(playerid, Erro, "O(A) Jogador(a) não está dentro da sua casa");


                switch(HouseInfo[idhouse][hResidents])
                {
                    case 1:
                    {
                        format(HouseInfo[idhouse][hM1], MAX_PLAYER_NAME, PlayerInfo[id][Nome]);
                        format(String, sizeof(String), "Você colocou o jogador(a) %s para morar em sua casa!", HouseInfo[idhouse][hM1]);
                        SendClientMessage(playerid, C_PROPERTY, String);
                    }
                    case 2:
                    {
                        format(HouseInfo[idhouse][hM2], MAX_PLAYER_NAME, PlayerInfo[id][Nome]);
                        format(String, sizeof(String), "Você colocou o jogador(a) %s para morar em sua casa!", HouseInfo[idhouse][hM2]);
                        SendClientMessage(playerid, C_PROPERTY, String);
                    }
                    case 3:
                    {
                        format(HouseInfo[idhouse][hM3], MAX_PLAYER_NAME, PlayerInfo[id][Nome]);
                        format(String, sizeof(String), "Você colocou o jogador(a) %s para morar em sua casa!", HouseInfo[idhouse][hM3]);
                        SendClientMessage(playerid, C_PROPERTY, String);
                    }
                    case 4:
                    {
                        format(HouseInfo[idhouse][hM4], MAX_PLAYER_NAME, PlayerInfo[id][Nome]);
                        format(String, sizeof(String), "Você colocou o jogador(a) %s para morar em sua casa!", HouseInfo[idhouse][hM4]);
                        SendClientMessage(playerid, C_PROPERTY, String);
                    }
                    case 5:
                    {
                        format(HouseInfo[idhouse][hM5], MAX_PLAYER_NAME, PlayerInfo[id][Nome]);
                        format(String, sizeof(String), "Você colocou o jogador(a) %s para morar em sua casa!", HouseInfo[idhouse][hM5]);
                        SendClientMessage(playerid, C_PROPERTY, String);
                    }
                    case 6:
                    {
                        format(HouseInfo[idhouse][hM6], MAX_PLAYER_NAME, PlayerInfo[id][Nome]);
                        format(String, sizeof(String), "Você colocou o jogador(a) %s para morar em sua casa!", HouseInfo[idhouse][hM6]);
                        SendClientMessage(playerid, C_PROPERTY, String);
                    }
                }

                format(String, sizeof(String), "O(A) Jogador(a) %s colocou voce para morar em sua casa, Digite: /MenuCasa para acessar o menu!", HouseInfo[idhouse][hNome]);
                SendClientMessage(id, C_PROPERTY, String);
                UpdateHouses(idhouse);
                return 1;
            }
        }
        case MAIN_HOUSE_UPGRADE:
        {
            if(response) switch(listitem)
            {
                case 0:
                {
                    if(HouseInfo[idhouse][hUp] == HouseInfo[idhouse][hUpMax])
                        return SendClientMessage(playerid, Erro, "Casa já está no upgrade máximo");

                    new standard[MAX_HOUSES];
                    standard[idhouse] = HouseInfo[idhouse][hPadrao];

                    switch(HouseInfo[idhouse][hUpMax]) // Perda 10% do valor padrão
                    {
                        case 3:
                        {
                            HouseInfo[idhouse][hPadrao] += 70000;

                            if(PlayerInfo[playerid][Dinheiro] < 70000)
                            {
                                HouseInfo[idhouse][hPadrao] = standard[idhouse];
                                SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");
                                return 1;
                            }

                            PlayerInfo[playerid][Dinheiro] -= 70000;
                        }
                        case 6:
                        {
                            HouseInfo[idhouse][hPadrao] += 150000;

                            if(PlayerInfo[playerid][Dinheiro] < 150000)
                            {
                                HouseInfo[idhouse][hPadrao] = standard[idhouse];
                                SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");
                                return 1;
                            }

                            PlayerInfo[playerid][Dinheiro] -= 150000;
                        }
                        case 9:
                        {
                            HouseInfo[idhouse][hPadrao] += 240000;

                            if(PlayerInfo[playerid][Dinheiro] < 240000)
                            {
                                HouseInfo[idhouse][hPadrao] = standard[idhouse];
                                SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");
                                return 1;
                            }

                            PlayerInfo[playerid][Dinheiro] -= 240000;
                        }
                        case 12:
                        {
                            HouseInfo[idhouse][hPadrao] += 350000;

                            if(PlayerInfo[playerid][Dinheiro] < 350000)
                            {
                                HouseInfo[idhouse][hPadrao] = standard[idhouse];
                                SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");
                                return 1;
                            }

                            PlayerInfo[playerid][Dinheiro] -= 350000;
                        }
                        case 15:
                        {
                            HouseInfo[idhouse][hPadrao] += 400000;

                            if(PlayerInfo[playerid][Dinheiro] < 400000)
                            {
                                HouseInfo[idhouse][hPadrao] = standard[idhouse];
                                SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");
                                return 1;
                            }

                            PlayerInfo[playerid][Dinheiro] -= 400000;
                        }
                        case 18:
                        {
                            HouseInfo[idhouse][hPadrao] += 500000;

                            if(PlayerInfo[playerid][Dinheiro] < 500000)
                            {
                                HouseInfo[idhouse][hPadrao] = standard[idhouse];
                                SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");
                                return 1;
                            }

                            PlayerInfo[playerid][Dinheiro] -= 500000;
                        }
                        case 21:
                        {
                            HouseInfo[idhouse][hPadrao] += 5000000;

                            if(PlayerInfo[playerid][Dinheiro] < 5000000)
                            {
                                HouseInfo[idhouse][hPadrao] = standard[idhouse];
                                SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");
                                return 1;
                            }

                            PlayerInfo[playerid][Dinheiro] -= 5000000;
                        }
                    }

                    HouseInfo[idhouse][hUp]++;

                    UpdatePlayerMoney(playerid);

                    UpgradeHouse(idhouse);
                    UpdateHouseExternal(idhouse);
                    UpdateHouses(idhouse);

                    SetPlayerVirtualWorld(playerid, HouseInfo[houseid[playerid]][hID]);
                    SetPlayerInterior(playerid, HouseInfo[houseid[playerid]][hInterior]);
                    SetPlayerPos(playerid, HouseInfo[houseid[playerid]][hInteriorX], HouseInfo[houseid[playerid]][hInteriorY], HouseInfo[houseid[playerid]][hInteriorZ]);
                    dentrocasa[playerid] = 1;
                    return 1;
                }
                case 1:
                {
                    if(HouseInfo[idhouse][hUp] == 1)
                        return SendClientMessage(playerid, Erro, "Casa já está no downgrade máximo");

                    switch(HouseInfo[idhouse][hUpMax]) // Perda 10% do novo valor padrão
                    {
                        case 3:
                        {
                            HouseInfo[idhouse][hPadrao] -= 70000;
                            PlayerInfo[playerid][Dinheiro] -= 63000;
                        }
                        case 6:
                        {
                            HouseInfo[idhouse][hPadrao] -= 150000;
                            PlayerInfo[playerid][Dinheiro] += 135000;
                        }
                        case 9:
                        {
                            HouseInfo[idhouse][hPadrao] -= 240000;
                            PlayerInfo[playerid][Dinheiro] += 216000;
                        }
                        case 12:
                        {
                            HouseInfo[idhouse][hPadrao] -= 350000;
                            PlayerInfo[playerid][Dinheiro] += 315000;
                        }
                        case 15:
                        {
                            HouseInfo[idhouse][hPadrao] -= 400000;
                            PlayerInfo[playerid][Dinheiro] += 360000;
                        }
                        case 18:
                        {
                            HouseInfo[idhouse][hPadrao] -= 500000;
                            PlayerInfo[playerid][Dinheiro] += 450000;
                        }
                        case 21:
                        {
                            HouseInfo[idhouse][hPadrao] -= 5000000;
                            PlayerInfo[playerid][Dinheiro] += 4500000;
                        }
                    }

                    HouseInfo[idhouse][hUp]--;

                    UpdatePlayerMoney(playerid);

                    UpgradeHouse(idhouse);
                    UpdateHouseExternal(idhouse);
                    UpdateHouses(idhouse);

                    SetPlayerVirtualWorld(playerid, HouseInfo[houseid[playerid]][hID]);
                    SetPlayerInterior(playerid, HouseInfo[houseid[playerid]][hInterior]);
                    SetPlayerPos(playerid, HouseInfo[houseid[playerid]][hInteriorX], HouseInfo[houseid[playerid]][hInteriorY], HouseInfo[houseid[playerid]][hInteriorZ]);
                    dentrocasa[playerid] = 1;
                    return 1;
                }
            }
        }
        case MAIN_HOUSE_SELF:
        {
            if(response)
            {
                if(listitem == 0)
                {
                    if(!strcmp(HouseInfo[idhouse][hVendendo], "Sim", true))
                        return SendClientMessage(playerid, Erro, "Sua casa está à venda, retira-a da venda para poder guardar dinheiro em seu cofre");

                    ShowPlayerDialog(playerid, MAIN_HOUSE_SELF_ADD, DIALOG_STYLE_INPUT, "{FFD700}Adicionar Dinheiro", "{FFFFFF}Digite abaixo a quantia de dinheiro que você deseja guardar no cofre de sua casa", "Continuar", "Cancelar");
                }
                else if(listitem == 1)
                {
                    ShowPlayerDialog(playerid, MAIN_HOUSE_SELF_REMOVE, DIALOG_STYLE_INPUT, "{FFD700}Remover Dinheiro", "{FFFFFF}Digite abaixo a quantia de dinheiro que você deseja retirar do cofre de sua casa", "Continuar", "Cancelar");
                }
            }
            return 1;
        }
        case MAIN_HOUSE_SELF_ADD:
        {
            if(response)
            {
                if(!IsNumeric(inputtext))
                    return ShowPlayerDialog(playerid, MAIN_HOUSE_SELF_ADD, DIALOG_STYLE_INPUT, "{FFD700}Adicionar Dinheiro", "{FFFFFF}Digite abaixo a quantia de dinheiro que você deseja guardar no cofre de sua casa\n{FF4000}Erro, Digite apenas numeros!", "Continuar", "Cancelar");

                if(strval(inputtext) > PlayerInfo[playerid][Dinheiro])
                    return ShowPlayerDialog(playerid, MAIN_HOUSE_SELF_ADD, DIALOG_STYLE_INPUT, "{FFD700}Adicionar Dinheiro", "{FFFFFF}Digite abaixo a quantia de dinheiro que você deseja guardar no cofre de sua casa\n{FF4000}Erro, você não tem todo esse dinheiro em mãos!", "Continuar", "Cancelar");

                PlayerInfo[playerid][Dinheiro] -= strval(inputtext);
                HouseInfo[houseid[playerid]][hCofre] += strval(inputtext);
                UpdatePlayerMoney(playerid);
                UpdateHouses(houseid[playerid]);

                format(String, sizeof(String), "Você guardou $%s no cofre de sua casa!", IsMoney(strval(inputtext), "."));
                SendClientMessage(playerid, C_PROPERTY, String);
            }
            return 1;
        }
        case MAIN_HOUSE_SELF_REMOVE:
        {
            if(response)
            {
                if(!IsNumeric(inputtext))
                    return ShowPlayerDialog(playerid, MAIN_HOUSE_SELF_REMOVE, DIALOG_STYLE_INPUT, "{FFD700}Adicionar Dinheiro", "{FFFFFF}Digite abaixo a quantia de dinheiro que você deseja retirar do cofre de sua casa\n{FF4000}Erro, Digite apenas numeros!", "Continuar", "Cancelar");

                if(strval(inputtext) > HouseInfo[houseid[playerid]][hCofre])
                    return ShowPlayerDialog(playerid, MAIN_HOUSE_SELF_REMOVE, DIALOG_STYLE_INPUT, "{FFD700}Adicionar Dinheiro", "{FFFFFF}Digite abaixo a quantia de dinheiro que você deseja retirar do cofre de sua casa\n{FF4000}Erro, você não tem todo esse dinheiro em sua casa!", "Continuar", "Cancelar");

                PlayerInfo[playerid][Dinheiro] += strval(inputtext);
                HouseInfo[houseid[playerid]][hCofre] -= strval(inputtext);
                UpdatePlayerMoney(playerid);
                UpdateHouses(houseid[playerid]);

                format(String, sizeof(String), "Você retirou $%s do cofre de sua casa!", IsMoney(strval(inputtext), "."));
                SendClientMessage(playerid, C_PROPERTY, String);
            }
            return 1;
        }
    }
    return 1;
}

stock UpdateHouses(idhouse)
{
    new _str[1000];
    mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Houses` SET `Nome`='%e', `M1`='%e', `M2`='%e', `M3`='%e', `M4`='%e', `M5`='%e', `M6`='%e', `Mensagem`='%e', `Alugando`='%e', `Vendendo`='%e', `Up`='%d', `UpMax`='%d', `Preco`='%d', `Custo`='%d', `Padrao`='%d', `Reais`='%d', `Cofre`='%d', `Interior`='%d', `Trancada`='%e', `Senha`='%e', `X`='%f', `Y`='%f', `Z`='%f', `InteriorX`='%f', `InteriorY`='%f', `InteriorZ`='%f' WHERE `ID`='%d'",
    HouseInfo[idhouse][hNome],
    HouseInfo[idhouse][hM1],
    HouseInfo[idhouse][hM2],
    HouseInfo[idhouse][hM3],
    HouseInfo[idhouse][hM4],
    HouseInfo[idhouse][hM5],
    HouseInfo[idhouse][hM6],
    HouseInfo[idhouse][hMensagem],
    HouseInfo[idhouse][hAlugando],
    HouseInfo[idhouse][hVendendo],
    HouseInfo[idhouse][hUp],
    HouseInfo[idhouse][hUpMax],
    HouseInfo[idhouse][hPreco],
    HouseInfo[idhouse][hCusto],
    HouseInfo[idhouse][hPadrao],
    HouseInfo[idhouse][hReais],
    HouseInfo[idhouse][hCofre],
    HouseInfo[idhouse][hInterior],
    HouseInfo[idhouse][hTrancada],
    HouseInfo[idhouse][hSenha],
    HouseInfo[idhouse][iconx],
    HouseInfo[idhouse][icony],
    HouseInfo[idhouse][iconz],
    HouseInfo[idhouse][hInteriorX],
    HouseInfo[idhouse][hInteriorY],
    HouseInfo[idhouse][hInteriorZ],
    HouseInfo[idhouse][hID]);
    mysql_query(IDConexao, _str);
    return 1;
}

forward LoadHouses(idhouse);
public LoadHouses(idhouse)
{
    if(cache_num_rows() != 0)
    {
        new var[128];

        cache_get_value_int(0, "ID", HouseInfo[idhouse][hID]);

        cache_get_value_name(0, "Nome", var);
        format(HouseInfo[idhouse][hNome], MAX_PLAYER_NAME, var);

        cache_get_value_name(0, "M1", var);
        format(HouseInfo[idhouse][hM1], MAX_PLAYER_NAME, var);

        cache_get_value_name(0, "M2", var);
        format(HouseInfo[idhouse][hM2], MAX_PLAYER_NAME, var);

        cache_get_value_name(0, "M3", var);
        format(HouseInfo[idhouse][hM3], MAX_PLAYER_NAME, var);

        cache_get_value_name(0, "M4", var);
        format(HouseInfo[idhouse][hM4], MAX_PLAYER_NAME, var);

        cache_get_value_name(0, "M5", var);
        format(HouseInfo[idhouse][hM5], MAX_PLAYER_NAME, var);

        cache_get_value_name(0, "M6", var);
        format(HouseInfo[idhouse][hM6], MAX_PLAYER_NAME, var);

        cache_get_value_name(0, "Mensagem", var);
        format(HouseInfo[idhouse][hMensagem], 30, var);

        cache_get_value_name(0, "Alugando", var);
        format(HouseInfo[idhouse][hAlugando], 5, var);

        cache_get_value_name(0, "Vendendo", var);
        format(HouseInfo[idhouse][hVendendo], 5, var);

        cache_get_value_int(0, "Up", HouseInfo[idhouse][hUp]);
        cache_get_value_int(0, "UpMax", HouseInfo[idhouse][hUpMax]);
        cache_get_value_int(0, "Preco", HouseInfo[idhouse][hPreco]);
        cache_get_value_int(0, "Custo", HouseInfo[idhouse][hCusto]);
        cache_get_value_int(0, "Padrao", HouseInfo[idhouse][hPadrao]);
        cache_get_value_int(0, "Reais", HouseInfo[idhouse][hReais]);
        cache_get_value_int(0, "Cofre", HouseInfo[idhouse][hCofre]);
        cache_get_value_int(0, "Interior", HouseInfo[idhouse][hInterior]);

        cache_get_value_name(0, "Trancada", var);
        format(HouseInfo[idhouse][hTrancada], 5, var);

        cache_get_value_name(0, "Senha", var);
        format(HouseInfo[idhouse][hSenha], 24, var);

        cache_get_value_float(0, "X", HouseInfo[idhouse][iconx]);
        cache_get_value_float(0, "Y", HouseInfo[idhouse][icony]);
        cache_get_value_float(0, "Z", HouseInfo[idhouse][iconz]);
        cache_get_value_float(0, "InteriorX", HouseInfo[idhouse][hInteriorX]);
        cache_get_value_float(0, "InteriorY", HouseInfo[idhouse][hInteriorY]);
        cache_get_value_float(0, "InteriorZ", HouseInfo[idhouse][hInteriorZ]);
        CreateHouseExternal(idhouse);
    }
    return 1;
}

forward CreateHouse(playerid, upgrademax, Cost, Standard, Reaiss, Float:iconX, Float:iconY, Float:iconZ);
public CreateHouse(playerid, upgrademax, Cost, Standard, Reaiss, Float:iconX, Float:iconY, Float:iconZ)
{
    new idhouse = cache_insert_id();

    HouseInfo[idhouse][hID] = idhouse;
    format(HouseInfo[idhouse][hNome], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[idhouse][hM1], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[idhouse][hM2], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[idhouse][hM3], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[idhouse][hM4], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[idhouse][hM5], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[idhouse][hM6], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[idhouse][hMensagem], 30, "N/A");
    format(HouseInfo[idhouse][hAlugando], 5, "N/A");
    format(HouseInfo[idhouse][hVendendo], 5, "Sim");
    HouseInfo[idhouse][hUp] = 1;
    HouseInfo[idhouse][hUpMax] = upgrademax;
    HouseInfo[idhouse][hCusto] = Cost;
    HouseInfo[idhouse][hPadrao] = Standard;
    HouseInfo[idhouse][hReais] = Reaiss;
    HouseInfo[idhouse][hCofre] = 0;
    format(HouseInfo[idhouse][hTrancada], 5, "N/A");
    format(HouseInfo[idhouse][hSenha], 5, "N/A");
    HouseInfo[idhouse][iconx] = iconX;
    HouseInfo[idhouse][icony] = iconY;
    HouseInfo[idhouse][iconz] = iconZ;

    GetPlayer2DZone(zone, MAX_ZONE_NAME, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony]);
    format(String, sizeof(String), "| VRC-Admin | O(A) %s %s criou a Casa ID %d localizada em %s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], HouseInfo[idhouse][hID], zone);
    SendClientMessageToAll(adm, String);

    CreateHouseExternal(idhouse);
    return 1;
}

stock UpdateHouseExternal(idhouse)
{
    DestroyDynamicMapIcon(HouseMapIcon[idhouse]);
    DestroyDynamicPickup(HousePickup[idhouse]);

    new House_Status[15];

    if(!strcmp(HouseInfo[idhouse][hTrancada], "Sim"))
    {
        format(House_Status, sizeof(House_Status), "Trancada");
    }
    else if(!strcmp(HouseInfo[idhouse][hTrancada], "N/A"))
    {
        format(House_Status, sizeof(House_Status), "Destrancada");
    }

    if(!strcmp(HouseInfo[idhouse][hNome], "N/A"))
    {
        if(HouseInfo[idhouse][hReais])
        {
            format(String, sizeof(String), "{31B404}Casa à Venda ( ID:%d )\n{FFFFFF}Upgrade do Interior: %d/%d\n{CE9F01}Valor: {31B404}$%s\n{CE9F01}Reais: {31B404}R$%d,00\n{6495ED}/ComprarCasa", HouseInfo[idhouse][hID], HouseInfo[idhouse][hUp], HouseInfo[idhouse][hUpMax], IsMoney(HouseInfo[idhouse][hCusto], "."), HouseInfo[idhouse][hReais]);
        }
        else if(!HouseInfo[idhouse][hReais])
        {
            format(String, sizeof(String), "{31B404}Casa à Venda ( ID:%d )\n{FFFFFF}Upgrade do Interior: %d/%d\n{CE9F01}Valor: {31B404}$%s\n{6495ED}/ComprarCasa", HouseInfo[idhouse][hID], HouseInfo[idhouse][hUp], HouseInfo[idhouse][hUpMax], IsMoney(HouseInfo[idhouse][hCusto], "."));
        }

        HousePickup[idhouse] = CreateDynamicPickup(1273, 23, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz], 0, -1, -1, 100.0);
        HouseMapIcon[idhouse] = CreateDynamicMapIcon(HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz], 31, -1, 0, -1, -1, 30.0);
        UpdateDynamic3DTextLabelText(HouseLabel[idhouse], 0xFFFFFFFF, String);
    }
    else if(strcmp(HouseInfo[idhouse][hNome], "N/A"))
    {
        if(!strcmp(HouseInfo[idhouse][hVendendo], "N/A"))
        {
            format(String, sizeof(String), "{FFD700}Casa de %s ( ID:%d )\n{FFFFFF}%s\n{FFFFFF}Upgrade do Interior: %d/%d\n{6BAF76}%s\n{6495ED}/EntrarCasa", HouseInfo[idhouse][hNome], HouseInfo[idhouse][hID], HouseInfo[idhouse][hMensagem], HouseInfo[idhouse][hUp], HouseInfo[idhouse][hUpMax], House_Status);
        }
        else if(!strcmp(HouseInfo[idhouse][hVendendo], "Sim"))
        {
            format(String, sizeof(String), "{FFD700}Casa de %s ( ID:%d )\n{FFFFFF}%s\n{FFFFFF}Upgrade do Interior: %d/%d\n{6BAF76}%s\n{FFFFFF}O(A) proprietário(a) está vendendo a casa por {019303}$%s\n{6495ED}/ComprarCasa", HouseInfo[idhouse][hNome], HouseInfo[idhouse][hID], HouseInfo[idhouse][hMensagem], HouseInfo[idhouse][hUp], HouseInfo[idhouse][hUpMax], House_Status,IsMoney(HouseInfo[idhouse][hPreco], "."));
        }

        HousePickup[idhouse] = CreateDynamicPickup(19522, 23, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz], 0, -1, -1, 100.0);
        HouseMapIcon[idhouse] = CreateDynamicMapIcon(HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz], 32, -1, 0, -1, -1, 30.0);
        UpdateDynamic3DTextLabelText(HouseLabel[idhouse], 0xFFFFFFFF, String);
    }
    return 1;
}

stock CreateHouseExternal(idhouse)
{
    new House_Status[15];

    if(!strcmp(HouseInfo[idhouse][hTrancada], "Sim"))
    {
        format(House_Status, sizeof(House_Status), "Trancada");
    }
    else if(!strcmp(HouseInfo[idhouse][hTrancada], "N/A"))
    {
        format(House_Status, sizeof(House_Status), "Destrancada");
    }

    if(!strcmp(HouseInfo[idhouse][hNome], "N/A"))
    {
        if(HouseInfo[idhouse][hReais])
        {
            format(String, sizeof(String), "{31B404}Casa à Venda ( ID:%d )\n{FFFFFF}Upgrade do Interior: %d/%d\n{CE9F01}Valor: {31B404}$%s\n{CE9F01}Reais: {31B404}R$%d,00\n{6495ED}/ComprarCasa", HouseInfo[idhouse][hID], HouseInfo[idhouse][hUp], HouseInfo[idhouse][hUpMax], IsMoney(HouseInfo[idhouse][hCusto], "."), HouseInfo[idhouse][hReais]);
        }
        else if(!HouseInfo[idhouse][hReais])
        {
            format(String, sizeof(String), "{31B404}Casa à Venda ( ID:%d )\n{FFFFFF}Upgrade do Interior: %d/%d\n{CE9F01}Valor: {31B404}$%s\n{6495ED}/ComprarCasa", HouseInfo[idhouse][hID], HouseInfo[idhouse][hUp], HouseInfo[idhouse][hUpMax], IsMoney(HouseInfo[idhouse][hCusto], "."));
        }

        HousePickup[idhouse] = CreateDynamicPickup(1273, 23, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz], 0, -1, -1, 100.0);
        HouseMapIcon[idhouse] = CreateDynamicMapIcon(HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz], 31, -1, 0, -1, -1, 30.0);
        HouseLabel[idhouse] = CreateDynamic3DTextLabel(String, 0xFFFFFFFF, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz]+0.50, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, -1, -1, 20.0, -1, 0);
    }
    else if(strcmp(HouseInfo[idhouse][hNome], "N/A"))
    {
        if(!strcmp(HouseInfo[idhouse][hVendendo], "N/A"))
        {
            format(String, sizeof(String), "{FFD700}Casa de %s ( ID:%d )\n{FFFFFF}%s\n{FFFFFF}Upgrade do Interior: %d/%d\n{6BAF76}%s\n{6495ED}/EntrarCasa", HouseInfo[idhouse][hNome], HouseInfo[idhouse][hID], HouseInfo[idhouse][hMensagem], HouseInfo[idhouse][hUp], HouseInfo[idhouse][hUpMax], House_Status);
        }
        else if(!strcmp(HouseInfo[idhouse][hVendendo], "Sim"))
        {
            format(String, sizeof(String), "{FFD700}Casa de %s ( ID:%d )\n{FFFFFF}%s\n{FFFFFF}Upgrade do Interior: %d/%d\n{6BAF76}%s\n{FFFFFF}O(A) proprietário(a) está vendendo a casa por {019303}$%s\n{6495ED}/ComprarCasa", HouseInfo[idhouse][hNome], HouseInfo[idhouse][hID], HouseInfo[idhouse][hMensagem], HouseInfo[idhouse][hUp], HouseInfo[idhouse][hUpMax], House_Status,IsMoney(HouseInfo[idhouse][hPreco], "."));
        }

        HousePickup[idhouse] = CreateDynamicPickup(19522, 23, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz], 0, -1, -1, 100.0);
        HouseMapIcon[idhouse] = CreateDynamicMapIcon(HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz], 32, -1, 0, -1, -1, 30.0);
        HouseLabel[idhouse] = CreateDynamic3DTextLabel(String, 0xFFFFFFFF, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz]+0.50, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, -1, -1, 20.0, -1, 0);
    }
    return 1;
}

stock UpgradeHouse(idhouse)
{
    switch(HouseInfo[idhouse][hUp])
    {
        case 1:
        {
            HouseInfo[idhouse][hInteriorX] = 267.4800;
            HouseInfo[idhouse][hInteriorY] = 305.0237;
            HouseInfo[idhouse][hInteriorZ] = 999.1484;
            HouseInfo[idhouse][hInterior] = 2;
        }
        case 2:
        {
            HouseInfo[idhouse][hInteriorX] = 244.5781;
            HouseInfo[idhouse][hInteriorY] = 305.0017;
            HouseInfo[idhouse][hInteriorZ] = 999.1484;
            HouseInfo[idhouse][hInterior] = 1;
        }
        case 3:
        {
            HouseInfo[idhouse][hInteriorX] = 2308.7378;
            HouseInfo[idhouse][hInteriorY] = -1211.6158;
            HouseInfo[idhouse][hInteriorZ] = 1049.0234;
            HouseInfo[idhouse][hInterior] = 6;
        }
        case 4:
        {
            HouseInfo[idhouse][hInteriorX] = 2333.0703;
            HouseInfo[idhouse][hInteriorY] = -1075.8330;
            HouseInfo[idhouse][hInteriorZ] = 1049.0234;
            HouseInfo[idhouse][hInterior] = 6;
        }
        case 5:
        {
            HouseInfo[idhouse][hInteriorX] = -42.6755;
            HouseInfo[idhouse][hInteriorY] = 1406.7865;
            HouseInfo[idhouse][hInteriorZ] = 1084.4297;
            HouseInfo[idhouse][hInterior] = 8;
        }
        case 6:
        {
            HouseInfo[idhouse][hInteriorX] = 223.1247;
            HouseInfo[idhouse][hInteriorY] = 1288.4781;
            HouseInfo[idhouse][hInteriorZ] = 1082.1406;
            HouseInfo[idhouse][hInterior] = 1;
        }
        case 7:
        {
            HouseInfo[idhouse][hInteriorX] = 261.0076;
            HouseInfo[idhouse][hInteriorY] = 1285.5956;
            HouseInfo[idhouse][hInteriorZ] = 1080.2578;
            HouseInfo[idhouse][hInterior] = 4;
        }
        case 8:
        {
            HouseInfo[idhouse][hInteriorX] = 226.1267;
            HouseInfo[idhouse][hInteriorY] = 1240.0048;
            HouseInfo[idhouse][hInteriorZ] = 1082.1406;
            HouseInfo[idhouse][hInterior] = 2;
        }
        case 9:
        {
            HouseInfo[idhouse][hInteriorX] = 2237.5969;
            HouseInfo[idhouse][hInteriorY] = -1079.6637;
            HouseInfo[idhouse][hInteriorZ] = 1049.0234;
            HouseInfo[idhouse][hInterior] = 2;
        }
        case 10:
        {
            HouseInfo[idhouse][hInteriorX] = 2365.2014;
            HouseInfo[idhouse][hInteriorY] = -1134.2975;
            HouseInfo[idhouse][hInteriorZ] = 1050.8750;
            HouseInfo[idhouse][hInterior] = 8;
        }
        case 11:
        {
            HouseInfo[idhouse][hInteriorX] = 295.2315;
            HouseInfo[idhouse][hInteriorY] = 1473.1649;
            HouseInfo[idhouse][hInteriorZ] = 1080.2578;
            HouseInfo[idhouse][hInterior] = 15;
        }
        case 12:
        {
            HouseInfo[idhouse][hInteriorX] = 260.6734;
            HouseInfo[idhouse][hInteriorY] = 1237.7909;
            HouseInfo[idhouse][hInteriorZ] = 1084.2578;
            HouseInfo[idhouse][hInterior] = 9;
        }
        case 13:
        {
            HouseInfo[idhouse][hInteriorX] = -261.8548;
            HouseInfo[idhouse][hInteriorY] = 1456.6841;
            HouseInfo[idhouse][hInteriorZ] = 1084.3672;
            HouseInfo[idhouse][hInterior] = 4;
        }
        case 14:
        {
            HouseInfo[idhouse][hInteriorX] = 235.3171;
            HouseInfo[idhouse][hInteriorY] = 1187.4275;
            HouseInfo[idhouse][hInteriorZ] = 1080.2578;
            HouseInfo[idhouse][hInterior] = 3;
        }
        case 15:
        {
            HouseInfo[idhouse][hInteriorX] = 2195.4243;
            HouseInfo[idhouse][hInteriorY] = -1204.5555;
            HouseInfo[idhouse][hInteriorZ] = 1049.0234;
            HouseInfo[idhouse][hInterior] = 6;
        }
        case 16:
        {
            HouseInfo[idhouse][hInteriorX] = 225.6588;
            HouseInfo[idhouse][hInteriorY] = 1022.2997;
            HouseInfo[idhouse][hInteriorZ] = 1084.0153;
            HouseInfo[idhouse][hInterior] = 7;
        }
        case 17:
        {
            HouseInfo[idhouse][hInteriorX] = 140.2825;
            HouseInfo[idhouse][hInteriorY] = 1367.8831;
            HouseInfo[idhouse][hInteriorZ] = 1083.8622;
            HouseInfo[idhouse][hInterior] = 5;
        }
        case 18:
        {
            HouseInfo[idhouse][hInteriorX] = 2317.8479;
            HouseInfo[idhouse][hInteriorY] = -1025.4985;
            HouseInfo[idhouse][hInteriorZ] = 1050.2109;
            HouseInfo[idhouse][hInterior] = 9;
        }
        case 19:
        {
            HouseInfo[idhouse][hInteriorX] = 0;
            HouseInfo[idhouse][hInteriorY] = 0;
            HouseInfo[idhouse][hInteriorZ] = 0;
            HouseInfo[idhouse][hInterior] = 0;
        }
        case 20:
        {
            HouseInfo[idhouse][hInteriorX] = 0;
            HouseInfo[idhouse][hInteriorY] = 0;
            HouseInfo[idhouse][hInteriorZ] = 0;
            HouseInfo[idhouse][hInterior] = 0;
        }
        case 21:
        {
            HouseInfo[idhouse][hInteriorX] = 1299.14;
            HouseInfo[idhouse][hInteriorY] = -794.77;
            HouseInfo[idhouse][hInteriorZ] = 1084.00;
            HouseInfo[idhouse][hInterior] = 5;
        }
    }
    return 1;
}

GetHouseID(playerid, pickupid)
{
    for(new i=1; i < MAX_HOUSES; i++)
    {
        if(pickupid == HousePickup[i] && IsPlayerInRangeOfPoint(playerid, 1.5, HouseInfo[i][iconx], HouseInfo[i][icony], HouseInfo[i][iconz]))
        {
            SendClientMessage(playerid, -1, "Para entrar na casa digite {CFCDCD}'/EntrarCasa'{FFFFFF} ou pressione a tecla {CFCDCD}'F'");
            return houseid[playerid] = i;
        }
    }
    return 0;
}

stock SpawnHouse(playerid)
{
    for(new i = 1; i < MAX_HOUSES; i++)
    {
        if(!strcmp(PlayerInfo[playerid][Nome], HouseInfo[i][hNome], true) ||
             !strcmp(PlayerInfo[playerid][Nome], HouseInfo[i][hM1], true) ||
             !strcmp(PlayerInfo[playerid][Nome], HouseInfo[i][hM2], true) ||
             !strcmp(PlayerInfo[playerid][Nome], HouseInfo[i][hM3], true) ||
             !strcmp(PlayerInfo[playerid][Nome], HouseInfo[i][hM4], true) ||
             !strcmp(PlayerInfo[playerid][Nome], HouseInfo[i][hM5], true) ||
             !strcmp(PlayerInfo[playerid][Nome], HouseInfo[i][hM6], true) )
        {
            SetSpawnInfo(playerid, 0, PlayerInfo[playerid][skin], HouseInfo[i][iconx], HouseInfo[i][icony], HouseInfo[i][iconz], 0, 0, 0, 0, 0, 0, 0);
            SendClientMessage(playerid, -1, "| INFO | Você tem 30 segundos para usar o comando {FF0000}/continuar{FFFFFF} e voltar a sua última posição");
            HouseContinueTimer[playerid] = SetTimerEx("OnHouseTimerContinue", 1000*30, false, "d", playerid);
            HouseContinue[playerid] = true;
            SpawnPlayer(playerid);
            return 1;
        }
    }

    SetPlayerInterior(playerid, PlayerInfo[playerid][Interior]);
    SetSpawnInfo(playerid, 0, PlayerInfo[playerid][skin], PlayerInfo[playerid][PosX], PlayerInfo[playerid][PosY], PlayerInfo[playerid][PosZ], PlayerInfo[playerid][PosA], 0, 0, 0, 0, 0, 0);

    SpawnPlayer(playerid);
    return 1;
}

forward OnHouseTimerContinue(playerid);
public OnHouseTimerContinue(playerid)
{
    KillTimer(HouseContinueTimer[playerid]);
    HouseContinue[playerid] = false;
    SendClientMessage(playerid, -1, "| INFO | Seu tempo para usar o comando {FF0000}/continuar{FFFFFF} acabou");
    return 1;
}

/******************************************************************************/
/*****************************| COMMANDS HOUSES |******************************/
/******************************************************************************/

CMD:dormir(playerid)
{
    if(dentrocasa[playerid] != 1)
        return SendClientMessage(playerid, Erro, "Você não está em uma casa");

    if(!IsPlayerInRangeOfPoint(playerid, 30.0, HouseInfo[houseid[playerid]][hInteriorX], HouseInfo[houseid[playerid]][hInteriorY], HouseInfo[houseid[playerid]][hInteriorZ]))
        return SendClientMessage(playerid, Erro, "Você está muito longe da porta da sua casa");

    if(strcmp(PlayerInfo[playerid][Nome], HouseInfo[houseid[playerid]][hNome], true))
        return SendClientMessage(playerid, Erro, "Você não está em sua casa");

    if(Sleeping[playerid])
        return SendClientMessage(playerid, Erro, "Você já está dormindo");

    if(Progress[playerid][Sono] < 90.0)
        return SendClientMessage(playerid, Erro, "Você não está com sono");

    TimerSleeping[playerid] = SetTimerEx("Sleep", 1000, true, "d", playerid);
    return 1;
}
CMD:salvarcasas(playerid)
{
    for(new id=1; id < MAX_HOUSES; id++)
    {
        GetPlayer2DZone(zone, MAX_ZONE_NAME, HouseInfo[id][iconx], HouseInfo[id][icony]);
        format(String, 128, "| VRC-Admin | O(A) %s %s[%d] salvou a casa ID:%d localizada em %s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid, id, zone);
        SendClientMessageToAll(adm, String);

        UpgradeHouse(id);
        UpdateHouseExternal(id);
        UpdateHouses(id);
    }
    return 1;
}
CMD:continuar(playerid)
{
    if(HouseContinue[playerid] == false)
        return SendClientMessage(playerid, Erro, "Seu tempo para usar o comando /continuar acabou");

    HouseContinue[playerid] = false;
    SetPlayerInterior(playerid, PlayerInfo[playerid][Interior]);
    SetPlayerPos(playerid, PlayerInfo[playerid][PosX], PlayerInfo[playerid][PosY], PlayerInfo[playerid][PosZ]);
    SendClientMessage(playerid, -1, "| INFO | Você foi até sua última posição");
    KillTimer(HouseContinueTimer[playerid]);
    return 1;
}
CMD:ircasa(playerid, params[])
{
    if(!IsPlayerHelper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new id;

    if(sscanf(params, "d", id))
        return SendClientMessage(playerid, Erro, "Digite: /IrCasa [id-casa]");

    if(id < 1 || id >= MAX_HOUSES)
        return SendClientMessage(playerid, Erro, "Esse ID de Casa não existe");

    SetPlayerInterior(playerid, 0);
    SetPlayerPos(playerid, HouseInfo[id][iconx], HouseInfo[id][icony], HouseInfo[id][iconz]);
    format(String, sizeof(String), "| VRC-Admin | Você se teletransportou para a Casa ID %d", id);
    SendClientMessage(playerid, adm, String);
    return 1;
}
CMD:criarcasa(playerid, params[])
{
    if(!IsPlayerDeveloper(playerid))
		return SendClientMessage(playerid, Erro, "Comando Inválido");

    new Float:hPos[3], Cost, Standard, reaiss, upgrademax;

    if(sscanf(params, "dd", upgrademax, reaiss))
        return SendClientMessage(playerid, Erro, "Digite: /CriarCasa [Maxímo-Upgrade][Reais]");

    GetPlayerPos(playerid, hPos[0], hPos[1], hPos[2]);

    if(!(upgrademax == 3 || upgrademax == 6 || upgrademax == 9 || upgrademax == 12 || upgrademax == 15 || upgrademax == 18))
        return SendClientMessage(playerid, Erro, "Upgrades permitidos: 3, 6, 9, 12, 15 e 18");

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
    else if(upgrademax == 21)
    {
        Cost = 5000000;
        Standard = 4500000;
    }

    new query[500];
    mysql_format(IDConexao, query, sizeof(query), "INSERT INTO `Houses` (`UpMax`,`Custo`, `Padrao`, `Reais`, `X`, `Y`, `Z`) VALUES ('%d', '%d', '%d', '%d', '%f', '%f', '%f')", upgrademax, Cost, Standard, reaiss, hPos[0], hPos[1], hPos[2]);
    mysql_tquery(IDConexao, query, "CreateHouse", "dddddfff", playerid, upgrademax, Cost, Standard, reaiss, hPos[0], hPos[1], hPos[2]);
    return 1;
}
CMD:editarcasa(playerid, params[])
{
    if(!IsPlayerDeveloper(playerid))
		return SendClientMessage(playerid, Erro, "Comando Inválido");

    new id, upgrademax;

    if(sscanf(params, "dd", id, upgrademax))
        return SendClientMessage(playerid, Erro, "Digite: /EditarCasa [id-casa] [máxímo-upgrade]");

    if(id < 1 || id >= MAX_HOUSES)
        return SendClientMessage(playerid, Erro, "Esse id de casa não existe");

    if(!(upgrademax == 3 || upgrademax == 6 || upgrademax == 9 || upgrademax == 12 || upgrademax == 15 || upgrademax == 18))
        return SendClientMessage(playerid, Erro, "Upgrades permitidos: 3, 6, 9, 12, 15 e 18");

    if(!IsPlayerInRangeOfPoint(playerid, 15.0, HouseInfo[id][iconx], HouseInfo[id][icony], HouseInfo[id][iconz]))
        return SendClientMessage(playerid, Erro, "Você não está perto da porta dessa casa");

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
        case 21:
        {
            HouseInfo[id][hCusto] = 5000000;
            HouseInfo[id][hPadrao] = 4500000;
        }
    }

    HouseInfo[id][hUpMax] = upgrademax;
    GetPlayerPos(playerid, HouseInfo[id][iconx], HouseInfo[id][icony], HouseInfo[id][iconz]);

    format(String, sizeof(String), "| VRC-Admin | O(A) %s %s editou a Casa ID %d", CargoAdmin(playerid), PlayerInfo[playerid][Nome], id);
    SendClientMessageToAll(adm, String);
    UpgradeHouse(id);
    UpdateHouseExternal(id);
    UpdateHouses(id);
    return 1;
}
CMD:liberarcasa(playerid, params[])
{
    if(!IsPlayerDeveloper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new idhousee;

    if(sscanf(params, "d", idhousee))
        return SendClientMessage(playerid, Erro, "Digite: /LiberarCasa [id-casa]");

    if(idhousee < 1 || idhousee >= MAX_HOUSES)
        return SendClientMessage(playerid, Erro, "Esse id de casa não existe");

    if(strcmp(HouseInfo[idhousee][hNome], "N/A", true)==0)
        return SendClientMessage(playerid, Erro, "Essa casa já está libera e não tem dono(a)");

    if(dentrocasa[playerid] == 1)
        return SendClientMessage(playerid, Erro, "Você não pode liberar nenhuma casa estando dentro de uma");

    GetPlayer2DZone(zone, MAX_ZONE_NAME, HouseInfo[idhousee][iconx], HouseInfo[idhousee][icony]);
    format(String, sizeof(String), "| VRC-Admin | O(A) %s %s liberou a Casa ID %d que pertencia a %s localizada em %s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], idhousee, HouseInfo[idhousee][hNome], zone);
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

    UpgradeHouse(houseid[playerid]);
    UpdateHouseExternal(idhousee);
    UpdateHouses(idhousee);
    return 1;
}
CMD:menucasa(playerid)
{
    new txt[500];

    if(dentrocasa[playerid] != 1)
        return SendClientMessage(playerid, Erro, "Você não está em uma casa");

    if(!strcmp(PlayerInfo[playerid][Nome], HouseInfo[houseid[playerid]][hNome], true))
    {
        strcat(txt, "{FF0000}Funções \t\t {1CEB00}Status \n");

        format(String, sizeof(String), "{FFFFFF}Mensagem \t\t %s\n", HouseInfo[houseid[playerid]][hMensagem]);
        strcat(txt, String);
        format(String, sizeof(String), "{FFFFFF}Senha \t\t {FF4500}%s\n", HouseInfo[houseid[playerid]][hSenha]);
        strcat(txt, String);

        if(!strcmp(HouseInfo[houseid[playerid]][hTrancada], "Sim", true))
            { strcat(txt, "{FFFFFF}Trancada \t\t Sim\n"); }

        if(!strcmp(HouseInfo[houseid[playerid]][hTrancada], "N/A", true))
            { strcat(txt, "{FFFFFF}Trancada \t\t Não\n"); }

        format(String, sizeof(String), "{FFFFFF}Cofre \t\t {2CC06B}$%s\n", IsMoney(HouseInfo[houseid[playerid]][hCofre], "."));
        strcat(txt, String);
        format(String, sizeof(String), "{FFFFFF}Upgrade \t\t {87CEFF}%d/%d \n", HouseInfo[houseid[playerid]][hUp], HouseInfo[houseid[playerid]][hUpMax]);
        strcat(txt, String);
        strcat(txt, "{FFFFFF}Morador(a) \t\t \n");
        format(String, sizeof(String), "{FFFFFF}Vender/Alterar Preço Casa \t\t {2CC06B}$%s\n", IsMoney(HouseInfo[houseid[playerid]][hPreco], "."));
        strcat(txt, String);
        format(String, sizeof(String), "{FFFFFF}Liberar Casa P/ o Servidor \t\t {2CC06B}$%s\n", IsMoney(HouseInfo[houseid[playerid]][hPadrao], "."));
        strcat(txt, String);
        ShowPlayerDialog(playerid, MAIN_HOUSE, DIALOG_STYLE_TABLIST_HEADERS, "{FFD700}Menu Casa", txt, "Continuar", "Cancelar");
    }
    else if(!strcmp(PlayerInfo[playerid][Nome], HouseInfo[houseid[playerid]][hM1], true) || !strcmp(PlayerInfo[playerid][Nome], HouseInfo[houseid[playerid]][hM2], true) || !strcmp(PlayerInfo[playerid][Nome], HouseInfo[houseid[playerid]][hM3], true) || !strcmp(PlayerInfo[playerid][Nome], HouseInfo[houseid[playerid]][hM4], true) || !strcmp(PlayerInfo[playerid][Nome], HouseInfo[houseid[playerid]][hM5], true) || !strcmp(PlayerInfo[playerid][Nome], HouseInfo[houseid[playerid]][hM6], true))
    {
        strcat(txt, "{FFFFFF}Revogar Moradia \n");
        ShowPlayerDialog(playerid, MAIN_HOUSE, DIALOG_STYLE_LIST, "{FFD700}Menu Casa", txt, "Continuar", "Cancelar");
    }
    else
    {
        SendClientMessage(playerid, Erro, "Você não é dono(a)/morador(a) dessa casa");
    }
    return 1;
}
CMD:entrarcasa(playerid)
{
    if(dentrocasa[playerid] == 1)
        return SendClientMessage(playerid, Erro, "Você já está em uma casa");

    if(!IsPlayerInRangeOfPoint(playerid, 1.5, HouseInfo[houseid[playerid]][iconx], HouseInfo[houseid[playerid]][icony], HouseInfo[houseid[playerid]][iconz]))
        return SendClientMessage(playerid, Erro, "Você não está em nenhuma porta de casa");

    if(strcmp(HouseInfo[houseid[playerid]][hNome], PlayerInfo[playerid][Nome], true)==0)
    {
        format(String, sizeof(String), "Bem vindo(a) a Casa ID %d em que você mora, Digite: /MenuCasa para acessar o menu!", HouseInfo[houseid[playerid]][hID]);
    }
    else
    {
        if(strcmp(HouseInfo[houseid[playerid]][hTrancada], "Sim", true)==0)
            return ShowPlayerDialog(playerid, MAIN_HOUSE_PASS, DIALOG_STYLE_INPUT, "{FF0000}Casa trancada", "{FFFFFF}Digite abaixo a senha da casa para entrar", "Entrar", "Cancelar");

        format(String, sizeof(String), "Bem vindo(a) a Casa ID %d que pertence a %s", HouseInfo[houseid[playerid]][hID], HouseInfo[houseid[playerid]][hNome]);
    }

    dentrocasa[playerid] = 1;
    SendClientMessage(playerid, C_PROPERTY, String);
    SetPlayerVirtualWorld(playerid, HouseInfo[houseid[playerid]][hID]);
    SetPlayerInterior(playerid, HouseInfo[houseid[playerid]][hInterior]);
    SetPlayerPos(playerid, HouseInfo[houseid[playerid]][hInteriorX], HouseInfo[houseid[playerid]][hInteriorY], HouseInfo[houseid[playerid]][hInteriorZ]);
    return 1;
}
CMD:saircasa(playerid)
{
    if(dentrocasa[playerid] != 1)
        return SendClientMessage(playerid, Erro, "Você não está em uma casa");

    if(!IsPlayerInRangeOfPoint(playerid, 2.0, HouseInfo[houseid[playerid]][hInteriorX], HouseInfo[houseid[playerid]][hInteriorY], HouseInfo[houseid[playerid]][hInteriorZ]))
        return SendClientMessage(playerid, Erro, "Você está longe da porta");

    if(!strcmp(HouseInfo[houseid[playerid]][hNome], PlayerInfo[playerid][Nome], true))
    {
        format(String, sizeof(String), "Você saiu da sua casa %s", HouseInfo[houseid[playerid]][hNome]);
    }
    else
    {
        format(String, sizeof(String), "Você saiu da casa que pertence a %s", HouseInfo[houseid[playerid]][hNome]);
    }

    dentrocasa[playerid] = 0;
    SendClientMessage(playerid, C_PROPERTY, String);
    SetPlayerVirtualWorld(playerid, 0);
    SetPlayerInterior(playerid, 0);
    SetPlayerPos(playerid, HouseInfo[houseid[playerid]][iconx], HouseInfo[houseid[playerid]][icony], HouseInfo[houseid[playerid]][iconz]);
    return 1;
}
CMD:comprarcasa(playerid)
{
    if(!IsPlayerInRangeOfPoint(playerid, 1.5, HouseInfo[houseid[playerid]][iconx], HouseInfo[houseid[playerid]][icony], HouseInfo[houseid[playerid]][iconz]))
        return SendClientMessage(playerid, Erro, "Você não está em nenhuma porta de casa");

    new _str[500], id;

    mysql_format(IDConexao, _str, sizeof(_str), "SELECT `Nome` FROM `Houses` WHERE `Nome`='%e'", PlayerInfo[playerid][Nome]);
    mysql_query(IDConexao, _str);

    if(cache_num_rows() > 0)
        return SendClientMessage(playerid, Erro, "Você já tem uma casa");

    if(!strcmp(HouseInfo[houseid[playerid]][hVendendo], "N/A"))
        return SendClientMessage(playerid, Erro, "Essa casa não está a venda");

    GetPlayer2DZone(zone, MAX_ZONE_NAME, HouseInfo[houseid[playerid]][iconx], HouseInfo[houseid[playerid]][icony]);

    if(!strcmp(HouseInfo[houseid[playerid]][hNome], "N/A"))
    {
        if(HouseInfo[houseid[playerid]][hReais])
        {
            if(PlayerInfo[playerid][Dinheiro] < HouseInfo[houseid[playerid]][hCusto] || PlayerInfo[playerid][Reais] < HouseInfo[houseid[playerid]][hReais]) return SendClientMessage(playerid, Erro, "Você não tem esse dinheiro e/ou reais suficiente");
        }
        else if(!HouseInfo[houseid[playerid]][hReais])
        {
            if(PlayerInfo[playerid][Dinheiro] < HouseInfo[houseid[playerid]][hCusto]) return SendClientMessage(playerid, Erro, "Você não tem esse dinheiro em mãos");
        }

        PlayerInfo[playerid][Reais] -= HouseInfo[houseid[playerid]][hReais];
        PlayerInfo[playerid][Dinheiro] -= HouseInfo[houseid[playerid]][hCusto];
        format(String, sizeof(String), "O(A) Jogador(a) %s comprou a casa ID %d localizada em %s", PlayerInfo[playerid][Nome], HouseInfo[houseid[playerid]][hID], zone);
    }
    else if(strcmp(HouseInfo[houseid[playerid]][hNome], "N/A"))
    {
        id = GetPlayerID(HouseInfo[houseid[playerid]][hNome]);

        if(!PlayerInfo[id][Logado])
            return SendClientMessage(playerid, Erro, "O(A) Proprietário(a) dessa casa não está conectado(a)");

        if(PlayerInfo[playerid][Dinheiro] < HouseInfo[houseid[playerid]][hPreco])
            return SendClientMessage(playerid, Erro, "Você não tem esse dinheiro em mãos");

        format(String, sizeof(String), "O(A) Jogador(a) %s comprou a sua casa e o seu dinheiro foi transferido direto pra sua conta bancária!", PlayerInfo[playerid][Nome], HouseInfo[houseid[playerid]][hID], HouseInfo[houseid[playerid]][hNome], zone);
        SendClientMessage(id, -1, String);
        format(String, sizeof(String), "O(A) Jogador(a) %s comprou a casa ID %d que pertencia ao jogador(a) %s localizada em %s", PlayerInfo[playerid][Nome], HouseInfo[houseid[playerid]][hID], HouseInfo[houseid[playerid]][hNome], zone);

        PlayerInfo[id][SaldoBancario] += HouseInfo[houseid[playerid]][hPreco];
        PlayerInfo[playerid][Dinheiro] -= HouseInfo[houseid[playerid]][hPreco];
    }

    HouseInfo[houseid[playerid]][hID] = houseid[playerid];
    format(HouseInfo[houseid[playerid]][hNome], MAX_PLAYER_NAME, PlayerInfo[playerid][Nome]);
    format(HouseInfo[houseid[playerid]][hM1], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[houseid[playerid]][hM2], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[houseid[playerid]][hM3], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[houseid[playerid]][hM4], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[houseid[playerid]][hM5], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[houseid[playerid]][hM6], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[houseid[playerid]][hMensagem], 15, "N/A");
    format(HouseInfo[houseid[playerid]][hAlugando], 15, "N/A");
    format(HouseInfo[houseid[playerid]][hVendendo], 5, "N/A");
    HouseInfo[houseid[playerid]][hUp] = 1;
    HouseInfo[houseid[playerid]][hPreco] = 0;
    format(HouseInfo[houseid[playerid]][hTrancada], 5, "N/A");
    format(HouseInfo[houseid[playerid]][hSenha], 24, "N/A");

    SendClientMessageToAll(-1, String);

    UpdatePlayerMoney(playerid);
    UpdatePlayerReais(playerid);

    UpgradeHouse(houseid[playerid]);
    UpdateHouseExternal(houseid[playerid]);
    UpdateHouses(houseid[playerid]);
    return 1;
}
