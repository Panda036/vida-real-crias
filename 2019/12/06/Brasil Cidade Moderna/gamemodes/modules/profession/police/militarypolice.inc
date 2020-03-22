#include YSI\y_hooks

new bool:Algemado[MAX_PLAYERS];
new bool:Abordado[MAX_PLAYERS];
new bool:Perseguicao[MAX_PLAYERS];
new bool:localizado[MAX_PLAYERS];

new TimerProcurando[MAX_PLAYERS];
new PerseguicaoTime[MAX_PLAYERS];

hook OnPlayerDisconnect(playerid, reason)
{
    if(Abordado[playerid])
    {
        //15 Minutos
        PrisonEnum[playerid][pTempo]=15*60;
        format(PrisonEnum[playerid][pMotivo], 30, "Saiu em abordagem"); //Motivo
        return 1;
    }
    if(Algemado[playerid])
    {
        //30 Minutos
        PrisonEnum[playerid][pTempo]=30*60;
        format(PrisonEnum[playerid][pMotivo], 30, "Saiu em abordagem e algemado"); //Motivo
        return 1;
    }
    if(Perseguicao[playerid])
    {
        //45 Minutos
        PrisonEnum[playerid][pTempo]=30*60;
        format(PrisonEnum[playerid][pMotivo], 30, "Saiu em perseguição"); //Motivo
        return 1;
    }
	return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(PRESSED(KEY_YES))
    {
        if(IsPlayerInRangeOfPoint(playerid, 1.5, 254.1715,74.3339,1003.6406) && PlayerInfo[playerid][Profissao] == PoliciaMunicipal)
        {
            SetPlayerSkin(playerid, 287);
            SetPlayerArmour(playerid, 100);
            GivePlayerWeapon(playerid, 31, 2000);
            GivePlayerWeapon(playerid, 28, 2000);
            GivePlayerWeapon(playerid, 24, 2000);
        }
        else if(IsPlayerInRangeOfPoint(playerid, 1.5, 254.1715,74.3339,1003.6406) && PlayerInfo[playerid][Profissao] != PoliciaMunicipal)
        {
            SendClientMessage(playerid, Erro, "| ERRO | Você não tem permissão!");
        }
    }
    else if(newkeys == KEY_SECONDARY_ATTACK)
    {
        if(IsPlayerHelper(playerid) || PlayerInfo[playerid][Profissao] == PoliciaMunicipal)
        {
            OpeningPolicePort(playerid);
        }
    }
	return 1;
}

forward GPSUpdate(playerid, playerid2);
public GPSUpdate(playerid, playerid2)
{
    if(PlayerInfo[playerid2][Logado] == false)
        return SendClientMessage(playerid, Verde_Escurinho, "GPS:{FFFFFF} O(A) Jogador(a) desconectou-se!");

    if(PrisonEnum[playerid2][pCadeia] != 0)
        return SendClientMessage(playerid, Verde_Escurinho, "GPS:{FFFFFF} O(A) Jogador(a) foi preso!");

    DisablePlayerCheckpoint(playerid);
    GetPlayerPos(playerid2, X, Y, Z);
    SetPlayerCheckpoint(playerid, X, Y, Z, 1.0);
    if(GetDistanceBetweenPlayers(playerid,playerid2) <= 2.0)
    {
        DisablePlayerCheckpoint(playerid);
        KillTimer(TimerProcurando[playerid2]);
    	localizado[playerid]=false;
        SendClientMessage(playerid, Verde_Escurinho, "GPS:{FFFFFF} Você chegou até o procurado(a)!");
    }
    return 1;
}
