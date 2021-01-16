#include YSI\y_hooks

new Text:TDSono[6];
new PlayerText:TDPlayerSono[MAX_PLAYERS][1];

hook OnGameModeInit()
{
    TDSono[0] = TextDrawCreate(0.500000, -1.333335, "_");
    TextDrawLetterSize(TDSono[0], 0.000000, 52.699848);
    TextDrawTextSize(TDSono[0], 715.000000, 0.000000);
    TextDrawAlignment(TDSono[0], 1);
    TextDrawColor(TDSono[0], -1);
    TextDrawUseBox(TDSono[0], 1);
    TextDrawBoxColor(TDSono[0], 255);
    TextDrawSetShadow(TDSono[0], 0);
    TextDrawSetOutline(TDSono[0], 0);
    TextDrawBackgroundColor(TDSono[0], 255);
    TextDrawFont(TDSono[0], 1);
    TextDrawSetProportional(TDSono[0], 1);
    TextDrawSetShadow(TDSono[0], 0);

    TDSono[1] = TextDrawCreate(318.500000, 222.666534, "");
    TextDrawLetterSize(TDSono[1], 0.000000, 0.000000);
    TextDrawTextSize(TDSono[1], 57.000000, 53.000000);
    TextDrawAlignment(TDSono[1], 1);
    TextDrawColor(TDSono[1], -1);
    TextDrawSetShadow(TDSono[1], 0);
    TextDrawSetOutline(TDSono[1], 0);
    TextDrawBackgroundColor(TDSono[1], 0);
    TextDrawFont(TDSono[1], 5);
    TextDrawSetProportional(TDSono[1], 0);
    TextDrawSetShadow(TDSono[1], 0);
    TextDrawSetPreviewModel(TDSono[1], 1550);
    TextDrawSetPreviewRot(TDSono[1], 300.000000, 0.000000, 0.000000, 1.000000);

    TDSono[2] = TextDrawCreate(467.500000, 86.399955, "");
    TextDrawLetterSize(TDSono[2], 0.000000, 0.000000);
    TextDrawTextSize(TDSono[2], 90.000000, 90.000000);
    TextDrawAlignment(TDSono[2], 1);
    TextDrawColor(TDSono[2], -1);
    TextDrawSetShadow(TDSono[2], 0);
    TextDrawSetOutline(TDSono[2], 0);
    TextDrawBackgroundColor(TDSono[2], 0);
    TextDrawFont(TDSono[2], 5);
    TextDrawSetProportional(TDSono[2], 0);
    TextDrawSetShadow(TDSono[2], 0);
    TextDrawSetPreviewModel(TDSono[2], 1212);
    TextDrawSetPreviewRot(TDSono[2], 290.000000, 0.000000, 0.000000, 1.000000);

    TDSono[3] = TextDrawCreate(456.000000, 255.799957, "");
    TextDrawLetterSize(TDSono[3], 0.000000, 0.000000);
    TextDrawTextSize(TDSono[3], 90.000000, 90.000000);
    TextDrawAlignment(TDSono[3], 1);
    TextDrawColor(TDSono[3], -1);
    TextDrawSetShadow(TDSono[3], 0);
    TextDrawSetOutline(TDSono[3], 0);
    TextDrawBackgroundColor(TDSono[3], 0);
    TextDrawFont(TDSono[3], 5);
    TextDrawSetProportional(TDSono[3], 0);
    TextDrawSetShadow(TDSono[3], 0);
    TextDrawSetPreviewModel(TDSono[3], 1212);
    TextDrawSetPreviewRot(TDSono[3], 290.000000, 20.000000, 40.000000, 1.000000);

    TDSono[4] = TextDrawCreate(111.000000, 252.533218, "");
    TextDrawLetterSize(TDSono[4], 0.000000, 0.000000);
    TextDrawTextSize(TDSono[4], 90.000000, 90.000000);
    TextDrawAlignment(TDSono[4], 1);
    TextDrawColor(TDSono[4], -1);
    TextDrawSetShadow(TDSono[4], 0);
    TextDrawSetOutline(TDSono[4], 0);
    TextDrawBackgroundColor(TDSono[4], 0);
    TextDrawFont(TDSono[4], 5);
    TextDrawSetProportional(TDSono[4], 0);
    TextDrawSetShadow(TDSono[4], 0);
    TextDrawSetPreviewModel(TDSono[4], 1212);
    TextDrawSetPreviewRot(TDSono[4], 290.000000, 20.000000, -40.000000, 1.000000);

    TDSono[5] = TextDrawCreate(120.500000, 51.399871, "");
    TextDrawLetterSize(TDSono[5], 0.000000, 0.000000);
    TextDrawTextSize(TDSono[5], 90.000000, 90.000000);
    TextDrawAlignment(TDSono[5], 1);
    TextDrawColor(TDSono[5], -1);
    TextDrawSetShadow(TDSono[5], 0);
    TextDrawSetOutline(TDSono[5], 0);
    TextDrawBackgroundColor(TDSono[5], 0);
    TextDrawFont(TDSono[5], 5);
    TextDrawSetProportional(TDSono[5], 0);
    TextDrawSetShadow(TDSono[5], 0);
    TextDrawSetPreviewModel(TDSono[5], 1212);
    TextDrawSetPreviewRot(TDSono[5], 290.000000, 20.000000, 50.000000, 1.000000);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    TDPlayerSono[playerid][0] = CreatePlayerTextDraw(playerid, 252.000000, 179.474929, "");
    PlayerTextDrawLetterSize(playerid, TDPlayerSono[playerid][0], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, TDPlayerSono[playerid][0], 142.000000, 122.000000);
    PlayerTextDrawAlignment(playerid, TDPlayerSono[playerid][0], 1);
    PlayerTextDrawColor(playerid, TDPlayerSono[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerSono[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerSono[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerSono[playerid][0], 0);
    PlayerTextDrawFont(playerid, TDPlayerSono[playerid][0], 5);
    PlayerTextDrawSetProportional(playerid, TDPlayerSono[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, TDPlayerSono[playerid][0], 0);
    PlayerTextDrawSetPreviewModel(playerid, TDPlayerSono[playerid][0], 0);
    PlayerTextDrawSetPreviewRot(playerid, TDPlayerSono[playerid][0], 0.000000, 0.000000, 0.000000, 1.000000);
    return 1;
}

stock ShowTDSleep(playerid)
{
    PlayerTextDrawSetPreviewModel(playerid, TDPlayerSono[playerid][0], PlayerInfo[playerid][skin]);
    PlayerTextDrawShow(playerid, TDPlayerSono[playerid][0]);
    TextDrawShowForPlayer(playerid, TDSono[0]);
    TextDrawShowForPlayer(playerid, TDSono[1]);
    TextDrawShowForPlayer(playerid, TDSono[2]);
    TextDrawShowForPlayer(playerid, TDSono[3]);
    TextDrawShowForPlayer(playerid, TDSono[4]);
    TextDrawShowForPlayer(playerid, TDSono[5]);
    return 1;
}

stock HideTDSleep(playerid)
{
    PlayerTextDrawHide(playerid, TDPlayerSono[playerid][0]);
    TextDrawHideForPlayer(playerid, TDSono[0]);
    TextDrawHideForPlayer(playerid, TDSono[1]);
    TextDrawHideForPlayer(playerid, TDSono[2]);
    TextDrawHideForPlayer(playerid, TDSono[3]);
    TextDrawHideForPlayer(playerid, TDSono[4]);
    TextDrawHideForPlayer(playerid, TDSono[5]);
    return 1;
}
