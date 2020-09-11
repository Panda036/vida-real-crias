#include YSI\y_hooks

hook OnGameModeInit()
{
    new db_accessories[1000];
    strins(db_accessories, "CREATE TABLE IF NOT EXISTS `Accessories` (", strlen(db_accessories));
    strins(db_accessories, "`id` int AUTO_INCREMENT, ", strlen(db_accessories));
    strins(db_accessories, "`model` int NOT NULL, ", strlen(db_accessories));
    strins(db_accessories, "`value` int NOT NULL, ", strlen(db_accessories));
    strins(db_accessories, "`bone` int NOT NULL, ", strlen(db_accessories));
    strins(db_accessories, "`x` float NOT NULL, ", strlen(db_accessories));
    strins(db_accessories, "`y` float NOT NULL, ", strlen(db_accessories));
    strins(db_accessories, "`z` float NOT NULL, ", strlen(db_accessories));
    strins(db_accessories, "`rx` float NOT NULL, ", strlen(db_accessories));
    strins(db_accessories, "`ry` float NOT NULL, ", strlen(db_accessories));
    strins(db_accessories, "`rz` float NOT NULL, ", strlen(db_accessories));
    strins(db_accessories, "`sx` float NOT NULL, ", strlen(db_accessories));
    strins(db_accessories, "`sy` float NOT NULL, ", strlen(db_accessories));
    strins(db_accessories, "`sz` float NOT NULL, ", strlen(db_accessories));
    strins(db_accessories, "`slot` int NOT NULL, ", strlen(db_accessories));
    strins(db_accessories, "`id_contas` int NOT NULL, ", strlen(db_accessories));
    strins(db_accessories, "PRIMARY KEY (`id`), ", strlen(db_accessories));
    strins(db_accessories, "FOREIGN KEY (`id_contas`) REFERENCES `Contas`(`id`) ON DELETE CASCADE )", strlen(db_accessories));
    mysql_query(IDConexao, db_accessories, false);
    return 1;
}
