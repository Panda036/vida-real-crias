#include YSI\y_hooks

new PlayerText:PlayerBarStatus[MAX_PLAYERS][6];
new TimerBarStatus[MAX_PLAYERS];
new Text:BarStatus[17];

hook OnGameModeInit()
{
    BarStatus[0] = TextDrawCreate(421.426879, 334.724060, "I");
    TextDrawLetterSize(BarStatus[0], 21.240295, 2.982496);
    TextDrawAlignment(BarStatus[0], 1);
    TextDrawColor(BarStatus[0], 200);
    TextDrawSetShadow(BarStatus[0], 0);
    TextDrawSetOutline(BarStatus[0], -1);
    TextDrawBackgroundColor(BarStatus[0], 0);
    TextDrawFont(BarStatus[0], 1);
    TextDrawSetProportional(BarStatus[0], 1);
    TextDrawSetShadow(BarStatus[0], 0);

    BarStatus[1] = TextDrawCreate(421.426879, 317.322998, "I");
    TextDrawLetterSize(BarStatus[1], 21.240295, 2.982496);
    TextDrawAlignment(BarStatus[1], 1);
    TextDrawColor(BarStatus[1], 200);
    TextDrawSetShadow(BarStatus[1], 0);
    TextDrawSetOutline(BarStatus[1], -1);
    TextDrawBackgroundColor(BarStatus[1], 0);
    TextDrawFont(BarStatus[1], 1);
    TextDrawSetProportional(BarStatus[1], 1);
    TextDrawSetShadow(BarStatus[1], 0);

    BarStatus[2] = TextDrawCreate(421.426879, 300.021942, "I");
    TextDrawLetterSize(BarStatus[2], 21.240295, 2.982496);
    TextDrawAlignment(BarStatus[2], 1);
    TextDrawColor(BarStatus[2], 200);
    TextDrawSetShadow(BarStatus[2], 0);
    TextDrawSetOutline(BarStatus[2], -1);
    TextDrawBackgroundColor(BarStatus[2], 0);
    TextDrawFont(BarStatus[2], 1);
    TextDrawSetProportional(BarStatus[2], 1);
    TextDrawSetShadow(BarStatus[2], 0);

    BarStatus[3] = TextDrawCreate(421.426879, 282.620880, "I");
    TextDrawLetterSize(BarStatus[3], 21.240295, 2.982496);
    TextDrawAlignment(BarStatus[3], 1);
    TextDrawColor(BarStatus[3], 200);
    TextDrawSetShadow(BarStatus[3], 0);
    TextDrawSetOutline(BarStatus[3], -1);
    TextDrawBackgroundColor(BarStatus[3], 0);
    TextDrawFont(BarStatus[3], 1);
    TextDrawSetProportional(BarStatus[3], 1);
    TextDrawSetShadow(BarStatus[3], 0);

    BarStatus[4] = TextDrawCreate(421.426879, 352.125122, "I");
    TextDrawLetterSize(BarStatus[4], 21.240295, 2.982496);
    TextDrawAlignment(BarStatus[4], 1);
    TextDrawColor(BarStatus[4], 200);
    TextDrawSetShadow(BarStatus[4], 0);
    TextDrawSetOutline(BarStatus[4], -1);
    TextDrawBackgroundColor(BarStatus[4], 0);
    TextDrawFont(BarStatus[4], 1);
    TextDrawSetProportional(BarStatus[4], 1);
    TextDrawSetShadow(BarStatus[4], 0);

    BarStatus[5] = TextDrawCreate(421.426879, 265.119812, "I");
    TextDrawLetterSize(BarStatus[5], 21.240295, 2.982496);
    TextDrawAlignment(BarStatus[5], 1);
    TextDrawColor(BarStatus[5], 200);
    TextDrawSetShadow(BarStatus[5], 0);
    TextDrawSetOutline(BarStatus[5], -1);
    TextDrawBackgroundColor(BarStatus[5], 0);
    TextDrawFont(BarStatus[5], 1);
    TextDrawSetProportional(BarStatus[5], 1);
    TextDrawSetShadow(BarStatus[5], 0);

    BarStatus[6] = TextDrawCreate(547.425170, 363.749755, "_");
    TextDrawLetterSize(BarStatus[6], 0.000000, 0.735496);
    TextDrawTextSize(BarStatus[6], 593.823120, 0.000000);
    TextDrawAlignment(BarStatus[6], 1);
    TextDrawColor(BarStatus[6], -65281);
    TextDrawUseBox(BarStatus[6], 1);
    TextDrawBoxColor(BarStatus[6], -2147483498);
    TextDrawSetShadow(BarStatus[6], 0);
    TextDrawSetOutline(BarStatus[6], 0);
    TextDrawBackgroundColor(BarStatus[6], 255);
    TextDrawFont(BarStatus[6], 1);
    TextDrawSetProportional(BarStatus[6], 1);
    TextDrawSetShadow(BarStatus[6], 0);

    BarStatus[7] = TextDrawCreate(547.425170, 346.048675, "_");
    TextDrawLetterSize(BarStatus[7], 0.000000, 0.735496);
    TextDrawTextSize(BarStatus[7], 593.823120, 0.000000);
    TextDrawAlignment(BarStatus[7], 1);
    TextDrawColor(BarStatus[7], -65281);
    TextDrawUseBox(BarStatus[7], 1);
    TextDrawBoxColor(BarStatus[7], -2147483498);
    TextDrawSetShadow(BarStatus[7], 0);
    TextDrawSetOutline(BarStatus[7], 0);
    TextDrawBackgroundColor(BarStatus[7], 255);
    TextDrawFont(BarStatus[7], 1);
    TextDrawSetProportional(BarStatus[7], 1);
    TextDrawSetShadow(BarStatus[7], 0);

    BarStatus[8] = TextDrawCreate(547.425170, 328.547607, "_");
    TextDrawLetterSize(BarStatus[8], 0.000000, 0.735496);
    TextDrawTextSize(BarStatus[8], 593.823120, 0.000000);
    TextDrawAlignment(BarStatus[8], 1);
    TextDrawColor(BarStatus[8], -65281);
    TextDrawUseBox(BarStatus[8], 1);
    TextDrawBoxColor(BarStatus[8], -2147483498);
    TextDrawSetShadow(BarStatus[8], 0);
    TextDrawSetOutline(BarStatus[8], 0);
    TextDrawBackgroundColor(BarStatus[8], 255);
    TextDrawFont(BarStatus[8], 1);
    TextDrawSetProportional(BarStatus[8], 1);
    TextDrawSetShadow(BarStatus[8], 0);

    BarStatus[9] = TextDrawCreate(547.425170, 311.446563, "_");
    TextDrawLetterSize(BarStatus[9], 0.000000, 0.735496);
    TextDrawTextSize(BarStatus[9], 593.823120, 0.000000);
    TextDrawAlignment(BarStatus[9], 1);
    TextDrawColor(BarStatus[9], -65281);
    TextDrawUseBox(BarStatus[9], 1);
    TextDrawBoxColor(BarStatus[9], -2147483498);
    TextDrawSetShadow(BarStatus[9], 0);
    TextDrawSetOutline(BarStatus[9], 0);
    TextDrawBackgroundColor(BarStatus[9], 255);
    TextDrawFont(BarStatus[9], 1);
    TextDrawSetProportional(BarStatus[9], 1);
    TextDrawSetShadow(BarStatus[9], 0);

    BarStatus[10] = TextDrawCreate(514.149536, 290.033447, "");
    TextDrawLetterSize(BarStatus[10], 0.000000, 0.000000);
    TextDrawTextSize(BarStatus[10], 19.360008, 14.070001);
    TextDrawAlignment(BarStatus[10], 1);
    TextDrawColor(BarStatus[10], -1);
    TextDrawSetShadow(BarStatus[10], 0);
    TextDrawSetOutline(BarStatus[10], 0);
    TextDrawBackgroundColor(BarStatus[10], 0);
    TextDrawFont(BarStatus[10], 5);
    TextDrawSetProportional(BarStatus[10], 0);
    TextDrawSetShadow(BarStatus[10], 0);
    TextDrawSetPreviewModel(BarStatus[10], 1247);
    TextDrawSetPreviewRot(BarStatus[10], 0.000000, 0.000000, 0.000000, 1.000000);

    BarStatus[11] = TextDrawCreate(512.799926, 302.583038, "");
    TextDrawLetterSize(BarStatus[11], 0.000000, 0.000000);
    TextDrawTextSize(BarStatus[11], 22.000000, 21.000000);
    TextDrawAlignment(BarStatus[11], 1);
    TextDrawColor(BarStatus[11], -1);
    TextDrawSetShadow(BarStatus[11], 0);
    TextDrawSetOutline(BarStatus[11], 0);
    TextDrawBackgroundColor(BarStatus[11], 0);
    TextDrawFont(BarStatus[11], 5);
    TextDrawSetProportional(BarStatus[11], 0);
    TextDrawSetShadow(BarStatus[11], 0);
    TextDrawSetPreviewModel(BarStatus[11], 2703);
    TextDrawSetPreviewRot(BarStatus[11], -90.000000, 0.000000, 0.000000, 1.000000);

    BarStatus[12] = TextDrawCreate(514.924560, 324.067626, "");
    TextDrawLetterSize(BarStatus[12], 0.000000, 0.000000);
    TextDrawTextSize(BarStatus[12], 20.229959, 15.839881);
    TextDrawAlignment(BarStatus[12], 1);
    TextDrawColor(BarStatus[12], -1);
    TextDrawSetShadow(BarStatus[12], 0);
    TextDrawSetOutline(BarStatus[12], 0);
    TextDrawBackgroundColor(BarStatus[12], 0);
    TextDrawFont(BarStatus[12], 5);
    TextDrawSetProportional(BarStatus[12], 0);
    TextDrawSetShadow(BarStatus[12], 0);
    TextDrawSetPreviewModel(BarStatus[12], 1484);
    TextDrawSetPreviewRot(BarStatus[12], 0.000000, 0.000000, 0.000000, 1.000000);

    BarStatus[13] = TextDrawCreate(514.924560, 340.468627, "");
    TextDrawLetterSize(BarStatus[13], 0.000000, 0.000000);
    TextDrawTextSize(BarStatus[13], 20.229959, 15.839881);
    TextDrawAlignment(BarStatus[13], 1);
    TextDrawColor(BarStatus[13], -1);
    TextDrawSetShadow(BarStatus[13], 0);
    TextDrawSetOutline(BarStatus[13], 0);
    TextDrawBackgroundColor(BarStatus[13], 0);
    TextDrawFont(BarStatus[13], 5);
    TextDrawSetProportional(BarStatus[13], 0);
    TextDrawSetShadow(BarStatus[13], 0);
    TextDrawSetPreviewModel(BarStatus[13], 14866);
    TextDrawSetPreviewRot(BarStatus[13], -25.000000, 0.000000, 270.000000, 1.000000);

    BarStatus[14] = TextDrawCreate(514.924560, 358.369720, "");
    TextDrawLetterSize(BarStatus[14], 0.000000, 0.000000);
    TextDrawTextSize(BarStatus[14], 20.229959, 15.839881);
    TextDrawAlignment(BarStatus[14], 1);
    TextDrawColor(BarStatus[14], -1);
    TextDrawSetShadow(BarStatus[14], 0);
    TextDrawSetOutline(BarStatus[14], 0);
    TextDrawBackgroundColor(BarStatus[14], 0);
    TextDrawFont(BarStatus[14], 5);
    TextDrawSetProportional(BarStatus[14], 0);
    TextDrawSetShadow(BarStatus[14], 0);
    TextDrawSetPreviewModel(BarStatus[14], 1240);
    TextDrawSetPreviewRot(BarStatus[14], 0.000000, 0.000000, 0.000000, 1.000000);

    BarStatus[15] = TextDrawCreate(421.426879, 247.918762, "I");
    TextDrawLetterSize(BarStatus[15], 21.240295, 2.982496);
    TextDrawAlignment(BarStatus[15], 1);
    TextDrawColor(BarStatus[15], 200);
    TextDrawSetShadow(BarStatus[15], 0);
    TextDrawSetOutline(BarStatus[15], -1);
    TextDrawBackgroundColor(BarStatus[15], 0);
    TextDrawFont(BarStatus[15], 1);
    TextDrawSetProportional(BarStatus[15], 1);
    TextDrawSetShadow(BarStatus[15], 0);

    BarStatus[16] = TextDrawCreate(517.000244, 257.699981, "______Vida_Real_Crias");
    TextDrawLetterSize(BarStatus[16], 0.142999, 0.861998);
    TextDrawAlignment(BarStatus[16], 1);
    TextDrawColor(BarStatus[16], -1);
    TextDrawSetShadow(BarStatus[16], 0);
    TextDrawSetOutline(BarStatus[16], 0);
    TextDrawBackgroundColor(BarStatus[16], 255);
    TextDrawFont(BarStatus[16], 2);
    TextDrawSetProportional(BarStatus[16], 1);
    TextDrawSetShadow(BarStatus[16], 0);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    PlayerBarStatus[playerid][0] = CreatePlayerTextDraw(playerid, 549.942382, 274.046966, "UP:_02:02");
    PlayerTextDrawLetterSize(playerid, PlayerBarStatus[playerid][0], 0.316249, 1.209166);
    PlayerTextDrawAlignment(playerid, PlayerBarStatus[playerid][0], 2);
    PlayerTextDrawColor(playerid, PlayerBarStatus[playerid][0], -16776961);
    PlayerTextDrawSetShadow(playerid, PlayerBarStatus[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, PlayerBarStatus[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerBarStatus[playerid][0], 255);
    PlayerTextDrawFont(playerid, PlayerBarStatus[playerid][0], 3);
    PlayerTextDrawSetProportional(playerid, PlayerBarStatus[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, PlayerBarStatus[playerid][0], 0);

    PlayerBarStatus[playerid][1] = CreatePlayerTextDraw(playerid, 568.537841, 290.847991, "0");
    PlayerTextDrawLetterSize(playerid, PlayerBarStatus[playerid][1], 0.316249, 1.209166);
    PlayerTextDrawAlignment(playerid, PlayerBarStatus[playerid][1], 2);
    PlayerTextDrawColor(playerid, PlayerBarStatus[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, PlayerBarStatus[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, PlayerBarStatus[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerBarStatus[playerid][1], 255);
    PlayerTextDrawFont(playerid, PlayerBarStatus[playerid][1], 3);
    PlayerTextDrawSetProportional(playerid, PlayerBarStatus[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, PlayerBarStatus[playerid][1], 0);

    PlayerBarStatus[playerid][2] = CreatePlayerTextDraw(playerid, 547.0, 311.446563, "_");
    PlayerTextDrawLetterSize(playerid, PlayerBarStatus[playerid][2], 0.000000, 0.735496);
    PlayerTextDrawTextSize(playerid, PlayerBarStatus[playerid][2], 593.0, 0.000000);
    PlayerTextDrawAlignment(playerid, PlayerBarStatus[playerid][2], 1);
    PlayerTextDrawColor(playerid, PlayerBarStatus[playerid][2], -16776961);
    PlayerTextDrawUseBox(playerid, PlayerBarStatus[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, PlayerBarStatus[playerid][2], -16776961);
    PlayerTextDrawSetShadow(playerid, PlayerBarStatus[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, PlayerBarStatus[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerBarStatus[playerid][2], 255);
    PlayerTextDrawFont(playerid, PlayerBarStatus[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, PlayerBarStatus[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, PlayerBarStatus[playerid][2], 0);

    PlayerBarStatus[playerid][3] = CreatePlayerTextDraw(playerid, 547.0, 328.547607, "_");
    PlayerTextDrawLetterSize(playerid, PlayerBarStatus[playerid][3], 0.000000, 0.735496);
    PlayerTextDrawTextSize(playerid, PlayerBarStatus[playerid][3], 593.0, 0.000000);
    PlayerTextDrawAlignment(playerid, PlayerBarStatus[playerid][3], 1);
    PlayerTextDrawColor(playerid, PlayerBarStatus[playerid][3], -16776961);
    PlayerTextDrawUseBox(playerid, PlayerBarStatus[playerid][3], 1);
    PlayerTextDrawBoxColor(playerid, PlayerBarStatus[playerid][3], -16776961);
    PlayerTextDrawSetShadow(playerid, PlayerBarStatus[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, PlayerBarStatus[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerBarStatus[playerid][3], 255);
    PlayerTextDrawFont(playerid, PlayerBarStatus[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, PlayerBarStatus[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, PlayerBarStatus[playerid][3], 0);

    PlayerBarStatus[playerid][4] = CreatePlayerTextDraw(playerid, 547.0, 346.048675, "_");
    PlayerTextDrawLetterSize(playerid, PlayerBarStatus[playerid][4], 0.000000, 0.735496);
    PlayerTextDrawTextSize(playerid, PlayerBarStatus[playerid][4], 593.0, 0.000000);
    PlayerTextDrawAlignment(playerid, PlayerBarStatus[playerid][4], 1);
    PlayerTextDrawColor(playerid, PlayerBarStatus[playerid][4], -65281);
    PlayerTextDrawUseBox(playerid, PlayerBarStatus[playerid][4], 1);
    PlayerTextDrawBoxColor(playerid, PlayerBarStatus[playerid][4], -16776961);
    PlayerTextDrawSetShadow(playerid, PlayerBarStatus[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, PlayerBarStatus[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerBarStatus[playerid][4], 255);
    PlayerTextDrawFont(playerid, PlayerBarStatus[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, PlayerBarStatus[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, PlayerBarStatus[playerid][4], 0);

    PlayerBarStatus[playerid][5] = CreatePlayerTextDraw(playerid, 547.0, 363.749755, "_");
    PlayerTextDrawLetterSize(playerid, PlayerBarStatus[playerid][5], 0.000000, 0.735496);
    PlayerTextDrawTextSize(playerid, PlayerBarStatus[playerid][5], 593.0, 0.000000);
    PlayerTextDrawAlignment(playerid, PlayerBarStatus[playerid][5], 1);
    PlayerTextDrawColor(playerid, PlayerBarStatus[playerid][5], -65281);
    PlayerTextDrawUseBox(playerid, PlayerBarStatus[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid, PlayerBarStatus[playerid][5], -16776961);
    PlayerTextDrawSetShadow(playerid, PlayerBarStatus[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, PlayerBarStatus[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerBarStatus[playerid][5], 255);
    PlayerTextDrawFont(playerid, PlayerBarStatus[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, PlayerBarStatus[playerid][5], 1);
    PlayerTextDrawSetShadow(playerid, PlayerBarStatus[playerid][5], 0);
    return 1;
}

stock StatusMostrar(playerid)
{
    for(new i=0; i < 6; i++){
        PlayerTextDrawShow(playerid, PlayerBarStatus[playerid][i]);
    }
    for(new i=0; i < 17; i++){
        TextDrawShowForPlayer(playerid, BarStatus[i]);
    }
    return 1;
}

stock StatusOcultar(playerid)
{
    for(new i=0; i < 6; i++){
        PlayerTextDrawHide(playerid, PlayerBarStatus[playerid][i]);
    }
    for(new i=0; i < 17; i++){
        TextDrawHideForPlayer(playerid, BarStatus[i]);
    }
    return 1;
}
