#include YSI\y_hooks

enum ProgressEnum
{
    Float:Fome,
    Float:Sede,
    Float:Sono,
    Float:Vida
};

new Progress[MAX_PLAYERS][ProgressEnum];

hook OnGameModeInit()
{
    new db_itens[500];
    strins(db_itens, "CREATE TABLE IF NOT EXISTS `Status`", strlen(db_itens));
    strins(db_itens, "(`id` int AUTO_INCREMENT, ", strlen(db_itens));
    strins(db_itens, "`fome` float NOT NULL, ", strlen(db_itens));
    strins(db_itens, "`sede` float NOT NULL, ", strlen(db_itens));
    strins(db_itens, "`sono` float NOT NULL, ", strlen(db_itens));
    strins(db_itens, "`vida` float NOT NULL, ", strlen(db_itens));
    strins(db_itens, "`id_contas` int NOT NULL, ", strlen(db_itens));
    strins(db_itens, "PRIMARY KEY (`id`), ", strlen(db_itens));
    strins(db_itens, "FOREIGN KEY (`id_contas`) REFERENCES `Contas`(`id`) ON DELETE CASCADE )", strlen(db_itens));
    mysql_query(IDConexao, db_itens, false);
    return 1;
}

forward DB_LoadStatus(playerid);
public DB_LoadStatus(playerid)
{
    if(cache_num_rows() != 0)
    {
        cache_get_value_float(0, "fome", Progress[playerid][Fome]);
        cache_get_value_float(0, "sede", Progress[playerid][Sede]);
        cache_get_value_float(0, "sono", Progress[playerid][Sono]);
        cache_get_value_float(0, "vida", Progress[playerid][Vida]);

        PlayerTextDrawTextSize(playerid, PlayerBarStatus[playerid][2], (593.0 - ((49.0 * Progress[playerid][Fome]) / 100)), 0.0);
        PlayerTextDrawShow(playerid, PlayerBarStatus[playerid][2]);
        PlayerTextDrawTextSize(playerid, PlayerBarStatus[playerid][3], (593.0 - ((49.0 * Progress[playerid][Sede]) / 100)), 0.0);
        PlayerTextDrawShow(playerid, PlayerBarStatus[playerid][3]);
        PlayerTextDrawTextSize(playerid, PlayerBarStatus[playerid][4], (593.0 - ((49.0 * Progress[playerid][Sono]) / 100)), 0.0);
        PlayerTextDrawShow(playerid, PlayerBarStatus[playerid][4]);
        PlayerTextDrawTextSize(playerid, PlayerBarStatus[playerid][5], (593.0 - ((49.0 * Progress[playerid][Vida]) / 100)), 0.0);
        PlayerTextDrawShow(playerid, PlayerBarStatus[playerid][5]);
    }
    else
    {
        Progress[playerid][Fome] = 0.0;
        Progress[playerid][Sede] = 0.0;
        Progress[playerid][Sono] = 0.0;
        Progress[playerid][Vida] = 0.0;

        new _query[100];
        mysql_format(IDConexao, _query, sizeof(_query), "INSERT INTO `Status` (`id_contas`) VALUES ('%d')", PlayerInfo[playerid][ID]);
        mysql_query(IDConexao, _query);
    }

    TimerBarStatus[playerid] = SetTimerEx("ProgrecoBar", 60*1000, true, "i", playerid);
    return 1;
}
