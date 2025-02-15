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
        ShowPlayerDialog(playerid, realestate, DIALOG_STYLE_LIST, "{FF0000}Imobili�ria", "{FFFFFF}Requisi��o de Casa\nRequisi��o de Empresa\nLista de Casa\nLista de Empresa", "Selecionar", "Fechar");
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
                if(Request_RealEstate[playerid][rre_house])
                    return SendClientMessage(playerid, Erro, "Voc� j� comprou requisi��o para compra de casas");

                Request_RealEstate[playerid][rre_house] = true;
                SendClientMessage(playerid, White, "Requisi��o para compra de casas adquirida");
                return 1;
            }
            case 1:
            {
                if(Request_RealEstate[playerid][rre_business])
                    return SendClientMessage(playerid, Erro, "Voc� j� comprou requisi��o para compra de empresas");

                Request_RealEstate[playerid][rre_business] = true;
                SendClientMessage(playerid, White, "Requisi��o para compra de empresas adquirida");
                return 1;
            }
            case 2:
            {
                new txt[1000];
                strcat(txt, "{FFFFFF}Casa ID\t\t {FFFFFF}Vendendo\n");

                for(new i = 1; i < (MAX_LIST_REALESTATE + 1); i++)
                {
                    format(String, 100, "{FFFFFF}%d\t\t %s\n", i, (!strcmp(HouseInfo[i][hVendendo], "Sim") ? ("{1B6302}Sim"):("{FF4000}N�o")));
                    strcat(txt, String);
                }
                strcat(txt, "{FF0000}<< Anterior\n{FF0000}>> Pr�ximo");

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
                    format(String, 100, "{FFFFFF}%d\t\t %s\n", i, (!strcmp(BusinessInfo[i][cSelling], "Sim") ? ("{1B6302}Sim"):("{FF4000}N�o")));
                    strcat(txt, String);
                }
                strcat(txt, "{FF0000}<< Anterior\n{FF0000}>> Pr�ximo");

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
                    case LIST_HOUSE: format(String, 100, "{FFFFFF}%d\t\t %s\n", i, (!strcmp(HouseInfo[i][hVendendo], "Sim") ? ("{1B6302}Sim"):("{FF4000}N�o")));
                    case LIST_BUSINESS: format(String, 100, "{FFFFFF}%d\t\t %s\n", i, (!strcmp(BusinessInfo[i][cSelling], "Sim") ? ("{1B6302}Sim"):("{FF4000}N�o")));
                }
                strcat(txt, String);
            }
            strcat(txt, "{FF0000}<< Anterior\n{FF0000}>> Pr�ximo");

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
                    case LIST_HOUSE: format(String, 100, "{FFFFFF}%d\t\t %s\n", i, (!strcmp(HouseInfo[i][hVendendo], "Sim") ? ("{1B6302}Sim"):("{FF4000}N�o")));
                    case LIST_BUSINESS: format(String, 100, "{FFFFFF}%d\t\t %s\n", i, (!strcmp(BusinessInfo[i][cSelling], "Sim") ? ("{1B6302}Sim"):("{FF4000}N�o")));
                }
                strcat(txt, String);
            }
            strcat(txt, "{FF0000}<< Anterior\n{FF0000}>> Pr�ximo");

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
