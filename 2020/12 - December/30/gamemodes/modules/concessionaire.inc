#include YSI\y_hooks

hook OnGameModeInit()
{
    CreateDynamicMapIcon(542.1480, -1292.0358, 17.2422, 16, -1, -1, -1, -1, 200.0);
    CreateDynamicMapIcon(2200.8438, 1393.8828, 11.0625, 16, -1, -1, -1, -1, 200.0);
    CreateDynamicMapIcon(-1966.3959, 293.9593, 35.4688, 16, -1, -1, -1, -1, 200.0);
    CreateDynamicMapIcon(411.1825, 2533.5020, 19.1484, 16, -1, -1, -1, -1, 200.0);
    CreateDynamicMapIcon(-2184.9480, 2413.0244, 5.1563, 16, -1, -1, -1, -1, 200.0);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    LocationConcessionaire[playerid] = 0;
    ShoppingVehicle[playerid] = 0;
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(PRESSED(KEY_YES))
    {
        if(!VehicleMenuEmptySpace(playerid))
            return SendClientMessage(playerid, Erro, "Atingido o limite de veículos");

        if(IsPlayerInConcessionaire(playerid))
            return ShowTDConcessionaire(playerid);

        return 1;
    }
	return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == main_concessionaire && response)
    {
        new VehiclieIDList[MAX_PLAYERS];

        VehiclieIDList[playerid] = ShoppingVehicle[playerid];

        if(PlayerInfo[playerid][Dinheiro] < ShoppingConcessionaire[VehiclieIDList[playerid]][sc_price])
            return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

        for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
        {
            if(!DataVehicles[slot][playerid][vmodel])
            {
                DataVehicles[slot][playerid][vmodel] = ShoppingConcessionaire[VehiclieIDList[playerid]][sc_model];
                format(DataVehicles[slot][playerid][vmessage], 30, "N/A");
                format(DataVehicles[slot][playerid][vplate], 30, "BCM-2020");
                DataVehicles[slot][playerid][vlife] = 1000.0;
                DataVehicles[slot][playerid][vdevaluation] = ShoppingConcessionaire[VehiclieIDList[playerid]][sc_devaluation];

                switch(LocationConcessionaire[playerid])
                {
                    case 1: {
                        DataVehicles[slot][playerid][vx] = 555.5782;
                        DataVehicles[slot][playerid][vy] = -1285.4679;
                        DataVehicles[slot][playerid][vz] = 18.3237;
                        DataVehicles[slot][playerid][va] = 0.0000;
                        DataVehicles[slot][playerid][vgasoline] = 60;
                    }
                    case 2: {
                        DataVehicles[slot][playerid][vx] = 2165.4084;
                        DataVehicles[slot][playerid][vy] = 1411.4419;
                        DataVehicles[slot][playerid][vz] = 11.9518;
                        DataVehicles[slot][playerid][va] = 90.0000;
                        DataVehicles[slot][playerid][vgasoline] = 60;
                    }
                    case 3: {
                        DataVehicles[slot][playerid][vx] = -1986.8801;
                        DataVehicles[slot][playerid][vy] = 269.9831;
                        DataVehicles[slot][playerid][vz] = 36.2939;
                        DataVehicles[slot][playerid][va] = 90.0000;
                        DataVehicles[slot][playerid][vgasoline] = 60;
                    }
                    case 4: {
                        DataVehicles[slot][playerid][vx] = 416.2171;
                        DataVehicles[slot][playerid][vy] = 2502.7700;
                        DataVehicles[slot][playerid][vz] = 20.6202;
                        DataVehicles[slot][playerid][va] = 90.0000;
                        DataVehicles[slot][playerid][vgasoline] = 400;
                    }
                    case 5: {
                        DataVehicles[slot][playerid][vx] = -2205.8254;
                        DataVehicles[slot][playerid][vy] = 2422.5042;
                        DataVehicles[slot][playerid][vz] = 5.3000;
                        DataVehicles[slot][playerid][va] = 45.0000;
                        DataVehicles[slot][playerid][vgasoline] = 100;
                    }
                }

                PlayerInfo[playerid][Dinheiro] -= ShoppingConcessionaire[VehiclieIDList[playerid]][sc_price];
                UpdatePlayerMoney(playerid);

                new query[400];
                mysql_format(IDConexao, query, 400, "INSERT INTO `Vehicles` (`slot`, `model`, `x`, `y`, `z`, `a`, `devaluation`, `gasoline`, `id_contas`) VALUES ('%d', '%d', '%f', '%f', '%f', '%f', '%d', '%d', '%d')", slot,
                DataVehicles[slot][playerid][vmodel],
                DataVehicles[slot][playerid][vx],
                DataVehicles[slot][playerid][vy],
                DataVehicles[slot][playerid][vz],
                DataVehicles[slot][playerid][va],
                DataVehicles[slot][playerid][vdevaluation],
                DataVehicles[slot][playerid][vgasoline],
                PlayerInfo[playerid][ID]);
                mysql_query(IDConexao, query);

                HideTDConcessionaire(playerid);
                LocationConcessionaire[playerid] = 0;
                return 1;
            }
        }
        return 1;
    }
    return 1;
}

stock ClickTextDrawConcessionaire(playerid, PlayerText:playertextid)
{
    if(playertextid == TDPlayerConcessionaire[playerid][0]) //closed
    {
        HideTDConcessionaire(playerid);
        return 1;
    }
    if(playertextid == TDPlayerConcessionaire[playerid][5]) //purchase
    {
        format(String, sizeof(String), "{FFFFFF}Nome do veículo: %s\nCusto: %s\nDesvalorização: %s\n\n{FF4000}Obs: o seu veículo precisará ser conectado!", getVehicleName(ShoppingConcessionaire[ShoppingVehicle[playerid]][sc_model]), IsMoney(ShoppingConcessionaire[ShoppingVehicle[playerid]][sc_price], "."), IsMoney(ShoppingConcessionaire[ShoppingVehicle[playerid]][sc_devaluation], "."));
        ShowPlayerDialog(playerid, main_concessionaire, DIALOG_STYLE_MSGBOX, "{FF0000}Comprar veículo", String, "Comprar", "Cancelar");
        return 1;
    }
    if(playertextid == TDPlayerConcessionaire[playerid][6]) //left
    {
        if(LocationConcessionaire[playerid] == 1 || LocationConcessionaire[playerid] == 2 || LocationConcessionaire[playerid] == 3)
        {
            if(ShoppingVehicle[playerid] == 0)
                return SendClientMessage(playerid, Erro, "Não tem mais veículos");
        }
        if(LocationConcessionaire[playerid] == 4)
        {
            if(ShoppingVehicle[playerid] == 125)
                return SendClientMessage(playerid, Erro, "Não tem mais veículos");
        }
        if(LocationConcessionaire[playerid] == 5)
        {
            if(ShoppingVehicle[playerid] == 133)
                return SendClientMessage(playerid, Erro, "Não tem mais veículos");
        }

        ShoppingVehicle[playerid]--;

        PlayerTextDrawSetString(playerid, TDPlayerConcessionaire[playerid][2], getVehicleName(ShoppingConcessionaire[ShoppingVehicle[playerid]][sc_model]));
        PlayerTextDrawShow(playerid, TDPlayerConcessionaire[playerid][2]);

        PlayerTextDrawSetString(playerid, TDPlayerConcessionaire[playerid][3], ShoppingConcessionaire[ShoppingVehicle[playerid]][sc_category]);
        PlayerTextDrawShow(playerid, TDPlayerConcessionaire[playerid][3]);

        PlayerTextDrawSetString(playerid, TDPlayerConcessionaire[playerid][4], IsMoney(ShoppingConcessionaire[ShoppingVehicle[playerid]][sc_price], "."));
        PlayerTextDrawShow(playerid, TDPlayerConcessionaire[playerid][4]);

        PlayerTextDrawSetPreviewModel(playerid, TDPlayerConcessionaire[playerid][1], ShoppingConcessionaire[ShoppingVehicle[playerid]][sc_model]);
        PlayerTextDrawShow(playerid, TDPlayerConcessionaire[playerid][1]);
        return 1;
    }
    if(playertextid == TDPlayerConcessionaire[playerid][7]) //right
    {
        if(LocationConcessionaire[playerid] == 1 || LocationConcessionaire[playerid] == 2 || LocationConcessionaire[playerid] == 3)
        {
            if(ShoppingVehicle[playerid] == 124)
                return SendClientMessage(playerid, Erro, "Não tem mais veículos");
        }
        if(LocationConcessionaire[playerid] == 4)
        {
            if(ShoppingVehicle[playerid] == 132)
                return SendClientMessage(playerid, Erro, "Não tem mais veículos");
        }
        if(LocationConcessionaire[playerid] == 5)
        {
            if(ShoppingVehicle[playerid] == 139)
                return SendClientMessage(playerid, Erro, "Não tem mais veículos");
        }

        ShoppingVehicle[playerid]++;

        PlayerTextDrawSetString(playerid, TDPlayerConcessionaire[playerid][2], getVehicleName(ShoppingConcessionaire[ShoppingVehicle[playerid]][sc_model]));
        PlayerTextDrawShow(playerid, TDPlayerConcessionaire[playerid][2]);

        PlayerTextDrawSetString(playerid, TDPlayerConcessionaire[playerid][3], ShoppingConcessionaire[ShoppingVehicle[playerid]][sc_category]);
        PlayerTextDrawShow(playerid, TDPlayerConcessionaire[playerid][3]);

        format(String, sizeof(String), "$%s", IsMoney(ShoppingConcessionaire[ShoppingVehicle[playerid]][sc_price], "."));
        PlayerTextDrawSetString(playerid, TDPlayerConcessionaire[playerid][4], String);
        PlayerTextDrawShow(playerid, TDPlayerConcessionaire[playerid][4]);

        PlayerTextDrawSetPreviewModel(playerid, TDPlayerConcessionaire[playerid][1], ShoppingConcessionaire[ShoppingVehicle[playerid]][sc_model]);
        PlayerTextDrawShow(playerid, TDPlayerConcessionaire[playerid][1]);
        return 1;
    }
    return 1;
}

stock IsPlayerInConcessionaire(playerid)
{
    if(IsPlayerInConceLS(playerid)) return 1;
    else if(IsPlayerInConceLV(playerid)) return 1;
    else if(IsPlayerInConceSF(playerid)) return 1;
    else if(IsPlayerInConceAbandoned(playerid)) return 1;
    else if(IsPlayerInConceBayside(playerid)) return 1;
    return 0;
}

stock IsPlayerInConceLS(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 542.1480, -1292.0358, 17.2422)){
        LocationConcessionaire[playerid] = 1;
        return 1;
    }
    return 0;
}

stock IsPlayerInConceLV(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2200.8438, 1393.8828, 11.0625)){
        LocationConcessionaire[playerid] = 2;
        return 1;
    }
    return 0;
}

stock IsPlayerInConceSF(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -1966.3959, 293.9593, 35.4688)){
        LocationConcessionaire[playerid] = 3;
        return 1;
    }
    return 0;
}

stock IsPlayerInConceAbandoned(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 411.1825, 2533.5020, 19.1484)){
        LocationConcessionaire[playerid] = 4;
        return 1;
    }
    return 0;
}

stock IsPlayerInConceBayside(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -2184.9480, 2413.0244, 5.1563)){
        LocationConcessionaire[playerid] = 5;
        return 1;
    }
    return 0;
}
