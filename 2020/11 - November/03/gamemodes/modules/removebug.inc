#include YSI\y_hooks

new AnimationLibraries[][] =
{
	"AIRPORT", "Attractors", "BAR", "BASEBALL", "BD_FIRE", "BEACH", "benchpress", "BF_injection", "BIKED", "BIKEH", "BIKELEAP",
	"BIKES", "BIKEV", "BIKE_DBZ", "BLOWJOBZ", "BMX", "BOMBER", "BOX", "BSKTBALL", "BUDDY", "BUS", "CAMERA", "CAR", "CARRY", "CAR_CHAT",
	"CASINO", "CHAINSAW", "CHOPPA", "CLOTHES", "COACH", "COLT45", "COP_AMBIENT", "COP_DVBYZ", "CRACK", "CRIB", "DAM_JUMP", "DANCING",
	"DEALER", "DILDO", "DODGE", "DOZER", "DRIVEBYS", "FAT", "FIGHT_B", "FIGHT_C", "FIGHT_D", "FIGHT_E", "FINALE", "FINALE2", "FLAME",
	"Flowers", "FOOD", "Freeweights", "GANGS", "GHANDS", "GHETTO_DB", "goggles", "GRAFFITI", "GRAVEYARD", "GRENADE", "GYMNASIUM", "HAIRCUTS",
	"HEIST9", "INT_HOUSE", "INT_OFFICE", "INT_SHOP", "JST_BUISNESS", "KART", "KISSING", "KNIFE", "LAPDAN1", "LAPDAN2", "LAPDAN3", "LOWRIDER",
	"MD_CHASE", "MD_END", "MEDIC", "MISC", "MTB", "MUSCULAR", "NEVADA", "ON_LOOKERS", "OTB", "PARACHUTE", "PARK", "PAULNMAC", "ped", "PLAYER_DVBYS",
	"PLAYIDLES", "POLICE", "POOL", "POOR", "PYTHON", "QUAD", "QUAD_DBZ", "RAPPING", "RIFLE", "RIOT", "ROB_BANK", "ROCKET", "RUSTLER", "RYDER",
	"SCRATCHING", "SHAMAL", "SHOP", "SHOTGUN", "SILENCED", "SKATE", "SMOKING", "SNIPER", "SPRAYCAN", "STRIP", "SUNBATHE", "SWAT", "SWEET", "SWIM",
	"SWORD", "TANK", "TATTOOS", "TEC", "TRAIN", "TRUCK", "UZI", "VAN", "VENDING", "VORTEX", "WAYFARER", "WEAPONS", "WUZI", "SAMP"
};


stock RemoveBugFirstAnimation(playerid)
{
    for (new i; i < sizeof(AnimationLibraries); i++)
    {
        ApplyAnimation(playerid, AnimationLibraries[i], "null", 0.0, 0, 0, 0, 0, 0);
    }
	return 1;
}

