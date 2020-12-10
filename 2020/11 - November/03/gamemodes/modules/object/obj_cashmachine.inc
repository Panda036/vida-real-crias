#include YSI\y_hooks

#define MAX_CASHMACHINE 21

enum e_cm
{
    Float:cm_x,
    Float:cm_y,
    Float:cm_z,
    Float:cm_rz
};

new CashMachine[MAX_CASHMACHINE][e_cm] =
{
    {1928.60632, -1784.59521, 13.20460, 90.00000},
    {1014.11890, -928.70648, 41.94270, 10.00000},
    {661.34857, -553.20978, 15.97270, -90.00000},
    {-79.17800, -1171.79468, 1.77250, -110.00000},
    {-1570.19873, -2719.59155, 48.38050, -125.00000},
    {-2232.02344, -2559.22900, 31.54370, -120.00000},
    {-1389.30725, 462.81891, 19.81610, -20.00000},
    {-1693.28662, 415.00159, 6.82460, 45.00000},
    {-2420.11548, 958.72717, 44.87560, 90.00000},
    {2107.30078, 896.79578, 10.81450, 180.00000},
    {1589.19617, 2217.98364, 10.69920, 0.00000},
    {2174.41187, 1966.42529, 10.45600, 180.00000},
    {360.54999, -1807.39734, 4.23160, -90.00000},
    {2156.21484, 2733.90234, 10.79440, 180.00000},
    {665.81152, 1720.01501, 6.82720, -140.00000},
    {58.96350, 1222.00098, 18.49980, 90.00000},
    {-734.95978, 2747.81543, 46.86530, 0.00000},
    {-1282.68091, 2714.94116, 49.88500, -60.00000},
    {-1463.42493, 1873.56836, 32.27230, 5.00000},
    {2187.76440, 2479.76392, 10.85080, 90.00000},
    {1367.26794, -1290.79810, 13.18500, -90.00000}
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
