#include YSI\y_hooks

enum e_petroleum
{
    Float:ptl_x,
    Float:ptl_y,
    Float:ptl_z,
    ptl_value
};

new Petroleum[MAX_PLAYERS][e_petroleum];
new tanker_mapicon[MAX_PLAYERS];

hook OnGameModeInit()
{
    AddStaticVehicleEx(584, 293.6473, 1479.4601, 11.5491, -117.0000, -1, -1, -1);
    AddStaticVehicleEx(584, 293.1074, 1474.1301, 11.6669, -117.0000, -1, -1, -1);
    AddStaticVehicleEx(584, 292.6587, 1469.5249, 11.5962, -119.0000, -1, -1, -1);
    AddStaticVehicleEx(584, 292.8142, 1463.5654, 11.7170, -117.0000, -1, -1, -1);
    AddStaticVehicleEx(584, 294.1655, 1457.5743, 12.1646, -117.0000, -1, -1, -1);
    AddStaticVehicleEx(584, 293.0652, 1453.2302, 11.7824, -118.0000, -1, -1, -1);
    AddStaticVehicleEx(584, 340.2242, 1478.3892, 8.1732, -180.0000, -1, -1, -1);
    AddStaticVehicleEx(584, 340.2765, 1456.8361, 9.5973, -179.0000, -1, -1, -1);

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

    CreateDynamic3DTextLabel("{00FF00}Entrada", 0xFFFFFFFF, 288.4768, 1416.2633, 10.3689, 50.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
    CreateDynamic3DTextLabel("{FF0000}Saída", 0xFFFFFFFF, 288.7573, 1405.6627, 10.3537, 50.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
    CreateDynamic3DTextLabel("{CCCCCC}Área de Carregamento\n{FFFFFF}Precione \"{FF0000}N{FFFFFF}\"", 0xFFFFFFFF, 234.7237, 1415.5150, 10.5859, 60.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    RemoveBuildingForPlayer(playerid, 16086, 232.2891, 1434.4844, 13.5000, 0.25);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(IsValidDynamicMapIcon(tanker_mapicon[playerid])) DestroyDynamicMapIcon(tanker_mapicon[playerid]);

    Petroleum[playerid][ptl_value] = 0;
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(PRESSED(KEY_NO) && PlayerInfo[playerid][Profissao] == tanker)
    {
        if(IsPlayerInRangeOfPoint(playerid, 15.0, 234.7237, 1415.5150, 10.5859))
        {
            new vehicleid = GetPlayerVehicleID(playerid);

            if(Petroleum[playerid][ptl_value])
                return SendClientMessage(playerid, Erro,"Seu caminhão já está carregado");

            if(GetVehicleModel(GetVehicleTrailer(vehicleid)) != 584 || !IsTrailerAttachedToVehicle(vehicleid))
                return SendClientMessage(playerid, Erro, "Você não está com o trailer de petróleo");

            new txt[1000];
            strcat(txt, "{FFFFFF}FortCarson {00FF00}$300 \n");
            strcat(txt, "{FFFFFF}Bony County {00FF00}$450 \n");
            strcat(txt, "{FFFFFF}Redsands West {00FF00}$600 \n");
            strcat(txt, "{FFFFFF}Tierra Roubada I {00FF00}$750 \n");
            strcat(txt, "{FFFFFF}Montgomery {00FF00}$800 \n");
            strcat(txt, "{FFFFFF}Las Venturas {00FF00}$850 \n");
            strcat(txt, "{FFFFFF}Valle Ocultado {00FF00}$900 \n");
            strcat(txt, "{FFFFFF}Tierra Roubada II {00FF00}$1.050 \n");
            strcat(txt, "{FFFFFF}The Emerald Isle {00FF00}$1.350 \n");
            strcat(txt, "{FFFFFF}Prickle Pine {00FF00}$1.400 \n");
            strcat(txt, "{FFFFFF}Dillimore {00FF00}$1.450 \n");
            strcat(txt, "{FFFFFF}Temple {00FF00}$1.650 \n");
            strcat(txt, "{FFFFFF}Easter Basin {00FF00}$1.650 \n");
            strcat(txt, "{FFFFFF}Flint County {00FF00}$1.850 \n");
            strcat(txt, "{FFFFFF}Juniper Hollow {00FF00}$2.000 \n");
            strcat(txt, "{FFFFFF}Idlewood {00FF00}$2.500 \n");
            strcat(txt, "{FFFFFF}Whetstone {00FF00}$2.750 \n");
            strcat(txt, "{FFFFFF}Angel Pine {00FF00}$3.000 \n");
            ShowPlayerDialog(playerid, tanker_fuel, DIALOG_STYLE_LIST, "{CCCCCC}Postos de Combustível", txt, "Escolher", "Cancelar");
            return 1;
        }
        else if(IsPlayerInRangeOfPoint(playerid, 20.0, Petroleum[playerid][ptl_x], Petroleum[playerid][ptl_y], Petroleum[playerid][ptl_z]))
        {
            if(!Petroleum[playerid][ptl_value])
                return SendClientMessage(playerid, Erro, "Seu veículo não está carregado");

            new vehicleid = GetPlayerVehicleID(playerid);
            new vehmod = GetVehicleModel(GetVehicleTrailer(vehicleid));

            if(!vehmod)
                return SendClientMessage(playerid, Erro, "Você não está com Petrol trailer");

            if(vehmod != 584)
                return SendClientMessage(playerid, Erro, "Você não está com Petrol trailer");

            if(IsValidDynamicMapIcon(tanker_mapicon[playerid])) DestroyDynamicMapIcon(tanker_mapicon[playerid]);

            format(String, MAX_STRING, "Caminhão descarregado e vocé ganhou $%s", IsMoney(Petroleum[playerid][ptl_value], "."));
            SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);

            GiveBonus(playerid, 500);

            PlayerInfo[playerid][Dinheiro] += Petroleum[playerid][ptl_value];
            UpdatePlayerMoney(playerid);

            Petroleum[playerid][ptl_value] = 0;
            SetVehicleToRespawn(GetVehicleTrailer(vehicleid));
            return 1;
        }
        return 1;
    }
	return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == tanker_fuel && response)
    {
        switch(listitem)
        {
            case 0:
            {
                Petroleum[playerid][ptl_x] = 70.2273;
                Petroleum[playerid][ptl_y] = 1218.1195;
                Petroleum[playerid][ptl_z] = 18.8120;
                Petroleum[playerid][ptl_value] = 300;
            }
            case 1:
            {
                Petroleum[playerid][ptl_x] = 611.9534;
                Petroleum[playerid][ptl_y] = 1694.7549;
                Petroleum[playerid][ptl_z] = 6.9922;
                Petroleum[playerid][ptl_value] = 450;
            }
            case 2:
            {
                Petroleum[playerid][ptl_x] = 1595.6119;
                Petroleum[playerid][ptl_y] = 2199.3965;
                Petroleum[playerid][ptl_z] = 10.8203;
                Petroleum[playerid][ptl_value] = 600;
            }
            case 3:
            {
                Petroleum[playerid][ptl_x] = -1471.4187;
                Petroleum[playerid][ptl_y] = 1862.7681;
                Petroleum[playerid][ptl_z] = 32.6328;
                Petroleum[playerid][ptl_value] = 750;
            }
            case 4:
            {
                Petroleum[playerid][ptl_x] = 1381.6041;
                Petroleum[playerid][ptl_y] = 459.9374;
                Petroleum[playerid][ptl_z] = 20.3452;
                Petroleum[playerid][ptl_value] = 800;
            }
            case 5:
            {
                Petroleum[playerid][ptl_x] = 2114.9490;
                Petroleum[playerid][ptl_y] = 920.1870;
                Petroleum[playerid][ptl_z] = 10.8203;
                Petroleum[playerid][ptl_value] = 850;
            }
            case 6:
            {
                Petroleum[playerid][ptl_x] = -737.1921;
                Petroleum[playerid][ptl_y] = 2744.6824;
                Petroleum[playerid][ptl_z] = 47.2266;
                Petroleum[playerid][ptl_value] = 900;
            }
            case 7:
            {
                Petroleum[playerid][ptl_x] = -1328.4478;
                Petroleum[playerid][ptl_y] = 2677.4004;
                Petroleum[playerid][ptl_z] = 50.0625;
                Petroleum[playerid][ptl_value] = 1050;
            }
            case 8:
            {
                Petroleum[playerid][ptl_x] = 2202.3323;
                Petroleum[playerid][ptl_y] = 2473.6587;
                Petroleum[playerid][ptl_z] = 10.8203;
                Petroleum[playerid][ptl_value] = 1350;
            }
            case 9:
            {
                Petroleum[playerid][ptl_x] = 2147.4045;
                Petroleum[playerid][ptl_y] = 2747.9360;
                Petroleum[playerid][ptl_z] = 10.8203;
                Petroleum[playerid][ptl_value] = 1400;
            }
            case 10:
            {
                Petroleum[playerid][ptl_x] = 655.5648;
                Petroleum[playerid][ptl_y] = -565.1674;
                Petroleum[playerid][ptl_z] = 16.3359;
                Petroleum[playerid][ptl_value] += 1450;
            }
            case 11:
            {
                Petroleum[playerid][ptl_x] = 1004.6576;
                Petroleum[playerid][ptl_y] = -936.7656;
                Petroleum[playerid][ptl_z] = 42.3281;
                Petroleum[playerid][ptl_value] = 1650;
            }
            case 12:
            {
                Petroleum[playerid][ptl_x] = -1677.2299;
                Petroleum[playerid][ptl_y] = 411.9955;
                Petroleum[playerid][ptl_z] = 7.1797;
                Petroleum[playerid][ptl_value] = 1650;
            }
            case 13:
            {
                Petroleum[playerid][ptl_x] = -90.8110;
                Petroleum[playerid][ptl_y] = -1168.4828;
                Petroleum[playerid][ptl_z] = 2.4241;
                Petroleum[playerid][ptl_value] = 1850;
            }
            case 14:
            {
                Petroleum[playerid][ptl_x] = -2410.0356;
                Petroleum[playerid][ptl_y] = 976.0281;
                Petroleum[playerid][ptl_z] = 45.4251;
                Petroleum[playerid][ptl_value] = 2000;
            }
            case 15:
            {
                Petroleum[playerid][ptl_x] = 1942.3728;
                Petroleum[playerid][ptl_y] = -1772.8689;
                Petroleum[playerid][ptl_z] = 13.6406;
                Petroleum[playerid][ptl_value] = 2500;
            }
            case 16:
            {
                Petroleum[playerid][ptl_x] = -1606.4144;
                Petroleum[playerid][ptl_y] = -2713.7371;
                Petroleum[playerid][ptl_z] = 48.5335;
                Petroleum[playerid][ptl_value] = 2750;
            }
            case 17:
            {
                Petroleum[playerid][ptl_x] = -2244.3455;
                Petroleum[playerid][ptl_y] = -2561.0513;
                Petroleum[playerid][ptl_z] = 31.9219;
                Petroleum[playerid][ptl_value] = 3000;
            }
        }

        tanker_mapicon[playerid] = CreateDynamicMapIcon(Petroleum[playerid][ptl_x], Petroleum[playerid][ptl_y], Petroleum[playerid][ptl_z], 53, -1, -1, -1, playerid, -1.0, MAPICON_GLOBAL, -1, 1);

        TogglePlayerControllable(playerid, false);
        SetTimerEx("LoadingTanker", 1000, false, "d", playerid);
    }
    return 1;
}

forward LoadingTanker(playerid);
public LoadingTanker(playerid)
{
    TogglePlayerControllable(playerid, true);
    GameTextForPlayer(playerid, "~w~Carregado", 2500, 1);
    SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Seu caminhão foi carregado");
    SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Para descarregá-lo vá até o checkpoint vermelho em seu mini-mapa e Precione \"{FF0000}N{808080}\"");
    return 1;
}
