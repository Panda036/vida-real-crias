#include YSI\y_hooks

enum e_rsw
{
    Float:rsw_x,
    Float:rsw_y,
    Float:rsw_z
};

new RandomSpawnWoods[5][e_rsw] =
{
    {-1992.04, -2447.83, 32.62},
    {-1987.04, -2452.29, 32.62},
    {-1981.81, -2456.91, 32.62},
    {-1976.63, -2461.47, 32.62},
    {-1971.88, -2465.52, 32.62}
};

new woodsObject[MAX_VEHICLES];
new woodsEndCP[MAX_PLAYERS];
new woodsTime[MAX_PLAYERS];

hook OnGameModeInit()
{
    CreateDynamic3DTextLabel("{FFFFFF}Área de Carregamento\n{F29B0D}Madeiras", 0xFFFFFFFF, -2019.80, -2399.61, 30.62, 200.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
    CreateDynamicRaceCP(2, -2019.80, -2399.61, 30.62, -1, -1, -1, 5.0, -1, -1, -1, 200.0);

    CreateVehicleLocation(-1969.32, -2431.03, 30.62);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(PRESSED(KEY_YES))
	{
        if(!IsPlayerInRangeOfPoint(playerid, 2.0, -1969.32, -2431.03, 30.62))
            return 1;

        if(PlayerInfo[playerid][Profissao] != woods)
            return SendClientMessage(playerid, Erro, "Você não tem permissão");

        if(PV_Profission[playerid])
            return SendClientMessage(playerid, Erro, "Seu veículo já está criado");

        new rand = random(sizeof(RandomSpawnWoods));

        CreatePlayerVehicle(playerid, 578, RandomSpawnWoods[rand][rsw_x], RandomSpawnWoods[rand][rsw_y], RandomSpawnWoods[rand][rsw_z], 0.00, 1, 1);

        SetPlayerSkin(playerid, 27);
        SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Foi criado um veículo profissão no estacionamento");
        return 1;
	}
	return 1;
}

forward OnPlayerLoadingWoods(playerid);
public OnPlayerLoadingWoods(playerid)
{
    woodsTime[playerid] = gettime();

    SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Veículo carregado, vá até a marcação vermelha em seu mini-mapa");

    woodsEndCP[playerid] = CreateDynamicRaceCP(1, -2431.95, 2290.99, 4.98, -1, -1, -1, 5.0, -1, -1, playerid, -1.0);
    AddWoodsVehicle(GetPlayerVehicleID(playerid));
    TogglePlayerControllable(playerid, true);
    return 1;
}

forward OnPlayerDowloadWoods(playerid);
public OnPlayerDowloadWoods(playerid)
{
    woodsTime[playerid] = (gettime() - woodsTime[playerid]);

    new value = (floatround((2500000 / woodsTime[playerid]), floatround_round));

    merchandise += 10;
    UpdadeMerchandise();

    if(woodsTime[playerid] < 400) {
        SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Muito bom, você é motorista de fuga");
    }
    else if(woodsTime[playerid] > 2500) {
        value = 1000;
        SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Demorou demais, dá próxima você nos surpreende");
    }
    else {
        SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Boa, continue assim");
    }

    PlayerInfo[playerid][Dinheiro] += value;
    UpdatePlayerMoney(playerid);

    format(String, MAX_STRING, "Sua recompensa pelo serviço prestado é de $%s", IsMoney(value, "."));
    SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);

    DestroyDynamicRaceCP(woodsEndCP[playerid]);
    RemoveWoodsVehicle(GetPlayerVehicleID(playerid));
    TogglePlayerControllable(playerid, true);

    woodsTime[playerid] = 0;
    return 1;
}

stock woodsDynamicRaceCP(playerid)
{
    if(PlayerInfo[playerid][Profissao] != woods)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsPlayerInAnyVehicle(playerid))
        return SendClientMessage(playerid, Erro, "Você não está em um DFT-30");

    if(GetVehicleModel(GetPlayerVehicleID(playerid)) != 578)
        return SendClientMessage(playerid, Erro, "Você não está em um DFT-30");

    new vehicleid = getPlayerVehicleID(playerid);

    if(PublicVehicle[vehicleid][pv_loaded] && (gettime() - woodsTime[playerid]) < 300)
        return SendClientMessage(playerid, Erro, "Você chegou muito rápido(a), aguarde alguns segundos...");

    LoadOrDownload(playerid, vehicleid, (PublicVehicle[vehicleid][pv_loaded] ? false : true ));
    TogglePlayerControllable(playerid, false);
    GameTextForPlayer(playerid, (PublicVehicle[vehicleid][pv_loaded] ? ("~r~Carregando...") : ("~r~Descarregando...")), 2000, 3);
    SetTimerEx((PublicVehicle[vehicleid][pv_loaded] ? ("OnPlayerLoadingWoods") : ("OnPlayerDowloadWoods")), 2000, false, "d", playerid);
    return 1;
}

stock AddWoodsVehicle(vehicleid)
{
    if(GetVehicleModel(vehicleid) != 578) return 0;

    if(IsValidDynamicObject(woodsObject[vehicleid])) return 0;

    woodsObject[vehicleid] = CreateDynamicObject(18609, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    AttachDynamicObjectToVehicle(woodsObject[vehicleid], vehicleid, 0.11, -4.67, 0.80, 0.00, 0.00, 3.00);
    return 1;
}

stock RemoveWoodsVehicle(vehicleid)
{
    if(GetVehicleModel(vehicleid) != 578) return 0;

    if(!IsValidDynamicObject(woodsObject[vehicleid])) return 0;

    DestroyDynamicObject(woodsObject[vehicleid]);
    woodsObject[vehicleid] = INVALID_OBJECT_ID;
    return 1;
}

stock LeftPfsWoods(playerid)
{
    if(PlayerInfo[playerid][Profissao] != woods)
        return 0;

    if(!woodsTime[playerid])
        return 0;

    DestroyDynamicRaceCP(woodsEndCP[playerid]);
    woodsTime[playerid] = 0;
    return 1;
}
