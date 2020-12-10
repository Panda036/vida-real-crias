enum
{
    unemployed,
    newspaperdelivery,
    icecream,
    pizzaboy,
    motoboy,
    gari,
    paramedic,
    light,
    lawyer,
    taxi,
    tanker,
    loader,
    strongcardriver,
    strongcarsecurity,
    military,
    federal,
    delegate,
    fbi,
    cia,
    swat,
    narcoticos,
    interpol,
    internalaffairs,
    navy,
    army,
    aeronautics,
    potplanter,
    weaponproducer,
    burglar,
    thief
};

enum e_pfs
{
    pfs_color,
    pfs_salary,
    pfs_level,
    pfs_profission,
    Float:pfs_x,
    Float:pfs_y,
    Float:pfs_z
};

new Profission[30][e_pfs] =
{
    {0xFFFFFFAA, 150, 0, unemployed, 0.0, 0.0, 0.0},
    {0x80FF80AA, 250, 0, newspaperdelivery, 785.20, -1327.76, 13.54},
    {0xFF80C0AA, 350, 2, icecream, 2444.00, 1663.00, 10.82},
    {0xFFFF80AA, 400, 4, pizzaboy, 2107.74, -1787.75, 13.56},
    {0xFF00FFAA, 650, 6, motoboy, 0.0, 0.0, 0.0},
    {0xD56A00AA, 700, 10, gari, 2089.53, -2080.92, 13.55},
    {0x00FF80AA, 700, 20, paramedic, 1599.87, 1818.08, 10.82},
    {0x008040AA, 1500, 45, light, -2516.58, -622.51, 132.75},
    {0x8000FFAA, 1600, 50, lawyer, -2051.29, 459.89, 35.17},
    {0xFFFF00AA, 450, 8, taxi, 2229.58, -1368.19, 23.992},
    {0x808080AA, 500, 15, tanker, 291.01, 1430.11, 10.54},
    {0x408080AA, 750, 20, loader, 2467.97, -2118.98, 13.54},
    {0x8080FFAA, 1000, 30, strongcardriver, 1765.19, -1703.33, 13.46},
    {0xB7B7FFAA, 1500, 50, strongcarsecurity, 1765.19, -1703.33, 13.46},
    {0x0090FFAA, 1800, 100, military, 1579.57, -1635.39, 13.56},
    {0x0080FFAA, 2000, 200, federal, 1579.57, -1635.39, 13.56},
    {0x0070FFAA, 2200, 300, delegate, 1579.57, -1635.39, 13.56},
    {0x0060FFAA, 2400, 400, fbi,1579.57, -1635.39, 13.56},
    {0x0050FFAA, 2600, 500, cia, 1579.57, -1635.39, 13.56},
    {0x0040FFAA, 2800, 600, swat, 1579.57, -1635.39, 13.56},
    {0x0030FFAA, 3000, 700, narcoticos, 1579.57, -1635.39, 13.56},
    {0x0020FFAA, 3200, 800, interpol, 1579.57, -1635.39, 13.56},
    {0x8080C0AA, 4000, 1000, internalaffairs, 2339.97, 2457.22, 14.96},
    {0x23238CAA, 4300, 1200, navy, -1425.52, 501.36, 3.03},
    {0x54693AAA, 4600, 1400, army, 126.10, 1897.44, 18.48},
    {0xCCCC00AA, 5000, 1600, aeronautics, 126.10, 1897.44, 18.48},
    {0x550000AA, 0, 5, potplanter, -1184.80, -1136.56, 129.21},
    {0x800000AA, 0, 10, weaponproducer, -2149.17, -241.95, 36.51},
    {0xAA0000AA, 0, 20, burglar, -391.40, 2221.69, 42.42},
    {0xD50000AA, 0, 30, thief, -391.40, 2221.69, 42.42}
};

new AgenciaMapIcon[MAX_PLAYERS];
new AgenciaPickup[MAX_PLAYERS];
new Text3D:AgenciaLabel[MAX_PLAYERS];
new bool:AgenciaEncaminhado[MAX_PLAYERS];
