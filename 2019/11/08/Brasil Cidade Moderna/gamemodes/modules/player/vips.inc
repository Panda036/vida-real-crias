#include YSI\y_hooks

enum VipI
{
        bool:Vip,
        Tempo,
        Chaves[25],
        Dias,
};

new VipInfo[MAX_PLAYERS][VipI];

hook OnGameModeInit()
{
    mysql_query(IDConexao, "CREATE TABLE IF NOT EXISTS `Vips`(`Nome` varchar(24) PRIMARY KEY NOT NULL, `Dias` int(5) NOT NULL, `Tempo` int(5) NOT NULL)", false);

    SetTimer("CheckVip", 1000, true);
    return 1;
}


DBLoadVip(playerid)
{
    new dbvip[128];
    mysql_format(IDConexao, dbvip, sizeof(dbvip), "SELECT * FROM `Vips` WHERE `Nome`='%e'", PlayerInfo[playerid][Nome]);
    mysql_tquery(IDConexao, dbvip, "DBLoadVips", "d", playerid);
    return 1;
}

forward DBLoadVips(playerid); public DBLoadVips(playerid)
{
    if(cache_num_rows() > 0)
    {
        VipInfo[playerid][Vip] = true;
        cache_get_value_int(0, "Dias", VipInfo[playerid][Dias]);
        cache_get_value_int(0, "Tempo", VipInfo[playerid][Tempo]);
    } else {
        VipInfo[playerid][Vip] = false;
        VipInfo[playerid][Dias] = 0;
        VipInfo[playerid][Tempo] = 0;
    }
    return 1;
}

forward DBSaveVips(playerid); public DBSaveVips(playerid)
{
    if(VipInfo[playerid][Vip])
    {
        new Query[80];
        mysql_format(IDConexao, Query, sizeof(Query), "UPDATE `Vips` SET `Dias`=%d, `Tempo`=%d WHERE `Nome`='%e'", VipInfo[playerid][Dias], VipInfo[playerid][Vip], VipInfo[playerid][Tempo], PlayerInfo[playerid][Nome]);
        mysql_tquery(IDConexao, Query);
    }
    return 1;
}


SetVip(playerid, days)
{
    new Query[110];
    if(VipInfo[playerid][Vip] == true)
    {
        format(String, sizeof String, "» Seu VIP foi renovado. +%d dias.", days);
        VipInfo[playerid][Tempo] += days;
        VipInfo[playerid][Dias] += days;

        mysql_format(IDConexao, Query, sizeof(Query), "UPDATE `Vips` SET `Dias`=%d, `Tempo`=%d WHERE `Nome`='%e'", VipInfo[playerid][Dias], VipInfo[playerid][Tempo], PlayerInfo[playerid][Nome]);
        mysql_tquery(IDConexao, Query);

    } else {

        format(String, sizeof String, "» Seu VIP de %d dias foi ativado", days);
        VipInfo[playerid][Tempo] = days;
        VipInfo[playerid][Dias] = days;
        VipInfo[playerid][Vip] = true;

        mysql_format(IDConexao, Query, sizeof(Query), "INSERT INTO `Vips`(`Nome`, `Dias`, `Tempo`) VALUES ('%e', %d, %d)", PlayerInfo[playerid][Nome], VipInfo[playerid][Dias], VipInfo[playerid][Vip], VipInfo[playerid][Tempo]);
        mysql_tquery(IDConexao, Query);
    }
    SendClientMessage(playerid, 0x09CC57AA, "~~~~~~~~~~~~~~~~~~~~~~~~~ VIP ~~~~~~~~~~~~~~~~~~~~~~~~~");
    SendClientMessage(playerid, -1, String);
    SendClientMessage(playerid, -1, "» Veja suas novas informações - /comandosvip");
    SendClientMessage(playerid, 0x09CC57AA, "~~~~~~~~~~~~~~~~~~~~~~~~~ VIP ~~~~~~~~~~~~~~~~~~~~~~~~~");
    return 1;
}

forward CheckVip(); public CheckVip()
{
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerConnected(i) && VipInfo[i][Vip] == true)
        {
            if(VipInfo[i][Tempo] > 0)
            {
                VipInfo[i][Tempo] = gettime() - ExpireVIP(i);
            } else {
                RemoveVip(i);
            }
        }
    }
    return 1;
}

ExpireVIP(playerid)
{
    new days = VipInfo[playerid][Dias] * 86400; // 86400 == 24horas
    return days;
}

RemoveVip(playerid)
{
    new query[70];
    mysql_format(IDConexao, query, sizeof(query), "DELETE FROM `Vips` WHERE `Nome` = '%e'", PlayerInfo[playerid][Nome]);
    mysql_tquery(IDConexao, query);

    VipInfo[playerid][Tempo] = 0;
    VipInfo[playerid][Vip] = false;
    VipInfo[playerid][Dias] = 0;
    SendClientMessage(playerid, 0x00E100AA, "| VIP | Infelizmente seus dias VIP expirou");
    return 1;
}
