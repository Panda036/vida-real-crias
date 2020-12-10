#include YSI\y_hooks

new cps_townhall;

hook OnGameModeInit()
{
    cps_townhall = CreateDynamicCP(362.98, 173.69, 1008.38, 1.0, -1, -1, -1, 50.0);
	return 1;
}

hook OnPlayerEnterCheckpoint(playerid)
{
    if(IsPlayerInDynamicCP(playerid, cps_townhall))
        return ShowPlayerDialog(playerid, townhall, DIALOG_STYLE_LIST, "{FF0000}Menu Prefeitura", "{FFFFFF}Casa IPTU \nEmpresa IPTU \nRemover estrela(s)", "Selecionar", "Fechar");

    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case townhall:
        {
            if(!response) return 1;

            switch(listitem)
            {
                case 0:
                {
                    new query[100], id, txt[3000];

                    mysql_format(IDConexao, query, 100, "SELECT `id` FROM `Houses` WHERE `Nome`='%e'", PlayerInfo[playerid][Nome]);
                    mysql_query(IDConexao, query);

                    if(cache_num_rows() == 0)
                        return SendClientMessage(playerid, Erro, "Você não tem casa");

                    cache_get_value_int(0, "id", id);

                    if(GetTaxHouse(id) == 0)
                        return ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Casa IPTU", "{FFFFFF}Não há impostos pendente!", "Fechar", #);

                    for(new taxid = 0; taxid < GetTaxHouse(id); taxid++)
                    {
                        format(String, 100, "{FFFFFF}%d\t {1B6302}$%s\n", (taxid + 1), IsMoney(( HOUSE_TAX_VALUE * (taxid + 1)), "."));
                        strcat(txt, String);
                    }

                    ShowPlayerDialog(playerid, townhall_iptu_house, DIALOG_STYLE_LIST, "{FF0000}Casa IPTU", txt, "Pagar", "Fechar");
                    return 1;
                }
                case 1:
                {
                    new query[100], id, txt[3000];

                    mysql_format(IDConexao, query, 100, "SELECT `id` FROM `Business` WHERE `Nome`='%e'", PlayerInfo[playerid][Nome]);
                    mysql_query(IDConexao, query);

                    if(cache_num_rows() == 0)
                        return SendClientMessage(playerid, Erro, "Você não tem empresa");

                    cache_get_value_int(0, "id", id);

                    if(GetTaxBusiness(id) == 0)
                        return ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Empresa IPTU", "{FFFFFF}Não há impostos pendente!", "Fechar", #);

                    for(new taxid = 0; taxid < GetTaxBusiness(id); taxid++)
                    {
                        format(String, 100, "{FFFFFF}%d\t {1B6302}$%s\n", (taxid + 1), IsMoney(( BUSINESS_TAX_VALUE * (taxid + 1)), "."));
                        strcat(txt, String);
                    }

                    ShowPlayerDialog(playerid, townhall_iptu_business, DIALOG_STYLE_LIST, "{FF0000}Empresa IPTU", txt, "Pagar", "Fechar");
                    return 1;
                }
                case 2:
                {
                    if(!PlayerInfo[playerid][Estrelas])
                        return SendClientMessage(playerid, Erro, "Você não está procurado(a)");

                    new txt[3000];

                    for(new i = 1, j = 0; i < (PlayerInfo[playerid][Estrelas] + 1); i++)
                    {
                        j += 200;

                        format(String, MAX_STRING, "{FFFFFF}%d Estrela%s\t {1B6302}$%s \n", i, (i == 1 ? ("") : ("s")), IsMoney(j, "."));
                        strcat(txt, String);
                    }

                    ShowPlayerDialog(playerid, townhall_star, DIALOG_STYLE_LIST, "{FF0000}Menu Prefeitura", txt, "Selecionar", "Fechar");
                    return 1;
                }
            }
            return 1;
        }
        case townhall_star:
        {
            if(!response) return 1;

            for(new i = 0, j = 0; i < PlayerInfo[playerid][Estrelas]; i++)
            {
                j += 200;

                if(listitem == i)
                {
                    i++;

                    if(PlayerInfo[playerid][Dinheiro] < j)
                        return SendClientMessage(playerid, Erro, "Você não tem dinheiro o suficiente");

                    PlayerInfo[playerid][Dinheiro] -= j;
                    UpdatePlayerMoney(playerid);

                    PlayerInfo[playerid][Estrelas] -= i;
                    UpdatePlayerStar(playerid);

                    format(String, MAX_STRING, "Você pagou $%s para remover %d estrela(s)", IsMoney(j, "."), i);
                    SendClientMessage(playerid, White, String);
                    return 1;
                }
            }
            return 1;
        }
        case townhall_iptu_house:
        {
            if(!response) return 0;

            for(new i = 0; i < MAX_TAX_HOUSE; i++)
            {
                if(listitem == i)
                {
                    if(PlayerInfo[playerid][Dinheiro] < ((i+1) * HOUSE_TAX_VALUE))
                        return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

                    new query[100], id;
                    mysql_format(IDConexao, query, 100, "SELECT `id` FROM `Houses` WHERE `Nome`='%e'", PlayerInfo[playerid][Nome]);
                    mysql_query(IDConexao, query);

                    if(cache_num_rows() == 0)
                        return SendClientMessage(playerid, Erro, "Você não tem casa");

                    cache_get_value_int(0, "id", id);

                    mysql_format(IDConexao, query, 100, "UPDATE `Houses` SET `IPTU`='%d' WHERE `id`='%d'", (GetTaxHouse(id) - (i+1)), id);
                    mysql_query(IDConexao, query);

                    PlayerInfo[playerid][Dinheiro] -= ((i+1) * HOUSE_TAX_VALUE);
                    UpdatePlayerMoney(playerid);

                    format(String, MAX_STRING, "Você pagou %d imposto no valor de $%s", (i+1), IsMoney(((i+1) * HOUSE_TAX_VALUE), "."));
                    SendClientMessage(playerid, White, String);
                    return 1;
                }
            }
            return 1;
        }
        case townhall_iptu_business:
        {
            if(!response) return 0;

            for(new i = 0; i < MAX_TAX_BUSINESS; i++)
            {
                if(listitem == i)
                {
                    if(PlayerInfo[playerid][Dinheiro] < ((i+1) * BUSINESS_TAX_VALUE))
                        return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

                    new query[100], id;
                    mysql_format(IDConexao, query, 100, "SELECT `id` FROM `Business` WHERE `Nome`='%e'", PlayerInfo[playerid][Nome]);
                    mysql_query(IDConexao, query);

                    if(cache_num_rows() == 0)
                        return SendClientMessage(playerid, Erro, "Você não tem empresa");

                    cache_get_value_int(0, "id", id);

                    mysql_format(IDConexao, query, 100, "UPDATE `Business` SET `IPTU`='%d' WHERE `id`='%d'", (GetTaxBusiness(id) - (i+1)), id);
                    mysql_query(IDConexao, query);

                    PlayerInfo[playerid][Dinheiro] -= ((i+1) * BUSINESS_TAX_VALUE);
                    UpdatePlayerMoney(playerid);

                    format(String, MAX_STRING, "Você pagou %d imposto no valor de $%s", (i+1), IsMoney(((i+1) * BUSINESS_TAX_VALUE), "."));
                    SendClientMessage(playerid, White, String);
                    return 1;
                }
            }
            return 1;
        }
    }
	return 1;
}
