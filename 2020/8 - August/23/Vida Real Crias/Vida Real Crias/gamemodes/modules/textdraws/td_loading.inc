#include YSI\y_hooks

new bool:PlayerRepairVehicle[MAX_PLAYERS];
new Text:TDLoading[2];
new PlayerText:TDPlayerLoading[MAX_PLAYERS][1];

hook OnGameModeInit()
{
    TDLoading[0] = TextDrawCreate(499.123565, 103.016677, "_");
    TextDrawLetterSize(TDLoading[0], 0.000000, 0.859246);
    TextDrawUseBox(TDLoading[0], 1);
    TextDrawBoxColor(TDLoading[0], 255);
    TextDrawTextSize(TDLoading[0], 605.890869, 0.000000);

    TDLoading[1] = TextDrawCreate(500.4, 104.716651, "_");
    TextDrawLetterSize(TDLoading[1], 0.000000, 0.469103);
    TextDrawUseBox(TDLoading[1], 1);
    TextDrawBoxColor(TDLoading[1], 8388758);
    TextDrawTextSize(TDLoading[1], 604.7, 0.000000);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    TDPlayerLoading[playerid][0] = CreatePlayerTextDraw(playerid, 500.4, 104.716651, "_");
    PlayerTextDrawLetterSize(playerid, TDPlayerLoading[playerid][0], 0.000000, 0.469103);
    PlayerTextDrawUseBox(playerid, TDPlayerLoading[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, TDPlayerLoading[playerid][0], 8388863);
    PlayerTextDrawTextSize(playerid, TDPlayerLoading[playerid][0], 497.4, 0.000000); //104.3 px
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(PlayerRepairVehicle[playerid])
    {
        PlayerRepairVehicle[playerid] = false;
        HideTDLoading(playerid);
    }
    return 1;
}

stock ShowTDLoading(playerid)
{
    TextDrawShowForPlayer(playerid, TDLoading[0]);
    TextDrawShowForPlayer(playerid, TDLoading[1]);
    PlayerTextDrawShow(playerid, TDPlayerLoading[playerid][0]);
    return 1;
}

stock HideTDLoading(playerid)
{
    TextDrawHideForPlayer(playerid, TDLoading[0]);
    TextDrawHideForPlayer(playerid, TDLoading[1]);
    PlayerTextDrawHide(playerid, TDPlayerLoading[playerid][0]);
    return 1;
}
