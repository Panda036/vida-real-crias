#include YSI\y_hooks

new bool:statejetpack[MAX_PLAYERS];

hook OnPlayerDisconnect(playerid, reason)
{
    statejetpack[playerid] = false;
	return 1;
}

hook OnPlayerUpdate(playerid)
{
    if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USEJETPACK && !statejetpack[playerid])
    {
        statejetpack[playerid] = true;
        t_jetpack[playerid] = SetTimerEx("OnPlayerInJetpack", 1000, false, "d", playerid);
        return 1;
    }
	return 1;
}

forward OnPlayerInJetpack(playerid);
public OnPlayerInJetpack(playerid)
{
    if(!PlayerInfo[playerid][Logado] && statejetpack[playerid]) return 0;

    t_jetpack[playerid] = SetTimerEx("OnPlayerInJetpack", 1000, false, "d", playerid);

    static warninggas[MAX_PLAYERS];

    if(GetPlayerSpecialAction(playerid) != SPECIAL_ACTION_USEJETPACK)
    {
        statejetpack[playerid] = false;
        PlayerTextDrawHide(playerid, TDJetpack[playerid][0]);
        ClearAnimations(playerid);
        KillTimer(t_jetpack[playerid]);
        return 1;
    }
    else if(PlayerInfo[playerid][Estrelas])
    {
        statejetpack[playerid] = false;
        PlayerTextDrawHide(playerid, TDJetpack[playerid][0]);
        ClearAnimations(playerid);
        KillTimer(t_jetpack[playerid]);

        SendClientMessage(playerid, Erro, "Você está procurado(a) e não pode usar Jetpack");
        return 1;
    }
    else if(IsArena[playerid])
    {
        statejetpack[playerid] = false;
        PlayerTextDrawHide(playerid, TDJetpack[playerid][0]);
        ClearAnimations(playerid);
        KillTimer(t_jetpack[playerid]);

        SendClientMessage(playerid, Erro, "Você entrou na arena e seu Jetpack foi destruido");
        return 1;
    }
    else if(GetPlayerInterior(playerid))
    {
        statejetpack[playerid] = false;
        PlayerTextDrawHide(playerid, TDJetpack[playerid][0]);
        ClearAnimations(playerid);
        KillTimer(t_jetpack[playerid]);

        SendClientMessage(playerid, Erro, "Você entrou em um interior e seu Jetpack foi destruido");
        return 1;
    }
    else if(IsPlayerInAnyVehicle(playerid))
    {
        statejetpack[playerid] = false;
        PlayerTextDrawHide(playerid, TDJetpack[playerid][0]);
        ClearAnimations(playerid);
        KillTimer(t_jetpack[playerid]);

        SendClientMessage(playerid, Erro, "Você entrou em um veículo e seu Jetpack foi destruido");
        return 1;
    }
    else if(!IsPlayerVip(playerid) && !IsPlayerIntern(playerid))
    {
        statejetpack[playerid] = false;
        PlayerTextDrawHide(playerid, TDJetpack[playerid][0]);
        ClearAnimations(playerid);
        KillTimer(t_jetpack[playerid]);

        SendClientMessage(playerid, Erro, "Seu vip expirou e seu Jetpack foi destruido");
        return 1;
    }
    else if(PlayerInfo[playerid][jetpackgas] <= 0)
    {
        statejetpack[playerid] = false;
        PlayerTextDrawHide(playerid, TDJetpack[playerid][0]);
        ClearAnimations(playerid);
        KillTimer(t_jetpack[playerid]);

        SendClientMessage(playerid, Erro, "Gás acabou e seu Jetpack foi destruido");
        return 1;
    }

    if(warninggas[playerid] >= 30)
    {
        warninggas[playerid] = 0;
        PlayerInfo[playerid][jetpackgas]--;

        new query[100];
        mysql_format(IDConexao, query, 100, "UPDATE `Itens` SET `jetpackgas`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][jetpackgas], PlayerInfo[playerid][ID]);
        mysql_query(IDConexao, query);
    }
    warninggas[playerid]++;

    format(String, 128, "GAS:_%s~w~M3", StateJetpack(PlayerInfo[playerid][jetpackgas]));
    PlayerTextDrawSetString(playerid, TDJetpack[playerid][0], String);
    PlayerTextDrawShow(playerid, TDJetpack[playerid][0]);
    return 1;
}

stock StateJetpack(value)
{
    switch(value)
    {
        case 0..5: format(String, 20, "~r~%d", value);
        case 6..10: format(String, 20, "~r~~h~~h~~h~%d", value);
        case 11..30: format(String, 20, "~g~%d", value);
    }
    return String;
}

/******************************************************************************/
/*****************************| COMMANDS JETPACK |*****************************/
/******************************************************************************/

CMD:jetpack(playerid)
{
    if(!IsPlayerVip(playerid) && !IsPlayerIntern(playerid) && !IsPlayerYoutuber(playerid))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(IsPlayerInAnyVehicle(playerid))
        return SendClientMessage(playerid, Erro, "Você precisa sair do veiculo");

    if(GetPlayerInterior(playerid))
        return SendClientMessage(playerid, Erro, "Não é possível criar jetpack dentro de interior");

    if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USEJETPACK)
        return SendClientMessage(playerid, Erro, "Você já está usando Jetpack");

    if(PlayerInfo[playerid][Estrelas])
        return SendClientMessage(playerid, Erro, "Você está procurado(a) e não pode usar Jetpack");

    if(IsPlayerVip(playerid))
        SendClientMessage(playerid, 0x00E100AA, "Jetpack criado");

    if(IsPlayerIntern(playerid))
        SendClientMessage(playerid, adm, "| VRC-Admin | Jetpack criado");

    statejetpack[playerid] = true;
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_USEJETPACK);
    t_jetpack[playerid] = SetTimerEx("OnPlayerInJetpack", 1000, false, "d", playerid);
    return 1;
}
