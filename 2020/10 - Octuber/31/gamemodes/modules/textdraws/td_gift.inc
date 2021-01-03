#if EVENT_GIFT

#include YSI\y_hooks

new Text:TDGift[2];
new PlayerText:TDPlayerGift[MAX_PLAYERS][1];

hook OnGameModeInit()
{
    /*TDGift[0] = TextDrawCreate(29.578159, 286.966674, "");
    TextDrawLetterSize(TDGift[0], 0.000000, 0.000000);
    TextDrawTextSize(TDGift[0], 34.000000, 40.000000);
    TextDrawAlignment(TDGift[0], 1);
    TextDrawColor(TDGift[0], -1);
    TextDrawSetShadow(TDGift[0], 0);
    TextDrawSetOutline(TDGift[0], 0);
    TextDrawBackgroundColor(TDGift[0], 0);
    TextDrawFont(TDGift[0], 5);
    TextDrawSetProportional(TDGift[0], 0);
    TextDrawSetShadow(TDGift[0], 0);
    TextDrawSetPreviewModel(TDGift[0], 19058);
    TextDrawSetPreviewRot(TDGift[0], -25.000000, 10.000000, 0.000000, 1.000000);  */

    TDGift[0] = TextDrawCreate(48.876399, 230.033340, "");
    TextDrawLetterSize(TDGift[0], 0.000000, 0.000000);
    TextDrawTextSize(TDGift[0], 47.000000, 54.000000);
    TextDrawAlignment(TDGift[0], 1);
    TextDrawColor(TDGift[0], -1);
    TextDrawSetShadow(TDGift[0], 0);
    TextDrawSetOutline(TDGift[0], 0);
    TextDrawBackgroundColor(TDGift[0], 0);
    TextDrawFont(TDGift[0], 5);
    TextDrawSetProportional(TDGift[0], 0);
    TextDrawSetShadow(TDGift[0], 0);
    TextDrawSetPreviewModel(TDGift[0], 19527);
    TextDrawSetPreviewRot(TDGift[0], -30.000000, 10.000000, -10.000000, 1.000000);

    TDGift[1] = TextDrawCreate(44.326553, 215.666656, "");
    TextDrawLetterSize(TDGift[1], 0.000000, 0.000000);
    TextDrawTextSize(TDGift[1], 50.000000, 50.000000);
    TextDrawAlignment(TDGift[1], 1);
    TextDrawColor(TDGift[1], -1);
    TextDrawSetShadow(TDGift[1], 0);
    TextDrawSetOutline(TDGift[1], 0);
    TextDrawBackgroundColor(TDGift[1], -256);
    TextDrawFont(TDGift[1], 5);
    TextDrawSetProportional(TDGift[1], 0);
    TextDrawSetShadow(TDGift[1], 0);
    TextDrawSetPreviewModel(TDGift[1], 19528);
    TextDrawSetPreviewRot(TDGift[1], 0.000000, 250.000000, 25.000000, 1.000000);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    /*TDPlayerGift[playerid][0] = CreatePlayerTextDraw(playerid, 69.685356, 299.516784, "");
    PlayerTextDrawLetterSize(playerid, TDPlayerGift[playerid][0], 0.236548, 1.774999);
    PlayerTextDrawAlignment(playerid, TDPlayerGift[playerid][0], 1);
    PlayerTextDrawColor(playerid, TDPlayerGift[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerGift[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerGift[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerGift[playerid][0], 255);
    PlayerTextDrawFont(playerid, TDPlayerGift[playerid][0], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerGift[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerGift[playerid][0], 0); */

    TDPlayerGift[playerid][0] = CreatePlayerTextDraw(playerid, 53.724166, 283.783294, "00:00");
    PlayerTextDrawLetterSize(playerid, TDPlayerGift[playerid][0], 0.348993, 1.944165);
    PlayerTextDrawAlignment(playerid, TDPlayerGift[playerid][0], 1);
    PlayerTextDrawColor(playerid, TDPlayerGift[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerGift[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerGift[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerGift[playerid][0], 255);
    PlayerTextDrawFont(playerid, TDPlayerGift[playerid][0], 3);
    PlayerTextDrawSetProportional(playerid, TDPlayerGift[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerGift[playerid][0], 0);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    HideTDGift(playerid);
    return 1;
}

stock ShowTDGift(playerid)
{
    TextDrawShowForPlayer(playerid, TDGift[0]);
    TextDrawShowForPlayer(playerid, TDGift[1]);
    PlayerTextDrawShow(playerid, TDPlayerGift[playerid][0]);
    return playerid;
}

stock HideTDGift(playerid)
{
    TextDrawHideForPlayer(playerid, TDGift[0]);
    TextDrawHideForPlayer(playerid, TDGift[1]);
    PlayerTextDrawHide(playerid, TDPlayerGift[playerid][0]);
    return playerid;
}

#endif
