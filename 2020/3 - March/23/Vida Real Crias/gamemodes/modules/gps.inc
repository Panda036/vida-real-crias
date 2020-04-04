#include YSI\y_hooks

#define DIALOG_GPS                  5060
#define DIALOG_GPS_PP               5061
#define DIALOG_GPS_PUBLIC           5062
#define DIALOG_GPS_PUBLIC_AGENCY    5063
#define DIALOG_GPS_PUBLIC_DP        5064
#define DIALOG_GPS_PUBLIC_PF        5065
#define DIALOG_GPS_PUBLIC_BK        5066
#define DIALOG_GPS_PUBLIC_AV        5067
#define DIALOG_GPS_PUBLIC_DT        5068
#define DIALOG_GPS_PUBLIC_AE        5069
#define DIALOG_GPS_PUBLIC_CN        5070
#define DIALOG_GPS_PUBLIC_IB        5071
#define DIALOG_GPS_PUBLIC_HP        5072
#define DIALOG_GPS_PUBLIC_ARENA     5073

new cps_gps[MAX_PLAYERS];

hook OnPlayerDisconnect(playerid, reason)
{
    if(cps_gps[playerid])
    {
        DestroyDynamicCP(cps_gps[playerid]);
    }
    return 1;
}

hook OnPlayerEnterCheckpoint(playerid)
{
    if(IsPlayerInDynamicCP(playerid, cps_gps[playerid]))
    {
        DestroyDynamicCP(cps_gps[playerid]);
        SendClientMessage(playerid, Green, "Você chegou até o local marcado");
        return 1;
    }
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case DIALOG_GPS:
        {
            if(!response) return 1;

            switch(listitem)
            {
                case 0:
                {
                    new query[200], txt[100], idhouse[MAX_PLAYERS] = -1, businessid[MAX_PLAYERS] = -1;

                    mysql_format(IDConexao, query, sizeof(query), "SELECT * FROM `Houses` WHERE `Nome`='%s'", PlayerInfo[playerid][Nome]);
                    mysql_query(IDConexao, query);

                    if(cache_num_rows() != 0)
                        { cache_get_value_int(0, "ID", idhouse[playerid]); }

                    mysql_format(IDConexao, query, sizeof(query), "SELECT * FROM `Business` WHERE `Nome`='%s'", PlayerInfo[playerid][Nome]);
                    mysql_query(IDConexao, query);

                    if(cache_num_rows() != 0)
                        { cache_get_value_int(0, "ID", businessid[playerid]); }

                    if(idhouse[playerid] == -1)
                    {
                        strcat(txt, "{FFFFFF}Casa {FF0000}N/A \n");
                    }
                    else
                    {
                        format(String, sizeof(String), "{FFFFFF}Casa ID {FF0000}%d \n", idhouse[playerid]);
                        strcat(txt, String);
                    }
                    if(businessid[playerid] == -1)
                    {
                        strcat(txt, "{FFFFFF}Empresa {FF0000}N/A \n");
                    }
                    else
                    {
                        format(String, sizeof(String), "{FFFFFF}Empresa ID {FF0000}%d \n", businessid[playerid]);
                        strcat(txt, String);
                    }

                    ShowPlayerDialog(playerid, DIALOG_GPS_PP, DIALOG_STYLE_LIST, "{FF0000}GPS", txt, "Continuar", "Cancelar");
                    return 1;
                }
                case 1:
                {
                    new txt[300];
                    strcat(txt, "{FFFFFF}Agencias de Empregos\n");
                    strcat(txt, "{FFFFFF}Departamentos\n");
                    strcat(txt, "{FFFFFF}Prefeituras\n");
                    strcat(txt, "{FFFFFF}Bancos\n");
                    strcat(txt, "{FFFFFF}Áreas Vips\n");
                    strcat(txt, "{FFFFFF}Detrans\n");
                    strcat(txt, "{FFFFFF}Auto Escolas\n");
                    strcat(txt, "{FFFFFF}Concessionárias\n");
                    strcat(txt, "{FFFFFF}Imobiliárias\n");
                    strcat(txt, "{FFFFFF}Hospitais\n");
                    strcat(txt, "{FFFFFF}Arenas\n");
                    ShowPlayerDialog(playerid, DIALOG_GPS_PUBLIC, DIALOG_STYLE_LIST, "{FF0000}GPS", txt, "Continuar", "Cancelar");
                    return 1;
                }
            }
            return 1;
        }
        case DIALOG_GPS_PP:
        {
            if(!response) return 1;

            switch(listitem)
            {
                case 0:
                {
                    new query[200], idhouse[MAX_PLAYERS] = -1;

                    mysql_format(IDConexao, query, sizeof(query), "SELECT * FROM `Houses` WHERE `Nome`='%s'", PlayerInfo[playerid][Nome]);
                    mysql_query(IDConexao, query);

                    if(cache_num_rows() != 0)
                        { cache_get_value_int(0, "ID", idhouse[playerid]); }

                    if(idhouse[playerid] == -1) return 0;

                    CreateCPGPS(playerid, HouseInfo[idhouse[playerid]][iconx], HouseInfo[idhouse[playerid]][icony], HouseInfo[idhouse[playerid]][iconz]);
                    return 1;
                }
                case 1:
                {
                    new query[200], businessid[MAX_PLAYERS] = -1;

                    mysql_format(IDConexao, query, sizeof(query), "SELECT * FROM `Business` WHERE `Nome`='%s'", PlayerInfo[playerid][Nome]);
                    mysql_query(IDConexao, query);

                    if(cache_num_rows() != 0)
                        { cache_get_value_int(0, "ID", businessid[playerid]);  }

                    if(businessid[playerid] == -1) return 0;

                    CreateCPGPS(playerid, BusinessInfo[businessid[playerid]][cIconX], BusinessInfo[businessid[playerid]][cIconY], BusinessInfo[businessid[playerid]][cIconZ]);
                    return 1;
                }
            }
            return 1;
        }
        case DIALOG_GPS_PUBLIC:
        {
            if(!response) return 1;

            switch(listitem)
            {
                case 0:
                {
                    new txt[75];
                    strcat(txt, "{FFFFFF}Los Santos\n");
                    strcat(txt, "{FFFFFF}Las Venturas\n");
                    strcat(txt, "{FFFFFF}San Fierro\n");
                    ShowPlayerDialog(playerid, DIALOG_GPS_PUBLIC_AGENCY, DIALOG_STYLE_LIST, "{FF0000}GPS - Agencias de Empregos", txt, "Continuar", "Cancelar");
                    return 1;
                }
                case 1:
                {
                    new txt[175];
                    strcat(txt, "{FFFFFF}Los Santos\n");
                    strcat(txt, "{FFFFFF}Las Venturas\n");
                    strcat(txt, "{FFFFFF}San Fierro\n");
                    strcat(txt, "{FFFFFF}Dillimore\n");
                    strcat(txt, "{FFFFFF}Fort Carson\n");
                    strcat(txt, "{FFFFFF}Angel Pine\n");
                    strcat(txt, "{FFFFFF}El Quebrados\n");
                    ShowPlayerDialog(playerid, DIALOG_GPS_PUBLIC_DP, DIALOG_STYLE_LIST, "{FF0000}GPS - Departamentos", txt, "Continuar", "Cancelar");
                    return 1;
                }
                case 2:
                {
                    new txt[75];
                    strcat(txt, "{FFFFFF}Los Santos\n");
                    strcat(txt, "{FFFFFF}Las Venturas\n");
                    strcat(txt, "{FFFFFF}San Fierro\n");
                    ShowPlayerDialog(playerid, DIALOG_GPS_PUBLIC_PF, DIALOG_STYLE_LIST, "{FF0000}GPS - Prefeituras", txt, "Continuar", "Cancelar");
                    return 1;
                }
                case 3:
                {
                    new txt[75];
                    strcat(txt, "{FFFFFF}Los Santos\n");
                    strcat(txt, "{FFFFFF}Las Venturas\n");
                    strcat(txt, "{FFFFFF}San Fierro\n");
                    strcat(txt, "{FFFFFF}Fort Carson\n");
                    strcat(txt, "{FFFFFF}El Quebrados\n");
                    strcat(txt, "{FFFFFF}Montgomery\n");
                    strcat(txt, "{FFFFFF}Palomino Creek\n");
                    strcat(txt, "{FFFFFF}Las Barrancas\n");
                    strcat(txt, "{FFFFFF}Blueberry\n");
                    ShowPlayerDialog(playerid, DIALOG_GPS_PUBLIC_BK, DIALOG_STYLE_LIST, "{FF0000}GPS - Bancos", txt, "Continuar", "Cancelar");
                    return 1;
                }
                case 4:
                {
                    new txt[75];
                    strcat(txt, "{FFFFFF}Los Santos\n");
                    strcat(txt, "{FFFFFF}Las Venturas\n");
                    strcat(txt, "{FFFFFF}San Fierro\n");
                    ShowPlayerDialog(playerid, DIALOG_GPS_PUBLIC_AV, DIALOG_STYLE_LIST, "{FF0000}GPS - Áreas Vips", txt, "Continuar", "Cancelar");
                    return 1;
                }
                case 5:
                {
                    new txt[75];
                    strcat(txt, "{FFFFFF}Los Santos\n");
                    strcat(txt, "{FFFFFF}Las Venturas\n");
                    strcat(txt, "{FFFFFF}San Fierro\n");
                    ShowPlayerDialog(playerid, DIALOG_GPS_PUBLIC_DT, DIALOG_STYLE_LIST, "{FF0000}GPS - Detrans", txt, "Continuar", "Cancelar");
                    return 1;
                }
                case 6:
                {
                    new txt[75];
                    strcat(txt, "{FFFFFF}Los Santos\n");
                    strcat(txt, "{FFFFFF}Las Venturas\n");
                    strcat(txt, "{FFFFFF}San Fierro\n");
                    ShowPlayerDialog(playerid, DIALOG_GPS_PUBLIC_AE, DIALOG_STYLE_LIST, "{FF0000}GPS - Auto Escolas", txt, "Continuar", "Cancelar");
                    return 1;
                }
                case 7:
                {
                    new txt[150];
                    strcat(txt, "{FFFFFF}Los Santos\n");
                    strcat(txt, "{FFFFFF}Las Venturas\n");
                    strcat(txt, "{FFFFFF}San Fierro\n");
                    strcat(txt, "{FFFFFF}Aeroporto Abandonado\n");
                    strcat(txt, "{FFFFFF}Bayside\n");
                    ShowPlayerDialog(playerid, DIALOG_GPS_PUBLIC_CN, DIALOG_STYLE_LIST, "{FF0000}GPS - Concessionárias", txt, "Continuar", "Cancelar");
                    return 1;
                }
                case 8:
                {
                    new txt[75];
                    strcat(txt, "{FFFFFF}Los Santos\n");
                    strcat(txt, "{FFFFFF}Las Venturas\n");
                    strcat(txt, "{FFFFFF}San Fierro\n");
                    ShowPlayerDialog(playerid, DIALOG_GPS_PUBLIC_IB, DIALOG_STYLE_LIST, "{FF0000}GPS - Imobiliárias", txt, "Continuar", "Cancelar");
                    return 1;
                }
                case 9:
                {
                    new txt[185];
                    strcat(txt, "{FFFFFF}Los Santos Market\n");
                    strcat(txt, "{FFFFFF}Los Santos Jefferson\n");
                    strcat(txt, "{FFFFFF}Las Venturas\n");
                    strcat(txt, "{FFFFFF}San Fierro\n");
                    strcat(txt, "{FFFFFF}El Quebrados\n");
                    strcat(txt, "{FFFFFF}Montgomery\n");
                    strcat(txt, "{FFFFFF}Fort Carson\n");
                    strcat(txt, "{FFFFFF}Angel Pine\n");
                    ShowPlayerDialog(playerid, DIALOG_GPS_PUBLIC_HP, DIALOG_STYLE_LIST, "{FF0000}GPS - Hospitais", txt, "Continuar", "Cancelar");
                    return 1;
                }
                case 10:
                {
                    new txt[75];
                    strcat(txt, "{FFFFFF}Los Santos\n");
                    strcat(txt, "{FFFFFF}Las Venturas\n");
                    strcat(txt, "{FFFFFF}San Fierro\n");
                    ShowPlayerDialog(playerid, DIALOG_GPS_PUBLIC_ARENA, DIALOG_STYLE_LIST, "{FF0000}GPS - Arenas", txt, "Continuar", "Cancelar");
                    return 1;
                }
            }
            return 1;
        }
        case DIALOG_GPS_PUBLIC_AGENCY:
        {
            if(!response) return 1;

            switch(listitem)
            {
                case 0: CreateCPGPS(playerid, 1154.08, -1771.98, 16.59);
                case 1: CreateCPGPS(playerid, 937.84, 1733.19, 8.85);
                case 2: CreateCPGPS(playerid, -2171.81, 252.08, 35.33);
            }
            return 1;
        }
        case DIALOG_GPS_PUBLIC_DP:
        {
            if(!response) return 1;

            switch(listitem)
            {
                case 0: CreateCPGPS(playerid, 1554.86, -1675.66, 16.19);
                case 1: CreateCPGPS(playerid, 2290.12, 2430.97, 10.82);
                case 2: CreateCPGPS(playerid, -1605.58, 710.84, 13.86);
                case 3: CreateCPGPS(playerid, 627.76, -571.72, 17.55);
                case 4: CreateCPGPS(playerid, -217.55, 979.16, 19.50);
                case 5: CreateCPGPS(playerid, -2162.06, -2385.79, 30.62);
                case 6: CreateCPGPS(playerid, -1390.03, 2638.01, 55.98);
            }
            return 1;
        }
        case DIALOG_GPS_PUBLIC_PF:
        {
            if(!response) return 1;

            switch(listitem)
            {
                case 0: CreateCPGPS(playerid, 1481.06, -1770.95, 18.79);
                case 1: CreateCPGPS(playerid, 2447.06, 2376.23, 12.16);
                case 2: CreateCPGPS(playerid, -2765.87, 375.58, 6.33);
            }
            return 1;
        }
        case DIALOG_GPS_PUBLIC_BK:
        {
            if(!response) return 1;

            switch(listitem)
            {
                case 0: CreateCPGPS(playerid, 1778.30, -1663.53, 14.43);
                case 1: CreateCPGPS(playerid, 2388.67, 2466.04, 10.82);
                case 2: CreateCPGPS(playerid, -2649.83, 376.00, 6.15);
                case 3: CreateCPGPS(playerid, -180.38, 1133.15, 19.74);
                case 4: CreateCPGPS(playerid, -1480.82, 2592.30, 55.83);
                case 5: CreateCPGPS(playerid, 1372.92, 405.24, 19.95);
                case 6: CreateCPGPS(playerid, 2302.95, -16.27, 26.48);
                case 7: CreateCPGPS(playerid, -828.06,1503.61, 19.75);
                case 8: CreateCPGPS(playerid, 207.77, -62.58, 1.64);
            }
            return 1;
        }
        case DIALOG_GPS_PUBLIC_AV:
        {
            if(!response) return 1;

            switch(listitem)
            {
                case 0: CreateCPGPS(playerid, 1022.45, -1121.59, 23.87);
                case 1: CreateCPGPS(playerid, 2015.07, 1106.63, 10.82);
                case 2: CreateCPGPS(playerid, -2664.41, -7.44, 6.13);
            }
            return 1;
        }
        case DIALOG_GPS_PUBLIC_DT:
        {
            if(!response) return 1;

            switch(listitem)
            {
                case 0: CreateCPGPS(playerid, 1310.14, -1367.80, 13.54);
                case 1: CreateCPGPS(playerid, 1173.16, 1349.00, 10.92);
                case 2: CreateCPGPS(playerid, -2720.63, 127.73, 7.03);
            }
            return 1;
        }
        case DIALOG_GPS_PUBLIC_AE:
        {
            if(!response) return 1;

            switch(listitem)
            {
                case 0: CreateCPGPS(playerid, 1519.04, -1453.58, 14.20);
                case 1: CreateCPGPS(playerid, 2183.24, 2295.22, 10.82);
                case 2: CreateCPGPS(playerid, -2026.59, -101.34, 35.16);
            }
            return 1;
        }
        case DIALOG_GPS_PUBLIC_CN:
        {
            if(!response) return 1;

            switch(listitem)
            {
                case 0: CreateCPGPS(playerid, 542.14, -1292.03, 17.24);
                case 1: CreateCPGPS(playerid, 2200.84, 1393.88, 11.06);
                case 2: CreateCPGPS(playerid, -1966.39, 293.95, 35.46);
                case 3: CreateCPGPS(playerid, 411.18, 2533.50, 19.14);
                case 4: CreateCPGPS(playerid, -2184.94, 2413.02, 5.15);
            }
            return 1;
        }
        case DIALOG_GPS_PUBLIC_IB:
        {
            if(!response) return 1;

            switch(listitem)
            {
                case 0: CreateCPGPS(playerid, 1798.47, -1578.31, 14.08);
                case 1: CreateCPGPS(playerid, 2413.23, 1123.83, 10.82);
                case 2: CreateCPGPS(playerid, -1881.12, 822.75, 35.17);
            }
            return 1;
        }
        case DIALOG_GPS_PUBLIC_HP:
        {
            if(!response) return 1;

            switch(listitem)
            {
                case 0: CreateCPGPS(playerid, 1172.67, -1323.31, 15.40);
                case 1: CreateCPGPS(playerid, 2029.76, -1402.84, 17.25);
                case 2: CreateCPGPS(playerid, 1607.35, 1815.63, 10.82);
                case 3: CreateCPGPS(playerid, -2655.06, 639.14, 14.45);
                case 4: CreateCPGPS(playerid, -1514.82, 2520.32, 55.91);
                case 5: CreateCPGPS(playerid, 1241.80, 327.10, 19.75);
                case 6: CreateCPGPS(playerid, -320.07, 1049.26, 20.34);
                case 7: CreateCPGPS(playerid, -2223.16, -2293.68, 31.67);
            }
            return 1;
        }
        case DIALOG_GPS_PUBLIC_ARENA:
        {
            if(!response) return 1;

            switch(listitem)
            {
                case 0: CreateCPGPS(playerid, 2695.55, -1704.70, 11.84);
                case 1: CreateCPGPS(playerid, 1099.56, 1601.52, 12.54);
                case 2: CreateCPGPS(playerid, -2110.82, -444.22, 38.73);
            }
            return 1;
        }
    }
	return 1;
}

stock CreateCPGPS(playerid, Float:x, Float:y, Float:z)
{
    if(cps_gps[playerid]) DestroyDynamicCP(cps_gps[playerid]);

    cps_gps[playerid] = CreateDynamicCP(x, y, z, 1.0, -1, -1, playerid, -1.0);

    SendClientMessage(playerid, Green, "Foi marcado um checkpoint vermelho em seu mini-mapa");
    return 1;
}

//Commands

CMD:gps(playerid)
{
    new txt[60];
    strcat(txt, "{FFFFFF}Propriedades\n");
    strcat(txt, "{FFFFFF}Locais Públicos\n");
    ShowPlayerDialog(playerid, DIALOG_GPS, DIALOG_STYLE_LIST, "{FF0000}GPS", txt, "Continuar", "Cancelar");
    return 1;
}
CMD:desmarcar(playerid)
{
    if(cps_gps[playerid])
        { DestroyDynamicCP(cps_gps[playerid]); }

    SendClientMessage(playerid, Green, "Foi desmarcado o checkpoint vermelho do seu mini-mapa");
    return 1;
}
