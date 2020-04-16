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
        AntiAfk[playerid][aa_timer] = SetTimerEx("OnPlayerTimerAFK", 300000, true, "d", playerid);

        if(IsArena[playerid])
        {
            SetPlayerHealth(playerid, AntiAfk[playerid][aa_life]);
        }

        SendClientMessage(playerid, White, "Anti-Afk desbloqueado, agora você pode voltar a jogar normalmente");

        new Float:x, Float:y, Float:z;
        GetPlayerPos(playerid, x, y, z);

        AntiAfk[playerid][aa_x] = x;
        AntiAfk[playerid][aa_y] = y;
        AntiAfk[playerid][aa_z] = z;
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
    if(!PlayerInfo[playerid][Logado] || AntiAfk[playerid][aa_afk] || IsPlayerMobile(playerid)) return 0;

    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);

    if((AntiAfk[playerid][aa_x] == x) && (AntiAfk[playerid][aa_y] == y) && (AntiAfk[playerid][aa_z] == z))
    {
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

        if(IsPlayerVip(playerid))
        {
            if(PlayerInfo[playerid][Exp] >= 3)
            {
                PlayerInfo[playerid][Level]++;
                PlayerInfo[playerid][Exp] = 0;

                SetPlayerScore(playerid, PlayerInfo[playerid][Level]);
                Salario(playerid);

                SendClientMessage(playerid, 0x75EA00AA, "Você ganhou +1 de Experiência ( 3/3 )");
                format(String, sizeof(String), "Você juntou 3 de Experiência e ganhou +1 level ( %d ) ", PlayerInfo[playerid][Level]);
            }
            else
            {
                format(String, sizeof(String), "Você ganhou +1 de Experiência ( %d/3 )", PlayerInfo[playerid][Exp]);
            }
        }
        else
        {
            if(PlayerInfo[playerid][Exp] >= 6)
            {
                PlayerInfo[playerid][Level]++;
                PlayerInfo[playerid][Exp] = 0;

                SetPlayerScore(playerid, PlayerInfo[playerid][Level]);
                Salario(playerid);

                SendClientMessage(playerid, 0x75EA00AA, "Você ganhou +1 de Experiência ( 6/6 )");
                format(String, sizeof(String), "Você juntou 6 de Experiência e ganhou +1 level ( %d )", PlayerInfo[playerid][Level]);
            }
            else
            {
                format(String, sizeof(String), "Você ganhou +1 de Experiência ( %d/6 )", PlayerInfo[playerid][Exp]);
            }
        }
        SendClientMessage(playerid, 0x75EA00AA, String);
        GameTextForPlayer(playerid, "~w~UP!", 3000, 6);
        PlayerPlaySound(playerid, 1057, 0, 0, 0);
        UpdatePlayerLevel(playerid);
    }

    if(PlayerInfo[playerid][segUP] == -1)
    {
        if(PlayerInfo[playerid][minUP] == 0)
        PlayerInfo[playerid][minUP] = 10;
        PlayerInfo[playerid][segUP] = 59;
        PlayerInfo[playerid][minUP]--;
    }

    if(IsPlayerMobile(playerid))
    {
        //format(String, sizeof(String), "~w~+~r~UP: ~w~%02d:%02d", PlayerInfo[playerid][minUP], PlayerInfo[playerid][segUP]);
        //GameTextForPlayer(playerid, String, 1000, 1);
    }
    else
    {
        format(String, sizeof(String), "~w~+~r~UP: ~w~%02d:%02d", PlayerInfo[playerid][minUP], PlayerInfo[playerid][segUP]);
        PlayerTextDrawSetString(playerid, PlayerBarStatus[playerid][0], String);
    }

    PlayerInfo[playerid][segUP]--;
    return 1;
}
