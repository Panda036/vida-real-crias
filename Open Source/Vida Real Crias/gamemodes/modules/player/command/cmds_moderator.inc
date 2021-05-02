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
CMD:verificarip(playerid, params[])
{
    if(!IsPlayerModerator(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new name[MAX_PLAYER_NAME];

    if(sscanf(params, "s[24]", name))
        return SendClientMessage(playerid, Erro, "Digite: /VerificarIP [nome]");

    new query[200], Cache:result;
    mysql_format(IDConexao, query, 200, "SELECT * FROM `Contas` WHERE `Nome`='%s'", name);
    result = mysql_query(IDConexao, query);

    if(cache_num_rows() == 0)
        return SendClientMessage(playerid, Erro, "Não existe essa conta no Banco de Dados");

    new playerIP[32];

    cache_get_value_name(0, "IP", playerIP);

    cache_delete(result);

    new txt[500], count;

    strcat(txt, "{FF4000}Contagem\t {FF4000}Nome\t {FF4000}IP \n");

    mysql_format(IDConexao, query, 200, "SELECT * FROM `Contas` WHERE `IP`='%s'", playerIP);
    result = mysql_query(IDConexao, query);

    for(new row = 0; row < cache_num_rows(); row++)
    {
        new otherName[MAX_PLAYER_NAME], otherIP[32];

        cache_get_value_name(row, "Nome", otherName);
        cache_get_value_name(row, "IP", otherIP);

        if(!strcmp(otherIP, "127.0.0.1") || !strcmp(otherIP, "255.255.255.255")) continue;

        if(!strcmp(otherName, PlayerInfo[playerid][Nome]))
            format(String, 100, "{CCCCCC}%d\t {CCCCCC}%s\t {CCCCCC}%s \n", (count+1), otherName, otherIP);
        else
            format(String, 100, "{FFFFFF}%d\t {FFFFFF}%s\t {FFFFFF}%s \n", (count+1), otherName, otherIP);
        strcat(txt, String);
        count++;
    }

    cache_delete(result);

    if(!count)
        return SendClientMessage(playerid, Erro, "Não encontramos esse IP por causa da Máscara de Sub-Rede");

    format(String, 100, "{FF0000}IPs iguais ao do(a) %s", name);
    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_TABLIST_HEADERS, String, txt, "Fechar", #);
    return 1;
}
CMD:banirip(playerid, params[])
{
    if(!IsPlayerModerator(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new adress[32];

    if(sscanf(params, "s[32]", adress))
        return SendClientMessage(playerid, Erro, "Digite: /BanirIO [IP]");

    format(String, 50, "banip %s", adress);
    SendRconCommand(String);

    format(String, MAX_STRING, "IP ( %s ) banido do servidor", adress);
    SendClientMessage(playerid, adm, String);
    return 1;
}
CMD:extrato(playerid, params[])
{
    if(!IsPlayerModerator(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new name[24];

    if(sscanf(params, "s[24]", name))
        return SendClientMessage(playerid, Erro, "Digite: /VerSaldo [Nome]");

    new query[200], Cache:result;
    mysql_format(IDConexao, query, 200, "SELECT * FROM `Contas` WHERE `Nome`='%s'", name);
    result = mysql_query(IDConexao, query);

    if(cache_num_rows() == 0)
        return SendClientMessage(playerid, Erro, "Não existe conta com esse nome");

    new id_account, handMoney, bankMoney, houseMoney, businessMoney;

    cache_get_value_int(0, "ID", id_account);

    cache_delete(result);

    mysql_format(IDConexao, query, 200, "SELECT * FROM `Identidade` WHERE `id_contas`='%d'", id_account);
    result = mysql_query(IDConexao, query);

    if(cache_num_rows() == 0)
        return SendClientMessage(playerid, Erro, "Não existe conta com esse nome");

    cache_get_value_int(0, "dinheiro", handMoney);
    cache_get_value_int(0, "saldobancario", bankMoney);

    cache_delete(result);

    for(new houseid = 1; houseid < MAX_HOUSES; houseid++)
    {
        if(!strcmp(name, HouseInfo[houseid][hNome])){
            houseMoney = HouseInfo[houseid][hCofre];
            break;
        }
    }
    for(new businessid = 1; businessid < MAX_BUSINESS; businessid++)
    {
        if(!strcmp(name, BusinessInfo[businessid][cName])){
            businessMoney = BusinessInfo[businessid][cSafe];
            break;
        }
    }

    new totalMoney = (houseMoney + handMoney + bankMoney + businessMoney);

    new txt[500];

    strcat(txt, (!IsPlayerMobile(playerid) ? ("{F29B0D}Alocação\t {F29B0D}Saldo\n") : (#)));

    format(String, 100, "{FFFFFF}Mãos\t {1B6302}$%s\n", IsMoney(handMoney, "."));
    strcat(txt, String);
    format(String, 100, "{FFFFFF}Banco\t {1B6302}$%s\n", IsMoney(bankMoney, "."));
    strcat(txt, String);
    format(String, 100, "{FFFFFF}Casa\t {1B6302}$%s\n", IsMoney(houseMoney, "."));
    strcat(txt, String);
    format(String, 100, "{FFFFFF}Empresa\t {1B6302}$%s\n\n", IsMoney(businessMoney, "."));
    strcat(txt, String);
    format(String, 100, "{FFFFFF}Total\t {00FF00}$%s", IsMoney(totalMoney, "."));
    strcat(txt, String);

    format(String, 100, "{FF0000}Extrato de %s", name);

    ShowPlayerDialog(playerid, 0, (!IsPlayerMobile(playerid) ? DIALOG_STYLE_TABLIST_HEADERS : DIALOG_STYLE_LIST), String, txt, "Fechar", #);
    return 1;
}
CMD:enquete(playerid, params[])
{
    if(!IsPlayerModerator(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    if(Survey[s_state])
        return SendClientMessage(playerid, Erro, "Já existe uma enquete, finalize-a primeiro");

    new tmp[128];

    if(sscanf(params, "s[128]", tmp))
        return SendClientMessage(playerid, Erro, "Digite: /Enquete [Pergunta]");

    Survey[s_yes] = 0;
    Survey[s_no] = 0;
    Survey[s_state] = true;
    format(Survey[s_survey], MAX_STRING, tmp);

    format(String, MAX_STRING, "VRC-Enquente ~ %s %s ( %s ) ~~> /Sim ou /Nao", CargoAdmin(playerid), PlayerInfo[playerid][Nome], tmp);
    SendClientMessageToAll(adm, String);
    return 1;
}
CMD:finalizarenquete(playerid)
{
    if(!IsPlayerModerator(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    if(!Survey[s_state])
        return SendClientMessage(playerid, Erro, "Não existe uma enquete, crie-a primeiro");

    format(String, MAX_STRING, "VRC-Enquente ~ %s ~~> ( Sim:%d / Não:%d )", Survey[s_survey], Survey[s_yes], Survey[s_no]);
    SendClientMessageToAll(adm, String);

    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        SurveyVoted[i] = false;
    }

    Survey[s_yes] = 0;
    Survey[s_no] = 0;
    Survey[s_state] = false;
    format(Survey[s_survey], MAX_STRING, "");
    return 1;
}
CMD:analisarenquete(playerid)
{
    if(!IsPlayerModerator(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    if(!Survey[s_state])
        return SendClientMessage(playerid, Erro, "Não existe uma enquete, crie-a primeiro");

    new txt[150];
    format(String, 100, "{FFFFFF}Enquete: {F29B0D}%s\n", Survey[s_survey]);
    strcat(txt, String);
    format(String, 100, "{FFFFFF}Sim: {1B6302}%d\n", Survey[s_yes]);
    strcat(txt, String);
    format(String, 100, "{FFFFFF}Não: {FF4000}%d\n", Survey[s_no]);
    strcat(txt, String);

    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_LIST, "{FF0000}Analise de Enquete", txt, "Selecionar", "Cancelar");
    return 1;
}
