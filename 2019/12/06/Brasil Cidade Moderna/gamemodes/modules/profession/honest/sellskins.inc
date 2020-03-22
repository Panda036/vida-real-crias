#include YSI\y_hooks

new bool:Refused[MAX_PLAYERS],
    bool:Accepted[MAX_PLAYERS],
    bool:OfferSkin[MAX_PLAYERS],
    CountOS[MAX_PLAYERS] = 0;

hook OnPlayerDisconnect(playerid, reason)
{
    Refused[playerid] = false;
    Accepted[playerid] = false;
    OfferSkin[playerid] = false;
    CountOS[playerid] = 0;
	return 1;
}

forward SkinOffer(playerid, playeridoffer, idskin, ammount);
public SkinOffer(playerid, playeridoffer, idskin, ammount)
{
    if(OfferSkin[playeridoffer])
    {
        if(CountOS[playeridoffer] == 10)
        {
            SendClientMessage(playeridoffer, 0x00B57DAA, "| INFO | Seu tempo de aceitar ou recusar acabou!");
            CountOS[playeridoffer] = 0;
            OfferSkin[playeridoffer] = false;
            return 1;
        }

        CountOS[playeridoffer]++;
        SetTimerEx("SkinOffer", 1000, false, "iiii", playerid, playeridoffer, idskin, ammount);

        if(CountOS[playeridoffer] == 1 || CountOS[playeridoffer] == 3 || CountOS[playeridoffer] == 5 || CountOS[playeridoffer] == 7 || CountOS[playeridoffer] == 9)
        {
            SendClientMessage(playeridoffer, 0x00B57DAA, "| INFO | Para aceitar ou recusar digite ( /aceitar ou /recusar )");
        }
    }
    else
    {
        if(Accepted[playeridoffer])
        {
            if(PlayerInfo[playeridoffer][Dinheiro] < ammount)
                return SendClientMessage(playeridoffer, Erro, "| ERRO | Você não tem esse dinheiro em mãos!");

            SendClientMessage(playeridoffer, 0xFFD993AA, "| INFO | Skin comprada com sucesso!");
            SendClientMessage(playerid, 0xFFD993AA, "| INFO | Skin vendida com sucesso!");

            Accepted[playeridoffer] = false;
            PlayerInfo[playerid][Dinheiro] += ammount;
            PlayerInfo[playeridoffer][Dinheiro] -= ammount;
            PlayerInfo[playeridoffer][Skin] = idskin;
            SetPlayerSkin(playeridoffer, PlayerInfo[playeridoffer][Skin]);
            UpdatePlayerMoney(playerid);
            UpdatePlayerMoney(playeridoffer);
        }
        else if(Refused[playeridoffer])
        {
            format(String, sizeof(String), "| INFO | O Jogador(a) %s[%d] recusou a compra de skin!", PlayerInfo[playeridoffer][Nome], playeridoffer);
            SendClientMessage(playerid, 0xFF0000AA, String);
            SendClientMessage(playeridoffer, 0xFF0000AA, "| INFO | Você recusou a compra de skin!");
            Refused[playeridoffer] = false;
        }
    }
    return 1;
}
