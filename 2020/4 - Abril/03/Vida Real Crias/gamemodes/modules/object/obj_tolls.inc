#include YSI\y_hooks

new tolls[18];
new warningtolls[MAX_PLAYERS];

hook OnGameModeInit()
{
    //Las Venturas - East Los Santos
    CreateDynamicObject(966, 1730.57678, 523.17059, 27.00000, 180.00000, 180.00000, 340.00000);
    CreateDynamicObject(966, 1722.15771, 526.19427, 27.00000, 180.00000, 180.00000, 340.00000);
    CreateDynamicObject(966, 1748.66772, 527.46814, 26.46100, 0.00000, 0.00000, 340.00000);
    CreateDynamicObject(966, 1757.11108, 524.43115, 26.46100, 0.00000, 0.00000, 340.00000);
    CreateDynamicObject(9623, 1748.28162, 522.32770, 29.56790, -3.00000, 0.00000, 340.00000);
    CreateDynamicObject(9623, 1731.06323, 528.60321, 29.56790, 3.00000, 0.00000, 160.00000);
    tolls[0] = CreateDynamicObject(968, 1721.96448, 526.26001, 27.88260, 0.00000, 90.00000, 340.00000);
    tolls[1] = CreateDynamicObject(968, 1730.37842, 523.23138, 27.88260, 0.00000, 90.00000, 340.00000);
    tolls[2] = CreateDynamicObject(968, 1748.85510, 527.40021, 27.26000, 0.00000, -90.00000, 340.00000);
    tolls[3] = CreateDynamicObject(968, 1757.30566, 524.35742, 27.26000, 0.00000, -90.00000, 340.00000);

    //Red Conty - Bone Conty
    CreateDynamicObject(4638, 521.35492, 471.37091, 19.62000, 0.00000, 0.00000, 126.00000);
    CreateDynamicObject(966, 521.99109, 469.36441, 17.92770, 0.00000, 0.00000, 35.26000);
    CreateDynamicObject(966, 520.73273, 473.36200, 17.92770, 0.00000, 0.00000, 215.46001);
    tolls[4] = CreateDynamicObject(968, 520.55988, 473.22699, 18.72980, 0.00000, 90.00000, 35.50000);
    tolls[5] = CreateDynamicObject(968, 522.15997, 469.50000, 18.72980, 0.00000, 90.00000, -144.70000);

    //Blueberry Acres - Red Conty
    CreateDynamicObject(4638, -168.84436, 364.06293, 12.77970, 0.00000, 0.00000, 75.50000);
    CreateDynamicObject(966, -167.75095, 365.85535, 11.07530, 0.00000, 0.00000, 165.00000);
    CreateDynamicObject(966, -169.90297, 362.28769, 11.07530, 0.00000, 0.00000, -15.00000);
    tolls[6] = CreateDynamicObject(968, -169.70210, 362.25891, 11.88740, 0.00000, -90.00000, -15.00000);
    tolls[7] = CreateDynamicObject(968, -167.94810, 365.91171, 11.88740, 0.00000, -90.00000, 165.00000);

    //San Fierro - Fort Carson
    CreateDynamicObject(9623, -1531.31433, 687.44269, 46.39290, 1.48000, 0.00000, 316.44791);
    CreateDynamicObject(966, -1527.49414, 690.26813, 43.94470, 0.00000, 0.00000, 135.00000);
    CreateDynamicObject(966, -1535.74817, 684.80426, 43.62470, 0.00000, 0.00000, -45.00000);
    CreateDynamicObject(19870, -1520.83838, 677.69659, 45.60860, 0.00000, 0.00000, 136.00000);
    CreateDynamicObject(19870, -1537.97131, 694.55090, 45.60860, 0.00000, 0.00000, 136.00000);
    tolls[8] = CreateDynamicObject(968, -1527.63647, 690.41492, 44.79950, 0.00000, 90.00000, 315.00000);
    tolls[9] = CreateDynamicObject(968, -1535.60205, 684.65912, 44.47950, 0.00000, 90.00000, 135.00000);

    //Entrando Bayside
    CreateDynamicObject(9623, -2274.15259, 2677.26855, 57.30800, 1.00000, 0.00000, 93.00000);
    CreateDynamicObject(966, -2279.14063, 2677.42017, 54.77990, 0.00000, 0.00000, -88.00000);
    CreateDynamicObject(966, -2278.82617, 2668.70190, 54.77990, 0.00000, 0.00000, -88.00000);
    tolls[10] = CreateDynamicObject(968, -2278.80737, 2668.49512, 55.59570, 0.00000, 90.00000, 92.00000);
    tolls[11] = CreateDynamicObject(968, -2279.14722, 2677.21484, 55.59570, 0.00000, 90.00000, 92.00000);

    //Saindo Bayside
    CreateDynamicObject(9623, -2001.67969, 2568.13989, 57.02846,   0.00000, 0.00000, 47.19812);
    CreateDynamicObject(966, -1999.05981, 2563.73535, 54.54320,   0.00000, 0.00000, 48.00000);
    CreateDynamicObject(966, -1993.05090, 2570.18921, 54.44320,   0.00000, 0.00000, 48.00000);
    tolls[12] = CreateDynamicObject(968, -1998.93347, 2563.89136, 55.35820,   0.00000, 90.00000, -132.00000);
    tolls[13] = CreateDynamicObject(968, -1992.90918, 2570.33740, 55.27820,   0.00000, 90.00000, -132.00000);

    //Bayside - San Fierro
    CreateDynamicObject(966, -2671.06592, 1279.74658, 54.42230, 0.00000, 0.00000, 180.00000);
    CreateDynamicObject(966, -2680.57471, 1279.74854, 54.42230, 0.00000, 0.00000, 180.00000);
    CreateDynamicObject(966, -2682.73828, 1269.61670, 54.42230, 0.00000, 0.00000, 0.00000);
    CreateDynamicObject(966, -2691.50366, 1269.65723, 54.42230, 0.00000, 0.00000, 0.00000);
    tolls[14] = CreateDynamicObject(968, -2671.27368, 1279.74084, 55.28190, 0.00000, 90.00000, 0.00000);
    tolls[15] = CreateDynamicObject(968, -2680.77393, 1279.73425, 55.28190, 0.00000, 90.00000, 0.00000);
    tolls[16] = CreateDynamicObject(968, -2682.53857, 1269.62988, 55.28190, 0.00000, 90.00000, 180.00000);
    tolls[17] = CreateDynamicObject(968, -2691.32251, 1269.65332, 55.28190, 0.00000, 90.00000, 180.00000);
	return 1;
}

hook OnPlayerConnect(playerid)
{
    SetTimerEx("CheckTollsNonStop", 500, true, "d", playerid);
    return 1;
}

forward CheckTollsNonStop(playerid);
public CheckTollsNonStop(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 5.0, 1727.2482, 530.4234, 26.6058))
    {
        if(warningtolls[playerid] == 0 && PlayerInfo[playerid][nonstop] && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle(playerid))
        {
            SetDynamicObjectRot(tolls[0], 0.00000, 18.00000, 340.00000);
            SetTimer("closed_right_lv_ls", 5000, false);

            warningtolls[playerid] = 1;
            PlayerInfo[playerid][nonstop] -= 25;

            format(String, sizeof(String), "Foi descontado do Sem Parar, seu novo saldo é $%s", IsMoney(PlayerInfo[playerid][nonstop], "."));
            SendClientMessage(playerid, Green, "Você pagou $25 no pedágio, Boa viajem!");
            SendClientMessage(playerid, Green, String);

            new _str[100];
            mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Itens` SET `nonstop`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][nonstop], PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, _str);
        }
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, 1735.7852, 526.9039, 26.6058))
    {
        if(warningtolls[playerid] == 0  && PlayerInfo[playerid][nonstop] && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle(playerid))
        {
            SetDynamicObjectRot(tolls[1], 0.00000, 18.00000, 340.00000);
            SetTimer("closed_left_lv_ls", 5000, false);

            warningtolls[playerid] = 1;
            PlayerInfo[playerid][nonstop] -= 25;

            format(String, sizeof(String), "Foi descontado do Sem Parar, seu novo saldo é $%s", IsMoney(PlayerInfo[playerid][nonstop], "."));
            SendClientMessage(playerid, Green, "Você pagou $25 no pedágio, Boa viajem!");
            SendClientMessage(playerid, Green, String);

            new _str[100];
            mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Itens` SET `nonstop`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][nonstop], PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, _str);
        }
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, 1743.3595, 522.5642, 26.6058))
    {
        if(warningtolls[playerid] == 0  && PlayerInfo[playerid][nonstop] && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle(playerid))
        {
            SetDynamicObjectRot(tolls[2], 0.00000, -18.00000, 340.00000);
            SetTimer("closed_right_ls_lv", 5000, false);

            warningtolls[playerid] = 1;
            PlayerInfo[playerid][nonstop] -= 25;

            format(String, sizeof(String), "Foi descontado do Sem Parar, seu novo saldo é $%s", IsMoney(PlayerInfo[playerid][nonstop], "."));
            SendClientMessage(playerid, Green, "Você pagou $25 no pedágio, Boa viajem!");
            SendClientMessage(playerid, Green, String);

            new _str[100];
            mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Itens` SET `nonstop`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][nonstop], PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, _str);
        }
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, 1751.6979, 519.8131, 26.6058))
    {
        if(warningtolls[playerid] == 0  && PlayerInfo[playerid][nonstop] && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle(playerid))
        {
            SetDynamicObjectRot(tolls[3], 0.00000, -18.00000, 340.00000);
            SetTimer("closed_left_ls_lv", 5000, false);

            warningtolls[playerid] = 1;
            PlayerInfo[playerid][nonstop] -= 25;

            format(String, sizeof(String), "Foi descontado do Sem Parar, seu novo saldo é $%s", IsMoney(PlayerInfo[playerid][nonstop], "."));
            SendClientMessage(playerid, Green, "Você pagou $25 no pedágio, Boa viajem!");
            SendClientMessage(playerid, Green, String);

            new _str[100];
            mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Itens` SET `nonstop`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][nonstop], PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, _str);
        }
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, 528.5143, 468.5071, 18.9297))
    {
        if(warningtolls[playerid] == 0  && PlayerInfo[playerid][nonstop] && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle(playerid))
        {
            SetDynamicObjectRot(tolls[4], 0.00000, 18.00000, 35.50000);
            SetTimer("closed_bb_lv", 5000, false);

            warningtolls[playerid] = 1;
            PlayerInfo[playerid][nonstop] -= 25;

            format(String, sizeof(String), "Foi descontado do Sem Parar, seu novo saldo é $%s", IsMoney(PlayerInfo[playerid][nonstop], "."));
            SendClientMessage(playerid, Green, "Você pagou $25 no pedágio, Boa viajem!");
            SendClientMessage(playerid, Green, String);

            new _str[100];
            mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Itens` SET `nonstop`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][nonstop], PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, _str);
        }
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, 513.8133, 474.9756, 18.9297))
    {
        if(warningtolls[playerid] == 0  && PlayerInfo[playerid][nonstop] && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle(playerid))
        {
            SetDynamicObjectRot(tolls[5], 0.00000, 18.00000, -144.00000);
            SetTimer("closed_lv_bb", 5000, false);

            warningtolls[playerid] = 1;
            PlayerInfo[playerid][nonstop] -= 25;

            format(String, sizeof(String), "Foi descontado do Sem Parar, seu novo saldo é $%s", IsMoney(PlayerInfo[playerid][nonstop], "."));
            SendClientMessage(playerid, Green, "Você pagou $25 no pedágio, Boa viajem!");
            SendClientMessage(playerid, Green, String);

            new _str[100];
            mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Itens` SET `nonstop`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][nonstop], PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, _str);
        }
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, -172.0047, 368.6565, 11.0716))
    {
        if(warningtolls[playerid] == 0  && PlayerInfo[playerid][nonstop] && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle(playerid))
        {
            SetDynamicObjectRot(tolls[6], 0.00000, -18.00000, -15.00000);
            SetTimer("closed_fc_ba", 5000, false);

            warningtolls[playerid] = 1;
            PlayerInfo[playerid][nonstop] -= 25;

            format(String, sizeof(String), "Foi descontado do Sem Parar, seu novo saldo é $%s", IsMoney(PlayerInfo[playerid][nonstop], "."));
            SendClientMessage(playerid, Green, "Você pagou $25 no pedágio, Boa viajem!");
            SendClientMessage(playerid, Green, String);

            new _str[100];
            mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Itens` SET `nonstop`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][nonstop], PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, _str);
        }
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, -166.3996, 358.6230, 11.0716))
    {
        if(warningtolls[playerid] == 0  && PlayerInfo[playerid][nonstop] && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle(playerid))
        {
            SetDynamicObjectRot(tolls[7], 0.00000, -18.00000, 165.00000);
            SetTimer("closed_ba_fc", 5000, false);

            warningtolls[playerid] = 1;
            PlayerInfo[playerid][nonstop] -= 25;

            format(String, sizeof(String), "Foi descontado do Sem Parar, seu novo saldo é $%s", IsMoney(PlayerInfo[playerid][nonstop], "."));
            SendClientMessage(playerid, Green, "Você pagou $25 no pedágio, Boa viajem!");
            SendClientMessage(playerid, Green, String);

            new _str[100];
            mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Itens` SET `nonstop`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][nonstop], PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, _str);
        }
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, -1529.0376, 682.9033, 43.8730))
    {
        if(warningtolls[playerid] == 0  && PlayerInfo[playerid][nonstop] && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle(playerid))
        {
            SetDynamicObjectRot(tolls[8], 0.00000, 18.00000, 315.00000);
            SetTimer("closed_sf_fc", 5000, false);

            warningtolls[playerid] = 1;
            PlayerInfo[playerid][nonstop] -= 25;

            format(String, sizeof(String), "Foi descontado do Sem Parar, seu novo saldo é $%s", IsMoney(PlayerInfo[playerid][nonstop], "."));
            SendClientMessage(playerid, Green, "Você pagou $25 no pedágio, Boa viajem!");
            SendClientMessage(playerid, Green, String);

            new _str[100];
            mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Itens` SET `nonstop`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][nonstop], PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, _str);
        }
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, -1534.7046, 691.2211, 43.8730))
    {
        if(warningtolls[playerid] == 0  && PlayerInfo[playerid][nonstop] && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle(playerid))
        {
            SetDynamicObjectRot(tolls[9], 0.00000, 18.00000, 135.00000);
            SetTimer("closed_fc_sf", 5000, false);

            warningtolls[playerid] = 1;
            PlayerInfo[playerid][nonstop] -= 25;

            format(String, sizeof(String), "Foi descontado do Sem Parar, seu novo saldo é $%s", IsMoney(PlayerInfo[playerid][nonstop], "."));
            SendClientMessage(playerid, Green, "Você pagou $25 no pedágio, Boa viajem!");
            SendClientMessage(playerid, Green, String);

            new _str[100];
            mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Itens` SET `nonstop`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][nonstop], PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, _str);
        }
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, -2272.8396, 2672.6208, 54.4125))
    {
        if(warningtolls[playerid] == 0  && PlayerInfo[playerid][nonstop] && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle(playerid))
        {
            SetDynamicObjectRot(tolls[10], 0.00000, 18.00000, 92.00000);
            SetTimer("closed_left_eq_bs", 5000, false);

            warningtolls[playerid] = 1;
            PlayerInfo[playerid][nonstop] -= 25;

            format(String, sizeof(String), "Foi descontado do Sem Parar, seu novo saldo é $%s", IsMoney(PlayerInfo[playerid][nonstop], "."));
            SendClientMessage(playerid, Green, "Você pagou $25 no pedágio, Boa viajem!");
            SendClientMessage(playerid, Green, String);

            new _str[100];
            mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Itens` SET `nonstop`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][nonstop], PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, _str);
        }
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, -2272.7207, 2681.8459, 54.4125))
    {
        if(warningtolls[playerid] == 0  && PlayerInfo[playerid][nonstop] && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle(playerid))
        {
            SetDynamicObjectRot(tolls[11], 0.00000, 18.00000, 92.00000);
            SetTimer("closed_right_eq_bs", 5000, false);

            warningtolls[playerid] = 1;
            PlayerInfo[playerid][nonstop] -= 25;

            format(String, sizeof(String), "Foi descontado do Sem Parar, seu novo saldo é $%s", IsMoney(PlayerInfo[playerid][nonstop], "."));
            SendClientMessage(playerid, Green, "Você pagou $25 no pedágio, Boa viajem!");
            SendClientMessage(playerid, Green, String);

            new _str[100];
            mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Itens` SET `nonstop`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][nonstop], PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, _str);
        }
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, -2005.5844, 2565.1606, 54.1843))
    {
        if(warningtolls[playerid] == 0  && PlayerInfo[playerid][nonstop] && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle(playerid))
        {
            SetDynamicObjectRot(tolls[12], 0.00000, 18.00000, -132.00000);
            SetTimer("closed_right_bs_eq", 5000, false);

            warningtolls[playerid] = 1;
            PlayerInfo[playerid][nonstop] -= 25;

            format(String, sizeof(String), "Foi descontado do Sem Parar, seu novo saldo é $%s", IsMoney(PlayerInfo[playerid][nonstop], "."));
            SendClientMessage(playerid, Green, "Você pagou $25 no pedágio, Boa viajem!");
            SendClientMessage(playerid, Green, String);

            new _str[100];
            mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Itens` SET `nonstop`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][nonstop], PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, _str);
        }
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, -1999.3038, 2571.6985, 54.1843))
    {
        if(warningtolls[playerid] == 0  && PlayerInfo[playerid][nonstop] && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle(playerid))
        {
            SetDynamicObjectRot(tolls[13], 0.00000, 18.00000, -132.00000);
            SetTimer("closed_left_bs_eq", 5000, false);

            warningtolls[playerid] = 1;
            PlayerInfo[playerid][nonstop] -= 25;

            format(String, sizeof(String), "Foi descontado do Sem Parar, seu novo saldo é $%s", IsMoney(PlayerInfo[playerid][nonstop], "."));
            SendClientMessage(playerid, Green, "Você pagou $25 no pedágio, Boa viajem!");
            SendClientMessage(playerid, Green, String);

            new _str[100];
            mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Itens` SET `nonstop`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][nonstop], PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, _str);
        }
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, -2667.8718, 1274.3220, 54.4192))
    {
        if(warningtolls[playerid] == 0  && PlayerInfo[playerid][nonstop] && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle(playerid))
        {
            SetDynamicObjectRot(tolls[14], 0.00000, 18.00000, 0.00000);
            SetTimer("closed_right_sf_bs", 5000, false);

            warningtolls[playerid] = 1;
            PlayerInfo[playerid][nonstop] -= 25;

            format(String, sizeof(String), "Foi descontado do Sem Parar, seu novo saldo é $%s", IsMoney(PlayerInfo[playerid][nonstop], "."));
            SendClientMessage(playerid, Green, "Você pagou $25 no pedágio, Boa viajem!");
            SendClientMessage(playerid, Green, String);

            new _str[100];
            mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Itens` SET `nonstop`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][nonstop], PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, _str);
        }
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, -2677.2190, 1274.3220, 54.4192))
    {
        if(warningtolls[playerid] == 0  && PlayerInfo[playerid][nonstop] && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle(playerid))
        {
            SetDynamicObjectRot(tolls[15], 0.00000, 18.00000, 0.00000);
            SetTimer("closed_left_sf_bs", 5000, false);

            warningtolls[playerid] = 1;
            PlayerInfo[playerid][nonstop] -= 25;

            format(String, sizeof(String), "Foi descontado do Sem Parar, seu novo saldo é $%s", IsMoney(PlayerInfo[playerid][nonstop], "."));
            SendClientMessage(playerid, Green, "Você pagou $25 no pedágio, Boa viajem!");
            SendClientMessage(playerid, Green, String);

            new _str[100];
            mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Itens` SET `nonstop`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][nonstop], PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, _str);
        }
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, -2686.3804, 1276.2887, 54.4192))
    {
        if(warningtolls[playerid] == 0  && PlayerInfo[playerid][nonstop] && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle(playerid))
        {
            SetDynamicObjectRot(tolls[16], 0.00000, 18.00000, 180.00000);
            SetTimer("closed_left_bs_sf", 5000, false);

            warningtolls[playerid] = 1;
            PlayerInfo[playerid][nonstop] -= 25;

            format(String, sizeof(String), "Foi descontado do Sem Parar, seu novo saldo é $%s", IsMoney(PlayerInfo[playerid][nonstop], "."));
            SendClientMessage(playerid, Green, "Você pagou $25 no pedágio, Boa viajem!");
            SendClientMessage(playerid, Green, String);

            new _str[100];
            mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Itens` SET `nonstop`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][nonstop], PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, _str);
        }
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, -2694.6233, 1276.2887, 54.4192))
    {
        if(warningtolls[playerid] == 0  && PlayerInfo[playerid][nonstop] && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle(playerid))
        {
            SetDynamicObjectRot(tolls[17], 0.00000, 18.00000, 180.00000);
            SetTimer("closed_right_bs_sf", 5000, false);

            warningtolls[playerid] = 1;
            PlayerInfo[playerid][nonstop] -= 25;

            format(String, sizeof(String), "Foi descontado do Sem Parar, seu novo saldo é $%s", IsMoney(PlayerInfo[playerid][nonstop], "."));
            SendClientMessage(playerid, Green, "Você pagou $25 no pedágio, Boa viajem!");
            SendClientMessage(playerid, Green, String);

            new _str[100];
            mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Itens` SET `nonstop`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][nonstop], PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, _str);
        }
    }
    else
    {
        warningtolls[playerid] = 0;
    }
    return 1;
}

forward closed_right_lv_ls(); public closed_right_lv_ls()
    return SetDynamicObjectRot(tolls[0], 0.00000, 90.00000, 340.00000);

forward closed_left_lv_ls(); public closed_left_lv_ls()
    return SetDynamicObjectRot(tolls[1], 0.00000, 90.00000, 340.00000);

forward closed_right_ls_lv(); public closed_right_ls_lv()
    return SetDynamicObjectRot(tolls[2], 0.00000, -90.00000, 340.00000);

forward closed_left_ls_lv(); public closed_left_ls_lv()
    return SetDynamicObjectRot(tolls[3], 0.00000, -90.00000, 340.00000);

forward closed_bb_lv(); public closed_bb_lv()
    return SetDynamicObjectRot(tolls[4], 0.00000, 90.00000, 35.50000);

forward closed_lv_bb(); public closed_lv_bb()
    return SetDynamicObjectRot(tolls[5], 0.00000, 90.00000, -144.70000);

forward closed_fc_ba(); public closed_fc_ba()
    return SetDynamicObjectRot(tolls[6], 0.00000, -90.00000, -15.00000);

forward closed_ba_fc(); public closed_ba_fc()
    return SetDynamicObjectRot(tolls[7], 0.00000, -90.00000, 165.00000);

forward closed_sf_fc(); public closed_sf_fc()
    return SetDynamicObjectRot(tolls[8], 0.00000, 90.00000, 315.00000);

forward closed_fc_sf(); public closed_fc_sf()
    return SetDynamicObjectRot(tolls[9], 0.00000, 90.00000, 135.00000);

forward closed_left_eq_bs(); public closed_left_eq_bs()
    return SetDynamicObjectRot(tolls[10], 0.00000, 90.00000, 92.00000);

forward closed_right_eq_bs(); public closed_right_eq_bs()
    return SetDynamicObjectRot(tolls[11], 0.00000, 90.00000, 92.00000);

forward closed_right_bs_eq(); public closed_right_bs_eq()
    return SetDynamicObjectRot(tolls[12], 0.00000, 90.00000, -132.00000);

forward closed_left_bs_eq(); public closed_left_bs_eq()
    return SetDynamicObjectRot(tolls[13], 0.00000, 90.00000, -132.00000);

forward closed_right_sf_bs(); public closed_right_sf_bs()
    return SetDynamicObjectRot(tolls[14], 0.00000, 90.00000, 0.00000);

forward closed_left_sf_bs(); public closed_left_sf_bs()
    return SetDynamicObjectRot(tolls[15], 0.00000, 90.00000, 0.00000);

forward closed_left_bs_sf(); public closed_left_bs_sf()
    return SetDynamicObjectRot(tolls[16], 0.00000, 90.00000, 180.00000);

forward closed_right_bs_sf(); public closed_right_bs_sf()
    return SetDynamicObjectRot(tolls[17], 0.00000, 90.00000, 180.00000);

CMD:pagarpedagio(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 5.0, 1727.2482, 530.4234, 26.6058))
    {
        SetDynamicObjectRot(tolls[0], 0.00000, 18.00000, 340.00000);
        SetTimer("closed_right_lv_ls", 5000, false);
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, 1735.7852, 526.9039, 26.6058))
    {
        SetDynamicObjectRot(tolls[1], 0.00000, 18.00000, 340.00000);
        SetTimer("closed_left_lv_ls", 5000, false);
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, 1743.3595, 522.5642, 26.6058))
    {
        SetDynamicObjectRot(tolls[2], 0.00000, -18.00000, 340.00000);
        SetTimer("closed_right_ls_lv", 5000, false);
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, 1751.6979, 519.8131, 26.6058))
    {
        SetDynamicObjectRot(tolls[3], 0.00000, -18.00000, 340.00000);
        SetTimer("closed_left_ls_lv", 5000, false);
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, 528.5143, 468.5071, 18.9297))
    {
        SetDynamicObjectRot(tolls[4], 0.00000, 18.00000, 35.50000);
        SetTimer("closed_bb_lv", 5000, false);
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, 513.8133, 474.9756, 18.9297))
    {
        SetDynamicObjectRot(tolls[5], 0.00000, 18.00000, -144.00000);
        SetTimer("closed_lv_bb", 5000, false);
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, -172.0047, 368.6565, 11.0716))
    {
        SetDynamicObjectRot(tolls[6], 0.00000, -18.00000, -15.00000);
        SetTimer("closed_fc_ba", 5000, false);
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, -166.3996, 358.6230, 11.0716))
    {
        SetDynamicObjectRot(tolls[7], 0.00000, -18.00000, 165.00000);
        SetTimer("closed_ba_fc", 5000, false);
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, -1529.0376, 682.9033, 43.8730))
    {
        SetDynamicObjectRot(tolls[8], 0.00000, 18.00000, 315.00000);
        SetTimer("closed_sf_fc", 5000, false);
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, -1534.7046, 691.2211, 43.8730))
    {
        SetDynamicObjectRot(tolls[9], 0.00000, 18.00000, 135.00000);
        SetTimer("closed_fc_sf", 5000, false);
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, -2272.8396, 2672.6208, 54.4125))
    {
        SetDynamicObjectRot(tolls[10], 0.00000, 18.00000, 92.00000);
        SetTimer("closed_left_eq_bs", 5000, false);
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, -2272.7207, 2681.8459, 54.4125))
    {
        SetDynamicObjectRot(tolls[11], 0.00000, 18.00000, 92.00000);
        SetTimer("closed_right_eq_bs", 5000, false);
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, -2005.5844, 2565.1606, 54.1843))
    {
        SetDynamicObjectRot(tolls[12], 0.00000, 18.00000, -132.00000);
        SetTimer("closed_right_bs_eq", 5000, false);
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, -1999.3038, 2571.6985, 54.1843))
    {
        SetDynamicObjectRot(tolls[13], 0.00000, 18.00000, -132.00000);
        SetTimer("closed_left_bs_eq", 5000, false);
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, -2667.8718, 1274.3220, 54.4192))
    {
        SetDynamicObjectRot(tolls[14], 0.00000, 18.00000, 0.00000);
        SetTimer("closed_right_sf_bs", 5000, false);
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, -2677.2190, 1274.3220, 54.4192))
    {
        SetDynamicObjectRot(tolls[15], 0.00000, 18.00000, 0.00000);
        SetTimer("closed_left_sf_bs", 5000, false);
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, -2686.3804, 1276.2887, 54.4192))
    {
        SetDynamicObjectRot(tolls[16], 0.00000, 18.00000, 180.00000);
        SetTimer("closed_left_bs_sf", 5000, false);
    }
    else if(IsPlayerInRangeOfPoint(playerid, 5.0, -2694.6233, 1276.2887, 54.4192))
    {
        SetDynamicObjectRot(tolls[17], 0.00000, 18.00000, 180.00000);
        SetTimer("closed_right_bs_sf", 5000, false);
    }
    else return SendClientMessage(playerid, Erro, "Você não está em um pedágio!");

    if(PlayerInfo[playerid][Dinheiro] < 30)
        return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente!");

    if(!IsPlayerInAnyVehicle(playerid))
        return SendClientMessage(playerid, Erro, "Você não está em um veículo!");

    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
        return SendClientMessage(playerid, Erro, "Você não está dirigindo nenhum veículo!");

    SendClientMessage(playerid, Green, "Você pagou $30 no pedágio, Boa viajem!");
    PlayerInfo[playerid][Dinheiro] -= 30;
    UpdatePlayerMoney(playerid);
    return 1;
}
