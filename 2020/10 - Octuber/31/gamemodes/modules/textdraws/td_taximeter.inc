#include YSI\y_hooks

new Text:TDTaximetro[4];
new PlayerText:TDPlayerTaximetro[MAX_PLAYERS][2];

hook OnGameModeInit()
{
    TDTaximetro[0] = TextDrawCreate(30.625000, 185.333328, "box");
    TextDrawLetterSize(TDTaximetro[0], 0.000000, 10.000000);
    TextDrawTextSize(TDTaximetro[0], 89.000000, 0.000000);
    TextDrawAlignment(TDTaximetro[0], 1);
    TextDrawColor(TDTaximetro[0], -1);
    TextDrawUseBox(TDTaximetro[0], 1);
    TextDrawBoxColor(TDTaximetro[0], 100);
    TextDrawSetShadow(TDTaximetro[0], 0);
    TextDrawSetOutline(TDTaximetro[0], 0);
    TextDrawBackgroundColor(TDTaximetro[0], 255);
    TextDrawFont(TDTaximetro[0], 1);
    TextDrawSetProportional(TDTaximetro[0], 1);
    TextDrawSetShadow(TDTaximetro[0], 0);

    TDTaximetro[1] = TextDrawCreate(37.124938, 189.516906, "Taximetro");
    TextDrawLetterSize(TDTaximetro[1], 0.199374, 1.109998);
    TextDrawAlignment(TDTaximetro[1], 1);
    TextDrawColor(TDTaximetro[1], -65281);
    TextDrawSetShadow(TDTaximetro[1], 0);
    TextDrawSetOutline(TDTaximetro[1], -1);
    TextDrawBackgroundColor(TDTaximetro[1], 255);
    TextDrawFont(TDTaximetro[1], 2);
    TextDrawSetProportional(TDTaximetro[1], 1);
    TextDrawSetShadow(TDTaximetro[1], 0);

    TDTaximetro[2] = TextDrawCreate(59.174583, 216.616180, "Total_a_pagar:");
    TextDrawLetterSize(TDTaximetro[2], 0.152499, 0.987498);
    TextDrawAlignment(TDTaximetro[2], 2);
    TextDrawColor(TDTaximetro[2], -1);
    TextDrawSetShadow(TDTaximetro[2], 0);
    TextDrawSetOutline(TDTaximetro[2], 0);
    TextDrawBackgroundColor(TDTaximetro[2], 255);
    TextDrawFont(TDTaximetro[2], 1);
    TextDrawSetProportional(TDTaximetro[2], 1);
    TextDrawSetShadow(TDTaximetro[2], 0);

    TDTaximetro[3] = TextDrawCreate(58.249588, 244.117858, "Localidade:");
    TextDrawLetterSize(TDTaximetro[3], 0.152499, 0.987498);
    TextDrawAlignment(TDTaximetro[3], 2);
    TextDrawColor(TDTaximetro[3], -1);
    TextDrawSetShadow(TDTaximetro[3], 0);
    TextDrawSetOutline(TDTaximetro[3], 0);
    TextDrawBackgroundColor(TDTaximetro[3], 255);
    TextDrawFont(TDTaximetro[3], 1);
    TextDrawSetProportional(TDTaximetro[3], 1);
    TextDrawSetShadow(TDTaximetro[3], 0);
	return 1;
}

hook OnPlayerConnect(playerid)
{
    TDPlayerTaximetro[playerid][0] = CreatePlayerTextDraw(playerid, 48.949958, 228.299331, "~g~$560");
    PlayerTextDrawLetterSize(playerid, TDPlayerTaximetro[playerid][0], 0.201249, 0.946665);
    PlayerTextDrawAlignment(playerid, TDPlayerTaximetro[playerid][0], 1);
    PlayerTextDrawColor(playerid, TDPlayerTaximetro[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerTaximetro[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerTaximetro[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerTaximetro[playerid][0], 255);
    PlayerTextDrawFont(playerid, TDPlayerTaximetro[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, TDPlayerTaximetro[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerTaximetro[playerid][0], 0);

    TDPlayerTaximetro[playerid][1] = CreatePlayerTextDraw(playerid, 57.624588, 256.601928, "~r~East_Los_Santos");
    PlayerTextDrawLetterSize(playerid, TDPlayerTaximetro[playerid][1], 0.152499, 0.987498);
    PlayerTextDrawAlignment(playerid, TDPlayerTaximetro[playerid][1], 2);
    PlayerTextDrawColor(playerid, TDPlayerTaximetro[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerTaximetro[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerTaximetro[playerid][1], 1);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerTaximetro[playerid][1], 255);
    PlayerTextDrawFont(playerid, TDPlayerTaximetro[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, TDPlayerTaximetro[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerTaximetro[playerid][1], 0);
	return 1;
}
