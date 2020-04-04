#include YSI\y_hooks

hook OnGameModeInit()
{
    new db_itens[500];
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
        //cache_get_value_int(0, "id", PlayerInfo[playerid][celular]);
        cache_get_value_int(0, "kitmedicos", PlayerInfo[playerid][medicalkit]);
        cache_get_value_int(0, "celular", PlayerInfo[playerid][cellphone]);
        cache_get_value_int(0, "sms", PlayerInfo[playerid][sms]);
        cache_get_value_int(0, "creditos", PlayerInfo[playerid][credits]);
        cache_get_value_int(0, "planosaude", PlayerInfo[playerid][healthplan]);
        cache_get_value_int(0, "havegallon", PlayerInfo[playerid][havegallon]);
        cache_get_value_int(0, "gallon", PlayerInfo[playerid][gallon]);
        cache_get_value_int(0, "nonstop", PlayerInfo[playerid][nonstop]);
        cache_get_value_int(0, "vaccine", PlayerInfo[playerid][vaccine]);
        //cache_get_value_int(0, "id_contas", PlayerInfo[playerid][credito]);
    }
    else
    {
        PlayerInfo[playerid][cellphone] = 0;
        PlayerInfo[playerid][sms] = 0;
        PlayerInfo[playerid][credits] = 0;
        PlayerInfo[playerid][healthplan] = false;
        PlayerInfo[playerid][havegallon] = false;
        PlayerInfo[playerid][gallon] = 0;
        PlayerInfo[playerid][nonstop] = 0;

        new _query[70];
        mysql_format(IDConexao, _query, sizeof(_query), "INSERT INTO `Itens` (`id_contas`) VALUES ('%d')", PlayerInfo[playerid][ID]);
        mysql_query(IDConexao, _query);
    }
    return 1;
}
