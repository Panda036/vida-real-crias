enum
{
    unemployed,
    newspaperdelivery,
    pizzaboy,
    motoboy,
    gari,
    mechanical,
    paramedic,
    light,
    lawyer,
    taxi,
    tanker,
    taxiair,
    loader,
    minerals,
    woods,
    strongcardriver,
    strongcarsecurity,
    municipalguard,
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

new Profission[33][e_pfs] =
{
    {0xFFFFFFAA, 150, 0, unemployed, 0.0, 0.0, 0.0},
    {0x80FF80AA, 250, 0, newspaperdelivery, 785.20, -1327.76, 13.54},
    {0xFFFF80AA, 400, 0, pizzaboy, 2107.74, -1787.75, 13.56},
    {0xFF00FFAA, 650, 0, motoboy, 0.0, 0.0, 0.0},
    {0xD56A00AA, 700, 0, gari, 2089.53, -2080.92, 13.55},
    {0x004000AA, 850, 0, mechanical, -66.25, -1144.25, 1.07},
    {0x00FF80AA, 950, 0, paramedic, 1599.87, 1818.08, 10.82},
    {0x008040AA, 1500, 0, light, -2516.58, -622.51, 132.75},
    {0x8000FFAA, 1600, 0, lawyer, -2051.29, 459.89, 35.17},
    {0xFFFF00AA, 450, 0, taxi, 2229.58, -1368.19, 23.992},
    {0x808080AA, 500, 0, tanker, 291.01, 1430.11, 10.54},
    {0xFFFF00AA, 650, 0, taxiair, 1655.17, 1614.62, 10.82},
    {0x408080AA, 750, 0, loader, 2467.97, -2118.98, 13.54},
    {0x808040AA, 850, 0, minerals, 825.16, 858.04, 12.17},
    {0x804000AA, 950, 0, woods, -1971.66, -2433.43, 30.62},
    {0x8080FFAA, 1000, 0, strongcardriver, 1765.19, -1703.33, 13.46},
    {0xB7B7FFAA, 500, 40, strongcarsecurity, 1765.19, -1703.33, 13.46},
    {0x0090FFAA, 1500, 50, municipalguard, 1579.57, -1635.39, 13.56},
    {0x0090FFAA, 1800, 100, military, 1579.57, -1635.39, 13.56},
    {0x0080FFAA, 2000, 200, federal, 1579.57, -1635.39, 13.56},
    {0x0070FFAA, 2200, 300, delegate, 1579.57, -1635.39, 13.56},
    {0x0060FFAA, 2400, 400, fbi,1579.57, -1635.39, 13.56},
    {0x0050FFAA, 2600, 500, cia, 1579.57, -1635.39, 13.56},
    {0x0040FFAA, 2800, 600, swat, 1579.57, -1635.39, 13.56},
    {0x0030FFAA, 3000, 700, narcoticos, 1579.57, -1635.39, 13.56},
    {0x0020FFAA, 3200, 800, interpol, 1579.57, -1635.39, 13.56},
    {0x8080C0AA, 4000, 1000, internalaffairs, 2339.97, 2457.22, 14.96},
    {0x23238CAA, 4300, 1100, navy, -1425.52, 501.36, 3.03},
    {0x54693AAA, 4600, 1200, army, 126.10, 1897.44, 18.48},
    {0xCCCC00AA, 5000, 1300, aeronautics, 126.10, 1897.44, 18.48},
    {0x550000AA, 0, 0, potplanter, -1184.80, -1136.56, 129.21},
    {0x800000AA, 0, 0, weaponproducer, -2149.17, -241.95, 36.51},
    {0xD50000AA, 0, 0, thief, -391.40, 2221.69, 42.42}
};

new AgenciaMapIcon[MAX_PLAYERS];
new AgenciaPickup[MAX_PLAYERS];
new Text3D:AgenciaLabel[MAX_PLAYERS];
new bool:AgenciaEncaminhado[MAX_PLAYERS];
