#include YSI\y_hooks

new cps_cnh;
new cps_fines;

hook OnGameModeInit()
{
    new db_cnh[500];
    strins(db_cnh, "CREATE TABLE IF NOT EXISTS `CNH` (", strlen(db_cnh));
    strins(db_cnh, "`id` int AUTO_INCREMENT,", strlen(db_cnh));
    strins(db_cnh, "`a` int(1) NOT NULL,", strlen(db_cnh));
    strins(db_cnh, "`fines_a` int(2) NOT NULL,", strlen(db_cnh));
    strins(db_cnh, "`b` int(1) NOT NULL,", strlen(db_cnh));
    strins(db_cnh, "`fines_b` int(2) NOT NULL,", strlen(db_cnh));
    strins(db_cnh, "`c` int(1) NOT NULL,", strlen(db_cnh));
    strins(db_cnh, "`fines_c` int(2) NOT NULL,", strlen(db_cnh));
    strins(db_cnh, "`cht` int(1) NOT NULL,", strlen(db_cnh));
    strins(db_cnh, "`fines_cht` int(2) NOT NULL,", strlen(db_cnh));
    strins(db_cnh, "`arrais` int(1) NOT NULL,", strlen(db_cnh));
    strins(db_cnh, "`fines_arrais` int(2) NOT NULL,", strlen(db_cnh));
    strins(db_cnh, "`id_contas` int NOT NULL,", strlen(db_cnh));
    strins(db_cnh, "PRIMARY KEY(`id`),", strlen(db_cnh));
    strins(db_cnh, "FOREIGN KEY(`id_contas`) REFERENCES `Contas`(`id`) ON DELETE CASCADE )", strlen(db_cnh));
    mysql_query(IDConexao, db_cnh, false);

    cps_cnh = CreateDynamicCP(-2032.8086, -117.5343, 1035.1719, 1.0, -1, -1, -1, 30.0);
    cps_fines = CreateDynamicCP(823.4891, 3.1578, 1004.1797, 1.0, -1, -1, -1, 30.0);
    return 1;
}

hook OnPlayerEnterCheckpoint(playerid)
{
    if(IsPlayerInDynamicCP(playerid, cps_cnh))
    {
        new txt[500];
        strcat(txt, "{FFFFFF}Carteira\t {FF8000}Tipos\t {1b6302}Valor\n");
        strcat(txt, "{FFFFFF}Categoria A\t {FF8000}Motos\t {1b6302}$800\n");
        strcat(txt, "{FFFFFF}Categoria B\t {FF8000}Carros\t {1b6302}$1.600\n");
        strcat(txt, "{FFFFFF}Categoria C\t {FF8000}Caminhões/Onibus/Carretas\t {1b6302}$2.400\n");
        strcat(txt, "{FFFFFF}Cht\t {FF8000}Aéreos\t {1b6302}$7.000\n");
        strcat(txt, "{FFFFFF}Arrais\t {FF8000}Aquáticos\t {1b6302}$3.600\n");
        ShowPlayerDialog(playerid, main_cnh, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Carteira Nacional de Habilitação", txt, "Selecionar", "Fechar");
    }
    if(IsPlayerInDynamicCP(playerid, cps_fines))
    {
        new txt[500], price[MAX_PLAYERS] = 0;
        strcat(txt, "{FFFFFF}Carteira\t {FFFF00}Multas\t {1b6302}Valor\n");

        price[playerid] = PlayerInfo[playerid][fines_a] * 800;

        format(String, sizeof(String), "{FFFFFF}Categoria A\t {FFFF00}%d\t {1b6302}$%s\n", PlayerInfo[playerid][fines_a], IsMoney(price[playerid], "."));
        strcat(txt, String);

        price[playerid] = PlayerInfo[playerid][fines_a] * 1600;

        format(String, sizeof(String), "{FFFFFF}Categoria B\t {FFFF00}%d\t {1b6302}$%s\n", PlayerInfo[playerid][fines_b], IsMoney(price[playerid], "."));
        strcat(txt, String);

        price[playerid] = PlayerInfo[playerid][fines_a] * 2400;

        format(String, sizeof(String), "{FFFFFF}Categoria C\t {FFFF00}%d\t {1b6302}$%s\n", PlayerInfo[playerid][fines_c], IsMoney(price[playerid], "."));
        strcat(txt, String);

        price[playerid] = PlayerInfo[playerid][fines_a] * 7000;

        format(String, sizeof(String), "{FFFFFF}Cht\t {FFFF00}%d\t {1b6302}$%s\n", PlayerInfo[playerid][fines_cht], IsMoney(price[playerid], "."));
        strcat(txt, String);

        price[playerid] = PlayerInfo[playerid][fines_a] * 3600;

        format(String, sizeof(String), "{FFFFFF}Arrais\t {FFFF00}%d\t {1b6302}$%s\n", PlayerInfo[playerid][fines_arrais], IsMoney(price[playerid], "."));
        strcat(txt, String);
        ShowPlayerDialog(playerid, main_fines, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Multas Detran", txt, "Selecionar", "Fechar");
    }
    return 1;
}


hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == main_cnh && response)
    {
        new query[100];

        if(listitem == 0)
        {
            if(PlayerInfo[playerid][cnh_a])
                return SendClientMessage(playerid, Erro, "Você já possui CNH Categoria A");

            if(PlayerInfo[playerid][Dinheiro] < 800)
                return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

            PlayerInfo[playerid][Dinheiro] -= 800;
            PlayerInfo[playerid][cnh_a] = true;
            mysql_format(IDConexao, query, sizeof(query), "UPDATE `CNH` SET `a`='1' WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
            SendClientMessage(playerid, White, "Você comprou sua CNH Categoria A, aproveite");
        }
        if(listitem == 1)
        {
            if(PlayerInfo[playerid][cnh_b])
                return SendClientMessage(playerid, Erro, "Você já possui CNH Categoria B");

            if(PlayerInfo[playerid][Dinheiro] < 1600)
                return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

            PlayerInfo[playerid][Dinheiro] -= 1600;
            PlayerInfo[playerid][cnh_b] = true;
            mysql_format(IDConexao, query, sizeof(query), "UPDATE `CNH` SET `b`='1' WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
            SendClientMessage(playerid, White, "Você comprou sua CNH Categoria B, aproveite");
        }
        if(listitem == 2)
        {
            if(PlayerInfo[playerid][cnh_c])
                return SendClientMessage(playerid, Erro, "Você já possui CNH Categoria C");

            if(PlayerInfo[playerid][Dinheiro] < 2400)
                return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

            PlayerInfo[playerid][Dinheiro] -= 2400;
            PlayerInfo[playerid][cnh_c] = true;
            mysql_format(IDConexao, query, sizeof(query), "UPDATE `CNH` SET `c`='1' WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
            SendClientMessage(playerid, White, "Você comprou sua CNH Categoria C, aproveite");
        }
        if(listitem == 3)
        {
            if(PlayerInfo[playerid][cnh_cht])
                return SendClientMessage(playerid, Erro, "Você já possui CNH CHT");

            if(PlayerInfo[playerid][Dinheiro] < 7000)
                return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

            PlayerInfo[playerid][Dinheiro] -= 7000;
            PlayerInfo[playerid][cnh_cht] = true;
            mysql_format(IDConexao, query, sizeof(query), "UPDATE `CNH` SET `cht`='1' WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
            SendClientMessage(playerid, White, "Você comprou sua CNH CHT, aproveite");
        }
        if(listitem == 4)
        {
            if(PlayerInfo[playerid][cnh_arrais])
                return SendClientMessage(playerid, Erro, "Você já possui CNH Arrais");



            if(PlayerInfo[playerid][Dinheiro] < 3600)
                return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

            PlayerInfo[playerid][Dinheiro] -= 3600;
            PlayerInfo[playerid][cnh_arrais] = true;
            mysql_format(IDConexao, query, sizeof(query), "UPDATE `CNH` SET `arrais`='1' WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
            SendClientMessage(playerid, White, "Você comprou sua CNH Arrias, aproveite");
        }
        UpdatePlayerMoney(playerid);
        mysql_query(IDConexao, query);
        return 1;
    }
    if(dialogid == main_fines && response)
    {
        new query[100], price[MAX_PLAYERS] = 0;

        if(listitem == 0)
        {
            if(!PlayerInfo[playerid][cnh_a])
                return SendClientMessage(playerid, Erro, "Você não possui CNH Categoria A");

            if(!PlayerInfo[playerid][fines_a])
                return SendClientMessage(playerid, Erro, "Você não tem multa pendente");

            price[playerid] = PlayerInfo[playerid][fines_a] * 800;

            if(PlayerInfo[playerid][Dinheiro] < price[playerid])
                return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

            PlayerInfo[playerid][Dinheiro] -= price[playerid];
            PlayerInfo[playerid][fines_a] = 0;

            mysql_format(IDConexao, query, sizeof(query), "UPDATE `CNH` SET `fines_a`='0' WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
            SendClientMessage(playerid, White, "Você pagou todas as suas multas Categoria A");
        }
        if(listitem == 1)
        {
            if(!PlayerInfo[playerid][cnh_b])
                return SendClientMessage(playerid, Erro, "Você não possui CNH Categoria B");

            if(!PlayerInfo[playerid][fines_b])
                return SendClientMessage(playerid, Erro, "Você não tem multa pendente");

            price[playerid] = PlayerInfo[playerid][fines_b] * 1600;

            if(PlayerInfo[playerid][Dinheiro] < price[playerid])
                return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

            PlayerInfo[playerid][Dinheiro] -= price[playerid];
            PlayerInfo[playerid][fines_b] = 0;

            mysql_format(IDConexao, query, sizeof(query), "UPDATE `CNH` SET `fines_b`='0' WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
            SendClientMessage(playerid, White, "Você pagou todas as suas multas Categoria B");
        }
        if(listitem == 2)
        {
            if(!PlayerInfo[playerid][cnh_c])
                return SendClientMessage(playerid, Erro, "Você não possui CNH Categoria C");

            if(!PlayerInfo[playerid][fines_c])
                return SendClientMessage(playerid, Erro, "Você não tem multa pendente");

            price[playerid] = PlayerInfo[playerid][fines_c] * 2400;

            if(PlayerInfo[playerid][Dinheiro] < price[playerid])
                return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

            PlayerInfo[playerid][Dinheiro] -= price[playerid];
            PlayerInfo[playerid][fines_c] = 0;

            mysql_format(IDConexao, query, sizeof(query), "UPDATE `CNH` SET `fines_c`='0' WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
            SendClientMessage(playerid, White, "Você pagou todas as suas multas Categoria C");
        }
        if(listitem == 3)
        {
            if(!PlayerInfo[playerid][cnh_cht])
                return SendClientMessage(playerid, Erro, "Você não possui CNH Categoria CHT");

            if(!PlayerInfo[playerid][fines_cht])
                return SendClientMessage(playerid, Erro, "Você não tem multa pendente");

            price[playerid] = PlayerInfo[playerid][fines_cht] * 7000;

            if(PlayerInfo[playerid][Dinheiro] < price[playerid])
                return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

            PlayerInfo[playerid][Dinheiro] -= price[playerid];
            PlayerInfo[playerid][fines_cht] = 0;

            mysql_format(IDConexao, query, sizeof(query), "UPDATE `CNH` SET `fines_cht`='0' WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
            SendClientMessage(playerid, White, "Você pagou todas as suas multas Categoria CHT");
        }
        if(listitem == 4)
        {
            if(!PlayerInfo[playerid][cnh_arrais])
                return SendClientMessage(playerid, Erro, "Você não possui CNH Categoria C");

            if(!PlayerInfo[playerid][fines_arrais])
                return SendClientMessage(playerid, Erro, "Você não tem multa pendente");

            price[playerid] = PlayerInfo[playerid][fines_arrais] * 3600;

            if(PlayerInfo[playerid][Dinheiro] < price[playerid])
                return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

            PlayerInfo[playerid][Dinheiro] -= price[playerid];
            PlayerInfo[playerid][fines_arrais] = 0;

            mysql_format(IDConexao, query, sizeof(query), "UPDATE `CNH` SET `fines_arrais`='0' WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
            SendClientMessage(playerid, White, "Você pagou todas as suas multas Categoria C");
        }
        UpdatePlayerMoney(playerid);
        mysql_query(IDConexao, query);
        return 1;
    }
    return 1;
}

forward DB_LoadCnh(playerid);
public DB_LoadCnh(playerid)
{
    if(cache_num_rows() > 0)
    {
        cache_get_value_int(0, "a", PlayerInfo[playerid][cnh_a]);
        cache_get_value_int(0, "fines_a", PlayerInfo[playerid][fines_a]);
        cache_get_value_int(0, "b", PlayerInfo[playerid][cnh_b]);
        cache_get_value_int(0, "fines_b", PlayerInfo[playerid][fines_b]);
        cache_get_value_int(0, "c", PlayerInfo[playerid][cnh_c]);
        cache_get_value_int(0, "fines_c", PlayerInfo[playerid][fines_c]);
        cache_get_value_int(0, "cht", PlayerInfo[playerid][cnh_cht]);
        cache_get_value_int(0, "fines_cht", PlayerInfo[playerid][fines_cht]);
        cache_get_value_int(0, "arrais", PlayerInfo[playerid][cnh_arrais]);
        cache_get_value_int(0, "fines_arrais", PlayerInfo[playerid][fines_arrais]);
    }
    else
    {
        PlayerInfo[playerid][cnh_a] = false;
        PlayerInfo[playerid][fines_a] = 0;
        PlayerInfo[playerid][cnh_b] = false;
        PlayerInfo[playerid][fines_b] = 0;
        PlayerInfo[playerid][cnh_c] = false;
        PlayerInfo[playerid][fines_c] = 0;
        PlayerInfo[playerid][cnh_cht] = false;
        PlayerInfo[playerid][fines_cht] = 0;
        PlayerInfo[playerid][cnh_arrais] = false;
        PlayerInfo[playerid][fines_arrais] = 0;

        new query[70];
        mysql_format(IDConexao, query, sizeof(query), "INSERT INTO `CNH` (`id_contas`) VALUES ('%d')", PlayerInfo[playerid][ID]);
        mysql_query(IDConexao, query);
    }
    return 1;
}
