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
    Float:aa_z,
    aa_warning
};

new AntiAfk[MAX_PLAYERS][e_aa];

hook OnPlayerConnect(playerid)
{
    UPRelogio[playerid] = SetTimerEx("ClockUP", 1000, true, "d", playerid);
    AntiAfk[playerid][aa_timer] = SetTimerEx("OnPlayerTimerAFK", 300000, true, "d", playerid);
	return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    KillTimer(UPRelogio[playerid]);
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

    if(((AntiAfk[playerid][aa_x] == x) && (AntiAfk[playerid][aa_y] == y) && (AntiAfk[playerid][aa_z] == z)) || AntiAfk[playerid][aa_warning] == 3)
    {
        AntiAfk[playerid][aa_warning] = 0;
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

        format(String, 100, "DIGITE:~n~/SAIRAFK_%s", AntiAfk[playerid][aa_code]);
        PlayerTextDrawSetString(playerid, TDPlayerAntiAfk[playerid][0], String);

        ShowTDAntiAfk(playerid);

        AntiAfk[playerid][aa_timer] = SetTimerEx("OnPlayerKickAFK", 120000, false, "d", playerid);
    }
    else
    {
        AntiAfk[playerid][aa_warning]++;
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

    SendClientMessage(playerid, Red, "Voc� ficou 2 minutos em afk e foi kickado do servidor!");
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

        if( IsPlayerVip(playerid) ? ( PlayerInfo[playerid][Exp] >= 4 ) : ( PlayerInfo[playerid][Exp] >= 5 ) )
        {
            PlayerInfo[playerid][Level]++;
            PlayerInfo[playerid][Exp] = 0;

            SetPlayerScore(playerid, PlayerInfo[playerid][Level]);
            Salario(playerid);
            CongratulationsLevel(playerid);

            SendClientMessage(playerid, 0x75EA00AA, (IsPlayerVip(playerid) ? ("Voc� ganhou +1 de Experi�ncia ( 4/4 )") : ("Voc� ganhou +1 de Experi�ncia ( 5/5 )")));
            format(String, MAX_STRING, "Voc� juntou %d de Experi�ncia e ganhou +1 level ( %d )", (IsPlayerVip(playerid) ? (4) : (5)), PlayerInfo[playerid][Level]);
        }
        else
        {
            format(String, MAX_STRING, "Voc� ganhou +1 de Experi�ncia ( %d/%d )", PlayerInfo[playerid][Exp], (IsPlayerVip(playerid) ? (4) : (5)));
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

    if(!PlayerInfo[playerid][tutorial]){
        format(String, MAX_STRING, "~w~+~r~UP: ~w~%02d:%02d", PlayerInfo[playerid][minUP], PlayerInfo[playerid][segUP]);
        PlayerTextDrawSetString(playerid, PlayerBarStatus[playerid][0], String);
    }
    PlayerInfo[playerid][segUP]--;

    return UpdatePlayerLevel(playerid);
}

stock CongratulationsLevel(playerid)
{
    format(String, MAX_STRING, "Parab�ns ao jogador(a) %s que alcan�ou o level ( %d )", PlayerInfo[playerid][Nome], PlayerInfo[playerid][Level]);

    switch(PlayerInfo[playerid][Level])
    {
        case 100: SendClientMessageToAll(Yellow, String);
        case 500: SendClientMessageToAll(Yellow, String);
        case 1000: SendClientMessageToAll(Yellow, String);
    }
    return 1;
}

/******************************************************************************/
/****************************| COMMANDS ANTI-AFK |*****************************/
/******************************************************************************/

CMD:sairafk(playerid, params[])
{
    if(!AntiAfk[playerid][aa_afk])
        return SendClientMessage(playerid, Erro, "Voc� n�o est� ausente");

    new code[5];

    if(sscanf(params, "s[5]", code))
    {
        format(String, sizeof(String), "Digite: /SairAfk %s", AntiAfk[playerid][aa_code]);
        SendClientMessage(playerid, Erro, String);
        return 1;
    }

    if(strcmp(AntiAfk[playerid][aa_code], code, true))
        return SendClientMessage(playerid, Erro, "C�digo errado!");

    HideTDAntiAfk(playerid);

    PlayerPlaySound(playerid, 1057, 0, 0, 0);

    AntiAfk[playerid][aa_afk] = false;
    AntiAfk[playerid][aa_code] = 0;

    KillTimer(AntiAfk[playerid][aa_timerkick]);

    AntiAfk[playerid][aa_timer] = SetTimerEx("OnPlayerTimerAFK", 300000, true, "d", playerid);

    if(IsArena[playerid])
        { SetPlayerHealth(playerid, AntiAfk[playerid][aa_life]); }

    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);

    AntiAfk[playerid][aa_x] = x;
    AntiAfk[playerid][aa_y] = y;
    AntiAfk[playerid][aa_z] = z;

    SendClientMessage(playerid, White, "Anti-Afk desbloqueado, agora voc� pode voltar a jogar normalmente");
    return 1;
}
