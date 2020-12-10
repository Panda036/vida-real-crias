#include YSI\y_hooks

hook OnGameModeInit()
{
    new db_wp[1500];
    strins(db_wp, "CREATE TABLE IF NOT EXISTS `WeaponProducer` (", strlen(db_wp));
    strins(db_wp, "`id` int AUTO_INCREMENT, ", strlen(db_wp));
    strins(db_wp, "`ak` int(2) NOT NULL, ", strlen(db_wp));
    strins(db_wp, "`m4` int(2) NOT NULL, ", strlen(db_wp));
    strins(db_wp, "`pistol` int(2) NOT NULL, ", strlen(db_wp));
    strins(db_wp, "`uzi` int(2) NOT NULL, ", strlen(db_wp));
    strins(db_wp, "`sawnoff` int(2) NOT NULL, ", strlen(db_wp));
    strins(db_wp, "`combat` int(2) NOT NULL, ", strlen(db_wp));
    strins(db_wp, "`sniper` int(2) NOT NULL, ", strlen(db_wp));
    strins(db_wp, "`id_contas` int NOT NULL, ", strlen(db_wp));
    strins(db_wp, "PRIMARY KEY (`id`), ", strlen(db_wp));
    strins(db_wp, "FOREIGN KEY (`id_contas`) REFERENCES `Contas`(`id`) ON DELETE CASCADE )", strlen(db_wp));
    mysql_query(IDConexao, db_wp, false);
    return 1;
}

forward DB_LoadWP(playerid);
public DB_LoadWP(playerid)
{
    if(cache_num_rows()) return 0;

    new query[200];
    mysql_format(IDConexao, query, 200, "INSERT INTO `WeaponProducer` (`id_contas`) VALUES ('%d')", PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);
    return 1;
}
