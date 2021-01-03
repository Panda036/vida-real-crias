/**************************************************************
*
*   DATE: 05/09/2020
*
*   Note: Created for free "Dialogs".
*
*
*/

#include YSI\y_hooks

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
                	strcat(txt, "{A4A4A4}A cada 10 minutos jogado Você ganhará 1 ponto de experiência \n");
                    strcat(txt, "{A4A4A4}Juntando 6 pontos de experiência Você ganhará +1 level \n\n");
                    strcat(txt, "{A4A4A4}Jogadores(as) VIPs terá que juntar 4 experiência para ganhar +1 level \n\n");
                    strcat(txt, "{A4A4A4}»{66cdaa} /MeuLevel {FFFFFF}- Para ver seu level \n");
                    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Ajuda Level", txt, "Fechar", #);
                }
                case 1:
                {
                    new txt[500];
                	strcat(txt, "{A4A4A4}O Salário é creditado em sua conta bancária ao completar UP ( 6/6 ) \n\n");
                    strcat(txt, "{A4A4A4}Jogadores(as) VIPs terá salário creditado ao completar UP ( 4/4 ) \n\n");
                    strcat(txt, "{A4A4A4}Cada profissão tem um salário diferente e justo \n\n");
                    strcat(txt, "{A4A4A4}Cargos da mafia não recebem salário \n");
                    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Ajuda Salário", txt, "Fechar", #);
                }
                case 2:
                {
                    new txt[2000];
                	strcat(txt, "{00FFFF}»{FFFFFF} /Regras {FFFFFF}- Para ver as regras do servidor\n");
                	strcat(txt, "{00FFFF}»{FFFFFF} /Creditos {FFFFFF}- Para ver os créditos do servidor\n");
                	strcat(txt, "{00FFFF}»{FFFFFF} /Admins {FFFFFF}- Para ver os Admins online no momento\n");
                	strcat(txt, "{00FFFF}»{FFFFFF} /MeuLevel {FFFFFF}- Para ver seu level atual\n");
                	strcat(txt, "{00FFFF}»{FFFFFF} /VantagensVip {FFFFFF}- Para saber as vantagens V.I.P\n");
                	strcat(txt, "{00FFFF}»{FFFFFF} /Sairafk {FFFFFF}- Para sair do modo AFK\n");
                	strcat(txt, "{00FFFF}»{FFFFFF} /Profissao {FFFFFF}- Para ver os comandos da profissão\n");
                	strcat(txt, "{00FFFF}»{FFFFFF} /Abastecer {FFFFFF}- Para abastecer um veículo em um determinado posto\n");
                	strcat(txt, "{00FFFF}»{FFFFFF} /Animes {FFFFFF}- Para ver a lista de animes disponível\n");
                	strcat(txt, "{00FFFF}»{FFFFFF} /Duvida [Duvida]{FFFFFF}- Para tirar alguma dúvida com algum membro da Administração\n");
                	strcat(txt, "{00FFFF}»{FFFFFF} /Relatorio [Playerid][Denucia]{FFFFFF}- Para denunciar algum jogador fora das regras ou usando hack\n");
                	strcat(txt, "{00FFFF}»{FFFFFF} /Transferir {FFFFFF}- Para transferir uma determinada quantia a um determinado(a) jogador(a)\n");
                	strcat(txt, "{00FFFF}»{FFFFFF} /Identidade {FFFFFF}- Para ver sua identidade\n");
                    strcat(txt, "{00FFFF}»{FFFFFF} /TopLevel {FFFFFF}- Para ver os top 10 leveis\n");
                    strcat(txt, "{00FFFF}»{FFFFFF} /TopDinheiro {FFFFFF}- Para ver os top 10 dinheiro\n");
                    strcat(txt, "{00FFFF}»{FFFFFF} /TopProcurado {FFFFFF}- Para ver os top 10 procurados\n");
                    strcat(txt, "{00FFFF}»{FFFFFF} /TopKill {FFFFFF}- Para ver os top 10 kills\n");
                	strcat(txt, "{00FFFF}»{FFFFFF} /Taxi [Local]{FFFFFF}- Chamar um Taxi\n");
                    strcat(txt, "{00FFFF}»{FFFFFF} /Radio {FFFFFF}- Para ligar a Rádio\n");
                    strcat(txt, "{00FFFF}»{FFFFFF} /Hud {FFFFFF}- Para mostrar/ocultar gráficos\n");
                    strcat(txt, "{00FFFF}»{FFFFFF} /192 {FFFFFF}- Para chamar os paramédicos\n");
                    strcat(txt, "{00FFFF}»{FFFFFF} /Anuncio {FFFFFF}- Para anúnciar algo\n");
                	ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Ajuda Comandos", txt, "Fechar", #);
                }
                case 3:
                {
                    new txt[500];
                    strcat(txt, "{00FFFF}»{FFFFFF} Fórum: https://vidarealcrias.forumeiros.com/ \n");
                    strcat(txt, "{00FFFF}»{FFFFFF} Facebook: https://www.facebook.com/vidarealcrias \n");
                    strcat(txt, "{00FFFF}»{FFFFFF} Instagram: https://www.instagram.com/vidarealcrias \n");
                    strcat(txt, "{00FFFF}»{FFFFFF} Discord: https://discord.gg/8nyDuEv \n");

                    format(String, MAX_STRING, "{00FFFF}»{FFFFFF} IP¹ : %s \n", SERVER_IP1);
                    strcat(txt, String);
                    format(String, MAX_STRING, "{00FFFF}»{FFFFFF} IP² : %s \n", SERVER_IP2);
                    strcat(txt, String);

                    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Contatos", txt, "Fechar", #);
                }
                case 4:
                {
                    new txt[500];
                    strcat(txt, "{00FFFF}»{FFFFFF} /ComprarCasa {FFFFFF}- Para comprar uma Casa\n");
                    strcat(txt, "{00FFFF}»{FFFFFF} /MenuCasa {FFFFFF}- Informações de sua Casa\n");
                    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Casa", txt, "Fechar", #);
                }
                case 5:
                {
                    new txt[500];
                    strcat(txt, "{00FFFF}»{FFFFFF} /ComprarEmpresa {FFFFFF}- Para comprar uma Empresa\n");
                    strcat(txt, "{00FFFF}»{FFFFFF} /MenuEmpresa {FFFFFF}- Informações de sua Empresa\n");
                    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Empresa", txt, "Fechar", #);
                }
                case 6:
                {
                    new txt[500];
                    strcat(txt, "{00FFFF}»{FFFFFF} /ComprarBase {FFFFFF}- Para comprar uma Base\n");
                    strcat(txt, "{00FFFF}»{FFFFFF} /MenuBase {FFFFFF}- Informações/Funções de sua Base\n");
                    strcat(txt, "{00FFFF}»{FFFFFF} Precione \"F\" {FFFFFF}- Para pegar armas Base\n");
                    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Base", txt, "Fechar", #);
                }
                case 7:
                {
                    new txt[500];
                    strcat(txt, "{00FFFF}» {FFFFFF}Concessionária - Está localizada no /gps para compra de veículos \n");
                    strcat(txt, "{00FFFF}» {FFFFFF}/MenuVeiculos - Para ver os véiculo que você possui\n");
                    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Veículos", txt, "Fechar", #);
                }
                case 8:
                {
                    new txt[100];
                    strcat(txt, "{00FFFF}» {FFFFFF}/PegarMercadoria - Para pegar mercadoria para empresa \n");
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
            if(!response) return SendClientMessage(playerid, Erro, "Você cancelou a troca de nome");

            if(strlen(inputtext) < MIN_PLAYER_NAME || strlen(inputtext) > MAX_PLAYER_NAME)
                return ShowPlayerDialog(playerid, rename, DIALOG_STYLE_INPUT, "{FF0000}Mudar nome", "{FFFFFF}Digite seu novo nome e clique em {FF0000}Mudar\n{FFFFFF}Por favor não coloque {FF0000}ESPAÇO {FFFFFF}em seu nome:\n{FF0000}Erro digite um nome entre 3 a 30 caracteres!", "Mudar", "Sair");

            mysql_format(IDConexao, String, sizeof(String), "SELECT `Nome` FROM Contas WHERE `Nome`='%s'", inputtext);
            mysql_query(IDConexao, String);

            if(cache_num_rows() > 0)
                return ShowPlayerDialog(playerid, rename, DIALOG_STYLE_INPUT, "{FF0000}Mudar nome", "{FF0000}O nome que você escolheu já existe\n\n {FFFFFF}Tente outro nome abaixo e clique em {FF0000}Mudar", "Mudar", "Sair");

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
                case 0: PlayAudioStreamForPlayer(playerid, "http://live.hunterfm.com/live");
                case 1: PlayAudioStreamForPlayer(playerid, "http://198.178.123.11:7746");
                case 2: PlayAudioStreamForPlayer(playerid, "http://64.31.27.234:9998");
                case 3: PlayAudioStreamForPlayer(playerid, "http://64.15.174.221:9026");
                case 4: PlayAudioStreamForPlayer(playerid, "http://play.sodafunk.net:8096");
                case 5: PlayAudioStreamForPlayer(playerid, "http://184.154.89.186:9944");
                case 6: PlayAudioStreamForPlayer(playerid, "http://50.7.66.3:9121");
                case 7: StopAudioStreamForPlayer(playerid);
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
            format(String, sizeof(String), "VRC-Admin ~ A cor do seu nome {%s}%s{FFFFFF} foi alterado com sucesso!", inputtext, PlayerInfo[playerid][Nome]);
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
            if(!response || listitem != 0) return 0;

            new txt[200];

            strcat(txt, "{FFFFFF}Dia(s)\t {FF0000}Real(is)\n");
            strcat(txt, "{FFFFFF}1 Dia \t\t{31B404}R$1,00\n");
            strcat(txt, "{FFFFFF}15 Dias \t\t{31B404}R$10,00\n");
            strcat(txt, "{FFFFFF}30 Dias \t\t{31B404}R$20,00\n");
            strcat(txt, "{FFFFFF}60 Dias \t\t{31B404}R$35,00\n");

            ShowPlayerDialog(playerid, main_reais_vip, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Comprar VIP", txt, "Comprar", "Voltar");
            return 1;
        }
        case main_reais_vip:
        {
            if(!response) return ShowPlayerDialog(playerid, main_reais, DIALOG_STYLE_LIST, "{FF0000}Reais", "{FFFFFF}Comprar VIP", "Continuar", "Cancelar");

            if(IsPlayerIntern(playerid))
                return SendClientMessage(playerid, Erro, "Você é membro da administração e não pode ter VIP");

            switch(listitem)
            {
                case 0:
                {
                    if(PlayerInfo[playerid][Reais] < 1)
                        return SendClientMessage(playerid, Erro, "Infelizmente você não tem Reais o suficiente");

                    PlayerInfo[playerid][Reais] -= 1;
                    OnPlayerGiveVIP(playerid, 1, 1);
                }
                case 1:
                {
                    if(PlayerInfo[playerid][Reais] < 10)
                    return SendClientMessage(playerid, Erro, "Infelizmente você não tem Reais o suficiente");

                    PlayerInfo[playerid][Reais] -= 10;
                    OnPlayerGiveVIP(playerid, 15, 10);
                }
                case 2:
                {
                    if(PlayerInfo[playerid][Reais] < 20)
                        return SendClientMessage(playerid, Erro, "Infelizmente você não tem Reais o suficiente");

                    PlayerInfo[playerid][Reais] -= 20;
                    OnPlayerGiveVIP(playerid, 30, 20);
                }
                case 3:
                {
                    if(PlayerInfo[playerid][Reais] < 35)
                        return SendClientMessage(playerid, Erro, "Infelizmente você não tem Reais o suficiente");

                    PlayerInfo[playerid][Reais] -= 35;
                    OnPlayerGiveVIP(playerid, 60, 35);
                }
            }
            UpdatePlayerReais(playerid);
            return 1;
        }
        case study:
        {
            if(!response || listitem != 0) return 0;

            new txt[200];

            strcat(txt, "{FFFFFF}1° - Evite bater com o veículo; \n");
            strcat(txt, "{FFFFFF}2° - Evite demorar para realizar à prova; \n\n");

            ShowPlayerDialog(playerid, 0, DIALOG_STYLE_LIST, "{FF0000}Auto Escola", txt, "Estudar", "Cancelar");
            return 1;
        }
        case buy_cannabis:
        {
            if(!response) return 0;

            if(!strval(inputtext))
                return ShowPlayerDialog(playerid, buy_cannabis, DIALOG_STYLE_INPUT, "{FF0000}Comprar Cannabis", "{FFFFFF}Digite abaixo a quantidade de muda de Cannabis que vai comprar\n\n{FF0000}Obs: Minímo 10 máximo 50", "Comprar", "Cancelar");

            if(strval(inputtext) < 10 || strval(inputtext) > 50)
                return ShowPlayerDialog(playerid, buy_cannabis, DIALOG_STYLE_INPUT, "{FF0000}Comprar Cannabis", "{FFFFFF}Digite abaixo a quantidade de muda de Cannabis que vai comprar\n\n{FF0000}Obs: Minímo 10 máximo 50", "Comprar", "Cancelar");

            if(PlayerInfo[playerid][cannabis] >= 50)
                return SendClientMessage(playerid, Erro, "Você já tem o máximo de mudas de Cannabis");

            if((PlayerInfo[playerid][cannabis] + strval(inputtext)) > 50)
            {
                new value[MAX_PLAYERS];

                value[playerid] = (50 - PlayerInfo[playerid][cannabis]);

                if(PlayerInfo[playerid][Dinheiro] < (value[playerid] * 55))
                    return SendClientMessage(playerid, Erro, "Você não tem dinheiro o suficiente");

                PlayerInfo[playerid][cannabis] += value[playerid];

                PlayerInfo[playerid][Dinheiro] -= (value[playerid] * 55);

                format(String, MAX_STRING, "Foram compradas %d mudas de Cannabis por $%s", value[playerid], IsMoney((value[playerid] * 55), "."));
            }
            else
            {
                if(PlayerInfo[playerid][Dinheiro] < (strval(inputtext) * 55))
                    return SendClientMessage(playerid, Erro, "Você não tem dinheiro o suficiente");

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
                return ShowPlayerDialog(playerid, buy_weaponpiece, DIALOG_STYLE_INPUT, "{FF0000}Comprar Peça de Arma", "{FFFFFF}Digite abaixo a quantidade de peça de arma que vai comprar\n\n{FF0000}Obs: Minímo 10 máximo 50", "Comprar", "Cancelar");

            if(strval(inputtext) < MIN_WP || strval(inputtext) > MAX_WP)
                return ShowPlayerDialog(playerid, buy_weaponpiece, DIALOG_STYLE_INPUT, "{FF0000}Comprar Peça de Arma", "{FFFFFF}Digite abaixo a quantidade de peça de arma que vai comprar\n\n{FF0000}Obs: Minímo 10 máximo 50", "Comprar", "Cancelar");

            new weaponPiece = GetIntQuery(playerid, "Itens", "weaponpiece");

            if(weaponPiece >= MAX_WP)
                return SendClientMessage(playerid, Erro, "Você já tem o máximo de peças");

            if((weaponPiece + strval(inputtext)) > MAX_WP)
            {
                new value[MAX_PLAYERS];

                value[playerid] = (MAX_WP - weaponPiece);

                if(PlayerInfo[playerid][Dinheiro] < (value[playerid] * WP_PRICE))
                    return SendClientMessage(playerid, Erro, "Você não tem dinheiro o suficiente");

                weaponPiece += value[playerid];

                SetIntQuery(playerid, "Itens", "weaponpiece", weaponPiece);

                PlayerInfo[playerid][Dinheiro] -= (value[playerid] * WP_PRICE);

                format(String, MAX_STRING, "Você comprou %d peças de arma por $%s", value[playerid], IsMoney((value[playerid] * WP_PRICE), "."));
            }
            else
            {
                if(PlayerInfo[playerid][Dinheiro] < (strval(inputtext) * WP_PRICE))
                    return SendClientMessage(playerid, Erro, "Você não tem dinheiro o suficiente");

                weaponPiece += strval(inputtext);
                SetIntQuery(playerid, "Itens", "weaponpiece", weaponPiece);

                PlayerInfo[playerid][Dinheiro] -= (strval(inputtext) * WP_PRICE);

                format(String, MAX_STRING, "Você comprou %d peças de arma por $%s", strval(inputtext), IsMoney((strval(inputtext) * WP_PRICE), "."));
            }

            UpdatePlayerMoney(playerid);
            SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);
            return 1;
        }
        default:
        {
            if(!response) return 0;

            //printf("[!] DIALOG INVÁLIDO - Player: %s[%d] - Dialogid %d - Response %d - Listitem %d - Inputtext %d", PlayerInfo[playerid][Nome], playerid, dialogid, response, listitem, inputtext);
            return 1;
        }
    }
    return 1;
}
