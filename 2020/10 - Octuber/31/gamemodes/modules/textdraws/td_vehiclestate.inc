new PlayerText:PlayerVehicleStatus[MAX_PLAYERS][5];
new PlayerText:VehicleStatus[MAX_PLAYERS][5];

new bool:stateVehicle[MAX_PLAYERS];

stock TDVehicleBarStatus(playerid)
{
    VehicleStatus[playerid][0] = CreatePlayerTextDraw(playerid, 389.0, 421.029327, "I");
    PlayerTextDrawLetterSize(playerid, VehicleStatus[playerid][0], 24.945632, 2.982496);
    PlayerTextDrawAlignment(playerid, VehicleStatus[playerid][0], 1);
    PlayerTextDrawColor(playerid, VehicleStatus[playerid][0], 200);
    PlayerTextDrawSetShadow(playerid, VehicleStatus[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, VehicleStatus[playerid][0], -1);
    PlayerTextDrawBackgroundColor(playerid, VehicleStatus[playerid][0], 0);
    PlayerTextDrawFont(playerid, VehicleStatus[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, VehicleStatus[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, VehicleStatus[playerid][0], 0);

    VehicleStatus[playerid][1] = CreatePlayerTextDraw(playerid, 389.0, 403.728271, "I");
    PlayerTextDrawLetterSize(playerid, VehicleStatus[playerid][1], 24.945632, 2.982496);
    PlayerTextDrawAlignment(playerid, VehicleStatus[playerid][1], 1);
    PlayerTextDrawColor(playerid, VehicleStatus[playerid][1], 200);
    PlayerTextDrawSetShadow(playerid, VehicleStatus[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, VehicleStatus[playerid][1], -1);
    PlayerTextDrawBackgroundColor(playerid, VehicleStatus[playerid][1], 0);
    PlayerTextDrawFont(playerid, VehicleStatus[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, VehicleStatus[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, VehicleStatus[playerid][1], 0);

    VehicleStatus[playerid][2] = CreatePlayerTextDraw(playerid, 389.0, 386.327209, "I");
    PlayerTextDrawLetterSize(playerid, VehicleStatus[playerid][2], 24.945632, 2.982496);
    PlayerTextDrawAlignment(playerid, VehicleStatus[playerid][2], 1);
    PlayerTextDrawColor(playerid, VehicleStatus[playerid][2], 200);
    PlayerTextDrawSetShadow(playerid, VehicleStatus[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, VehicleStatus[playerid][2], -1);
    PlayerTextDrawBackgroundColor(playerid, VehicleStatus[playerid][2], 0);
    PlayerTextDrawFont(playerid, VehicleStatus[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, VehicleStatus[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, VehicleStatus[playerid][2], 0);

    VehicleStatus[playerid][3] = CreatePlayerTextDraw(playerid, 389.0, 369.226165, "I");
    PlayerTextDrawLetterSize(playerid, VehicleStatus[playerid][3], 24.945632, 2.982496);
    PlayerTextDrawAlignment(playerid, VehicleStatus[playerid][3], 1);
    PlayerTextDrawColor(playerid, VehicleStatus[playerid][3], 200);
    PlayerTextDrawSetShadow(playerid, VehicleStatus[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, VehicleStatus[playerid][3], -1);
    PlayerTextDrawBackgroundColor(playerid, VehicleStatus[playerid][3], 0);
    PlayerTextDrawFont(playerid, VehicleStatus[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, VehicleStatus[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, VehicleStatus[playerid][3], 0);

    VehicleStatus[playerid][4] = CreatePlayerTextDraw(playerid, (IsPlayerMobile(playerid) ? (450.1) : (520.1)), 396.664794, "KM/H");
    PlayerTextDrawLetterSize(playerid, VehicleStatus[playerid][4], 0.186249, 0.939166);
    PlayerTextDrawAlignment(playerid, VehicleStatus[playerid][4], 2);
    PlayerTextDrawColor(playerid, VehicleStatus[playerid][4], -16776961);
    PlayerTextDrawSetShadow(playerid, VehicleStatus[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, VehicleStatus[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleStatus[playerid][4], 255);
    PlayerTextDrawFont(playerid, VehicleStatus[playerid][4], 2);
    PlayerTextDrawSetProportional(playerid, VehicleStatus[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, VehicleStatus[playerid][4], 0);

    PlayerVehicleStatus[playerid][0] = CreatePlayerTextDraw(playerid, (IsPlayerMobile(playerid) ? (471.1) : (541.1)), 429.266784, "N/A");
    PlayerTextDrawLetterSize(playerid, PlayerVehicleStatus[playerid][0], 0.316249, 1.209166);
    PlayerTextDrawAlignment(playerid, PlayerVehicleStatus[playerid][0], 2);
    PlayerTextDrawColor(playerid, PlayerVehicleStatus[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, PlayerVehicleStatus[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, PlayerVehicleStatus[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerVehicleStatus[playerid][0], 255);
    PlayerTextDrawFont(playerid, PlayerVehicleStatus[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, PlayerVehicleStatus[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, PlayerVehicleStatus[playerid][0], 0);

    PlayerVehicleStatus[playerid][1] = CreatePlayerTextDraw(playerid, (IsPlayerMobile(playerid) ? (471.1) : (541.1)), 411.865722, "N/A");
    PlayerTextDrawLetterSize(playerid, PlayerVehicleStatus[playerid][1], 0.316249, 1.209166);
    PlayerTextDrawAlignment(playerid, PlayerVehicleStatus[playerid][1], 2);
    PlayerTextDrawColor(playerid, PlayerVehicleStatus[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, PlayerVehicleStatus[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, PlayerVehicleStatus[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerVehicleStatus[playerid][1], 255);
    PlayerTextDrawFont(playerid, PlayerVehicleStatus[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, PlayerVehicleStatus[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, PlayerVehicleStatus[playerid][1], 0);

    PlayerVehicleStatus[playerid][2] = CreatePlayerTextDraw(playerid, (IsPlayerMobile(playerid) ? (427.0) : (497.0)), 394.764678, "N/A");
    PlayerTextDrawLetterSize(playerid, PlayerVehicleStatus[playerid][2], 0.316249, 1.209166);
    PlayerTextDrawAlignment(playerid, PlayerVehicleStatus[playerid][2], 2);
    PlayerTextDrawColor(playerid, PlayerVehicleStatus[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, PlayerVehicleStatus[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, PlayerVehicleStatus[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerVehicleStatus[playerid][2], 255);
    PlayerTextDrawFont(playerid, PlayerVehicleStatus[playerid][2], 2);
    PlayerTextDrawSetProportional(playerid, PlayerVehicleStatus[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, PlayerVehicleStatus[playerid][2], 0);

    PlayerVehicleStatus[playerid][3] = CreatePlayerTextDraw(playerid, (IsPlayerMobile(playerid) ? (499.1) : (569.1)), 396.664794, "N/A");
    PlayerTextDrawLetterSize(playerid, PlayerVehicleStatus[playerid][3], 0.186249, 0.939166);
    PlayerTextDrawAlignment(playerid, PlayerVehicleStatus[playerid][3], 2);
    PlayerTextDrawColor(playerid, PlayerVehicleStatus[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, PlayerVehicleStatus[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, PlayerVehicleStatus[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerVehicleStatus[playerid][3], 255);
    PlayerTextDrawFont(playerid, PlayerVehicleStatus[playerid][3], 2);
    PlayerTextDrawSetProportional(playerid, PlayerVehicleStatus[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, PlayerVehicleStatus[playerid][3], 0);

    PlayerVehicleStatus[playerid][4] = CreatePlayerTextDraw(playerid, (IsPlayerMobile(playerid) ? (471.8) : (541.8)), 378.930297, "N/A");
    PlayerTextDrawLetterSize(playerid, PlayerVehicleStatus[playerid][4], 0.316249, 1.209166);
    PlayerTextDrawAlignment(playerid, PlayerVehicleStatus[playerid][4], 2);
    PlayerTextDrawColor(playerid, PlayerVehicleStatus[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, PlayerVehicleStatus[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, PlayerVehicleStatus[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, PlayerVehicleStatus[playerid][4], 255);
    PlayerTextDrawFont(playerid, PlayerVehicleStatus[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, PlayerVehicleStatus[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, PlayerVehicleStatus[playerid][4], 0);
	return 1;
}

stock ShowPlayerVelocimetro(playerid)
{
    for(new textid = 0; textid < 5; textid++)
    {
        PlayerTextDrawShow(playerid, PlayerVehicleStatus[playerid][textid]);
        PlayerTextDrawShow(playerid, VehicleStatus[playerid][textid]);
    }

    UpdatePlayerVelocimetro(playerid);

    stateVehicle[playerid] = true;
	return 1;
}

stock HidePlayerVelocimetro(playerid)
{
    for(new textid = 0; textid < 5; textid++)
    {
        PlayerTextDrawHide(playerid, PlayerVehicleStatus[playerid][textid]);
        PlayerTextDrawHide(playerid, VehicleStatus[playerid][textid]);
    }

    stateVehicle[playerid] = false;
	return 1;
}

