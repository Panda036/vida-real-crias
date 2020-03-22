    if(strcmp(cmd, "/planejarroubo", true)==0)
    {
        if(PlayerInfo[playerid][Profissao] != LadraoGas)
            return SendClientMessage(playerid, Erro, "ERRO:{FFFFFF} Você não tem permissão!");
        return 1;
    }
    if(strcmp(cmd, "/pegargas", true)==0)
    {
        if(PlayerInfo[playerid][Profissao] != LadraoGas)
            return SendClientMessage(playerid, Erro, "ERRO:{FFFFFF} Você não tem permissão!");
        return 1;
    }
    if(strcmp(cmd, "/colocargas", true)==0)
    {
        if(PlayerInfo[playerid][Profissao] != LadraoGas)
            return SendClientMessage(playerid, Erro, "ERRO:{FFFFFF} Você não tem permissão!");

        if(PegouGas[playerid] == false)
            return SendClientMessage(playerid, Erro, "ERRO:{FFFFFF} Você não tem nenhum Bujão de Gás na mão!");
        return 1;
    }
    if(strcmp(cmd, "/cancelarroubo", true)==0)
    {
        if(PlayerInfo[playerid][Profissao] != LadraoGas)
            return SendClientMessage(playerid, Erro, "ERRO:{FFFFFF} Você não tem permissão!");

        return 1;
    }
