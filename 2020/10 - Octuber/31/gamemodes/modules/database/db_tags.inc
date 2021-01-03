#include YSI\y_hooks

hook OnGameModeInit()
{
    new db_tags[500];
    strins(db_tags, "CREATE TABLE IF NOT EXISTS `Tags` (", strlen(db_tags));
    strins(db_tags, "`id` int AUTO_INCREMENT,", strlen(db_tags));
    strins(db_tags, "`youtube` int(1) NOT NULL,", strlen(db_tags));
    strins(db_tags, "`id_contas` int NOT NULL,", strlen(db_tags));
    strins(db_tags, "PRIMARY KEY(`id`), FOREIGN KEY(`id_contas`) REFERENCES `Contas`(`id`) ON DELETE CASCADE )", strlen(db_tags));
    mysql_query(IDConexao, db_tags, false);
	return 1;
}

forward DB_LoadTags(playerid);
public DB_LoadTags(playerid)
{
    if(cache_num_rows() == 0) return 0;

    cache_get_value_int(0, "youtube", PlayerInfo[playerid][youtube]);
    return 1;
}

stock IsPlayerYoutuber(playerid)
    return (PlayerInfo[playerid][youtube] > 0) ? true : false;

