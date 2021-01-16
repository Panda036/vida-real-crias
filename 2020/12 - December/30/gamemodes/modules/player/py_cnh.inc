#include YSI\y_hooks

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == main_cnh && response)
    {
        switch(listitem)
        {
            case 0:
            {
                if(IsPlayerCnhType(playerid, "a"))
                    return SendClientMessage(playerid, Erro, "Você já possui CNH A");

                SchelduingCNH(playerid, "a", 800);
            }
            case 1:
            {
                if(IsPlayerCnhType(playerid, "b"))
                    return SendClientMessage(playerid, Erro, "Você já possui CNH B");

                SchelduingCNH(playerid, "b", 1600);
                return 1;
            }
            case 2:
            {
                if(IsPlayerCnhType(playerid, "c"))
                    return SendClientMessage(playerid, Erro, "Você já possui CNH C");

                SchelduingCNH(playerid, "c", 2400);
                return 1;
            }
            case 3:
            {
                if(IsPlayerCnhType(playerid, "cht"))
                    return SendClientMessage(playerid, Erro, "Você já possui CNH CHT");

                SchelduingCNH(playerid, "cht", 7000);
                return 1;
            }
            case 4:
            {
                if(IsPlayerCnhType(playerid, "arrais"))
                    return SendClientMessage(playerid, Erro, "Você já possui CNH Arrais");

                SchelduingCNH(playerid, "arrais", 3600);
                return 1;
            }
        }
        return 1;
    }
    if(dialogid == main_fines && response)
    {
        new price[MAX_PLAYERS], fines_x[MAX_PLAYERS];

        switch(listitem)
        {
            case 0:
            {
                if(!IsPlayerCnhType(playerid, "a"))
                    return SendClientMessage(playerid, Erro, "Você não possui CNH Categoria A");

                if(!PlayerInfo[playerid][fines_a])
                    return SendClientMessage(playerid, Erro, "Você não tem multa pendente");

                price[playerid] = PlayerInfo[playerid][fines_a] * 800;

                if(PlayerInfo[playerid][Dinheiro] < price[playerid])
                    return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

                fines_x[playerid] = PlayerInfo[playerid][fines_arrais];
                PlayerInfo[playerid][fines_a] = 0;
            }
            case 1:
            {
                if(!IsPlayerCnhType(playerid, "b"))
                    return SendClientMessage(playerid, Erro, "Você não possui CNH Categoria B");

                if(!PlayerInfo[playerid][fines_b])
                    return SendClientMessage(playerid, Erro, "Você não tem multa pendente");

                price[playerid] = PlayerInfo[playerid][fines_b] * 1600;

                if(PlayerInfo[playerid][Dinheiro] < price[playerid])
                    return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

                fines_x[playerid] = PlayerInfo[playerid][fines_b];
                PlayerInfo[playerid][fines_b] = 0;
            }
            case 2:
            {
                if(!IsPlayerCnhType(playerid, "c"))
                    return SendClientMessage(playerid, Erro, "Você não possui CNH Categoria C");

                if(!PlayerInfo[playerid][fines_c])
                    return SendClientMessage(playerid, Erro, "Você não tem multa pendente");

                price[playerid] = PlayerInfo[playerid][fines_c] * 2400;

                if(PlayerInfo[playerid][Dinheiro] < price[playerid])
                    return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

                fines_x[playerid] = PlayerInfo[playerid][fines_c];
                PlayerInfo[playerid][fines_c] = 0;
            }
            case 3:
            {
                if(!IsPlayerCnhType(playerid, "cht"))
                    return SendClientMessage(playerid, Erro, "Você não possui CNH Categoria CHT");

                if(!PlayerInfo[playerid][fines_cht])
                    return SendClientMessage(playerid, Erro, "Você não tem multa pendente");

                price[playerid] = PlayerInfo[playerid][fines_cht] * 7000;

                if(PlayerInfo[playerid][Dinheiro] < price[playerid])
                    return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

                fines_x[playerid] = PlayerInfo[playerid][fines_cht];
                PlayerInfo[playerid][fines_cht] = 0;
            }
            case 4:
            {
                if(!IsPlayerCnhType(playerid, "arrais"))
                    return SendClientMessage(playerid, Erro, "Você não possui CNH Categoria C");

                if(!PlayerInfo[playerid][fines_arrais])
                    return SendClientMessage(playerid, Erro, "Você não tem multa pendente");

                price[playerid] = PlayerInfo[playerid][fines_arrais] * 3600;

                if(PlayerInfo[playerid][Dinheiro] < price[playerid])
                    return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

                fines_x[playerid] = PlayerInfo[playerid][fines_arrais];
                PlayerInfo[playerid][fines_arrais] = 0;
            }
        }

        format(String, MAX_STRING, "Você pagou %d multa(s) no valor total de %s", fines_x[playerid], IsMoney(price[playerid], "."));
        SendClientMessage(playerid, Yellow, String);

        PlayerInfo[playerid][Dinheiro] -= price[playerid];
        UpdatePlayerMoney(playerid);
        UpdateCNH(playerid);
        return 1;
    }
    return 1;
}

