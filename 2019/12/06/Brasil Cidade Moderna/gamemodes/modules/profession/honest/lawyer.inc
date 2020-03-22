#include YSI\y_hooks

new bool:AdvogadoOfertou[MAX_PLAYERS],
    bool:AdvogadoRecusou[MAX_PLAYERS],
    bool:AdvogadoAceitou[MAX_PLAYERS],
    ContagemAdvogado[MAX_PLAYERS] = 0;

hook OnGameModeInit()
{
    Create3DTextLabel("{8000FF}Advogados\n{FFFFFF}Digite: {FF0000}/Profissão{FFFFFF} e veja os comandos", 0xFFFFFFFF, 252.1618, 67.7849, 1003.6478, 10.0, 0);
    CreatePickup(1239, 1, 252.1618, 67.7849, 1003.6478);
    return 1;
}

forward LowyerOffer(playerid, playeridoffer);
public LowyerOffer(playerid, playeridoffer)
{
    if(AdvogadoOfertou[playeridoffer])
    {
        if(ContagemAdvogado[playeridoffer] == 10)
        {
            SendClientMessage(playeridoffer, 0x00B57DAA, "| INFO | Seu tempo de aceitar ou recusar acabou!");
            ContagemAdvogado[playeridoffer] = 0;
            AdvogadoOfertou[playeridoffer] = false;
            return 1;
        }

        ContagemAdvogado[playeridoffer]++;
        SetTimerEx("LowyerOffer", 1000, false, "ii", playerid, playeridoffer);

        if(ContagemAdvogado[playeridoffer] == 1 || ContagemAdvogado[playeridoffer] == 3 || ContagemAdvogado[playeridoffer] == 5 || ContagemAdvogado[playeridoffer] == 7 || ContagemAdvogado[playeridoffer] == 9)
        {
            SendClientMessage(playeridoffer, 0x00B57DAA, "| INFO | Para aceitar ou recusar digite ( /aceitar ou /recusar )");
        }
        return 1;
    }
    else
    {
        if(AdvogadoAceitou[playeridoffer])
        {
            AdvogadoAceitou[playeridoffer] = false;

            if(PlayerInfo[playeridoffer][SaldoBancario] < (PlayerInfo[playeridoffer][Estrelas] * 100))
            {
                format(String, sizeof(String), "| ERRO | O(A) Jogador(a) %s[%d] não tem saldo bancário suficiente!", PlayerInfo[playeridoffer][Nome], playeridoffer);
                SendClientMessage(playerid, Erro, String);
                SendClientMessage(playeridoffer, Erro, "| ERRO | Você não tem saldo bancário suficiente!");
                return 1;
            }

            KillTimer(TempoPreso[playerid]);
            SetPlayerInterior(playeridoffer, 0);
            SetPlayerHealth(playeridoffer, 100);
            SetPlayerPos(playeridoffer, 1554.8657, -1675.6693, 16.1953);

            PlayerInfo[playeridoffer][SaldoBancario] -= (PlayerInfo[playeridoffer][Estrelas] * 100);
            PlayerInfo[playerid][SaldoBancario] += (PlayerInfo[playeridoffer][Estrelas] * 100);

            format(PrisonEnum[playeridoffer][pMotivo], 1, "");
            PrisonEnum[playeridoffer][pCadeia] = 0;
            PrisonEnum[playeridoffer][pTempo] = 0;
            PlayerInfo[playeridoffer][Estrelas] = 0;
            format(String, sizeof(String), "%d", PlayerInfo[playerid][Estrelas]);
            PlayerTextDrawSetString(playerid, PlayerBarStatus[playerid][1], String);
            PlayerTextDrawShow(playerid, PlayerBarStatus[playerid][1]);

            mysql_format(IDConexao, String, sizeof(String), "DELETE FROM `Prisoes` WHERE `Nome`='%e'", PlayerInfo[playeridoffer][Nome]);
            mysql_query(IDConexao, String);

            PlayerTextDrawHide(playeridoffer, TempoPresidio[playeridoffer][2]);
            PlayerTextDrawHide(playeridoffer, TempoPresidio[playeridoffer][1]);
            PlayerTextDrawHide(playeridoffer, TempoPresidio[playeridoffer][0]);

            GameTextForPlayer(playeridoffer, "~w~Solto!", 3000, 0);
            SendClientMessage(playeridoffer, 0xFFD993AA, "| INFO | Você pagou a sua fiança e está livre novamente!");
            format(String, sizeof(String), "| INFO | O(A) Jogador(a) %s[%d] aceitou sua oferta, seu dinheiro foi para sua conta bancária!", PlayerInfo[playeridoffer][Nome], playeridoffer);
            SendClientMessage(playerid, 0xFFD993AA, String);
        }
        else if(AdvogadoRecusou[playeridoffer])
        {
            format(String, sizeof(String), "| INFO | O Jogador(a) %s[%d] recusou a oferta!", PlayerInfo[playeridoffer][Nome], playeridoffer);
            SendClientMessage(playerid, 0xFF0000AA, String);
            SendClientMessage(playeridoffer, 0xFF0000AA, "| INFO | Você recusou a oferta!");
            AdvogadoRecusou[playeridoffer] = false;
        }
    }
    return 1;
}
