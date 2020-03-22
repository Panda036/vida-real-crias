#include YSI\y_hooks

hook OnGameModeInit()
{
    new dbban[500];
    strins(dbban, "CREATE TABLE IF NOT EXISTS Banidos ", strlen(dbban));
    strins(dbban, "(ID int(11) PRIMARY KEY,", strlen(dbban));
    strins(dbban, "Nome varchar(24) NOT NULL,", strlen(dbban));
    strins(dbban, "Responsavel varchar(24) NOT NULL,", strlen(dbban));
    strins(dbban, "Motivo varchar(24) NOT NULL,", strlen(dbban));
    strins(dbban, "Dia varchar(24) NOT NULL,", strlen(dbban));
    strins(dbban, "Vencimento varchar(24) NOT NULL,", strlen(dbban));
    strins(dbban, "Hora varchar(24) NOT NULL)", strlen(dbban));
    mysql_query(IDConexao, dbban, false);
    return 1;
}

DBLoadBan(playerid)
{
   mysql_format(IDConexao, String, sizeof(String), "SELECT * FROM `Banidos` WHERE `Nome`='%e'", pPlayerInfo[playerid][pNome]);
   mysql_tquery(IDConexao, String, "DBLoadBans", "d", playerid);
   return 1;
}

forward DBLoadBans(playerid);
public DBLoadBans(playerid)
{
    if(cache_num_rows() > 0)
    {
        new tmp[128];
        cache_get_value_name(0, "Responsavel", tmp); format(BanidosEnum[playerid][bResponsavel], 24, tmp);
        cache_get_value_name(0, "Motivo", tmp); format(BanidosEnum[playerid][bMotivo], 24, tmp);
        cache_get_value_name(0, "Dia", tmp); format(BanidosEnum[playerid][bDia], 24, tmp);
        cache_get_value_name(0, "Vencimento", tmp); format(BanidosEnum[playerid][bVencimento], 24, tmp);
        cache_get_value_name(0, "Hora", tmp); format(BanidosEnum[playerid][bHora], 24, tmp);

        new str[500];
        strcat(str, "\t {D9D900}Dados do Banimento \t\n\n");
        format(String, sizeof(String), "{FF6464}Nome:{C5C5C5} %s \n", PlayerInfo[playerid][Nome]);
        strcat(str, String);
        format(String, sizeof(String), "{FF6464}Responsável:{C5C5C5} %s \n", BanidosEnum[playerid][bResponsavel]);
        strcat(str, String);
        format(String, sizeof(String), "{FF6464}Motivo:{C5C5C5} %s \n", BanidosEnum[playerid][bMotivo]);
        strcat(str, String);
        format(String, sizeof(String), "{FF6464}Data:{C5C5C5} %s \n", BanidosEnum[playerid][bDia]);
        strcat(str, String);
        format(String, sizeof(String), "{FF6464}Hora:{C5C5C5} %s \n", BanidosEnum[playerid][bHora]);
        strcat(str, String);
        format(String, sizeof(String), "{FF6464}Validade:{C5C5C5} %s \n", BanidosEnum[playerid][bVencimento]);
        strcat(str, String);
        ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{0069B7}Banido", str, "Fechar", "");
        return Kick(playerid);
    } else {
        BanidosEnum[playerid][bResponsavel] = 0;
        BanidosEnum[playerid][bMotivo] = 0;
        BanidosEnum[playerid][bDia] = 0;
        BanidosEnum[playerid][bVencimento] = 0;
        BanidosEnum[playerid][bHora] = 0;
    }
    return 1;
}

