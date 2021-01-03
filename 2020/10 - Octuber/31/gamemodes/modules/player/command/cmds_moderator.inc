CMD:banir(playerid, params[])
{
    if(!IsPlayerModerator(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    ShowTDPlayerBan(playerid);
    return 1;
}
CMD:desbanir(playerid, params[])
{
    if(!IsPlayerModerator(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new name[MAX_PLAYER_NAME], id;

    if(sscanf(params, "s[24]", name))
        return SendClientMessage(playerid, Erro, "Digite: /Desbanir [nome]");

    new query[200], Cache:result;
    mysql_format(IDConexao, query, 200, "SELECT * FROM `Contas` WHERE `Nome`='%s'", name);
    result = mysql_query(IDConexao, query);

    if(cache_num_rows() == 0)
        return SendClientMessage(playerid, Erro, "Não existe essa conta no banco de dados");

    cache_get_value_int(0, "ID", id);

    cache_delete(result);

    mysql_format(IDConexao, query, 200, "SELECT * FROM `Ban` WHERE `id_contas`='%d'", id);
    result = mysql_query(IDConexao, query);

    if(cache_num_rows() == 0)
        return SendClientMessage(playerid, Erro, "Esse jogador(a) não está banido(a)");

    cache_delete(result);

    mysql_format(IDConexao, query, 200, "DELETE FROM `Ban` WHERE `id_contas`='%d'", id);
    result = mysql_query(IDConexao, query);

    cache_delete(result);

    format(String, MAX_STRING, "VRC-Admin ~ Jogador(a) %s desbanido(a)", name);
    SendClientMessage(playerid, adm, String);
    return 1;
}
