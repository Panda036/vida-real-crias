#include YSI\y_hooks

new Text:TDCoding[15];
new PlayerText:TDPlayerCoding[MAX_PLAYERS][2];

hook OnGameModeInit()
{
    TDCoding[0] = TextDrawCreate(247.600860, 122.877304, "box");
    TextDrawLetterSize(TDCoding[0], 0.000000, 17.702919);
    TextDrawTextSize(TDCoding[0], 393.000000, 0.000000);
    TextDrawAlignment(TDCoding[0], 1);
    TextDrawColor(TDCoding[0], -1);
    TextDrawUseBox(TDCoding[0], 1);
    TextDrawBoxColor(TDCoding[0], 100);
    TextDrawSetShadow(TDCoding[0], 0);
    TextDrawSetOutline(TDCoding[0], 0);
    TextDrawBackgroundColor(TDCoding[0], 255);
    TextDrawFont(TDCoding[0], 1);
    TextDrawSetProportional(TDCoding[0], 1);
    TextDrawSetShadow(TDCoding[0], 0);

    TDCoding[1] = TextDrawCreate(261.500000, 185.669097, "ld_pool:ball");
    TextDrawLetterSize(TDCoding[1], 0.000000, 0.000000);
    TextDrawTextSize(TDCoding[1], 25.000000, 26.000000);
    TextDrawAlignment(TDCoding[1], 1);
    TextDrawColor(TDCoding[1], -92724737);
    TextDrawSetShadow(TDCoding[1], 0);
    TextDrawSetOutline(TDCoding[1], 0);
    TextDrawBackgroundColor(TDCoding[1], 255);
    TextDrawFont(TDCoding[1], 4);
    TextDrawSetProportional(TDCoding[1], 0);
    TextDrawSetShadow(TDCoding[1], 0);

    TDCoding[2] = TextDrawCreate(347.905334, 185.969116, "ld_pool:ball");
    TextDrawLetterSize(TDCoding[2], 0.000000, 0.000000);
    TextDrawTextSize(TDCoding[2], 25.000000, 25.509988);
    TextDrawAlignment(TDCoding[2], 1);
    TextDrawColor(TDCoding[2], -92724737);
    TextDrawSetShadow(TDCoding[2], 0);
    TextDrawSetOutline(TDCoding[2], 0);
    TextDrawBackgroundColor(TDCoding[2], 255);
    TextDrawFont(TDCoding[2], 4);
    TextDrawSetProportional(TDCoding[2], 0);
    TextDrawSetShadow(TDCoding[2], 0);

    TDCoding[3] = TextDrawCreate(275.600036, 189.057922, "box");
    TextDrawLetterSize(TDCoding[3], 0.000000, 2.146991);
    TextDrawTextSize(TDCoding[3], 359.000000, 0.000000);
    TextDrawAlignment(TDCoding[3], 1);
    TextDrawColor(TDCoding[3], -1);
    TextDrawUseBox(TDCoding[3], 1);
    TextDrawBoxColor(TDCoding[3], -92724737);
    TextDrawSetShadow(TDCoding[3], 0);
    TextDrawSetOutline(TDCoding[3], 0);
    TextDrawBackgroundColor(TDCoding[3], 255);
    TextDrawFont(TDCoding[3], 1);
    TextDrawSetProportional(TDCoding[3], 1);
    TextDrawSetShadow(TDCoding[3], 0);

    TDCoding[4] = TextDrawCreate(263.200073, 187.669219, "ld_pool:ball");
    TextDrawLetterSize(TDCoding[4], 0.000000, 0.000000);
    TextDrawTextSize(TDCoding[4], 22.739948, 22.069910);
    TextDrawAlignment(TDCoding[4], 1);
    TextDrawColor(TDCoding[4], 255);
    TextDrawSetShadow(TDCoding[4], 0);
    TextDrawSetOutline(TDCoding[4], 0);
    TextDrawBackgroundColor(TDCoding[4], 255);
    TextDrawFont(TDCoding[4], 4);
    TextDrawSetProportional(TDCoding[4], 0);
    TextDrawSetShadow(TDCoding[4], 0);

    TDCoding[5] = TextDrawCreate(348.105285, 187.947052, "ld_pool:ball");
    TextDrawLetterSize(TDCoding[5], 0.000000, 0.000000);
    TextDrawTextSize(TDCoding[5], 22.739948, 22.069910);
    TextDrawAlignment(TDCoding[5], 1);
    TextDrawColor(TDCoding[5], 255);
    TextDrawSetShadow(TDCoding[5], 0);
    TextDrawSetOutline(TDCoding[5], 0);
    TextDrawBackgroundColor(TDCoding[5], 255);
    TextDrawFont(TDCoding[5], 4);
    TextDrawSetProportional(TDCoding[5], 0);
    TextDrawSetShadow(TDCoding[5], 0);

    TDCoding[6] = TextDrawCreate(275.100036, 190.558013, "box");
    TextDrawLetterSize(TDCoding[6], 0.000000, 1.837996);
    TextDrawTextSize(TDCoding[6], 362.000000, 0.000000);
    TextDrawAlignment(TDCoding[6], 1);
    TextDrawColor(TDCoding[6], -1);
    TextDrawUseBox(TDCoding[6], 1);
    TextDrawBoxColor(TDCoding[6], 255);
    TextDrawSetShadow(TDCoding[6], 0);
    TextDrawSetOutline(TDCoding[6], 0);
    TextDrawBackgroundColor(TDCoding[6], 255);
    TextDrawFont(TDCoding[6], 1);
    TextDrawSetProportional(TDCoding[6], 1);
    TextDrawSetShadow(TDCoding[6], 0);

    TDCoding[7] = TextDrawCreate(264.500000, 135.355224, "VIDA_REAL_CRIAS");
    TextDrawLetterSize(TDCoding[7], 0.400000, 1.600000);
    TextDrawAlignment(TDCoding[7], 1);
    TextDrawColor(TDCoding[7], -5963521);
    TextDrawSetShadow(TDCoding[7], -1);
    TextDrawSetOutline(TDCoding[7], 1);
    TextDrawBackgroundColor(TDCoding[7], 255);
    TextDrawFont(TDCoding[7], 3);
    TextDrawSetProportional(TDCoding[7], 1);
    TextDrawSetShadow(TDCoding[7], -1);

    TDCoding[8] = TextDrawCreate(301.098724, 150.467712, "Copyright_2020_-_RPG");
    TextDrawLetterSize(TDCoding[8], 0.180500, 0.834662);
    TextDrawAlignment(TDCoding[8], 1);
    TextDrawColor(TDCoding[8], -1);
    TextDrawSetShadow(TDCoding[8], 0);
    TextDrawSetOutline(TDCoding[8], 1);
    TextDrawBackgroundColor(TDCoding[8], 255);
    TextDrawFont(TDCoding[8], 1);
    TextDrawSetProportional(TDCoding[8], 1);
    TextDrawSetShadow(TDCoding[8], 0);

    TDCoding[9] = TextDrawCreate(284.095886, 235.427505, "ld_pool:ball");
    TextDrawLetterSize(TDCoding[9], 0.000000, 0.000000);
    TextDrawTextSize(TDCoding[9], 25.000000, 26.000000);
    TextDrawAlignment(TDCoding[9], 1);
    TextDrawColor(TDCoding[9], 8388863);
    TextDrawSetShadow(TDCoding[9], 0);
    TextDrawSetOutline(TDCoding[9], 0);
    TextDrawBackgroundColor(TDCoding[9], 255);
    TextDrawFont(TDCoding[9], 4);
    TextDrawSetProportional(TDCoding[9], 0);
    TextDrawSetShadow(TDCoding[9], 0);

    TDCoding[10] = TextDrawCreate(321.104980, 235.859558, "ld_pool:ball");
    TextDrawLetterSize(TDCoding[10], 0.000000, 0.000000);
    TextDrawTextSize(TDCoding[10], 25.000000, 25.509988);
    TextDrawAlignment(TDCoding[10], 1);
    TextDrawColor(TDCoding[10], 8388863);
    TextDrawSetShadow(TDCoding[10], 0);
    TextDrawSetOutline(TDCoding[10], 0);
    TextDrawBackgroundColor(TDCoding[10], 255);
    TextDrawFont(TDCoding[10], 4);
    TextDrawSetProportional(TDCoding[10], 0);
    TextDrawSetShadow(TDCoding[10], 0);

    TDCoding[11] = TextDrawCreate(298.201721, 238.471862, "box");
    TextDrawLetterSize(TDCoding[11], 0.000000, 2.209988);
    TextDrawTextSize(TDCoding[11], 333.508544, 0.000000);
    TextDrawAlignment(TDCoding[11], 1);
    TextDrawColor(TDCoding[11], 8388863);
    TextDrawUseBox(TDCoding[11], 1);
    TextDrawBoxColor(TDCoding[11], 8388863);
    TextDrawSetShadow(TDCoding[11], 0);
    TextDrawSetOutline(TDCoding[11], 0);
    TextDrawBackgroundColor(TDCoding[11], 255);
    TextDrawFont(TDCoding[11], 1);
    TextDrawSetProportional(TDCoding[11], 1);
    TextDrawSetShadow(TDCoding[11], 0);

    TDCoding[12] = TextDrawCreate(286.101470, 237.772277, "ld_pool:ball");
    TextDrawLetterSize(TDCoding[12], 0.000000, 0.000000);
    TextDrawTextSize(TDCoding[12], 25.000000, 21.709924);
    TextDrawAlignment(TDCoding[12], 1);
    TextDrawColor(TDCoding[12], 255);
    TextDrawSetShadow(TDCoding[12], 0);
    TextDrawSetOutline(TDCoding[12], 0);
    TextDrawBackgroundColor(TDCoding[12], 255);
    TextDrawFont(TDCoding[12], 4);
    TextDrawSetProportional(TDCoding[12], 0);
    TextDrawSetShadow(TDCoding[12], 0);

    TDCoding[13] = TextDrawCreate(321.403625, 237.972290, "ld_pool:ball");
    TextDrawLetterSize(TDCoding[13], 0.000000, 0.000000);
    TextDrawTextSize(TDCoding[13], 22.739948, 21.349893);
    TextDrawAlignment(TDCoding[13], 1);
    TextDrawColor(TDCoding[13], 255);
    TextDrawSetShadow(TDCoding[13], 0);
    TextDrawSetOutline(TDCoding[13], 0);
    TextDrawBackgroundColor(TDCoding[13], 255);
    TextDrawFont(TDCoding[13], 4);
    TextDrawSetProportional(TDCoding[13], 0);
    TextDrawSetShadow(TDCoding[13], 0);

    TDCoding[14] = TextDrawCreate(298.201721, 240.371978, "box");
    TextDrawLetterSize(TDCoding[14], 0.000000, 1.843994);
    TextDrawTextSize(TDCoding[14], 334.000000, 0.000000);
    TextDrawAlignment(TDCoding[14], 1);
    TextDrawColor(TDCoding[14], 8388863);
    TextDrawUseBox(TDCoding[14], 1);
    TextDrawBoxColor(TDCoding[14], 255);
    TextDrawSetShadow(TDCoding[14], 0);
    TextDrawSetOutline(TDCoding[14], 0);
    TextDrawBackgroundColor(TDCoding[14], 255);
    TextDrawFont(TDCoding[14], 1);
    TextDrawSetProportional(TDCoding[14], 1);
    TextDrawSetShadow(TDCoding[14], 0);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    TDPlayerCoding[playerid][0] = CreatePlayerTextDraw(playerid, 317.400054, 193.957885, "CLIQUE_AQUI_PARA_COLOCAR_SEU_CODIGO");
    PlayerTextDrawLetterSize(playerid, TDPlayerCoding[playerid][0], 0.097498, 0.840888);
    PlayerTextDrawAlignment(playerid, TDPlayerCoding[playerid][0], 2);
    PlayerTextDrawColor(playerid, TDPlayerCoding[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerCoding[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerCoding[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerCoding[playerid][0], 255);
    PlayerTextDrawFont(playerid, TDPlayerCoding[playerid][0], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerCoding[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerCoding[playerid][0], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerCoding[playerid][0], true);
    PlayerTextDrawTextSize(playerid, TDPlayerCoding[playerid][0], 10.000000, 78.000000);

    TDPlayerCoding[playerid][1] = CreatePlayerTextDraw(playerid, 295.299957, 242.387145, "Continuar");
    PlayerTextDrawLetterSize(playerid, TDPlayerCoding[playerid][1], 0.267999, 1.176887);
    PlayerTextDrawAlignment(playerid, TDPlayerCoding[playerid][1], 1);
    PlayerTextDrawColor(playerid, TDPlayerCoding[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerCoding[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerCoding[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerCoding[playerid][1], 255);
    PlayerTextDrawFont(playerid, TDPlayerCoding[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, TDPlayerCoding[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerCoding[playerid][1], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerCoding[playerid][1], true);
    PlayerTextDrawTextSize(playerid, TDPlayerCoding[playerid][1], 335.000000, 10.000000);
    return 1;
}

stock TDCodingShow(playerid)
{
    for(new i = 0; i < 15; i++)
        { TextDrawShowForPlayer(playerid, TDCoding[i]); }
    for(new i = 0; i < 2; i++)
        { PlayerTextDrawShow(playerid, TDPlayerCoding[playerid][i]); }
    return 1;
}

stock TDCodingHide(playerid)
{
    for(new i = 0; i < 15; i++)
        { TextDrawHideForPlayer(playerid, TDCoding[i]); }
    for(new i = 0; i < 2; i++)
        { PlayerTextDrawHide(playerid, TDPlayerCoding[playerid][i]); }
    return 1;
}
