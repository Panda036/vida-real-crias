#include YSI\y_hooks

new Text:TDDetonated[2];

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
    cps_hospital = CPS_AddCheckpoint(1033.1370, 993.1141, 14.03293, 1.5, 30);

    SetObjectMaterialText(CreateObject(19353, 1039.24207, 993.21283, 16.91360, 0.00000, 0.00000, 0.00000), "{FF0000}Hospital", 0, 50, "Arial", 15, 1, 0xFF0000AA, 0, 1);

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

    CreateObject(1502, 1025.69995, 990.79999, 14.12000,   0.00000, 0.00000, 180.00000);
    CreateObject(1502, 1022.66809, 990.75500, 14.12000,   0.00000, 0.00000, 0.00000);
    CreateObject(1502, 1025.69995, 995.81763, 14.12000,   0.00000, 0.00000, 180.00000);
    CreateObject(1502, 1022.66809, 995.77759, 14.12000,   0.00000, 0.00000, 0.00000);

    CreateObject(19449, 1024.00000, 990.79999, 22.44400,   90.00000, 0.00000, 90.00000);
    CreateObject(19449, 1027.43994, 990.79999, 14.30000,   90.00000, 0.00000, 90.00000);
    CreateObject(19449, 1027.44348, 995.79724, 14.30000,   90.00000, 0.00000, 90.00000);
    CreateObject(19449, 1024.00000, 995.79761, 22.44400,   90.00000, 0.00000, 90.00000);
    CreateObject(19449, 1020.91541, 995.79700, 14.30000,   90.00000, 0.00000, 90.00000);
    CreateObject(19449, 1020.91541, 990.79999, 14.30000,   90.00000, 0.00000, 90.00000);
    CreateObject(19449, 1029.33325, 986.14539, 19.35200,   0.00000, 0.00000, 0.00000);
    CreateObject(19449, 1029.33325, 985.99719, 15.86000,   0.00000, 0.00000, 0.00000);
    CreateObject(19449, 1029.31995, 1000.76019, 19.35200,   0.00000, 0.00000, 0.00000);
    CreateObject(19449, 1029.33325, 1000.77515, 15.86000,   0.00000, 0.00000, 0.00000);

    CreateObject(19466, 1025.30005, 995.77759, 17.56760,   0.00000, 0.00000, 90.00000);
    CreateObject(19466, 1023.06000, 995.79761, 17.56760,   0.00000, 0.00000, 90.00000);
    CreateObject(19466, 1023.06000, 990.79999, 17.56760,   0.00000, 0.00000, 90.00000);
    CreateObject(19466, 1025.30005, 990.79999, 17.56760,   0.00000, 0.00000, 90.00000);

    CreateObject(2205, 1035.33521, 992.59998, 14.09980,   0.00000, 0.00000, 90.00000);
    CreateObject(2205, 1035.31592, 996.00000, 14.09980,   0.00000, 0.00000, 90.00000);
    CreateObject(2205, 1035.31592, 999.40002, 14.09980,   0.00000, 0.00000, 90.00000);
    CreateObject(2205, 1035.33264, 989.20001, 14.09980,   0.00000, 0.00000, 90.00000);
    CreateObject(2205, 1035.33264, 985.79999, 14.09980,   0.00000, 0.00000, 90.00000);

    CreateObject(1714, 1037.00000, 986.40002, 14.09980,   0.00000, 0.00000, -90.00000);
    CreateObject(1714, 1037.00000, 989.79999, 14.09980,   0.00000, 0.00000, -90.00000);
    CreateObject(1714, 1037.00000, 993.29999, 14.09980,   0.00000, 0.00000, -90.00000);
    CreateObject(1714, 1037.01086, 996.68323, 14.09980,   0.00000, 0.00000, -90.00000);
    CreateObject(1714, 1036.99414, 1000.04999, 14.09980,   0.00000, 0.00000, -90.00000);

    CreateObject(11685, 1030.80005, 997.00000, 14.11930,   0.00000, 0.00000, 90.00000);
    CreateObject(11685, 1030.80005, 999.00000, 14.11930,   0.00000, 0.00000, 90.00000);
    CreateObject(11685, 1030.80005, 1001.00000, 14.11930,   0.00000, 0.00000, 90.00000);
    CreateObject(11685, 1030.80005, 989.40002, 14.11930,   0.00000, 0.00000, 90.00000);
    CreateObject(11685, 1030.80005, 987.40002, 14.11930,   0.00000, 0.00000, 90.06000);
    CreateObject(11685, 1030.80005, 985.40002, 14.11930,   0.00000, 0.00000, 90.00000);

    CreateObject(1997, 1021.00000, 986.00000, 14.12030,   0.00000, 0.00000, 180.00000);
    CreateObject(1997, 1024.00000, 986.00000, 14.12030,   0.00000, 0.00000, 180.00000);
    CreateObject(1997, 1027.00000, 986.00000, 14.12030,   0.00000, 0.00000, 180.00000);
    CreateObject(1997, 1027.00000, 1000.09998, 14.12030,   0.00000, 0.00000, 0.00000);
    CreateObject(1997, 1024.00000, 1000.09998, 14.12030,   0.00000, 0.00000, 0.00000);
    CreateObject(1997, 1021.00000, 1000.09998, 14.12030,   0.00000, 0.00000, 0.00000);

    TDDetonated[0] = TextDrawCreate(0.000000, 180.000000, "box");
    TextDrawLetterSize(TDDetonated[0], 0.000000, 9.125000);
    TextDrawTextSize(TDDetonated[0], 634.000000, 0.000000);
    TextDrawAlignment(TDDetonated[0], 1);
    TextDrawColor(TDDetonated[0], -1);
    TextDrawUseBox(TDDetonated[0], 1);
    TextDrawBoxColor(TDDetonated[0], 149);
    TextDrawSetShadow(TDDetonated[0], 0);
    TextDrawSetOutline(TDDetonated[0], 0);
    TextDrawBackgroundColor(TDDetonated[0], 255);
    TextDrawFont(TDDetonated[0], 1);
    TextDrawSetProportional(TDDetonated[0], 1);
    TextDrawSetShadow(TDDetonated[0], 0);

    TDDetonated[1] = TextDrawCreate(250.000000, 205.000000, "DETONADO");
    TextDrawLetterSize(TDDetonated[1], 0.811874, 3.309160);
    TextDrawAlignment(TDDetonated[1], 1);
    TextDrawColor(TDDetonated[1], -16777066);
    TextDrawSetShadow(TDDetonated[1], 0);
    TextDrawSetOutline(TDDetonated[1], 1);
    TextDrawBackgroundColor(TDDetonated[1], 255);
    TextDrawFont(TDDetonated[1], 3);
    TextDrawSetProportional(TDDetonated[1], 1);
    TextDrawSetShadow(TDDetonated[1], 0);
	return 1;
}

hook OnPlayerConnect(playerid)
{
    Cidade_Que_Morreu[playerid] = -1;
	return 1;
}

hook OnPlayerSpawn(playerid)
{
    if(Cidade_Que_Morreu[playerid] != -1)
    {
        TextDrawHideForPlayer(playerid, TDDetonated[0]);
        TextDrawHideForPlayer(playerid, TDDetonated[1]);
        Cidade_Que_Morreu[playerid] = -1;
    }
    return 1;
}

hook OnPlayerDeath(playerid, killerid, reason)
{
    if(Cidade_Que_Morreu[playerid] == -1)
    {
        TextDrawShowForPlayer(playerid, TDDetonated[0]);
        TextDrawShowForPlayer(playerid, TDDetonated[1]);
        Cidade_Que_Morreu[playerid] = PickupHospitalNext(playerid);
        SetSpawnInfo(playerid, 0, PlayerInfo[playerid][Skin], Hosp[Cidade_Que_Morreu[playerid]][0], Hosp[Cidade_Que_Morreu[playerid]][1], Hosp[Cidade_Que_Morreu[playerid]][2], 0, 0, 0, 0, 0, 0, 0);
    }
    return 1;
}

hook OnPlayerEnterCheckpoint(playerid)
{
    if(CPS_GetPlayerCheckpoint(playerid) == cps_hospital)
        return ShowPlayerDialog(playerid, hospital, DIALOG_STYLE_LIST, "{FF0000}Menu Hospital", "{FFFFFF}Kit médico \nCurar doença \nTrocar de sexo \nPlano de saude", "Escolher", "Cancelar");

	return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case 0: // Kit Médico
        {

            return 1;
        }
        case 1: // Curar Doença
        {

            return 1;
        }
        case 2: // Trocar de Sexo
        {

            return 1;
        }
        case 3: // Plano de saude
        {

            return 1;
        }
    }
    return 1;
}

PickupHospitalNext(playerid)
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
