#include YSI\y_hooks

new bool:passradar[MAX_PLAYERS];

hook OnGameModeInit()
{
    CreateDynamicObject(19979, 1660.14050, -358.27560, 38.97510, 0.00000, 0.00000, 180.00000);
    CreateDynamicObject(19979, 1653.96814, -1127.96460, 57.89750, 0.00000, 0.00000, -10.00000);
    CreateDynamicObject(18880, 1698.01575, -736.62671, 49.62680, 0.00000, 0.00000, 356.00000);
    CreateDynamicObject(18880, 1698.01575, -736.62671, 49.62680, 0.00000, 0.00000, 176.00000);
    CreateDynamic3DTextLabel("{FF0000}RADAR \n{F8F8FF}Velocidade Maxima Permitida \n{F6F600}120 KM/H", 0xFFFFFFFF, 1698.01575, -736.62671, 49.62680, 80.0);

    CreateDynamicObject(19979, 1319.17786, -1559.09058, 12.54520, 0.00000, 0.00000, -10.00000);
    CreateDynamicObject(19979, 1336.98560, -1260.84851, 12.53870, 0.00000, 0.00000, 180.00000);
    CreateDynamicObject(18880, 1348.61023, -1437.94104, 12.54230, 0.00000, 0.00000, 180.00000);
    CreateDynamicObject(18880, 1348.61023, -1437.94104, 12.54230, 0.00000, 0.00000, 0.00000);
    CreateDynamic3DTextLabel("{FF0000}RADAR \n{F8F8FF}Velocidade Maxima Permitida \n{F6F600}120 KM/H", 0xFFFFFFFF, 1348.61023, -1437.94104, 12.54230, 80.0);

    CreateDynamicObject(19979, -2666.29370, 1456.38000, 54.79361, 0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19979, -2696.52661, 2030.43640, 57.51340, 0.00000, 0.00000, 180.00000);
    CreateDynamicObject(18880, -2681.36499, 1697.24792, 66.84030, 0.00000, 0.00000, 359.00000);
    CreateDynamicObject(18880, -2681.36499, 1697.24792, 66.84030, 0.00000, 0.00000, 179.00000);
    CreateDynamic3DTextLabel("{FF0000}RADAR \n{F8F8FF}Velocidade Maxima Permitida \n{F6F600}120 KM/H", 0xFFFFFFFF, -2681.36499, 1697.24792, 66.84030, 80.0);

    CreateDynamicObject(19979, 258.53589, -1701.00305, 7.59140, 0.00000, 0.00000, -120.00000);
    CreateDynamicObject(19979, 732.64209, -1753.81067, 13.50590, 0.00000, 0.00000, 60.00000);
    CreateDynamicObject(18880, 521.66827, -1722.15320, 12.01470, 0.00000, 0.00000, 260.00000);
    CreateDynamicObject(18880, 521.66827, -1722.15320, 12.01470, 0.00000, 0.00000, 80.00000);
    CreateDynamic3DTextLabel("{FF0000}RADAR \n{F8F8FF}Velocidade Maxima Permitida \n{F6F600}120 KM/H", 0xFFFFFFFF, 521.66827, -1722.15320, 12.01470, 80.0);

    CreateDynamicObject(19979, 1233.52124, 1359.26428, 5.75971, 0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19979, 1200.69714, 2009.95898, 5.77830, 0.00000, 0.00000, 180.00000);
    CreateDynamicObject(18880, 1217.27795, 1689.31787, 5.28600, 0.00000, 0.00000, 359.00000);
    CreateDynamicObject(18880, 1217.27795, 1689.31787, 5.28600, 0.00000, 0.00000, 179.00000);
    CreateDynamic3DTextLabel("{FF0000}RADAR \n{F8F8FF}Velocidade Maxima Permitida \n{F6F600}120 KM/H", 0xFFFFFFFF, 1217.27795, 1689.31787, 5.28600, 80.0);

    CreateDynamicObject(19979, 1082.31335, 2522.20361, 9.78070, 0.00000, 0.00000, 55.00000);
    CreateDynamicObject(19979, 675.05402, 2533.47974, 29.55980, 0.00000, 0.00000, -30.00000);
    CreateDynamicObject(18880, 877.62048, 2618.48071, 9.88910, 0.00000, 0.00000, 250.00000);
    CreateDynamicObject(18880, 877.62048, 2618.48071, 9.88910, 0.00000, 0.00000, 70.00000);
    CreateDynamic3DTextLabel("{FF0000}RADAR \n{F8F8FF}Velocidade Maxima Permitida \n{F6F600}120 KM/H", 0xFFFFFFFF, 877.62048, 2618.48071, 9.88910, 80.0);

    CreateDynamicObject(19979, -424.02771, 589.86151, 16.29280, 0.00000, 0.00000, 75.00000);
    CreateDynamicObject(19979, -888.98932, 812.92554, 19.06410, 0.00000, 0.00000, 180.00000);
    CreateDynamicObject(18880, -628.94098, 651.85773, 15.95270, 0.00000, 0.00000, -293.00000);
    CreateDynamicObject(18880, -628.94098, 651.85773, 15.95270, 0.00000, 0.00000, -113.00000);
    CreateDynamic3DTextLabel("{FF0000}RADAR \n{F8F8FF}Velocidade Maxima Permitida \n{F6F600}120 KM/H", 0xFFFFFFFF, -628.94098, 651.85773, 15.95270, 80.0);

    CreateDynamicObject(19979, -260.65689, -1663.01379, 14.23120, 0.00000, 0.00000, -30.00000);
    CreateDynamicObject(19979, -17.28854, -1328.10632, 10.16520, 0.00000, 0.00000, 130.00000);
    CreateDynamicObject(18880, -153.37735, -1482.08020, 11.75090, 0.00000, 0.00000, -43.00000);
    CreateDynamicObject(18880, -153.37730, -1482.08020, 11.75090, 0.00000, 0.00000, -223.00000);
    CreateDynamic3DTextLabel("{FF0000}RADAR \n{F8F8FF}Velocidade Maxima Permitida \n{F6F600}120 KM/H", 0xFFFFFFFF, -153.37735, -1482.08020, 11.75090, 80.0);

    CreateDynamicObject(19979, -1239.01086, -2889.52686, 62.35080, 0.00000, 0.00000, -70.00000);
    CreateDynamicObject(19979, -776.73682, -2767.00098, 73.61650, 0.00000, 0.00000, 110.00000);
    CreateDynamicObject(18880, -1093.93665, -2857.76221, 66.70730, 0.00000, 0.00000, -90.00000);
    CreateDynamicObject(18880, -1093.93665, -2857.76221, 66.70730, 0.00000, 0.00000, 90.00000);
    CreateDynamic3DTextLabel("{FF0000}RADAR \n{F8F8FF}Velocidade Maxima Permitida \n{F6F600}120 KM/H", 0xFFFFFFFF, -1093.93665, -2857.76221, 66.70730, 80.0);

    CreateDynamicObject(19979, 1057.78455, -967.25482, 41.78440, 0.00000, 0.00000, -80.00000);
    CreateDynamicObject(19979, 1406.80811, -934.16040, 34.32120, 0.00000, 0.00000, 80.00000);
    CreateDynamicObject(18880, 1223.22632, -937.84967, 41.60010, 0.00000, 0.00000, 100.00000);
    CreateDynamicObject(18880, 1223.22632, -937.84967, 41.60010, 0.00000, 0.00000, 280.00000);
    CreateDynamic3DTextLabel("{FF0000}RADAR \n{F8F8FF}Velocidade Maxima Permitida \n{F6F600}120 KM/H", 0xFFFFFFFF, 1223.22632, -937.84967, 41.60010, 80.0);

    CreateDynamicObject(18880, -1228.66772, 1006.46289, 42.66140, 0.00000, 0.00000, -40.00000);
    CreateDynamicObject(18880, -1228.66772, 1006.46289, 42.66140, 0.00000, 0.00000, 140.00000);
    CreateDynamicObject(19979, -1133.11804, 1129.38318, 36.78950, 0.00000, 0.00000, 130.00000);
    CreateDynamicObject(19979, -1524.90833, 673.26288, 43.88560, 0.00000, 0.00000, -60.00000);
    CreateDynamic3DTextLabel("{FF0000}RADAR \n{F8F8FF}Velocidade Maxima Permitida \n{F6F600}120 KM/H", 0xFFFFFFFF, -1228.66772, 1006.46289, 42.66140, 80.0);

    CreateDynamicObject(18880, -1897.53027, 2378.34766, 47.54410, 0.00000, 0.00000, 20.00000);
    CreateDynamicObject(18880, -1897.53027, 2378.34766, 47.54410, 0.00000, 0.00000, 200.00000);
    CreateDynamicObject(19979, -1696.63037, 2196.04517, 20.11270, 0.00000, 0.00000, 20.00000);
    CreateDynamicObject(19979, -1988.60449, 2543.16504, 54.84080, 0.00000, 0.00000, 210.00000);
    CreateDynamic3DTextLabel("{FF0000}RADAR \n{F8F8FF}Velocidade Maxima Permitida \n{F6F600}120 KM/H", 0xFFFFFFFF, -1897.53027, 2378.34766, 47.54410, 80.0);

    CreateObject(18880, 1473.75635, 843.08539, 5.77170, 0.00000, 0.00000, 92.00000);
    CreateObject(18880, 1473.75635, 843.08539, 5.77170, 0.00000, 0.00000, 272.00000);
    CreateObject(19979, 1220.06458, 820.97748, 7.99580, 0.00000, 0.00000, -90.00000);
    CreateObject(19979, 1761.39734, 859.53223, 9.17750, 0.00000, 0.00000, 90.00000);
    CreateDynamic3DTextLabel("{FF0000}RADAR \n{F8F8FF}Velocidade Maxima Permitida \n{F6F600}120 KM/H", 0xFFFFFFFF, 1473.75635, 843.08539, 5.77170, 80.0);

    CreateDynamicObject(18880, 884.05408, -1400.54785, 12.26650, 0.00000, 0.00000, 271.00000);
    CreateDynamicObject(18880, 884.05408, -1400.54785, 12.26650, 0.00000, 0.00000, 91.00000);
    CreateDynamicObject(19979, 1095.26563, -1389.89111, 12.71070, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(19979, 665.37927, -1411.29089, 12.56030, 0.00000, 0.00000, -90.00000);
    CreateDynamic3DTextLabel("{FF0000}RADAR \n{F8F8FF}Velocidade Maxima Permitida \n{F6F600}90 KM/H", 0xFFFFFFFF, 884.05408, -1400.54785, 12.26654, 80.0);

    CreateDynamicObject(18880, 356.60172, -1376.75232, 13.34580, 0.00000, 0.00000, 298.00000);
    CreateDynamicObject(18880, 356.60172, -1376.75232, 13.34580, 0.00000, 0.00000, 118.00000);
    CreateDynamicObject(19979, 197.79790, -1507.65442, 11.82530, 0.00000, 0.00000, -30.00000);
    CreateDynamicObject(19979, 491.20099, -1273.59668, 14.74610, 0.00000, 0.00000, 120.00000);
    CreateDynamic3DTextLabel("{FF0000}RADAR \n{F8F8FF}Velocidade Maxima Permitida \n{F6F600}90 KM/H", 0xFFFFFFFF, 356.64810, -1376.79541, 13.34579, 80.0);

    CreateDynamicObject(19979, -142.40216, -1405.00989, 1.90036, 0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19979, -89.46280, -1054.16699, 18.81880, 0.00000, 0.00000, 190.00000);
    CreateDynamicObject(18880, -121.80331, -1204.59814, 2.15627, 0.00000, 0.00000, 157.95448);
    CreateDynamic3DTextLabel("{FF0000}RADAR \n{F8F8FF}Velocidade Maxima Permitida \n{F6F600}90 KM/H", 0xFFFFFFFF, -121.80331, -1204.59814, 2.15627, 80.0);

    CreateDynamicObject(19979, -890.74188, -1310.22351, 116.99340, 0.00000, 0.00000, -15.00000);
    CreateDynamicObject(19979, -691.16248, -1000.54602, 71.55080, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(18880, -845.09442, -1045.57422, 88.33936, 0.00000, 0.00000, 326.50021);
    CreateDynamic3DTextLabel("{FF0000}RADAR \n{F8F8FF}Velocidade Maxima Permitida \n{F6F600}90 KM/H", 0xFFFFFFFF, -845.09442, -1045.57422, 88.33936, 80.0);

    CreateDynamicObject(19979, -1764.39246, 300.58521, 6.51980, 0.00000, 0.00000, 130.00000);
    CreateDynamicObject(19979, -1793.56519, -46.21168, 13.36470, 0.00000, 0.00000, 0.00000);
    CreateDynamicObject(18880, -1817.13293, 206.84985, 14.10623, 0.00000, 0.00000, 0.00000);
    CreateDynamic3DTextLabel("{FF0000}RADAR \n{F8F8FF}Velocidade Maxima Permitida \n{F6F600}90 KM/H", 0xFFFFFFFF, -1817.13293, 206.84985, 14.10623, 80.0);

    CreateDynamicObject(19979, -1716.09814, 2725.33862, 60.37230, 0.00000, 0.00000, -90.00000);
    CreateDynamicObject(19979, -1375.77246, 2689.78613, 52.83300, 0.00000, 0.00000, 40.00000);
    CreateDynamicObject(18880, -1527.99158, 2738.29956, 63.09090, 0.00000, 0.00000, 271.00000);
    CreateDynamic3DTextLabel("{FF0000}RADAR \n{F8F8FF}Velocidade Maxima Permitida \n{F6F600}90 KM/H", 0xFFFFFFFF, -1527.99158, 2738.29956, 63.09090, 80.0);

    CreateDynamicObject(19979, 205.79570, 2761.89038, 57.80340, 0.00000, 0.00000, 80.00000);
    CreateDynamicObject(19979, -318.14020, 2625.12866, 62.73070, 0.00000, 0.00000, -100.00000);
    CreateDynamicObject(18880, -51.94530, 2644.98169, 62.04370, 0.00000, 0.00000, -90.00000);
    CreateDynamic3DTextLabel("{FF0000}RADAR \n{F8F8FF}Velocidade Maxima Permitida \n{F6F600}90 KM/H", 0xFFFFFFFF, -51.94530, 2644.98169, 62.04370, 80.0);

    CreateDynamicObject(19979, 311.32861, 1267.23987, 13.29540, 0.00000, 0.00000, -30.00000);
    CreateDynamicObject(19979, 467.58221, 1649.73438, 14.60320, 0.00000, 0.00000, 110.00000);
    CreateDynamicObject(18880, 366.77060, 1499.16675, 8.87369, 0.00000, 0.00000, 348.14325);
    CreateDynamic3DTextLabel("{FF0000}RADAR \n{F8F8FF}Velocidade Maxima Permitida \n{F6F600}90 KM/H", 0xFFFFFFFF, 366.77060, 1499.16675, 8.87369, 80.0);

    CreateDynamicObject(19979, -711.90570, -1678.86816, 49.39570, 0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19979, -725.63849, -1319.51697, 62.74820, 0.00000, 0.00000, -180.00000);
    CreateDynamicObject(18880, -708.56897, -1471.71875, 57.91850, 0.00000, 0.00000, -181.00000);
    CreateDynamic3DTextLabel("{FF0000}RADAR \n{F8F8FF}Velocidade Maxima Permitida \n{F6F600}90 KM/H", 0xFFFFFFFF, -708.56897, -1471.71875, 57.91850, 80.0);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    SetTimerEx("Radars", 200, true, "d", playerid);
    return 1;
}

forward Radars(playerid);
public Radars(playerid)
{
    /*if(IsPlayerPolice(playerid) || PlayerInfo[playerid][Profissao] == paramedic) return 0;*/

    if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
    {
        new query[100], velocid, vehicleid = GetPlayerVehicleID(playerid);

        velocid = GetVehicleSpeed(vehicleid);

        if(IsPlayerInAnyBike(vehicleid) || IsPlayerInVehicleArrais(vehicleid) || IsPlayerInVehicleCHT(vehicleid)) return 0;

        if(IsPlayerInRadar120Km(playerid))
        {
            if(!passradar[playerid])
            {
                if(velocid > 120)
                {
                    if(velocid <= 130)
                    {
                        GameTextForPlayer(playerid, "~y~RADAR", 1000, 3);
                        SendClientMessage(playerid, Yellow, "Você não recebeu multa por causa da tolerância");
                    }
                    else
                    {
                        if(IsPlayerInVehicleA(vehicleid))
                        {
                            if(!PlayerInfo[playerid][cnh_a])
                            {
                                GameTextForPlayer(playerid, "~r~RADAR", 1000, 3);
                                SendClientMessage(playerid, Red, "Você não tem CNH Categoria A");
                                SendClientMessage(playerid, Red, "Por esse motivo recebeu +1 estrela e agora está sendo procurado pela polícia");
                                PlayerInfo[playerid][Estrelas]++;

                                PlayerTextDrawSetString(playerid, PlayerBarStatus[playerid][1], IsMoney(PlayerInfo[playerid][Estrelas], "."));
                            }
                            else
                            {
                                PlayerInfo[playerid][fines_a]++;

                                if(PlayerInfo[playerid][fines_a] >= 20)
                                {
                                    GameTextForPlayer(playerid, "~r~RADAR", 1000, 3);
                                    SendClientMessage(playerid, Red, "Você recebeu 20 multas e isso resultou na perda sua CNH Categoria A");
                                    PlayerInfo[playerid][cnh_a] = false;
                                    PlayerInfo[playerid][fines_a] = 0;
                                }
                                else
                                {
                                    GameTextForPlayer(playerid, "~y~RADAR", 1000, 3);
                                    SendClientMessage(playerid, Yellow, "Você passou acima da tolerância e recebeu uma multa em sua CNH Categoria A");
                                }
                                mysql_format(IDConexao, query, sizeof(query), "UPDATE `CNH` SET `fines_a`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][fines_a], PlayerInfo[playerid][ID]);
                            }
                        }
                        else if(IsPlayerInVehicleB(vehicleid))
                        {
                            if(!PlayerInfo[playerid][cnh_b])
                            {
                                GameTextForPlayer(playerid, "~r~RADAR", 1000, 3);
                                SendClientMessage(playerid, Red, "Você não tem CNH Categoria B");
                                SendClientMessage(playerid, Red, "Por esse motivo recebeu +1 estrela e agora está sendo procurado pela polícia");
                                PlayerInfo[playerid][Estrelas]++;

                                PlayerTextDrawSetString(playerid, PlayerBarStatus[playerid][1], IsMoney(PlayerInfo[playerid][Estrelas], "."));
                            }
                            else
                            {
                                PlayerInfo[playerid][fines_b]++;

                                if(PlayerInfo[playerid][fines_b] >= 20)
                                {
                                    GameTextForPlayer(playerid, "~r~RADAR", 1000, 3);
                                    SendClientMessage(playerid, Red, "Você recebeu 20 multas e isso resultou na perda sua CNH Categoria B");
                                    PlayerInfo[playerid][cnh_b] = false;
                                    PlayerInfo[playerid][fines_b] = 0;
                                }
                                else
                                {
                                    GameTextForPlayer(playerid, "~y~RADAR", 1000, 3);
                                    SendClientMessage(playerid, Yellow, "Você passou acima da tolerância e recebeu uma multa em sua CNH Categoria B");
                                }
                                mysql_format(IDConexao, query, sizeof(query), "UPDATE `CNH` SET `fines_b`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][fines_b], PlayerInfo[playerid][ID]);
                            }
                        }
                        else if(IsPlayerInVehicleC(vehicleid))
                        {
                            if(!PlayerInfo[playerid][cnh_c])
                            {
                                GameTextForPlayer(playerid, "~r~RADAR", 1000, 3);
                                SendClientMessage(playerid, Red, "Você não tem CNH Categoria C");
                                SendClientMessage(playerid, Red, "Por esse motivo recebeu +1 estrela e agora está sendo procurado pela polícia");
                                PlayerInfo[playerid][Estrelas]++;

                                PlayerTextDrawSetString(playerid, PlayerBarStatus[playerid][1], IsMoney(PlayerInfo[playerid][Estrelas], "."));
                            }
                            else
                            {
                                PlayerInfo[playerid][fines_c]++;

                                if(PlayerInfo[playerid][fines_c] >= 20)
                                {
                                    GameTextForPlayer(playerid, "~r~RADAR", 1000, 3);
                                    SendClientMessage(playerid, Red, "Você recebeu 20 multas e isso resultou na perda sua CNH Categoria C");
                                    PlayerInfo[playerid][cnh_c] = false;
                                    PlayerInfo[playerid][fines_c] = 0;
                                }
                                else
                                {
                                    GameTextForPlayer(playerid, "~y~RADAR", 1000, 3);
                                    SendClientMessage(playerid, Yellow, "Você passou acima da tolerância e recebeu uma multa em sua CNH Categoria C");
                                }
                                mysql_format(IDConexao, query, sizeof(query), "UPDATE `CNH` SET `fines_c`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][fines_c], PlayerInfo[playerid][ID]);
                            }
                        }
                        mysql_query(IDConexao, query);
                    }
                }
                else
                {
                    GameTextForPlayer(playerid, "~g~RADAR", 1000, 3);
                }
                PlayerPlaySound(playerid, 1132, 0.0, 0.0, 0.0);
                passradar[playerid] = true;
            }
        }
        else if(IsPlayerInRadar90Km(playerid))
        {
            if(!passradar[playerid])
            {
                if(velocid > 90)
                {
                    if(velocid <= 90)
                    {
                        GameTextForPlayer(playerid, "~y~RADAR", 1000, 3);
                        SendClientMessage(playerid, Yellow, "Você não recebeu multa por causa da tolerância");
                    }
                    else
                    {
                        if(IsPlayerInVehicleA(vehicleid))
                        {
                            if(!PlayerInfo[playerid][cnh_a])
                            {
                                GameTextForPlayer(playerid, "~r~RADAR", 1000, 3);
                                SendClientMessage(playerid, Red, "Você não tem CNH Categoria A");
                                SendClientMessage(playerid, Red, "Por esse motivo recebeu +1 estrela e agora está sendo procurado pela polícia");
                                PlayerInfo[playerid][Estrelas]++;

                                PlayerTextDrawSetString(playerid, PlayerBarStatus[playerid][1], IsMoney(PlayerInfo[playerid][Estrelas], "."));
                            }
                            else
                            {
                                PlayerInfo[playerid][fines_a]++;

                                if(PlayerInfo[playerid][fines_a] >= 20)
                                {
                                    GameTextForPlayer(playerid, "~r~RADAR", 1000, 3);
                                    SendClientMessage(playerid, Red, "Você recebeu 20 multas e isso resultou na perda sua CNH Categoria A");
                                    PlayerInfo[playerid][cnh_a] = false;
                                    PlayerInfo[playerid][fines_a] = 0;
                                }
                                else
                                {
                                    GameTextForPlayer(playerid, "~y~RADAR", 1000, 3);
                                    SendClientMessage(playerid, Yellow, "Você passou acima da tolerância e recebeu uma multa em sua CNH Categoria A");
                                }
                                mysql_format(IDConexao, query, sizeof(query), "UPDATE `CNH` SET `fines_a`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][fines_a], PlayerInfo[playerid][ID]);
                            }
                        }
                        else if(IsPlayerInVehicleB(vehicleid))
                        {
                            if(!PlayerInfo[playerid][cnh_b])
                            {
                                GameTextForPlayer(playerid, "~r~RADAR", 1000, 3);
                                SendClientMessage(playerid, Red, "Você não tem CNH Categoria B");
                                SendClientMessage(playerid, Red, "Por esse motivo recebeu +1 estrela e agora está sendo procurado pela polícia");
                                PlayerInfo[playerid][Estrelas]++;

                                PlayerTextDrawSetString(playerid, PlayerBarStatus[playerid][1], IsMoney(PlayerInfo[playerid][Estrelas], "."));
                            }
                            else
                            {
                                PlayerInfo[playerid][fines_b]++;

                                if(PlayerInfo[playerid][fines_b] >= 20)
                                {
                                    GameTextForPlayer(playerid, "~r~RADAR", 1000, 3);
                                    SendClientMessage(playerid, Red, "Você recebeu 20 multas e isso resultou na perda sua CNH Categoria B");
                                    PlayerInfo[playerid][cnh_b] = false;
                                    PlayerInfo[playerid][fines_b] = 0;
                                }
                                else
                                {
                                    GameTextForPlayer(playerid, "~y~RADAR", 1000, 3);
                                    SendClientMessage(playerid, Yellow, "Você passou acima da tolerância e recebeu uma multa em sua CNH Categoria B");
                                }
                                mysql_format(IDConexao, query, sizeof(query), "UPDATE `CNH` SET `fines_b`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][fines_b], PlayerInfo[playerid][ID]);
                            }
                        }
                        else if(IsPlayerInVehicleC(vehicleid))
                        {
                            if(!PlayerInfo[playerid][cnh_c])
                            {
                                GameTextForPlayer(playerid, "~r~RADAR", 1000, 3);
                                SendClientMessage(playerid, Red, "Você não tem CNH Categoria C");
                                SendClientMessage(playerid, Red, "Por esse motivo recebeu +1 estrela e agora está sendo procurado pela polícia");
                                PlayerInfo[playerid][Estrelas]++;

                                PlayerTextDrawSetString(playerid, PlayerBarStatus[playerid][1], IsMoney(PlayerInfo[playerid][Estrelas], "."));
                            }
                            else
                            {
                                PlayerInfo[playerid][fines_c]++;

                                if(PlayerInfo[playerid][fines_c] >= 20)
                                {
                                    GameTextForPlayer(playerid, "~r~RADAR", 1000, 3);
                                    SendClientMessage(playerid, Red, "Você recebeu 20 multas e isso resultou na perda sua CNH Categoria C");
                                    PlayerInfo[playerid][cnh_c] = false;
                                    PlayerInfo[playerid][fines_c] = 0;
                                }
                                else
                                {
                                    GameTextForPlayer(playerid, "~y~RADAR", 1000, 3);
                                    SendClientMessage(playerid, Yellow, "Você passou acima da tolerância e recebeu uma multa em sua CNH Categoria C");
                                }
                                mysql_format(IDConexao, query, sizeof(query), "UPDATE `CNH` SET `fines_c`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][fines_c], PlayerInfo[playerid][ID]);
                            }
                        }
                        mysql_query(IDConexao, query);
                    }
                }
                else
                {
                    GameTextForPlayer(playerid, "~g~RADAR", 1000, 3);
                }
                PlayerPlaySound(playerid, 1132, 0.0, 0.0, 0.0);
                passradar[playerid] = true;
            }
        }
        else
        {
            passradar[playerid] = false;
        }
    }
    return 1;
}

stock IsPlayerInRadar120Km(playerid)
{
    if(IsPlayerInCircle(playerid, 1698.01575, -736.62671, 20)   ||
       IsPlayerInCircle(playerid, 1348.61023, -1437.94104, 20)  ||
       IsPlayerInCircle(playerid, -2681.36499, 1697.24792, 20)  ||
       IsPlayerInCircle(playerid, 521.66827, -1722.15320, 20)   ||
       IsPlayerInCircle(playerid, 1217.27795, 1689.31787,20)    ||
       IsPlayerInCircle(playerid, 877.62048, 2618.48071, 20)    ||
       IsPlayerInCircle(playerid, -628.94098, 651.85773, 20)    ||
       IsPlayerInCircle(playerid, 1473.75635, 843.08539, 20)    ||
       IsPlayerInCircle(playerid, -1897.53027, 2378.34766, 20)  ||
       IsPlayerInCircle(playerid, -1228.66772, 1006.46289, 20)  ||
       IsPlayerInCircle(playerid, -153.37735, -1482.08020, 20)  ||
       IsPlayerInCircle(playerid, -1093.93665, -2857.76221, 20) ||
       IsPlayerInCircle(playerid, 1223.22632, -937.84967, 20)   ) return true;
    else return false;
}

stock IsPlayerInRadar90Km(playerid)
{
    if(IsPlayerInCircle(playerid, 884.05408, -1400.54785, 20)  ||
       IsPlayerInCircle(playerid, 356.64810, -1376.79541,  20) ||
       IsPlayerInCircle(playerid, -121.80331, -1204.59814, 20) ||
       IsPlayerInCircle(playerid, -845.09442, -1045.57422, 20) ||
       IsPlayerInCircle(playerid, -1817.13293, 206.84985, 20)  ||
       IsPlayerInCircle(playerid, -1527.99158, 2738.29956, 20) ||
       IsPlayerInCircle(playerid, -1817.13293, 206.84985, 20)  ||
       IsPlayerInCircle(playerid, -51.94530, 2644.98169, 20)   ||
       IsPlayerInCircle(playerid, 366.77060, 1499.16675, 20)   ||
       IsPlayerInCircle(playerid, -708.56897, -1471.71875, 20)  ) return true;
    else return false;
}

stock IsPlayerInCircle(playerid,Float:x,Float:y,radius)
{
    if(GetPlayerDistanceToPoint2(playerid,Float:x,Float:y) < radius)
    {
        return 1;
    }
    return 0;
}

stock GetPlayerDistanceToPoint2(playerid,Float:x,Float:y)
{
    new Float:x1,Float:y1,Float:z1; GetPlayerPos(playerid,x1,y1,z1);
    new Float:tmpdis = floatsqroot(floatpower(floatabs(floatsub(x,x1)),2)+
    floatpower(floatabs(floatsub(y,y1)),2));
    return floatround(tmpdis);
}
