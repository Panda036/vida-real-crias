#include YSI\y_hooks

new Text:TDConcessionaire[6];
new PlayerText:TDPlayerConcessionaire[MAX_PLAYERS][8];

hook OnGameModeInit()
{
    TDConcessionaire[0] = TextDrawCreate(182.000000, 123.733772, "box");
    TextDrawLetterSize(TDConcessionaire[0], 0.000000, 16.200008);
    TextDrawTextSize(TDConcessionaire[0], 458.000000, 0.000000);
    TextDrawAlignment(TDConcessionaire[0], 1);
    TextDrawColor(TDConcessionaire[0], -1);
    TextDrawUseBox(TDConcessionaire[0], 1);
    TextDrawBoxColor(TDConcessionaire[0], -2147483393);
    TextDrawSetShadow(TDConcessionaire[0], 0);
    TextDrawSetOutline(TDConcessionaire[0], 0);
    TextDrawBackgroundColor(TDConcessionaire[0], 255);
    TextDrawFont(TDConcessionaire[0], 1);
    TextDrawSetProportional(TDConcessionaire[0], 1);
    TextDrawSetShadow(TDConcessionaire[0], 0);

    TDConcessionaire[1] = TextDrawCreate(184.700164, 137.634292, "box");
    TextDrawLetterSize(TDConcessionaire[1], 0.000000, 14.312436);
    TextDrawTextSize(TDConcessionaire[1], 454.574188, 0.000000);
    TextDrawAlignment(TDConcessionaire[1], 1);
    TextDrawColor(TDConcessionaire[1], -1);
    TextDrawUseBox(TDConcessionaire[1], 1);
    TextDrawBoxColor(TDConcessionaire[1], 150);
    TextDrawSetShadow(TDConcessionaire[1], 0);
    TextDrawSetOutline(TDConcessionaire[1], 0);
    TextDrawBackgroundColor(TDConcessionaire[1], 255);
    TextDrawFont(TDConcessionaire[1], 1);
    TextDrawSetProportional(TDConcessionaire[1], 1);
    TextDrawSetShadow(TDConcessionaire[1], 0);

    TDConcessionaire[2] = TextDrawCreate(192.000000, 145.200027, "Nome:");
    TextDrawLetterSize(TDConcessionaire[2], 0.271000, 1.053998);
    TextDrawAlignment(TDConcessionaire[2], 1);
    TextDrawColor(TDConcessionaire[2], -1);
    TextDrawSetShadow(TDConcessionaire[2], 0);
    TextDrawSetOutline(TDConcessionaire[2], -1);
    TextDrawBackgroundColor(TDConcessionaire[2], 255);
    TextDrawFont(TDConcessionaire[2], 1);
    TextDrawSetProportional(TDConcessionaire[2], 1);
    TextDrawSetShadow(TDConcessionaire[2], 0);

    TDConcessionaire[3] = TextDrawCreate(192.000000, 173.301742, "Categoria:");
    TextDrawLetterSize(TDConcessionaire[3], 0.271000, 1.053998);
    TextDrawAlignment(TDConcessionaire[3], 1);
    TextDrawColor(TDConcessionaire[3], -1);
    TextDrawSetShadow(TDConcessionaire[3], 0);
    TextDrawSetOutline(TDConcessionaire[3], -1);
    TextDrawBackgroundColor(TDConcessionaire[3], 255);
    TextDrawFont(TDConcessionaire[3], 1);
    TextDrawSetProportional(TDConcessionaire[3], 1);
    TextDrawSetShadow(TDConcessionaire[3], 0);

    TDConcessionaire[4] = TextDrawCreate(192.000000, 200.103378, "Custo:");
    TextDrawLetterSize(TDConcessionaire[4], 0.271000, 1.053998);
    TextDrawAlignment(TDConcessionaire[4], 1);
    TextDrawColor(TDConcessionaire[4], -1);
    TextDrawSetShadow(TDConcessionaire[4], 0);
    TextDrawSetOutline(TDConcessionaire[4], -1);
    TextDrawBackgroundColor(TDConcessionaire[4], 255);
    TextDrawFont(TDConcessionaire[4], 1);
    TextDrawSetProportional(TDConcessionaire[4], 1);
    TextDrawSetShadow(TDConcessionaire[4], 0);

    TDConcessionaire[5] = TextDrawCreate(193.799835, 242.666625, "box");
    TextDrawLetterSize(TDConcessionaire[5], 0.000000, 1.550000);
    TextDrawTextSize(TDConcessionaire[5], 250.299835, 0.000000);
    TextDrawAlignment(TDConcessionaire[5], 1);
    TextDrawColor(TDConcessionaire[5], -1);
    TextDrawUseBox(TDConcessionaire[5], 1);
    TextDrawBoxColor(TDConcessionaire[5], 8388863);
    TextDrawSetShadow(TDConcessionaire[5], 0);
    TextDrawSetOutline(TDConcessionaire[5], 0);
    TextDrawBackgroundColor(TDConcessionaire[5], 255);
    TextDrawFont(TDConcessionaire[5], 1);
    TextDrawSetProportional(TDConcessionaire[5], 1);
    TextDrawSetShadow(TDConcessionaire[5], 0);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    TDPlayerConcessionaire[playerid][0] = CreatePlayerTextDraw(playerid, 443.600128, 123.866661, "LD_BEAT:cross");
    PlayerTextDrawLetterSize(playerid, TDPlayerConcessionaire[playerid][0], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, TDPlayerConcessionaire[playerid][0], 11.590013, 9.380031);
    PlayerTextDrawAlignment(playerid, TDPlayerConcessionaire[playerid][0], 1);
    PlayerTextDrawColor(playerid, TDPlayerConcessionaire[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerConcessionaire[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerConcessionaire[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerConcessionaire[playerid][0], 255);
    PlayerTextDrawFont(playerid, TDPlayerConcessionaire[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, TDPlayerConcessionaire[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, TDPlayerConcessionaire[playerid][0], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerConcessionaire[playerid][0], true);

    TDPlayerConcessionaire[playerid][1] = CreatePlayerTextDraw(playerid, 300.600769, 135.212432, "");
    PlayerTextDrawLetterSize(playerid, TDPlayerConcessionaire[playerid][1], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, TDPlayerConcessionaire[playerid][1], 122.000000, 104.000000);
    PlayerTextDrawAlignment(playerid, TDPlayerConcessionaire[playerid][1], 1);
    PlayerTextDrawColor(playerid, TDPlayerConcessionaire[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerConcessionaire[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerConcessionaire[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerConcessionaire[playerid][1], 0);
    PlayerTextDrawFont(playerid, TDPlayerConcessionaire[playerid][1], 5);
    PlayerTextDrawSetProportional(playerid, TDPlayerConcessionaire[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, TDPlayerConcessionaire[playerid][1], 0);
    PlayerTextDrawSetPreviewModel(playerid, TDPlayerConcessionaire[playerid][1], 451);
    PlayerTextDrawSetPreviewRot(playerid, TDPlayerConcessionaire[playerid][1], -10.000000, 0.000000, -30.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, TDPlayerConcessionaire[playerid][1], 1, 1);

    TDPlayerConcessionaire[playerid][2] = CreatePlayerTextDraw(playerid, 224.500000, 145.666702, "Turismo");
    PlayerTextDrawLetterSize(playerid, TDPlayerConcessionaire[playerid][2], 0.271000, 1.053998);
    PlayerTextDrawAlignment(playerid, TDPlayerConcessionaire[playerid][2], 1);
    PlayerTextDrawColor(playerid, TDPlayerConcessionaire[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerConcessionaire[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerConcessionaire[playerid][2], -1);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerConcessionaire[playerid][2], 255);
    PlayerTextDrawFont(playerid, TDPlayerConcessionaire[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, TDPlayerConcessionaire[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerConcessionaire[playerid][2], 0);

    TDPlayerConcessionaire[playerid][3] = CreatePlayerTextDraw(playerid, 239.500915, 173.768417, "Esportes");
    PlayerTextDrawLetterSize(playerid, TDPlayerConcessionaire[playerid][3], 0.271000, 1.053998);
    PlayerTextDrawAlignment(playerid, TDPlayerConcessionaire[playerid][3], 1);
    PlayerTextDrawColor(playerid, TDPlayerConcessionaire[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerConcessionaire[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerConcessionaire[playerid][3], -1);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerConcessionaire[playerid][3], 255);
    PlayerTextDrawFont(playerid, TDPlayerConcessionaire[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, TDPlayerConcessionaire[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerConcessionaire[playerid][3], 0);

    TDPlayerConcessionaire[playerid][4] = CreatePlayerTextDraw(playerid, 221.999847, 200.270034, "Custo");
    PlayerTextDrawLetterSize(playerid, TDPlayerConcessionaire[playerid][4], 0.271000, 1.053998);
    PlayerTextDrawAlignment(playerid, TDPlayerConcessionaire[playerid][4], 1);
    PlayerTextDrawColor(playerid, TDPlayerConcessionaire[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerConcessionaire[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerConcessionaire[playerid][4], -1);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerConcessionaire[playerid][4], 255);
    PlayerTextDrawFont(playerid, TDPlayerConcessionaire[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, TDPlayerConcessionaire[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerConcessionaire[playerid][4], 0);

    TDPlayerConcessionaire[playerid][5] = CreatePlayerTextDraw(playerid, 203.100006, 243.366683, "Comprar");
    PlayerTextDrawLetterSize(playerid, TDPlayerConcessionaire[playerid][5], 0.281000, 1.184666);
    PlayerTextDrawAlignment(playerid, TDPlayerConcessionaire[playerid][5], 1);
    PlayerTextDrawColor(playerid, TDPlayerConcessionaire[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerConcessionaire[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerConcessionaire[playerid][5], -1);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerConcessionaire[playerid][5], 255);
    PlayerTextDrawFont(playerid, TDPlayerConcessionaire[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, TDPlayerConcessionaire[playerid][5], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerConcessionaire[playerid][5], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerConcessionaire[playerid][5], true);
    PlayerTextDrawTextSize(playerid, TDPlayerConcessionaire[playerid][5], 240.000000, 11.000000);

    TDPlayerConcessionaire[playerid][6] = CreatePlayerTextDraw(playerid, 324.900939, 243.033508, "LD_BEAT:left");
    PlayerTextDrawLetterSize(playerid, TDPlayerConcessionaire[playerid][6], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, TDPlayerConcessionaire[playerid][6], 20.000000, 12.300006);
    PlayerTextDrawAlignment(playerid, TDPlayerConcessionaire[playerid][6], 1);
    PlayerTextDrawColor(playerid, TDPlayerConcessionaire[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerConcessionaire[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerConcessionaire[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerConcessionaire[playerid][6], 255);
    PlayerTextDrawFont(playerid, TDPlayerConcessionaire[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, TDPlayerConcessionaire[playerid][6], 0);
    PlayerTextDrawSetShadow(playerid, TDPlayerConcessionaire[playerid][6], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerConcessionaire[playerid][6], true);

    TDPlayerConcessionaire[playerid][7] = CreatePlayerTextDraw(playerid, 373.703948, 243.033508, "LD_BEAT:right");
    PlayerTextDrawLetterSize(playerid, TDPlayerConcessionaire[playerid][7], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, TDPlayerConcessionaire[playerid][7], 20.000000, 12.300006);
    PlayerTextDrawAlignment(playerid, TDPlayerConcessionaire[playerid][7], 1);
    PlayerTextDrawColor(playerid, TDPlayerConcessionaire[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerConcessionaire[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerConcessionaire[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerConcessionaire[playerid][7], 255);
    PlayerTextDrawFont(playerid, TDPlayerConcessionaire[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, TDPlayerConcessionaire[playerid][7], 0);
    PlayerTextDrawSetShadow(playerid, TDPlayerConcessionaire[playerid][7], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerConcessionaire[playerid][7], true);
    return 1;
}

stock ShowTDConcessionaire(playerid)
{
    SelectTextDraw(playerid, Green);

    switch(LocationConcessionaire[playerid])
    {
        case 1..3: ShoppingVehicle[playerid] = 0;
        case 4: ShoppingVehicle[playerid] = 125;
        case 5: ShoppingVehicle[playerid] = 133;
    }

    PlayerTextDrawSetString(playerid, TDPlayerConcessionaire[playerid][2], getVehicleName(ShoppingConcessionaire[ShoppingVehicle[playerid]][sc_model]));
    PlayerTextDrawSetString(playerid, TDPlayerConcessionaire[playerid][3], ShoppingConcessionaire[ShoppingVehicle[playerid]][sc_category]);
    PlayerTextDrawSetString(playerid, TDPlayerConcessionaire[playerid][4], IsMoney(ShoppingConcessionaire[ShoppingVehicle[playerid]][sc_price], "."));
    PlayerTextDrawSetPreviewModel(playerid, TDPlayerConcessionaire[playerid][1], ShoppingConcessionaire[ShoppingVehicle[playerid]][sc_model]);


    for(new i = 0; i < 8; i++)
    {
        PlayerTextDrawShow(playerid, TDPlayerConcessionaire[playerid][i]);
    }
    for(new i = 0; i < 6; i++)
    {
        TextDrawShowForPlayer(playerid, TDConcessionaire[i]);
    }
    return 1;
}

stock HideTDConcessionaire(playerid)
{
    CancelSelectTextDraw(playerid);

    for(new i = 0; i < 8; i++)
    {
        PlayerTextDrawHide(playerid, TDPlayerConcessionaire[playerid][i]);
    }
    for(new i = 0; i < 6; i++)
    {
        TextDrawHideForPlayer(playerid, TDConcessionaire[i]);
    }
    return 1;
}
