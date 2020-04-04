//#include YSI\y_hooks



/******************************************************************************/
/*************************| COMMANDS INTERNAL AFFAIRS |************************/
/******************************************************************************/

CMD:prenderpolicial(playerid, params[])
{
    if(PlayerInfo[playerid][Profissao] != internalaffairs)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    new id, tmp[128];

    if(sscanf(params, "us[128]", id, tmp))
        return SendClientMessage(playerid, Erro, "Digite: /PrenderPolicial [id/nome] [motivo]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    if(!IsPlayerPolice(id) || PlayerInfo[id][Profissao] == internalaffairs)
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) não é policial");

    if(PrisonEnum[id][pTempo] != 0)
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) já está preso(a)");

    if(PerseguicaoTime[id])
        { KillTimer(PerseguicaoTime[id]); }

    format(PrisonEnum[id][pCadeia], 15, "Federal");
    format(PrisonEnum[id][pMotivo], 128, tmp);
    PrisonEnum[id][pTempo] = 30*60;

    ResetPlayerWeapons(id);
    SetPlayerInterior(id, 10);
    SetPlayerHealth(id, 99999);
    SetPlayerPos(id, 223.5335, 110.3779, 999.0156);

    PlayerTextDrawShow(id, TempoPresidio[id][1]);
    PlayerTextDrawShow(id, TempoPresidio[id][0]);

    format(String, sizeof(String), "Você prendeu o(a) %s %s[%d] você por 30 minutos ( Motivo: %s )", NameProfission(PlayerInfo[id][Profissao]), PlayerInfo[id][Nome], id, PrisonEnum[id][pMotivo]);
    SendClientMessage(playerid, color_internalaffairs, String);
    format(String, sizeof(String), "O(A) %s %s[%d] prendeu o(a) você por 30 minutos ( Motivo: %s )", NameProfission(PlayerInfo[playerid][Profissao]), PlayerInfo[playerid][Nome], playerid, PrisonEnum[id][pMotivo]);
    SendClientMessage(id, color_internalaffairs, String);

    GameTextForPlayer(id, "~w~~h~PRESO!", 2000, 0);
    SendClientMessage(id, 0x2894FFAA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Prisão ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    SendClientMessage(id, White, "•» Você está preso");
    format(String, sizeof(String), "•» Foi preso por ( %s )", PlayerInfo[playerid][Nome]);
    SendClientMessage(id, White, String);
    format(String, sizeof(String), "•» Motivo ( %s )", PrisonEnum[id][pMotivo]);
    SendClientMessage(id, White, String);
    SendClientMessage(id, 0x2894FFAA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Prisão ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    mysql_format(IDConexao, String, sizeof(String), "INSERT INTO `Prison` (`responsible`, `chain`, `reason`, `time`, `id_contas`) VALUES ('%e', '%e', '%e', '%d', '%d')", PlayerInfo[playerid][Nome], PrisonEnum[id][pCadeia], PrisonEnum[id][pMotivo], PrisonEnum[id][pTempo], PlayerInfo[id][ID]);
    mysql_query(IDConexao, String);

    PrisonSystem(id);
    return 1;
}
