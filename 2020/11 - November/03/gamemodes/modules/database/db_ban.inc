#include YSI\y_hooks

hook OnGameModeInit()
{
    new dbban[500];
    strins(dbban, "CREATE TABLE IF NOT EXISTS `Ban` (", strlen(dbban));
    strins(dbban, "`id` int AUTO_INCREMENT,", strlen(dbban));
    strins(dbban, "`responsible` varchar(24) NOT NULL,", strlen(dbban));
    strins(dbban, "`reason` varchar(24) NOT NULL,", strlen(dbban));
    strins(dbban, "`date` datetime NOT NULL,", strlen(dbban));
    strins(dbban, "`duedate` int NOT NULL,", strlen(dbban));
    strins(dbban, "`id_contas` int NOT NULL,", strlen(dbban));
    strins(dbban, "PRIMARY KEY(`id`),", strlen(dbban));
    strins(dbban, "FOREIGN KEY(`id_contas`) REFERENCES `Contas`(`id`) ON DELETE CASCADE )", strlen(dbban));
    mysql_query(IDConexao, dbban, false);
    return 1;
}

stock DB_LoadBans(playerid)
{
    new var[24], str[100], value, days, hours, minutes, seconds;

    HideTextDrawLogin(playerid);

    cache_get_value_name(0, "responsible", var); format(Banimento[playerid][b_responsible], 24, var);
    cache_get_value_name(0, "reason", var); format(Banimento[playerid][b_reason], 24, var);
    cache_get_value_name(0, "date", var); format(Banimento[playerid][b_date], 24, var);
    cache_get_value_int(0, "duedate", Banimento[playerid][b_duedate]);
    cache_get_value_int(0, "id_contas", Banimento[playerid][b_idaccount]);

    if(gettime() >= Banimento[playerid][b_duedate] && Banimento[playerid][b_duedate] != 0)
    {
        new query[200];
        mysql_format(IDConexao, query, 200, "DELETE FROM `Ban` WHERE `id_contas`='%d'", Banimento[playerid][b_idaccount]);
        mysql_tquery(IDConexao, query, "LoadAccounts", "d", playerid);
    }
    else
    {
        value = (Banimento[playerid][b_duedate] - gettime());

        TimeConvertEx(value, days, hours, minutes, seconds);

        if(value > 86400)
            format(str, 30, "%d Dia(s) %02d:%02d:%02d", days, hours, minutes, seconds);
        else if(value > 3600)
            format(str, 20, "%02d:%02d:%02d", hours, minutes, seconds);
        else
            format(str, 10, "%02d:%02d", minutes, seconds);

        new txt[500];
        strcat(txt, "\t {D9D900}Dados do Banimento \n\n");
        format(String, 50, "{FF6464}Nome: {C5C5C5}%s \n", pPlayerInfo[playerid][pNome]);
        strcat(txt, String);
        format(String, 50, "{FF6464}Responsável: {C5C5C5}%s \n", Banimento[playerid][b_responsible]);
        strcat(txt, String);
        format(String, 50, "{FF6464}Motivo: {C5C5C5}%s \n", Banimento[playerid][b_reason]);
        strcat(txt, String);
        format(String, 50, "{FF6464}Data: {C5C5C5}%s \n", Banimento[playerid][b_date]);
        strcat(txt, String);
        format(String, 50, "{FF6464}Validade: {C5C5C5}%s \n", (Banimento[playerid][b_duedate] ? (str) : ("Permanente")));
        strcat(txt, String);
        ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{0069B7}Banido", txt, "Fechar", #);
        Kick(playerid);
    }
    return 1;
}

