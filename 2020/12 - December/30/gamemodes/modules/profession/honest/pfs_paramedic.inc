#include YSI\y_hooks

enum e_rsm
{
    Float:rsm_x,
    Float:rsm_y,
    Float:rsm_z,
    Float:rsm_a
};

new RandomSpawnMedic[7][e_rsm] =
{
    {1179.51, -1308.70, 13.90, 269.15},
    {2001.57, -1424.90, 16.49, 178.55},
    {1221.72, 302.32, 19.70, 67.18},
    {-331.49, 1062.84, 19.89, 268.53},
    {1606.38, 1840.33, 12.53, 0.00},
    {-1500.62, 2526.27, 55.83, 0.08},
    {-2186.76, -2307.73, 32.26, -40.00}
};

new bool:ParamedicOffer[MAX_PLAYERS];
new bool:ParamedicRefused[MAX_PLAYERS];
new bool:ParamedicAccepted[MAX_PLAYERS];
new ParamedicCount[MAX_PLAYERS];

hook OnGameModeInit()
{
    CreateVehicleLocation(1177.82, -1313.27, 14.06);    // LS Market
    CreateVehicleLocation(2017.94, -1410.86, 16.99);    // LS Jefferson
    CreateVehicleLocation(1225.68, 308.65, 19.74);      // Montgomery
    CreateVehicleLocation(-325.82, 1064.75, 19.74);     // Fort Carson
    CreateVehicleLocation(1619.37, 1821.78, 10.82);     // Las Venturas
    CreateVehicleLocation(-1501.91, 2519.93, 55.89);    // El Quebrados
    CreateVehicleLocation(-2191.03, -2315.62, 30.62);   // Angel Pine
	return 1;
}

hook OnPlayerConnect(playerid)
{
    PlayerInfo[playerid][doctorReborn] = INVALID_PLAYER_ID;
    PlayerInfo[playerid][victimReborn] = INVALID_PLAYER_ID;
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(PlayerInfo[playerid][doctorReborn] != INVALID_PLAYER_ID)
    {
        new id = PlayerInfo[playerid][doctorReborn];

        KillTimer(PlayerInfo[playerid][t_doctorReborn]);

        SendClientMessage(id, White, "Seu médico saiu do servidor e não foi possível terminar o pronto socorro");

        PlayerInfo[playerid][doctorReborn] = INVALID_PLAYER_ID;
    }

    if(PlayerInfo[playerid][victimReborn] != INVALID_PLAYER_ID)
    {
        new id = PlayerInfo[playerid][victimReborn];

        KillTimer(PlayerInfo[id][t_doctorReborn]);

        SendClientMessage(id, White, "Seu paciente saiu do servidor e não foi possível terminar o pronto socorro");

        PlayerInfo[playerid][victimReborn] = INVALID_PLAYER_ID;
    }

    ParamedicOffer[playerid] = false;
    ParamedicRefused[playerid] = false;
    ParamedicAccepted[playerid] = false;
    ParamedicCount[playerid] = 0;
    return 1;
}

hook OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    if(GetVehicleModel(vehicleid) == 416)
    {
        if(ispassenger) return 0;

        if(PlayerInfo[playerid][Profissao] != paramedic)
        {
            SendClientMessage(playerid, Erro, "Veiculo exclusivo da profissão Paramédico");
            ClearAnimations(playerid);
            return 0;
        }
        if(!IsPlayerUniformParamedic(playerid))
        {
            SendClientMessage(playerid, Erro, "Você não está com o uniforme");
            ClearAnimations(playerid);
            return 0;
        }
        return 1;
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(PRESSED(KEY_YES) && IsPlayerInHospital(playerid, 2.0))
	{
        if(PlayerInfo[playerid][Profissao] != paramedic)
            return SendClientMessage(playerid, Erro, "Você não tem permissão");

        if(PV_Profission[playerid])
            return SendClientMessage(playerid, Erro, "Você já criou um veículo profissão");

        new hospitalid = GetPlayerHospitalID(playerid);

        CreatePlayerVehicle(playerid, 416, RandomSpawnMedic[hospitalid][rsm_x], RandomSpawnMedic[hospitalid][rsm_y], RandomSpawnMedic[hospitalid][rsm_z], RandomSpawnMedic[hospitalid][rsm_a], -1, -1);

        SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Foi criado um veículo profissão no estacionamento");

        return (PlayerInfo[playerid][sexo] == SEX_BOY ? SetPlayerSkin(playerid, 276) : SetPlayerSkin(playerid, 308));
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

forward OnPlayerDoctorReborn(doctorid, victimid);
public OnPlayerDoctorReborn(doctorid, victimid)
{
    PlayerInfo[victimid][hasReborn] = false;
    PlayerInfo[doctorid][doctorReborn] = INVALID_PLAYER_ID;
    PlayerInfo[victimid][victimReborn] = INVALID_PLAYER_ID;

    ClearAnimations(doctorid);
    ClearAnimations(victimid);
    StopAudioStreamForPlayer(victimid);

    ShowTDStatus(victimid);
    #if EVENT_GIFT
        ShowTDGift(victimid);
    #endif

    PlayerPlaySound(victimid, 1057, 0, 0, 0);
    SetPlayerHealth(victimid, 100.0);

    PlayerInfo[doctorid][pointsDoctor] += 1;
    SetIntQuery(doctorid, "Itens", "pointsDoctor", PlayerInfo[doctorid][pointsDoctor]);

    format(String, MAX_STRING, "Você reanimou o(a) jogador(a) %s[%d] e recebeu um ponto do governo ( totoal : %d )", PlayerInfo[victimid][Nome], victimid, PlayerInfo[doctorid][pointsDoctor]);
    SendClientMessage(doctorid, White, String);
    format(String, MAX_STRING, "O(A) Paramedico(a) %s[%d] te reanimou e agora pode voltar a viver a vida", PlayerInfo[doctorid][Nome], doctorid);
    SendClientMessage(victimid, White, String);
    return 1;
}

stock IsPlayerUniformParamedic(playerid)
{
    if(GetPlayerSkin(playerid) == 276) return true;
    else if(GetPlayerSkin(playerid) == 308) return true;
    else return false;
}

stock IsPlayerInHospital(playerid, Float:range = 100.0)
{
    if(IsPlayerInRangeOfPoint(playerid, range, 1177.82, -1313.27, 14.06)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, range, 2017.94, -1410.86, 16.99)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, range, 1225.68, 308.65, 19.74)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, range, -325.82, 1064.75, 19.74)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, range, 1619.37, 1821.78, 10.82)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, range, -1501.91, 2519.93, 55.89)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, range, -2191.03, -2315.62, 30.62)) return 1;
    return 0;
}

stock GetPlayerHospitalID(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 100.0, 1177.82, -1313.27, 14.06)) return 0;
    if(IsPlayerInRangeOfPoint(playerid, 100.0, 2017.94, -1410.86, 16.99)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 100.0, 1225.68, 308.65, 19.74)) return 2;
    if(IsPlayerInRangeOfPoint(playerid, 100.0, -325.82, 1064.75, 19.74)) return 3;
    if(IsPlayerInRangeOfPoint(playerid, 100.0, 1619.37, 1821.78, 10.82)) return 4;
    if(IsPlayerInRangeOfPoint(playerid, 100.0, -1501.91, 2519.93, 55.89)) return 5;
    if(IsPlayerInRangeOfPoint(playerid, 100.0, -2191.03, -2315.62, 30.62)) return 6;
    return -1;
}

/******************************************************************************/
/****************************| COMMANDS PARAMEDIC |****************************/
/******************************************************************************/

CMD:vendervacina(playerid, params[])
{
    if(PlayerInfo[playerid][Profissao] != paramedic)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsPlayerInAnyVehicle(playerid))
        return SendClientMessage(playerid, Erro, "Você não está em uma Ambulância");

    new vehicleid = GetPlayerVehicleID(playerid);

    if(GetVehicleModel(vehicleid) != 416)
        return SendClientMessage(playerid, Erro, "Você não está em uma Ambulância");

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
CMD:vendercura(playerid, params[])
{
    if(PlayerInfo[playerid][Profissao] != paramedic)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsPlayerInAnyVehicle(playerid))
        return SendClientMessage(playerid, Erro, "Você não está em uma Ambulância");

    new vehicleid = GetPlayerVehicleID(playerid);

    if(GetVehicleModel(vehicleid) != 416)
        return SendClientMessage(playerid, Erro, "Você não está em uma Ambulância");

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
CMD:reanimar(playerid, params[])
{
    if(PlayerInfo[playerid][Profissao] != paramedic)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsPlayerUniformParamedic(playerid))
        return SendClientMessage(playerid, Erro, "Você não está com uniforme");

    new vehicleid = LastVehicle[playerid];

    if(GetVehicleModel(vehicleid) != 416)
        return SendClientMessage(playerid, Erro, "Seu último veículo não é uma Ambulância");

    if(PlayerInfo[playerid][doctorReborn] != INVALID_PLAYER_ID)
        return SendClientMessage(playerid, Erro, "Você já está reanimando algum jogador(a)");

    new id;

    if(sscanf(params, "d", id))
        return SendClientMessage(playerid, Erro, "Digite: /reanimar [id]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    if(GetDistanceBetweenPlayers(playerid, id) > 15)
        return SendClientMessage(playerid, Erro, "Você está muito longe, chegue mais perto");

    if(!PlayerInfo[id][hasReborn])
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) não está ferido(a)");

    if(PlayerInfo[id][victimReborn] != INVALID_PLAYER_ID)
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) já está sendo reanimado(a) por outro(a) paramédico(a)");

    KillTimer(PlayerInfo[playerid][t_death]);

    PlayerInfo[playerid][doctorReborn] = id;
    PlayerInfo[id][victimReborn] = playerid;

    ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 1, 0, 0, 10000, 0);
    PlayerInfo[playerid][t_doctorReborn] = SetTimerEx("OnPlayerDoctorReborn", 10000, false, "dd", playerid, id);
    return 1;
}
