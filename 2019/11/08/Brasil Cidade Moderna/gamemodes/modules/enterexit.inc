#include YSI\y_hooks

new Entrando[MAX_PLAYERS]=0;
new PlayerText:CarregandoInterior[MAX_PLAYERS];

hook OnPlayerConnect(playerid)
{
    CarregandoInterior[playerid] = CreatePlayerTextDraw(playerid, 252.800033, 399.066589, "Carregando_Interior...");
    PlayerTextDrawLetterSize(playerid, CarregandoInterior[playerid], 0.400000, 1.600000);
    PlayerTextDrawAlignment(playerid, CarregandoInterior[playerid], 1);
    PlayerTextDrawColor(playerid, CarregandoInterior[playerid], -1);
    PlayerTextDrawSetShadow(playerid, CarregandoInterior[playerid], 0);
    PlayerTextDrawSetOutline(playerid, CarregandoInterior[playerid], -1);
    PlayerTextDrawBackgroundColor(playerid, CarregandoInterior[playerid], 255);
    PlayerTextDrawFont(playerid, CarregandoInterior[playerid], 1);
    PlayerTextDrawSetProportional(playerid, CarregandoInterior[playerid], 1);
    PlayerTextDrawSetShadow(playerid, CarregandoInterior[playerid], 0);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_SECONDARY_ATTACK)
    {
        if(Entrando[playerid] == 0)
        {
            EntrarInterior(playerid);
        }
        else if(Entrando[playerid] > 0 && Entrando[playerid] < 10)
        {
            SairInterior(playerid);
        }
        return 1;
    }
	return 1;
}

hook OnPlayerDisconnect(playerid)
{
    Entrando[playerid] = 0;
    return 1;
}

EntrarInterior(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1154.0808,-1771.9812,16.5992)) //Agencia LS
    {
        Entrando[playerid] = 1;
        SetPlayerPos(playerid,1494.4989,1303.6678,1093.2964);
        SetPlayerFacingAngle(playerid, 359.9018);
        SetPlayerInterior(playerid, 3);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar na Agencia de Empregos de Los Santos!");
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 937.8450,1733.1957,8.8516))    //Agencia LV
    {
        Entrando[playerid] = 2;
        SetPlayerPos(playerid,1494.4989,1303.6678,1093.2964);
        SetPlayerFacingAngle(playerid, 359.9018);
        SetPlayerInterior(playerid, 3);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar na Agencia de Empregos de Las Venturas!");
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -2171.8110,252.0813,35.3378))  //Agencia SF
    {
        Entrando[playerid] = 3;
        SetPlayerPos(playerid,1494.4989,1303.6678,1093.2964);
        SetPlayerFacingAngle(playerid, 359.9018);
        SetPlayerInterior(playerid, 3);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar na Agencia de Empregos de San Fierro!");
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1481.0637,-1770.9515,18.7958)) //Prefeitura LS
    {
        Entrando[playerid] = 1;
        SetPlayerInterior(playerid, 3);
        SetPlayerPos(playerid, 389.3904,173.8544,1008.3828);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar na Prefeitura de Los Santos!");
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2447.0620,2376.2354,12.1635))  //Prefeitura LV
    {
        Entrando[playerid] = 2;
        SetPlayerInterior(playerid, 3);
        SetPlayerPos(playerid, 389.3904,173.8544,1008.3828);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar na Prefeitura de Las Venturas!");
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -2765.8796,375.5812,6.3347))   //Prefeitura SF
    {
        Entrando[playerid] = 3;
        SetPlayerInterior(playerid, 3);
        SetPlayerPos(playerid, 389.3904,173.8544,1008.3828);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar na Prefeitura de San Fierro!");
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1554.8657,-1675.6693,16.1953)) // Departamento LS
    {
        Entrando[playerid] = 1;
        SetPlayerInterior(playerid, 6);
        SetPlayerPos(playerid, 246.8748,63.0608,1003.6406);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar no Departamento de Polícia de Los Santos!");
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2290.1218,2430.9775,10.8203))  // Departamento LV
    {
        Entrando[playerid] = 2;
        SetPlayerInterior(playerid, 6);
        SetPlayerPos(playerid, 246.8748,63.0608,1003.6406);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar no Departamento de Polícia de Las Venturas!");
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -1605.5848,710.8436,13.8672))  // Departamento SF
    {
        Entrando[playerid] = 3;
        SetPlayerInterior(playerid, 6);
        SetPlayerPos(playerid, 246.8748,63.0608,1003.6406);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar no Departamento de Polícia de San Fierro!");
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 627.7621,-571.7207,17.5526))  // Departamento DM
    {
        Entrando[playerid] = 4;
        SetPlayerInterior(playerid, 6);
        SetPlayerPos(playerid, 246.8748,63.0608,1003.6406);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar no Departamento de Polícia de Dillimore!");
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1172.6787,-1323.3129,15.4022)) // Hospital LS
    {
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar no Hospital de Los Santos!");
        Entrando[playerid] = 1;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, false);
        SetPlayerPos(playerid, 1104.6949,1515.8959,4452.8071);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("LoadInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1607.3579,1815.6309,10.8203))  // Hospital LV
    {
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar no Hospital de Las Venturas!");
        Entrando[playerid] = 2;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, false);
        SetPlayerPos(playerid, 1104.6949,1515.8959,4452.8071);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("LoadInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -2655.0662,639.1497,14.4531))  // Hospital SF
    {
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar no Hospital de San Fierro!");
        Entrando[playerid] = 3;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, false);
        SetPlayerPos(playerid, 1104.6949,1515.8959,4452.8071);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("LoadInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -1514.8217,2520.3232,55.9185))  // Hospital EL
    {
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar no Hospital de El Quebrados!");
        Entrando[playerid] = 4;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, false);
        SetPlayerPos(playerid, 1104.6949,1515.8959,4452.8071);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("LoadInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1241.8073,327.1022,19.7555))  // Hospital MG
    {
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar no Hospital de Montgomery!");
        Entrando[playerid] = 5;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, false);
        SetPlayerPos(playerid, 1104.6949,1515.8959,4452.8071);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("LoadInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -320.0716,1049.2637,20.3403))  // Hospital FC
    {
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar no Hospital de Fort Carson!");
        Entrando[playerid] = 6;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 1104.6949,1515.8959,4452.8071);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("LoadInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -2223.1670,-2293.6865,31.6719))  // Hospital AP
    {
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar no Hospital de Angel Pine!");
        Entrando[playerid] = 7;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 1104.6949,1515.8959,4452.8071);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("LoadInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1778.3052,-1663.5337,14.4362)) // Banco LS
    {
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar no Banco de Los Santos!");
        Entrando[playerid] = 1;
        SetPlayerInterior(playerid, 0);
        SetPlayerPos(playerid, 2315.952880,-1.618174,26.742187);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2388.6733,2466.0430,10.8203))  // Banco LV
    {
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar no Banco de Las Venturas!");
        Entrando[playerid] = 2;
        SetPlayerInterior(playerid, 0);
        SetPlayerPos(playerid, 2315.952880,-1.618174,26.742187);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -2649.8374,376.0090,6.1563))   // Banco SF
    {
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar no Banco de San Fierro!");
        Entrando[playerid] = 3;
        SetPlayerInterior(playerid, 0);
        SetPlayerPos(playerid, 2315.952880,-1.618174,26.742187);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -180.3883,1133.1510,19.7422))  // Banco FC
    {
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar no Banco de Fort Carson!");
        Entrando[playerid] = 4;
        SetPlayerInterior(playerid, 0);
        SetPlayerPos(playerid, 2315.952880,-1.618174,26.742187);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1372.9271,405.2487,19.9555))   // Banco MG
    {
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar no Banco de Montgomery!");
        Entrando[playerid] = 5;
        SetPlayerInterior(playerid, 0);
        SetPlayerPos(playerid, 2315.952880,-1.618174,26.742187);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2302.9521,-16.2789,26.4844))   // Banco PC
    {
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar no Banco de Fort Carson!");
        Entrando[playerid] = 6;
        SetPlayerInterior(playerid, 0);
        SetPlayerPos(playerid, 2315.952880,-1.618174,26.742187);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -828.0650,1503.6166,19.7585))  // Banco LB
    {
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar no Banco de Las Barrancas!");
        Entrando[playerid] = 7;
        SetPlayerInterior(playerid, 0);
        SetPlayerPos(playerid, 2315.952880,-1.618174,26.742187);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -1480.8273,2592.3015,55.8359)) // Banco EQ
    {
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar no Banco de El Quebrados!");
        Entrando[playerid] = 8;
        SetPlayerInterior(playerid, 0);
        SetPlayerPos(playerid, 2315.952880,-1.618174,26.742187);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 207.7767,-62.5814,1.6498))     // Banco BB
    {
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar no Banco de BlueBerry!");
        Entrando[playerid] = 9;
        SetPlayerInterior(playerid, 0);
        SetPlayerPos(playerid, 2315.952880,-1.618174,26.742187);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1798.4763,-1578.3191,14.0849)) // Imobiliaria LS
    {
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar na Imobiliaria de Los Santos!");
        Entrando[playerid] = 1;
        SetPlayerInterior(playerid, 3);
        //SetPlayerPos(playerid, 1038.531372,0.111030,1001.284484);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2413.2390,1123.8374,10.8203))  // Imobiliaria LV
    {
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar na Imobiliaria de Las Venturas!");
        Entrando[playerid] = 2;
        SetPlayerInterior(playerid, 3);
        //SetPlayerPos(playerid, 1038.531372,0.111030,1001.284484);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -1881.1293,822.7573,35.1773))  // Imobiliaria SF
    {
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar na Imobiliaria de San Fierro!");
        Entrando[playerid] = 3;
        SetPlayerInterior(playerid, 3);
        //SetPlayerPos(playerid, 1038.531372,0.111030,1001.284484);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1519.0413,-1453.5895,14.2073)) // Auto Escola LS
    {
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar na Auto Escola de Los Santos!");
        Entrando[playerid] = 1;
        SetPlayerInterior(playerid, 3);
        SetPlayerPos(playerid, -2029.798339,-106.675910,1035.171875);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2183.2483,2295.2205,10.8203))  // Auto Escola LV
    {
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar na Auto Escola de Las Venturas!");
        Entrando[playerid] = 2;
        SetPlayerInterior(playerid, 3);
        SetPlayerPos(playerid, -2029.798339,-106.675910,1035.171875);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -2026.5950,-101.3410,35.1641)) // Auto Escola SF
    {
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar na Auto Escola de San Fierro!");
        Entrando[playerid] = 3;
        SetPlayerInterior(playerid, 3);
        SetPlayerPos(playerid, -2029.798339,-106.675910,1035.171875);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1310.1411,-1367.8086,13.5408)) // Detran LS
    {
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar no Detran de Los Santos!");
        Entrando[playerid] = 1;
        SetPlayerInterior(playerid, 3);
        SetPlayerPos(playerid, 833.269775,10.588416,1004.179687);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1173.1600,1349.0011,10.9219))  // Detran LV
    {
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar no Detran de Las Venturas!");
        Entrando[playerid] = 2;
        SetPlayerInterior(playerid, 3);
        SetPlayerPos(playerid, 833.269775,10.588416,1004.179687);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -2720.6375,127.7373,7.0391))   // Detran SF
    {
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar no Detran de San Fierro!");
        Entrando[playerid] = 3;
        SetPlayerInterior(playerid, 3);
        SetPlayerPos(playerid, 833.269775,10.588416,1004.179687);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1022.4510,-1121.5958,23.8719)) // Area VIP LS
    {
        if(!IsPlayerVip(playerid))
            return SendClientMessage(playerid, -1, "{FF4000}| ERRO | Você não tem permissão!");

        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar na Área VIP de Los Santos!");
        Entrando[playerid] = 1;
        SetPlayerInterior(playerid, 1);
        SetPlayerPos(playerid, -794.8354,495.9334,1376.1953);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2015.0763,1106.6337,10.8203))  // Area VIP LV
    {
        if(!IsPlayerVip(playerid))
            return SendClientMessage(playerid, -1, "{FF4000}| ERRO | Você não tem permissão!");

        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar na Área VIP de Las Venturas!");
        Entrando[playerid] = 2;
        SetPlayerInterior(playerid, 1);
        SetPlayerPos(playerid, -794.8354,495.9334,1376.1953);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -2664.4136,-7.4449,6.1328))   // Area VIP SF
    {
        if(!IsPlayerVip(playerid))
            return SendClientMessage(playerid, -1, "{FF4000}| ERRO | Você não tem permissão!");

        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de entrar na Área VIP de San Fierro!");
        Entrando[playerid] = 3;
        SetPlayerInterior(playerid, 1);
        SetPlayerPos(playerid, -794.8354,495.9334,1376.1953);
    }
    return 1;
}

SairInterior(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1494.4989,1303.6678,1093.2964) && Entrando[playerid] == 1)         //Agencia LS
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair da Agencia de Emprego de Los Santos!");
        SetPlayerPos(playerid,1154.0808,-1771.9812,16.5992);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1494.4989,1303.6678,1093.2964) && Entrando[playerid] == 2)       //Agencia LV
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair da Agencia de Emprego de Las Venturas!");
        SetPlayerPos(playerid,937.8450,1733.1957,8.8516);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1494.4989,1303.6678,1093.2964) && Entrando[playerid] == 3)       //Agencia SF
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair da Agencia de Emprego de San Fierro!");
        SetPlayerPos(playerid,-2171.8110,252.0813,35.3378);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 389.3904,173.8544,1008.3828) && Entrando[playerid] == 1)   //Prefeitura LS
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair da Prefeirura de Los Santos!");
        SetPlayerPos(playerid, 1481.0637,-1770.9515,18.7958);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 389.3904,173.8544,1008.3828) && Entrando[playerid] == 2)   //Prefeitura LV
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair da Prefeirura de Las Venturas!");
        SetPlayerPos(playerid, 2447.0620,2376.2354,12.1635);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 389.3904,173.8544,1008.3828) && Entrando[playerid] == 3)   //Prefeitura SF
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair da Prefeirura de San Fierro!");
        SetPlayerPos(playerid, -2765.8796,375.5812,6.3347);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 246.8748,63.0608,1003.6406) && Entrando[playerid] == 1)    // Departamento LS
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair do Departamento de Polícia de Los Santos!");
        SetPlayerPos(playerid, 1554.8657,-1675.6693,16.1953);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 246.8748,63.0608,1003.6406) && Entrando[playerid] == 2)    // Departamento LV
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair do Departamento de Polícia de Las Venturas!");
        SetPlayerPos(playerid, 2290.1218,2430.9775,10.8203);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 246.8748,63.0608,1003.6406) && Entrando[playerid] == 3)    // Departamento SF
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair do Departamento de Polícia de San Fierro!");
        SetPlayerPos(playerid, -1605.5848,710.8436,13.8672);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 246.8748,63.0608,1003.6406) && Entrando[playerid] == 4)    // Departamento DM
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair do Departamento de Polícia de Dillimore!");
        SetPlayerPos(playerid, 627.7621,-571.7207,17.5526);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1104.6949,1515.8959,4452.8071) && Entrando[playerid] == 1)       // Hospital LS
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair do Hospital de Los Santos!");
        SetPlayerPos(playerid, 1172.6787,-1323.3129,15.4022);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1104.6949,1515.8959,4452.8071) && Entrando[playerid] == 2)       // Hospital LV
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair do Hospital de Las Venturas!");
        SetPlayerPos(playerid, 1607.3579,1815.6309,10.8203);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1104.6949,1515.8959,4452.8071) && Entrando[playerid] == 3)       // Hospital SF
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair do Hospital de San Fierro!");
        SetPlayerPos(playerid, -2655.0662,639.1497,14.4531);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1104.6949,1515.8959,4452.8071) && Entrando[playerid] == 4)       // Hospital EQ
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair do Hospital de El Quebrados!");
        SetPlayerPos(playerid, -1514.8217,2520.3232,55.9185);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1104.6949,1515.8959,4452.8071) && Entrando[playerid] == 5)       // Hospital MG
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair do Hospital de Montgomery!");
        SetPlayerPos(playerid, 1241.8073,327.1022,19.7555);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1104.6949,1515.8959,4452.8071) && Entrando[playerid] == 6)       // Hospital FC
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair do Hospital de Fort Carson!");
        SetPlayerPos(playerid, -320.0716,1049.2637,20.3403);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1104.6949,1515.8959,4452.8071) && Entrando[playerid] == 7)       // Hospital AP
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair do Hospital de Angel Pine!");
        SetPlayerPos(playerid, -2223.1670,-2293.6865,31.6719);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2315.952880,-1.618174,26.742187) && Entrando[playerid] == 1)     // Banco LS
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair do Banco de Los Santos!");
        SetPlayerPos(playerid, 1778.3052,-1663.5337,14.4362);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2315.952880,-1.618174,26.742187) && Entrando[playerid] == 2)     // Banco LV
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair do Banco de Las Venturas!");
        SetPlayerPos(playerid, 2388.6733,2466.0430,10.8203);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2315.952880,-1.618174,26.742187) && Entrando[playerid] == 3)     // Banco SF
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair do Banco de San Fierro!");
        SetPlayerPos(playerid, -2649.8374,376.0090,6.1563);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2315.952880,-1.618174,26.742187) && Entrando[playerid] == 4)     // Banco FC
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair do Banco de Fort Carson!");
        SetPlayerPos(playerid, -180.3883,1133.1510,19.7422);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2315.952880,-1.618174,26.742187) && Entrando[playerid] == 5)     // Banco MG
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair do Banco de Montgomery!");
        SetPlayerPos(playerid, 1372.9271,405.2487,19.9555);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2315.952880,-1.618174,26.742187) && Entrando[playerid] == 6)     // Banco PC
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair do Banco de Palomino Creek!");
        SetPlayerPos(playerid, 302.9521,-16.2789,26.4844);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2315.952880,-1.618174,26.742187) && Entrando[playerid] == 7)     // Banco LB
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair do Banco de Las Barrancas!");
        SetPlayerPos(playerid, -828.0650,1503.6166,19.7585);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2315.952880,-1.618174,26.742187) && Entrando[playerid] == 8)     // Banco EQ
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair do Banco de El Quebrados!");
        SetPlayerPos(playerid, -1480.8273,2592.3015,55.8359);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2315.952880,-1.618174,26.742187) && Entrando[playerid] == 9)     // Banco BB
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair do Banco de BlueBerry!");
        SetPlayerPos(playerid, 207.7767,-62.5814,1.6498);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1798.4763,-1578.3191,14.0849) && Entrando[playerid] == 1)    // Imobiliaria LS
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair da Imobiliaria de Los Santos!");
        SetPlayerPos(playerid, 1798.4763,-1578.3191,14.0849);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2413.2390,1123.8374,10.8203) && Entrando[playerid] == 2)     // Imobiliaria LV
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair da Imobiliaria de Las Venturas!");
        SetPlayerPos(playerid, 2413.2390,1123.8374,10.8203);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -1881.1293,822.7573,35.1773) && Entrando[playerid] == 3)     // Imobiliaria SF
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair da Imobiliaria de San Fierro!");
        SetPlayerPos(playerid, -1881.1293,822.7573,35.1773);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -2029.798339,-106.675910,1035.171875) && Entrando[playerid] == 1)     // Auto Escola LS
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair da Auto Escola de Los Santos!");
        SetPlayerPos(playerid, 1519.0413,-1453.5895,14.2073);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -2029.798339,-106.675910,1035.171875) && Entrando[playerid] == 2)      // Auto Escola LV
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair da Auto Escola de Las Venturas!");
        SetPlayerPos(playerid, 2183.2483,2295.2205,10.8203);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -2029.798339,-106.675910,1035.171875) && Entrando[playerid] == 3)      // Auto Escola SF
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair da Auto Escola de San Fierro!");
        SetPlayerPos(playerid, -2026.5950,-101.3410,35.1641);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 833.269775,10.588416,1004.179687) && Entrando[playerid] == 1)     // Detran LS
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair do Detran de Los Santos!");
        SetPlayerPos(playerid, 1310.1411,-1367.8086,13.5408);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 833.269775,10.588416,1004.179687) && Entrando[playerid] == 2)   // Detran LV
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair do Detran de Las Venturas!");
        SetPlayerPos(playerid, 1173.1600,1349.0011,10.9219);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 833.269775,10.588416,1004.179687) && Entrando[playerid] == 3)   // Detran SF
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair do Detran de San Fierro!");
        SetPlayerPos(playerid, -2720.6375,127.7373,7.0391);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -794.9983,490.3652,1376.1953) && Entrando[playerid] == 1)     // Area VIP LS
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair da Área VIP de Los Santos!");
        SetPlayerPos(playerid, 1022.4510,-1121.5958,23.8719);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -794.9983,490.3652,1376.1953) && Entrando[playerid] == 2)   // Area VIP LV
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair da Área VIP de Los Venturas!");
        SetPlayerPos(playerid, 2015.0763,1106.6337,10.8203);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -794.9983,490.3652,1376.1953) && Entrando[playerid] == 3)   // Area VIP SF
    {
        Entrando[playerid] = 0;
        SetPlayerInterior(playerid, 0);
        SendClientMessage(playerid, 0xFFFF00AA, "| INFO | Você acabou de sair da Área VIP de San Fierro!");
        SetPlayerPos(playerid, -2664.4136,-7.4449,6.1328);
    }
    return 1;
}

forward LoadInterior(playerid);
public LoadInterior(playerid)
{
    TogglePlayerControllable(playerid, true);
    PlayerTextDrawHide(playerid, CarregandoInterior[playerid]);
    return 1;
}
