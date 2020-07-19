#include YSI\y_hooks

new pt_vehicle[8];
new bool:Petroleum[MAX_PLAYERS];

hook OnGameModeInit()
{
    pt_vehicle[0] = CreateVehicle(514, 302.7167, 1474.7983, 10.4853, -117.0000, -1, -1, 100);
    pt_vehicle[1] = CreateVehicle(514, 301.5925, 1464.5660, 10.4129, -119.0000, -1, -1, 100);
    pt_vehicle[2] = CreateVehicle(514, 301.0728, 1459.1483, 9.8414, -117.0000, -1, -1, 100);
    pt_vehicle[3] = CreateVehicle(514, 302.1852, 1453.4656, 10.2672, -117.0000, -1, -1, 100);
    pt_vehicle[4] = CreateVehicle(514, 301.9598, 1448.5229, 10.3889, -119.0000, -1, -1, 100);
    pt_vehicle[5] = CreateVehicle(514, 301.6843, 1469.6198, 10.4388, -119.0000, -1, -1, 100);
    pt_vehicle[6] = CreateVehicle(514, 340.5740, 1446.1991, 9.0670, -179.0000, -1, -1, 100);
    pt_vehicle[7] = CreateVehicle(514, 340.4822, 1467.7844, 7.5528, -178.0000, -1, -1, 100);
    for(new i = 0; i < sizeof(pt_vehicle); i++) { SetVehicleParamsEx(pt_vehicle[i], 0, 0, 0, 0, 0, 0, 0); }

    CreateVehicle(584, 293.6473, 1479.4601, 11.5491, -117.0000, -1, -1, 100);
    CreateVehicle(584, 293.1074, 1474.1301, 11.6669, -117.0000, -1, -1, 100);
    CreateVehicle(584, 292.6587, 1469.5249, 11.5962, -119.0000, -1, -1, 100);
    CreateVehicle(584, 292.8142, 1463.5654, 11.7170, -117.0000, -1, -1, 100);
    CreateVehicle(584, 294.1655, 1457.5743, 12.1646, -117.0000, -1, -1, 100);
    CreateVehicle(584, 293.0652, 1453.2302, 11.7824, -118.0000, -1, -1, 100);
    CreateVehicle(584, 340.2242, 1478.3892, 8.1732, -180.0000, -1, -1, 100);
    CreateVehicle(584, 340.2765, 1456.8361, 9.5973, -179.0000, -1, -1, 100);

    CreateDynamicObject(16394, 293.68210, 1452.91711, 9.81920,   0.00000, 2.00000, 0.00000);
    CreateDynamicObject(3626, 291.85831, 1430.90088, 10.75890,   0.00000, 0.00000, -269.00000);
    CreateDynamicObject(3578, 293.26648, 1411.46985, 9.54270,   0.00000, 4.00000, -2.00000);
    CreateDynamicObject(3578, 283.13928, 1411.58582, 10.00540,   0.00000, 0.00000, 0.56889);
    CreateDynamicObject(3578, 272.88821, 1411.52014, 10.01050,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3578, 262.57449, 1411.50305, 10.00820,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3578, 256.81049, 1400.75769, 10.02100,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(3578, 256.88599, 1410.98450, 10.01920,   0.00000, 0.00000, -91.00000);
    CreateDynamicObject(3578, 257.11240, 1421.29858, 10.04630,   0.00000, 0.00000, -91.00000);
    CreateDynamicObject(3578, 257.28049, 1431.57190, 10.03850,   0.00000, 0.00000, -91.00000);
    CreateDynamicObject(3578, 257.54749, 1441.88977, 10.03250,   0.00000, 0.00000, -92.00000);
    CreateDynamicObject(3578, 256.84021, 1390.48364, 10.00160,   0.00000, 0.00000, -89.00000);
    CreateDynamicObject(3578, 257.01169, 1380.18298, 10.00160,   0.00000, 0.00000, -89.00000);
    CreateDynamicObject(3578, 242.19910, 1460.89551, 10.22820,   0.00000, 0.00000, 63.00000);
    CreateDynamicObject(3578, 227.42047, 1459.71619, 10.15840,   0.00000, 0.00000, -55.00000);
    CreateDynamicObject(3578, 224.86060, 1479.60339, 10.15520,   0.00000, 0.00000, -91.00000);
    CreateDynamicObject(3578, 224.65640, 1469.32666, 10.16020,   0.00000, 0.00000, -91.00000);
    CreateDynamicObject(3578, 229.77190, 1419.36816, 10.21210,   0.00000, 0.00000, -92.00000);
    CreateDynamicObject(3578, 230.00716, 1429.67725, 10.19590,   0.00000, 0.00000, -91.00000);
    CreateDynamicObject(3578, 230.19690, 1439.92065, 10.19820,   0.00000, 0.00000, -91.00000);
    CreateDynamicObject(3578, 230.28230, 1450.16064, 10.17830,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(3578, 239.84595, 1451.21753, 10.19290,   0.00000, 0.40000, -91.00000);
    CreateDynamicObject(3578, 239.66240, 1440.90601, 10.15220,   0.00000, -0.04000, -271.00000);
    CreateDynamicObject(3578, 239.60364, 1430.63049, 10.14140,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(3578, 239.58603, 1420.32349, 10.14110,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(3578, 239.54678, 1410.01099, 10.13680,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(3578, 239.41611, 1399.70020, 10.14150,   0.00000, 0.00000, -91.00000);
    CreateDynamicObject(3578, 239.19905, 1389.40283, 10.14200,   0.00000, 0.00000, -91.00000);
    CreateDynamicObject(3578, 239.01344, 1379.13989, 10.12150,   0.00000, 0.00000, -91.00000);
    CreateDynamicObject(3578, 238.83954, 1368.84131, 10.11470,   0.00000, 0.00000, -91.00000);
    CreateDynamicObject(3578, 238.61314, 1358.54651, 10.11220,   0.00000, 0.00000, -91.00000);
    CreateDynamicObject(3578, 229.60692, 1409.07397, 10.21450,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(3578, 229.52406, 1398.77612, 10.21720,   0.00000, 0.00000, -91.00000);
    CreateDynamicObject(3578, 229.44011, 1388.46436, 10.21060,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(3578, 229.34779, 1378.15796, 10.21090,   0.00000, 0.00000, -91.00000);
    CreateDynamicObject(3578, 229.13261, 1367.86487, 10.20970,   0.00000, 0.00000, -91.00000);
    CreateDynamicObject(3578, 229.04010, 1357.54968, 10.21050,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(3578, 224.77991, 1349.09009, 10.21840,   0.00000, 0.00000, 34.00000);
    CreateDynamicObject(3578, 220.20044, 1341.14758, 10.19700,   0.00000, 0.00000, -89.00000);
    CreateDynamicObject(3578, 257.11038, 1369.87012, 10.00580,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(3578, 257.08459, 1359.56714, 10.02780,   0.00000, 0.00000, -89.96000);

    CreateDynamicPickup(1318, 1, 288.4768, 1416.2633, 10.3689, -1, -1, -1, 50.0);
    CreateDynamicPickup(1318, 1, 288.7573, 1405.6627, 10.3537, -1, -1, -1, 50.0);
    CreateDynamicPickup(1318, 1, 234.7237, 1415.5150, 10.5859, -1, -1, -1, 60.0);

    CreateDynamic3DTextLabel("{FF0000}** {FFFFFF}Entrada{FF0000} **", 0xFFFFFFFF, 288.4768, 1416.2633, 10.3689, 50.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
    CreateDynamic3DTextLabel("{FF0000}** {FFFFFF}Saída{FF0000} **", 0xFFFFFFFF, 288.7573, 1405.6627, 10.3537, 50.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
    CreateDynamic3DTextLabel("{FFFFFF}Digite: \"{FF0000}/Carregar{FFFFFF}\"", 0xFFFFFFFF, 234.7237, 1415.5150, 10.5859, 60.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    RemoveBuildingForPlayer(playerid, 16086, 232.2891, 1434.4844, 13.5000, 0.25);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    Petroleum[playerid] = false;
    return 1;
}

hook OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    for(new i; i < sizeof(pt_vehicle); i++) if(vehicleid == pt_vehicle[i])
    {
        if(!ispassenger && vehicleid != INVALID_VEHICLE_ID && PlayerInfo[playerid][Profissao] != tanker)
        {
            ClearAnimations(playerid);
            SendClientMessage(playerid, Erro, "Veiculo exclusivo da profissão Petroleiro(a)");
            return 1;
        }
    }
    return 1;
}

forward LoadingTanker(playerid);
public LoadingTanker(playerid)
{
    Petroleum[playerid] = true;
    TogglePlayerControllable(playerid, true);
    GameTextForPlayer(playerid, "~g~Carregado com sucesso", 2500, 1);
    SendClientMessage(playerid, color_tanker, "Seu caminhão foi carregado, Para descarregá-lo vá ate um dos 20 postos espalhados por San Andreas");
    return 1;
}

/******************************************************************************/
/******************************| COMMANDS TANKER |*****************************/
/******************************************************************************/

CMD:carregar(playerid)
{
    if(PlayerInfo[playerid][Profissao] != tanker)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(Petroleum[playerid])
        return SendClientMessage(playerid, Erro,"Seu caminhão já está carregado");

    new vehicleid = GetPlayerVehicleID(playerid);

    if(GetVehicleModel(GetVehicleTrailer(vehicleid)) != 584)
        return SendClientMessage(playerid, Erro, "Você não está com o trailer de petróleo");

    if(!IsPlayerInRangeOfPoint(playerid, 15.0, 234.7237, 1415.5150, 10.5859))
        return SendClientMessage(playerid, Erro, "Vocé não está na área de carregamento");

    if(IsTrailerAttachedToVehicle(vehicleid))
    {
        TogglePlayerControllable(playerid, false);
        GameTextForPlayer(playerid, "~r~Carregando...", 2500, 1);
        SetTimerEx("LoadingTanker", 2500, false, "d", playerid);
    }
    return 1;
}
CMD:descarregar(playerid)
{
    if(PlayerInfo[playerid][Profissao] != tanker)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

	if(!Petroleum[playerid])
        return SendClientMessage(playerid, Erro, "Seu veículo não está carregado");

	new vehicleid = GetPlayerVehicleID(playerid);
  	new vehmod = GetVehicleModel(GetVehicleTrailer(vehicleid));

  	if(vehmod != 584)
        return SendClientMessage(playerid, Erro, "Você não está em um Posto de Combustível");

    if(!GetVehicleModel(GetVehicleTrailer(vehicleid)))
        return SendClientMessage(playerid, Erro, "Você não está em um Posto de Combustível");

    if(!IsPlayerFuelTerrestrial(playerid))
        return SendClientMessage(playerid, Erro, "Você não está em um Posto de Combustível");

    Petroleum[playerid] = false;
    PlayerInfo[playerid][Dinheiro] += 920;
    UpdatePlayerMoney(playerid);
    SetVehicleToRespawn(GetVehicleTrailer(vehicleid));
	SendClientMessage(playerid, color_tanker, "Caminhão descarregado e vocé ganhou $920");
    return 1;
}
