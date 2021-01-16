#include YSI\y_hooks

#include modules\database\db_hud

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case hud:
        {
            if(!response) return 0;

            switch(listitem)
            {
                case 0: return ( statePlayer[playerid] ? (ShowTDStatus(playerid)) : (HideTDStatus(playerid)));

                case 1:
                {
                    if(!IsPlayerInAnyVehicle(playerid))
                        return SendClientMessage(playerid, Erro, "Você não está em um veículo");

                    return ( stateVehicle[playerid] ? (ShowPlayerVelocimetro(playerid)) : (HidePlayerVelocimetro(playerid)));
                }
                case 2: return ( stateTime[playerid] ? (ShowTDTime(playerid)) : (HideTDTime(playerid)));

                case 3: {
                    #if !EVENT_GIFT
                        SendClientMessage(playerid, Erro, "Não estamos em evento de presentes...");
                    #else
                        return ( stateGift[playerid] ? (HideTDGift(playerid)) : (ShowTDGift(playerid)));
                    #endif
                }

                case 4: ShowPlayerDialog(playerid, hudbackcolor, DIALOG_STYLE_INPUT, "{FF0000}Alterar cor status background", "{FFFFFF}Digite um codigo em '{FF0000}HTML{FFFFFF}' abaixo\nPesquise no Google algo como {00FF00}Cores em HTML {FFFFFF}:\n{FF0000}Exemplo {FFFFFF}00FF00 = {00FF00}Calenzo", "Alterar", "Cancelar");

                case 5: ShowPlayerDialog(playerid, hudcolor, DIALOG_STYLE_INPUT, "{FF0000}Alterar cor status", "{FFFFFF}Digite um codigo em '{FF0000}HTML{FFFFFF}' abaixo\nPesquise no Google algo como {00FF00}Cores em HTML {FFFFFF}:\n{FF0000}Exemplo {FFFFFF}00FF00 = {00FF00}Calenzo", "Alterar", "Cancelar");

                case 6: ShowPlayerDialog(playerid, hudfontcolor, DIALOG_STYLE_INPUT, "{FF0000}Alterar cor fonte", "{FFFFFF}Digite um codigo em '{FF0000}HTML{FFFFFF}' abaixo\nPesquise no Google algo como {00FF00}Cores em HTML {FFFFFF}:\n{FF0000}Exemplo {FFFFFF}{00FF00} = {00FF00}Calenzo", "Alterar", "Cancelar");
            }
            return 1;
        }
        case hudbackcolor:
        {
            if(!response) return 0;

            if(!strlen(inputtext))
                return ShowPlayerDialog(playerid, hudbackcolor, DIALOG_STYLE_INPUT, "{FF0000}Alterar cor status background", "{FFFFFF}Digite um codigo em '{FF0000}HTML{FFFFFF}' abaixo\nPesquise no Google algo como {00FF00}Cores em HTML {FFFFFF}:\n{FF0000}Exemplo {FFFFFF}00FF00 = {00FF00}Calenzo\n{FF4000}Você não digitou nada!", "Alterar", "Cancelar");

            if(strlen(inputtext) != 6)
                return ShowPlayerDialog(playerid, hudbackcolor, DIALOG_STYLE_INPUT, "{FF0000}Alterar cor status background", "{FFFFFF}Digite um codigo em '{FF0000}HTML{FFFFFF}' abaixo\nPesquise no Google algo como {00FF00}Cores em HTML {FFFFFF}:\n{FF0000}Exemplo {FFFFFF}00FF00 = {00FF00}Calenzo\n{FF4000}Você não digitou 6 digitos!", "Alterar", "Cancelar");

            format(PlayerInfo[playerid][hud_backcolor], 7, inputtext);

            new query[200];
            mysql_format(IDConexao, query, 200, "UPDATE `Hud` SET `backcolor`='%s' WHERE `id_contas`='%d'", PlayerInfo[playerid][hud_backcolor], PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, query);

            UpdateTDStatus(playerid);
            UpdateTDVelocimetro(playerid);
            return 1;
        }
        case hudcolor:
        {
            if(!response) return 0;

            if(!strlen(inputtext))
                return ShowPlayerDialog(playerid, hudcolor, DIALOG_STYLE_INPUT, "{FF0000}Alterar cor status", "{FFFFFF}Digite um codigo em '{FF0000}HTML{FFFFFF}' abaixo\nPesquise no Google algo como {00FF00}Cores em HTML {FFFFFF}:\n{FF0000}Exemplo {FFFFFF}00FF00 = {00FF00}Calenzo\n{FF4000}Você não digitou nada!", "Alterar", "Cancelar");

            if(strlen(inputtext) != 6)
                return ShowPlayerDialog(playerid, hudcolor, DIALOG_STYLE_INPUT, "{FF0000}Alterar cor status", "{FFFFFF}Digite um codigo em '{FF0000}HTML{FFFFFF}' abaixo\nPesquise no Google algo como {00FF00}Cores em HTML {FFFFFF}:\n{FF0000}Exemplo {FFFFFF}00FF00 = {00FF00}Calenzo\n{FF4000}Você não digitou 6 digitos!", "Alterar", "Cancelar");

            format(PlayerInfo[playerid][hud_color], 7, inputtext);

            new query[200];
            mysql_format(IDConexao, query, 200, "UPDATE `Hud` SET `color`='%s' WHERE `id_contas`='%d'", PlayerInfo[playerid][hud_color], PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, query);

            UpdateTDStatus(playerid);
            UpdateTDVelocimetro(playerid);
            return 1;
        }
        case hudfontcolor:
        {
            if(!response) return 0;

            if(!strlen(inputtext))
                return ShowPlayerDialog(playerid, hudfontcolor, DIALOG_STYLE_INPUT, "{FF0000}Alterar cor da fonte status", "{FFFFFF}Digite um codigo em '{FF0000}HTML{FFFFFF}' abaixo\nPesquise no Google algo como {00FF00}Cores em HTML {FFFFFF}:\n{FF0000}Exemplo {FFFFFF}00FF00 = {00FF00}Calenzo\n{FF4000}Você não digitou nada!", "Alterar", "Cancelar");

            if(strlen(inputtext) != 6)
                return ShowPlayerDialog(playerid, hudfontcolor, DIALOG_STYLE_INPUT, "{FF0000}Alterar cor da fonte status", "{FFFFFF}Digite um codigo em '{FF0000}HTML{FFFFFF}' abaixo\nPesquise no Google algo como {00FF00}Cores em HTML {FFFFFF}:\n{FF0000}Exemplo {FFFFFF}00FF00 = {00FF00}Calenzo\n{FF4000}Você não digitou 6 digitos!", "Alterar", "Cancelar");

            format(PlayerInfo[playerid][hud_fontcolor], 7, inputtext);

            new query[200];
            mysql_format(IDConexao, query, 200, "UPDATE `Hud` SET `fontcolor`='%s' WHERE `id_contas`='%d'", PlayerInfo[playerid][hud_fontcolor], PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, query);

            UpdateTDStatus(playerid);
            UpdateTDVelocimetro(playerid);
            return 1;
        }
    }
	return 1;
}

CMD:hud(playerid)
{
    new txt[500];

    strcat(txt, "{FFFFFF}TextDraw\t Status\n");

    format(String, 50, "{FFFFFF}Status Jogador\t %s\n", (statePlayer[playerid] ? ("{FF4000}Ocultar") : ("{1B6302}Mostrar")));
    strcat(txt, String);
    format(String, 50, "{FFFFFF}Status Veículo\t %s\n", (stateVehicle[playerid] ? ("{FF4000}Ocultar") : ("{1B6302}Mostrar")));
    strcat(txt, String);
    format(String, 50, "{FFFFFF}Hora e Data\t %s\n", (stateTime[playerid] ? ("{FF4000}Ocultar") : ("{1B6302}Mostrar")));
    strcat(txt, String);

    #if !EVENT_GIFT
        format(String, 50, "{FFFFFF}Presente\t {1B6302}Mostrar\n");
    #else
        format(String, 50, "{FFFFFF}Presente\t %s\n", (stateGift[playerid] ? ("{FF4000}Ocultar") : ("{1B6302}Mostrar")));
    #endif
    strcat(txt, String);

    strcat(txt, "{FFFFFF}Alterar cor status background\n");
    strcat(txt, "{FFFFFF}Alterar cor status\n");
    strcat(txt, "{FFFFFF}Alterar cor fonte\n");

    ShowPlayerDialog(playerid, hud, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}HUD", txt, "Continuar", "Cancelar");
    return 1;
}

