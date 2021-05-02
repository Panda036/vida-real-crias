#include YSI\y_hooks

new cps_realestate;
new main_realestate[MAX_PLAYERS];
new listitemre[MAX_PLAYERS];
new view_realestate[MAX_PLAYERS];

#define MAX_LIST_REALESTATE     10
#define DIALOG_REALESTATE_FIRST 100

#define LIST_HOUSE      1
#define LIST_BUSINESS   2

hook OnGameModeInit()
{
    cps_realestate = CreateDynamicCP(362.9239, 169.3350, 1025.7964, 1.0, -1, -1, -1, 30.0);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    main_realestate[playerid] = 0;
    listitemre[playerid] = 0;
    view_realestate[playerid] = 0;
    Request_RealEstate[playerid][rre_house] = false;
    Request_RealEstate[playerid][rre_business] = false;
    return 1;
}

hook OnPlayerEnterCheckpoint(playerid)
{
    if(IsPlayerInDynamicCP(playerid, cps_realestate))
    {
        new txt[200];
        format(String, 50, "{FFFFFF}Requisição de Casa\t $100\n");
        strcat(txt, String);
        format(String, 50, "{FFFFFF}Requisição de Empresa\t $100\n");
        strcat(txt, String);
        format(String, 50, "{FFFFFF}Lista de Casa\t\n");
        strcat(txt, String);
        format(String, 50, "{FFFFFF}Lista de Empresa\t\n");
        strcat(txt, String);

        ShowPlayerDialog(playerid, realestate, DIALOG_STYLE_LIST, "{FF0000}Imobiliária", txt, "Selecionar", "Fechar");
        return 1;
    }
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == realestate && response)
    {
        switch(listitem)
        {
            case 0:
            {
                if(PlayerInfo[playerid][Dinheiro] < 100)
                    return SendClientMessage(playerid, Erro, "Você não tem dinheiro o suficiente");

                if(Request_RealEstate[playerid][rre_house])
                    return SendClientMessage(playerid, Erro, "Você já comprou requisição para compra de casas");

                PlayerInfo[playerid][Dinheiro] -= 100;
                UpdatePlayerMoney(playerid);

                Request_RealEstate[playerid][rre_house] = true;
                SendClientMessage(playerid, White, "Requisição para compra de casas adquirida");
                return 1;
            }
            case 1:
            {
                if(PlayerInfo[playerid][Dinheiro] < 100)
                    return SendClientMessage(playerid, Erro, "Você não tem dinheiro o suficiente");

                if(Request_RealEstate[playerid][rre_business])
                    return SendClientMessage(playerid, Erro, "Você já comprou requisição para compra de empresas");

                PlayerInfo[playerid][Dinheiro] -= 100;
                UpdatePlayerMoney(playerid);

                Request_RealEstate[playerid][rre_business] = true;
                SendClientMessage(playerid, White, "Requisição para compra de empresas adquirida");
                return 1;
            }
            case 2:
            {
                new txt[1000];
                strcat(txt, "{FFFFFF}Casa ID\t\t {FFFFFF}Vendendo\n");

                for(new i = 1; i < (MAX_LIST_REALESTATE + 1); i++)
                {
                    format(String, 100, "{FFFFFF}%d\t\t %s\n", i, (!strcmp(HouseInfo[i][hVendendo], "Sim") ? ("{1B6302}Sim"):("{FF4000}Não")));
                    strcat(txt, String);
                }
                strcat(txt, "{FF0000}<< Anterior\n{FF0000}>> Próximo");

                listitemre[playerid] = 1;
                view_realestate[playerid] = LIST_HOUSE;
                main_realestate[playerid] = DIALOG_REALESTATE_FIRST;
                ShowPlayerDialog(playerid, main_realestate[playerid], DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Lista de Casas", txt, "Selecionar", "Fechar");
                return 1;
            }
            case 3:
            {
                new txt[1000];
                strcat(txt, "{FFFFFF}Empresas ID\t\t {FFFFFF}Vendendo\n");

                for(new i = 1; i < (MAX_LIST_REALESTATE + 1); i++)
                {
                    format(String, 100, "{FFFFFF}%d\t\t %s\n", i, (!strcmp(BusinessInfo[i][cSelling], "Sim") ? ("{1B6302}Sim"):("{FF4000}Não")));
                    strcat(txt, String);
                }
                strcat(txt, "{FF0000}<< Anterior\n{FF0000}>> Próximo");

                listitemre[playerid] = 1;
                view_realestate[playerid] = LIST_BUSINESS;
                main_realestate[playerid] = DIALOG_REALESTATE_FIRST;
                ShowPlayerDialog(playerid, main_realestate[playerid], DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Lista de Empresas", txt, "Selecionar", "Fechar");
                return 1;
            }
        }
        return 1;
    }
    if(dialogid == main_realestate[playerid] && response)
    {
        if(listitem == MAX_LIST_REALESTATE)
        {
            main_realestate[playerid]--;
            listitemre[playerid] -= MAX_LIST_REALESTATE;

            new txt[1000];

            format(String, 100, "{FFFFFF}%s ID\t\t {FFFFFF}Vendendo\n", (view_realestate[playerid] == LIST_HOUSE ? ("Casas"):("Empresas")));
            strcat(txt, String);

            for(new i = listitemre[playerid]; i < (listitemre[playerid] + MAX_LIST_REALESTATE); i++)
            {
                if(i < 1) return 0;

                switch(view_realestate[playerid])
                {
                    case LIST_HOUSE: format(String, 100, "{FFFFFF}%d\t\t %s\n", i, (!strcmp(HouseInfo[i][hVendendo], "Sim") ? ("{1B6302}Sim"):("{FF4000}Não")));
                    case LIST_BUSINESS: format(String, 100, "{FFFFFF}%d\t\t %s\n", i, (!strcmp(BusinessInfo[i][cSelling], "Sim") ? ("{1B6302}Sim"):("{FF4000}Não")));
                }
                strcat(txt, String);
            }
            strcat(txt, "{FF0000}<< Anterior\n{FF0000}>> Próximo");

            ShowPlayerDialog(playerid, main_realestate[playerid], DIALOG_STYLE_TABLIST_HEADERS, (view_realestate[playerid] == LIST_HOUSE ? ("{FF0000}Lista de Casas") : ("{FF0000}Lista de Empresas")), txt, "Selecionar", "Fechar");
            return 1;
        }
        else if(listitem == (MAX_LIST_REALESTATE + 1))
        {
            main_realestate[playerid]++;
            listitemre[playerid] += MAX_LIST_REALESTATE;

            new txt[1000];

            format(String, 100, "{FFFFFF}%s ID\t\t {FFFFFF}Vendendo\n", (view_realestate[playerid] == LIST_HOUSE ? ("Casas"):("Empresas")));
            strcat(txt, String);

            for(new i = listitemre[playerid]; i < (listitemre[playerid] + MAX_LIST_REALESTATE); i++)
            {
                if((i == MAX_HOUSES && view_realestate[playerid] == LIST_HOUSE) || (i == MAX_BUSINESS && view_realestate[playerid] == LIST_BUSINESS)) break;

                switch(view_realestate[playerid])
                {
                    case LIST_HOUSE: format(String, 100, "{FFFFFF}%d\t\t %s\n", i, (!strcmp(HouseInfo[i][hVendendo], "Sim") ? ("{1B6302}Sim"):("{FF4000}Não")));
                    case LIST_BUSINESS: format(String, 100, "{FFFFFF}%d\t\t %s\n", i, (!strcmp(BusinessInfo[i][cSelling], "Sim") ? ("{1B6302}Sim"):("{FF4000}Não")));
                }
                strcat(txt, String);
            }
            strcat(txt, "{FF0000}<< Anterior\n{FF0000}>> Próximo");

            ShowPlayerDialog(playerid, main_realestate[playerid], DIALOG_STYLE_TABLIST_HEADERS, (view_realestate[playerid] == LIST_HOUSE ? ("{FF0000}Lista de Casas") : ("{FF0000}Lista de Empresas")), txt, "Selecionar", "Fechar");
            return 1;
        }
        else
        {
            switch(view_realestate[playerid])
            {
                case LIST_HOUSE:
                {
                    //TogglePlayerSpectating(playerid, true);
                    //SetPlayerCameraPos(playerid, HouseInfo[x][iconx], HouseInfo[x][icony], HouseInfo[x][iconz]);
                    return 1;
                }
                case LIST_BUSINESS:
                {
                    //TogglePlayerSpectating(playerid, true);
                    //SetPlayerCameraPos(playerid, BusinessInfo[x][iconx], BusinessInfo[x][icony], BusinessInfo[x][iconz]);
                    return 1;
                }
            }
        }
        return 1;
    }
    return 1;
}
