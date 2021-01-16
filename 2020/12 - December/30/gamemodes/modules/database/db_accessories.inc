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

forward DB_LoadAccessories(playerid);
public DB_LoadAccessories(playerid)
{
    new slot = 0, rows = cache_num_rows();

    if(rows == 0) return 1;

    for(new row = 0; row < rows; row++)
    {
        cache_get_value_int(row, "slot", slot);

        cache_get_value_int(row, "model", ao[playerid][slot][ao_model]);
        cache_get_value_int(row, "value", ao[playerid][slot][ao_value]);
        cache_get_value_int(row, "bone", ao[playerid][slot][ao_bone]);
        cache_get_value_float(row, "x", ao[playerid][slot][ao_x]);
        cache_get_value_float(row, "y", ao[playerid][slot][ao_y]);
        cache_get_value_float(row, "z", ao[playerid][slot][ao_z]);
        cache_get_value_float(row, "rx", ao[playerid][slot][ao_rx]);
        cache_get_value_float(row, "ry", ao[playerid][slot][ao_ry]);
        cache_get_value_float(row, "rz", ao[playerid][slot][ao_rz]);
        cache_get_value_float(row, "sx", ao[playerid][slot][ao_sx]);
        cache_get_value_float(row, "sy", ao[playerid][slot][ao_sy]);
        cache_get_value_float(row, "sz", ao[playerid][slot][ao_sz]);
    }
    return 1;
}
