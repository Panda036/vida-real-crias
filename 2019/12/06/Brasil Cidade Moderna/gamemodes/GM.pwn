//-----------------------------------------
//By: Henrique Calenzo
//Date: 23/03/2019
//-----------------------------------------
#include                        a_samp
#include                        a_mysql
#include                        streamer
#include                        cpstream
#include                        modules\color

//Login 1 - 5
#define vip_area                        6
#define mob                             7
#define honest                          8
#define transport                       9
#define police                          10
#define government                      11
#define help                            12
#define tuning                          13
#define paintjob                        14
#define nitro                           15
#define hydraulic                       16
#define wheel                           17
#define rename                          18
#define radio                           19
#define colorname                       20
#define vip_color_tag                   21
#define reais                           22
#define reais_vip                       23
#define cmds_adm_pg1                    24
#define cmds_adm_pg2                    25
#define cmds_adm_pg3                    26
#define cmds_adm_pg4                    27
#define bank_balance                    28
#define bank_draft                      29
#define bank_deposit                    30
#define bank                            31
#define agency                          32
#define hospital                        33

#define Desempregado                    0
#define EntregadorJornais               1
#define EntregadorPizzas                2
#define VendedorSkins                   3
#define Advogado                        4

#define Taxi                            5

#define PoliciaMunicipal                6

#define Corregedoria                    7

#define LadraoGas                       8

enum pInfo
{
    ID,
    Profissao,
    Semprofissao,
    Nome[MAX_PLAYER_NAME],
    Senha[MAX_PLAYER_PASS],
    Email[MAX_PLAYER_EMAIL],
    Admin,
    minUP,
    segUP,
    Level,
    Exp,
    Reais,
    Skin,
    Avisos,
    Estrelas,
    Dinheiro,
    SaldoBancario,
    Matou,
    Morreu,
    Interior,
    Float:PosX,
    Float:PosY,
    Float:PosZ,
    Float:PosA,
    bool:Afk,
    bool:Logado
};

enum BanidosE {
    bResponsavel[MAX_PLAYER_NAME],
    bMotivo[24],
    bDia[24],
    bVencimento[24],
    bHora[24]
}

enum ppInfo
{
    pNome[MAX_PLAYER_NAME],
    pSenha[MAX_PLAYER_PASS],
    pEmail[MAX_PLAYER_EMAIL]
};

enum rankingEnum
{
    player_Score,
    player_ID
}

new BanidosEnum[MAX_PLAYERS][BanidosE];
new pPlayerInfo[MAX_PLAYERS][ppInfo];
new PlayerInfo[MAX_PLAYERS][pInfo];

new bool:LiberarRelatorio[MAX_PLAYERS char];
new bool:LiberarDuvida[MAX_PLAYERS char];
new bool:cVehicle[MAX_PLAYERS];
new bool:Respawnando;

new String[256];
new TempoPreso[MAX_PLAYERS];
new CarroAdmin[MAX_PLAYERS];
new UPRelogio[MAX_PLAYERS];
new Float:X, Float:Y, Float:Z, Float:A;
new Ano, Mes, Dia, Hora, Min, Seg;
new Cor1, Cor2;

//ProgressBar
new PlayerText:PlayerBarStatus[MAX_PLAYERS][6],
    TimerBarStatus[MAX_PLAYERS];

new Text:RespawnVeiculos;

new cps_areavip,
    cps_mafia,
    cps_agencia,
    cps_bank;

new Count = 5;
new ContadorTxT[5][19] =
{
	"~y~] ]~w~ 1 ~y~] ]",
	"~y~] ]~w~ 2 ~y~] ]",
	"~r~] ]~w~ 3 ~r~] ]",
	"~r~] ]~w~ 4 ~r~] ]",
	"~r~] ]~w~ 5 ~r~] ]"
};

new MSGs[16][128] =
{
    "{FFFFFF}[!] {76EE00}Para ver seu level ~~> /Meulevel",
    "{FFFFFF}[!] {76EE00}Jogar em nosso servidor é um privilegio e não direito!",
    "{FFFFFF}[!] {76EE00}Ofensa à Staff Será Punido com Ban",
    "{FFFFFF}[!] {76EE00}Se cadastrem no Fórum e fique por dentro das novidades ~~> /Ajuda ~~> Contatos",
    "{FFFFFF}[!] {76EE00}Viu uma pessoa dando Teleporte? /Relatorio",
    "{FFFFFF}[!] {FF8C00}Inscreva-se em nosso canal no YouTube: www.youtube.com/channel/UCMijwRnIbRf2RerUEST-sqg?",
    "{FFFFFF}[!] {76EE00}Deseja VIP ? Acesse nosso site e confira: https://n290690.tryinvision.com/",
    "{FFFFFF}[!] {76EE00}Bem vindo(a) ao Brasil Cidade Moderna",
    "{FFFFFF}[!] {76EE00}Para ver os Players Level Alto Digite ~~> /Toplevel",
    "{FFFFFF}[!] {76EE00}Chame Seus Amigo pro Servidor Fica Mais Divertido",
    "{FFFFFF}[!] {76EE00}Para evitar punições, sempre respeite as regras, use: /Regras",
    "{FFFFFF}[!] {76EE00}Caso esteja com pouco combustivel, procure um dos 10 postos espalhados por San Andreas",
    "{FFFFFF}[!] {76EE00}Veja Todos Contatos do Servidor: /Ajuda ~~> Contatos",
    "{FFFFFF}[!] {76EE00}Para denuciar Cheaters ou Abusers ~~> /Relatorio",
    "{FFFFFF}[!] {76EE00}Para ver as vantagens VIP /Vantagensvip",
    "{FFFFFF}[!] {76EE00}Está precisando de ajuda e não tem nenhum admin online ? ~~> /Ajuda"
};

#include modules\database\db_accounts.sql
#include modules\database\db_ban.sql

#include modules\prison
#include modules\profession\police\militarypolice
#include modules\profession\honest\ej
#include modules\profession\honest\pizzaboy
#include modules\profession\honest\sellskins
#include modules\profession\honest\lawyer
#include modules\profession\mob\thief

#include modules\bank
#include modules\base
#include modules\hud
#include modules\agency
#include modules\vehicles
#include modules\speedometer
#include modules\enterexit
#include modules\hospital

#include modules\player\barstatus
#include modules\player\loginscreen
#include modules\player\vips
#include modules\player\houses
#include modules\player\company

#include modules\object\labels
#include modules\object\pickups
#include modules\object\departament

main(){}

public OnGameModeInit()
{
    ShowPlayerMarkers(PLAYER_MARKERS_MODE_STREAMED);

    RespawnVeiculos = TextDrawCreate(317.799987, 192.346771, "");
    TextDrawLetterSize(RespawnVeiculos, 0.400000, 1.600000);
    TextDrawAlignment(RespawnVeiculos, 2);
    TextDrawColor(RespawnVeiculos, -1);
    TextDrawSetShadow(RespawnVeiculos, 0);
    TextDrawSetOutline(RespawnVeiculos, -1);
    TextDrawBackgroundColor(RespawnVeiculos, 255);
    TextDrawFont(RespawnVeiculos, 1);
    TextDrawSetProportional(RespawnVeiculos, 1);
    TextDrawSetShadow(RespawnVeiculos, 0);

    CPS_AddCheckpoint(248.9497, 67.6059, 1003.6406, 1.0, 30);   //CPS Departament
    cps_areavip = CPS_AddCheckpoint(-783.7917, 495.3470, 1376.1953, 1.0, 30);
    cps_bank = CPS_AddCheckpoint(2310.0422, -8.3888, 26.7422, 1.0, 30);
    cps_mafia = CPS_AddCheckpoint(2360.1792, -652.2457, 128.0910, 1.0, 50);
    cps_agencia = CPS_AddCheckpoint(1490.8159, 1305.7130, 1093.2964, 1.0, 30);

    UsePlayerPedAnims();
	EnableStuntBonusForAll(0);
	DisableInteriorEnterExits();

    SetTimer("RandomMSGs", 1000*60*20, true);

	SetGameModeText("Brasil - BCM @BETA");
    SendRconCommand("mapname San Andreas");
	SendRconCommand("hostname Brasil Cidade Moderna ® #Ultra-h.com");
	SendRconCommand("language Português - Brasil");
    return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
    TogglePlayerSpectating(playerid, true);
    InterpolateCameraPos(playerid, -2397.553710, 1436.038452, 140.798019, -2876.055175, 1382.189697, 159.150161, 17000);
    InterpolateCameraLookAt(playerid, -2401.776855, 1438.431640, 139.599197, -2872.188964, 1384.818359, 157.377395, 17000);
	return 1;
}

public OnPlayerConnect(playerid)
{
    PlayAudioStreamForPlayer(playerid, "http://listen.shoutcast.com:80/RadioHunter-TheHitzChannel");
    format(String, sizeof(String), "Entrando_%d", playerid);
    SetPlayerName(playerid, String);
    SelectTextDraw(playerid, Verde);

    ShowTextDrawLogin(playerid);

    SetTimerEx("OnPlayerUpdateCreate", 1000, true, "i", playerid);
    UPRelogio[playerid] = SetTimerEx("ClockUP", 1000,true,"i",playerid);
    SetTimerEx("OnPlayerClearChat", 4000, false, "i", playerid);
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
    DeletarSair(playerid);
    SaveAccounts(playerid);
    DBSavePrisons(playerid);
    ZerandoVariaveis(playerid);
	return 1;
}

public OnPlayerSpawn(playerid)
{
    CancelSelectTextDraw(playerid);
    StopAudioStreamForPlayer(playerid);
    return 1;
}

public OnPlayerDeath(playerid, killerid, reason)
{
    SendDeathMessage(killerid, playerid, reason);

    PlayerInfo[killerid][Estrelas]+=5;
    PlayerInfo[playerid][Morreu]++;
    PlayerInfo[killerid][Matou]++;

    DeletarSair(playerid);

    format(String, sizeof(String), "%d", PlayerInfo[killerid][Estrelas]);
    PlayerTextDrawSetString(killerid, PlayerBarStatus[killerid][1], String);
    PlayerTextDrawShow(killerid, PlayerBarStatus[killerid][1]);

    format(String, sizeof(String), "| PROCURADO(A) | O(A) %s %s[%d] feriu %s[%d] e foi colocado +5 estrelas de procurado(a)", PlayerInfo[killerid][Profissao], PlayerInfo[killerid][Nome], killerid, PlayerInfo[playerid][Nome], playerid);
    ProxDetector(50.0, playerid, String, 0xB9FFFFAA, 0xB9FFFFAA, 0xB9FFFFAA, 0xB9FFFFAA, 0xB9FFFFAA);
	return 1;
}

public OnVehicleDeath(vehicleid, killerid)
{
    DeletarSair(killerid);
	return 1;
}

public OnPlayerText(playerid, text[])
{
    if(PlayerInfo[playerid][Logado] == false)
    {
        SendClientMessage(playerid, Erro, "| ERRO | Você não está logado!");
        return false;
    }
    if(PlayerInfo[playerid][Afk] == true)
    {
        SendClientMessage(playerid, Erro, "| ERRO | Antes de falar, digite: /Sairafk");
        return false;
    }
    if(PrisonEnum[playerid][pTempo] != 0)
    {
        SendClientMessage(playerid, Erro, "| ERRO | Você está preso e não pode usar o chat!");
        return false;
    }
    if(PlayerInfo[playerid][Admin] == 5)
    {
        format(String, sizeof(String), "%s {FFFFFF}[{328E0A}Desenvolvedor(a){FFFFFF}][%d]: %s", PlayerInfo[playerid][Nome], playerid, text);
        ProxDetector(30.0, playerid, String, GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid));
        return false;
    }
    else if(PlayerInfo[playerid][Admin] == 4)
    {
        format(String, sizeof(String), "%s {FFFFFF}[{FF0000}Coordenador(a){FFFFFF}][%d]: %s", PlayerInfo[playerid][Nome], playerid, text);
        ProxDetector(30.0, playerid, String, GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid));
        return false;
    }
    else if(PlayerInfo[playerid][Admin] == 3)
    {
        format(String, sizeof(String), "%s {FFFFFF}[{008bce}Admininstrador(a){FFFFFF}][%d]: %s", PlayerInfo[playerid][Nome], playerid, text);
        ProxDetector(30.0, playerid, String, GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid));
        return false;
    }
    else if(PlayerInfo[playerid][Admin] == 2)
    {
        format(String, sizeof(String), "%s {FFFFFF}[{FF8C00}Moderador(a){FFFFFF}][%d]: %s", PlayerInfo[playerid][Nome], playerid, text);
        ProxDetector(30.0, playerid, String, GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid));
        return false;
    }
    else if(PlayerInfo[playerid][Admin] == 1)
    {
        format(String, sizeof(String), "%s {FFFFFF}[{FFFF00}Ajudante{FFFFFF}][%d]: %s", PlayerInfo[playerid][Nome], playerid, text);
        ProxDetector(30.0, playerid, String, GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid));
        return false;
    }
    else if(!IsPlayerHelper(playerid))
    {
        format(String, sizeof(String), "%s {FFFFFF}[%d]: %s", PlayerInfo[playerid][Nome], playerid, text);
        ProxDetector(30.0, playerid, String, GetPlayerColor(playerid), GetPlayerColor(playerid), PlayerInfo[playerid][Nome], GetPlayerColor(playerid), GetPlayerColor(playerid));
        return false;
    }
    return 1;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
    new cmd[128], idx;
    cmd = strtok(cmdtext, idx);

    if(PlayerInfo[playerid][Logado] == false)
        return SendClientMessage(playerid, Erro, "| ERRO | Você não está logado!");

    if(PlayerInfo[playerid][Afk] == true)
        return SendClientMessage(playerid, Erro, "| ERRO | Antes de usar comando, digite: /Sairafk");

    if(Algemado[playerid] == true)
        return SendClientMessage(playerid, Erro, "| ERRO | Você está algemado e não pode usar comando!");

    if(!strcmp(cmd, "/aceitar", true))
    {
        if(AdvogadoOfertou[playerid])
        {
            AdvogadoOfertou[playerid] = false;
            AdvogadoAceitou[playerid] = true;
        }
        else if(OfferSkin[playerid])
        {
            OfferSkin[playerid] = false;
            Accepted[playerid] = true;
        }
        else
        {
            SendClientMessage(playerid, Erro, "| ERRO | Você não recebeu nenhuma oferta!");
        }
        return 1;
    }
    if(!strcmp(cmd, "/recusar", true))
    {
        if(AdvogadoOfertou[playerid])
        {
            AdvogadoOfertou[playerid] = false;
            AdvogadoRecusou[playerid] = true;
        }
        else if(OfferSkin[playerid])
        {
            OfferSkin[playerid] = false;
            Refused[playerid] = true;
        }
        else
        {
            SendClientMessage(playerid, Erro, "| ERRO | Você não recebeu nenhuma oferta!");
        }
        return 1;
    }

    if(PrisonEnum[playerid][pTempo] != 0)
        return SendClientMessage(playerid, Erro, "| ERRO | Você está preso e não pode usar comando!");

    #include modules\player\command\cmds_adm

    #include modules\player\command\cmds_ambos

    #include modules\player\command\cmds_ej
    #include modules\player\command\cmds_pizzaboy
    #include modules\player\command\cmds_sellskins
    #include modules\player\command\cmds_lawyer

    #include modules\player\command\cmds_militarypolice

    #include modules\player\command\cmds_thief

    #include modules\player\command\cmds_vip

    #include modules\player\command\cmds_houses

    #include modules\player\command\cmds_company

    #include modules\player\command\cmds_gerais

	return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
}

public OnPlayerExitVehicle(playerid, vehicleid)
{
    DeletarSair(playerid);
	return 1;
}

public OnPlayerEnterCheckpoint(playerid)
{
    if(CPS_GetPlayerCheckpoint(playerid) == cps_areavip)
        return ShowPlayerDialog(playerid, vip_area, DIALOG_STYLE_LIST, "{FFFFFF}Armas área [{FF0000}VIP{FFFFFF}]", "{FFFFFF}Chainsaw \nCombate Shotgun \nSawnoff \nUZI \nMP5 \nTec-9 \nM4 \nAK-47 \nRifle \nSniper", "Escolher", "Cancelar");

	return 1;
}

public OnPlayerPickUpPickup(playerid, pickupid)
{
    GetEnterExitStatus(playerid, pickupid);
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
                    new textos[500];
                	strcat(textos, "{a4a4a4}A cada 10 minutos jogado Você ganhará 1 ponto de experiência \n");
                    strcat(textos, "{a4a4a4}Juntando 6 pontos de experiência Você ganhará +1 level \n\n");
                    strcat(textos, "{a4a4a4}Jogadores(as) VIPs terá que juntar 5 experiência para ganhar +1 level \n\n");
                    strcat(textos, "{FFFFFF}»{66cdaa} /MeuLevel {FFFFFF}- Para ver seu level \n");
                    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Ajuda Level", textos, "Fechar", "");
                }
                case 1:
                {
                    new textos[500];
                	strcat(textos, "{a4a4a4}O Salário é creditado em sua conta bancária ao completar UP ( 6/6 ) \n\n");
                    strcat(textos, "{a4a4a4}Jogadores(as) VIPs terá salário creditado ao completar UP ( 5/5 ) \n\n");
                    strcat(textos, "{a4a4a4}Cada profissão tem um salário diferente e justo \n\n");
                    strcat(textos, "{a4a4a4}Cargos da mafia não recebem salário \n");
                    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Ajuda Salï¿½rio", textos, "Fechar", "");
                }
                case 2:
                {
                    new textos[2000];
                	strcat(textos, "{00FFFF}»{FFFFFF} /Regras {FFFFFF}- Para ver as regras do servidor\n");
                	strcat(textos, "{00FFFF}»{FFFFFF} /Creditos {FFFFFF}- Para ver os créditos do servidor\n");
                	strcat(textos, "{00FFFF}»{FFFFFF} /Admins {FFFFFF}- Para ver os Admins online no momento\n");
                	strcat(textos, "{00FFFF}»{FFFFFF} /MeuLevel {FFFFFF}- Para ver seu level atual\n");
                	strcat(textos, "{00FFFF}»{FFFFFF} /VantagensVip {FFFFFF}- Para saber as vantagens V.I.P\n");
                	strcat(textos, "{00FFFF}»{FFFFFF} /Sairafk {FFFFFF}- Para sair do modo AFK\n");
                	strcat(textos, "{00FFFF}»{FFFFFF} /Profissao {FFFFFF}- Para ver os comandos da profissão\n");
                	strcat(textos, "{00FFFF}»{FFFFFF} /Abastecer {FFFFFF}- Para abastecer um veï¿½culo em um determinado posto\n");
                	strcat(textos, "{00FFFF}»{FFFFFF} /Animes {FFFFFF}- Para ver a lista de animes disponível\n");
                	strcat(textos, "{00FFFF}»{FFFFFF} /190 [Denúncia] {FFFFFF}- Para fazer uma denúncia à policia\n");
                	strcat(textos, "{00FFFF}»{FFFFFF} /193 [Local] {FFFFFF}- Para chamar a equipe de paramï¿½dicos\n");
                	strcat(textos, "{00FFFF}»{FFFFFF} /Duvida [Duvida]{FFFFFF}- Para tirar alguma dúvida com algum membro da Administraï¿½ï¿½o\n");
                	strcat(textos, "{00FFFF}»{FFFFFF} /Relatorio [Playerid][Denucia]{FFFFFF}- Para denunciar algum jogador fora das regras ou usando hack\n");
                	strcat(textos, "{00FFFF}»{FFFFFF} /Transferir {FFFFFF}- Para transferir uma determinada quantia a um determinado jogador\n");
                	strcat(textos, "{00FFFF}»{FFFFFF} /identidade {FFFFFF}- Para ver sua identidade\n");
                	strcat(textos, "{00FFFF}»{FFFFFF} /Toplevel {FFFFFF}- Para ver os Level Alto\n");
                	strcat(textos, "{00FFFF}»{FFFFFF} /Taxi [Local]{FFFFFF}- Chamar um Taxi\n");
                	strcat(textos, "{00FFFF}»{FFFFFF} /Mecanico [Local]{FFFFFF}- Chamar um Mecanico\n");
                	strcat(textos, "{00FFFF}»{FFFFFF} /Radio {FFFFFF}- Para ligar a Rádio \n");
                	ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Ajuda Comandos", textos, "Fechar", "");
                }
                case 3:
                {
                    new textos[500];
                    strcat(textos, "{FFFFFF}»{FF0000} Fórum: {FFFFFF}Em Breve \n");
                    strcat(textos, "{FFFFFF}»{FF0000} Facebook: {FFFFFF}Em Breve \n");
                    strcat(textos, "{FFFFFF}»{FF0000} IP do TeamSpeak 3: {FFFFFF}Em Breve \n");
                    strcat(textos, "{FFFFFF}»{FF0000} IP do Servidor ( v1.0.0 ) {FFFFFF}Em Breve \n");
                    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Contatos", textos, "Fechar", "");
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
        if(response)
        {
            if(strlen(inputtext) < MIN_PLAYER_NAME || strlen(inputtext) > MAX_PLAYER_NAME)
                return ShowPlayerDialog(playerid, rename, DIALOG_STYLE_INPUT, "{FF0000}Mudar nick", "{FFFFFF}Digite seu novo nick e clique em {FF0000}Mudar\n{FFFFFF}Por favor não coloque {FF0000}ESPAï¿½O {FFFFFF}em seu nick:\n{FF0000}Erro digite um nome entre 6 a 30 caracteres!", "Mudar", "Sair");

            mysql_format(IDConexao, String, sizeof(String), "SELECT `Nome` FROM Contas WHERE `Nome`='%s'", inputtext);
            mysql_query(IDConexao, String);

            if(cache_num_rows() > 0)
                return ShowPlayerDialog(playerid, rename, DIALOG_STYLE_INPUT, "{FF0000}Mudar nick", "{FF0000}O nick que você escolheu já existe\n\n {FFFFFF}Tente outro nick abaixo e clique em {FF0000}Mudar", "Mudar", "Sair");

            format(String, sizeof(String), "| NICK | O(A) jogador(a) %s mudou o nick para ( %s )", PlayerInfo[playerid][Nome], inputtext);
            SendClientMessageToAll(Amarelo, String);

            PlayerInfo[playerid][Reais] -= 7000;

            mysql_format(IDConexao, String, sizeof(String), "UPDATE Contas SET Nome='%e', Reais='%d' WHERE Nome='%e'", inputtext, PlayerInfo[playerid][Reais], PlayerInfo[playerid][Nome]);
            mysql_query(IDConexao, String);

            format(PlayerInfo[playerid][Nome], MAX_PLAYER_NAME, inputtext);
            SetPlayerName(playerid, PlayerInfo[playerid][Nome]);
        }
        if(!response) return SendClientMessage(playerid, Erro, "| ERRO | Você cancelou a troca de nick!");
        return 1;
    }
    if(dialogid == radio)
    {
        if(response)
        {
            switch(listitem)
            {
                case 0:
                    PlayAudioStreamForPlayer(playerid, "");
                case 1:
                    PlayAudioStreamForPlayer(playerid, "http://listen.shoutcast.com:80/RadioHunter-TheHitzChannel");
                case 2:
                    PlayAudioStreamForPlayer(playerid, "");
                case 3:
                    PlayAudioStreamForPlayer(playerid, "");
                case 4:
                    StopAudioStreamForPlayer(playerid);
            }
        }
        return 1;
    }
    if(dialogid == colorname)
    {
        if(response)
        {
            if(strlen(inputtext) != 6)
                return ShowPlayerDialog(playerid, colorname, DIALOG_STYLE_INPUT, "{FF0000}Cor nick", "{FFFFFF}Digite um codigo em '{FF0000}HTML{FFFFFF}' abaixo\nPesquise no Google algo como {00FF00}Cores em HTML {FFFFFF}:\n{FF0000}Exemplo {FFFFFF}00FF00 = {00FF00}Calenzo\n{FF0000}Erro digite uma cor 'HTML' com 6 digitos!", "Alterar", "Cancelar");

            format(String, sizeof(String), "0x%sAA", inputtext);
            SetPlayerColor(playerid, HexToInt(String));
            format(String, sizeof(String), "| BCM-Admin | A cor do seu nick {%s}%s{FFFFFF} foi alterado com sucesso!", inputtext, PlayerInfo[playerid][Nome]);
            SendClientMessage(playerid, Branco, String);
        }
        return 1;
    }

    if(dialogid == vip_area)
    {
        switch(listitem)
        {
            case 0: GivePlayerWeapon(playerid, 9, 100000);
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
    if(dialogid == reais)
    {
        if(response)
        {
            if(listitem == 0)
            {
                new textos[200];
                strcat(textos, "{FF0000}Dia(s) \t\t{1CEB00}Real(is)\n");
                strcat(textos, "{FFFFFF}1 Dia \t\t{31B404}R$1,00\n");
                strcat(textos, "{FFFFFF}15 Dias \t\t{31B404}R$10,00\n");
                strcat(textos, "{FFFFFF}30 Dias \t\t{31B404}R$20,00\n");
                strcat(textos, "{FFFFFF}60 Dias \t\t{31B404}R$45,00\n");
        		ShowPlayerDialog(playerid, reais_vip, DIALOG_STYLE_TABLIST_HEADERS, "{C0C0C0}Comandos VIP", textos, "Comprar", "Voltar");
            }
        }
        return 1;
    }
    if(dialogid == reais_vip)
    {
        if(!response)
            return ShowPlayerDialog(playerid, reais, DIALOG_STYLE_LIST, "{FF0000}Reais", "Comprar VIP", "Continuar", "Cancelar");

        if(response)
        {
            if(listitem == 0)
            {
                if(PlayerInfo[playerid][Reais] < 1000)
                    return SendClientMessage(playerid, Erro, "| ERRO | Infelizmente você não tem Reais o suficiente!");

                SetVip(playerid, 1);
            }
            if(listitem == 1)
            {
                if(PlayerInfo[playerid][Reais] < 10000)
                    return SendClientMessage(playerid, Erro, "| ERRO | Infelizmente você não tem Reais o suficiente!");

                SetVip(playerid, 10);
            }
            if(listitem == 2)
            {
                if(PlayerInfo[playerid][Reais] < 20000)
                    return SendClientMessage(playerid, Erro, "| ERRO | Infelizmente você não tem Reais o suficiente!");

                SetVip(playerid, 20);
            }
            if(listitem == 3)
            {
                if(PlayerInfo[playerid][Reais] < 45000)
                    return SendClientMessage(playerid, Erro, "| ERRO | Infelizmente você não tem Reais o suficiente!");

                SetVip(playerid, 60);
            }
        }
        return 1;
    }
    if(dialogid == cmds_adm_pg1)
    {
        if(response)
        {
            new txt[2800];
            strcat(txt, "{FF0000}Comandos \t\t{1CEB00}Informações\n");
            strcat(txt, "{87CEFF}/Ir [id] \t\t{FFFFFF}Para ir até um(a) jogador(a) \n");
    		strcat(txt, "{87CEFF}/Trazer [id] \t\t{FFFFFF}Para puxar um(a) jogador(a) \n");
    		strcat(txt, "{87CEFF}/Punicao [id][minutos][motivo] \t\t{FFFFFF}Para prender um(a) jogador(a) \n");
    		strcat(txt, "{87CEFF}/Despunicao [id] \t\t{FFFFFF}Para soltar um(a) jogador(a) \n");
            strcat(txt, "{87CEFF}/EncherVida [id] \t\t{FFFFFF}Para recuperar a vida de um(a) jogador(a) \n");
            strcat(txt, "{87CEFF}/EncherColete [id] \t\t{FFFFFF}Para recuperar o colete de um(a) jogador(a) \n");
            strcat(txt, "{87CEFF}/CriarVeiculo [id-carro][id-cor][id-cor] \t\t{FFFFFF}Para criar um veiculo em sua posição \n");
    		strcat(txt, "{87CEFF}/Ac [mensagem] \t\t{FFFFFF}Para digitar no chat da admininstração \n");
      		strcat(txt, "{87CEFF}/A [mensagem] \t\t{FFFFFF}Para mandar mensagem(ns) global\n");
        	strcat(txt, "{87CEFF}/Ann [mensagem] \t\t{FFFFFF}Para mandar mensagem(ns) na tela\n");
          	strcat(txt, "{87CEFF}/Cnn [mensagem] \t\t{FFFFFF}Para mandar mensagem(ns) na tela com o nome\n");
            strcat(txt, "{87CEFF}/Tps \t\t{FFFFFF}Para ver os teletransportes\n");
            strcat(txt, "{87CEFF}/Banir [id][motivo] \t\t{FFFFFF}Para banir um(a) jogador(a) permanente\n");
            strcat(txt, "{87CEFF}/DarArma [id][id-arma] \t\t{FFFFFF}Para dar uma arma para um(a) jogador(a)\n");
            strcat(txt, "{87CEFF}/DarSkin [id] [id-skin] \t\t{FFFFFF}Para dar uma skin para um(a) jogador(a)\n");
            ShowPlayerDialog(playerid, cmds_adm_pg2, DIALOG_STYLE_TABLIST_HEADERS, "{C0C0C0}Comandos da Admininstração - Página {00CA00}2", txt, "Próxima", "Cancelar");
        }
        return 1;
    }
    if(dialogid == cmds_adm_pg2)
    {
        if(response)
        {
            new txt[2800];
            strcat(txt, "{FF0000}Comandos \t\t{1CEB00}Informações\n");
            strcat(txt, "{87CEFF}/IrCasa [id-casa]\t\t{FFFFFF}Para se teletransportar para a casa com esse id\n");
            strcat(txt, "{87CEFF}/DarDinheiro [id][quantia] \t\t{FFFFFF}Para dar dinheiro para um(a) jogador(a)\n");
            strcat(txt, "{87CEFF}/RemoverDinheiro [id][quantia] \t\t{FFFFFF}Para remover dinheiro de um(a) jogador(a)\n");
            strcat(txt, "{87CEFF}/DarVip [id][Dias] \t\t{FFFFFF}Para dar vip para um(a) jogador(a)\n");
            strcat(txt, "{87CEFF}/RemoverVip [id] \t\t{FFFFFF}Para remover o vip de um(a) jogador(a)\n");
            strcat(txt, "{87CEFF}/DarAdmin [id][Nivel] \t\t{FFFFFF}Para promover/rebaixar/remover jogador(a) da admininstração\n");
            strcat(txt, "{87CEFF}/Reiniciar \t\t{FFFFFF}Para reiniciar o servidor\n");
            strcat(txt, "{87CEFF}/DarLevel [id][quantia] \t\t{FFFFFF}Para dar level(s) para um(a) jogador(a)\n");
            strcat(txt, "{87CEFF}/RemoverLevel [id][quantia] \t\t{FFFFFF}Para remover level(s) de um(a) jogador(a)\n");
            strcat(txt, "{87CEFF}/DarReais [id][quantia] \t\t{FFFFFF}Para dar real(is) de um(a) jogador(a)\n");
            strcat(txt, "{87CEFF}/RemoverReais [id][quantia] \t\t{FFFFFF}Para remover real(is) de um(a) jogador(a)\n");
            strcat(txt, "{87CEFF}/R [id][resposta] \t\t{FFFFFF}Para responder a dúvida de um(a) jogador(a)\n");
            strcat(txt, "{87CEFF}/AbrirServidor \t\t{FFFFFF}Para retirar a senha do servidor\n");
            strcat(txt, "{87CEFF}/FecharServidor [senha] \t\t{FFFFFF}Para fechar o servidor com senha\n");
            strcat(txt, "{87CEFF}/SalvarContas \t\t{FFFFFF}Para salvar todas as contas logadas no servidor\n");
            ShowPlayerDialog(playerid, cmds_adm_pg3, DIALOG_STYLE_TABLIST_HEADERS, "{C0C0C0}Comandos da Admininstração - Página {00CA00}3", txt, "Fechar", "Cancelar");
        }
        return 1;
    }
	return 1;
}

public OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
{
    if(IsPlayerHelper(playerid) && GetPlayerInterior(playerid) == 0)
    {
        if(IsPlayerInAnyVehicle(playerid))
        {
            SetVehiclePos(GetPlayerVehicleID(playerid), fX, fY, fZ);
            PutPlayerInVehicle(playerid, GetPlayerVehicleID(playerid), GetPlayerVehicleSeat(playerid));
        } else {
            SetPlayerPosFindZ(playerid, fX, fY, fZ);
        }
    }
	return 1;
}

forward Respawn1();
public Respawn1()
{
    TextDrawHideForAll(RespawnVeiculos);
    SetTimer("Respawn2", 12*1000, false);
    return 1;
}

forward Respawn2();
public Respawn2()
{
    TextDrawSetString(RespawnVeiculos, "~r~>> ~w~Respawn de veiculos nao em uso em ~g~15 ~w~segundos... ~r~<<");
    TextDrawShowForAll(RespawnVeiculos);
    SetTimer("Respawn3", 3000, false);
    return 1;
}

forward Respawn3();
public Respawn3()
{
    TextDrawHideForAll(RespawnVeiculos);
    SetTimer("CountDown", 7000, false);
    return 1;
}

forward CountDown();
public CountDown()
{
    if(Count > 0)
    {
        GameTextForAll(ContadorTxT[Count-1], 2500, 3);
        Count--;
        SetTimer("CountDown", 1000, 0);
    } else {
        TextDrawHideForAll(RespawnVeiculos);
        SendClientMessageToAll(Amarelo, "| INFO | Todos os veiculos não em uso foram respawnados!");
        Respawnando=false;
        GameTextForAll("~g~]] ~w~RESPAWNANDO~g~ ]]", 2500, 3);
        Count=5;
        for(new i; i < MAX_VEHICLES; i++) if(!IsVehicleInUse(i)) SetVehicleToRespawn(i);
    }
    return 1;
}

forward OnPlayerUpdateCreate(playerid);
public OnPlayerUpdateCreate(playerid)
{
    if(PlayerInfo[playerid][Logado] == false) return 0;

    switch(PlayerInfo[playerid][Admin])
    {
        case 1:
            SetPlayerChatBubble(playerid, "Ajudante", 0xFFFF00AA, 80.0, 100000);
        case 2:
            SetPlayerChatBubble(playerid, "Moderador(a)", 0xFF8C00AA, 80.0, 100000);
        case 3:
            SetPlayerChatBubble(playerid, "Administrador(a)", 0x008bceAA, 80.0, 100000);
        case 4:
            SetPlayerChatBubble(playerid, "Coordenador(a)", 0xFF0000AA, 80.0, 100000);
        case 5:
            SetPlayerChatBubble(playerid, "Desenvolvedor(a)", 0x328E0AAA, 80.0, 100000);
    }
    return 1;
}

forward Kicka(playerid);
public Kicka(playerid)
{
    #undef Kick
    Kick(playerid);
    #define Kick(%0) SetTimerEx("Kicka", 100, false, "i", %0)
    return 1;
}

forward Bana(playerid);
public Bana(playerid)
{
    #undef Ban
    Ban(playerid);
    #define Ban(%0) SetTimerEx("Bana", 100, false, "i", %0)
    return 1;
}

forward ProxDetector(Float:radi, playerid, string[], col1, col2, col3, col4, col5);
public ProxDetector(Float:radi, playerid, string[], col1, col2, col3, col4, col5)
{
    if(IsPlayerConnected(playerid))
    {
        new Float:posx, Float:posy, Float:posz;
        new Float:oldposx, Float:oldposy, Float:oldposz;
        new Float:tempposx, Float:tempposy, Float:tempposz;
        GetPlayerPos(playerid, oldposx, oldposy, oldposz);
        for(new i; i <= MAX_PLAYERS; i++)
        {
            if(IsPlayerConnected(i))
            {
                GetPlayerPos(i, posx, posy, posz);
                tempposx = (oldposx -posx);
                tempposy = (oldposy -posy);
                tempposz = (oldposz -posz);
                if (((tempposx < radi/16) && (tempposx > -radi/16)) && ((tempposy < radi/16) && (tempposy > -radi/16)) && ((tempposz < radi/16) && (tempposz > -radi/16))) {
                    SendClientMessage(i, col1, string);
                } else if (((tempposx < radi/8) && (tempposx > -radi/8)) && ((tempposy < radi/8) && (tempposy > -radi/8)) && ((tempposz < radi/8) && (tempposz > -radi/8))) {
                    SendClientMessage(i, col2, string);
                } else if (((tempposx < radi/4) && (tempposx > -radi/4)) && ((tempposy < radi/4) && (tempposy > -radi/4)) && ((tempposz < radi/4) && (tempposz > -radi/4))) {
                    SendClientMessage(i, col3, string);
                } else if (((tempposx < radi/2) && (tempposx > -radi/2)) && ((tempposy < radi/2) && (tempposy > -radi/2)) && ((tempposz < radi/2) && (tempposz > -radi/2))) {
                    SendClientMessage(i, col4, string);
                } else if (((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi))) {
                    SendClientMessage(i, col5, string);
                }
            }
        }
    }
    return 1;
}

forward HideTextRespawn(playerid);
public HideTextRespawn(playerid)
{
    TextDrawHideForPlayer(playerid, RespawnVeiculos);
    return 1;
}

forward RandomMSGs(COLOR, const string[]);
public RandomMSGs(COLOR, const string[])
{
    new random1 = random(sizeof(MSGs));
    SendClientMessageToAll(COLOR, MSGs[random1]);
    return 1;
}

ChatAdmin(COLOR, const string[])
{
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerHelper(i))
        {
            SendClientMessage(i, COLOR, string);
        }
    }
    return 1;
}

ChatVIP(COLOR, const string[])
{
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerHelper(i) || IsPlayerVip(i))
        {
            SendClientMessage(i, COLOR, string);
        }
    }
    return 1;
}

forward UnlockingReport(playerid);
public UnlockingReport(playerid)
{
    LiberarRelatorio{playerid} = false;
    return true;
}

forward UnlockingDoubt(playerid);
public UnlockingDoubt(playerid)
{
    LiberarDuvida{playerid} = false;
    return true;
}

forward Report(COLOR, const string[]);
public Report(COLOR, const string[])
{
    for(new i; i <= MAX_PLAYERS; i++) if(IsPlayerHelper(i))
    {
        SendClientMessage(i, COLOR, String);
        GameTextForPlayer(i, "~n~~r~RELATORIO" , 3000, 3);
        PlayerPlaySound(i,1057,0,0,0);
    }
    return 1;
}

forward Doubt(COLOR, const string[]);
public Doubt(COLOR, const string[])
{
    for(new i; i <= MAX_PLAYERS; i++) if(IsPlayerHelper(i))
    {
        SendClientMessage(i, COLOR, string);
        GameTextForPlayer(i, "~n~~b~DUVIDA" , 3000, 3);
        PlayerPlaySound(i, 1057, 0, 0, 0);
    }
    return 1;
}

forward OnPlayerClearChat(playerid);
public OnPlayerClearChat(playerid)
{
    for(new i=0; i < 50; i++)
    {
        SendClientMessage(playerid, -1, "");
    }
    return 1;
}

forward ClockUP(playerid);
public ClockUP(playerid)
{
    if(PlayerInfo[playerid][segUP] == 0 && PlayerInfo[playerid][minUP] == 0)
    {
        if(PlayerInfo[playerid][Logado] == true)
        {
            if(PlayerInfo[playerid][Afk] == false)
            {
                if(PlayerInfo[playerid][Exp] == 5)
                {
                    PlayerInfo[playerid][Level]++;
                    SendClientMessage(playerid, 0x75EA00AA, "| UP | Você ganhou +1 de Experiência ( 6/6 )");
                    format(String, sizeof(String), "| UP | Você juntou 6 de Experiência e ganhou +1 level ( %d ) ", PlayerInfo[playerid][Level]);
                    SendClientMessage(playerid, 0x75EA00AA, String);
                    PlayerPlaySound(playerid, 1057, 0, 0, 0);
                    PlayerInfo[playerid][Exp]=0;
                    Salario(playerid);
                    SetPlayerScore(playerid, PlayerInfo[playerid][Level]);
                } else {
                    PlayerInfo[playerid][Exp]++;
                    format(String, sizeof(String), "| UP | Você ganhou +1 de Experiência ( %d/6 )",PlayerInfo[playerid][Exp]);
                    SendClientMessage(playerid, 0x75EA00AA, String);
                    PlayerPlaySound(playerid, 1057, 0, 0, 0);
                    GameTextForPlayer(playerid, "~w~UP!", 3000, 6);
                }
            }
        }
    }

    if(PlayerInfo[playerid][segUP]==-1)
    {
        if(PlayerInfo[playerid][minUP]==0)
        PlayerInfo[playerid][minUP]=10;
        PlayerInfo[playerid][segUP]=59;
        PlayerInfo[playerid][minUP]--;
    }
    format(String, sizeof(String), "~w~+~r~UP: ~w~%02d:%02d", PlayerInfo[playerid][minUP],PlayerInfo[playerid][segUP]);
    PlayerTextDrawSetString(playerid, PlayerBarStatus[playerid][0], String);
    PlayerInfo[playerid][segUP]--;
    return 1;
}

SetColorProfession(playerid)
{
    switch(PlayerInfo[playerid][Profissao])
    {
        case Desempregado:
            SetPlayerColor(playerid, 0xFFFFFFAA);
        case EntregadorJornais:
            SetPlayerColor(playerid, 0x80FF80AA);
        case EntregadorPizzas:
            SetPlayerColor(playerid, 0xEDA909AA);
        case VendedorSkins:
            SetPlayerColor(playerid, 0xFF80C0AA);
        case Advogado:
            SetPlayerColor(playerid, 0x8000FFAA);
        case Taxi:
            SetPlayerColor(playerid, 0xFFFF00AA);
        case PoliciaMunicipal:
            SetPlayerColor(playerid, 0x66B3FFAA);
        case Corregedoria:
            SetPlayerColor(playerid, 0x8080C0AA);
        case LadraoGas:
            SetPlayerColor(playerid, 0xFF8080AA);
    }
    return 1;
}

forward RestartServer();
public RestartServer()
{
    SendClientMessageToAll(0xB9FFFFAA, "| BCM-Admin | O Server reiniciara em 1 minuto!");
    return SetTimer("RestartServer1", 1000*60, false);

}

forward RestartServer1();
 public RestartServer1()
{
    for(new i; i <= MAX_PLAYERS; i++)
    {
        if(IsPlayerConnected(i))
        {
            SaveAccounts(i);
            Kick(i);
    	}
	}
    SendClientMessageToAll(0xB9FFFFAA, "| BCM-Admin | O Server reinicio aguarde!");
    return SendRconCommand("gmx");
}

forward ExitPersecution(playerid); public ExitPersecution(playerid)
{
    format(String, sizeof(String), "| PERSEGUIÇÃO | O(A) jogador(a) %s[%d] não está sendo mais perseguido pela pocilia por passar 5 minutos!", PlayerInfo[playerid][Nome], playerid);
    SendClientMessage(playerid, 0x2894FFAA, String);
    SendClientMessage(playerid, 0xB9FFFFAA, "| INFO | Você não está mas em perseguição");
    KillTimer(PerseguicaoTime[playerid]);
    Perseguicao[playerid] = false;
    Abordado[playerid] = false;
    return 1;
}

Salario(playerid)
{
    switch(PlayerInfo[playerid][Profissao])
    {
        case Desempregado:
        {
            PlayerInfo[playerid][SaldoBancario] += 150;
        	SendClientMessage(playerid, 0xEDA909AA,"~~~~~~~~~~~~~~~~~~~~~~ Salário ~~~~~~~~~~~~~~~~~~~~~~");
        	format(String,sizeof(String),"{EDA909}» {FFFFFF}Salário: {00A600}$%d", 150);
        	SendClientMessage(playerid, 0xEDA909AA, String);
        	format(String,sizeof(String),"{EDA909}» {FFFFFF}Balanço antigo: {FF0000}$%d", PlayerInfo[playerid][SaldoBancario]-150);
        	SendClientMessage(playerid, 0xEDA909AA, String);
        	format(String,sizeof(String),"{EDA909}» {FFFFFF}Balanço atual: {00A600}$%d", PlayerInfo[playerid][SaldoBancario]);
        	SendClientMessage(playerid, 0xEDA909AA, String);
        	SendClientMessage(playerid, 0xEDA909AA,"~~~~~~~~~~~~~~~~~~~~~~ Salário ~~~~~~~~~~~~~~~~~~~~~~");
        	PlayerPlaySound(playerid, 1057, 0, 0, 0);
        }
        case EntregadorJornais:
        {
            PlayerInfo[playerid][SaldoBancario] += 250;
        	SendClientMessage(playerid, 0xEDA909AA,"~~~~~~~~~~~~~~~~~~~~~~ Salário ~~~~~~~~~~~~~~~~~~~~~~");
        	format(String,sizeof(String),"{EDA909}» {FFFFFF}Salário: {00A600}$%d", 250);
        	SendClientMessage(playerid, 0xEDA909AA, String);
        	format(String,sizeof(String),"{EDA909}» {FFFFFF}Balanço antigo: {FF0000}$%d", PlayerInfo[playerid][SaldoBancario]-250);
        	SendClientMessage(playerid, 0xEDA909AA, String);
        	format(String,sizeof(String),"{EDA909}» {FFFFFF}Balanço atual: {00A600}$%d", PlayerInfo[playerid][SaldoBancario]);
        	SendClientMessage(playerid, 0xEDA909AA, String);
        	SendClientMessage(playerid, 0xEDA909AA,"~~~~~~~~~~~~~~~~~~~~~~ Salário ~~~~~~~~~~~~~~~~~~~~~~");
            PlayerPlaySound(playerid, 1057, 0, 0, 0);
        }
        case VendedorSkins:
        {
            PlayerInfo[playerid][SaldoBancario] += 980;
        	SendClientMessage(playerid, 0xEDA909AA,"~~~~~~~~~~~~~~~~~~~~~~ Salário ~~~~~~~~~~~~~~~~~~~~~~");
        	format(String,sizeof(String),"{EDA909}» {FFFFFF}Salário: {00A600}$%d", 980);
        	SendClientMessage(playerid, 0xEDA909AA, String);
        	format(String,sizeof(String),"{EDA909}» {FFFFFF}Balanço antigo: {FF0000}$%d", PlayerInfo[playerid][SaldoBancario]-980);
        	SendClientMessage(playerid, 0xEDA909AA, String);
        	format(String,sizeof(String),"{EDA909}» {FFFFFF}Balanço atual: {00A600}$%d", PlayerInfo[playerid][SaldoBancario]);
        	SendClientMessage(playerid, 0xEDA909AA, String);
        	SendClientMessage(playerid, 0xEDA909AA,"~~~~~~~~~~~~~~~~~~~~~~ Salário ~~~~~~~~~~~~~~~~~~~~~~");
            PlayerPlaySound(playerid, 1057, 0, 0, 0);
        }
        case Advogado:
        {
            PlayerInfo[playerid][SaldoBancario] += 1000;
        	SendClientMessage(playerid, 0xEDA909AA,"~~~~~~~~~~~~~~~~~~~~~~ Salário ~~~~~~~~~~~~~~~~~~~~~~");
        	format(String,sizeof(String),"{EDA909}» {FFFFFF}Salário: {00A600}$%d", 1000);
        	SendClientMessage(playerid, 0xEDA909AA, String);
        	format(String,sizeof(String),"{EDA909}» {FFFFFF}Balanço antigo: {FF0000}$%d", PlayerInfo[playerid][SaldoBancario]-1000);
        	SendClientMessage(playerid, 0xEDA909AA, String);
        	format(String,sizeof(String),"{EDA909}» {FFFFFF}Balanço atual: {00A600}$%d", PlayerInfo[playerid][SaldoBancario]);
        	SendClientMessage(playerid, 0xEDA909AA, String);
        	SendClientMessage(playerid, 0xEDA909AA,"~~~~~~~~~~~~~~~~~~~~~~ Salário ~~~~~~~~~~~~~~~~~~~~~~");
            PlayerPlaySound(playerid, 1057, 0, 0, 0);
        }
        case Taxi:
        {
            PlayerInfo[playerid][SaldoBancario] += 350;
        	SendClientMessage(playerid, 0xEDA909AA,"~~~~~~~~~~~~~~~~~~~~~~ Salário ~~~~~~~~~~~~~~~~~~~~~~");
        	format(String,sizeof(String),"{EDA909}» {FFFFFF}Salário: {00A600}$%d", 350);
        	SendClientMessage(playerid, 0xEDA909AA, String);
        	format(String,sizeof(String),"{EDA909}» {FFFFFF}Balanço antigo: {FF0000}$%d", PlayerInfo[playerid][SaldoBancario]-350);
        	SendClientMessage(playerid, 0xEDA909AA, String);
        	format(String,sizeof(String),"{EDA909}» {FFFFFF}Balanço atual: {00A600}$%d", PlayerInfo[playerid][SaldoBancario]);
        	SendClientMessage(playerid, 0xEDA909AA, String);
        	SendClientMessage(playerid, 0xEDA909AA,"~~~~~~~~~~~~~~~~~~~~~~ Salário ~~~~~~~~~~~~~~~~~~~~~~");
            PlayerPlaySound(playerid, 1057, 0, 0, 0);
        }
        case PoliciaMunicipal:
        {
            PlayerInfo[playerid][SaldoBancario] += 1000;
        	SendClientMessage(playerid, 0xEDA909AA,"~~~~~~~~~~~~~~~~~~~~~~ Salário ~~~~~~~~~~~~~~~~~~~~~~");
        	format(String,sizeof(String),"{EDA909}» {FFFFFF}Salário: {00A600}$%d", 1000);
        	SendClientMessage(playerid, 0xEDA909AA, String);
        	format(String,sizeof(String),"{EDA909}» {FFFFFF}Balanço antigo: {FF0000}$%d", PlayerInfo[playerid][SaldoBancario]-1000);
        	SendClientMessage(playerid, 0xEDA909AA, String);
        	format(String,sizeof(String),"{EDA909}» {FFFFFF}Balanço atual: {00A600}$%d", PlayerInfo[playerid][SaldoBancario]);
        	SendClientMessage(playerid, 0xEDA909AA, String);
        	SendClientMessage(playerid, 0xEDA909AA,"~~~~~~~~~~~~~~~~~~~~~~ Salário ~~~~~~~~~~~~~~~~~~~~~~");
            PlayerPlaySound(playerid, 1057, 0, 0, 0);
        }
        case Corregedoria:
        {
            PlayerInfo[playerid][SaldoBancario] += 5000;
        	SendClientMessage(playerid, 0xEDA909AA,"~~~~~~~~~~~~~~~~~~~~~~ Salário ~~~~~~~~~~~~~~~~~~~~~~");
        	format(String,sizeof(String),"{EDA909}» {FFFFFF}Salário: {00A600}$%d", 5000);
        	SendClientMessage(playerid, 0xEDA909AA, String);
        	format(String,sizeof(String),"{EDA909}» {FFFFFF}Balanço antigo: {FF0000}$%d", PlayerInfo[playerid][SaldoBancario]-5000);
        	SendClientMessage(playerid, 0xEDA909AA, String);
        	format(String,sizeof(String),"{EDA909}» {FFFFFF}Balanço atual: {00A600}$%d", PlayerInfo[playerid][SaldoBancario]);
        	SendClientMessage(playerid, 0xEDA909AA, String);
        	SendClientMessage(playerid, 0xEDA909AA,"~~~~~~~~~~~~~~~~~~~~~~ Salário ~~~~~~~~~~~~~~~~~~~~~~");
            PlayerPlaySound(playerid, 1057, 0, 0, 0);
        }
        case LadraoGas:
        {
        	SendClientMessage(playerid, 0xEDA909AA,"~~~~~~~~~~~~~~~~~~~~~~ Salário ~~~~~~~~~~~~~~~~~~~~~~");
        	SendClientMessage(playerid, Amarelo, "| AVISO | Mafia não recebe Salário!");
        	format(String,sizeof(String),"{EDA909}» {FFFFFF}Balanço antigo: {FF0000}$%d", PlayerInfo[playerid][SaldoBancario]-0);
        	SendClientMessage(playerid, 0xEDA909AA, String);
        	format(String,sizeof(String),"{EDA909}» {FFFFFF}Balanço atual: {00A600}$%d", PlayerInfo[playerid][SaldoBancario]);
        	SendClientMessage(playerid, 0xEDA909AA, String);
        	SendClientMessage(playerid, 0xEDA909AA,"~~~~~~~~~~~~~~~~~~~~~~ Salário ~~~~~~~~~~~~~~~~~~~~~~");
            PlayerPlaySound(playerid, 1057, 0, 0, 0);
        }
    }
    return EntregouMercadoria[playerid] = false;
}

IsVehicleInUse(vehicleid)
{
    new VeiculoRcd;
    for(new i; i <= MAX_PLAYERS; i++)
    {
        if(GetPlayerVehicleID(i) == vehicleid)
            VeiculoRcd = vehicleid;
        if(GetVehicleTrailer(GetPlayerVehicleID(i)) == vehicleid)
            VeiculoRcd = vehicleid;
    }
    return VeiculoRcd;
}

DeletarSair(playerid)
{
    if(cVehicle[playerid])
    {
        DestroyVehicle(GetPlayerVehicleID(playerid));
        cVehicle[playerid] = false;
        return 1;
    }
    return 1;
}

CargoAdmin(playerid)
{
    static var[21];
    switch(PlayerInfo[playerid][Admin])
    {
        case 1: var = "Ajudante";
        case 2: var = "Moderador(a)";
        case 3: var = "Administrador(a)";
        case 4: var = "Coordenador(a)";
        case 5: var = "Desenvolvedor(a)";
    }
    return var;
}

ZerandoVariaveis(playerid)
{
    PlayerInfo[playerid][ID] = 0;
    PlayerInfo[playerid][Profissao] = 0;
    PlayerInfo[playerid][Semprofissao] = 0;
    PlayerInfo[playerid][Nome] = 0;
    PlayerInfo[playerid][Senha] = 0;
    PlayerInfo[playerid][Email] = 0;
    PlayerInfo[playerid][Admin] = 0;
    PlayerInfo[playerid][minUP] = 0;
    PlayerInfo[playerid][segUP] = 0;
    PlayerInfo[playerid][Level] = 0;
    PlayerInfo[playerid][Exp] = 0;
    PlayerInfo[playerid][Reais] = 0;
    PlayerInfo[playerid][Skin] = 0;
    PlayerInfo[playerid][Avisos] = 0;
    PlayerInfo[playerid][Estrelas] = 0;
    PlayerInfo[playerid][Dinheiro] = 0;
    PlayerInfo[playerid][SaldoBancario] = 0;
    PlayerInfo[playerid][Matou] = 0;
    PlayerInfo[playerid][Morreu] = 0;
    PlayerInfo[playerid][Interior] = 0;
    PlayerInfo[playerid][PosX] = 0;
    PlayerInfo[playerid][PosY] = 0;
    PlayerInfo[playerid][PosZ] = 0;
    PlayerInfo[playerid][PosA] = 0;
    PlayerInfo[playerid][Afk] = false;
    PlayerInfo[playerid][Logado] = false;

    pPlayerInfo[playerid][pNome] = 0;
    pPlayerInfo[playerid][pSenha] = 0;
    pPlayerInfo[playerid][pEmail] = 0;

    CarroAdmin[playerid]=0;

    Algemado[playerid] = false;
    Abordado[playerid] = false;
    Perseguicao[playerid] = false;

    KillTimer(TimerProcurando[playerid]);
    KillTimer(PerseguicaoTime[playerid]);
    KillTimer(TempoPreso[playerid]);
    KillTimer(UPRelogio[playerid]);
    return 1;
}

formatSeconds(seconds, &hours_left, &minutes_left, &seconds_left)
{
    hours_left = seconds/60/60;
    minutes_left = (seconds - hours_left*60*60 )/60;
    seconds_left = (seconds - hours_left*60*60 - minutes_left*60);
    return 1;
}

GetDistanceBetweenPlayers(playerid,playerid2)
{
    new Float:x1,Float:y1,Float:z1,Float:x2,Float:y2,Float:z2;
    new Float:dis;
    GetPlayerPos(playerid,x1,y1,z1);
    GetPlayerPos(playerid2,x2,y2,z2);
    dis = floatsqroot(floatpower(floatabs(floatsub(x2,x1)),2)+floatpower(floatabs(floatsub(y2,y1)),2)+floatpower(floatabs(floatsub(z2,z1)),2));
    return floatround(dis);
}

IsPlayerHelper(playerid)
{
    if(PlayerInfo[playerid][Admin] >= 1 && PlayerInfo[playerid][Admin] <= 5) return true;
    return false;
}

IsPlayerModerator(playerid)
{
    if(PlayerInfo[playerid][Admin] >= 2 && PlayerInfo[playerid][Admin] <= 5) return true;
    return false;
}

IsPlayerAdmininstrator(playerid)
{
    if(PlayerInfo[playerid][Admin] >= 3 && PlayerInfo[playerid][Admin] <= 5) return true;
    return false;
}

IsPlayerDeveloper(playerid)
{
    if(PlayerInfo[playerid][Admin] == 5) return true;
    return false;
}

IsPlayerVip(playerid)
{
    if(VipInfo[playerid][Vip] == true) return true;
    return false;
}

IsPlayerUniformePM(playerid)
{
    if(GetPlayerSkin(playerid) == 287) return true;
    return false;
}

NitroInfinito(arg)
{
    switch(GetVehicleModel(arg))
    {
        case 444: return 0;
        case 581: return 0;
        case 586: return 0;
        case 481: return 0;
        case 509: return 0;
        case 446: return 0;
        case 556: return 0;
        case 443: return 0;
        case 452: return 0;
        case 453: return 0;
        case 454: return 0;
        case 472: return 0;
        case 473: return 0;
        case 484: return 0;
        case 493: return 0;
        case 595: return 0;
        case 462: return 0;
        case 463: return 0;
        case 468: return 0;
        case 521: return 0;
        case 522: return 0;
        case 417: return 0;
        case 425: return 0;
        case 447: return 0;
        case 487: return 0;
        case 488: return 0;
        case 497: return 0;
        case 501: return 0;
        case 548: return 0;
        case 563: return 0;
        case 406: return 0;
        case 520: return 0;
        case 539: return 0;
        case 553: return 0;
        case 557: return 0;
        case 573: return 0;
        case 460: return 0;
        case 593: return 0;
        case 464: return 0;
        case 476: return 0;
        case 511: return 0;
        case 512: return 0;
        case 577: return 0;
        case 592: return 0;
        case 471: return 0;
        case 448: return 0;
        case 461: return 0;
        case 523: return 0;
        case 510: return 0;
        case 430: return 0;
        case 465: return 0;
        case 469: return 0;
        case 513: return 0;
        case 519: return 0;
    }
    return 1;
}

GetPlayerHighestScores(array[][rankingEnum], left, right)
{
    new tempLeft = left,
        tempRight = right,
        pivot = array[(left + right) / 2][player_Score],
        tempVar;

    while(tempLeft <= tempRight)
    {
        while(array[tempLeft][player_Score] > pivot) tempLeft++;
        while(array[tempRight][player_Score] < pivot) tempRight--;

        if(tempLeft <= tempRight)
        {
            tempVar = array[tempLeft][player_Score], array[tempLeft][player_Score] = array[tempRight][player_Score], array[tempRight][player_Score] = tempVar;
            tempVar = array[tempLeft][player_ID], array[tempLeft][player_ID] = array[tempRight][player_ID], array[tempRight][player_ID] = tempVar;
            tempLeft++, tempRight--;
        }
    }
    if(left < tempRight) GetPlayerHighestScores(array, left, tempRight);
    if(tempLeft < right) GetPlayerHighestScores(array, tempLeft, right);
}

HexToInt(string[])
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

IsValidUsername(name[])
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

IsValidMessageHouse(name[])
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

IsMoney(integer, delimiter[] = ",")
{
    new str[16];

    format(str, sizeof str, "%i", integer);

    for (new i = strlen(str) - 3, j = ((integer < 0) ? 1 : 0); i > j; i -= 3)
    {
        strins(str, delimiter, i, sizeof str);
    }
    return str;
}

UpdatePlayerMoney(i)
{
    new _str[200];
    mysql_format(IDConexao, _str, sizeof(_str), "UPDATE Contas SET `Dinheiro`='%d' WHERE `ID`='%d'", PlayerInfo[i][Dinheiro], PlayerInfo[i][ID]);
    mysql_query(IDConexao, _str);
    ResetPlayerMoney(i);
    GivePlayerMoney(i, PlayerInfo[i][Dinheiro]);
}

GetPlayerID(playername[])
{
    for(new i=0; i <= MAX_PLAYERS; i++)
    {
        if(strcmp(playername, PlayerInfo[i][Nome], true)==0 && PlayerInfo[i][Logado] == true)
        {
            return i;
        }
        else
        {
            return true;
        }
    }
    return true;
}
