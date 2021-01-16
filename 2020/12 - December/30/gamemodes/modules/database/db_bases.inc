/************************************************************
* OWNER :
*        Henrique Calenzo
*
* START DATE :
*       24/06/2020
*
* NOTES :
*       Copyright Vida Real Crias 2019 - 2020.  All rights reserved.
*
*/

#include YSI\y_hooks

hook OnGameModeInit()
{
    new db_base[3000];
    strins(db_base, "CREATE TABLE IF NOT EXISTS `Bases` (", strlen(db_base));
    strins(db_base, "`id` int PRIMARY KEY,", strlen(db_base));
    strins(db_base, "`tag` varchar(10) NOT NULL DEFAULT 'N.A',", strlen(db_base));
    strins(db_base, "`name` varchar(30) NOT NULL DEFAULT 'N/A',", strlen(db_base));
    strins(db_base, "`owner` varchar(24) NOT NULL DEFAULT 'N/A',", strlen(db_base));
    strins(db_base, "`sub` varchar(24) NOT NULL DEFAULT 'N/A',", strlen(db_base));

    for(new i = 0; i < MAX_BASE_MEMBERS; i++)
    {
        format(String, 128, "`member%d` varchar(24) NOT NULL DEFAULT 'N/A',", i);
        strins(db_base, String, strlen(db_base));
    }
    strins(db_base, "`selling` int(1) NOT NULL DEFAULT 1,", strlen(db_base));
    strins(db_base, "`price` int NOT NULL,", strlen(db_base));
    strins(db_base, "`invasion` int NOT NULL DEFAULT 1,", strlen(db_base));
    strins(db_base, "`dm` int NOT NULL,", strlen(db_base));
    strins(db_base, "`lock` int NOT NULL,", strlen(db_base));
    strins(db_base, "`pass` varchar(10) NOT NULL DEFAULT 'N/A',", strlen(db_base));
    strins(db_base, "`tagcolor` varchar(10) NOT NULL DEFAULT 'FF0000',", strlen(db_base));
    strins(db_base, "`renovation` int(20) NOT NULL )", strlen(db_base));
    mysql_query(IDConexao, db_base);

    new query[200];

    for(new i = 0; i < MAX_BASES; i++)
	{
        mysql_format(IDConexao, query, 200, "SELECT * FROM `Bases` WHERE `id`='%d'", i);
        mysql_tquery(IDConexao, query, "OnLoadBase", "d", i);
	}
    return 1;
}

forward OnLoadBase(baseid);
public OnLoadBase(baseid)
{
    if(cache_num_rows())
    {
        new tmp[MAX_PLAYER_NAME];

        cache_get_value_name(0, "tag", tmp);
        format(BaseInfo[baseid][bi_tag], MAX_BASE_TAG_NAME, tmp);
        cache_get_value_name(0, "name", tmp);
        format(BaseInfo[baseid][bi_name], MAX_BASE_NAME, tmp);
        cache_get_value_name(0, "owner", tmp);
        format(BaseInfo[baseid][bi_owner], MAX_PLAYER_NAME, tmp);
        cache_get_value_name(0, "sub", tmp);
        format(BaseInfo[baseid][bi_sub], MAX_PLAYER_NAME, tmp);

        for(new i = 0; i < MAX_BASE_MEMBERS; i++)
        {
            format(String, 128, "member%d", i);
            cache_get_value_name(0, String, tmp);
            format(BaseMember[baseid][i], MAX_PLAYER_NAME, tmp);
        }

        cache_get_value_int(0, "selling", BaseInfo[baseid][bi_selling]);
        cache_get_value_int(0, "price", BaseInfo[baseid][bi_price]);
        cache_get_value_int(0, "invasion", BaseInfo[baseid][bi_invasion]);
        cache_get_value_int(0, "dm", BaseInfo[baseid][bi_dm]);
        cache_get_value_int(0, "lock", BaseInfo[baseid][bi_lock]);

        cache_get_value_name(0, "pass", tmp);
        format(BaseInfo[baseid][bi_pass], MAX_BASE_PASS, tmp);
        cache_get_value_name(0, "tagcolor", tmp);
        format(BaseInfo[baseid][bi_tagcolor], 10, tmp);

        cache_get_value_int(0, "renovation", BaseInfo[baseid][bi_renovation]);
    }
    else
    {
        format(BaseInfo[baseid][bi_tag], MAX_BASE_NAME, "N.A");
        format(BaseInfo[baseid][bi_name], MAX_BASE_NAME, "N/A");
        format(BaseInfo[baseid][bi_owner], MAX_PLAYER_NAME, "N/A");
        format(BaseInfo[baseid][bi_sub], MAX_PLAYER_NAME, "N/A");

        for(new i = 0; i < MAX_BASE_MEMBERS; i++)
        {
            format(BaseMember[baseid][i], MAX_PLAYER_NAME, "N/A");
        }

        BaseInfo[baseid][bi_selling] = 1;
        BaseInfo[baseid][bi_price] = 0;
        BaseInfo[baseid][bi_dm] = 0;
        BaseInfo[baseid][bi_invasion] = 1;
        BaseInfo[baseid][bi_lock] = 0;

        format(BaseInfo[baseid][bi_pass], MAX_BASE_PASS, "N/A");
        format(BaseInfo[baseid][bi_tagcolor], 10, "FF0000");
        BaseInfo[baseid][bi_renovation] = 0;

        new query[100];
        mysql_format(IDConexao, query, 100, "INSERT INTO `Bases` (`id`) VALUES ('%d')", baseid);
        mysql_query(IDConexao, query);
    }

    CreateBases(baseid);
    return 1;
}

stock UpdateSubBase(baseid)
{
    new query[200];
    mysql_format(IDConexao, query, 200, "UPDATE `Bases` SET `sub`='%e' WHERE `id`='%d'", BaseInfo[baseid][bi_sub], baseid);
    mysql_query(IDConexao, query);
    return 1;
}

stock UpdateMemberBase(baseid, memberid)
{
    UpdateSubBase(baseid);

    new query[200];
    mysql_format(IDConexao, query, 200, "UPDATE `Bases` SET `member%d`='%e' WHERE `id`='%d'", memberid, BaseMember[baseid][memberid], baseid);
    mysql_query(IDConexao, query);
    return 1;
}
