#include YSI\y_hooks

enum e_rsta
{
    Float:rsta_x,
    Float:rsta_y,
    Float:rsta_z
};

new RandomSpawnTaxiAir[3][e_rsta] =
{
    {1664.00, 1635.30, 10.93},
    {1677.00, 1635.30, 10.93},
    {1690.00, 1635.30, 10.93}
};

hook OnGameModeInit()
{
    CreateVehicleLocation(1655.21, 1618.53, 10.82);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(PRESSED(KEY_YES))
	{
        if(!IsPlayerInRangeOfPoint(playerid, 2.0, 1655.21, 1618.53, 10.82))
            return 1;

        if(PlayerInfo[playerid][Profissao] != taxiair)
            return SendClientMessage(playerid, Erro, "Você não tem permissão");

        if(PV_Profission[playerid])
            return SendClientMessage(playerid, Erro, "Seu veículo já está criado");

        new rand = random(sizeof(RandomSpawnTaxiAir));

        CreatePlayerVehicle(playerid, 487, RandomSpawnTaxiAir[rand][rsta_x], RandomSpawnTaxiAir[rand][rsta_y],RandomSpawnTaxiAir[rand][rsta_z], 180.00, 6, 6);

        SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Foi criado um veículo profissão no estacionamento");
        return 1;
	}
	return 1;
}
