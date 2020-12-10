#include YSI\y_hooks

new merchandise;

hook OnGameModeInit()
{
    new db_server[300];
    strins(db_server, "CREATE TABLE IF NOT EXISTS `Server` (", strlen(db_server));
    strins(db_server, "`id` int PRIMARY KEY AUTO_INCREMENT, ", strlen(db_server));
    strins(db_server, "`merchandise` int(20) NOT NULL )", strlen(db_server));
    mysql_query(IDConexao, db_server, false);

    new Cache:result = mysql_query(IDConexao, "SELECT `merchandise` FROM `Server`");

    if(cache_num_rows())
        cache_get_value_int(0, "merchandise", merchandise);
    else
        mysql_query(IDConexao, "INSERT INTO `Server` (`merchandise`) VALUES (0)");

    cache_delete(result);
    return 1;
}

