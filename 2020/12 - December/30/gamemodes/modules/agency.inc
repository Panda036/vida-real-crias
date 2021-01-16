#include YSI\y_hooks

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

hook OnPlayerDisconnect(playerid, reason)
{
    if(AgenciaEncaminhado[playerid])
    {
        AgenciaEncaminhado[playerid] = false;
        if(IsValidDynamic3DTextLabel(AgenciaLabel[playerid])) DestroyDynamic3DTextLabel(AgenciaLabel[playerid]);
        if(IsValidDynamicPickup(AgenciaPickup[playerid])) DestroyDynamicPickup(AgenciaPickup[playerid]);
        if(IsValidDynamicMapIcon(AgenciaMapIcon[playerid])) DestroyDynamicMapIcon(AgenciaMapIcon[playerid]);
    }
	return 1;
}

stock Agency_Checkpoint(playerid)
{
    if(IsPlayerInDynamicCP(playerid, cp_mafia[0]) || IsPlayerInDynamicCP(playerid, cp_mafia[1]) || IsPlayerInDynamicCP(playerid, cp_mafia[2]))
    {
        new txt[500];

        strcat(txt, (IsPlayerMobile(playerid) ? (#) : ("{FFFFFF}Profissão\n")));

        strcat(txt, "{FFFFFF}Plantador de Cannabis\n");
        strcat(txt, "{FFFFFF}Produtor de Armas\n");
        strcat(txt, "{FFFFFF}Ladrão\n");

        ShowPlayerDialog(playerid, mob, (IsPlayerMobile(playerid) ? DIALOG_STYLE_LIST : DIALOG_STYLE_TABLIST_HEADERS), "{FF0000}Menu Cargos", txt, "Selecionar", "Voltar");
        return 1;
    }

    if(IsPlayerInDynamicCP(playerid, cp_agencia))
    {
        new txt[200];

        strcat(txt, (IsPlayerMobile(playerid) ? (#) : ("{FFFFFF}Classes \n")));

        strcat(txt, "{80FF80}Honesta \n");
        strcat(txt, "{80FFFF}Transporte \n");
        strcat(txt, "{51A8FF}Policia \n");
        strcat(txt, "{626262}Governo \n");

        ShowPlayerDialog(playerid, agency, (IsPlayerMobile(playerid) ? DIALOG_STYLE_LIST : DIALOG_STYLE_TABLIST_HEADERS), "{FF0000}Menu Empregos", txt, "Selecionar", "Fechar");
        return 1;
    }
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case agency:
        {
            if(!response) return 0;

            switch(listitem)
            {
                case 0:
                {
                    new txt[500];

                    strcat(txt, (IsPlayerMobile(playerid) ? (#) : ("{FFFFFF}Profissão\t {00C40A}Salário\n")));

                    strcat(txt, "{FFFFFF}Entregador de Jornais\t {00C40A}$250\n");
                    strcat(txt, "{FFFFFF}PizzaBoy\t {00C40A}$400\n");
                    strcat(txt, "{FFFFFF}MotoBoy\t {00C40A}$650\n");
                    strcat(txt, "{FFFFFF}Gari\t {00C40A}$700\n");
                    strcat(txt, "{FFFFFF}Mecânico(a)\t {00C40A}$850\n");
                    strcat(txt, "{FFFFFF}Paramédico(a)\t {00C40A}$950\n");
                    strcat(txt, "{FFFFFF}Técnico(a) da Light\t {00C40A}$1.500\n");
                    strcat(txt, "{FFFFFF}Advogado(a)\t {00C40A}$1.600\n");

                    ShowPlayerDialog(playerid, honest, (IsPlayerMobile(playerid) ? DIALOG_STYLE_LIST : DIALOG_STYLE_TABLIST_HEADERS), "{80FF80}Honesta", txt, "Selecionar", "Voltar");
                    return 1;
                }
                case 1:
                {
                    new txt[400];

                    strcat(txt, (IsPlayerMobile(playerid) ? (#) : ("{FFFFFF}Profissão\t {00C40A}Salário\n")));

                    strcat(txt, "{FFFFFF}Taxi\t {00C40A}$450\n");
                    strcat(txt, "{FFFFFF}Petroleiro\t {00C40A}$500\n");
                    strcat(txt, "{FFFFFF}Taxi Aério\t {00C40A}$650\n");
                    strcat(txt, "{FFFFFF}Carregador\t {00C40A}$750\n");
                    strcat(txt, "{FFFFFF}Transportador(a) de Minérios\t {00C40A}$850\n");
                    strcat(txt, "{FFFFFF}Transportador(a) de Madeiras\t {00C40A}$950\n");
                    strcat(txt, "{FFFFFF}Motorista de Carro Forte\t {00C40A}$1.000\n");
                    strcat(txt, "{FFFFFF}Piloto\t {00C40A}$1.200\n");

                    ShowPlayerDialog(playerid, transport, (IsPlayerMobile(playerid) ? DIALOG_STYLE_LIST : DIALOG_STYLE_TABLIST_HEADERS), "{80FFFF}Transporte", txt, "Selecionar", "Voltar");
                    return 1;
                }
                case 2:
                {
                    new txt[600];

                    strcat(txt, (IsPlayerMobile(playerid) ? (#) : ("{FFFFFF}Profissão\t {FF0000}Level\t {00C40A}Salário\n")));

                    strcat(txt, "{FFFFFF}Segurança de Carro Forte\t {F71616}40\t {00C40A}$500\n");
                    strcat(txt, "{FFFFFF}Guarda Municipal\t {F71616}50\t {00C40A}$1.500\n");
                    strcat(txt, "{FFFFFF}Policia Militar\t {F71616}100\t {00C40A}$1.800\n");
                    strcat(txt, "{FFFFFF}Policia Federal\t {F71616}200\t {00C40A}$2.000\n");
                    strcat(txt, "{FFFFFF}Delegado\t {F71616}300\t {00C40A}$2.200\n");
                    strcat(txt, "{FFFFFF}FBI\t {F71616}400\t {00C40A}$2.400\n");
                    strcat(txt, "{FFFFFF}CIA\t {F71616}500\t {00C40A}$2.600\n");
                    strcat(txt, "{FFFFFF}S.W.A.T\t {F71616}600\t {00C40A}$2.800\n");
                    strcat(txt, "{FFFFFF}Nacórticos\t {F71616}700\t {00C40A}$3.000\n");
                    strcat(txt, "{FFFFFF}Interpol\t {F71616}800\t {00C40A}$3.200\n");

                    ShowPlayerDialog(playerid, police, (IsPlayerMobile(playerid) ? DIALOG_STYLE_LIST : DIALOG_STYLE_TABLIST_HEADERS), "{51A8FF}Policia", txt, "Selecionar", "Voltar");
                    return 1;
                }
                case 3:
                {
                    new txt[300];

                    strcat(txt, (IsPlayerMobile(playerid) ? (#) : ("{FFFFFF}Profissão\t {FF0000}Level\t {00C40A}Salário\n")));

                    strcat(txt, "{FFFFFF}Corregedoria\t {F71616}1000\t {00C40A}$4.000\n");
                    strcat(txt, "{FFFFFF}Marinha\t {F71616}1100\t {00C40A}$4.300\n");
                    strcat(txt, "{FFFFFF}Exército\t {F71616}1200\t {00C40A}$4.600\n");
                    strcat(txt, "{FFFFFF}Aeronáutica\t {F71616}1300\t {00C40A}$5.000\n");

                    ShowPlayerDialog(playerid, government, (IsPlayerMobile(playerid) ? DIALOG_STYLE_LIST : DIALOG_STYLE_TABLIST_HEADERS), "{626262}Governo", txt, "Selecionar", "Voltar");
                    return 1;
                }
            }
            return 1;
        }
        case mob:
        {
            if(!response) return 1;

            switch(listitem)
            {
                case 0: SetForwardedAgency(playerid, potplanter);
                case 1: SetForwardedAgency(playerid, weaponproducer);
                case 2: SetForwardedAgency(playerid, thief);
            }
            return 1;
        }
        case honest:
        {
            if(!response)
            {
                new txt[200];

                strcat(txt, (IsPlayerMobile(playerid) ? (#) : ("{FFFFFF}Classes \n")));

                strcat(txt, "{80FF80}Honesta \n");
                strcat(txt, "{80FFFF}Transporte \n");
                strcat(txt, "{51A8FF}Policia \n");
                strcat(txt, "{626262}Governo \n");

                ShowPlayerDialog(playerid, agency, (IsPlayerMobile(playerid) ? DIALOG_STYLE_LIST : DIALOG_STYLE_TABLIST_HEADERS), "{FF0000}Menu Empregos", txt, "Selecionar", "Fechar");
                return 1;
            }

            switch(listitem)
            {
                case 0: SetForwardedAgency(playerid, newspaperdelivery);
                case 1: SetForwardedAgency(playerid, pizzaboy);
                case 2: SetForwardedAgency(playerid, motoboy, true);
                case 3: SetForwardedAgency(playerid, gari);
                case 4: SetForwardedAgency(playerid, mechanical);
                case 5: SetForwardedAgency(playerid, paramedic);
                case 6: SetForwardedAgency(playerid, light);
                case 7: SetForwardedAgency(playerid, lawyer);
            }
            return 1;
        }
        case transport:
        {
            if(!response)
            {
                new txt[200];

                strcat(txt, (IsPlayerMobile(playerid) ? (#) : ("{FFFFFF}Classes \n")));

                strcat(txt, "{80FF80}Honesta \n");
                strcat(txt, "{80FFFF}Transporte \n");
                strcat(txt, "{51A8FF}Policia \n");
                strcat(txt, "{626262}Governo \n");

                ShowPlayerDialog(playerid, agency, (IsPlayerMobile(playerid) ? DIALOG_STYLE_LIST : DIALOG_STYLE_TABLIST_HEADERS), "{FF0000}Menu Empregos", txt, "Selecionar", "Fechar");
                return 1;
            }

            switch(listitem)
            {
                case 0: SetForwardedAgency(playerid, taxi);
                case 1: SetForwardedAgency(playerid, tanker);
                case 2: SetForwardedAgency(playerid, taxiair);
                case 3: SetForwardedAgency(playerid, loader);
                case 4: SetForwardedAgency(playerid, minerals);
                case 5: SetForwardedAgency(playerid, woods);
                case 6: SetForwardedAgency(playerid, strongcardriver);
                case 7: SetForwardedAgency(playerid, pilot);
            }
            return 1;
        }
        case police:
        {
            if(!response)
            {
                new txt[200];

                strcat(txt, (IsPlayerMobile(playerid) ? (#) : ("{FFFFFF}Classes \n")));

                strcat(txt, "{80FF80}Honesta \n");
                strcat(txt, "{80FFFF}Transporte \n");
                strcat(txt, "{51A8FF}Policia \n");
                strcat(txt, "{626262}Governo \n");

                ShowPlayerDialog(playerid, agency, (IsPlayerMobile(playerid) ? DIALOG_STYLE_LIST : DIALOG_STYLE_TABLIST_HEADERS), "{FF0000}Menu Empregos", txt, "Selecionar", "Fechar");
                return 1;
            }

            switch(listitem)
            {
                case 0: SetForwardedAgency(playerid, strongcarsecurity);
                case 1: SetForwardedAgency(playerid, municipalguard);
                case 2: SetForwardedAgency(playerid, military);
                case 3: SetForwardedAgency(playerid, federal);
                case 4: SetForwardedAgency(playerid, delegate);
                case 5: SetForwardedAgency(playerid, fbi);
                case 6: SetForwardedAgency(playerid, cia);
                case 7: SetForwardedAgency(playerid, swat);
                case 8: SetForwardedAgency(playerid, narcoticos);
                case 9: SetForwardedAgency(playerid, interpol);
            }
            return 1;
        }
        case government:
        {
            if(!response)
            {
                new txt[200];

                strcat(txt, (IsPlayerMobile(playerid) ? (#) : ("{FFFFFF}Classes \n")));

                strcat(txt, "{80FF80}Honesta \n");
                strcat(txt, "{80FFFF}Transporte \n");
                strcat(txt, "{51A8FF}Policia \n");
                strcat(txt, "{626262}Governo \n");

                ShowPlayerDialog(playerid, agency, (IsPlayerMobile(playerid) ? DIALOG_STYLE_LIST : DIALOG_STYLE_TABLIST_HEADERS), "{FF0000}Menu Empregos", txt, "Selecionar", "Fechar");
                return 1;
            }

            switch(listitem)
            {
                case 0: SetForwardedAgency(playerid, internalaffairs);
                case 1: SetForwardedAgency(playerid, navy);
                case 2: SetForwardedAgency(playerid, army);
                case 3: SetForwardedAgency(playerid, aeronautics);
            }
            return 1;
        }
    }
    return 1;
}

stock SetColorProfession(playerid)
{
    SetPlayerColor(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color]);
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

stock LeftProfission(playerid)
{
    if(PV_Profission[playerid]) DestroyPlayerVehicle(playerid);

    LeftPfsNewspaperDelivery(playerid);
    LeftPfsMotoboy(playerid);
    LeftPfsGari(playerid);
    LeftPfsLight(playerid);
    LeftPfsLoader(playerid);
    LeftPfsMinerals(playerid);
    LeftPfsWoods(playerid);
    LeftPfsPilot(playerid);
    LeftPfsPotPlanter(playerid);
    LeftPfsThief(playerid);
    return 1;
}

stock SetForwardedAgency(playerid, profession, bool:location = false)
{
    if(PlayerInfo[playerid][Level] < Profission[profession][pfs_level])
        return SendClientMessage(playerid, Erro, "Você não tem level suficiente para pegar essa profissão");

    LeftProfission(playerid);

    if(AgenciaEncaminhado[playerid])
    {
        if(IsValidDynamic3DTextLabel(AgenciaLabel[playerid])) DestroyDynamic3DTextLabel(AgenciaLabel[playerid]);
        if(IsValidDynamicPickup(AgenciaPickup[playerid])) DestroyDynamicPickup(AgenciaPickup[playerid]);
        if(IsValidDynamicMapIcon(AgenciaMapIcon[playerid])) DestroyDynamicMapIcon(AgenciaMapIcon[playerid]);
    }

    AgenciaEncaminhado[playerid] = true;
    PlayerInfo[playerid][Profissao] = unemployed;
    PlayerInfo[playerid][Semprofissao] = profession;

    SetPlayerSkin(playerid, PlayerInfo[playerid][skin]);
    SetColorProfession(playerid);
    PlayerPlaySound(playerid, 1057, 0, 0, 0);

    if(location)
        return GetForwardedAgency(playerid, PlayerInfo[playerid][Semprofissao]);

    AgenciaLabel[playerid] = CreateDynamic3DTextLabel("{FFFFFF}Encaminhamento\n{FF8000}Agência", 0xFFFFFFFF, Profission[profession][pfs_x], Profission[profession][pfs_y], Profission[profession][pfs_z], 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, -1, -1, playerid);
    AgenciaPickup[playerid] = CreateDynamicPickup(1210, 1, Profission[profession][pfs_x], Profission[profession][pfs_y], Profission[profession][pfs_z], -1, -1, playerid);
    AgenciaMapIcon[playerid] = CreateDynamicMapIcon(Profission[profession][pfs_x], Profission[profession][pfs_y], Profission[profession][pfs_z], 53, -1, -1, -1, playerid, -1.0, MAPICON_GLOBAL);

    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{00C40A}Encaminhamento...", "{FFFFFF}Agora você está encaminhado, \n\nPara iniciar os serviços siga a bandeira {FF0000}Preta e Branca {FFFFFF}em seu radar", "Fechar", #);
    return 1;
}

stock GetForwardedAgency(playerid, profession)
{
    if(!AgenciaEncaminhado[playerid]) return 0;

    AgenciaEncaminhado[playerid] = false;
    if(IsValidDynamic3DTextLabel(AgenciaLabel[playerid])) DestroyDynamic3DTextLabel(AgenciaLabel[playerid]);
    if(IsValidDynamicPickup(AgenciaPickup[playerid])) DestroyDynamicPickup(AgenciaPickup[playerid]);
    if(IsValidDynamicMapIcon(AgenciaMapIcon[playerid])) DestroyDynamicMapIcon(AgenciaMapIcon[playerid]);

    PlayerInfo[playerid][Profissao] = profession;
    PlayerInfo[playerid][Semprofissao] = unemployed;

    SetColorProfession(playerid);
    PlayerPlaySound(playerid, 1057, 0, 0, 0);

    SetIntQuery(playerid, "Identidade", "profissao", PlayerInfo[playerid][Profissao]);

    SendClientMessage(playerid, GetPlayerColor(playerid), "Agora você está exercendo a profissão");
    SendClientMessage(playerid, GetPlayerColor(playerid), "Para saber os comandos da profissão, digite: /Profissao");
    return 1;
}

stock Salario(playerid)
{
    new salary = Profission[PlayerInfo[playerid][Profissao]][pfs_salary];

    PlayerInfo[playerid][SaldoBancario] += salary;

    SendClientMessage(playerid, 0xEDA909AA,"~~~~~~~~~~~~~~~~~~~~~~ Salário ~~~~~~~~~~~~~~~~~~~~~~");

    if(IsPlayerMafia(playerid))
        SendClientMessage(playerid, Yellow, "AVISO ~ Mafia não recebe Salário");

    if(IsPlayerVip(playerid))
        SendClientMessage(playerid, 0xEDA909AA, "{EDA909}» {FFFFFF}Salário VIP: {00A600}$1.500");

    if(PlayerInfo[playerid][healthplan])
        SendClientMessage(playerid, 0xEDA909AA, "{EDA909}» {FFFFFF}Plano de saúde: {FF0000}$-150");

    if(!IsPlayerMafia(playerid)){
        format(String, MAX_STRING, "{EDA909}» {FFFFFF}Salário: {00A600}$%s", IsMoney(salary, "."));
        SendClientMessage(playerid, 0xEDA909AA, String);
    }

    format(String, MAX_STRING, "{EDA909}» {FFFFFF}Balanço antigo: {FF0000}$%s", IsMoney(PlayerInfo[playerid][SaldoBancario] - salary, "."));
    SendClientMessage(playerid, 0xEDA909AA, String);

    if(PlayerInfo[playerid][healthplan])
        PlayerInfo[playerid][SaldoBancario] -= 150;

    if(IsPlayerVip(playerid))
        PlayerInfo[playerid][SaldoBancario] += 1500;

    format(String, MAX_STRING,"{EDA909}» {FFFFFF}Balanço atual: {00A600}$%s", IsMoney(PlayerInfo[playerid][SaldoBancario], "."));
    SendClientMessage(playerid, 0xEDA909AA, String);
    SendClientMessage(playerid, 0xEDA909AA,"~~~~~~~~~~~~~~~~~~~~~~ Salário ~~~~~~~~~~~~~~~~~~~~~~");

    PlayerPlaySound(playerid, 1057, 0, 0, 0);
    EntregouMercadoria[playerid] = false;

    SetIntQuery(playerid, "Identidade", "saldobancario", PlayerInfo[playerid][SaldoBancario]);
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
    new skin = GetPlayerSkin(playerid);

    if(IsPlayerUniformPM(playerid) || skin == 155 || skin == 16 || IsPlayerUniformParamedic(playerid)) return 1;

    return 0;
}

stock CreateVehicleLocation(Float:x, Float:y, Float:z)
{
    CreateDynamicPickup(1239, 1, x, y, z, -1, -1, -1, 200.0);
    CreateDynamic3DTextLabel("{FFFFFF}Precione {FF0000}Y{FFFFFF}\nCriar Veículo", 0xFFFFFFFF, x, y, z, 200.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
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

