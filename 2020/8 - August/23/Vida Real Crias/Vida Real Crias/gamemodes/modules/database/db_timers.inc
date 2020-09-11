#include YSI\y_hooks

hook OnGameModeInit()
{
    new db_timers[500];
    strins(db_timers, "CREATE TABLE IF NOT EXISTS `Timers` (", strlen(db_timers));
    strins(db_timers, "`id` int AUTO_INCREMENT, ", strlen(db_timers));
    strins(db_timers, "`burglar` int NOT NULL, ", strlen(db_timers));
    strins(db_timers, "`burglarbox` int NOT NULL, ", strlen(db_timers));
    strins(db_timers, "`transaction` int NOT NULL, ", strlen(db_timers));
    strins(db_timers, "`transactionbox` int NOT NULL, ", strlen(db_timers));
    strins(db_timers, "`id_contas` int NOT NULL, ", strlen(db_timers));
    strins(db_timers, "PRIMARY KEY(`id`), ", strlen(db_timers));
    strins(db_timers, "FOREIGN KEY(`id_contas`) REFERENCES `Contas`(`id`) ON DELETE CASCADE )", strlen(db_timers));
    mysql_query(IDConexao, db_timers, false);
    return 1;
}

forward LoadTimers(playerid);
public LoadTimers(playerid)
{
    if(cache_num_rows())
    {
        cache_get_value_int(0, "burglar", PlayerInfo[playerid][t_burglar]);
        cache_get_value_int(0, "burglarbox", PlayerInfo[playerid][t_burglarbox]);
        cache_get_value_int(0, "transaction", PlayerInfo[playerid][t_transaction]);
        cache_get_value_int(0, "transactionbox", PlayerInfo[playerid][t_transactionbox]);
    }
    else
    {
        new query[100];
        mysql_format(IDConexao, query, 100, "INSERT INTO `Timers` (`id_contas`) VALUES ('%d')", PlayerInfo[playerid][ID]);
        mysql_query(IDConexao, query);
    }
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    PlayerInfo[playerid][t_burglar] = 0;
    PlayerInfo[playerid][t_burglarbox] = 0;
    PlayerInfo[playerid][t_transaction] = 0;
    PlayerInfo[playerid][t_transactionbox] = 0;
    return 1;
}
