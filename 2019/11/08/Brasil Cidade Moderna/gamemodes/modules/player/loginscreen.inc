#include YSI\y_hooks

#define name_login                      0
#define pass_login                      1
#define name_register                   2
#define pass_register                   3
#define email_register                  4

new Text:TDLogin[6];
new PlayerText:TDPlayerLogin[MAX_PLAYERS][4];
new Text:TDRegistro[6];
new PlayerText:TDPlayerRegistro[MAX_PLAYERS][4];

hook OnGameModeInit()
{
    TDLogin[0] = TextDrawCreate(231.000000, 172.500000, "box");
    TextDrawLetterSize(TDLogin[0], 0.000000, 9.249998);
    TextDrawTextSize(TDLogin[0], 419.000000, 0.000000);
    TextDrawAlignment(TDLogin[0], 1);
    TextDrawColor(TDLogin[0], -1);
    TextDrawUseBox(TDLogin[0], 1);
    TextDrawBoxColor(TDLogin[0], -2147450625);
    TextDrawSetShadow(TDLogin[0], 0);
    TextDrawSetOutline(TDLogin[0], 0);
    TextDrawBackgroundColor(TDLogin[0], 255);
    TextDrawFont(TDLogin[0], 1);
    TextDrawSetProportional(TDLogin[0], 1);
    TextDrawSetShadow(TDLogin[0], 0);

    TDLogin[1] = TextDrawCreate(232.800109, 174.300109, "box");
    TextDrawLetterSize(TDLogin[1], 0.000000, 8.869964);
    TextDrawTextSize(TDLogin[1], 417.000000, 0.000000);
    TextDrawAlignment(TDLogin[1], 1);
    TextDrawColor(TDLogin[1], -1);
    TextDrawUseBox(TDLogin[1], 1);
    TextDrawBoxColor(TDLogin[1], 200);
    TextDrawSetShadow(TDLogin[1], 0);
    TextDrawSetOutline(TDLogin[1], 0);
    TextDrawBackgroundColor(TDLogin[1], 255);
    TextDrawFont(TDLogin[1], 1);
    TextDrawSetProportional(TDLogin[1], 1);
    TextDrawSetShadow(TDLogin[1], 0);

    TDLogin[2] = TextDrawCreate(241.899871, 186.287567, "box");
    TextDrawLetterSize(TDLogin[2], 0.000000, 1.299998);
    TextDrawTextSize(TDLogin[2], 406.778778, 0.000000);
    TextDrawAlignment(TDLogin[2], 1);
    TextDrawColor(TDLogin[2], -1);
    TextDrawUseBox(TDLogin[2], 1);
    TextDrawBoxColor(TDLogin[2], -2139062172);
    TextDrawSetShadow(TDLogin[2], 0);
    TextDrawSetOutline(TDLogin[2], 0);
    TextDrawBackgroundColor(TDLogin[2], 255);
    TextDrawFont(TDLogin[2], 1);
    TextDrawSetProportional(TDLogin[2], 1);
    TextDrawSetShadow(TDLogin[2], 0);

    TDLogin[3] = TextDrawCreate(241.899871, 206.488800, "box");
    TextDrawLetterSize(TDLogin[3], 0.000000, 1.299998);
    TextDrawTextSize(TDLogin[3], 406.778778, 0.000000);
    TextDrawAlignment(TDLogin[3], 1);
    TextDrawColor(TDLogin[3], -1);
    TextDrawUseBox(TDLogin[3], 1);
    TextDrawBoxColor(TDLogin[3], -2139062172);
    TextDrawSetShadow(TDLogin[3], 0);
    TextDrawSetOutline(TDLogin[3], 0);
    TextDrawBackgroundColor(TDLogin[3], 255);
    TextDrawFont(TDLogin[3], 1);
    TextDrawSetProportional(TDLogin[3], 1);
    TextDrawSetShadow(TDLogin[3], 0);

    TDLogin[4] = TextDrawCreate(276.999755, 231.587554, "box");
    TextDrawLetterSize(TDLogin[4], 0.000000, 1.350000);
    TextDrawTextSize(TDLogin[4], 319.999755, 0.000000);
    TextDrawAlignment(TDLogin[4], 1);
    TextDrawColor(TDLogin[4], -1);
    TextDrawUseBox(TDLogin[4], 1);
    TextDrawBoxColor(TDLogin[4], -2147483393);
    TextDrawSetShadow(TDLogin[4], 0);
    TextDrawSetOutline(TDLogin[4], 0);
    TextDrawBackgroundColor(TDLogin[4], 255);
    TextDrawFont(TDLogin[4], 1);
    TextDrawSetProportional(TDLogin[4], 1);
    TextDrawSetShadow(TDLogin[4], 0);

    TDLogin[5] = TextDrawCreate(331.003051, 231.487548, "box");
    TextDrawLetterSize(TDLogin[5], 0.000000, 1.350000);
    TextDrawTextSize(TDLogin[5], 374.003051, 0.000000);
    TextDrawAlignment(TDLogin[5], 1);
    TextDrawColor(TDLogin[5], -1);
    TextDrawUseBox(TDLogin[5], 1);
    TextDrawBoxColor(TDLogin[5], 8388863);
    TextDrawSetShadow(TDLogin[5], 0);
    TextDrawSetOutline(TDLogin[5], 0);
    TextDrawBackgroundColor(TDLogin[5], 255);
    TextDrawFont(TDLogin[5], 1);
    TextDrawSetProportional(TDLogin[5], 1);
    TextDrawSetShadow(TDLogin[5], 0);

    TDRegistro[0] = TextDrawCreate(231.400085, 165.699798, "box");
    TextDrawLetterSize(TDRegistro[0], 0.000000, 10.699997);
    TextDrawTextSize(TDRegistro[0], 411.400085, 0.000000);
    TextDrawAlignment(TDRegistro[0], 1);
    TextDrawColor(TDRegistro[0], -1);
    TextDrawUseBox(TDRegistro[0], 1);
    TextDrawBoxColor(TDRegistro[0], -2147450625);
    TextDrawSetShadow(TDRegistro[0], 0);
    TextDrawSetOutline(TDRegistro[0], 0);
    TextDrawBackgroundColor(TDRegistro[0], 255);
    TextDrawFont(TDRegistro[0], 1);
    TextDrawSetProportional(TDRegistro[0], 1);
    TextDrawSetShadow(TDRegistro[0], 0);

    TDRegistro[1] = TextDrawCreate(234.000274, 167.299896, "box");
    TextDrawLetterSize(TDRegistro[1], 0.000000, 10.302017);
    TextDrawTextSize(TDRegistro[1], 408.949127, 0.000000);
    TextDrawAlignment(TDRegistro[1], 1);
    TextDrawColor(TDRegistro[1], -1);
    TextDrawUseBox(TDRegistro[1], 1);
    TextDrawBoxColor(TDRegistro[1], 200);
    TextDrawSetShadow(TDRegistro[1], 0);
    TextDrawSetOutline(TDRegistro[1], 0);
    TextDrawBackgroundColor(TDRegistro[1], 255);
    TextDrawFont(TDRegistro[1], 1);
    TextDrawSetProportional(TDRegistro[1], 1);
    TextDrawSetShadow(TDRegistro[1], 0);

    TDRegistro[2] = TextDrawCreate(244.000000, 175.562500, "box");
    TextDrawLetterSize(TDRegistro[2], 0.000000, 1.300000);
    TextDrawTextSize(TDRegistro[2], 399.000000, 0.000000);
    TextDrawAlignment(TDRegistro[2], 1);
    TextDrawColor(TDRegistro[2], -1);
    TextDrawUseBox(TDRegistro[2], 1);
    TextDrawBoxColor(TDRegistro[2], -2139062172);
    TextDrawSetShadow(TDRegistro[2], 0);
    TextDrawSetOutline(TDRegistro[2], 0);
    TextDrawBackgroundColor(TDRegistro[2], 255);
    TextDrawFont(TDRegistro[2], 1);
    TextDrawSetProportional(TDRegistro[2], 1);
    TextDrawSetShadow(TDRegistro[2], 0);

    TDRegistro[3] = TextDrawCreate(244.000000, 194.363647, "box");
    TextDrawLetterSize(TDRegistro[3], 0.000000, 1.300000);
    TextDrawTextSize(TDRegistro[3], 399.000000, 0.000000);
    TextDrawAlignment(TDRegistro[3], 1);
    TextDrawColor(TDRegistro[3], -1);
    TextDrawUseBox(TDRegistro[3], 1);
    TextDrawBoxColor(TDRegistro[3], -2139062172);
    TextDrawSetShadow(TDRegistro[3], 0);
    TextDrawSetOutline(TDRegistro[3], 0);
    TextDrawBackgroundColor(TDRegistro[3], 255);
    TextDrawFont(TDRegistro[3], 1);
    TextDrawSetProportional(TDRegistro[3], 1);
    TextDrawSetShadow(TDRegistro[3], 0);

    TDRegistro[4] = TextDrawCreate(244.000000, 213.264801, "box");
    TextDrawLetterSize(TDRegistro[4], 0.000000, 1.300000);
    TextDrawTextSize(TDRegistro[4], 399.000000, 0.000000);
    TextDrawAlignment(TDRegistro[4], 1);
    TextDrawColor(TDRegistro[4], -1);
    TextDrawUseBox(TDRegistro[4], 1);
    TextDrawBoxColor(TDRegistro[4], -2139062172);
    TextDrawSetShadow(TDRegistro[4], 0);
    TextDrawSetOutline(TDRegistro[4], 0);
    TextDrawBackgroundColor(TDRegistro[4], 255);
    TextDrawFont(TDRegistro[4], 1);
    TextDrawSetProportional(TDRegistro[4], 1);
    TextDrawSetShadow(TDRegistro[4], 0);

    TDRegistro[5] = TextDrawCreate(300.500000, 239.000000, "box");
    TextDrawLetterSize(TDRegistro[5], 0.000000, 1.300000);
    TextDrawTextSize(TDRegistro[5], 342.000000, 0.000000);
    TextDrawAlignment(TDRegistro[5], 1);
    TextDrawColor(TDRegistro[5], -1);
    TextDrawUseBox(TDRegistro[5], 1);
    TextDrawBoxColor(TDRegistro[5], 8388863);
    TextDrawSetShadow(TDRegistro[5], 0);
    TextDrawSetOutline(TDRegistro[5], 0);
    TextDrawBackgroundColor(TDRegistro[5], 255);
    TextDrawFont(TDRegistro[5], 1);
    TextDrawSetProportional(TDRegistro[5], 1);
    TextDrawSetShadow(TDRegistro[5], 0);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    TDPlayerLogin[playerid][0] = CreatePlayerTextDraw(playerid, 245.500000, 187.375000, "CLIQUE_AQUI_PARA_COLOCAR_SEU_NOME");
    PlayerTextDrawLetterSize(playerid, TDPlayerLogin[playerid][0], 0.112500, 0.878126);
    PlayerTextDrawAlignment(playerid, TDPlayerLogin[playerid][0], 1);
    PlayerTextDrawColor(playerid, TDPlayerLogin[playerid][0], -56);
    PlayerTextDrawSetShadow(playerid, TDPlayerLogin[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerLogin[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerLogin[playerid][0], 255);
    PlayerTextDrawFont(playerid, TDPlayerLogin[playerid][0], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerLogin[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerLogin[playerid][0], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerLogin[playerid][0], true);
    PlayerTextDrawTextSize(playerid, TDPlayerLogin[playerid][0], 333.000000, 10.000000);

    TDPlayerLogin[playerid][1] = CreatePlayerTextDraw(playerid, 245.500000, 207.276214, "CLIQUE_AQUI_PARA_COLOCAR_SEU_SENHA");
    PlayerTextDrawLetterSize(playerid, TDPlayerLogin[playerid][1], 0.112500, 0.878126);
    PlayerTextDrawAlignment(playerid, TDPlayerLogin[playerid][1], 1);
    PlayerTextDrawColor(playerid, TDPlayerLogin[playerid][1], -56);
    PlayerTextDrawSetShadow(playerid, TDPlayerLogin[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerLogin[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerLogin[playerid][1], 255);
    PlayerTextDrawFont(playerid, TDPlayerLogin[playerid][1], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerLogin[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerLogin[playerid][1], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerLogin[playerid][1], true);
    PlayerTextDrawTextSize(playerid, TDPlayerLogin[playerid][1], 335.000000, 10.000000);

    TDPlayerLogin[playerid][2] = CreatePlayerTextDraw(playerid, 282.799957, 231.474914, "Entrar");
    PlayerTextDrawLetterSize(playerid, TDPlayerLogin[playerid][2], 0.321000, 1.184375);
    PlayerTextDrawAlignment(playerid, TDPlayerLogin[playerid][2], 1);
    PlayerTextDrawColor(playerid, TDPlayerLogin[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerLogin[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerLogin[playerid][2], -1);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerLogin[playerid][2], 255);
    PlayerTextDrawFont(playerid, TDPlayerLogin[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, TDPlayerLogin[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerLogin[playerid][2], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerLogin[playerid][2], true);
    PlayerTextDrawTextSize(playerid, TDPlayerLogin[playerid][2], 314.000000, 12.000000);

    TDPlayerLogin[playerid][3] = CreatePlayerTextDraw(playerid, 332.402984, 231.474914, "Registrar");
    PlayerTextDrawLetterSize(playerid, TDPlayerLogin[playerid][3], 0.287000, 1.184375);
    PlayerTextDrawAlignment(playerid, TDPlayerLogin[playerid][3], 1);
    PlayerTextDrawColor(playerid, TDPlayerLogin[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerLogin[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerLogin[playerid][3], -1);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerLogin[playerid][3], 255);
    PlayerTextDrawFont(playerid, TDPlayerLogin[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, TDPlayerLogin[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerLogin[playerid][3], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerLogin[playerid][3], true);
    PlayerTextDrawTextSize(playerid, TDPlayerLogin[playerid][3], 372.000000, 12.000000);

    TDPlayerRegistro[playerid][0] = CreatePlayerTextDraw(playerid, 247.000000, 176.425079, "CLIQUE_AQUI_PARA_COLOCAR_SEU_NOME");
    PlayerTextDrawLetterSize(playerid, TDPlayerRegistro[playerid][0], 0.128500, 0.996251);
    PlayerTextDrawAlignment(playerid, TDPlayerRegistro[playerid][0], 1);
    PlayerTextDrawColor(playerid, TDPlayerRegistro[playerid][0], -56);
    PlayerTextDrawSetShadow(playerid, TDPlayerRegistro[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerRegistro[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerRegistro[playerid][0], 255);
    PlayerTextDrawFont(playerid, TDPlayerRegistro[playerid][0], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerRegistro[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerRegistro[playerid][0], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerRegistro[playerid][0], true);
    PlayerTextDrawTextSize(playerid, TDPlayerRegistro[playerid][0], 348.000000, 10.000000);

    TDPlayerRegistro[playerid][1] = CreatePlayerTextDraw(playerid, 247.000000, 194.926208, "CLIQUE_AQUI_PARA_COLOCAR_SUA_SENHA");
    PlayerTextDrawLetterSize(playerid, TDPlayerRegistro[playerid][1], 0.128500, 0.996251);
    PlayerTextDrawAlignment(playerid, TDPlayerRegistro[playerid][1], 1);
    PlayerTextDrawColor(playerid, TDPlayerRegistro[playerid][1], -56);
    PlayerTextDrawSetShadow(playerid, TDPlayerRegistro[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerRegistro[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerRegistro[playerid][1], 255);
    PlayerTextDrawFont(playerid, TDPlayerRegistro[playerid][1], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerRegistro[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerRegistro[playerid][1], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerRegistro[playerid][1], true);
    PlayerTextDrawTextSize(playerid, TDPlayerRegistro[playerid][1], 350.000000, 10.000000);

    TDPlayerRegistro[playerid][2] = CreatePlayerTextDraw(playerid, 247.000000, 213.527343, "CLIQUE_AQUI_PARA_COLOCAR_SEU_EMAIL");
    PlayerTextDrawLetterSize(playerid, TDPlayerRegistro[playerid][2], 0.128500, 0.996251);
    PlayerTextDrawAlignment(playerid, TDPlayerRegistro[playerid][2], 1);
    PlayerTextDrawColor(playerid, TDPlayerRegistro[playerid][2], -56);
    PlayerTextDrawSetShadow(playerid, TDPlayerRegistro[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerRegistro[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerRegistro[playerid][2], 255);
    PlayerTextDrawFont(playerid, TDPlayerRegistro[playerid][2], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerRegistro[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerRegistro[playerid][2], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerRegistro[playerid][2], true);
    PlayerTextDrawTextSize(playerid, TDPlayerRegistro[playerid][2], 350.000000, 10.000000);

    TDPlayerRegistro[playerid][3] = CreatePlayerTextDraw(playerid, 302.500122, 239.125061, "Registrar");
    PlayerTextDrawLetterSize(playerid, TDPlayerRegistro[playerid][3], 0.264500, 1.136250);
    PlayerTextDrawAlignment(playerid, TDPlayerRegistro[playerid][3], 1);
    PlayerTextDrawColor(playerid, TDPlayerRegistro[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerRegistro[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerRegistro[playerid][3], -1);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerRegistro[playerid][3], 255);
    PlayerTextDrawFont(playerid, TDPlayerRegistro[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, TDPlayerRegistro[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerRegistro[playerid][3], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerRegistro[playerid][3], true);
    PlayerTextDrawTextSize(playerid, TDPlayerRegistro[playerid][3], 338.000000, 12.000000);
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == name_login)
    {
        format(pPlayerInfo[playerid][pNome], MAX_PLAYER_NAME, inputtext);

        if(pPlayerInfo[playerid][pNome] == 0) return 0;

        PlayerTextDrawSetString(playerid, TDPlayerLogin[playerid][0], inputtext);
        PlayerTextDrawShow(playerid, TDPlayerLogin[playerid][0]);
        return 1;
    }
    if(dialogid == pass_login)
    {
        format(pPlayerInfo[playerid][pSenha], MAX_PLAYER_PASS, inputtext);

        if(pPlayerInfo[playerid][pSenha] == 0) return 0;

        for(new i=0; i < strlen(inputtext); i++)
        {
            inputtext[i] = ']';
        }

        PlayerTextDrawSetString(playerid, TDPlayerLogin[playerid][1], inputtext);
        PlayerTextDrawShow(playerid, TDPlayerLogin[playerid][1]);
        return 1;
    }
    if(dialogid == name_register)
    {
        format(pPlayerInfo[playerid][pNome], MAX_PLAYER_NAME, inputtext);

        if(pPlayerInfo[playerid][pNome] == 0) return 0;

        if(strlen(inputtext) < MIN_PLAYER_NAME || strlen(inputtext) > MAX_PLAYER_NAME)
        {
            SendClientMessage(playerid, 0xFFFF80AA, "| AVISO | Digite um nome entre 6 a 30 caracteres!");
            pPlayerInfo[playerid][pNome]=0;
            return 1;
        }

        if(!IsValidUsername(inputtext))
            return SendClientMessage(playerid, 0xFFFF80AA, "| INFO | Digite um nome sem caracteres especiais!");

        PlayerTextDrawSetString(playerid, TDPlayerRegistro[playerid][0], inputtext);
        PlayerTextDrawShow(playerid, TDPlayerRegistro[playerid][0]);
        return 1;
    }
    if(dialogid == pass_register)
    {
        format(pPlayerInfo[playerid][pSenha], MAX_PLAYER_PASS, inputtext);

        if(pPlayerInfo[playerid][pSenha] == 0) return 0;

        if(strlen(inputtext) < MIN_PLAYER_PASS || strlen(inputtext) > MAX_PLAYER_PASS)
        {
            SendClientMessage(playerid, 0xFFFF80AA, "| AVISO | Digite uma senha entre 6 a 30 caracteres!");
            pPlayerInfo[playerid][pSenha]=0;
            return 1;
        }

        for(new i=0; i < strlen(inputtext); i++)
        {
            inputtext[i] = ']';
        }

        PlayerTextDrawSetString(playerid, TDPlayerRegistro[playerid][1], inputtext);
        PlayerTextDrawShow(playerid, TDPlayerRegistro[playerid][1]);
        return 1;
    }
    if(dialogid == email_register)
    {
        format(pPlayerInfo[playerid][pEmail], MAX_PLAYER_NAME, inputtext);
        if(strlen(inputtext) <= 0) return 0;
        if(strlen(inputtext) < MIN_PLAYER_EMAIL || strlen(inputtext) > MAX_PLAYER_EMAIL)
        {
            SendClientMessage(playerid, 0xFFFF80AA, "| AVISO | Digite um e-mail entre 10 a 50 caracteres!");
            pPlayerInfo[playerid][pEmail]=0;
            return 1;
        }
        PlayerTextDrawSetString(playerid, TDPlayerRegistro[playerid][2], inputtext);
        PlayerTextDrawShow(playerid, TDPlayerRegistro[playerid][2]);
        return 1;
    }
    return 1;
}

public OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{
    if(playertextid == TDPlayerLogin[playerid][0])
        return ShowPlayerDialog(playerid, name_login, DIALOG_STYLE_INPUT, "{FF0000}Nome", "{FFFFFF}Digite seu nome em baixo para efetuar login : \n\n{FF0000}AVISO: Se o seu nome tiver caracteres especiais pode ser exibido como espaço,{FFFFFF} \nMas não se preocupe, isso não afetará o nome digitado", "Continuar", "Cancelar");

    if(playertextid == TDPlayerLogin[playerid][1])
        return ShowPlayerDialog(playerid, pass_login, DIALOG_STYLE_PASSWORD, "{FF0000}Senha", "{FFFFFF}Digite sua senha em baixo para efetuar login : \n\n{FF0000}Sua senha será escondida por *", "Continuar", "Cancelar");

    if(playertextid == TDPlayerLogin[playerid][2])
    {
        if(pPlayerInfo[playerid][pNome] == 0 && pPlayerInfo[playerid][pSenha] == 0)
            return SendClientMessage(playerid, Erro, "| ERRO | Preencha os campos para proseguir!");

        if(pPlayerInfo[playerid][pNome] == 0)
            return SendClientMessage(playerid, Erro, "| ERRO | Coloque seu nome!");

        if(pPlayerInfo[playerid][pSenha] == 0)
            return SendClientMessage(playerid, Erro, "| ERRO | Coloque sua senha!");

        mysql_format(IDConexao, String, sizeof(String), "SELECT * FROM Contas WHERE Nome='%s'", pPlayerInfo[playerid][pNome]);
        mysql_query(IDConexao, String);

        if(cache_num_rows() < 1)
            return SendClientMessage(playerid, Erro, "| ERRO | Conta não registrada!");

        mysql_format(IDConexao, String, sizeof(String), "SELECT * FROM Contas WHERE Nome='%s' AND Senha='%s'", pPlayerInfo[playerid][pNome], pPlayerInfo[playerid][pSenha]);
        mysql_query(IDConexao, String);

        if(cache_num_rows() < 1)
            return SendClientMessage(playerid, Erro, "| ERRO | Senha Incorreta!");

        mysql_format(IDConexao, String, sizeof(String), "SELECT * FROM Contas WHERE Nome='%s'", pPlayerInfo[playerid][pNome]);
        mysql_tquery(IDConexao, String, "LoadAccounts", "i", playerid);
        return 1;
    }

    if(playertextid == TDPlayerLogin[playerid][3])
        return HideTextDrawLogin(playerid), ShowTextDrawRegister(playerid);

    if(playertextid == TDPlayerRegistro[playerid][0])
        return ShowPlayerDialog(playerid, name_register, DIALOG_STYLE_INPUT, "{FF0000}Nome", "{FFFFFF}Digite seu nome em baixo para efetuar o registro : \n\n{FF0000}AVISO: Se o seu nome tiver caracteres especiais pode ser exibido como espaço,{FFFFFF} \nMas não se preocupe, isso não afetará o nome digitado", "Continuar", "Cancelar");

    if(playertextid == TDPlayerRegistro[playerid][1])
        return ShowPlayerDialog(playerid, pass_register, DIALOG_STYLE_PASSWORD, "{FF0000}Senha", "{FFFFFF}Digite sua senha em baixo para efetuar o registro : \n\n{FF0000}Sua senha será escondida por *", "Continuar", "Cancelar");

    if(playertextid == TDPlayerRegistro[playerid][2])
        return ShowPlayerDialog(playerid, email_register, DIALOG_STYLE_INPUT, "{FF0000}E-mail", "{FFFFFF}Digite seu e-mail em baixo para efetuar o registro : \n\n{FF0000}AVISO: Se o seu e-mail tiver caracteres especiais pode ser exibido como espaço,{FFFFFF} \nMas não se preocupe, isso não afetará o e-mail digitado", "Continuar", "Cancelar");

    if(playertextid == TDPlayerRegistro[playerid][3])
    {
        if(pPlayerInfo[playerid][pNome] == 0 && pPlayerInfo[playerid][pSenha] == 0)
            return SendClientMessage(playerid, Erro, "| ERRO | Preencha os campos para proseguir!");

        if(pPlayerInfo[playerid][pNome] == 0)
            return SendClientMessage(playerid, Erro, "| ERRO | Coloque seu nome!");

        if(pPlayerInfo[playerid][pSenha] == 0)
            return SendClientMessage(playerid, Erro, "| ERRO | Coloque sua senha!");

        if(pPlayerInfo[playerid][pEmail] == 0)
            return SendClientMessage(playerid, Erro, "| ERRO | Coloque seu e-mail!");

        mysql_format(IDConexao, String, sizeof(String), "SELECT * FROM Contas WHERE Nome='%s'", pPlayerInfo[playerid][pNome]);
        mysql_query(IDConexao, String);

        if(cache_num_rows() > 0)
            return SendClientMessage(playerid, Erro, "| ERRO | Nome já em uso, tente outro!");

        mysql_format(IDConexao, String, sizeof(String), "SELECT * FROM Contas WHERE Email='%s'", pPlayerInfo[playerid][pEmail]);
        mysql_query(IDConexao, String);

        if(cache_num_rows() > 0)
            return SendClientMessage(playerid, Erro, "| ERRO | E-mail já em uso, tente outro!");

        mysql_format(IDConexao, String, sizeof(String), "INSERT INTO Contas (Nome, Senha, Email) VALUES ('%s', '%s', '%s')", pPlayerInfo[playerid][pNome], pPlayerInfo[playerid][pSenha], pPlayerInfo[playerid][pEmail]);
        mysql_tquery(IDConexao, String, "RegisterAccounts", "i", playerid);
        return 1;
    }
    return 1;
}

ShowTextDrawLogin(playerid)
{
    for(new i=0; i < 4; ++i){
        PlayerTextDrawShow(playerid, TDPlayerLogin[playerid][i]); //Pro player
    }
    for(new i=0; i < 6; ++i){
        TextDrawShowForPlayer(playerid, TDLogin[i]); //Global
    }
    return 1;
}

ShowTextDrawRegister(playerid)
{
    for(new i=0; i < 4; ++i){
        PlayerTextDrawShow(playerid, TDPlayerRegistro[playerid][i]); //Pro player
    }
    for(new i=0; i < 6; ++i){
        TextDrawShowForPlayer(playerid, TDRegistro[i]); //Global
    }
    return 1;
}

HideTextDrawLogin(playerid)
{
    for(new i=0; i < 4; ++i){
        PlayerTextDrawHide(playerid, TDPlayerLogin[playerid][i]); //Pro player
    }
    for(new i=0; i < 6; ++i){
        TextDrawHideForPlayer(playerid, TDLogin[i]); //Global
    }
    return 1;
}

HideTextDrawRegister(playerid)
{
    for(new i=0; i < 4; ++i){
        PlayerTextDrawHide(playerid, TDPlayerRegistro[playerid][i]); //Pro player
    }
    for(new i=0; i < 6; ++i){
        TextDrawHideForPlayer(playerid, TDRegistro[i]); //Global
    }
    return 1;
}

/*SkinList(playerid)
{
    new var[17];
    switch(SkinPlayer[playerid])
    {
        case 0: var = "Cj_(ID:0)";
        case 1: var = "Truth_(ID:1)";
        case 2: var = "Maccer_(ID:2)";
        case 3: var = "andre_(ID:3)";
        case 4: var = "Bbthin_(ID:4)";
        case 5: var = "Bb_(ID:5)";
        case 6: var = "Emmet_(ID:6)";
        case 7: var = "male01 (ID:7)";
        case 8: var = "janitor (ID:8)";
        case 9: var = "bfori (ID:9)";
        case 10: var = "bfost (ID:10)";
        case 11: var = "vbfycrp (ID:11)";
        case 12: var = "bfyri (ID:12)";
        case 13: var = "bfyst (ID:13)";
        case 14: var = "bmori (ID:14)";
        case 15: var = "bmost (ID:15)";
        case 16: var = "bmyap (ID:16)";
        case 17: var = "bmybu (ID:17)";
        case 18: var = "bmybe (ID:18)";
        case 19: var = "bmydj (ID:19)";
        case 20: var = "bmyri (ID:20)";
        case 21: var = "bmycr (ID:21)";
        case 22: var = "bmyst (ID:22)";
        case 23: var = "wmybmx (ID:23)";
        case 24: var = "wbdyg1 (ID:24)";
        case 25: var = "wbdyg2 (ID:25)";
        case 26: var = "wmybp (ID:26)";
        case 27: var = "wmycon (ID:27)";
        case 28: var = "bmydrug (ID:28)";
        case 29: var = "wmydrug (ID:29)";
        case 30: var = "hmydrug (ID:30)";
        case 31: var = "dwfolc (ID:31)";
        case 32: var = "dwmolc1 (ID:32)";
        case 33: var = "dwmolc2 (ID:33)";
        case 34: var = "dwmylc1 (ID:34)";
        case 35: var = "hmogar (ID:35)";
        case 36: var = "wmygol1 (ID:36)";
        case 37: var = "wmygol2 (ID:37)";
        case 38: var = "hfori (ID:38)";
        case 39: var = "hfost (ID:39)";
        case 40: var = "hfyri (ID:40)";
        case 41: var = "hfyst (ID:41)";
        case 42: var = "jethro (ID:42)";
        case 43: var = "hmori (ID:43)";
        case 44: var = "hmost (ID:44)";
        case 45: var = "hmybe (ID:45)";
        case 46: var = "hmyri (ID:46)";
        case 47: var = "hmycr (ID:47)";
        case 48: var = "hmyst (ID:48)";
        case 49: var = "omokung (ID:49)";
        case 50: var = "wmymech (ID:50)";
        case 51: var = "bmymoun (ID:51)";
        case 52: var = "wmymoun (ID:52)";
        case 53: var = "ofori (ID:53)";
        case 54: var = "ofost (ID:54)";
        case 55: var = "ofyri (ID:55)";
        case 56: var = "ofyst (ID:56)";
        case 57: var = "omori (ID:57)";
        case 58: var = "omost (ID:58)";
        case 59: var = "omyri (ID:59)";
        case 60: var = "omyst (ID:60)";
        case 61: var = "wmyplt (ID:61)";
        case 62: var = "wmopj (ID:62)";
        case 63: var = "bfypro (ID:63)";
        case 64: var = "hfypro (ID:64)";
        case 65: var = "kendl (ID:65)";
        case 66: var = "bmypol1 (ID:66)";
        case 67: var = "bmypol2 (ID:67)";
        case 68: var = "wmoprea (ID:68)";
        case 69: var = "sbfyst (ID:69)";
        case 70: var = "wmosci (ID:70)";
        case 71: var = "wmysgrd (ID:71)";
        case 72: var = "swmyhp1 (ID:72)";
        case 73: var = "swmyhp2 (ID:73)";
        case 74: var = "Sem Nome (ID:74)";
        case 75: var = "swfopro (ID:75)";
        case 76: var = "wfystew (ID:76)";
        case 77: var = "swmotr1 (ID:77)";
        case 78: var = "wmotr1 (ID:78)";
        case 79: var = "bmotr1 (ID:79)";
        case 80: var = "vbmybox (ID:80)";
        case 81: var = "vwmybox (ID:81)";
        case 82: var = "vhmyelv (ID:82)";
        case 83: var = "vbmyelv (ID:83)";
        case 84: var = "vimyelv (ID:84)";
        case 85: var = "vwfypro (ID:85)";
        case 86: var = "ryder3 (ID:86)";
        case 87: var = "vwfyst1 (ID:87)";
        case 88: var = "wfori (ID:88)";
        case 89: var = "wfost (ID:89)";
        case 90: var = "wfyjg (ID:90)";
        case 91: var = "wfyri (ID:91)";
        case 92: var = "wfyro (ID:92)";
        case 93: var = "wfyst (ID:93)";
        case 94: var = "wmori (ID:94)";
        case 95: var = "wmost (ID:95)";
        case 96: var = "wmyjg (ID:96)";
        case 97: var = "wmylg (ID:97)";
        case 98: var = "wmyri (ID:98)";
        case 99: var = "wmyro (ID:99)";
        case 100: var = "wmycr (ID:100)";
        case 101: var = "wmyst (ID:101)";
        case 102: var = "ballas1 (ID:102)";
        case 103: var = "ballas2 (ID:103)";
        case 104: var = "ballas3 (ID:104)";
        case 105: var = "fam1 (ID:105)";
        case 106: var = "fam2 (ID:106)";
        case 107: var = "fam3 (ID:107)";
        case 108: var = "lsv1 (ID:108)";
        case 109: var = "lsv2 (ID:109)";
        case 110: var = "lsv3 (ID:110)";
        case 111: var = "maffa (ID:111)";
        case 112: var = "maffb (ID:112)";
        case 113: var = "mafboss (ID:113)";
        case 114: var = "vla1 (ID:114)";
        case 115: var = "vla2 (ID:115)";
        case 116: var = "vla3 (ID:116)";
        case 117: var = "triada (ID:117)";
        case 118: var = "triadb (ID:118)";
        case 119: var = "sindaco (ID:119)";
        case 120: var = "triboss (ID:120)";
        case 121: var = "dnb1 (ID:121)";
        case 122: var = "dnb2 (ID:122)";
        case 123: var = "dnb3 (ID:123)";
        case 124: var = "vmaff1 (ID:124)";
        case 125: var = "vmaff2 (ID:125)";
        case 126: var = "vmaff3 (ID:126)";
        case 127: var = "vmaff4 (ID:127)";
        case 128: var = "dnmylc (ID:128)";
        case 129: var = "dnfolc1 (ID:129)";
        case 130: var = "dnfolc2 (ID:130)";
        case 131: var = "dnfylc (ID:131)";
        case 132: var = "dnmolc1 (ID:132)";
        case 133: var = "dnmolc2 (ID:133)";
        case 134: var = "sbmotr2 (ID:134)";
        case 135: var = "swmotr2 (ID:135)";
        case 136: var = "sbmytr3 (ID:136)";
        case 137: var = "swmotr3 (ID:137)";
        case 138: var = "wfybe (ID:138)";
        case 139: var = "bfybe (ID:139)";
        case 140: var = "hfybe (ID:140)";
        case 141: var = "sofybu (ID:141)";
        case 142: var = "sbmyst (ID:142)";
        case 143: var = "sbmycr (ID:143)";
        case 144: var = "bmycg (ID:144)";
        case 145: var = "wfycrk (ID:145)";
        case 146: var = "hmycm (ID:146)";
        case 147: var = "wmybu (ID:147)";
        case 148: var = "bfybu (ID:148)";
        case 149: var = "smokev (ID:149)";
        case 150: var = "wfybu (ID:150)";
        case 151: var = "dwfylc1 (ID:151)";
        case 152: var = "wfypro (ID:152)";
        case 153: var = "wmyconb (ID:153)";
        case 154: var = "wmybe (ID:154)";
        case 155: var = "wmypizz (ID:155)";
        case 156: var = "bmobar (ID:156)";
        case 157: var = "cwfyhb (ID:157)";
        case 158: var = "cwmofr (ID:158)";
        case 159: var = "cwmohb1 (ID:159)";
        case 160: var = "cwmohb2 (ID:160)";
        case 161: var = "cwmyfr (ID:161)";
        case 162: var = "cwmyhb1 (ID:162)";
        case 163: var = "bmyboun (ID:163)";
        case 164: var = "wmyboun (ID:164)";
        case 165: var = "wmomib (ID:165)";
        case 166: var = "bmymib (ID:166)";
        case 167: var = "wmybell (ID:167)";
        case 168: var = "bmochil (ID:168)";
        case 169: var = "sofyri (ID:169)";
        case 170: var = "somyst (ID:170)";
        case 171: var = "vwmybjd (ID:171)";
        case 172: var = "vwfycrp (ID:172)";
        case 173: var = "sfr1 (ID:173)";
        case 174: var = "sfr2 (ID:174)";
        case 175: var = "sfr3 (ID:175)";
        case 176: var = "bmybar (ID:176)";
        case 177: var = "wmybar (ID:177)";
        case 178: var = "wfysex (ID:178)";
        case 179: var = "wmyammo (ID:179)";
        case 180: var = "bmytatt (ID:180)";
        case 181: var = "vwmycr (ID:181)";
        case 182: var = "vbmocd (ID:182)";
        case 183: var = "vbmycr (ID:183)";
        case 184: var = "vhmycr (ID:184)";
        case 185: var = "sbmyri (ID:185)";
        case 186: var = "somyri (ID:186)";
        case 187: var = "somybu (ID:187)";
        case 188: var = "swmyst (ID:188)";
        case 189: var = "wmyva (ID:189)";
        case 190: var = "copgrl3 (ID:190)";
        case 191: var = "gungrl3 (ID:191)";
        case 192: var = "mecgrl3 (ID:192)";
        case 193: var = "nurgrl3 (ID:193)";
        case 194: var = "crogrl3 (ID:194)";
        case 195: var = "gangrl3 (ID:195)";
        case 196: var = "cwfofr (ID:196)";
        case 197: var = "cwfohb (ID:197)";
        case 198: var = "cwfyfr1 (ID:198)";
        case 199: var = "cwfyfr2 (ID:199)";
        case 200: var = "cwmyhb2 (ID:200)";
        case 201: var = "dwfylc2 (ID:201)";
        case 202: var = "dwmylc2 (ID:202)";
        case 203: var = "omykara (ID:203)";
        case 204: var = "wmykara (ID:204)";
        case 205: var = "wfyburg (ID:205)";
        case 206: var = "vwmycd (ID:206)";
        case 207: var = "vhfypro (ID:207)";
        case 208: var = "suzie (ID:208)";
        case 209: var = "omonood (ID:209)";
        case 210: var = "omoboat (ID:210)";
        case 211: var = "wfyclot (ID:211)";
        case 212: var = "vwmotr1 (ID:212)";
        case 213: var = "vwmotr2 (ID:213)";
        case 214: var = "vwfywai (ID:214)";
        case 215: var = "sbfori (ID:215)";
        case 216: var = "swfyri (ID:216)";
        case 217: var = "wmyclot (ID:217)";
        case 218: var = "sbfost (ID:218)";
        case 219: var = "sbfyri (ID:219)";
        case 220: var = "sbmocd (ID:220)";
        case 221: var = "sbmori (ID:221)";
        case 222: var = "sbmost (ID:222)";
        case 223: var = "shmycr (ID:223)";
        case 224: var = "sofori (ID:224)";
        case 225: var = "sofost (ID:225)";
        case 226: var = "sofyst (ID:226)";
        case 227: var = "somobu (ID:227)";
        case 228: var = "somori (ID:228)";
        case 229: var = "somost (ID:229)";
        case 230: var = "swmotr5 (ID:230)";
        case 231: var = "swfori (ID:231)";
        case 232: var = "swfost (ID:232)";
        case 233: var = "swfyst (ID:233)";
        case 234: var = "swmocd (ID:234)";
        case 235: var = "swmori (ID:235)";
        case 236: var = "swmost (ID:236)";
        case 237: var = "shfypro (ID:237)";
        case 238: var = "sbfypro (ID:238)";
        case 239: var = "swmotr4 (ID:239)";
        case 240: var = "swmyri (ID:240)";
        case 241: var = "smyst (ID:241)";
        case 242: var = "smyst2 (ID:242)";
        case 243: var = "sfypro (ID:243)";
        case 244: var = "vbfyst2 (ID:244)";
        case 245: var = "vbfypro (ID:245)";
        case 246: var = "vhfyst3 (ID:246)";
        case 247: var = "bikera (ID:247)";
        case 248: var = "bikerb (ID:248)";
        case 249: var = "bmypimp (ID:249)";
        case 250: var = "swmycr (ID:250)";
        case 251: var = "wfylg (ID:251)";
        case 252: var = "wmyva2 (ID:252)";
        case 253: var = "bmosec (ID:253)";
        case 254: var = "bikdrug (ID:254)";
        case 255: var = "wmych (ID:255)";
        case 256: var = "sbfystr (ID:256)";
        case 257: var = "swfystr (ID:257)";
        case 258: var = "heck1 (ID:258)";
        case 259: var = "heck2 (ID:259)";
        case 260: var = "bmycon (ID:260)";
        case 261: var = "wmycd1 (ID:261)";
        case 262: var = "bmocd (ID:262)";
        case 263: var = "vwfywa2 (ID:263)";
        case 264: var = "wmoice (ID:264)";
        case 265: var = "tenpen (ID:265)";
        case 266: var = "pulaski (ID:266)";
        case 267: var = "hern (ID:267)";
        case 268: var = "dwayne (ID:268)";
        case 269: var = "smoke (ID:269)";
        case 270: var = "sweet (ID:270)";
        case 271: var = "ryder (ID:271)";
        case 272: var = "forelli (ID:272)";
        case 273: var = "tbone (ID:273)";
        case 274: var = "laemt1 (ID:274)";
        case 275: var = "lvemt1 (ID:275)";
        case 276: var = "sfemt1 (ID:276)";
        case 277: var = "lafd1 (ID:277)";
        case 278: var = "lvfd1 (ID:278)";
        case 279: var = "sffd1 (ID:279)";
        case 280: var = "lapd1 (ID:280)";
        case 281: var = "sfpd1 (ID:281)";
        case 282: var = "lvpd1 (ID:282)";
        case 283: var = "csher (ID:283)";
        case 284: var = "lapdm1 (ID:284)";
        case 285: var = "swat (ID:285)";
        case 286: var = "fbi (ID:286)";
        case 287: var = "army (ID:287)";
        case 288: var = "dsher (ID:288)";
        case 289: var = "zero (ID:289)";
        case 290: var = "rose (ID:290)";
        case 291: var = "paul (ID:291)";
        case 292: var = "cesar (ID:292)";
        case 293: var = "ogloc (ID:293)";
        case 294: var = "wuzimu (ID:294)";
        case 295: var = "torino (ID:295)";
        case 296: var = "jizzy (ID:296)";
        case 297: var = "maddogg (ID:297)";
        case 298: var = "cat (ID:298)";
        case 299: var = "claude (ID:299)";
        case 300: var = "lapdna (ID:300)";
        case 301: var = "sfpdna (ID:301)";
        case 302: var = "lvpdna (ID:302)";
        case 303: var = "lapdpc (ID:303)";
        case 304: var = "lapdpd (ID:304)";
        case 305: var = "lvpdpc (ID:305)";
        case 306: var = "wfyclpd (ID:306)";
        case 307: var = "vbfycpd (ID:307)";
        case 308: var = "wfyclem (ID:308)";
        case 309: var = "wfycllv (ID:309)";
        case 310: var = "csherna (ID:310)";
        case 311: var = "dsherna (ID:311)";
    }
    return var;
}*/
