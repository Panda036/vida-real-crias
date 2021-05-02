#include YSI\y_hooks

#define LOADED_PLACE_INVALID    0
#define LOADED_PLACE_LS         1
#define LOADED_PLACE_LV         2
#define LOADED_PLACE_SF         3

enum e_scd
{
    Float:scd_x,
    Float:scd_y,
    Float:scd_z
};

new vr_strongcardriver[5][e_scd] =
{
    {1770.00, -1700.14, 14.03},
    {1775.00, -1700.14, 14.03},
    {1780.00, -1700.14, 14.03},
    {1785.00, -1700.14, 14.03},
    {1795.00, -1700.14, 14.03}
};

hook OnGameModeInit()
{
    CreateVehicleLocation(1773.58, -1689.39, 13.42);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(PRESSED(KEY_NO) && PlayerInfo[playerid][Profissao] == strongcardriver)
    {
        if(!IsPlayerInAnyVehicle(playerid))
            return SendClientMessage(playerid, Erro, "Você não está em um veículo");

        if(GetVehicleModel(GetPlayerVehicleID(playerid)) != 428)
            return SendClientMessage(playerid, Erro, "Você não está em um Carro Forte");

        if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
            return SendClientMessage(playerid, Erro, "Você não está dirigindo um Carro Forte");

        new vehicleid = getPlayerVehicleID(playerid);

        if(!PublicVehicle[vehicleid][pv_loaded])
        {
            if(IsPlayerInBankLS(playerid))
                PublicVehicle[vehicleid][pv_place] = LOADED_PLACE_LS;
            else if(IsPlayerInBankLV(playerid))
                PublicVehicle[vehicleid][pv_place] = LOADED_PLACE_LV;
            else if(IsPlayerInBankSF(playerid))
                PublicVehicle[vehicleid][pv_place] = LOADED_PLACE_SF;
            else
                return SendClientMessage(playerid, Erro, "Você não está no Banco de Los Santos/Las Venturas/San Fierro");

            LoadOrDownload(playerid, vehicleid, true);
            SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Carro Forte carregado, vá até algum caixa eletrônico e descarregue");
            return 1;
        }
        else
        {
            for(new cashid = 0; cashid < MAX_CASHMACHINE; cashid++)
            {
                if(IsPlayerInRangeOfPoint(playerid, 5.0, CashMachine[cashid][cm_x], CashMachine[cashid][cm_y], CashMachine[cashid][cm_z]))
                {
                    LoadOrDownload(playerid, vehicleid, false);

                    new value, Float:x, Float:y, Float:z;

                    value = RandomValueStrongCarDriver(playerid, vehicleid);

                    PublicVehicle[vehicleid][pv_place] = LOADED_PLACE_INVALID;

                    if(PublicVehicle[vehicleid][pv_security] != INVALID_PLAYER_ID)
                    {
                        new id = PublicVehicle[vehicleid][pv_security];
                        new value_security = floatround((value/2), floatround_round);

                        format(String, MAX_STRING, "Você recebeu $%s pela segurança do Carro Forte do(a) jogador(a) %s[%d]", IsMoney(value_security, "."), PlayerInfo[playerid][Nome], playerid);
                        SendClientMessage(id, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Segurança foi automaticamente desfeita");
                        SendClientMessage(id, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);

                        PlayerInfo[id][Dinheiro] += value_security;
                        UpdatePlayerMoney(id);

                        GiveBonus(id, 500);

                        PublicVehicle[vehicleid][pv_security] = INVALID_PLAYER_ID;
                    }

                    GetPlayerPos(playerid, x, y, z);
                    GetPlayer2DZone(zone, MAX_ZONE_NAME, x, y);

                    format(String, MAX_STRING, "Você recebeu $%s pela entrega localizada em %s", IsMoney(value, "."), zone);
                    SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Carro Forte descarregado, vá até o banco de Los Santos/Las Venturas/San Fierro");
                    SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);

                    PlayerInfo[playerid][Dinheiro] += value;
                    UpdatePlayerMoney(playerid);

                    GiveBonus(playerid, 500);
                    return 1;
                }
            }
            SendClientMessage(playerid, Erro, "Você não está perto de um caixa eletrônico, chegue mais perto");
        }
        return 1;
    }
    if(PRESSED(KEY_YES) && IsPlayerInRangeOfPoint(playerid, 2.0, 1773.58, -1689.39, 13.42))
    {
        if(PlayerInfo[playerid][Profissao] != strongcardriver)
            return SendClientMessage(playerid, Erro, "Você não tem permissão");

        if(PV_Profission[playerid])
            return SendClientMessage(playerid, Erro, "Seu veículo já está criado");

        new rand = random(sizeof(vr_strongcardriver));

        new vehicleid = CreatePlayerVehicle(playerid, 428, vr_strongcardriver[rand][scd_x], vr_strongcardriver[rand][scd_y], vr_strongcardriver[rand][scd_z], 0.0, 6, 128);

        SetVehicleHealth(vehicleid, 9999.0);

        SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Foi criado um veículo profissão no estacionamento");
        return 1;
	}
	return 1;
}

stock RandomValueStrongCarDriver(playerid, vehicleid)
{
    new Float:distance;

    switch(PublicVehicle[vehicleid][pv_place])
    {
        case LOADED_PLACE_LS: distance = GetPlayerDistanceFromPoint(playerid, 1778.30, -1663.53, 14.43);
        case LOADED_PLACE_LV: distance = GetPlayerDistanceFromPoint(playerid, 2388.67, 2466.04, 10.8);
        case LOADED_PLACE_SF: distance = GetPlayerDistanceFromPoint(playerid, -1494.52, 920.06, 7.18);
    }
    return (floatround( ( distance * 0.6 ), floatround_round));
}

stock IsPlayerInBankLS(playerid)
{
    new Float:x,Float:y,Float:z;
    GetPlayerPos(playerid, x, y, z);
    if(x >= 1762.52 && y >= -1719.89 && x <= 1810.31 && y <= -1687.55) return 1;
    else return 0;
}

stock IsPlayerInBankLV(playerid)
{
    new Float:x,Float:y,Float:z;
    GetPlayerPos(playerid, x, y, z);
    if(x >= 2370.83 && y >= 2432.56 && x <= 2388.15 && y <= 2498.67) return 1;
    else return 0;
}

stock IsPlayerInBankSF(playerid)
{
    new Float:x,Float:y,Float:z;
    GetPlayerPos(playerid, x, y, z);
    if(x >= -1520.76 && y >= 845.17 && x <= -1490.70 && y <= 998.32) return 1;
    else return 0;
}
