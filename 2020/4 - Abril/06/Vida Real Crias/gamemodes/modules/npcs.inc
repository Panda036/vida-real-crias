#include YSI\y_hooks

// Actors IDs
enum
{
	ACTOR_AGENCY,
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
    ACTOR_AGENCY_MOB,
    ACTOR_PIZZA,
    ACTOR_BURGUESHOT,
    ACTOR_PIZZABOY
}

new ActorData[21]; // Actor limit: 1000 (0.3.7)

hook OnGameModeInit()
{
    ActorData[ACTOR_AGENCY] = CreateActor(57, 1488.71, 1305.64, 1093.29, 270.19);
    ActorData[ACTOR_AGENCY_MOB] = CreateActor(124, 2360.283, -649.142, 128.192, 180.16);
    ActorData[ACTOR_IMOBILIARIA] = CreateActor(113, 362.89, 172.26, 1025.78, 178.69);
    ActorData[ACTOR_BANK_1] = CreateActor(59, 354.53, 162.29, 1019.98, 357.90);
    ActorData[ACTOR_BANK_2] = CreateActor(59, 356.25, 162.53, 1019.98, 354.45);
    ActorData[ACTOR_AUTO_SCHOLL] = CreateActor(281, -2035.2778, -117.6251, 1035.1719, 275.18);
    ActorData[ACTOR_AMMU_1] = CreateActor(121, 316.56, -134.03, 999.60, 80.60);
    ActorData[ACTOR_AMMU_2] = CreateActor(121, 290.30, -104.20, 1001.52, 186.19);
    ActorData[ACTOR_AMMU_3] = CreateActor(121, 295.62, -83.02, 1001.51, 2.26);
    ActorData[ACTOR_AMMU_4] = CreateActor(121, 312.20, -168.43, 999.59, 359.47);
    ActorData[ACTOR_AMMU_5] = CreateActor(121, 296.00, -40.78, 1001.51, 6.96);
    ActorData[ACTOR_CLUCKINBELL] = CreateActor(167, 369.51, -4.08, 1001.85, 175.22);
    ActorData[ACTOR_BAR] = CreateActor(189, 497.27, -77.73, 998.76, 356.34);
    ActorData[ACTOR_UTILITS] = CreateActor(194, -23.56, -57.51, 1003.55, 356.48);
    ActorData[ACTOR_RESTAURANT] = CreateActor(11, 450.36, -81.56, 999.55, 180.96);
    ActorData[ACTOR_KINGS] = CreateActor(209, 380.98, -188.84, 1000.63, 132.40);
    ActorData[ACTOR_TBSR] = CreateActor(257, 1206.13, -28.32, 1000.95, 267.30);
    ActorData[ACTOR_PD] = CreateActor(252, -2655.96, 1407.52, 906.27, 271.11); //Not show
    ActorData[ACTOR_PIZZA] = CreateActor(155, 375.62, -117.09, 1001.49, 178.43);
    ActorData[ACTOR_BURGUESHOT] = CreateActor(205, 377.21, -65.20, 1001.51, 178.65);
    ActorData[ACTOR_PIZZABOY] = CreateActor(155, 2122.32, -1790.29, 13.55, 352.91);

    for(new actorid = 0; actorid < sizeof(ActorData); actorid++)
    {
        SetTimerEx("ResetActorAnimation", 15000, true, "d", actorid);
    }
	return 1;
}

forward ResetActorAnimation(actorid);
public ResetActorAnimation(actorid)
{
    if(!IsValidActor(ActorData[actorid])) return 0;

    ApplyActorAnimation(ActorData[actorid], "DEALER", "DEALER_DEAL", 4.1, 1, 0, 0, 1, 0);
    return 1;
}
