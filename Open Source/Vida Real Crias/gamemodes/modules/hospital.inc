#include YSI\y_hooks

hook OnPlayerConnect(playerid)
{
    Cidade_Que_Morreu[playerid] = -1;
	return 1;
}

hook OnPlayerSpawn(playerid)
{
    TextDrawHideForPlayer(playerid, TDDetonated[0]);
    TextDrawHideForPlayer(playerid, TDDetonated[1]);

    if(Cidade_Que_Morreu[playerid] != -1)
    {
        if(!PlayerInfo[playerid][healthplan]){
            PlayerInfo[playerid][SaldoBancario] -= 1000;
            SetIntQuery(playerid, "Identidade", "saldobancario", PlayerInfo[playerid][SaldoBancario]);
        }

        SendClientMessage(playerid, 0x008000AA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        SendClientMessage(playerid, 0xFFFFFFAA, (PlayerInfo[playerid][healthplan] ? ("Você tem plano de saúde") : ("Você não tem plano de saúde")));
        SendClientMessage(playerid, 0xFFFFFFAA, (PlayerInfo[playerid][healthplan] ? ("Seu plano de saúde cobriu todas as suas necessidades médicas") : ("Foi retirado {FF4000}$1.000{FFFFFF} de sua conta bancária")));
        SendClientMessage(playerid, 0x008000AA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        Cidade_Que_Morreu[playerid] = -1;
    }
    return 1;
}

stock PickupHospitalNext(playerid)
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
