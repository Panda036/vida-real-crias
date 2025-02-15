CMD:fecharservidor(playerid, params[])
{
    if(!IsPlayerCoordinator(playerid))
		return SendClientMessage(playerid, Erro, "Comando Inv�lido");

    new tmp[128];

    if(sscanf(params, "s[128]", tmp))
        return SendClientMessage(playerid, Erro, "Digite: /FecharServidor [senha]");

    format(String, 50, "password %s", tmp);
	SendRconCommand(String);

    format(String, MAX_STRING, "VRC-Admin ~ O(A) %s %s trancou o servidor", CargoAdmin(playerid), PlayerInfo[playerid][Nome]);
    SendClientMessageToAll(adm, String);
    format(String, MAX_STRING, "VRC-Admin ~ Senha do servidor {FF0000}%s", tmp);
    SendClientMessage(playerid, adm, String);
    return 1;
}
CMD:abrirservidor(playerid)
{
    if(!IsPlayerCoordinator(playerid))
		return SendClientMessage(playerid, Erro, "Comando Inv�lido");

	SendRconCommand("password 0");

    format(String, MAX_STRING, "VRC-Admin ~ O(A) %s %s abriu o servidor", CargoAdmin(playerid), PlayerInfo[playerid][Nome]);
    SendClientMessageToAll(adm, String);
    SendClientMessage(playerid, adm, "VRC-Admin ~ O servidor acaba de ser destrancado por voc�");
    return 1;
}
CMD:reiniciar(playerid)
{
    if(!IsPlayerCoordinator(playerid))
		return SendClientMessage(playerid, Erro, "Comando Inv�lido");

    format(String, 30, "password %s", GetRandomString(10));
	SendClientMessageToAll(0xB9FFFFAA, "VRC-BOT ~ O Servidor reiniciar� em 2 minutos");
	SetTimer("RestartServer", 60000, false);
    return 1;
}
CMD:daradmin(playerid, params[])
{
    if(!IsPlayerCoordinator(playerid))
		return SendClientMessage(playerid, Erro, "Comando Inv�lido");

    new nivel, id;

    if(sscanf(params, "ud", id, nivel))
        return SendClientMessage(playerid, Erro, "Digite: /Daradmin [id/nome] [1-5]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) n�o conectado(a)");

    if(nivel < 0 || nivel > 5)
        return SendClientMessage(playerid, Erro, "Digite um cargo entre 1-5");

    if(nivel == PlayerInfo[id][Admin]){
        format(String, MAX_STRING, "O(A) Jogador(a) j� � %s!", CargoAdmin(id));
        SendClientMessage(playerid, Erro, String);
        return 1;
    }

    if(!nivel)
	{
        format(String, MAX_STRING, "VRC-Admin ~ Voc� removeu o(a) jogador(a) %s[%d] da Admininstra��o!", PlayerInfo[id][Nome], id, CargoAdmin(id));
        SendClientMessage(playerid, adm, String);
        format(String, MAX_STRING, "VRC-Admin ~ O(A) %s %s[%d] removeu voc� da Admininstra��o!", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid, CargoAdmin(id));
        SendClientMessage(id, adm, String);
  	}
    else
    {
        format(String, MAX_STRING, "VRC-Admin ~ Voc� %s o(a) jogador(a) %s[%d] para %s", (nivel > PlayerInfo[id][Admin] ? ("promoveu") : ("rebaixou")), PlayerInfo[id][Nome], id, CargoAdmin(id));
        SendClientMessage(playerid, adm, String);
        format(String, MAX_STRING, "VRC-Admin ~ O(A) %s %s[%d] %s voc� para %s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid, (nivel > PlayerInfo[id][Admin] ? ("promoveu") : ("rebaixou")), CargoAdmin(id));
        SendClientMessage(id, adm, String);
    }

    PlayerInfo[id][Admin] = nivel;
    return 1;
}
