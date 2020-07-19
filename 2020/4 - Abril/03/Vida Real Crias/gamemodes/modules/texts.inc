public OnPlayerText(playerid, text[])
{
    if(!PlayerInfo[playerid][Logado]){
        SendClientMessage(playerid, Erro, "Você não está logado");
        return 0;
    }
    if(AntiAfk[playerid][aa_afk]){
        SendClientMessage(playerid, Erro, "Antes de falar, digite: /Sairafk");
        return 0;
    }
    if(PrisonEnum[playerid][pTempo]){
        SendClientMessage(playerid, Erro, "Você está preso e não pode usar o chat");
        return 0;
    }
    if(PlayerInfo[playerid][tutorial]){
        SendClientMessage(playerid, Erro, "Você está no tutorial e não pode usar o chat");
        return 0;
    }
    if(PlayerInfo[playerid][load]){
        SendClientMessage(playerid, Erro, "Seus dados estão sendo carregado, aguarde alguns segundos...");
        return 0;
    }

    //Staffs login
    new query[200];
    mysql_format(IDConexao, query, sizeof(query), "SELECT * FROM `Staffs` WHERE `code`='%e'", text);
    mysql_query(IDConexao, query);

    if(cache_num_rows() > 0)
    {
        if(IsPlayerHelper(playerid)){
            SendClientMessage(playerid, Erro, "Você já está exercendo seu cargo");
            return 0;
        }

        cache_get_value_int(0, "nivel", PlayerInfo[playerid][Admin]);

        if(!strcmp(PlayerInfo[playerid][sexo], "Masculino"))
            { SetPlayerSkin(playerid, 217); }
        else
            { SetPlayerSkin(playerid, 211); }

        format(String, sizeof(String), "| VRC-Admin | Olá %s %s[%d], agora você pode exerce seu cargo", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid);
        SendClientMessage(playerid, adm, String);
        return 0;
    }

    //Vips
    if(VipInfo[playerid][Vip]){
        format(String, sizeof(String), "%s {FFFFFF}[{%s}VIP{FFFFFF}][%d]: %s", PlayerInfo[playerid][Nome], VipInfo[playerid][tagcolor], playerid, text);
        LocalMessage(30.0, playerid, String, GetPlayerColor(playerid));
        return 0;
    }

    //Staffs
    switch(PlayerInfo[playerid][Admin])
    {
        case 1:
        {
            format(String, sizeof(String), "%s {FFFFFF}[{804000}Estagiário(a){FFFFFF}][%d]: %s", PlayerInfo[playerid][Nome], playerid, text);
            LocalMessage(30.0, playerid, String, GetPlayerColor(playerid));
            return 0;
        }
        case 2:
        {
            format(String, sizeof(String), "%s {FFFFFF}[{FFFF00}Ajudante{FFFFFF}][%d]: %s", PlayerInfo[playerid][Nome], playerid, text);
            LocalMessage(30.0, playerid, String, GetPlayerColor(playerid));
            return 0;
        }
        case 3:
        {
            format(String, sizeof(String), "%s {FFFFFF}[{FF8C00}Moderador(a){FFFFFF}][%d]: %s", PlayerInfo[playerid][Nome], playerid, text);
            LocalMessage(30.0, playerid, String, GetPlayerColor(playerid));
            return 0;
        }
        case 4:
        {
            format(String, sizeof(String), "%s {FFFFFF}[{008bce}Admininstrador(a){FFFFFF}][%d]: %s", PlayerInfo[playerid][Nome], playerid, text);
            LocalMessage(30.0, playerid, String, GetPlayerColor(playerid));
            return 0;
        }
        case 5:
        {
            format(String, sizeof(String), "%s {FFFFFF}[{FF0000}Coordenador(a){FFFFFF}][%d]: %s", PlayerInfo[playerid][Nome], playerid, text);
            LocalMessage(30.0, playerid, String, GetPlayerColor(playerid));
            return 0;
        }
        case 6:
        {
            format(String, sizeof(String), "%s {FFFFFF}[{328E0A}Desenvolvedor(a){FFFFFF}][%d]: %s", PlayerInfo[playerid][Nome], playerid, text);
            LocalMessage(30.0, playerid, String, GetPlayerColor(playerid));
            return 0;
        }
    }
    format(String, sizeof(String), "%s {FFFFFF}[%d]: %s", PlayerInfo[playerid][Nome], playerid, text);
    LocalMessage(30.0, playerid, String, GetPlayerColor(playerid));
    return 0;
}
