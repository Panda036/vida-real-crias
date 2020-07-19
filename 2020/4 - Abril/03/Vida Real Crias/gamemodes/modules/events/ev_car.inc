#include YSI\y_hooks

new bool:InEvent[MAX_PLAYERS];
new OnEvent;
new OpenEvent;

enum e_rse
{
    rse_vehicleid,
    Float:rse_x,
    Float:rse_y,
    Float:rse_z,
    bool:rse_occupied
};

new RS_Event[5][e_rse] =
{
    {0, -1427.5707, -582.3622, 1055.2944},
    {1, -1427.5269, -587.7442, 1055.2944},
    {2, -1427.5482, -585.0950, 1055.2944},
    {3, -1427.4843, -590.5684, 1055.2944},
    {4, -1427.5186, -593.5314, 1055.2944}
};

hook OnGameModeInit()
{
	return 1;
}

hook OnGameModeExit()
{
    OpenEvent = false;
    OnEvent = false;
	return 1;
}

hook OnPlayerConnect(playerid)
{
	return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    InEvent[playerid] = false;
	return 1;
}

hook OnPlayerSpawn(playerid)
{
	return 1;
}

hook OnPlayerDeath(playerid, killerid, reason)
{
	return 1;
}

hook OnVehicleSpawn(vehicleid)
{
	return 1;
}

hook OnVehicleDeath(vehicleid, killerid)
{
	return 1;
}

hook OnPlayerText(playerid, text[])
{
	return 1;
}

hook OnPlayerExitVehicle(playerid, vehicleid)
{
	return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
	return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == events)
    {
        if(listitem == 0 && response)
        {
            OnEvent = true;
            SendClientMessage(playerid, White, "Evento criado, para começar digite: /abrirevento");
            return 1;
        }
        return 1;
    }
	return 1;
}

/******************************************************************************/
/*****************************| COMMANDS EVENTOS |*****************************/
/******************************************************************************/

CMD:criarevento(playerid)
{
    if(OnEvent)
        return SendClientMessage(playerid, Erro, "Já tem evento acontecendo");

    ShowPlayerDialog(playerid, events, DIALOG_STYLE_LIST, "{FF0000}Criar Evento", "{FFFFFF}Corrida de carros", "Criar", "Cancelar");
    return 1;
}
CMD:abrirevento(playerid)
{
    if(OpenEvent)
        return SendClientMessage(playerid, Erro, "Envento já está aberto");

    OpenEvent = true;
    GameTextForAll("~r~EVENTO~n~~w~PARA IR DIGITE: /IREVENTO", 5000, 3);
    return 1;
}
CMD:irevento(playerid)
{
    if(!OpenEvent)
        return SendClientMessage(playerid, Erro, "Não está acontecendo evento");

    if(InEvent[playerid])
        return SendClientMessage(playerid, Erro, "Você já está em um evento");

    for(new i = 0; i < 5; i++)
    {
        if(!RS_Event[i][rse_occupied])
        {
            RS_Event[i][rse_vehicleid] = AddStaticVehicleEx(522, RS_Event[i][rse_x], RS_Event[i][rse_y], RS_Event[i][rse_z], 90.0000, 0, 0, -1);

            SetPlayerInterior(playerid, 4);
            LinkVehicleToInterior(RS_Event[i][rse_vehicleid], 4);
            PutPlayerInVehicle(playerid, RS_Event[i][rse_vehicleid], 0);
            TogglePlayerControllable(playerid, false);

            InEvent[playerid] = true;

            //SetPlayerFacingAngle(playerid, 94.0312);
            //SetPlayerPos(playerid, -1403.6448,-587.4628,1059.2813);
            return 1;
        }
    }
    SendClientMessage(playerid, Erro, "Envento cheio");
    return 1;
}
CMD:sairevento(playerid)
{
    if(!InEvent[playerid])
        return SendClientMessage(playerid, Erro, "Você já está em um evento");

    for(new i = 0; i < 5; i++)
    {
        if(RS_Event[i][rse_occupied] && GetPlayerVehicleID(playerid) == RS_Event[i][rse_vehicleid])
        {
            RS_Event[i][rse_occupied] = false;
            DestroyVehicle(RS_Event[i][rse_vehicleid]);
        }
    }

    InEvent[playerid] = false;
    SetPlayerHealth(playerid, 0.0);
    SendClientMessage(playerid, White, "Você se retirou do evento");
    return 1;
}
CMD:iniciarevento(playerid)
{
    if(Respawnando)
        return SendClientMessage(playerid, Erro, "Aguarde acabar o respawn de veículos");

    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(InEvent[i])
        {
            GameTextForPlayer(i, ContadorTxT[Count-1], 2500, 3);
        }
    }

    TogglePlayerControllable(playerid, true);
    return 1;
}
