#include YSI\y_hooks

enum LocationsEnum
{
    Locality[40],
    Float:GasPosX,
    Float:GasPosY,
    Float:GasPosZ,
    GetWork

};

new LocationsGas[12][LocationsEnum] =
{
    {"Fort Carson", 6.6462, 1116.0157, 20.2422, 100},
    {"Fort Carson", -12.3098, 1117.0446, 20.2056, 110},
    {"Fort Carson", -39.1690, 1079.0314, 20.2445, 120},
    {"Fort Carson", -38.0604, 1043.7631, 20.2422, 130},
    {"Fort Carson", -253.6878, 997.8894, 20.2422, 140},
    {"Fort Carson", -272.9225, 999.8505, 20.2422, 150},
    {"Fort Carson", -256.4237, 1042.2617, 20.2422, 160},
    {"Fort Carson", -260.1199, 1081.1206, 20.2422, 170},
    {"Fort Carson", -259.0572, 1118.7147, 20.2271, 180},
    {"Fort Carson", -293.8350, 1170.5311, 20.2422, 190},
    {"Fort Carson", -364.8671, 1116.6910, 20.2221, 200},
    {"Fort Carson", -367.8246, 1171.1335, 20.2719, 210}
};

enum PLEnum
{
    pLocality[40],
    Float:pGasPosX,
    Float:pGasPosY,
    Float:pGasPosZ,
    pGetWork
};

new PLGas[MAX_PLAYERS][PLEnum];

enum r_VSG
{
    Float:r_vsg_x,
    Float:r_vsg_y,
    Float:r_vsg_z
};

new VehicleSGasRandom[6][r_VSG] =
{
    {-451.0000, 2210.0000, 42.3809},
    {-447.0000, 2210.0000, 42.3809},
    {-443.0000, 2210.0000, 42.3809},
    {-439.0000, 2210.0000, 42.3809},
    {-435.0000, 2210.0000, 42.3809},
    {-431.0000, 2210.0000, 42.3809}
};

#define MAX_VEHICLE_GAS 100

enum e_VSG
{
    VSGas,
    NameVSGas[MAX_PLAYER_NAME],
    Text3D:LabelVSGas
};

new VehicleSGas[MAX_PLAYERS][e_VSG];

new bool:StealingGas[MAX_PLAYERS],
    bool:CaughtGas[MAX_PLAYERS],
    ObjectGas[MAX_PLAYERS],
    CPS_Gas[MAX_PLAYERS],
    AmountGas[MAX_PLAYERS];

hook OnPlayerDisconnect(playerid, reason)
{
    StealingGas[playerid] = false;
    CaughtGas[playerid] = false;
    ObjectGas[playerid] = 0;
    CPS_Gas[playerid] = 0;
    AmountGas[playerid] = 0;

    PLGas[playerid][pLocality] = 0;
    PLGas[playerid][pGasPosX] = 0;
    PLGas[playerid][pGasPosY] = 0;
    PLGas[playerid][pGasPosZ] = 0;
    PLGas[playerid][pGetWork] = 0;

    Delete3DTextLabel(VehicleSGas[playerid][LabelVSGas]);
    DestroyVehicle(VehicleSGas[playerid][VSGas]);
    VehicleSGas[playerid][VSGas] = 0;
    VehicleSGas[playerid][NameVSGas] = 0;
	return 1;
}

hook OnGameModeInit()
{
    CreatePickup(1239, 1, -439.6549, 2218.1484, 42.4297);
    Create3DTextLabel("{FF8080}Veiculo Profissão\n{FFFFFF}Aperte a letra '{00FF00}Y{FFFFFF}' para criar", 0xFFFFFFFF, -439.6549, 2218.1484, 42.4297, 50.0, 0);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_YES && PlayerInfo[playerid][Profissao] == thief && IsPlayerInRangeOfPoint(playerid, 2.0, -439.6549, 2218.1484, 42.4297))
    {
        if(VehicleSGas[playerid][VSGas] != 0)
            return SendClientMessage(playerid, Erro, "O Seu veículo já foi criado!");

        new i = random(sizeof(VehicleSGasRandom));

        format(VehicleSGas[playerid][NameVSGas], MAX_PLAYER_NAME, PlayerInfo[playerid][Nome]);
        format(String, sizeof(String), "{FFFFFF}Ladrão {FF8080}%s", VehicleSGas[playerid][NameVSGas]);

        VehicleSGas[playerid][LabelVSGas] = Create3DTextLabel(String, 0xFFFFFFFF, VehicleSGasRandom[i][r_vsg_x], VehicleSGasRandom[i][r_vsg_y], VehicleSGasRandom[i][r_vsg_z], 20.0, 0);
        VehicleSGas[playerid][VSGas] = AddStaticVehicleEx(478, VehicleSGasRandom[i][r_vsg_x], VehicleSGasRandom[i][r_vsg_y], VehicleSGasRandom[i][r_vsg_z], 0.0, 129, 129, 100);
        Attach3DTextLabelToVehicle(VehicleSGas[playerid][LabelVSGas], VehicleSGas[playerid][VSGas], 0.0, 0.0, 0.0);

        SendClientMessage(playerid, 0xFF8080AA, "Seu veículo foi criado com sucesso!");
    }
	return 1;
}

hook OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    if(vehicleid == VehicleSGas[playerid][VSGas])
    {
        if(!ispassenger && vehicleid != INVALID_VEHICLE_ID)
        {
            if(PlayerInfo[playerid][Profissao] == thief)
            {
                if(PlayerInfo[playerid][Nome] == VehicleSGas[playerid][NameVSGas])
                {
                    return true;

                } else {
                    format(String, sizeof(String), "Este veiculo pertence a %s!", VehicleSGas[playerid][NameVSGas]);
                    SendClientMessage(playerid, Erro, String);
                }
            } else {
                SendClientMessage(playerid, Erro, "Veiculo exclusivo do cargo Ladrão de Gás!");
            }
            ClearAnimations(playerid);
        }
    }
    return 1;
}

stock IsVehicleInRangeOfPoint(playerid, vehicleid, Float:range)
{
    new Float:x, Float:y, Float:z;

    GetPlayerPos(playerid, x, y, z);
    return range >= GetVehicleDistanceFromPoint(vehicleid, x, y, z);
}

/******************************************************************************/
/******************************| COMMANDS THIEF |******************************/
/******************************************************************************/

CMD:roubargas(playerid)
{
    if(PlayerInfo[playerid][Profissao] != thief)
        return SendClientMessage(playerid, Erro, "Você não tem permissão!");

    if(VehicleSGas[playerid][VSGas] == 0)
        return SendClientMessage(playerid, Erro, "Você não pegou seu veículo de ladrão!");

    if(AmountGas[playerid] != 0)
        return SendClientMessage(playerid, Erro, "Você já pegou informação de roubo de gás!");

    AmountGas[playerid] = 5;
    SendClientMessage(playerid, 0xFF8080AA, "Foi informado que tem 5 bujões de gás marcando bobeira!!!");
    SendClientMessage(playerid, 0xFF8080AA, "Vá até o checkpoint marcado no mini-mapa para começar a roubar!");

    new i = random(sizeof(LocationsGas));

    format(PLGas[playerid][pLocality], 40, LocationsGas[i][Locality]);
    PLGas[playerid][pGasPosX] = LocationsGas[i][GasPosX];
    PLGas[playerid][pGasPosY] = LocationsGas[i][GasPosY];
    PLGas[playerid][pGasPosZ] = LocationsGas[i][GasPosZ];
    PLGas[playerid][pGetWork] = LocationsGas[i][GetWork];

    //CPS_Gas[playerid] = CPS_AddCheckpoint(LocationsGas[i][GasPosX], LocationsGas[i][GasPosY], LocationsGas[i][GasPosZ], 1.0, 999999999);
    ObjectGas[playerid] = CreateObject(1370, LocationsGas[i][GasPosX], LocationsGas[i][GasPosY], LocationsGas[i][GasPosZ], 0.0, 0.0, 0.0);
    return 1;
}
CMD:pegargas(playerid)
{
    if(PlayerInfo[playerid][Profissao] != thief)
        return SendClientMessage(playerid, Erro, "Você não tem permissão!");

    if(AmountGas[playerid] == 0)
        return SendClientMessage(playerid, Erro, "Você não tem pegou nenhuma informação de roubo de gás!");

    if(VehicleSGas[playerid][VSGas] == 0)
        return SendClientMessage(playerid, Erro, "Você não pegou seu veículo de ladrão!");

    if(IsVehicleInRangeOfPoint(playerid, VehicleSGas[playerid][VSGas], 10))
        return SendClientMessage(playerid, Erro, "Seu veículo de ladrão ta muito longe!");

    if(!IsPlayerInRangeOfPoint(playerid, 10.0, PLGas[playerid][pGasPosX], PLGas[playerid][pGasPosY], PLGas[playerid][pGasPosZ]))
        return SendClientMessage(playerid, Erro, "Você não está no local informado!");

    if(!IsPlayerInRangeOfPoint(playerid, 2.0, PLGas[playerid][pGasPosX], PLGas[playerid][pGasPosY], PLGas[playerid][pGasPosZ]))
        return SendClientMessage(playerid, Erro, "Você está longe, vá mas perto do bujão de gás!");

    CaughtGas[playerid] = true;
    DestroyObject(ObjectGas[playerid]);
    SetPlayerAttachedObject(playerid, 3, 1370, 6, 0.339000, 0.235000, 0.090999, 69.699974, 118.899940, 36.300010, 0.699999, 0.699999, 0.699999);
    return 1;
}
CMD:colocargas(playerid)
{
    if(PlayerInfo[playerid][Profissao] != thief)
        return SendClientMessage(playerid, Erro, "Você não tem permissão!");

    if(CaughtGas[playerid] == false)
        return SendClientMessage(playerid, Erro, "Você não tem nenhum Bujão de Gás na mão!");

    AttachObjectToVehicle(1370, 478, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0);

    //format(String, sizeof(String), "Agora tem só mais %d informação de roubo de gás!", AmountGas[playerid]);
    //SendClientMessage(playerid, 0xFF8080AA, String);
    //format(String, sizeof(String), "Vá até o próximo roubo de gás localizado em %s", LocationsGas[playerid][Locality]);
    //SendClientMessage(playerid, 0xFF8080AA, String);
    return 1;
}
CMD:cancelarroubo(playerid)
{
    if(PlayerInfo[playerid][Profissao] != thief)
        return SendClientMessage(playerid, Erro, "Você não tem permissão!");

    return 1;
}
