#include YSI\y_hooks

#define check_system                    1
#define name_login                      2
#define pass_login                      3
#define name_register                   4
#define pass_register                   5
#define pass_register_confirm           6
#define email_register                  7
#define sexo_register                   8
/*#define recover_account               9
#define recover_account_pass            10
#define recover_account_pass_ok         11*/

#define cell_login_name                 12
#define cell_login_pass                 13
#define cell_register_name              14
#define cell_register_pass              15
#define cell_register_email             16
#define cell_register_sexo              17

#define DEFAULT_SKIN_BOY                97
#define DEFAULT_SKIN_GIRL               93

new t_login[MAX_PLAYERS];

hook OnPlayerConnect(playerid)
{
    ShowPlayerDialog(playerid, check_system, DIALOG_STYLE_MSGBOX, "{FF0000}ATENCÃO", "{FFFFFF}Por onde você vai jogar?\n\n{FF0000}Observação: Se você não selecionar a opção correta podera ocasionar em bugs!!!", "Android", "Computador");

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
        case check_system:
        {
            if(response)
            {
                format(String, MAX_PLAYER_NAME, "Android_Entrando_%d", playerid);
                IsMobile[playerid] = true;

                ShowPlayerDialog(playerid, cell_login_name, DIALOG_STYLE_INPUT, "{CCCCCC}Login - Nome", "{FFFFFF}Digite o seu nome para poder entrar e depois clique em \"{FF0000}Continuar{FFFFFF}\"\nSe não tiver conta clique em\"{00FF00}Registrar{FFFFFF}\"", "Continuar", "Registrar");
            }
            else
            {
                format(String, MAX_PLAYER_NAME, "PC_Entrando_%d", playerid);
                IsMobile[playerid] = false;
                SelectTextDraw(playerid, Green);
                ShowTextDrawLogin(playerid);
                RemoveBugFirstAnimation(playerid);
                CheckVersionSAMP(playerid);
            }

            SetPlayerName(playerid, String);
            return 1;
        }
        case cell_login_name:
        {
            if(response)
            {
                if(!strlen(inputtext))
                    return ShowPlayerDialog(playerid, cell_login_name, DIALOG_STYLE_INPUT, "{CCCCCC}Login - Nome", "{FFFFFF}Digite o seu nome para poder entrar e depois clique em \"{FF0000}Continuar{FFFFFF}\"\nSe não tiver conta clique em\"{00FF00}Registrar{FFFFFF}\"", "Continuar", "Registrar");

                format(pPlayerInfo[playerid][pNome], MAX_PLAYER_NAME, inputtext);

                new query[150];
                mysql_format(IDConexao, query, 150, "SELECT `Nome` FROM `Contas` WHERE `Nome`='%s'", pPlayerInfo[playerid][pNome]);
                mysql_query(IDConexao, query);

                if(cache_num_rows() == 0)
                    return ShowPlayerDialog(playerid, cell_login_name, DIALOG_STYLE_INPUT, "{CCCCCC}Login - Nome", "{FFFFFF}Digite o seu nome para poder entrar e depois clique em \"{FF0000}Continuar{FFFFFF}\"\nSe não tiver conta clique em\"{00FF00}Registrar{FFFFFF}\"\n\n{FF0000}Conta não registrada", "Continuar", "Registrar");

                ShowPlayerDialog(playerid, cell_login_pass, DIALOG_STYLE_PASSWORD, "{CCCCCC}Login - Senha", "{FFFFFF}Digite a sua senha para poder entrar e depois clique em \"{FF0000}Entrar{FFFFFF}\"\nSe digitou nome errado clique em\"{00FF00}Voltar{FFFFFF}\"", "Entrar", "Voltar");
            }
            else
            {
                ShowPlayerDialog(playerid, cell_register_name, DIALOG_STYLE_INPUT, "{00FF00}Registro - Nome", "{FFFFFF}Digite seu novo nome e depois clique em \"{FF0000}Continuar{FFFFFF}\"\nSe já tiver conta clique em\"{00FF00}Voltar{FFFFFF}\"", "Continuar", "Voltar");
            }
            return 1;
        }
        case cell_login_pass:
        {
            if(response)
            {
                if(!strlen(inputtext))
                    return ShowPlayerDialog(playerid, cell_login_pass, DIALOG_STYLE_INPUT, "{CCCCCC}Login - Senha", "{FFFFFF}Digite a sua senha para poder entrar e depois clique em \"{FF0000}Entrar{FFFFFF}\"\nSe digitou nome errado clique em\"{00FF00}Voltar{FFFFFF}\"", "Entrar", "Voltar");

                format(pPlayerInfo[playerid][pSenha], MAX_PLAYER_PASS, inputtext);

                new query[300];
                mysql_format(IDConexao, query, 300, "SELECT `Nome` AND `Senha` FROM `Contas` WHERE `Nome`='%e' AND `Senha`=MD5('%s')", pPlayerInfo[playerid][pNome], pPlayerInfo[playerid][pSenha]);
                mysql_query(IDConexao, query);

                if(cache_num_rows() == 0)
                    return ShowPlayerDialog(playerid, cell_login_pass, DIALOG_STYLE_INPUT, "{CCCCCC}Login - Senha", "{FFFFFF}Digite a sua senha para poder entrar e depois clique em \"{FF0000}Entrar{FFFFFF}\"\nSe digitou nome errado clique em\"{00FF00}Voltar\"\n\n{FF0000}Senha Incorreta", "Entrar", "Voltar");

                mysql_format(IDConexao, query, 150, "SELECT * FROM `Contas` WHERE Nome='%e'", pPlayerInfo[playerid][pNome]);
                mysql_tquery(IDConexao, query, "LoadAccounts", "d", playerid);
            }
            else
            {
                ShowPlayerDialog(playerid, cell_login_name, DIALOG_STYLE_INPUT, "{CCCCCC}Login - Nome", "{FFFFFF}Digite o seu nome para poder entrar e depois clique em \"{FF0000}Continuar{FFFFFF}\"\nSe não tiver conta clique em\"{00FF00}Registrar\"", "Continuar", "Registrar");
            }
            return 1;
        }
        case cell_register_name:
        {
            if(response)
            {
                if(!strlen(inputtext))
                    return ShowPlayerDialog(playerid, cell_register_name, DIALOG_STYLE_INPUT, "{00FF00}Registro - Nome", "{FFFFFF}Digite seu novo nome e depois clique em \"{FF0000}Continuar{FFFFFF}\"\nSe já tiver conta clique em\"{00FF00}Voltar{FFFFFF}\"", "Continuar", "Voltar");

                format(pPlayerInfo[playerid][pNome], MAX_PLAYER_NAME, inputtext);

                new query[150];
                mysql_format(IDConexao, query, 150, "SELECT `Nome` FROM `Contas` WHERE `Nome`='%e'", pPlayerInfo[playerid][pNome]);
                mysql_query(IDConexao, query);

                if(cache_num_rows())
                    return ShowPlayerDialog(playerid, cell_register_name, DIALOG_STYLE_INPUT, "{00FF00}Registro - Nome", "{FFFFFF}Digite seu novo nome e depois clique em \"{FF0000}Continuar{FFFFFF}\"\nSe já tiver conta clique em\"{00FF00}Voltar\"\n\n{FF0000}Nome já em uso", "Continuar", "Voltar");

                ShowPlayerDialog(playerid, cell_register_pass, DIALOG_STYLE_PASSWORD, "{CCCCCC}Registro - Senha", "{FFFFFF}Digite a sua nova senha e depois clique em \"{FF0000}Continuar{FFFFFF}\"\nSe digitou nome errado clique em\"{00FF00}Voltar{FFFFFF}\"", "Continuar", "Voltar");
            }
            else
            {
                ShowPlayerDialog(playerid, cell_login_name, DIALOG_STYLE_INPUT, "{CCCCCC}Login - Nome", "{FFFFFF}Digite o seu nome para poder entrar e depois clique em \"{FF0000}Continuar{FFFFFF}\"\nSe não tiver conta clique em\"{00FF00}Registrar\"", "Continuar", "Registrar");
            }
            return 1;
        }
        case cell_register_pass:
        {
            if(response)
            {
                if(!strlen(inputtext))
                    return ShowPlayerDialog(playerid, cell_register_pass, DIALOG_STYLE_PASSWORD, "{CCCCCC}Registro - Senha", "{FFFFFF}Digite a sua nova senha e depois clique em \"{FF0000}Continuar{FFFFFF}\"\nSe digitou nome errado clique em\"{00FF00}Voltar{FFFFFF}\"", "Continuar", "Voltar");

                if(strlen(inputtext) < MIN_PLAYER_PASS || strlen(inputtext) > MAX_PLAYER_PASS)
                    return ShowPlayerDialog(playerid, cell_register_pass, DIALOG_STYLE_PASSWORD, "{CCCCCC}Registro - Senha", "{FFFFFF}Digite a sua nova senha e depois clique em \"{FF0000}Continuar{FFFFFF}\"\nSe digitou nome errado clique em\"{00FF00}Voltar\"\n\n{FF0000}Digite uma senha entre 6 a 30 caracteres", "Continuar", "Voltar");

                format(pPlayerInfo[playerid][pSenha], MAX_PLAYER_PASS, inputtext);

                ShowPlayerDialog(playerid, cell_register_email, DIALOG_STYLE_INPUT, "{00FF00}Registro - Email", "{FFFFFF}Digite abaixo seu email e clique em \"{FF0000}Continuar{FFFFFF}\"\nSe digitou sua sennha errada clique em\"{00FF00}Voltar{FFFFFF}\"", "Continuar", "Voltar");
            }
            else
            {
                ShowPlayerDialog(playerid, cell_register_name, DIALOG_STYLE_INPUT, "{00FF00}Registro - Nome", "{FFFFFF}Digite seu novo nome e depois clique em \"{FF0000}Continuar{FFFFFF}\"\nSe já tiver conta clique em\"{00FF00}Voltar{FFFFFF}\"", "Continuar", "Voltar");
            }
            return 1;
        }
        case cell_register_email:
        {
            if(response)
            {
                if(!strlen(inputtext))
                    return ShowPlayerDialog(playerid, cell_register_email, DIALOG_STYLE_INPUT, "{00FF00}Registro - Email", "{FFFFFF}Digite abaixo seu email e clique em \"{FF0000}Continuar{FFFFFF}\"\nSe digitou sua sennha errada clique em\"{00FF00}Voltar{FFFFFF}\"", "Continuar", "Voltar");

                if(strlen(inputtext) < MIN_PLAYER_EMAIL || strlen(inputtext) > MAX_PLAYER_EMAIL)
                    return ShowPlayerDialog(playerid, cell_register_email, DIALOG_STYLE_INPUT, "{00FF00}Registro - Email", "{FFFFFF}Digite abaixo seu email e clique em \"{FF0000}Continuar{FFFFFF}\"\nSe digitou sua sennha errada clique em\"{00FF00}Voltar\"\n\n{FF0000}Digite um email entre 10 a 50 caracteres", "Continuar", "Voltar");

                format(pPlayerInfo[playerid][pEmail], MAX_PLAYER_EMAIL, inputtext);

                new query[200];
                mysql_format(IDConexao, query, 200, "SELECT `Email` FROM `Contas` WHERE `Email`='%e'", pPlayerInfo[playerid][pEmail]);
                mysql_query(IDConexao, query);

                if(cache_num_rows())
                    return ShowPlayerDialog(playerid, cell_register_email, DIALOG_STYLE_INPUT, "{00FF00}Registro - Email", "{FFFFFF}Digite abaixo seu email e clique em \"{FF0000}Continuar{FFFFFF}\"\nSe digitou sua sennha errada clique em\"{00FF00}Voltar\"\n\n{FF0000}Email já em uso", "Continuar", "Voltar");

                ShowPlayerDialog(playerid, cell_register_sexo, DIALOG_STYLE_MSGBOX, "{00FF00}Registro", "{FFFFFF}Escolha seu sexo", "Masculino", "Feminino");
            }
            else
            {
                ShowPlayerDialog(playerid, cell_register_pass, DIALOG_STYLE_PASSWORD, "{CCCCCC}Registro - Senha", "{FFFFFF}Digite a sua nova senha e depois clique em \"{FF0000}Continuar{FFFFFF}\"\nSe digitou nome errado clique em\"{00FF00}Voltar{FFFFFF}\"", "Continuar", "Voltar");
            }
            return 1;
        }
        case cell_register_sexo:
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

            new coding[10];

            format(coding, 10, CreateRandomCode());

            new query[300];
            mysql_format(IDConexao, query, 300, "INSERT INTO `Contas` (`Nome`, `Senha`, `Email`, `Code`) VALUES ('%s', MD5('%s'), '%s', '%s')", pPlayerInfo[playerid][pNome], pPlayerInfo[playerid][pSenha], pPlayerInfo[playerid][pEmail], coding);
            mysql_tquery(IDConexao, query, "RegisterAccounts", "d", playerid);
            return 1;
        }
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
            if(!strlen(inputtext) || !response) return 0;

            format(pPlayerInfo[playerid][pSenha], MAX_PLAYER_PASS, inputtext);

            for(new i=0; i < strlen(inputtext); i++)
                { inputtext[i] = ']'; }

            PlayerTextDrawSetString(playerid, TDPlayerLogin[playerid][1], inputtext);
            PlayerTextDrawShow(playerid, TDPlayerLogin[playerid][1]);
            return 1;
        }
        case name_register:
        {
            if(!strlen(inputtext) || !response) return 0;

            if(strlen(inputtext) < MIN_PLAYER_NAME || strlen(inputtext) > MAX_PLAYER_NAME)
                return SendClientMessage(playerid, 0xFFFF80AA, "Digite um nome entre 3 a 30 caracteres!");

            if(!IsValidUsername(inputtext))
                return SendClientMessage(playerid, 0xFFFF80AA, "| INFO | Digite um nome sem caracteres especiais!");

            format(pPlayerInfo[playerid][pNome], MAX_PLAYER_NAME, inputtext);

            PlayerTextDrawSetString(playerid, TDPlayerRegister[playerid][0], inputtext);
            PlayerTextDrawShow(playerid, TDPlayerRegister[playerid][0]);
            return 1;
        }
        case pass_register:
        {
            if(!strlen(inputtext) || !response) return 0;

            if(strlen(inputtext) < MIN_PLAYER_PASS || strlen(inputtext) > MAX_PLAYER_PASS)
                return SendClientMessage(playerid, 0xFFFF80AA, "Digite uma senha entre 6 a 30 caracteres!");

            format(pPlayerInfo[playerid][pSenha], MAX_PLAYER_PASS, inputtext);

            for(new i=0; i < strlen(inputtext); i++)
                { inputtext[i] = ']'; }

            PlayerTextDrawSetString(playerid, TDPlayerRegister[playerid][1], inputtext);
            PlayerTextDrawShow(playerid, TDPlayerRegister[playerid][1]);
            return 1;
        }
        case pass_register_confirm:
        {
            if(!strlen(inputtext) || !response) return 0;

            if(strlen(inputtext) < MIN_PLAYER_PASS || strlen(inputtext) > MAX_PLAYER_PASS)
                return SendClientMessage(playerid, 0xFFFF80AA, "Digite uma senha entre 6 a 30 caracteres!");

            format(pPlayerInfo[playerid][pSenhaConfirm], MAX_PLAYER_PASS, inputtext);

            for(new i=0; i < strlen(inputtext); i++)
                { inputtext[i] = ']'; }

            PlayerTextDrawSetString(playerid, TDPlayerRegister[playerid][2], inputtext);
            PlayerTextDrawShow(playerid, TDPlayerRegister[playerid][2]);
            return 1;
        }
        case email_register:
        {
            if(!strlen(inputtext) || !response) return 0;

            if(strlen(inputtext) < MIN_PLAYER_EMAIL || strlen(inputtext) > MAX_PLAYER_EMAIL)
                return SendClientMessage(playerid, 0xFFFF80AA, "Digite um e-mail entre 10 a 50 caracteres!");

            format(pPlayerInfo[playerid][pEmail], MAX_PLAYER_EMAIL, inputtext);

            PlayerTextDrawSetString(playerid, TDPlayerRegister[playerid][3], inputtext);
            PlayerTextDrawShow(playerid, TDPlayerRegister[playerid][3]);
            return 1;
        }
        case sexo_register:
        {
            if(response)
            {
                if(PlayerInfo[playerid][sexo] == SEX_BOY)
                    return SendClientMessage(playerid, Erro, "Você já selecionou o sexo \"masculino\"");

                PlayerInfo[playerid][sexo] = SEX_BOY;
                PlayerInfo[playerid][skin] = DEFAULT_SKIN_BOY;
            }
            else
            {
                if(PlayerInfo[playerid][sexo] == SEX_GIRL)
                    return SendClientMessage(playerid, Erro, "Você já selecionou o sexo \"feminino\"");

                PlayerInfo[playerid][sexo] = SEX_GIRL;
                PlayerInfo[playerid][skin] = DEFAULT_SKIN_GIRL;
            }
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
        mysql_format(IDConexao, query, 150, "SELECT `Nome` FROM `Contas` WHERE `Nome`='%s'", pPlayerInfo[playerid][pNome]);
        mysql_query(IDConexao, query);

        if(cache_num_rows() == 0)
            return SendClientMessage(playerid, Erro, "Conta não registrada");

        mysql_format(IDConexao, query, 300, "SELECT `Nome` AND `Senha` FROM `Contas` WHERE `Nome`='%e' AND `Senha`=MD5('%s')", pPlayerInfo[playerid][pNome], pPlayerInfo[playerid][pSenha]);
        mysql_query(IDConexao, query);

        if(cache_num_rows() == 0)
            return SendClientMessage(playerid, Erro, "Senha Incorreta");

        mysql_format(IDConexao, query, 150, "SELECT * FROM `Contas` WHERE Nome='%s'", pPlayerInfo[playerid][pNome]);
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
        return ShowPlayerDialog(playerid, email_register, DIALOG_STYLE_INPUT, "{FF0000}E-mail", "{FFFFFF}Digite seu e-mail em baixo para efetuar o registro : \n\n{FF0000}AVISO: Se o seu e-mail tiver caracteres especiais pode ser exibido como espaço,{FFFFFF} \nMas não se preocupe, isso não afetará o e-mail digitado", "Continuar", "Cancelar");

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
            return ShowPlayerDialog(playerid, sexo_register, DIALOG_STYLE_MSGBOX, "{FF0000}Sexo", "{FFFFFF}Selecione seu sexo e clique em \"registrar-se\" novamente!", "Masculino", "Feminino");

        new query[400];
        mysql_format(IDConexao, query, 150, "SELECT * FROM Contas WHERE Nome='%s'", pPlayerInfo[playerid][pNome]);
        mysql_query(IDConexao, query);

        if(cache_num_rows())
            return SendClientMessage(playerid, Erro, "Nome já em uso, tente outro");

        if(strcmp(pPlayerInfo[playerid][pSenha], pPlayerInfo[playerid][pSenhaConfirm]))
            return SendClientMessage(playerid, Erro, "Às senhas digitadas não são iguais");

        mysql_format(IDConexao, query, 200, "SELECT * FROM Contas WHERE Email='%s'", pPlayerInfo[playerid][pEmail]);
        mysql_query(IDConexao, query);

        if(cache_num_rows())
            return SendClientMessage(playerid, Erro, "E-mail já em uso, tente outro");

        new coding[10];

        format(coding, 10, CreateRandomCode());

        mysql_format(IDConexao, query, 400, "INSERT INTO `Contas` (`Nome`, `Senha`, `Email`, `Code`) VALUES ('%s', MD5('%s'), '%s', '%s')", pPlayerInfo[playerid][pNome], pPlayerInfo[playerid][pSenha], pPlayerInfo[playerid][pEmail], coding);
        mysql_tquery(IDConexao, query, "RegisterAccounts", "d", playerid);
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
