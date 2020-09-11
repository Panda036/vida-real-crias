#include YSI\y_hooks

new bool:locate[MAX_PLAYERS];
new maplocate[MAX_PLAYERS];

hook OnPlayerDisconnect(playerid, reason)
{
    if(locate[playerid])
    {
        locate[playerid] = false;
        KillTimer(TimerProcurando[playerid]);
        DestroyDynamicMapIcon(maplocate[playerid]);
    }
    return 1;
}

forward OnPlayerLocate(playerid, id);
public OnPlayerLocate(playerid, id)
{
    if(IsValidDynamicMapIcon(maplocate[id])) DestroyDynamicMapIcon(maplocate[id]);

    if(!PlayerInfo[id][Logado] || PrisonEnum[id][pCadeia])
    {
        locate[id] = false;
        KillTimer(TimerProcurando[id]);

        SendClientMessage(playerid, Erro, (!PlayerInfo[id][Logado]) ? ("O(A) Jogador(a) que você localizou desconectou-se") : ("O(A) Jogador(a) que você localizou foi preso"));
        return 1;
    }
    if(GetDistanceBetweenPlayers(playerid, id) <= 1.5)
    {
        locate[id] = false;
        KillTimer(TimerProcurando[id]);

        SendClientMessage(playerid, Green, "Você chegou até o procurado(a)");
        return 1;
    }

    new Float:x, Float:y, Float:z;

    GetPlayerPos(id, x, y, z);

    maplocate[id] = CreateDynamicMapIcon(x, y, z, 0, 0xFF0000AA, -1, -1, playerid, -1.0, MAPICON_GLOBAL);

    TimerProcurando[id] = SetTimerEx("OnPlayerLocate", 500, false, "dd", playerid, id);
    return 1;
}
