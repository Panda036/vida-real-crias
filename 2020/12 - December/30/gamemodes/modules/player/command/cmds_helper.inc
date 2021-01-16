CMD:vercomandos(playerid)
{
    if(!IsPlayerHelper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    if(viewcmds[playerid])
        viewcmds[playerid] = false;
    else
        viewcmds[playerid] = true;

    SendClientMessage(playerid, adm, "VRC-Admin ~ Comando efetuado com sucesso");
    return 1;
}
CMD:cornome(playerid)
{
    if(!IsPlayerHelper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    ShowPlayerDialog(playerid, colorname, DIALOG_STYLE_INPUT, "{FF0000}Cor nome", "{FFFFFF}Digite um codigo em '{FF0000}HTML{FFFFFF}' abaixo\nPesquise no Google algo como {00FF00}Cores em HTML {FFFFFF}:\n{FF0000}Exemplo {FFFFFF}00FF00 = {00FF00}Calenzo", "Alterar", "Cancelar");
    return 1;
}
CMD:avisar(playerid, params[])
{
    if(!IsPlayerHelper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new id, reason[24];

    if(sscanf(params, "us[24]", id, reason))
        return SendClientMessage(playerid, Erro, "Digite: /Avisar [id/nome] [motivo]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    if(PrisonEnum[id][pTempo] != 0)
        return SendClientMessage(playerid, Erro, "O(A) jogador(a) está preso");

    new warning = GetIntQuery(id, "Identidade", "avisos");

    warning++;
    SetIntQuery(id, "Identidade", "avisos", warning);
    format(String, MAX_STRING, "VRC-Admin ~ O(A) %s %s avisou o(a) jogador(a) %s ( %d/3 )( Motivo: %s )", CargoAdmin(playerid), PlayerInfo[playerid][Nome], PlayerInfo[id][Nome], warning, reason);
    SendClientMessageToAll(Red, String);

    if(warning == 3)
    {
        SetIntQuery(id, "Identidade", "avisos", 0);

        format(String, MAX_STRING, "VRC-Admin ~ Por receber 3 avisos o(a) jogador(a) %s foi preso por 30 minutos", PlayerInfo[id][Nome]);
        SendClientMessageToAll(Red, String);

        SetPlayerPrision(PlayerInfo[id][Nome], PlayerInfo[playerid][Nome], "Federal", reason, 30);
    }
    return 1;
}

CMD:espiar(playerid, params[])
{
    if(!IsPlayerHelper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new id;

    if(sscanf(params, "u", id))
        return SendClientMessage(playerid, Erro, "Digite: /Espiar [id/nome]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    if(PlayerInfo[id][tutorial])
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) está no tutorial");

    if(Spying[playerid] == INVALID_PLAYER_ID){
        GetPlayerFacingAngle(playerid, stopspying[playerid][3]);
        GetPlayerPos(playerid, stopspying[playerid][0], stopspying[playerid][1], stopspying[playerid][2]);
    }

    Spying[playerid] = id;
    TogglePlayerSpectating(playerid, true);
    PlayerSpectatePlayer(playerid, id);
    SetPlayerInterior(playerid, GetPlayerInterior(id));
    SendClientMessage(playerid, adm, "VRC-Admin ~ Comando efetuado com sucesso");
    return 1;
}
CMD:pararespiar(playerid)
{
    if(!IsPlayerHelper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    if(Spying[playerid] == INVALID_PLAYER_ID)
        return SendClientMessage(playerid, Erro, "Você não está espiando");

    Spying[playerid] = INVALID_PLAYER_ID;
    SetPlayerInterior(playerid, 0);
    TogglePlayerSpectating(playerid, false);
    SetPlayerFacingAngle(playerid, stopspying[playerid][3]);
    SetPlayerPos(playerid, stopspying[playerid][0], stopspying[playerid][1], stopspying[playerid][2]);

    stopspying[playerid][0] = 0;
    stopspying[playerid][1] = 0;
    stopspying[playerid][2] = 0;
    stopspying[playerid][3] = 0;

    SendClientMessage(playerid, adm, "VRC-Admin ~ Comando efetuado com sucesso");
    return 1;
}
CMD:kick(playerid, params[])
{
    if(!IsPlayerHelper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new id, tmp[128];

    if(sscanf(params, "us[128]", id, tmp))
        return SendClientMessage(playerid, Erro, "Digite: /Kick [id/nome] [motivo]");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    GameTextForPlayer(id,"~r~kickado~w~!", 2500, 3);
    format(String, MAX_STRING, "VRC-Admin ~ O(A) %s %s kickou o(a) jogador(a) %s ( Motivo: %s )", CargoAdmin(playerid), PlayerInfo[playerid][Nome], PlayerInfo[id][Nome], tmp);
    SendClientMessageToAll(Red, String);
    format(String, MAX_STRING, "VRC-Admin ~ Você kickou o(a) Jogador(a) %s[%d]", PlayerInfo[id][Nome], id);
    SendClientMessage(playerid, adm, String);
    Kick(id);
    return 1;
}
CMD:punicao(playerid, params[])
{
    if(!IsPlayerHelper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new name[24], tempo, tmp[128];

    if(sscanf(params, "s[24]ds[128]", name, tempo, tmp))
        return SendClientMessage(playerid, Erro, "Digite: /Punicao [nome] [tempo] [motivo]");

    new id = GetPlayerID(name);

    if(playerid == id || !strcmp(name, PlayerInfo[playerid][Nome]))
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    if(tempo <= 0 || tempo > 1000)
        return SendClientMessage(playerid, Erro, "Tempo só permitido entre 1 e 1000");

    if(id != INVALID_PLAYER_ID && PrisonEnum[id][pTempo])
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) já está preso(a)");

    format(String, MAX_STRING, "VRC-Admin ~ O(A) %s %s %s jogador(a) %s por %d minutos ( Motivo: %s )", CargoAdmin(playerid), PlayerInfo[playerid][Nome], ((id == INVALID_PLAYER_ID) ? ("agendou à prisão do(a)") : ("prendeu o(a)")), name, tempo, tmp);
    SendClientMessageToAll(adm, String);

    SetPlayerPrision(name, PlayerInfo[playerid][Nome], "Federal", tmp, tempo, true);
    return 1;
}
CMD:despunicao(playerid, params[])
{
    if(!IsPlayerHelper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new name[24];

    if(sscanf(params, "s[24]", name))
        return SendClientMessage(playerid, Erro, "Digite: /Despunicao [nome]");

    new id = GetPlayerID(name);

    if(id != INVALID_PLAYER_ID && !PrisonEnum[id][pTempo])
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) não esta preso(a)");

    new query[200];

    if(id == INVALID_PLAYER_ID)
    {
        mysql_format(IDConexao, query, 200, "SELECT * FROM `Contas` WHERE `Nome`='%s'", name);
        mysql_query(IDConexao, query);

        if(cache_num_rows() == 0)
            return SendClientMessage(playerid, Erro, "Não existe conta com este nome");

        new id_account;

        cache_get_value_int(0, "ID", id_account);

        mysql_format(IDConexao, query, 200, "SELECT * FROM `Prison` WHERE `id_contas`='%d'", id_account);
        mysql_query(IDConexao, query);

        if(cache_num_rows() == 0)
            return SendClientMessage(playerid, Erro, "Jogador(a) não está preso(a)");

        mysql_format(IDConexao, query, 200, "DELETE FROM `Prison` WHERE `id_contas`='%d'", id_account);
        mysql_query(IDConexao, query);

        format(String, MAX_STRING, "VRC-Admin ~ Você agendou à despunição do(a) jogador(a) %s", name);
        SendClientMessage(playerid, adm, String);
        return 1;
    }

    KillTimer(TempoPreso[id]);

    SetPlayerInterior(id, 0);
    SetPlayerHealth(id, 100);
    SetPlayerPos(id, 1554.8657,-1675.6693,16.1953);

    PrisonEnum[id][pCadeia] = 0;
    PrisonEnum[id][pTempo] = 0;
    format(PrisonEnum[id][pMotivo], 1, "");

    mysql_format(IDConexao, query, 200, "DELETE FROM `Prison` WHERE `id_contas`='%d'", PlayerInfo[id][ID]);
    mysql_query(IDConexao, query);

    PlayerTextDrawHide(id, TempoPresidio[id][2]);
    PlayerTextDrawHide(id, TempoPresidio[id][1]);
    PlayerTextDrawHide(id, TempoPresidio[id][0]);

    GameTextForPlayer(id, "~w~Solto!", 3000, 0);
    format(String, MAX_STRING, "VRC-Admin ~ Você despuniu o(a) jogador(a) %s[%d] da prisão", PlayerInfo[id][Nome], id);
    SendClientMessage(playerid, adm, String);
    format(String, MAX_STRING, "VRC-Admin ~ O(A) %s %s[%d] despuniu você da prisão", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid);
    SendClientMessage(id, adm, String);
    return 1;
}
CMD:a(playerid, params[])
{
    if(!IsPlayerHelper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new tmp[128];

    if(sscanf(params, "s[128]", tmp))
        return SendClientMessage(playerid,Erro, "Digite: /A [mensagem]");

    format(String, MAX_STRING, "* %s %s: %s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], tmp);
    SendClientMessageToAll(0x0099CCAA, String);
    return 1;
}
CMD:cnn(playerid, params[])
{
    if(!IsPlayerHelper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new tmp[128];

    if(sscanf(params, "s[128]", tmp))
        return SendClientMessage(playerid, Erro, "Digite: /Cnn [mensagem]");

    TextConverter(tmp);

    format(String, MAX_STRING, "~r~# ~p~%s~w~: %s ~r~#", PlayerInfo[playerid][Nome], tmp);
    TextDrawSetString(RespawnVeiculos, String);
    TextDrawShowForAll(RespawnVeiculos);
    SetTimer("HideTextRespawn", 3000, false);
    return 1;
}
CMD:ann(playerid, params[])
{
    if(!IsPlayerHelper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new tmp[128];

    if(sscanf(params, "s[128]", tmp))
        return SendClientMessage(playerid, Erro, "Digite: /Ann [mensagem]");

    TextConverter(tmp);

    format(String, 50, "~r~#~w~%s ~r~#", tmp);
    TextDrawSetString(RespawnVeiculos, String);
	TextDrawShowForAll(RespawnVeiculos);
	SetTimer("HideTextRespawn", 3000, false);
    return 1;
}
CMD:godmodon(playerid)
{
    if(!IsPlayerHelper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    SetPlayerHealth(playerid, 99999);
    SetPlayerArmour(playerid, 99999);
    SendClientMessage(playerid, adm, "VRC-Admin ~ Comando efetuado com sucesso");
    return 1;
}
CMD:godmodoff(playerid)
{
    if(!IsPlayerHelper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    SetPlayerHealth(playerid, 100);
    SetPlayerArmour(playerid, 0);
    SendClientMessage(playerid, adm, "VRC-Admin ~ Comando efetuado com sucesso");
    return 1;
}
CMD:congelar(playerid, params[])
{
    if(!IsPlayerHelper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new id;

    if(sscanf(params, "u", id))
        return SendClientMessage(playerid, Erro, "Digite: /Congelar [id/nome]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    if(PlayerInfo[id][frozen]){
        TogglePlayerControllable(id, true);
        PlayerInfo[id][frozen] = false;
    } else {
        TogglePlayerControllable(id, false);
        PlayerInfo[id][frozen]= true;
    }

    format(String, MAX_STRING, "VRC-Admin ~ Jogador(a) %s[%d] %s(a)",  PlayerInfo[id][Nome], id, (PlayerInfo[id][frozen] ? ("congelado") : ("descongelado")));
    SendClientMessage(playerid, adm, String);
    format(String, MAX_STRING, "VRC-Admin ~ %s %s lê %s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], (PlayerInfo[id][frozen] ? ("congelou") : ("descongelou")));
    SendClientMessage(id, adm, String);
    return 1;
}
