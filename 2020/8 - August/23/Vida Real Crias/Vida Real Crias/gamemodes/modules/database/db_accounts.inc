#include YSI\y_hooks

hook OnGameModeInit()
{
    #if SERVER_OFFLINE
        IDConexao = mysql_connect("127.0.0.1", "root", "", "samp");
    #else
        IDConexao = mysql_connect("198.50.187.244", "henriquec_3473", "L8m4gts5gw", "henriquec_3473");
    #endif

    if(mysql_errno(IDConexao))
    {
        print(" =======================================");
        print(" |                                     |");
        print(" |           Banco de Dados            |");
        print(" |               Falhou                |");
        print(" |                                     |");
        print(" =======================================");
        return SendRconCommand("exit");
    }
    else
    {
        print(" =======================================");
        print(" |                                     |");
        print(" |           Banco de Dados            |");
        print(" |        Conectado com sucesso        |");
        print(" |                                     |");
        print(" =======================================");
    }

    new dbacc[1000];
    strins(dbacc, "CREATE TABLE IF NOT EXISTS `Contas` (", strlen(dbacc));
    strins(dbacc, "`ID` int AUTO_INCREMENT, ", strlen(dbacc));
    strins(dbacc, "`Nome` varchar(24) NOT NULL, ", strlen(dbacc));
    strins(dbacc, "`Senha` varchar(32) NOT NULL, ", strlen(dbacc));
    strins(dbacc, "`Email` varchar(50) NOT NULL, ", strlen(dbacc));
    strins(dbacc, "`Code` varchar(10) NOT NULL, ", strlen(dbacc));
    strins(dbacc, "`Tutorial` int(1) DEFAULT 1, ", strlen(dbacc));
    strins(dbacc, "`X` float DEFAULT 816.2747, ", strlen(dbacc));
    strins(dbacc, "`Y` float DEFAULT -1343.7556, ", strlen(dbacc));
    strins(dbacc, "`Z` float DEFAULT 13.5289, ", strlen(dbacc));
    strins(dbacc, "`A` float DEFAULT 1.8391, ", strlen(dbacc));
    strins(dbacc, "PRIMARY KEY (`ID`))", strlen(dbacc));
    mysql_query(IDConexao, dbacc, false);
    return 1;
}

hook OnGameModeExit()
{
    mysql_close(IDConexao);
	return 1;
}

forward LoadAccounts(playerid);
public LoadAccounts(playerid)
{
    if(PlayerInfo[playerid][Logado]) return 0;

    new tmp[128], query[100];

    if(AccountIsLoggedIn(playerid))
    {
        Kick(playerid);
        SendClientMessage(playerid, Erro, "Essa conta já está logado no servidor");
        return 1;
    }

    PlayerInfo[playerid][load] = true;

    cache_get_value_int(0, "ID", PlayerInfo[playerid][ID]);
    cache_get_value_name(0, "Nome", tmp); format(PlayerInfo[playerid][Nome], MAX_PLAYER_NAME, tmp);
    cache_get_value_name(0, "Senha", tmp); format(PlayerInfo[playerid][Senha], MAX_PLAYER_PASS, tmp);
    cache_get_value_name(0, "Email", tmp); format(PlayerInfo[playerid][Email], MAX_PLAYER_EMAIL, tmp);
    cache_get_value_name(0, "Code", tmp); format(PlayerInfo[playerid][Code], MAX_PLAYER_EMAIL, tmp);
    cache_get_value_int(0, "Tutorial", PlayerInfo[playerid][tutorial]);
    cache_get_value_float(0, "X", PlayerInfo[playerid][PosX]);
    cache_get_value_float(0, "Y", PlayerInfo[playerid][PosY]);
    cache_get_value_float(0, "Z", PlayerInfo[playerid][PosZ]);
    cache_get_value_float(0, "A", PlayerInfo[playerid][PosA]);

    mysql_format(IDConexao, query, 100, "SELECT * FROM `Ban` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);

    if(cache_num_rows())
        return DB_LoadBans(playerid);

    mysql_format(IDConexao, query, 100, "SELECT * FROM `Identidade` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadIdentidade", "d", playerid);

    mysql_format(IDConexao, query, 100, "SELECT * FROM `Prison` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadPrisons", "d", playerid);

    mysql_format(IDConexao, query, 100, "SELECT * FROM `Vips` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadVips", "d", playerid);

    mysql_format(IDConexao, query, 100, "SELECT * FROM `Itens` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadItens", "d", playerid);

    mysql_format(IDConexao, query, 100, "SELECT * FROM `Status` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadStatus", "d", playerid);

    mysql_format(IDConexao, query, 100, "SELECT * FROM `CNH` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadCnh", "d", playerid);

    mysql_format(IDConexao, query, 100, "SELECT * FROM `Bag` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadBag", "d", playerid);

    mysql_format(IDConexao, query, 100, "SELECT * FROM `Tags` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadTags", "d", playerid);

    mysql_format(IDConexao, query, 100, "SELECT * FROM `Timers` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "LoadTimers", "d", playerid);

    for(new slot = 0; slot < 10; slot++)
	{
        mysql_format(IDConexao, query, 100, "SELECT * FROM `Accessories` WHERE `slot`='%d' AND `id_contas`='%d'", slot, PlayerInfo[playerid][ID]);
        mysql_tquery(IDConexao, query, "DB_LoadAccessories", "dd", playerid, slot);
	}
    for(new slot = 0; slot < 10; slot++)
    {
        mysql_format(IDConexao, query, 100, "SELECT * FROM `Vehicles` WHERE `slot`='%d' AND `id_contas`='%d'", slot, PlayerInfo[playerid][ID]);
        mysql_tquery(IDConexao, query, "DB_LoadVehicles", "dd", playerid, slot);
    }

    PlayerInfo[playerid][load] = false;
    return 1;
}

forward SaveAccounts(playerid);
public SaveAccounts(playerid)
{
    if(!PlayerInfo[playerid][Logado] || PlayerInfo[playerid][tutorial]) return 0;

    new Query[400];
    mysql_format(IDConexao, Query, sizeof(Query), "UPDATE Contas SET `Nome`='%e', `Senha`='%e', `Email`='%e', `X`='%f', `Y`='%f', `Z`='%f', `A`='%f' WHERE `ID`='%d'",
    PlayerInfo[playerid][Nome],
    PlayerInfo[playerid][Senha],
    PlayerInfo[playerid][Email],
    PlayerInfo[playerid][PosX],
    PlayerInfo[playerid][PosY],
    PlayerInfo[playerid][PosZ],
    PlayerInfo[playerid][PosA],
    PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, Query);
    return 1;
}

forward RegisterAccounts(playerid);
public RegisterAccounts(playerid)
{
    if(PlayerInfo[playerid][Logado]) return 0;

    PlayerInfo[playerid][load] = true;
    PlayerInfo[playerid][ID] = cache_insert_id();
    PlayerInfo[playerid][Logado] = true;
    PlayerInfo[playerid][tutorial] = true;

    format(PlayerInfo[playerid][Nome], MAX_PLAYER_NAME, pPlayerInfo[playerid][pNome]);
    format(PlayerInfo[playerid][Senha], MAX_PLAYER_PASS, pPlayerInfo[playerid][pSenha]);
    format(PlayerInfo[playerid][Email], MAX_PLAYER_EMAIL, pPlayerInfo[playerid][pEmail]);

    PlayerInfo[playerid][PosX] = 816.2747;
    PlayerInfo[playerid][PosY] = -1343.7556;
    PlayerInfo[playerid][PosZ] = 13.5289;
    PlayerInfo[playerid][PosA] = 1.8391;

    SetColorProfession(playerid);

    new query[500];
    mysql_format(IDConexao, query, 500, "INSERT INTO `Vehicles` (`slot`, `model`, `x`, `y`, `z`, `a`, `devaluation`, `gasoline`, `id_contas`) VALUES ('%d', '%d', '%f', '%f', '%f', '%f', '%d', '%d', '%d')", 0, 510, 555.5782, -1285.4679, 18.3237, 0.0000, 720, 0, PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);

    mysql_format(IDConexao, query, 100, "SELECT * FROM `Ban` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);

    if(cache_num_rows())
        return DB_LoadBans(playerid);

    mysql_format(IDConexao, query, 100, "SELECT * FROM `Identidade` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadIdentidade", "d", playerid);

    mysql_format(IDConexao, query, 100, "SELECT * FROM `Prison` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadPrisons", "d", playerid);

    mysql_format(IDConexao, query, 100, "SELECT * FROM `Vips` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadVips", "d", playerid);

    mysql_format(IDConexao, query, 100, "SELECT * FROM `Itens` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadItens", "d", playerid);

    mysql_format(IDConexao, query, 100, "SELECT * FROM `Status` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadStatus", "d", playerid);

    mysql_format(IDConexao, query, 100, "SELECT * FROM `CNH` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadCnh", "d", playerid);

    mysql_format(IDConexao, query, 100, "SELECT * FROM `Bag` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadBag", "d", playerid);

    mysql_format(IDConexao, query, 100, "SELECT * FROM `Tags` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadTags", "d", playerid);

    mysql_format(IDConexao, query, 100, "SELECT * FROM `Timers` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "LoadTimers", "d", playerid);

    for(new slot = 0; slot < 10; slot++)
	{
        mysql_format(IDConexao, query, 100, "SELECT * FROM `Accessories` WHERE `slot`='%d' AND `id_contas`='%d'", slot, PlayerInfo[playerid][ID]);
        mysql_tquery(IDConexao, query, "DB_LoadAccessories", "dd", playerid, slot);
	}
    for(new slot = 0; slot < 10; slot++)
    {
        mysql_format(IDConexao, query, 100, "SELECT * FROM `Vehicles` WHERE `slot`='%d' AND `id_contas`='%d'", slot, PlayerInfo[playerid][ID]);
        mysql_tquery(IDConexao, query, "DB_LoadVehicles", "dd", playerid, slot);
    }

    SetSpawnInfo(playerid, 0, PlayerInfo[playerid][skin], PlayerInfo[playerid][PosX], PlayerInfo[playerid][PosY], PlayerInfo[playerid][PosZ], PlayerInfo[playerid][PosA], 0, 0, 0, 0, 0, 0);
    SetPlayerName(playerid, PlayerInfo[playerid][Nome]);
    SetPlayerScore(playerid, PlayerInfo[playerid][Level]);
    GivePlayerMoney(playerid, PlayerInfo[playerid][Dinheiro]);

    HideTextDrawRegister(playerid);
    CancelSelectTextDraw(playerid);
    StopAudioStreamForPlayer(playerid);

    SpawnHouse(playerid);
    SpawnPlayer(playerid);

    PlayerInfo[playerid][tutorial] = false;
    PlayerInfo[playerid][load] = false;
    return 1;
}

stock AccountIsLoggedIn(playerid)
{
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerConnected(playerid) && IsPlayerConnected(i))
        {
            if(PlayerInfo[playerid][Logado] == false && PlayerInfo[i][Logado] == true)
            {
                if(strcmp(pPlayerInfo[playerid][pNome], PlayerInfo[i][Nome], true)==0)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

stock UpdatePlayerProfission(playerid)
{
    new query[150];
    mysql_format(IDConexao, query, sizeof(query), "UPDATE `Identidade` SET `profissao`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][Profissao], PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);
    return 1;
}

stock UpdatePlayerMoney(playerid)
{
    new _str[100];
    mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Identidade` SET `dinheiro`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][Dinheiro], PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, _str);
    ResetPlayerMoney(playerid);
    GivePlayerMoney(playerid, PlayerInfo[playerid][Dinheiro]);
    return 1;
}

stock UpdatePlayerReais(playerid)
{
    new _str[100];
    mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Identidade` SET `reais`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][Reais], PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, _str);
    return 1;
}

stock UpdatePlayerLevel(playerid)
{
    new query[500];

    mysql_format(IDConexao, query, sizeof(query), "UPDATE `Identidade` SET `level`='%d', `experiencia`='%d', `minup`='%d', `segup`='%d' WHERE `id_contas`='%d'",
    PlayerInfo[playerid][Level],
    PlayerInfo[playerid][Exp],
    PlayerInfo[playerid][minUP],
    PlayerInfo[playerid][segUP],
    PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);
    return 1;
}
