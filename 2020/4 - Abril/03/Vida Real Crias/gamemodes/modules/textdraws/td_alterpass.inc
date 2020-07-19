#include YSI\y_hooks

new Text:TDAlterPass[21];
new PlayerText:TDPlayerAlterPass[MAX_PLAYERS][3];

hook OnGameModeInit()
{
    TDAlterPass[0] = TextDrawCreate(246.600860, 112.099693, "box");
    TextDrawLetterSize(TDAlterPass[0], 0.000000, 20.277503);
    TextDrawTextSize(TDAlterPass[0], 392.000000, 0.000000);
    TextDrawAlignment(TDAlterPass[0], 1);
    TextDrawColor(TDAlterPass[0], -1);
    TextDrawUseBox(TDAlterPass[0], 1);
    TextDrawBoxColor(TDAlterPass[0], 100);
    TextDrawSetShadow(TDAlterPass[0], 0);
    TextDrawSetOutline(TDAlterPass[0], 0);
    TextDrawBackgroundColor(TDAlterPass[0], 255);
    TextDrawFont(TDAlterPass[0], 1);
    TextDrawSetProportional(TDAlterPass[0], 1);
    TextDrawSetShadow(TDAlterPass[0], 0);

    TDAlterPass[1] = TextDrawCreate(261.500000, 177.568603, "ld_pool:ball");
    TextDrawLetterSize(TDAlterPass[1], 0.000000, 0.000000);
    TextDrawTextSize(TDAlterPass[1], 25.000000, 26.000000);
    TextDrawAlignment(TDAlterPass[1], 1);
    TextDrawColor(TDAlterPass[1], -92724737);
    TextDrawSetShadow(TDAlterPass[1], 0);
    TextDrawSetOutline(TDAlterPass[1], 0);
    TextDrawBackgroundColor(TDAlterPass[1], 255);
    TextDrawFont(TDAlterPass[1], 4);
    TextDrawSetProportional(TDAlterPass[1], 0);
    TextDrawSetShadow(TDAlterPass[1], 0);

    TDAlterPass[2] = TextDrawCreate(349.605346, 177.968627, "ld_pool:ball");
    TextDrawLetterSize(TDAlterPass[2], 0.000000, 0.000000);
    TextDrawTextSize(TDAlterPass[2], 25.000000, 25.509988);
    TextDrawAlignment(TDAlterPass[2], 1);
    TextDrawColor(TDAlterPass[2], -92724737);
    TextDrawSetShadow(TDAlterPass[2], 0);
    TextDrawSetOutline(TDAlterPass[2], 0);
    TextDrawBackgroundColor(TDAlterPass[2], 255);
    TextDrawFont(TDAlterPass[2], 4);
    TextDrawSetProportional(TDAlterPass[2], 0);
    TextDrawSetShadow(TDAlterPass[2], 0);

    TDAlterPass[3] = TextDrawCreate(276.100036, 180.757415, "box");
    TextDrawLetterSize(TDAlterPass[3], 0.000000, 2.146991);
    TextDrawTextSize(TDAlterPass[3], 362.000000, 0.000000);
    TextDrawAlignment(TDAlterPass[3], 1);
    TextDrawColor(TDAlterPass[3], -1);
    TextDrawUseBox(TDAlterPass[3], 1);
    TextDrawBoxColor(TDAlterPass[3], -92724737);
    TextDrawSetShadow(TDAlterPass[3], 0);
    TextDrawSetOutline(TDAlterPass[3], 0);
    TextDrawBackgroundColor(TDAlterPass[3], 255);
    TextDrawFont(TDAlterPass[3], 1);
    TextDrawSetProportional(TDAlterPass[3], 1);
    TextDrawSetShadow(TDAlterPass[3], 0);

    TDAlterPass[4] = TextDrawCreate(263.200073, 179.668731, "ld_pool:ball");
    TextDrawLetterSize(TDAlterPass[4], 0.000000, 0.000000);
    TextDrawTextSize(TDAlterPass[4], 22.739948, 22.069910);
    TextDrawAlignment(TDAlterPass[4], 1);
    TextDrawColor(TDAlterPass[4], 255);
    TextDrawSetShadow(TDAlterPass[4], 0);
    TextDrawSetOutline(TDAlterPass[4], 0);
    TextDrawBackgroundColor(TDAlterPass[4], 255);
    TextDrawFont(TDAlterPass[4], 4);
    TextDrawSetProportional(TDAlterPass[4], 0);
    TextDrawSetShadow(TDAlterPass[4], 0);

    TDAlterPass[5] = TextDrawCreate(350.105377, 179.946563, "ld_pool:ball");
    TextDrawLetterSize(TDAlterPass[5], 0.000000, 0.000000);
    TextDrawTextSize(TDAlterPass[5], 22.739948, 22.069910);
    TextDrawAlignment(TDAlterPass[5], 1);
    TextDrawColor(TDAlterPass[5], 255);
    TextDrawSetShadow(TDAlterPass[5], 0);
    TextDrawSetOutline(TDAlterPass[5], 0);
    TextDrawBackgroundColor(TDAlterPass[5], 255);
    TextDrawFont(TDAlterPass[5], 4);
    TextDrawSetProportional(TDAlterPass[5], 0);
    TextDrawSetShadow(TDAlterPass[5], 0);

    TDAlterPass[6] = TextDrawCreate(275.100036, 182.557525, "box");
    TextDrawLetterSize(TDAlterPass[6], 0.000000, 1.837996);
    TextDrawTextSize(TDAlterPass[6], 362.000000, 0.000000);
    TextDrawAlignment(TDAlterPass[6], 1);
    TextDrawColor(TDAlterPass[6], -1);
    TextDrawUseBox(TDAlterPass[6], 1);
    TextDrawBoxColor(TDAlterPass[6], 255);
    TextDrawSetShadow(TDAlterPass[6], 0);
    TextDrawSetOutline(TDAlterPass[6], 0);
    TextDrawBackgroundColor(TDAlterPass[6], 255);
    TextDrawFont(TDAlterPass[6], 1);
    TextDrawSetProportional(TDAlterPass[6], 1);
    TextDrawSetShadow(TDAlterPass[6], 0);

    TDAlterPass[7] = TextDrawCreate(264.500000, 120.854881, "VIDA_REAL_CRIAS");
    TextDrawLetterSize(TDAlterPass[7], 0.400000, 1.600000);
    TextDrawAlignment(TDAlterPass[7], 1);
    TextDrawColor(TDAlterPass[7], -5963521);
    TextDrawSetShadow(TDAlterPass[7], -1);
    TextDrawSetOutline(TDAlterPass[7], 1);
    TextDrawBackgroundColor(TDAlterPass[7], 255);
    TextDrawFont(TDAlterPass[7], 3);
    TextDrawSetProportional(TDAlterPass[7], 1);
    TextDrawSetShadow(TDAlterPass[7], -1);

    TDAlterPass[8] = TextDrawCreate(301.098724, 137.166900, "Copyright_2020_-_RPG");
    TextDrawLetterSize(TDAlterPass[8], 0.180500, 0.834662);
    TextDrawAlignment(TDAlterPass[8], 1);
    TextDrawColor(TDAlterPass[8], -1);
    TextDrawSetShadow(TDAlterPass[8], 0);
    TextDrawSetOutline(TDAlterPass[8], 1);
    TextDrawBackgroundColor(TDAlterPass[8], 255);
    TextDrawFont(TDAlterPass[8], 1);
    TextDrawSetProportional(TDAlterPass[8], 1);
    TextDrawSetShadow(TDAlterPass[8], 0);

    TDAlterPass[9] = TextDrawCreate(261.500000, 209.570556, "ld_pool:ball");
    TextDrawLetterSize(TDAlterPass[9], 0.000000, 0.000000);
    TextDrawTextSize(TDAlterPass[9], 25.000000, 26.000000);
    TextDrawAlignment(TDAlterPass[9], 1);
    TextDrawColor(TDAlterPass[9], -92724737);
    TextDrawSetShadow(TDAlterPass[9], 0);
    TextDrawSetOutline(TDAlterPass[9], 0);
    TextDrawBackgroundColor(TDAlterPass[9], 255);
    TextDrawFont(TDAlterPass[9], 4);
    TextDrawSetProportional(TDAlterPass[9], 0);
    TextDrawSetShadow(TDAlterPass[9], 0);

    TDAlterPass[10] = TextDrawCreate(349.605346, 209.770568, "ld_pool:ball");
    TextDrawLetterSize(TDAlterPass[10], 0.000000, 0.000000);
    TextDrawTextSize(TDAlterPass[10], 25.000000, 25.509988);
    TextDrawAlignment(TDAlterPass[10], 1);
    TextDrawColor(TDAlterPass[10], -92724737);
    TextDrawSetShadow(TDAlterPass[10], 0);
    TextDrawSetOutline(TDAlterPass[10], 0);
    TextDrawBackgroundColor(TDAlterPass[10], 255);
    TextDrawFont(TDAlterPass[10], 4);
    TextDrawSetProportional(TDAlterPass[10], 0);
    TextDrawSetShadow(TDAlterPass[10], 0);

    TDAlterPass[11] = TextDrawCreate(274.399932, 212.659362, "box");
    TextDrawLetterSize(TDAlterPass[11], 0.000000, 2.160989);
    TextDrawTextSize(TDAlterPass[11], 360.299896, 0.000000);
    TextDrawAlignment(TDAlterPass[11], 1);
    TextDrawColor(TDAlterPass[11], -1);
    TextDrawUseBox(TDAlterPass[11], 1);
    TextDrawBoxColor(TDAlterPass[11], -92724737);
    TextDrawSetShadow(TDAlterPass[11], 0);
    TextDrawSetOutline(TDAlterPass[11], 0);
    TextDrawBackgroundColor(TDAlterPass[11], 255);
    TextDrawFont(TDAlterPass[11], 1);
    TextDrawSetProportional(TDAlterPass[11], 1);
    TextDrawSetShadow(TDAlterPass[11], 0);

    TDAlterPass[12] = TextDrawCreate(263.200073, 211.470672, "ld_pool:ball");
    TextDrawLetterSize(TDAlterPass[12], 0.000000, 0.000000);
    TextDrawTextSize(TDAlterPass[12], 22.739948, 22.069910);
    TextDrawAlignment(TDAlterPass[12], 1);
    TextDrawColor(TDAlterPass[12], 255);
    TextDrawSetShadow(TDAlterPass[12], 0);
    TextDrawSetOutline(TDAlterPass[12], 0);
    TextDrawBackgroundColor(TDAlterPass[12], 255);
    TextDrawFont(TDAlterPass[12], 4);
    TextDrawSetProportional(TDAlterPass[12], 0);
    TextDrawSetShadow(TDAlterPass[12], 0);

    TDAlterPass[13] = TextDrawCreate(350.105377, 211.748504, "ld_pool:ball");
    TextDrawLetterSize(TDAlterPass[13], 0.000000, 0.000000);
    TextDrawTextSize(TDAlterPass[13], 22.739948, 22.069910);
    TextDrawAlignment(TDAlterPass[13], 1);
    TextDrawColor(TDAlterPass[13], 255);
    TextDrawSetShadow(TDAlterPass[13], 0);
    TextDrawSetOutline(TDAlterPass[13], 0);
    TextDrawBackgroundColor(TDAlterPass[13], 255);
    TextDrawFont(TDAlterPass[13], 4);
    TextDrawSetProportional(TDAlterPass[13], 0);
    TextDrawSetShadow(TDAlterPass[13], 0);

    TDAlterPass[14] = TextDrawCreate(274.500030, 214.559478, "box");
    TextDrawLetterSize(TDAlterPass[14], 0.000000, 1.837996);
    TextDrawTextSize(TDAlterPass[14], 361.000000, 0.000000);
    TextDrawAlignment(TDAlterPass[14], 1);
    TextDrawColor(TDAlterPass[14], -1);
    TextDrawUseBox(TDAlterPass[14], 1);
    TextDrawBoxColor(TDAlterPass[14], 255);
    TextDrawSetShadow(TDAlterPass[14], 0);
    TextDrawSetOutline(TDAlterPass[14], 0);
    TextDrawBackgroundColor(TDAlterPass[14], 255);
    TextDrawFont(TDAlterPass[14], 1);
    TextDrawSetProportional(TDAlterPass[14], 1);
    TextDrawSetShadow(TDAlterPass[14], 0);

    TDAlterPass[15] = TextDrawCreate(285.501464, 257.595672, "ld_pool:ball");
    TextDrawLetterSize(TDAlterPass[15], 0.000000, 0.000000);
    TextDrawTextSize(TDAlterPass[15], 25.000000, 26.000000);
    TextDrawAlignment(TDAlterPass[15], 1);
    TextDrawColor(TDAlterPass[15], 8388863);
    TextDrawSetShadow(TDAlterPass[15], 0);
    TextDrawSetOutline(TDAlterPass[15], 0);
    TextDrawBackgroundColor(TDAlterPass[15], 255);
    TextDrawFont(TDAlterPass[15], 4);
    TextDrawSetProportional(TDAlterPass[15], 0);
    TextDrawSetShadow(TDAlterPass[15], 0);

    TDAlterPass[16] = TextDrawCreate(321.604980, 257.438690, "ld_pool:ball");
    TextDrawLetterSize(TDAlterPass[16], 0.000000, 0.000000);
    TextDrawTextSize(TDAlterPass[16], 25.000000, 25.509988);
    TextDrawAlignment(TDAlterPass[16], 1);
    TextDrawColor(TDAlterPass[16], 8388863);
    TextDrawSetShadow(TDAlterPass[16], 0);
    TextDrawSetOutline(TDAlterPass[16], 0);
    TextDrawBackgroundColor(TDAlterPass[16], 255);
    TextDrawFont(TDAlterPass[16], 4);
    TextDrawSetProportional(TDAlterPass[16], 0);
    TextDrawSetShadow(TDAlterPass[16], 0);

    TDAlterPass[17] = TextDrawCreate(298.201721, 260.573211, "box");
    TextDrawLetterSize(TDAlterPass[17], 0.000000, 2.209988);
    TextDrawTextSize(TDAlterPass[17], 333.508544, 0.000000);
    TextDrawAlignment(TDAlterPass[17], 1);
    TextDrawColor(TDAlterPass[17], 8388863);
    TextDrawUseBox(TDAlterPass[17], 1);
    TextDrawBoxColor(TDAlterPass[17], 8388863);
    TextDrawSetShadow(TDAlterPass[17], 0);
    TextDrawSetOutline(TDAlterPass[17], 0);
    TextDrawBackgroundColor(TDAlterPass[17], 255);
    TextDrawFont(TDAlterPass[17], 1);
    TextDrawSetProportional(TDAlterPass[17], 1);
    TextDrawSetShadow(TDAlterPass[17], 0);

    TDAlterPass[18] = TextDrawCreate(287.301544, 259.873626, "ld_pool:ball");
    TextDrawLetterSize(TDAlterPass[18], 0.000000, 0.000000);
    TextDrawTextSize(TDAlterPass[18], 22.739948, 22.069910);
    TextDrawAlignment(TDAlterPass[18], 1);
    TextDrawColor(TDAlterPass[18], 255);
    TextDrawSetShadow(TDAlterPass[18], 0);
    TextDrawSetOutline(TDAlterPass[18], 0);
    TextDrawBackgroundColor(TDAlterPass[18], 255);
    TextDrawFont(TDAlterPass[18], 4);
    TextDrawSetProportional(TDAlterPass[18], 0);
    TextDrawSetShadow(TDAlterPass[18], 0);

    TDAlterPass[19] = TextDrawCreate(322.203674, 259.473602, "ld_pool:ball");
    TextDrawLetterSize(TDAlterPass[19], 0.000000, 0.000000);
    TextDrawTextSize(TDAlterPass[19], 22.739948, 22.069910);
    TextDrawAlignment(TDAlterPass[19], 1);
    TextDrawColor(TDAlterPass[19], 255);
    TextDrawSetShadow(TDAlterPass[19], 0);
    TextDrawSetOutline(TDAlterPass[19], 0);
    TextDrawBackgroundColor(TDAlterPass[19], 255);
    TextDrawFont(TDAlterPass[19], 4);
    TextDrawSetProportional(TDAlterPass[19], 0);
    TextDrawSetShadow(TDAlterPass[19], 0);

    TDAlterPass[20] = TextDrawCreate(298.201721, 262.173309, "box");
    TextDrawLetterSize(TDAlterPass[20], 0.000000, 1.904997);
    TextDrawTextSize(TDAlterPass[20], 334.000000, 0.000000);
    TextDrawAlignment(TDAlterPass[20], 1);
    TextDrawColor(TDAlterPass[20], 8388863);
    TextDrawUseBox(TDAlterPass[20], 1);
    TextDrawBoxColor(TDAlterPass[20], 255);
    TextDrawSetShadow(TDAlterPass[20], 0);
    TextDrawSetOutline(TDAlterPass[20], 0);
    TextDrawBackgroundColor(TDAlterPass[20], 255);
    TextDrawFont(TDAlterPass[20], 1);
    TextDrawSetProportional(TDAlterPass[20], 1);
    TextDrawSetShadow(TDAlterPass[20], 0);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    TDPlayerAlterPass[playerid][0] = CreatePlayerTextDraw(playerid, 317.200042, 185.557373, "CLIQUE_AQUI_PARA_COLOCAR_SUA_SENHA");
    PlayerTextDrawLetterSize(playerid, TDPlayerAlterPass[playerid][0], 0.097498, 0.840888);
    PlayerTextDrawAlignment(playerid, TDPlayerAlterPass[playerid][0], 2);
    PlayerTextDrawColor(playerid, TDPlayerAlterPass[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerAlterPass[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerAlterPass[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerAlterPass[playerid][0], 255);
    PlayerTextDrawFont(playerid, TDPlayerAlterPass[playerid][0], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerAlterPass[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerAlterPass[playerid][0], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerAlterPass[playerid][0], true);
    PlayerTextDrawTextSize(playerid, TDPlayerAlterPass[playerid][0], 10.000000, 78.000000);

    TDPlayerAlterPass[playerid][1] = CreatePlayerTextDraw(playerid, 317.200042, 217.859344, "CLIQUE_AQUI_PARA_CONFIRMAR_SUA_SENHA");
    PlayerTextDrawLetterSize(playerid, TDPlayerAlterPass[playerid][1], 0.097498, 0.840888);
    PlayerTextDrawAlignment(playerid, TDPlayerAlterPass[playerid][1], 2);
    PlayerTextDrawColor(playerid, TDPlayerAlterPass[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerAlterPass[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerAlterPass[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerAlterPass[playerid][1], 255);
    PlayerTextDrawFont(playerid, TDPlayerAlterPass[playerid][1], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerAlterPass[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerAlterPass[playerid][1], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerAlterPass[playerid][1], true);
    PlayerTextDrawTextSize(playerid, TDPlayerAlterPass[playerid][1], 10.000000, 78.000000);

    TDPlayerAlterPass[playerid][2] = CreatePlayerTextDraw(playerid, 301.000305, 264.188476, "Alterar");
    PlayerTextDrawLetterSize(playerid, TDPlayerAlterPass[playerid][2], 0.267999, 1.176887);
    PlayerTextDrawAlignment(playerid, TDPlayerAlterPass[playerid][2], 1);
    PlayerTextDrawColor(playerid, TDPlayerAlterPass[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerAlterPass[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerAlterPass[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerAlterPass[playerid][2], 255);
    PlayerTextDrawFont(playerid, TDPlayerAlterPass[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, TDPlayerAlterPass[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerAlterPass[playerid][2], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerAlterPass[playerid][2], true);
    PlayerTextDrawTextSize(playerid, TDPlayerAlterPass[playerid][2], 335.000000, 10.000000);
    return 1;
}

stock TDAlterPassShow(playerid)
{
    for(new i = 0; i < 21; i++)
        { TextDrawShowForPlayer(playerid, TDAlterPass[i]); }
    for(new i = 0; i < 3; i++)
        { PlayerTextDrawShow(playerid, TDPlayerAlterPass[playerid][i]); }
    return 1;
}

stock TDAlterPassHide(playerid)
{
    for(new i = 0; i < 21; i++)
        { TextDrawHideForPlayer(playerid, TDAlterPass[i]); }
    for(new i = 0; i < 3; i++)
        { PlayerTextDrawHide(playerid, TDPlayerAlterPass[playerid][i]); }
    return 1;
}
