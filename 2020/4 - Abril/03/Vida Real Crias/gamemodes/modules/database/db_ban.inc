#include YSI\y_hooks

enum BAN_INFO
{
    bResponsible[MAX_PLAYER_NAME],
    bReason[24],
    bHour[24],
    bDate[24],
    bExpiration[24]
};

new BanInfo[MAX_PLAYERS][BAN_INFO];

hook OnGameModeInit()
{
    new dbban[500];
    strins(dbban, "CREATE TABLE IF NOT EXISTS Banidos (", strlen(dbban));
    strins(dbban, "`id` int AUTO_INCREMENT,", strlen(dbban));
    strins(dbban, "`responsavel` varchar(24) NOT NULL,", strlen(dbban));
    strins(dbban, "`motivo` varchar(24) NOT NULL,", strlen(dbban));
    strins(dbban, "`hora` varchar(24) NOT NULL,", strlen(dbban));
    strins(dbban, "`data` varchar(24) NOT NULL,", strlen(dbban));
    strins(dbban, "`vencimento` varchar(24) NOT NULL,", strlen(dbban));
    strins(dbban, "`id_contas` int NOT NULL,", strlen(dbban));
    strins(dbban, "PRIMARY KEY(`id`),", strlen(dbban));
    strins(dbban, "FOREIGN KEY(`id_contas`) REFERENCES `Contas`(`id`) ON DELETE CASCADE )", strlen(dbban));
    mysql_query(IDConexao, dbban, false);
    return 1;
}

forward DB_LoadBans(playerid);
public DB_LoadBans(playerid)
{
    if(cache_num_rows() > 0)
    {
        new var[MAX_PLAYER_NAME];

        HideTextDrawLogin(playerid);
        cache_get_value_name(0, "responsavel", var); format(BanInfo[playerid][bResponsible], 24, var);
        cache_get_value_name(0, "motivo", var); format(BanInfo[playerid][bReason], 24, var);
        cache_get_value_name(0, "hora", var); format(BanInfo[playerid][bHour], 24, var);
        cache_get_value_name(0, "data", var); format(BanInfo[playerid][bDate], 24, var);
        cache_get_value_name(0, "vencimento", var); format(BanInfo[playerid][bExpiration], 24, var);

        new str[500];
        strcat(str, "\t {D9D900}Dados do Banimento \t\n\n");
        format(String, sizeof(String), "{FF6464}Nome: {C5C5C5}%s \n", pPlayerInfo[playerid][pNome]);
        strcat(str, String);
        format(String, sizeof(String), "{FF6464}Responsável: {C5C5C5}%s \n", BanInfo[playerid][bResponsible]);
        strcat(str, String);
        format(String, sizeof(String), "{FF6464}Motivo: {C5C5C5}%s \n", BanInfo[playerid][bReason]);
        strcat(str, String);
        format(String, sizeof(String), "{FF6464}Hora: {C5C5C5}%s \n", BanInfo[playerid][bHour]);
        strcat(str, String);
        format(String, sizeof(String), "{FF6464}Data: {C5C5C5}%s \n", BanInfo[playerid][bDate]);
        strcat(str, String);
        format(String, sizeof(String), "{FF6464}Validade: {C5C5C5}%s \n", BanInfo[playerid][bExpiration]);
        strcat(str, String);
        ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{0069B7}Banido", str, "Fechar", "");
        Kick(playerid);
    }
    else
    {
        BanInfo[playerid][bResponsible] = 0;
        BanInfo[playerid][bReason] = 0;
        BanInfo[playerid][bHour] = 0;
        BanInfo[playerid][bDate] = 0;
        BanInfo[playerid][bExpiration] = 0;
    }
    return 1;
}

