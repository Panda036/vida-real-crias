#include YSI\y_hooks

#define MAX_HOUSES (869+1)
#define MAIN_HOUSE_COMMAND              10000
#define MAIN_HOUSE                      10001
#define MAIN_HOUSE_ALTER_MSG            10002
#define MAIN_HOUSE_ALTER_PASS           10003
#define MAIN_HOUSE_RELEASE_AGREE        10004
#define MAIN_HOUSE_PASS                 10005
#define MAIN_HOUSE_SELL_INPUT           10006
#define MAIN_HOUSE_SELL_LIST            10007
#define MAIN_HOUSE_RESIDENTS            10008
#define MAIN_HOUSE_RESIDENTS_M1         10009
#define MAIN_HOUSE_RESIDENTS_M2         10010
#define MAIN_HOUSE_RESIDENTS_M3         10011
#define MAIN_HOUSE_RESIDENTS_M4         10012
#define MAIN_HOUSE_RESIDENTS_M5         10013
#define MAIN_HOUSE_RESIDENTS_M6         10014
#define MAIN_HOUSE_RESIDENTS_INPUT      10015
#define MAIN_HOUSE_UPGRADE              10016

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
    hPadrao,
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
new playerinterior[MAX_PLAYERS]=-1;
new houseid[MAX_PLAYERS];
new playerworld[MAX_PLAYERS];
new dentrocasa[MAX_PLAYERS];
new HouseContinueTimer[MAX_PLAYERS];
new bool:HouseContinue[MAX_PLAYERS];

hook OnGameModeInit()
{
    new dbhouse[1000];
    strins(dbhouse,"CREATE TABLE IF NOT EXISTS Casas ", strlen(dbhouse));
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
    strins(dbhouse,"Trancada varchar(3) NOT NULL DEFAULT 'N/A',", strlen(dbhouse));
    strins(dbhouse,"Senha varchar(24) NOT NULL DEFAULT 'N/A',", strlen(dbhouse));
    strins(dbhouse,"X float NOT NULL,", strlen(dbhouse));
    strins(dbhouse,"Y float NOT NULL,", strlen(dbhouse));
    strins(dbhouse,"Z float NOT NULL)", strlen(dbhouse));
    mysql_query(IDConexao, dbhouse, false);
    LoadHouse();
    return 1;
}

hook OnGameModeExit()
{
    for(new i=1; i < MAX_HOUSES; i++)
	{
        DestroyDynamicMapIcon(HouseMapIcon[i]);
        Delete3DTextLabel(HouseLabel[i]);
        DestroyPickup(HousePickup[i]);
	}
	return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    HouseMapIcon[playerid] = 0;
    HousePickup[playerid] = 0;
    playerinterior[playerid] = -1;
    houseid[playerid] = 0;
    playerworld[playerid] = 0;
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
        else if(dentrocasa[playerid] == 1 && GetPlayerInterior(playerid) == playerinterior[playerid] && IsPlayerInRangeOfPoint(playerid, 2.0, HouseInfo[idhouse][hInteriorX], HouseInfo[idhouse][hInteriorY], HouseInfo[idhouse][hInteriorZ]))
        {
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
                switch(listitem)
                {
                    case 0:
                    {
                        ShowPlayerDialog(playerid, MAIN_HOUSE_ALTER_MSG, DIALOG_STYLE_INPUT, "{87CEFF}Alterar Mensagem", "{FFFFFF}Digite abaixo a nova mensagem da sua casa", "Selecionar", "Cancelar");
                    }
                    case 1:
                    {
                        ShowPlayerDialog(playerid, MAIN_HOUSE_ALTER_PASS, DIALOG_STYLE_INPUT, "{87CEFF}Alterar Senha", "{FFFFFF}Digite abaixo a nova senha da sua casa", "Selecionar", "Cancelar");
                    }
                    case 2:
                    {
                        if(dentrocasa[playerid] != 1)
                            return SendClientMessage(playerid, 0xFF4000AA, "| ERRO | Você não está em uma casa");

                        if(strcmp(HouseInfo[idhouse][hNome], PlayerInfo[playerid][Nome], true))
                            return SendClientMessage(playerid, 0xFF4000AA, "| ERRO | Você não é dono(a)/morador(a) dessa casa");

                        if(strcmp(HouseInfo[idhouse][hTrancada], "Sim", true)==0)
                        {
                            format(HouseInfo[idhouse][hTrancada], 24, "N/A");
                            format(String, sizeof(String),"| INFO | Agora a sua casa está aberta!", inputtext);
                            SendClientMessage(playerid, -1, String);
                            DestroyDynamicMapIcon(HouseMapIcon[idhouse]);
                            Delete3DTextLabel(HouseLabel[idhouse]);
                            DestroyPickup(HousePickup[idhouse]);
                            CreateHouseExternal(idhouse);

                        } else if(strcmp(HouseInfo[idhouse][hTrancada], "N/A", true)==0) {

                            format(HouseInfo[idhouse][hTrancada], 24, "Sim");
                            format(String, sizeof(String),"| INFO | Agora a sua casa está fechada com a senha {FF0000}%s", HouseInfo[idhouse][hSenha]);
                            SendClientMessage(playerid, -1, String);
                            DestroyDynamicMapIcon(HouseMapIcon[idhouse]);
                            Delete3DTextLabel(HouseLabel[idhouse]);
                            DestroyPickup(HousePickup[idhouse]);
                            CreateHouseExternal(idhouse);
                        }
                        UpdateHouses(idhouse);
                    }
                    case 3:
                    {
                        ShowPlayerDialog(playerid, MAIN_HOUSE_UPGRADE, DIALOG_STYLE_LIST, "{87CEFF}Configurações Casa", "{FFFFFF}Upgrade do Interior\nDowngrade do Interior", "Selecionar", "Cancelar");
                    }
                    case 4:
                    {
                        new txt[300];

                        if(HouseInfo[idhouse][hUp] >= 1 && HouseInfo[idhouse][hUp] <= 2)
                        {
                            ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{87CEFF}Configurações Casa", "{FF4000}Sua casa não tem upgrade necessário para colocar moradores!", "Fechar", #);
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
                        ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS, DIALOG_STYLE_LIST, "{87CEFF}Configurações Casa", txt, "Selecionar", "Cancelar");
                    }
                    case 5:
                    {
                        new txt[200];

                        strcat(txt, "{FF0000}Funções \t\t {1CEB00}Status \n");

                        if(strcmp(HouseInfo[idhouse][hVendendo], "Sim", true)==0)
                            { strcat(txt, "{FFFFFF}Vendendo: \t\t Sim\n");  }

                        if(strcmp(HouseInfo[idhouse][hVendendo], "N/A", true)==0)
                            { strcat(txt, "{FFFFFF}Vendendo: \t\t Não\n"); }

                        format(String, sizeof(String), "{FFFFFF}Alterar Valor: \t\t $%s \n", IsMoney(HouseInfo[idhouse][hPreco], "."));
                        strcat(txt, String);
                        ShowPlayerDialog(playerid, MAIN_HOUSE_SELL_LIST, DIALOG_STYLE_TABLIST_HEADERS, "{87CEFF}Configurações Casa", txt, "Selecionar", "Cancelar");
                    }
                    case 6:
                    {
                        ShowPlayerDialog(playerid, MAIN_HOUSE_RELEASE_AGREE, DIALOG_STYLE_MSGBOX, "{87CEFF}Configurações Casa", "{FFFFFF}Tem certeza que quer liberar sua casa?", "Sim", "Não");
                    }
                }
            }
        }
        case MAIN_HOUSE_ALTER_MSG:
        {
            if(response)
            {
                if(dentrocasa[playerid] == 0)
                    return SendClientMessage(playerid, 0xFF4000AA, "| ERRO | Você não está em uma casa");

                if(strcmp(HouseInfo[idhouse][hNome], PlayerInfo[playerid][Nome], true))
                    return SendClientMessage(playerid, 0xFF4000AA, "| ERRO | Você não é dono(a)/morador(a) dessa casa");

                if(!IsValidMessageHouse(inputtext))
                    return ShowPlayerDialog(playerid, MAIN_HOUSE_ALTER_MSG, DIALOG_STYLE_INPUT, "{87CEFF}Alterar Mensagem", "{FFFFFF}Digite abaixo a nova mensagem da sua casa \n{FF0000}Alguns caracteres especias não são permitidos!", "Selecionar", "Cancelar");

                format(HouseInfo[idhouse][hMensagem], 30, inputtext);
                format(String, sizeof(String),"| INFO | Agora a mensagem da sua casa é {FF0000}%s", inputtext);
                SendClientMessage(playerid, -1, String);
                DestroyDynamicMapIcon(HouseMapIcon[idhouse]);
                Delete3DTextLabel(HouseLabel[idhouse]);
                DestroyPickup(HousePickup[idhouse]);
                CreateHouseExternal(idhouse);
                UpdateHouses(idhouse);
            }
        }
        case MAIN_HOUSE_ALTER_PASS:
        {
            if(response)
            {
                if(dentrocasa[playerid] == 0)
                    return SendClientMessage(playerid, 0xFF4000AA, "| ERRO | Você não está em uma casa");

                if(strcmp(HouseInfo[idhouse][hNome], PlayerInfo[playerid][Nome], true))
                    return SendClientMessage(playerid, 0xFF4000AA, "| ERRO | Você não é dono(a)/morador(a) dessa casa");

                if(!IsValidUsername(inputtext))
                    return ShowPlayerDialog(playerid, MAIN_HOUSE_ALTER_PASS, DIALOG_STYLE_INPUT, "{87CEFF}Alterar Senha", "{FFFFFF}Digite abaixo a nova senha da sua casa \n{FF0000}Alguns caracteres especias não são permitidos!", "Selecionar", "Cancelar");

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
                if(dentrocasa[playerid] == 0)
                    return SendClientMessage(playerid, 0xFF4000AA, "| ERRO | Você não está em uma casa");

                if(strcmp(HouseInfo[idhouse][hNome], PlayerInfo[playerid][Nome], true))
                    return SendClientMessage(playerid, 0xFF4000AA, "| ERRO | Você não é dono(a)/morador(a) dessa casa");

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
                format(String, sizeof(String), "| CASAS | O(A) Jogador(a) %s liberou a casa ID %d localizada em %s", PlayerInfo[playerid][Nome], HouseInfo[idhouse][hID], zone);
                SendClientMessageToAll(-1, String);

                SetPlayerPos(playerid, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz]);
                SetPlayerInterior(playerid, playerworld[playerid]);
                SetPlayerVirtualWorld(playerid, 0);
                dentrocasa[playerid] = 0;

                DestroyDynamicMapIcon(HouseMapIcon[idhouse]);
                Delete3DTextLabel(HouseLabel[idhouse]);
                DestroyPickup(HousePickup[idhouse]);
                CreateHouseExternal(idhouse);
                UpdateHouses(idhouse);
            }
        }
        case MAIN_HOUSE_PASS:
        {
            if(response)
            {
                if(strlen(inputtext) == 0)
                    return ShowPlayerDialog(playerid, MAIN_HOUSE_PASS, DIALOG_STYLE_INPUT, "{87CEFF}Configurações Casa", "{FFFFFF}Digite abaixo a senha da casa para entrar \n{FF0000}Senha incorreta, tente novamente!", "Entrar", "Cancelar");

                if(strcmp(inputtext, HouseInfo[idhouse][hSenha], true))
                    return ShowPlayerDialog(playerid, MAIN_HOUSE_PASS, DIALOG_STYLE_INPUT, "{87CEFF}Configurações Casa", "{FFFFFF}Digite abaixo a senha da casa para entrar \n{FF0000}Senha incorreta, tente novamente!", "Entrar", "Cancelar");

                playerworld[playerid] = GetPlayerVirtualWorld(playerid);
                SetPlayerVirtualWorld(playerid, HouseInfo[idhouse][hID]);
                SetPlayerInterior(playerid, HouseInfo[idhouse][hInterior]);
                SetPlayerPos(playerid, HouseInfo[idhouse][hInteriorX], HouseInfo[idhouse][hInteriorY], HouseInfo[idhouse][hInteriorZ]);
                playerinterior[playerid] = HouseInfo[idhouse][hInterior];
                dentrocasa[playerid] = 1;
                format(String, sizeof(String), "| CASA | Bem vindo(a) a Casa ID %d que pertence a %s", HouseInfo[idhouse][hID], HouseInfo[idhouse][hNome]);
                SendClientMessage(playerid, 0x87CEFFAA, String);
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
                        if(strcmp(HouseInfo[idhouse][hVendendo], "Sim", true)==0)
                        {
                            format(HouseInfo[idhouse][hVendendo], 5, "N/A");
                            SendClientMessage(playerid, -1, "| CASA | Agora sua casa não está mas à venda!");
                        }
                        else if(strcmp(HouseInfo[idhouse][hVendendo], "N/A", true)==0)
                        {
                            if(HouseInfo[idhouse][hPreco] == 0)
                            {
                                HouseInfo[idhouse][hPreco] = 0;
                                HouseInfo[idhouse][hPreco] += HouseInfo[idhouse][hPadrao];
                            }

                            format(HouseInfo[idhouse][hVendendo], 5, "Sim");
                            format(String, sizeof(String),"| CASA | Agora sua casa está à venda no valor de {019303}$%s{FFFFFF}!", IsMoney(HouseInfo[idhouse][hPreco], "."));
                            SendClientMessage(playerid, -1, String);
                        }

                        DestroyDynamicMapIcon(HouseMapIcon[idhouse]);
                        Delete3DTextLabel(HouseLabel[idhouse]);
                        DestroyPickup(HousePickup[idhouse]);
                        CreateHouseExternal(idhouse);
                        UpdateHouses(idhouse);
                    }
                    case 1:
                    {
                        ShowPlayerDialog(playerid, MAIN_HOUSE_SELL_INPUT, DIALOG_STYLE_INPUT, "{87CEFF}Configurações Casa", "{FFFFFF}Digite abaixo o valor que será somado com o valor padrão \nde sua casa automaticamente!", "Continuar", "Cancelar");
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

                format(String, sizeof(String), "| CASA | O valor da sua casa foi alterado para {019303}$%s{FFFFFF}, agora é só colocar a venda!", IsMoney(HouseInfo[idhouse][hPreco], "."));
                SendClientMessage(playerid, -1, String);

                DestroyDynamicMapIcon(HouseMapIcon[idhouse]);
                Delete3DTextLabel(HouseLabel[idhouse]);
                DestroyPickup(HousePickup[idhouse]);
                CreateHouseExternal(idhouse);
                UpdateHouses(idhouse);
            }
        }
        case MAIN_HOUSE_RESIDENTS:
        {
            if(response)
            {
                switch(listitem)
                {
                    case 0:
                    {
                        ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS_M1, DIALOG_STYLE_LIST, "{87CEFF}Configurações Casa", "{FFFFFF}Alterar morador(a) \nRemover morador(a) \n", "Selecionar", "Cancelar");
                    }
                    case 1:
                    {
                        ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS_M2, DIALOG_STYLE_LIST, "{87CEFF}Configurações Casa", "{FFFFFF}Alterar morador(a) \nRemover morador(a) \n", "Selecionar", "Cancelar");
                    }
                    case 2:
                    {
                        ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS_M3, DIALOG_STYLE_LIST, "{87CEFF}Configurações Casa", "{FFFFFF}Alterar morador(a) \nRemover morador(a) \n", "Selecionar", "Cancelar");
                    }
                    case 3:
                    {
                        ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS_M4, DIALOG_STYLE_LIST, "{87CEFF}Configurações Casa", "{FFFFFF}Alterar morador(a) \nRemover morador(a) \n", "Selecionar", "Cancelar");
                    }
                    case 4:
                    {
                        ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS_M5, DIALOG_STYLE_LIST, "{87CEFF}Configurações Casa", "{FFFFFF}Alterar morador(a) \nRemover morador(a) \n", "Selecionar", "Cancelar");
                    }
                    case 5:
                    {
                        ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS_M6, DIALOG_STYLE_LIST, "{87CEFF}Configurações Casa", "{FFFFFF}Alterar morador(a) \nRemover morador(a) \n", "Selecionar", "Cancelar");
                    }
                }
            }
        }
        case MAIN_HOUSE_RESIDENTS_M1:
        {
            if(response)
            {
                switch(listitem)
                {
                    case 0:
                    {
                        HouseInfo[idhouse][hResidents] = 1;
                        ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS_INPUT, DIALOG_STYLE_INPUT, "{87CEFF}Configurações Casa", "{FFFFFF}Digite abaixo o {FF0000}id{FFFFFF} do jogador(a)\nque você quer colocar/alterar o morador(a)", "Continuar", "Cancelar");
                    }
                    case 1:
                    {
                        if(strcmp(HouseInfo[houseid[playerid]][hM1], "N/A", true)==0)
                            return SendClientMessage(playerid, Erro, "| ERRO | Não tem nenhum morador(a) para remover!");

                        format(HouseInfo[houseid[playerid]][hM1], MAX_PLAYER_NAME, "N/A");
                        UpdateHouses(idhouse);
                    }
                }
            }
        }
        case MAIN_HOUSE_RESIDENTS_M2:
        {
            if(response)
            {
                switch(listitem)
                {
                    case 0:
                    {
                        HouseInfo[idhouse][hResidents] = 2;
                        ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS_INPUT, DIALOG_STYLE_INPUT, "{87CEFF}Configurações Casa", "{FFFFFF}Digite abaixo o {FF0000}id{FFFFFF} do jogador(a)\nque você quer colocar/alterar o morador(a)", "Continuar", "Cancelar");
                    }
                    case 1:
                    {
                        if(strcmp(HouseInfo[houseid[playerid]][hM2], "N/A", true)==0)
                            return SendClientMessage(playerid, Erro, "| ERRO | Não tem nenhum morador(a) para remover!");

                        format(HouseInfo[houseid[playerid]][hM2], MAX_PLAYER_NAME, "N/A");
                        UpdateHouses(idhouse);
                    }
                }
            }
        }
        case MAIN_HOUSE_RESIDENTS_M3:
        {
            if(response)
            {
                switch(listitem)
                {
                    case 0:
                    {
                        HouseInfo[idhouse][hResidents] = 3;
                        ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS_INPUT, DIALOG_STYLE_INPUT, "{87CEFF}Configurações Casa", "{FFFFFF}Digite abaixo o {FF0000}id{FFFFFF} do jogador(a)\nque você quer colocar/alterar o morador(a)", "Continuar", "Cancelar");
                    }
                    case 1:
                    {
                        if(strcmp(HouseInfo[houseid[playerid]][hM3], "N/A", true)==0)
                            return SendClientMessage(playerid, Erro, "| ERRO | Não tem nenhum morador(a) para remover!");

                        format(HouseInfo[houseid[playerid]][hM3], MAX_PLAYER_NAME, "N/A");
                        UpdateHouses(idhouse);
                    }
                }
            }
        }
        case MAIN_HOUSE_RESIDENTS_M4:
        {
            if(response)
            {
                switch(listitem)
                {
                    case 0:
                    {
                        HouseInfo[idhouse][hResidents] = 4;
                        ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS_INPUT, DIALOG_STYLE_INPUT, "{87CEFF}Configurações Casa", "{FFFFFF}Digite abaixo o {FF0000}id{FFFFFF} do jogador(a)\nque você quer colocar/alterar o morador(a)", "Continuar", "Cancelar");
                    }
                    case 1:
                    {
                        if(strcmp(HouseInfo[houseid[playerid]][hM4], "N/A", true)==0)
                            return SendClientMessage(playerid, Erro, "| ERRO | Não tem nenhum morador(a) para remover!");

                        format(HouseInfo[houseid[playerid]][hM4], MAX_PLAYER_NAME, "N/A");
                        UpdateHouses(idhouse);
                    }
                }
            }
        }
        case MAIN_HOUSE_RESIDENTS_M5:
        {
            if(response)
            {
                switch(listitem)
                {
                    case 0:
                    {
                        HouseInfo[idhouse][hResidents] = 5;
                        ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS_INPUT, DIALOG_STYLE_INPUT, "{87CEFF}Configurações Casa", "{FFFFFF}Digite abaixo o {FF0000}id{FFFFFF} do jogador(a)\nque você quer colocar/alterar o morador(a)", "Continuar", "Cancelar");
                    }
                    case 1:
                    {
                        if(strcmp(HouseInfo[houseid[playerid]][hM5], "N/A", true)==0)
                            return SendClientMessage(playerid, Erro, "| ERRO | Não tem nenhum morador(a) para remover!");

                        format(HouseInfo[houseid[playerid]][hM5], MAX_PLAYER_NAME, "N/A");
                        UpdateHouses(idhouse);
                    }
                }
            }
        }
        case MAIN_HOUSE_RESIDENTS_M6:
        {
            if(response)
            {
                switch(listitem)
                {
                    case 0:
                    {
                        HouseInfo[idhouse][hResidents] = 6;
                        ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS_INPUT, DIALOG_STYLE_INPUT, "{87CEFF}Configurações Casa", "{FFFFFF}Digite abaixo o {FF0000}id{FFFFFF} do jogador(a)\nque você quer colocar/alterar o morador(a)", "Continuar", "Cancelar");
                    }
                    case 1:
                    {
                        if(strcmp(HouseInfo[houseid[playerid]][hM6], "N/A", true)==0)
                            return SendClientMessage(playerid, Erro, "| ERRO | Não tem nenhum morador(a) para remover!");

                        format(HouseInfo[houseid[playerid]][hM6], MAX_PLAYER_NAME, "N/A");
                        UpdateHouses(idhouse);
                    }
                }
            }
        }
        case MAIN_HOUSE_RESIDENTS_INPUT:
        {
            if(response)
            {
                new _str[500], id = strval(inputtext);

                if(id < 0 || id >= MAX_PLAYERS)
                    return ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS_INPUT, DIALOG_STYLE_INPUT, "{87CEFF}Configurações Casa", "{FFFFFF}Digite abaixo o {FF0000}id{FFFFFF} do jogador(a)\nque você quer colocar/alterar o morador(a)\n{FF0000}Jogador(a) não conectado(a)!", "Continuar", "Cancelar");

                if(PlayerInfo[id][Logado] == false)
                    return ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS_INPUT, DIALOG_STYLE_INPUT, "{87CEFF}Configurações Casa", "{FFFFFF}Digite abaixo o {FF0000}id{FFFFFF} do jogador(a)\nque você quer colocar/alterar o morador(a)\n{FF0000}Jogador(a) não conectado(a)!", "Continuar", "Cancelar");

                if(id == playerid)
                    return ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS_INPUT, DIALOG_STYLE_INPUT, "{87CEFF}Configurações Casa", "{FFFFFF}Digite abaixo o {FF0000}id{FFFFFF} do jogador(a)\nque você quer colocar/alterar o morador(a)\n{FF0000}Não pode colocar você como morador(a)!", "Continuar", "Cancelar");

                mysql_format(IDConexao, _str, sizeof(_str), "SELECT `Nome` FROM `Casas` WHERE `Nome`='%e'", PlayerInfo[id][Nome]);
                mysql_query(IDConexao, _str);

                if(cache_num_rows() > 0)
                    return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) já tem uma casa!");

                mysql_format(IDConexao, _str, sizeof(_str), "SELECT `M1` FROM `Casas` WHERE `M1`='%e'", PlayerInfo[id][Nome]);
                mysql_query(IDConexao, _str);

                if(cache_num_rows() > 0)
                    return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) já está de morador(a) em uma casa!");

                if(strcmp(HouseInfo[idhouse][hM1], "N/A", true))
                    return SendClientMessage(playerid, Erro, "| ERRO | Sua casa já tem um(a) morador(a)!");

                switch(HouseInfo[idhouse][hResidents])
                {
                    case 1:
                    {
                        format(HouseInfo[idhouse][hM1], MAX_PLAYER_NAME, PlayerInfo[id][Nome]);
                    }
                    case 2:
                    {
                        format(HouseInfo[idhouse][hM2], MAX_PLAYER_NAME, PlayerInfo[id][Nome]);
                    }
                    case 3:
                    {
                        format(HouseInfo[idhouse][hM3], MAX_PLAYER_NAME, PlayerInfo[id][Nome]);
                    }
                    case 4:
                    {
                        format(HouseInfo[idhouse][hM4], MAX_PLAYER_NAME, PlayerInfo[id][Nome]);
                    }
                    case 5:
                    {
                        format(HouseInfo[idhouse][hM5], MAX_PLAYER_NAME, PlayerInfo[id][Nome]);
                    }
                    case 6:
                    {
                        format(HouseInfo[idhouse][hM6], MAX_PLAYER_NAME, PlayerInfo[id][Nome]);
                    }
                }


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
                        return SendClientMessage(playerid, Erro, "| ERRO | Casa já está no upgrade máximo!");

                    new standard = HouseInfo[idhouse][hPadrao];

                    switch(HouseInfo[idhouse][hUpMax]) // Perda 60% do valor padrão
                    {
                        case 3:
                        {
                            HouseInfo[idhouse][hPadrao] += 42000;

                            if(PlayerInfo[playerid][Dinheiro] < 42000)
                            {
                                HouseInfo[idhouse][hPadrao] = standard;
                                SendClientMessage(playerid, Erro, "| ERRO | Você não tem dinheiro suficiente!");
                                return 1;
                            }

                            PlayerInfo[playerid][Dinheiro] -= 42000;
                        }
                        case 6:
                        {
                            HouseInfo[idhouse][hPadrao] += 90000;

                            if(PlayerInfo[playerid][Dinheiro] < 90000)
                            {
                                HouseInfo[idhouse][hPadrao] = standard;
                                SendClientMessage(playerid, Erro, "| ERRO | Você não tem dinheiro suficiente!");
                                return 1;
                            }

                            PlayerInfo[playerid][Dinheiro] -= 90000;
                        }
                        case 9:
                        {
                            HouseInfo[idhouse][hPadrao] += 144000;

                            if(PlayerInfo[playerid][Dinheiro] < 144000)
                            {
                                HouseInfo[idhouse][hPadrao] = standard;
                                SendClientMessage(playerid, Erro, "| ERRO | Você não tem dinheiro suficiente!");
                                return 1;
                            }

                            PlayerInfo[playerid][Dinheiro] -= 144000;
                        }
                        case 12:
                        {
                            HouseInfo[idhouse][hPadrao] += 210000;

                            if(PlayerInfo[playerid][Dinheiro] < 210000)
                            {
                                HouseInfo[idhouse][hPadrao] = standard;
                                SendClientMessage(playerid, Erro, "| ERRO | Você não tem dinheiro suficiente!");
                                return 1;
                            }

                            PlayerInfo[playerid][Dinheiro] -= 210000;
                        }
                        case 15:
                        {
                            HouseInfo[idhouse][hPadrao] += 240000;

                            if(PlayerInfo[playerid][Dinheiro] < 240000)
                            {
                                HouseInfo[idhouse][hPadrao] = standard;
                                SendClientMessage(playerid, Erro, "| ERRO | Você não tem dinheiro suficiente!");
                                return 1;
                            }

                            PlayerInfo[playerid][Dinheiro] -= 240000;
                        }
                        case 18:
                        {
                            HouseInfo[idhouse][hPadrao] += 300000;

                            if(PlayerInfo[playerid][Dinheiro] < 300000)
                            {
                                HouseInfo[idhouse][hPadrao] = standard;
                                SendClientMessage(playerid, Erro, "| ERRO | Você não tem dinheiro suficiente!");
                                return 1;
                            }

                            PlayerInfo[playerid][Dinheiro] -= 300000;
                        }
                    }

                    HouseInfo[idhouse][hUp]++;

                    UpdatePlayerMoney(playerid);
                    DestroyDynamicMapIcon(HouseMapIcon[idhouse]);
                    Delete3DTextLabel(HouseLabel[idhouse]);
                    DestroyPickup(HousePickup[idhouse]);
                    CreateHouseExternal(idhouse);

                    SetPlayerVirtualWorld(playerid, HouseInfo[houseid[playerid]][hID]);
                    SetPlayerInterior(playerid, HouseInfo[houseid[playerid]][hInterior]);
                    SetPlayerPos(playerid, HouseInfo[houseid[playerid]][hInteriorX], HouseInfo[houseid[playerid]][hInteriorY], HouseInfo[houseid[playerid]][hInteriorZ]);
                    playerinterior[playerid] = HouseInfo[houseid[playerid]][hInterior];
                    dentrocasa[playerid] = 1;
                    UpdateHouses(idhouse);
                }
                case 1:
                {
                    if(HouseInfo[idhouse][hUp] == 1)
                        return SendClientMessage(playerid, Erro, "| ERRO | Casa já está no downgrade máximo!");

                    switch(HouseInfo[idhouse][hUpMax]) // Perda 10% do novo valor padrão
                    {
                        case 3:
                        {
                            HouseInfo[idhouse][hPadrao] -= 35000;
                            PlayerInfo[playerid][Dinheiro] -= 42000;
                        }
                        case 6:
                        {
                            HouseInfo[idhouse][hPadrao] -= 90000;
                            PlayerInfo[playerid][Dinheiro] += 75000;
                        }
                        case 9:
                        {
                            HouseInfo[idhouse][hPadrao] -= 144000;
                            PlayerInfo[playerid][Dinheiro] += 120000;
                        }
                        case 12:
                        {
                            HouseInfo[idhouse][hPadrao] -= 210000;
                            PlayerInfo[playerid][Dinheiro] += 175000;
                        }
                        case 15:
                        {
                            HouseInfo[idhouse][hPadrao] -= 240000;
                            PlayerInfo[playerid][Dinheiro] += 200000;
                        }
                        case 18:
                        {
                            HouseInfo[idhouse][hPadrao] -= 300000;
                            PlayerInfo[playerid][Dinheiro] += 250000;
                        }
                    }

                    HouseInfo[idhouse][hUp]--;

                    UpdatePlayerMoney(playerid);
                    DestroyDynamicMapIcon(HouseMapIcon[idhouse]);
                    Delete3DTextLabel(HouseLabel[idhouse]);
                    DestroyPickup(HousePickup[idhouse]);
                    CreateHouseExternal(idhouse);

                    SetPlayerVirtualWorld(playerid, HouseInfo[houseid[playerid]][hID]);
                    SetPlayerInterior(playerid, HouseInfo[houseid[playerid]][hInterior]);
                    SetPlayerPos(playerid, HouseInfo[houseid[playerid]][hInteriorX], HouseInfo[houseid[playerid]][hInteriorY], HouseInfo[houseid[playerid]][hInteriorZ]);
                    playerinterior[playerid] = HouseInfo[houseid[playerid]][hInterior];
                    dentrocasa[playerid] = 1;
                    UpdateHouses(idhouse);
                }
            }
        }
    }
    return 1;
}

UpdateHouses(idhouse)
{
    new _str[1000];
    mysql_format(IDConexao, _str, sizeof(_str), "UPDATE Casas SET `Nome`='%e', `M1`='%e', `M2`='%e', `M3`='%e', `M4`='%e', `M5`='%e', `M6`='%e', `Mensagem`='%e', `Alugando`='%e', `Vendendo`='%e', `Up`='%d', `UpMax`='%d', `Preco`='%d', `Custo`='%d', `Padrao`='%d', `Trancada`='%e', `Senha`='%e' WHERE `ID`='%d'",
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
    HouseInfo[idhouse][hTrancada],
    HouseInfo[idhouse][hSenha],
    HouseInfo[idhouse][hID]);
    mysql_query(IDConexao, _str);
    return 1;
}

hook OnPlayerPickUpPickup(playerid, pickupid)
{
    GetHouseID(playerid);
    return 1;
}

LoadHouse()
{
    new _str[200];
    for(new i=1; i < MAX_HOUSES; ++i)
    {
        mysql_format(IDConexao, _str, sizeof(_str), "SELECT * FROM `Casas` WHERE `ID`='%d'", i);
        mysql_tquery(IDConexao, _str, "LoadHouses", "d", i);
    }
    return 1;
}

forward LoadHouses(idhouse);
public LoadHouses(idhouse)
{
    if(cache_num_rows() != 0)
    {
        new tmp[128];

        cache_get_value_int(0, "ID", HouseInfo[idhouse][hID]);

        cache_get_value_name(0, "Nome", tmp);
        format(HouseInfo[idhouse][hNome], MAX_PLAYER_NAME, tmp);

        cache_get_value_name(0, "M1", tmp);
        format(HouseInfo[idhouse][hM1], MAX_PLAYER_NAME, tmp);

        cache_get_value_name(0, "M2", tmp);
        format(HouseInfo[idhouse][hM2], MAX_PLAYER_NAME, tmp);

        cache_get_value_name(0, "M3", tmp);
        format(HouseInfo[idhouse][hM3], MAX_PLAYER_NAME, tmp);

        cache_get_value_name(0, "M4", tmp);
        format(HouseInfo[idhouse][hM4], MAX_PLAYER_NAME, tmp);

        cache_get_value_name(0, "M5", tmp);
        format(HouseInfo[idhouse][hM5], MAX_PLAYER_NAME, tmp);

        cache_get_value_name(0, "M6", tmp);
        format(HouseInfo[idhouse][hM6], MAX_PLAYER_NAME, tmp);

        cache_get_value_name(0, "Mensagem", tmp);
        format(HouseInfo[idhouse][hMensagem], 30, tmp);

        cache_get_value_name(0, "Alugando", tmp);
        format(HouseInfo[idhouse][hAlugando], 5, tmp);

        cache_get_value_name(0, "Vendendo", tmp);
        format(HouseInfo[idhouse][hVendendo], 5, tmp);

        cache_get_value_int(0, "Up", HouseInfo[idhouse][hUp]);
        cache_get_value_int(0, "UpMax", HouseInfo[idhouse][hUpMax]);
        cache_get_value_int(0, "Preco", HouseInfo[idhouse][hPreco]);
        cache_get_value_int(0, "Custo", HouseInfo[idhouse][hCusto]);
        cache_get_value_int(0, "Padrao", HouseInfo[idhouse][hPadrao]);

        cache_get_value_name(0, "Trancada", tmp);
        format(HouseInfo[idhouse][hTrancada], 5, tmp);

        cache_get_value_name(0, "Senha", tmp);
        format(HouseInfo[idhouse][hSenha], 24, tmp);

        cache_get_value_float(0, "X", HouseInfo[idhouse][iconx]);
        cache_get_value_float(0, "Y", HouseInfo[idhouse][icony]);
        cache_get_value_float(0, "Z", HouseInfo[idhouse][iconz]);

        CreateHouseExternal(idhouse);
    }
    return 1;
}

forward CreateHouse(playerid, upgrademax, Cost, Standard, Float:iconX, Float:iconY, Float:iconZ);
public CreateHouse(playerid, upgrademax, Cost, Standard, Float:iconX, Float:iconY, Float:iconZ)
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
    format(HouseInfo[idhouse][hTrancada], 5, "N/A");
    format(HouseInfo[idhouse][hSenha], 5, "N/A");
    HouseInfo[idhouse][iconx] = iconX;
    HouseInfo[idhouse][icony] = iconY;
    HouseInfo[idhouse][iconz] = iconZ;

    GetPlayer2DZone(zone, MAX_ZONE_NAME, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony]);
    format(String, sizeof(String), "| BCM-Admin | O(A) %s %s criou a Casa ID %d localizada em %s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], HouseInfo[idhouse][hID], zone);
    SendClientMessageToAll(adm, String);

    CreateHouseExternal(idhouse);
    return 1;
}

CreateHouseExternal(idhouse)
{
    new House_Status[15];

    if(strcmp(HouseInfo[idhouse][hTrancada], "Sim", true)==0)
    {
        format(House_Status, sizeof(House_Status), "Trancada");
    }
    else if(strcmp(HouseInfo[idhouse][hTrancada], "N/A", true)==0)
    {
        format(House_Status, sizeof(House_Status), "Destrancada");
    }

    if(strcmp(HouseInfo[idhouse][hNome], "N/A", true)==0 && strcmp(HouseInfo[idhouse][hVendendo], "Sim", true)==0)
    {
        HousePickup[idhouse] = CreatePickup(1273, 23, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz]);
        HouseMapIcon[idhouse] = CreateDynamicMapIcon(HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz], 31, -1, -1, -1, -1, 30.0);
        format(String, sizeof(String), "{31B404}Casa a Venda ( ID:%d )\n{FFFFFF}Upgrade do Interior: %d/%d\n{CE9F01}Valor: {31B404}$%s\n{41619B}/ComprarCasa", HouseInfo[idhouse][hID], HouseInfo[idhouse][hUp], HouseInfo[idhouse][hUpMax], IsMoney(HouseInfo[idhouse][hCusto], "."));
        HouseLabel[idhouse] =  Create3DTextLabel(String, 0xFFFFFFFF, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz]+0.50, 20.0, 0, 1);

    } else if(strcmp(HouseInfo[idhouse][hNome], "N/A", true) && strcmp(HouseInfo[idhouse][hVendendo], "N/A", true)==0) {

        HousePickup[idhouse] = CreatePickup(19522, 23, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz]);
        HouseMapIcon[idhouse] = CreateDynamicMapIcon(HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz], 32, -1, -1, -1, -1, 30.0);
        format(String, sizeof(String), "{FFD700}Casa de %s ( ID:%d )\n{FFFFFF}%s\n{FFFFFF}Upgrade do Interior: %d/%d\n{6BAF76}%s\n{41619B}/EntrarCasa", HouseInfo[idhouse][hNome], HouseInfo[idhouse][hID], HouseInfo[idhouse][hMensagem], HouseInfo[idhouse][hUp], HouseInfo[idhouse][hUpMax], House_Status);
        HouseLabel[idhouse] =  Create3DTextLabel(String, 0xFFFFFFFF, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz]+0.50, 20.0, 0,1);

    } else if(strcmp(HouseInfo[idhouse][hNome], "N/A", true) && strcmp(HouseInfo[idhouse][hVendendo], "Sim", true)==0) {

        HousePickup[idhouse] = CreatePickup(19522, 23, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz]);
        HouseMapIcon[idhouse] = CreateDynamicMapIcon(HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz], 31, -1, -1, -1, -1, 30.0);
        format(String, sizeof(String), "{FFD700}Casa de %s ( ID:%d )\n{FFFFFF}%s\n{FFFFFF}Upgrade do Interior: %d/%d\n{6BAF76}%s\n{FFFFFF}O(A) proprietário(a) está vendendo a casa por {019303}$%s\n{41619B}/ComprarCasa", HouseInfo[idhouse][hNome], HouseInfo[idhouse][hID], HouseInfo[idhouse][hMensagem], HouseInfo[idhouse][hUp], HouseInfo[idhouse][hUpMax], House_Status,IsMoney(HouseInfo[idhouse][hPreco], "."));
        HouseLabel[idhouse] =  Create3DTextLabel(String, 0xFFFFFFFF, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz]+0.50, 20.0, 0,1);
    }

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
            HouseInfo[idhouse][hInteriorX] = 2308.7378;
            HouseInfo[idhouse][hInteriorY] = -1211.6158;
            HouseInfo[idhouse][hInteriorZ] = 1049.0234;
            HouseInfo[idhouse][hInterior] = 6;
        }
        case 3:
        {
            HouseInfo[idhouse][hInteriorX] = 2333.0703;
            HouseInfo[idhouse][hInteriorY] = -1075.8330;
            HouseInfo[idhouse][hInteriorZ] = 1049.0234;
            HouseInfo[idhouse][hInterior] = 6;
        }
        case 4:
        {
            HouseInfo[idhouse][hInteriorX] = -42.6755;
            HouseInfo[idhouse][hInteriorY] = 1406.7865;
            HouseInfo[idhouse][hInteriorZ] = 1084.4297;
            HouseInfo[idhouse][hInterior] = 8;
        }
        case 5:
        {
            HouseInfo[idhouse][hInteriorX] = 223.1247;
            HouseInfo[idhouse][hInteriorY] = 1288.4781;
            HouseInfo[idhouse][hInteriorZ] = 1082.1406;
            HouseInfo[idhouse][hInterior] = 1;
        }
        case 6:
        {
            HouseInfo[idhouse][hInteriorX] = 261.0076;
            HouseInfo[idhouse][hInteriorY] = 1285.5956;
            HouseInfo[idhouse][hInteriorZ] = 1080.2578;
            HouseInfo[idhouse][hInterior] = 4;
        }
        case 7:
        {
            HouseInfo[idhouse][hInteriorX] = 226.1267;
            HouseInfo[idhouse][hInteriorY] = 1240.0048;
            HouseInfo[idhouse][hInteriorZ] = 1082.1406;
            HouseInfo[idhouse][hInterior] = 2;
        }
        case 8:
        {
            HouseInfo[idhouse][hInteriorX] = 2237.5969;
            HouseInfo[idhouse][hInteriorY] = -1079.6637;
            HouseInfo[idhouse][hInteriorZ] = 1049.0234;
            HouseInfo[idhouse][hInterior] = 2;
        }
        case 9:
        {
            HouseInfo[idhouse][hInteriorX] = 2365.2014;
            HouseInfo[idhouse][hInteriorY] = -1134.2975;
            HouseInfo[idhouse][hInteriorZ] = 1050.8750;
            HouseInfo[idhouse][hInterior] = 8;
        }
        case 10:
        {
            HouseInfo[idhouse][hInteriorX] = 295.2315;
            HouseInfo[idhouse][hInteriorY] = 1473.1649;
            HouseInfo[idhouse][hInteriorZ] = 1080.2578;
            HouseInfo[idhouse][hInterior] = 15;
        }
        case 11:
        {
            HouseInfo[idhouse][hInteriorX] = 260.6734;
            HouseInfo[idhouse][hInteriorY] = 1237.7909;
            HouseInfo[idhouse][hInteriorZ] = 1084.2578;
            HouseInfo[idhouse][hInterior] = 9;
        }
        case 12:
        {
            HouseInfo[idhouse][hInteriorX] = -261.8548;
            HouseInfo[idhouse][hInteriorY] = 1456.6841;
            HouseInfo[idhouse][hInteriorZ] = 1084.3672;
            HouseInfo[idhouse][hInterior] = 4;
        }
        case 13:
        {
            HouseInfo[idhouse][hInteriorX] = 235.3171;
            HouseInfo[idhouse][hInteriorY] = 1187.4275;
            HouseInfo[idhouse][hInteriorZ] = 1080.2578;
            HouseInfo[idhouse][hInterior] = 3;
        }
        case 14:
        {
            HouseInfo[idhouse][hInteriorX] = 2195.4243;
            HouseInfo[idhouse][hInteriorY] = -1204.5555;
            HouseInfo[idhouse][hInteriorZ] = 1049.0234;
            HouseInfo[idhouse][hInterior] = 6;
        }
        case 15:
        {
            HouseInfo[idhouse][hInteriorX] = 225.6588;
            HouseInfo[idhouse][hInteriorY] = 1022.2997;
            HouseInfo[idhouse][hInteriorZ] = 1084.0153;
            HouseInfo[idhouse][hInterior] = 7;
        }
        case 16:
        {
            HouseInfo[idhouse][hInteriorX] = 140.2825;
            HouseInfo[idhouse][hInteriorY] = 1367.8831;
            HouseInfo[idhouse][hInteriorZ] = 1083.8622;
            HouseInfo[idhouse][hInterior] = 5;
        }
        case 17:
        {
            HouseInfo[idhouse][hInteriorX] = 2317.8479;
            HouseInfo[idhouse][hInteriorY] = -1025.4985;
            HouseInfo[idhouse][hInteriorZ] = 1050.2109;
            HouseInfo[idhouse][hInterior] = 9;
        }
        case 18:
        {
            HouseInfo[idhouse][hInteriorX] = 1299.14;
            HouseInfo[idhouse][hInteriorY] = -794.77;
            HouseInfo[idhouse][hInteriorZ] = 1084.00;
            HouseInfo[idhouse][hInterior] = 5;
        }
    }
    return 1;
}

GetHouseID(playerid)
{
    for(new i=1; i < MAX_HOUSES; i++)
    {
        if(IsPlayerInRangeOfPoint(playerid, 1.5, HouseInfo[i][iconx], HouseInfo[i][icony], HouseInfo[i][iconz]))
    	{
            SendClientMessage(playerid, -1, "| CASA | Para entrar na casa digite {CFCDCD}'/EntrarCasa'{FFFFFF} ou pressione a tecla {CFCDCD}'F'");
            return houseid[playerid] = i;
    	}
    }
    return -255;
}

SpawnHouse(playerid)
{
    for(new i=1; i < MAX_HOUSES; i++)
    {
        if(!strcmp(PlayerInfo[playerid][Nome], HouseInfo[i][hNome], true))
        {
            if(PrisonEnum[playerid][pTempo] == 0)
            {
                SetSpawnInfo(playerid, 0, PlayerInfo[playerid][Skin], HouseInfo[i][iconx], HouseInfo[i][icony], HouseInfo[i][iconz], 0, 0, 0, 0, 0, 0, 0);
                SendClientMessage(playerid, -1, "| INFO | Você tem 30 segundos para usar o comando {FF0000}/continuar{FFFFFF} e voltar a sua última posição!");
                HouseContinueTimer[playerid] = SetTimerEx("OnHouseTimerContinue", 1000*30, false, "d", playerid);
                HouseContinue[playerid] = true;
                return 1;
            }

        }
    }
    return 1;
}

forward OnHouseTimerContinue(playerid);
public OnHouseTimerContinue(playerid)
{
    KillTimer(HouseContinueTimer[playerid]);
    HouseContinue[playerid] = false;
    SendClientMessage(playerid, -1, "| INFO | Seu tempo para usar o comando {FF0000}/continuar{FFFFFF} acabou!");
    return 1;
}
