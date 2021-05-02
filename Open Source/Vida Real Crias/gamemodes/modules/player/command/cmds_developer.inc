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
CMD:darvip(playerid, params[])
{
	if(!IsPlayerDeveloper(playerid))
		return SendClientMessage(playerid, Erro, "Comando Inválido");

    new value, id;

    if(sscanf(params, "ud", id, value))
		return SendClientMessage(playerid, Erro, "Digite: /Darlevel [id/nome] [quantia]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    OnPlayerGiveVIP(id, value, 0);

	format(String, MAX_STRING, "VRC-Admin ~ Você deu %d dia(s) de VIP para o jogador(a) %s[%d]", value, PlayerInfo[id][Nome], id);
    SendClientMessage(playerid, adm, String);
    return 1;
}
