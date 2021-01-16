#include YSI\y_hooks

hook OnPlayerExitVehicle(playerid, vehicleid)
{
    if(PlayerInfo[playerid][Profissao] == strongcarsecurity)
    {
        for(new i = 0; i < MAX_VEHICLES; i++)
        {
            if(vehicleid != PublicVehicle[i][pv_vehicle]) continue;

            if(GetVehicleModel(vehicleid) != 428) break;

            if(PublicVehicle[i][pv_security] != playerid) break;

            new id = PublicVehicle[i][pv_id];

            PublicVehicle[i][pv_security] = INVALID_PLAYER_ID;

            SendClientMessage(playerid, Red, "Você não está mais realizando à segurança do Carro Forte");
            SendClientMessage(id, Red, "Seu Carro Forte está sem Segurança");
            break;
        }
        return 1;
    }
	return 1;
}

CMD:seguranca(playerid)
{
    if(PlayerInfo[playerid][Profissao] != strongcarsecurity)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsPlayerInAnyVehicle(playerid))
        return SendClientMessage(playerid, Erro, "Você não está em um Carro Forte");

    new vehicleid = GetPlayerVehicleID(playerid);

    for(new i = 0; i < MAX_VEHICLES; i++)
    {
        if(vehicleid != PublicVehicle[i][pv_vehicle]) continue;

        if(GetVehicleModel(vehicleid) != 428)
            return SendClientMessage(playerid, Erro, "Você não está em um Carro Forte");

        if(GetPlayerState(playerid) != PLAYER_STATE_PASSENGER)
            return SendClientMessage(playerid, Erro, "Você não está como passageiro(a)");

        if(PublicVehicle[i][pv_security] != INVALID_PLAYER_ID)
            return SendClientMessage(playerid, Erro, "Esse Carro Forte já tem um(a) segurança");

        if(PublicVehicle[i][pv_id] == INVALID_PLAYER_ID) return 0;

        new id = PublicVehicle[i][pv_id];

        PublicVehicle[i][pv_security] = playerid;

        format(String, MAX_STRING, "Agora você está realizando segurança do(a) Motorista %s[%d]", PlayerInfo[id][Nome], id);
        SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);
        format(String, MAX_STRING, "Agora o(a) jogador(a) %s[%d] está realizando sua segurança", PlayerInfo[playerid][Nome], playerid);
        SendClientMessage(id, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);
        break;
    }
    return 1;
}

