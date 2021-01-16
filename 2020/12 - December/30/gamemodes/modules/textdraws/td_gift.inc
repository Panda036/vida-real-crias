#if EVENT_GIFT

#include YSI\y_hooks

new Text:TDGift[2];
new PlayerText:TDPlayerGift[MAX_PLAYERS][1];

new bool:stateGift[MAX_PLAYERS];

hook OnGameModeInit()
{
    /* Halloween
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
    TextDrawSetPreviewModel(TDGift[0], CHRISTMAS_TREE);
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
    TextDrawSetPreviewModel(TDGift[1], CHRISTMAS_BOX_5);
    TextDrawSetPreviewRot(TDGift[1], 0.000000, 250.000000, 25.000000, 1.000000);*/

    TDGift[0] = TextDrawCreate(45.328170, 259.717163, "");
    TextDrawLetterSize(TDGift[0], 0.000000, 0.000000);
    TextDrawTextSize(TDGift[0], 50.000000, 47.000000);
    TextDrawAlignment(TDGift[0], 1);
    TextDrawColor(TDGift[0], -1);
    TextDrawSetShadow(TDGift[0], 0);
    TextDrawSetOutline(TDGift[0], 0);
    TextDrawBackgroundColor(TDGift[0], -256);
    TextDrawFont(TDGift[0], 5);
    TextDrawSetProportional(TDGift[0], 0);
    TextDrawSetShadow(TDGift[0], 0);
    TextDrawSetPreviewModel(TDGift[0], CHRISTMAS_BOX_1);
    TextDrawSetPreviewRot(TDGift[0], -25.000000, 10.000000, 0.000000, 1.000000);

    TDGift[1] = TextDrawCreate(37.158088, 241.549606, "");
    TextDrawLetterSize(TDGift[1], 0.000000, 0.000000);
    TextDrawTextSize(TDGift[1], 70.000000, 70.000000);
    TextDrawAlignment(TDGift[1], 1);
    TextDrawColor(TDGift[1], -56);
    TextDrawSetShadow(TDGift[1], 0);
    TextDrawSetOutline(TDGift[1], 0);
    TextDrawBackgroundColor(TDGift[1], -256);
    TextDrawFont(TDGift[1], 5);
    TextDrawSetProportional(TDGift[1], 0);
    TextDrawSetShadow(TDGift[1], 0);
    TextDrawSetPreviewModel(TDGift[1], CHRISTMAS_HAT);
    TextDrawSetPreviewRot(TDGift[1], 0.000000, 0.000000, 0.000000, 1.000000);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    /* Halloween
    TDPlayerGift[playerid][0] = CreatePlayerTextDraw(playerid, 53.724166, 283.783294, "00:00");
    PlayerTextDrawLetterSize(playerid, TDPlayerGift[playerid][0], 0.348993, 1.944165);
    PlayerTextDrawAlignment(playerid, TDPlayerGift[playerid][0], 1);
    PlayerTextDrawColor(playerid, TDPlayerGift[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerGift[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerGift[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerGift[playerid][0], 255);
    PlayerTextDrawFont(playerid, TDPlayerGift[playerid][0], 3);
    PlayerTextDrawSetProportional(playerid, TDPlayerGift[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerGift[playerid][0], 0); */

    TDPlayerGift[playerid][0] = CreatePlayerTextDraw(playerid, 55.413543, 293.633117, "00:00");
    PlayerTextDrawLetterSize(playerid, TDPlayerGift[playerid][0], 0.328316, 1.809999);
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
    stateGift[playerid] = true;

    TextDrawShowForPlayer(playerid, TDGift[0]);
    TextDrawShowForPlayer(playerid, TDGift[1]);
    PlayerTextDrawShow(playerid, TDPlayerGift[playerid][0]);
    return playerid;
}

stock HideTDGift(playerid)
{
    stateGift[playerid] = false;

    TextDrawHideForPlayer(playerid, TDGift[0]);
    TextDrawHideForPlayer(playerid, TDGift[1]);
    PlayerTextDrawHide(playerid, TDPlayerGift[playerid][0]);
    return playerid;
}

#endif
