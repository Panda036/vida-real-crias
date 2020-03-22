#include YSI\y_hooks

#define MAX_HOUSES (500)
#define MAIN_HOUSE_COMMAND         10000
#define MAIN_HOUSE                  10001
#define MAIN_HOUSE_ALTER_MSG        10002
#define MAIN_HOUSE_ALTER_PASS       10003
#define MAIN_HOUSE_SELL_AGREE       10004
#define MAIN_HOUSE_PASS             10005
#define MAIN_HOUSE_ALTERMSG         0
#define MAIN_HOUSE_ALTERPASS        1
#define MAIN_HOUSE_LOCKED           2
#define MAIN_HOUSE_SELL             3

enum hInfo
{
    hID,
    hNome[24],
    hMorador[24],
    hMensagem[30],
    hLogin[15],
    hAlugando[5],
    hVendendo[5],
    hTemDono[5],
    hCusto,
    hVender,
    hInterior,
    hTrancada[5],
    hSenha[24],
    Float:hInteriorX,
    Float:hInteriorY,
    Float:hInteriorZ,
    Float:iconx,
    Float:icony,
    Float:iconz,
}
new HouseInfo[MAX_HOUSES][hInfo];

new Text3D:HouseLabel[MAX_HOUSES];
new HouseMapIcon[MAX_HOUSES];
new HousePickup[MAX_HOUSES];
new playerinterior[MAX_PLAYERS]=-1;
new houseid[MAX_PLAYERS];
new playerworld[MAX_PLAYERS];
new dentrocasa[MAX_PLAYERS];
new Float:housex, Float:housey, Float:housez;

hook OnGameModeInit()
{
    new dbhouse[1000];
    strins(dbhouse,"CREATE TABLE IF NOT EXISTS Casas ", strlen(dbhouse));
    strins(dbhouse,"(ID int PRIMARY KEY AUTO_INCREMENT,", strlen(dbhouse));
    strins(dbhouse,"Nome varchar(24) NOT NULL DEFAULT 'N/A',", strlen(dbhouse));
    strins(dbhouse,"Morador varchar(24) NOT NULL DEFAULT 'N/A',", strlen(dbhouse));
    strins(dbhouse,"Mensagem varchar(80) NOT NULL DEFAULT 'N/A',", strlen(dbhouse));
    strins(dbhouse,"Login varchar(10) NOT NULL DEFAULT 'N/A',", strlen(dbhouse));
    strins(dbhouse,"Alugando varchar(3) NOT NULL DEFAULT 'N/A',", strlen(dbhouse));
    strins(dbhouse,"Vendendo varchar(3) NOT NULL DEFAULT 'N/A',", strlen(dbhouse));
    strins(dbhouse,"TemDono varchar(3) NOT NULL DEFAULT 'N/A',", strlen(dbhouse));
    strins(dbhouse,"Custo int(10) NOT NULL,", strlen(dbhouse));
    strins(dbhouse,"Vender int(10) NOT NULL,", strlen(dbhouse));
    strins(dbhouse,"Interior int(3) NOT NULL DEFAULT 15,", strlen(dbhouse));
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
    for(new i=0; i < MAX_HOUSES; i++)
	{
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
    housex = 0;
    housey = 0;
    housez = 0;
	return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    new idhouse = houseid[playerid];

    if(dialogid == MAIN_HOUSE)
    {
        if(response)
        {
            switch(listitem)
            {
                case MAIN_HOUSE_ALTERMSG:
                {
                    ShowPlayerDialog(playerid, MAIN_HOUSE_ALTER_MSG, DIALOG_STYLE_INPUT, "{87CEFF}Alterar Mensagem", "{FFFFFF}Digite abaixo a nova mensagem da sua casa", "Alterar", "Cancelar");
                }
                case MAIN_HOUSE_ALTERPASS:
                {
                    ShowPlayerDialog(playerid, MAIN_HOUSE_ALTER_PASS, DIALOG_STYLE_INPUT, "{87CEFF}Alterar Senha", "{FFFFFF}Digite abaixo a nova senha da sua casa", "Continuar", "Cancelar");
                }
                case MAIN_HOUSE_LOCKED:
                {
                    if(dentrocasa[playerid] != 1)
                        return SendClientMessage(playerid, 0xFF4000AA, "| ERRO | Você não está em uma casa!");

                    if(strcmp(HouseInfo[idhouse][hNome], PlayerInfo[playerid][Nome], true))
                        return SendClientMessage(playerid, 0xFF4000AA, "| ERRO | Esta casa não é sua!");

                    if(strcmp(HouseInfo[idhouse][hTrancada], "Sim", true)==0)
                    {
                        format(HouseInfo[idhouse][hTrancada], 24, "N/A");
                        format(String, sizeof(String),"| INFO | Agora a sua casa está aberta!", inputtext);
                        SendClientMessage(playerid, -1, String);
                        Delete3DTextLabel(HouseLabel[idhouse]);
                        DestroyPickup(HousePickup[idhouse]);
                        CreateHouseExternal(idhouse);

                    } else if(strcmp(HouseInfo[idhouse][hTrancada], "N/A", true)==0) {

                        format(HouseInfo[idhouse][hTrancada], 24, "Sim");
                        format(String, sizeof(String),"| INFO | Agora a sua casa está fechada com a senha {FF0000}%s", HouseInfo[idhouse][hSenha]);
                        SendClientMessage(playerid, -1, String);
                        Delete3DTextLabel(HouseLabel[idhouse]);
                        DestroyPickup(HousePickup[idhouse]);
                        CreateHouseExternal(idhouse);
                    }
                    UpdateHouses(idhouse);
                }
                case MAIN_HOUSE_SELL:
                {
                    ShowPlayerDialog(playerid, MAIN_HOUSE_SELL_AGREE, DIALOG_STYLE_MSGBOX, "{87CEFF}Liberar Casa", "{FFFFFF}Tem certeza que quer liberar sua casa?", "Sim", "Não");
                }
            }
        }
        return 1;
    }
    if(dialogid == MAIN_HOUSE_ALTER_MSG)
    {
        if(response)
        {
            if(dentrocasa[playerid] != 1)
                return SendClientMessage(playerid, 0xFF4000AA, "| ERRO | Você não está em uma casa!");

            if(strcmp(HouseInfo[idhouse][hNome], PlayerInfo[playerid][Nome], true))
                return SendClientMessage(playerid, 0xFF4000AA, "| ERRO | Esta casa não é sua!");

            if(!IsValidMessageHouse(inputtext))
                return ShowPlayerDialog(playerid, MAIN_HOUSE_ALTER_MSG, DIALOG_STYLE_INPUT, "{87CEFF}Alterar Mensagem", "{FFFFFF}Digite abaixo a nova mensagem da sua casa \n{FF0000}Alguns caracteres especias não são permitidos!", "Alterar", "Cancelar");

            format(HouseInfo[idhouse][hMensagem], 30, inputtext);
            format(String, sizeof(String),"| INFO | Agora a mensagem da sua casa é {FF0000}%s", inputtext);
            SendClientMessage(playerid, -1, String);
            Delete3DTextLabel(HouseLabel[idhouse]);
            DestroyPickup(HousePickup[idhouse]);
            CreateHouseExternal(idhouse);
            UpdateHouses(idhouse);
        }
        return 1;
    }
    if(dialogid == MAIN_HOUSE_ALTER_PASS)
    {
        if(response)
        {
            if(dentrocasa[playerid] != 1)
                return SendClientMessage(playerid, 0xFF4000AA, "| ERRO | Você não está em uma casa!");

            if(strcmp(HouseInfo[idhouse][hNome], PlayerInfo[playerid][Nome], true))
                return SendClientMessage(playerid, 0xFF4000AA, "| ERRO | Esta casa não é sua!");

            if(!IsValidUsername(inputtext))
                return ShowPlayerDialog(playerid, MAIN_HOUSE_ALTER_PASS, DIALOG_STYLE_INPUT, "{87CEFF}Alterar Senha", "{FFFFFF}Digite abaixo a nova senha da sua casa \n{FF0000}Alguns caracteres especias não são permitidos!", "Alterar", "Cancelar");

            format(HouseInfo[idhouse][hSenha], 24, inputtext);
            format(String, sizeof(String),"| INFO | Agora a senha da sua casa é {FF0000}%s", inputtext);
            SendClientMessage(playerid, -1, String);
            UpdateHouses(idhouse);
        }
        return 1;
    }
    if(dialogid == MAIN_HOUSE_SELL_AGREE)
    {
        if(response)
        {
            if(dentrocasa[playerid] != 1)
                return SendClientMessage(playerid, 0xFF4000AA, "| ERRO | Você não está em uma casa!");

            if(strcmp(HouseInfo[idhouse][hNome], PlayerInfo[playerid][Nome], true))
                return SendClientMessage(playerid, 0xFF4000AA, "| ERRO | Esta casa não é sua!");

            HouseInfo[idhouse][hID] = idhouse;
            format(HouseInfo[idhouse][hNome], 24, "N/A");
            format(HouseInfo[idhouse][hLogin], 24, "N/A");
            format(HouseInfo[idhouse][hTemDono], 5, "N/A");
            format(HouseInfo[idhouse][hTrancada], 5, "N/A");
            PlayerInfo[playerid][Dinheiro] += HouseInfo[idhouse][hVender];
            GivePlayerMoney(playerid, HouseInfo[idhouse][hVender]);

            GetPlayer2DZone(zone, MAX_ZONE_NAME, housex, housey);
            format(String, sizeof(String), "| CASAS | O(A) Jogador(a) %s liberou a casa ID %d localizada em %s", PlayerInfo[playerid][Nome], HouseInfo[idhouse][hID], zone);
            SendClientMessageToAll(-1, String);

            Delete3DTextLabel(HouseLabel[idhouse]);
            DestroyPickup(HousePickup[idhouse]);
            CreateHouseExternal(idhouse);
            UpdateHouses(idhouse);
        }
        return 1;
    }
    if(dialogid == MAIN_HOUSE_PASS)
    {
        if(response)
        {
            if(strlen(inputtext) == 0)
                return ShowPlayerDialog(playerid, MAIN_HOUSE_PASS, DIALOG_STYLE_INPUT, "{FF0000}Casa trancada", "{FFFFFF}Digite abaixo a senha da casa para entrar \n{FF0000}Senha incorreta, tente novamente!", "Entrar", "Cancelar");

            if(strcmp(inputtext, HouseInfo[idhouse][hSenha], true))
                return ShowPlayerDialog(playerid, MAIN_HOUSE_PASS, DIALOG_STYLE_INPUT, "{FF0000}Casa trancada", "{FFFFFF}Digite abaixo a senha da casa para entrar \n{FF0000}Senha incorreta, tente novamente!", "Entrar", "Cancelar");

            playerworld[playerid] = GetPlayerVirtualWorld(playerid);
            SetPlayerVirtualWorld(playerid, HouseInfo[idhouse][hID]);
            SetPlayerInterior(playerid, HouseInfo[idhouse][hInterior]);
            SetPlayerPos(playerid, HouseInfo[idhouse][hInteriorX], HouseInfo[idhouse][hInteriorY], HouseInfo[idhouse][hInteriorZ]);
            playerinterior[playerid] = HouseInfo[idhouse][hInterior];
            dentrocasa[playerid] = 1;
            format(String, sizeof(String), "| INFO | Bem vindo(a) a casa que pertence a %s", HouseInfo[idhouse][hNome]);
            SendClientMessage(playerid, 0x87CEFFAA, String);
        }
        return 1;
    }
    return 1;
}

UpdateHouses(idhouse)
{
    new _str[1000];
    mysql_format(IDConexao, _str, sizeof(_str), "UPDATE Casas SET `Nome`='%e', `Morador`='%e', `Mensagem`='%e', `Login`='%e', `Alugando`='%e', `Vendendo`='%e', `TemDono`='%e', `Custo`='%d', `Vender`='%d', `Interior`='%d', `Trancada`='%e', `Senha`='%e' WHERE `ID`='%d'",
    HouseInfo[idhouse][hNome],
    HouseInfo[idhouse][hMorador],
    HouseInfo[idhouse][hMensagem],
    HouseInfo[idhouse][hLogin],
    HouseInfo[idhouse][hAlugando],
    HouseInfo[idhouse][hVendendo],
    HouseInfo[idhouse][hTemDono],
    HouseInfo[idhouse][hCusto],
    HouseInfo[idhouse][hVender],
    HouseInfo[idhouse][hInterior],
    HouseInfo[idhouse][hTrancada],
    HouseInfo[idhouse][hSenha],
    HouseInfo[idhouse][hID]);
    mysql_query(IDConexao, _str);
    return 1;
}

hook OnPlayerPickUpPickup(playerid, pickupid)
{
    if(GetProxHouse(playerid))
        { SendClientMessage(playerid, -1, "| INFO | Para entrar na casa digite {CFCDCD}'/EntrarCasa'{FFFFFF} ou pressione a tecla {CFCDCD}'F'"); }

    return 1;
}

LoadHouse()
{
    new _str[100];
    for(new i=0; i < MAX_HOUSES; ++i)
    {
        mysql_format(IDConexao, _str, sizeof(_str), "SELECT * FROM `Casas` WHERE `ID`='%d'", i);
        mysql_tquery(IDConexao, _str, "r@LoadHouse", "d", i);
    }
    return 1;
}

forward r@LoadHouse(idhouse); public r@LoadHouse(idhouse)
{
    if(cache_num_rows() != 0)
    {
        new tmp[128];

        cache_get_value_int(0, "ID", HouseInfo[idhouse][hID]);

        cache_get_value_name(0, "Nome", tmp);
        format(HouseInfo[idhouse][hNome], MAX_PLAYER_NAME, tmp);

        cache_get_value_name(0, "Morador", tmp);
        format(HouseInfo[idhouse][hMorador], MAX_PLAYER_NAME, tmp);

        cache_get_value_name(0, "Mensagem", tmp);
        format(HouseInfo[idhouse][hMensagem], 30, tmp);

        cache_get_value_name(0, "Login", tmp);
        format(HouseInfo[idhouse][hLogin], 15, tmp);

        cache_get_value_name(0, "Alugando", tmp);
        format(HouseInfo[idhouse][hAlugando], 5, tmp);

        cache_get_value_name(0, "Vendendo", tmp);
        format(HouseInfo[idhouse][hVendendo], 5, tmp);

        cache_get_value_name(0, "TemDono", tmp);
        format(HouseInfo[idhouse][hTemDono], 5, tmp);

        cache_get_value_int(0, "Custo", HouseInfo[idhouse][hCusto]);
        cache_get_value_int(0, "Vender", HouseInfo[idhouse][hVender]);
        cache_get_value_int(0, "Interior", HouseInfo[idhouse][hInterior]);

        cache_get_value_name(0, "Trancada", tmp);
        format(HouseInfo[idhouse][hTrancada], 5, tmp);

        cache_get_value_name(0, "Senha", tmp);
        format(HouseInfo[idhouse][hSenha], 24, tmp);

        cache_get_value_float(0, "X", HouseInfo[idhouse][iconx]);
        cache_get_value_float(0, "Y", HouseInfo[idhouse][icony]);
        cache_get_value_float(0, "Z", HouseInfo[idhouse][iconz]);

        CreateHouseExternal(idhouse);
        LoadInland(idhouse, HouseInfo[idhouse][hInterior]);
    }
    return 1;
}

publics CreateHouse(Cost, Sell, Float:iconX, Float:iconY, Float:iconZ)
{
    new idhouse = cache_insert_id();

    HouseInfo[idhouse][hID] = idhouse;
    format(HouseInfo[idhouse][hNome], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[idhouse][hMorador], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[idhouse][hMensagem], 30, "N/A");
    format(HouseInfo[idhouse][hLogin], 15, "N/A");
    format(HouseInfo[idhouse][hAlugando], 5, "N/A");
    format(HouseInfo[idhouse][hVendendo], 5, "N/A");
    format(HouseInfo[idhouse][hTemDono], 5, "N/A");
    HouseInfo[idhouse][hCusto] = Cost;
    HouseInfo[idhouse][hVender] = Sell;
    HouseInfo[idhouse][hInterior] = 15;
    format(HouseInfo[idhouse][hTrancada], 5, "N/A");
    format(HouseInfo[idhouse][hSenha], 5, "N/A");
    HouseInfo[idhouse][iconx] = iconX;
    HouseInfo[idhouse][icony] = iconY;
    HouseInfo[idhouse][iconz] = iconZ;
    HouseInfo[idhouse][hInteriorX] = 386.4823;
    HouseInfo[idhouse][hInteriorY] = 1471.7446;
    HouseInfo[idhouse][hInteriorZ] = 1080.1949;
    CreateHouseExternal(idhouse);
    return 1;
}

CreateHouseExternal(idhouse)
{
    if(strcmp(HouseInfo[idhouse][hTemDono], "N/A", true)==0)
    {
        HousePickup[idhouse] = CreatePickup(1273, 23, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz]);
        HouseMapIcon[idhouse] = CreateDynamicMapIcon(HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz], 31, -1, -1, -1, 0, 100.0);
        format(String, sizeof(String), "{31B404}Casa a Venda ( ID:%d )\n{CE9F01}Valor: {31B404}$%d\n{41619B}/ComprarCasa", HouseInfo[idhouse][hID], HouseInfo[idhouse][hCusto]);
        HouseLabel[idhouse] =  Create3DTextLabel(String, 0xFFFFFFFF, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz]+0.50, 20.0, 0, 1);

    } else if(strcmp(HouseInfo[idhouse][hTemDono], "Sim", true)==0 && strcmp(HouseInfo[idhouse][hTrancada], "Sim", true)==0) {

        HousePickup[idhouse] = CreatePickup(19522, 23, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz]);
        HouseMapIcon[idhouse] = CreateDynamicMapIcon(HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz], 31, -1, -1, -1, 0, 100.0);
        format(String, sizeof(String), "{A3000A}%s ( ID:%d )\n{FFFFFF}%s\n{6BAF76}%s\n{41619B}/EntrarCasa", HouseInfo[idhouse][hNome], HouseInfo[idhouse][hID], HouseInfo[idhouse][hMensagem], "Trancada");
        HouseLabel[idhouse] =  Create3DTextLabel(String, 0xFFFFFFFF, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz]+0.50, 20.0, 0,1);

    } else if(strcmp(HouseInfo[idhouse][hTemDono], "Sim", true)==0 && strcmp(HouseInfo[idhouse][hTrancada], "N/A", true)==0) {

        HousePickup[idhouse] = CreatePickup(19522, 23, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz]);
        HouseMapIcon[idhouse] = CreateDynamicMapIcon(HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz], 31, -1, -1, -1, 0, 100.0);
        format(String, sizeof(String), "{A3000A}%s ( ID:%d )\n{FFFFFF}%s\n{6BAF76}%s\n{41619B}/EntrarCasa", HouseInfo[idhouse][hNome], HouseInfo[idhouse][hID], HouseInfo[idhouse][hMensagem], "Destrancada");
        HouseLabel[idhouse] =  Create3DTextLabel(String, 0xFFFFFFFF, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz]+0.50, 20.0, 0,1);
    }
    //SetPlayerMapIcon(playerid, 36, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz], 31, MAPICON_LOCAL);
    return 1;
}

LoadInland(idhouse, inland)
{
    switch(inland)
    {
        case 15:
        {
            HouseInfo[idhouse][hInteriorX] = 386.4823;
            HouseInfo[idhouse][hInteriorY] = 1471.7446;
            HouseInfo[idhouse][hInteriorZ] = 1080.1949;
        }
        case 1:
        {
            HouseInfo[idhouse][hInteriorX] = -42.6267;
            HouseInfo[idhouse][hInteriorY] = 1406.9242;
            HouseInfo[idhouse][hInteriorZ] = 1084.4297;
        }
    }
    return 1;
}

GetProxHouse(playerid)
{
    for(new i = 0; i != MAX_HOUSES; i++)
    {
    	if(IsPlayerInRangeOfPoint(playerid, 1.5, HouseInfo[i][iconx], HouseInfo[i][icony], HouseInfo[i][iconz]))
    	{
            return houseid[playerid] = i;
    	}
    }
    return -255;
}
