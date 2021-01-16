#include YSI\y_hooks

#define check_system                    1
#define name_login                      2
#define pass_login                      3
#define name_register                   4
#define pass_register                   5
#define pass_register_confirm           6
#define email_register                  7
#define sexo_register                   8

#define DEFAULT_SKIN_BOY                97
#define DEFAULT_SKIN_GIRL               93

new t_login[MAX_PLAYERS];

hook OnPlayerConnect(playerid)
{
    new name[MAX_PLAYER_NAME];

    GetPlayerName(playerid, name, MAX_PLAYER_NAME);
    format(pPlayerInfo[playerid][pNome], MAX_PLAYER_NAME, name);
    PlayerTextDrawSetString(playerid, TDPlayerLogin[playerid][0], name);

    new date[3];

    getdate(date[0], date[1], date[2]);

    if((date[2] == 24 && date[1] == 12) || (date[2] == 25 && date[1] == 12))
        format(String, sizeof(String), "http://vidarealcrias.com/songs/login/christimas.mp3");
    else if((date[2] == 31 && date[1] == 12) || (date[2] == 01 && date[1] == 01))
        format(String, sizeof(String), "http://vidarealcrias.com/songs/login/newyear.mp3");
    else
        format(String, sizeof(String), "http://vidarealcrias.com/songs/login/_%d.mp3", random(10));

    PlayAudioStreamForPlayer(playerid, String);
    OnClearChat(playerid);

    SetPlayerColor(playerid, White);
    SetPlayerName(playerid, "Verificando_Dispositivo");

    ShowPlayerDialog(playerid, check_system, DIALOG_STYLE_MSGBOX, "{FF0000}ATENCÃO", "{FFFFFF}Por onde você vai jogar?\n\n{FF0000}Observação: Se você não selecionar a opção correta podera ocasionar em bugs!!", "Android", "Computador");

    t_login[playerid] = SetTimerEx("OnPlayerLoginKick", 300000, false, "d", playerid);
    return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
    enum e_al
    {
        Float:e_al_x,
        Float:e_al_y,
        Float:e_al_z,
        Float:e_al_x1,
        Float:e_al_y1,
        Float:e_al_z1
    };

    new AnimsLogin[3][e_al] =
    {
        {161.9850, -1963.3818, 38.5807, 852.1138, -1957.2549, 85.3233}, //ls
        {2068.0583, 825.6366, 29.9414, 1812.3918, 2533.0408, 100.6096}, //lv
        {-2426.7578, 316.2170, 37.6387, -1628.6191, -415.7397, 80.0648} //sf
    };

    new rand = random(sizeof(AnimsLogin));

    TogglePlayerSpectating(playerid, true);
    InterpolateCameraPos(playerid, AnimsLogin[rand][e_al_x], AnimsLogin[rand][e_al_y], AnimsLogin[rand][e_al_z], AnimsLogin[rand][e_al_x1], AnimsLogin[rand][e_al_y1], AnimsLogin[rand][e_al_z1], 50000);
    InterpolateCameraLookAt(playerid, AnimsLogin[rand][e_al_x], AnimsLogin[rand][e_al_y], AnimsLogin[rand][e_al_z], AnimsLogin[rand][e_al_x1], AnimsLogin[rand][e_al_y1], AnimsLogin[rand][e_al_z1], 50000);
	return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    KillTimer(t_login[playerid]);
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case check_system: return ( response ? ShowPlayerLogin(playerid, true) : ShowPlayerLogin(playerid, false) );

        case name_login:
        {
            if(!strlen(inputtext) || !response) return 0;

            format(pPlayerInfo[playerid][pNome], MAX_PLAYER_NAME, inputtext);

            PlayerTextDrawSetString(playerid, TDPlayerLogin[playerid][0], inputtext);
            PlayerTextDrawShow(playerid, TDPlayerLogin[playerid][0]);
            return 1;
        }
        case pass_login:
        {
            new txt[200];

            if(!strlen(inputtext) || !response)
            {
                if(!IsMobile[playerid]) return 0;

                strcat(txt, "{0080FF}Vida Real Crias © - Todos direitos reservados\n\n");
                format(String, 100, "{FFFFFF}Olá %s, você está registrado(a), digite sua senha para proseguir\n", pPlayerInfo[playerid][pNome]);
                strcat(txt, String);

                return ShowPlayerDialog(playerid, pass_login, DIALOG_STYLE_INPUT, "{CCCCCC}Login - Nome", txt, "Entrar", "Cancelar");
            }

            format(pPlayerInfo[playerid][pSenha], MAX_PLAYER_PASS, inputtext);

            if(!IsMobile[playerid])
            {
                PlayerTextDrawSetString(playerid, TDPlayerLogin[playerid][1], HidePasswordTextDraw(inputtext));
                PlayerTextDrawShow(playerid, TDPlayerLogin[playerid][1]);
            }
            else
            {
                new query[300];
                mysql_format(IDConexao, query, 300, "SELECT `Nome` AND `Senha` FROM `Contas` WHERE `Nome`='%e' AND `Senha`=MD5('%e')", pPlayerInfo[playerid][pNome], pPlayerInfo[playerid][pSenha]);
                mysql_query(IDConexao, query);

                if(cache_num_rows() == 0)
                {
                    strcat(txt, "{0080FF}Vida Real Crias © - Todos direitos reservados\n\n");
                    format(String, 100, "{FFFFFF}Olá %s, você está registrado(a), digite sua senha para proseguir\n\n", pPlayerInfo[playerid][pNome]);
                    strcat(txt, String);
                    strcat(txt, "{FF4000}Senha incorreta\n");

                    return ShowPlayerDialog(playerid, pass_login, DIALOG_STYLE_INPUT, "{CCCCCC}Login - Senha", txt, "Entrar", "Cancelar");
                }

                mysql_format(IDConexao, query, 200, "SELECT * FROM `Contas` WHERE `Nome`='%e'", pPlayerInfo[playerid][pNome]);
                mysql_tquery(IDConexao, query, "LoadAccounts", "d", playerid);
            }
            return 1;
        }
        case name_register:
        {
            if(!strlen(inputtext) || !response) return 0;

            if(strlen(inputtext) < MIN_PLAYER_NAME || strlen(inputtext) > MAX_PLAYER_NAME)
                return SendClientMessage(playerid, Yellow, "Digite um nome entre 3 a 30 caracteres");

            if(!IsValidUsername(inputtext))
                return SendClientMessage(playerid, Yellow, "Digite um nome sem caracteres especiais");

            format(pPlayerInfo[playerid][pNome], MAX_PLAYER_NAME, inputtext);

            PlayerTextDrawSetString(playerid, TDPlayerRegister[playerid][0], inputtext);
            PlayerTextDrawShow(playerid, TDPlayerRegister[playerid][0]);
            return 1;
        }
        case pass_register:
        {
            new txt[200];

            if(!strlen(inputtext) || !response)
            {
                if(!IsMobile[playerid]) return 0;

                strcat(txt, "{0080FF}Vida Real Crias © - Todos direitos reservados\n\n");
                format(String, 100, "{FFFFFF}Olá %s, você está registrado(a), digite sua senha para proseguir\n", pPlayerInfo[playerid][pNome]);
                strcat(txt, String);

                return ShowPlayerDialog(playerid, pass_register, DIALOG_STYLE_INPUT, "{CCCCCC}Login - Nome", txt, "Registrar-se", "Cancelar");
            }

            format(pPlayerInfo[playerid][pSenha], MAX_PLAYER_PASS, inputtext);

            if(!IsMobile[playerid])
            {
                if(strlen(inputtext) < MIN_PLAYER_PASS || strlen(inputtext) > MAX_PLAYER_PASS)
                    return SendClientMessage(playerid, Yellow, "Digite uma senha entre 6 a 30 caracteres");

                PlayerTextDrawSetString(playerid, TDPlayerRegister[playerid][1], HidePasswordTextDraw(inputtext));
                PlayerTextDrawShow(playerid, TDPlayerRegister[playerid][1]);
            }
            else
            {
                if(strlen(inputtext) < MIN_PLAYER_PASS || strlen(inputtext) > MAX_PLAYER_PASS)
                {
                    strcat(txt, "{0080FF}Vida Real Crias © - Todos direitos reservados\n\n");
                    format(String, 100, "{FFFFFF}Olá %s, você está registrado(a), digite sua senha para proseguir\n", pPlayerInfo[playerid][pNome]);
                    strcat(txt, String);
                    strcat(txt, "{FF4000}Digite uma senha entre 6 a 30 caracteres\n");

                    return ShowPlayerDialog(playerid, pass_register, DIALOG_STYLE_INPUT, "{CCCCCC}Registro - Senha", txt, "Registrar-se", "Cancelar");
                }

                ShowPlayerDialog(playerid, email_register, DIALOG_STYLE_INPUT, "{FF0000}Registro - E-mail", "{FFFFFF}Digite seu e-mail em baixo para efetuar o registro:", "Continuar", "Cancelar");
            }
            return 1;
        }
        case pass_register_confirm:
        {
            if(!strlen(inputtext) || !response) return 0;

            if(strlen(inputtext) < MIN_PLAYER_PASS || strlen(inputtext) > MAX_PLAYER_PASS)
                return SendClientMessage(playerid, Yellow, "Digite uma senha entre 6 a 30 caracteres");

            format(pPlayerInfo[playerid][pSenhaConfirm], MAX_PLAYER_PASS, inputtext);

            PlayerTextDrawSetString(playerid, TDPlayerRegister[playerid][2], HidePasswordTextDraw(inputtext));
            PlayerTextDrawShow(playerid, TDPlayerRegister[playerid][2]);
            return 1;
        }
        case email_register:
        {
            new txt[200];

            if(!strlen(inputtext) || !response)
            {
                if(!IsMobile[playerid]) return 0;

                strcat(txt, "{0080FF}Vida Real Crias © - Todos direitos reservados\n\n");
                strcat(txt, "{FFFFFF}Digite seu e-mail em baixo para efetuar o registro:");

                return ShowPlayerDialog(playerid, email_register, DIALOG_STYLE_INPUT, "{FF0000}Registro - E-mail", txt, "Continuar", "Cancelar");
            }

            format(pPlayerInfo[playerid][pEmail], MAX_PLAYER_EMAIL, inputtext);

            if(!IsMobile[playerid])
            {
                if(strlen(inputtext) < MIN_PLAYER_EMAIL || strlen(inputtext) > MAX_PLAYER_EMAIL)
                    return SendClientMessage(playerid, Yellow, "Digite um e-mail entre 10 a 50 caracteres");

                PlayerTextDrawSetString(playerid, TDPlayerRegister[playerid][3], inputtext);
                PlayerTextDrawShow(playerid, TDPlayerRegister[playerid][3]);
            }
            else
            {
                if(strlen(inputtext) < MIN_PLAYER_EMAIL || strlen(inputtext) > MAX_PLAYER_EMAIL)
                {
                    strcat(txt, "{0080FF}Vida Real Crias © - Todos direitos reservados\n\n");
                    strcat(txt, "{FFFFFF}Digite seu e-mail em baixo para efetuar o registro:\n\n");
                    strcat(txt, "{FF4000}Digite um e-mail entre 10 a 50 caracteres");

                    return ShowPlayerDialog(playerid, email_register, DIALOG_STYLE_INPUT, "{FF0000}Registro - E-mail", txt, "Registrar-se", "Cancelar");

                }

                new query[200];
                mysql_format(IDConexao, query, 200, "SELECT * FROM Contas WHERE `Email`='%e'", pPlayerInfo[playerid][pEmail]);
                mysql_query(IDConexao, query);

                if(cache_num_rows())
                {
                    strcat(txt, "{0080FF}Vida Real Crias © - Todos direitos reservados\n\n");
                    strcat(txt, "{FFFFFF}Digite seu e-mail em baixo para efetuar o registro:\n\n");
                    strcat(txt, "{FF4000}E-mail já em uso, tente outro");

                    return ShowPlayerDialog(playerid, email_register, DIALOG_STYLE_INPUT, "{FF0000}Registro - E-mail", txt, "Registrar-se", "Cancelar");
                }

                ShowPlayerDialog(playerid, sexo_register, DIALOG_STYLE_MSGBOX, "{FF0000}Sexo", "{FFFFFF}Selecione seu sexo abaixo:", "Masculino", "Feminino");
            }
            return 1;
        }
        case sexo_register:
        {
            if(response)
            {
                PlayerInfo[playerid][sexo] = SEX_BOY;
                PlayerInfo[playerid][skin] = DEFAULT_SKIN_BOY;
            }
            else
            {
                PlayerInfo[playerid][sexo] = SEX_GIRL;
                PlayerInfo[playerid][skin] = DEFAULT_SKIN_GIRL;
            }

            if(IsMobile[playerid]) RegisterAccount(playerid);

            return 1;
        }
    }
    return 1;
}

stock ClickTextDrawLoginRegister(playerid, PlayerText:playertextid)
{
    if(playertextid == TDPlayerLogin[playerid][0])
        return ShowPlayerDialog(playerid, name_login, DIALOG_STYLE_INPUT, "{FF0000}Nome", "{FFFFFF}Digite seu nome em baixo para efetuar login : \n\n{FF0000}AVISO: Se o seu nome tiver caracteres especiais pode ser exibido como espaço,{FFFFFF} \nMas não se preocupe, isso não afetará o nome digitado", "Continuar", "Cancelar");

    if(playertextid == TDPlayerLogin[playerid][1])
        return ShowPlayerDialog(playerid, pass_login, DIALOG_STYLE_PASSWORD, "{FF0000}Senha", "{FFFFFF}Digite sua senha em baixo para efetuar login : \n\n{FF0000}Sua senha será escondida por *", "Continuar", "Cancelar");

    if(playertextid == TDPlayerLogin[playerid][2])
    {
        PlayerInfo[playerid][sexo] = -1;
        PlayerInfo[playerid][skin] = -1;
        HideTextDrawLogin(playerid);
        ShowTextDrawRegister(playerid);
        return 1;
    }
    if(playertextid == TDPlayerLogin[playerid][3])
    {
        if(pPlayerInfo[playerid][pNome] == 0 && pPlayerInfo[playerid][pSenha] == 0)
            return SendClientMessage(playerid, Erro, "Preencha os campos para proseguir");

        if(pPlayerInfo[playerid][pNome] == 0)
            return SendClientMessage(playerid, Erro, "Coloque seu nome");

        if(pPlayerInfo[playerid][pSenha] == 0)
            return SendClientMessage(playerid, Erro, "Coloque sua senha");

        new query[300];
        mysql_format(IDConexao, query, 200, "SELECT `Nome` FROM `Contas` WHERE `Nome`='%e'", pPlayerInfo[playerid][pNome]);
        mysql_query(IDConexao, query);

        if(cache_num_rows() == 0)
            return SendClientMessage(playerid, Erro, "Conta não registrada");

        mysql_format(IDConexao, query, 300, "SELECT `Nome` AND `Senha` FROM `Contas` WHERE `Nome`='%e' AND `Senha`=MD5('%e')", pPlayerInfo[playerid][pNome], pPlayerInfo[playerid][pSenha]);
        mysql_query(IDConexao, query);

        if(cache_num_rows() == 0)
            return SendClientMessage(playerid, Erro, "Senha Incorreta");

        mysql_format(IDConexao, query, 200, "SELECT * FROM `Contas` WHERE Nome='%e'", pPlayerInfo[playerid][pNome]);
        mysql_tquery(IDConexao, query, "LoadAccounts", "d", playerid);
        return 1;
    }

    if(playertextid == TDPlayerRegister[playerid][0])
        return ShowPlayerDialog(playerid, name_register, DIALOG_STYLE_INPUT, "{FF0000}Nome", "{FFFFFF}Digite seu nome em baixo para efetuar o registro : \n\n{FF0000}AVISO: Se o seu nome tiver caracteres especiais pode ser exibido como espaço,{FFFFFF} \nMas não se preocupe, isso não afetará o nome digitado", "Continuar", "Cancelar");

    if(playertextid == TDPlayerRegister[playerid][1])
        return ShowPlayerDialog(playerid, pass_register, DIALOG_STYLE_PASSWORD, "{FF0000}Senha", "{FFFFFF}Digite sua senha em baixo para efetuar o registro : \n\n{FF0000}Sua senha será escondida por *", "Continuar", "Cancelar");

    if(playertextid == TDPlayerRegister[playerid][2])
        return ShowPlayerDialog(playerid, pass_register_confirm, DIALOG_STYLE_PASSWORD, "{FF0000}Confirmar Senha", "{FFFFFF}Digite à mesma senha que digitou acima para efetuar o registro : \n\n{FF0000}Sua senha será escondida por *", "Continuar", "Cancelar");

    if(playertextid == TDPlayerRegister[playerid][3])
        return ShowPlayerDialog(playerid, email_register, DIALOG_STYLE_INPUT, "{FF0000}E-mail", "{FFFFFF}Digite seu e-mail em baixo para efetuar o registro:\n\n{FF0000}AVISO: Se o seu e-mail tiver caracteres especiais pode ser exibido como espaço,{FFFFFF} \nMas não se preocupe, isso não afetará o e-mail digitado", "Continuar", "Cancelar");

    if(playertextid == TDPlayerRegister[playerid][4])
    {
        if(pPlayerInfo[playerid][pNome] == 0)
            return SendClientMessage(playerid, Erro, "Coloque seu nome");

        if(pPlayerInfo[playerid][pSenha] == 0)
            return SendClientMessage(playerid, Erro, "Coloque sua senha");

        if(pPlayerInfo[playerid][pSenhaConfirm] == 0)
            return SendClientMessage(playerid, Erro, "Coloque à sua confirmação de senha");

        if(pPlayerInfo[playerid][pEmail] == 0)
            return SendClientMessage(playerid, Erro, "Coloque seu e-mail");

        if(PlayerInfo[playerid][sexo] == -1)
            return ShowPlayerDialog(playerid, sexo_register, DIALOG_STYLE_MSGBOX, "{FF0000}Sexo", "{FFFFFF}Selecione seu sexo e clique em \"registrar-se\" novamente", "Masculino", "Feminino");

        new query[300];
        mysql_format(IDConexao, query, 200, "SELECT * FROM Contas WHERE `Nome`='%s'", pPlayerInfo[playerid][pNome]);
        mysql_query(IDConexao, query);

        if(cache_num_rows())
            return SendClientMessage(playerid, Erro, "Nome já em uso, tente outro");

        if(strcmp(pPlayerInfo[playerid][pSenha], pPlayerInfo[playerid][pSenhaConfirm]))
            return SendClientMessage(playerid, Erro, "Às senhas digitadas não são iguais");

        mysql_format(IDConexao, query, 200, "SELECT * FROM Contas WHERE `Email`='%s'", pPlayerInfo[playerid][pEmail]);
        mysql_query(IDConexao, query);

        if(cache_num_rows())
            return SendClientMessage(playerid, Erro, "E-mail já em uso, tente outro");

        RegisterAccount(playerid);
        return 1;
    }
    return 1;
}

forward OnPlayerLoginKick(playerid);
public OnPlayerLoginKick(playerid)
{
    if(PlayerInfo[playerid][Logado]) return 0;

    KillTimer(t_login[playerid]);
    Kick(playerid);
    SendClientMessage(playerid, Red, "Você foi kickado por ficar ausente em login/registro por 5 minutos");
    return 1;
}

stock ShowPlayerLogin(playerid, bool:mobile)
{
    IsMobile[playerid] = (mobile ? true : false);

    LoadTDStatus(playerid);
    LoadTDPlayerVelocimetro(playerid);

    format(String, MAX_PLAYER_NAME, "%s_Entrando_%d", (mobile ? ("Android") : ("PC")), playerid);
    SetPlayerName(playerid, String);

    if(!mobile)
    {
        SelectTextDraw(playerid, Green);
        ShowTextDrawLogin(playerid);
        RemoveBugFirstAnimation(playerid);
    }
    else
    {
        new query[200], txt[200];
        mysql_format(IDConexao, query, 200, "SELECT `Nome` FROM `Contas` WHERE `Nome`='%e'", pPlayerInfo[playerid][pNome]);
        mysql_query(IDConexao, query);

        if(cache_num_rows())
        {
            strcat(txt, "{0080FF}Vida Real Crias © - Todos direitos reservados\n\n");
            format(String, 100, "{FFFFFF}Olá %s, você está registrado(a), digite sua senha para proseguir\n", pPlayerInfo[playerid][pNome]);
            strcat(txt, String);

            ShowPlayerDialog(playerid, pass_login, DIALOG_STYLE_INPUT, "{CCCCCC}Login - Nome", txt, "Entrar", "Cancelar");
        }
        else
        {
            strcat(txt, "{0080FF}Vida Real Crias © - Todos direitos reservados\n\n");
            format(String, 100, "{FFFFFF}Olá %s, você não está registrado(a), digite uma senha nova para proseguir\n", pPlayerInfo[playerid][pNome]);
            strcat(txt, String);

            ShowPlayerDialog(playerid, pass_register, DIALOG_STYLE_INPUT, "{CCCCCC}Login - Nome", txt, "Registrar-se", "Cancelar");
        }
    }
    return 1;
}

stock HidePasswordTextDraw(inputtext[])
{
    for(new text = 0; text < strlen(inputtext); text++)
    {
        inputtext[text] = ']';
    }

    format(String, MAX_PLAYER_PASS, inputtext);

    return String;
}

stock RegisterAccount(playerid)
{
    if(!pPlayerInfo[playerid][pNome] || !pPlayerInfo[playerid][pSenha] || !pPlayerInfo[playerid][pEmail])
    {
        SendClientMessage(playerid, Erro, "Erro no registro, se o problema persiste relate-o");
        Kick(playerid);
        return 1;
    }

    new coding[10];

    format(coding, 10, CreateRandomCode());

    new query[300];
    mysql_format(IDConexao, query, 300, "INSERT INTO `Contas` (`Nome`, `Senha`, `Email`, `Code`) VALUES ('%s', MD5('%e'), '%s', '%s')", pPlayerInfo[playerid][pNome], pPlayerInfo[playerid][pSenha], pPlayerInfo[playerid][pEmail], coding);
    mysql_tquery(IDConexao, query, "RegisterAccounts", "d", playerid);
    return 1;
}
