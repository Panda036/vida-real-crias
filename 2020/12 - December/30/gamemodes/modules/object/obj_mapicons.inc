#include YSI\y_hooks

hook OnGameModeInit(playerid)
{
    CreateDynamicMapIcon(1154.08, -1771.98, 16.59, 23, -1, WORLD_DEFAULT, 0, -1, 200.0);     //Agencia LS
    CreateDynamicMapIcon(937.84, 1733.19, 8.85, 23, -1, WORLD_DEFAULT, 0, -1, 200.0);        //Agencia LV
    CreateDynamicMapIcon(-2171.81, 252.08, 35.33, 23, -1, WORLD_DEFAULT, 0, -1, 200.0);      //Agencia SF
    CreateDynamicMapIcon(1481.06, -1770.95, 18.79, 42, -1, WORLD_DEFAULT, 0, -1, 200.0);     //Prefeitura LS
    CreateDynamicMapIcon(2447.06, 2376.23, 12.16, 42, -1, WORLD_DEFAULT, 0, -1, 200.0);      //Prefeitura LV
    CreateDynamicMapIcon(-2765.87, 375.58, 6.33, 42, -1, WORLD_DEFAULT, 0, -1, 200.0);       //Prefeitura SF
    CreateDynamicMapIcon(1554.86, -1675.66, 16.19, 30, -1, WORLD_DEFAULT, 0, -1, 200.0);     // Departamento LS
    CreateDynamicMapIcon(2290.12, 2430.97, 10.82, 30, -1, WORLD_DEFAULT, 0, -1, 200.0);      // Departamento LV
    CreateDynamicMapIcon(-1605.58, 710.84, 13.86, 30, -1, WORLD_DEFAULT, 0, -1, 200.0);      // Departamento SF
    CreateDynamicMapIcon(627.76, -571.72, 17.55, 30, -1, WORLD_DEFAULT, 0, -1, 200.0);       // Departamento DM
    CreateDynamicMapIcon(-217.55, 979.16, 19.50, 30, -1, WORLD_DEFAULT, 0, -1, 200.0);      // Departamento FC
    CreateDynamicMapIcon(-2162.06, -2385.79, 30.62, 30, -1, WORLD_DEFAULT, 0, -1, 200.0);   // Departamento AP
    CreateDynamicMapIcon(-1390.03, 2638.01, 55.98, 30, -1, WORLD_DEFAULT, 0, -1, 200.0);    // Departamento EQ
    CreateDynamicMapIcon(1172.67, -1323.31, 15.40, 22, -1, WORLD_DEFAULT, 0, -1, 200.0);     // Hospital LS Market
    CreateDynamicMapIcon(2029.76, -1402.84, 17.25, 22, -1, WORLD_DEFAULT, 0, -1, 200.0);    // Hospital LS Jefferson
    CreateDynamicMapIcon(1607.35, 1815.63, 10.82, 22, -1, WORLD_DEFAULT, 0, -1, 200.0);      // Hospital LV
    CreateDynamicMapIcon(-2655.06, 639.14, 14.45, 22, -1, WORLD_DEFAULT, 0, -1, 200.0);      // Hospital SF
    CreateDynamicMapIcon(-1514.82, 2520.32, 55.91, 22, -1, WORLD_DEFAULT, 0, -1, 200.0);     // Hospital EL
    CreateDynamicMapIcon(1241.80, 327.10, 19.75, 22, -1, WORLD_DEFAULT, 0, -1, 200.0);       // Hospital MG
    CreateDynamicMapIcon(-320.07, 1049.26, 20.34, 22, -1, WORLD_DEFAULT, 0, -1, 200.0);      // Hospital FC
    CreateDynamicMapIcon(-2223.16, -2293.68, 31.67, 22, -1, WORLD_DEFAULT, 0, -1, 200.0);    // Hospital AP
    CreateDynamicMapIcon(1778.30, -1663.53, 14.43, 52, -1, WORLD_DEFAULT, 0, -1, 200.0);     // Banco LS
    CreateDynamicMapIcon(2388.67, 2466.04, 10.82, 52, -1, WORLD_DEFAULT, 0, -1, 200.0);      // Banco LV
    CreateDynamicMapIcon(-1494.52, 920.06, 7.18, 52, -1, WORLD_DEFAULT, 0, -1, 200.0);       // Banco SF
    CreateDynamicMapIcon(-180.38, 1133.15, 19.74, 52, -1, WORLD_DEFAULT, 0, -1, 200.0);      // Banco FC
    CreateDynamicMapIcon(1372.92, 405.24, 19.95, 52, -1, WORLD_DEFAULT, 0, -1, 200.0);       // Banco MG
    CreateDynamicMapIcon(2302.95, -16.27, 26.48, 52, -1, WORLD_DEFAULT, 0, -1, 200.0);       // Banco PC
    CreateDynamicMapIcon(-828.06, 1503.61, 19.75, 52, -1, WORLD_DEFAULT, 0, -1, 200.0);      // Banco LB
    CreateDynamicMapIcon(-1480.82, 2592.30, 55.83, 52, -1, WORLD_DEFAULT, 0, -1, 200.0);     // Banco EQ
    CreateDynamicMapIcon(207.77, -62.58, 1.64, 52, -1, WORLD_DEFAULT, 0, -1, 200.0);         // Banco BB
    CreateDynamicMapIcon(1798.47, -1578.31, 14.08, 58, -1, WORLD_DEFAULT, 0, -1, 200.0);     // Imobiliaria LS
    CreateDynamicMapIcon(2413.23, 1123.83, 10.82, 58, -1, WORLD_DEFAULT, 0, -1, 200.0);      // Imobiliaria LV
    CreateDynamicMapIcon(-1881.12, 822.75, 35.17, 58, -1, WORLD_DEFAULT, 0, -1, 200.0);      // Imobiliaria SF
    CreateDynamicMapIcon(1519.04, -1453.58, 14.20, 36, -1, WORLD_DEFAULT, 0, -1, 200.0);     // Auto Escola LS
    CreateDynamicMapIcon(2183.24, 2295.22, 10.82, 36, -1, WORLD_DEFAULT, 0, -1, 200.0);      // Auto Escola LV
    CreateDynamicMapIcon(-2026.59, -101.34, 35.16, 36, -1, WORLD_DEFAULT, 0, -1, 200.0);     // Auto Escola SF
    CreateDynamicMapIcon(1310.14, -1367.80, 13.54, 19, -1, WORLD_DEFAULT, 0, -1, 200.0);     // Detran LS
    CreateDynamicMapIcon(1173.16, 1349.00, 10.92, 19, -1, WORLD_DEFAULT, 0, -1, 200.0);      // Detran LV
    CreateDynamicMapIcon(-2720.63, 127.73, 7.03, 19, -1, WORLD_DEFAULT, 0, -1, 200.0);       // Detran SF
    return 1;
}
