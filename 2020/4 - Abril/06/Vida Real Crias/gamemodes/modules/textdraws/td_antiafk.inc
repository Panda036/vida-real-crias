#include YSI\y_hooks

new Text:TDAntiAfk[5];
new PlayerText:TDPlayerAntiAfk[MAX_PLAYERS][2];

hook OnGameModeInit()
{
    TDAntiAfk[0] = TextDrawCreate(215.500000, 119.066589, "box");
    TextDrawLetterSize(TDAntiAfk[0], 0.000000, 14.399996);
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

    TDAntiAfk[1] = TextDrawCreate(243.999847, 207.958068, "box");
    TextDrawLetterSize(TDAntiAfk[1], 0.000000, 2.250000);
    TextDrawTextSize(TDAntiAfk[1], 387.499847, 0.000000);
    TextDrawAlignment(TDAntiAfk[1], 1);
    TextDrawColor(TDAntiAfk[1], -1);
    TextDrawUseBox(TDAntiAfk[1], 1);
    TextDrawBoxColor(TDAntiAfk[1], -106);
    TextDrawSetShadow(TDAntiAfk[1], 0);
    TextDrawSetOutline(TDAntiAfk[1], 0);
    TextDrawBackgroundColor(TDAntiAfk[1], 255);
    TextDrawFont(TDAntiAfk[1], 1);
    TextDrawSetProportional(TDAntiAfk[1], 1);
    TextDrawSetShadow(TDAntiAfk[1], 0);

    TDAntiAfk[2] = TextDrawCreate(262.000000, 132.133270, "VIDA_REAL_CRIAS");
    TextDrawLetterSize(TDAntiAfk[2], 0.400000, 1.600000);
    TextDrawAlignment(TDAntiAfk[2], 1);
    TextDrawColor(TDAntiAfk[2], -5963521);
    TextDrawSetShadow(TDAntiAfk[2], 0);
    TextDrawSetOutline(TDAntiAfk[2], 1);
    TextDrawBackgroundColor(TDAntiAfk[2], 255);
    TextDrawFont(TDAntiAfk[2], 3);
    TextDrawSetProportional(TDAntiAfk[2], 1);
    TextDrawSetShadow(TDAntiAfk[2], 0);

    TDAntiAfk[3] = TextDrawCreate(334.500000, 147.066650, "ANTI-AFK");
    TextDrawLetterSize(TDAntiAfk[3], 0.232500, 1.176887);
    TextDrawAlignment(TDAntiAfk[3], 1);
    TextDrawColor(TDAntiAfk[3], -1);
    TextDrawSetShadow(TDAntiAfk[3], 0);
    TextDrawSetOutline(TDAntiAfk[3], 0);
    TextDrawBackgroundColor(TDAntiAfk[3], 255);
    TextDrawFont(TDAntiAfk[3], 1);
    TextDrawSetProportional(TDAntiAfk[3], 1);
    TextDrawSetShadow(TDAntiAfk[3], 0);

    TDAntiAfk[4] = TextDrawCreate(218.000000, 239.777801, "~r~Obs~w~:_Voce_esta_ausente,_digite_o_codigo_para_continuar_jogando.");
    TextDrawLetterSize(TDAntiAfk[4], 0.164000, 0.959109);
    TextDrawAlignment(TDAntiAfk[4], 1);
    TextDrawColor(TDAntiAfk[4], -16776961);
    TextDrawSetShadow(TDAntiAfk[4], 0);
    TextDrawSetOutline(TDAntiAfk[4], 0);
    TextDrawBackgroundColor(TDAntiAfk[4], 255);
    TextDrawFont(TDAntiAfk[4], 1);
    TextDrawSetProportional(TDAntiAfk[4], 1);
    TextDrawSetShadow(TDAntiAfk[4], 0);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    TDPlayerAntiAfk[playerid][0] = CreatePlayerTextDraw(playerid, 313.701446, 177.099212, "X92KF621");
    PlayerTextDrawLetterSize(playerid, TDPlayerAntiAfk[playerid][0], 0.400000, 1.600000);
    PlayerTextDrawAlignment(playerid, TDPlayerAntiAfk[playerid][0], 2);
    PlayerTextDrawColor(playerid, TDPlayerAntiAfk[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerAntiAfk[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerAntiAfk[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerAntiAfk[playerid][0], 255);
    PlayerTextDrawFont(playerid, TDPlayerAntiAfk[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, TDPlayerAntiAfk[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerAntiAfk[playerid][0], 0);

    TDPlayerAntiAfk[playerid][1] = CreatePlayerTextDraw(playerid, 258.399871, 211.577789, "CLIQUE_AQUI_PARA_COLOCAR_O_CODIGO");
    PlayerTextDrawLetterSize(playerid, TDPlayerAntiAfk[playerid][1], 0.146999, 1.201776);
    PlayerTextDrawAlignment(playerid, TDPlayerAntiAfk[playerid][1], 1);
    PlayerTextDrawColor(playerid, TDPlayerAntiAfk[playerid][1], 150);
    PlayerTextDrawSetShadow(playerid, TDPlayerAntiAfk[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerAntiAfk[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerAntiAfk[playerid][1], 255);
    PlayerTextDrawFont(playerid, TDPlayerAntiAfk[playerid][1], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerAntiAfk[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerAntiAfk[playerid][1], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerAntiAfk[playerid][1], true);
    PlayerTextDrawTextSize(playerid, TDPlayerAntiAfk[playerid][1], 362.000000, 10.000000);
    return 1;
}

stock ShowTDAntiAfk(playerid)
{
    SelectTextDraw(playerid, Green);

    for(new i = 0; i < 5; i++){
        TextDrawShowForPlayer(playerid, TDAntiAfk[i]);
    }
    for(new i = 0; i < 2; i++){
        PlayerTextDrawShow(playerid, TDPlayerAntiAfk[playerid][i]);
    }
    return 1;
}

stock HideTDAntiAfk(playerid)
{
    CancelSelectTextDraw(playerid);

    for(new i = 0; i < 5; i++){
        TextDrawHideForPlayer(playerid, TDAntiAfk[i]);
    }
    for(new i = 0; i < 2; i++){
        PlayerTextDrawHide(playerid, TDPlayerAntiAfk[playerid][i]);
    }
    return 1;
}
