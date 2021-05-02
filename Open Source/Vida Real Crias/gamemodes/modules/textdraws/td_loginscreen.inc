#include YSI\y_hooks

new Text:TDLogin[7];
new PlayerText:TDPlayerLogin[MAX_PLAYERS][4];

new Text:TDRegister[8];
new PlayerText:TDPlayerRegister[MAX_PLAYERS][5];

hook OnGameModeInit()
{
    TDLogin[0] = TextDrawCreate(253.923736, 160.833450, "box");
    TextDrawLetterSize(TDLogin[0], 0.000000, 2.072364);
    TextDrawTextSize(TDLogin[0], 383.000000, 0.000000);
    TextDrawAlignment(TDLogin[0], 1);
    TextDrawColor(TDLogin[0], -1);
    TextDrawUseBox(TDLogin[0], 1);
    TextDrawBoxColor(TDLogin[0], 100);
    TextDrawSetShadow(TDLogin[0], 0);
    TextDrawSetOutline(TDLogin[0], 0);
    TextDrawBackgroundColor(TDLogin[0], 255);
    TextDrawFont(TDLogin[0], 1);
    TextDrawSetProportional(TDLogin[0], 1);
    TextDrawSetShadow(TDLogin[0], 0);

    TDLogin[1] = TextDrawCreate(253.923736, 186.134994, "box");
    TextDrawLetterSize(TDLogin[1], 0.000000, 2.072364);
    TextDrawTextSize(TDLogin[1], 383.000000, 0.000000);
    TextDrawAlignment(TDLogin[1], 1);
    TextDrawColor(TDLogin[1], -1);
    TextDrawUseBox(TDLogin[1], 1);
    TextDrawBoxColor(TDLogin[1], 100);
    TextDrawSetShadow(TDLogin[1], 0);
    TextDrawSetOutline(TDLogin[1], 0);
    TextDrawBackgroundColor(TDLogin[1], 255);
    TextDrawFont(TDLogin[1], 1);
    TextDrawSetProportional(TDLogin[1], 1);
    TextDrawSetShadow(TDLogin[1], 0);

    TDLogin[2] = TextDrawCreate(254.392257, 223.437271, "box");
    TextDrawLetterSize(TDLogin[2], 0.000000, 2.072364);
    TextDrawTextSize(TDLogin[2], 383.000000, 0.000000);
    TextDrawAlignment(TDLogin[2], 1);
    TextDrawColor(TDLogin[2], -1);
    TextDrawUseBox(TDLogin[2], 1);
    TextDrawBoxColor(TDLogin[2], -2147483498);
    TextDrawSetShadow(TDLogin[2], 0);
    TextDrawSetOutline(TDLogin[2], 0);
    TextDrawBackgroundColor(TDLogin[2], 255);
    TextDrawFont(TDLogin[2], 2);
    TextDrawSetProportional(TDLogin[2], 1);
    TextDrawSetShadow(TDLogin[2], 0);

    TDLogin[3] = TextDrawCreate(253.092102, 209.833343, "Nšo_tem_conta?");
    TextDrawLetterSize(TDLogin[3], 0.239297, 0.911665);
    TextDrawAlignment(TDLogin[3], 1);
    TextDrawColor(TDLogin[3], -1);
    TextDrawSetShadow(TDLogin[3], 0);
    TextDrawSetOutline(TDLogin[3], 0);
    TextDrawBackgroundColor(TDLogin[3], 255);
    TextDrawFont(TDLogin[3], 1);
    TextDrawSetProportional(TDLogin[3], 1);
    TextDrawSetShadow(TDLogin[3], 0);

    TDLogin[4] = TextDrawCreate(252.212783, 131.100036, "Vida_Real_Crias");
    TextDrawLetterSize(TDLogin[4], 0.487284, 2.720000);
    TextDrawAlignment(TDLogin[4], 1);
    TextDrawColor(TDLogin[4], -1);
    TextDrawSetShadow(TDLogin[4], 0);
    TextDrawSetOutline(TDLogin[4], 1);
    TextDrawBackgroundColor(TDLogin[4], 255);
    TextDrawFont(TDLogin[4], 3);
    TextDrawSetProportional(TDLogin[4], 1);
    TextDrawSetShadow(TDLogin[4], 0);

    #if EVENT_CHRISTMAS
    TDLogin[5] = TextDrawCreate(376.476318, 130.733444, "X");
    TextDrawLetterSize(TDLogin[5], 0.014874, 0.024999);
    TextDrawAlignment(TDLogin[5], 1);
    TextDrawColor(TDLogin[5], -2147450625);
    TextDrawSetShadow(TDLogin[5], 0);
    TextDrawSetOutline(TDLogin[5], 1);
    TextDrawBackgroundColor(TDLogin[5], 255);
    TextDrawFont(TDLogin[5], 3);
    TextDrawSetProportional(TDLogin[5], 1);
    TextDrawSetShadow(TDLogin[5], 0);

    TDLogin[6] = TextDrawCreate(322.628295, 97.249984, "");
    TextDrawLetterSize(TDLogin[6], 0.000000, 0.000000);
    TextDrawTextSize(TDLogin[6], 90.000000, 90.000000);
    TextDrawAlignment(TDLogin[6], 1);
    TextDrawColor(TDLogin[6], -56);
    TextDrawSetShadow(TDLogin[6], 0);
    TextDrawSetOutline(TDLogin[6], 0);
    TextDrawBackgroundColor(TDLogin[6], -256);
    TextDrawFont(TDLogin[6], 5);
    TextDrawSetProportional(TDLogin[6], 0);
    TextDrawSetShadow(TDLogin[6], 0);
    TextDrawSetPreviewModel(TDLogin[6], CHRISTMAS_HAT);
    TextDrawSetPreviewRot(TDLogin[6], 0.000000, 0.000000, 0.000000, 1.000000);
    #endif

    TDRegister[0] = TextDrawCreate(253.923736, 143.532394, "box");
    TextDrawLetterSize(TDRegister[0], 0.000000, 2.072364);
    TextDrawTextSize(TDRegister[0], 383.000000, 0.000000);
    TextDrawAlignment(TDRegister[0], 1);
    TextDrawColor(TDRegister[0], -1);
    TextDrawUseBox(TDRegister[0], 1);
    TextDrawBoxColor(TDRegister[0], 100);
    TextDrawSetShadow(TDRegister[0], 0);
    TextDrawSetOutline(TDRegister[0], 0);
    TextDrawBackgroundColor(TDRegister[0], 255);
    TextDrawFont(TDRegister[0], 1);
    TextDrawSetProportional(TDRegister[0], 1);
    TextDrawSetShadow(TDRegister[0], 0);

    TDRegister[1] = TextDrawCreate(253.923736, 169.733993, "box");
    TextDrawLetterSize(TDRegister[1], 0.000000, 2.072364);
    TextDrawTextSize(TDRegister[1], 383.000000, 0.000000);
    TextDrawAlignment(TDRegister[1], 1);
    TextDrawColor(TDRegister[1], -1);
    TextDrawUseBox(TDRegister[1], 1);
    TextDrawBoxColor(TDRegister[1], 100);
    TextDrawSetShadow(TDRegister[1], 0);
    TextDrawSetOutline(TDRegister[1], 0);
    TextDrawBackgroundColor(TDRegister[1], 255);
    TextDrawFont(TDRegister[1], 1);
    TextDrawSetProportional(TDRegister[1], 1);
    TextDrawSetShadow(TDRegister[1], 0);

    TDRegister[2] = TextDrawCreate(253.923736, 195.235549, "box");
    TextDrawLetterSize(TDRegister[2], 0.000000, 2.072364);
    TextDrawTextSize(TDRegister[2], 383.000000, 0.000000);
    TextDrawAlignment(TDRegister[2], 1);
    TextDrawColor(TDRegister[2], -1);
    TextDrawUseBox(TDRegister[2], 1);
    TextDrawBoxColor(TDRegister[2], 100);
    TextDrawSetShadow(TDRegister[2], 0);
    TextDrawSetOutline(TDRegister[2], 0);
    TextDrawBackgroundColor(TDRegister[2], 255);
    TextDrawFont(TDRegister[2], 1);
    TextDrawSetProportional(TDRegister[2], 1);
    TextDrawSetShadow(TDRegister[2], 0);

    TDRegister[3] = TextDrawCreate(253.923736, 220.737106, "box");
    TextDrawLetterSize(TDRegister[3], 0.000000, 2.072364);
    TextDrawTextSize(TDRegister[3], 383.000000, 0.000000);
    TextDrawAlignment(TDRegister[3], 1);
    TextDrawColor(TDRegister[3], -1);
    TextDrawUseBox(TDRegister[3], 1);
    TextDrawBoxColor(TDRegister[3], 100);
    TextDrawSetShadow(TDRegister[3], 0);
    TextDrawSetOutline(TDRegister[3], 0);
    TextDrawBackgroundColor(TDRegister[3], 255);
    TextDrawFont(TDRegister[3], 1);
    TextDrawSetProportional(TDRegister[3], 1);
    TextDrawSetShadow(TDRegister[3], 0);

    TDRegister[4] = TextDrawCreate(253.923736, 251.138961, "box");
    TextDrawLetterSize(TDRegister[4], 0.000000, 2.072364);
    TextDrawTextSize(TDRegister[4], 383.000000, 0.000000);
    TextDrawAlignment(TDRegister[4], 1);
    TextDrawColor(TDRegister[4], -1);
    TextDrawUseBox(TDRegister[4], 1);
    TextDrawBoxColor(TDRegister[4], 8388758);
    TextDrawSetShadow(TDRegister[4], 0);
    TextDrawSetOutline(TDRegister[4], 0);
    TextDrawBackgroundColor(TDRegister[4], 255);
    TextDrawFont(TDRegister[4], 1);
    TextDrawSetProportional(TDRegister[4], 1);
    TextDrawSetShadow(TDRegister[4], 0);

    TDRegister[5] = TextDrawCreate(252.244262, 115.750030, "VIDA_REAL_CRIAS");
    TextDrawLetterSize(TDRegister[5], 0.492766, 2.387500);
    TextDrawAlignment(TDRegister[5], 1);
    TextDrawColor(TDRegister[5], -1);
    TextDrawSetShadow(TDRegister[5], 0);
    TextDrawSetOutline(TDRegister[5], 1);
    TextDrawBackgroundColor(TDRegister[5], 255);
    TextDrawFont(TDRegister[5], 3);
    TextDrawSetProportional(TDRegister[5], 1);
    TextDrawSetShadow(TDRegister[5], 0);

    #if EVENT_CHRISTMAS
    TDRegister[6] = TextDrawCreate(387.795104, 108.449943, "x");
    TextDrawLetterSize(TDRegister[6], 0.037363, 0.048331);
    TextDrawAlignment(TDRegister[6], 3);
    TextDrawColor(TDRegister[6], -2139094785);
    TextDrawSetShadow(TDRegister[6], 0);
    TextDrawSetOutline(TDRegister[6], 1);
    TextDrawBackgroundColor(TDRegister[6], 255);
    TextDrawFont(TDRegister[6], 1);
    TextDrawSetProportional(TDRegister[6], 1);
    TextDrawSetShadow(TDRegister[6], 0);

    TDRegister[7] = TextDrawCreate(324.033843, 78.583351, "");
    TextDrawLetterSize(TDRegister[7], 0.000000, 0.000000);
    TextDrawTextSize(TDRegister[7], 90.000000, 90.000000);
    TextDrawAlignment(TDRegister[7], 1);
    TextDrawColor(TDRegister[7], -56);
    TextDrawSetShadow(TDRegister[7], 0);
    TextDrawSetOutline(TDRegister[7], 0);
    TextDrawBackgroundColor(TDRegister[7], -256);
    TextDrawFont(TDRegister[7], 5);
    TextDrawSetProportional(TDRegister[7], 0);
    TextDrawSetShadow(TDRegister[7], 0);
    TextDrawSetPreviewModel(TDRegister[7], CHRISTMAS_HAT);
    TextDrawSetPreviewRot(TDRegister[7], 0.000000, 0.000000, 20.000000, 1.000000);
    #endif
    return 1;
}

hook OnPlayerConnect(playerid)
{
    TDPlayerLogin[playerid][0] = CreatePlayerTextDraw(playerid, 318.197601, 164.050033, "CLIQUE_AQUI_PARA_DIGITAR_SEU_NOME");
    PlayerTextDrawLetterSize(playerid, TDPlayerLogin[playerid][0], 0.148872, 1.174165);
    PlayerTextDrawAlignment(playerid, TDPlayerLogin[playerid][0], 2);
    PlayerTextDrawColor(playerid, TDPlayerLogin[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerLogin[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerLogin[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerLogin[playerid][0], 255);
    PlayerTextDrawFont(playerid, TDPlayerLogin[playerid][0], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerLogin[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerLogin[playerid][0], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerLogin[playerid][0], true);
    PlayerTextDrawTextSize(playerid, TDPlayerLogin[playerid][0], 8.000000, 110.000000);

    TDPlayerLogin[playerid][1] = CreatePlayerTextDraw(playerid, 318.197601, 188.951553, "CLIQUE_AQUI_PARA_COLOCAR_SUA_SENHA");
    PlayerTextDrawLetterSize(playerid, TDPlayerLogin[playerid][1], 0.148872, 1.174165);
    PlayerTextDrawAlignment(playerid, TDPlayerLogin[playerid][1], 2);
    PlayerTextDrawColor(playerid, TDPlayerLogin[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerLogin[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerLogin[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerLogin[playerid][1], 255);
    PlayerTextDrawFont(playerid, TDPlayerLogin[playerid][1], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerLogin[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerLogin[playerid][1], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerLogin[playerid][1], true);
    PlayerTextDrawTextSize(playerid, TDPlayerLogin[playerid][1], 9.000000, 120.000000);

    TDPlayerLogin[playerid][2] = CreatePlayerTextDraw(playerid, 319.896179, 208.833282, "Registrar-se");
    PlayerTextDrawLetterSize(playerid, TDPlayerLogin[playerid][2], 0.228294, 1.065832);
    PlayerTextDrawAlignment(playerid, TDPlayerLogin[playerid][2], 1);
    PlayerTextDrawColor(playerid, TDPlayerLogin[playerid][2], 8388863);
    PlayerTextDrawSetShadow(playerid, TDPlayerLogin[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerLogin[playerid][2], 1);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerLogin[playerid][2], 255);
    PlayerTextDrawFont(playerid, TDPlayerLogin[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, TDPlayerLogin[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerLogin[playerid][2], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerLogin[playerid][2], true);
    PlayerTextDrawTextSize(playerid, TDPlayerLogin[playerid][2], 370.000000, 10.000000);

    TDPlayerLogin[playerid][3] = CreatePlayerTextDraw(playerid, 305.866790, 225.399566, "Entrar");
    PlayerTextDrawLetterSize(playerid, TDPlayerLogin[playerid][3], 0.269282, 1.349166);
    PlayerTextDrawAlignment(playerid, TDPlayerLogin[playerid][3], 1);
    PlayerTextDrawColor(playerid, TDPlayerLogin[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerLogin[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerLogin[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerLogin[playerid][3], 255);
    PlayerTextDrawFont(playerid, TDPlayerLogin[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, TDPlayerLogin[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerLogin[playerid][3], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerLogin[playerid][3], true);
    PlayerTextDrawTextSize(playerid, TDPlayerLogin[playerid][3], 330.000000, 10.000000);

    TDPlayerRegister[playerid][0] = CreatePlayerTextDraw(playerid, 316.890563, 147.416656, "CLIQUE_AQUI_PARA_COLOCAR_SEU_NOME");
    PlayerTextDrawLetterSize(playerid, TDPlayerRegister[playerid][0], 0.121229, 1.086665);
    PlayerTextDrawAlignment(playerid, TDPlayerRegister[playerid][0], 2);
    PlayerTextDrawColor(playerid, TDPlayerRegister[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerRegister[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerRegister[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerRegister[playerid][0], 255);
    PlayerTextDrawFont(playerid, TDPlayerRegister[playerid][0], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerRegister[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerRegister[playerid][0], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerRegister[playerid][0], true);
    PlayerTextDrawTextSize(playerid, TDPlayerRegister[playerid][0], 9.000000, 100.000000);

    TDPlayerRegister[playerid][1] = CreatePlayerTextDraw(playerid, 316.890563, 172.818206, "CLIQUE_AQUI_PARA_COLOCAR_SUA_SENHA");
    PlayerTextDrawLetterSize(playerid, TDPlayerRegister[playerid][1], 0.121229, 1.086665);
    PlayerTextDrawAlignment(playerid, TDPlayerRegister[playerid][1], 2);
    PlayerTextDrawColor(playerid, TDPlayerRegister[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerRegister[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerRegister[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerRegister[playerid][1], 255);
    PlayerTextDrawFont(playerid, TDPlayerRegister[playerid][1], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerRegister[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerRegister[playerid][1], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerRegister[playerid][1], true);
    PlayerTextDrawTextSize(playerid, TDPlayerRegister[playerid][1], 9.000000, 100.000000);

    TDPlayerRegister[playerid][2] = CreatePlayerTextDraw(playerid, 316.890563, 198.319763, "CLIQUE_AQUI_PARA_CONFIRMA_SUA_SENHA");
    PlayerTextDrawLetterSize(playerid, TDPlayerRegister[playerid][2], 0.121229, 1.086665);
    PlayerTextDrawAlignment(playerid, TDPlayerRegister[playerid][2], 2);
    PlayerTextDrawColor(playerid, TDPlayerRegister[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerRegister[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerRegister[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerRegister[playerid][2], 255);
    PlayerTextDrawFont(playerid, TDPlayerRegister[playerid][2], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerRegister[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerRegister[playerid][2], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerRegister[playerid][2], true);
    PlayerTextDrawTextSize(playerid, TDPlayerRegister[playerid][2], 9.000000, 100.000000);

    TDPlayerRegister[playerid][3] = CreatePlayerTextDraw(playerid, 316.890563, 224.121337, "CLIQUE_AQUI_PARA_COLOCAR_SEU_EMAIL");
    PlayerTextDrawLetterSize(playerid, TDPlayerRegister[playerid][3], 0.121229, 1.086665);
    PlayerTextDrawAlignment(playerid, TDPlayerRegister[playerid][3], 2);
    PlayerTextDrawColor(playerid, TDPlayerRegister[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerRegister[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerRegister[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerRegister[playerid][3], 255);
    PlayerTextDrawFont(playerid, TDPlayerRegister[playerid][3], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerRegister[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerRegister[playerid][3], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerRegister[playerid][3], true);
    PlayerTextDrawTextSize(playerid, TDPlayerRegister[playerid][3], 9.000000, 100.000000);

    TDPlayerRegister[playerid][4] = CreatePlayerTextDraw(playerid, 294.233215, 252.816665, "Registrar-se");
    PlayerTextDrawLetterSize(playerid, TDPlayerRegister[playerid][4], 0.256163, 1.459998);
    PlayerTextDrawAlignment(playerid, TDPlayerRegister[playerid][4], 1);
    PlayerTextDrawColor(playerid, TDPlayerRegister[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerRegister[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerRegister[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerRegister[playerid][4], 255);
    PlayerTextDrawFont(playerid, TDPlayerRegister[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, TDPlayerRegister[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerRegister[playerid][4], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerRegister[playerid][4], true);
    PlayerTextDrawTextSize(playerid, TDPlayerRegister[playerid][4], 345.000000, 10.000000);
    return 1;
}

stock ShowTextDrawLogin(playerid)
{
    for(new i = 0; i < 4; ++i){
        PlayerTextDrawShow(playerid, TDPlayerLogin[playerid][i]); //Pro player
    }
    for(new i = 0; i < 7; ++i)
    {
        if(i >= 5 && !EVENT_CHRISTMAS) continue;

        TextDrawShowForPlayer(playerid, TDLogin[i]); //Global
    }
    return 1;
}

stock ShowTextDrawRegister(playerid)
{
    for(new i = 0; i < 5; ++i){
        PlayerTextDrawShow(playerid, TDPlayerRegister[playerid][i]); //Pro player
    }
    for(new i = 0; i < 8; ++i)
    {
        if(i >= 6 && !EVENT_CHRISTMAS) continue;

        TextDrawShowForPlayer(playerid, TDRegister[i]); //Global
    }
    return 1;
}

stock HideTextDrawLogin(playerid)
{
    for(new i = 0; i < 4; ++i){
        PlayerTextDrawHide(playerid, TDPlayerLogin[playerid][i]); //Pro player
    }
    for(new i = 0; i < 7; ++i)
    {
        if(i >= 5 && !EVENT_CHRISTMAS) continue;

        TextDrawHideForPlayer(playerid, TDLogin[i]); //Global
    }
    return 1;
}

stock HideTextDrawRegister(playerid)
{
    for(new i = 0; i < 5; ++i){
        PlayerTextDrawHide(playerid, TDPlayerRegister[playerid][i]); //Pro player
    }
    for(new i = 0; i < 8; ++i)
    {
        if(i >= 6 && !EVENT_CHRISTMAS) continue;

        TextDrawHideForPlayer(playerid, TDRegister[i]); //Global
    }
    return 1;
}
