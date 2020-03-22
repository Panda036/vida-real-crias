#include YSI\y_hooks

new Float:Hosp[8][3] =
{
    {2029.7653,-1402.8408,17.2528},     // Hosp Jefferson Los Santos
    {1172.8495,-1323.3513,15.3998},     // Hosp Market Los Santos
    {1607.3652,1815.8800,10.8203},      // Hosp Las Venturas
    {-318.8461,1049.0421,20.3403},      // Hosp Fort Carson
    {-1514.8762,2519.5337,56.0703},     // Hosp El Quebrados
    {-2655.0889,639.6584,14.4545},      // Hosp San Fierro
    {-2215.4927,-2287.0698,30.6250},    // Hosp Angel Pine
    {1244.7914,331.5576,19.5547}        // Hosp Montgomery
};

new Cidade_Que_Morreu[MAX_PLAYERS];

hook OnPlayerConnect(playerid)
{
    Cidade_Que_Morreu[playerid] = -1;
	return 1;
}

hook OnPlayerDeath(playerid, killerid, reason)
{
    if(Cidade_Que_Morreu[playerid] == -1)
    {
        Cidade_Que_Morreu[playerid] = PickupHospitalNext(playerid);
        SetSpawnInfo(playerid, 0, PlayerInfo[playerid][Skin], Hosp[Cidade_Que_Morreu[playerid]][0], Hosp[Cidade_Que_Morreu[playerid]][1], Hosp[Cidade_Que_Morreu[playerid]][2], 0, 0, 0, 0, 0, 0, 0);
        Cidade_Que_Morreu[playerid] = -1;
    }
    return 1;
}

PickupHospitalNext(playerid)
{
    new Float:dist, Float:ldist = 3000.0, hosp = 0;
    for(new i = 0; i < sizeof(Hosp); i++)
    {
        dist = GetPlayerDistanceFromPoint(playerid, Hosp[i][0], Hosp[i][1], Hosp[i][2]);
        if(dist < ldist)
        {
            ldist = dist;
            hosp = i;
        }
    }
    return hosp;
}
