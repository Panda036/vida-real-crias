#include YSI\y_hooks

enum e_aa
{
    aa_code[5],
    aa_timer,
    aa_timerpos,
    aa_timerkick,
    bool:aa_afk,
    Float:aa_x,
    Float:aa_y,
    Float:aa_z
};

new AntiAfk[MAX_PLAYERS][e_aa];

hook OnGameModeInit()
{

	return 1;
}

hook OnPlayerConnect(playerid)
{
    AntiAfk[playerid][aa_timer] = SetTimerEx("OnPlayerTimerAFK", 600000, true, "d", playerid);
    AntiAfk[playerid][aa_timerpos] = SetTimerEx("OnPlayerPositionAFK", 300000, true, "d", playerid);
	return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    AntiAfk[playerid][aa_afk] = false;
    AntiAfk[playerid][aa_x] = 0;
    AntiAfk[playerid][aa_y] = 0;
    AntiAfk[playerid][aa_z] = 0;
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

        AntiAfk[playerid][aa_timer] = SetTimerEx("OnPlayerTimerAFK", 600000, true, "d", playerid);
        AntiAfk[playerid][aa_timerpos] = SetTimerEx("OnPlayerPositionAFK", 300000, true, "d", playerid);
        UPRelogio[playerid] = SetTimerEx("ClockUP", 1000, true, "d", playerid);

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
    if(!PlayerInfo[playerid][Logado] || AntiAfk[playerid][aa_afk]) return 1;

    AntiAfk[playerid][aa_afk] = true;

    KillTimer(UPRelogio[playerid]);
    KillTimer(AntiAfk[playerid][aa_timerpos]);
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

forward OnPlayerPositionAFK(playerid);
public OnPlayerPositionAFK(playerid)
{
    new Float:x, Float:y, Float:z;

    GetPlayerPos(playerid, x, y, z);

    if(AntiAfk[playerid][aa_x] == x && AntiAfk[playerid][aa_y] == y && AntiAfk[playerid][aa_z] == z)
    {
        OnPlayerTimerAFK(playerid);
    }
    else
    {
        AntiAfk[playerid][aa_x] = x;
        AntiAfk[playerid][aa_y] = y;
        AntiAfk[playerid][aa_z] = z;
    }
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
