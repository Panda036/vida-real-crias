#include YSI\y_hooks

#define unemployed                      0
    #define color_unemployed        0xFFFFFFAA
#define newspaperdelivery               1
    #define color_newspaperdelivery 0x80FF80AA
#define icecream                        2
    #define color_icecream          0xFF80C0AA
#define pizzaboy                        3
    #define color_pizzaboy          0xFFFF80AA
#define gari                            4
    #define color_gari              0xD56A00AA
#define paramedic                       5
    #define color_paramedic         0x00FF80AA
#define light                           6
    #define color_light             0x008040AA
#define lawyer                          7
    #define color_lawyer            0x8000FFAA
#define taxi                            8
    #define color_taxi              0xFFFF00AA
#define tanker                          9
    #define color_tanker            0x808080AA
#define loader                          10
    #define color_loader            0x408080AA
#define strongcardriver                 11
    #define color_strongcardriver   0x8080FFAA
#define strongcarsecurity               12
    #define color_strongcarsecurity 0xB7B7FFAA
#define military                        13
    #define color_military          0x0090FFAA
#define federal                         14
    #define color_federal           0x0080FFAA
#define delegate                        15
    #define color_delegate          0x0070FFAA
#define fbi                             16
    #define color_fbi               0x0060FFAA
#define cia                             17
    #define color_cia               0x0050FFAA
#define swat                            18
    #define color_swat              0x0040FFAA
#define narcoticos                      19
    #define color_narcoticos        0x0030FFAA
#define interpol                        20
    #define color_interpol          0x0020FFAA
#define internalaffairs                 21
    #define color_internalaffairs   0x8080C0AA
#define navy                            22
    #define color_navy              0x23238CAA
#define army                            23
    #define color_army              0x54693AAA
#define aeronautics                     24
    #define color_aeronautics       0xCCCC00AA
#define potplanter                      25
    #define color_potplanter        0x550000AA
#define burglar                         26
    #define color_burglar           0x800000AA
#define thief                           27
    #define color_thief             0xAA0000AA

/* color máfia
0x550000AA
0x800000AA
0xAA0000AA
0xD50000AA
0xFF0000AA
0xFF2B2BAA
0xFF5555AA
0xFF8080AA
0xFFAAAAAA
*/

enum e_pa
{
    pa_profission,
    Float:pa_x,
    Float:pa_y,
    Float:pa_z
};

new PlayerAgency[MAX_PLAYERS][e_pa];
new cps_mafia[3];
new cps_agencia;
new AgenciaMapIcon[MAX_PLAYERS];
new AgenciaPickup[MAX_PLAYERS];
new Text3D:AgenciaLabel[MAX_PLAYERS];
new bool:AgenciaEncaminhado[MAX_PLAYERS];

hook OnGameModeInit()
{
    cps_mafia[0] = CreateDynamicCP(2445.82, -1970.11, 13.54, 1.0, -1, -1, -1, 50.0);
    cps_mafia[1] = CreateDynamicCP(2557.30, 2832.35, 10.82, 1.0, -1, -1, -1, 50.0);
    cps_mafia[2] = CreateDynamicCP(-2187.88, -234.58, 36.52, 1.0, -1, -1, -1, 50.0);

    cps_agencia = CreateDynamicCP(1490.8159, 1305.7130, 1093.2964, 1.0, -1, -1, -1, 30.0);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(AgenciaEncaminhado[playerid])
    {
        AgenciaEncaminhado[playerid] = false;
        DestroyDynamic3DTextLabel(AgenciaLabel[playerid]);
        DestroyDynamicPickup(AgenciaPickup[playerid]);
        DestroyDynamicMapIcon(AgenciaMapIcon[playerid]);
    }

    PlayerAgency[playerid][pa_profission] = 0;
    PlayerAgency[playerid][pa_x] = 0;
    PlayerAgency[playerid][pa_y] = 0;
    PlayerAgency[playerid][pa_z] = 0;
	return 1;
}

hook OnPlayerEnterCheckpoint(playerid)
{
    if(IsPlayerInDynamicCP(playerid, cps_mafia[0]) || IsPlayerInDynamicCP(playerid, cps_mafia[1]) || IsPlayerInDynamicCP(playerid, cps_mafia[2]))
    {
        new txt[500];

        if(!IsPlayerMobile(playerid))
            { strcat(txt, "{FFFFFF}Profissão\t {FF0000}Level \n"); }

        strcat(txt, "{FFFFFF}Plantador de Cannabis\t {F71616}5 \n");
        strcat(txt, "{FFFFFF}Assaltante\t {F71616}20 \n");
        strcat(txt, "{FFFFFF}Ladrão\t {F71616}30 \n");

        ShowPlayerDialog(playerid, mob, (IsPlayerMobile(playerid) ? (DIALOG_STYLE_LIST) : (DIALOG_STYLE_TABLIST_HEADERS)), "{FF0000}Menu Cargos", txt, "Selecionar", "Voltar");
        return 1;
    }

    if(IsPlayerInDynamicCP(playerid, cps_agencia))
        return ShowPlayerDialog(playerid, agency, DIALOG_STYLE_LIST, "{FF0000}Menu Empregos", "{FFFFFF}Classe » {80FF80}Honesta \n{FFFFFF}Classe » {80FFFF}Transporte \n{FFFFFF}Classe » {51A8FF}Policia \n{FFFFFF}Classe » {626262}Governo \n{FFFFFF}Classe » {808000}Forças Armadas", "Selecionar", "Fechar");

    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == agency && response)
    {
        switch(listitem)
        {
            case 0:
            {
                new txt[500];

                if(!IsPlayerMobile(playerid))
                    { strcat(txt, "{FFFFFF}Profissão\t {FF0000}Level\t {00C40A}Salário\n"); }

                strcat(txt, "{FFFFFF}Entregador de Jornais\t {F71616}0\t {00C40A}$250\n");
                strcat(txt, "{FFFFFF}Sorveteiro(a)\t {F71616}2\t {00C40A}$350\n");
                strcat(txt, "{FFFFFF}PizzaBoy\t {F71616}4\t {00C40A}$400\n");
                strcat(txt, "{FFFFFF}Gari\t {F71616}10\t {00C40A}$550\n");
                strcat(txt, "{FFFFFF}Paramédico(a)\t {F71616}20\t {00C40A}$850\n");
                strcat(txt, "{FFFFFF}Técnico(a) da Light\t {F71616}45\t {00C40A}$1.500\n");
                strcat(txt, "{FFFFFF}Advogado(a)\t {F71616}50\t {00C40A}$1.600\n");

                ShowPlayerDialog(playerid, honest, (IsPlayerMobile(playerid) ? (DIALOG_STYLE_LIST) : (DIALOG_STYLE_TABLIST_HEADERS)), "{80FF80}Honesta", txt, "Selecionar", "Voltar");
                return 1;
            }
            case 1:
            {
                new txt[300];

                if(!IsPlayerMobile(playerid))
                    { strcat(txt, "{FFFFFF}Profissão\t {FF0000}Level\t {00C40A}Salário\n"); }

                strcat(txt, "{FFFFFF}Taxi\t{F71616}8\t {00C40A}$450\n");
                strcat(txt, "{FFFFFF}Petroleiro\t{F71616}15\t {00C40A}$500\n");
                strcat(txt, "{FFFFFF}Carregador\t{F71616}20\t {00C40A}$750\n");
                strcat(txt, "{FFFFFF}Motorista de Carro Forte\t{F71616}30\t {00C40A}$1.000\n");

                ShowPlayerDialog(playerid, transport, (IsPlayerMobile(playerid) ? (DIALOG_STYLE_LIST) : (DIALOG_STYLE_TABLIST_HEADERS)), "{80FFFF}Transporte", txt, "Selecionar", "Voltar");
                return 1;
            }
            case 2:
            {
                new txt[500];

                if(!IsPlayerMobile(playerid))
                    { strcat(txt, "{FFFFFF}Profissão\t {FF0000}Level\t {00C40A}Salário\n"); }

                strcat(txt, "{FFFFFF}Segurança de Carro Forte\t {F71616}100\t {00C40A}$1.500\n");
                strcat(txt, "{FFFFFF}Policia Militar\t {F71616}100\t {00C40A}$1.800\n");
                strcat(txt, "{FFFFFF}Policia Federal\t {F71616}200\t {00C40A}$2.000\n");
                strcat(txt, "{FFFFFF}Delegado\t {F71616}300\t {00C40A}$2.200\n");
                strcat(txt, "{FFFFFF}FBI\t {F71616}400\t {00C40A}$2.400\n");
                strcat(txt, "{FFFFFF}CIA\t {F71616}500\t {00C40A}$2.600\n");
                strcat(txt, "{FFFFFF}S.W.A.T\t {F71616}600\t {00C40A}$2.800\n");
                strcat(txt, "{FFFFFF}Nacórticos\t {F71616}700\t {00C40A}$3.000\n");
                strcat(txt, "{FFFFFF}Interpol\t {F71616}800\t {00C40A}$3.200\n");

                ShowPlayerDialog(playerid, police, (IsPlayerMobile(playerid) ? (DIALOG_STYLE_LIST) : (DIALOG_STYLE_TABLIST_HEADERS)), "{51A8FF}Policia", txt, "Selecionar", "Voltar");
                return 1;
            }
            case 3:
            {
                new txt[300];

                if(!IsPlayerMobile(playerid))
                    { strcat(txt, "{FFFFFF}Profissão\t {FF0000}Level\t {00C40A}Salário\n"); }

                strcat(txt, "{FFFFFF}Corregedoria\t {F71616}1000\t {00C40A}$4.000\n");

                ShowPlayerDialog(playerid, government, (IsPlayerMobile(playerid) ? (DIALOG_STYLE_LIST) : (DIALOG_STYLE_TABLIST_HEADERS)), "{626262}Governo", txt, "Selecionar", "Voltar");
                return 1;
            }
            case 4:
            {
                new txt[300];

                if(!IsPlayerMobile(playerid))
                    { strcat(txt, "{FFFFFF}Profissão\t {FF0000}Level\t {00C40A}Salário\n"); }

                strcat(txt, "{FFFFFF}Marinha\t {F71616}1200\t {00C40A}$4.300\n");
                strcat(txt, "{FFFFFF}Exército\t {F71616}1400\t {00C40A}$4.600\n");
                strcat(txt, "{FFFFFF}Aeronáutica\t {F71616}1600\t {00C40A}$5.000\n");

                ShowPlayerDialog(playerid, armedforces, (IsPlayerMobile(playerid) ? (DIALOG_STYLE_LIST) : (DIALOG_STYLE_TABLIST_HEADERS)), "{808000}Forças Armadas", txt, "Selecionar", "Voltar");
                return 1;
            }
        }
        return 1;
    }
    if(dialogid == mob && response)
    {
        switch(listitem)
        {
            case 0: SetForwardedAgency(playerid, -1184.80, -1136.56, 129.21, potplanter, 5);
            case 1: SetForwardedAgency(playerid, -391.40, 2221.69, 42.42, burglar, 20);
            case 2: SetForwardedAgency(playerid, -391.40, 2221.69, 42.42, thief, 30);
        }
        return 1;
    }
    if(dialogid == honest)
    {
        if(!response)
            return ShowPlayerDialog(playerid, agency, DIALOG_STYLE_LIST, "{FF0000}Menu Empregos", "{FFFFFF}Classe » {80FF80}Honesta \n{FFFFFF}Classe » {80FFFF}Transporte \n{FFFFFF}Classe » {51A8FF}Policia \n{FFFFFF}Classe » {626262}Governo \n{FFFFFF}Classe » {808000}Forças Armadas", "Selecionar", "Fechar");

        switch(listitem)
        {
            case 0:
                SetForwardedAgency(playerid, 785.20, -1327.76, 13.54, newspaperdelivery, 0);
            case 1:
                SetForwardedAgency(playerid, 2444.00, 1663.00, 10.82, icecream, 2);
            case 2:
                SetForwardedAgency(playerid, 2107.74, -1787.75, 13.56, pizzaboy, 4);
            case 3:
                SetForwardedAgency(playerid, 2089.53, -2080.92, 13.55, gari, 10);
            case 4:
                SetForwardedAgency(playerid, 1599.87, 1818.08, 10.82, paramedic, 20);
            case 5:
                SetForwardedAgency(playerid, -2516.58, -622.51, 132.75, light, 45);
            case 6:
                SetForwardedAgency(playerid, -2051.29, 459.89, 35.17, lawyer, 50);
        }
        return 1;
    }
    if(dialogid == transport)
    {
        if(!response)
            return ShowPlayerDialog(playerid, agency, DIALOG_STYLE_LIST, "{FF0000}Menu Empregos", "{FFFFFF}Classe » {80FF80}Honesta \n{FFFFFF}Classe » {80FFFF}Transporte \n{FFFFFF}Classe » {51A8FF}Policia \n{FFFFFF}Classe » {626262}Governo \n{FFFFFF}Classe » {808000}Forças Armadas", "Selecionar", "Fechar");

        switch(listitem)
        {
            case 0:
                SetForwardedAgency(playerid, 2229.58, -1368.19, 23.992, taxi, 8);
            case 1:
                SetForwardedAgency(playerid, 291.01, 1430.11, 10.54, tanker, 15);
            case 2:
                SetForwardedAgency(playerid, 2467.97, -2118.98, 13.54, loader, 20);
            case 3:
                SetForwardedAgency(playerid, 1765.19, -1703.33, 13.46, strongcardriver, 30);
        }
        return 1;
    }
    if(dialogid == police)
    {
        if(!response)
            return ShowPlayerDialog(playerid, agency, DIALOG_STYLE_LIST, "{FF0000}Menu Empregos", "{FFFFFF}Classe » {80FF80}Honesta \n{FFFFFF}Classe » {80FFFF}Transporte \n{FFFFFF}Classe » {51A8FF}Policia \n{FFFFFF}Classe » {626262}Governo \n{FFFFFF}Classe » {808000}Forças Armadas", "Selecionar", "Fechar");

        switch(listitem)
        {
            case 0:
                SetForwardedAgency(playerid, 1765.19, -1703.33, 13.46, strongcarsecurity, 50);
            case 1:
                SetForwardedAgency(playerid, 1579.5728, -1635.3932, 13.5611, military, 100);
            case 2:
                SetForwardedAgency(playerid, 1579.5728, -1635.3932, 13.5611, federal, 200);
            case 3:
                SetForwardedAgency(playerid, 1579.5728, -1635.3932, 13.5611, delegate, 300);
            case 4:
                SetForwardedAgency(playerid, 1579.5728, -1635.3932, 13.5611, fbi, 400);
            case 5:
                SetForwardedAgency(playerid, 1579.5728, -1635.3932, 13.5611, cia, 500);
            case 6:
                SetForwardedAgency(playerid, 1579.5728, -1635.3932, 13.5611, swat, 600);
            case 7:
                SetForwardedAgency(playerid, 1579.5728, -1635.3932, 13.5611, narcoticos, 700);
            case 8:
                SetForwardedAgency(playerid, 1579.5728, -1635.3932, 13.5611, interpol, 800);
        }
        return 1;
    }
    if(dialogid == government)
    {
        if(!response)
            return ShowPlayerDialog(playerid, agency, DIALOG_STYLE_LIST, "{FF0000}Menu Empregos", "{FFFFFF}Classe » {80FF80}Honesta \n{FFFFFF}Classe » {80FFFF}Transporte \n{FFFFFF}Classe » {51A8FF}Policia \n{FFFFFF}Classe » {626262}Governo \n{FFFFFF}Classe » {808000}Forças Armadas", "Selecionar", "Fechar");

        switch(listitem)
        {
            case 0:
                SetForwardedAgency(playerid, 2339.9778, 2457.2256, 14.9688, internalaffairs, 1000);
        }
        return 1;
    }
    if(dialogid == armedforces)
    {
        if(!response)
            return ShowPlayerDialog(playerid, agency, DIALOG_STYLE_LIST, "{FF0000}Menu Empregos", "{FFFFFF}Classe » {80FF80}Honesta \n{FFFFFF}Classe » {80FFFF}Transporte \n{FFFFFF}Classe » {51A8FF}Policia \n{FFFFFF}Classe » {626262}Governo \n{FFFFFF}Classe » {808000}Forças Armadas", "Selecionar", "Fechar");

        switch(listitem)
        {
            case 0:
                SetForwardedAgency(playerid, -1425.5208, 501.3613, 3.0391, navy, 1200);
            case 1:
                SetForwardedAgency(playerid, 126.1066, 1897.4442, 18.4865, army, 1400);
            case 2:
                SetForwardedAgency(playerid, 126.1066, 1897.4442, 18.4865, aeronautics, 1600);
        }
        return 1;
    }
    return 1;
}

stock NameProfission(profission)
{
    static var[30];
    switch(profission)
    {
        case unemployed: var = "Desempregado(a)";
        case newspaperdelivery: var = "Entregador(a) de Jornais";
        case icecream: var = "Sorveteiro(a)";
        case pizzaboy: var = "PizzaBoy";
        case gari: var = "Gari";
        case paramedic: var = "Paramédico(a)";
        case light: var = "Técnico(a) da Light";
        case lawyer: var = "Advogado(a)";
        case taxi: var = "Taxista";
        case tanker: var = "Petroleiro(a)";
        case loader: var = "Carregador(a)";
        case strongcardriver: var = "Motorista de Carro Forte";
        case strongcarsecurity: var = "Segurança de Carro Forte";
        case military: var = "Polícial Militar";
        case federal: var = "Polícial Federal";
        case delegate: var = "Delegado(a)";
        case fbi: var = "FBI";
        case cia: var = "CIA";
        case swat: var = "S.W.A.T";
        case narcoticos: var = "Narcóticos";
        case interpol: var = "Interpol";
        case internalaffairs: var = "Corregedor(a)";
        case navy: var = "Soldado(a) da Marinha";
        case army: var = "Soldado(a) do Exército";
        case aeronautics: var = "Soldado(a) da Aeronautica";
        case potplanter: var = "Plantador(a) de Cannabis";
        case burglar: var = "Assaltante";
        case thief: var = "Ladrão";
    }
    return var;
}

stock SetColorProfession(playerid)
{
    switch(PlayerInfo[playerid][Profissao])
    {
        case unemployed:
            SetPlayerColor(playerid, color_unemployed);
        case newspaperdelivery:
            SetPlayerColor(playerid, color_newspaperdelivery);
        case icecream:
            SetPlayerColor(playerid, color_icecream);
        case pizzaboy:
            SetPlayerColor(playerid, color_pizzaboy);
        case gari:
            SetPlayerColor(playerid, color_gari);
        case paramedic:
            SetPlayerColor(playerid, color_paramedic);
        case light:
            SetPlayerColor(playerid, color_light);
        case lawyer:
            SetPlayerColor(playerid, color_lawyer);
        case taxi:
            SetPlayerColor(playerid, color_taxi);
        case tanker:
            SetPlayerColor(playerid, color_tanker);
        case loader:
            SetPlayerColor(playerid, color_loader);
        case strongcardriver:
            SetPlayerColor(playerid, color_strongcardriver);
        case strongcarsecurity:
            SetPlayerColor(playerid, color_strongcarsecurity);
        case military:
            SetPlayerColor(playerid, color_military);
        case federal:
            SetPlayerColor(playerid, color_federal);
        case delegate:
            SetPlayerColor(playerid, color_delegate);
        case fbi:
            SetPlayerColor(playerid, color_fbi);
        case cia:
            SetPlayerColor(playerid, color_cia);
        case swat:
            SetPlayerColor(playerid, color_swat);
        case narcoticos:
            SetPlayerColor(playerid, color_narcoticos);
        case interpol:
            SetPlayerColor(playerid, color_interpol);
        case internalaffairs:
            SetPlayerColor(playerid, color_internalaffairs);
        case navy:
            SetPlayerColor(playerid, color_navy);
        case army:
            SetPlayerColor(playerid, color_army);
        case aeronautics:
            SetPlayerColor(playerid, color_aeronautics);
        case potplanter:
            SetPlayerColor(playerid, color_potplanter);
        case burglar:
            SetPlayerColor(playerid, color_burglar);
        case thief:
            SetPlayerColor(playerid, color_burglar);
    }
    return 1;
}

stock GetPickUpProfission(playerid, pickupid)
{
    if(pickupid == AgenciaPickup[playerid] && PlayerInfo[playerid][Semprofissao] != 0)
    {
        SendClientMessage(playerid, Red, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Profissão ~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    	SendClientMessage(playerid, White, "•» Sejá bem vindo ao local de sua profissão");
    	SendClientMessage(playerid, White, "•» Digite: /Trabalhar para iniciar seus serviços nesta profissão");
        SendClientMessage(playerid, Red, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Profissão ~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        return 1;
    }
    return 1;
}

stock SetForwardedAgency(playerid, Float:x, Float:y, Float:z, profession, profissionlevel)
{
    if(PlayerInfo[playerid][Level] < profissionlevel)
        return SendClientMessage(playerid, Erro, "Você não tem level suficiente para pegar essa profissão");

    //Lefts Profissions
    Left_Pfs_NSD(playerid);
    Left_Pfs_Gari(playerid);
    Left_Pfs_PotPlanter(playerid);
    left_pfs_thief(playerid);

    if(IsPlayerProfisssionSkin(playerid)) SetPlayerSkin(playerid, PlayerInfo[playerid][skin]);

    if(AgenciaEncaminhado[playerid])
    {
        KillTimer(playerid);

        DestroyDynamic3DTextLabel(AgenciaLabel[playerid]);
        DestroyDynamicPickup(AgenciaPickup[playerid]);
        DestroyDynamicMapIcon(AgenciaMapIcon[playerid]);
    }

    AgenciaEncaminhado[playerid] = true;
    PlayerInfo[playerid][Profissao] = unemployed;
    PlayerInfo[playerid][Semprofissao] = profession;

    PlayerAgency[playerid][pa_profission] = PlayerInfo[playerid][Semprofissao];
    PlayerAgency[playerid][pa_x] = x;
    PlayerAgency[playerid][pa_y] = y;
    PlayerAgency[playerid][pa_z] = z;

    format(String, sizeof(String), "{FFFFFF}Profissão\n{FF8000}%s", NameProfission(PlayerAgency[playerid][pa_profission]));
    AgenciaLabel[playerid] = CreateDynamic3DTextLabel(String, 0xFFFFFFFF, PlayerAgency[playerid][pa_x], PlayerAgency[playerid][pa_y], PlayerAgency[playerid][pa_z], 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, -1, -1, playerid);
    AgenciaPickup[playerid] = CreateDynamicPickup(1210, 1, PlayerAgency[playerid][pa_x], PlayerAgency[playerid][pa_y], PlayerAgency[playerid][pa_z], -1, -1, playerid);
    AgenciaMapIcon[playerid] = CreateDynamicMapIcon(PlayerAgency[playerid][pa_x], PlayerAgency[playerid][pa_y], PlayerAgency[playerid][pa_z], 53, -1, -1, -1, playerid, -1.0, MAPICON_GLOBAL);

    SetColorProfession(playerid);
    PlayerPlaySound(playerid, 1057, 0, 0, 0);

    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{00C40A}Encaminhamento...", "{FFFFFF}Agora você está encaminhado, \n\nPara iniciar os serviços siga a bandeira {FF0000}Preta e Branca {FFFFFF}em seu radar", "Fechar", #);
    return 1;
}

stock GetForwardedAgency(playerid, profession)
{
    KillTimer(playerid);

    if(AgenciaEncaminhado[playerid])
    {
        DestroyDynamic3DTextLabel(AgenciaLabel[playerid]);
        DestroyDynamicPickup(AgenciaPickup[playerid]);
        DestroyDynamicMapIcon(AgenciaMapIcon[playerid]);
    }

    AgenciaEncaminhado[playerid] = false;
    PlayerInfo[playerid][Profissao] = profession;
    PlayerInfo[playerid][Semprofissao] = unemployed;

    PlayerAgency[playerid][pa_profission] = 0;
    PlayerAgency[playerid][pa_x] = 0;
    PlayerAgency[playerid][pa_y] = 0;
    PlayerAgency[playerid][pa_z] = 0;

    SetColorProfession(playerid);
    PlayerPlaySound(playerid, 1057, 0, 0, 0);

    new query[150];
    mysql_format(IDConexao, query, 150, "UPDATE `Identidade` SET `profissao`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][Profissao], PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);

    format(String, MAX_STRING, "Apartir de agora você ira exerce a profissão como %s", NameProfission(PlayerInfo[playerid][Profissao]));
    SendClientMessage(playerid, GetPlayerColor(playerid), String);
    SendClientMessage(playerid, GetPlayerColor(playerid), "Para saber os comandos da profissão, digite: /Profissao");
    return 1;
}

stock Salario(playerid)
{
    new salary[MAX_PLAYERS];

    switch(PlayerInfo[playerid][Profissao])
    {
        case unemployed: salary[playerid] = 150;
        case newspaperdelivery: salary[playerid] = 250;
        case icecream: salary[playerid] = 350;
        case pizzaboy: salary[playerid] = 400;
        case gari: salary[playerid] = 550;
        case paramedic: salary[playerid] = 850;
        case light: salary[playerid] = 1500;
        case lawyer: salary[playerid] = 1600;
        case taxi: salary[playerid] = 450;
        case tanker: salary[playerid] = 500;
        case loader: salary[playerid] = 750;
        case strongcardriver: salary[playerid] = 1000;
        case strongcarsecurity: salary[playerid] = 1500;
        case military: salary[playerid] = 1800;
        case federal: salary[playerid] = 2000;
        case delegate: salary[playerid] = 2200;
        case fbi: salary[playerid] = 2400;
        case cia: salary[playerid] = 2600;
        case swat: salary[playerid] = 2800;
        case narcoticos: salary[playerid] = 3000;
        case interpol: salary[playerid] = 3200;
        case internalaffairs: salary[playerid] = 4000;
        case navy: salary[playerid] = 4300;
        case army: salary[playerid] = 4600;
        case aeronautics: salary[playerid] = 5000;
        case potplanter..thief: salary[playerid] = 0;
    }

    PlayerInfo[playerid][SaldoBancario] += salary[playerid];

    SendClientMessage(playerid, 0xEDA909AA,"~~~~~~~~~~~~~~~~~~~~~~ Salário ~~~~~~~~~~~~~~~~~~~~~~");

    if(IsPlayerMafia(playerid))
        { SendClientMessage(playerid, Yellow, "| AVISO | Mafia não recebe Salário"); }

    if(IsPlayerVip(playerid))
        { SendClientMessage(playerid, 0xEDA909AA, "{EDA909}» {FFFFFF}Salário VIP: {00A600}$1.500"); }

    if(PlayerInfo[playerid][healthplan])
        { SendClientMessage(playerid, 0xEDA909AA, "{EDA909}» {FFFFFF}Plano de saúde: {FF0000}$-150"); }

    if(!IsPlayerMafia(playerid))
    {
        format(String,sizeof(String),"{EDA909}» {FFFFFF}Salário: {00A600}$%s", IsMoney(salary[playerid], "."));
        SendClientMessage(playerid, 0xEDA909AA, String);
    }

    format(String,sizeof(String),"{EDA909}» {FFFFFF}Balanço antigo: {FF0000}$%s", IsMoney(PlayerInfo[playerid][SaldoBancario] - salary[playerid], "."));
    SendClientMessage(playerid, 0xEDA909AA, String);

    if(PlayerInfo[playerid][healthplan])
        { PlayerInfo[playerid][SaldoBancario] -= 150; }

    if(IsPlayerVip(playerid))
        { PlayerInfo[playerid][SaldoBancario] += 1500; }

    format(String,sizeof(String),"{EDA909}» {FFFFFF}Balanço atual: {00A600}$%s", IsMoney(PlayerInfo[playerid][SaldoBancario], "."));
    SendClientMessage(playerid, 0xEDA909AA, String);
    SendClientMessage(playerid, 0xEDA909AA,"~~~~~~~~~~~~~~~~~~~~~~ Salário ~~~~~~~~~~~~~~~~~~~~~~");

    PlayerPlaySound(playerid, 1057, 0, 0, 0);
    EntregouMercadoria[playerid] = false;

    new query[200];
    mysql_format(IDConexao, query, sizeof(query), "UPDATE `Identidade` SET `saldobancario`='%d' WHERE `id_contas`='%d'",
    PlayerInfo[playerid][SaldoBancario],
    PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);
    return 1;
}

stock IsPlayerMafia(playerid)
{
    switch(PlayerInfo[playerid][Profissao])
    {
        case potplanter..thief: return 1;
        default: return 0;
    }
    return 1;
}

stock IsPlayerProfisssionSkin(playerid)
{
    if(IsPlayerUniformPM(playerid)  ||
    GetPlayerSkin(playerid) == 155  ||
    GetPlayerSkin(playerid) == 16   ||
    IsPlayerUniformParamedic(playerid)) return 1; else return 0;
}

stock CreateVehicleLocation(Float:x, Float:y, Float:z)
{
    CreateDynamicPickup(1239, 1, x, y, z, -1, -1, -1, 200.0);
    CreateDynamic3DTextLabel("{FFFFFF}Precione {FF0000}Y{FFFFFF} e crie um\nveículo profissão", 0xFFFFFFFF, x, y, z, 200.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
    return 1;
}

stock GiveBonus(playerid, value = 500)
{
    if((random(10) % 2) != 0) return 0;

    new rand = random(value);

    if(rand < 100) return GiveBonus(playerid);

    format(String, MAX_STRING, "Você ganhou um bonus de {1B6302}$%d", rand);
    SendClientMessage(playerid, White, String);

    PlayerInfo[playerid][Dinheiro] += rand;
    UpdatePlayerMoney(playerid);
    return 1;
}
