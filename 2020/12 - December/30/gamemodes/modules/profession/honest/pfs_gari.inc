#include YSI\y_hooks

#define MAX_TRASH 170

enum e_gd
{
    gd_value,
    Float:gd_x,
    Float:gd_y,
    Float:gd_z
};

new GariData[MAX_TRASH][e_gd] =
{
    {2, 1666.57, 2034.53, 9.94},
    {1, 1666.54, 2037.78, 9.92},
    {1, 1666.54, 2039.00, 9.92},
    {1, 1666.54, 2042.21, 9.92},
    {1, 1659.14, 2046.46, 9.92},
    {1, 1659.14, 2049.14, 9.92},
    {1, 1659.14, 2050.90, 9.92},
    {2, 1666.57, 2056.00, 9.94},
    {2, 1666.57, 2056.00, 9.94},
    {1, 1666.65, 2062.53, 9.92},
    {1, 1666.65, 2064.29, 9.92},
    {1, 1659.14, 2068.96, 9.92},
    {1, 1659.14, 2070.73, 9.92},
    {2, 1659.10, 2084.48, 9.94},
    {1, 1659.21, 2092.30, 9.92},
    {1, 1659.21, 2086.60, 9.92},
    {1, 1666.65, 2098.84, 9.92},
    {1, 1666.65, 2100.60, 9.92},
    {2, 1666.57, 2109.21, 9.94},
    {1, 1659.21, 2116.01, 9.92},
    {1, 1659.21, 2121.70, 9.92},
    {2, 1659.10, 2124.22, 9.94},
    {1, 1666.96, 2128.73, 9.92},
    {1, 1666.96, 2134.42, 9.92},
    {1, 1659.00, 2142.66, 9.92},
    {1, 1659.00, 2144.42, 9.92},
    {2, 1659.10, 2159.10, 9.94},
    {2, 1659.10, 2161.60, 9.94}, //beoc de 30 lv
    {2, 1577.58, 2091.53, 10.21},
    {1, 1567.82, 2095.57, 9.92},
    {1, 1567.82, 2096.80, 9.92},
    {1, 1577.75, 2112.21, 9.92},
    {1, 1577.75, 2113.43, 9.92},
    {2, 1577.58, 2119.10, 10.21},
    {1, 1567.82, 2133.48, 9.92},
    {1, 1567.82, 2134.71, 9.92},
    {1, 1577.75, 2154.25, 9.92},
    {1, 1577.75, 2155.48, 9.92},
    {1, 1577.75, 2158.68, 9.92},
    {2, 1577.58, 2161.14, 10.21},
    {1, 1567.82, 2160.75, 9.92},
    {1, 1567.82, 2157.54, 9.92},
    {1, 1567.82, 2156.32, 9.92}, //beco ao lado lv
    {1, 1446.26, 1884.84, 9.92},
    {1, 1446.26, 1888.05, 9.92},
    {1, 1427.24, 1891.88, 9.92},
    {1, 1427.24, 1893.10, 9.92},
    {2, 1427.17, 1905.25, 9.94},
    {1, 1446.26, 1910.70, 9.92},
    {1, 1446.26, 1911.92, 9.92},
    {1, 1446.26, 1915.13, 9.92},
    {2, 1446.10, 1917.59, 9.94},
    {1, 1427.24, 1910.70, 9.92},
    {1, 1427.24, 1911.92, 9.92},
    {1, 1427.24, 1915.13, 9.92},
    {1, 1434.63, 1932.28, 9.92},
    {1, 1431.42, 1932.28, 9.92},
    {1, 1430.20, 1932.28, 9.92}, //Beco perto hp lv
    {1, 1066.47, 2021.93, 9.95},
    {1, 1066.47, 2018.73, 9.95},
    {1, 1066.47, 2017.50, 9.95},
    {2, 1048.33, 2017.70, 9.94},
    {1, 1048.50, 2012.03, 9.95},
    {1, 1047.79, 1994.59, 9.95},
    {1, 1047.79, 1991.39, 9.95},
    {1, 1047.79, 1990.16, 9.95},
    {1, 1066.82, 1990.16, 9.95},
    {1, 1066.82, 1991.39, 9.95},
    {1, 1066.82, 1994.59, 9.95},
    {2, 1066.65, 1997.05, 9.94}, //Beco perto da entrega em lv
    {2, 2379.25, 2759.40, 10.63},
    {2, 2377.21, 2759.44, 10.61},
    {2, 2374.35, 2759.87, 10.63},
    {2, 2361.24, 2781.76, 10.62},
    {2, 2361.10, 2783.21, 10.61},
    {2, 2361.79, 2793.01, 10.61},
    {2, 2287.78, 2784.28, 10.57},
    {2, 2273.84, 2784.45, 10.57}, //Correios
    {1, 974.92, -815.51, 96.72},
    {1, 960.24, -822.85, 95.53},
    {1, 911.70, -836.20, 91.35},
    {1, 910.87, -836.69, 91.12}, //Mullholand
    {2, 1424.57, -1080.38, 17.41},
    {2, 1424.52, -1084.30, 17.41},
    {2, 1435.58, -1095.79, 17.41},
    {2, 1438.19, -1095.84, 17.41}, //Beco East Los Santos
    {2, 1611.68, -993.90, 23.84},
    {2, 1631.92, -987.82, 23.84},
    {2, 1633.93, -990.55, 23.84},
    {2, 1660.25, -1000.41, 23.78},
    {2, 1666.39, -997.70, 23.78},
    {2, 1789.90, -1112.64, 23.89},
    {2, 1789.77, -1116.06, 23.89},
    {2, 1786.21, -1148.29, 23.67},
    {2, 1800.45, -1148.29, 23.67},
    {2, 1830.57, -1147.38, 23.67},
    {2, 1830.61, -1143.82, 23.67},
    {2, 1830.57, -1113.92, 23.67},
    {2, 1830.57, -1097.30, 23.67},
    {2, 1830.57, -1084.28, 23.67}, //Estacionamento East Los Santos
    {2, 1520.21, -1014.63, 23.84},
    {2, 1520.15, -1018.55, 23.84},
    {2, 1659.91, -1065.11, 23.79},
    {2, 1439.85, -1323.70, 13.38},
    {2, 1415.60, -1299.18, 13.36},
    {2, 1425.57, -1317.96, 13.36},
    {2, 1425.53, -1320.57, 13.36},
    {2, 1420.11, -1356.84, 13.38}, //Market/East Los Santos
    {2, -2760.36, 144.35, 6.88},
    {2, -2763.13, 115.38, 6.89},
    {2, -2757.96, 95.98, 6.92},
    {2, -2756.48, 93.18, 6.92},
    {2, -2756.26, 90.35, 6.92},
    {2, -2766.21, 86.57, 6.92},
    {2, -2716.98, 74.35, 4.07},
    {2, -2717.92, 77.92, 4.07},
    {2, -2760.36, 63.85, 6.93},
    {2, -2766.42, 52.07, 6.92},
    {2, -2766.03, 25.01, 6.83},
    {2, -2759.47, 7.89, 6.83},
    {2, -2747.35, -8.66, 6.09},
    {2, -2763.70, -13.73, 6.83},
    {2, -2755.91, -36.38, 6.83},
    {2, -2760.71, -54.34, 6.83},
    {2, -2754.85, -56.60, 6.83},
    {2, -2754.42, -85.39, 6.83},
    {2, -2759.94, -96.82, 6.83},
    {2, -2759.20, -120.82, 6.83},
    {2, -2753.27, -121.60, 6.83},
    {2, -2759.25, -136.20, 6.83},
    {2, -2753.31, -149.85, 6.83},
    {2, -2753.94, -178.32, 6.83},
    {2, -2657.77, 135.60, 3.98},
    {2, -2651.90, 133.34, 3.98},
    {2, -2656.71, 115.38, 3.98},
    {2, -2651.25, 92.43, 3.98},
    {2, -2656.59, 71.56, 3.98},
    {2, -2649.81, 52.75, 3.98},
    {2, -2658.31, -89.61, 3.98},
    {2, -2659.27, -125.20, 3.98},
    {2, -2653.67, -124.74, 3.98},
    {2, -2653.38, -167.39, 3.98},
    {2, -2658.97, -168.89, 3.98},
    {2, -2657.92, -189.07, 3.98},
    {2, -2652.78, -188.28, 3.98}, //East Los Santos
    {1, 2380.85, -1039.05, 52.78},
    {1, 2380.03, -1038.07, 52.82},
    {1, 2426.72, -1016.75, 53.44},
    {1, 2436.71, -1052.25, 53.42},
    {1, 2459.45, -1051.60, 58.84},
    {1, 2457.39, -1023.17, 58.78},
    {1, 2484.08, -1053.14, 66.64},
    {1, 2489.61, -1022.60, 64.51},
    {1, 2505.07, -1061.07, 69.31},
    {1, 2510.28, -1029.58, 69.17},
    {1, 2527.92, -1058.14, 68.68},
    {1, 2528.67, -1034.92, 68.67},
    {1, 2538.64, -1058.60, 68.67},
    {1, 2545.15, -1034.89, 68.66},
    {1, 2567.82, -1035.28, 68.67}, //Favela
    {2, 1419.69, -1844.20, 12.66},
    {2, 1419.73, -1846.54, 12.66},
    {2, 1466.94, -1847.84, 12.66},
    {2, 1468.06, -1847.78, 12.66},
    {2, 1486.21, -1848.12, 12.66},
    {2, 1516.68, -1850.05, 12.66},
    {2, 1538.94, -1849.27, 12.66}, //Atras da prefeitura ls
    {2, 1337.69, -1774.73, 12.66},
    {2, 1336.78, -1816.30, 12.66},
    {2, 1336.33, -1842.85, 12.66} //Atras 24/7 lado prefeitura
};

enum e_rsg
{
    Float:rsg_x,
    Float:rsg_y,
    Float:rsg_z
};

new RandomSpawnGari[8][e_rsg] =
{
    {2112.57, -2072.28, 14.06},
    {2116.85, -2076.33, 14.06},
    {2119.89, -2079.04, 14.06},
    {2124.62, -2083.69, 14.06},
    {2127.73, -2086.42, 14.06},
    {2132.34, -2090.57, 14.06},
    {2135.52, -2093.38, 14.06},
    {2139.73, -2097.40, 14.06}
};

enum e_gi
{
    gi_mapicon1,
    gi_mapicon2,
    gi_mapicon3
};

new GariInfo[MAX_PLAYERS][e_gi];

new bool:GotTrash[MAX_PLAYERS];
new Float:Gari_CPS[MAX_PLAYERS][4];
new CPVehicleGari[MAX_PLAYERS];
new Text3D:GariLabel[MAX_TRASH];

new CPTrash[3];
new Text3D:LabelTrash[3];
new TrashsLocal[3];

hook OnGameModeInit()
{
    CreateDynamicObject(18862, 2098.28, -2001.96, 15.99, 0.00000, 0.00000, 0.00000);
    CreateDynamicObject(18862, 1006.56, 2450.99, 13.05, 0.00000, 0.00000, 0.00000);
    CreateDynamicObject(18862, -1050.29, -615.69, 33.17, 0.00000, 0.00000, 0.00000);

    CPTrash[0] = CreateDynamicRaceCP(2, 2102.65, -2010.79, 13.54, -1, -1, -1, 3.0, -1, -1, -1, 100.0);
    CPTrash[1] = CreateDynamicRaceCP(2, 1006.71, 2438.94, 9.67, -1, -1, -1, 3.0, -1, -1, -1, 100.0);
    CPTrash[2] = CreateDynamicRaceCP(2, -1047.07, -607.76, 32.00, -1, -1, -1, 3.0, -1, -1, -1, 100.0);

    LabelTrash[0] = CreateDynamic3DTextLabel("{FFFFFF}Los Santos\n{F29B0D}0 {FFFFFF}Saco(s) de Lixo(s)", 0xFFFFFFFF, 2102.65, -2010.79, 13.54, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
    LabelTrash[1] = CreateDynamic3DTextLabel("{FFFFFF}Las Venturas\n{F29B0D}0 {FFFFFF}Saco(s) de Lixo(s)", 0xFFFFFFFF, 1006.71, 2438.94, 9.67, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
    LabelTrash[2] = CreateDynamic3DTextLabel("{FFFFFF}San Fierro\n{F29B0D}0 {FFFFFF}Saco(s) de Lixo(s)", 0xFFFFFFFF, -1047.07, -607.76, 32.00, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

    CreateVehicleLocation(2108.38, -2071.96, 13.56);

    for(new i = 0; i < MAX_TRASH; i++)
    {
        CreateTrash(i, GariData[i][gd_x], GariData[i][gd_y], GariData[i][gd_z]);
    }
    return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(newstate == PLAYER_STATE_DRIVER)
    {
        new vehicleid = GetPlayerVehicleID(playerid);

        if(GetVehicleModel(vehicleid) == 408 && PlayerInfo[playerid][Profissao] == gari)
        {
            format(String, 10, "%d%%", returnPorcentage(PublicVehicle[LastVehicle[playerid]][pv_trash], 30.0));
            PlayerTextDrawSetString(playerid, TDPlayerLoading[playerid][1], String);
            PlayerTextDrawTextSize(playerid, TDPlayerLoading[playerid][0], (500.4 + ((104.3 * PublicVehicle[LastVehicle[playerid]][pv_trash]) / 30.0)), 0.0);
            ShowTDLoading(playerid);

            if(IsValidDynamicMapIcon(GariInfo[playerid][gi_mapicon1])) DestroyDynamicMapIcon(GariInfo[playerid][gi_mapicon1]);
            if(IsValidDynamicMapIcon(GariInfo[playerid][gi_mapicon2])) DestroyDynamicMapIcon(GariInfo[playerid][gi_mapicon2]);
            if(IsValidDynamicMapIcon(GariInfo[playerid][gi_mapicon3])) DestroyDynamicMapIcon(GariInfo[playerid][gi_mapicon3]);

            if(PublicVehicle[LastVehicle[playerid]][pv_trash])
            {
                GariInfo[playerid][gi_mapicon1] = CreateDynamicMapIcon(2102.65, -2010.79, 13.54, 51, -1, -1, -1, playerid, -1.0, MAPICON_GLOBAL);
                GariInfo[playerid][gi_mapicon2] = CreateDynamicMapIcon(1006.71, 2438.94, 9.67, 51, -1, -1, -1, playerid, -1.0, MAPICON_GLOBAL);
                GariInfo[playerid][gi_mapicon3] = CreateDynamicMapIcon(-1047.07, -607.76, 32.00, 51, -1, -1, -1, playerid, -1.0, MAPICON_GLOBAL);
            }
        }
        return 1;
    }
	return 1;
}

hook OnPlayerExitVehicle(playerid, vehicleid)
{
    if(GetVehicleModel(vehicleid) == 408 && PlayerInfo[playerid][Profissao] == gari && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
    {
        HideTDLoading(playerid);

        if(IsValidDynamicMapIcon(GariInfo[playerid][gi_mapicon1])) DestroyDynamicMapIcon(GariInfo[playerid][gi_mapicon1]);
        if(IsValidDynamicMapIcon(GariInfo[playerid][gi_mapicon2])) DestroyDynamicMapIcon(GariInfo[playerid][gi_mapicon2]);
        if(IsValidDynamicMapIcon(GariInfo[playerid][gi_mapicon3])) DestroyDynamicMapIcon(GariInfo[playerid][gi_mapicon3]);

        return 1;
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(PRESSED(KEY_YES) && IsPlayerInRangeOfPoint(playerid, 2.0, 2108.38, -2071.96, 13.56))
	{
        if(PlayerInfo[playerid][Profissao] != gari)
            return SendClientMessage(playerid, Erro, "Você não tem permissão");

        if(PV_Profission[playerid])
            return SendClientMessage(playerid, Erro, "Você já criou um veículo profissão");

        SetPlayerSkin(playerid, 16);

        new rand = random(sizeof(RandomSpawnGari));

        CreatePlayerVehicle(playerid, 408, RandomSpawnGari[rand][rsg_x], RandomSpawnGari[rand][rsg_y], RandomSpawnGari[rand][rsg_z], 137.50, -1, -1);

        SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Foi criado um veículo profissão no estacionamento");
        return 1;
	}
    if(PRESSED(KEY_NO) && PlayerInfo[playerid][Profissao] == gari)
    {
        if(IsPlayerInAnyVehicle(playerid))
            return 0;

        for(new trashid = 0; trashid < MAX_TRASH; trashid++)
        {
            if(IsPlayerInRangeOfPoint(playerid, 2.0, GariData[trashid][gd_x], GariData[trashid][gd_y], GariData[trashid][gd_z]))
            {
                if(GotTrash[playerid])
                    return SendClientMessage(playerid, Erro, "Você já pegou um lixo, coloque no caminhão esse primeiro");

                if(!GariData[trashid][gd_value])
                    return SendClientMessage(playerid, Erro, "Essa lixeira está vazia");

                new Float:x, Float:y, Float:z;

                GetVehiclePos(LastVehicle[playerid], x, y, z);

                if(GetVehicleModel(LastVehicle[playerid]) != 408 || !IsPlayerInRangeOfPoint(playerid, 30.0, x, y, z))
                    return SendClientMessage(playerid, Erro, "Você não está perto de um TrashMaster");

                GotTrash[playerid] = true;

                SetPlayerAttachedObject(playerid, 3, 1265, 6, 0.221000, 0.031999, 0.072999, -132.900039, -60.600112, 101.199996, 0.574000, 0.418000, 0.843999);
                ApplyAnimation(playerid, "BSKTBALL", "BBALL_pickup", 2, 0, 0, 0, 0, 500);

                GetVehiclePos(LastVehicle[playerid], Gari_CPS[playerid][0], Gari_CPS[playerid][1], Gari_CPS[playerid][2]);
                GetVehicleZAngle(LastVehicle[playerid], Gari_CPS[playerid][3]);

                Gari_CPS[playerid][0] += -6.0 * floatsin(-Gari_CPS[playerid][3], degrees);
                Gari_CPS[playerid][1] += -6.0 * floatcos(-Gari_CPS[playerid][3], degrees);

                CPVehicleGari[playerid] = CreateDynamicRaceCP(1, Gari_CPS[playerid][0], Gari_CPS[playerid][1], Gari_CPS[playerid][2], -1, -1, -1, 1.0, -1, -1, playerid);

                GariData[trashid][gd_value]--;

                switch(GariData[trashid][gd_value])
                {
                    case 0: UpdateDynamic3DTextLabelText(GariLabel[trashid], 0xFFFFFFFF, "{FF0000}Lixeira\n{FFFFFF}Precione \"{FF0000}N{FFFFFF}\"");
                    case 1: UpdateDynamic3DTextLabelText(GariLabel[trashid], 0xFFFFFFFF, "{F29B0D}Lixeira\n{FFFFFF}Precione \"{FF0000}N{FFFFFF}\"");
                    case 2: UpdateDynamic3DTextLabelText(GariLabel[trashid], 0xFFFFFFFF, "{76EE00}Lixeira\n{FFFFFF}Precione \"{FF0000}N{FFFFFF}\"");
                }

                SetTimerEx("ReloadTrash", 300000, false, "d", trashid);
                return 1;
            }
        }
        SendClientMessage(playerid, Erro, "Você não está perto de um lixo");
        return 1;
    }
    if(PRESSED(KEY_CTRL_BACK))
    {
        if(PlayerInfo[playerid][Profissao] == gari && IsPlayerAttachedObjectSlotUsed(playerid, 3))
        {
            if(!GotTrash[playerid])
                return SendClientMessage(playerid, Erro, "Você não tem nenhum lixo em mãos");

            if(CPVehicleGari[playerid])
                { DestroyDynamicRaceCP(CPVehicleGari[playerid]); }

            GotTrash[playerid] = false;
            RemovePlayerAttachedObject(playerid, 3);
            SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Lixo removido de sua mão");
        }
        return 1;
    }
	return 1;
}

forward ReloadTrash(trashid);
public ReloadTrash(trashid)
{
    GariData[trashid][gd_value]++;

    switch(GariData[trashid][gd_value])
    {
        case 2: UpdateDynamic3DTextLabelText(GariLabel[trashid], 0xFFFFFFFF, "{76EE00}Lixeira\n{FFFFFF}Precione \"{FF0000}N{FFFFFF}\"");
        default: UpdateDynamic3DTextLabelText(GariLabel[trashid], 0xFFFFFFFF, "{F29B0D}Lixeira\n{FFFFFF}Precione \"{FF0000}N{FFFFFF}\"");
    }
    return 1;
}

stock Gari_DynamicRaceCP(playerid)
{
    if(PlayerInfo[playerid][Profissao] == gari)
    {
        if(IsPlayerInDynamicRaceCP(playerid, CPTrash[0]) || IsPlayerInDynamicRaceCP(playerid, CPTrash[1]) || IsPlayerInDynamicRaceCP(playerid, CPTrash[2]))
        {
            if(!PublicVehicle[LastVehicle[playerid]][pv_trash]) return 0;

            format(String, MAX_STRING, "Você entregou {FF8000}%d {FFFFFF}saco(s) de lixo(s) e recebeu {1B6302}$%s", PublicVehicle[LastVehicle[playerid]][pv_trash], IsMoney((PublicVehicle[LastVehicle[playerid]][pv_trash] * 125), "."));
            SendClientMessage(playerid, -1, String);

            PlayerInfo[playerid][Dinheiro] += ( PublicVehicle[LastVehicle[playerid]][pv_trash] * 125 );
            UpdatePlayerMoney(playerid);

            GiveBonus(playerid, 500);

            if(IsPlayerInDynamicRaceCP(playerid, CPTrash[0]))
            {
                TrashsLocal[0] += PublicVehicle[LastVehicle[playerid]][pv_trash];

                format(String, MAX_STRING, "{FFFFFF}Los Santos\n{F29B0D}%d {FFFFFF}Saco(s) de Lixo(s)", TrashsLocal[0]);
                UpdateDynamic3DTextLabelText(LabelTrash[0], 0xFFFFFFFF, String);
            }
            else if(IsPlayerInDynamicRaceCP(playerid, CPTrash[1]))
            {
                TrashsLocal[1] += PublicVehicle[LastVehicle[playerid]][pv_trash];

                format(String, MAX_STRING, "{FFFFFF}Las Venturas\n{F29B0D}%d {FFFFFF}Saco(s) de Lixo(s)", TrashsLocal[1]);
                UpdateDynamic3DTextLabelText(LabelTrash[1], 0xFFFFFFFF, String);
            }
            else if(IsPlayerInDynamicRaceCP(playerid, CPTrash[2]))
            {
                TrashsLocal[2] += PublicVehicle[LastVehicle[playerid]][pv_trash];

                format(String, MAX_STRING, "{FFFFFF}San Fierro\n{F29B0D}%d {FFFFFF}Saco(s) de Lixo(s)", TrashsLocal[2]);
                UpdateDynamic3DTextLabelText(LabelTrash[2], 0xFFFFFFFF, String);
            }

            if(LastVehicle[playerid] != -1) PublicVehicle[LastVehicle[playerid]][pv_trash] = 0;

            if(IsValidDynamicMapIcon(GariInfo[playerid][gi_mapicon1])) DestroyDynamicMapIcon(GariInfo[playerid][gi_mapicon1]);
            if(IsValidDynamicMapIcon(GariInfo[playerid][gi_mapicon2])) DestroyDynamicMapIcon(GariInfo[playerid][gi_mapicon2]);
            if(IsValidDynamicMapIcon(GariInfo[playerid][gi_mapicon3])) DestroyDynamicMapIcon(GariInfo[playerid][gi_mapicon3]);

            format(String, 10, "%d%%", returnPorcentage(PublicVehicle[LastVehicle[playerid]][pv_trash], 30.0));
            PlayerTextDrawSetString(playerid, TDPlayerLoading[playerid][1], String);
            PlayerTextDrawTextSize(playerid, TDPlayerLoading[playerid][0], (500.4 + ((104.3 * PublicVehicle[LastVehicle[playerid]][pv_trash]) / 30.0)), 0.0);
            PlayerTextDrawShow(playerid, TDPlayerLoading[playerid][0]);
            return 1;
        }
        else if(IsPlayerInDynamicRaceCP(playerid, CPVehicleGari[playerid]))
        {
            if(PublicVehicle[LastVehicle[playerid]][pv_trash] >= 30)
                return SendClientMessage(playerid, Erro, "Seu TrashMaster já tem está cheio");

            PublicVehicle[LastVehicle[playerid]][pv_trash]++;

            switch(PublicVehicle[LastVehicle[playerid]][pv_trash])
            {
                case 1:
                {
                    format(String, MAX_STRING, "Você pegou 1 saco de lixo e agora faltam apenas {F29B0D}%d", ( 30 - PublicVehicle[LastVehicle[playerid]][pv_trash] ));
                    SendClientMessage(playerid, White, String);
                }
                case 30:
                {
                    SendClientMessage(playerid, White, "Você o último saco de lixo, agora vá até o caminhão localizado no mini-mapa");
                }
                default:
                {
                    format(String, MAX_STRING, "Você pegou +1 saco de lixo e agora faltam apenas {F29B0D}%d", ( 30 - PublicVehicle[LastVehicle[playerid]][pv_trash] ));
                    SendClientMessage(playerid, White, String);
                }
            }

            ApplyAnimation(playerid, "GRENADE", "WEAPON_throwu", 4, 0, 0, 0, 0, 500);

            GotTrash[playerid] = false;
            DestroyDynamicRaceCP(CPVehicleGari[playerid]);
            RemovePlayerAttachedObject(playerid, 3);
            return 1;
        }
    }
    return 1;
}

stock CreateTrash(trashid, Float:x, Float:y, Float:z)
{
    GariLabel[trashid] = CreateDynamic3DTextLabel("{76EE00}Lixeira\n{FFFFFF}Precione \"{FF0000}N{FFFFFF}\"", 0xFFFFFFFF, x, y, z+0.80, 20.0);
    return 1;
}

stock LeftPfsGari(playerid)
{
    if(PlayerInfo[playerid][Profissao] == gari)
    {
        if(GotTrash[playerid]){
            DestroyDynamicRaceCP(CPVehicleGari[playerid]);
            RemovePlayerAttachedObject(playerid, 3);
            GotTrash[playerid] = false;
        }

        if(LastVehicle[playerid] != -1) PublicVehicle[LastVehicle[playerid]][pv_trash] = 0;

        CPVehicleGari[playerid] = 0;
    }
    return 1;
}
