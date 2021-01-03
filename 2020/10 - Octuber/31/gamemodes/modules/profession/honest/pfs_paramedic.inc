#include YSI\y_hooks

new bool:ParamedicOffer[MAX_PLAYERS];
new bool:ParamedicRefused[MAX_PLAYERS];
new bool:ParamedicAccepted[MAX_PLAYERS];
new ParamedicCount[MAX_PLAYERS];

new paramedic_vehicle[15];

hook OnGameModeInit()
{
    paramedic_vehicle[0] = AddStaticVehicleEx(416,1179.5149,-1308.7095,13.9063,269.1594,-1,-1, 300);
    paramedic_vehicle[1] = AddStaticVehicleEx(416,1179.8286,-1338.8124,13.9468,270.4886,-1,-1, 300);
    paramedic_vehicle[2] = AddStaticVehicleEx(416,2001.5714,-1424.9049,16.4980,178.5554,-1,-1, 300);
    paramedic_vehicle[3] = AddStaticVehicleEx(416,2023.7933,-1446.3790,16.5302,90.4014,-1,-1, 300);
    paramedic_vehicle[4] = AddStaticVehicleEx(416,1221.7292,302.3253,19.7042,67.1851,-1,-1, 300);
    paramedic_vehicle[5] = AddStaticVehicleEx(416,-331.4927,1062.8427,19.8908,268.5377,-1,-1, 300);
    paramedic_vehicle[6] = AddStaticVehicleEx(416,1584.9120,1803.8765,10.9747,0.5026,-1,-1, 300);
    paramedic_vehicle[7] = AddStaticVehicleEx(416,1624.2662,1819.2810,10.9696,1.4280,-1,-1, 300);
    paramedic_vehicle[8] = AddStaticVehicleEx(416,1620.2365,1849.3208,10.8621,180.4984,-1,-1, 300);
    paramedic_vehicle[9] = AddStaticVehicleEx(416,1614.0154,1849.2772,10.9694,179.6454,-1,-1, 300);
    paramedic_vehicle[10] = AddStaticVehicleEx(416,1607.3267,1849.4493,10.9694,178.2186,-1,-1, 300);
    paramedic_vehicle[11] = AddStaticVehicleEx(416,1601.0958,1849.5103,10.9702,179.2516,-1,-1, 300);
    paramedic_vehicle[12] = AddStaticVehicleEx(416,1594.6311,1849.2970,10.9701,180.1864,-1,-1, 300);
    paramedic_vehicle[13] = AddStaticVehicleEx(416,-1525.3906,2526.2146,55.8943,358.9956,-1,-1, 300);
    paramedic_vehicle[14] = AddStaticVehicleEx(416,-1500.6295,2526.2712,55.8366,0.0829,-1,-1, 300);

    for(new i = 0; i < sizeof(paramedic_vehicle); i++){
        SetVehicleParamsEx(paramedic_vehicle[i], 0, 0, 0, 0, 0, 0, 0);
    }


    CreateDynamic3DTextLabel("{808080}Uniforme\n{FFFFFF}Precione \"N\"", 0xFFFFFFFF, 1027.10, 997.50, 15.11, 30.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
    CreateDynamicPickup(1275, 1, 1027.10, 997.50, 15.11);
	return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    ParamedicOffer[playerid] = false;
    ParamedicRefused[playerid] = false;
    ParamedicAccepted[playerid] = false;
    ParamedicCount[playerid] = 0;
    return 1;
}

hook OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    for(new i; i < sizeof(paramedic_vehicle); i++)
    {
        if(vehicleid == paramedic_vehicle[i])
        {
            if(!ispassenger && vehicleid != INVALID_VEHICLE_ID)
            {
                if(PlayerInfo[playerid][Profissao] != paramedic)
                {
                    ClearAnimations(playerid);
                    return SendClientMessage(playerid, Erro, "Veiculo exclusivo da profissão Paramédico");
                }
                else
                {
                    if(!IsPlayerUniformParamedic(playerid))
                    {
                        ClearAnimations(playerid);
                        return SendClientMessage(playerid, Erro, "Você não está com o uniforme");

                    }
                }
            }
        }
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(PRESSED(KEY_NO) && IsPlayerInRangeOfPoint(playerid, 1.0, 1027.10, 997.50, 15.11))
	{
        if(PlayerInfo[playerid][Profissao] != paramedic)
            return SendClientMessage(playerid, Erro, "Você não tem permissão");

        if(IsPlayerUniformParamedic(playerid))
            return SendClientMessage(playerid, Erro, "Você já está uniformizado(a)");

        SetPlayerSkin(playerid, (PlayerInfo[playerid][sexo] == SEX_BOY ? 276 : 308));
        SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Agora você está uniformizado(a) e poderá exercer sua profissão");
        return 1;
	}
	return 1;
}

forward OnPlayerParamedicOffer(playerid, playeridoffer, value, bool:cure);
public OnPlayerParamedicOffer(playerid, playeridoffer, value, bool:cure)
{
    if(ParamedicOffer[playeridoffer])
    {
        if(ParamedicCount[playeridoffer] == 10)
        {
            SendClientMessage(playeridoffer, 0x00B57DAA, "Seu tempo de aceitar ou recusar acabou");
            ParamedicCount[playeridoffer] = 0;
            ParamedicOffer[playeridoffer] = false;
            return 1;
        }

        ParamedicCount[playeridoffer]++;
        SetTimerEx("OnPlayerParamedicOffer", 1000, false, "dddb", playerid, playeridoffer, value, cure);

        if(ParamedicCount[playeridoffer] == 1 || ParamedicCount[playeridoffer] == 3 || ParamedicCount[playeridoffer] == 5 || ParamedicCount[playeridoffer] == 7 || ParamedicCount[playeridoffer] == 9)
        {
            SendClientMessage(playeridoffer, 0x00B57DAA, "Para aceitar ou recusar digite ( /aceitar ou /recusar )");
        }
        return 1;
    }
    else
    {
        if(ParamedicAccepted[playeridoffer])
        {
            ParamedicAccepted[playeridoffer] = false;

            if(PlayerInfo[playeridoffer][Dinheiro] < value)
            {
                SendClientMessage(playerid, Erro, "O(A) Jogador(a) não tem dinheiro o suficiente");
                SendClientMessage(playeridoffer, Erro, "Você não tem saldo bancário suficiente");
                return 1;
            }

            PlayerInfo[playeridoffer][Dinheiro] -= value;
            UpdatePlayerMoney(playeridoffer);
            PlayerInfo[playerid][Dinheiro] += value;
            UpdatePlayerMoney(playerid);

            if(cure)
            {
                PlayerInfo[playeridoffer][disease] = 0;
                Progress[playeridoffer][Vida] = 0.0;
                UpdateProgressBar(playeridoffer);
            }
            else
            {
                if(IsPlayerVaccinated(playerid))
                {
                    PlayerInfo[playeridoffer][vaccine] += 18000;
                }
                else
                {
                    PlayerInfo[playeridoffer][vaccine] = (gettime() + 18000);
                }
            }

            PlayerInfo[playeridoffer][Health] = 100.0;
            SetPlayerHealth(playeridoffer, PlayerInfo[playeridoffer][Health]);

            UpdatePlayerDisease(playeridoffer);

            SendClientMessage(playeridoffer, 0xFFD993AA, "Você aceitou à oferta");
            SendClientMessage(playerid, 0xFFD993AA, "Sua oferta foi aceita");
        }
        else
        {
            SendClientMessage(playerid, 0xFFD993AA, "Sua oferta foi recusada");
            SendClientMessage(playeridoffer, 0xFFD993AA, "Você recusou à oferta");
            ParamedicRefused[playeridoffer] = false;
        }
    }
    return 1;
}

stock IsPlayerUniformParamedic(playerid)
{
    if(GetPlayerSkin(playerid) == 276) return true;
    else if(GetPlayerSkin(playerid) == 308) return true;
    else return false;
}

/******************************************************************************/
/****************************| COMMANDS PARAMEDIC |****************************/
/******************************************************************************/

CMD:doentes(playerid, params[])
{
    if(PlayerInfo[playerid][Profissao] != paramedic)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    new txt[3000], count;

    for(new player = 0; player < MAX_PLAYERS; player++)
    {
        if(PlayerInfo[player][disease])
        {
            count++;
            format(String, 80, "{FFFFFF}%s[%d]\t %s\n", PlayerInfo[player][Nome], player, DiseaseName(player));
            strcat(txt, String);
            continue;
        }
    }

    if(!count)
        return ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FFFFFF}Doentes Online [ {FF0000}0{FFFFFF} ]", "{FF0000}Náo há vítimas de doenças online no momento!", "Fechar", #);

    format(String, 100, "{FFFFFF}Doentes Online [ {328E0A}%d{FFFFFF} ]", count);
    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, String, txt, "Fechar", #);
    return 1;
}
CMD:vendervacina(playerid, params[])
{
    if(PlayerInfo[playerid][Profissao] != paramedic)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    for(new i = 0; i < sizeof(paramedic_vehicle); i++)
    {
        if(GetPlayerVehicleID(playerid) == paramedic_vehicle[i])
        {
            new id, value;

            if(sscanf(params, "dd", id, value))
                return SendClientMessage(playerid, Erro, "Digite: /VenderVacina [id] [valor]");

            if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
                return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

            if(playerid == id)
                return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

            if(GetDistanceBetweenPlayers(playerid, id) > 15)
                return SendClientMessage(playerid, Erro, "Você está muito longe, chegue mais perto");

            if(ParamedicOffer[id])
                return SendClientMessage(playerid, Erro, "O(A) Jogador(a) já recebeu uma oferta");

            if(PlayerInfo[id][disease])
                return SendClientMessage(playerid, Erro, "O(A) Jogador(a) já está doente e não pode tomar vacina");

            if((PlayerInfo[id][vaccine] - gettime()) > 54000)
                return SendClientMessage(playerid, Erro, "O(A) Jogador(a) já tem doses o suficiente");

            if(value < 1000 || value > 2000)
                return SendClientMessage(playerid, Erro, "Só é permitido valores entre $1.000 à $2.000");

            if(PlayerInfo[id][Dinheiro] < value)
                return SendClientMessage(playerid, Erro, "O(A) Jogador(a) não tem dinheiro o suficiente");

            format(String, MAX_STRING, "Você está oferencendo 5 doses de vacinas para o(a) jogador(a) %s[%d] por $%s", PlayerInfo[id][Nome], id, IsMoney(value, "."));
            SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);
            format(String, MAX_STRING, "O(A) Paramédico(a) %s[%d] está oferencendo 5 doses de vacinas para você por $%s", PlayerInfo[playerid][Nome], playerid, IsMoney(value, "."));
            SendClientMessage(id, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);

            ParamedicOffer[id] = true;
            OnPlayerParamedicOffer(playerid, id, value, false);
            return 1;
        }
    }
    SendClientMessage(playerid, Erro, "Você não está em uma Ambulância");
    return 1;
}
CMD:vendercura(playerid, params[])
{
    if(PlayerInfo[playerid][Profissao] != paramedic)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    for(new i = 0; i < sizeof(paramedic_vehicle); i++)
    {
        if(GetPlayerVehicleID(playerid) == paramedic_vehicle[i])
        {
            new id, value;

            if(sscanf(params, "dd", id, value))
                return SendClientMessage(playerid, Erro, "Digite: /VenderCura [id] [valor]");

            if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
                return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

            if(playerid == id)
                return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

            if(GetDistanceBetweenPlayers(playerid, id) > 15)
                return SendClientMessage(playerid, Erro, "Você está muito longe, chegue mais perto");

            if(ParamedicOffer[id])
                return SendClientMessage(playerid, Erro, "O(A) Jogador(a) já recebeu uma oferta");

            if(!PlayerInfo[id][disease])
                return SendClientMessage(playerid, Erro, "O(A) Jogador(a) não está doente");

            if(value < 1000 || value > 2500)
                return SendClientMessage(playerid, Erro, "Só é permitido valores entre $1.000 à $2.500");

            if(PlayerInfo[id][Dinheiro] < value)
                return SendClientMessage(playerid, Erro, "O(A) Jogador(a) não tem dinheiro o suficiente");

            format(String, MAX_STRING, "Você está oferencendo cura para o(a) jogador(a) %s[%d] por $%s", PlayerInfo[id][Nome], id, IsMoney(value, "."));
            SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);
            format(String, MAX_STRING, "O(A) Paramédico(a) %s[%d] está oferencendo cura para você por $%s", PlayerInfo[playerid][Nome], playerid, IsMoney(value, "."));
            SendClientMessage(id, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);

            ParamedicOffer[id] = true;
            OnPlayerParamedicOffer(playerid, id, value, true);
            return 1;
        }
    }
    SendClientMessage(playerid, Erro, "Você não está em uma Ambulância");
    return 1;
}
