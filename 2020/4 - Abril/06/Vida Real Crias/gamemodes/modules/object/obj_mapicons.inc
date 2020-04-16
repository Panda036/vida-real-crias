#include YSI\y_hooks

hook OnGameModeInit(playerid)
{
    CreateDynamicMapIcon(1154.0808, -1771.9812, 16.5992, 23, -1, -1, -1, -1, 200.0);     //Agencia LS
    CreateDynamicMapIcon(937.8450, 1733.1957, 8.8516, 23, -1, -1, -1, -1, 200.0);        //Agencia LV
    CreateDynamicMapIcon(-2171.8110, 252.0813, 35.3378, 23, -1, -1, -1, -1, 200.0);      //Agencia SF
    CreateDynamicMapIcon(1481.0637, -1770.9515, 18.7958, 42, -1, -1, -1, -1, 200.0);     //Prefeitura LS
    CreateDynamicMapIcon(2447.0620, 2376.2354, 12.1635, 42, -1, -1, -1, -1, 200.0);      //Prefeitura LV
    CreateDynamicMapIcon(-2765.8796, 375.5812, 6.3347, 42, -1, -1, -1, -1, 200.0);       //Prefeitura SF
    CreateDynamicMapIcon(1554.8657, -1675.6693, 16.1953, 30, -1, -1, -1, -1, 200.0);     // Departamento LS
    CreateDynamicMapIcon(2290.1218, 2430.9775, 10.8203, 30, -1, -1, -1, -1, 200.0);      // Departamento LV
    CreateDynamicMapIcon(-1605.5848, 710.8436, 13.8672, 30, -1, -1, -1, -1, 200.0);      // Departamento SF
    CreateDynamicMapIcon(627.7621, -571.7207, 17.5526, 30, -1, -1, -1, -1, 200.0);       // Departamento DM
    CreateDynamicMapIcon(-217.5554, 979.1621, 19.5025, 30, -1, -1, -1, -1, 200.0);      // Departamento FC
    CreateDynamicMapIcon(-2162.0627, -2385.7957, 30.6250, 30, -1, -1, -1, -1, 200.0);   // Departamento AP
    CreateDynamicMapIcon(-1390.0345, 2638.0100, 55.9844, 30, -1, -1, -1, -1, 200.0);    // Departamento EQ
    CreateDynamicMapIcon(1172.6787, -1323.3129, 15.4022, 22, -1, -1, -1, -1, 200.0);     // Hospital LS Market
    CreateDynamicMapIcon(2029.7653, -1402.8408, 17.2528, 22, -1, -1, -1, -1, 200.0);    // Hospital LS Jefferson
    CreateDynamicMapIcon(1607.3579, 1815.6309, 10.8203, 22, -1, -1, -1, -1, 200.0);      // Hospital LV
    CreateDynamicMapIcon(-2655.0662, 639.1497, 14.4531, 22, -1, -1, -1, -1, 200.0);      // Hospital SF
    CreateDynamicMapIcon(-1514.8217, 2520.3232, 55.9185, 22, -1, -1, -1, -1, 200.0);     // Hospital EL
    CreateDynamicMapIcon(1241.8073, 327.1022, 19.7555, 22, -1, -1, -1, -1, 200.0);       // Hospital MG
    CreateDynamicMapIcon(-320.0716, 1049.2637, 20.3403, 22, -1, -1, -1, -1, 200.0);      // Hospital FC
    CreateDynamicMapIcon(-2223.1670, -2293.6865, 31.6719, 22, -1, -1, -1, -1, 200.0);    // Hospital AP
    CreateDynamicMapIcon(1778.3052, -1663.5337, 14.4362, 52, -1, -1, -1, -1, 200.0);     // Banco LS
    CreateDynamicMapIcon(2388.6733, 2466.0430, 10.8203, 52, -1, -1, -1, -1, 200.0);      // Banco LV
    CreateDynamicMapIcon(-2649.8374, 376.0090, 6.1563, 52, -1, -1, -1, -1, 200.0);       // Banco SF
    CreateDynamicMapIcon(-180.3883, 1133.1510, 19.7422, 52, -1, -1, -1, -1, 200.0);      // Banco FC
    CreateDynamicMapIcon(1372.9271, 405.2487, 19.9555, 52, -1, -1, -1, -1, 200.0);       // Banco MG
    CreateDynamicMapIcon(2302.9521, -16.2789, 26.4844, 52, -1, -1, -1, -1, 200.0);       // Banco PC
    CreateDynamicMapIcon(-828.0650, 1503.6166, 19.7585, 52, -1, -1, -1, -1, 200.0);      // Banco LB
    CreateDynamicMapIcon(-1480.8273, 2592.3015, 55.8359, 52, -1, -1, -1, -1, 200.0);     // Banco EQ
    CreateDynamicMapIcon(207.7767, -62.5814, 1.6498, 52, -1, -1, -1, -1, 200.0);         // Banco BB
    CreateDynamicMapIcon(1798.4763, -1578.3191, 14.0849, 58, -1, -1, -1, -1, 200.0);     // Imobiliaria LS
    CreateDynamicMapIcon(2413.2390, 1123.8374, 10.8203, 58, -1, -1, -1, -1, 200.0);      // Imobiliaria LV
    CreateDynamicMapIcon(-1881.1293, 822.7573, 35.1773, 58, -1, -1, -1, -1, 200.0);      // Imobiliaria SF
    CreateDynamicMapIcon(1519.0413, -1453.5895, 14.2073, 36, -1, -1, -1, -1, 200.0);     // Auto Escola LS
    CreateDynamicMapIcon(2183.2483, 2295.2205, 10.8203, 36, -1, -1, -1, -1, 200.0);      // Auto Escola LV
    CreateDynamicMapIcon(-2026.5950, -101.3410, 35.1641, 36, -1, -1, -1, -1, 200.0);     // Auto Escola SF
    CreateDynamicMapIcon(1310.1411, -1367.8086, 13.5408, 19, -1, -1, -1, -1, 200.0);     // Detran LS
    CreateDynamicMapIcon(1173.1600, 1349.0011, 10.9219, 19, -1, -1, -1, -1, 200.0);      // Detran LV
    CreateDynamicMapIcon(-2720.6375, 127.7373, 7.0391, 19, -1, -1, -1, -1, 200.0);       // Detran SF
    return 1;
}
