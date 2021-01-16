#include YSI\y_hooks

#define MAX_PLACE_PILOT 3

enum e_rsp
{
    Float:rsp_x,
    Float:rsp_y,
    Float:rsp_z
};

new RandomSpawnPilot[3][e_rsp] =
{
    {1906.00, -2622.00, 16.10},
    {1890.00, -2622.00, 16.10},
    {1874.00, -2622.00, 16.10}
};

new pilotCP[MAX_PLAYERS];
new pilotCount[MAX_PLAYERS];
new pilotTime[MAX_PLAYERS];

hook OnGameModeInit()
{
    CreateVehicleLocation(1914.50, -2633.60, 13.54);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(PRESSED(KEY_YES))
	{
        if(!IsPlayerInRangeOfPoint(playerid, 2.0, 1914.50, -2633.60, 13.54))
            return 1;

        if(PlayerInfo[playerid][Profissao] != pilot)
            return SendClientMessage(playerid, Erro, "Você não tem permissão");

        if(PV_Profission[playerid])
            return SendClientMessage(playerid, Erro, "Seu veículo já está criado");

        SetPlayerSkin(playerid, 253);

        new rand = random(sizeof(RandomSpawnPilot));

        CreatePlayerVehicle(playerid, 593, RandomSpawnPilot[rand][rsp_x], RandomSpawnPilot[rand][rsp_y], RandomSpawnPilot[rand][rsp_z], 0.00, -1, -1);

        SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Foi criado um veículo profissão no estacionamento");
        return 1;
	}
	return 1;
}

forward OnPlayerLoadingPilot(playerid);
public OnPlayerLoadingPilot(playerid)
{
    pilotTime[playerid] = gettime();
    pilotCount[playerid] = 1;

    new coountid = pilotCount[playerid];

    TogglePlayerControllable(playerid, true);
    pilotCP[playerid] = CreateDynamicRaceCP((pilotCount[playerid] == (MAX_PLACE_LOADER - 1) ? 1 : 0 ), loader_place[coountid][lp_x], loader_place[coountid][lp_y], loader_place[coountid][lp_z], loader_place[coountid + 1][lp_x], loader_place[coountid + 1][lp_y], loader_place[coountid + 1][lp_z], 5.0, -1, -1, playerid, -1.0);

    SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Veículo carregado, vá até a marcação vermelha em seu mini-mapa");
    return 1;
}

forward OnPlayerDowloadPilot(playerid);
public OnPlayerDowloadPilot(playerid)
{
    new value = RandomValuePilot();

    GiveBonus(playerid, 500);
    PlayerInfo[playerid][Dinheiro] += value;
    UpdatePlayerMoney(playerid);

    format(String, MAX_STRING, "Você recebeu $%s pelo serviço", IsMoney(value, "."));
    SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Serviço finalizado, volte para o LT e carregue novamente");
    SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);

    PlayerPlaySound(playerid, 1058, 0.0, 0.0, 0.0);
    DestroyDynamicRaceCP(pilotCP[playerid]);
    pilotCount[playerid] = 0;
    pilotTime[playerid] = 0;
    pilotCP[playerid] = 0;

    TogglePlayerControllable(playerid, true);
    return 1;
}

stock pilotDynamicRaceCP(playerid)
{
    if(PlayerInfo[playerid][Profissao] != pilot)
        return 0;

    if(!IsPlayerInAnyVehicle(playerid))
        return SendClientMessage(playerid, Erro, "Você não está em um Dodo");

    if(GetVehicleModel(GetPlayerVehicleID(playerid)) != 593)
        return SendClientMessage(playerid, Erro, "Você não está em um Dodo");

    switch(pilotCount[playerid])
    {
        case (MAX_PLACE_PILOT - 1):
        {
            if((gettime() - pilotTime[playerid]) < 180)
                return SendClientMessage(playerid, Erro, "Você chegou muito rápido(a), aguarde alguns segundos...");

            new vehicleid = getPlayerVehicleID(playerid);

            LoadOrDownload(playerid, vehicleid, false);
            TogglePlayerControllable(playerid, false);
            GameTextForPlayer(playerid, "~r~Finalizando...", 2000, 3);
            SetTimerEx("OnPlayerDowloadPilot", 2000, false, "d", playerid);
            return 1;
        }
        default:
        {
            pilotCount[playerid]++;

            new coountid = pilotCount[playerid];

            GetPlayer2DZone(zone, MAX_ZONE_NAME, loader_place[coountid - 1][lp_x], loader_place[coountid - 1][lp_y]);
            format(String, MAX_STRING, "Mercadoria descarregada no Aeroporto de %s, agora vá para o próximo", zone);
            SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);

            PlayerPlaySound(playerid, 1057, 0.0, 0.0, 0.0);
            DestroyDynamicRaceCP(pilotCP[playerid]);
            pilotCP[playerid] = CreateDynamicRaceCP((pilotCount[playerid] == MAX_PLACE_LOADER ? 1 : 0 ), loader_place[coountid][lp_x], loader_place[coountid][lp_y], loader_place[coountid][lp_z], loader_place[coountid + 1][lp_x], loader_place[coountid + 1][lp_y], loader_place[coountid + 1][lp_z], 5.0, -1, -1, playerid, -1.0);
        }
    }
    return 1;
}

stock RandomValuePilot()
{
    new value = random(5000);

    if(value < 3000) return RandomValuePilot();

    return value;
}

stock LeftPfsPilot(playerid)
{
    if(PlayerInfo[playerid][Profissao] != woods)
        return 0;

    if(!pilotTime[playerid])
        return 0;

    DestroyDynamicRaceCP(pilotCP[playerid]);
    pilotCount[playerid] = 0;
    pilotTime[playerid] = 0;
    pilotCP[playerid] = 0;
    return 1;
}

/******************************************************************************/
/*****************************| COMMANDS PILOTO |******************************/
/******************************************************************************/

stock CMD_PilotCarregar(playerid)
{
    if(PlayerInfo[playerid][Profissao] != pilot)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsPlayerInRangeOfPoint(playerid, 200.0, 1914.50, -2633.60, 13.54))
        return SendClientMessage(playerid, Erro, "Você não está no Local de Trabalho");

    if(!IsPlayerInAnyVehicle(playerid))
        return SendClientMessage(playerid, Erro, "Você não está em um Dodo");

    if(GetVehicleModel(GetPlayerVehicleID(playerid)) != 593)
        return SendClientMessage(playerid, Erro, "Você não está em um Dodo");

    new vehicleid = getPlayerVehicleID(playerid);

    if(PublicVehicle[vehicleid][pv_loaded])
        return SendClientMessage(playerid, Erro, "Seu veículo já está carregado");

    LoadOrDownload(playerid, vehicleid, true);
    TogglePlayerControllable(playerid, false);
    GameTextForPlayer(playerid, "~r~Carregando...", 2000, 3);
    SetTimerEx("OnPlayerLoadingPilot", 2000, false, "d", playerid);
    return 1;
}
