#include YSI\y_hooks

#define SPEED_HACK 400

enum e_sac
{
    bool:sac_money,
    bool:sac_fly,
    bool:sac_fakekill,
    bool:sac_weapon,
    bool:sac_speed
};

new stateanticheat[e_sac];
new FakeKill[MAX_PLAYERS];
new FakeKillVictim[MAX_PLAYERS];
new t_ac[MAX_PLAYERS];

hook OnGameModeInit()
{
    stateanticheat[sac_money] = true;
    stateanticheat[sac_fly] = false;
    stateanticheat[sac_fakekill] = true;
    stateanticheat[sac_weapon] = true;
    stateanticheat[sac_speed] = true;
    return 1;
}

hook OnPlayerConnect(playerid)
{
    t_ac[playerid] = SetTimerEx("OnPlayerCheater", 1000, true, "d", playerid);
	return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    KillTimer(t_ac[playerid]);
    FakeKill[playerid] = 0;
    FakeKillVictim[playerid] = INVALID_PLAYER_ID;
	return 1;
}

hook OnPlayerDeath(playerid, killerid, reason)
{
    if(stateanticheat[sac_fakekill])
    {
        FakeKill[playerid]++;

        if(killerid != INVALID_PLAYER_ID)
        {
            FakeKillVictim[playerid] = killerid;
        }
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
            {
                if(stateanticheat[sac_money])
                    stateanticheat[sac_money] = false;
                else
                    stateanticheat[sac_money] = true;

                return 1;
            }
            case 1:
            {
                if(stateanticheat[sac_fly])
                    stateanticheat[sac_fly] = false;
                else
                    stateanticheat[sac_fly] = true;

                return 1;
            }
            case 2:
            {
                if(stateanticheat[sac_fakekill])
                    stateanticheat[sac_fakekill] = false;
                else
                    stateanticheat[sac_fakekill] = true;

                return 1;
            }
            case 3:
            {
                if(stateanticheat[sac_weapon])
                    stateanticheat[sac_weapon] = false;
                else
                    stateanticheat[sac_weapon] = true;

                return 1;
            }
            case 4:
            {
                if(stateanticheat[sac_speed])
                    stateanticheat[sac_speed] = false;
                else
                    stateanticheat[sac_speed] = true;

                return 1;
            }
        }
        return 1;
    }
    return 0;
}

forward OnPlayerCheater(playerid);
public OnPlayerCheater(playerid)
{
    if(!PlayerInfo[playerid][Logado]) return 0;

    new weaponid = GetPlayerWeapon(playerid);

    if(stateanticheat[sac_fly])
    {
        if(weaponid != WEAPON_PARACHUTE && GetPlayerAnimationIndex(playerid) == 959) return AC_Kick(playerid, "Fly");
        if(weaponid != WEAPON_PARACHUTE && GetPlayerAnimationIndex(playerid) == 958) return AC_Kick(playerid, "Fly");
        if(!IsPlayerInWater(playerid) && GetPlayerAnimationIndex(playerid) == 1539) return AC_Kick(playerid, "Fly");
        if(!IsPlayerInWater(playerid) && GetPlayerAnimationIndex(playerid) == 1538) return AC_Kick(playerid, "Fly");
    }
    if(stateanticheat[sac_fakekill])
    {
        if(FakeKill[playerid] > 3)
        {
            if(FakeKillVictim[playerid] != INVALID_PLAYER_ID)
            {
                new id = FakeKillVictim[playerid];

                PlayerInfo[id][Estrelas] = 0;
                UpdatePlayerStar(id);

                FakeKillVictim[playerid] = INVALID_PLAYER_ID;
            }

            AC_Kick(playerid, "Fake Kill");
            return 1;
        }

        FakeKill[playerid] = 0;
    }
    if(stateanticheat[sac_weapon])
    {
        if(!IsPlayerIntern(playerid))
        {
            switch(weaponid)
            {
                case 35..38, 44, 45: AC_Kick(playerid, "Arma Proibida");
            }
        }
    }
    if(stateanticheat[sac_money])
    {
        if(GetPlayerMoney(playerid) > PlayerInfo[playerid][Dinheiro])
        {
            UpdatePlayerMoney(playerid);
        }
    }
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
    format(String, MAX_STRING, "VRC-Admin ~ O Bot kickou o jogador %s ( Motivo : %s )", PlayerInfo[playerid][Nome], reason);
    SendClientMessageToAll(Red, String);

    Kick(playerid);
    return 1;
}

stock CheckPlayerSpeedHack(playerid)
{
    new vehicleid = GetPlayerVehicleID(playerid);
    new speed = GetVehicleSpeed(vehicleid);

    if(speed > SPEED_HACK)
    {
        for(new admid = 0; admid < MAX_PLAYERS; admid++)
        {
            if(!IsPlayerIntern(admid)) continue;

            format(String, MAX_STRING, "VRC-Admin ~ O(A) Jogador(a) %s[%d] está possívelmente de Speed Hack", PlayerInfo[playerid][Nome], playerid);
            SendClientMessage(admid, Red, String);
        }
        return 1;
    }
    return 0;
}

/******************************************************************************/
/***************************| COMMANDS ANTI-CHEATS |***************************/
/******************************************************************************/

CMD:anticheats(playerid)
{
    if(!IsPlayerCoordinator(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new txt[1000];

    strcat(txt, "{FFFFFF}Nome \t\t\t {FFFFFF}Status \n");

    format(String, 100, "Money \t\t\t %s \n", (stateanticheat[sac_money] ? ("{00FF00}Ativado{FFFFFF}") : ("{FF4000}Desativado{FFFFFF}")));
    strcat(txt, String);
    format(String, 100, "Fly \t\t\t %s \n", (stateanticheat[sac_fly] ? ("{00FF00}Ativado{FFFFFF}") : ("{FF4000}Desativado{FFFFFF}")));
    strcat(txt, String);
    format(String, 100, "Fake Kill \t\t\t %s \n", (stateanticheat[sac_fakekill] ? ("{00FF00}Ativado{FFFFFF}") : ("{FF4000}Desativado{FFFFFF}")));
    strcat(txt, String);
    format(String, 100, "Arma Proibida \t\t\t %s \n", (stateanticheat[sac_weapon] ? ("{00FF00}Ativado{FFFFFF}") : ("{FF4000}Desativado{FFFFFF}")));
    strcat(txt, String);
    format(String, 100, "Speed \t\t\t %s \n", (stateanticheat[sac_speed] ? ("{00FF00}Ativado{FFFFFF}") : ("{FF4000}Desativado{FFFFFF}")));
    strcat(txt, String);

    ShowPlayerDialog(playerid, anticheat, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Anti-Cheats VRC", txt, "Ativar/Desativa", "Cancelar");
    return 1;
}                                  //stateanticheat[sac_speed]
