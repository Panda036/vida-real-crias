enum e_bg
{
    Float:bg_x,
    Float:bg_y,
    Float:bg_z,
    Float:bg_rx,
    Float:bg_ry,
    Float:bg_rz
};

new BaseGate[MAX_BASES][e_bg] =
{
    {-495.55, -561.52, 27.24, 0.00, 0.00, 180.00},
    {1073.17, 1362.75, 12.62, 0.00, 0.00, 0.00},
    {997.12, 2127.51, 12.56, 0.00, 0.00, -90.00},
    {1017.86, 2139.33, 12.61, 0.00, 0.00, 90.00},
    {-75.47, -346.27, 3.24, 0.00, 0.00, 90.00}
};

enum e_be
{
    Float:be_x,
    Float:be_y,
    Float:be_z,
    Float:be_a
};

new BaseEnter[MAX_BASES][e_be] =
{
    {-540.02, -504.75, 25.52, 1.57},
    {1040.05, 1304.81, 10.82, -0.82},
    {967.55, 2133.02, 10.82, 273.40},
    {1053.58, 2148.19, 10.82, 90.0},
    {-49.83, -269.75, 6.63, 90.0}
};

enum e_pvb
{
    Float:pvb_x,
    Float:pvb_y,
    Float:pvb_z,
    Float:pvb_a
};

new PlaceVehicleBase[MAX_BASES][MAX_VEHICLE_BASE][e_pvb] =
{
    {
        {-554.50, -472.50, 25.42, 180.00},
        {-559.50, -472.50, 25.42, 180.00},
        {-564.50, -472.50, 25.42, 180.00},
        {-569.50, -472.50, 25.42, 180.00}
    },
    {
        {1044.00, 1355.00, 10.72, -90.00},
        {1044.00, 1350.00, 10.72, -90.00},
        {1044.00, 1345.00, 10.72, -90.00},
        {1044.00, 1340.00, 10.72, -90.00}
    },
    {
        {990.00, 2176.00, 10.83, 180.00},
        {985.00, 2176.00, 10.83, 180.00},
        {980.00, 2176.00, 10.83, 180.00},
        {975.00, 2176.00, 10.83, 180.00}
    },
    {
        {1033.00, 2078.00, 9.81, -90.00},
        {1033.00, 2074.00, 9.81, -90.00},
        {1033.00, 2070.00, 9.81, -90.00},
        {1033.00, 2066.00, 9.81, -90.00}
    },
    {
        {-31.00, -296.99, 5.15, -90.00},
        {-31.00, -293.60, 5.15, -90.00},
        {-31.00, -290.30, 5.15, -90.00},
        {-31.00, -286.80, 5.15, -90.00}
    }
};

enum bi
{
    bi_tag[MAX_BASE_TAG_NAME],
    bi_name[MAX_BASE_NAME],
    bi_owner[MAX_PLAYER_NAME],
    bi_sub[MAX_PLAYER_NAME],

    bi_selling,
    bi_price,

    bi_invasion,
    bi_dm,
    bi_lock,
    bi_pass[MAX_BASE_PASS],
    bi_tagcolor[10],
    bi_renovation,

    bi_pickup,
    bi_map,
    Text3D:bi_label,

    bi_gate,
    bool:bi_gatestate
};

new InBase[MAX_PLAYERS] = -1;
new bool:WarningLeftBase[MAX_PLAYERS];
new t_getweapon[MAX_PLAYERS];
new memberID[MAX_PLAYERS];

new t_basegate[MAX_BASES];
new bool:t_basegatestate[MAX_BASES];

new BaseInfo[MAX_BASES][bi];
new BaseMember[MAX_BASES][MAX_BASE_MEMBERS][MAX_PLAYER_NAME];
