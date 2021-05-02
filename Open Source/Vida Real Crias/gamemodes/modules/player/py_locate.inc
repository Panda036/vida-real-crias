#include YSI\y_hooks

new bool:locate[MAX_PLAYERS];
new maplocate[MAX_PLAYERS];

forward OnPlayerLocate(playerid, id);
public OnPlayerLocate(playerid, id)
{
    if(IsValidDynamicMapIcon(maplocate[playerid])) DestroyDynamicMapIcon(maplocate[playerid]);

    if(!PlayerInfo[id][Logado] || PrisonEnum[id][pCadeia])
    {
        locate[playerid] = false;
        KillTimer(TimerProcurando[playerid]);

        return SendClientMessage(playerid, Erro, (!PlayerInfo[id][Logado]) ? ("O(A) Jogador(a) que você localizou desconectou-se") : ("O(A) Jogador(a) que você localizou foi preso"));
    }
    else if(GetDistanceBetweenPlayers(playerid, id) <= 2.0)
    {
        locate[playerid] = false;
        KillTimer(TimerProcurando[playerid]);

        return SendClientMessage(playerid, Green, "Você chegou até o(a) localizado(a)");
    }

    new Float:x, Float:y, Float:z;

    GetPlayerPos(id, x, y, z);

    maplocate[playerid] = CreateDynamicMapIcon(x, y, z, 0, 0xFF0000AA, -1, -1, playerid, -1.0, MAPICON_GLOBAL);
    return 1;
}
