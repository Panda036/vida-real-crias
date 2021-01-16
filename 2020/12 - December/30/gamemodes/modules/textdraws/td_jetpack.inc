#include YSI\y_hooks

new PlayerText:TDJetpack[MAX_PLAYERS][1];

hook OnPlayerConnect(playerid)
{
    TDJetpack[playerid][0] = CreatePlayerTextDraw(playerid, 123.674957, 372.866516, "GAS_:_~r~30~w~M3");
    PlayerTextDrawLetterSize(playerid, TDJetpack[playerid][0], 0.251478, 1.413332);
    PlayerTextDrawAlignment(playerid, TDJetpack[playerid][0], 1);
    PlayerTextDrawColor(playerid, TDJetpack[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, TDJetpack[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, TDJetpack[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, TDJetpack[playerid][0], 255);
    PlayerTextDrawFont(playerid, TDJetpack[playerid][0], 2);
    PlayerTextDrawSetProportional(playerid, TDJetpack[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, TDJetpack[playerid][0], 0);
    return 1;
}
