#include YSI\y_hooks

new PlayerText:TDBase[MAX_PLAYERS][1];

hook OnPlayerConnect(playerid)
{
    TDBase[playerid][0] = CreatePlayerTextDraw(playerid, 323.676361, 10.233320, "BaseNomeTeste");
    PlayerTextDrawLetterSize(playerid, TDBase[playerid][0], 0.282400, 1.314166);
    PlayerTextDrawAlignment(playerid, TDBase[playerid][0], 2);
    PlayerTextDrawColor(playerid, TDBase[playerid][0], -1);
    PlayerTextDrawSetOutline(playerid, TDBase[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, TDBase[playerid][0], 255);
    PlayerTextDrawFont(playerid, TDBase[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, TDBase[playerid][0], 1);
    return 1;
}
