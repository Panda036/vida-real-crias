#include YSI\y_hooks

hook OnGameModeInit()
{
    new db_transfer[500];
    strins(db_transfer, "CREATE TABLE IF NOT EXISTS `Transfer` (", strlen(db_transfer));
    strins(db_transfer, "`id` int AUTO_INCREMENT, ", strlen(db_transfer));
    strins(db_transfer, "`value` int NOT NULL, ", strlen(db_transfer));
    strins(db_transfer, "`date` DATETIME NOT NULL, ", strlen(db_transfer));
    strins(db_transfer, "`id_received` int NOT NULL, ", strlen(db_transfer));
    strins(db_transfer, "`id_contas` int NOT NULL, ", strlen(db_transfer));
    strins(db_transfer, "PRIMARY KEY(`id`), ", strlen(db_transfer));
    strins(db_transfer, "FOREIGN KEY(`id_contas`) REFERENCES `Contas`(`id`) ON DELETE CASCADE )", strlen(db_transfer));
    mysql_query(IDConexao, db_transfer, false);
    return 1;
}
