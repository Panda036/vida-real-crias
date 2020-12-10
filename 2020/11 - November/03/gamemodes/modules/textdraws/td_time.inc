#include YSI\y_hooks

new Text:txtDateDisp, Text:txtTimeDisp;
new bool:stateTime[MAX_PLAYERS];

hook OnGameModeInit()
{
    txtDateDisp = TextDrawCreate(551.690856, 4.726683, ""); //Data
    TextDrawLetterSize(txtDateDisp, 0.250799, 1.908619);
    TextDrawAlignment(txtDateDisp, 2);
    TextDrawColor(txtDateDisp, -1);
    TextDrawSetShadow(txtDateDisp, 0);
    TextDrawSetOutline(txtDateDisp, 1);
    TextDrawBackgroundColor(txtDateDisp, 255);
    TextDrawFont(txtDateDisp, 3);
    TextDrawSetProportional(txtDateDisp, 1);
    TextDrawSetShadow(txtDateDisp, 0);

    txtTimeDisp = TextDrawCreate(576.693359, 21.317758, ""); //Hora
    TextDrawLetterSize(txtTimeDisp, 0.574198, 2.405065);
    TextDrawAlignment(txtTimeDisp, 2);
    TextDrawColor(txtTimeDisp, -1);
    TextDrawSetShadow(txtTimeDisp, 0);
    TextDrawSetOutline(txtTimeDisp, 1);
    TextDrawBackgroundColor(txtTimeDisp, 255);
    TextDrawFont(txtTimeDisp, 3);
    TextDrawSetProportional(txtTimeDisp, 1);
    TextDrawSetShadow(txtTimeDisp, 0);
	return 1;
}

stock ShowTDTime(playerid)
{
    TextDrawShowForPlayer(playerid, txtTimeDisp);
    TextDrawShowForPlayer(playerid, txtDateDisp);

    stateTime[playerid] = true;
    return 1;
}

stock HideTDTime(playerid)
{
    TextDrawHideForPlayer(playerid, txtTimeDisp);
    TextDrawHideForPlayer(playerid, txtDateDisp);

    stateTime[playerid] = false;
    return 1;
}
