#if EVENT_SWEET

#include YSI\y_hooks

hook OnGameModeInit()
{
    new db_sweet[500];

    strins(db_sweet, "CREATE TABLE IF NOT EXISTS `Sweet` (", strlen(db_sweet));
    strins(db_sweet, "`id` int AUTO_INCREMENT,", strlen(db_sweet));
    strins(db_sweet, "`sweets` int(3) NOT NULL,", strlen(db_sweet));
    strins(db_sweet, "`id_contas` int NOT NULL,", strlen(db_sweet));
    strins(db_sweet, "PRIMARY KEY(`id`),", strlen(db_sweet));
    strins(db_sweet, "FOREIGN KEY(`id_contas`) REFERENCES `Contas`(`id`) ON DELETE CASCADE )", strlen(db_sweet));
    mysql_query(IDConexao, db_sweet, false);

    return 1;
}

forward DB_LoadSweet(playerid);
public DB_LoadSweet(playerid)
{
    if(cache_num_rows()) return 0;

    new query[200];
    mysql_format(IDConexao, query, 200, "INSERT INTO `Sweet` (`id_contas`) VALUES ('%d')", PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);
    return 1;
}

#endif
