#include YSI\y_hooks

enum e_aa
{
    aa_code[5],
    aa_timer,
    aa_timerkick,
    bool:aa_afk,
    Float:aa_life
};

new AntiAfk[MAX_PLAYERS][e_aa];

hook OnPlayerConnect(playerid)
{
    AntiAfk[playerid][aa_timer] = SetTimerEx("OnPlayerTimerAFK", 900000, true, "d", playerid);
	return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    KillTimer(AntiAfk[playerid][aa_timerkick]);
    KillTimer(AntiAfk[playerid][aa_timer]);
    AntiAfk[playerid][aa_afk] = false;
    AntiAfk[playerid][aa_code] = 0;
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == antiiafk && response)
    {
        if(!strlen(inputtext)) return 0;

        if(strcmp(AntiAfk[playerid][aa_code], inputtext, true))
            return SendClientMessage(playerid, Erro, "Código errado!");

        HideTDAntiAfk(playerid);

        PlayerPlaySound(playerid, 1057, 0, 0, 0);

        AntiAfk[playerid][aa_afk] = false;

        KillTimer(AntiAfk[playerid][aa_timerkick]);

        UPRelogio[playerid] = SetTimerEx("ClockUP", 1000, true, "d", playerid);
        AntiAfk[playerid][aa_timer] = SetTimerEx("OnPlayerTimerAFK", 600000, true, "d", playerid);

        if(IsArena[playerid])
        {
            SetPlayerHealth(playerid, AntiAfk[playerid][aa_life]);
        }

        SendClientMessage(playerid, White, "Anti-Afk desbloqueado, agora você pode voltar a jogar normalmente");
        return 1;
    }
    return 1;
}

stock ClickTextDrawAntiAfk(playerid, PlayerText:playertextid)
{
    if(playertextid == TDPlayerAntiAfk[playerid][1])
    {
        format(String, sizeof(String), "{FFFFFF}Digite abaixo o código \"{FF0000}%s{FFFFFF}\" \n\n{FF0000}Obs{FFFFFF}: Escreva igual mostra acima!! Tem diferença entre maiuscula/minuscula.", AntiAfk[playerid][aa_code]);
        ShowPlayerDialog(playerid, antiiafk, DIALOG_STYLE_INPUT, "{FF0000}Anti-Afk", String, "Continuar", "Cancelar");
        return 1;
    }
    return 1;
}

forward OnPlayerTimerAFK(playerid);
public OnPlayerTimerAFK(playerid)
{
    if(!PlayerInfo[playerid][Logado] || AntiAfk[playerid][aa_afk]) return 0;

    if(IsArena[playerid])
    {
        GetPlayerHealth(playerid, AntiAfk[playerid][aa_life]);
        SetPlayerHealth(playerid, 99999);
    }

    AntiAfk[playerid][aa_afk] = true;

    KillTimer(UPRelogio[playerid]);
    KillTimer(AntiAfk[playerid][aa_timer]);

    new code[4], Coding[36][2] =
    {
        "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
        "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "X", "W", "Y", "Z"
    };

    code[0] = random(sizeof(Coding));
    code[1] = random(sizeof(Coding));
    code[2] = random(sizeof(Coding));
    code[3] = random(sizeof(Coding));

    format(String, sizeof(String), "%s%s%s%s", Coding[code[0]], Coding[code[1]], Coding[code[2]], Coding[code[3]]);
    format(AntiAfk[playerid][aa_code], 5, String);

    PlayerTextDrawSetString(playerid, PlayerBarStatus[playerid][0], "~w~AFK");
    PlayerTextDrawShow(playerid, PlayerBarStatus[playerid][0]);

    ShowTDAntiAfk(playerid);

    PlayerTextDrawSetString(playerid, TDPlayerAntiAfk[playerid][0], AntiAfk[playerid][aa_code]);
    PlayerTextDrawShow(playerid, TDPlayerAntiAfk[playerid][0]);

    AntiAfk[playerid][aa_timer] = SetTimerEx("OnPlayerKickAFK", 120000, false, "d", playerid);
    return 1;
}

forward OnPlayerKickAFK(playerid);
public OnPlayerKickAFK(playerid)
{
    if(!AntiAfk[playerid][aa_afk]) return 0;

    SendClientMessage(playerid, Red, "Você ficou 2 minutos em afk e foi kickado do servidor!");
    Kick(playerid);
    return 1;
}
