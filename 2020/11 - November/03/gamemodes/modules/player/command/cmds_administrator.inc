CMD:dararma(playerid, params[])
{
    if(!IsPlayerAdministrator(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new id, idarma;

	if(sscanf(params, "ud", id, idarma))
        return SendClientMessage(playerid, Erro, "Digite: /DarArma [id/nome] [id-arma]");

	GivePlayerWeapon(id, idarma, 900);
	SendClientMessage(playerid, adm, "VRC-Admin ~ Comando efetuado com sucesso");
	format(String, MAX_STRING, "VRC-Admin ~ O(A) %s %s te deu a arma ID '%d'", CargoAdmin(playerid),PlayerInfo[playerid][Nome],idarma);
    SendClientMessage(id, adm, String);
    return 1;
}
CMD:pagarevento(playerid, params[])
{
    if(!IsPlayerAdministrator(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new grana, id;

    if(sscanf(params, "ud", id, grana))
        return SendClientMessage(playerid, Erro, "Digite: /PagarEvento [id/nome] [quantia]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    if(grana > 1000000)
        return SendClientMessage(playerid, Erro, "Você não pode pagar mais do que $1.000.000");

    PlayerInfo[id][Dinheiro] += grana;
    UpdatePlayerMoney(id);

	format(String, MAX_STRING, "VRC-Admin ~ Você pagou $%s para o jogador(a) %s[%d] que ganhou o evento", IsMoney(grana, "."), PlayerInfo[id][Nome], id);
    SendClientMessage(playerid, adm, String);
	format(String, MAX_STRING, "VRC-Admin ~ O(A) %s %s lê pagou $%s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], IsMoney(grana, "."));
    SendClientMessage(id, adm, String);
    return 1;
}
