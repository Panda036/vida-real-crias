#include YSI\y_hooks

new icecream_vehicles[6];
new CounterIceCream[MAX_PLAYERS];
new bool:IceCreamOffer[MAX_PLAYERS];
new bool:IceCreamAccepted[MAX_PLAYERS];
new bool:IceCreamRefused[MAX_PLAYERS];

hook OnGameModeInit()
{
    icecream_vehicles[0] = AddStaticVehicle(423, 2476.1001000, 1658.7000000, 11.0000000, 182.0000000, 245, 245); //Mr Whoopee
    icecream_vehicles[1] = AddStaticVehicle(423, 2473.0000000, 1659.0000000, 11.0000000, 180.0000000, 245, 245); //Mr Whoopee
    icecream_vehicles[2] = AddStaticVehicle(423, 2479.2000000, 1658.5000000, 11.0000000, 182.0000000, 245, 245); //Mr Whoopee
    icecream_vehicles[3] = AddStaticVehicle(423, 2482.7000000, 1658.7000000, 11.0000000, 182.0000000, 245, 245); //Mr Whoopee
    icecream_vehicles[4] = AddStaticVehicle(423, 2485.8000000, 1658.6000000, 11.0000000, 182.0000000, 245, 245); //Mr Whoopee
    icecream_vehicles[5] = AddStaticVehicle(423, 2489.5000000, 1658.7000000, 11.0000000, 182.0000000, 245, 245); //Mr Whoopee

    for(new i = 0; i < sizeof(icecream_vehicles); i++){
        SetVehicleParamsEx(icecream_vehicles[i], 0, 0, 0, 0, 0, 0, 0);
    }

    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    IceCreamOffer[playerid] = false;
    IceCreamAccepted[playerid] = false;
    IceCreamRefused[playerid] = false;
    CounterIceCream[playerid] = 0;
    return 1;
}

hook OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    for(new i; i < sizeof(icecream_vehicles); i++)
    {
        if(vehicleid == icecream_vehicles[i])
        {
            if(!ispassenger && vehicleid != INVALID_VEHICLE_ID && PlayerInfo[playerid][Profissao] != icecream)
            {
                ClearAnimations(playerid);
                SendClientMessage(playerid, Erro, "Veiculo exclusivo da profissão Sorveteiro");
                return 1;
            }
        }
    }
    return 1;
}

forward OnPlayerIceCreamOffer(playerid, playeridoffer, value);
public OnPlayerIceCreamOffer(playerid, playeridoffer, value)
{
    if(IceCreamOffer[playeridoffer])
    {
        if(CounterIceCream[playeridoffer] == 10)
        {
            IceCreamOffer[playeridoffer] = false;
            CounterIceCream[playeridoffer] = 0;
            SendClientMessage(playeridoffer, 0x00B57DAA, "Seu tempo de aceitar ou recusar acabou");
            return 1;
        }

        CounterIceCream[playeridoffer]++;
        SetTimerEx("OnPlayerIceCreamOffer", 1000, false, "ddd", playerid, playeridoffer, value);

        if(CounterIceCream[playeridoffer] == 1 || CounterIceCream[playeridoffer] == 3 || CounterIceCream[playeridoffer] == 5 || CounterIceCream[playeridoffer] == 7 || CounterIceCream[playeridoffer] == 9)
        {
            SendClientMessage(playeridoffer, 0x00B57DAA, "Para aceitar ou recusar digite ( /aceitar ou /recusar )");
        }
    }
    else
    {
        if(IceCreamAccepted[playeridoffer])
        {
            if(PlayerInfo[playeridoffer][Dinheiro] < value)
                return SendClientMessage(playeridoffer, Erro, "Você não tem dinheiro o suficiente");

            Progress[playeridoffer][Fome] -= 10.0;
            Progress[playeridoffer][Sede] -= 20.0;

            if(Progress[playeridoffer][Fome] < 0.0) Progress[playeridoffer][Fome] = 0.0;
            if(Progress[playeridoffer][Sede] < 0.0) Progress[playeridoffer][Sede] = 0.0;
            UpdateProgressBar(playerid);

            PlayerInfo[playerid][Dinheiro] += value;
            UpdatePlayerMoney(playerid);
            PlayerInfo[playeridoffer][Dinheiro] -= value;
            UpdatePlayerMoney(playeridoffer);

            PlayerInfo[playeridoffer][Health] += 20.0;
            UpdatePlayerHealth(playeridoffer);

            SendClientMessage(playeridoffer, 0xFFD993AA, "Você aceitou a oferta");
            format(String, MAX_STRING, "Você vendeu o sorvete para o(a) jogador(a) %s[%d] e você ganhou $%s", PlayerInfo[playeridoffer][Nome], playeridoffer, IsMoney(value, "."));
            SendClientMessage(playerid, 0xFFD993AA, String);
        }
        else
        {
            format(String, MAX_STRING, "O(A) Jogador(a) %s[%d] recusou a oferta", PlayerInfo[playeridoffer][Nome], playeridoffer);
            SendClientMessage(playerid, 0xFF0000AA, String);
            SendClientMessage(playeridoffer, 0xFF0000AA, "Você recusou a oferta");
            IceCreamRefused[playeridoffer] = false;
        }
    }
    return 1;
}

/******************************************************************************/
/****************************| COMMANDS ICE CREAM |****************************/
/******************************************************************************/

CMD:vendersorvete(playerid, params[])
{
	if(PlayerInfo[playerid][Profissao] != icecream)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    new id, value;

    if(sscanf(params, "dd", id, value))
        return SendClientMessage(playerid, Erro, "Digite: /VenderSorvete [id] [valor]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    if(GetDistanceBetweenPlayers(playerid, id) > 15)
        return SendClientMessage(playerid, Erro, "Você está muito longe, chegue mais perto");

    if(IceCreamOffer[id])
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) já recebeu uma oferta");

    if(value < 100 || value > 1000)
        return SendClientMessage(playerid, Erro, "Só é permítido valores entre 100 e 1000");

    for(new i; i < sizeof(icecream_vehicles); i++)
    {
        if(GetPlayerVehicleID(playerid) == icecream_vehicles[i])
        {
            IceCreamOffer[id] = true;
            OnPlayerIceCreamOffer(playerid, id, value);

            format(String, sizeof(String), "Você ofereceu ao jogador(a) %s[%d] um sorvete no valor de $%s", PlayerInfo[id][Nome], id, IsMoney(value, "."));
            SendClientMessage(playerid, color_icecream, String);
            format(String, sizeof(String), "O(A) Sorveteiro(a) %s[%d] está te oferecendo um sorvete no valor de $%s", PlayerInfo[playerid][Nome], playerid, IsMoney(value, "."));
            SendClientMessage(id, color_icecream, String);
            return 1;
        }
    }
    SendClientMessage(playerid, Erro, "Você não está no caminhão de serviço");
	return 1;
}
