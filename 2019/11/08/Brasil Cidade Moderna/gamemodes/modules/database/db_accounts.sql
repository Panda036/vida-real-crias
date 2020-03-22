#include YSI\y_hooks

new MySQL:IDConexao;

hook OnGameModeInit()
{
    IDConexao = mysql_connect("127.0.0.1", "root", "", "samp");
    //IDConexao = mysql_connect("127.0.0.1", "server_119", "wpjoas73xr", "server_119_bcm");

    new dbacc[1000];
    strins(dbacc,"CREATE TABLE IF NOT EXISTS Contas ", strlen(dbacc));
    strins(dbacc,"(ID int PRIMARY KEY AUTO_INCREMENT,", strlen(dbacc));
    strins(dbacc,"Nome varchar(24) NOT NULL,", strlen(dbacc));
    strins(dbacc,"Senha varchar(24) NOT NULL,", strlen(dbacc));
    strins(dbacc,"Email varchar(30) NOT NULL,", strlen(dbacc));
    strins(dbacc,"Profissao int(3) NOT NULL,", strlen(dbacc));
    strins(dbacc,"Admin int(1) NOT NULL,", strlen(dbacc));
    strins(dbacc,"minUP int(1) NOT NULL,", strlen(dbacc));
    strins(dbacc,"segUP int(2) NOT NULL,", strlen(dbacc));
    strins(dbacc,"Level int(20) NOT NULL,", strlen(dbacc));
    strins(dbacc,"Exp int(1) NOT NULL,", strlen(dbacc));
    strins(dbacc,"Reais int(20) NOT NULL,", strlen(dbacc));
    strins(dbacc,"Skin int(3) NOT NULL,", strlen(dbacc));
    strins(dbacc,"Aviso int(1) NOT NULL,", strlen(dbacc));
    strins(dbacc,"Estrelas int(10) NOT NULL,", strlen(dbacc));
    strins(dbacc,"Dinheiro int(20) NOT NULL,", strlen(dbacc));
    strins(dbacc,"SaldoBancario int(20) NOT NULL,", strlen(dbacc));
    strins(dbacc,"Matou int(10) NOT NULL,", strlen(dbacc));
    strins(dbacc,"Morreu int(10) NOT NULL,", strlen(dbacc));
    strins(dbacc,"Interior int(1) NOT NULL,", strlen(dbacc));
    strins(dbacc,"X float NOT NULL,", strlen(dbacc));
    strins(dbacc,"Y float NOT NULL,", strlen(dbacc));
    strins(dbacc,"Z float NOT NULL,", strlen(dbacc));
    strins(dbacc,"A float NOT NULL)", strlen(dbacc));
    mysql_query(IDConexao, dbacc, false);

    if(mysql_errno(IDConexao) != 0)
    {
        print(" =======================================");
        print(" |                                     |");
        print(" |           Banco de Dados            |");
        print(" |               Falhou                |");
        print(" |                                     |");
        print(" =======================================");
        SendRconCommand("exit");
    } else {
        print(" =======================================");
        print(" |                                     |");
        print(" |           Banco de Dados            |");
        print(" |        Conectado com sucesso        |");
        print(" |                                     |");
        print(" =======================================");
    }
    return 1;
}

hook OnGameModeExit()
{
    mysql_close(IDConexao);
	return 1;
}

forward LoadAccounts(playerid); public LoadAccounts(playerid)
{
    new tmp[128];
    DBLoadBan(playerid);

    if(BanidosEnum[playerid][bResponsavel] != 0) return 0;

    cache_get_value_int(0, "ID", PlayerInfo[playerid][ID]);
    cache_get_value_name(0, "Nome", tmp); format(PlayerInfo[playerid][Nome], MAX_PLAYER_NAME, tmp);
    cache_get_value_name(0, "Senha", tmp); format(PlayerInfo[playerid][Senha], MAX_PLAYER_PASS, tmp);
    cache_get_value_name(0, "Email", tmp); format(PlayerInfo[playerid][Email], MAX_PLAYER_EMAIL, tmp);
    cache_get_value_int(0, "Profissao", PlayerInfo[playerid][Profissao]);
    cache_get_value_int(0, "Admin", PlayerInfo[playerid][Admin]);
    cache_get_value_int(0, "minUP", PlayerInfo[playerid][minUP]);
    cache_get_value_int(0, "segUP", PlayerInfo[playerid][segUP]);
    cache_get_value_int(0, "Level", PlayerInfo[playerid][Level]);
    cache_get_value_int(0, "Exp", PlayerInfo[playerid][Exp]);
    cache_get_value_int(0, "Reais", PlayerInfo[playerid][Reais]);
    cache_get_value_int(0, "Skin", PlayerInfo[playerid][Skin]);
    cache_get_value_int(0, "Aviso", PlayerInfo[playerid][Avisos]);
    cache_get_value_int(0, "Estrelas", PlayerInfo[playerid][Estrelas]);
    cache_get_value_int(0, "Dinheiro", PlayerInfo[playerid][Dinheiro]);
    cache_get_value_int(0, "SaldoBancario", PlayerInfo[playerid][SaldoBancario]);
    cache_get_value_int(0, "Matou", PlayerInfo[playerid][Matou]);
    cache_get_value_int(0, "Morreu", PlayerInfo[playerid][Morreu]);
    cache_get_value_int(0, "Interior", PlayerInfo[playerid][Interior]);
    cache_get_value_float(0, "X", PlayerInfo[playerid][PosX]);
    cache_get_value_float(0, "Y", PlayerInfo[playerid][PosY]);
    cache_get_value_float(0, "Z", PlayerInfo[playerid][PosZ]);
    cache_get_value_float(0, "A", PlayerInfo[playerid][PosA]);

    SendClientMessage(playerid, Verde, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    format(String, sizeof(String), "» Logado com sucesso {008040}%s{FFFFFF}!", PlayerInfo[playerid][Nome]);
    SendClientMessage(playerid, Branco, String);
    SendClientMessage(playerid, Verde, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    TogglePlayerSpectating(playerid, false);
    PlayerInfo[playerid][Logado] = true;
    SetColorProfession(playerid);

    SetPlayerInterior(playerid, PlayerInfo[playerid][Interior]);
    SetPlayerName(playerid, PlayerInfo[playerid][Nome]);
    SetPlayerScore(playerid, PlayerInfo[playerid][Level]);
    GivePlayerMoney(playerid, PlayerInfo[playerid][Dinheiro]);
    SetSpawnInfo(playerid,0,PlayerInfo[playerid][Skin],PlayerInfo[playerid][PosX],PlayerInfo[playerid][PosY],PlayerInfo[playerid][PosZ],0,0,0,0,0,0,0);
    HideTextDrawLogin(playerid);

    SpawnPlayer(playerid);

    //Banco dedos
    DBLoadVip(playerid);
    DBLoadPrison(playerid);
    return 1;
}

forward SaveAccounts(playerid); public SaveAccounts(playerid)
{
    if(PlayerInfo[playerid][Logado] == false) return 0;

    PlayerInfo[playerid][Interior] = GetPlayerInterior(playerid);
    GetPlayerFacingAngle(playerid, PlayerInfo[playerid][PosA]);
    GetPlayerPos(playerid, PlayerInfo[playerid][PosX],
    PlayerInfo[playerid][PosY],PlayerInfo[playerid][PosZ]);

    new Query[500];
    mysql_format(IDConexao, Query, sizeof(Query), "UPDATE Contas SET Profissao=%i, Admin=%i, minUP=%i, segUP=%i, Level=%i, Exp=%i, Reais=%i, Skin=%i, Aviso=%i, Estrelas=%i, Dinheiro=%i, SaldoBancario=%i, Matou=%i, Morreu=%i, Interior=%i, X=%f, Y=%f, Z=%f, A=%f WHERE Nome='%e'",
    PlayerInfo[playerid][Profissao],
    PlayerInfo[playerid][Admin],
    PlayerInfo[playerid][minUP],
    PlayerInfo[playerid][segUP],
    PlayerInfo[playerid][Level],
    PlayerInfo[playerid][Exp],
    PlayerInfo[playerid][Reais],
    PlayerInfo[playerid][Skin],
    PlayerInfo[playerid][Avisos],
    PlayerInfo[playerid][Estrelas],
    PlayerInfo[playerid][Dinheiro],
    PlayerInfo[playerid][SaldoBancario],
    PlayerInfo[playerid][Matou],
    PlayerInfo[playerid][Morreu],
    PlayerInfo[playerid][Interior],
    PlayerInfo[playerid][PosX],
    PlayerInfo[playerid][PosY],
    PlayerInfo[playerid][PosZ],
    PlayerInfo[playerid][PosA],
    PlayerInfo[playerid][Nome]);
    mysql_query(IDConexao, Query);
    return 1;
}

forward RegisterAccounts(playerid); public RegisterAccounts(playerid)
{
    PlayerInfo[playerid][ID] = cache_insert_id();
    PlayerInfo[playerid][Skin] = 29;
    PlayerInfo[playerid][Logado] = true;
    format(PlayerInfo[playerid][Nome], MAX_PLAYER_NAME, pPlayerInfo[playerid][pNome]);
    format(PlayerInfo[playerid][Senha], MAX_PLAYER_PASS, pPlayerInfo[playerid][pSenha]);
    format(PlayerInfo[playerid][Email], MAX_PLAYER_EMAIL, pPlayerInfo[playerid][pEmail]);

    TogglePlayerSpectating(playerid, false);
    SetColorProfession(playerid);

    SetSpawnInfo(playerid, 0, PlayerInfo[playerid][Skin], 816.2747, -1343.7556, 13.5289, 1.8391, 0, 0, 0, 0, 0, 0);
    SetPlayerName(playerid, PlayerInfo[playerid][Nome]);
    SetPlayerScore(playerid, PlayerInfo[playerid][Level]);
    GivePlayerMoney(playerid, PlayerInfo[playerid][Dinheiro]);
    HideTextDrawRegister(playerid);
    SpawnPlayer(playerid);
    return 1;
}
