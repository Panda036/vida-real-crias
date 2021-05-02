#include YSI\y_hooks

enum e_rstaxi
{
    Float:rstaxi_x,
    Float:rstaxi_y,
    Float:rstaxi_z
};

new RandomSpawnTaxi[5][e_rstaxi] =
{
    {2230.00, -1340.00, 23.58},
    {2230.00, -1344.00, 23.58},
    {2230.00, -1348.00, 23.58},
    {2230.00, -1352.00, 23.58},
    {2230.00, -1356.00, 23.58}
};

new TaximeterValue[MAX_PLAYERS];
new BlockTaxi[MAX_PLAYERS];
new t_unlocktaxi[MAX_PLAYERS];
new bool:RequestTaxi[MAX_PLAYERS];

hook OnGameModeInit()
{
    CreateVehicleLocation(2230.03, -1363.38, 23.99);
	return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(BlockTaxi[playerid]){
        BlockTaxi[playerid] = false;
        KillTimer(t_unlocktaxi[playerid]);
    }

    RequestTaxi[playerid] = false;
    TaximeterValue[playerid] = 0;
	return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(PRESSED(KEY_YES) && IsPlayerInRangeOfPoint(playerid, 2.0, 2230.03, -1363.38, 23.99))
	{
        if(PlayerInfo[playerid][Profissao] != taxi)
            return SendClientMessage(playerid, Erro, "Você não tem permissão");

        if(PV_Profission[playerid])
            return SendClientMessage(playerid, Erro, "Você já criou um veículo profissão");

        new rand = random(sizeof(RandomSpawnTaxi));

        CreatePlayerVehicle(playerid, 420, RandomSpawnTaxi[rand][rstaxi_x], RandomSpawnTaxi[rand][rstaxi_y], RandomSpawnTaxi[rand][rstaxi_z], 90.0000, -1, -1);

        SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Foi criado um veículo profissão no estacionamento");
        return 1;
	}
	return 1;
}

forward taximeter(playerid, passengerid);
public taximeter(playerid, passengerid)
{
    if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT || GetPlayerState(passengerid) == PLAYER_STATE_ONFOOT || !PlayerInfo[passengerid][Logado] || !PlayerInfo[playerid][Logado])
    {
        TextDrawHideForPlayer(passengerid, TDTaximetro[0]);
        TextDrawHideForPlayer(passengerid, TDTaximetro[1]);
        TextDrawHideForPlayer(passengerid, TDTaximetro[2]);
        TextDrawHideForPlayer(passengerid, TDTaximetro[3]);
        PlayerTextDrawHide(passengerid, TDPlayerTaximetro[passengerid][0]);
        PlayerTextDrawHide(passengerid, TDPlayerTaximetro[passengerid][1]);
        TextDrawHideForPlayer(playerid, TDTaximetro[0]);
        TextDrawHideForPlayer(playerid, TDTaximetro[1]);
        TextDrawHideForPlayer(playerid, TDTaximetro[2]);
        TextDrawHideForPlayer(playerid, TDTaximetro[3]);
        PlayerTextDrawHide(playerid, TDPlayerTaximetro[playerid][0]);
        PlayerTextDrawHide(playerid, TDPlayerTaximetro[playerid][1]);

        PlayerInfo[playerid][Dinheiro] += TaximeterValue[passengerid];
        UpdatePlayerMoney(playerid);
        PlayerInfo[passengerid][Dinheiro] -= TaximeterValue[passengerid];
        UpdatePlayerMoney(passengerid);

        format(String, 50, "Valor total $%d", TaximeterValue[passengerid]);
        SendClientMessage(playerid, Yellow, "A corrida foi paga automaticamente");
        SendClientMessage(playerid, Yellow, String);
        return 1;
    }

    new Float:x, Float:y, Float:z;

    GetPlayerPos(playerid, x, y, z);
    GetPlayer2DZone(zone, MAX_ZONE_NAME, x, y);

    TaximeterValue[passengerid] += 2;

    format(String, 50, "~g~$%d", TaximeterValue[passengerid]);
    PlayerTextDrawSetString(playerid, TDPlayerTaximetro[playerid][0], String);
    PlayerTextDrawSetString(passengerid, TDPlayerTaximetro[passengerid][0], String);
    format(String, 50, "~r~%s", zone);
    PlayerTextDrawSetString(passengerid, TDPlayerTaximetro[passengerid][1], String);
    PlayerTextDrawSetString(playerid, TDPlayerTaximetro[playerid][1], String);

    SetTimerEx("taximeter", 1000, false, "dd", playerid, passengerid);
    return 1;
}

forward UnlockTaxi(playerid);
public UnlockTaxi(playerid)
{
    BlockTaxi[playerid] = false;
    KillTimer(t_unlocktaxi[playerid]);
    return 1;
}

/******************************************************************************/
/******************************| COMMANDS TAXÍ |*******************************/
/******************************************************************************/

CMD:taxi(playerid)
{
    if(BlockTaxi[playerid])
        return SendClientMessage(playerid, Erro, "Você acabou de pedir taxí, aguarde alguns segundos...");

    new Float:x, Float:y, Float:z;

    GetPlayerPos(playerid, x, y, z);
    GetPlayer2DZone(zone, MAX_ZONE_NAME, x, y);

    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(PlayerInfo[i][Profissao] == taxi)
        {
            format(String, MAX_STRING, "O(A) Jogador(a) %s[%d] está requisitando um Táxi nas Localidades ( %s )", PlayerInfo[playerid][Nome], playerid, zone);
            SendClientMessage(i, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);
        }
    }

    RequestTaxi[playerid] = true;
    BlockTaxi[playerid] = true;
    t_unlocktaxi[playerid] = SetTimerEx("UnlockTaxi", 120000, false, "d", playerid);
    SendClientMessage(playerid, Green, "Os(As) taxístas foram informados");
    return 1;
}
CMD:taximetro(playerid, params[])
{
    new id, vehicleid = GetPlayerVehicleID(playerid);

    if(PlayerInfo[playerid][Profissao] != taxi)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(PlayerInfo[playerid][Profissao] == taxi && !IsPlayerInAnyVehicle(playerid))
        return SendClientMessage(playerid, Erro, "Seu último veículo não é um táxi");

    if((PlayerInfo[playerid][Profissao] == taxi && GetVehicleModel(LastVehicle[playerid]) != 420) && (PlayerInfo[playerid][Profissao] == taxi && GetVehicleModel(LastVehicle[playerid]) != 487))
        return SendClientMessage(playerid, Erro, "Seu último veículo não é um táxi");

    if(sscanf(params, "u", id))
        return SendClientMessage(playerid, Erro, "Digite: /taximetro [id/nome]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
        return SendClientMessage(playerid, Erro, "Você não está dirigindo");

    if(vehicleid != GetPlayerVehicleID(id))
        return SendClientMessage(playerid, Erro, "O passageiro não está no taxi");

    format(String, MAX_STRING, "O(A) Táxista %s[%d] inicou o táximetro", PlayerInfo[playerid][Nome], playerid);
    SendClientMessage(id, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);
    format(String, MAX_STRING, "Você iníciou o táximetro para o(a) jogador(a) %s[%d]", PlayerInfo[id][Nome], id);
    SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);

    TextDrawShowForPlayer(id, TDTaximetro[0]);
    TextDrawShowForPlayer(id, TDTaximetro[1]);
    TextDrawShowForPlayer(id, TDTaximetro[2]);
    TextDrawShowForPlayer(id, TDTaximetro[3]);
    PlayerTextDrawShow(id, TDPlayerTaximetro[id][0]);
    PlayerTextDrawShow(id, TDPlayerTaximetro[id][1]);
    TextDrawShowForPlayer(playerid, TDTaximetro[0]);
    TextDrawShowForPlayer(playerid, TDTaximetro[1]);
    TextDrawShowForPlayer(playerid, TDTaximetro[2]);
    TextDrawShowForPlayer(playerid, TDTaximetro[3]);
    PlayerTextDrawShow(playerid, TDPlayerTaximetro[playerid][0]);
    PlayerTextDrawShow(playerid, TDPlayerTaximetro[playerid][1]);

    RequestTaxi[id] = false;
    taximeter(playerid, id);
    return 1;
}
