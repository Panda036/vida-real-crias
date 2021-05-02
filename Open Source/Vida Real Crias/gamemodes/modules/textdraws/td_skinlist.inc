#include YSI\y_hooks

new Text:TDSkinList[7];
new PlayerText:TDPlayerSkinList[MAX_PLAYERS][6];

hook OnGameModeInit()
{
    TDSkinList[0] = TextDrawCreate(287.772552, 127.199203, "box");
    TextDrawLetterSize(TDSkinList[0], 0.000000, 18.023378);
    TextDrawTextSize(TDSkinList[0], 365.000000, 0.000000);
    TextDrawAlignment(TDSkinList[0], 1);
    TextDrawColor(TDSkinList[0], -1);
    TextDrawUseBox(TDSkinList[0], 1);
    TextDrawBoxColor(TDSkinList[0], 16777215);
    TextDrawSetShadow(TDSkinList[0], 0);
    TextDrawSetOutline(TDSkinList[0], 0);
    TextDrawBackgroundColor(TDSkinList[0], 255);
    TextDrawFont(TDSkinList[0], 2);
    TextDrawSetProportional(TDSkinList[0], 1);
    TextDrawSetShadow(TDSkinList[0], 0);

    TDSkinList[1] = TextDrawCreate(289.835205, 130.016082, "box");
    TextDrawLetterSize(TDSkinList[1], 0.000000, 12.630632);
    TextDrawTextSize(TDSkinList[1], 363.500488, 0.000000);
    TextDrawAlignment(TDSkinList[1], 1);
    TextDrawColor(TDSkinList[1], -1);
    TextDrawUseBox(TDSkinList[1], 1);
    TextDrawBoxColor(TDSkinList[1], 150);
    TextDrawSetShadow(TDSkinList[1], 0);
    TextDrawSetOutline(TDSkinList[1], 0);
    TextDrawBackgroundColor(TDSkinList[1], 255);
    TextDrawFont(TDSkinList[1], 2);
    TextDrawSetProportional(TDSkinList[1], 1);
    TextDrawSetShadow(TDSkinList[1], 0);

    TDSkinList[2] = TextDrawCreate(289.577728, 250.688949, "box");
    TextDrawLetterSize(TDSkinList[2], 0.000000, 4.088014);
    TextDrawTextSize(TDSkinList[2], 363.459289, 0.000000);
    TextDrawAlignment(TDSkinList[2], 1);
    TextDrawColor(TDSkinList[2], -1);
    TextDrawUseBox(TDSkinList[2], 1);
    TextDrawBoxColor(TDSkinList[2], 150);
    TextDrawSetShadow(TDSkinList[2], 0);
    TextDrawSetOutline(TDSkinList[2], 0);
    TextDrawBackgroundColor(TDSkinList[2], 255);
    TextDrawFont(TDSkinList[2], 2);
    TextDrawSetProportional(TDSkinList[2], 1);
    TextDrawSetShadow(TDSkinList[2], 0);

    TDSkinList[3] = TextDrawCreate(292.535217, 271.883209, "box");
    TextDrawLetterSize(TDSkinList[3], 0.000000, 1.294999);
    TextDrawTextSize(TDSkinList[3], 323.737487, 0.000000);
    TextDrawAlignment(TDSkinList[3], 1);
    TextDrawColor(TDSkinList[3], -1);
    TextDrawUseBox(TDSkinList[3], 1);
    TextDrawBoxColor(TDSkinList[3], -2147483393);
    TextDrawSetShadow(TDSkinList[3], 0);
    TextDrawSetOutline(TDSkinList[3], 0);
    TextDrawBackgroundColor(TDSkinList[3], 255);
    TextDrawFont(TDSkinList[3], 1);
    TextDrawSetProportional(TDSkinList[3], 1);
    TextDrawSetShadow(TDSkinList[3], 0);

    TDSkinList[4] = TextDrawCreate(329.434875, 272.033508, "box");
    TextDrawLetterSize(TDSkinList[4], 0.000000, 1.326850);
    TextDrawTextSize(TDSkinList[4], 360.368408, 0.000000);
    TextDrawAlignment(TDSkinList[4], 1);
    TextDrawColor(TDSkinList[4], -1);
    TextDrawUseBox(TDSkinList[4], 1);
    TextDrawBoxColor(TDSkinList[4], -2147483393);
    TextDrawSetShadow(TDSkinList[4], 0);
    TextDrawSetOutline(TDSkinList[4], 0);
    TextDrawBackgroundColor(TDSkinList[4], 255);
    TextDrawFont(TDSkinList[4], 1);
    TextDrawSetProportional(TDSkinList[4], 1);
    TextDrawSetShadow(TDSkinList[4], 0);

    TDSkinList[5] = TextDrawCreate(292.757049, 253.898956, "box");
    TextDrawLetterSize(TDSkinList[5], 0.000000, 1.248146);
    TextDrawTextSize(TDSkinList[5], 360.300018, 0.000000);
    TextDrawAlignment(TDSkinList[5], 1);
    TextDrawColor(TDSkinList[5], -1);
    TextDrawUseBox(TDSkinList[5], 1);
    TextDrawBoxColor(TDSkinList[5], 8388863);
    TextDrawSetShadow(TDSkinList[5], 0);
    TextDrawSetOutline(TDSkinList[5], 0);
    TextDrawBackgroundColor(TDSkinList[5], 255);
    TextDrawFont(TDSkinList[5], 1);
    TextDrawSetProportional(TDSkinList[5], 1);
    TextDrawSetShadow(TDSkinList[5], 0);

    TDSkinList[6] = TextDrawCreate(292.811157, 130.499984, "Sexo:");
    TextDrawLetterSize(TDSkinList[6], 0.212591, 1.069166);
    TextDrawAlignment(TDSkinList[6], 1);
    TextDrawColor(TDSkinList[6], -1);
    TextDrawSetShadow(TDSkinList[6], 0);
    TextDrawSetOutline(TDSkinList[6], -1);
    TextDrawBackgroundColor(TDSkinList[6], 255);
    TextDrawFont(TDSkinList[6], 1);
    TextDrawSetProportional(TDSkinList[6], 1);
    TextDrawSetShadow(TDSkinList[6], 0);
	return 1;
}

hook OnPlayerConnect(playerid)
{
    TDPlayerSkinList[playerid][0] = CreatePlayerTextDraw(playerid, 282.199981, 143.249816, "");
    PlayerTextDrawLetterSize(playerid, TDPlayerSkinList[playerid][0], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, TDPlayerSkinList[playerid][0], 90.000000, 90.000000);
    PlayerTextDrawAlignment(playerid, TDPlayerSkinList[playerid][0], 1);
    PlayerTextDrawColor(playerid, TDPlayerSkinList[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerSkinList[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerSkinList[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerSkinList[playerid][0], 0);
    PlayerTextDrawFont(playerid, TDPlayerSkinList[playerid][0], 5);
    PlayerTextDrawSetProportional(playerid, TDPlayerSkinList[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, TDPlayerSkinList[playerid][0], 0);
    PlayerTextDrawSetPreviewModel(playerid, TDPlayerSkinList[playerid][0], 0);
    PlayerTextDrawSetPreviewRot(playerid, TDPlayerSkinList[playerid][0], 0.000000, 0.000000, 0.000000, 1.000000);

    TDPlayerSkinList[playerid][1] = CreatePlayerTextDraw(playerid, 310.500000, 254.475463, "Escolher");
    PlayerTextDrawLetterSize(playerid, TDPlayerSkinList[playerid][1], 0.263000, 1.005000);
    PlayerTextDrawAlignment(playerid, TDPlayerSkinList[playerid][1], 1);
    PlayerTextDrawColor(playerid, TDPlayerSkinList[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerSkinList[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerSkinList[playerid][1], -1);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerSkinList[playerid][1], 255);
    PlayerTextDrawFont(playerid, TDPlayerSkinList[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, TDPlayerSkinList[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerSkinList[playerid][1], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerSkinList[playerid][1], true);
    PlayerTextDrawTextSize(playerid, TDPlayerSkinList[playerid][1], 350.000000, 11.000000);

    TDPlayerSkinList[playerid][2] = CreatePlayerTextDraw(playerid, 301.396789, 272.491729, "LD_BEAT:left");
    PlayerTextDrawLetterSize(playerid, TDPlayerSkinList[playerid][2], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, TDPlayerSkinList[playerid][2], 14.000000, 11.000000);
    PlayerTextDrawAlignment(playerid, TDPlayerSkinList[playerid][2], 1);
    PlayerTextDrawColor(playerid, TDPlayerSkinList[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerSkinList[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerSkinList[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerSkinList[playerid][2], 255);
    PlayerTextDrawFont(playerid, TDPlayerSkinList[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, TDPlayerSkinList[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, TDPlayerSkinList[playerid][2], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerSkinList[playerid][2], true);

    TDPlayerSkinList[playerid][3] = CreatePlayerTextDraw(playerid, 338.422058, 272.641723, "LD_BEAT:right");
    PlayerTextDrawLetterSize(playerid, TDPlayerSkinList[playerid][3], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, TDPlayerSkinList[playerid][3], 14.000000, 11.000000);
    PlayerTextDrawAlignment(playerid, TDPlayerSkinList[playerid][3], 1);
    PlayerTextDrawColor(playerid, TDPlayerSkinList[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerSkinList[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerSkinList[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerSkinList[playerid][3], 255);
    PlayerTextDrawFont(playerid, TDPlayerSkinList[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, TDPlayerSkinList[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, TDPlayerSkinList[playerid][3], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerSkinList[playerid][3], true);

    TDPlayerSkinList[playerid][4] = CreatePlayerTextDraw(playerid, 314.512481, 130.499984, "");
    PlayerTextDrawLetterSize(playerid, TDPlayerSkinList[playerid][4], 0.212591, 1.069166);
    PlayerTextDrawAlignment(playerid, TDPlayerSkinList[playerid][4], 1);
    PlayerTextDrawColor(playerid, TDPlayerSkinList[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerSkinList[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerSkinList[playerid][4], -1);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerSkinList[playerid][4], 255);
    PlayerTextDrawFont(playerid, TDPlayerSkinList[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, TDPlayerSkinList[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerSkinList[playerid][4], 0);

    TDPlayerSkinList[playerid][5] = CreatePlayerTextDraw(playerid, 353.082427, 130.016647, "LD_BEAT:cross");
    PlayerTextDrawLetterSize(playerid, TDPlayerSkinList[playerid][5], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, TDPlayerSkinList[playerid][5], 9.549989, 10.000000);
    PlayerTextDrawAlignment(playerid, TDPlayerSkinList[playerid][5], 1);
    PlayerTextDrawColor(playerid, TDPlayerSkinList[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerSkinList[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerSkinList[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerSkinList[playerid][5], 255);
    PlayerTextDrawFont(playerid, TDPlayerSkinList[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, TDPlayerSkinList[playerid][5], 0);
    PlayerTextDrawSetShadow(playerid, TDPlayerSkinList[playerid][5], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerSkinList[playerid][5], true);
    return 1;
}

stock ShowTDPlayerSkinList(playerid)
{
    SelectTextDraw(playerid, Green);

    for(new i = 0; i < 7; i++)
    {
        TextDrawShowForPlayer(playerid, TDSkinList[i]);
    }
    for(new i = 0; i < 6; i++)
    {
        PlayerTextDrawShow(playerid, TDPlayerSkinList[playerid][i]);
    }
    return 1;
}

stock HideTDPlayerSkinList(playerid)
{
    CancelSelectTextDraw(playerid);

    for(new i = 0; i < 7; i++)
    {
        TextDrawHideForPlayer(playerid, TDSkinList[i]);
    }
    for(new i = 0; i < 6; i++)
    {
        PlayerTextDrawHide(playerid, TDPlayerSkinList[playerid][i]);
    }
    return 1;
}
