#include YSI\y_hooks

hook OnGameModeInit()
{
    new db_schedulingcnh[500];

    strins(db_schedulingcnh, "CREATE TABLE IF NOT EXISTS `SchedulingCNH` ( ", strlen(db_schedulingcnh));
    strins(db_schedulingcnh, "`id` int AUTO_INCREMENT,", strlen(db_schedulingcnh));
    strins(db_schedulingcnh, "`cnh` varchar(11) NOT NULL,", strlen(db_schedulingcnh));
    strins(db_schedulingcnh, "`date` datetime NOT NULL,", strlen(db_schedulingcnh));
    strins(db_schedulingcnh, "`time` int NOT NULL,", strlen(db_schedulingcnh));
    strins(db_schedulingcnh, "`id_contas` int NOT NULL,", strlen(db_schedulingcnh));
    strins(db_schedulingcnh, "PRIMARY KEY(`id`),", strlen(db_schedulingcnh));
    strins(db_schedulingcnh, "FOREIGN KEY(`id_contas`) REFERENCES `Contas`(`id`) ON DELETE CASCADE )", strlen(db_schedulingcnh));
    mysql_query(IDConexao, db_schedulingcnh, false);
    return 1;
}

stock IsNowSchedulingCNH(playerid, type[])
{
    if(!IsValidSchedulingCNH(playerid, type)) return 0;

    return ( gettime() >= GetTimeSchedulingCNH(playerid, type) ? true : false );
}

stock IsValidSchedulingCNH(playerid, type[])
{
    new query[200];
    mysql_format(IDConexao, query, 200, "SELECT * FROM `SchedulingCNH` WHERE `cnh`='%e' AND `id_contas`='%d'", type, PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);
    return ( cache_num_rows() ? true : false );
}

stock InsertSchedulingCNH(playerid, type[])
{
    new query[200];
    mysql_format(IDConexao, query, 200, "INSERT INTO `SchedulingCNH` (`cnh`, `date`, `time`, `id_contas`) VALUES ('%e', NOW(), '%d', '%d')",
    type,
    ( gettime() + 1800 ),
    PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);
    return 1;
}

stock DeleteSchedulingCNH(playerid, type[])
{
    if(!IsValidSchedulingCNH(playerid, type)) return 0;

    new time = GetTimeSchedulingCNH(playerid, type);

    if(gettime() >= time)
    {
        new query[200];
        mysql_format(IDConexao, query, 200, "DELETE FROM `SchedulingCNH` WHERE `cnh`='%e' AND `id_contas`='%d'", type, PlayerInfo[playerid][ID]);
        mysql_query(IDConexao, query);
        return 1;
    }
    return 1;
}

stock GetTimeSchedulingCNH(playerid, type[])
{
    if(!IsValidSchedulingCNH(playerid, type)) return 0;

    new query[200], time;
    mysql_format(IDConexao, query, 200, "SELECT `time` FROM `SchedulingCNH` WHERE `cnh`='%e' AND `id_contas`='%d'", type, PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);

    if(cache_num_rows() == 0) return 0;

    cache_get_value_int(0, "time", time);

    if(cache_num_rows()) return time;
    else return 0;
}

stock SchelduingCNH(playerid, type[], price)
{
    new days, hours, minutes, seconds;

    if(IsValidSchedulingCNH(playerid, type))
    {
        if(!IsNowSchedulingCNH(playerid, type))
        {
            TimeConvertEx(( GetTimeSchedulingCNH(playerid, type) - gettime() ), days, hours, minutes, seconds);

            new txt[500];

            format(String, MAX_STRING, "{FFFFFF}Olá %s, você está agendado \n", PlayerInfo[playerid][Nome]);
            strcat(txt, String);
            format(String, MAX_STRING, "{FFFFFF}Falta apenas %02d minutos e %02d segundos \n\n", minutes, seconds);
            strcat(txt, String);
            strcat(txt, "{FF0000}Dica: {FFFFFF}Não perca dinheiro atoa, estude: /estudar\n");

            ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Agendamento", txt, "Fechar", #);
            return 1;
        }

        Start_DS(playerid, type);
        DeleteSchedulingCNH(playerid, type);
        return 1;
    }

    if(PlayerInfo[playerid][Dinheiro] < price)
        return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

    PlayerInfo[playerid][Dinheiro] -= price;

    InsertSchedulingCNH(playerid, type);
    UpdatePlayerMoney(playerid);
    UpdateCNH(playerid);

    format(String, MAX_STRING, "O agendamento da CNH categoria \"{FF4000}%s{FFFFFF}\" começa daqui à 30 minutos", type);
    SendClientMessage(playerid, White, String);
    return 1;
}
