#include YSI\y_hooks

#define MAX_CASHMACHINE 20

enum e_cm
{
    Float:cm_x,
    Float:cm_y,
    Float:cm_z,
    Float:cm_rz
};

new CashMachine[MAX_CASHMACHINE][e_cm] =
{
    {1928.60, -1784.59, 13.20, 90.00},
    {1014.11, -928.70, 41.94, 10.00},
    {661.34, -553.20, 15.97, -90.00},
    {-79.17, -1171.79, 1.77, -110.00},
    {-1570.19, -2719.59, 48.38, -125.00},
    {-2232.02, -2559.22, 31.54, -120.00},
    {-1693.28, 415.00, 6.82, 45.00},
    {-2420.11, 958.72, 44.87, 90.00},
    {2107.30, 896.79, 10.81, 180.00},
    {1589.19, 2217.98, 10.69, 0.00},
    {2174.41, 1966.42, 10.45, 180.00},
    {360.54, -1807.39, 4.23, -90.00},
    {2156.21, 2733.90, 10.79, 180.00},
    {665.81, 1720.01, 6.82, -140.00},
    {58.96, 1222.00, 18.49, 90.00},
    {-734.95, 2747.81, 46.86, 0.00},
    {-1282.68, 2714.94, 49.88, -60.00},
    {-1463.42, 1873.56, 32.27, 5.00},
    {2187.76, 2479.76, 10.85, 90.00},
    {1367.26, -1290.79, 13.18, -90.00}
};

hook OnGameModeInit()
{
    for(new cashid = 0; cashid < MAX_CASHMACHINE; cashid++)
    {
        CreateDynamic3DTextLabel("{008000}Caixa Eletrônico\n{FFFFFF}Precione \"{00FF00}Y{FFFFFF}\"", 0xFFFFFFFF, CashMachine[cashid][cm_x], CashMachine[cashid][cm_y], CashMachine[cashid][cm_z], 20.0);
        CreateDynamicObject(2942, CashMachine[cashid][cm_x], CashMachine[cashid][cm_y], CashMachine[cashid][cm_z], 0.0, 0.0, CashMachine[cashid][cm_rz]);
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(PRESSED(KEY_YES))
    {
        for(new cashid = 0; cashid < MAX_CASHMACHINE; cashid++)
        {
            if(IsPlayerInRangeOfPoint(playerid, 2.5, CashMachine[cashid][cm_x], CashMachine[cashid][cm_y], CashMachine[cashid][cm_z]))
            {
                ShowPlayerDialog(playerid, bank, DIALOG_STYLE_LIST, "{FF0000}Banco", "{FFFFFF}Saldo \nSaque \nDeposito", "Selecionar", "Cancelar");
                return 1;
            }
        }
        return 1;
    }
	return 1;
}
