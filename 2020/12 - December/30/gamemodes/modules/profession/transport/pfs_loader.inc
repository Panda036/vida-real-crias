#include YSI\y_hooks

#define MAX_PLACE_LOADER 4

enum e_vrl
{
    Float:vrl_x,
    Float:vrl_y,
    Float:vrl_z
};

new vr_loader[6][e_vrl] =
{
    {2490.17, -2108.64, 13.54},
    {2484.73, -2108.50, 13.54},
    {2479.31, -2108.42, 13.54},
    {2503.50, -2109.06, 13.54},
    {2509.16, -2109.14, 13.54},
    {2514.84, -2109.28, 13.54}
};

enum e_lp
{
    Float:lp_x,
    Float:lp_y,
    Float:lp_z,
};

new loader_place[MAX_PLACE_LOADER][e_lp] =
{
    {1989.50, -2313.11, 13.54},
    {1301.84, 1360.43, 10.82},
    {-1327.12, -529.23, 14.14},
    {-2431.95, 2290.99, 4.98}
};

new loader_cp[MAX_PLAYERS];
new loader_count[MAX_PLAYERS];

hook OnGameModeInit()
{
    CreateVehicleLocation(2470.74, -2118.92, 13.54);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(PRESSED(KEY_YES))
	{
        if(!IsPlayerInRangeOfPoint(playerid, 2.0, 2470.74, -2118.92, 13.54))
            return 1;

        if(PlayerInfo[playerid][Profissao] != loader)
            return SendClientMessage(playerid, Erro, "Você não tem permissão");

        if(PV_Profission[playerid])
            return SendClientMessage(playerid, Erro, "Seu veículo já está criado");

        new rand = random(sizeof(vr_loader));

        CreatePlayerVehicle(playerid, 456, vr_loader[rand][vrl_x], vr_loader[rand][vrl_y], vr_loader[rand][vrl_z], 0.0, -1, -1);

        SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Foi criado um veículo profissão no estacionamento");
        return 1;
	}
	return 1;
}

stock Loader_DynamicRaceCP(playerid)
{
    if(PlayerInfo[playerid][Profissao] == loader)
    {
        new vehicleid = getPlayerVehicleID(playerid);

        if(vehicleid == INVALID_VEHICLE_ID)
            return 0;

        if(!PublicVehicle[vehicleid][pv_loaded])
            return 0;

        if(!IsPlayerInAnyVehicle(playerid))
            return SendClientMessage(playerid, Erro, "Você não está em um Yankee");

        if(GetVehicleModel(PublicVehicle[vehicleid][pv_vehicle]) != 456)
            return SendClientMessage(playerid, Erro, "Você não está em um Yankee");

        switch(loader_count[playerid])
        {
            case MAX_PLACE_LOADER:
            {
                LoadOrDownload(playerid, vehicleid, false);

                PlayerPlaySound(playerid, 1058, 0.0, 0.0, 0.0);

                merchandise += 10;
                UpdadeMerchandise();

                new value = RandomValueLoader();

                format(String, MAX_STRING, "Você recebeu $%s pelo serviço", IsMoney(value, "."));
                SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Descarregamento finalizado, volte para o LT e carregue novamente");
                SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);

                PlayerInfo[playerid][Dinheiro] += value;
                UpdatePlayerMoney(playerid);

                GiveBonus(playerid, 500);

                DestroyDynamicRaceCP(loader_cp[playerid]);
                loader_count[playerid] = 0;
                return 1;
            }
            default:
            {
                PlayerPlaySound(playerid, 1057, 0.0, 0.0, 0.0);

                GetPlayer2DZone(zone, MAX_ZONE_NAME, loader_place[ ( loader_count[playerid] - 1) ][lp_x], loader_place[ ( loader_count[playerid] - 1) ][lp_y]);
                format(String, MAX_STRING, "Você pegou mercadoria no Aeroporto de %s, agora vá para o %", zone, (loader_count[playerid] == (MAX_PLACE_LOADER - 1) ? ("último") : ("próximo")));
                SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);

                DestroyDynamicRaceCP(loader_cp[playerid]);
                loader_cp[playerid] = CreateDynamicRaceCP((loader_count[playerid] == (MAX_PLACE_LOADER - 1) ? 1 : 0 ), loader_place[loader_count[playerid]][lp_x], loader_place[loader_count[playerid]][lp_y], loader_place[loader_count[playerid]][lp_z], loader_place[ (loader_count[playerid] + 1) ][lp_x], loader_place[ (loader_count[playerid] + 1) ][lp_y], loader_place[ (loader_count[playerid] + 1) ][lp_z], 5.0, -1, -1, playerid, -1.0);
                loader_count[playerid]++;
            }
        }
        return 1;
    }
    return 1;
}

stock RandomValueLoader()
{
    new value = random(10000);

    if(value < 7000) return RandomValueLoader();

    return value;
}

stock LeftPfsLoader(playerid)
{
    if(PlayerInfo[playerid][Profissao] == loader)
    {
        if(loader_count[playerid]){
            loader_count[playerid] = 0;
            DestroyDynamicRaceCP(loader_cp[playerid]);
        }
        return 1;
    }
    return 1;
}

stock CMD_LoaderCarregar(playerid)
{
    if(PlayerInfo[playerid][Profissao] != loader)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsPlayerInRangeOfPoint(playerid, 50.0, 2483.99, -2088.98, 13.54))
        return SendClientMessage(playerid, Erro, "Você não está no seu Local de Trabalho");

    if(!IsPlayerInAnyVehicle(playerid))
        return SendClientMessage(playerid, Erro, "Você não está em um Yankee");

    new vehicleid = getPlayerVehicleID(playerid);

    if(vehicleid == INVALID_VEHICLE_ID)
        return SendClientMessage(playerid, Erro, "Você não criou um veículo profissão");

    if(GetVehicleModel(PublicVehicle[vehicleid][pv_vehicle]) != 456)
        return SendClientMessage(playerid, Erro, "Você não está em um Yankee");

    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
        return SendClientMessage(playerid, Erro, "Você não está dirigindo um Yankee");

    if(PublicVehicle[vehicleid][pv_loaded])
        return SendClientMessage(playerid, Erro, "Seu veículo já está carregado");

    LoadOrDownload(playerid, vehicleid, true);

    SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Caminhão carregado, siga à marcação em seu mini-mapa");

    loader_cp[playerid] = CreateDynamicRaceCP(0, loader_place[loader_count[playerid]][lp_x], loader_place[loader_count[playerid]][lp_y], loader_place[loader_count[playerid]][lp_z], loader_place[ (loader_count[playerid] + 1) ][lp_x], loader_place[ (loader_count[playerid] + 1) ][lp_y], loader_place[ (loader_count[playerid] + 1) ][lp_z], 5.0, -1, -1, playerid, -1.0);
    loader_count[playerid] = 1;
    return 1;
}
