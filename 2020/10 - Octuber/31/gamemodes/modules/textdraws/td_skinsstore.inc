#include YSI\y_hooks

new Text:TDSkinsStore[7];
new PlayerText:TDPlayerSkinsStore[MAX_PLAYERS][6];

hook OnGameModeInit()
{
    TDSkinsStore[0] = TextDrawCreate(30.907775, 190.000015, "box");
    TextDrawLetterSize(TDSkinsStore[0], 0.000000, 10.000000);
    TextDrawTextSize(TDSkinsStore[0], 94.000000, 0.000000);
    TextDrawAlignment(TDSkinsStore[0], 1);
    TextDrawColor(TDSkinsStore[0], -1);
    TextDrawUseBox(TDSkinsStore[0], 1);
    TextDrawBoxColor(TDSkinsStore[0], -1061109505);
    TextDrawSetShadow(TDSkinsStore[0], 0);
    TextDrawSetOutline(TDSkinsStore[0], 0);
    TextDrawBackgroundColor(TDSkinsStore[0], 255);
    TextDrawFont(TDSkinsStore[0], 1);
    TextDrawSetProportional(TDSkinsStore[0], 1);
    TextDrawSetShadow(TDSkinsStore[0], 0);

    TDSkinsStore[1] = TextDrawCreate(32.007778, 191.300094, "box");
    TextDrawLetterSize(TDSkinsStore[1], 0.000000, 9.663864);
    TextDrawTextSize(TDSkinsStore[1], 93.019538, 0.000000);
    TextDrawAlignment(TDSkinsStore[1], 1);
    TextDrawColor(TDSkinsStore[1], -1);
    TextDrawUseBox(TDSkinsStore[1], 1);
    TextDrawBoxColor(TDSkinsStore[1], 150);
    TextDrawSetShadow(TDSkinsStore[1], 0);
    TextDrawSetOutline(TDSkinsStore[1], 0);
    TextDrawBackgroundColor(TDSkinsStore[1], 255);
    TextDrawFont(TDSkinsStore[1], 1);
    TextDrawSetProportional(TDSkinsStore[1], 1);
    TextDrawSetShadow(TDSkinsStore[1], 0);

    TDSkinsStore[2] = TextDrawCreate(35.618858, 194.283309, "Sexo:");
    TextDrawLetterSize(TDSkinsStore[2], 0.147935, 0.905830);
    TextDrawAlignment(TDSkinsStore[2], 1);
    TextDrawColor(TDSkinsStore[2], -1);
    TextDrawSetShadow(TDSkinsStore[2], 0);
    TextDrawSetOutline(TDSkinsStore[2], -1);
    TextDrawBackgroundColor(TDSkinsStore[2], 255);
    TextDrawFont(TDSkinsStore[2], 1);
    TextDrawSetProportional(TDSkinsStore[2], 1);
    TextDrawSetShadow(TDSkinsStore[2], 0);

    TDSkinsStore[3] = TextDrawCreate(35.618858, 206.884078, "Valor:");
    TextDrawLetterSize(TDSkinsStore[3], 0.147935, 0.905830);
    TextDrawAlignment(TDSkinsStore[3], 1);
    TextDrawColor(TDSkinsStore[3], -1);
    TextDrawSetShadow(TDSkinsStore[3], 0);
    TextDrawSetOutline(TDSkinsStore[3], -1);
    TextDrawBackgroundColor(TDSkinsStore[3], 255);
    TextDrawFont(TDSkinsStore[3], 1);
    TextDrawSetProportional(TDSkinsStore[3], 1);
    TextDrawSetShadow(TDSkinsStore[3], 0);

    TDSkinsStore[4] = TextDrawCreate(35.655929, 263.033203, "box");
    TextDrawLetterSize(TDSkinsStore[4], 0.000000, 1.254106);
    TextDrawTextSize(TDSkinsStore[4], 59.769184, 0.000000);
    TextDrawAlignment(TDSkinsStore[4], 1);
    TextDrawColor(TDSkinsStore[4], -1);
    TextDrawUseBox(TDSkinsStore[4], 1);
    TextDrawBoxColor(TDSkinsStore[4], -2147483393);
    TextDrawSetShadow(TDSkinsStore[4], 0);
    TextDrawSetOutline(TDSkinsStore[4], 0);
    TextDrawBackgroundColor(TDSkinsStore[4], 255);
    TextDrawFont(TDSkinsStore[4], 0);
    TextDrawSetProportional(TDSkinsStore[4], 1);
    TextDrawSetShadow(TDSkinsStore[4], 0);

    TDSkinsStore[5] = TextDrawCreate(64.955482, 263.033203, "box");
    TextDrawLetterSize(TDSkinsStore[5], 0.000000, 1.254106);
    TextDrawTextSize(TDSkinsStore[5], 89.068740, 0.000000);
    TextDrawAlignment(TDSkinsStore[5], 1);
    TextDrawColor(TDSkinsStore[5], -1);
    TextDrawUseBox(TDSkinsStore[5], 1);
    TextDrawBoxColor(TDSkinsStore[5], -2147483393);
    TextDrawSetShadow(TDSkinsStore[5], 0);
    TextDrawSetOutline(TDSkinsStore[5], 0);
    TextDrawBackgroundColor(TDSkinsStore[5], 255);
    TextDrawFont(TDSkinsStore[5], 0);
    TextDrawSetProportional(TDSkinsStore[5], 1);
    TextDrawSetShadow(TDSkinsStore[5], 0);

    TDSkinsStore[6] = TextDrawCreate(35.955924, 245.632141, "box");
    TextDrawLetterSize(TDSkinsStore[6], 0.000000, 1.254106);
    TextDrawTextSize(TDSkinsStore[6], 89.113883, 0.000000);
    TextDrawAlignment(TDSkinsStore[6], 1);
    TextDrawColor(TDSkinsStore[6], -1);
    TextDrawUseBox(TDSkinsStore[6], 1);
    TextDrawBoxColor(TDSkinsStore[6], 8388863);
    TextDrawSetShadow(TDSkinsStore[6], 0);
    TextDrawSetOutline(TDSkinsStore[6], 0);
    TextDrawBackgroundColor(TDSkinsStore[6], 255);
    TextDrawFont(TDSkinsStore[6], 0);
    TextDrawSetProportional(TDSkinsStore[6], 1);
    TextDrawSetShadow(TDSkinsStore[6], 0);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    TDPlayerSkinsStore[playerid][0] = CreatePlayerTextDraw(playerid, 53.918579, 194.283309, "~r~Masculino");
    PlayerTextDrawLetterSize(playerid, TDPlayerSkinsStore[playerid][0], 0.147935, 0.905830);
    PlayerTextDrawAlignment(playerid, TDPlayerSkinsStore[playerid][0], 1);
    PlayerTextDrawColor(playerid, TDPlayerSkinsStore[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerSkinsStore[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerSkinsStore[playerid][0], -1);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerSkinsStore[playerid][0], 255);
    PlayerTextDrawFont(playerid, TDPlayerSkinsStore[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, TDPlayerSkinsStore[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerSkinsStore[playerid][0], 0);

    TDPlayerSkinsStore[playerid][1] = CreatePlayerTextDraw(playerid, 53.618583, 206.884078, "~g~$150");
    PlayerTextDrawLetterSize(playerid, TDPlayerSkinsStore[playerid][1], 0.147935, 0.905830);
    PlayerTextDrawAlignment(playerid, TDPlayerSkinsStore[playerid][1], 1);
    PlayerTextDrawColor(playerid, TDPlayerSkinsStore[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerSkinsStore[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerSkinsStore[playerid][1], -1);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerSkinsStore[playerid][1], 255);
    PlayerTextDrawFont(playerid, TDPlayerSkinsStore[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, TDPlayerSkinsStore[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerSkinsStore[playerid][1], 0);

    if(IsPlayerMobile(playerid))
    {
        TDPlayerSkinsStore[playerid][2] = CreatePlayerTextDraw(playerid, 84.171104, 191.099807, "X");
        PlayerTextDrawLetterSize(playerid, TDPlayerSkinsStore[playerid][2], 0.147935, 0.905830);
        PlayerTextDrawAlignment(playerid, TDPlayerSkinsStore[playerid][2], 1);
        PlayerTextDrawColor(playerid, TDPlayerSkinsStore[playerid][2], -1);
        PlayerTextDrawSetShadow(playerid, TDPlayerSkinsStore[playerid][2], 0);
        PlayerTextDrawSetOutline(playerid, TDPlayerSkinsStore[playerid][2], -1);
        PlayerTextDrawBackgroundColor(playerid, TDPlayerSkinsStore[playerid][2], 255);
        PlayerTextDrawFont(playerid, TDPlayerSkinsStore[playerid][2], 1);
        PlayerTextDrawSetProportional(playerid, TDPlayerSkinsStore[playerid][2], 1);
        PlayerTextDrawSetShadow(playerid, TDPlayerSkinsStore[playerid][2], 0);
        PlayerTextDrawSetSelectable(playerid, TDPlayerSkinsStore[playerid][2], true);
    } else {
        TDPlayerSkinsStore[playerid][2] = CreatePlayerTextDraw(playerid, 84.171104, 191.099807, "LD_BEAT:cross");
        PlayerTextDrawLetterSize(playerid, TDPlayerSkinsStore[playerid][2], 0.000000, 0.000000);
        PlayerTextDrawTextSize(playerid, TDPlayerSkinsStore[playerid][2], 8.269983, 9.000000);
        PlayerTextDrawAlignment(playerid, TDPlayerSkinsStore[playerid][2], 1);
        PlayerTextDrawColor(playerid, TDPlayerSkinsStore[playerid][2], -1);
        PlayerTextDrawSetShadow(playerid, TDPlayerSkinsStore[playerid][2], 0);
        PlayerTextDrawSetOutline(playerid, TDPlayerSkinsStore[playerid][2], 0);
        PlayerTextDrawBackgroundColor(playerid, TDPlayerSkinsStore[playerid][2], 255);
        PlayerTextDrawFont(playerid, TDPlayerSkinsStore[playerid][2], 4);
        PlayerTextDrawSetProportional(playerid, TDPlayerSkinsStore[playerid][2], 0);
        PlayerTextDrawSetShadow(playerid, TDPlayerSkinsStore[playerid][2], 0);
        PlayerTextDrawSetSelectable(playerid, TDPlayerSkinsStore[playerid][2], true);
    }

    TDPlayerSkinsStore[playerid][3] = CreatePlayerTextDraw(playerid, 49.905963, 247.250152, "Comprar");
    PlayerTextDrawLetterSize(playerid, TDPlayerSkinsStore[playerid][3], 0.141844, 0.894164);
    PlayerTextDrawAlignment(playerid, TDPlayerSkinsStore[playerid][3], 1);
    PlayerTextDrawColor(playerid, TDPlayerSkinsStore[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerSkinsStore[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerSkinsStore[playerid][3], -1);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerSkinsStore[playerid][3], 255);
    PlayerTextDrawFont(playerid, TDPlayerSkinsStore[playerid][3], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerSkinsStore[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerSkinsStore[playerid][3], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerSkinsStore[playerid][3], true);
    PlayerTextDrawTextSize(playerid, TDPlayerSkinsStore[playerid][3], 75.000000, 9.000000);

    TDPlayerSkinsStore[playerid][4] = CreatePlayerTextDraw(playerid, 41.083915, 263.250122, "LD_BEAT:left");
    PlayerTextDrawLetterSize(playerid, TDPlayerSkinsStore[playerid][4], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, TDPlayerSkinsStore[playerid][4], 13.930112, 11.750085);
    PlayerTextDrawAlignment(playerid, TDPlayerSkinsStore[playerid][4], 1);
    PlayerTextDrawColor(playerid, TDPlayerSkinsStore[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerSkinsStore[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerSkinsStore[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerSkinsStore[playerid][4], 255);
    PlayerTextDrawFont(playerid, TDPlayerSkinsStore[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, TDPlayerSkinsStore[playerid][4], 0);
    PlayerTextDrawSetShadow(playerid, TDPlayerSkinsStore[playerid][4], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerSkinsStore[playerid][4], true);

    TDPlayerSkinsStore[playerid][5] = CreatePlayerTextDraw(playerid, 70.383468, 263.250122, "LD_BEAT:right");
    PlayerTextDrawLetterSize(playerid, TDPlayerSkinsStore[playerid][5], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, TDPlayerSkinsStore[playerid][5], 13.930112, 11.750085);
    PlayerTextDrawAlignment(playerid, TDPlayerSkinsStore[playerid][5], 1);
    PlayerTextDrawColor(playerid, TDPlayerSkinsStore[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerSkinsStore[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerSkinsStore[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerSkinsStore[playerid][5], 255);
    PlayerTextDrawFont(playerid, TDPlayerSkinsStore[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, TDPlayerSkinsStore[playerid][5], 0);
    PlayerTextDrawSetShadow(playerid, TDPlayerSkinsStore[playerid][5], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerSkinsStore[playerid][5], true);
    return 1;
}
