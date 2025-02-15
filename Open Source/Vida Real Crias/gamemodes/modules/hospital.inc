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
        SendClientMessage(playerid, 0xFFFFFFAA, (PlayerInfo[playerid][healthplan] ? ("Voc� tem plano de sa�de") : ("Voc� n�o tem plano de sa�de")));
        SendClientMessage(playerid, 0xFFFFFFAA, (PlayerInfo[playerid][healthplan] ? ("Seu plano de sa�de cobriu todas as suas necessidades m�dicas") : ("Foi retirado {FF4000}$1.000{FFFFFF} de sua conta banc�ria")));
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
