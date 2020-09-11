#include YSI\y_hooks

enum e_ee
{
    Float:ee_x,
    Float:ee_y,
    Float:ee_z,
    ee_name[50],
    Float:ee_lx,
    Float:ee_ly,
    Float:ee_lz,
    ee_interior
};

new EnterExit[MAX_PLACE_PUBLIC][e_ee] =
{
    {-100.0, -100.0, -100.0, "N/A", -100.0, -100.0, -100.0, 3}, //Remove bug
    {1154.08, -1771.98, 16.59, "Agencia de Empregos de Los Santos", 1494.49, 1303.66, 1093.29, 3},
    {937.84, 1733.19, 8.85, "Agencia de Empregos de Las Venturas", 1494.49, 1303.66, 1093.29, 3},
    {-2171.81, 252.08, 35.33, "Agencia de Empregos de San Fierro", 1494.49, 1303.66, 1093.29, 3},
    {1481.06, -1770.95, 18.79, "Prefeitura de Los Santos", 389.39, 173.85, 1008.38, 3},
    {2447.06, 2376.23, 12.16, "Prefeitura de Las Venturas", 389.39, 173.85, 1008.38, 3},
    {-2765.87, 375.58, 6.33, "Prefeitura de San Fierro", 389.39, 173.85, 1008.38, 3},
    {1554.86, -1675.66, 16.19, "Departamento de Polícia de Los Santos", 246.87, 63.06, 1003.64, 6},
    {2290.12, 2430.97, 10.82, "Departamento de Polícia de Las Venturas", 246.87, 63.06, 1003.64, 6},
    {-1605.58, 710.84, 13.86, "Departamento de Polícia de San Fierro", 246.87, 63.06, 1003.64, 6},
    {627.76, -571.72, 17.55, "Departamento de Polícia de Dillimore", 246.87, 63.06, 1003.64, 6},
    {-217.55, 979.16, 19.50, "Departamento de Polícia de Fort Carson", 246.87, 63.06, 1003.64, 6},
    {-2162.06, -2385.79, 30.62, "Departamento de Polícia de Angel Pine", 246.87, 63.06, 1003.64, 6},
    {-1390.03, 2638.01, 55.98, "Departamento de Polícia de El Quebrados", 246.87, 63.06, 1003.64, 6},
    {1172.67, -1323.31, 15.40, "Hospital de Los Santos Market", 1020.66, 993.22, 15.12, 0},
    {2029.76, -1402.84, 17.25, "Hospital de Los Santos Jefferson", 1020.66, 993.22, 15.12, 0},
    {1607.35, 1815.63, 10.82, "Hospital de Las Venturas", 1020.66, 993.22, 15.12, 0},
    {-2655.06, 639.14, 14.45, "Hospital de San Fierro", 1020.66, 993.22, 15.12, 0},
    {-1514.82, 2520.32, 55.91, "Hospital de El Quebrados", 1020.66, 993.22, 15.12, 0},
    {1241.80, 327.10 ,19.75, "Hospital de Montgomery", 1020.66, 993.22, 15.12, 0},
    {-320.07, 1049.26, 20.34, "Hospital de Fort Carson", 1020.66, 993.22, 15.12, 0},
    {-2223.16, -2293.68, 31.67, "Hospital de Angel Pine", 1020.66, 993.22, 15.12, 0},
    {1778.30, -1663.53, 14.43, "Banco de Los Santos", 354.14, 167.22, 1019.98, 3},
    {2388.67, 2466.04, 10.82, "Banco de Las Venturas", 354.14, 167.22, 1019.98, 3},
    {-2649.83, 376.00, 6.15, "Banco de San Fierro", 354.14, 167.22, 1019.98, 3},
    {-180.38, 1133.15, 19.74, "Banco de Fort Carson", 354.14, 167.22, 1019.98, 3},
    {1372.92, 405.24, 19.95, "Banco de Montgomery", 354.14, 167.22, 1019.98, 3},
    {2302.95, -16.27, 26.48, "Banco de Palomino Creek", 354.14, 167.22, 1019.98, 3},
    {-828.06, 1503.61, 19.75, "Banco de Las Barrancas", 354.14, 167.22, 1019.98, 3},
    {-1480.82, 2592.30, 55.83, "Banco de El Quebrados", 354.14, 167.22, 1019.98, 3},
    {207.77, -62.58, 1.64, "Banco de Blueberry", 354.14, 167.22, 1019.98, 3},
    {1798.47, -1578.31, 14.08, "Imobiliaria de Los Santos", 363.60, 166.44, 1025.79, 3},
    {2413.23, 1123.83, 10.82, "Imobiliaria de Las Venturas", 363.60, 166.44, 1025.79, 3},
    {-1881.12, 822.75, 35.17, "Imobiliaria de San Fierro", 363.60, 166.44, 1025.79, 3},
    {1519.04, -1453.58, 14.20, "Auto Escola de Los Santos", -2026.94, -104.71, 1035.17, 3},
    {2183.24, 2295.22, 10.82, "Auto Escola de Las Venturas", -2026.94, -104.71, 1035.17, 3},
    {-2026.59, -101.34, 35.16, "Auto Escola de San Fierro", -2026.94, -104.71, 1035.17, 3},
    {1310.14, -1367.80, 13.54, "Detran de Los Santos", 833.85, 7.04, 1004.18, 3},
    {1173.16, 1349.00, 10.92, "Detran de Las Venturas", 833.85, 7.04, 1004.18, 3},
    {-2720.63, 127.73, 7.03, "Detran de San Fierro", 833.85, 7.04, 1004.18, 3},
    {1022.45, -1121.59, 23.87, "Área VIP de Los Santos", -794.83, 495.93, 1376.19, 1},
    {2015.07, 1106.63, 10.82, "Área VIP de Las Venturas", -794.83, 495.93, 1376.19, 1},
    {-2664.41, -7.44, 6.13, "Área VIP de San Fierro", -794.83, 495.93, 1376.19, 1},
    {-2521.30, -623.65, 132.77, "Light", 231.28, 1822.78, 7.41, 0}
};

new t_enterexit[MAX_PLAYERS];
new Entering[MAX_PLAYERS];
new PlayerText:CarregandoInterior[MAX_PLAYERS];

hook OnPlayerConnect(playerid)
{
    CarregandoInterior[playerid] = CreatePlayerTextDraw(playerid, 252.800033, 399.066589, "Carregando_Interior...");
    PlayerTextDrawLetterSize(playerid, CarregandoInterior[playerid], 0.400000, 1.600000);
    PlayerTextDrawAlignment(playerid, CarregandoInterior[playerid], 1);
    PlayerTextDrawColor(playerid, CarregandoInterior[playerid], -1);
    PlayerTextDrawSetShadow(playerid, CarregandoInterior[playerid], 0);
    PlayerTextDrawSetOutline(playerid, CarregandoInterior[playerid], -1);
    PlayerTextDrawBackgroundColor(playerid, CarregandoInterior[playerid], 255);
    PlayerTextDrawFont(playerid, CarregandoInterior[playerid], 1);
    PlayerTextDrawSetProportional(playerid, CarregandoInterior[playerid], 1);
    PlayerTextDrawSetShadow(playerid, CarregandoInterior[playerid], 0);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_SECONDARY_ATTACK)
    {
        if(Entering[playerid])
        {
            if(IsPlayerInRangeOfPoint(playerid, 2.0, EnterExit[Entering[playerid]][ee_lx], EnterExit[Entering[playerid]][ee_ly], EnterExit[Entering[playerid]][ee_lz]))
            {
                KillTimer(t_enterexit[playerid]);
                SetPlayerInterior(playerid, 0);
                SetPlayerPos(playerid, EnterExit[Entering[playerid]][ee_x], EnterExit[Entering[playerid]][ee_y], EnterExit[Entering[playerid]][ee_z]);
                format(String, 128, "Você acabou de sair do(a) %s", EnterExit[Entering[playerid]][ee_name]);
                SendClientMessage(playerid, Yellow, String);

                Entering[playerid] = 0;
                return 1;
            }
        }
        else
        {
            for(new i = 0; i < MAX_PLACE_PUBLIC; i++)
            {
                if(IsPlayerInRangeOfPoint(playerid, 2.0, EnterExit[i][ee_x], EnterExit[i][ee_y], EnterExit[i][ee_z]))
                {
                    switch(i)
                    {
                        case 39..41:
                        {
                            if(!IsPlayerVip(playerid) && !IsPlayerIntern(playerid))
                                return SendClientMessage(playerid, Erro, "Você não tem permissão");
                        }
                        case 13..20:
                        {
                            TogglePlayerControllable(playerid, false);
                            PlayerTextDrawSetString(playerid, CarregandoInterior[playerid], "Carregando_Interior...");
                            PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
                            t_enterexit[playerid] = SetTimerEx("LoadInterior", 2000, false, "d", playerid);
                        }
                    }

                    Entering[playerid] = i;
                    SetPlayerInterior(playerid, EnterExit[i][ee_interior]);
                    SetPlayerPos(playerid, EnterExit[i][ee_lx], EnterExit[i][ee_ly], EnterExit[i][ee_lz]);
                    format(String, 128, "Você acabou de entrar no(a) %s", EnterExit[i][ee_name]);
                    SendClientMessage(playerid, Yellow, String);
                    return 1;
                }
            }
        }
        return 1;
    }
	return 1;
}

hook OnPlayerDisconnect(playerid)
{
    KillTimer(t_enterexit[playerid]);
    Entering[playerid] = 0;
    return 1;
}

forward LoadInterior(playerid);
public LoadInterior(playerid)
{
    TogglePlayerControllable(playerid, true);
    PlayerTextDrawHide(playerid, CarregandoInterior[playerid]);
    return 1;
}

stock LeftEnterExit(playerid)
{
    if(!Entering[playerid])
        return 0;

    PlayerInfo[playerid][PosX] = EnterExit[Entering[playerid]][ee_x];
    PlayerInfo[playerid][PosY] = EnterExit[Entering[playerid]][ee_y];
    PlayerInfo[playerid][PosZ] = EnterExit[Entering[playerid]][ee_z];
    PlayerInfo[playerid][PosA] = 0.0;
    return 1;
}

/* Commands */

CMD:entrar(playerid)
{
    for(new i = 0; i < MAX_PLACE_PUBLIC; i++)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, EnterExit[i][ee_x], EnterExit[i][ee_y], EnterExit[i][ee_z]))
        {
            switch(i)
            {
                case 39..41:
                {
                    if(!IsPlayerVip(playerid) && !IsPlayerIntern(playerid))
                        return SendClientMessage(playerid, Erro, "Você não tem permissão");
                }
                case 13..20:
                {
                    TogglePlayerControllable(playerid, false);
                    PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
                    t_enterexit[playerid] = SetTimerEx("LoadInterior", 2000, false, "d", playerid);
                }
            }

            Entering[playerid] = i;
            SetPlayerInterior(playerid, EnterExit[i][ee_interior]);
            SetPlayerPos(playerid, EnterExit[i][ee_lx], EnterExit[i][ee_ly], EnterExit[i][ee_lz]);
            format(String, 128, "Você acabou de entrar no(a) %s", EnterExit[i][ee_name]);
            SendClientMessage(playerid, Yellow, String);
            return 1;
        }
    }
    return SendClientMessage(playerid, Erro, "Você está longe da porta, chegue mais perto");
}
CMD:sair(playerid)
{
    if(!IsPlayerInRangeOfPoint(playerid, 2.0, EnterExit[Entering[playerid]][ee_lx], EnterExit[Entering[playerid]][ee_ly], EnterExit[Entering[playerid]][ee_lz]))
        return SendClientMessage(playerid, Erro, "Você está longe da porta, chegue mais perto");

    KillTimer(t_enterexit[playerid]);
    SetPlayerInterior(playerid, 0);
    SetPlayerPos(playerid, EnterExit[Entering[playerid]][ee_x], EnterExit[Entering[playerid]][ee_y], EnterExit[Entering[playerid]][ee_z]);
    format(String, 128, "Você acabou de sair do(a) %s", EnterExit[Entering[playerid]][ee_name]);
    SendClientMessage(playerid, Yellow, String);

    Entering[playerid] = 0;
    return 1;
}
