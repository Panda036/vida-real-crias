#include YSI\y_hooks

#define ban_name        96
#define ban_reason      97
#define ban_temporary   98
#define ban_days        99

enum e_ban
{
    b_idaccount,
    b_days,
    b_date[24],
    b_duedate,
    b_name[MAX_PLAYER_NAME],
    b_reason[MAX_REASON],
    b_responsible[MAX_PLAYER_NAME],
    bool:b_temporary,
    bool:b_ban
};

new Banimento[MAX_PLAYERS][e_ban];
new Text:TDBan[8];
new PlayerText:TDPlayerBan[MAX_PLAYERS][6];

hook OnGameModeInit()
{
    TDBan[0] = TextDrawCreate(237.994155, 127.583335, "box");
    TextDrawLetterSize(TDBan[0], 0.000000, 14.076132);
    TextDrawTextSize(TDBan[0], 404.000000, 0.000000);
    TextDrawAlignment(TDBan[0], 1);
    TextDrawColor(TDBan[0], -1);
    TextDrawUseBox(TDBan[0], 1);
    TextDrawBoxColor(TDBan[0], 150);
    TextDrawSetShadow(TDBan[0], 0);
    TextDrawSetOutline(TDBan[0], 0);
    TextDrawBackgroundColor(TDBan[0], 255);
    TextDrawFont(TDBan[0], 1);
    TextDrawSetProportional(TDBan[0], 1);
    TextDrawSetShadow(TDBan[0], 0);

    TDBan[1] = TextDrawCreate(296.559509, 138.083389, "box");
    TextDrawLetterSize(TDBan[1], 0.000000, 1.695176);
    TextDrawTextSize(TDBan[1], 398.000000, 0.000000);
    TextDrawAlignment(TDBan[1], 1);
    TextDrawColor(TDBan[1], -1);
    TextDrawUseBox(TDBan[1], 1);
    TextDrawBoxColor(TDBan[1], 1145324799);
    TextDrawSetShadow(TDBan[1], 0);
    TextDrawSetOutline(TDBan[1], 0);
    TextDrawBackgroundColor(TDBan[1], 255);
    TextDrawFont(TDBan[1], 1);
    TextDrawSetProportional(TDBan[1], 1);
    TextDrawSetShadow(TDBan[1], 0);

    TDBan[2] = TextDrawCreate(296.559509, 166.285110, "box");
    TextDrawLetterSize(TDBan[2], 0.000000, 1.695176);
    TextDrawTextSize(TDBan[2], 398.000000, 0.000000);
    TextDrawAlignment(TDBan[2], 1);
    TextDrawColor(TDBan[2], -1);
    TextDrawUseBox(TDBan[2], 1);
    TextDrawBoxColor(TDBan[2], 1145324799);
    TextDrawSetShadow(TDBan[2], 0);
    TextDrawSetOutline(TDBan[2], 0);
    TextDrawBackgroundColor(TDBan[2], 255);
    TextDrawFont(TDBan[2], 1);
    TextDrawSetProportional(TDBan[2], 1);
    TextDrawSetShadow(TDBan[2], 0);

    TDBan[3] = TextDrawCreate(296.559509, 210.487808, "box");
    TextDrawLetterSize(TDBan[3], 0.000000, 1.695176);
    TextDrawTextSize(TDBan[3], 398.000000, 0.000000);
    TextDrawAlignment(TDBan[3], 1);
    TextDrawColor(TDBan[3], -1);
    TextDrawUseBox(TDBan[3], 1);
    TextDrawBoxColor(TDBan[3], 1145324799);
    TextDrawSetShadow(TDBan[3], 0);
    TextDrawSetOutline(TDBan[3], 0);
    TextDrawBackgroundColor(TDBan[3], 255);
    TextDrawFont(TDBan[3], 1);
    TextDrawSetProportional(TDBan[3], 1);
    TextDrawSetShadow(TDBan[3], 0);

    TDBan[4] = TextDrawCreate(243.616302, 137.900024, "BANIDO(A):");
    TextDrawLetterSize(TDBan[4], 0.200408, 1.284999);
    TextDrawAlignment(TDBan[4], 1);
    TextDrawColor(TDBan[4], -1);
    TextDrawSetShadow(TDBan[4], 0);
    TextDrawSetOutline(TDBan[4], 1);
    TextDrawBackgroundColor(TDBan[4], 255);
    TextDrawFont(TDBan[4], 2);
    TextDrawSetProportional(TDBan[4], 1);
    TextDrawSetShadow(TDBan[4], 0);

    TDBan[5] = TextDrawCreate(243.616302, 166.001739, "MOTIVO:");
    TextDrawLetterSize(TDBan[5], 0.200408, 1.284999);
    TextDrawAlignment(TDBan[5], 1);
    TextDrawColor(TDBan[5], -1);
    TextDrawSetShadow(TDBan[5], 0);
    TextDrawSetOutline(TDBan[5], 1);
    TextDrawBackgroundColor(TDBan[5], 255);
    TextDrawFont(TDBan[5], 2);
    TextDrawSetProportional(TDBan[5], 1);
    TextDrawSetShadow(TDBan[5], 0);

    TDBan[6] = TextDrawCreate(243.616302, 210.204437, "DIAS:");
    TextDrawLetterSize(TDBan[6], 0.200408, 1.284999);
    TextDrawAlignment(TDBan[6], 1);
    TextDrawColor(TDBan[6], -1);
    TextDrawSetShadow(TDBan[6], 0);
    TextDrawSetOutline(TDBan[6], 1);
    TextDrawBackgroundColor(TDBan[6], 255);
    TextDrawFont(TDBan[6], 2);
    TextDrawSetProportional(TDBan[6], 1);
    TextDrawSetShadow(TDBan[6], 0);

    TDBan[7] = TextDrawCreate(268.410736, 237.083435, "Vida_Real_Crias~n~~r~Banimento");
    TextDrawLetterSize(TDBan[7], 0.272504, 1.383330);
    TextDrawAlignment(TDBan[7], 2);
    TextDrawColor(TDBan[7], -1);
    TextDrawSetShadow(TDBan[7], 0);
    TextDrawSetOutline(TDBan[7], 1);
    TextDrawBackgroundColor(TDBan[7], 255);
    TextDrawFont(TDBan[7], 1);
    TextDrawSetProportional(TDBan[7], 1);
    TextDrawSetShadow(TDBan[7], 0);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    TDPlayerBan[playerid][0] = CreatePlayerTextDraw(playerid, 347.348907, 139.550033, "DIGITE_AQUI_O_NOME_JOGADOR(A)");
    PlayerTextDrawLetterSize(playerid, TDPlayerBan[playerid][0], 0.109985, 1.133330);
    PlayerTextDrawAlignment(playerid, TDPlayerBan[playerid][0], 2);
    PlayerTextDrawColor(playerid, TDPlayerBan[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerBan[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerBan[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerBan[playerid][0], 255);
    PlayerTextDrawFont(playerid, TDPlayerBan[playerid][0], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerBan[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerBan[playerid][0], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerBan[playerid][0], true);
    PlayerTextDrawTextSize(playerid, TDPlayerBan[playerid][0], 10.000000, 80.000000);

    TDPlayerBan[playerid][1] = CreatePlayerTextDraw(playerid, 346.448852, 168.251785, "DIGITE_AQUI_O_MOTIVO_DO_BANIMENTO");
    PlayerTextDrawLetterSize(playerid, TDPlayerBan[playerid][1], 0.109985, 1.133330);
    PlayerTextDrawAlignment(playerid, TDPlayerBan[playerid][1], 2);
    PlayerTextDrawColor(playerid, TDPlayerBan[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerBan[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerBan[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerBan[playerid][1], 255);
    PlayerTextDrawFont(playerid, TDPlayerBan[playerid][1], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerBan[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerBan[playerid][1], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerBan[playerid][1], true);
    PlayerTextDrawTextSize(playerid, TDPlayerBan[playerid][1], 10.000000, 90.000000);

    TDPlayerBan[playerid][2] = CreatePlayerTextDraw(playerid, 243.616302, 189.003143, "TEMPORARIO?");
    PlayerTextDrawLetterSize(playerid, TDPlayerBan[playerid][2], 0.160409, 1.284999);
    PlayerTextDrawAlignment(playerid, TDPlayerBan[playerid][2], 1);
    PlayerTextDrawColor(playerid, TDPlayerBan[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerBan[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerBan[playerid][2], 1);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerBan[playerid][2], 255);
    PlayerTextDrawFont(playerid, TDPlayerBan[playerid][2], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerBan[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerBan[playerid][2], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerBan[playerid][2], true);
    PlayerTextDrawTextSize(playerid, TDPlayerBan[playerid][2], 290.000000, 10.000000);

    TDPlayerBan[playerid][3] = CreatePlayerTextDraw(playerid, 346.448852, 212.154464, "DIGITE_AQUI_QUANTOS_DIAS");
    PlayerTextDrawLetterSize(playerid, TDPlayerBan[playerid][3], 0.109985, 1.133330);
    PlayerTextDrawAlignment(playerid, TDPlayerBan[playerid][3], 2);
    PlayerTextDrawColor(playerid, TDPlayerBan[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerBan[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerBan[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerBan[playerid][3], 255);
    PlayerTextDrawFont(playerid, TDPlayerBan[playerid][3], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerBan[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerBan[playerid][3], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerBan[playerid][3], true);
    PlayerTextDrawTextSize(playerid, TDPlayerBan[playerid][3], 10.000000, 70.000000);

    TDPlayerBan[playerid][4] = CreatePlayerTextDraw(playerid, 349.802581, 237.250045, "LD_BEAT:cross");
    PlayerTextDrawLetterSize(playerid, TDPlayerBan[playerid][4], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, TDPlayerBan[playerid][4], 13.000000, 13.000000);
    PlayerTextDrawAlignment(playerid, TDPlayerBan[playerid][4], 1);
    PlayerTextDrawColor(playerid, TDPlayerBan[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerBan[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerBan[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerBan[playerid][4], 255);
    PlayerTextDrawFont(playerid, TDPlayerBan[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, TDPlayerBan[playerid][4], 0);
    PlayerTextDrawSetShadow(playerid, TDPlayerBan[playerid][4], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerBan[playerid][4], true);

    TDPlayerBan[playerid][5] = CreatePlayerTextDraw(playerid, 374.404083, 237.250045, "LD_BEAT:circle");
    PlayerTextDrawLetterSize(playerid, TDPlayerBan[playerid][5], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, TDPlayerBan[playerid][5], 13.000000, 13.000000);
    PlayerTextDrawAlignment(playerid, TDPlayerBan[playerid][5], 1);
    PlayerTextDrawColor(playerid, TDPlayerBan[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerBan[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerBan[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerBan[playerid][5], 255);
    PlayerTextDrawFont(playerid, TDPlayerBan[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, TDPlayerBan[playerid][5], 0);
    PlayerTextDrawSetShadow(playerid, TDPlayerBan[playerid][5], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerBan[playerid][5], true);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    Banimento[playerid][b_idaccount] = 0;
    Banimento[playerid][b_days] = 0;
    Banimento[playerid][b_date] = 0;
    Banimento[playerid][b_duedate] = 0;
    Banimento[playerid][b_name] = 0;
    Banimento[playerid][b_reason] = 0;
    Banimento[playerid][b_responsible] = 0;
    Banimento[playerid][b_temporary] = false;
    Banimento[playerid][b_ban] = false;

    PlayerTextDrawSetString(playerid, TDPlayerBan[playerid][0], "DIGITE_AQUI_O_NOME_JOGADOR(A)");
    PlayerTextDrawSetString(playerid, TDPlayerBan[playerid][1], "DIGITE_AQUI_O_MOTIVO_DO_BANIMENTO");
    PlayerTextDrawSetString(playerid, TDPlayerBan[playerid][3], "DIGITE_AQUI_QUANTOS_DIAS");
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case ban_name:
        {
            if(!response)
                return 0;

            if(!strlen(inputtext))
                return ShowPlayerDialog(playerid, ban_name, DIALOG_STYLE_INPUT, "{FF0000}Nome", "{FFFFFF}Digite abaixo o nome do(a) jogador(a) que será banido(a):\n{FF4000}Nome Inválido", "Continuar", "Cancelar");

            new query[100];
            mysql_format(IDConexao, query, 100, "SELECT `id` FROM `Contas` WHERE `Nome`='%e'", inputtext);
            mysql_query(IDConexao, query);

            if(cache_num_rows())
            {
                cache_get_value_int(0, "id", Banimento[playerid][b_idaccount]);

                if(Banimento[playerid][b_idaccount] == PlayerInfo[playerid][ID])
                    return ShowPlayerDialog(playerid, ban_name, DIALOG_STYLE_INPUT, "{FF0000}Nome", "{FFFFFF}Digite abaixo o nome do(a) jogador(a) que será banido(a):\n{FF4000}Não pode banir sí mesmo", "Continuar", "Cancelar");

                mysql_format(IDConexao, query, 100, "SELECT `id_contas` FROM `Ban` WHERE `id_contas`='%d'", Banimento[playerid][b_idaccount]);
                mysql_query(IDConexao, query);

                if(cache_num_rows())
                    return ShowPlayerDialog(playerid, ban_name, DIALOG_STYLE_INPUT, "{FF0000}Nome", "{FFFFFF}Digite abaixo o nome do(a) jogador(a) que será banido(a):\n{FF4000}O(A) jogador(a) já está banido(a)", "Continuar", "Cancelar");
            }
            else return ShowPlayerDialog(playerid, ban_name, DIALOG_STYLE_INPUT, "{FF0000}Nome", "{FFFFFF}Digite abaixo o nome do(a) jogador(a) que será banido(a):\n{FF4000}Nome Inválido", "Continuar", "Cancelar");

            format(Banimento[playerid][b_responsible], MAX_PLAYER_NAME, PlayerInfo[playerid][Nome]);
            format(Banimento[playerid][b_name], MAX_PLAYER_NAME, inputtext);
            PlayerTextDrawSetString(playerid, TDPlayerBan[playerid][0], Banimento[playerid][b_name]);
            return 1;
        }
        case ban_reason:
        {
            if(!response)
                return 0;

            if(!strlen(inputtext) || strlen(inputtext) < 2 || strlen(inputtext) > MAX_REASON)
                return ShowPlayerDialog(playerid, ban_reason, DIALOG_STYLE_INPUT, "{FF0000}Motivo", "{FFFFFF}Digite abaixo o motivo do banimento:\n{FF4000}Motivo Inválido", "Continuar", "Cancelar");

            format(Banimento[playerid][b_reason], MAX_REASON, inputtext);
            PlayerTextDrawSetString(playerid, TDPlayerBan[playerid][1], Banimento[playerid][b_reason]);
            return 1;
        }
        case ban_temporary:
        {
            if(response && Banimento[playerid][b_temporary])
            {
                Banimento[playerid][b_temporary] = false;
                TextDrawHideForPlayer(playerid, TDBan[3]);
                TextDrawHideForPlayer(playerid, TDBan[6]);
                PlayerTextDrawHide(playerid, TDPlayerBan[playerid][3]);
            }
            else if(!response && !Banimento[playerid][b_temporary])
            {
                Banimento[playerid][b_temporary] = true;
                TextDrawShowForPlayer(playerid, TDBan[3]);
                TextDrawShowForPlayer(playerid, TDBan[6]);
                PlayerTextDrawShow(playerid, TDPlayerBan[playerid][3]);
            }
            return 1;
        }
        case ban_days:
        {
            if(!response)
                return 0;

            if(!strval(inputtext))
                return ShowPlayerDialog(playerid, ban_days, DIALOG_STYLE_INPUT, "{FF0000}Dias", "{FFFFFF}Digite abaixo quantos dias o jogador(a) ficará banido(a):\n{FF4000}Dias Inválido", "Continuar", "Cancelar");

            if(strval(inputtext) != 15 && strval(inputtext) != 30 && strval(inputtext) != 45 && strval(inputtext) != 60)
                return ShowPlayerDialog(playerid, ban_days, DIALOG_STYLE_INPUT, "{FF0000}Dias", "{FFFFFF}Digite abaixo quantos dias o jogador(a) ficará banido(a):\n{FF4000}Dias permítido: 15, 30, 45 ou 60", "Continuar", "Cancelar");

            Banimento[playerid][b_days] = strval(inputtext);
            format(String, 128, "%d", Banimento[playerid][b_days]);
            PlayerTextDrawSetString(playerid, TDPlayerBan[playerid][3], String);
            return 1;
        }
    }
	return 1;
}

stock ClickTextDrawBan(playerid, PlayerText:playertextid)
{
    if(playertextid == TDPlayerBan[playerid][0]) //name
        return ShowPlayerDialog(playerid, ban_name, DIALOG_STYLE_INPUT, "{FF0000}Nome", "{FFFFFF}Digite abaixo o nome do(a) jogador(a) que será banido(a):", "Continuar", "Cancelar");

    if(playertextid == TDPlayerBan[playerid][1]) //reason
        return ShowPlayerDialog(playerid, ban_reason, DIALOG_STYLE_INPUT, "{FF0000}Motivo", "{FFFFFF}Digite abaixo o motivo do banimento:", "Continuar", "Cancelar");

    if(playertextid == TDPlayerBan[playerid][2]) //temporary?
        return ShowPlayerDialog(playerid, ban_temporary, DIALOG_STYLE_MSGBOX, "{FF0000}Temporário?", "{FFFFFF}Escolha qual será a punição:", "Permanente", "Temporário");

    if(playertextid == TDPlayerBan[playerid][3]) //if so, how many days?
        return ShowPlayerDialog(playerid, ban_days, DIALOG_STYLE_INPUT, "{FF0000}Dias", "{FFFFFF}Digite abaixo quantos dias o jogador(a) ficará banido(a):", "Continuar", "Cancelar");

    if(playertextid == TDPlayerBan[playerid][4]) //Exit
    {
        HideTDPlayerBan(playerid);

        if(Banimento[playerid][b_temporary])
        {
            Banimento[playerid][b_temporary] = false;
            TextDrawHideForPlayer(playerid, TDBan[3]);
            TextDrawHideForPlayer(playerid, TDBan[6]);
            PlayerTextDrawHide(playerid, TDPlayerBan[playerid][3]);
        }

        Banimento[playerid][b_idaccount] = 0;
        Banimento[playerid][b_days] = 0;
        Banimento[playerid][b_date] = 0;
        Banimento[playerid][b_duedate] = 0;
        Banimento[playerid][b_name] = 0;
        Banimento[playerid][b_reason] = 0;
        Banimento[playerid][b_responsible] = 0;
        Banimento[playerid][b_temporary] = false;
        Banimento[playerid][b_ban] = false;

        PlayerTextDrawSetString(playerid, TDPlayerBan[playerid][0], "DIGITE_AQUI_O_NOME_JOGADOR(A)");
        PlayerTextDrawSetString(playerid, TDPlayerBan[playerid][1], "DIGITE_AQUI_O_MOTIVO_DO_BANIMENTO");
        PlayerTextDrawSetString(playerid, TDPlayerBan[playerid][3], "DIGITE_AQUI_QUANTOS_DIAS");
        return 1;
    }
    if(playertextid == TDPlayerBan[playerid][5]) //Ban
    {
        if(!Banimento[playerid][b_name])
            return SendClientMessage(playerid, Erro, "Preencha o nome");

        if(!Banimento[playerid][b_reason])
            return SendClientMessage(playerid, Erro, "Preencha o motivo");

        if(Banimento[playerid][b_temporary] && !Banimento[playerid][b_days])
            return SendClientMessage(playerid, Erro, "Preencha os dias");

        new query[500];

        HideTDPlayerBan(playerid);

        if(Banimento[playerid][b_temporary])
        {
            Banimento[playerid][b_duedate] = ( gettime() + ( 86400 * Banimento[playerid][b_days] ));

            mysql_format(IDConexao, query, 500, "INSERT INTO `Ban` (`responsible`, `reason`, `date`, `duedate`, `id_contas`) VALUES ('%e', '%e', NOW(), '%d', '%d')", Banimento[playerid][b_responsible], Banimento[playerid][b_reason], Banimento[playerid][b_duedate], Banimento[playerid][b_idaccount]);

            Banimento[playerid][b_temporary] = false;
            TextDrawHideForPlayer(playerid, TDBan[3]);
            TextDrawHideForPlayer(playerid, TDBan[6]);
            PlayerTextDrawHide(playerid, TDPlayerBan[playerid][3]);

            new id = GetPlayerID(Banimento[playerid][b_name]);

            if(id == INVALID_PLAYER_ID)
            {
                format(String, 128, "| VRC-Admin | O(A) %s %s agendou o banimento do(a) jogador(a) %s por %d dias ( motivo : %s )", CargoAdmin(playerid), Banimento[playerid][b_responsible], Banimento[playerid][b_name], Banimento[playerid][b_days], Banimento[playerid][b_reason]);
            }
            else
            {
                format(String, 128, "| VRC-Admin | O(A) %s %s baniu o(a) jogador(a) %s por %d dias ( motivo : %s )", CargoAdmin(playerid), Banimento[playerid][b_responsible], Banimento[playerid][b_name], Banimento[playerid][b_days], Banimento[playerid][b_reason]);
                Kick(id);
            }
        }
        else
        {
            new id = GetPlayerID(Banimento[playerid][b_name]);

            if(id == INVALID_PLAYER_ID)
            {
                format(String, 128, "| VRC-Admin | O(A) %s %s agendou o banimento do(a) jogador(a) %s ( motivo : %s )", CargoAdmin(playerid), Banimento[playerid][b_responsible], Banimento[playerid][b_name], Banimento[playerid][b_reason]);
            }
            else
            {
                format(String, 128, "| VRC-Admin | O(A) %s %s baniu o(a) jogador(a) %s ( motivo : %s )", CargoAdmin(playerid), Banimento[playerid][b_responsible], Banimento[playerid][b_name], Banimento[playerid][b_reason]);
                Kick(id);
            }

            Banimento[playerid][b_duedate] = 0;
            mysql_format(IDConexao, query, 500, "INSERT INTO `Ban` (`responsible`, `reason`, `date`, `duedate`, `id_contas`) VALUES ('%e', '%e', NOW(), '%d', '%d')", Banimento[playerid][b_responsible], Banimento[playerid][b_reason], Banimento[playerid][b_duedate], Banimento[playerid][b_idaccount]);
        }

        mysql_query(IDConexao, query);
        SendClientMessageToAll(Red, String);

        Banimento[playerid][b_idaccount] = 0;
        Banimento[playerid][b_days] = 0;
        Banimento[playerid][b_date] = 0;
        Banimento[playerid][b_duedate] = 0;
        Banimento[playerid][b_name] = 0;
        Banimento[playerid][b_reason] = 0;
        Banimento[playerid][b_responsible] = 0;
        Banimento[playerid][b_temporary] = false;
        Banimento[playerid][b_ban] = false;

        PlayerTextDrawSetString(playerid, TDPlayerBan[playerid][0], "DIGITE_AQUI_O_NOME_JOGADOR(A)");
        PlayerTextDrawSetString(playerid, TDPlayerBan[playerid][1], "DIGITE_AQUI_O_MOTIVO_DO_BANIMENTO");
        PlayerTextDrawSetString(playerid, TDPlayerBan[playerid][3], "DIGITE_AQUI_QUANTOS_DIAS");
        return 1;
    }
    return 1;
}

stock ShowTDPlayerBan(playerid)
{
    Banimento[playerid][b_ban] = true;
    SelectTextDraw(playerid, Green);

    for(new i = 0; i < 8; i++)
    {
        if(i == 3 || i == 6) continue;

        TextDrawShowForPlayer(playerid, TDBan[i]);
    }
    for(new i = 0; i < 6; i++)
    {
        if(i == 3) continue;

        PlayerTextDrawShow(playerid, TDPlayerBan[playerid][i]);
    }
    return 1;
}
stock HideTDPlayerBan(playerid)
{
    Banimento[playerid][b_ban] = false;
    CancelSelectTextDraw(playerid);

    for(new i = 0; i < 8; i++)
    {
        if(i == 3 || i == 6) continue;

        TextDrawHideForPlayer(playerid, TDBan[i]);
    }
    for(new i = 0; i < 6; i++)
    {
        if(i == 3) continue;

        PlayerTextDrawHide(playerid, TDPlayerBan[playerid][i]);
    }
    return 1;
}
