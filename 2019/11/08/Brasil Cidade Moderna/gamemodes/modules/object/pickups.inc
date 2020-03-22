#include YSI\y_hooks

#define MAX_PICKUPS_PUBLICS 38

new PPublics[MAX_PICKUPS_PUBLICS];

hook OnGameModeInit()
{
    PPublics[0] = CreatePickup(1314,1,1154.0808,-1771.9812,16.5992);            // Agencia LS
    PPublics[1] = CreatePickup(1314,1,937.8450,1733.1957,8.8516);               // Agencia LV
    PPublics[2] = CreatePickup(1314,1,-2171.8110,252.0813,35.3378);             // Agencia SF
    PPublics[3] = CreatePickup(1239,1,1481.0637,-1770.9515,18.7958);            // Prefeitura LS
    PPublics[4] = CreatePickup(1239,1,2447.0620,2376.2354,12.1635);             // Prefeitura LV
    PPublics[5] = CreatePickup(1239,1,-2765.8796,375.5812,6.3347);              // Prefeitura SF
    PPublics[6] = CreatePickup(1247,1,1554.8657,-1675.6693,16.1953);            // Departamento LS
    PPublics[7] = CreatePickup(1247,1,2290.1218,2430.9775,10.8203);             // Departamento LV
    PPublics[8] = CreatePickup(1247,1,-1605.5848,710.8436,13.8672);             // Departamento SF
    PPublics[9] = CreatePickup(1247,1,627.7621,-571.7207,17.5526);              // Departamento DM
    PPublics[10] = CreatePickup(1240,1,1172.6787,-1323.3129,15.4022);           // Hospital LS
    PPublics[11] = CreatePickup(1240,1,1607.3579,1815.6309,10.8203);            // Hospital LV
    PPublics[12] = CreatePickup(1240,1,-2655.0662,639.1497,14.4531);            // Hospital SF
    PPublics[13] = CreatePickup(1240,1,-1514.8217,2520.3232,55.9185);           // Hospital EQ
    PPublics[14] = CreatePickup(1240,1,1241.8073,327.1022,19.7555);             // Hospital MG
    PPublics[15] = CreatePickup(1240,1,-320.0716,1049.2637,20.3403);            // Hospital FC
    PPublics[16] = CreatePickup(1240,1,-2223.1670,-2293.6865,31.6719);          // Hospital AP
    PPublics[17] = CreatePickup(1274,1,1778.3052,-1663.5337,14.4362);           // Banco LS
    PPublics[18] = CreatePickup(1274,1,2388.6733,2466.0430,10.8203);            // Banco LV
    PPublics[19] = CreatePickup(1274,1,-2649.8374,376.0090,6.1563);             // Banco SF
    PPublics[20] = CreatePickup(1274,1,-180.3883,1133.1510,19.7422);            // Banco FC
    PPublics[21] = CreatePickup(1274,1,1372.9271,405.2487,19.9555);             // Banco MG
    PPublics[22] = CreatePickup(1274,1,2302.9521,-16.2789,26.4844);             // Banco PC
    PPublics[23] = CreatePickup(1274,1,-828.0650,1503.6166,19.7585);            // Banco LB
    PPublics[24] = CreatePickup(1274,1,-1480.8273,2592.3015,55.8359);           // Banco EQ
    PPublics[25] = CreatePickup(1274,1,207.7767,-62.5814,1.6498);               // Banco BB
    PPublics[26] = CreatePickup(1239,1,1798.4763,-1578.3191,14.0849);           // Imobiliaria LS
    PPublics[27] = CreatePickup(1239,1,2413.2390,1123.8374,10.8203);            // Imobiliaria LV
    PPublics[28] = CreatePickup(1239,1,-1881.1293,822.7573,35.1773);            // Imobiliaria SF
    PPublics[29] = CreatePickup(1239,1,1519.0413,-1453.5895,14.2073);           // Auto Escola LS
    PPublics[30] = CreatePickup(1239,1,2183.2483,2295.2205,10.8203);            // Auto Escola LV
    PPublics[31] = CreatePickup(1239,1,-2026.5950,-101.3410,35.1641);           // Auto Escola SF
    PPublics[32] = CreatePickup(19132,1,1310.1411,-1367.8086,13.5408);          // Detran LS
    PPublics[33] = CreatePickup(19132,1,1173.1600,1349.0011,10.9219);           // Detran LV
    PPublics[34] = CreatePickup(19132,1,-2720.6375,127.7373,7.0391);            // Detran SF
    PPublics[35] = CreatePickup(1239,1,1022.4510,-1121.5958,23.8719);           // 햞ea Vip LS
    PPublics[36] = CreatePickup(1239,1,2015.0763,1106.6337,10.8203);            // 햞ea Vip LV
    PPublics[37] = CreatePickup(1239,1,-2664.4136,-7.4449,6.1328);              // 햞ea Vip SF
    CreatePickup(1318,1,1494.4989,1303.6678,1093.2964);                         // Agencia
    CreatePickup(1318,1,389.3904,173.8544,1008.3828);                           // Prefeitura
    CreatePickup(1318,1,246.8748,63.0608,1003.6406);                            // Departamento
    CreatePickup(1318,1,1104.6949,1515.8959,4452.8071);                         // Hospital
    CreatePickup(1318,1,2315.952880,-1.618174,26.742187);                       // Banco
    CreatePickup(1318,1,1798.4763,-1578.3191,14.0849);                          // Imobiliaria
    CreatePickup(1318,1,-2029.798339,-106.675910,1035.171875);                  // Auto Escola
    CreatePickup(1318,1,833.269775,10.588416,1004.179687);                      // Detran
    CreatePickup(1318,1,-794.9983,490.3652,1376.1953);                          // 햞ea Vip
    CreatePickup(1242,1,254.1715,74.3339,1003.6406);                            // DP ARMAMENTO
    return 1;
}

hook OnGameModeExit()
{
    for(new i=0; i < MAX_PICKUPS_PUBLICS; i++)
	{
     	DestroyPickup(PPublics[i]);
	}
	return 1;
}

GetEnterExitStatus(playerid, pickupid)
{
    for(new i=0; i <= MAX_PICKUPS_PUBLICS; ++i)
    {
        if(pickupid == PPublics[i])
        {
            SendClientMessage(playerid, -1, "| INFO | Para entrar digite {CFCDCD}'/Entrar'{FFFFFF} ou pressione a tecla {CFCDCD}'F'");
        }
    }
    return 1;
}
