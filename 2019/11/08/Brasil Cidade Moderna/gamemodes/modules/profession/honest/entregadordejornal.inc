#include <YSI\y_hooks>

enum JornalProxx
{
    Local[40],
    Float:JornalX,
    Float:JornalY,
    Float:JornalZ,
    ValorReceber
};

enum JornalProx
{
    RandomLocal[40],
    Float:RandomX,
    Float:RandomY,
    Float:RandomZ,
    VaiReceber
};

static const LocaisJornal[19][JornalProxx] =
{
    {"Marina", 852.1297,-1422.2274,13.7665, 110},
    {"Market", 1195.6843,-1017.1591,32.5469, 130},
    {"Market", 1234.0033,-1016.5063,32.6067, 120},
    {"Mulholland", 1247.0552,-908.7471,42.8828, 140},
    {"Mulholland", 1248.8364,-877.6268,42.8828, 160},
    {"Mulholland", 1290.2649,-897.1113,42.8828, 170},
    {"Mulholland", 1281.4331,-874.5957,42.9572, 150},
    {"Jefferson", 1905.9628,-1113.0104,26.6641, 180},
    {"Jefferson", 2022.8094,-1120.6379,26.4210, 200},
    {"Jefferson", 2091.9280,-1166.4626,26.5859, 180},
    {"Jefferson", 2111.0930,-1243.4509,25.8516, 190},
    {"Jefferson", 2147.6541,-1367.1768,25.6418, 210},
    {"East Beach", 2776.0256,-1245.9175,49.3598, 170},
    {"East Beach", 2147.6541,-1367.1768,25.6418, 210},
    {"Marina", 901.2523,-1471.0151,13.9762, 190},
    {"Marina", 767.3795,-1655.7631,5.6094, 250},
    {"Marina", 693.6930,-1705.7681,3.8195, 230},
    {"Marina", 692.9327,-1602.1597,15.0469, 180},
    {"Marina", 783.2158,-1464.5664,13.5469, 150}
};

new LocaisJornalPlayer[MAX_PLAYERS][JornalProx];
new bool:JornalBlock[MAX_PLAYERS];
new Jornal[MAX_PLAYERS];

hook OnPlayerCommandText(playerid, cmdtext[])
{
    if(strcmp(cmdtext, "/Pegarjornal", true)==0)                                    //EntregadorJornal
    {
        if(PlayerInfo[playerid][Profissao] != EntregadorJornal)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não tem permissão!");

        if(GetVehicleModel(GetPlayerVehicleID(playerid)) != 510)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não está em uma Mountain Bike!");

        if(!IsPlayerInRangeOfPoint(playerid, 20.0, 784.9813, -1345.0000, 13.1522))
            return SendClientMessage(playerid, Erro, "| ERRO | Você não está na sua HQ!");

        if(Jornal[playerid] != 0)
            return SendClientMessage(playerid, Erro, "| ERRO | Você já pegou jornal!");

        JornalBlock[playerid]=false;
        Jornal[playerid]=20;
        new rand = random(sizeof(LocaisJornal));
        format(LocaisJornalPlayer[playerid][RandomLocal],20,LocaisJornal[rand][Local]);
        LocaisJornalPlayer[playerid][RandomX] = LocaisJornal[rand][JornalX];
        LocaisJornalPlayer[playerid][RandomY] = LocaisJornal[rand][JornalY];
        LocaisJornalPlayer[playerid][RandomZ] = LocaisJornal[rand][JornalZ];
        LocaisJornalPlayer[playerid][VaiReceber] = LocaisJornal[rand][ValorReceber];
        SetPlayerRaceCheckpoint(playerid,1,LocaisJornal[rand][JornalX],LocaisJornal[rand][JornalY],LocaisJornal[rand][JornalZ],0,0,0,1.5);
        SendClientMessage(playerid, Branco, "| BCM-News | Você pegou 20 jornais, vá até o checkpoint {FF0000}vermelho {FFFFFF}marcado mo mini-mapa");
        return 1;
    }
    if(strcmp(cmdtext, "/cancelar", true)==0)
    {
        if(PlayerInfo[playerid][Profissao] != EntregadorJornal)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não tem permissão!");

        if(Jornal[playerid] == 0)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não tem nenhuma entrega pendente!");

        Jornal[playerid]=0;
        DisablePlayerRaceCheckpoint(playerid);
        SendClientMessage(playerid, Branco, "| BCM-News | Você cancelou suas entregas!");
        return 1;
    }
    return 0;
}

hook OnPlayerEnterRaceCheckpoint(playerid)
{
    if(PlayerInfo[playerid][Profissao] != EntregadorJornal && !IsPlayerInRangeOfPoint(playerid, 1.5, LocaisJornalPlayer[playerid][RandomX], LocaisJornalPlayer[playerid][RandomY], LocaisJornalPlayer[playerid][RandomZ]))
    {
        if(JornalBlock[playerid] == true)
            return SendClientMessage(playerid, Erro, "| ERRO | Você acabou de entregar, aguarde alguns segundos...!");

        Jornal[playerid]--;
        if(Jornal[playerid] > 0)
        {
            JornalBlock[playerid]=true;
            SetTimerEx("UnlockingNewspaper", 1000*60, false, "d", playerid);
            PlayerInfo[playerid][Dinheiro]=PlayerInfo[playerid][Dinheiro]+LocaisJornalPlayer[playerid][VaiReceber];
            GivePlayerMoney(playerid, LocaisJornalPlayer[playerid][VaiReceber]);
            TogglePlayerControllable(playerid, false);
            GameTextForPlayer(playerid, "~n~~r~Carregando Proxíma casa..." , 3000, 3);
            format(String, sizeof(String), "| BCM-News | Você entregou um jornal, e agora Você tem {FF0000}%d {FFFFFF}jornais!", Jornal[playerid]);
            SendClientMessage(playerid, Branco, String);
            format(String, sizeof(String), "| BCM-News | Você ganho {00C40A}$%d {FFFFFF}pela entrega localizada em {FF8000}%s", LocaisJornalPlayer[playerid][VaiReceber], LocaisJornalPlayer[playerid][RandomLocal]);
            SendClientMessage(playerid, Branco, String);
            new rand = random(sizeof(LocaisJornal));
            format(LocaisJornalPlayer[playerid][RandomLocal],40,LocaisJornal[rand][Local]);
            LocaisJornalPlayer[playerid][RandomX] = LocaisJornal[rand][JornalX];
            LocaisJornalPlayer[playerid][RandomY] = LocaisJornal[rand][JornalY];
            LocaisJornalPlayer[playerid][RandomZ] = LocaisJornal[rand][JornalZ];
            LocaisJornalPlayer[playerid][VaiReceber] = LocaisJornal[rand][ValorReceber];
            SetPlayerRaceCheckpoint(playerid,1,LocaisJornal[rand][JornalX],LocaisJornal[rand][JornalY],LocaisJornal[rand][JornalZ],0,0,0,1.5);

        } else if(Jornal[playerid] == 0) {

            JornalBlock[playerid]=false;
            DisablePlayerRaceCheckpoint(playerid);
            PlayerInfo[playerid][Dinheiro]=PlayerInfo[playerid][Dinheiro]+LocaisJornalPlayer[playerid][VaiReceber];
            GivePlayerMoney(playerid, LocaisJornalPlayer[playerid][VaiReceber]);
            TogglePlayerControllable(playerid, false);
            GameTextForPlayer(playerid, "~n~~r~Carregando Proxíma casa..." , 3000, 3);
            SendClientMessage(playerid, Branco, "| BCM-News | Você entregou o último jornal!");
            SendClientMessage(playerid, Branco, "| BCM-News | Para pegar mas jornais, volte para HQ e pegue mais");
        }
    }
	return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    Jornal[playerid]=0;
    JornalBlock[playerid] = false;
	return 1;
}

forward UnlockingNewspaper(playerid);
public UnlockingNewspaper(playerid)
{
    JornalBlock[playerid] = false;
    TogglePlayerControllable(playerid, true);
    return 1;
}
