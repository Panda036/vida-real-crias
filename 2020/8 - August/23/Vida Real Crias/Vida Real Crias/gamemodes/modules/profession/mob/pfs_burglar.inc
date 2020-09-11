#include YSI\y_hooks

new T_PlantingC4[MAX_PLAYERS];
new T_BlockBurglar[MAX_PLAYERS];

new obj_c4[MAX_PLAYERS];
new bool:planting_c4[MAX_PLAYERS];

hook OnPlayerConnect(playerid)
{
    T_BlockBurglar[playerid] = SetTimerEx("OnPlayerUnlockBurglar", 1000, true, "d", playerid);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    KillTimer(T_BlockBurglar[playerid]);

    if(planting_c4[playerid])
    {
        DestroyDynamicObject(obj_c4[playerid]);
        KillTimer(T_PlantingC4[playerid]);
        planting_c4[playerid] = false;
    }
	return 1;
}

forward OnPlayerPlantingC4(playerid, cashid, Float:x, Float:y, Float:z);
public OnPlayerPlantingC4(playerid, cashid, Float:x, Float:y, Float:z)
{
    planting_c4[playerid] = false;
    DestroyDynamicObject(obj_c4[playerid]);

    if(!IsPlayerInRangeOfPoint(playerid, 20.0, CashMachine[cashid][cm_x], CashMachine[cashid][cm_y], CashMachine[cashid][cm_z]))
    {
        SendClientMessage(playerid, Erro, "Sua dinamite acabou falhando");
        return 1;
    }

    new value[MAX_PLAYERS];

    value[playerid] = RandomValueMachine();

    PlayerInfo[playerid][Dinheiro] += value[playerid];
    UpdatePlayerMoney(playerid);

    CreateExplosion(x, y, z, 12, 3.0);

    PlayerInfo[playerid][t_burglarbox] = gettime();

    new query[100];
    mysql_format(IDConexao, query, 100, "UPDATE `Timers` SET `burglarbox`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][t_burglarbox], PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);

    format(String, sizeof(String), "Caixa Eletrônico explodido e você ganhou $%s", IsMoney(value[playerid], "."));
    SendClientMessage(playerid, color_burglar, String);

    GetPlayer2DZone(zone, MAX_ZONE_NAME, x, y);

    format(String, sizeof(String), "O(A) Jogador(a) %s[%d] assaltou um caixa eletrônico na localidade ( %s )", PlayerInfo[playerid][Nome], playerid, zone);

    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerPolice(i))
        {
            SendClientMessage(i, 0x2894FFAA, String);
        }
    }
    return 1;
}

stock RandomValueMachine()
{
    new value = random(2000);

    if(value < 500)
        return RandomValueMachine();

    return value;
}

stock RandomValueBurglar()
{
    new value = random(1000);

    if(value < 200)
        return RandomValueBurglar();

    return value;
}

/******************************************************************************/
/*****************************| COMMANDS BURGLAR |*****************************/
/******************************************************************************/

CMD:assaltar(playerid, params[])
{
    if(PlayerInfo[playerid][Profissao] != burglar && PlayerInfo[playerid][Profissao] != thief)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if((gettime() - PlayerInfo[playerid][t_burglar]) < 120)
    {
        new days, hours, minutes, seconds;

        TimeConvertEx(120 - (gettime() - PlayerInfo[playerid][t_burglar]), days, hours, minutes, seconds);

        if(minutes)
            format(String, 128, "Você acabou de assaltar, aguarde %d minuto e %d segundos...", minutes, seconds);
        else
            format(String, 128, "Você acabou de assaltar, aguarde %d segundos...", seconds);

        SendClientMessage(playerid, Erro, String);
        return 1;
    }

    new id, Float:x, Float:y, Float:z;

    if(sscanf(params, "d", id))
        return SendClientMessage(playerid, Erro, "/Assaltar [id]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    GetPlayerPos(id, x, y, z);

    if(!IsPlayerInRangeOfPoint(playerid, 3.0, x, y, z))
        return SendClientMessage(playerid, Erro, "Você não está perto da vítima, chegue mais perto");

    PlayerInfo[playerid][t_burglar] = gettime();

    new query[100];
    mysql_format(IDConexao, query, 100, "UPDATE `Timers` SET `burglar`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][t_burglar], PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);

    new value[MAX_PLAYERS];

    value[playerid] = RandomValueBurglar();

    PlayerInfo[playerid][Dinheiro] += value[playerid];
    UpdatePlayerMoney(playerid);
    PlayerInfo[id][Dinheiro] -= value[playerid];
    UpdatePlayerMoney(id);

    PlayerInfo[playerid][Estrelas] += 1;
    UpdatePlayerStar(playerid);

    format(String, sizeof(String), "Você assaltou o jogador(a) %s[%d] e ganhou $%s", PlayerInfo[id][Nome], id, IsMoney(value[playerid], "."));
    SendClientMessage(playerid, color_burglar, String);
    format(String, sizeof(String), "O(A) Jogador(a) %s[%d] assaltou $%s de você", PlayerInfo[playerid][Nome], playerid, IsMoney(value[playerid], "."));
    SendClientMessage(id, color_burglar, String);

    GetPlayer2DZone(zone, MAX_ZONE_NAME, x, y);

    format(String, sizeof(String), "O(A) Jogador(a) %s[%d] assaltou o jogador(a) %s[%d] na localidade ( %s )", PlayerInfo[playerid][Nome], playerid, PlayerInfo[id][Nome], id, zone);

    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerPolice(i))
        {
            SendClientMessage(i, 0x2894FFAA, String);
        }
    }
    return 1;
}
CMD:assaltarcaixa(playerid)
{
    if(PlayerInfo[playerid][Profissao] != burglar && PlayerInfo[playerid][Profissao] != thief)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(planting_c4[playerid])
        return SendClientMessage(playerid, Erro, "Você já está assaltando um caixa");

    for(new cashid = 0; cashid < MAX_CASHMACHINE; cashid++)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, CashMachine[cashid][cm_x], CashMachine[cashid][cm_y], CashMachine[cashid][cm_z]))
        {
            if((gettime() - PlayerInfo[playerid][t_burglarbox]) < 120)
            {
                new days, hours, minutes, seconds;

                TimeConvertEx(120 - (gettime() - PlayerInfo[playerid][t_burglarbox]), days, hours, minutes, seconds);

                if(minutes)
                    format(String, 128, "Você acabou de assaltar, aguarde %d minuto e %d segundos...", minutes, seconds);
                else
                    format(String, 128, "Você acabou de assaltar, aguarde %d segundos...", seconds);

                SendClientMessage(playerid, Erro, String);
                return 1;
            }

            if(!PlayerInfo[playerid][c4])
                return SendClientMessage(playerid, Erro, "Você não tem dinamites, vá até alguma Ammunation");

            new Float:x, Float:y, Float:z;

            GetPlayerPos(playerid, x, y, z);

            obj_c4[playerid] = CreateDynamicObject(1654, x, y, z-0.7, 0.0, 0.0, 0.0);

            planting_c4[playerid] = true;
            PlayerInfo[playerid][c4]--;

            PlayerInfo[playerid][Estrelas] += 1;
            UpdatePlayerStar(playerid);

            new query[100];
            mysql_format(IDConexao, query, sizeof(query), "UPDATE `Itens` SET `c4`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][c4], PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, query);

            T_PlantingC4[playerid] = SetTimerEx("OnPlayerPlantingC4", 5000, false, "ddfff", playerid, cashid, x, y, z);

            SendClientMessage(playerid, color_burglar, "C4 plantada, se afaste e espere explodir");
            return 1;
        }
    }
    return SendClientMessage(playerid, Erro, "Você não está perto de um caixa eletrônico");
}
CMD:assaltarcarroforte(playerid, params[])
{
    if(PlayerInfo[playerid][Profissao] != burglar && PlayerInfo[playerid][Profissao] != thief)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    new id;

    if(sscanf(params, "d", id))
        return SendClientMessage(playerid, Erro, "Digite: /AssaltarCarroForte [id]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    if(PlayerInfo[id][Profissao] != strongcardriver)
        return SendClientMessage(playerid, Erro, "Esse Jogador(a) não é Motorista de Carro Forte");

    new vehicleid = GetPlayerVehicleID(id), Float:x, Float:y, Float:z;

    GetVehiclePos(vehicleid, x, y, z);

    if(!IsPlayerInRangeOfPoint(playerid, 7.5, x, y, z))
        return SendClientMessage(playerid, Erro, "Esse Carro Forte está longe, chegue mais perto");

    if(!PublicVehicle[vehicleid][pv_loaded])
        return SendClientMessage(playerid, Erro, "Esse Carro Forte não está carregado");

    if(PublicVehicle[vehicleid][pv_security] != INVALID_PLAYER_ID)
        return SendClientMessage(playerid, Erro, "O Carro Forte tem segurança");

    new value = RandomValueBurglar();

    PlayerInfo[playerid][Dinheiro] += value;
    UpdatePlayerMoney(playerid);

    PlayerInfo[playerid][Estrelas] += 1;
    UpdatePlayerStar(playerid);

    PublicVehicle[vehicleid][pv_loaded] = false;

    GameTextForPlayer(playerid, "~g~ASSALTO!", 1000, 1);
    PlayerPlaySound(playerid, 1054, 0, 0, 0);
    GameTextForPlayer(id, "~r~ASSALTO!", 1000, 1);
    PlayerPlaySound(id, 1055, 0, 0, 0);

    format(String, 128, "Você assaltou o Carro Forte do(a) jogador(a) %s[%d] e recebeu $%s", PlayerInfo[id][Nome], id, IsMoney(value, "."));
    SendClientMessage(playerid, color_burglar, String);
    format(String, 128, "O(A) %s %s[%d] assaltou seu Carro Forte", NameProfission(PlayerInfo[playerid][Profissao]), PlayerInfo[playerid][Nome], playerid);
    SendClientMessage(id, color_burglar, String);
    return 1;
}
