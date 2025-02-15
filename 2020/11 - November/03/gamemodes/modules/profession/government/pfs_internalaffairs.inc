//#include YSI\y_hooks



/******************************************************************************/
/*************************| COMMANDS INTERNAL AFFAIRS |************************/
/******************************************************************************/

CMD:prenderpolicial(playerid, params[])
{
    if(PlayerInfo[playerid][Profissao] != internalaffairs)
        return SendClientMessage(playerid, Erro, "Voc� n�o tem permiss�o");

    new id, tmp[128], time = 30;

    if(sscanf(params, "us[128]", id, tmp))
        return SendClientMessage(playerid, Erro, "Digite: /PrenderPolicial [id/nome] [motivo]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) n�o conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Voc� n�o pode efetuar comando em s� mesmo");

    if(!IsPlayerPolice(id) || PlayerInfo[id][Profissao] == internalaffairs)
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) n�o � policial");

    if(PrisonEnum[id][pTempo] != 0)
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) j� est� preso(a)");

    format(String, MAX_STRING, "Voc� prendeu o(a) jogador(a) %s[%d] por %d minutos ( Motivo: %s )", PlayerInfo[id][Nome], id, time, PrisonEnum[id][pMotivo]);
    SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);
    format(String, MAX_STRING, "O(A) Corregedor(a) %s[%d] prendeu o(a) voc� por %d minutos ( Motivo: %s )", PlayerInfo[playerid][Nome], playerid, time, PrisonEnum[id][pMotivo]);
    SendClientMessage(id, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);

    SetPlayerPrision(id, PlayerInfo[playerid][Nome], "Federal", tmp, time);
    return 1;
}
