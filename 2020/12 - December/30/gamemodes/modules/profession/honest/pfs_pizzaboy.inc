#include YSI\y_hooks

enum e_vrpz
{
    Float:vrpz_x,
    Float:vrpz_y,
    Float:vrpz_z
};

new vr_pizzaboy[6][e_vrpz] =
{
    {2121.20, -1779.24, 12.96},
    {2121.16, -1776.75, 12.95},
    {2121.12, -1774.24, 12.96},
    {2121.13, -1771.60, 12.96},
    {2121.12, -1769.12, 12.96},
    {2121.00, -1766.65, 12.96}
};

enum e_pbdt
{
    Float:pbdt_x,
    Float:pbdt_y,
    Float:pbdt_z,
    pbdt_value
};

enum e_pbif
{
    Float:pbif_x,
    Float:pbif_y,
    Float:pbif_z,
    pbif_value
};

new pb_data[12][e_pbdt] =
{
    {802.90, -1731.16, 13.54, 155},
    {760.19, -1660.28, 4.36, 120},
    {851.89, -1413.33, 13.36, 125},
    {1183.66, -1264.12, 15.17, 200},
    {1230.58, -1017.63, 32.60, 180},
    {1193.52, -1020.56, 32.54, 140},
    {1089.81, -1093.62, 25.50, 105},
    {1268.93, -908.62, 42.88, 120},
    {2652.80, -1997.71, 13.55, 160},
    {2306.96, -1666.37, 14.54, 100},
    {2505.80, -1682.95, 13.54, 220},
    {2175.58, -999.38, 62.97, 130}
};

new pb_info[MAX_PLAYERS][e_pbif];
new pb_pizzas[MAX_PLAYERS];
new Text3D:pb_label[MAX_PLAYERS];
new pb_pickup[MAX_PLAYERS];
new pb_mapicon[MAX_PLAYERS];
new BlockNewPizza[MAX_PLAYERS];

hook OnGameModeInit()
{
    CreateVehicleLocation(2122.31, -1789.06, 13.55);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    left_pfs_pizzaboy(playerid);
	return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(PRESSED(KEY_YES))
	{
        if(!IsPlayerInRangeOfPoint(playerid, 2.0, 2122.31, -1789.06, 13.55))
            return 1;

        if(PlayerInfo[playerid][Profissao] != pizzaboy)
            return SendClientMessage(playerid, Erro, "Você não tem permissão");

        if(PV_Profission[playerid])
            return SendClientMessage(playerid, Erro, "Seu veículo já está criado");

        SetPlayerSkin(playerid, 155);

        new rand = random(sizeof(vr_pizzaboy));

        CreatePlayerVehicle(playerid, 448, vr_pizzaboy[rand][vrpz_x], vr_pizzaboy[rand][vrpz_y], vr_pizzaboy[rand][vrpz_z], 268.0, -1, -1);

        SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Foi criado um veículo profissão no estacionamento");
        return 1;
	}
    if(PRESSED(KEY_NO))
    {
        if(PlayerInfo[playerid][Profissao] == pizzaboy)
        {
            if(pb_pizzas[playerid])
            {
                if(!IsPlayerInRangeOfPoint(playerid, 2.0, pb_info[playerid][pbif_x], pb_info[playerid][pbif_y], pb_info[playerid][pbif_z]))
                    return SendClientMessage(playerid, Erro, "Você não está no local de entrega, chegue mais perto");

                if(IsPlayerInAnyVehicle(playerid))
                    return SendClientMessage(playerid, Erro, "Saia do veículo para poder entregar");

                if(GetVehicleModel(LastVehicle[playerid]) != 448)
                    return SendClientMessage(playerid, Erro, "Seu último veículo não é de Pizzaboy");

                if(BlockNewPizza[playerid])
                    return SendClientMessage(playerid, Erro, "Você acabou de entregar, aguarde alguns segundos...");

                pb_pizzas[playerid]--;

                PlayerInfo[playerid][Dinheiro] += pb_info[playerid][pbif_value];
                UpdatePlayerMoney(playerid);

                format(String, MAX_STRING, "Você recebeu $%d pela entrega", pb_info[playerid][pbif_value]);
                SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);

                GiveBonus(playerid, 500);

                if(pb_pizzas[playerid])
                {
                    new rand = random(sizeof(pb_data));

                    if(pb_data[rand][pbdt_x] == pb_info[playerid][pbif_x] && pb_data[rand][pbdt_y] == pb_info[playerid][pbif_y] && pb_data[rand][pbdt_z] == pb_info[playerid][pbif_z])
                        { rand = random(sizeof(pb_data)); }

                    pb_info[playerid][pbif_x] = pb_data[rand][pbdt_x];
                    pb_info[playerid][pbif_y] = pb_data[rand][pbdt_y];
                    pb_info[playerid][pbif_z] = pb_data[rand][pbdt_z];
                    pb_info[playerid][pbif_value] = pb_data[rand][pbdt_value];

                    GetPlayer2DZone(zone, MAX_ZONE_NAME, pb_data[rand][pbdt_x], pb_data[rand][pbdt_y]);

                    format(String, sizeof(String), "Agora vá até à próxima localizada em %s", zone);
                    SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);

                    if(IsValidDynamicPickup(pb_pickup[playerid])) DestroyDynamicPickup(pb_pickup[playerid]);
                    if(IsValidDynamicMapIcon(pb_mapicon[playerid])) DestroyDynamicMapIcon(pb_mapicon[playerid]);
                    if(IsValidDynamic3DTextLabel(pb_label[playerid])) DestroyDynamic3DTextLabel(pb_label[playerid]);

                    pb_pickup[playerid] = CreateDynamicPickup(1582, 1, pb_info[playerid][pbif_x], pb_info[playerid][pbif_y], pb_info[playerid][pbif_z], -1, -1, playerid, -1.0);
                    pb_mapicon[playerid] = CreateDynamicMapIcon(pb_info[playerid][pbif_x], pb_info[playerid][pbif_y], pb_info[playerid][pbif_z], 53, -1, -1, -1, playerid, -1.0, MAPICON_GLOBAL, -1, 1);
                    pb_label[playerid] = CreateDynamic3DTextLabel("{FFFFFF}Entregar Pizza\nPrecione \"{FF0000}N{FFFFFF}\"", 0xFFFFFFFF, pb_info[playerid][pbif_x], pb_info[playerid][pbif_y], pb_info[playerid][pbif_z], 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, -1, -1, playerid);

                    BlockNewPizza[playerid] = true;
                    SetTimerEx("UnlockingNewsPizza", 1000*30, false, "d", playerid);
                }
                else
                {
                    if(IsValidDynamicPickup(pb_pickup[playerid])) DestroyDynamicPickup(pb_pickup[playerid]);
                    if(IsValidDynamicMapIcon(pb_mapicon[playerid])) DestroyDynamicMapIcon(pb_mapicon[playerid]);
                    if(IsValidDynamic3DTextLabel(pb_label[playerid])) DestroyDynamic3DTextLabel(pb_label[playerid]);

                    SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Acabou as suas pizzas, vá até HQ e pegue mais");
                }
                return 1;
            }
            else
            {
                if(!IsPlayerInRangeOfPoint(playerid, 30.0, 2122.31, -1789.06, 13.55))
                    return SendClientMessage(playerid, Erro, "Você não está no local de trabalho");

                if(PlayerInfo[playerid][Profissao] != pizzaboy)
                    return SendClientMessage(playerid, Erro, "Você não tem permissão");

                pb_pizzas[playerid] = 5;

                new rand = random(sizeof(pb_data));

                pb_info[playerid][pbif_x] = pb_data[rand][pbdt_x];
                pb_info[playerid][pbif_y] = pb_data[rand][pbdt_y];
                pb_info[playerid][pbif_z] = pb_data[rand][pbdt_z];
                pb_info[playerid][pbif_value] = pb_data[rand][pbdt_value];

                pb_pickup[playerid] = CreateDynamicPickup(1582, 1, pb_info[playerid][pbif_x], pb_info[playerid][pbif_y], pb_info[playerid][pbif_z], -1, -1, playerid, -1.0);
                pb_mapicon[playerid] = CreateDynamicMapIcon(pb_info[playerid][pbif_x], pb_info[playerid][pbif_y], pb_info[playerid][pbif_z], 53, -1, -1, -1, playerid, -1.0, MAPICON_GLOBAL, -1, 1);
                pb_label[playerid] = CreateDynamic3DTextLabel("{FFFFFF}Entregar Pizza\nPrecione \"{FF0000}N{FFFFFF}\"", 0xFFFFFFFF, pb_info[playerid][pbif_x], pb_info[playerid][pbif_y], pb_info[playerid][pbif_z], 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, -1, -1, playerid);

                format(String, MAX_STRING, "Você pegou %d Pizzas", pb_pizzas[playerid]);
                SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);
                SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Vá até a marcação vermelha em seu mini-mapa e as entregue");
            }
            return 1;
        }
        return 1;
    }
	return 1;
}

forward UnlockingNewsPizza(playerid);
public UnlockingNewsPizza(playerid)
{
    BlockNewPizza[playerid] = false;
    return 1;
}

stock left_pfs_pizzaboy(playerid)
{
    if(PlayerInfo[playerid][Profissao] == pizzaboy)
    {
        if(pb_pizzas[playerid])
        {
            DestroyDynamicPickup(pb_pickup[playerid]);
            DestroyDynamicMapIcon(pb_mapicon[playerid]);
            DestroyDynamic3DTextLabel(pb_label[playerid]);
            pb_pizzas[playerid] = 0;
        }

        pb_info[playerid][pbif_x] = 0;
        pb_info[playerid][pbif_y] = 0;
        pb_info[playerid][pbif_z] = 0;
        pb_info[playerid][pbif_value] = 0;

        BlockNewPizza[playerid] = false;
        return 1;
    }
    return 1;
}
