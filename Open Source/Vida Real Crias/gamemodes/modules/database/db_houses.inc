#include YSI\y_hooks

hook OnGameModeInit()
{
    new dbhouse[1000];
    strins(dbhouse,"CREATE TABLE IF NOT EXISTS `Houses` ", strlen(dbhouse));
    strins(dbhouse,"(ID int PRIMARY KEY AUTO_INCREMENT,", strlen(dbhouse));
    strins(dbhouse,"Nome varchar(24) NOT NULL DEFAULT 'N/A',", strlen(dbhouse));
    strins(dbhouse,"M1 varchar(24) NOT NULL DEFAULT 'N/A',", strlen(dbhouse));
    strins(dbhouse,"M2 varchar(24) NOT NULL DEFAULT 'N/A',", strlen(dbhouse));
    strins(dbhouse,"M3 varchar(24) NOT NULL DEFAULT 'N/A',", strlen(dbhouse));
    strins(dbhouse,"M4 varchar(24) NOT NULL DEFAULT 'N/A',", strlen(dbhouse));
    strins(dbhouse,"M5 varchar(24) NOT NULL DEFAULT 'N/A',", strlen(dbhouse));
    strins(dbhouse,"M6 varchar(24) NOT NULL DEFAULT 'N/A',", strlen(dbhouse));
    strins(dbhouse,"Mensagem varchar(80) NOT NULL DEFAULT 'N/A',", strlen(dbhouse));
    strins(dbhouse,"Alugando varchar(3) NOT NULL DEFAULT 'N/A',", strlen(dbhouse));
    strins(dbhouse,"Vendendo varchar(3) NOT NULL DEFAULT 'Sim',", strlen(dbhouse));
    strins(dbhouse,"Up int(2) NOT NULL DEFAULT 1,", strlen(dbhouse));
    strins(dbhouse,"UpMax int(2) NOT NULL,", strlen(dbhouse));
    strins(dbhouse,"Preco int(10) NOT NULL,", strlen(dbhouse));
    strins(dbhouse,"Custo int(10) NOT NULL,", strlen(dbhouse));
    strins(dbhouse,"Padrao int(10) NOT NULL,", strlen(dbhouse));
    strins(dbhouse,"Reais int(10) NOT NULL DEFAULT 0,", strlen(dbhouse));
    strins(dbhouse,"Cofre int(11) NOT NULL,", strlen(dbhouse));
    strins(dbhouse,"Interior int(5) NOT NULL,", strlen(dbhouse));
    strins(dbhouse,"IPTU int(2) NOT NULL,", strlen(dbhouse));
    strins(dbhouse,"Trancada varchar(3) NOT NULL DEFAULT 'N/A',", strlen(dbhouse));
    strins(dbhouse,"Senha varchar(24) NOT NULL DEFAULT 'N/A',", strlen(dbhouse));
    strins(dbhouse,"X float NOT NULL,", strlen(dbhouse));
    strins(dbhouse,"Y float NOT NULL,", strlen(dbhouse));
    strins(dbhouse,"Z float NOT NULL )", strlen(dbhouse));
    mysql_query(IDConexao, dbhouse, false);

    new query[100];
    for(new i = 1; i < MAX_HOUSES; ++i)
    {
        mysql_format(IDConexao, query, sizeof(query), "SELECT * FROM `Houses` WHERE `ID`='%d'", i);
        mysql_tquery(IDConexao, query, "LoadHouses", "d", i);
    }
    return 1;
}

forward LoadHouses(idhouse);
public LoadHouses(idhouse)
{
    if(cache_num_rows() != 0)
    {
        new var[128];

        cache_get_value_int(0, "ID", HouseInfo[idhouse][hID]);

        cache_get_value_name(0, "Nome", var);
        format(HouseInfo[idhouse][hNome], MAX_PLAYER_NAME, var);

        cache_get_value_name(0, "M1", var);
        format(HouseInfo[idhouse][hM1], MAX_PLAYER_NAME, var);

        cache_get_value_name(0, "M2", var);
        format(HouseInfo[idhouse][hM2], MAX_PLAYER_NAME, var);

        cache_get_value_name(0, "M3", var);
        format(HouseInfo[idhouse][hM3], MAX_PLAYER_NAME, var);

        cache_get_value_name(0, "M4", var);
        format(HouseInfo[idhouse][hM4], MAX_PLAYER_NAME, var);

        cache_get_value_name(0, "M5", var);
        format(HouseInfo[idhouse][hM5], MAX_PLAYER_NAME, var);

        cache_get_value_name(0, "M6", var);
        format(HouseInfo[idhouse][hM6], MAX_PLAYER_NAME, var);

        cache_get_value_name(0, "Mensagem", var);
        format(HouseInfo[idhouse][hMensagem], 30, var);

        cache_get_value_name(0, "Alugando", var);
        format(HouseInfo[idhouse][hAlugando], 5, var);

        cache_get_value_name(0, "Vendendo", var);
        format(HouseInfo[idhouse][hVendendo], 5, var);

        cache_get_value_int(0, "Up", HouseInfo[idhouse][hUp]);
        cache_get_value_int(0, "UpMax", HouseInfo[idhouse][hUpMax]);
        cache_get_value_int(0, "Preco", HouseInfo[idhouse][hPreco]);
        cache_get_value_int(0, "Custo", HouseInfo[idhouse][hCusto]);
        cache_get_value_int(0, "Padrao", HouseInfo[idhouse][hPadrao]);
        cache_get_value_int(0, "Reais", HouseInfo[idhouse][hReais]);
        cache_get_value_int(0, "Cofre", HouseInfo[idhouse][hCofre]);
        cache_get_value_int(0, "Interior", HouseInfo[idhouse][hInterior]);

        cache_get_value_name(0, "Trancada", var);
        format(HouseInfo[idhouse][hTrancada], 5, var);

        cache_get_value_name(0, "Senha", var);
        format(HouseInfo[idhouse][hSenha], 24, var);

        cache_get_value_float(0, "X", HouseInfo[idhouse][iconx]);
        cache_get_value_float(0, "Y", HouseInfo[idhouse][icony]);
        cache_get_value_float(0, "Z", HouseInfo[idhouse][iconz]);

        CreateHouseExternal(idhouse);
        UpgradeHouse(idhouse);
        #if EVENT_SWEET
            OnSweet(idhouse);
        #endif
    }
    return 1;
}

stock UpdateHouses(idhouse)
{
    new query[3000];
    mysql_format(IDConexao, query, sizeof(query), "UPDATE `Houses` SET `Nome`='%e', `M1`='%e', `M2`='%e', `M3`='%e', `M4`='%e', `M5`='%e', `M6`='%e', `Mensagem`='%e', `Alugando`='%e', `Vendendo`='%e', `Up`='%d', `UpMax`='%d', `Preco`='%d', `Custo`='%d', `Padrao`='%d', `Reais`='%d', `Cofre`='%d', `Interior`='%d', `Trancada`='%e', `Senha`='%e', `X`='%f', `Y`='%f', `Z`='%f' WHERE `ID`='%d'",
    HouseInfo[idhouse][hNome],
    HouseInfo[idhouse][hM1],
    HouseInfo[idhouse][hM2],
    HouseInfo[idhouse][hM3],
    HouseInfo[idhouse][hM4],
    HouseInfo[idhouse][hM5],
    HouseInfo[idhouse][hM6],
    HouseInfo[idhouse][hMensagem],
    HouseInfo[idhouse][hAlugando],
    HouseInfo[idhouse][hVendendo],
    HouseInfo[idhouse][hUp],
    HouseInfo[idhouse][hUpMax],
    HouseInfo[idhouse][hPreco],
    HouseInfo[idhouse][hCusto],
    HouseInfo[idhouse][hPadrao],
    HouseInfo[idhouse][hReais],
    HouseInfo[idhouse][hCofre],
    HouseInfo[idhouse][hInterior],
    HouseInfo[idhouse][hTrancada],
    HouseInfo[idhouse][hSenha],
    HouseInfo[idhouse][iconx],
    HouseInfo[idhouse][icony],
    HouseInfo[idhouse][iconz],
    HouseInfo[idhouse][hID]);
    mysql_query(IDConexao, query);
    return 1;
}
