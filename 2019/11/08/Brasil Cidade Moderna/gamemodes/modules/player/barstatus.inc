#include YSI\y_hooks

new PlayerText:PlayerStatus[MAX_PLAYERS][29];

hook OnPlayerConnect(playerid)
{
    PlayerStatus[playerid][0] = CreatePlayerTextDraw(playerid, 559.696166, 295.111968, "box");
    PlayerTextDrawLetterSize(playerid, PlayerStatus[playerid][0], 0.000000, 16.298648);
    PlayerTextDrawTextSize(playerid, PlayerStatus[playerid][0], 636.076538, 0.000000);
    PlayerTextDrawAlignment(playerid, PlayerStatus[playerid][0], 1);
    PlayerTextDrawUseBox(playerid, PlayerStatus[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, PlayerStatus[playerid][0], 130);

    PlayerStatus[playerid][1] = CreatePlayerTextDraw(playerid, 560.699951, 296.777862, "box");
    PlayerTextDrawLetterSize(playerid, PlayerStatus[playerid][1], 0.000000, 1.939012);
    PlayerTextDrawTextSize(playerid, PlayerStatus[playerid][1], 634.797485, 0.000000);
    PlayerTextDrawAlignment(playerid, PlayerStatus[playerid][1], 1);
    PlayerTextDrawUseBox(playerid, PlayerStatus[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, PlayerStatus[playerid][1], -2139062222);

    PlayerStatus[playerid][2] = CreatePlayerTextDraw(playerid, 560.699951, 320.579315, "box");
    PlayerTextDrawLetterSize(playerid, PlayerStatus[playerid][2], 0.000000, 1.465988);
    PlayerTextDrawTextSize(playerid, PlayerStatus[playerid][2], 634.797485, 0.000000);
    PlayerTextDrawAlignment(playerid, PlayerStatus[playerid][2], 1);
    PlayerTextDrawUseBox(playerid, PlayerStatus[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, PlayerStatus[playerid][2], -2139062222);

    PlayerStatus[playerid][3] = CreatePlayerTextDraw(playerid, 560.699951, 339.880493, "box");
    PlayerTextDrawLetterSize(playerid, PlayerStatus[playerid][3], 0.000000, 1.465988);
    PlayerTextDrawTextSize(playerid, PlayerStatus[playerid][3], 634.797485, 0.000000);
    PlayerTextDrawAlignment(playerid, PlayerStatus[playerid][3], 1);
    PlayerTextDrawUseBox(playerid, PlayerStatus[playerid][3], 1);
    PlayerTextDrawBoxColor(playerid, PlayerStatus[playerid][3], -2139062222);

    PlayerStatus[playerid][4] = CreatePlayerTextDraw(playerid, 560.699951, 359.381683, "box");
    PlayerTextDrawLetterSize(playerid, PlayerStatus[playerid][4], 0.000000, 1.465988);
    PlayerTextDrawTextSize(playerid, PlayerStatus[playerid][4], 634.797485, 0.000000);
    PlayerTextDrawAlignment(playerid, PlayerStatus[playerid][4], 1);
    PlayerTextDrawUseBox(playerid, PlayerStatus[playerid][4], 1);
    PlayerTextDrawBoxColor(playerid, PlayerStatus[playerid][4], -2139062222);

    PlayerStatus[playerid][5] = CreatePlayerTextDraw(playerid, 560.699951, 378.482849, "box");
    PlayerTextDrawLetterSize(playerid, PlayerStatus[playerid][5], 0.000000, 1.465988);
    PlayerTextDrawTextSize(playerid, PlayerStatus[playerid][5], 634.797485, 0.000000);
    PlayerTextDrawAlignment(playerid, PlayerStatus[playerid][5], 1);
    PlayerTextDrawUseBox(playerid, PlayerStatus[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid, PlayerStatus[playerid][5], -2139062222);

    PlayerStatus[playerid][6] = CreatePlayerTextDraw(playerid, 560.699951, 397.984039, "box");
    PlayerTextDrawLetterSize(playerid, PlayerStatus[playerid][6], 0.000000, 1.465988);
    PlayerTextDrawTextSize(playerid, PlayerStatus[playerid][6], 634.797485, 0.000000);
    PlayerTextDrawAlignment(playerid, PlayerStatus[playerid][6], 1);
    PlayerTextDrawUseBox(playerid, PlayerStatus[playerid][6], 1);
    PlayerTextDrawBoxColor(playerid, PlayerStatus[playerid][6], -2139062222);

    PlayerStatus[playerid][7] = CreatePlayerTextDraw(playerid, 560.699951, 417.085205, "box");
    PlayerTextDrawLetterSize(playerid, PlayerStatus[playerid][7], 0.000000, 1.419983);
    PlayerTextDrawTextSize(playerid, PlayerStatus[playerid][7], 635.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, PlayerStatus[playerid][7], 1);
    PlayerTextDrawUseBox(playerid, PlayerStatus[playerid][7], 1);
    PlayerTextDrawBoxColor(playerid, PlayerStatus[playerid][7], -2139062222);

    PlayerStatus[playerid][8] = CreatePlayerTextDraw(playerid, 560.699951, 434.986297, "box");
    PlayerTextDrawLetterSize(playerid, PlayerStatus[playerid][8], 0.000000, 0.626972);
    PlayerTextDrawTextSize(playerid, PlayerStatus[playerid][8], 633.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, PlayerStatus[playerid][8], 1);
    PlayerTextDrawUseBox(playerid, PlayerStatus[playerid][8], 1);
    PlayerTextDrawBoxColor(playerid, PlayerStatus[playerid][8], -2139062222);

    PlayerStatus[playerid][9] = CreatePlayerTextDraw(playerid, 577.499877, 341.800140, "box");
    PlayerTextDrawLetterSize(playerid, PlayerStatus[playerid][9], 0.000000, 1.139001);
    PlayerTextDrawTextSize(playerid, PlayerStatus[playerid][9], 633.830200, 0.000000);
    PlayerTextDrawAlignment(playerid, PlayerStatus[playerid][9], 1);
    PlayerTextDrawUseBox(playerid, PlayerStatus[playerid][9], 1);
    PlayerTextDrawBoxColor(playerid, PlayerStatus[playerid][9], -1061109660);

    PlayerStatus[playerid][10] = CreatePlayerTextDraw(playerid, 577.499877, 360.801300, "box"); //273px
    PlayerTextDrawLetterSize(playerid, PlayerStatus[playerid][10], 0.000000, 1.139001);
    PlayerTextDrawTextSize(playerid, PlayerStatus[playerid][10], 633.830200, 0.000000);
    PlayerTextDrawBoxColor(playerid, PlayerStatus[playerid][10], -1061109660);
    PlayerTextDrawUseBox(playerid, PlayerStatus[playerid][10], 1);

    PlayerStatus[playerid][11] = CreatePlayerTextDraw(playerid, 577.499877, 380.202484, "box");
    PlayerTextDrawLetterSize(playerid, PlayerStatus[playerid][11], 0.000000, 1.139001);
    PlayerTextDrawTextSize(playerid, PlayerStatus[playerid][11], 633.830200, 0.000000);
    PlayerTextDrawAlignment(playerid, PlayerStatus[playerid][11], 1);
    PlayerTextDrawUseBox(playerid, PlayerStatus[playerid][11], 1);
    PlayerTextDrawBoxColor(playerid, PlayerStatus[playerid][11], -1061109660);

    PlayerStatus[playerid][12] = CreatePlayerTextDraw(playerid, 577.499877, 399.303649, "box");
    PlayerTextDrawLetterSize(playerid, PlayerStatus[playerid][12], 0.000000, 1.139001);
    PlayerTextDrawTextSize(playerid, PlayerStatus[playerid][12], 633.830200, 0.000000);
    PlayerTextDrawAlignment(playerid, PlayerStatus[playerid][12], 1);
    PlayerTextDrawUseBox(playerid, PlayerStatus[playerid][12], 1);
    PlayerTextDrawBoxColor(playerid, PlayerStatus[playerid][12], -1061109660);

    PlayerStatus[playerid][13] = CreatePlayerTextDraw(playerid, 577.499877, 418.404815, "box");
    PlayerTextDrawLetterSize(playerid, PlayerStatus[playerid][13], 0.000000, 1.139001);
    PlayerTextDrawTextSize(playerid, PlayerStatus[playerid][13], 633.830200, 0.000000);
    PlayerTextDrawAlignment(playerid, PlayerStatus[playerid][13], 1);
    PlayerTextDrawUseBox(playerid, PlayerStatus[playerid][13], 1);
    PlayerTextDrawBoxColor(playerid, PlayerStatus[playerid][13], -1061109660);

    PlayerStatus[playerid][14] = CreatePlayerTextDraw(playerid, 577.499877, 341.800140, "box");
    PlayerTextDrawLetterSize(playerid, PlayerStatus[playerid][14], 0.000000, 1.139001);
    PlayerTextDrawTextSize(playerid, PlayerStatus[playerid][14], 633.830200, 0.000000);
    PlayerTextDrawAlignment(playerid, PlayerStatus[playerid][14], 1);
    PlayerTextDrawUseBox(playerid, PlayerStatus[playerid][14], 1);
    PlayerTextDrawBoxColor(playerid, PlayerStatus[playerid][14], -106);

    PlayerStatus[playerid][15] = CreatePlayerTextDraw(playerid, 577.499877, 360.801300, "box");
    PlayerTextDrawLetterSize(playerid, PlayerStatus[playerid][15], 0.000000, 1.139001);
    PlayerTextDrawTextSize(playerid, PlayerStatus[playerid][15], 633.830200, 0.000000);
    PlayerTextDrawAlignment(playerid, PlayerStatus[playerid][15], 1);
    PlayerTextDrawUseBox(playerid, PlayerStatus[playerid][15], 1);
    PlayerTextDrawBoxColor(playerid, PlayerStatus[playerid][15], -106);

    PlayerStatus[playerid][16] = CreatePlayerTextDraw(playerid, 577.499877, 380.202484, "box");
    PlayerTextDrawLetterSize(playerid, PlayerStatus[playerid][16], 0.000000, 1.139001);
    PlayerTextDrawTextSize(playerid, PlayerStatus[playerid][16], 633.830200, 0.000000);
    PlayerTextDrawAlignment(playerid, PlayerStatus[playerid][16], 1);
    PlayerTextDrawUseBox(playerid, PlayerStatus[playerid][16], 1);
    PlayerTextDrawBoxColor(playerid, PlayerStatus[playerid][16], -106);

    PlayerStatus[playerid][17] = CreatePlayerTextDraw(playerid, 577.499877, 399.303649, "box");
    PlayerTextDrawLetterSize(playerid, PlayerStatus[playerid][17], 0.000000, 1.139001);
    PlayerTextDrawTextSize(playerid, PlayerStatus[playerid][17], 633.830200, 0.000000);
    PlayerTextDrawAlignment(playerid, PlayerStatus[playerid][17], 1);
    PlayerTextDrawUseBox(playerid, PlayerStatus[playerid][17], 1);
    PlayerTextDrawBoxColor(playerid, PlayerStatus[playerid][17], -106);

    PlayerStatus[playerid][18] = CreatePlayerTextDraw(playerid, 577.499877, 418.404815, "box");
    PlayerTextDrawLetterSize(playerid, PlayerStatus[playerid][18], 0.000000, 1.139001);
    PlayerTextDrawTextSize(playerid, PlayerStatus[playerid][18], 633.830200, 0.000000);
    PlayerTextDrawAlignment(playerid, PlayerStatus[playerid][18], 1);
    PlayerTextDrawUseBox(playerid, PlayerStatus[playerid][18], 1);
    PlayerTextDrawBoxColor(playerid, PlayerStatus[playerid][18], -106);

    PlayerStatus[playerid][19] = CreatePlayerTextDraw(playerid, 562.000000, 285.200012, "Status");
    PlayerTextDrawLetterSize(playerid, PlayerStatus[playerid][19], 0.400000, 1.600000);
    PlayerTextDrawAlignment(playerid, PlayerStatus[playerid][19], 1);
    PlayerTextDrawColor(playerid, PlayerStatus[playerid][19], -2139062017);
    PlayerTextDrawSetShadow(playerid, PlayerStatus[playerid][19], 1);
    PlayerTextDrawSetOutline(playerid, PlayerStatus[playerid][19], 1);
    PlayerTextDrawBackgroundColor(playerid, PlayerStatus[playerid][19], 61);
    PlayerTextDrawFont(playerid, PlayerStatus[playerid][19], 0);
    PlayerTextDrawSetProportional(playerid, PlayerStatus[playerid][19], 1);
    PlayerTextDrawSetShadow(playerid, PlayerStatus[playerid][19], 1);

    PlayerStatus[playerid][20] = CreatePlayerTextDraw(playerid, 598.600097, 302.655731, "");
    PlayerTextDrawLetterSize(playerid, PlayerStatus[playerid][20], 0.331000, 1.130000);
    PlayerTextDrawAlignment(playerid, PlayerStatus[playerid][20], 2);
    PlayerTextDrawColor(playerid, PlayerStatus[playerid][20], -1);
    PlayerTextDrawSetShadow(playerid, PlayerStatus[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, PlayerStatus[playerid][20], -1);
    PlayerTextDrawBackgroundColor(playerid, PlayerStatus[playerid][20], 255);
    PlayerTextDrawFont(playerid, PlayerStatus[playerid][20], 3);
    PlayerTextDrawSetProportional(playerid, PlayerStatus[playerid][20], 1);
    PlayerTextDrawSetShadow(playerid, PlayerStatus[playerid][20], 0);

    PlayerStatus[playerid][21] = CreatePlayerTextDraw(playerid, 597.096435, 319.744506, "0");
    PlayerTextDrawLetterSize(playerid, PlayerStatus[playerid][21], 0.399000, 1.600000);
    PlayerTextDrawAlignment(playerid, PlayerStatus[playerid][21], 2);
    PlayerTextDrawColor(playerid, PlayerStatus[playerid][21], -1);
    PlayerTextDrawSetShadow(playerid, PlayerStatus[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, PlayerStatus[playerid][21], -1);
    PlayerTextDrawBackgroundColor(playerid, PlayerStatus[playerid][21], 255);
    PlayerTextDrawFont(playerid, PlayerStatus[playerid][21], 3);
    PlayerTextDrawSetProportional(playerid, PlayerStatus[playerid][21], 1);
    PlayerTextDrawSetShadow(playerid, PlayerStatus[playerid][21], 0);

    PlayerStatus[playerid][22] = CreatePlayerTextDraw(playerid, 558.999877, 318.977905, "");
    PlayerTextDrawLetterSize(playerid, PlayerStatus[playerid][22], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PlayerStatus[playerid][22], 16.000000, 17.000000);
    PlayerTextDrawAlignment(playerid, PlayerStatus[playerid][22], 1);
    PlayerTextDrawColor(playerid, PlayerStatus[playerid][22], -1);
    PlayerTextDrawSetShadow(playerid, PlayerStatus[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, PlayerStatus[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerStatus[playerid][22], 0);
    PlayerTextDrawFont(playerid, PlayerStatus[playerid][22], 5);
    PlayerTextDrawSetProportional(playerid, PlayerStatus[playerid][22], 0);
    PlayerTextDrawSetShadow(playerid, PlayerStatus[playerid][22], 0);
    PlayerTextDrawSetPreviewModel(playerid, PlayerStatus[playerid][22], 1247);
    PlayerTextDrawSetPreviewRot(playerid, PlayerStatus[playerid][22], 0.000000, 0.000000, 0.000000, 1.000000);

    PlayerStatus[playerid][23] = CreatePlayerTextDraw(playerid, 558.999877, 338.179077, "");
    PlayerTextDrawLetterSize(playerid, PlayerStatus[playerid][23], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PlayerStatus[playerid][23], 16.000000, 17.000000);
    PlayerTextDrawAlignment(playerid, PlayerStatus[playerid][23], 1);
    PlayerTextDrawColor(playerid, PlayerStatus[playerid][23], -1);
    PlayerTextDrawSetShadow(playerid, PlayerStatus[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, PlayerStatus[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerStatus[playerid][23], 0);
    PlayerTextDrawFont(playerid, PlayerStatus[playerid][23], 5);
    PlayerTextDrawSetProportional(playerid, PlayerStatus[playerid][23], 0);
    PlayerTextDrawSetShadow(playerid, PlayerStatus[playerid][23], 0);
    PlayerTextDrawSetPreviewModel(playerid, PlayerStatus[playerid][23], 2880);
    PlayerTextDrawSetPreviewRot(playerid, PlayerStatus[playerid][23], 0.000000, 0.000000, 0.000000, 1.000000);

    PlayerStatus[playerid][24] = CreatePlayerTextDraw(playerid, 558.999877, 357.580261, "");
    PlayerTextDrawLetterSize(playerid, PlayerStatus[playerid][24], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PlayerStatus[playerid][24], 16.000000, 17.000000);
    PlayerTextDrawAlignment(playerid, PlayerStatus[playerid][24], 1);
    PlayerTextDrawColor(playerid, PlayerStatus[playerid][24], -1);
    PlayerTextDrawSetShadow(playerid, PlayerStatus[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, PlayerStatus[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerStatus[playerid][24], 0);
    PlayerTextDrawFont(playerid, PlayerStatus[playerid][24], 5);
    PlayerTextDrawSetProportional(playerid, PlayerStatus[playerid][24], 0);
    PlayerTextDrawSetShadow(playerid, PlayerStatus[playerid][24], 0);
    PlayerTextDrawSetPreviewModel(playerid, PlayerStatus[playerid][24], 1484);
    PlayerTextDrawSetPreviewRot(playerid, PlayerStatus[playerid][24], 0.000000, 0.000000, 0.000000, 1.000000);

    PlayerStatus[playerid][25] = CreatePlayerTextDraw(playerid, 558.999877, 376.581420, "");
    PlayerTextDrawLetterSize(playerid, PlayerStatus[playerid][25], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PlayerStatus[playerid][25], 16.000000, 17.000000);
    PlayerTextDrawAlignment(playerid, PlayerStatus[playerid][25], 1);
    PlayerTextDrawColor(playerid, PlayerStatus[playerid][25], -1);
    PlayerTextDrawSetShadow(playerid, PlayerStatus[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, PlayerStatus[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerStatus[playerid][25], 0);
    PlayerTextDrawFont(playerid, PlayerStatus[playerid][25], 5);
    PlayerTextDrawSetProportional(playerid, PlayerStatus[playerid][25], 0);
    PlayerTextDrawSetShadow(playerid, PlayerStatus[playerid][25], 0);
    PlayerTextDrawSetPreviewModel(playerid, PlayerStatus[playerid][25], 14866);
    PlayerTextDrawSetPreviewRot(playerid, PlayerStatus[playerid][25], 0.000000, 0.000000, 0.000000, 1.000000);

    PlayerStatus[playerid][26] = CreatePlayerTextDraw(playerid, 551.499389, 371.911193, "");
    PlayerTextDrawLetterSize(playerid, PlayerStatus[playerid][26], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PlayerStatus[playerid][26], 32.000000, 64.000000);
    PlayerTextDrawAlignment(playerid, PlayerStatus[playerid][26], 1);
    PlayerTextDrawColor(playerid, PlayerStatus[playerid][26], -1);
    PlayerTextDrawSetShadow(playerid, PlayerStatus[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, PlayerStatus[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerStatus[playerid][26], 0);
    PlayerTextDrawFont(playerid, PlayerStatus[playerid][26], 5);
    PlayerTextDrawSetProportional(playerid, PlayerStatus[playerid][26], 0);
    PlayerTextDrawSetShadow(playerid, PlayerStatus[playerid][26], 0);
    PlayerTextDrawSetPreviewModel(playerid, PlayerStatus[playerid][26], 1665);
    PlayerTextDrawSetPreviewRot(playerid, PlayerStatus[playerid][26], 0.000000, 0.000000, 0.000000, 1.000000);

    PlayerStatus[playerid][27] = CreatePlayerTextDraw(playerid, 559.199523, 414.600250, "");
    PlayerTextDrawLetterSize(playerid, PlayerStatus[playerid][27], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PlayerStatus[playerid][27], 15.000000, 17.000000);
    PlayerTextDrawAlignment(playerid, PlayerStatus[playerid][27], 1);
    PlayerTextDrawColor(playerid, PlayerStatus[playerid][27], -1);
    PlayerTextDrawSetShadow(playerid, PlayerStatus[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, PlayerStatus[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerStatus[playerid][27], 0);
    PlayerTextDrawFont(playerid, PlayerStatus[playerid][27], 5);
    PlayerTextDrawSetProportional(playerid, PlayerStatus[playerid][27], 0);
    PlayerTextDrawSetShadow(playerid, PlayerStatus[playerid][27], 0);
    PlayerTextDrawSetPreviewModel(playerid, PlayerStatus[playerid][27], 1240);
    PlayerTextDrawSetPreviewRot(playerid, PlayerStatus[playerid][27], 0.000000, 0.000000, 0.000000, 1.000000);

    PlayerStatus[playerid][28] = CreatePlayerTextDraw(playerid, 561.500854, 432.500152, "www.vidabrasileira.forumeiros.com");
    PlayerTextDrawLetterSize(playerid, PlayerStatus[playerid][28], 0.117500, 1.017333);
    PlayerTextDrawAlignment(playerid, PlayerStatus[playerid][28], 1);
    PlayerTextDrawColor(playerid, PlayerStatus[playerid][28], -1);
    PlayerTextDrawSetShadow(playerid, PlayerStatus[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, PlayerStatus[playerid][28], 1);
    PlayerTextDrawBackgroundColor(playerid, PlayerStatus[playerid][28], 255);
    PlayerTextDrawFont(playerid, PlayerStatus[playerid][28], 1);
    PlayerTextDrawSetProportional(playerid, PlayerStatus[playerid][28], 1);
    PlayerTextDrawSetShadow(playerid, PlayerStatus[playerid][28], 0);
    return 1;
}

hook OnPlayerSpawn(playerid)
{
    StatusMostrar(playerid);
    return 1;
}


StatusMostrar(playerid)
{
    for(new i=0; i < 28; i++){
        PlayerTextDrawShow(playerid, PlayerStatus[playerid][i]);
    }
    return 1;
}

StatusOcultar(playerid)
{
    for(new i=0; i < 28; i++){
        PlayerTextDrawHide(playerid, PlayerStatus[playerid][i]);
    }
    return 1;
}
