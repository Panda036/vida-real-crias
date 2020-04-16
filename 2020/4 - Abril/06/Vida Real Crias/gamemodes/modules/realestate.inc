/*
#include YSI\y_hooks

new cps_realestate;
new main_realestate[MAX_PLAYERS];
new listitemre[MAX_PLAYERS];

hook OnGameModeInit()
{
    cps_realestate = CreateDynamicCP(362.9239, 169.3350, 1025.7964, 1.0, -1, -1, -1, 30.0);
    return 1;
}

hook OnPlayerEnterCheckpoint(playerid)
{
    if(IsPlayerInDynamicCP(playerid, cps_realestate))
    {
        new txt[1000];

        strcat(txt, "{C0C0C0}Casa ID\t\t {FF8000}Vendendo\n");

        for(new i = 1; i < 21; i++)
        {
            if(!strcmp(HouseInfo[i][hVendendo], "Sim"))
            {
                format(String, sizeof(String), "{FFFFFF}%d\t\t {00FF00}Sim\n", i);
            }
            else
            {
                format(String, sizeof(String), "{FFFFFF}%d\t\t {FF4000}Não\n", i);
            }
            strcat(txt, String);

            if(i == 20) strcat(txt, "{FF0000}>> Próximo");
        }

        listitemre[playerid] = 20;
        main_realestate[playerid] = 36;
        ShowPlayerDialog(playerid, main_realestate[playerid], DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Imobiliária - Página 1", txt, "Selecionar", "Fechar");
        return 1;
    }
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == main_realestate[playerid] && response)
    {
        if(listitem == listitemre[playerid])
        {
            new txt[1000];

            strcat(txt, "{C0C0C0}Casa ID\t\t {FF8000}Vendendo\n");

            for(new i = listitemre[playerid]+1; i < listitemre[playerid]+21; i++)
            {
                if(!strcmp(HouseInfo[i][hVendendo], "Sim"))
                {
                    format(String, sizeof(String), "{FFFFFF}%d\t\t {00FF00}Sim\n", i);
                }
                else
                {
                    format(String, sizeof(String), "{FFFFFF}%d\t\t {FF4000}Não\n", i);
                }
                strcat(txt, String);

                if(i == 40) strcat(txt, "{FF0000}>> Próximo\n");
                main_realestate[playerid]++;
            }
            ShowPlayerDialog(playerid, main_realestate[playerid], DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Imobiliária - Página 2", txt, "Selecionar", "Fechar");
        }
        return 1;
    }
    return 1;
}
*/
