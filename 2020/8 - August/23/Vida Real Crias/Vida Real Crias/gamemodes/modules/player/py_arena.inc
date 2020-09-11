#include YSI\y_hooks

enum e_rs
{
    Float:rs_x,
    Float:rs_y,
    Float:rs_z,
    Float:rs_a
};

new RandomSpawns[8][e_rs] =
{
    {2177.02, -984.53, 64.46, 169.15},
    {2203.73, -992.35, 63.92, 158.49},
    {2224.99, -1009.80, 60.41, 151.60},
    {2220.89, -1045.92, 57.72, 314.85},
    {2225.53, -1059.49, 46.00, 50.39},
    {2191.95, -1088.92, 40.50, 335.82},
    {2157.41, -1053.34, 63.42, 331.12},
    {2207.75, -1111.24, 25.74, 171.12}
};

//textdraw
new Text:TDKD[4];
new PlayerText:TDPlayerKD[MAX_PLAYERS][3];

//variaveis globais
new Text:GiveDamage[MAX_PLAYERS];
new Text:TakeDamage[MAX_PLAYERS];
new CP_Arena[3];
new Kills[MAX_PLAYERS] = 0;
new WeaponsKit[MAX_PLAYERS] = -1;
new Enter_Arena[MAX_PLAYERS] = -1;
new bool:IsArena[MAX_PLAYERS];
new bool:BlockEnterArena[MAX_PLAYERS];

hook OnGameModeInit()
{
    for(new  i; i < MAX_PLAYERS ; ++i)
    {
        GiveDamage[i] = TextDrawCreate(171.000000, 388.000000, " ");
        TextDrawAlignment(GiveDamage[i], 2);
        TextDrawBackgroundColor(GiveDamage[i], 255);
        TextDrawFont(GiveDamage[i], 2);
        TextDrawLetterSize(GiveDamage[i], 0.160000, 0.599999);
        TextDrawColor(GiveDamage[i], 0x00FF04FF);
        TextDrawSetOutline(GiveDamage[i], 1);
        TextDrawSetProportional(GiveDamage[i], 1);
    }
    for(new i; i < MAX_PLAYERS; ++i)
    {
        TakeDamage[i] = TextDrawCreate(440.000000,388.000000, " ");
        TextDrawAlignment(TakeDamage[i], 2);
        TextDrawBackgroundColor(TakeDamage[i], 255);
        TextDrawFont(TakeDamage[i], 2);
        TextDrawLetterSize(TakeDamage[i], 0.160000, 0.599999);
        TextDrawColor(TakeDamage[i], 0xE81010FF);
        TextDrawSetOutline(TakeDamage[i], 1);
        TextDrawSetProportional(TakeDamage[i], 1);
    }

    TDKD[0] = TextDrawCreate(32.100070, 263.988464, "box");
    TextDrawLetterSize(TDKD[0], 0.000000, 5.649998);
    TextDrawTextSize(TDKD[0], 108.099708, 0.000000);
    TextDrawAlignment(TDKD[0], 1);
    TextDrawColor(TDKD[0], -1);
    TextDrawUseBox(TDKD[0], 1);
    TextDrawBoxColor(TDKD[0], 150);
    TextDrawSetShadow(TDKD[0], 0);
    TextDrawSetOutline(TDKD[0], 0);
    TextDrawBackgroundColor(TDKD[0], 255);
    TextDrawFont(TDKD[0], 1);
    TextDrawSetProportional(TDKD[0], 1);
    TextDrawSetShadow(TDKD[0], 0);

    TDKD[1] = TextDrawCreate(33.600036, 277.289276, "box");
    TextDrawLetterSize(TDKD[1], 0.000000, 3.899969);
    TextDrawTextSize(TDKD[1], 106.000000, 0.000000);
    TextDrawAlignment(TDKD[1], 1);
    TextDrawColor(TDKD[1], -1);
    TextDrawUseBox(TDKD[1], 1);
    TextDrawBoxColor(TDKD[1], -2139062172);
    TextDrawSetShadow(TDKD[1], 0);
    TextDrawSetOutline(TDKD[1], 0);
    TextDrawBackgroundColor(TDKD[1], 255);
    TextDrawFont(TDKD[1], 1);
    TextDrawSetProportional(TDKD[1], 1);
    TextDrawSetShadow(TDKD[1], 0);

    TDKD[2] = TextDrawCreate(34.700027, 299.233825, "");
    TextDrawLetterSize(TDKD[2], 0.000000, 0.000000);
    TextDrawTextSize(TDKD[2], 14.000000, 17.000000);
    TextDrawAlignment(TDKD[2], 1);
    TextDrawColor(TDKD[2], -1);
    TextDrawSetShadow(TDKD[2], 0);
    TextDrawSetOutline(TDKD[2], 0);
    TextDrawBackgroundColor(TDKD[2], -256);
    TextDrawFont(TDKD[2], 5);
    TextDrawSetProportional(TDKD[2], 0);
    TextDrawSetShadow(TDKD[2], 0);
    TextDrawSetPreviewModel(TDKD[2], 1254);
    TextDrawSetPreviewRot(TDKD[2], 0.000000, 0.000000, 0.000000, 1.000000);

    TDKD[3] = TextDrawCreate(35.600006, 276.632446, "");
    TextDrawLetterSize(TDKD[3], 0.000000, 0.000000);
    TextDrawTextSize(TDKD[3], 23.000000, 26.000000);
    TextDrawAlignment(TDKD[3], 1);
    TextDrawColor(TDKD[3], -1);
    TextDrawSetShadow(TDKD[3], 0);
    TextDrawSetOutline(TDKD[3], 0);
    TextDrawBackgroundColor(TDKD[3], -256);
    TextDrawFont(TDKD[3], 5);
    TextDrawSetProportional(TDKD[3], 0);
    TextDrawSetShadow(TDKD[3], 0);
    TextDrawSetPreviewModel(TDKD[3], 348);
    TextDrawSetPreviewRot(TDKD[3], 0.000000, 0.000000, 0.000000, 1.000000);

    CP_Arena[0] = CreateDynamicCP(2695.55, -1704.70, 11.84, 2.0, -1, -1, -1, 100.0);
    CP_Arena[1] = CreateDynamicCP(1099.56, 1601.52, 12.54, 2.0, -1, -1, -1, 100.0);
    CP_Arena[2] = CreateDynamicCP(-2110.82, -444.22, 38.73, 2.0, -1, -1, -1, 100.0);
	return 1;
}

hook OnPlayerConnect(playerid)
{
    TDPlayerKD[playerid][0] = CreatePlayerTextDraw(playerid, 69.699546, 263.177917, "K/D_Ratio_:_0.1");
    PlayerTextDrawLetterSize(playerid, TDPlayerKD[playerid][0], 0.238499, 1.003553);
    PlayerTextDrawAlignment(playerid, TDPlayerKD[playerid][0], 2);
    PlayerTextDrawColor(playerid, TDPlayerKD[playerid][0], -16776961);
    PlayerTextDrawSetShadow(playerid, TDPlayerKD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerKD[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerKD[playerid][0], 255);
    PlayerTextDrawFont(playerid, TDPlayerKD[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, TDPlayerKD[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerKD[playerid][0], 0);

    TDPlayerKD[playerid][1] = CreatePlayerTextDraw(playerid, 52.799713, 300.133300, "~r~0");
    PlayerTextDrawLetterSize(playerid, TDPlayerKD[playerid][1], 0.203997, 1.512887);
    PlayerTextDrawAlignment(playerid, TDPlayerKD[playerid][1], 1);
    PlayerTextDrawColor(playerid, TDPlayerKD[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerKD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerKD[playerid][1], -1);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerKD[playerid][1], 255);
    PlayerTextDrawFont(playerid, TDPlayerKD[playerid][1], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerKD[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerKD[playerid][1], 0);

    TDPlayerKD[playerid][2] = CreatePlayerTextDraw(playerid, 53.099708, 280.365539, "~g~0");
    PlayerTextDrawLetterSize(playerid, TDPlayerKD[playerid][2], 0.203997, 1.512887);
    PlayerTextDrawAlignment(playerid, TDPlayerKD[playerid][2], 1);
    PlayerTextDrawColor(playerid, TDPlayerKD[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerKD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerKD[playerid][2], -1);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerKD[playerid][2], 255);
    PlayerTextDrawFont(playerid, TDPlayerKD[playerid][2], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerKD[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerKD[playerid][2], 0);
    return 1;
}

hook OnPlayerSpawn(playerid)
{
    TextDrawHideForPlayer(playerid, TDDetonated[0]);
    TextDrawHideForPlayer(playerid, TDDetonated[1]);

    if(IsArena[playerid])
    {
        SetPlayerHealth(playerid, 99999);
        SetTimerEx("AntiSpawnKill", 3000, false, "d", playerid);

        switch(WeaponsKit[playerid])
        {
            case 1:
            {
                GivePlayerWeapon(playerid, 23, 2000); //Pistol Silenc
                GivePlayerWeapon(playerid, 32, 2000); //Tec-9
                GivePlayerWeapon(playerid, 26, 2000); //Sawn
                GivePlayerWeapon(playerid, 4, 1); //Faca
            }
            case 2:
            {
                GivePlayerWeapon(playerid, 23, 2000); //Pistol Silenc
                GivePlayerWeapon(playerid, 28, 2000); //Uzi
                GivePlayerWeapon(playerid, 26, 2000); //Sawn
                GivePlayerWeapon(playerid, 4, 1); //Faca
            }
            case 3:
            {
                GivePlayerWeapon(playerid, 22, 2000); //9mm
                GivePlayerWeapon(playerid, 29, 2000); //Mp5
                GivePlayerWeapon(playerid, 26, 2000); //Sawn
                GivePlayerWeapon(playerid, 4, 1); //Faca
            }
            case 4:
            {
                GivePlayerWeapon(playerid, 30, 2000); //AK-47
                GivePlayerWeapon(playerid, 27, 2000); //Combat Shotgun
                GivePlayerWeapon(playerid, 28, 2000); //Uzi
                GivePlayerWeapon(playerid, 34, 2000); //Sniper
                GivePlayerWeapon(playerid, 4, 1); //Faca
            }
            case 5:
            {
                GivePlayerWeapon(playerid, 31, 2000); //M4
                GivePlayerWeapon(playerid, 27, 2000); //Combat Shotgun
                GivePlayerWeapon(playerid, 29, 2000); //Mp5
                GivePlayerWeapon(playerid, 34, 2000); //Sniper
                GivePlayerWeapon(playerid, 4, 1); //Faca
            }
        }

        ShowTextDrawKD(playerid);
    }
    return 1;
}

hook OnPlayerEnterCheckpoint(playerid)
{
    if(IsPlayerInDynamicCP(playerid, CP_Arena[0]) || IsPlayerInDynamicCP(playerid, CP_Arena[1]) || IsPlayerInDynamicCP(playerid, CP_Arena[2]))
    {
        if(BlockEnterArena[playerid])
            return SendClientMessage(playerid, Erro, "Você acabou de sair da arena, aguarde alguns segundos...");

        if(PlayerInfo[playerid][Estrelas])
            return SendClientMessage(playerid, Erro, "Você está procurado e não pode entrar na arena");

        if(IsPlayerInDynamicCP(playerid, CP_Arena[0]))
            { Enter_Arena[playerid] = 0; }
        if(IsPlayerInDynamicCP(playerid, CP_Arena[1]))
            { Enter_Arena[playerid] = 1; }
        if(IsPlayerInDynamicCP(playerid, CP_Arena[2]))
            { Enter_Arena[playerid] = 2; }

        ShowPlayerDialog(playerid, arena, DIALOG_STYLE_LIST, "{FF0000}Arena", "{FFFFFF}Favela", "Entrar", "Cancelar");
        return 1;
    }
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case arena:
        {
            if(!response) return 0;

            if(IsPlayerMobile(playerid))
                return SendClientMessage(playerid, Erro, "Arena foi temporariamente desativada para mobile");

            SetPlayerVirtualWorld(playerid, WORLD_ARENA);

            new txt[500];

            strcat(txt, "{F71616}Kit\t {31B404}Preço\t {FFFFFF}Armas\n");

            format(String, 100, "{F71616}1\t {31B404}%s\t {FFFFFF}Pistol silenc, tec, saw e faca\n", ( IsPlayerVip(playerid) ? ("N/A") : ("$750")));
            strcat(txt, String);
            format(String, 100, "{F71616}2\t {31B404}%s\t {FFFFFF}Pistol silenc, uzi, saw e faca\n", ( IsPlayerVip(playerid) ? ("N/A") : ("$1.000")));
            strcat(txt, String);
            format(String, 100, "{F71616}3\t {31B404}%s\t {FFFFFF}Pistol 9m, mp5, saw e faca\n", ( IsPlayerVip(playerid) ? ("N/A") : ("$850")));
            strcat(txt, String);
            format(String, 100, "{F71616}4\t {31B404}%s\t {FFFFFF}ak47, shotgun combat, uzi, sniper e faca\n", ( IsPlayerVip(playerid) ? ("N/A") : ("$1.250")));
            strcat(txt, String);
            format(String, 100, "{F71616}5\t {31B404}%s\t {FFFFFF}M4, shotgun combat, mp5, sniper e faca\n", ( IsPlayerVip(playerid) ? ("N/A") : ("$1.500")));
            strcat(txt, String);

            ShowPlayerDialog(playerid, arena_kits, DIALOG_STYLE_TABLIST_HEADERS, "{FFD700}Kit Armas", txt, "Comprar", "Cancelar");
            return 1;
        }
        case arena_kits:
        {
            if(!response)
            {
                WeaponsKit[playerid] = -1;
                SetPlayerVirtualWorld(playerid, 0);
                return 1;
            }

            switch(listitem)
            {
                case 0:
                {
                    if(!IsPlayerVip(playerid))
                    {
                        if(PlayerInfo[playerid][Dinheiro] < 750)
                            return SendClientMessage(playerid, Erro, "Você não tem dinheiro o suficiente");

                        PlayerInfo[playerid][Dinheiro] -= 750;
                        UpdatePlayerMoney(playerid);
                    }

                    GivePlayerWeapon(playerid, 23, 2000); //Pistol Silenc
                    GivePlayerWeapon(playerid, 32, 2000); //Tec-9
                    GivePlayerWeapon(playerid, 26, 2000); //Sawn
                    GivePlayerWeapon(playerid, 4, 1); //Faca

                    WeaponsKit[playerid] = 1;
                }
                case 1:
                {
                    if(!IsPlayerVip(playerid))
                    {
                        if(PlayerInfo[playerid][Dinheiro] < 1000)
                            return SendClientMessage(playerid, Erro, "Você não tem dinheiro o suficiente");

                        PlayerInfo[playerid][Dinheiro] -= 1000;
                        UpdatePlayerMoney(playerid);
                    }

                    GivePlayerWeapon(playerid, 23, 2000); //Pistol Silenc
                    GivePlayerWeapon(playerid, 28, 2000); //Uzi
                    GivePlayerWeapon(playerid, 26, 2000); //Sawn
                    GivePlayerWeapon(playerid, 4, 1); //Faca

                    WeaponsKit[playerid] = 2;
                }
                case 2:
                {
                    if(!IsPlayerVip(playerid))
                    {
                        if(PlayerInfo[playerid][Dinheiro] < 850)
                            return SendClientMessage(playerid, Erro, "Você não tem dinheiro o suficiente");

                        PlayerInfo[playerid][Dinheiro] -= 850;
                        UpdatePlayerMoney(playerid);
                    }

                    GivePlayerWeapon(playerid, 22, 2000); //9mm
                    GivePlayerWeapon(playerid, 29, 2000); //Mp5
                    GivePlayerWeapon(playerid, 26, 2000); //Sawn
                    GivePlayerWeapon(playerid, 4, 1); //Faca

                    WeaponsKit[playerid] = 3;
                }
                case 3:
                {
                    if(!IsPlayerVip(playerid))
                    {
                        if(PlayerInfo[playerid][Dinheiro] < 1250)
                            return SendClientMessage(playerid, Erro, "Você não tem dinheiro o suficiente");

                        PlayerInfo[playerid][Dinheiro] -= 1250;
                        UpdatePlayerMoney(playerid);
                    }

                    GivePlayerWeapon(playerid, 30, 2000); //AK-47
                    GivePlayerWeapon(playerid, 27, 2000); //Combat Shotgun
                    GivePlayerWeapon(playerid, 28, 2000); //Uzi
                    GivePlayerWeapon(playerid, 34, 2000); //Sniper
                    GivePlayerWeapon(playerid, 4, 1); //Faca

                    WeaponsKit[playerid] = 4;
                }
                case 4:
                {
                    if(!IsPlayerVip(playerid))
                    {
                        if(PlayerInfo[playerid][Dinheiro] < 1500)
                            return SendClientMessage(playerid, Erro, "Você não tem dinheiro o suficiente");

                        PlayerInfo[playerid][Dinheiro] -= 1500;
                        UpdatePlayerMoney(playerid);
                    }

                    GivePlayerWeapon(playerid, 31, 2000); //M4
                    GivePlayerWeapon(playerid, 27, 2000); //Combat Shotgun
                    GivePlayerWeapon(playerid, 29, 2000); //Mp5
                    GivePlayerWeapon(playerid, 34, 2000); //Sniper
                    GivePlayerWeapon(playerid, 4, 1); //Faca

                    WeaponsKit[playerid] = 5;
                }
            }

            if(IsPlayerVip(playerid))
                { SendClientMessage(playerid, 0x00E100AA, "Jogador(a) VIP não paga pelo KIT Arena"); }

            for(new slot; slot < MAX_ACCESSORIES; slot++)
        	{
                if(ao[playerid][slot][ao_connected])
                {
                    ao[playerid][slot][ao_connected] = false;
                    RemovePlayerAttachedObject(playerid, slot);
                }
        	}

            IsArena[playerid] = true;
            ShowTextDrawKD(playerid);

            SetPlayerArmour(playerid, 0);
            SetPlayerHealth(playerid, 99999);
            SetTimerEx("AntiSpawnKill", 3000, false, "d", playerid);

            new rand = random(sizeof(RandomSpawns));
            SetPlayerFacingAngle(playerid, RandomSpawns[rand][rs_a]);
            SetPlayerPos(playerid, RandomSpawns[rand][rs_x], RandomSpawns[rand][rs_y], RandomSpawns[rand][rs_z]);

            SendClientMessage(playerid, White, "Seja bem-vindo(a) à arena, quando quiser sair digite: /sairarena");
            return 1;
        }
    }
    return 1;
}

forward UnlockEnterArena(playerid);
public UnlockEnterArena(playerid)
{
    BlockEnterArena[playerid] = false;
    return 1;
}

forward AntiSpawnKill(playerid);
public AntiSpawnKill(playerid)
{
    SetPlayerHealth(playerid, 100);
    SendClientMessage(playerid, Red, "O Anti-Spawn Kill de 3 segundos acabou e você pode ser morto agora");
    return 1;
}

forward Spectate(playerid);
public Spectate(playerid)
{
    TogglePlayerSpectating(playerid, 0);
    return 1;
}

forward OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid);
public OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid)
{
    if(IsArena[playerid])
    {
        format(String, 20, "+Damage %.0f", amount);

        TextDrawSetString(GiveDamage[playerid], String);
        TextDrawShowForPlayer(playerid, GiveDamage[playerid]);
        PlayerPlaySound(playerid, 17802, 0.0, 0.0, 0.0);

        SetTimerEx("HideTextDrawDamage", 1000, false, "i", playerid);
    }
    return 1;
}


forward OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid);
public OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid)
{
    if(IsArena[playerid])
    {
        format(String, 20, "-Damage %.0f", amount);

        TextDrawSetString(TakeDamage[playerid], String);
        TextDrawShowForPlayer(playerid, TakeDamage[playerid]);

        SetTimerEx("HideTextDrawDamage", 1000, false, "i", playerid);
    }
    return 1;
}

forward HideTextDrawDamage(playerid);
public HideTextDrawDamage(playerid)
{
    TextDrawHideForPlayer(playerid, GiveDamage[playerid]);
    TextDrawHideForPlayer(playerid, TakeDamage[playerid]);
    return 1;

}

stock ShowTextDrawKD(playerid)
{
    format(String, sizeof(String), "~g~%d", PlayerInfo[playerid][Matou]);
    PlayerTextDrawSetString(playerid, TDPlayerKD[playerid][2], String);

    format(String, sizeof(String), "~r~%d", PlayerInfo[playerid][Morreu]);
    PlayerTextDrawSetString(playerid, TDPlayerKD[playerid][1], String);

    format(String, sizeof(String), "~g~K~w~/~r~D~w~_Ratio_:_%.1f", (float(PlayerInfo[playerid][Matou]) / float(PlayerInfo[playerid][Morreu])));
    PlayerTextDrawSetString(playerid, TDPlayerKD[playerid][0], String);


    TextDrawShowForPlayer(playerid, TDKD[0]);
    TextDrawShowForPlayer(playerid, TDKD[1]);
    TextDrawShowForPlayer(playerid, TDKD[2]);
    TextDrawShowForPlayer(playerid, TDKD[3]);
    PlayerTextDrawShow(playerid, TDPlayerKD[playerid][0]);
    PlayerTextDrawShow(playerid, TDPlayerKD[playerid][1]);
    PlayerTextDrawShow(playerid, TDPlayerKD[playerid][2]);
    return 1;
}

stock HideTextDrawKD(playerid)
{
    TextDrawHideForPlayer(playerid, TDKD[0]);
    TextDrawHideForPlayer(playerid, TDKD[1]);
    TextDrawHideForPlayer(playerid, TDKD[2]);
    TextDrawHideForPlayer(playerid, TDKD[3]);
    PlayerTextDrawHide(playerid, TDPlayerKD[playerid][0]);
    PlayerTextDrawHide(playerid, TDPlayerKD[playerid][1]);
    PlayerTextDrawHide(playerid, TDPlayerKD[playerid][2]);
    return 1;
}

stock LeftArena(playerid)
{
    if(IsArena[playerid])
    {
        switch(Enter_Arena[playerid])
        {
            case 0:
            {
                PlayerInfo[playerid][PosX] = 2695.55;
                PlayerInfo[playerid][PosY] = -1704.70;
                PlayerInfo[playerid][PosZ] = 11.84;
                PlayerInfo[playerid][PosA] = 31.45;
            }
            case 1:
            {
                PlayerInfo[playerid][PosX] = 1099.56;
                PlayerInfo[playerid][PosY] = 1601.52;
                PlayerInfo[playerid][PosZ] = 12.54;
                PlayerInfo[playerid][PosA] = 174.62;
            }
            case 2:
            {
                PlayerInfo[playerid][PosX] = -2110.82;
                PlayerInfo[playerid][PosY] = -444.22;
                PlayerInfo[playerid][PosZ] = 38.73;
                PlayerInfo[playerid][PosA] = 270.19;
            }
        }
    }
    return 1;
}

/******************************************************************************/
/******************************| COMMANDS AREBA |******************************/
/******************************************************************************/

CMD:sairarena(playerid)
{
    if(!IsArena[playerid])
        return SendClientMessage(playerid, Erro, "Você não está em uma arena");

    switch(Enter_Arena[playerid])
    {
        case 0:
        {
            SetPlayerFacingAngle(playerid, 31.45);
            SetPlayerPos(playerid, 2695.55, -1704.70, 11.84);
        }
        case 1:
        {
            SetPlayerFacingAngle(playerid, 174.62);
            SetPlayerPos(playerid, 1099.56, 1601.52, 12.54);
        }
        case 2:
        {
            SetPlayerFacingAngle(playerid, 270.19);
            SetPlayerPos(playerid, -2110.82, -444.22, 38.73);
        }
    }

    TogglePlayerSpectating(playerid, 0);

    BlockEnterArena[playerid] = true;
    IsArena[playerid] = false;
    ResetPlayerWeapons(playerid);
    HideTextDrawKD(playerid);
    SetPlayerVirtualWorld(playerid, 0);
    SetTimerEx("UnlockEnterArena", 1000*60*2, false, "d", playerid);
    return 1;
}
