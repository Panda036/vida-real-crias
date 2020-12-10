#include YSI\y_hooks

#define MAX_AREA_PLANTER 24

enum e_app
{
    Float:app_x,
    Float:app_y,
    Float:app_z
};

new AreaPlanterPot[MAX_AREA_PLANTER][e_app] =
{
    {-1095.86816, -1095.49438, 128.21500},
    {-1077.31201, -1095.48596, 128.21500},
    {-1083.47986, -1095.51831, 128.21500},
    {-1089.54590, -1095.47498, 128.21500},
    {-1077.11230, -1084.38599, 128.21500},
    {-1089.67126, -1084.37659, 128.21500},
    {-1083.49988, -1084.28394, 128.21500},
    {-1095.65479, -1084.42810, 128.21500},
    {-1130.66858, -1095.46460, 128.21500},
    {-1124.09436, -1095.54590, 128.21500},
    {-1136.59216, -1095.43384, 128.21500},
    {-1142.88110, -1095.36536, 128.21500},
    {-1130.27222, -1084.26392, 128.21500},
    {-1124.02942, -1084.34290, 128.21500},
    {-1136.71997, -1084.23254, 128.21500},
    {-1142.97205, -1084.33667, 128.21500},
    {-1138.54224, -1134.46069, 128.21500},
    {-1144.83325, -1134.47595, 128.21500},
    {-1151.09473, -1134.44751, 128.21500},
    {-1157.62769, -1134.40112, 128.21500},
    {-1169.49548, -1095.82410, 128.21500},
    {-1175.88440, -1095.79407, 128.21500},
    {-1181.95996, -1095.85889, 128.21500},
    {-1188.40833, -1095.97839, 128.21500}
};

new Text3D:LabelCannabis[MAX_AREA_PLANTER];
new ObjectCannabis[MAX_AREA_PLANTER];
new bool:CannabisOK[MAX_AREA_PLANTER];
new CannabisUsed[MAX_AREA_PLANTER] = -1;
new T_DestroyCannabis[MAX_PLAYERS];
new T_CannabisOK[MAX_PLAYERS];
new T_Cannabis[MAX_PLAYERS];

hook OnGameModeInit()                 //126.3000 no chão
{
    //Buy Cannabis
    CreateDynamicObject(1271, 197.20020, -234.75011, 1.12120,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(1271, 197.20020, -233.93010, 1.12120,   0.00000, 0.00000, 0.00000);

    for(new i = 0; i < MAX_AREA_PLANTER; i++)
    {
        CannabisOK[i] = false;
        CannabisUsed[i] = -1;
        LabelCannabis[i] = CreateDynamic3DTextLabel("{FFFFFF}Área de plantacão\nPertênce à {8080C0}N/A", 0xFFFFFFFF, AreaPlanterPot[i][app_x], AreaPlanterPot[i][app_y], AreaPlanterPot[i][app_z]+0.25, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, -1, -1, -1);
    }
    return 1;
}

hook OnPlayerConnect(playerid)
{
    RemoveBuildingForPlayer(playerid, 3261, -1183.7656, -1095.7969, 128.2188, 0.25);
    RemoveBuildingForPlayer(playerid, 3261, -1152.2969, -1134.5078, 128.2188, 0.25);
    RemoveBuildingForPlayer(playerid, 3261, -1139.8125, -1134.5078, 128.2188, 0.25);
    RemoveBuildingForPlayer(playerid, 3261, -1146.1094, -1134.5078, 128.2188, 0.25);
    RemoveBuildingForPlayer(playerid, 3261, -1171.2813, -1095.7969, 128.2188, 0.25);
    RemoveBuildingForPlayer(playerid, 3261, -1177.5859, -1095.7969, 128.2188, 0.25);
    RemoveBuildingForPlayer(playerid, 3261, -1137.7578, -1095.5391, 128.2188, 0.25);
    RemoveBuildingForPlayer(playerid, 3261, -1131.5703, -1095.5391, 128.2188, 0.25);
    RemoveBuildingForPlayer(playerid, 3261, -1125.2656, -1095.5391, 128.2188, 0.25);
    RemoveBuildingForPlayer(playerid, 3261, -1078.3906, -1095.5391, 128.2188, 0.25);
    RemoveBuildingForPlayer(playerid, 3261, -1090.8750, -1095.5391, 128.2188, 0.25);
    RemoveBuildingForPlayer(playerid, 3261, -1084.6875, -1095.5391, 128.2188, 0.25);
    RemoveBuildingForPlayer(playerid, 3261, -1137.7578, -1084.3672, 128.2188, 0.25);
    RemoveBuildingForPlayer(playerid, 3261, -1125.2656, -1084.3672, 128.2188, 0.25);
    RemoveBuildingForPlayer(playerid, 3261, -1131.5703, -1084.3672, 128.2188, 0.25);
    RemoveBuildingForPlayer(playerid, 3261, -1090.8750, -1084.3672, 128.2188, 0.25);
    RemoveBuildingForPlayer(playerid, 3261, -1078.3906, -1084.3672, 128.2188, 0.25);
    RemoveBuildingForPlayer(playerid, 3261, -1084.6875, -1084.3672, 128.2188, 0.25);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i = 0; i < MAX_AREA_PLANTER; i++)
    {
        if(CannabisUsed[i] == playerid)
        {
            CannabisUsed[i] = -1;
            CannabisOK[i] = false;
            KillTimer(T_DestroyCannabis[playerid]);
            KillTimer(T_CannabisOK[playerid]);
            KillTimer(T_Cannabis[playerid]);
            DestroyDynamicObject(ObjectCannabis[i]);
            UpdateDynamic3DTextLabelText(LabelCannabis[i], 0xFFFFFFFF, "{FFFFFF}Área de plantacão\nPertênce à {8080C0}N/A");
        }
    }

    return 1;
}

forward OnPlayerCannabisDestroy(playerid, cannabisid);
public OnPlayerCannabisDestroy(playerid, cannabisid)
{
    CannabisUsed[cannabisid] = -1;
    CannabisOK[cannabisid] = false;
    KillTimer(T_DestroyCannabis[playerid]);
    KillTimer(T_CannabisOK[playerid]);
    KillTimer(T_Cannabis[playerid]);
    DestroyDynamicObject(ObjectCannabis[cannabisid]);
    UpdateDynamic3DTextLabelText(LabelCannabis[cannabisid], 0xFFFFFFFF, "{FFFFFF}Área de plantacão\nPertênce à {8080C0}N/A");

    SendClientMessage(playerid, Red, "Você demorou muito para fazer a colheita e ela foi destruida");
    return 1;
}

forward OnPlayerCannabisOK(playerid, cannabisid);
public OnPlayerCannabisOK(playerid, cannabisid)
{
    T_DestroyCannabis[playerid] = SetTimerEx("OnPlayerCannabisDestroy", 120000, false, "dd", playerid, cannabisid);

    CannabisOK[cannabisid] = true;
    SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Sua erva Cannabis está pronta para colheita");
    return 1;
}

forward OnPlayerCannabis(playerid, cannabisid);
public OnPlayerCannabis(playerid, cannabisid)
{
    T_CannabisOK[playerid] = SetTimerEx("OnPlayerCannabisOK", 20000, false, "dd", playerid, cannabisid);
    MoveDynamicObject(ObjectCannabis[cannabisid], AreaPlanterPot[cannabisid][app_x], AreaPlanterPot[cannabisid][app_y], AreaPlanterPot[cannabisid][app_z], 0.1);
    return 1;
}

stock RandomValueCannabis()
{
    new rand = random(1500);

    if(rand < 750) return RandomValueCannabis();

    return rand;
}

stock LeftPfsPotPlanter(playerid)
{
    if(PlayerInfo[playerid][Profissao] == potplanter)
    {
        for(new i = 0; i < MAX_AREA_PLANTER; i++)
        {
            if(CannabisUsed[i] == playerid)
            {
                CannabisUsed[i] = -1;
                CannabisOK[i] = false;
                KillTimer(T_DestroyCannabis[playerid]);
                KillTimer(T_CannabisOK[playerid]);
                KillTimer(T_Cannabis[playerid]);
                DestroyDynamicObject(ObjectCannabis[i]);
                UpdateDynamic3DTextLabelText(LabelCannabis[i], 0xFFFFFFFF, "{FFFFFF}Área de plantacão\nPertênce à {8080C0}N/A");
            }
        }
    }
    return 1;
}

/******************************************************************************/
/***************************| COMMANDS POT PLANTER |***************************/
/******************************************************************************/

CMD:plantar(playerid)
{
    if(PlayerInfo[playerid][Profissao] != potplanter)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(IsPlayerInAnyVehicle(playerid))
        return SendClientMessage(playerid, Erro, "Você está em um veículo, saia e tente novamente");

    if(!PlayerInfo[playerid][cannabis])
        return SendClientMessage(playerid, Erro, "Você não tem muda, vá até o fornecedor");

    for(new i = 0; i < MAX_AREA_PLANTER; i++)
    {
        if(IsPlayerInRangeOfPoint(playerid, 4.0, AreaPlanterPot[i][app_x], AreaPlanterPot[i][app_y], AreaPlanterPot[i][app_z]))
        {
            for(new j = 0; j < MAX_AREA_PLANTER; j++)
            {
                if(CannabisUsed[j] == playerid)
                    return SendClientMessage(playerid, Erro, "Só pode fazer uma plantação por vez");
            }

            if(CannabisUsed[i] != -1)
                return SendClientMessage(playerid, Erro, "Já tem gente plantando neste local");

            PlayerInfo[playerid][cannabis]--;
            SetIntQuery(playerid, "Itens", "cannabis", PlayerInfo[playerid][cannabis]);
            CannabisUsed[i] = playerid;
            ObjectCannabis[i] = CreateDynamicObject(19473, AreaPlanterPot[i][app_x], AreaPlanterPot[i][app_y], AreaPlanterPot[i][app_z]-2.0, 0.0, 0.0, 0.0);

            format(String, MAX_STRING, "{FFFFFF}Área de plantacão\nPertênce à {8080C0}%s", PlayerInfo[playerid][Nome]);
            UpdateDynamic3DTextLabelText(LabelCannabis[i], 0xFFFFFFFF, String);

            T_Cannabis[playerid] = SetTimerEx("OnPlayerCannabis", 160000, false, "dd", playerid, i);

            SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Cannabis plantada, aguarde 3 minutos para poder colher");
            return 1;
        }
    }
    return SendClientMessage(playerid, Erro, "Você não está em uma área de plantar Cannabis");
}
CMD:colher(playerid)
{
    if(PlayerInfo[playerid][Profissao] != potplanter)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(IsPlayerInAnyVehicle(playerid))
        return SendClientMessage(playerid, Erro, "Você está em um veículo, saia e tente novamente");

    for(new i = 0; i < MAX_AREA_PLANTER; i++)
    {
        if(IsPlayerInRangeOfPoint(playerid, 4.0, AreaPlanterPot[i][app_x], AreaPlanterPot[i][app_y], AreaPlanterPot[i][app_z]))
        {
            if(CannabisUsed[i] != playerid)
                return SendClientMessage(playerid, Erro, "Essa plantação não pertênce a você");

            if(!CannabisOK[i])
                return SendClientMessage(playerid, Erro, "Sua plantação não está pronta");

            new rand = RandomValueCannabis();

            PlayerInfo[playerid][Dinheiro] += rand;
            UpdatePlayerMoney(playerid);

            PlayerInfo[playerid][Estrelas]++;
            UpdatePlayerStar(playerid);

            format(String, MAX_STRING, "Você recebeu $%s e agora tem %d mudas", IsMoney(rand, "."), PlayerInfo[playerid][cannabis]);
            SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);

            CannabisUsed[i] = -1;
            CannabisOK[i] = false;
            KillTimer(T_DestroyCannabis[playerid]);
            KillTimer(T_CannabisOK[playerid]);
            KillTimer(T_Cannabis[playerid]);
            DestroyDynamicObject(ObjectCannabis[i]);

            UpdateDynamic3DTextLabelText(LabelCannabis[i], 0xFFFFFFFF, "{FFFFFF}Área de plantacão\nPertênce à {8080C0}N/A");
            return 1;
        }
    }
    return SendClientMessage(playerid, Erro, "Você não está em uma área de colher Cannabis");
}

CMD:fornecedor(playerid)
{
    if(PlayerInfo[playerid][Profissao] != potplanter && PlayerInfo[playerid][Profissao] != weaponproducer)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    CreateCPGPS(playerid, 198.59, -234.24, 1.77);
    return 1;
}
