#include YSI\y_hooks

new cp_merchandise;

hook OnGameModeInit()
{
    cp_merchandise = CreateDynamicCP(-2433.96, 2313.70, 4.98, 1.0, -1, -1, -1, 30.0);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    SetTimerEx("OnPlayerMerchandise", 5000, true, "d", playerid);
    return 1;
}

hook OnPlayerEnterCheckpoint(playerid)
{
    if(IsPlayerInDynamicCP(playerid, cp_merchandise))
    {
        SendClientMessage(playerid, C_PROPERTY, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        SendClientMessage(playerid, 0xFFFFFFAA, "Para poder pegar mercadoria... ");
        SendClientMessage(playerid, 0xFFFFFFAA, "Digite: /PegarMercadoria");
        SendClientMessage(playerid, C_PROPERTY, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        return 1;
    }
	return 1;
}

forward OnPlayerMerchandise(playerid);
public OnPlayerMerchandise(playerid)
{
    if(!PlayerInfo[playerid][Logado]) return 0;

    if(IsPlayerInRangeOfPoint(playerid, 10.0, -2433.96, 2313.70, 4.98))
    {
        if(merchandise)
            format(String, 100, "~w~Mercadorias Bayside: ~g~%d", merchandise);
        else
            format(String, 100, "~w~Mercadorias Bayside: ~r~%d", merchandise);

        PlayerTextDrawSetString(playerid, CarregandoInterior[playerid], String);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
    }
    else
    {
        PlayerTextDrawHide(playerid, CarregandoInterior[playerid]);
    }
    return 1;
}

stock UpdadeMerchandise()
{
    new query[100];
    mysql_format(IDConexao, query, 100, "UPDATE `Server` SET `merchandise`='%d' WHERE `id`=1", merchandise);
    mysql_query(IDConexao, query);
    return 1;
}

/******************************************************************************/
/***************************| COMMANDS MARCHANDISE |***************************/
/******************************************************************************/

CMD:pegarmercadoria(playerid)
{
    if(!IsPlayerInDynamicCP(playerid, cp_merchandise))
        return SendClientMessage(playerid, Erro, "Você não está em bayside");

    new _str[500];
    mysql_format(IDConexao, _str, sizeof(_str), "SELECT `Nome` OR `Func1` OR `Func2` OR `Func3` OR `Func4` FROM `Business` WHERE `Nome`='%e' OR `Func1`='%e' OR `Func2`='%e' OR `Func3`='%e' OR `Func4`='%e'", PlayerInfo[playerid][Nome], PlayerInfo[playerid][Nome], PlayerInfo[playerid][Nome], PlayerInfo[playerid][Nome], PlayerInfo[playerid][Nome]);
    mysql_query(IDConexao, _str);

    if(cache_num_rows() == 0)
        return SendClientMessage(playerid, Erro, "Você não é dono(a)/funcionário(a) de uma empresa");

    if(EntregouMercadoria[playerid] == true)
        return SendClientMessage(playerid, Erro, "Você já entregou mercadoria nesse level");

    if(Mercadoria[playerid] == true)
        return SendClientMessage(playerid, Erro, "Você já tem uma mercadoria");

    if(!merchandise)
        return SendClientMessage(playerid, Erro, "Não tem mercadoria no momento");

    merchandise--;
    UpdadeMerchandise();
    Mercadoria[playerid] = true;
    SendClientMessage(playerid, C_PROPERTY, "Você pegou uma mercadoria, vá até a sua empresa para entregar");
    return 1;
}
