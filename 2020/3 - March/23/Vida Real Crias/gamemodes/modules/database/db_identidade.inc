#include YSI\y_hooks

hook OnGameModeInit()
{
    new db_identidade[1000];
    strins(db_identidade, "CREATE TABLE IF NOT EXISTS `Identidade` (", strlen(db_identidade));
    strins(db_identidade, "`id` int AUTO_INCREMENT, ", strlen(db_identidade));
    strins(db_identidade, "`profissao` int(3) NOT NULL,", strlen(db_identidade));
    strins(db_identidade, "`admin` int(1) NOT NULL,", strlen(db_identidade));
    strins(db_identidade, "`minup` int(3) NOT NULL,", strlen(db_identidade));
    strins(db_identidade, "`segup` int(3) NOT NULL,", strlen(db_identidade));
    strins(db_identidade, "`level` int(11) NOT NULL,", strlen(db_identidade));
    strins(db_identidade, "`experiencia` int(1) NOT NULL,", strlen(db_identidade));
    strins(db_identidade, "`reais` int(11) NOT NULL,", strlen(db_identidade));
    strins(db_identidade, "`avisos` int(1) NOT NULL,", strlen(db_identidade));
    strins(db_identidade, "`estrelas` int(11) NOT NULL,", strlen(db_identidade));
    strins(db_identidade, "`dinheiro` int(20) NOT NULL,", strlen(db_identidade));
    strins(db_identidade, "`saldobancario` int(20) NOT NULL,", strlen(db_identidade));
    strins(db_identidade, "`matou` int(10) NOT NULL,", strlen(db_identidade));
    strins(db_identidade, "`morreu` int(10) NOT NULL,", strlen(db_identidade));
    strins(db_identidade, "`sexo` varchar(10) NOT NULL, ", strlen(db_identidade));
    strins(db_identidade, "`skin` int(3) NOT NULL, ", strlen(db_identidade));
    strins(db_identidade, "`disease` int(1) NOT NULL, ", strlen(db_identidade));
    strins(db_identidade, "`lastlogin` varchar(25) NOT NULL DEFAULT '00/00/0000 - 00:00', ", strlen(db_identidade));
    strins(db_identidade, "`id_contas` int NOT NULL, ", strlen(db_identidade));
    strins(db_identidade, "PRIMARY KEY (`id`), ", strlen(db_identidade));
    strins(db_identidade, "FOREIGN KEY (`id_contas`) REFERENCES `Contas`(`id`) ON DELETE CASCADE )", strlen(db_identidade));
    mysql_query(IDConexao, db_identidade, false);
    return 1;
}

forward DB_LoadIdentidade(playerid);
public DB_LoadIdentidade(playerid)
{
    if(cache_num_rows() == 0)
    {
        new _query[150];
        mysql_format(IDConexao, _query, sizeof(_query), "INSERT INTO `Identidade` (`sexo`, `skin`, `id_contas`) VALUES ('%s', '%d', '%d')", PlayerInfo[playerid][sexo], PlayerInfo[playerid][skin], PlayerInfo[playerid][ID]);
        mysql_query(IDConexao, _query);
    }
    else
    {
        new tmp[25];
        cache_get_value_int(0, "profissao", PlayerInfo[playerid][Profissao]);
        cache_get_value_int(0, "admin", PlayerInfo[playerid][Admin]);
        cache_get_value_int(0, "minup", PlayerInfo[playerid][minUP]);
        cache_get_value_int(0, "segup", PlayerInfo[playerid][segUP]);
        cache_get_value_int(0, "level", PlayerInfo[playerid][Level]);
        cache_get_value_int(0, "experiencia", PlayerInfo[playerid][Exp]);
        cache_get_value_int(0, "reais", PlayerInfo[playerid][Reais]);
        cache_get_value_int(0, "avisos", PlayerInfo[playerid][Avisos]);
        cache_get_value_int(0, "estrelas", PlayerInfo[playerid][Estrelas]);
        cache_get_value_int(0, "dinheiro", PlayerInfo[playerid][Dinheiro]);
        cache_get_value_int(0, "saldobancario", PlayerInfo[playerid][SaldoBancario]);
        cache_get_value_int(0, "matou", PlayerInfo[playerid][Matou]);
        cache_get_value_int(0, "morreu", PlayerInfo[playerid][Morreu]);
        cache_get_value_name(0, "sexo", tmp); format(PlayerInfo[playerid][sexo], 10, tmp);
        cache_get_value_int(0, "skin", PlayerInfo[playerid][skin]);
        cache_get_value_int(0, "disease", PlayerInfo[playerid][disease]);
        cache_get_value_name(0, "lastlogin", tmp); format(PlayerInfo[playerid][lastlogin], 25, tmp);

        SendClientMessage(playerid, Green, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        format(String, sizeof(String), "» Seja bem-vindo(a) mais uma vez {008040}%s{FFFFFF}!", PlayerInfo[playerid][Nome]);
        SendClientMessage(playerid, White, String);
        format(String, sizeof(String), "» Sua última entrada foi dia {FFFF00}%s", PlayerInfo[playerid][lastlogin]);
        SendClientMessage(playerid, White, String);
        SendClientMessage(playerid, Green, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

        format(String, sizeof(String), "%d", PlayerInfo[playerid][Estrelas]);
        PlayerTextDrawSetString(playerid, PlayerBarStatus[playerid][1], String);
        PlayerTextDrawShow(playerid, PlayerBarStatus[playerid][1]);

        TogglePlayerSpectating(playerid, false);
        PlayerInfo[playerid][Logado] = true;
        SetColorProfession(playerid);

        SetPlayerName(playerid, PlayerInfo[playerid][Nome]);
        SetPlayerScore(playerid, PlayerInfo[playerid][Level]);
        GivePlayerMoney(playerid, PlayerInfo[playerid][Dinheiro]);

        HideTextDrawLogin(playerid);
        StatusMostrar(playerid);
        TDShowHourDate(playerid);
        CancelSelectTextDraw(playerid);
        StopAudioStreamForPlayer(playerid);
    }
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    new hour, minutes, year, month, day, query[500];

    gettime(hour, minutes);
    getdate(year, month, day);
    format(String, sizeof(String), "%02d/%02d/%04d - %02d:%02dhrs", day, month, year, hour, minutes);
    format(PlayerInfo[playerid][lastlogin], 25, String);

    mysql_format(IDConexao, query, sizeof(query), "UPDATE `Identidade` SET `profissao`='%d', `admin`='%d', `minup`='%d', `segup`='%d', `level`='%d', `experiencia`='%d', `reais`='%d', `avisos`='%d', `estrelas`='%d', `dinheiro`='%d', `saldobancario`='%d', `matou`='%d', `morreu`='%d', `sexo`='%e', `skin`='%d', `lastlogin`='%e' WHERE `id_contas`='%d'",
    PlayerInfo[playerid][Profissao],
    PlayerInfo[playerid][Admin],
    PlayerInfo[playerid][minUP],
    PlayerInfo[playerid][segUP],
    PlayerInfo[playerid][Level],
    PlayerInfo[playerid][Exp],
    PlayerInfo[playerid][Reais],
    PlayerInfo[playerid][Avisos],
    PlayerInfo[playerid][Estrelas],
    PlayerInfo[playerid][Dinheiro],
    PlayerInfo[playerid][SaldoBancario],
    PlayerInfo[playerid][Matou],
    PlayerInfo[playerid][Morreu],
    PlayerInfo[playerid][sexo],
    PlayerInfo[playerid][skin],
    PlayerInfo[playerid][lastlogin],
    PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);
    return 1;
}
