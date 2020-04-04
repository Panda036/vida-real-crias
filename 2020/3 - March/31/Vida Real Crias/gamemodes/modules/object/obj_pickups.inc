#include YSI\y_hooks

#define MAX_PICKUPS_PUBLICS 42

new PPublics[MAX_PICKUPS_PUBLICS];

hook OnGameModeInit()
{
    PPublics[0] = CreateDynamicPickup(1314,1,1154.0808,-1771.9812,16.5992);             // Agencia LS
    PPublics[1] = CreateDynamicPickup(1314,1,937.8450,1733.1957,8.8516);                // Agencia LV
    PPublics[2] = CreateDynamicPickup(1314,1,-2171.8110,252.0813,35.3378);              // Agencia SF
    PPublics[3] = CreateDynamicPickup(1239,1,1481.0637,-1770.9515,18.7958);             // Prefeitura LS
    PPublics[4] = CreateDynamicPickup(1239,1,2447.0620,2376.2354,12.1635);              // Prefeitura LV
    PPublics[5] = CreateDynamicPickup(1239,1,-2765.8796,375.5812,6.3347);               // Prefeitura SF
    PPublics[6] = CreateDynamicPickup(1247,1,1554.8657,-1675.6693,16.1953);             // Departamento LS
    PPublics[7] = CreateDynamicPickup(1247,1,2290.1218,2430.9775,10.8203);              // Departamento LV
    PPublics[8] = CreateDynamicPickup(1247,1,-1605.5848,710.8436,13.8672);              // Departamento SF
    PPublics[9] = CreateDynamicPickup(1247,1,627.7621,-571.7207,17.5526);               // Departamento DM
    PPublics[10] = CreateDynamicPickup(1247,1,-217.5554,979.1621,19.5025);              // Departamento FC
    PPublics[11] = CreateDynamicPickup(1247,1,-2162.0627,-2385.7957,30.6250);           // Departamento AP
    PPublics[12] = CreateDynamicPickup(1247,1,-1390.0345,2638.0100,55.9844);            // Departamento EQ
    PPublics[13] = CreateDynamicPickup(1240,1,1172.6787,-1323.3129,15.4022);            // Hospital LS Market
    PPublics[14] = CreateDynamicPickup(1240,1,2029.7653,-1402.8408,17.2528);            // Hospital LS Jefferson
    PPublics[15] = CreateDynamicPickup(1240,1,1607.3579,1815.6309,10.8203);             // Hospital LV
    PPublics[16] = CreateDynamicPickup(1240,1,-2655.0662,639.1497,14.4531);             // Hospital SF
    PPublics[17] = CreateDynamicPickup(1240,1,-1514.8217,2520.3232,55.9185);            // Hospital EQ
    PPublics[18] = CreateDynamicPickup(1240,1,1241.8073,327.1022,19.7555);              // Hospital MG
    PPublics[19] = CreateDynamicPickup(1240,1,-320.0716,1049.2637,20.3403);             // Hospital FC
    PPublics[20] = CreateDynamicPickup(1240,1,-2223.1670,-2293.6865,31.6719);           // Hospital AP
    PPublics[21] = CreateDynamicPickup(1274,1,1778.3052,-1663.5337,14.4362);            // Banco LS
    PPublics[22] = CreateDynamicPickup(1274,1,2388.6733,2466.0430,10.8203);             // Banco LV
    PPublics[23] = CreateDynamicPickup(1274,1,-2649.8374,376.0090,6.1563);              // Banco SF
    PPublics[24] = CreateDynamicPickup(1274,1,-180.3883,1133.1510,19.7422);             // Banco FC
    PPublics[25] = CreateDynamicPickup(1274,1,-1480.8273,2592.3015,55.8359);            // Banco EQ
    PPublics[26] = CreateDynamicPickup(1274,1,1372.9271,405.2487,19.9555);              // Banco MG
    PPublics[27] = CreateDynamicPickup(1274,1,2302.9521,-16.2789,26.4844);              // Banco PC
    PPublics[28] = CreateDynamicPickup(1274,1,-828.0650,1503.6166,19.7585);             // Banco LB
    PPublics[29] = CreateDynamicPickup(1274,1,207.7767,-62.5814,1.6498);                // Banco BB
    PPublics[30] = CreateDynamicPickup(1239,1,1798.4763,-1578.3191,14.0849);            // Imobiliaria LS
    PPublics[31] = CreateDynamicPickup(1239,1,2413.2390,1123.8374,10.8203);             // Imobiliaria LV
    PPublics[32] = CreateDynamicPickup(1239,1,-1881.1293,822.7573,35.1773);             // Imobiliaria SF
    PPublics[33] = CreateDynamicPickup(19134,1,1519.0413,-1453.5895,14.2073);           // Auto Escola LS
    PPublics[34] = CreateDynamicPickup(19134,1,2183.2483,2295.2205,10.8203);            // Auto Escola LV
    PPublics[35] = CreateDynamicPickup(19134,1,-2026.5950,-101.3410,35.1641);           // Auto Escola SF
    PPublics[36] = CreateDynamicPickup(19132,1,1310.1411,-1367.8086,13.5408);           // Detran LS
    PPublics[37] = CreateDynamicPickup(19132,1,1173.1600,1349.0011,10.9219);            // Detran LV
    PPublics[38] = CreateDynamicPickup(19132,1,-2720.6375,127.7373,7.0391);             // Detran SF
    PPublics[39] = CreateDynamicPickup(1239,1,1022.4510,-1121.5958,23.8719);            // 햞ea Vip LS
    PPublics[40] = CreateDynamicPickup(1239,1,2015.0763,1106.6337,10.8203);             // 햞ea Vip LV
    PPublics[41] = CreateDynamicPickup(1239,1,-2664.4136,-7.4449,6.1328);               // 햞ea Vip SF
    CreateDynamicPickup(19133, 1, 1494.4989, 1303.6678, 1093.2964);                     // Agencia
    CreateDynamicPickup(19133, 1, 389.3904, 173.8544, 1008.3828);                       // Prefeitura
    CreateDynamicPickup(19133, 1, 246.8748, 63.0608, 1003.6406);                        // Departamento
    CreateDynamicPickup(19133, 1, 1020.6611, 993.2256, 15.1257);                        // Hospital
    CreateDynamicPickup(19133, 1, 354.14, 167.22, 1019.98);                             // Banco
    CreateDynamicPickup(19133, 1, 363.6009,166.4433,1025.7964);                         // Imobiliaria
    CreateDynamicPickup(19133, 1, -2026.9402, -104.7151, 1035.1719);                    // Auto Escola
    CreateDynamicPickup(19133, 1, 833.8543, 7.0404, 1004.1870);                         // Detran
    CreateDynamicPickup(19133, 1, -794.9983, 490.3652, 1376.1953);                      // 햞ea Vip
    CreateDynamicPickup(1239, 1, 354.45, 164.66, 1019.98);                              // Banco
    CreateDynamicPickup(1239, 1, 356.30, 164.72, 1019.99);                              // Banco
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

public OnPlayerPickUpDynamicPickup(playerid, pickupid)
{
    if(pickupid == PickupDP)
    {
        SendClientMessage(playerid, Red, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        SendClientMessage(playerid, White, "빝 Para equipar uniforme, digite: /uniforme");
        SendClientMessage(playerid, White, "빝 Para retirar o uniforme, digite: /removeruniforme");
        SendClientMessage(playerid, White, "빝 Para equipar armas, digite: /equipar");
        SendClientMessage(playerid, Red, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        return 1;
    }
    GetCompanyID(playerid, pickupid);
    GetHouseID(playerid, pickupid);
    GetPickUpPublics(playerid, pickupid);
    GetPickUpProfission(playerid, pickupid);
    return 1;
}

GetPickUpPublics(playerid, pickupid)
{
    for(new i=0; i < MAX_PICKUPS_PUBLICS; ++i)
    {
        if(pickupid == PPublics[i])
        {
            SendClientMessage(playerid, -1, "Para entrar digite {CFCDCD}'/Entrar'{FFFFFF} ou pressione a tecla {CFCDCD}'F'");
            return 1;
        }
    }
	return 1;
}
