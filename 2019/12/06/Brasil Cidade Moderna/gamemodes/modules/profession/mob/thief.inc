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
    if(newkeys == KEY_YES && PlayerInfo[playerid][Profissao] == LadraoGas && IsPlayerInRangeOfPoint(playerid, 2.0, -439.6549, 2218.1484, 42.4297))
    {
        if(VehicleSGas[playerid][VSGas] != 0)
            return SendClientMessage(playerid, Erro, "| ERRO | O Seu veículo já foi criado!");

        new i = random(sizeof(VehicleSGasRandom));

        format(VehicleSGas[playerid][NameVSGas], MAX_PLAYER_NAME, PlayerInfo[playerid][Nome]);
        format(String, sizeof(String), "{FFFFFF}Ladrão {FF8080}%s", VehicleSGas[playerid][NameVSGas]);

        VehicleSGas[playerid][LabelVSGas] = Create3DTextLabel(String, 0xFFFFFFFF, VehicleSGasRandom[i][r_vsg_x], VehicleSGasRandom[i][r_vsg_y], VehicleSGasRandom[i][r_vsg_z], 20.0, 0);
        VehicleSGas[playerid][VSGas] = AddStaticVehicleEx(478, VehicleSGasRandom[i][r_vsg_x], VehicleSGasRandom[i][r_vsg_y], VehicleSGasRandom[i][r_vsg_z], 0.0, 129, 129, 100);
        Attach3DTextLabelToVehicle(VehicleSGas[playerid][LabelVSGas], VehicleSGas[playerid][VSGas], 0.0, 0.0, 0.0);

        SendClientMessage(playerid, 0xFF8080AA, "| LADRÃO | Seu veículo foi criado com sucesso!");
    }
	return 1;
}

hook OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    if(vehicleid == VehicleSGas[playerid][VSGas])
    {
        if(!ispassenger && vehicleid != INVALID_VEHICLE_ID)
        {
            if(PlayerInfo[playerid][Profissao] == LadraoGas)
            {
                if(PlayerInfo[playerid][Nome] == VehicleSGas[playerid][NameVSGas])
                {
                    return true;

                } else {
                    format(String, sizeof(String), "| ERRO | Este veiculo pertence a %s!", VehicleSGas[playerid][NameVSGas]);
                    SendClientMessage(playerid, Erro, String);
                }
            } else {
                SendClientMessage(playerid, Erro, "| ERRO | Veiculo exclusivo do cargo Ladrão de Gás!");
            }
            ClearAnimations(playerid);
        }
    }
    return 1;
}

hook OnPlayerEnterCheckpoint(playerid)
{
    if(CPS_GetPlayerCheckpoint(playerid) == CPS_Gas[playerid])
    {
        SendClientMessage(playerid, 0xFF8080AA, "| LADRÃO | Foi chegou até o local informado, para pegar o bujão de gás. digite: /PegarGas!");
        CPS_RemoveCheckpoint(CPS_Gas[playerid]);
        return 1;
    }
	return 1;
}

stock IsVehicleInRangeOfPoint(playerid, vehicleid, Float:range)
{
    GetPlayerPos(playerid, X, Y, Z);
    return range >= GetVehicleDistanceFromPoint(vehicleid, X, Y, Z);
}
