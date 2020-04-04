#include YSI\y_hooks

#define MAX_SLOT_BAG 10

enum e_bi
{
    bi_weaponid,
    bi_ammunation
};

new BagInfo[MAX_SLOT_BAG][MAX_PLAYERS][e_bi];

hook OnGameModeInit()
{
    new db_bag[1500];
    strins(db_bag, "CREATE TABLE IF NOT EXISTS `Bag` (", strlen(db_bag));
    strins(db_bag, "`id` int NOT NULL,", strlen(db_bag));
    strins(db_bag, "`weapon0` int NOT NULL DEFAULT = 0,", strlen(db_bag));
    strins(db_bag, "`ammunation_weapon0` int NOT NULL DEFAULT = 0,", strlen(db_bag));
    strins(db_bag, "`weapon1` int NOT NULL DEFAULT = 0,", strlen(db_bag));
    strins(db_bag, "`ammunation_weapon1` int NOT NULL DEFAULT = 0,", strlen(db_bag));
    strins(db_bag, "`weapon2` int NOT NULL DEFAULT = 0,", strlen(db_bag));
    strins(db_bag, "`ammunation_weapon2` int NOT NULL DEFAULT = 0,", strlen(db_bag));
    strins(db_bag, "`weapon3` int NOT NULL DEFAULT = 0,", strlen(db_bag));
    strins(db_bag, "`ammunation_weapon3` int NOT NULL DEFAULT = 0,", strlen(db_bag));
    strins(db_bag, "`weapon4` int NOT NULL DEFAULT = 0,", strlen(db_bag));
    strins(db_bag, "`ammunation_weapon4` int NOT NULL DEFAULT = 0,", strlen(db_bag));
    strins(db_bag, "`weapon5` int NOT NULL DEFAULT = 0,", strlen(db_bag));
    strins(db_bag, "`ammunation_weapon5` int NOT NULL DEFAULT = 0,", strlen(db_bag));
    strins(db_bag, "`weapon6` int NOT NULL DEFAULT = 0,", strlen(db_bag));
    strins(db_bag, "`ammunation_weapon6` int NOT NULL DEFAULT = 0,", strlen(db_bag));
    strins(db_bag, "`weapon7` int NOT NULL DEFAULT = 0,", strlen(db_bag));
    strins(db_bag, "`ammunation_weapon7` int NOT NULL DEFAULT = 0,", strlen(db_bag));
    strins(db_bag, "`weapon8` int NOT NULL DEFAULT = 0,", strlen(db_bag));
    strins(db_bag, "`ammunation_weapon8` int NOT NULL DEFAULT = 0,", strlen(db_bag));
    strins(db_bag, "`weapon9` int NOT NULL DEFAULT = 0,", strlen(db_bag));
    strins(db_bag, "`ammunation_weapon9` int NOT NULL DEFAULT = 0,", strlen(db_bag));
    strins(db_bag, "`id_contas` int NOT NULL DEFAULT = 0,", strlen(db_bag));
    strins(db_bag, "PRIMARY KEY(`id`), FOREIGN KEY(`id_contas`) REFERENCES `Contas`(`id`) ON DELETE CASCADE )", strlen(db_bag));
    mysql_query(IDConexao, db_bag, false);
	return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case school_bag:
        {
            if(!response) return 1;

            if(listitem == 0)
            {
                new txt[2000];
                strcat(txt, "{CCCCCC}Arma\t {1B6302}Munição\n\n");

                for(new slot = 0; slot < MAX_SLOT_BAG; slot++)
                {
                    if(BagInfo[slot][playerid][bi_weaponid])
                    {
                        new gunname[32];
                        GetWeaponName(BagInfo[slot][playerid][bi_weaponid], gunname, sizeof(gunname));

                        format(String, sizeof(String), "{CCCCCC}%s\t {1B6302}%d\n", gunname, BagInfo[slot][playerid][bi_ammunation]);
                        strcat(txt, String);
                    }
                    else
                    {
                        strcat(txt, "{CCCCCC}N/A\t {1B6302}0\n\n");
                    }
                }

                ShowPlayerDialog(playerid, school_bag_get, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Mochila", txt, "Continuar", "Cancelar");
            }
            else if(listitem == 1)
            {
                for(new slot = 0; slot < MAX_SLOT_BAG; slot++)
                {
                    if(!BagInfo[slot][playerid][bi_weaponid])
                    {
                        new gunname[32];
                        GetWeaponName(BagInfo[slot][playerid][bi_weaponid], gunname, sizeof(gunname));

                        for (new i = 0; i <= 12; i++)
                        {
                            GetPlayerWeaponData(playerid, i, BagInfo[slot][playerid][bi_weaponid], BagInfo[slot][playerid][bi_ammunation]);
                        }

                        format(String, sizeof(String), "%s guardada com %d munições no %dº slot", gunname, BagInfo[slot][playerid][bi_ammunation], slot);
                        SendClientMessage(playerid, Green, String);
                        return 1;
                    }
                }
                SendClientMessage(playerid, Erro, "Esse slot já está cheio");
            }
            return 1;
        }
        case school_bag_get:
        {
            if(!response) return 1;

            return 1;
        }
        case school_bag_add:
        {
            if(!response) return 1;

            return 1;
        }
    }
    return 1;
}

CMD:mochila(playerid)
{
    ShowPlayerDialog(playerid, school_bag, DIALOG_STYLE_LIST, "{FF0000}Mochila", "{FFFFFF}Pegar arma\nGuardar arma", "Continuar", "Cancelar");
    return 1;
}
