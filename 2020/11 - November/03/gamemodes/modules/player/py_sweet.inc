#if EVENT_SWEET

#include YSI\y_hooks

#define TIME_RESET_SWEET    1800000
#define SWEET_TOP           100

hook OnGameModeInit()
{
    CreateDynamicObject(734, 789.77759, -1312.72900, 12.54677,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19320, 793.30701, -1321.61499, 18.73016,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(18728, 793.30701, -1321.61499, 18.73016,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19320, 800.02991, -1309.18909, 19.00318,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(18728, 800.02991, -1309.18909, 19.00318,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19320, 786.93689, -1319.13660, 18.62231,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(18728, 786.93689, -1319.13660, 18.62231,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19320, 782.37878, -1313.87292, 19.17520,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(18728, 782.37878, -1313.87292, 19.17520,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19320, 781.48053, -1319.92395, 31.66767,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(18728, 781.48053, -1319.92395, 31.66767,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19320, 798.79895, -1310.60120, 32.13224,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(18728, 798.79895, -1310.60120, 32.13224,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19320, 791.00415, -1311.10754, 28.30470,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(18728, 791.00415, -1311.10754, 28.30470,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19320, 795.97961, -1321.48096, 25.34774,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(18728, 795.97961, -1321.48096, 25.34774,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19320, 780.76306, -1312.65796, 26.66981,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(18728, 780.76306, -1312.65796, 26.66981,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19320, 797.71594, -1310.57605, 24.41475,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(18728, 797.71594, -1310.57605, 24.41475,   0.00000, 0.00000, 0.00000);
    CreateObject(19527, 787.01343, -1313.16321, 12.54032,   0.00000, 0.00000, 0.00000);
    CreateObject(19527, 788.62537, -1315.13977, 12.49193,   0.00000, 0.00000, 0.00000);
    CreateObject(19527, 790.65820, -1315.19739, 12.37370,   0.00000, 0.00000, 0.00000);
    CreateObject(19527, 792.13715, -1313.50610, 12.37187,   0.00000, 0.00000, 0.00000);
    CreateObject(19527, 791.45636, -1311.00146, 12.53980,   0.00000, 0.00000, 0.00000);
    CreateObject(19527, 789.30768, -1310.33655, 12.54725,   0.00000, 0.00000, 0.00000);
    CreateObject(19527, 787.70026, -1311.20178, 12.54831,   0.00000, 0.00000, 0.00000);
    return 1;
}

forward OnSweet(houseID);
public OnSweet(houseID)
{
    if(HouseInfo[houseID][hSweet]) return 0;

    HouseInfo[houseID][hSweet] = true;
    HouseInfo[houseID][hPumpkin] = CreateDynamicObject(19320, HouseInfo[houseID][iconx]+0.25, HouseInfo[houseID][icony]+0.25, HouseInfo[houseID][iconz]-0.80, 0.0, 0.0, 0.0, -1, -1, -1, 30.0, 30.0);
    return 1;
}

stock RandomValueSweet()
{
    new rand = random(5);

    return (rand < 1 ? ( RandomValueSweet() ) : ( rand ));
}

/******************************************************************************/
/*****************************| COMMANDS SWEETS |******************************/
/******************************************************************************/

CMD:pegardoce(playerid)
{
    for(new houseID = 0; houseID < MAX_HOUSES; houseID++)
    {
        if(IsPlayerInRangeOfPoint(playerid, 3.0, HouseInfo[houseID][iconx], HouseInfo[houseID][icony], HouseInfo[houseID][iconz]))
        {
            if(!HouseInfo[houseID][hSweet])
                return SendClientMessage(playerid, Erro, "Não tem doce nessa casa");

            HouseInfo[houseID][hSweet] = false;
            if(IsValidDynamicObject(HouseInfo[houseID][hPumpkin])) DestroyDynamicObject(HouseInfo[houseID][hPumpkin]);

            new sweet = RandomValueSweet();

            SetIntQuery(playerid, "Sweet", "sweets", (GetIntQuery(playerid, "Sweet", "sweets")+sweet));

            format(String, MAX_STRING, "Halloween ~ Você ganhou %d doce(s)", sweet);
            SendClientMessage(playerid, Orange, String);

            SetTimerEx("OnSweet", TIME_RESET_SWEET, false, "d", houseID);

            if(GetIntQuery(playerid, "Sweet", "sweets") >= SWEET_TOP)
            {
                new query[200];

                mysql_format(IDConexao, query, 200, "SELECT `model` FROM `Accessories` WHERE `model`='19528' AND `id_contas`='%d'", PlayerInfo[playerid][ID]);
                mysql_query(IDConexao, query);

                if(cache_num_rows()) return 0;

                for(new slot = 0; slot < MAX_ACCESSORIES; slot++)
                {
                    if(!ao[playerid][slot][ao_model])
                    {
                        InsertAccessory(playerid, slot, 19528, 1, 100000);
                        break;
                    }
                }

                format(String, MAX_STRING, "O(A) Jogador(a) %s alcançou %d doces e ganhou prêmio ( Chapéu de Bruxa )", PlayerInfo[playerid][Nome], SWEET_TOP);
                SendClientMessageToAll(Orange, String);
            }
            return 1;
        }
    }

    SendClientMessage(playerid, Erro, "Você não está perto de uma casa, chegue mais perto");
    return 1;
}

CMD:topdoces(playerid)
{
    new name[MAX_PLAYER_NAME], value, txt[2000];

    new Cache:result = mysql_query(IDConexao, "SELECT `Nome`, `Sweet`.`sweets` FROM `Contas` INNER JOIN `Sweet` ON (`Sweet`.`id_contas`=`Contas`.`id`) ORDER BY `Sweet`.`sweets` DESC LIMIT 10");

    strcat(txt, "{FFFFFF}Top\t {FFFFFF}Nome\t {FFFFFF}Doces\n");

    for(new row = 0; row < cache_num_rows(); row++)
    {
        cache_get_value_name(row, "Nome", name);
        cache_get_value_int(row, "sweets", value);

        format(String, 100, "{400080}%dº\t {FFFFFF}%s\t {FF8000}%d\n", (row + 1), name, value);
        strcat(txt, String);
    }

    cache_delete(result);
    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_TABLIST_HEADERS, "{FFFFFF}Top {FF8000}D{400080}o{FF8000}c{400080}e{FF8000}s", txt, "Fechar", #);
    return 1;
}

#endif
