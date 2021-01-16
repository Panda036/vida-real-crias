/*

12,5% Acessório RARO;
12,5% VIP;
12,5% Level;
12,5% Reais In-Game;
50% Moedas In-Game;

*/

#if EVENT_GIFT

#include YSI\y_hooks

#define GIFT_TIME_MIN   (60-1)
#define GIFT_TIME_SEC   (60-1)
#define MAX_GIFTS       (40)

hook OnPlayerConnect(playerid)
{
    tg_min[playerid] = GIFT_TIME_MIN;
    tg_sec[playerid] = GIFT_TIME_SEC;

    t_gift[playerid] = SetTimerEx("OnPlayerGift", 1000, true, "d", playerid);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    KillTimer(t_gift[playerid]);
    return 1;
}

forward OnPlayerGift(playerid);
public OnPlayerGift(playerid)
{
    if(!PlayerInfo[playerid][Logado]) return 0;

    if(tg_min[playerid] == 0 && tg_sec[playerid] == 0) GiveGifts(playerid, random(MAX_GIFTS));

    if(tg_sec[playerid] == -1)
    {
        if(tg_min[playerid] == 0)
        tg_min[playerid] = GIFT_TIME_MIN + 1;
        tg_sec[playerid] = GIFT_TIME_SEC;
        tg_min[playerid]--;
    }

    format(String, 20, "%02d:%02d", tg_min[playerid], tg_sec[playerid]);
    PlayerTextDrawSetString(playerid, TDPlayerGift[playerid][0], String);
    tg_sec[playerid]--;
    return 1;
}

stock GiveGifts(playerid, giftid)
{
    switch(giftid)
    {
        case 0..4:
        {
            new query[200];

            mysql_format(IDConexao, query, 200, "SELECT `model` FROM `Accessories` WHERE `model`='18728' AND `id_contas`='%d'", PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, query);

            if(cache_num_rows())
                return GiveGifts(playerid, 20);

            for(new slot = 0; slot < MAX_ACCESSORIES; slot++)
            {
                if(!ao[playerid][slot][ao_model])
                {
                    InsertAccessory(playerid, slot, CHRISTMAS_HAT, 1, 100000);

                    SendClientMessage(playerid, White, "<!> {FFFF00}Presente - Você ganhou o acessório Gorro Natalino");
                    return 1;
                }
            }

            SendClientMessage(playerid, Erro, "Você não ganhou acessório RARO, acessório cheio!");
        }
        case 10..14:
        {
            if(IsPlayerIntern(playerid))
                return GiveGifts(playerid, (giftid += 10));

            OnPlayerGiveVIP(playerid, 1, 0);

            SendClientMessage(playerid, White, "<!> {FFFF00}Presente - Você ganhou +1 dia de VIP");
        }
        case 20..24:
        {
            PlayerInfo[playerid][Reais] += 1;
            UpdatePlayerReais(playerid);

            SendClientMessage(playerid, White, "<!> {FFFF00}Presente - Você ganhou +1 Real");
        }
        case 30..34:
        {
            PlayerInfo[playerid][Level] += 1;
            SetPlayerScore(playerid, PlayerInfo[playerid][Level]);
            UpdatePlayerLevel(playerid);

            SendClientMessage(playerid, White, "<!> {FFFF00}Presente - Você ganhou +1 Level");
        }
        default:
        {
            new value = random(5000);

            PlayerInfo[playerid][Dinheiro] += value;
            UpdatePlayerMoney(playerid);

            format(String, MAX_STRING, "<!> {FFFF00}Presente - Você ganhou $%s", IsMoney(value, "."));
            SendClientMessage(playerid, White, String);
        }
    }

    PlayerPlaySound(playerid, 1057, 0.0, 0.0, 10.0);
    return 1;
}

#endif
