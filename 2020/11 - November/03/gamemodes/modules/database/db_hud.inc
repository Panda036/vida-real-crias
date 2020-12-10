
hook OnGameModeInit()
{
    new db_hud[500];
    strins(db_hud, "CREATE TABLE IF NOT EXISTS `Hud` (", strlen(db_hud));
    strins(db_hud, "`id` int AUTO_INCREMENT,", strlen(db_hud));
    strins(db_hud, "`backcolor` varchar(12) NOT NULL DEFAULT 'FF0000',", strlen(db_hud));
    strins(db_hud, "`color` varchar(12) NOT NULL DEFAULT 'FF0000',", strlen(db_hud));
    strins(db_hud, "`fontcolor` varchar(12) NOT NULL DEFAULT 'FFFFFF',", strlen(db_hud));
    strins(db_hud, "`id_contas` int NOT NULL,", strlen(db_hud));
    strins(db_hud, "PRIMARY KEY(`id`),", strlen(db_hud));
    strins(db_hud, "FOREIGN KEY(`id_contas`) REFERENCES `Contas`(`id`) ON DELETE CASCADE )", strlen(db_hud));
    mysql_query(IDConexao, db_hud, false);
    return 1;
}


forward DB_LoadHud(playerid);
public DB_LoadHud(playerid)
{
    if(cache_num_rows())
    {
        new tmp[7];
        cache_get_value_name(0, "backcolor", tmp); format(PlayerInfo[playerid][hud_backcolor], 7, tmp);
        cache_get_value_name(0, "color", tmp); format(PlayerInfo[playerid][hud_color], 7, tmp);
        cache_get_value_name(0, "fontcolor", tmp); format(PlayerInfo[playerid][hud_fontcolor], 7, tmp);
    }
    else
    {
        new query[200];
        mysql_format(IDConexao, query, 200, "INSERT INTO `Hud` (`id_contas`) VALUES ('%d')", PlayerInfo[playerid][ID]);
        mysql_query(IDConexao, query);

        format(PlayerInfo[playerid][hud_backcolor], 7, "FF0000");
        format(PlayerInfo[playerid][hud_color], 7, "FF0000");
        format(PlayerInfo[playerid][hud_fontcolor], 7, "FFFFFF");
    }
    return 1;
}
