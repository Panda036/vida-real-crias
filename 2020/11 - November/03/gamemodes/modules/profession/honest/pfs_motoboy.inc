/***********************************************************
*
*   START: 25/09/2020
*
*   OBS: IFOOD, UBER, RAPPEZ ( Calulcar distancia... Aceitar encomenda e dps entregar ) Bag ID : 19572
*
*
*/

#include YSI\y_hooks

#define MAX_DELIVERY_MB     6
#define TIME_REQUEST_MB     30000
#define BAG_MODEL_MB        19572
#define RADIUS_MINIMUM_MB   1000.0

enum e_mb
{
    bool:mb_business,
    mb_cp,
    mb_requestsbefore,
    bool:mb_accept,
    bool:mb_radar,
    mb_radarTimer,
    mb_count,
    bool:mb_getOrSet,
    mb_total
};

new MotoBoy[MAX_PLAYERS][e_mb];

hook OnPlayerConnect(playerid)
{
    MotoBoy[playerid][mb_requestsbefore] = -1;
    MotoBoy[playerid][mb_radar] = false;
    return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(PlayerInfo[playerid][Profissao] == motoboy)
    {
        if(!MotoBoy[playerid][mb_radar]) return 0;

        if(newstate != PLAYER_STATE_DRIVER) return 0;

        new vehicleid = GetPlayerVehicleID(playerid);

        if(!IsPlayerInVehicleA(vehicleid)) return 0;

        if(IsPlayerAttachedObjectSlotUsed(playerid, ATTACH_INDEX_PROFISSION)) return 0;

        SetPlayerAttachedObject(playerid, ATTACH_INDEX_PROFISSION, BAG_MODEL_MB, 1, -0.260, -0.301, -0.016, 0.200, 88.700, -0.000, 1.500, 1.500, 1.500);
        return 1;
    }
	return 1;
}

hook OnPlayerExitVehicle(playerid, vehicleid)
{
    if(PlayerInfo[playerid][Profissao] == motoboy)
    {
        if(!IsPlayerInVehicleA(vehicleid)) return 0;

        if(!IsPlayerAttachedObjectSlotUsed(playerid, ATTACH_INDEX_PROFISSION)) return 0;

        RemovePlayerAttachedObject(playerid, ATTACH_INDEX_PROFISSION);
        return 1;
    }
	return 1;
}

forward GetOrSetRequestMB(playerid);
public GetOrSetRequestMB(playerid)
{
    if(MotoBoy[playerid][mb_count] >= 5)
    {
        TogglePlayerControllable(playerid, true);
        MotoBoy[playerid][mb_count] = 0;
        MotoBoy[playerid][mb_getOrSet] = false;
        PlayerPlaySound(playerid, 1054, 0, 0, 0);

        if(MotoBoy[playerid][mb_business])
        {
            new houseID = nearestHouse(playerid);

            MotoBoy[playerid][mb_business] = false;
            MotoBoy[playerid][mb_cp] = CreateDynamicRaceCP(1, HouseInfo[houseID][iconx], HouseInfo[houseID][icony], HouseInfo[houseID][iconz], -1, -1, -1, 2.0, -1, -1, playerid, -1.0, -1, 0);

            SendClientMessage(playerid, White, "Você pegou o pedido, agora vá até o cliente e entregue-o");
        }
        else
        {
            new value = RandomValueMotoboy();

            GiveBonus(playerid, 500);
            PlayerInfo[playerid][SaldoBancario] += value;
            SetIntQuery(playerid, "Identidade", "SaldoBancario", PlayerInfo[playerid][SaldoBancario]);

            MotoBoy[playerid][mb_accept] = false;

            format(String, MAX_STRING, "Pedido finalizado, você recebeu {1B6302}$%s {FFFFFF}pelo seu servíço", IsMoney(value, "."));
            SendClientMessage(playerid, White, String);
            SendClientMessage(playerid, White, "Aguarde alguns segundos para receber outra {FF8000}notificação{FFFFFF} de pedido");
        }
        return 1;
    }

    MotoBoy[playerid][mb_count]++;
    GameTextForPlayer(playerid, ( MotoBoy[playerid][mb_business] ? ("Pegando pedido...") : ("Entregando pedido...")), 1000, 1);
    ApplyAnimation(playerid, "DEALER", "DEALER_DEAL", 4.0, 1, 0, 0, 1000, 0);
    SetTimerEx("GetOrSetRequestMB", 1000, false, "d", playerid);
    return 1;
}

forward OnPlayerRequestsMotoboy(playerid);
public OnPlayerRequestsMotoboy(playerid)
{
    if(PlayerInfo[playerid][Profissao] != motoboy) return 0;

    if(!MotoBoy[playerid][mb_radar]) return 0;

    if(MotoBoy[playerid][mb_accept]) return 0;

    MotoBoy[playerid][mb_requestsbefore] = nearestBusiness(playerid);

    format(String, MAX_STRING, "{FF4000}%s {FFFFFF}está te oferecendo serviço, {1B6302}aceite-o{FFFFFF} e vá até a empresa", businessName());
    SendClientMessage(playerid, White, String);
    PlayerPlaySound(playerid, 1053, 0, 0, 0);
    return 1;
}

stock Motoboy_DynamicRaceCP(playerid)
{
    if(PlayerInfo[playerid][Profissao] == motoboy)
    {
        if(!MotoBoy[playerid][mb_accept]) return 0;

        if(IsPlayerInAnyVehicle(playerid))
            return SendClientMessage(playerid, Erro, "Você está em um veículo");

        new vehicleid = LastVehicle[playerid];

        if(!IsPlayerInVehicleA(vehicleid))
            return SendClientMessage(playerid, Erro, "Seu último veículo não é uma moto");

        MotoBoy[playerid][mb_getOrSet] = true;
        DestroyDynamicRaceCP(MotoBoy[playerid][mb_cp]);
        TogglePlayerControllable(playerid, false);
        GetOrSetRequestMB(playerid);
        return 1;
    }
    return 1;
}

stock businessName()
{
    new var[3][10] =
    {
        {"Uber Eats"},
        {"Rappi"},
        {"iFood"}
    };
    return var[random(3)];
}

stock nearestHouse(playerid)
{
    new Float:beforeDistance = 50000.0, id;

    for(new houseID = 0; houseID < MAX_HOUSES; houseID++)
    {
        new Float:distance = GetPlayerDistanceFromPoint(playerid, HouseInfo[houseID][iconx], HouseInfo[houseID][icony], HouseInfo[houseID][iconz]);

        if(distance > RADIUS_MINIMUM_MB && distance < beforeDistance)
        {
            beforeDistance = distance;
            id = houseID;
        }
    }
    return id;
}

stock nearestBusiness(playerid)
{
    new Float:beforeDistance = 50000.0, id;

    for(new businessid = 0; businessid < MAX_BUSINESS; businessid++)
    {
        new Float:distance = GetPlayerDistanceFromPoint(playerid, BusinessInfo[businessid][cIconX], BusinessInfo[businessid][cIconY], BusinessInfo[businessid][cIconZ]);

        if(businessid == MotoBoy[playerid][mb_requestsbefore]) continue;

        if(distance < beforeDistance)
        {
            beforeDistance = distance;
            id = businessid;
        }
    }
    return id;
}

stock RandomValueMotoboy()
{
    new rand = random(1000);

    return (rand < 300 ? ( RandomValueMotoboy() ) : ( rand ));
}

stock LeftPfsMotoboy(playerid)
{
    if(PlayerInfo[playerid][Profissao] == motoboy)
    {
        if(IsValidDynamicRaceCP(MotoBoy[playerid][mb_cp])){
            DestroyDynamicRaceCP(MotoBoy[playerid][mb_cp]);
        }
        if(MotoBoy[playerid][mb_radar]){
            MotoBoy[playerid][mb_radar] = false;
            KillTimer(MotoBoy[playerid][mb_radarTimer]);
        }

        MotoBoy[playerid][mb_business] = false;
        MotoBoy[playerid][mb_accept] = false;
        MotoBoy[playerid][mb_radar] = false;
        MotoBoy[playerid][mb_getOrSet] = false;
        MotoBoy[playerid][mb_cp] = 0;
        MotoBoy[playerid][mb_requestsbefore] = 0;
        MotoBoy[playerid][mb_radarTimer] = 0;
        MotoBoy[playerid][mb_count] = 0;
    }
    return 1;
}

/******************************************************************************/
/*****************************| COMMANDS MOTOBOY |*****************************/
/******************************************************************************/

CMD:radar(playerid)
{
    if(PlayerInfo[playerid][Profissao] != motoboy)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(MotoBoy[playerid][mb_radar])
    {
        MotoBoy[playerid][mb_radar] = false;
        SendClientMessage(playerid, White, "Radar de pedidos desativado");
        KillTimer(MotoBoy[playerid][mb_radarTimer]);
    }
    else
    {
        MotoBoy[playerid][mb_radar] = true;
        SendClientMessage(playerid, White, "Radar de pedidos ativado");
        MotoBoy[playerid][mb_radarTimer] = SetTimerEx("OnPlayerRequestsMotoboy", TIME_REQUEST_MB, true, "d", playerid);
    }

    //format(String, MAX_STRING, "");
    //SendClientMessage(playerid, White, String);

    PlayerPlaySound(playerid, 1055, 0, 0, 0);
    return 1;
}
CMD:aceitarpedido(playerid)
{
    if(PlayerInfo[playerid][Profissao] != motoboy)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    new vehicleid = GetPlayerVehicleID(playerid);

    if(!IsPlayerInAnyVehicle(playerid) || !IsPlayerInVehicleA(vehicleid))
        return SendClientMessage(playerid, Erro, "Você não está em uma moto");

    if(MotoBoy[playerid][mb_requestsbefore] == -1)
        return SendClientMessage(playerid, Erro, "Você não recebeu pedido");

    if(MotoBoy[playerid][mb_accept])
        return SendClientMessage(playerid, Erro, "Você já aceitou um pedido, termine-o");

    new businessid = MotoBoy[playerid][mb_requestsbefore];

    MotoBoy[playerid][mb_business] = true;
    MotoBoy[playerid][mb_accept] = true;
    MotoBoy[playerid][mb_cp] = CreateDynamicRaceCP(1, BusinessInfo[businessid][cIconX], BusinessInfo[businessid][cIconY], BusinessInfo[businessid][cIconZ], -1, -1, -1, 2.0, -1, -1, playerid, -1.0, -1, 0);
    PlayerPlaySound(playerid, 1055, 0, 0, 0);

    SendClientMessage(playerid, White, "Pedido {1B6302}aceito{FFFFFF}, agora vá até à empresa localiza em seu mini-mapa");
    return 1;
}
