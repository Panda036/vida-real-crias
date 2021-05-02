#include YSI\y_hooks

enum e_ds
{
    Float:ds_x,
    Float:ds_y,
    Float:ds_z,
};

new ds_place[MAX_TYPE_CNH][MAX_PLACE_DS][e_ds] =
{
    {
        {-1456.51, -588.07, 1056.37},
        {-1520.99, -677.26, 1052.18},
        {-1459.05, -736.34, 1049.76},
        {-1360.54, -743.54, 1050.38},
        {-1291.45, -726.85, 1050.38},
        {-1491.17, -647.16, 1053.70},
        {-1423.23, -617.49, 1051.83},
        {-1358.83, -721.23, 1054.36},
        {-1353.81, -626.28, 1052.26},
        {-1426.28, -588.73, 1054.19}
    },
    {
        {289.30, 2510.29, 52.45},
        {145.81, 2517.95, 90.74},
        {-56.57, 2537.54, 122.47},
        {-258.66, 2434.66, 155.58},
        {-339.71, 2207.64, 174.74},
        {-182.39, 2098.02, 171.64},
        {21.12, 2150.71, 142.25},
        {167.31, 2235.67, 108.60},
        {275.22, 2393.90, 68.70},
        {403.20, 2503.30, 16.66}
    },
    {
        {236.81, -400.34, -0.57},
        {329.43, -322.77, -0.57},
        {442.75, -264.11, -0.59},
        {587.82, -231.40, -0.59},
        {752.33, -192.50, -0.54},
        {1098.93, -106.01, -0.53},
        {1388.24, -255.91, -0.54},
        {1637.51, -16.23, -0.52},
        {1972.30, -113.74, -0.50},
        {2110.33, -109.56, -0.54}
    }
};

new cps_DS[MAX_PLAYERS];
new count_DS[MAX_PLAYERS];

hook OnPlayerDisconnect(playerid, reason)
{
    if(!PlayerInfo[playerid][pds_in])
    {
        DestroyVehicleEx(PlayerInfo[playerid][pds_vehicleid]);

        PlayerInfo[playerid][pds_in] = false;
        DestroyDynamicRaceCP(cps_DS[playerid]);
        count_DS[playerid] = 0;
        PlayerInfo[playerid][pds_type] = 0;
        return 1;
    }
    return 1;
}

hook OnPlayerExitVehicle(playerid, vehicleid)
{
    if(!PlayerInfo[playerid][pds_in]) return 0;

    if(vehicleid != PlayerInfo[playerid][pds_vehicleid]) return 0;

    SendClientMessage(playerid, Yellow, "Volte para o veículo e evite reprovação");
	return 1;
}

stock Start_DS(playerid, type[])
{
    new model, Float:x, Float:y, Float:z, Float:a;

    if(!strcmp(type, "a"))
    {
        model = 522;
        x = -1427.54;
        y = -588.00;
        z = 1057.34;
        a = 90.0;
    }
    else if(!strcmp(type, "b"))
    {
        model = 560;
        x = -1427.54;
        y = -588.00;
        z = 1057.34;
        a = 90.0;
    }
    else if(!strcmp(type, "c"))
    {
        model = 560;
        x = -1427.54;
        y = -588.00;
        z = 1057.34;
        a = 90.0;
    }
    else if(!strcmp(type, "cht"))
    {
        model = 487;
        x = 416.01;
        y = 2502.13;
        z = 16.68;
        a = 90.0;
    }
    else if(!strcmp(type, "arrais"))
    {
        model = 595;
        x = 188.95;
        y = -421.03;
        z = -0.55;
        a = 290.0;
    }

    format(PlayerInfo[playerid][pds_type], 10, type);

    PlayerInfo[playerid][pds_vehicleid] = CreateVehicleEx(model, x, y, z, a, -1, -1, 0, 0);

    PlayerInfo[playerid][pds_in] = true;
    count_DS[playerid] = 0;

    SetPlayerTeam(playerid, playerid);
    SetVehicleVirtualWorld(PlayerInfo[playerid][pds_vehicleid], WORLD_DS);
    SetPlayerVirtualWorld(playerid, WORLD_DS);

    new count = count_DS[playerid];
    new typeid = GetNumberTypeCNH(PlayerInfo[playerid][pds_type]);
    new interiorid = ( !typeid ? 4 : 0 );
    new typecp = (typeid == 1 ? 3 : 0);

    switch(typeid)
    {
        case TYPE_CNH_ABC:
        {
            SetPlayerInterior(playerid, 4);
            LinkVehicleToInterior(PlayerInfo[playerid][pds_vehicleid], 4);
        }
        case TYPE_CNH_CHT:
        {
            SetPlayerInterior(playerid, 0);
            LinkVehicleToInterior(PlayerInfo[playerid][pds_vehicleid], 0);
        }
        case TYPE_CNH_ARRAIS:
        {
            SetPlayerInterior(playerid, 0);
            LinkVehicleToInterior(PlayerInfo[playerid][pds_vehicleid], 0);
        }
    }

    PutPlayerInVehicle(playerid, PlayerInfo[playerid][pds_vehicleid], 0);

    PlayerPlaySound(playerid, 1057, 0.0, 0.0, 0.0);

    cps_DS[playerid] = CreateDynamicRaceCP(typecp, ds_place[typeid][count][ds_x], ds_place[typeid][count][ds_y], ds_place[typeid][count][ds_z], ds_place[typeid][count+1][ds_x], ds_place[typeid][count+1][ds_y], ds_place[typeid][count+1][ds_z], 5.0, WORLD_DS, interiorid, playerid, -1.0);

    format(String, MAX_STRING, "Prová para CNH %s iníciada, para cancelar à prova ~~> /CancelarProva", type);
    SendClientMessage(playerid, Yellow, String);
    return 1;
}

stock DS_DynamicRaceCP(playerid)
{
    if(!PlayerInfo[playerid][pds_in])
        return 0;

    count_DS[playerid]++;

    switch(count_DS[playerid])
    {
        case ( MAX_PLACE_DS - 1 ):
        {
            PlayerPlaySound(playerid, 1058, 0.0, 0.0, 0.0);

            new Float:health;

            GetVehicleHealth(PlayerInfo[playerid][pds_vehicleid], health);

            SendClientMessage(playerid, Yellow, "Prova finalizada");

            if(health < 700.0)
            {
                SendClientMessage(playerid, Yellow, "Infelizmente por causa das batidas você não foi aprovado, tente novamente");
            }
            else
            {
                SendClientMessage(playerid, Yellow, "Felizmente você foi aprovado, bom jogo");
                SetPlayerCnhType(playerid, PlayerInfo[playerid][pds_type]);
            }

            DestroyDynamicRaceCP(cps_DS[playerid]);
            count_DS[playerid] = 0;
            PlayerInfo[playerid][pds_type] = 0;

            PC_EmulateCommand(playerid, "/cancelarprova");
            return 1;
        }
        case ( MAX_PLACE_DS - 2 ):
        {
            PlayerPlaySound(playerid, 1057, 0.0, 0.0, 0.0);

            new count = count_DS[playerid];
            new typeid = GetNumberTypeCNH(PlayerInfo[playerid][pds_type]);
            new interiorid = ( !typeid ? 4 : 0 );
            new typecp = (typeid == 1 ? 3 : 1);

            DestroyDynamicRaceCP(cps_DS[playerid]);
            cps_DS[playerid] = CreateDynamicRaceCP(typecp, ds_place[typeid][count][ds_x], ds_place[typeid][count][ds_y], ds_place[typeid][count][ds_z], ds_place[typeid][count+1][ds_x], ds_place[typeid][count+1][ds_y], ds_place[typeid][count+1][ds_z], 5.0, WORLD_DS, interiorid, playerid, -1.0);
        }
        default:
        {
            PlayerPlaySound(playerid, 1057, 0.0, 0.0, 0.0);

            new count = count_DS[playerid];
            new typeid = GetNumberTypeCNH(PlayerInfo[playerid][pds_type]);
            new interiorid = ( !typeid ? 4 : 0 );
            new typecp = (typeid == 1 ? 3 : 0);

            DestroyDynamicRaceCP(cps_DS[playerid]);
            cps_DS[playerid] = CreateDynamicRaceCP(typecp, ds_place[typeid][count][ds_x], ds_place[typeid][count][ds_y], ds_place[typeid][count][ds_z], ds_place[typeid][count+1][ds_x], ds_place[typeid][count+1][ds_y], ds_place[typeid][count+1][ds_z], 5.0, WORLD_DS, interiorid, playerid, -1.0);
        }
    }
    return 1;
}

/******************************************************************************/
/**************************| COMMANDS DRIVINGSCHOOL |**************************/
/******************************************************************************/

CMD:cancelarprova(playerid)
{
    if(!PlayerInfo[playerid][pds_in])
        return SendClientMessage(playerid, Erro, "Você não está em uma prova da Auto Escola");

    DestroyVehicleEx(PlayerInfo[playerid][pds_vehicleid]);

    PlayerInfo[playerid][pds_in] = false;
    DestroyDynamicRaceCP(cps_DS[playerid]);
    count_DS[playerid] = 0;
    PlayerInfo[playerid][pds_type] = 0;

    SetPlayerInterior(playerid, 3);
    SetPlayerPos(playerid, -2026.94, -104.71, 1035.17);
    SetPlayerVirtualWorld(playerid, WORLD_DEFAULT);
    return 1;
}
