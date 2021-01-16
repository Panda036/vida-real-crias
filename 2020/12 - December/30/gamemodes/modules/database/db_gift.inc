#if EVENT_GIFT

#include YSI\y_hooks

hook OnGameModeInit()
{
    new db_gift[400];
    strins(db_gift, "CREATE TABLE IF NOT EXISTS `Gift` (", strlen(db_gift));
    strins(db_gift, "`id` int AUTO_INCREMENT,", strlen(db_gift));
    strins(db_gift, "`min` int(2) NOT NULL,", strlen(db_gift));
    strins(db_gift, "`sec` int(2) NOT NULL,", strlen(db_gift));
    strins(db_gift, "`id_contas` int NOT NULL,", strlen(db_gift));
    strins(db_gift, "PRIMARY KEY(`id`),", strlen(db_gift));
    strins(db_gift, "FOREIGN KEY(`id_contas`) REFERENCES `Contas`(`id`) ON DELETE CASCADE )", strlen(db_gift));
    mysql_query(IDConexao, db_gift, false);
    return 1;
}

forward DB_LoadGift(playerid);
public DB_LoadGift(playerid)
{
    if(cache_num_rows())
    {
        cache_get_value_int(0, "min", tg_min[playerid]);
        cache_get_value_int(0, "sec", tg_sec[playerid]);
        return 1;
    }

    new query[200];
    mysql_format(IDConexao, query, 200, "INSERT INTO `Gift` (`min`, `sec`, `id_contas`) VALUES ('59', '59', '%d')", PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);
    return 1;
}

#endif
