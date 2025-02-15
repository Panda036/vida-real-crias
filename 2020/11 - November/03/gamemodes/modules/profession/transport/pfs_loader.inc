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
            return SendClientMessage(playerid, Erro, "Voc� n�o tem permiss�o");

        if(PV_Profission[playerid])
            return SendClientMessage(playerid, Erro, "Seu ve�culo j� est� criado");

        new rand = random(sizeof(vr_loader));

        CreatePlayerVehicle(playerid, 456, vr_loader[rand][vrl_x], vr_loader[rand][vrl_y], vr_loader[rand][vrl_z], 0.0, -1, -1);

        SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Foi criado um ve�culo profiss�o no estacionamento");
        return 1;
	}
	return 1;
}

stock Loader_DynamicRaceCP(playerid)
{
    if(PlayerInfo[playerid][Profissao] == loader)
    {
        new vehicleid = getPlayerVehicleID(playerid);

        if(!PublicVehicle[vehicleid][pv_loaded])
            return 0;

        if(!IsPlayerInAnyVehicle(playerid))
            return SendClientMessage(playerid, Erro, "Voc� n�o est� em um Yankee");

        if(GetVehicleModel(PublicVehicle[vehicleid][pv_vehicle]) != 456)
            return SendClientMessage(playerid, Erro, "Voc� n�o est� em um Yankee");

        if(PublicVehicle[vehicleid][pv_id] != playerid)
            return SendClientMessage(playerid, Erro, "Esse ve�culo n�o pertence a voc�");

        switch(loader_count[playerid])
        {
            case MAX_PLACE_LOADER:
            {
                LoadOrDownload(playerid, vehicleid, false);

                PlayerPlaySound(playerid, 1058, 0.0, 0.0, 0.0);

                merchandise += 10;
                UpdadeMerchandise();

                new value[MAX_PLAYERS];

                value[playerid] = RandomValueLoader();

                format(String, MAX_STRING, "Voc� recebeu $%s pelo servi�o", IsMoney(value[playerid], "."));
                SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Descarregamento finalizado, volte para o LT e carregue novamente");
                SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);

                PlayerInfo[playerid][Dinheiro] += value[playerid];
                UpdatePlayerMoney(playerid);

                GiveBonus(playerid, 500);

                DestroyDynamicRaceCP(loader_cp[playerid]);
                loader_count[playerid] = 0;
                return 1;
            }
            case ( MAX_PLACE_LOADER - 1 ):
            {
                PlayerPlaySound(playerid, 1057, 0.0, 0.0, 0.0);

                GetPlayer2DZone(zone, MAX_ZONE_NAME, loader_place[ ( loader_count[playerid] - 1) ][lp_x], loader_place[ ( loader_count[playerid] - 1) ][lp_y]);
                format(String, 128, "Voc� pegou mercadoria no Aeroporto de %s, agora v� para o �ltimo", zone);
                SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);

                DestroyDynamicRaceCP(loader_cp[playerid]);
                loader_cp[playerid] = CreateDynamicRaceCP(1, loader_place[loader_count[playerid]][lp_x], loader_place[loader_count[playerid]][lp_y], loader_place[loader_count[playerid]][lp_z], -1, -1, -1, 5.0, -1, -1, playerid, -1.0);
            }
            default:
            {
                PlayerPlaySound(playerid, 1057, 0.0, 0.0, 0.0);

                GetPlayer2DZone(zone, MAX_ZONE_NAME, loader_place[ ( loader_count[playerid] - 1) ][lp_x], loader_place[ ( loader_count[playerid] - 1) ][lp_y]);
                format(String, 128, "Voc� pegou mercadoria no Aeroporto de %s, agora v� para o pr�ximo", zone);
                SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);

                DestroyDynamicRaceCP(loader_cp[playerid]);
                loader_cp[playerid] = CreateDynamicRaceCP(0, loader_place[loader_count[playerid]][lp_x], loader_place[loader_count[playerid]][lp_y], loader_place[loader_count[playerid]][lp_z], loader_place[ (loader_count[playerid] + 1) ][lp_x], loader_place[ (loader_count[playerid] + 1) ][lp_y], loader_place[ (loader_count[playerid] + 1) ][lp_z], 5.0, -1, -1, playerid, -1.0);

            }
        }

        loader_count[playerid]++;
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

CMD:carregar(playerid)
{
    if(PlayerInfo[playerid][Profissao] != loader)
        return SendClientMessage(playerid, Erro, "Voc� n�o tem permiss�o");

    if(!IsPlayerInRangeOfPoint(playerid, 50.0, 2483.99, -2088.98, 13.54))
        return SendClientMessage(playerid, Erro, "Voc� n�o est� no seu Local de Trabalho");

    if(!IsPlayerInAnyVehicle(playerid))
        return SendClientMessage(playerid, Erro, "Voc� n�o est� em um Yankee");

    new vehicleid = getPlayerVehicleID(playerid);

    if(!vehicleid)
        return SendClientMessage(playerid, Erro, "Voc� n�o criou um ve�culo profiss�o");

    if(GetVehicleModel(PublicVehicle[vehicleid][pv_vehicle]) != 456)
        return SendClientMessage(playerid, Erro, "Voc� n�o est� em um Yankee");

    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
        return SendClientMessage(playerid, Erro, "Voc� n�o est� dirigindo um Yankee");

    if(PublicVehicle[vehicleid][pv_loaded])
        return SendClientMessage(playerid, Erro, "Seu ve�culo j� est� carregado");

    LoadOrDownload(playerid, vehicleid, true);

    SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Caminh�o carregado, siga � marca��o em seu mini-mapa");

    loader_cp[playerid] = CreateDynamicRaceCP(0, loader_place[loader_count[playerid]][lp_x], loader_place[loader_count[playerid]][lp_y], loader_place[loader_count[playerid]][lp_z], loader_place[ (loader_count[playerid] + 1) ][lp_x], loader_place[ (loader_count[playerid] + 1) ][lp_y], loader_place[ (loader_count[playerid] + 1) ][lp_z], 5.0, -1, -1, playerid, -1.0);
    loader_count[playerid] = 1;
    return 1;
}
