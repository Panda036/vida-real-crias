#include YSI\y_hooks

new Text:TDDetonated[2];

hook OnGameModeInit()
{
    TDDetonated[0] = TextDrawCreate(0.000000, 180.000000, "box");
    TextDrawLetterSize(TDDetonated[0], 0.000000, 9.125000);
    TextDrawTextSize(TDDetonated[0], 634.000000, 0.000000);
    TextDrawAlignment(TDDetonated[0], 1);
    TextDrawColor(TDDetonated[0], -1);
    TextDrawUseBox(TDDetonated[0], 1);
    TextDrawBoxColor(TDDetonated[0], 149);
    TextDrawSetShadow(TDDetonated[0], 0);
    TextDrawSetOutline(TDDetonated[0], 0);
    TextDrawBackgroundColor(TDDetonated[0], 255);
    TextDrawFont(TDDetonated[0], 1);
    TextDrawSetProportional(TDDetonated[0], 1);
    TextDrawSetShadow(TDDetonated[0], 0);

    TDDetonated[1] = TextDrawCreate(250.000000, 205.000000, "DETONADO");
    TextDrawLetterSize(TDDetonated[1], 0.811874, 3.309160);
    TextDrawAlignment(TDDetonated[1], 1);
    TextDrawColor(TDDetonated[1], -16777066);
    TextDrawSetShadow(TDDetonated[1], 0);
    TextDrawSetOutline(TDDetonated[1], 1);
    TextDrawBackgroundColor(TDDetonated[1], 255);
    TextDrawFont(TDDetonated[1], 3);
    TextDrawSetProportional(TDDetonated[1], 1);
    TextDrawSetShadow(TDDetonated[1], 0);
	return 1;
}
