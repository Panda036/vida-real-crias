#include YSI\y_hooks

new bool:AdvogadoOfertou[MAX_PLAYERS];
new bool:AdvogadoRecusou[MAX_PLAYERS];
new bool:AdvogadoAceitou[MAX_PLAYERS];
new ContagemAdvogado[MAX_PLAYERS];

/*enum e_skinslawyer
{
    sl_sex[10],
    sl_skinid
};

new SkinsLawyer[17][e_skinslawyer] =
{
    {"Feminino", 11},
    {"Masculino", 59},
    {"Feminino", 141},
    {"Feminino", 150},
    {"Masculino", 153},
    {"Masculino", 163},
    {"Masculino", 164},
    {"Masculino", 165},
    {"Masculino", 166},
    {"Feminino", 172},
    {"Masculino", 185},
    {"Masculino", 186},
    {"Masculino", 187},
    {"Feminino", 194},
    {"Masculino", 227},
    {"Masculino", 228},
    {"Masculino", 240}
};*/

hook OnGameModeInit()
{
    CreateDynamic3DTextLabel("{8000FF}Advogados\n{FFFFFF}Digite: {FF0000}/Profissão{FFFFFF} e veja os comandos", 0xFFFFFFFF, 252.1618, 67.7849, 1003.6478, 10.0);
    CreatePickup(1239, 1, 252.1618, 67.7849, 1003.6478);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    AdvogadoOfertou[playerid] = false;
    AdvogadoRecusou[playerid] = false;
    AdvogadoAceitou[playerid] = false;
    ContagemAdvogado[playerid] = 0;
    return 1;
}

forward OnPlayerLawyerOffer(playerid, playeridoffer);
public OnPlayerLawyerOffer(playerid, playeridoffer)
{
    if(AdvogadoOfertou[playeridoffer])
    {
        if(ContagemAdvogado[playeridoffer] == 10)
        {
            SendClientMessage(playeridoffer, 0x00B57DAA, "Seu tempo de aceitar ou recusar acabou");
            ContagemAdvogado[playeridoffer] = 0;
            AdvogadoOfertou[playeridoffer] = false;
            return 1;
        }

        ContagemAdvogado[playeridoffer]++;
        SetTimerEx("OnPlayerLawyerOffer", 1000, false, "dd", playerid, playeridoffer);

        if(ContagemAdvogado[playeridoffer] == 1 || ContagemAdvogado[playeridoffer] == 3 || ContagemAdvogado[playeridoffer] == 5 || ContagemAdvogado[playeridoffer] == 7 || ContagemAdvogado[playeridoffer] == 9)
        {
            SendClientMessage(playeridoffer, 0x00B57DAA, "Para aceitar ou recusar digite ( /aceitar ou /recusar )");
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
                SendClientMessage(playerid, Erro, "O(A) Jogador(a) não tem dinheiro o suficiente");
                SendClientMessage(playeridoffer, Erro, "Você não tem saldo bancário suficiente");
                return 1;
            }

            PrisonEnum[playeridoffer][pTempo] = 0; //Automaticamente será solto

            PlayerInfo[playeridoffer][SaldoBancario] -= (PlayerInfo[playeridoffer][Estrelas] * 100);
            PlayerInfo[playerid][SaldoBancario] += (PlayerInfo[playeridoffer][Estrelas] * 100);

            SendClientMessage(playeridoffer, 0xFFD993AA, "Você aceitou à oferta");
            SendClientMessage(playerid, 0xFFD993AA, "Sua oferta foi aceita");
        }
        else
        {
            SendClientMessage(playerid, 0xFFD993AA, "Sua oferta foi recusada");
            SendClientMessage(playeridoffer, 0xFFD993AA, "Você recusou à oferta");
            AdvogadoRecusou[playeridoffer] = false;
        }
    }
    return 1;
}

/******************************************************************************/
/*****************************| COMMANDS LAWYER |******************************/
/******************************************************************************/

CMD:soltar(playerid, params[])
{
    if(PlayerInfo[playerid][Profissao] != lawyer)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsPlayerInRangeOfPoint(playerid, 2.0, 252.1618, 67.7849, 1003.6478))
        return SendClientMessage(playerid, Erro, "Você não está em nenhum departamento de polícia");

    new id;

    if(sscanf(params, "u", id))
        return SendClientMessage(playerid, Erro, "Digite: /Soltar [id/nome]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    if(PrisonEnum[id][pTempo] == 0)
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) não está preso");

    if(!strcmp(PrisonEnum[id][pCadeia], "Federal"))
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) foi preso pela admininstração");

    if(AdvogadoOfertou[id])
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) já recebeu uma oferta");

    format(String, MAX_STRING, "Você ofereceu ao jogador(a) %s[%d] a liberdade no valor de $%s", PlayerInfo[id][Nome], id, IsMoney(PlayerInfo[id][Estrelas] * 100, "."));
    SendClientMessage(playerid, 0x8000FFAA, String);
    format(String, MAX_STRING, "O(A) Advogado(a) %s[%d] está te oferecendo  a liberdade no valor de $%s", PlayerInfo[playerid][Nome], playerid, IsMoney(PlayerInfo[id][Estrelas] * 100, "."));
    SendClientMessage(id, 0x8000FFAA, String);

    AdvogadoOfertou[id] = true;
    OnPlayerLawyerOffer(playerid, id);
	return 1;
}
