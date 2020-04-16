#include YSI\y_hooks

new PlayerText:TDPlayerTutorial[MAX_PLAYERS][1];

hook OnPlayerConnect(playerid)
{
    TDPlayerTutorial[playerid][0] = CreatePlayerTextDraw(playerid, 329.500000, 352.400146, "");
    PlayerTextDrawLetterSize(playerid, TDPlayerTutorial[playerid][0], 0.304500, 1.425777);
    PlayerTextDrawAlignment(playerid, TDPlayerTutorial[playerid][0], 2);
    PlayerTextDrawColor(playerid, TDPlayerTutorial[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerTutorial[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerTutorial[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerTutorial[playerid][0], 255);
    PlayerTextDrawFont(playerid, TDPlayerTutorial[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, TDPlayerTutorial[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerTutorial[playerid][0], 0);
    return 1;
}

stock ShowTDTutorial(playerid, str[])
{
    format(String, sizeof(String), "%s", str);
    PlayerTextDrawSetString(playerid, TDPlayerTutorial[playerid][0], String);
    PlayerTextDrawShow(playerid, TDPlayerTutorial[playerid][0]);
    return 1;
}

stock HideTDTutorial(playerid)
{
    PlayerTextDrawHide(playerid, TDPlayerTutorial[playerid][0]);
    return 1;
}
