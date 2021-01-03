#include YSI\y_hooks

new Text:TDAntiAfk[4];
new PlayerText:TDPlayerAntiAfk[MAX_PLAYERS][1];

hook OnGameModeInit()
{
    TDAntiAfk[0] = TextDrawCreate(215.500000, 119.066589, "box");
    TextDrawLetterSize(TDAntiAfk[0], 0.000000, 14.399994);
    TextDrawTextSize(TDAntiAfk[0], 421.000000, 0.000000);
    TextDrawAlignment(TDAntiAfk[0], 1);
    TextDrawColor(TDAntiAfk[0], -1);
    TextDrawUseBox(TDAntiAfk[0], 1);
    TextDrawBoxColor(TDAntiAfk[0], -206);
    TextDrawSetShadow(TDAntiAfk[0], 0);
    TextDrawSetOutline(TDAntiAfk[0], 0);
    TextDrawBackgroundColor(TDAntiAfk[0], 255);
    TextDrawFont(TDAntiAfk[0], 1);
    TextDrawSetProportional(TDAntiAfk[0], 1);
    TextDrawSetShadow(TDAntiAfk[0], 0);

    TDAntiAfk[1] = TextDrawCreate(262.000000, 132.133270, "VIDA_REAL_CRIAS");
    TextDrawLetterSize(TDAntiAfk[1], 0.400000, 1.600000);
    TextDrawAlignment(TDAntiAfk[1], 1);
    TextDrawColor(TDAntiAfk[1], -5963521);
    TextDrawSetShadow(TDAntiAfk[1], 0);
    TextDrawSetOutline(TDAntiAfk[1], 1);
    TextDrawBackgroundColor(TDAntiAfk[1], 255);
    TextDrawFont(TDAntiAfk[1], 3);
    TextDrawSetProportional(TDAntiAfk[1], 1);
    TextDrawSetShadow(TDAntiAfk[1], 0);

    TDAntiAfk[2] = TextDrawCreate(334.500000, 147.066650, "ANTI-AFK");
    TextDrawLetterSize(TDAntiAfk[2], 0.232500, 1.176887);
    TextDrawAlignment(TDAntiAfk[2], 1);
    TextDrawColor(TDAntiAfk[2], -1);
    TextDrawSetShadow(TDAntiAfk[2], 0);
    TextDrawSetOutline(TDAntiAfk[2], 0);
    TextDrawBackgroundColor(TDAntiAfk[2], 255);
    TextDrawFont(TDAntiAfk[2], 1);
    TextDrawSetProportional(TDAntiAfk[2], 1);
    TextDrawSetShadow(TDAntiAfk[2], 0);

    TDAntiAfk[3] = TextDrawCreate(218.000000, 236.377593, "~r~Obs~w~:_Voce_esta_ausente,_digite_o_codigo_para_continuar_jogando.");
    TextDrawLetterSize(TDAntiAfk[3], 0.174500, 1.064887);
    TextDrawAlignment(TDAntiAfk[3], 1);
    TextDrawColor(TDAntiAfk[3], -16776961);
    TextDrawSetShadow(TDAntiAfk[3], 0);
    TextDrawSetOutline(TDAntiAfk[3], 0);
    TextDrawBackgroundColor(TDAntiAfk[3], 255);
    TextDrawFont(TDAntiAfk[3], 1);
    TextDrawSetProportional(TDAntiAfk[3], 1);
    TextDrawSetShadow(TDAntiAfk[3], 0);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    TDPlayerAntiAfk[playerid][0] = CreatePlayerTextDraw(playerid, 314.201446, 182.354598, "DIGITE:~n~/SAIRAFK_XXXXXX");
    PlayerTextDrawLetterSize(playerid, TDPlayerAntiAfk[playerid][0], 0.313998, 1.631109);
    PlayerTextDrawAlignment(playerid, TDPlayerAntiAfk[playerid][0], 2);
    PlayerTextDrawColor(playerid, TDPlayerAntiAfk[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerAntiAfk[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerAntiAfk[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerAntiAfk[playerid][0], 255);
    PlayerTextDrawFont(playerid, TDPlayerAntiAfk[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, TDPlayerAntiAfk[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerAntiAfk[playerid][0], 0);
    return 1;
}

stock ShowTDAntiAfk(playerid)
{
    for(new i = 0; i < 4; i++){
        TextDrawShowForPlayer(playerid, TDAntiAfk[i]);
    }
    for(new i = 0; i < 1; i++){
        PlayerTextDrawShow(playerid, TDPlayerAntiAfk[playerid][i]);
    }
    return 1;
}

stock HideTDAntiAfk(playerid)
{
    for(new i = 0; i < 4; i++){
        TextDrawHideForPlayer(playerid, TDAntiAfk[i]);
    }
    for(new i = 0; i < 1; i++){
        PlayerTextDrawHide(playerid, TDPlayerAntiAfk[playerid][i]);
    }
    return 1;
}
