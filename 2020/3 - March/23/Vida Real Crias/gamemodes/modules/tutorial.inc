#include YSI\y_hooks

#define tutorial_1                      11
#define tutorial_2                      12
#define tutorial_3                      13
#define tutorial_4                      14
#define tutorial_5                      15

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case tutorial_1:
        {
            new txt[3000];
            strcat(txt, "{B2CEDE}Sistema de Empresas \n");
            strcat(txt, "{FFFFFF}Compra - valor será exibido na porta da empresa \n");
            strcat(txt, "{FFFFFF}Liberação - ao liberar uma empresa para o servidor setá perdido 10% do valor da compra \n");
            strcat(txt, "{FFFFFF}Venda - adicione o valor da empresa e ele será somado automaticamente com valor padrão \n\n");
            strcat(txt, "{B2CEDE}Comandos Empresas \n");
            strcat(txt, "{FFFFFF}/ComprarEmpresa \n");
            strcat(txt, "{FFFFFF}/MenuEmpresa \n\n");
            strcat(txt, "{FF0000}Obs \n");
            strcat(txt, "{FFFFFF}/PegarMercadoria - Server para pegar mercadoria em {FF0000}bs {FFFFFF}e entregar na empresa \n");
            ShowPlayerDialog(playerid, tutorial_2, DIALOG_STYLE_MSGBOX, "{FF0000}Tutorial - Página 2", txt, "Próximo", #);
            return 1;
        }
        case tutorial_2:
        {
            new txt[3000];
            strcat(txt, "{B2CEDE}Concessionária \n");
            strcat(txt, "{FFFFFF}Compra - basta localizar uma concessionária e precionar Y \n");
            strcat(txt, "{FFFFFF}Venda - ao vender seu veículo para o servidor setá perdido 10% do valor da compra \n\n");
            strcat(txt, "{B2CEDE}Comandos Veículos \n");
            strcat(txt, "{FFFFFF}/MenuVeiculos \n");
            ShowPlayerDialog(playerid, tutorial_3, DIALOG_STYLE_MSGBOX, "{FF0000}Tutorial - Página 3", txt, "Próximo", #);
            return 1;
        }
        case tutorial_3:
        {
            new txt[3000];
            strcat(txt, "{B2CEDE}Hospitais \n");
            strcat(txt, "{FFFFFF}Plano de Saúde - Compre um Plano de Saúde e evite a perda de $1.000 ao morrer \n\n");
            strcat(txt, "{FF0000}Obs \n");
            strcat(txt, "{FFFFFF}Será descontado a cada UP Level $150 de sua conta bancária automaticamente \n");
            ShowPlayerDialog(playerid, tutorial_4, DIALOG_STYLE_MSGBOX, "{FF0000}Tutorial - Página 4", txt, "Próximo", #);
            return 1;
        }
        case tutorial_4:
        {
            SaveAccounts(playerid);

            new txt[3000];
            strcat(txt, "{B2CEDE}Level UP \n");
            strcat(txt, "{FFFFFF}No VIP - Receberá 1 experiëncia a cada 10 minutos e ao somar 6/6 ganhará +1 level \n");
            strcat(txt, "{FFFFFF}VIP - Receberá 1 experiëncia a cada 10 minutos e ao somar 3/3 ganhará +1 level \n\n");
            strcat(txt, "{FF0000}Obs \n");
            strcat(txt, "{FFFFFF}Para quem é vip receberá salário VIP de $1.500 a cada level \n");
            strcat(txt, "{FFFFFF}Saiba mais em : /VantagensVip \n");
            ShowPlayerDialog(playerid, tutorial_5, DIALOG_STYLE_MSGBOX, "{FF0000}Tutorial - Página 5", txt, "Concluir", #);
            return 1;
        }
    }
	return 1;
}

stock LoadTutorial(playerid)
{
    new txt[3000];
    strcat(txt, "{B2CEDE}Sistema de Casas \n");
    strcat(txt, "{FFFFFF}Compra - valor será exibido na porta da casa \n");
    strcat(txt, "{FFFFFF}Liberação - ao liberar uma casa para o servidor setá perdido 10% do valor da compra \n");
    strcat(txt, "{FFFFFF}Venda - adicione o valor da casa e ele será somado automaticamente com valor padrão \n\n");
    strcat(txt, "{B2CEDE}Comandos Casas \n");
    strcat(txt, "{FFFFFF}/ComprarCasa \n");
    strcat(txt, "{FFFFFF}/MenuCasa \n");
    ShowPlayerDialog(playerid, tutorial_1, DIALOG_STYLE_MSGBOX, "{FF0000}Tutorial - Página 1", txt, "Próximo", #);
    return 1;
}
