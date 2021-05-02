#include YSI\y_hooks

#undef MAX_ACTORS
#define MAX_ACTORS 27

/*
// Actors IDs
enum
{
    ACTOR_WELCOME,
	ACTOR_AGENCY,
    ACTOR_MOB_1,
    ACTOR_MOB_2,
    ACTOR_MOB_3,
    ACTOR_MOB_LT,
    ACTOR_CANNABIS,
    ACTOR_TOWNHALL,
    ACTOR_IMOBILIARIA,
    ACTOR_BANK_1,
    ACTOR_BANK_2,
    ACTOR_AUTO_SCHOLL,
    ACTOR_AMMU_1,
    ACTOR_AMMU_2,
    ACTOR_AMMU_3,
    ACTOR_AMMU_4,
    ACTOR_AMMU_5,
    ACTOR_CLUCKINBELL,
    ACTOR_BAR,
    ACTOR_UTILITS,
    ACTOR_RESTAURANT,
    ACTOR_KINGS,
    ACTOR_TBSR, //Nome de emp abreviado
    ACTOR_PD, //Nome de emp abreviado
    ACTOR_PIZZA,
    ACTOR_BURGUESHOT,
    ACTOR_PIZZABOY
}
*/

enum e_ad
{
    ad_skinid,
    Float:ad_x,
    Float:ad_y,
    Float:ad_z,
    Float:ad_a
};

new ActorActor[MAX_ACTORS];
new ActorData[MAX_ACTORS][e_ad] =
{
    {217, 826.48, -1338.09, 13.53, 0.35},
    {57, 1488.71, 1305.64, 1093.29, 270.19},
    {124, 2442.05, -1970.16, 13.54, 271.48},
    {124, 2557.32, 2836.36, 10.82, 179.97},
    {124, -2187.84, -238.60, 36.52, 354.50},
    {124, -439.84, 2217.97, 42.42, 179.63},
    {124, 195.73, -234.35, 1.77, 270.46},
    {57, 359.71, 173.59, 1008.38, 263.49},
    {113, 362.89, 172.26, 1025.78, 178.69},
    {59, 916.00, 1647.00, 1101.00, 90.00},
    {59, 916.00, 1645.00, 1101.00, 90.00},
    {281, -2035.27, -117.62, 1035.17, 275.18},
    {121, 316.56, -134.03, 999.60, 80.60},
    {121, 290.30, -104.20, 1001.52, 186.19},
    {121, 295.62, -83.02, 1001.51, 2.26},
    {121, 312.20, -168.43, 999.59, 359.47},
    {121, 296.00, -40.78, 1001.51, 6.96},
    {167, 369.51, -4.08, 1001.85, 175.22},
    {189, 497.27, -77.73, 998.76, 356.34},
    {194, -23.56, -57.51, 1003.55, 356.48},
    {11, 450.36, -81.56, 999.55, 180.96},
    {209, 380.98, -188.84, 1000.63, 132.40},
    {257, 1206.13, -28.32, 1000.95, 267.30},
    {252, -2655.96, 1407.52, 906.27, 271.11}, //Not show
    {155, 375.62, -117.09, 1001.49, 178.43},
    {205, 377.21, -65.20, 1001.51, 178.65},
    {155, 2122.32, -1790.29, 13.55, 352.91}
}; // Actor limit: 1000 (0.3.7)

hook OnGameModeInit()
{
    for(new actorid = 0; actorid < MAX_ACTORS; actorid++)
    {
        ActorActor[actorid] = CreateActor(ActorData[actorid][ad_skinid], ActorData[actorid][ad_x], ActorData[actorid][ad_y], ActorData[actorid][ad_z], ActorData[actorid][ad_a]);
    }

    SetTimer("ResetActorAnimation", 15000, true);
	return 1;
}

forward ResetActorAnimation();
public ResetActorAnimation()
{
    new Float:x, Float:y, Float:z;

    for(new actorid = 0; actorid < MAX_ACTORS; actorid++)
    {
        GetActorPos(ActorActor[actorid], x, y, z);

        if(ActorData[actorid][ad_x] != x || ActorData[actorid][ad_y] != y || ActorData[actorid][ad_z] != z)
        {
            SetActorPos(ActorActor[actorid], ActorData[actorid][ad_x], ActorData[actorid][ad_y], ActorData[actorid][ad_z]);
        }

        ApplyActorAnimation(ActorActor[actorid], "DEALER", "DEALER_DEAL", 4.1, 1, 0, 0, 1, 0);
    }
    return 1;
}
