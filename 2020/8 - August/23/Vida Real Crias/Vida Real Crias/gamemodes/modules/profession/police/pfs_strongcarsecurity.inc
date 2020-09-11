#include YSI\y_hooks

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(PlayerInfo[playerid][Profissao] == strongcarsecurity)
    {
        new vehicleid = GetPlayerVehicleID(playerid);

        if(GetVehicleModel(vehicleid) != 428)
            return print("ERRO 1");

        if(newstate == PLAYER_STATE_DRIVER)
            return print("ERRO 2");

        if(PublicVehicle[vehicleid][pv_security] != INVALID_PLAYER_ID)
            return print("ERRO 3");

        if(PublicVehicle[vehicleid][pv_id] == INVALID_PLAYER_ID)
            return print("ERRO 4");

        new id = PublicVehicle[vehicleid][pv_id];

        PublicVehicle[vehicleid][pv_security] = playerid;

        format(String, 128, "Agora você está realizando segurança do(a) Motorista %s[%d]", PlayerInfo[id][Nome], id);
        SendClientMessage(playerid, color_strongcarsecurity, String);
        format(String, 128, "Agora o(a) jogador(a) %s[%d] está realizando sua segurança", PlayerInfo[playerid][Nome], playerid);
        SendClientMessage(id, color_strongcarsecurity, String);
        return 1;
    }
	return 1;
}

hook OnPlayerExitVehicle(playerid, vehicleid)
{
    if(PlayerInfo[playerid][Profissao] == strongcarsecurity)
    {
        if(GetVehicleModel(vehicleid) != 428)
            return 0;

        if(PublicVehicle[vehicleid][pv_security] != playerid)
            return 0;

        new id = PublicVehicle[vehicleid][pv_id];

        PublicVehicle[vehicleid][pv_security] = INVALID_PLAYER_ID;

        SendClientMessage(playerid, Red, "Você não está mais realizando à segurança do Carro Forte");
        SendClientMessage(id, Red, "Seu Carro Forte está sem Segurança");
        return 1;
    }
	return 1;
}
