#include YSI\y_hooks

enum NewspaperNext
{
    nnLocations[40],
    Float:nnPosX,
    Float:nnPosY,
    Float:nnPosZ,
    nnGetWork
};

new NL[19][NewspaperNext] = //NewspaperLocations
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

enum JornalProx
{
    RandomLocal[40],
    Float:RandomX,
    Float:RandomY,
    Float:RandomZ,
    VaiReceber
};

new PNL[MAX_PLAYERS][JornalProx]; //PlayerNewspaperLocations

new Newspaper[MAX_PLAYERS],
    bool:BlockNewspaper[MAX_PLAYERS];

hook OnPlayerDisconnect(playerid, reason)
{
    Newspaper[playerid] = 0;
    BlockNewspaper[playerid] = false;
	return 1;
}

hook OnPlayerEnterRaceCheckpoint(playerid)
{
    if(PlayerInfo[playerid][Profissao] == EntregadorJornais && IsPlayerInRangeOfPoint(playerid, 2.0, PNL[playerid][RandomX], PNL[playerid][RandomY], PNL[playerid][RandomZ]))
    {
        if(BlockNewspaper[playerid] == true)
            return SendClientMessage(playerid, Erro, "| ERRO | Você acabou de entregar, aguarde alguns segundos...!");

        Newspaper[playerid]--;
        if(Newspaper[playerid] > 0)
        {
            format(String, sizeof(String), "| BCM-News | Você entregou um jornal, e agora tem {FF0000}%d {FFFFFF}jornais!", Newspaper[playerid]);
            SendClientMessage(playerid, Branco, String);
            format(String, sizeof(String), "| BCM-News | Você recebeu {00C40A}$%d {FFFFFF}pela entrega localizada em {FF8000}%s", PNL[playerid][VaiReceber], PNL[playerid][RandomLocal]);
            SendClientMessage(playerid, Branco, String);

            BlockNewspaper[playerid] = true;

            SetTimerEx("UnlockingNewspaper", 1000*60, false, "d", playerid);

            PlayerInfo[playerid][Dinheiro] += PNL[playerid][VaiReceber];
            UpdatePlayerMoney(playerid);

            new rand = random(sizeof(NL));

            format(PNL[playerid][RandomLocal], 40, NL[rand][nnLocations]);
            PNL[playerid][RandomX] = NL[rand][nnPosX];
            PNL[playerid][RandomY] = NL[rand][nnPosY];
            PNL[playerid][RandomZ] = NL[rand][nnPosZ];
            PNL[playerid][VaiReceber] = NL[rand][nnGetWork];

            SetPlayerRaceCheckpoint(playerid, 1, NL[rand][nnPosX], NL[rand][nnPosY], NL[rand][nnPosZ], 0, 0, 0, 2.0);

        } else if(Newspaper[playerid] == 0) {

            BlockNewspaper[playerid] = false;
            DisablePlayerRaceCheckpoint(playerid);
            GivePlayerMoney(playerid, PNL[playerid][VaiReceber]);
            PlayerInfo[playerid][Dinheiro] += PNL[playerid][VaiReceber];
            SendClientMessage(playerid, Branco, "| BCM-News | Você entregou o último jornal!");
            SendClientMessage(playerid, Branco, "| BCM-News | Para pegar mas jornais, volte para HQ e pegue mais");
        }
    }
	return 1;
}

forward UnlockingNewspaper(playerid);
public UnlockingNewspaper(playerid)
{
    return BlockNewspaper[playerid] = false;
}
