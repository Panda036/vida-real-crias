
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
    new query[150];

    PlayerInfo[playerid][hud_backcolor] = 0;
    PlayerInfo[playerid][hud_color] = 0;
    PlayerInfo[playerid][hud_fontcolor] = 0;

    if(cache_num_rows())
    {
        new tmp[7];
        cache_get_value_name(0, "backcolor", tmp); format(PlayerInfo[playerid][hud_backcolor], 7, tmp);
        cache_get_value_name(0, "color", tmp); format(PlayerInfo[playerid][hud_color], 7, tmp);
        cache_get_value_name(0, "fontcolor", tmp); format(PlayerInfo[playerid][hud_fontcolor], 7, tmp);
    }
    else
    {
        mysql_format(IDConexao, query, 150, "INSERT INTO `Hud` (`id_contas`) VALUES ('%d')", PlayerInfo[playerid][ID]);
        mysql_query(IDConexao, query);

        format(PlayerInfo[playerid][hud_backcolor], 7, "FF0000");
        format(PlayerInfo[playerid][hud_color], 7, "FF0000");
        format(PlayerInfo[playerid][hud_fontcolor], 7, "FFFFFF");
    }

    printf("%s", PlayerInfo[playerid][hud_backcolor]);
    printf("%s", PlayerInfo[playerid][hud_color]);
    printf("%s", PlayerInfo[playerid][hud_fontcolor]);

    TDPlayerBarStatus(playerid);
    TDVehicleBarStatus(playerid);

    mysql_format(IDConexao, query, 150, "SELECT * FROM `Status` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadStatus", "d", playerid);
    return 1;
}
