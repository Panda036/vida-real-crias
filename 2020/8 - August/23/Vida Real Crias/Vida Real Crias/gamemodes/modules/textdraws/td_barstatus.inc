#include YSI\y_hooks

new PlayerText:PlayerBarStatus[MAX_PLAYERS][6];
new PlayerText:BarStatus[MAX_PLAYERS][17];

new TimerBarStatus[MAX_PLAYERS];

stock TDPlayerBarStatus(playerid)
{
    BarStatus[playerid][0] = CreatePlayerTextDraw(playerid, 421.5, 334.724060, "I");
    PlayerTextDrawLetterSize(playerid, BarStatus[playerid][0], 21.240295, 2.982496);
    PlayerTextDrawAlignment(playerid, BarStatus[playerid][0], 1);
    PlayerTextDrawColor(playerid, BarStatus[playerid][0], 200);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, BarStatus[playerid][0], -1);
    PlayerTextDrawBackgroundColor(playerid, BarStatus[playerid][0], 0);
    PlayerTextDrawFont(playerid, BarStatus[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, BarStatus[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][0], 0);

    BarStatus[playerid][1] = CreatePlayerTextDraw(playerid, 421.5, 317.322998, "I");
    PlayerTextDrawLetterSize(playerid, BarStatus[playerid][1], 21.240295, 2.982496);
    PlayerTextDrawAlignment(playerid, BarStatus[playerid][1], 1);
    PlayerTextDrawColor(playerid, BarStatus[playerid][1], 200);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, BarStatus[playerid][1], -1);
    PlayerTextDrawBackgroundColor(playerid, BarStatus[playerid][1], 0);
    PlayerTextDrawFont(playerid, BarStatus[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, BarStatus[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][1], 0);

    BarStatus[playerid][2] = CreatePlayerTextDraw(playerid, 421.5, 300.021942, "I");
    PlayerTextDrawLetterSize(playerid, BarStatus[playerid][2], 21.240295, 2.982496);
    PlayerTextDrawAlignment(playerid, BarStatus[playerid][2], 1);
    PlayerTextDrawColor(playerid, BarStatus[playerid][2], 200);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, BarStatus[playerid][2], -1);
    PlayerTextDrawBackgroundColor(playerid, BarStatus[playerid][2], 0);
    PlayerTextDrawFont(playerid, BarStatus[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, BarStatus[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][2], 0);

    BarStatus[playerid][3] = CreatePlayerTextDraw(playerid, 421.5, 282.620880, "I");
    PlayerTextDrawLetterSize(playerid, BarStatus[playerid][3], 21.240295, 2.982496);
    PlayerTextDrawAlignment(playerid, BarStatus[playerid][3], 1);
    PlayerTextDrawColor(playerid, BarStatus[playerid][3], 200);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, BarStatus[playerid][3], -1);
    PlayerTextDrawBackgroundColor(playerid, BarStatus[playerid][3], 0);
    PlayerTextDrawFont(playerid, BarStatus[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, BarStatus[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][3], 0);

    BarStatus[playerid][4] = CreatePlayerTextDraw(playerid, 421.5, 352.125122, "I");
    PlayerTextDrawLetterSize(playerid, BarStatus[playerid][4], 21.240295, 2.982496);
    PlayerTextDrawAlignment(playerid, BarStatus[playerid][4], 1);
    PlayerTextDrawColor(playerid, BarStatus[playerid][4], 200);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, BarStatus[playerid][4], -1);
    PlayerTextDrawBackgroundColor(playerid, BarStatus[playerid][4], 0);
    PlayerTextDrawFont(playerid, BarStatus[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, BarStatus[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][4], 0);

    BarStatus[playerid][5] = CreatePlayerTextDraw(playerid, 421.5, 265.119812, "I");
    PlayerTextDrawLetterSize(playerid, BarStatus[playerid][5], 21.240295, 2.982496);
    PlayerTextDrawAlignment(playerid, BarStatus[playerid][5], 1);
    PlayerTextDrawColor(playerid, BarStatus[playerid][5], 200);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, BarStatus[playerid][5], -1);
    PlayerTextDrawBackgroundColor(playerid, BarStatus[playerid][5], 0);
    PlayerTextDrawFont(playerid, BarStatus[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, BarStatus[playerid][5], 1);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][5], 0);

    BarStatus[playerid][6] = CreatePlayerTextDraw(playerid, (IsPlayerMobile(playerid) ? (467.0) : (547.0)), 363.749755, "_");
    PlayerTextDrawLetterSize(playerid, BarStatus[playerid][6], 0.000000, 0.735496);
    PlayerTextDrawTextSize(playerid, BarStatus[playerid][6], (IsPlayerMobile(playerid) ? (513.0) : (593.0)), 0.000000);
    PlayerTextDrawAlignment(playerid, BarStatus[playerid][6], 1);
    PlayerTextDrawColor(playerid, BarStatus[playerid][6], -65281);
    PlayerTextDrawUseBox(playerid, BarStatus[playerid][6], 1);
    PlayerTextDrawBoxColor(playerid, BarStatus[playerid][6], -2147483498);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, BarStatus[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, BarStatus[playerid][6], 255);
    PlayerTextDrawFont(playerid, BarStatus[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, BarStatus[playerid][6], 1);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][6], 0);

    BarStatus[playerid][7] = CreatePlayerTextDraw(playerid, (IsPlayerMobile(playerid) ? (467.0) : (547.0)), 346.048675, "_");
    PlayerTextDrawLetterSize(playerid, BarStatus[playerid][7], 0.000000, 0.735496);
    PlayerTextDrawTextSize(playerid, BarStatus[playerid][7], (IsPlayerMobile(playerid) ? (513.0) : (593.0)), 0.000000);
    PlayerTextDrawAlignment(playerid, BarStatus[playerid][7], 1);
    PlayerTextDrawColor(playerid, BarStatus[playerid][7], -65281);
    PlayerTextDrawUseBox(playerid, BarStatus[playerid][7], 1);
    PlayerTextDrawBoxColor(playerid, BarStatus[playerid][7], -2147483498);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, BarStatus[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, BarStatus[playerid][7], 255);
    PlayerTextDrawFont(playerid, BarStatus[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, BarStatus[playerid][7], 1);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][7], 0);

    BarStatus[playerid][8] = CreatePlayerTextDraw(playerid, (IsPlayerMobile(playerid) ? (467.0) : (547.0)), 328.547607, "_");
    PlayerTextDrawLetterSize(playerid, BarStatus[playerid][8], 0.000000, 0.735496);
    PlayerTextDrawTextSize(playerid, BarStatus[playerid][8], (IsPlayerMobile(playerid) ? (513.0) : (593.0)), 0.000000);
    PlayerTextDrawAlignment(playerid, BarStatus[playerid][8], 1);
    PlayerTextDrawColor(playerid, BarStatus[playerid][8], -65281);
    PlayerTextDrawUseBox(playerid, BarStatus[playerid][8], 1);
    PlayerTextDrawBoxColor(playerid, BarStatus[playerid][8], -2147483498);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, BarStatus[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, BarStatus[playerid][8], 255);
    PlayerTextDrawFont(playerid, BarStatus[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, BarStatus[playerid][8], 1);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][8], 0);

    BarStatus[playerid][9] = CreatePlayerTextDraw(playerid, (IsPlayerMobile(playerid) ? (467.0) : (547.0)), 311.446563, "_");
    PlayerTextDrawLetterSize(playerid, BarStatus[playerid][9], 0.000000, 0.735496);
    PlayerTextDrawTextSize(playerid, BarStatus[playerid][9], (IsPlayerMobile(playerid) ? (513.0) : (593.0)), 0.000000);
    PlayerTextDrawAlignment(playerid, BarStatus[playerid][9], 1);
    PlayerTextDrawColor(playerid, BarStatus[playerid][9], -65281);
    PlayerTextDrawUseBox(playerid, BarStatus[playerid][9], 1);
    PlayerTextDrawBoxColor(playerid, BarStatus[playerid][9], -2147483498);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, BarStatus[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, BarStatus[playerid][9], 255);
    PlayerTextDrawFont(playerid, BarStatus[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, BarStatus[playerid][9], 1);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][9], 0);

    BarStatus[playerid][10] = CreatePlayerTextDraw(playerid, 514.149536, 290.033447, "");
    PlayerTextDrawLetterSize(playerid, BarStatus[playerid][10], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, BarStatus[playerid][10], 19.360008, 14.070001);
    PlayerTextDrawAlignment(playerid, BarStatus[playerid][10], 1);
    PlayerTextDrawColor(playerid, BarStatus[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, BarStatus[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, BarStatus[playerid][10], 0);
    PlayerTextDrawFont(playerid, BarStatus[playerid][10], 5);
    PlayerTextDrawSetProportional(playerid, BarStatus[playerid][10], 0);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][10], 0);
    PlayerTextDrawSetPreviewModel(playerid, BarStatus[playerid][10], 1247);
    PlayerTextDrawSetPreviewRot(playerid, BarStatus[playerid][10], 0.000000, 0.000000, 0.000000, 1.000000);

    BarStatus[playerid][11] = CreatePlayerTextDraw(playerid, 512.799926, 302.583038, "");
    PlayerTextDrawLetterSize(playerid, BarStatus[playerid][11], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, BarStatus[playerid][11], 22.000000, 21.000000);
    PlayerTextDrawAlignment(playerid, BarStatus[playerid][11], 1);
    PlayerTextDrawColor(playerid, BarStatus[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, BarStatus[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, BarStatus[playerid][11], 0);
    PlayerTextDrawFont(playerid, BarStatus[playerid][11], 5);
    PlayerTextDrawSetProportional(playerid, BarStatus[playerid][11], 0);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][11], 0);
    PlayerTextDrawSetPreviewModel(playerid, BarStatus[playerid][11], 2703);
    PlayerTextDrawSetPreviewRot(playerid, BarStatus[playerid][11], -90.000000, 0.000000, 0.000000, 1.000000);

    BarStatus[playerid][12] = CreatePlayerTextDraw(playerid, 514.924560, 324.067626, "");
    PlayerTextDrawLetterSize(playerid, BarStatus[playerid][12], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, BarStatus[playerid][12], 20.229959, 15.839881);
    PlayerTextDrawAlignment(playerid, BarStatus[playerid][12], 1);
    PlayerTextDrawColor(playerid, BarStatus[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, BarStatus[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, BarStatus[playerid][12], 0);
    PlayerTextDrawFont(playerid, BarStatus[playerid][12], 5);
    PlayerTextDrawSetProportional(playerid, BarStatus[playerid][12], 0);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][12], 0);
    PlayerTextDrawSetPreviewModel(playerid, BarStatus[playerid][12], 1484);
    PlayerTextDrawSetPreviewRot(playerid, BarStatus[playerid][12], 0.000000, 0.000000, 0.000000, 1.000000);

    BarStatus[playerid][13] = CreatePlayerTextDraw(playerid, 514.924560, 340.468627, "");
    PlayerTextDrawLetterSize(playerid, BarStatus[playerid][13], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, BarStatus[playerid][13], 20.229959, 15.839881);
    PlayerTextDrawAlignment(playerid, BarStatus[playerid][13], 1);
    PlayerTextDrawColor(playerid, BarStatus[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, BarStatus[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, BarStatus[playerid][13], 0);
    PlayerTextDrawFont(playerid, BarStatus[playerid][13], 5);
    PlayerTextDrawSetProportional(playerid, BarStatus[playerid][13], 0);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][13], 0);
    PlayerTextDrawSetPreviewModel(playerid, BarStatus[playerid][13], 14866);
    PlayerTextDrawSetPreviewRot(playerid, BarStatus[playerid][13], -25.000000, 0.000000, 270.000000, 1.000000);

    BarStatus[playerid][14] = CreatePlayerTextDraw(playerid, 514.924560, 358.369720, "");
    PlayerTextDrawLetterSize(playerid, BarStatus[playerid][14], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, BarStatus[playerid][14], 20.229959, 15.839881);
    PlayerTextDrawAlignment(playerid, BarStatus[playerid][14], 1);
    PlayerTextDrawColor(playerid, BarStatus[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, BarStatus[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, BarStatus[playerid][14], 0);
    PlayerTextDrawFont(playerid, BarStatus[playerid][14], 5);
    PlayerTextDrawSetProportional(playerid, BarStatus[playerid][14], 0);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][14], 0);
    PlayerTextDrawSetPreviewModel(playerid, BarStatus[playerid][14], 1240);
    PlayerTextDrawSetPreviewRot(playerid, BarStatus[playerid][14], 0.000000, 0.000000, 0.000000, 1.000000);

    BarStatus[playerid][15] = CreatePlayerTextDraw(playerid, 421.5, 247.918762, "I");
    PlayerTextDrawLetterSize(playerid, BarStatus[playerid][15], 21.240295, 2.982496);
    PlayerTextDrawAlignment(playerid, BarStatus[playerid][15], 1);
    PlayerTextDrawColor(playerid, BarStatus[playerid][15], 200);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, BarStatus[playerid][15], -1);
    PlayerTextDrawBackgroundColor(playerid, BarStatus[playerid][15], 0);
    PlayerTextDrawFont(playerid, BarStatus[playerid][15], 1);
    PlayerTextDrawSetProportional(playerid, BarStatus[playerid][15], 1);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][15], 0);

    BarStatus[playerid][16] = CreatePlayerTextDraw(playerid, (IsPlayerMobile(playerid) ? (457.0) : (517.0)), 257.699981, "______Vida_Real_Crias");
    PlayerTextDrawLetterSize(playerid, BarStatus[playerid][16], 0.142999, 0.861998);
    PlayerTextDrawAlignment(playerid, BarStatus[playerid][16], 1);
    PlayerTextDrawColor(playerid, BarStatus[playerid][16], -1);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, BarStatus[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, BarStatus[playerid][16], 255);
    PlayerTextDrawFont(playerid, BarStatus[playerid][16], 2);
    PlayerTextDrawSetProportional(playerid, BarStatus[playerid][16], 1);
    PlayerTextDrawSetShadow(playerid, BarStatus[playerid][16], 0);

    PlayerBarStatus[playerid][0] = CreatePlayerTextDraw(playerid, (IsPlayerMobile(playerid) ? (489.9) : (549.9)), 274.046966, "UP:_02:02");
    PlayerTextDrawLetterSize(playerid, PlayerBarStatus[playerid][0], 0.316249, 1.209166);
    PlayerTextDrawAlignment(playerid, PlayerBarStatus[playerid][0], 2);
    PlayerTextDrawColor(playerid, PlayerBarStatus[playerid][0], -16776961);
    PlayerTextDrawSetShadow(playerid, PlayerBarStatus[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, PlayerBarStatus[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerBarStatus[playerid][0], 255);
    PlayerTextDrawFont(playerid, PlayerBarStatus[playerid][0], 3);
    PlayerTextDrawSetProportional(playerid, PlayerBarStatus[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, PlayerBarStatus[playerid][0], 0);

    PlayerBarStatus[playerid][1] = CreatePlayerTextDraw(playerid, (IsPlayerMobile(playerid) ? (488.5) : (568.5)), 290.847991, "0");
    PlayerTextDrawLetterSize(playerid, PlayerBarStatus[playerid][1], 0.316249, 1.209166);
    PlayerTextDrawAlignment(playerid, PlayerBarStatus[playerid][1], 2);
    PlayerTextDrawColor(playerid, PlayerBarStatus[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, PlayerBarStatus[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, PlayerBarStatus[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerBarStatus[playerid][1], 255);
    PlayerTextDrawFont(playerid, PlayerBarStatus[playerid][1], 3);
    PlayerTextDrawSetProportional(playerid, PlayerBarStatus[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, PlayerBarStatus[playerid][1], 0);

    PlayerBarStatus[playerid][2] = CreatePlayerTextDraw(playerid, (IsPlayerMobile(playerid) ? (467.0) : (547.0)), 311.446563, "_");
    PlayerTextDrawLetterSize(playerid, PlayerBarStatus[playerid][2], 0.000000, 0.735496);
    PlayerTextDrawTextSize(playerid, PlayerBarStatus[playerid][2], (IsPlayerMobile(playerid) ? (513.0) : (593.0)), 0.000000);
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

    PlayerBarStatus[playerid][3] = CreatePlayerTextDraw(playerid, (IsPlayerMobile(playerid) ? (467.0) : (547.0)), 328.547607, "_");
    PlayerTextDrawLetterSize(playerid, PlayerBarStatus[playerid][3], 0.000000, 0.735496);
    PlayerTextDrawTextSize(playerid, PlayerBarStatus[playerid][3], (IsPlayerMobile(playerid) ? (513.0) : (593.0)), 0.000000);
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

    PlayerBarStatus[playerid][4] = CreatePlayerTextDraw(playerid, (IsPlayerMobile(playerid) ? (467.0) : (547.0)), 346.048675, "_");
    PlayerTextDrawLetterSize(playerid, PlayerBarStatus[playerid][4], 0.000000, 0.735496);
    PlayerTextDrawTextSize(playerid, PlayerBarStatus[playerid][4], (IsPlayerMobile(playerid) ? (513.0) : (593.0)), 0.000000);
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

    PlayerBarStatus[playerid][5] = CreatePlayerTextDraw(playerid, (IsPlayerMobile(playerid) ? (467.0) : (547.0)), 363.749755, "_");
    PlayerTextDrawLetterSize(playerid, PlayerBarStatus[playerid][5], 0.000000, 0.735496);
    PlayerTextDrawTextSize(playerid, PlayerBarStatus[playerid][5], (IsPlayerMobile(playerid) ? (513.0) : (593.0)), 0.000000);
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
    for(new textid = 0; textid < 6; textid++){
        PlayerTextDrawShow(playerid, PlayerBarStatus[playerid][textid]);
    }
    for(new textid = 0; textid < 17; textid++){
        PlayerTextDrawShow(playerid, BarStatus[playerid][textid]);
    }
    return 1;
}

stock StatusOcultar(playerid)
{
    for(new textid = 0; textid < 6; textid++){
        PlayerTextDrawHide(playerid, PlayerBarStatus[playerid][textid]);
    }
    for(new textid = 0; textid < 17; textid++){
        PlayerTextDrawHide(playerid, BarStatus[playerid][textid]);
    }
    return 1;
}
