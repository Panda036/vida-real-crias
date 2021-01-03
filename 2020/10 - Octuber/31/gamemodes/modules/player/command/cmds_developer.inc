CMD:darreais(playerid, params[])
{
    if(!IsPlayerDeveloper(playerid))
		return SendClientMessage(playerid, Erro, "Comando Inválido");

    new real, id;

    if(sscanf(params, "ud", id, real))
		return SendClientMessage(playerid, Erro, "Digite: /DarReais [id/nome] [quantia]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    PlayerInfo[id][Reais] += real;
    SetIntQuery(id, "Identidade", "reais", PlayerInfo[id][Reais]);

	format(String, MAX_STRING, "VRC-Admin ~ Você deu R$%s para o(a) jogador(a) %s[%d]", IsMoney(real, "."), PlayerInfo[id][Nome], id);
    SendClientMessage(playerid, adm, String);
	format(String, MAX_STRING, "VRC-Admin ~ O(A) %s %s deu para você R$%s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], IsMoney(real, "."));
    SendClientMessage(id, adm, String);
    return 1;
}
CMD:removerreais(playerid, params[])
{
    if(!IsPlayerDeveloper(playerid))
		return SendClientMessage(playerid, Erro, "Comando Inválido");

    new real, id;

    if(sscanf(params, "ud", id, real))
		return SendClientMessage(playerid, Erro, "Digite: /RemoverReais [id/nome] [quantia]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    PlayerInfo[id][Reais] -= real;
    SetIntQuery(id, "Identidade", "reais", PlayerInfo[id][Reais]);

	format(String, MAX_STRING, "VRC-Admin ~ Você removeu R$%s do(a) jogador(a) %s[%d]", IsMoney(real), PlayerInfo[id][Nome], id);
    SendClientMessage(playerid, adm, String);
	format(String, MAX_STRING, "VRC-Admin ~ (A) %s %s removeu de você R$%s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], IsMoney(real));
    SendClientMessage(id, adm, String);
    return 1;
}

CMD:daradmin(playerid, params[])
{
    if(!IsPlayerDeveloper(playerid))
		return SendClientMessage(playerid, Erro, "Comando Inválido");

    new nivel, id;

    if(sscanf(params, "ud", id, nivel))
        return SendClientMessage(playerid, Erro, "Digite: /Daradmin [id/nome] [1-5]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(nivel < 0 || nivel > 5)
        return SendClientMessage(playerid, Erro, "Digite um cargo entre 1-5");

    if(nivel == PlayerInfo[id][Admin]){
        format(String, MAX_STRING, "O(A) Jogador(a) já é %s!", CargoAdmin(id));
        SendClientMessage(playerid, Erro, String);
        return 1;
    }

    if(!nivel)
	{
        format(String, MAX_STRING, "VRC-Admin ~ Você removeu o(a) jogador(a) %s[%d] da Admininstração!", PlayerInfo[id][Nome], id, CargoAdmin(id));
        SendClientMessage(playerid, adm, String);
        format(String, MAX_STRING, "VRC-Admin ~ O(A) %s %s[%d] removeu você da Admininstração!", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid, CargoAdmin(id));
        SendClientMessage(id, adm, String);
  	}
    else
    {
        format(String, MAX_STRING, "VRC-Admin ~ Você %s o(a) jogador(a) %s[%d] para %s", (nivel > PlayerInfo[id][Admin] ? ("promoveu") : ("rebaixou")), PlayerInfo[id][Nome], id, CargoAdmin(id));
        SendClientMessage(playerid, adm, String);
        format(String, MAX_STRING, "VRC-Admin ~ O(A) %s %s[%d] %s você para %s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid, (nivel > PlayerInfo[id][Admin] ? ("promoveu") : ("rebaixou")), CargoAdmin(id));
        SendClientMessage(id, adm, String);
    }

    PlayerInfo[id][Admin] = nivel;
    return 1;
}
CMD:darlevel(playerid, params[])
{
	if(!IsPlayerDeveloper(playerid))
		return SendClientMessage(playerid, Erro, "Comando Inválido");

    new level, id;

    if(sscanf(params, "ud", id, level))
		return SendClientMessage(playerid, Erro, "Digite: /Darlevel [id/nome] [quantia]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    PlayerInfo[id][Level] += level;
    SetPlayerScore(id, PlayerInfo[id][Level]);
    SetIntQuery(id, "Identidade", "level", PlayerInfo[id][Level]);

	format(String, MAX_STRING, "VRC-Admin ~ Você deu %d level(s) para o jogador(a) %s[%d]", level, PlayerInfo[id][Nome], id);
    SendClientMessage(playerid, adm, String);
	format(String, MAX_STRING, "VRC-Admin ~ O(A) %s %s deu para você %d level(s)", CargoAdmin(playerid), PlayerInfo[playerid][Nome], level);
    SendClientMessage(id, adm, String);
    return 1;
}
CMD:removerlevel(playerid, params[])
{
    if(!IsPlayerDeveloper(playerid))
		return SendClientMessage(playerid, Erro, "Comando Inválido");

    new level, id;

    if(sscanf(params, "ud", id, level))
		return SendClientMessage(playerid, Erro, "Digite: /Removerlevel [id/nome] [quantia]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    PlayerInfo[id][Level] -= level;
    SetPlayerScore(id, PlayerInfo[id][Level]);
    SetIntQuery(id, "Identidade", "level", PlayerInfo[id][Level]);

	format(String, MAX_STRING, "VRC-Admin ~ Você removeu %d level(s) do(a) jogador(a) %s[%d]", level, PlayerInfo[id][Nome], id);
    SendClientMessage(playerid, adm, String);
	format(String, MAX_STRING, "VRC-Admin ~ O(A) %s %s removeu de você %d level(s)", CargoAdmin(playerid), PlayerInfo[playerid][Nome], level);
    SendClientMessage(id, adm, String);
    return 1;
}
