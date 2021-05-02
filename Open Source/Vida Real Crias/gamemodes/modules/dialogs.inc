/**************************************************************
*
*   DATE: 05/09/2020
*
*   Note: Created for free "Dialogs".
*
*
*/

#include YSI\y_hooks

new ytbAdsList[MAX_PLAYERS];

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case help:
        {
            if(!response) return 0;

            switch(listitem)
            {
                case 0:
                {
                    new txt[500];
                	strcat(txt, "{A4A4A4}A cada 10 minutos jogado Voc� ganhar� 1 ponto de experi�ncia \n");
                    strcat(txt, "{A4A4A4}Juntando 6 pontos de experi�ncia Voc� ganhar� +1 level \n\n");
                    strcat(txt, "{A4A4A4}Jogadores(as) VIPs ter� que juntar 4 experi�ncia para ganhar +1 level \n\n");
                    strcat(txt, "{A4A4A4}�{66cdaa} /MeuLevel {FFFFFF}- Para ver seu level \n");
                    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Ajuda Level", txt, "Fechar", #);
                }
                case 1:
                {
                    new txt[500];
                	strcat(txt, "{A4A4A4}O Sal�rio � creditado em sua conta banc�ria ao completar UP ( 6/6 ) \n\n");
                    strcat(txt, "{A4A4A4}Jogadores(as) VIPs ter� sal�rio creditado ao completar UP ( 4/4 ) \n\n");
                    strcat(txt, "{A4A4A4}Cada profiss�o tem um sal�rio diferente e justo \n\n");
                    strcat(txt, "{A4A4A4}Cargos da mafia n�o recebem sal�rio \n");
                    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Ajuda Sal�rio", txt, "Fechar", #);
                }
                case 2:
                {
                    new txt[2000];
                	strcat(txt, "{00FFFF}�{FFFFFF} /Regras {FFFFFF}- Para ver as regras do servidor\n");
                    strcat(txt, "{00FFFF}�{FFFFFF} /CoresID {FFFFFF}- Para ver os ID das cores\n");
                	strcat(txt, "{00FFFF}�{FFFFFF} /Creditos {FFFFFF}- Para ver os cr�ditos do servidor\n");
                	strcat(txt, "{00FFFF}�{FFFFFF} /Admins {FFFFFF}- Para ver os Admins online no momento\n");
                	strcat(txt, "{00FFFF}�{FFFFFF} /MinhasHoras {FFFFFF}- Para ver suas horas jogadas\n");
                	strcat(txt, "{00FFFF}�{FFFFFF} /VantagensVip {FFFFFF}- Para saber as vantagens V.I.P\n");
                	strcat(txt, "{00FFFF}�{FFFFFF} /Sairafk {FFFFFF}- Para sair do modo AFK\n");
                	strcat(txt, "{00FFFF}�{FFFFFF} /Profissao {FFFFFF}- Para ver os comandos da profiss�o\n");
                	strcat(txt, "{00FFFF}�{FFFFFF} /Abastecer {FFFFFF}- Para abastecer um ve�culo em um determinado posto\n");
                	strcat(txt, "{00FFFF}�{FFFFFF} /Animes {FFFFFF}- Para ver a lista de animes dispon�vel\n");
                	strcat(txt, "{00FFFF}�{FFFFFF} /Duvida [Duvida]{FFFFFF}- Para tirar alguma d�vida com algum membro da Administra��o\n");
                	strcat(txt, "{00FFFF}�{FFFFFF} /Relatorio [Playerid][Denucia]{FFFFFF}- Para denunciar algum jogador fora das regras ou usando hack\n");
                	strcat(txt, "{00FFFF}�{FFFFFF} /Transferir {FFFFFF}- Para transferir uma determinada quantia a um determinado(a) jogador(a)\n");
                	strcat(txt, "{00FFFF}�{FFFFFF} /Identidade {FFFFFF}- Para ver sua identidade\n");
                	strcat(txt, "{00FFFF}�{FFFFFF} /TopHoras {FFFFFF}- Para ver os TOP horas jogadas\n");
                	strcat(txt, "{00FFFF}�{FFFFFF} /Taxi [Local]{FFFFFF}- Chamar um Taxi\n");
                    strcat(txt, "{00FFFF}�{FFFFFF} /Radios {FFFFFF}- Para ligar a R�dio\n");
                    strcat(txt, "{00FFFF}�{FFFFFF} /Hud {FFFFFF}- Personalize seu HUD do seu jeito\n");
                    strcat(txt, "{00FFFF}�{FFFFFF} /192 {FFFFFF}- Para chamar os param�dicos\n");
                    strcat(txt, "{00FFFF}�{FFFFFF} /Anuncios {FFFFFF}- Para anunciar algo Casas/Empresas\n");
                    strcat(txt, "{00FFFF}�{FFFFFF} /MudarNome {FFFFFF}- Para mudar de nome\n");
                    strcat(txt, "{00FFFF}�{FFFFFF} /MudarSenha {FFFFFF}- Para mudar de senha\n");
                    strcat(txt, "{00FFFF}�{FFFFFF} /Celular {FFFFFF}- Para acessar as fun��es informa��es\n");
                    strcat(txt, "{00FFFF}�{FFFFFF} /Sim ou /N�o {FFFFFF}- Para votar em uma enquete\n");
                	ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Ajuda Comandos", txt, "Fechar", #);
                }
                case 3:
                {
                    new txt[500];

                    format(String, 150, "{00FFFF}�{FFFFFF} F�rum: %s \n", SERVER_FORUM);
                    strcat(txt, String);
                    format(String, 150, "{00FFFF}�{FFFFFF} Facebook: %s \n", SERVER_FACEBOOK);
                    strcat(txt, String);
                    format(String, 150, "{00FFFF}�{FFFFFF} Instagram: %s \n", SERVER_INSTAGRAM);
                    strcat(txt, String);
                    format(String, 150, "{00FFFF}�{FFFFFF} Discord: %s \n", SERVER_DISCORD);
                    strcat(txt, String);
                    format(String, 150, "{00FFFF}�{FFFFFF} IP� : %s \n", SERVER_IP1);
                    strcat(txt, String);
                    format(String, 150, "{00FFFF}�{FFFFFF} IP� : %s \n", SERVER_IP2);
                    strcat(txt, String);

                    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Contatos", txt, "Fechar", #);
                }
                case 4:
                {
                    new txt[500];
                    strcat(txt, "{00FFFF}�{FFFFFF} /ComprarCasa {FFFFFF}- Para comprar uma Casa\n");
                    strcat(txt, "{00FFFF}�{FFFFFF} /MenuCasa {FFFFFF}- Informa��es de sua Casa\n");
                    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Casa", txt, "Fechar", #);
                }
                case 5:
                {
                    new txt[500];
                    strcat(txt, "{00FFFF}�{FFFFFF} /ComprarEmpresa {FFFFFF}- Para comprar uma Empresa\n");
                    strcat(txt, "{00FFFF}�{FFFFFF} /MenuEmpresa {FFFFFF}- Informa��es de sua Empresa\n");
                    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Empresa", txt, "Fechar", #);
                }
                case 6:
                {
                    new txt[500];
                    strcat(txt, "{00FFFF}�{FFFFFF} /ComprarBase {FFFFFF}- Para comprar uma Base\n");
                    strcat(txt, "{00FFFF}�{FFFFFF} /MenuBase {FFFFFF}- Informa��es/Fun��es de sua Base\n");
                    strcat(txt, "{00FFFF}�{FFFFFF} Precione \"F\" {FFFFFF}- Para pegar armas Base\n");
                    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Base", txt, "Fechar", #);
                }
                case 7:
                {
                    new txt[500];
                    strcat(txt, "{00FFFF}� {FFFFFF}Concession�ria - Est� localizada no /gps para compra de ve�culos \n");
                    strcat(txt, "{00FFFF}� {FFFFFF}/MenuVeiculos - Para ver os v�iculo que voc� possui\n");
                    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Ve�culos", txt, "Fechar", #);
                }
                case 8:
                {
                    new txt[100];
                    strcat(txt, "{00FFFF}� {FFFFFF}/PegarMercadoria - Para pegar mercadoria para empresa \n");
                    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Mercadoria", txt, "Fechar", #);
                }
            }
            return 1;
        }
        case tuning:
        {
            if(!response) return 0;

            switch(listitem)
            {
                case 0: ShowPlayerDialog(playerid, paintjob, DIALOG_STYLE_LIST, "{FF0000}Paint Jobs", "{FFFFFF}PaintJob 1 \nPaintJob 2\nPaintJob 3 \nRemover PaintJob","Concluir","Voltar");
                case 1: ShowPlayerDialog(playerid, nitro, DIALOG_STYLE_LIST, "{FF0000}Nitros", "{FFFFFF}Nitro 2\nNitro 5 \nNitro 10 \nRemover Nitro","Concluir","Voltar");
                case 2: ShowPlayerDialog(playerid, wheel, DIALOG_STYLE_LIST, "{FF0000}Rodas", "{FFFFFF}Shadow \nMega \nRimshine \nWires \nClassic \nTwist \nCutter \nSwitch \nGrove \nDollar \nTrance \nAtomic \nRemover Rodas","Concluir","Voltar");
                case 3: ShowPlayerDialog(playerid, hydraulic, DIALOG_STYLE_LIST, "{FF0000}Hidraulica", "{FFFFFF}Hidraulica \nRemover Hidraulica","Concluir","Voltar");
            }
            return 1;
        }
        case nitro:
        {
            if(!response) return ShowPlayerDialog(playerid, tuning,DIALOG_STYLE_LIST,"{FF0000}Tunar","{FFFFFF}PaintJobs \nNitros \nRodas \nHidraulica","Concluir","Fechar");

            switch(listitem)
            {
                case 0: AddVehicleComponent(GetPlayerVehicleID(playerid), 1009); // Nitro 1
                case 1: AddVehicleComponent(GetPlayerVehicleID(playerid), 1008); // Nitro 2
                case 2: AddVehicleComponent(GetPlayerVehicleID(playerid), 1010); // Nitro 3
                case 3: RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1009), // Nitro 1
                        RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1008), // Nitro 2
                        RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1010); // Nitro 3
            }
            return 1;
        }
        case paintjob:
        {
            if(!response) return ShowPlayerDialog(playerid, tuning,DIALOG_STYLE_LIST,"{FF0000}Tunar","{FFFFFF}PaintJobs \nNitros \nRodas \nHidraulica","Concluir","Fechar");

            switch(listitem)
            {
                case 0: ChangeVehiclePaintjob(GetPlayerVehicleID(playerid), 0);
                case 1: ChangeVehiclePaintjob(GetPlayerVehicleID(playerid), 1);
                case 2: ChangeVehiclePaintjob(GetPlayerVehicleID(playerid), 2);
                case 3: ChangeVehiclePaintjob(GetPlayerVehicleID(playerid), 3);
   		 	}
            return 1;
        }
        case wheel:
        {
            if(!response) return ShowPlayerDialog(playerid, tuning, DIALOG_STYLE_LIST,"{FF0000}Tunar","{FFFFFF}PaintJobs \nNitros \nRodas \nHidraulica","Concluir","Fechar");

            switch(listitem)
            {
                case 0: AddVehicleComponent(GetPlayerVehicleID(playerid), 1073); // Shadow
                case 1: AddVehicleComponent(GetPlayerVehicleID(playerid), 1074); // Mega
                case 2: AddVehicleComponent(GetPlayerVehicleID(playerid), 1075); // Rimshine
                case 3: AddVehicleComponent(GetPlayerVehicleID(playerid), 1076); // Wires
                case 4: AddVehicleComponent(GetPlayerVehicleID(playerid), 1077);  // Classic
                case 5: AddVehicleComponent(GetPlayerVehicleID(playerid), 1078); //  Twist
                case 6: AddVehicleComponent(GetPlayerVehicleID(playerid), 1079); //  Cutter
                case 7: AddVehicleComponent(GetPlayerVehicleID(playerid), 1080); //  Switch
                case 8: AddVehicleComponent(GetPlayerVehicleID(playerid), 1081); //  Grove
                case 9: AddVehicleComponent(GetPlayerVehicleID(playerid), 1082); //  Import
                case 10: AddVehicleComponent(GetPlayerVehicleID(playerid), 1083); //  Dollar
                case 11: AddVehicleComponent(GetPlayerVehicleID(playerid), 1084); // Trance
                case 12: AddVehicleComponent(GetPlayerVehicleID(playerid), 1085); // Atomic
                case 13: RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1073),
                        RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1074),
                        RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1075),
                        RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1076),
                        RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1077),
                        RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1078),
                        RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1079),
                        RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1080),
                        RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1081),
                        RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1082),
                        RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1083),
                        RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1084),
                        RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1085);
            }
            return 1;
        }
        case hydraulic:
        {
            if(!response) return ShowPlayerDialog(playerid, tuning,DIALOG_STYLE_LIST,"{FF0000}Tunar","{FFFFFF}PaintJobs \nNitros \nRodas \nHidraulica","Concluir","Fechar");

            switch(listitem)
            {
                case 0: AddVehicleComponent(GetPlayerVehicleID(playerid), 1087); // Hidraulica
                case 1: RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1087); // Hidraulica
			}
            return 1;
        }
        case rename:
        {
            if(!response) return SendClientMessage(playerid, Erro, "Voc� cancelou a troca de nome");

            if(strlen(inputtext) < MIN_PLAYER_NAME || strlen(inputtext) > MAX_PLAYER_NAME)
                return ShowPlayerDialog(playerid, rename, DIALOG_STYLE_INPUT, "{FF0000}Mudar nome", "{FFFFFF}Digite seu novo nome e clique em {FF0000}Mudar\n{FFFFFF}Por favor n�o coloque {FF0000}ESPA�O {FFFFFF}em seu nome:\n{FF0000}Erro digite um nome entre 3 a 30 caracteres!", "Mudar", "Sair");

            mysql_format(IDConexao, String, sizeof(String), "SELECT `Nome` FROM Contas WHERE `Nome`='%s'", inputtext);
            mysql_query(IDConexao, String);

            if(cache_num_rows() > 0)
                return ShowPlayerDialog(playerid, rename, DIALOG_STYLE_INPUT, "{FF0000}Mudar nome", "{FF0000}O nome que voc� escolheu j� existe\n\n {FFFFFF}Tente outro nome abaixo e clique em {FF0000}Mudar", "Mudar", "Sair");

            format(String, sizeof(String), "O(A) jogador(a) %s mudou o nome para ( %s )", PlayerInfo[playerid][Nome], inputtext);
            SendClientMessageToAll(Yellow, String);

            PlayerInfo[playerid][Reais] -= 7;

            mysql_format(IDConexao, String, sizeof(String), "UPDATE `Contas` SET `Nome`='%e' WHERE `ID`='%d'", inputtext, PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, String);

            mysql_format(IDConexao, String, sizeof(String), "UPDATE `Identidade` SET `reais`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][Reais], PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, String);

            mysql_format(IDConexao, String, sizeof(String), "SELECT `ID` FROM `Houses` WHERE `Nome`='%e'", PlayerInfo[playerid][Nome]);
            mysql_query(IDConexao, String);

            if(cache_num_rows())
            {
                new idhouse[MAX_PLAYERS];

                cache_get_value_int(0, "ID", idhouse[playerid]);
                format(HouseInfo[idhouse[playerid]][hNome], MAX_PLAYER_NAME, inputtext);
                UpdateHouseExternal(idhouse[playerid]);

                mysql_format(IDConexao, String, sizeof(String), "UPDATE `Houses` SET `Nome`='%e' WHERE `Nome`='%e'", inputtext, PlayerInfo[playerid][Nome]);
                mysql_query(IDConexao, String);
            }

            mysql_format(IDConexao, String, sizeof(String), "SELECT `ID` FROM `Business` WHERE `Nome`='%e'", PlayerInfo[playerid][Nome]);
            mysql_query(IDConexao, String);

            if(cache_num_rows())
            {
                new businessid[MAX_PLAYERS];

                cache_get_value_int(0, "ID", businessid[playerid]);
                format(BusinessInfo[businessid[playerid]][cName], MAX_PLAYER_NAME, inputtext);
                UpdateCompanyExternal(businessid[playerid]);

                mysql_format(IDConexao, String, sizeof(String), "UPDATE `Business` SET `Nome`='%e' WHERE `Nome`='%e'", inputtext, PlayerInfo[playerid][Nome]);
                mysql_query(IDConexao, String);
            }

            format(PlayerInfo[playerid][Nome], MAX_PLAYER_NAME, inputtext);
            SetPlayerName(playerid, PlayerInfo[playerid][Nome]);
            return 1;
        }
        case radio:
        {
            if(!response) return 0;

            StopAudioStreamForPlayer(playerid);

            switch(listitem)
            {
                case 0: PlayAudioStreamForPlayer(playerid, "http://vidarealcrias.com/songs/electronic.mp3");
                //case 1: PlayAudioStreamForPlayer(playerid, "http://vidarealcrias.com/songs/lining.mp3");
                //case 2: PlayAudioStreamForPlayer(playerid, "http://vidarealcrias.com/songs/funk.mp3");
                //case 3: PlayAudioStreamForPlayer(playerid, "http://vidarealcrias.com/songs/rap.mp3");
                case 4: StopAudioStreamForPlayer(playerid);
            }
            return 1;
        }
        case colorname:
        {
            if(!response) return 0;

            if(strlen(inputtext) != 6)
                return ShowPlayerDialog(playerid, colorname, DIALOG_STYLE_INPUT, "{FF0000}Cor nome", "{FFFFFF}Digite um codigo em '{FF0000}HTML{FFFFFF}' abaixo\nPesquise no Google algo como {00FF00}Cores em HTML {FFFFFF}:\n{FF0000}Exemplo {FFFFFF}00FF00 = {00FF00}Calenzo\n{FF0000}Erro digite uma cor 'HTML' com 6 digitos!", "Alterar", "Cancelar");

            format(String, sizeof(String), "0x%sAA", inputtext);
            SetPlayerColor(playerid, HexToInt(String));
            format(String, sizeof(String), "| VRC-Admin | A cor do seu nome {%s}%s{FFFFFF} foi alterado com sucesso!", inputtext, PlayerInfo[playerid][Nome]);
            SendClientMessage(playerid, White, String);
            return 1;
        }
        case vip_area:
        {
            if(!response) return 0;

            switch(listitem)
            {
                case 0: GivePlayerWeapon(playerid, 9, 1);
                case 1: GivePlayerWeapon(playerid, 27, 499);
                case 2: GivePlayerWeapon(playerid, 26, 499);
                case 3: GivePlayerWeapon(playerid, 28, 499);
                case 4: GivePlayerWeapon(playerid, 29, 499);
                case 5: GivePlayerWeapon(playerid, 32, 499);
                case 6: GivePlayerWeapon(playerid, 31, 499);
                case 7: GivePlayerWeapon(playerid, 30, 499);
                case 8: GivePlayerWeapon(playerid, 33, 499);
                case 9: GivePlayerWeapon(playerid, 34, 499);
            }
            return 1;
        }
        case main_reais:
        {
            if(!response) return 0;

            switch(listitem)
            {
                case 0:
                {
                    new txt[200];

                    strcat(txt, (!IsPlayerMobile(playerid) ? ("{FFFFFF}Dia(s)\t {FF0000}Real(is)\n") : (#)));
                    strcat(txt, "{FFFFFF}1 Dia \t\t{31B404}R$1,00\n");
                    strcat(txt, "{FFFFFF}15 Dias \t\t{31B404}R$10,00\n");
                    strcat(txt, "{FFFFFF}30 Dias \t\t{31B404}R$20,00\n");
                    strcat(txt, "{FFFFFF}60 Dias \t\t{31B404}R$35,00\n");

                    ShowPlayerDialog(playerid, main_reais_vip, (!IsPlayerMobile(playerid) ? DIALOG_STYLE_TABLIST_HEADERS : DIALOG_STYLE_LIST), "{FF0000}Comprar VIP", txt, "Comprar", "Voltar");
                    return 1;
                }
            }
            return 1;
        }
        case main_reais_vip:
        {
            if(!response)
                return ShowPlayerDialog(playerid, main_reais, DIALOG_STYLE_LIST, "{FF0000}Reais", "{FFFFFF}Comprar VIP", "Continuar", "Cancelar");

            if(IsPlayerIntern(playerid))
                return SendClientMessage(playerid, Erro, "Voc� � membro da administra��o e n�o pode ter VIP");

            switch(listitem)
            {
                case 0:
                {
                    if(PlayerInfo[playerid][Reais] < 1)
                        return SendClientMessage(playerid, Erro, "Infelizmente voc� n�o tem Reais o suficiente");

                    PlayerInfo[playerid][Reais] -= 1;
                    UpdatePlayerReais(playerid);

                    OnPlayerGiveVIP(playerid, 1, 1);
                }
                case 1:
                {
                    if(PlayerInfo[playerid][Reais] < 10)
                    return SendClientMessage(playerid, Erro, "Infelizmente voc� n�o tem Reais o suficiente");

                    PlayerInfo[playerid][Reais] -= 10;
                    UpdatePlayerReais(playerid);

                    OnPlayerGiveVIP(playerid, 15, 10);
                }
                case 2:
                {
                    if(PlayerInfo[playerid][Reais] < 20)
                        return SendClientMessage(playerid, Erro, "Infelizmente voc� n�o tem Reais o suficiente");

                    PlayerInfo[playerid][Reais] -= 20;
                    UpdatePlayerReais(playerid);

                    OnPlayerGiveVIP(playerid, 30, 20);
                }
                case 3:
                {
                    if(PlayerInfo[playerid][Reais] < 35)
                        return SendClientMessage(playerid, Erro, "Infelizmente voc� n�o tem Reais o suficiente");

                    PlayerInfo[playerid][Reais] -= 35;
                    UpdatePlayerReais(playerid);

                    OnPlayerGiveVIP(playerid, 60, 35);
                }
            }
            return 1;
        }
        case study:
        {
            if(!response || listitem != 0) return 0;

            new txt[200];

            strcat(txt, "{FFFFFF}1� - Evite bater com o ve�culo; \n");
            strcat(txt, "{FFFFFF}2� - Evite demorar para realizar � prova; \n\n");

            ShowPlayerDialog(playerid, 0, DIALOG_STYLE_LIST, "{FF0000}Auto Escola", txt, "Estudar", "Cancelar");
            return 1;
        }
        case buy_cannabis:
        {
            if(!response) return 0;

            if(!strval(inputtext))
                return ShowPlayerDialog(playerid, buy_cannabis, DIALOG_STYLE_INPUT, "{FF0000}Comprar Cannabis", "{FFFFFF}Digite abaixo a quantidade de muda de Cannabis que vai comprar\n\n{FF0000}Obs: Min�mo 10 m�ximo 50", "Comprar", "Cancelar");

            if(strval(inputtext) < 10 || strval(inputtext) > 50)
                return ShowPlayerDialog(playerid, buy_cannabis, DIALOG_STYLE_INPUT, "{FF0000}Comprar Cannabis", "{FFFFFF}Digite abaixo a quantidade de muda de Cannabis que vai comprar\n\n{FF0000}Obs: Min�mo 10 m�ximo 50", "Comprar", "Cancelar");

            if(PlayerInfo[playerid][cannabis] >= 50)
                return SendClientMessage(playerid, Erro, "Voc� j� tem o m�ximo de mudas de Cannabis");

            if((PlayerInfo[playerid][cannabis] + strval(inputtext)) > 50)
            {
                new value[MAX_PLAYERS];

                value[playerid] = (50 - PlayerInfo[playerid][cannabis]);

                if(PlayerInfo[playerid][Dinheiro] < (value[playerid] * 55))
                    return SendClientMessage(playerid, Erro, "Voc� n�o tem dinheiro o suficiente");

                PlayerInfo[playerid][cannabis] += value[playerid];

                PlayerInfo[playerid][Dinheiro] -= (value[playerid] * 55);

                format(String, MAX_STRING, "Foram compradas %d mudas de Cannabis por $%s", value[playerid], IsMoney((value[playerid] * 55), "."));
            }
            else
            {
                if(PlayerInfo[playerid][Dinheiro] < (strval(inputtext) * 55))
                    return SendClientMessage(playerid, Erro, "Voc� n�o tem dinheiro o suficiente");

                PlayerInfo[playerid][cannabis] += strval(inputtext);

                PlayerInfo[playerid][Dinheiro] -= (strval(inputtext) * 55);

                format(String, MAX_STRING, "Foram compradas %d mudas de Cannabis por $%s", strval(inputtext), IsMoney((strval(inputtext) * 55), "."));
            }

            SetIntQuery(playerid, "Itens", "cannabis", PlayerInfo[playerid][cannabis]);
            UpdatePlayerMoney(playerid);
            SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);
            return 1;
        }
        case buy_weaponpiece:
        {
            if(!response) return 0;

            if(!strval(inputtext))
                return ShowPlayerDialog(playerid, buy_weaponpiece, DIALOG_STYLE_INPUT, "{FF0000}Comprar Pe�a de Arma", "{FFFFFF}Digite abaixo a quantidade de pe�a de arma que vai comprar\n\n{FF0000}Obs: Min�mo 10 m�ximo 50", "Comprar", "Cancelar");

            if(strval(inputtext) < MIN_WP || strval(inputtext) > MAX_WP)
                return ShowPlayerDialog(playerid, buy_weaponpiece, DIALOG_STYLE_INPUT, "{FF0000}Comprar Pe�a de Arma", "{FFFFFF}Digite abaixo a quantidade de pe�a de arma que vai comprar\n\n{FF0000}Obs: Min�mo 10 m�ximo 50", "Comprar", "Cancelar");

            new weaponPiece = GetIntQuery(playerid, "Itens", "weaponpiece");

            if(weaponPiece >= MAX_WP)
                return SendClientMessage(playerid, Erro, "Voc� j� tem o m�ximo de pe�as");

            if((weaponPiece + strval(inputtext)) > MAX_WP)
            {
                new value[MAX_PLAYERS];

                value[playerid] = (MAX_WP - weaponPiece);

                if(PlayerInfo[playerid][Dinheiro] < (value[playerid] * WP_PRICE))
                    return SendClientMessage(playerid, Erro, "Voc� n�o tem dinheiro o suficiente");

                weaponPiece += value[playerid];

                SetIntQuery(playerid, "Itens", "weaponpiece", weaponPiece);

                PlayerInfo[playerid][Dinheiro] -= (value[playerid] * WP_PRICE);

                format(String, MAX_STRING, "Voc� comprou %d pe�as de arma por $%s", value[playerid], IsMoney((value[playerid] * WP_PRICE), "."));
            }
            else
            {
                if(PlayerInfo[playerid][Dinheiro] < (strval(inputtext) * WP_PRICE))
                    return SendClientMessage(playerid, Erro, "Voc� n�o tem dinheiro o suficiente");

                weaponPiece += strval(inputtext);
                SetIntQuery(playerid, "Itens", "weaponpiece", weaponPiece);

                PlayerInfo[playerid][Dinheiro] -= (strval(inputtext) * WP_PRICE);

                format(String, MAX_STRING, "Voc� comprou %d pe�as de arma por $%s", strval(inputtext), IsMoney((strval(inputtext) * WP_PRICE), "."));
            }

            UpdatePlayerMoney(playerid);
            SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);
            return 1;
        }
        case hud:
        {
            if(!response) return 0;

            switch(listitem)
            {
                case 0:
                {
                    if(statePlayer[playerid])
                        HideTDStatus(playerid);
                    else
                        ShowTDStatus(playerid);

                    return 1;
                }
                case 1:
                {
                    if(!IsPlayerInAnyVehicle(playerid))
                        return SendClientMessage(playerid, Erro, "Voc� n�o est� em um ve�culo");

                    if(stateVehicle[playerid])
                        HidePlayerVelocimetro(playerid);
                    else
                        ShowPlayerVelocimetro(playerid);

                    return 1;
                }
                case 2:
                {
                    if(stateTime[playerid])
                        HideTDTime(playerid);
                    else
                        ShowTDTime(playerid);

                    return 1;
                }
            }
            return 1;
        }
        case alter_pass:
        {
            if(!response)
                return SendClientMessage(playerid, Erro, "Altera��o de senha cancelada");

            if(!strlen(inputtext))
                return ShowPlayerDialog(playerid, alter_pass, DIALOG_STYLE_PASSWORD, "{FF0000}Alterar Senha", "{FFFFFF}Digite abaixo sua nova senha:\n\n{FF4000}Digite sua nova senha", "Alterar", "Cancelar");

            if(strlen(inputtext) < MIN_PLAYER_PASS || strlen(inputtext) > MAX_PLAYER_PASS)
                return ShowPlayerDialog(playerid, alter_pass, DIALOG_STYLE_PASSWORD, "{FF0000}Alterar Senha", "{FFFFFF}Digite abaixo sua nova senha:\n\n{FF4000}Digite de 6 � 30 caracteres", "Alterar", "Cancelar");

            new query[300];
            mysql_format(IDConexao, query, 300, "SELECT `Senha` FROM `Contas` WHERE `Senha`=MD5('%e') AND `ID`='%d'", inputtext, PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, query);

            if(cache_num_rows())
                return ShowPlayerDialog(playerid, alter_pass, DIALOG_STYLE_PASSWORD, "{FF0000}Alterar Senha", "{FFFFFF}Digite abaixo sua nova senha:\n\n{FF4000}Digite uma senha diferente da atual", "Alterar", "Cancelar");

            mysql_format(IDConexao, query, 300, "UPDATE `Contas` SET `Senha`=MD5('%e') WHERE `ID`='%d'", inputtext, PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, query);

            format(PlayerInfo[playerid][Senha], MAX_PLAYER_PASS, inputtext);

            SendClientMessage(playerid, Green, "Senha alterada");
            return 1;
        }
        case alter_email:
        {
            if(!response)
                return SendClientMessage(playerid, Erro, "Altera��o de email cancelada");

            if(!strlen(inputtext))
                return ShowPlayerDialog(playerid, alter_email, DIALOG_STYLE_INPUT, "{FF0000}Alterar Email", "{FFFFFF}Digite abaixo seu novo email:\n\n{FF4000}Digite seu novo email", "Alterar", "Cancelar");

            if(strlen(inputtext) < MIN_PLAYER_EMAIL || strlen(inputtext) > MAX_PLAYER_EMAIL)
                return ShowPlayerDialog(playerid, alter_email, DIALOG_STYLE_INPUT, "{FF0000}Alterar Email", "{FFFFFF}Digite abaixo seu novo email:\n\n{FF4000}Digite de 10 � 50 caracteres", "Alterar", "Cancelar");

            new query[300];
            mysql_format(IDConexao, query, 300, "SELECT `Email` FROM `Contas` WHERE `Email`='%e' AND `ID`='%d'", inputtext, PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, query);

            if(cache_num_rows())
                return ShowPlayerDialog(playerid, alter_email, DIALOG_STYLE_INPUT, "{FF0000}Alterar Email", "{FFFFFF}Digite abaixo seu novo email:\n\n{FF4000}Digite uma senha diferente da atual", "Alterar", "Cancelar");

            mysql_format(IDConexao, query, 300, "UPDATE `Contas` SET `Email`='%e' WHERE `ID`='%d'", inputtext, PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, query);

            format(PlayerInfo[playerid][Email], MAX_PLAYER_EMAIL, inputtext);

            SendClientMessage(playerid, Green, "Email alterado");
            return 1;
        }
        case hospital:
        {
            if(!response) return 0;

            switch(listitem)
            {
                case 0:
                {
                    if(PlayerInfo[playerid][Dinheiro] < 900)
                        return SendClientMessage(playerid, Erro, "Voc� n�o tem dinheiro suficiente");

                    if(PlayerInfo[playerid][medicalkit] != 0)
                        return SendClientMessage(playerid, Erro, "Voc� ainda tem Kit M�dicos");

                    PlayerInfo[playerid][Dinheiro] -= 900;
                    UpdatePlayerMoney(playerid);

                    PlayerInfo[playerid][medicalkit] = 3;
                    SetIntQuery(playerid, "Itens", "kitmedicos", 3);

                    SendClientMessage(playerid, White, "Voc� comprou 3 kit m�dicos, para usar digite ~~> /UsarKit");
                    return 1;
                }
                case 1:
                {
                    if(!PlayerInfo[playerid][disease])
                        return SendClientMessage(playerid, Erro, "Voc� n�o est� doente");

                    if(PlayerInfo[playerid][Dinheiro] < 5000)
                        return SendClientMessage(playerid, Erro, "Voc� n�o tem dinheiro suficiente");

                    Progress[playerid][Vida] = 0.0;

                    PlayerInfo[playerid][vaccine] = (gettime() + 18000);
                    PlayerInfo[playerid][disease] = 0;

                    PlayerInfo[playerid][Health] = 100.0;
                    SetPlayerHealth(playerid, PlayerInfo[playerid][Health]);

                    PlayerInfo[playerid][Dinheiro] -= 5000;
                    UpdatePlayerMoney(playerid);
                    UpdatePlayerDisease(playerid);
                    UpdateProgressBar(playerid);

                    SendClientMessage(playerid, White, "Agora voc� n�o est� mais doente e tomou refor�o de 5 vacinas");
                    return 1;
                }
                case 2: ShowPlayerDialog(playerid, hospital_sex, DIALOG_STYLE_MSGBOX, "{FF0000}Trocar de Sexo", "{FFFFFF}Tem certeza que deseja trocar de sexo?\n\nObs: voc� perder� {FF4000}$50.000", "Sim", "N�o");
                case 3:
                {
                    if(PlayerInfo[playerid][Dinheiro] < 150)
                        return SendClientMessage(playerid, Erro, "Voc� n�o tem dinheiro suficiente");

                    if(PlayerInfo[playerid][healthplan])
                        return SendClientMessage(playerid, Erro, "Voc� j� tem um plano de sa�de");

                    PlayerInfo[playerid][Dinheiro] -= 150;
                    UpdatePlayerMoney(playerid);

                    PlayerInfo[playerid][healthplan] = true;
                    SetIntQuery(playerid, "Itens", "planosaude", 1);

                    SendClientMessage(playerid, White, "Voc� acabe de adquirir um plano de sa�de");
                    SendClientMessage(playerid, White, "N�o se preocupe, ser� descontado automaticamente do seu s�lario");
                    return 1;
                }
                case 4:
                {
                    if(PlayerInfo[playerid][Profissao] != paramedic)
                        return 0;

                    if(!PlayerInfo[playerid][pointsDoctor])
                        return SendClientMessage(playerid, Erro, "Voc� n�o tem pontos, v� salvar vidas");

                    PlayerInfo[playerid][SaldoBancario] += (PlayerInfo[playerid][pointsDoctor] * 250);
                    SetIntQuery(playerid, "Identidade", "saldobancario", PlayerInfo[playerid][SaldoBancario]);

                    SendClientMessage(playerid, White, "Seu pagamento foi transferido direto para sua conta bancaria");
                    return 1;
                }
            }
            return 1;
        }
        case hospital_sex:
        {
            if(!response) return 0;

            if(PlayerInfo[playerid][Dinheiro] < 50000)
                return SendClientMessage(playerid, Erro, "Voc� n�o tem dinheiro suficiente");

            if(PlayerInfo[playerid][sexo] == SEX_BOY)
            {
                PlayerInfo[playerid][sexo] = SEX_GIRL;
                PlayerInfo[playerid][skin] = DEFAULT_SKIN_GIRL;
                SetPlayerSkin(playerid, PlayerInfo[playerid][skin]);
            }
            else
            {
                PlayerInfo[playerid][sexo] = SEX_BOY;
                PlayerInfo[playerid][skin] = DEFAULT_SKIN_BOY;
                SetPlayerSkin(playerid, PlayerInfo[playerid][skin]);
            }

            format(String, MAX_STRING, "Voc� mudou seu sexo para %s", (PlayerInfo[playerid][sexo] == SEX_BOY ? ("Masculino") : ("Feminino")));
            SendClientMessage(playerid, White, String);

            PlayerInfo[playerid][Dinheiro] -= 50000;
            UpdatePlayerMoney(playerid);

            new query[200];
            mysql_format(IDConexao, query, 200, "UPDATE `Identidade` SET `sexo`='%d', `skin`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][sexo], PlayerInfo[playerid][skin], PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, query);
            return 1;
        }
        case player_ads:
        {
            if(!response) return 0;

            switch(listitem)
            {
                case 0:
                {
                    if(!IsPlayerOwnerHouse(playerid))
                        return SendClientMessage(playerid, Erro, "Voc� n�o tem casa para an�nciar");

                    PlayerInfo[playerid][blockAd] = true;
                    SetTimerEx("UnlockingAd", 300000, false, "d", playerid);

                    format(String, MAX_STRING, "VRC-An�ncios ~ %s[%d] est� an�nciando � casa ID %d ~~> /SMS", PlayerInfo[playerid][Nome], playerid, GetPlayerHouseID(playerid));
                    SendClientMessageToAll(Green, String);
                    return 1;
                }
                case 1:
                {
                    if(!IsPlayerOwnerBusiness(playerid))
                        return SendClientMessage(playerid, Erro, "Voc� n�o tem empresa para an�nciar");

                    PlayerInfo[playerid][blockAd] = true;
                    SetTimerEx("UnlockingAd", 300000, false, "d", playerid);

                    format(String, MAX_STRING, "VRC-An�ncios ~ %s[%d] est� an�nciando � empresa ID %d ~~> /SMS", PlayerInfo[playerid][Nome], playerid, GetPlayerBusinessID(playerid));
                    SendClientMessageToAll(Green, String);
                    return 1;
                }
                case 2, 3:
                {
                    if(!IsPlayerYoutuber(playerid)) return 0;

                    ytbAdsList[playerid] = (listitem - 2);

                    return ShowPlayerDialog(playerid, youtuber_ads, DIALOG_STYLE_INPUT, "{FF0000}VRC-An�ncios", "{FFFFFF}Digite abaixo o an�ncio:", "An�nciar", "Cancelar");
                }
            }
            return 1;
        }
        case youtuber_ads:
        {
            if(!IsPlayerYoutuber(playerid) || !response || !strlen(inputtext)) return 0;

            if(!ytbAdsList[playerid]){
                format(String, MAX_STRING, "Youtuber %s diz: %s", PlayerInfo[playerid][Nome], inputtext);
                SendClientMessageToAll(Green, String);
                return 1;
            }

            if(Respawnando)
                return SendClientMessage(playerid, Erro, "Aguarde o fim do respawn de ve�culos n�o em uso");

            format(String, MAX_STRING, "~r~# ~p~%s~w~: %s ~r~#", PlayerInfo[playerid][Nome], inputtext);
            TextDrawSetString(RespawnVeiculos, String);
            TextDrawShowForAll(RespawnVeiculos);
            SetTimer("HideTextRespawn", 3000, false);
            return 1;
        }
        case police_vehicle:
        {
            if(!response || !IsPlayerPolice(playerid) || !IsPlayerInDepartamentPolice(playerid)) return 0;

            if(PV_Profission[playerid]) DestroyPlayerVehicle(playerid);

            new model, dpid, vehicleid, rand;

            switch(listitem)
            {
                case 0: model = 596;
                case 1: model = 598;
                case 2: model = 597;
                case 3: model = 599;
                case 4: model = 601;
                case 5: model = 523;
                case 6: model = 490;
                case 7: model = 528;
                case 8: model = 427;
            }

            rand = random(MAX_VEHICLE_IN_DP);
            dpid = GetPlayerDepartamentPoliceID(playerid);
            vehicleid = CreatePlayerVehicle(playerid, model, dp_vehicles[dpid][rand][dpv_x], dp_vehicles[dpid][rand][dpv_y], dp_vehicles[dpid][rand][dpv_z], dp_vehicles[dpid][rand][dpv_a], -1, -1);

            SetVehicleHealth(vehicleid, 9999.0);

            SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Ve�culo profiss�o criado no estacionamento");
            return 1;
        }
        case cellphone_list:
        {
            if(!response) return 0;

            switch(listitem)
            {
                case 0:
                {
                    new txt[100];
                    strcat(txt, "{FFFFFF}Propriedades\n");
                    strcat(txt, "{FFFFFF}Locais P�blicos\n");
                    strcat(txt, "{FFFFFF}�reas da M�fia\n");
                    ShowPlayerDialog(playerid, DIALOG_GPS, DIALOG_STYLE_LIST, "{FF0000}GPS", txt, "Continuar", "Cancelar");
                    return 1;
                }
                case 1:
                {
                    if(!PlayerInfo[playerid][cellphone])
                        return SendClientMessage(playerid, Erro, "Voc� n�o tem um celular");

                    if(!PlayerInfo[playerid][sms])
                        return SendClientMessage(playerid, Erro, "Voc� n�o tem sms suficiente");

                    ShowPlayerDialog(playerid, cellphone_sms_id, DIALOG_STYLE_INPUT, "{FF0000}SMS", "{FFFFFF}Digite abaixo o ID do jogador(a) que ir� enviar SMS:", "Continuar", "Cancelar");
                    return 1;
                }
                case 2:
                {
                    PlayerInfo[playerid][smsBlock] = (PlayerInfo[playerid][smsBlock] ? false : true);
                    SendClientMessage(playerid, Green, (PlayerInfo[playerid][smsBlock] ? ("Recebimento de SMS Bloqueado") : ("Recebimento de SMS Desbloqueado")));
                    return 1;
                }
            }
            return 1;
        }
        case cellphone_sms_id:
        {
            if(!response)
                return SendClientMessage(playerid, Erro, "Voc� cancelou o envio do SMS");

            if(!IsNumeric(inputtext))
                return ShowPlayerDialog(playerid, cellphone_sms_id, DIALOG_STYLE_INPUT, "{FF0000}SMS", "{FFFFFF}Digite abaixo o ID do jogador(a) que ir� enviar SMS:\n\n{FF4000}Jogador(a) n�o conectado(a)", "Continuar", "Cancelar");

            new id = strval(inputtext);

            if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
                return ShowPlayerDialog(playerid, cellphone_sms_id, DIALOG_STYLE_INPUT, "{FF0000}SMS", "{FFFFFF}Digite abaixo o ID do jogador(a) que ir� enviar SMS:\n\n{FF4000}Jogador(a) n�o conectado(a)", "Continuar", "Cancelar");

            if(playerid == id)
                return ShowPlayerDialog(playerid, cellphone_sms_id, DIALOG_STYLE_INPUT, "{FF0000}SMS", "{FFFFFF}Digite abaixo o ID do jogador(a) que ir� enviar SMS:\n\n{FF4000}Voc� n�o pode enviar para s� mesmo", "Continuar", "Cancelar");

            if(!PlayerInfo[id][cellphone])
                return SendClientMessage(playerid, Erro, "O(A) Jogador(a) n�o tem celular");

            if(PlayerInfo[id][smsBlock])
                return SendClientMessage(playerid, Erro, "O(A) Jogador(a) bloqueou sms");

            PlayerInfo[playerid][smsIdReceive] = id;

            format(String, 255, "{FFFFFF}Digite abaixo a MENSAGEM ir� enviar para %s[%d] :", PlayerInfo[id][Nome], id);
            ShowPlayerDialog(playerid, cellphone_sms_message, DIALOG_STYLE_INPUT, "{FF0000}SMS", String, "Continuar", "Cancelar");
            return 1;
        }
        case cellphone_sms_message:
        {
            if(!response)
                return SendClientMessage(playerid, Erro, "Voc� cancelou o envio do SMS");

            if(PlayerInfo[playerid][smsIdReceive] == INVALID_PLAYER_ID) return 0;

            new id = PlayerInfo[playerid][smsIdReceive];

            format(String, MAX_STRING, "SMS ~ Mensagem enviada para %s[%d] ( %s )", PlayerInfo[id][Nome], id, inputtext);
            SendClientMessage(playerid, 0xC0C0C0AA, String);
            GameTextForPlayer(playerid, "~w~mensagem ~w~enviada!" , 2500, 1);
            PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);

            format(String, MAX_STRING, "SMS ~ Mensagem recebida de %s[%d] ( %s )", PlayerInfo[playerid][Nome], playerid, inputtext);
            SendClientMessage(id, 0x808080AA, String);
            GameTextForPlayer(id, "~w~mensagem ~w~recebida!" , 2500, 1);
            PlayerPlaySound(id, 1085, 0.0, 0.0, 0.0);

            PlayerInfo[playerid][sms]--;
            SetIntQuery(playerid, "Itens", "sms", PlayerInfo[playerid][sms]);
            return 1;
        }
    }
    return 1;
}
