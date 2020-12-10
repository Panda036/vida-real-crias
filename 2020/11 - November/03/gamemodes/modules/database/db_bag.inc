#include YSI\y_hooks

#define MAX_SLOT_BAG    10

enum e_bi
{
    bi_weaponid,
    bi_ammunation
};

new BagInfo[MAX_SLOT_BAG][MAX_PLAYERS][e_bi];

hook OnGameModeInit()
{
    new db_bag[2000];
    strins(db_bag, "CREATE TABLE IF NOT EXISTS `Bag` (", strlen(db_bag));
    strins(db_bag, "`id` int AUTO_INCREMENT,", strlen(db_bag));
    strins(db_bag, "`weapon0` int NOT NULL,", strlen(db_bag));
    strins(db_bag, "`ammun0` int NOT NULL,", strlen(db_bag));
    strins(db_bag, "`weapon1` int NOT NULL,", strlen(db_bag));
    strins(db_bag, "`ammun1` int NOT NULL,", strlen(db_bag));
    strins(db_bag, "`weapon2` int NOT NULL,", strlen(db_bag));
    strins(db_bag, "`ammun2` int NOT NULL,", strlen(db_bag));
    strins(db_bag, "`weapon3` int NOT NULL,", strlen(db_bag));
    strins(db_bag, "`ammun3` int NOT NULL,", strlen(db_bag));
    strins(db_bag, "`weapon4` int NOT NULL,", strlen(db_bag));
    strins(db_bag, "`ammun4` int NOT NULL,", strlen(db_bag));
    strins(db_bag, "`weapon5` int NOT NULL,", strlen(db_bag));
    strins(db_bag, "`ammun5` int NOT NULL,", strlen(db_bag));
    strins(db_bag, "`weapon6` int NOT NULL,", strlen(db_bag));
    strins(db_bag, "`ammun6` int NOT NULL,", strlen(db_bag));
    strins(db_bag, "`weapon7` int NOT NULL,", strlen(db_bag));
    strins(db_bag, "`ammun7` int NOT NULL,", strlen(db_bag));
    strins(db_bag, "`weapon8` int NOT NULL,", strlen(db_bag));
    strins(db_bag, "`ammun8` int NOT NULL,", strlen(db_bag));
    strins(db_bag, "`weapon9` int NOT NULL,", strlen(db_bag));
    strins(db_bag, "`ammun9` int NOT NULL,", strlen(db_bag));
    strins(db_bag, "`id_contas` int NOT NULL,", strlen(db_bag));
    strins(db_bag, "PRIMARY KEY(`id`), FOREIGN KEY(`id_contas`) REFERENCES `Contas`(`id`) ON DELETE CASCADE )", strlen(db_bag));
    mysql_query(IDConexao, db_bag, false);
	return 1;
}

forward DB_LoadBag(playerid);
public DB_LoadBag(playerid)
{
    if(cache_num_rows() == 0) return 0;

    cache_get_value_int(0, "weapon0", BagInfo[0][playerid][bi_weaponid]);
    cache_get_value_int(0, "ammun0", BagInfo[0][playerid][bi_ammunation]);
    cache_get_value_int(0, "weapon1", BagInfo[1][playerid][bi_weaponid]);
    cache_get_value_int(0, "ammun1", BagInfo[1][playerid][bi_ammunation]);
    cache_get_value_int(0, "weapon2", BagInfo[2][playerid][bi_weaponid]);
    cache_get_value_int(0, "ammun2", BagInfo[2][playerid][bi_ammunation]);
    cache_get_value_int(0, "weapon3", BagInfo[3][playerid][bi_weaponid]);
    cache_get_value_int(0, "ammun3", BagInfo[3][playerid][bi_ammunation]);
    cache_get_value_int(0, "weapon4", BagInfo[4][playerid][bi_weaponid]);
    cache_get_value_int(0, "ammun4", BagInfo[4][playerid][bi_ammunation]);
    cache_get_value_int(0, "weapon5", BagInfo[5][playerid][bi_weaponid]);
    cache_get_value_int(0, "ammun5", BagInfo[5][playerid][bi_ammunation]);
    cache_get_value_int(0, "weapon6", BagInfo[6][playerid][bi_weaponid]);
    cache_get_value_int(0, "ammun6", BagInfo[6][playerid][bi_ammunation]);
    cache_get_value_int(0, "weapon7", BagInfo[7][playerid][bi_weaponid]);
    cache_get_value_int(0, "ammun7", BagInfo[7][playerid][bi_ammunation]);
    cache_get_value_int(0, "weapon8", BagInfo[8][playerid][bi_weaponid]);
    cache_get_value_int(0, "ammun8", BagInfo[8][playerid][bi_ammunation]);
    cache_get_value_int(0, "weapon9", BagInfo[9][playerid][bi_weaponid]);
    cache_get_value_int(0, "ammun9", BagInfo[9][playerid][bi_ammunation]);
    return 1;
}
