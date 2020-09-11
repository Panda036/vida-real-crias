/************************************************************
* OWNER :
*        Henrique Calenzo
*
* START DATE :
*       13/03/2019
*
* NOTES :
*       Copyright Vida Real Crias 2019 - 2020.  All rights reserved.
*
*/

#define SERVER_OFFLINE  false
#define SERVER_VERSION  "0.0.11"
#define SERVER_IP1      "149.56.41.55:7778"
#define SERVER_IP2      "ca12.heavyhost.com.br:7778"
#define SERVER_FORUM    "vidarealcrias.forumeiros.com"

#include                        a_samp
#include                        a_mysql
#include                        streamer
#include                        pawn.cmd
#include                        sscanf2
#include                        crashdetect
#include                        ysf

#include modules\defines
#include modules\variables
#include modules\discord

#define     MAILER_URL "spelsajten.net/mailer.php"
#include    mailer

/* TextDraws */
#include modules\textdraws\td_skinlist
#include modules\textdraws\td_barstatus
#include modules\textdraws\td_skinsstore
#include modules\textdraws\td_taximeter
#include modules\textdraws\td_detonated
#include modules\textdraws\td_alterpass
#include modules\textdraws\td_coding
#include modules\textdraws\td_antiafk
#include modules\textdraws\td_time
#include modules\textdraws\td_tutorial
#include modules\textdraws\td_vehiclestate
#include modules\textdraws\td_prision
#include modules\textdraws\td_concessionaire
#include modules\textdraws\td_identity
#include modules\textdraws\td_ban
#include modules\textdraws\td_loading
#include modules\textdraws\td_jetpack
#include modules\textdraws\td_base

/* Database */
#include modules\database\db_accounts
#include modules\database\db_accessories
#include modules\database\db_itens
#include modules\database\db_identidade
#include modules\database\db_ban
#include modules\database\db_bag
#include modules\database\db_status
#include modules\database\db_vehicles
#include modules\database\db_houses
#include modules\database\db_business
#include modules\database\db_cnh
#include modules\database\db_staffs
#include modules\database\db_tags
#include modules\database\db_timers
#include modules\database\db_transfer
#include modules\database\db_server
#include modules\database\db_schedulingcnh

/* Player */
#include modules\player\py_mobile
#include modules\player\py_functions
#include modules\player\py_editobject
#include modules\player\py_bag
#include modules\player\py_accessories
#include modules\player\py_skinsstore
#include modules\player\py_arena
#include modules\player\py_sleep
#include modules\player\py_barstatus
#include modules\player\py_loginscreen
#include modules\player\py_vips
#include modules\player\py_disease
#include modules\player\py_antiafk
#include modules\player\py_dbweaponblock
#include modules\player\py_disconnect
#include modules\player\py_locate
#include modules\player\py_identity
#include modules\player\py_jetpack
#include modules\player\py_gunsscallop
#include modules\player\py_drivingschool
#include modules\player\py_cnh

/* Modules */
#include modules\safety
#include modules\serverconfig
#include modules\tax
#include modules\agency
#include modules\vehicles
#include modules\base
#include modules\concessionaire
#include modules\bank
#include modules\hud
#include modules\speedometer
#include modules\enterexit
#include modules\hospital
#include modules\fuelstation
#include modules\realestate
#include modules\msgrandom
#include modules\npcs
#include modules\gps
#include modules\office
#include modules\prison
#include modules\removebug
#include modules\tutorial
#include modules\texts
#include modules\townhall
#include modules\merchandise

/* Objects */
#include modules\object\obj_cashmachine
#include modules\object\obj_objects
#include modules\object\obj_radars
#include modules\object\obj_labels
#include modules\object\obj_pickups
#include modules\object\obj_departament
#include modules\object\obj_mapicons
#include modules\object\obj_tolls
#include modules\object\obj_checkpoints
#include modules\object\obj_remove

/* Profission */
#include modules\profession\honest\pfs_ej
#include modules\profession\honest\pfs_icecream
#include modules\profession\honest\pfs_pizzaboy
#include modules\profession\honest\pfs_gari
#include modules\profession\honest\pfs_paramedic
#include modules\profession\honest\pfs_lawyer
#include modules\profession\honest\pfs_light

#include modules\profession\transport\pfs_taxi
#include modules\profession\transport\pfs_tanker
#include modules\profession\transport\pfs_strongcardriver
#include modules\profession\transport\pfs_loader

#include modules\profession\police\pfs_police
#include modules\profession\police\pfs_strongcarsecurity

#include modules\profession\government\pfs_internalaffairs
#include modules\profession\government\pfs_navy
#include modules\profession\government\pfs_army
#include modules\profession\government\pfs_aeronautics

#include modules\profession\mob\pfs_potplanter
#include modules\profession\mob\pfs_burglar
#include modules\profession\mob\pfs_thief

/* Player Commands*/
#include modules\player\command\cmds_general
#include modules\player\command\cmds_both

/* Events */
//#include modules\events\ev_car

/* Anti Cheats */
#include modules\anticheats\ac_config
#include modules\anticheats\ac_money

main(){}

public OnPlayerConnect(playerid)
{
    SetPlayerColor(playerid, White);
    SetPlayerName(playerid, "Verificando_Dispositivo");
    PlayAudioStreamForPlayer(playerid, "https://www.spreaker.com/user/12774048/neffex");

    OnClearChat(playerid);
	return 1;
}

public OnPlayerEnterDynamicRaceCP(playerid)
{
    if(!PlayerInfo[playerid][pds_in])
    {
        Gari_DynamicRaceCP(playerid);
        BoyNewspaper_DynamicRaceCP(playerid);
        Light_DynamicRaceCP(playerid);
        Thief_DynamicRaceCP(playerid);
        Loader_DynamicRaceCP(playerid);
        Vehicles_DynamicRaceCP(playerid);
    }
    else
    {
        DS_DynamicRaceCP(playerid);
    }
	return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == help)
    {
        if(response)
        {
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
                	strcat(txt, "{00FFFF}»{FFFFFF} /Toplevel {FFFFFF}- Para ver os Level Alto\n");
                	strcat(txt, "{00FFFF}»{FFFFFF} /Taxi [Local]{FFFFFF}- Chamar um Taxi\n");
                	strcat(txt, "{00FFFF}»{FFFFFF} /Radio {FFFFFF}- Para ligar a Rádio \n");
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
        }
        return 1;
    }
    if(dialogid == tuning)
	{
        if(response)
		{
            switch(listitem)
            {
                case 0:
                    ShowPlayerDialog(playerid, paintjob, DIALOG_STYLE_LIST, "{FF0000}Paint Jobs", "{FFFFFF}PaintJob 1 \nPaintJob 2\nPaintJob 3 \nRemover PaintJob","Concluir","Voltar");
                case 1:
                    ShowPlayerDialog(playerid, nitro, DIALOG_STYLE_LIST, "{FF0000}Nitros", "{FFFFFF}Nitro 2\nNitro 5 \nNitro 10 \nRemover Nitro","Concluir","Voltar");
                case 2:
                    ShowPlayerDialog(playerid, wheel, DIALOG_STYLE_LIST, "{FF0000}Rodas", "{FFFFFF}Shadow \nMega \nRimshine \nWires \nClassic \nTwist \nCutter \nSwitch \nGrove \nDollar \nTrance \nAtomic \nRemover Rodas","Concluir","Voltar");
                case 3:
                    ShowPlayerDialog(playerid, hydraulic, DIALOG_STYLE_LIST, "{FF0000}Hidraulica", "{FFFFFF}Hidraulica \nRemover Hidraulica","Concluir","Voltar");
            }
        }
        return 1;
    }
    if(dialogid == nitro)
	{
        if(!response)
            return ShowPlayerDialog(playerid, tuning,DIALOG_STYLE_LIST,"{FF0000}Tunar","{FFFFFF}PaintJobs \nNitros \nRodas \nHidraulica","Concluir","Fechar");

        if(response)
		{
            switch(listitem)
            {
                case 0:
                    AddVehicleComponent(GetPlayerVehicleID(playerid), 1009); // Nitro 1
                case 1:
                    AddVehicleComponent(GetPlayerVehicleID(playerid), 1008); // Nitro 2
                case 2:
                    AddVehicleComponent(GetPlayerVehicleID(playerid), 1010); // Nitro 3
                case 3:
                    RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1009), // Nitro 1
                    RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1008), // Nitro 2
                    RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1010); // Nitro 3
            }
		}
		return 1;
	}
    if(dialogid == paintjob)
	{
        if(!response)
            return ShowPlayerDialog(playerid, tuning,DIALOG_STYLE_LIST,"{FF0000}Tunar","{FFFFFF}PaintJobs \nNitros \nRodas \nHidraulica","Concluir","Fechar");

        if(response)
        {
            switch(listitem)
            {
                case 0:
                    ChangeVehiclePaintjob(GetPlayerVehicleID(playerid), 0);
                case 1:
                    ChangeVehiclePaintjob(GetPlayerVehicleID(playerid), 1);
                case 2:
                    ChangeVehiclePaintjob(GetPlayerVehicleID(playerid), 2);
                case 3:
                    ChangeVehiclePaintjob(GetPlayerVehicleID(playerid), 3);
   		 	}
		}
        return 1;
	}
    if(dialogid == wheel)
	{
        if(!response)
            return ShowPlayerDialog(playerid, tuning,DIALOG_STYLE_LIST,"{FF0000}Tunar","{FFFFFF}PaintJobs \nNitros \nRodas \nHidraulica","Concluir","Fechar");

        if(response)
		{
            switch(listitem)
            {
                case 0:
                    AddVehicleComponent(GetPlayerVehicleID(playerid), 1073); // Shadow
                case 1:
                    AddVehicleComponent(GetPlayerVehicleID(playerid), 1074); // Mega
                case 2:
                    AddVehicleComponent(GetPlayerVehicleID(playerid), 1075); // Rimshine
                case 3:
                    AddVehicleComponent(GetPlayerVehicleID(playerid), 1076); // Wires
                case 4:
                    AddVehicleComponent(GetPlayerVehicleID(playerid), 1077);  // Classic
                case 5:
                    AddVehicleComponent(GetPlayerVehicleID(playerid), 1078); //  Twist
                case 6:
                    AddVehicleComponent(GetPlayerVehicleID(playerid), 1079); //  Cutter
                case 7:
                    AddVehicleComponent(GetPlayerVehicleID(playerid), 1080); //  Switch
                case 8:
                    AddVehicleComponent(GetPlayerVehicleID(playerid), 1081); //  Grove
                case 9:
                    AddVehicleComponent(GetPlayerVehicleID(playerid), 1082); //  Import
                case 10:
                    AddVehicleComponent(GetPlayerVehicleID(playerid), 1083); //  Dollar
                case 11:
                    AddVehicleComponent(GetPlayerVehicleID(playerid), 1084); // Trance
                case 12:
                    AddVehicleComponent(GetPlayerVehicleID(playerid), 1085); // Atomic
                case 13:
                    RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1073),
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
		}
		return 1;
	}
    if(dialogid == hydraulic)
	{
        if(response)
		{
            switch(listitem)
            {
                case 0:
                    AddVehicleComponent(GetPlayerVehicleID(playerid), 1087); // Hidraulica
                case 1:
                    RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1087); // Hidraulica
			}
		}
        if(!response)
		{
            ShowPlayerDialog(playerid, tuning,DIALOG_STYLE_LIST,"{FF0000}Tunar","{FFFFFF}PaintJobs \nNitros \nRodas \nHidraulica","Concluir","Fechar");
		}
		return true;
	}
    if(dialogid == rename)
    {
        if(!response)
            return SendClientMessage(playerid, Erro, "Você cancelou a troca de nome");

        if(response)
        {
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

            if(cache_num_rows()){
                new idhouse[MAX_PLAYERS];

                cache_get_value_int(0, "ID", idhouse[playerid]);
                format(HouseInfo[idhouse[playerid]][hNome], MAX_PLAYER_NAME, inputtext);
                UpdateHouseExternal(idhouse[playerid]);

                mysql_format(IDConexao, String, sizeof(String), "UPDATE `Houses` SET `Nome`='%e' WHERE `Nome`='%e'", inputtext, PlayerInfo[playerid][Nome]);
                mysql_query(IDConexao, String);
            }

            mysql_format(IDConexao, String, sizeof(String), "SELECT `ID` FROM `Business` WHERE `Nome`='%e'", PlayerInfo[playerid][Nome]);
            mysql_query(IDConexao, String);

            if(cache_num_rows()){
                new businessid[MAX_PLAYERS];

                cache_get_value_int(0, "ID", businessid[playerid]);
                format(BusinessInfo[businessid[playerid]][cName], MAX_PLAYER_NAME, inputtext);
                UpdateCompanyExternal(businessid[playerid]);

                mysql_format(IDConexao, String, sizeof(String), "UPDATE `Business` SET `Nome`='%e' WHERE `Nome`='%e'", inputtext, PlayerInfo[playerid][Nome]);
                mysql_query(IDConexao, String);
            }

            format(PlayerInfo[playerid][Nome], MAX_PLAYER_NAME, inputtext);
            SetPlayerName(playerid, PlayerInfo[playerid][Nome]);
        }
        return 1;
    }
    if(dialogid == radio)
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
    if(dialogid == colorname)
    {
        if(response)
        {
            if(strlen(inputtext) != 6)
                return ShowPlayerDialog(playerid, colorname, DIALOG_STYLE_INPUT, "{FF0000}Cor nome", "{FFFFFF}Digite um codigo em '{FF0000}HTML{FFFFFF}' abaixo\nPesquise no Google algo como {00FF00}Cores em HTML {FFFFFF}:\n{FF0000}Exemplo {FFFFFF}00FF00 = {00FF00}Calenzo\n{FF0000}Erro digite uma cor 'HTML' com 6 digitos!", "Alterar", "Cancelar");

            format(String, sizeof(String), "0x%sAA", inputtext);
            SetPlayerColor(playerid, HexToInt(String));
            format(String, sizeof(String), "| VRC-Admin | A cor do seu nome {%s}%s{FFFFFF} foi alterado com sucesso!", inputtext, PlayerInfo[playerid][Nome]);
            SendClientMessage(playerid, White, String);
        }
        return 1;
    }

    if(dialogid == vip_area)
    {
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
    if(dialogid == main_reais && response)
    {
        if(listitem == 0)
        {
            new txt[200];

            if(!IsPlayerMobile(playerid))
                { strcat(txt, "{FFFFFF}Dia(s)\t {FF0000}Real(is) \n"); }

            strcat(txt, "{FFFFFF}1 Dia \t\t{31B404}R$1,00\n");
            strcat(txt, "{FFFFFF}15 Dias \t\t{31B404}R$10,00\n");
            strcat(txt, "{FFFFFF}30 Dias \t\t{31B404}R$20,00\n");
            strcat(txt, "{FFFFFF}60 Dias \t\t{31B404}R$35,00\n");

            ShowPlayerDialog(playerid, main_reais_vip, (IsPlayerMobile(playerid) ? (DIALOG_STYLE_LIST) : (DIALOG_STYLE_TABLIST_HEADERS)), "{FF0000}Comprar VIP", txt, "Comprar", "Voltar");
        }
        return 1;
    }
    if(dialogid == main_reais_vip)
    {
        if(!response)
            return ShowPlayerDialog(playerid, main_reais, DIALOG_STYLE_LIST, "{FF0000}Reais", "{FFFFFF}Comprar VIP", "Continuar", "Cancelar");

        switch(listitem)
        {
            case 0:
            {
                if(PlayerInfo[playerid][Reais] < 1)
                    return SendClientMessage(playerid, Erro, "Infelizmente você não tem Reais o suficiente");

                PlayerInfo[playerid][Reais] -= 1;
                OnPlayerGiveVIP(playerid, 1, 1);
                return 1;
            }
            case 1:
            {
                if(PlayerInfo[playerid][Reais] < 10)
                return SendClientMessage(playerid, Erro, "Infelizmente você não tem Reais o suficiente");

                PlayerInfo[playerid][Reais] -= 10;
                OnPlayerGiveVIP(playerid, 15, 10);
                return 1;
            }
            case 2:
            {
                if(PlayerInfo[playerid][Reais] < 20)
                    return SendClientMessage(playerid, Erro, "Infelizmente você não tem Reais o suficiente");

                PlayerInfo[playerid][Reais] -= 20;
                OnPlayerGiveVIP(playerid, 30, 20);
                return 1;
            }
            case 3:
            {
                if(PlayerInfo[playerid][Reais] < 35)
                    return SendClientMessage(playerid, Erro, "Infelizmente você não tem Reais o suficiente");

                PlayerInfo[playerid][Reais] -= 35;
                OnPlayerGiveVIP(playerid, 60, 35);
                return 1;
            }
        }
        return 1;
    }
    if(dialogid == study && response)
    {
        switch(listitem)
        {
            case 0:
            {
                new txt[200];

                strcat(txt, "{FFFFFF}1° - Evite bater com o veículo; \n");
                strcat(txt, "{FFFFFF}2° - Evite demorar para realizar à prova; \n\n");

                ShowPlayerDialog(playerid, 0, DIALOG_STYLE_LIST, "{FF0000}Auto Escola", txt, "Estudar", "Cancelar");
                return 1;
            }
        }
        return 1;
    }
	return 1;
}

public OnPlayerClickTextDraw(playerid, Text:clickedid)
{
    if(clickedid == Text:INVALID_TEXT_DRAW)
    {
        if(!PlayerInfo[playerid][Logado]) {
            SelectTextDraw(playerid, Green);
        }

        if(LocationConcessionaire[playerid]) {
            LocationConcessionaire[playerid] = 0;
            HideTDConcessionaire(playerid);
        }

        if(CostSkin[playerid]) {
            CostSkin[playerid] = 0;
            HideTDPlayerSkinsStore(playerid);
        }

        if(Identity[playerid]) {
            Identity[playerid] = false;
            HideTDPlayerIdentity(playerid);
        }

        if(Banimento[playerid][b_ban]) {
            Banimento[playerid][b_ban] = false;
            HideTDPlayerBan(playerid);
        }

        return 1;
    }
    return 1;
}

public OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{
    ClickTextDrawLoginRegister(playerid, playertextid);
    ClickTextDrawConcessionaire(playerid, playertextid);
    ClickTextDrawSkinsStore(playerid, playertextid);
    ClickTextDrawIdentity(playerid, playertextid);
    ClickTextDrawBan(playerid, playertextid);

    if(playertextid == TDPlayerSkinList[playerid][1]) //Escolher
    {
        if(strcmp(PlayerInfo[playerid][sexo], SkinListPolice[SkinList[playerid]][slp_sex]))
            return SendClientMessage(playerid, Erro, "Sexo Inválido");

        if((SkinListPolice[SkinList[playerid]][slp_skinid] == 287 || SkinListPolice[SkinList[playerid]][slp_skinid] == 191) && ( PlayerInfo[playerid][Profissao] != navy && PlayerInfo[playerid][Profissao] != army && PlayerInfo[playerid][Profissao] != aeronautics ))
            return SendClientMessage(playerid, Erro, "Você não trabalhar para as forças armadas!");

        HideTDPlayerSkinList(playerid);
        SetPlayerSkin(playerid, SkinListPolice[SkinList[playerid]][slp_skinid]);
        return 1;
    }
    if(playertextid == TDPlayerSkinList[playerid][2]) //left
    {
        if(SkinList[playerid] == 0)
            return SendClientMessage(playerid, Erro, "Não tem mais skins");

        SkinList[playerid]--;

        PlayerTextDrawSetPreviewModel(playerid, TDPlayerSkinList[playerid][0], SkinListPolice[SkinList[playerid]][slp_skinid]);
        PlayerTextDrawShow(playerid, TDPlayerSkinList[playerid][0]);
        PlayerTextDrawSetString(playerid, TDPlayerSkinList[playerid][4], SkinListPolice[SkinList[playerid]][slp_sex]);
        PlayerTextDrawShow(playerid, TDPlayerSkinList[playerid][4]);
        return 1;
    }
    if(playertextid == TDPlayerSkinList[playerid][3]) //right
    {
        if(SkinList[playerid] == 20)
            return SendClientMessage(playerid, Erro, "Não tem mais skins");

        SkinList[playerid]++;

        PlayerTextDrawSetPreviewModel(playerid, TDPlayerSkinList[playerid][0], SkinListPolice[SkinList[playerid]][slp_skinid]);
        PlayerTextDrawShow(playerid, TDPlayerSkinList[playerid][0]);
        PlayerTextDrawSetString(playerid, TDPlayerSkinList[playerid][4], SkinListPolice[SkinList[playerid]][slp_sex]);
        PlayerTextDrawShow(playerid, TDPlayerSkinList[playerid][4]);
        return 1;
    }

    if(playertextid == TDPlayerSkinList[playerid][5]) return HideTDPlayerSkinList(playerid); //exit

    return 1;
}

stock formatSeconds(seconds, &hours_left, &minutes_left, &seconds_left)
{
    hours_left = seconds/60/60;
    minutes_left = (seconds - hours_left*60*60 )/60;
    seconds_left = (seconds - hours_left*60*60 - minutes_left*60);
    return 1;
}

stock GetDistanceBetweenPlayers(playerid,playerid2)
{
    new Float:x1,Float:y1,Float:z1,Float:x2,Float:y2,Float:z2;
    new Float:dis;
    GetPlayerPos(playerid,x1,y1,z1);
    GetPlayerPos(playerid2,x2,y2,z2);
    dis = floatsqroot(floatpower(floatabs(floatsub(x2,x1)),2)+floatpower(floatabs(floatsub(y2,y1)),2)+floatpower(floatabs(floatsub(z2,z1)),2));
    return floatround(dis);
}

stock HexToInt(string[])
{
    if(!string[0]) return 0;
    new cur = 1, res = 0;
    for(new i = strlen(string); i > 0; i--)
    {
        res += cur * (string[i - 1] - ((string[i - 1] < 58) ? (48) : (55)));
        cur = cur * 16;
    }
    return res;
}

stock IsNumeric(const string[])
{
    for (new i = 0, j = strlen(string); i < j; i++)
    {
        if(string[i] > '9' || string[i] < '0') return 0;
    }
    return 1;
}

stock IsValidUsername(name[])
{
	new i, len = strlen(name);

	if(len < 3) return 0;

	while(i < len)
	{
		switch(name[i])
		{
			case 'a'..'z', 'A'..'Z', '0'..'9', '.', '_':
				i++;
			default:
				return 0;
		}
	}
	return 1;
}

stock IsValidMessageHouse(name[])
{
	new i, len = strlen(name);

	if(len < 3) return 0;

	while(i < len)
	{
		switch(name[i])
		{
			case 'a'..'z', 'A'..'Z', '0'..'9', '.', '_', ' ', '{', '}', '?', '!':
				i++;
			default:
				return 0;
		}
	}
	return 1;
}

stock IsMoney(integer, delimiter[] = ",")
{
    new str[16];

    format(str, sizeof str, "%i", integer);

    for (new i = strlen(str) - 3, j = ((integer < 0) ? 1 : 0); i > j; i -= 3)
    {
        strins(str, delimiter, i, sizeof str);
    }
    return str;
}

stock GetPlayerID(playername[])
{
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(!strcmp(playername, PlayerInfo[i][Nome], true) && PlayerInfo[i][Logado])
        {
            return i;
        }
    }
    return INVALID_PLAYER_ID;
}

stock TextConverter(string[])
{
    for(new arraysize = 0; arraysize < strlen(string); arraysize++)
    {
        if(strfind(string, "â", true) != -1){new pos = strfind(string, "â", true); strdel(string, pos, pos+strlen("â")); strins(string, "™", pos, sizeof(pos));}
        if(strfind(string, "ã", true) != -1){new pos = strfind(string, "ã", true); strdel(string, pos, pos+strlen("ã")); strins(string, "š", pos, sizeof(pos));}
        if(strfind(string, "á", true) != -1){new pos = strfind(string, "á", true); strdel(string, pos, pos+strlen("á")); strins(string, "˜", pos, sizeof(pos));}
        if(strfind(string, "é", true) != -1){new pos = strfind(string, "é", true); strdel(string, pos, pos+strlen("é")); strins(string, "ž", pos, sizeof(pos));}
        if(strfind(string, "ú", true) != -1){new pos = strfind(string, "ú", true); strdel(string, pos, pos+strlen("ú")); strins(string, "“", pos, sizeof(pos));}
        if(strfind(string, "ó", true) != -1){new pos = strfind(string, "ó", true); strdel(string, pos, pos+strlen("ó")); strins(string, "¦", pos, sizeof(pos));}
        if(strfind(string, "ê", true) != -1){new pos = strfind(string, "ê", true); strdel(string, pos, pos+strlen("ê")); strins(string, "Ÿ", pos, sizeof(pos));}
        if(strfind(string, "í", true) != -1){new pos = strfind(string, "í", true); strdel(string, pos, pos+strlen("í")); strins(string, "¢", pos, sizeof(pos));}
        if(strfind(string, "ç", true) != -1){new pos = strfind(string, "ç", true); strdel(string, pos, pos+strlen("ç")); strins(string, "œ", pos, sizeof(pos));}
        if(strfind(string, "ô", true) != -1){new pos = strfind(string, "ô", true); strdel(string, pos, pos+strlen("ô")); strins(string, "§", pos, sizeof(pos));}
    }
    return 1;
}

stock CreateRandomCode()
{
    new code[10], Coding[36][2] =
    {
        "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
        "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "X", "W", "Y", "Z"
    };

    code[0] = random(sizeof(Coding));
    code[1] = random(sizeof(Coding));
    code[2] = random(sizeof(Coding));
    code[3] = random(sizeof(Coding));
    code[4] = random(sizeof(Coding));
    code[5] = random(sizeof(Coding));
    code[6] = random(sizeof(Coding));
    code[7] = random(sizeof(Coding));
    code[8] = random(sizeof(Coding));
    code[9] = random(sizeof(Coding));

    format(String, sizeof(String), "%s%s%s%s%s%s%s%s%s%s", Coding[code[0]], Coding[code[1]], Coding[code[2]], Coding[code[3]], Coding[code[4]], Coding[code[5]], Coding[code[6]], Coding[code[7]], Coding[code[8]], Coding[code[9]]);

    new query[100];

    mysql_format(IDConexao, query, sizeof(query), "SELECT `Code` FROM `Contas` WHERE `Code`='%e'", String);
    mysql_query(IDConexao, query);

    if(cache_num_rows() != 0) return CreateRandomCode();

    return String;
}

stock IsValidCodingAccount(playerid, coding[])
{
    new query[100];
    mysql_format(IDConexao, query, sizeof(query), "SELECT `Code` FROM `Contas` WHERE `Code`='%e' AND `id`='%d'", coding, PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);

    if(cache_num_rows() != 0) return true;
    return false;
}

stock alfabeto [ 1 + ('z' - 'a') ] = { 'a', 'b', ...};
stock numeros [ 1 + ('9' - '0') ] = { '0', '1', ...};

stock GetRandomString(size = 0xff)
{
    static stringBuff[0xff];

    if(size < 0xff && size) {

        for(new i; i != size; i++) stringBuff[i] = bool: random(2) ? numeros [random(sizeof numeros )] : alfabeto [random(sizeof alfabeto )];

        stringBuff[size] = EOS;
    }
    return stringBuff;
}

stock GetPlayerIDAccount(name[])
{
    new id_account, query[100];

    mysql_format(IDConexao, query, 100, "SELECT `id` FROM `Contas` WHERE `Nome`='%e' LIMIT 1", name);
    new Cache:result = mysql_query(IDConexao, query);

    switch(cache_num_rows())
    {
        case 0: id_account = INVALID_PLAYER_ID;
        case 1: cache_get_value_int(0, "id", id_account);
    }

    cache_delete(result);
    return id_account;
}
