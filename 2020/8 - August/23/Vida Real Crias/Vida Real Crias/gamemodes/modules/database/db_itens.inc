#include YSI\y_hooks

hook OnGameModeInit()
{
    new db_itens[1000];
    strins(db_itens, "CREATE TABLE IF NOT EXISTS `Itens`", strlen(db_itens));
    strins(db_itens, "(`id` int AUTO_INCREMENT, ", strlen(db_itens));
    strins(db_itens, "`kitmedicos` int(1) NOT NULL, ", strlen(db_itens));
    strins(db_itens, "`celular` int(1) NOT NULL, ", strlen(db_itens));
    strins(db_itens, "`sms` int(4) NOT NULL, ", strlen(db_itens));
    strins(db_itens, "`creditos` int(4) NOT NULL, ", strlen(db_itens));
    strins(db_itens, "`planosaude` int(1) NOT NULL, ", strlen(db_itens));
    strins(db_itens, "`havegallon` int(1) NOT NULL, ", strlen(db_itens));
    strins(db_itens, "`gallon` int(2) NOT NULL, ", strlen(db_itens));
    strins(db_itens, "`nonstop` int(5) NOT NULL, ", strlen(db_itens));
    strins(db_itens, "`vaccine` int(2) NOT NULL, ", strlen(db_itens));
    strins(db_itens, "`cannabis` int(3) NOT NULL, ", strlen(db_itens));
    strins(db_itens, "`bag` int(1) NOT NULL, ", strlen(db_itens));
    strins(db_itens, "`c4` int(2) NOT NULL, ", strlen(db_itens));
    strins(db_itens, "`kitrepair` int(2) NOT NULL, ", strlen(db_itens));
    strins(db_itens, "`jetpackgas` int(2) NOT NULL, ", strlen(db_itens));
    strins(db_itens, "`id_contas` int NOT NULL, ", strlen(db_itens));
    strins(db_itens, "PRIMARY KEY (`id`), ", strlen(db_itens));
    strins(db_itens, "FOREIGN KEY (`id_contas`) REFERENCES `Contas`(`id`) ON DELETE CASCADE )", strlen(db_itens));
    mysql_query(IDConexao, db_itens, false);
    return 1;
}

forward DB_LoadItens(playerid);
public DB_LoadItens(playerid)
{
    if(cache_num_rows() != 0)
    {
        cache_get_value_int(0, "kitmedicos", PlayerInfo[playerid][medicalkit]);
        cache_get_value_int(0, "celular", PlayerInfo[playerid][cellphone]);
        cache_get_value_int(0, "sms", PlayerInfo[playerid][sms]);
        cache_get_value_int(0, "creditos", PlayerInfo[playerid][credits]);
        cache_get_value_int(0, "planosaude", PlayerInfo[playerid][healthplan]);
        cache_get_value_int(0, "havegallon", PlayerInfo[playerid][havegallon]);
        cache_get_value_int(0, "gallon", PlayerInfo[playerid][gallon]);
        cache_get_value_int(0, "nonstop", PlayerInfo[playerid][nonstop]);
        cache_get_value_int(0, "vaccine", PlayerInfo[playerid][vaccine]);
        cache_get_value_int(0, "cannabis", PlayerInfo[playerid][cannabis]);
        cache_get_value_int(0, "bag", PlayerInfo[playerid][bag]);
        cache_get_value_int(0, "c4", PlayerInfo[playerid][c4]);
        cache_get_value_int(0, "kitrepair", PlayerInfo[playerid][kitrepair]);
        cache_get_value_int(0, "jetpackgas", PlayerInfo[playerid][jetpackgas]);
        cache_get_value_int(0, "active", PlayerInfo[playerid][active]);
    }
    else
    {
        new query[100];
        mysql_format(IDConexao, query, sizeof(query), "INSERT INTO `Itens` (`id_contas`) VALUES ('%d')", PlayerInfo[playerid][ID]);
        mysql_query(IDConexao, query);
    }
    return 1;
}
