#include YSI\y_hooks

hook OnGameModeInit()
{
    new db_cnh[500];
    strins(db_cnh, "CREATE TABLE IF NOT EXISTS `CNH` (", strlen(db_cnh));
    strins(db_cnh, "`id` int AUTO_INCREMENT,", strlen(db_cnh));
    strins(db_cnh, "`a` int(1) NOT NULL,", strlen(db_cnh));
    strins(db_cnh, "`fines_a` int(2) NOT NULL,", strlen(db_cnh));
    strins(db_cnh, "`b` int(1) NOT NULL,", strlen(db_cnh));
    strins(db_cnh, "`fines_b` int(2) NOT NULL,", strlen(db_cnh));
    strins(db_cnh, "`c` int(1) NOT NULL,", strlen(db_cnh));
    strins(db_cnh, "`fines_c` int(2) NOT NULL,", strlen(db_cnh));
    strins(db_cnh, "`cht` int(1) NOT NULL,", strlen(db_cnh));
    strins(db_cnh, "`fines_cht` int(2) NOT NULL,", strlen(db_cnh));
    strins(db_cnh, "`arrais` int(1) NOT NULL,", strlen(db_cnh));
    strins(db_cnh, "`fines_arrais` int(2) NOT NULL,", strlen(db_cnh));
    strins(db_cnh, "`id_contas` int NOT NULL,", strlen(db_cnh));
    strins(db_cnh, "PRIMARY KEY(`id`),", strlen(db_cnh));
    strins(db_cnh, "FOREIGN KEY(`id_contas`) REFERENCES `Contas`(`id`) ON DELETE CASCADE )", strlen(db_cnh));
    mysql_query(IDConexao, db_cnh, false);
    return 1;
}

forward DB_LoadCnh(playerid);
public DB_LoadCnh(playerid)
{
    if(cache_num_rows() > 0)
    {
        cache_get_value_int(0, "fines_a", PlayerInfo[playerid][fines_a]);
        cache_get_value_int(0, "fines_b", PlayerInfo[playerid][fines_b]);
        cache_get_value_int(0, "fines_c", PlayerInfo[playerid][fines_c]);
        cache_get_value_int(0, "fines_cht", PlayerInfo[playerid][fines_cht]);
        cache_get_value_int(0, "fines_arrais", PlayerInfo[playerid][fines_arrais]);
    }
    else
    {
        PlayerInfo[playerid][fines_a] = 0;
        PlayerInfo[playerid][fines_b] = 0;
        PlayerInfo[playerid][fines_c] = 0;
        PlayerInfo[playerid][fines_cht] = 0;
        PlayerInfo[playerid][fines_arrais] = 0;

        new query[70];
        mysql_format(IDConexao, query, sizeof(query), "INSERT INTO `CNH` (`id_contas`) VALUES ('%d')", PlayerInfo[playerid][ID]);
        mysql_query(IDConexao, query);
    }
    return 1;
}

stock UpdateCNH(playerid)
{
    new query[500];
    mysql_format(IDConexao, query, 100, "UPDATE `CNH` SET `fines_a`='%d', `fines_b`='%d', `fines_c`='%d', `fines_cht`='%d', `fines_arrais`='%d' WHERE `id_contas`='%d'",
    PlayerInfo[playerid][fines_a],
    PlayerInfo[playerid][fines_b],
    PlayerInfo[playerid][fines_c],
    PlayerInfo[playerid][fines_cht],
    PlayerInfo[playerid][fines_arrais],
    PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);
    return 1;
}

stock IsPlayerCnhType(playerid, type[])
{
    new query[200];
    mysql_format(IDConexao, query, 100, "SELECT `%s` FROM `CNH` WHERE `%s`='1' AND `id_contas`='%d'", type, type, PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);

    return ( cache_num_rows() ? true : false );
}

stock SetPlayerCnhType(playerid, type[])
{
    if(IsPlayerCnhType(playerid, type))
        return 0;

    new query[200];
    mysql_format(IDConexao, query, 100, "UPDATE `CNH` SET `%s`='1' WHERE `id_contas`='%d'", type, PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);
    return 1;
}

stock DeletePlayerCnhType(playerid, type[])
{
    if(IsPlayerCnhType(playerid, type))
        return 0;

    new query[200];
    mysql_format(IDConexao, query, 100, "UPDATE `CNH` SET `%s`='0' WHERE `id_contas`='%d'", type, PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);
    return 1;
}

stock GetNumberTypeCNH(type[])
{
    if(!strcmp(type, "a") || !strcmp(type, "b") || !strcmp(type, "c")) return TYPE_CNH_ABC;
    else if(!strcmp(type, "cht")) return TYPE_CNH_CHT;
    else if(!strcmp(type, "arrais")) return TYPE_CNH_ARRAIS;
    return 1;
}
