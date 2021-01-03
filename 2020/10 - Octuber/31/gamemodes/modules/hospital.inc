#include YSI\y_hooks

new Float:Hosp[8][3] =
{
    {2029.7653,-1402.8408,17.2528},     // Hosp Jefferson Los Santos
    {1172.8495,-1323.3513,15.3998},     // Hosp Market Los Santos
    {1607.3652,1815.8800,10.8203},      // Hosp Las Venturas
    {-318.8461,1049.0421,20.3403},      // Hosp Fort Carson
    {-1514.8762,2519.5337,56.0703},     // Hosp El Quebrados
    {-2655.0889,639.6584,14.4545},      // Hosp San Fierro
    {-2215.4927,-2287.0698,30.6250},    // Hosp Angel Pine
    {1244.7914,331.5576,19.5547}        // Hosp Montgomery
};

new Cidade_Que_Morreu[MAX_PLAYERS];

new cps_hospital;

new Parede[8],
    Door[2],
    Tapete[4],
    Coluna[10],
    Chao[4],
    Teto[4];

hook OnGameModeInit()
{
    SetDynamicObjectMaterialText(CreateDynamicObject(19353, 1039.24207, 993.21283, 16.91360, 0.00000, 0.00000, 0.00000), 0, "{FF0000}Hospital", 50, "Arial", 15, 1, 0xFF0000AA, 0, 1);

    Chao[0] = CreateDynamicObject(19376, 1024.00000, 988.38000, 14.03293,   0.00000, 90.00000, 0.00000);
    Chao[1] = CreateDynamicObject(19376, 1034.50000, 988.38000, 14.03293,   0.00000, 90.00000, 0.00000);
    Chao[2] = CreateDynamicObject(19376, 1034.50000, 998.00000, 14.03293,   0.00000, 90.00000, 0.00000);
    Chao[3] = CreateDynamicObject(19376, 1024.00000, 998.00000, 14.03293,   0.00000, 90.00000, 0.00000);
    for(new i = 0; i < sizeof(Chao); i++)  SetDynamicObjectMaterial(Chao[i],0, 18646, "matcolours", "grey-93-percent", 0);

    Teto[0] = CreateDynamicObject(19379, 1024.00000, 988.38000, 19.20760,   0.00000, 90.00000, 0.00000);
    Teto[1] = CreateDynamicObject(19379, 1034.50000, 988.38000, 19.20760,   0.00000, 90.00000, 0.00000);
    Teto[2] = CreateDynamicObject(19379, 1034.50000, 998.00000, 19.20760,   0.00000, 90.00000, 0.00000);
    Teto[3] = CreateDynamicObject(19379, 1024.00000, 998.00000, 19.20760,   0.00000, 90.00000, 0.00000);
    for(new i = 0; i < sizeof(Teto); i++) SetDynamicObjectMaterial(Teto[i],0, 16639, "a51_labs", "ws_trainstationwin1", 0);

    Coluna[0] = CreateDynamicObject(18762, 1019.26038, 984.18500, 16.62030,   0.00000, 0.00000, 0.00000);
    Coluna[1] = CreateDynamicObject(18762, 1039.25000, 984.18500, 16.62030,   0.00000, 0.00000, 0.00000);
    Coluna[2] = CreateDynamicObject(18762, 1039.24548, 1002.31549, 16.62030,   0.00000, 0.00000, 0.00000);
    Coluna[3] = CreateDynamicObject(18762, 1019.24536, 1002.32373, 16.62030,   0.00000, 0.00000, 0.00000);
    Coluna[4] = CreateDynamicObject(18762, 1019.25311, 995.65234, 16.62030,   0.00000, 0.00000, 0.00000);
    Coluna[5] = CreateDynamicObject(18762, 1019.25879, 990.83008, 16.62030,   0.00000, 0.00000, 0.00000);
    Coluna[6] = CreateDynamicObject(18762, 1029.29089, 990.82544, 16.62030,   0.00000, 0.00000, 0.00000);
    Coluna[7] = CreateDynamicObject(18762, 1029.29089, 995.65839, 16.62030,   0.00000, 0.00000, 0.00000);
    Coluna[8] = CreateDynamicObject(18762, 1029.29089, 1002.29327, 16.62030,   0.00000, 0.00000, 0.00000);
    Coluna[9] = CreateDynamicObject(18762, 1029.29089, 984.19659, 16.62030,   0.00000, 0.00000, 0.00000);
    for(new i = 0; i < sizeof(Coluna); i++)  SetDynamicObjectMaterial(Coluna[i], 0, 3897, "libertyhi", "wallmix64HV", 0);

    Parede[0] = CreateDynamicObject(19375, 1039.25000, 988.38000, 16.10387,   0.00000, 0.00000, 0.00000);
    Parede[1] = CreateDynamicObject(19375, 1039.25000, 998.00000, 16.10387,   0.00000, 0.00000, 0.00000);
    Parede[2] = CreateDynamicObject(19375, 1019.25000, 998.00000, 16.10387,   0.00000, 0.00000, 0.00000);
    Parede[3] = CreateDynamicObject(19375, 1019.25000, 988.38000, 16.10387,   0.00000, 0.00000, 0.00000);
    Parede[4] = CreateDynamicObject(19375, 1024.02002, 1002.16998, 16.10390,   0.00000, 0.00000, 90.00000);
    Parede[5] = CreateDynamicObject(19375, 1034.54578, 1002.16998, 16.10390,   0.00000, 0.00000, 90.00000);
    Parede[6] = CreateDynamicObject(19375, 1024.02002, 984.19702, 16.10390,   0.00000, 0.00000, 90.00000);
    Parede[7] = CreateDynamicObject(19375, 1034.54578, 984.19702, 16.10390,   0.00000, 0.00000, 90.00000);
    for(new i = 0; i < sizeof(Parede); i++)  SetDynamicObjectMaterial(Parede[i], 0, 10765, "airportgnd_sfse", "white", 0);

    Door[0] = CreateDynamicObject(1501, 1019.38000, 991.74811, 14.12000,   0.00000, 0.00000, 90.00000);
    Door[1] = CreateDynamicObject(1501, 1019.38000, 994.76001, 14.12000,   0.00000, 0.00000, 270.00000);
    for(new i = 0; i < sizeof(Door); i++) SetDynamicObjectMaterial(Door[i], 0, 10765, "airportgnd_sfse", "black", 0);

    Tapete[0] = CreateDynamicObject(19449, 1020.38898, 993.21600, 14.03980,   0.00000, 90.00000, 90.00000);
    Tapete[1] = CreateDynamicObject(19449, 1030.01978, 993.21277, 14.03980,   0.00000, 90.00000, 90.00000);
    Tapete[2] = CreateDynamicObject(19449, 1033.07996, 986.64972, 14.03980,   0.00000, 90.00000, 0.00000);
    Tapete[3] = CreateDynamicObject(19449, 1033.07996, 999.78003, 14.03980,   0.00000, 90.00000, 0.00000);
    for(new i = 0; i < sizeof(Tapete); i++) SetDynamicObjectMaterial(Tapete[i], 0, 18646, "matcolours", "red", 0);

    CreateDynamicObject(1502, 1025.69995, 990.79999, 14.12000,   0.00000, 0.00000, 180.00000);
    CreateDynamicObject(1502, 1022.66809, 990.75500, 14.12000,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(1502, 1025.69995, 995.81763, 14.12000,   0.00000, 0.00000, 180.00000);
    CreateDynamicObject(1502, 1022.66809, 995.77759, 14.12000,   0.00000, 0.00000, 0.00000);

    CreateDynamicObject(19449, 1024.00000, 990.79999, 22.44400,   90.00000, 0.00000, 90.00000);
    CreateDynamicObject(19449, 1027.43994, 990.79999, 14.30000,   90.00000, 0.00000, 90.00000);
    CreateDynamicObject(19449, 1027.44348, 995.79724, 14.30000,   90.00000, 0.00000, 90.00000);
    CreateDynamicObject(19449, 1024.00000, 995.79761, 22.44400,   90.00000, 0.00000, 90.00000);
    CreateDynamicObject(19449, 1020.91541, 995.79700, 14.30000,   90.00000, 0.00000, 90.00000);
    CreateDynamicObject(19449, 1020.91541, 990.79999, 14.30000,   90.00000, 0.00000, 90.00000);
    CreateDynamicObject(19449, 1029.33325, 986.14539, 19.35200,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19449, 1029.33325, 985.99719, 15.86000,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19449, 1029.31995, 1000.76019, 19.35200,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19449, 1029.33325, 1000.77515, 15.86000,   0.00000, 0.00000, 0.00000);

    CreateDynamicObject(19466, 1025.30005, 995.77759, 17.56760,   0.00000, 0.00000, 90.00000);
    CreateDynamicObject(19466, 1023.06000, 995.79761, 17.56760,   0.00000, 0.00000, 90.00000);
    CreateDynamicObject(19466, 1023.06000, 990.79999, 17.56760,   0.00000, 0.00000, 90.00000);
    CreateDynamicObject(19466, 1025.30005, 990.79999, 17.56760,   0.00000, 0.00000, 90.00000);

    CreateDynamicObject(2205, 1035.33521, 992.59998, 14.09980,   0.00000, 0.00000, 90.00000);
    CreateDynamicObject(2205, 1035.31592, 996.00000, 14.09980,   0.00000, 0.00000, 90.00000);
    CreateDynamicObject(2205, 1035.31592, 999.40002, 14.09980,   0.00000, 0.00000, 90.00000);
    CreateDynamicObject(2205, 1035.33264, 989.20001, 14.09980,   0.00000, 0.00000, 90.00000);
    CreateDynamicObject(2205, 1035.33264, 985.79999, 14.09980,   0.00000, 0.00000, 90.00000);

    CreateDynamicObject(1714, 1037.00000, 986.40002, 14.09980,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(1714, 1037.00000, 989.79999, 14.09980,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(1714, 1037.00000, 993.29999, 14.09980,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(1714, 1037.01086, 996.68323, 14.09980,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(1714, 1036.99414, 1000.04999, 14.09980,   0.00000, 0.00000, -90.00000);

    CreateDynamicObject(11685, 1030.80005, 997.00000, 14.11930,   0.00000, 0.00000, 90.00000);
    CreateDynamicObject(11685, 1030.80005, 999.00000, 14.11930,   0.00000, 0.00000, 90.00000);
    CreateDynamicObject(11685, 1030.80005, 1001.00000, 14.11930,   0.00000, 0.00000, 90.00000);
    CreateDynamicObject(11685, 1030.80005, 989.40002, 14.11930,   0.00000, 0.00000, 90.00000);
    CreateDynamicObject(11685, 1030.80005, 987.40002, 14.11930,   0.00000, 0.00000, 90.06000);
    CreateDynamicObject(11685, 1030.80005, 985.40002, 14.11930,   0.00000, 0.00000, 90.00000);

    CreateDynamicObject(1997, 1021.00000, 986.00000, 14.12030,   0.00000, 0.00000, 180.00000);
    CreateDynamicObject(1997, 1024.00000, 986.00000, 14.12030,   0.00000, 0.00000, 180.00000);
    CreateDynamicObject(1997, 1027.00000, 986.00000, 14.12030,   0.00000, 0.00000, 180.00000);
    CreateDynamicObject(1997, 1027.00000, 1000.09998, 14.12030,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(1997, 1024.00000, 1000.09998, 14.12030,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(1997, 1021.00000, 1000.09998, 14.12030,   0.00000, 0.00000, 0.00000);

    cps_hospital = CreateDynamicCP(1033.1370, 993.1141, 14.03293, 1.5, -1, -1, -1, 30.0);
	return 1;
}

hook OnPlayerConnect(playerid)
{
    Cidade_Que_Morreu[playerid] = -1;
	return 1;
}

hook OnPlayerSpawn(playerid)
{
    TextDrawHideForPlayer(playerid, TDDetonated[0]);
    TextDrawHideForPlayer(playerid, TDDetonated[1]);

    if(Cidade_Que_Morreu[playerid] != -1)
    {
        if(PlayerInfo[playerid][healthplan])
        {
            SendClientMessage(playerid, 0x008000AA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            SendClientMessage(playerid, 0xFFFFFFAA, "Você tem plano de saúde");
            SendClientMessage(playerid, 0xFFFFFFAA, "Seu plano de saúde cobriu todas as suas necessidades médicas");
            SendClientMessage(playerid, 0x008000AA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        }
        else if(PlayerInfo[playerid][healthplan] == false)
        {
            PlayerInfo[playerid][SaldoBancario] -= 1000;
            SendClientMessage(playerid, 0x008000AA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            SendClientMessage(playerid, 0xFFFFFFAA, "Você não tem plano de saúde");
            SendClientMessage(playerid, 0xFFFFFFAA, "Foi retirado {FF4000}$1.000{FFFFFF} de sua conta bancária");
            SendClientMessage(playerid, 0x008000AA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        }
        Cidade_Que_Morreu[playerid] = -1;
    }
    return 1;
}

hook OnPlayerDeath(playerid, killerid, reason)
{
    if(!PlayerInfo[playerid][Logado]) return 0;

    SendDeathMessage(killerid, playerid, reason);

    TextDrawShowForPlayer(playerid, TDDetonated[0]);
    TextDrawShowForPlayer(playerid, TDDetonated[1]);

    if(IsPlayerInBase(playerid))
    {
        for(new baseid = 0; baseid < MAX_BASES; baseid++)
        {
            if(IsPlayerInBase(playerid, baseid) && ( IsPlayerMemberBase(playerid, baseid) || IsPlayerSubBase(playerid, baseid) || IsPlayerOwnerBase(playerid, baseid) ))
            {
                SetSpawnInfo(playerid, 0, PlayerInfo[playerid][skin], BaseEnter[baseid][be_x], BaseEnter[baseid][be_y], BaseEnter[baseid][be_z], BaseEnter[baseid][be_a], 0, 0, 0, 0, 0, 0);
            }
        }

        PlayerInfo[playerid][Morreu]++;

        Kills[playerid] = 0;

        if(killerid != INVALID_PLAYER_ID)
        {
            TogglePlayerSpectating(playerid, true);

            Kills[killerid]++;

            switch(Kills[killerid])
            {
                case 2: GameTextForPlayer(killerid, "~r~DOUBLE KILL", 1000, 4);
                case 3: GameTextForPlayer(killerid, "~r~TRIPE KILL", 1000, 4);
                case 4..10: GameTextForPlayer(killerid, "~r~CHAIN KILLER", 1000, 4);
            }

            PlayerInfo[killerid][Matou]++;

            if(!IsPlayerInBaseDmOn(killerid))
            {
                PlayerInfo[killerid][Estrelas] += 5;
                UpdatePlayerStar(killerid);

                format(String, MAX_STRING, "O(A) Jogador(a) %s[%d] matou %s[%d] e foi colocado +5 estrelas de procurado(a)", PlayerInfo[killerid][Nome], killerid, PlayerInfo[playerid][Nome], playerid);
            }
            else
            {
                format(String, MAX_STRING, "O(A) Jogador(a) %s[%d] matou %s[%d] e não recebeu estrelas ( DM Liberado )", PlayerInfo[killerid][Nome], killerid, PlayerInfo[playerid][Nome], playerid);
            }
            LocalMessage(50.0, playerid, String, 0xB9FFFFAA);
            PlayerSpectatePlayer(playerid, killerid);
            SetTimerEx("Spectate", 5000, false, "d", playerid);
        }
    }
    else if(IsArena[playerid])
    {
        new rand = random(sizeof(RandomSpawns));

        SetSpawnInfo(playerid, 0, PlayerInfo[playerid][skin], RandomSpawns[rand][rs_x], RandomSpawns[rand][rs_y], RandomSpawns[rand][rs_z], RandomSpawns[rand][rs_a], 0, 0, 0, 0, 0, 0);

        TogglePlayerSpectating(playerid, true);

        Kills[playerid] = 0;

        if(killerid != INVALID_PLAYER_ID)
        {
            Kills[killerid]++;

            switch(Kills[killerid])
            {
                case 2: GameTextForPlayer(killerid, "~r~DOUBLE KILL", 1000, 4);
                case 3: GameTextForPlayer(killerid, "~r~TRIPE KILL", 1000, 4);
                case 4..10: GameTextForPlayer(killerid, "~r~CHAIN KILLER", 1000, 4);
            }

            PlayerInfo[killerid][Matou]++;

            if(IsArena[killerid])
            {
                HideTextDrawKD(killerid);
                ShowTextDrawKD(killerid);
            }

            format(String, MAX_STRING, "O(A) Jogador(a) %s[%d] matou %s[%d] e não recebeu estrelas ( DM Liberado )", PlayerInfo[killerid][Nome], killerid, PlayerInfo[playerid][Nome], playerid);
            LocalMessage(50.0, playerid, String, 0xB9FFFFAA);

            PlayerSpectatePlayer(playerid, killerid);
        }

        Cidade_Que_Morreu[playerid] = -1;
        PlayerInfo[playerid][Morreu]++;

        if(IsArena[playerid]) HideTextDrawKD(playerid);

        SetTimerEx("Spectate", 5000, false, "d", playerid);
    }
    else
    {
        Cidade_Que_Morreu[playerid] = PickupHospitalNext(playerid);

        SetSpawnInfo(playerid, 0, PlayerInfo[playerid][skin], Hosp[Cidade_Que_Morreu[playerid]][0], Hosp[Cidade_Que_Morreu[playerid]][1], Hosp[Cidade_Que_Morreu[playerid]][2], 0, 0, 0, 0, 0, 0, 0);

        if(killerid != INVALID_PLAYER_ID)
        {
            PlayerInfo[killerid][Estrelas] += 5;
            UpdatePlayerStar(killerid);

            format(String, MAX_STRING, "O(A) Jogador(a) %s[%d] matou %s[%d] e foi colocado +5 estrelas de procurado(a)", PlayerInfo[killerid][Nome], killerid, PlayerInfo[playerid][Nome], playerid);
            LocalMessage(50.0, playerid, String, 0xB9FFFFAA);
        }
    }
    return 1;
}

hook OnPlayerEnterCheckpoint(playerid)
{
    if(IsPlayerInDynamicCP(playerid, cps_hospital))
    {
        new txt[300];
        strcat(txt, "{FFFFFF}Kit médicos \t\t {2CC06B}$900 \n");
        strcat(txt, "{FFFFFF}Curar doença \t\t {2CC06B}$5.000 \n");
        strcat(txt, "{FFFFFF}Trocar de sexo \t\t {2CC06B}$50.000 \n");
        strcat(txt, "{FFFFFF}Plano de saude \t\t {2CC06B}$150 \n");
        ShowPlayerDialog(playerid, hospital, DIALOG_STYLE_TABLIST, "{FF0000}Menu Hospital", txt, "Selecionar", "Cancelar");
        return 1;
    }
	return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == hospital && response)
    {
        if(listitem == 0) // Kit Médico
        {
            if(PlayerInfo[playerid][Dinheiro] < 900)
                return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

            if(PlayerInfo[playerid][medicalkit] != 0)
                return SendClientMessage(playerid, Erro, "Você ainda tem Kit Médicos");

            SendClientMessage(playerid, -1, "Você comprou 3 kit médicos, para usar digite ~~> /UsarKit");
            PlayerInfo[playerid][medicalkit] = 3;
            PlayerInfo[playerid][Dinheiro] -= 900;
            UpdatePlayerMoney(playerid);

            SetIntQuery(playerid, "Itens", "kitmedicos", 3);
            return 1;
        }
        else if(listitem == 1) // Curar Doença
        {
            if(!PlayerInfo[playerid][disease])
                return SendClientMessage(playerid, Erro, "Você não está doente");

            if(PlayerInfo[playerid][Dinheiro] < 5000)
                return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

            Progress[playerid][Vida] = 0.0;

            PlayerInfo[playerid][vaccine] = (gettime() + 18000);
            PlayerInfo[playerid][disease] = 0;

            PlayerInfo[playerid][Health] = 100.0;
            SetPlayerHealth(playerid, PlayerInfo[playerid][Health]);

            PlayerInfo[playerid][Dinheiro] -= 5000;
            UpdatePlayerMoney(playerid);
            UpdatePlayerDisease(playerid);
            UpdateProgressBar(playerid);

            SendClientMessage(playerid, 0x33CCFFAA, "Agora você não está mais doente e tomou reforço de 5 vacinas");
            return 1;
        }
        else if(listitem == 2) //Troca de sexo
        {
            ShowPlayerDialog(playerid, hospital_sex, DIALOG_STYLE_MSGBOX, "{FF0000}Trocar de Sexo", "{FFFFFF}Tem certeza que deseja trocar de sexo?\n\nObs: você perderá {FF4000}$50.000", "Sim", "Não");
            return 1;
        }
        else if(listitem == 3) //Plano de saude
        {
            if(PlayerInfo[playerid][Dinheiro] < 150)
                return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

            if(PlayerInfo[playerid][healthplan])
                return SendClientMessage(playerid, Erro, "Você já tem um plano de saúde");

            PlayerInfo[playerid][healthplan] = true;
            PlayerInfo[playerid][Dinheiro] -= 150;
            UpdatePlayerMoney(playerid);

            SetIntQuery(playerid, "Itens", "planosaude", 1);

            SendClientMessage(playerid, -1, "Você acabe de adquirir um plano de saúde");
            SendClientMessage(playerid, -1, "Não se preocupe, será descontado automaticamente do seu sálario");
            return 1;
        }
        return 1;
    }
    if(dialogid == hospital_sex && response)
    {
        if(PlayerInfo[playerid][Dinheiro] < 50000)
            return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

        if(PlayerInfo[playerid][sexo] == SEX_BOY)
        {
            PlayerInfo[playerid][sexo] = SEX_GIRL;
            PlayerInfo[playerid][skin] = DEFAULT_SKIN_GIRL;
        }
        else
        {
            PlayerInfo[playerid][sexo] = SEX_BOY;
            PlayerInfo[playerid][skin] = DEFAULT_SKIN_GIRL;
        }

        SetPlayerSkin(playerid, PlayerInfo[playerid][skin]);
        format(String, 50, "Você mudou seu sexo para %s", PlayerInfo[playerid][sexo]);
        SendClientMessage(playerid, -1, String);

        PlayerInfo[playerid][Dinheiro] -= 50000;
        UpdatePlayerMoney(playerid);

        new query[200];
        mysql_format(IDConexao, query, 200, "UPDATE `Identidade` SET `sexo`='%d', `skin`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][sexo], PlayerInfo[playerid][skin], PlayerInfo[playerid][ID]);
        mysql_query(IDConexao, query);
        return 1;
    }
    return 1;
}

stock PickupHospitalNext(playerid)
{
    new Float:dist, Float:ldist = 3000.0, hosp = 0;
    for(new i = 0; i < sizeof(Hosp); i++)
    {
        dist = GetPlayerDistanceFromPoint(playerid, Hosp[i][0], Hosp[i][1], Hosp[i][2]);
        if(dist < ldist)
        {
            ldist = dist;
            hosp = i;
        }
    }
    return hosp;
}
