#include YSI\y_hooks

hook OnGameModeInit()
{
    #if SERVER_OFFLINE
        IDConexao = mysql_connect("127.0.0.1", "root", "", "samp");
    #else
        IDConexao = mysql_connect("198.50.187.244", "henriquec_4226", "5GV5Q2CCg8", "henriquec_4226");
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

    new tmp[128], query[200];

    if(AccountIsLoggedIn(playerid))
    {
        Kick(playerid);
        SendClientMessage(playerid, Erro, "Essa conta já está logado no servidor");
        return 1;
    }

    PlayerInfo[playerid][load] = true;
    PlayerInfo[playerid][Logado] = true;
    CancelSelectTextDraw(playerid);
    HideTextDrawLogin(playerid);

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

    mysql_format(IDConexao, query, 200, "SELECT * FROM `Ban` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);

    if(cache_num_rows())
        return DB_LoadBans(playerid);

    mysql_format(IDConexao, query, 200, "SELECT * FROM `Identidade` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadIdentidade", "d", playerid);

    mysql_format(IDConexao, query, 200, "SELECT * FROM `Prison` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadPrisons", "d", playerid);

    mysql_format(IDConexao, query, 200, "SELECT * FROM `Vips` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadVips", "d", playerid);

    mysql_format(IDConexao, query, 200, "SELECT * FROM `Itens` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadItens", "d", playerid);

    mysql_format(IDConexao, query, 200, "SELECT * FROM `Status` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadStatus", "d", playerid);

    mysql_format(IDConexao, query, 200, "SELECT * FROM `Status` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadHud", "d", playerid);

    mysql_format(IDConexao, query, 200, "SELECT * FROM `CNH` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadCnh", "d", playerid);

    mysql_format(IDConexao, query, 200, "SELECT * FROM `Bag` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadBag", "d", playerid);

    mysql_format(IDConexao, query, 200, "SELECT * FROM `Tags` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadTags", "d", playerid);

    mysql_format(IDConexao, query, 200, "SELECT * FROM `Timers` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadTimers", "d", playerid);

    mysql_format(IDConexao, query, 200, "SELECT * FROM `WeaponProducer` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadWP", "d", playerid);

    #if EVENT_GIFT
        mysql_format(IDConexao, query, 200, "SELECT * FROM `Gift` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
        mysql_tquery(IDConexao, query, "DB_LoadGift", "d", playerid);
    #endif

    #if EVENT_SWEET
        mysql_format(IDConexao, query, 200, "SELECT * FROM `Sweet` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
        mysql_tquery(IDConexao, query, "DB_LoadSweet", "d", playerid);
    #endif

    mysql_format(IDConexao, query, 200, "SELECT * FROM `Accessories` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadAccessories", "d", playerid);

    mysql_format(IDConexao, query, 200, "SELECT * FROM `Vehicles` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadVehicles", "d", playerid);

    #if !SERVER_OFFLINE
        format(String, MAX_STRING, "**%s** entrou no servidor!", PlayerInfo[playerid][Nome]);
        DCC_SendChannelMessage(Channels[dsc_geral], String);
    #endif

    PlayerInfo[playerid][load] = false;
    return 1;
}

stock SavePos(playerid)
{
    if(!PlayerInfo[playerid][Logado] || PlayerInfo[playerid][tutorial]) return 0;

    new query[300];
    mysql_format(IDConexao, query, 300, "UPDATE Contas SET `X`='%f', `Y`='%f', `Z`='%f', `A`='%f' WHERE `ID`='%d'",
    PlayerInfo[playerid][PosX],
    PlayerInfo[playerid][PosY],
    PlayerInfo[playerid][PosZ],
    PlayerInfo[playerid][PosA],
    PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);
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

    new query[200];
    mysql_format(IDConexao, query, 200, "SELECT * FROM `Ban` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);

    if(cache_num_rows())
        return DB_LoadBans(playerid);

    mysql_format(IDConexao, query, 200, "SELECT * FROM `Identidade` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadIdentidade", "d", playerid);

    mysql_format(IDConexao, query, 200, "SELECT * FROM `Prison` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadPrisons", "d", playerid);

    mysql_format(IDConexao, query, 200, "SELECT * FROM `Vips` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadVips", "d", playerid);

    mysql_format(IDConexao, query, 200, "SELECT * FROM `Itens` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadItens", "d", playerid);

    mysql_format(IDConexao, query, 200, "SELECT * FROM `Status` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadStatus", "d", playerid);

    mysql_format(IDConexao, query, 200, "SELECT * FROM `Status` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadHud", "d", playerid);

    mysql_format(IDConexao, query, 200, "SELECT * FROM `CNH` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadCnh", "d", playerid);

    mysql_format(IDConexao, query, 200, "SELECT * FROM `Bag` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadBag", "d", playerid);

    mysql_format(IDConexao, query, 200, "SELECT * FROM `Tags` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadTags", "d", playerid);

    mysql_format(IDConexao, query, 200, "SELECT * FROM `Timers` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadTimers", "d", playerid);

    mysql_format(IDConexao, query, 200, "SELECT * FROM `WeaponProducer` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadWP", "d", playerid);

    #if EVENT_GIFT
        mysql_format(IDConexao, query, 200, "SELECT * FROM `Gift` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
        mysql_tquery(IDConexao, query, "DB_LoadGift", "d", playerid);
    #endif

    #if EVENT_SWEET
        mysql_format(IDConexao, query, 200, "SELECT * FROM `Sweet` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
        mysql_tquery(IDConexao, query, "DB_LoadSweet", "d", playerid);
    #endif

    mysql_format(IDConexao, query, 200, "SELECT * FROM `Accessories` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadAccessories", "d", playerid);

    mysql_format(IDConexao, query, 200, "SELECT * FROM `Vehicles` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query, "DB_LoadVehicles", "d", playerid);

    SetSpawnInfo(playerid, 0, PlayerInfo[playerid][skin], PlayerInfo[playerid][PosX], PlayerInfo[playerid][PosY], PlayerInfo[playerid][PosZ], PlayerInfo[playerid][PosA], 0, 0, 0, 0, 0, 0);
    SetPlayerName(playerid, PlayerInfo[playerid][Nome]);
    SetPlayerScore(playerid, PlayerInfo[playerid][Level]);
    GivePlayerMoney(playerid, PlayerInfo[playerid][Dinheiro]);

    HideTextDrawRegister(playerid);
    CancelSelectTextDraw(playerid);
    SetColorProfession(playerid);

    SpawnHouse(playerid);
    SpawnPlayer(playerid);

    PlayerInfo[playerid][tutorial] = false;
    PlayerInfo[playerid][load] = false;
    return 1;
}
