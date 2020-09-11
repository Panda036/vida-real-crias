#include YSI\y_hooks

enum e_aa
{
    aa_code[5],
    aa_timer,
    aa_timerkick,
    bool:aa_afk,
    Float:aa_life,
    Float:aa_x,
    Float:aa_y,
    Float:aa_z
};

new AntiAfk[MAX_PLAYERS][e_aa];

hook OnPlayerConnect(playerid)
{
    AntiAfk[playerid][aa_timer] = SetTimerEx("OnPlayerTimerAFK", 300000, true, "d", playerid);
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

forward OnPlayerTimerAFK(playerid);
public OnPlayerTimerAFK(playerid)
{
    if(!PlayerInfo[playerid][Logado] || AntiAfk[playerid][aa_afk]) return 0;

    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);

    if((AntiAfk[playerid][aa_x] == x) && (AntiAfk[playerid][aa_y] == y) && (AntiAfk[playerid][aa_z] == z))
    {
        AntiAfk[playerid][aa_afk] = true;

        if(IsArena[playerid])
        {
            GetPlayerHealth(playerid, AntiAfk[playerid][aa_life]);
            SetPlayerHealth(playerid, 99999);
        }

        KillTimer(AntiAfk[playerid][aa_timer]);

        format(AntiAfk[playerid][aa_code], 5, GetRandomString(4));

        PlayerTextDrawSetString(playerid, PlayerBarStatus[playerid][0], "~w~AFK");
        PlayerTextDrawShow(playerid, PlayerBarStatus[playerid][0]);

        format(String, sizeof(String), "DIGITE:~n~/SAIRAFK_%s", AntiAfk[playerid][aa_code]);
        PlayerTextDrawSetString(playerid, TDPlayerAntiAfk[playerid][0], String);

        ShowTDAntiAfk(playerid);

        AntiAfk[playerid][aa_timer] = SetTimerEx("OnPlayerKickAFK", 120000, false, "d", playerid);
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

forward ClockUP(playerid);
public ClockUP(playerid)
{
    if(!PlayerInfo[playerid][Logado] || AntiAfk[playerid][aa_afk]) return 1;

    if(PlayerInfo[playerid][segUP] == 0 && PlayerInfo[playerid][minUP] == 0)
    {
        PlayerInfo[playerid][Exp]++;

        if( IsPlayerVip(playerid) ? ( PlayerInfo[playerid][Exp] > 3 ) : ( PlayerInfo[playerid][Exp] > 4 ) )
        {
            PlayerInfo[playerid][Level]++;
            PlayerInfo[playerid][Exp] = 0;

            SetPlayerScore(playerid, PlayerInfo[playerid][Level]);
            Salario(playerid);

            SendClientMessage(playerid, 0x75EA00AA, (IsPlayerVip(playerid) ? ("Você ganhou +1 de Experiência ( 4/4 )") : ("Você ganhou +1 de Experiência ( 5/5 )")));
            format(String, MAX_STRING, "Você juntou %d de Experiência e ganhou +1 level ( %d )", (IsPlayerVip(playerid) ? (4) : (5)), PlayerInfo[playerid][Level]);
        }
        else
        {
            format(String, MAX_STRING, "Você ganhou +1 de Experiência ( %d/%d )", PlayerInfo[playerid][Exp], (IsPlayerVip(playerid) ? (4) : (5)));
        }

        SendClientMessage(playerid, 0x75EA00AA, String);
        GameTextForPlayer(playerid, "~w~UP!", 3000, 6);
        PlayerPlaySound(playerid, 1057, 0, 0, 0);
    }

    if(PlayerInfo[playerid][segUP] == -1)
    {
        if(PlayerInfo[playerid][minUP] == 0)
        PlayerInfo[playerid][minUP] = 10;
        PlayerInfo[playerid][segUP] = 59;
        PlayerInfo[playerid][minUP]--;
    }

    format(String, MAX_STRING, "~w~+~r~UP: ~w~%02d:%02d", PlayerInfo[playerid][minUP], PlayerInfo[playerid][segUP]);
    PlayerTextDrawSetString(playerid, PlayerBarStatus[playerid][0], String);
    PlayerInfo[playerid][segUP]--;

    return UpdatePlayerLevel(playerid);
}

//--------------------------------------------------------

CMD:sairafk(playerid, params[])
{
    new code[5];

    if(sscanf(params, "s[5]", code))
    {
        format(String, sizeof(String), "Digite: /SairAfk %s", AntiAfk[playerid][aa_code]);
        SendClientMessage(playerid, Erro, String);
        return 1;
    }

    if(strcmp(AntiAfk[playerid][aa_code], code, true))
        return SendClientMessage(playerid, Erro, "Código errado!");

    HideTDAntiAfk(playerid);

    PlayerPlaySound(playerid, 1057, 0, 0, 0);

    AntiAfk[playerid][aa_afk] = false;

    KillTimer(AntiAfk[playerid][aa_timerkick]);

    AntiAfk[playerid][aa_timer] = SetTimerEx("OnPlayerTimerAFK", 300000, true, "d", playerid);

    if(IsArena[playerid])
        { SetPlayerHealth(playerid, AntiAfk[playerid][aa_life]); }

    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);

    AntiAfk[playerid][aa_x] = x;
    AntiAfk[playerid][aa_y] = y;
    AntiAfk[playerid][aa_z] = z;

    SendClientMessage(playerid, White, "Anti-Afk desbloqueado, agora você pode voltar a jogar normalmente");
    return 1;
}
