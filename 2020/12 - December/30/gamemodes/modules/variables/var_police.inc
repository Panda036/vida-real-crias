#define MAX_DEPARTAMENT_POLICE  7
#define MAX_VEHICLE_IN_DP       4

#define DEPARTAMENT_POLICE_LS   0
#define DEPARTAMENT_POLICE_LV   1
#define DEPARTAMENT_POLICE_SF   2
#define DEPARTAMENT_POLICE_DM   3
#define DEPARTAMENT_POLICE_FC   4
#define DEPARTAMENT_POLICE_AP   5
#define DEPARTAMENT_POLICE_EQ   6

enum e_dpv
{
    Float:dpv_x,
    Float:dpv_y,
    Float:dpv_z,
    Float:dpv_a
};

new dp_vehicles[MAX_DEPARTAMENT_POLICE][MAX_VEHICLE_IN_DP][e_dpv] =
{
    {
        {1554.98, -1606.00, 13.08, 180.00},
        {1559.00, -1605.97, 13.08, 180.00},
        {1563.00, -1606.00, 13.08, 180.00},
        {1567.00, -1606.00, 13.08, 180.00}
    },
    {
        {2252.00, 2476.55, 10.42, 180.00},
        {2255.97, 2476.55, 10.42, 180.00},
        {2260.40, 2476.55, 10.42, 180.00},
        {2269.30, 2476.55, 10.42, 180.00}
    },
    {
        {-1610.70, 651.80, 6.87, 0.00},
        {-1616.58, 651.80, 6.87, 0.00},
        {-1622.56, 651.80, 6.87, 0.00},
        {-1628.41, 651.80, 6.87, 0.00}
    },
    {
        {634.00, -609.80, 17.00, 0.00},
        {630.00, -609.80, 17.00, 0.00},
        {615.00, -596.90, 17.00, -90.00},
        {615.00, -601.40, 17.00, -90.00}
    },
    {
        {-209.00, 998.34, 20.00, -180.00},
        {-209.00, 991.29, 20.00, -180.00},
        {-221.03, 1005.00, 20.00, 0.00},
        {-217.16, 1005.00, 20.00, 0.00}
    },
    {
        {-2173.67, -2364.22, 30.53, 52.00},
        {-2171.53, -2361.53, 30.53, 52.00},
        {-2169.20, -2358.71, 30.53, 52.00},
        {-2175.91, -2366.98, 30.53, 52.00}
    },
    {
        {-1400.20, 2659.80, 55.90, 90.00},
        {-1400.20, 2640.79, 55.90, 90.00},
        {-1400.20, 2653.42, 55.90, 90.00},
        {-1400.20, 2647.17, 55.90, 90.00}
    }
};

enum e_tpt
{
    tpt_obj,
    Text3D:tpt_label,
    Float:tpt_x,
    Float:tpt_y,
    Float:tpt_z
};

new TapeteInfo[MAX_PLAYERS][e_tpt];

new BarrierObj[MAX_PLAYERS];
new Text3D:BarrierLabel[MAX_PLAYERS];
new Handcuffed[MAX_PLAYERS];
new bool:Abordado[MAX_PLAYERS];
new bool:Perseguicao[MAX_PLAYERS];
new TimerProcurando[MAX_PLAYERS];

new t_persecution[MAX_PLAYERS];
new t_handcuffed[MAX_PLAYERS];
new t_approach[MAX_PLAYERS];
