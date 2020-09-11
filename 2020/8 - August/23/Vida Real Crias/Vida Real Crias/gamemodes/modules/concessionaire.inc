#include YSI\y_hooks

#define MAIN_CONCESSIONAIRE_SHOP    5059

new ShoppingVehicle[MAX_PLAYERS] = 0;
new LocationConcessionaire[MAX_PLAYERS] = 0;

enum e_sc
{
    sc_category[30],
    sc_model,
    sc_price,
    sc_devaluation
};

new ShoppingConcessionaire[140][e_sc] =
{
    {"Off Road", 400, 45000, 40500}, //Terrestres
    {"Saloons", 401, 20000, 18000},
    {"Sport Vehicles", 402, 25000, 22500},
    {"Industrial", 403, 220000, 198000},
    {"Station Wagons", 404, 28000, 25200},
    {"Saloons", 405, 23000, 20700},
    {"Industrial", 408, 60000, 54000},
    {"Unique Vehicles", 409, 110000, 99000},
    {"Saloons", 410, 16000, 14400},
    {"Sport Vehicles", 411, 200000, 180000},
    {"Sport Vehicles", 412, 42000, 37800},
    {"Industrial", 413, 50000, 45000},
    {"Industrial", 414, 55000, 49500},
    {"Sport Vehicles", 415, 40000, 36000},
    {"Station Wagons", 418, 61000, 54900},
    {"Saloons", 419, 34000, 30600},
    {"Saloons", 421, 28000, 25200},
    {"Industrial", 422, 42000, 37800},
    {"Off Road", 424, 12000, 10800},
    {"Saloons", 426, 19000, 17100},
    {"Sport Vehicles", 429, 50000, 45000},
    {"Public Service", 431, 330000, 297000},
    {"Unique Vehicles", 434, 53000, 47700},
    {"Saloons", 436, 22000, 19800},
    {"Public Service", 437, 350000, 315000},
    {"Convertibles", 439, 21000, 18900},
    {"Industrial", 440, 38000, 34200},
    {"Unique Vehicles", 442, 18000, 16200},
    {"Industrial", 443, 150000, 135000},
    {"Off Road", 444, 81000, 72900},
    {"Saloons", 445, 15000, 13500},
    {"Sport Vehicles", 451, 190000, 171000},
    {"Industrial", 455, 80000, 72000},
    {"Industrial", 456, 70000, 63000},
    {"Station Wagons", 458, 32000, 28800},
    {"Industrial", 459, 48000, 43200},
    {"Bikes", 461, 15000, 13500},
    {"Bikes", 462, 4000, 3600},
    {"Bikes", 463, 50000, 45000},
    {"Saloons", 466, 34000, 30600},
    {"Saloons", 467, 38000, 34200},
    {"Bikes", 468, 8000, 7200},
    {"Bikes", 471, 10000, 9000},
    {"Saloons", 474, 33000, 29700},
    {"Sport Vehicles", 475, 30000, 27000},
    {"Sport Vehicles", 477, 150000, 135000},
    {"Industrial", 478, 32000, 28800},
    {"Station Wagons", 479, 28000, 25200},
    {"Convertibles", 480, 20000, 18000},
    {"Bikes", 481, 500, 450},
    {"Industrial", 482, 58000, 52200},
    {"Unique Vehicles", 483, 28000, 25200},
    {"Off Road", 489, 54000, 48600},
    {"Saloons", 491, 38000, 34200},
    {"Saloons", 492, 31000, 27900},
    {"Sport Vehicles", 494, 160000, 144000},
    {"Off Road", 495, 83000, 74700},
    {"Sport Vehicles", 496, 16000, 14400},
    {"Industrial", 498, 68000, 61200},
    {"Industrial", 499, 56000, 50400},
    {"Off Road", 500, 40000, 36000},
    {"Sport Vehicles", 502, 162000, 145800},
    {"Sport Vehicles", 503, 154000, 138600},
    {"Saloons", 504, 30000, 27000},
    {"Off Road", 505, 52000, 46800},
    {"Sport Vehicles", 506, 80000, 72000},
    {"Saloons", 507, 29000, 26100},
    {"Unique Vehicles", 508, 110000, 99000},
    {"Bikes", 509, 300, 270},
    {"Bikes", 510, 800, 720},
    {"Industrial", 514, 210000, 189000},
    {"Industrial", 515, 230000, 207000},
    {"Saloons", 516, 20000, 18000},
    {"Saloons", 517, 22000, 19800},
    {"Saloons", 518, 31000, 27900},
    {"Bikes", 521, 20000, 18000},
    {"Bikes", 522, 80000, 72000},
    {"Industrial", 524, 84000, 75600},
    {"Unique Vehicles", 525, 66000, 59400},
    {"Saloons", 526, 20000, 18000},
    {"Saloons", 527, 19000, 17100},
    {"Saloons", 529, 23000, 20700},
    {"Convertibles", 533, 22000, 19800},
    {"Lowriders", 534, 48000, 43200},
    {"Lowriders", 535, 64000, 57600},
    {"Lowriders", 536, 32000, 28800},
    {"Saloons", 540, 25000, 22500},
    {"Sport Vehicles", 541, 180000, 162000},
    {"Saloons", 542, 12000, 10800},
    {"Industrial", 543, 31000, 27900},
    {"Unique Vehicles", 545, 47000, 42300},
    {"Saloons", 546, 28000, 25200},
    {"Saloons", 547, 20000, 18000},
    {"Saloons", 549, 18000, 16200},
    {"Saloons", 550, 38000, 34200},
    {"Saloons", 551, 30000, 27000},
    {"Industrial", 554, 45000, 40500},
    {"Convertibles", 555, 56000, 50400},
    {"Off Road", 556, 85000, 76500},
    {"Off Road", 557, 88000, 79200},
    {"Sport Vehicles", 558, 33000, 29700},
    {"Sport Vehicles", 559, 24000, 21600},
    {"Saloons", 560, 53000, 47700},
    {"Station Wagons", 561, 33000, 29700},
    {"Saloons", 562, 62000, 55800},
    {"Sport Vehicles", 565, 30000, 27000},
    {"Lowriders", 566, 26000, 23400},
    {"Lowriders", 567, 50000, 45000},
    {"Off Road", 568, 18000, 16200},
    {"Unique Vehicles", 571, 14000, 12600},
    {"Off Road", 573, 140000, 126000},
    {"Lowriders", 575, 28000, 25200},
    {"Lowriders", 576, 45000, 40500},
    {"Industrial", 578, 112000, 100800},
    {"Off Road", 579, 30000, 27000},
    {"Saloons", 580, 300000, 27000},
    {"Bikes", 581, 18000, 16200},
    {"Saloons", 585, 27000, 24300},
    {"Bikes", 586, 25000, 22500},
    {"Sport Vehicles", 587, 43000, 38700},
    {"Sport Vehicles", 589, 30000, 27000},
    {"Industrial", 600, 38000, 34200},
    {"Sport Vehicles", 602, 53000, 47700},
    {"Sport Vehicles", 603, 82000, 73800},
    {"Industrial", 609, 72000, 64800}, //124

    {"Helicopters", 417, 230000, 207000}, //Aérios
    {"Sparrow", 447, 180000, 162000},
    {"Helicopters", 487, 220000, 198000},
    {"Airplane", 511, 200000, 180000},
    {"Airplane", 512, 130000, 117000},
    {"Airplane", 513, 160000, 144000},
    {"Airplane", 519, 1500000, 1350000},
    {"Airplane", 593, 100000, 90000}, //132

    {"Boats", 446, 220000, 198000}, //Aquaticos
    {"Boats", 452, 180000, 162000},
    {"Boats", 454, 300000, 270000},
    {"Boats", 460, 105000, 94500},
    {"Boats", 473, 10000, 9000},
    {"Boats", 484, 230000, 207000},
    {"Boats", 493, 240000, 216000} //139
};

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
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 542.1480, -1292.0358, 17.2422))
        {
            if(!HaveEmptyVehicleMenuSlots(playerid))
                return SendClientMessage(playerid, Erro, "Todos o seus slots de veículos estão cheios");

            LocationConcessionaire[playerid] = 1;

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

            ShowTDConcessionaire(playerid);
            return 1;
        }
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 2200.8438, 1393.8828, 11.0625))
        {
            if(!HaveEmptyVehicleMenuSlots(playerid))
                return SendClientMessage(playerid, Erro, "Todos o seus slots de veículos estão cheios");

            LocationConcessionaire[playerid] = 2;

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

            ShowTDConcessionaire(playerid);
            return 1;
        }
        if(IsPlayerInRangeOfPoint(playerid, 2.0, -1966.3959, 293.9593, 35.4688))
        {
            if(!HaveEmptyVehicleMenuSlots(playerid))
                return SendClientMessage(playerid, Erro, "Todos o seus slots de veículos estão cheios");

            LocationConcessionaire[playerid] = 3;

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

            ShowTDConcessionaire(playerid);
            return 1;
        }
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 411.1825, 2533.5020, 19.1484))
        {
            if(!HaveEmptyVehicleMenuSlots(playerid))
                return SendClientMessage(playerid, Erro, "Todos o seus slots de veículos estão cheios");

            LocationConcessionaire[playerid] = 4;

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

            ShowTDConcessionaire(playerid);
            return 1;
        }
        if(IsPlayerInRangeOfPoint(playerid, 2.0, -2184.9480, 2413.0244, 5.1563))
        {
            if(!HaveEmptyVehicleMenuSlots(playerid))
                return SendClientMessage(playerid, Erro, "Todos o seus slots de veículos estão cheios");

            LocationConcessionaire[playerid] = 5;

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

            ShowTDConcessionaire(playerid);
            return 1;
        }
        return 1;
    }
	return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == MAIN_CONCESSIONAIRE_SHOP && response)
    {
        new VehiclieIDList[MAX_PLAYERS];

        VehiclieIDList[playerid] = ShoppingVehicle[playerid];

        if(PlayerInfo[playerid][Dinheiro] < ShoppingConcessionaire[VehiclieIDList[playerid]][sc_price])
            return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

        for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
        {
            if(!DataVehicles[slot][playerid][vmodel])
            {
                DataVehicles[slot][playerid][vvehicle] = 0;
                DataVehicles[slot][playerid][vmodel] = ShoppingConcessionaire[VehiclieIDList[playerid]][sc_model];
                format(DataVehicles[slot][playerid][vmessage], 30, "N/A");
                format(DataVehicles[slot][playerid][vplate], 30, "BCM-2020");
                DataVehicles[slot][playerid][vlock] = false;
                DataVehicles[slot][playerid][vlife] = 1000.0;
                DataVehicles[slot][playerid][vdevaluation] = ShoppingConcessionaire[VehiclieIDList[playerid]][sc_devaluation];
                DataVehicles[slot][playerid][vconnected] = false;

                if(LocationConcessionaire[playerid] == 1)
                {
                    DataVehicles[slot][playerid][vx] = 555.5782;
                    DataVehicles[slot][playerid][vy] = -1285.4679;
                    DataVehicles[slot][playerid][vz] = 18.3237;
                    DataVehicles[slot][playerid][va] = 0.0000;
                    DataVehicles[slot][playerid][vgasoline] = 60;
                }
                if(LocationConcessionaire[playerid] == 2)
                {
                    DataVehicles[slot][playerid][vx] = 2165.4084;
                    DataVehicles[slot][playerid][vy] = 1411.4419;
                    DataVehicles[slot][playerid][vz] = 11.9518;
                    DataVehicles[slot][playerid][va] = 90.0000;
                    DataVehicles[slot][playerid][vgasoline] = 60;
                }
                if(LocationConcessionaire[playerid] == 3)
                {
                    DataVehicles[slot][playerid][vx] = -1986.8801;
                    DataVehicles[slot][playerid][vy] = 269.9831;
                    DataVehicles[slot][playerid][vz] = 36.2939;
                    DataVehicles[slot][playerid][va] = 90.0000;
                    DataVehicles[slot][playerid][vgasoline] = 60;
                }
                if(LocationConcessionaire[playerid] == 4)
                {
                    DataVehicles[slot][playerid][vx] = 416.2171;
                    DataVehicles[slot][playerid][vy] = 2502.7700;
                    DataVehicles[slot][playerid][vz] = 20.6202;
                    DataVehicles[slot][playerid][va] = 90.0000;
                    DataVehicles[slot][playerid][vgasoline] = 400;
                }
                if(LocationConcessionaire[playerid] == 5)
                {
                    DataVehicles[slot][playerid][vx] = -2205.8254;
                    DataVehicles[slot][playerid][vy] = 2422.5042;
                    DataVehicles[slot][playerid][vz] = 5.3000;
                    DataVehicles[slot][playerid][va] = 45.0000;
                    DataVehicles[slot][playerid][vgasoline] = 100;
                }

                PlayerInfo[playerid][Dinheiro] -= ShoppingConcessionaire[VehiclieIDList[playerid]][sc_price];
                UpdatePlayerMoney(playerid);

                mysql_format(IDConexao, String, sizeof(String), "INSERT INTO `Vehicles` (`slot`, `model`, `x`, `y`, `z`, `a`, `devaluation`, `gasoline`, `id_contas`) VALUES ('%d', '%d', '%f', '%f', '%f', '%f', '%d', '%d', '%d')", slot,
                DataVehicles[slot][playerid][vmodel],
                DataVehicles[slot][playerid][vx],
                DataVehicles[slot][playerid][vy],
                DataVehicles[slot][playerid][vz],
                DataVehicles[slot][playerid][va],
                DataVehicles[slot][playerid][vdevaluation],
                DataVehicles[slot][playerid][vgasoline],
                PlayerInfo[playerid][ID]);
                mysql_query(IDConexao, String);

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
        ShowPlayerDialog(playerid, MAIN_CONCESSIONAIRE_SHOP, DIALOG_STYLE_MSGBOX, "{FF0000}Comprar veículo", String, "Comprar", "Cancelar");
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
