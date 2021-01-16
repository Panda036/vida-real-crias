#include YSI\y_hooks

new PlayerText:TempoPresidio[MAX_PLAYERS][3];

hook OnPlayerConnect(playerid)
{
    TempoPresidio[playerid][0] = CreatePlayerTextDraw(playerid, 1.390990, 293.250061, "I");
    PlayerTextDrawLetterSize(playerid, TempoPresidio[playerid][0], 15.084396, 3.670835);
    PlayerTextDrawAlignment(playerid, TempoPresidio[playerid][0], 1);
    PlayerTextDrawColor(playerid, TempoPresidio[playerid][0], 100);
    PlayerTextDrawSetShadow(playerid, TempoPresidio[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, TempoPresidio[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, TempoPresidio[playerid][0], 0);
    PlayerTextDrawFont(playerid, TempoPresidio[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, TempoPresidio[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, TempoPresidio[playerid][0], 0);

    TempoPresidio[playerid][1] = CreatePlayerTextDraw(playerid, 83.016113, 299.666595, "");
    PlayerTextDrawLetterSize(playerid, TempoPresidio[playerid][1], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, TempoPresidio[playerid][1], -24.000000, 23.000000);
    PlayerTextDrawAlignment(playerid, TempoPresidio[playerid][1], 1);
    PlayerTextDrawColor(playerid, TempoPresidio[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, TempoPresidio[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, TempoPresidio[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, TempoPresidio[playerid][1], 0);
    PlayerTextDrawFont(playerid, TempoPresidio[playerid][1], 5);
    PlayerTextDrawSetProportional(playerid, TempoPresidio[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, TempoPresidio[playerid][1], 0);
    PlayerTextDrawSetPreviewModel(playerid, TempoPresidio[playerid][1], 19825);
    PlayerTextDrawSetPreviewRot(playerid, TempoPresidio[playerid][1], 180.000000, 180.000000, 0.000000, 1.000000);

    TempoPresidio[playerid][2] = CreatePlayerTextDraw(playerid, 81.508071, 304.333312, "");
    PlayerTextDrawLetterSize(playerid, TempoPresidio[playerid][2], 0.168549, 1.308331);
    PlayerTextDrawAlignment(playerid, TempoPresidio[playerid][2], 1);
    PlayerTextDrawColor(playerid, TempoPresidio[playerid][2], -74);
    PlayerTextDrawSetShadow(playerid, TempoPresidio[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, TempoPresidio[playerid][2], -1);
    PlayerTextDrawBackgroundColor(playerid, TempoPresidio[playerid][2], 255);
    PlayerTextDrawFont(playerid, TempoPresidio[playerid][2], 2);
    PlayerTextDrawSetProportional(playerid, TempoPresidio[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, TempoPresidio[playerid][2], 0);
}
