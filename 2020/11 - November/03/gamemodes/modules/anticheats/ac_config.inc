#include YSI\y_hooks

enum e_sac
{
    bool:sac_money      = true,
    bool:sac_fly        = true,
    bool:sac_fakekill   = true,
    bool:sac_weapon     = true
};

new stateanticheat[e_sac];
new FakeKill[MAX_PLAYERS];

#include YSI\y_hooks

new t_ac[MAX_PLAYERS];

hook OnPlayerConnect(playerid)
{
    t_ac[playerid] = SetTimerEx("OnPlayerCheater", 1000, true, "d", playerid);
	return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    KillTimer(t_ac[playerid]);
    FakeKill[playerid] = 0;
	return 1;
}

hook OnPlayerDeath(playerid, killerid, reason)
{
    if(stateanticheat[sac_fakekill])
    {
        FakeKill[playerid]++;
    }
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == anticheat && response)
    {
        switch(listitem)
        {
            case 0:
                return ( stateanticheat[sac_money] ? (stateanticheat[sac_money] = false) : (stateanticheat[sac_money] = true) );

            case 1:
                return ( stateanticheat[sac_fly] ? (stateanticheat[sac_fly] = false) : (stateanticheat[sac_fly] = true) );

            case 2:
                return ( stateanticheat[sac_fakekill] ? (stateanticheat[sac_fakekill] = false) : (stateanticheat[sac_fakekill] = true) );

            case 3:
                return ( stateanticheat[sac_weapon] ? (stateanticheat[sac_weapon] = false) : (stateanticheat[sac_weapon] = true) );
        }
        return 1;
    }
    return 0;
}

forward OnPlayerCheater(playerid);
public OnPlayerCheater(playerid)
{
    if(!PlayerInfo[playerid][Logado]) return 0;

    new animation = GetPlayerWeapon(playerid);

    if(stateanticheat[sac_fly])
    {
        if(animation != WEAPON_PARACHUTE && GetPlayerAnimationIndex(playerid) == 959) return AC_Kick(playerid, "Fly");
        if(animation != WEAPON_PARACHUTE && GetPlayerAnimationIndex(playerid) == 958) return AC_Kick(playerid, "Fly");
        if(!IsPlayerInWater(playerid) && GetPlayerAnimationIndex(playerid) == 1539) return AC_Kick(playerid, "Fly");
        if(!IsPlayerInWater(playerid) && GetPlayerAnimationIndex(playerid) == 1538) return AC_Kick(playerid, "Fly"); //*
    }
    if(stateanticheat[sac_fakekill])
    {
        if(FakeKill[playerid] > 3) return AC_Kick(playerid, "Fake Kill");

        FakeKill[playerid] = 0;
    }
    if(stateanticheat[sac_weapon])
    {
        if(!IsPlayerIntern(playerid))
        {
            switch(GetPlayerWeapon(playerid))
            {
                case 35..38, 44, 45: AC_Kick(playerid, "Arma Proibida");
            }
        }
    }

    //Check
    return 1;
}

stock IsPlayerInWater(playerid)
{
    new Float:Z;

    GetPlayerPos(playerid, Z, Z, Z);

    if(Z < 0.7) switch(GetPlayerAnimationIndex(playerid)) { case 1543, 1538, 1539: return 1; }

    if(GetPlayerDistanceFromPoint(playerid, -965, 2438, 42) <= 700 && Z < 45) return 1;

    new Float:water_places[][] =
    {
        {
            25.0,   2313.0, -1417.0,    23.0},
        {
            15.0,   1280.0, -773.0,     1082.0},
        {
            15.0,   1279.0, -804.0,     86.0},
        {
            20.0,   1094.0, -674.0,     111.0},
        {
            26.0,   194.0,  -1232.0,    76.0},
        {
            25.0,   2583.0, 2385.0,     15.0},
        {
            25.0,   225.0,  -1187.0,    73.0},
        {
            50.0,   1973.0, -1198.0,    17.0},
        {
            140.0,  1923.0, 1592.0,     10.0}
    };

    for(new t=0; t < sizeof water_places; t++)
    {
        if(GetPlayerDistanceFromPoint(playerid, water_places[t][1], water_places[t][2], water_places[t][3]) <= water_places[t][0]) return 1;
    }
    return 0;
}

stock AC_Kick(playerid, reason[])
{
    format(String, MAX_STRING, "| VRC-Admin | O Guardião kickou o jogador %s ( Motivo : %s )", PlayerInfo[playerid][Nome], reason);
    SendClientMessageToAll(Red, String);

    printf("%s", String);

    Kick(playerid);
    return 1;
}

/******************************************************************************/
/***************************| COMMANDS ANTI-CHEATS |***************************/
/******************************************************************************/

CMD:anticheats(playerid)
{
    if(!IsPlayerDeveloper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new txt[1000];

    strcat(txt, "{FFFFFF}Nome \t\t\t {FFFFFF}Status \n");

    format(String, 50, "Money \t\t\t %s \n", (stateanticheat[sac_money] ? ("{00FF00}Ativado{FFFFFF}") : ("{FF4000}Desativado{FFFFFF}")));
    strcat(txt, String);
    format(String, 50, "Fly \t\t\t %s \n", (stateanticheat[sac_fly] ? ("{00FF00}Ativado{FFFFFF}") : ("{FF4000}Desativado{FFFFFF}")));
    strcat(txt, String);
    format(String, 50, "Fake Kill \t\t\t %s \n", (stateanticheat[sac_fakekill] ? ("{00FF00}Ativado{FFFFFF}") : ("{FF4000}Desativado{FFFFFF}")));
    strcat(txt, String);
    format(String, 50, "Arma Proibida \t\t\t %s \n", (stateanticheat[sac_weapon] ? ("{00FF00}Ativado{FFFFFF}") : ("{FF4000}Desativado{FFFFFF}")));
    strcat(txt, String);

    ShowPlayerDialog(playerid, anticheat, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Anti-Cheats VRC", txt, "Ativar/Desativa", "Cancelar");
    return 1;
}
