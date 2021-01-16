#include YSI\y_hooks

enum e_rsmine
{
    Float:rsmine_x,
    Float:rsmine_y,
    Float:rsmine_z
};

new RandomSpawnMinerals[5][e_rsmine] =
{
    {836.42, 866.81, 14.82},
    {842.26, 869.80, 14.82},
    {847.95, 872.86, 14.82},
    {853.83, 876.35, 14.82},
    {859.72, 879.69, 14.82}
};

enum e_rn
{
    Float:rn_x,
    Float:rn_y,
    Float:rn_z
};

new Refinery[5][e_rn] =
{
    {2575.35, 2781.12, 10.82},
    {234.72, 1415.51, 10.58},
    {2490.67, -2089.40, 13.54},
    {-1883.09, -1726.48, 21.75},
    {-1821.50, 2.74, 15.11}
};

new mineralsCount[MAX_PLAYERS];
new mineralsCP[MAX_PLAYERS];
new mineralsRefineryID[MAX_PLAYERS];

hook OnGameModeInit()
{
    CreateVehicleLocation(829.19, 859.44, 12.42);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    mineralsRefineryID[playerid] = -1;
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(PRESSED(KEY_YES))
	{
        if(!IsPlayerInRangeOfPoint(playerid, 2.0, 829.19, 859.44, 12.42))
            return 1;

        if(PlayerInfo[playerid][Profissao] != minerals)
            return SendClientMessage(playerid, Erro, "Você não tem permissão");

        if(PV_Profission[playerid])
            return SendClientMessage(playerid, Erro, "Seu veículo já está criado");

        new rand = random(sizeof(RandomSpawnMinerals));

        CreatePlayerVehicle(playerid, 524, RandomSpawnMinerals[rand][rsmine_x], RandomSpawnMinerals[rand][rsmine_y], RandomSpawnMinerals[rand][rsmine_z], 180.00, -1, -1);

        SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Foi criado um veículo profissão no estacionamento");
        return 1;
	}
	return 1;
}


hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == minerals_load && response)
    {
        if(!IsPlayerInAnyVehicle(playerid))
            return SendClientMessage(playerid, Erro, "Você não está em um Cement Truck");

        if(GetVehicleModel(GetPlayerVehicleID(playerid)) != 524)
            return SendClientMessage(playerid, Erro, "Você não está em um Cement Truck");

        new vehicleid = getPlayerVehicleID(playerid);

        if(vehicleid == INVALID_VEHICLE_ID)
            return 0;

        LoadOrDownload(playerid, vehicleid, true);

        DestroyDynamicRaceCP(mineralsCP[playerid]);
        mineralsCP[playerid] = CreateDynamicRaceCP(0, Refinery[listitem][rn_x], Refinery[listitem][rn_y], Refinery[listitem][rn_z], -1, -1, -1, 5.0, -1, -1, playerid, -1.0);
        mineralsCount[playerid] = 2;
        mineralsRefineryID[playerid] = listitem;

        SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Local escolhido, vá até á marcação vermelha em seu mini-mapa para descarregar");
        return 1;
    }
    return 1;
}

stock CMD_MineralsCarregar(playerid)
{
    if(PlayerInfo[playerid][Profissao] != minerals)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsPlayerInRangeOfPoint(playerid, 50.0, 829.19, 859.44, 12.42))
        return SendClientMessage(playerid, Erro, "Você não está no local de trabalho");

    if(!IsPlayerInAnyVehicle(playerid))
        return SendClientMessage(playerid, Erro, "Você não está em um Cement Truck");

    if(GetVehicleModel(GetPlayerVehicleID(playerid)) != 524)
        return SendClientMessage(playerid, Erro, "Você não está em um Cement Truck");

    new vehicleid = getPlayerVehicleID(playerid);

    if(vehicleid == INVALID_VEHICLE_ID)
        return 0;

    if(mineralsCount[playerid])
        return SendClientMessage(playerid, Erro, "Carregamento já iniciado, termine-o");

    SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Vá até à marcação vermelha em seu mini-mapa para completar o carregamento...");

    mineralsCount[playerid] = 1;
    mineralsCP[playerid] = CreateDynamicRaceCP(0, 555.32, 904.96, -42.96, -1, -1, -1, 5.0, -1, -1, playerid, -1.0);
    return 1;
}

stock Minerals_DynamicRaceCP(playerid)
{
    if(PlayerInfo[playerid][Profissao] == minerals)
    {
        new vehicleid = getPlayerVehicleID(playerid);

        if(vehicleid == INVALID_VEHICLE_ID)
            return 0;

        if(!IsPlayerInAnyVehicle(playerid))
            return SendClientMessage(playerid, Erro, "Você não está em um Cement Truck");

        if(GetVehicleModel(PublicVehicle[vehicleid][pv_vehicle]) != 524)
            return SendClientMessage(playerid, Erro, "Você não está em um Cement Truck");

        switch(mineralsCount[playerid])
        {
            case 1:
            {
                new txt[500];

                strcat(txt, (IsPlayerMobile(playerid) ? (#) : ("{FFFFFF}Localidade\t {00FF00}Recompensa \n")));

                for(new i = 0; i < sizeof(Refinery); i++)
                {
                    new value = GetMoneyByDistance(playerid, Refinery[i][rn_x], Refinery[i][rn_y], Refinery[i][rn_z]);

                    GetPlayer2DZone(zone, MAX_ZONE_NAME, Refinery[i][rn_x], Refinery[i][rn_y]);

                    format(String, 100, "{FFFFFF}%s\t {00FF00}$%s \n", zone, IsMoney(value, "."));
                    strcat(txt, String);
                }

                ShowPlayerDialog(playerid, minerals_load, (IsPlayerMobile(playerid) ? DIALOG_STYLE_LIST : DIALOG_STYLE_TABLIST_HEADERS), "{FF0000}Refinarias", txt, "Escolher", "Cancelar");
                return 1;
            }
            case 2:
            {
                if(mineralsRefineryID[playerid] == -1) return 0;

                LoadOrDownload(playerid, vehicleid, false);
                DestroyDynamicRaceCP(mineralsCP[playerid]);

                new refineryid = mineralsRefineryID[playerid];
                new value = GetMoneyByDistance(playerid, 555.32, 904.96, -42.96);
                new zoneLocal[MAX_ZONE_NAME];

                PlayerInfo[playerid][Dinheiro] += value;
                UpdatePlayerMoney(playerid);

                GetPlayer2DZone(zoneLocal, MAX_ZONE_NAME, Refinery[refineryid][rn_x], Refinery[refineryid][rn_y]);

                format(String, MAX_STRING, "Muito bom %s, seu veículo descarregado na localidade ( %s )", PlayerInfo[playerid][Nome], zoneLocal);
                SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);
                format(String, MAX_STRING, "Como recompensa você recebeu em mãos $%s", IsMoney(value, "."));
                SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);

                mineralsRefineryID[playerid] = -1;
                mineralsCP[playerid] = 0;
                mineralsCount[playerid] = 0;
                return 1;
            }
            default:
                return 0;
        }

        return 1;
    }
    return 1;
}

stock GetMoneyByDistance(playerid, Float:x, Float:y, Float:z, Float:media = 0.6)
{
    new Float:distance = GetPlayerDistanceFromPoint(playerid, x, y, z);

    return (floatround( ( distance * media ), floatround_round));
}

stock LeftPfsMinerals(playerid)
{
    if(PlayerInfo[playerid][Profissao] == minerals)
    {
        if(mineralsCount[playerid]){
            DestroyDynamicRaceCP(mineralsCP[playerid]);
            mineralsCount[playerid] = 0;
            mineralsCP[playerid] = 0;
        }

        mineralsRefineryID[playerid] = -1;
    }
    return 1;
}
