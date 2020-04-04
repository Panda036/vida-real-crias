#include YSI\y_hooks

#define MAX_MAIN_VEHICLES           (10)
#define MAIN_VEHICLES               5051
#define MAIN_VEHICLES_EDIT          5052
#define MAIN_VEHICLES_EDIT_MSG      5053
#define MAIN_VEHICLES_EDIT_PLATE    5054
#define MAIN_DEALERSHIP             5055
#define MAIN_VEHICLES_EDIT_COLORS1  5056
#define MAIN_VEHICLES_EDIT_COLORS2  5057
#define MAIN_VEHICLES_RELEASE_INPUT 5058
//5059 SHOPPING CONCESSIONAIRE

new vspoiler[20][0] =
{
    {1000},
    {1001},
    {1002},
    {1003},
    {1014},
    {1015},
    {1016},
    {1023},
    {1058},
    {1060},
    {1049},
    {1050},
    {1138},
    {1139},
    {1146},
    {1147},
    {1158},
    {1162},
    {1163},
    {1164}
};

new vnitro[3][0] =
{
    {1008},
    {1009},
    {1010}
};

new vfbumper[23][0] =
{
    {1117},
    {1152},
    {1153},
    {1155},
    {1157},
    {1160},
    {1165},
    {1167},
    {1169},
    {1170},
    {1171},
    {1172},
    {1173},
    {1174},
    {1175},
    {1179},
    {1181},
    {1182},
    {1185},
    {1188},
    {1189},
    {1192},
    {1193}
};

new vrbumper[22][0] =
{
    {1140},
    {1141},
    {1148},
    {1149},
    {1150},
    {1151},
    {1154},
    {1156},
    {1159},
    {1161},
    {1166},
    {1168},
    {1176},
    {1177},
    {1178},
    {1180},
    {1183},
    {1184},
    {1186},
    {1187},
    {1190},
    {1191}
};

new vexhaust[28][0] =
{
    {1018},
    {1019},
    {1020},
    {1021},
    {1022},
    {1028},
    {1029},
    {1037},
    {1043},
    {1044},
    {1045},
    {1046},
    {1059},
    {1064},
    {1065},
    {1066},
    {1089},
    {1092},
    {1104},
    {1105},
    {1113},
    {1114},
    {1126},
    {1127},
    {1129},
    {1132},
    {1135},
    {1136}
};

new vbventr[2][0] =
{
    {1042},
    {1044}
};

new vbventl[2][0] =
{
    {1043},
    {1045}
};

new vbscoop[4][0] =
{
    {1004},
    {1005},
    {1011},
    {1012}
};

new vrscoop[13][0] =
{
    {1006},
    {1032},
    {1033},
    {1035},
    {1038},
    {1053},
    {1054},
    {1055},
    {1061},
    {1067},
    {1068},
    {1088},
    {1091}
};

new vlskirt[21][0] =
{
    {1007},
    {1026},
    {1031},
    {1036},
    {1039},
    {1042},
    {1047},
    {1048},
    {1056},
    {1057},
    {1069},
    {1070},
    {1090},
    {1093},
    {1106},
    {1108},
    {1118},
    {1119},
    {1133},
    {1122},
    {1134}
};

new vrskirt[21][0] =
{
    {1017},
    {1027},
    {1030},
    {1040},
    {1041},
    {1051},
    {1052},
    {1062},
    {1063},
    {1071},
    {1072},
    {1094},
    {1095},
    {1099},
    {1101},
    {1102},
    {1107},
    {1120},
    {1121},
    {1124},
    {1137}
};

new vhydraulics[1][0] =
{
    {1087}
};

new vbase[1][0] =
{
    {1086}
};

new vrbbars[2][0] =
{
    {1109},
    {1110}
};

new vfbbars[2][0] =
{
    {1115},
    {1116}
};

new vwheels[17][0] =
{
    {1025},
    {1073},
    {1074},
    {1075},
    {1076},
    {1077},
    {1078},
    {1079},
    {1080},
    {1081},
    {1082},
    {1083},
    {1084},
    {1085},
    {1096},
    {1097},
    {1098}
};

new vlights[2][0] =
{
    {1013},
    {1024}
};

enum enum_vehicles
{
    vvehicle,
    vmodel,
    vmessage[30],
    vplate[10],
    bool:vlock,
    Float:vx,
    Float:vy,
    Float:vz,
    Float:va,
    Float:vlife,
    vdevaluation,
    Float:vkm,
    vgasoline,
    vfines,
    bool:vconnected,
    vmod1,
    vmod2,
    vmod3,
    vmod4,
    vmod5,
    vmod6,
    vmod7,
    vmod8,
    vmod9,
    vmod10,
    vmod11,
    vmod12,
    vmod13,
    vmod14,
    vmod15,
    vmod16,
    vmod17,
    vpaintjob,
    vcolor1,
    vcolor2
};

new DataVehicles[MAX_MAIN_VEHICLES][MAX_PLAYERS][enum_vehicles];
new ModifyingVehicle[MAX_PLAYERS];
new VehiclePlace[MAX_PLAYERS];

hook OnGameModeInit()
{
    new db_vehicles[2000];
    strins(db_vehicles, "CREATE TABLE IF NOT EXISTS `Vehicles` (", strlen(db_vehicles));
    strins(db_vehicles, "`id` int AUTO_INCREMENT,", strlen(db_vehicles));
    strins(db_vehicles, "`slot` int(3) NOT NULL,", strlen(db_vehicles));
    strins(db_vehicles, "`model` int(3) DEFAULT 0,", strlen(db_vehicles));
    strins(db_vehicles, "`message` varchar(30) DEFAULT 'N/A',", strlen(db_vehicles));
    strins(db_vehicles, "`plate` varchar(10) DEFAULT 'BCM-2020',", strlen(db_vehicles));
    strins(db_vehicles, "`lock` int(1) NOT NULL,", strlen(db_vehicles));
    strins(db_vehicles, "`x` float NOT NULL,", strlen(db_vehicles));
    strins(db_vehicles, "`y` float NOT NULL,", strlen(db_vehicles));
    strins(db_vehicles, "`z` float NOT NULL,", strlen(db_vehicles));
    strins(db_vehicles, "`a` float NOT NULL,", strlen(db_vehicles));
    strins(db_vehicles, "`life` float NOT NULL DEFAULT 1000,", strlen(db_vehicles));
    strins(db_vehicles, "`devaluation` int(11) NOT NULL,", strlen(db_vehicles));
    strins(db_vehicles, "`km` int(2) NOT NULL,", strlen(db_vehicles));
    strins(db_vehicles, "`gasoline` int(3) NOT NULL,", strlen(db_vehicles));
    strins(db_vehicles, "`fines` int(2) NOT NULL,", strlen(db_vehicles));
    strins(db_vehicles, "`mod1` int(5) DEFAULT 0,", strlen(db_vehicles));
    strins(db_vehicles, "`mod2` int(5) DEFAULT 0,", strlen(db_vehicles));
    strins(db_vehicles, "`mod3` int(5) DEFAULT 0,", strlen(db_vehicles));
    strins(db_vehicles, "`mod4` int(5) DEFAULT 0,", strlen(db_vehicles));
    strins(db_vehicles, "`mod5` int(5) DEFAULT 0,", strlen(db_vehicles));
    strins(db_vehicles, "`mod6` int(5) DEFAULT 0,", strlen(db_vehicles));
    strins(db_vehicles, "`mod7` int(5) DEFAULT 0,", strlen(db_vehicles));
    strins(db_vehicles, "`mod8` int(5) DEFAULT 0,", strlen(db_vehicles));
    strins(db_vehicles, "`mod9` int(5) DEFAULT 0,", strlen(db_vehicles));
    strins(db_vehicles, "`mod10` int(5) DEFAULT 0,", strlen(db_vehicles));
    strins(db_vehicles, "`mod11` int(5) DEFAULT 0,", strlen(db_vehicles));
    strins(db_vehicles, "`mod12` int(5) DEFAULT 0,", strlen(db_vehicles));
    strins(db_vehicles, "`mod13` int(5) DEFAULT 0,", strlen(db_vehicles));
    strins(db_vehicles, "`mod14` int(5) DEFAULT 0,", strlen(db_vehicles));
    strins(db_vehicles, "`mod15` int(5) DEFAULT 0,", strlen(db_vehicles));
    strins(db_vehicles, "`mod16` int(5) DEFAULT 0,", strlen(db_vehicles));
    strins(db_vehicles, "`mod17` int(5) DEFAULT 0,", strlen(db_vehicles));
    strins(db_vehicles, "`paintjobs` int(1) NOT NULL DEFAULT 3,", strlen(db_vehicles));
    strins(db_vehicles, "`color1` int(3) DEFAULT 0,", strlen(db_vehicles));
    strins(db_vehicles, "`color2` int(3) DEFAULT 0,", strlen(db_vehicles));
    strins(db_vehicles, "`id_contas` int NOT NULL,", strlen(db_vehicles));
    strins(db_vehicles, "PRIMARY KEY (`id`),", strlen(db_vehicles));
    strins(db_vehicles, "FOREIGN KEY (`id_contas`) REFERENCES `Contas`(`id`) ON DELETE CASCADE )", strlen(db_vehicles));
    mysql_query(IDConexao, db_vehicles, false);

    CreateDynamicPickup(1239, 1, 542.1480, -1292.0358, 17.2422);
    CreateDynamicPickup(1239, 1, 2200.8438, 1393.8828, 11.0625);
    CreateDynamicPickup(1239, 1, -1966.3959, 293.9593, 35.4688);
    CreateDynamicPickup(1239, 1, 411.1825, 2533.5020, 19.1484);
    CreateDynamicPickup(1239, 1, -2184.9480, 2413.0244, 5.1563);

    CreateDynamic3DTextLabel("{6495ED}Concessionária\n{FFFFFF}Aperte a letra '{00FF00}Y{FFFFFF}' para ver os veículos", 0xFFFFFFFF, 542.1480, -1292.0358, 17.2422, 30.0);
    CreateDynamic3DTextLabel("{6495ED}Concessionária\n{FFFFFF}Aperte a letra '{00FF00}Y{FFFFFF}' para ver os veículos", 0xFFFFFFFF, 2200.8438, 1393.8828, 11.0625, 30.0);
    CreateDynamic3DTextLabel("{6495ED}Concessionária\n{FFFFFF}Aperte a letra '{00FF00}Y{FFFFFF}' para ver os veículos", 0xFFFFFFFF, -1966.3959, 293.9593, 35.4688, 30.0);
    CreateDynamic3DTextLabel("{6495ED}Concessionária\n{FFFFFF}Aperte a letra '{00FF00}Y{FFFFFF}' para ver os veículos", 0xFFFFFFFF, 411.1825, 2533.5020, 19.1484, 30.0);
    CreateDynamic3DTextLabel("{6495ED}Concessionária\n{FFFFFF}Aperte a letra '{00FF00}Y{FFFFFF}' para ver os veículos", 0xFFFFFFFF, -2184.9480, 2413.0244, 5.1563, 30.0);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
    {
        UpdateVehicles(playerid, slot);

        DestroyVehicle(DataVehicles[slot][playerid][vvehicle]);
        DataVehicles[slot][playerid][vvehicle] = 0;
        DataVehicles[slot][playerid][vmodel] = 0;
        DataVehicles[slot][playerid][vx] = 0;
        DataVehicles[slot][playerid][vy] = 0;
        DataVehicles[slot][playerid][vz] = 0;
        DataVehicles[slot][playerid][va] = 0;
        DataVehicles[slot][playerid][vcolor1] = 0;
        DataVehicles[slot][playerid][vcolor2] = 0;
        DataVehicles[slot][playerid][vlife] = 0;
        DataVehicles[slot][playerid][vconnected] = false;
    }

    DestroyDynamicRaceCP(VehiclePlace[playerid]);

    ModifyingVehicle[playerid] = 0;
    VehiclePlace[playerid] = 0;
	return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == MAIN_VEHICLES && response)
    {
        for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
        {
            if(listitem == slot)
            {
                if(!DataVehicles[slot][playerid][vmodel])
                    return SendClientMessage(playerid, Erro, "Você não tem veículo nesse slot");

                ModifyingVehicle[playerid] = slot;

                new txt[500];

                if(DataVehicles[slot][playerid][vconnected])
                {
                    strcat(txt, "{FFFFFF}Desconectar veículo\n");
                }
                else
                {
                    strcat(txt, "{FFFFFF}Conectar veículo\n");
                }
                strcat(txt, "{FFFFFF}Salvar neste local\n");
                strcat(txt, "{FFFFFF}Alterar mensagem\n");
                strcat(txt, "{FFFFFF}Alterar placa\n");
                strcat(txt, "{FFFFFF}Alterar pinturas\n");
                strcat(txt, "{FFFFFF}Destrancar veículo\n");
                strcat(txt, "{FFFFFF}Trancar veículo\n");
                strcat(txt, "{FFFFFF}Abrir porta-malas\n");
                strcat(txt, "{FFFFFF}Fechar porta-malas\n");
                strcat(txt, "{FFFFFF}Abrir capô\n");
                strcat(txt, "{FFFFFF}Fechar capô\n");
                strcat(txt, "{FFFFFF}Localizar veículo\n");
                strcat(txt, "{FFFFFF}Remover tunagem\n");
                strcat(txt, "{FFFFFF}Vender veículo\n");

                format(String, sizeof(String), "{FF0000}%s", getVehicleName(DataVehicles[slot][playerid][vmodel]));
                ShowPlayerDialog(playerid, MAIN_VEHICLES_EDIT, DIALOG_STYLE_LIST, String, txt, "Selecionar", "Cancelar");

            }
        }
        return 1;
    }
    if(dialogid == MAIN_VEHICLES_EDIT && response)
    {
        switch(listitem)
        {
            case 0: //conectar ou desconectar
            {
                for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
                {
                    if(ModifyingVehicle[playerid] == slot)
                    {
                        if(DataVehicles[slot][playerid][vconnected])
                        {
                            GetVehicleHealth(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vlife]);

                            DataVehicles[slot][playerid][vconnected] = false;
                            SendClientMessage(playerid, White, "Veículo desconectado com sucesso");
                            DestroyVehicle(DataVehicles[slot][playerid][vvehicle]);
                        }
                        else
                        {
                            for(new i = 0; i < MAX_MAIN_VEHICLES; i++)
                            {
                                if(DataVehicles[i][playerid][vconnected]) return SendClientMessage(playerid, Erro, "Você já tem um veículo conectado");
                            }

                            DataVehicles[slot][playerid][vconnected] = true;
                            SendClientMessage(playerid, White, "Veículo conectado com sucesso");
                            DataVehicles[slot][playerid][vvehicle] = AddStaticVehicleEx(DataVehicles[slot][playerid][vmodel], DataVehicles[slot][playerid][vx], DataVehicles[slot][playerid][vy], DataVehicles[slot][playerid][vz], DataVehicles[slot][playerid][va], DataVehicles[slot][playerid][vcolor1], DataVehicles[slot][playerid][vcolor2], -1);

                            SetVehicleNumberPlate(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vplate]);
                            SetVehicleToRespawn(DataVehicles[slot][playerid][vvehicle]);
                            SetVehicleParamsEx(DataVehicles[slot][playerid][vvehicle], 0, 0, 0, 0, 0, 0, 0);
                            TuneThisCar(playerid, slot);
                        }
                        return 1;
                    }
                }
                return 1;
            }
            case 1: //salvar veículo
            {
                for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
                {
                    if(ModifyingVehicle[playerid] == slot)
                    {
                        if(!DataVehicles[slot][playerid][vconnected])
                            return SendClientMessage(playerid, Erro, "Esse veículo não está conectado");

                        new Float:x, Float:y, Float:z, Float:a;
                        GetVehiclePos(DataVehicles[slot][playerid][vvehicle], x, y, z);
                        GetVehicleZAngle(DataVehicles[slot][playerid][vvehicle], a);

                        if(!IsPlayerInRangeOfPoint(playerid, 10.0, x, y, z))
                            return SendClientMessage(playerid, Erro, "Você está longe do veículo, chegue mais perto");

                        DataVehicles[slot][playerid][vx] = x;
                        DataVehicles[slot][playerid][vy] = y;
                        DataVehicles[slot][playerid][vz] = z;
                        DataVehicles[slot][playerid][va] = a;

                        UpdateVehicles(playerid, slot);

                        SendClientMessage(playerid, White, "Veículo salvo neste local com sucesso");
                        return 1;
                    }
                }
                return 1;
            }
            case 2: //alterar mensagen
            {
                for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
                {
                    if(ModifyingVehicle[playerid] == slot)
                    {
                        if(!DataVehicles[slot][playerid][vconnected])
                            return SendClientMessage(playerid, Erro, "Esse veículo não está conectado");

                        if(!IsPlayerInVehicle(playerid, DataVehicles[slot][playerid][vvehicle]))
                            return SendClientMessage(playerid, Erro, "Você não está em seu veículo");

                        ShowPlayerDialog(playerid, MAIN_VEHICLES_EDIT_MSG, DIALOG_STYLE_INPUT, "{FF0000}Alterar mensagem", "{FFFFFF}Digite abaixo a nova mensagem do seu veículo:", "Continuar", "Cancelar");
                        return 1;
                    }
                }
                return 1;
            }
            case 3: //alterar placa
            {
                for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
                {
                    if(ModifyingVehicle[playerid] == slot)
                    {
                        if(!DataVehicles[slot][playerid][vconnected])
                            return SendClientMessage(playerid, Erro, "Esse veículo não está conectado");

                        if(!IsPlayerInVehicle(playerid, DataVehicles[slot][playerid][vvehicle]))
                            return SendClientMessage(playerid, Erro, "Você não está em seu veículo");

                        ShowPlayerDialog(playerid, MAIN_VEHICLES_EDIT_PLATE, DIALOG_STYLE_INPUT, "{FF0000}Alterar placa", "{FFFFFF}Digite abaixo novos números para placa do seu veículo:", "Continuar", "Cancelar");
                        return 1;
                    }
                }
                return 1;
            }
            case 4: //alterar pintura
            {
                for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
                {
                    if(ModifyingVehicle[playerid] == slot)
                    {
                        if(!DataVehicles[slot][playerid][vconnected])
                            return SendClientMessage(playerid, Erro, "Esse veículo não está conectado");

                        if(!IsPlayerInVehicle(playerid, DataVehicles[slot][playerid][vvehicle]))
                            return SendClientMessage(playerid, Erro, "Você não está em seu veículo");

                        ShowPlayerDialog(playerid, MAIN_VEHICLES_EDIT_COLORS1, DIALOG_STYLE_INPUT, "{FF0000}Alterar pinturas", "{FFFFFF}Digite abaixo a {FF0000}primeira{FFFFFF} cor ID para seu veículo\n\nExemplo: 3", "Continuar", "Cancelar");
                        return 1;
                    }
                }
                return 1;
            }
            case 5: //destrancar
            {
                for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
                {
                    if(ModifyingVehicle[playerid] == slot)
                    {
                        if(!DataVehicles[slot][playerid][vconnected])
                            return SendClientMessage(playerid, Erro, "Esse veículo não está conectado");

                        new Float:x, Float:y, Float:z;
                        GetVehiclePos(DataVehicles[slot][playerid][vvehicle], x, y, z);

                        if(!IsPlayerInRangeOfPoint(playerid, 10.0, x, y, z))
                            return SendClientMessage(playerid, Erro, "Você está longe do veículo, chegue mais perto");

                        if(!DataVehicles[slot][playerid][vlock])
                            return SendClientMessage(playerid, Erro, "Seu veículo já está destrancado");

                        DataVehicles[slot][playerid][vlock] = false;
                        SetVehicleParamsCarDoors(DataVehicles[slot][playerid][vvehicle], 1, 1, 1, 1);
                        SendClientMessage(playerid, White, "Agora o seu veículo esta destrancado");

                        UpdateVehicles(playerid, slot);
                        return 1;
                    }
                }
                return 1;
            }
            case 6: //trancar
            {
                for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
                {
                    if(ModifyingVehicle[playerid] == slot)
                    {
                        if(!DataVehicles[slot][playerid][vconnected])
                            return SendClientMessage(playerid, Erro, "Esse veículo não está conectado");

                        new Float:x, Float:y, Float:z;
                        GetVehiclePos(DataVehicles[slot][playerid][vvehicle], x, y, z);

                        if(!IsPlayerInRangeOfPoint(playerid, 10.0, x, y, z))
                            return SendClientMessage(playerid, Erro, "Você está longe do veículo, chegue mais perto");

                        if(DataVehicles[slot][playerid][vlock])
                            return SendClientMessage(playerid, Erro, "Seu veículo já está trancado");

                        DataVehicles[slot][playerid][vlock] = true;
                        SetVehicleParamsCarDoors(DataVehicles[slot][playerid][vvehicle], 0, 0, 0, 0);
                        SendClientMessage(playerid, White, "Agora o seu veículo esta trancado");

                        UpdateVehicles(playerid, slot);
                        return 1;
                    }
                }
                return 1;
            }
            case 7: //abrir porta-malas
            {
                for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
                {
                    if(ModifyingVehicle[playerid] == slot)
                    {
                        if(!DataVehicles[slot][playerid][vconnected])
                            return SendClientMessage(playerid, Erro, "Esse veículo não está conectado");

                        new Float:x, Float:y, Float:z;
                        GetVehiclePos(DataVehicles[slot][playerid][vvehicle], x, y, z);

                        if(!IsPlayerInRangeOfPoint(playerid, 10.0, x, y, z))
                            return SendClientMessage(playerid, Erro, "Você está longe do veículo, chegue mais perto");

                        new engine, lights, alarm, doors, bonnet, boot, objective;

                        GetVehicleParamsEx(DataVehicles[slot][playerid][vvehicle], engine, lights, alarm, doors, bonnet, boot, objective);

                        SetVehicleParamsEx(DataVehicles[slot][playerid][vvehicle], engine, lights, alarm, doors, bonnet, 1, objective);

                        SendClientMessage(playerid, White, "Agora o portar-malas do seu veículo está aberto");
                        return 1;
                    }
                }
                return 1;
            }
            case 8: //fechar porta-malas
            {
                for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
                {
                    if(ModifyingVehicle[playerid] == slot)
                    {
                        if(!DataVehicles[slot][playerid][vconnected])
                            return SendClientMessage(playerid, Erro, "Esse veículo não está conectado");

                        new Float:x, Float:y, Float:z;
                        GetVehiclePos(DataVehicles[slot][playerid][vvehicle], x, y, z);

                        if(!IsPlayerInRangeOfPoint(playerid, 10.0, x, y, z))
                            return SendClientMessage(playerid, Erro, "Você está longe do veículo, chegue mais perto");

                        new engine, lights, alarm, doors, bonnet, boot, objective;

                        GetVehicleParamsEx(DataVehicles[slot][playerid][vvehicle], engine, lights, alarm, doors, bonnet, boot, objective);

                        SetVehicleParamsEx(DataVehicles[slot][playerid][vvehicle], engine, lights, alarm, doors, bonnet, 0, objective);

                        SendClientMessage(playerid, White, "Agora o portar-malas do seu veículo está fechado");
                        return 1;
                    }
                }
                return 1;
            }
            case 9: //abrir capô
            {
                for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
                {
                    if(ModifyingVehicle[playerid] == slot)
                    {
                        if(!DataVehicles[slot][playerid][vconnected])
                            return SendClientMessage(playerid, Erro, "Esse veículo não está conectado");

                        new Float:x, Float:y, Float:z;
                        GetVehiclePos(DataVehicles[slot][playerid][vvehicle], x, y, z);

                        if(!IsPlayerInRangeOfPoint(playerid, 10.0, x, y, z))
                            return SendClientMessage(playerid, Erro, "Você está longe do veículo, chegue mais perto");

                        new engine, lights, alarm, doors, bonnet, boot, objective;

                        GetVehicleParamsEx(DataVehicles[slot][playerid][vvehicle], engine, lights, alarm, doors, bonnet, boot, objective);

                        SetVehicleParamsEx(DataVehicles[slot][playerid][vvehicle], engine, lights, alarm, doors, 1, boot, objective);

                        SendClientMessage(playerid, White, "Agora o capô do seu veículo está aberto");
                        return 1;
                    }
                }
                return 1;
            }
            case 10: //fechar capô
            {
                for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
                {
                    if(ModifyingVehicle[playerid] == slot)
                    {
                        if(!DataVehicles[slot][playerid][vconnected])
                            return SendClientMessage(playerid, Erro, "Esse veículo não está conectado");

                        new Float:x, Float:y, Float:z;
                        GetVehiclePos(DataVehicles[slot][playerid][vvehicle], x, y, z);

                        if(!IsPlayerInRangeOfPoint(playerid, 10.0, x, y, z))
                            return SendClientMessage(playerid, Erro, "Você está longe do veículo, chegue mais perto");

                        new engine, lights, alarm, doors, bonnet, boot, objective;

                        GetVehicleParamsEx(DataVehicles[slot][playerid][vvehicle], engine, lights, alarm, doors, bonnet, boot, objective);

                        SetVehicleParamsEx(DataVehicles[slot][playerid][vvehicle], engine, lights, alarm, doors, 0, boot, objective);

                        SendClientMessage(playerid, White, "Agora o capô do seu veículo está fechado");
                        return 1;
                    }
                }
                return 1;
            }
            case 11: //localizar veículo
            {
                for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
                {
                    if(ModifyingVehicle[playerid] == slot)
                    {
                        if(!DataVehicles[slot][playerid][vconnected])
                            return SendClientMessage(playerid, Erro, "Esse veículo não está conectado");

                        new Float:x, Float:y, Float:z;

                        GetVehiclePos(DataVehicles[slot][playerid][vvehicle], x, y, z);

                        if(VehiclePlace[playerid])
                        {
                            DestroyDynamicRaceCP(VehiclePlace[playerid]);
                        }

                        VehiclePlace[playerid] = CreateDynamicRaceCP(1, x, y, z, -1, -1, -1, 5.0, -1, -1, playerid, -1.0, -1, 0);
                        SendClientMessage(playerid, White, "Veículo localizado com sucesso");
                        return 1;
                    }
                }
                return 1;
            }
            case 12: //remover tunagem
            {
                for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
                {
                    if(ModifyingVehicle[playerid] == slot)
                    {
                        if(!DataVehicles[slot][playerid][vconnected])
                            return SendClientMessage(playerid, Erro, "Esse veículo não está conectado");

                        if(!IsPlayerInVehicle(playerid, DataVehicles[slot][playerid][vvehicle]))
                            return SendClientMessage(playerid, Erro, "Você não está em seu veículo");

                        RemoveVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod1]);
                        RemoveVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod2]);
                        RemoveVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod3]);
                        RemoveVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod4]);
                        RemoveVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod5]);
                        RemoveVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod6]);
                        RemoveVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod7]);
                        RemoveVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod8]);
                        RemoveVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod9]);
                        RemoveVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod10]);
                        RemoveVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod11]);
                        RemoveVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod12]);
                        RemoveVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod13]);
                        RemoveVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod14]);
                        RemoveVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod15]);
                        RemoveVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod16]);
                        RemoveVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod17]);
                        ChangeVehicleColor(DataVehicles[slot][playerid][vvehicle], 1, 1);
                        ChangeVehiclePaintjob(DataVehicles[slot][playerid][vvehicle], 3);

                        DataVehicles[slot][playerid][vmod1] = 0;
                        DataVehicles[slot][playerid][vmod2] = 0;
                        DataVehicles[slot][playerid][vmod3] = 0;
                        DataVehicles[slot][playerid][vmod4] = 0;
                        DataVehicles[slot][playerid][vmod5] = 0;
                        DataVehicles[slot][playerid][vmod6] = 0;
                        DataVehicles[slot][playerid][vmod7] = 0;
                        DataVehicles[slot][playerid][vmod8] = 0;
                        DataVehicles[slot][playerid][vmod9] = 0;
                        DataVehicles[slot][playerid][vmod10] = 0;
                        DataVehicles[slot][playerid][vmod11] = 0;
                        DataVehicles[slot][playerid][vmod12] = 0;
                        DataVehicles[slot][playerid][vmod13] = 0;
                        DataVehicles[slot][playerid][vmod14] = 0;
                        DataVehicles[slot][playerid][vmod15] = 0;
                        DataVehicles[slot][playerid][vmod16] = 0;
                        DataVehicles[slot][playerid][vmod17] = 0;
                        DataVehicles[slot][playerid][vcolor1] = 1;
                        DataVehicles[slot][playerid][vcolor2] = 1;
                        DataVehicles[slot][playerid][vpaintjob] = 3;

                        UpdateVehicles(playerid, slot);
                        return 1;
                    }
                }
                return 1;
            }
            case 13: //Vender veículo
            {
                for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
                {
                    if(ModifyingVehicle[playerid] == slot)
                    {
                        if(!DataVehicles[slot][playerid][vconnected])
                            return SendClientMessage(playerid, Erro, "Esse veículo não está conectado");

                        if(!IsPlayerInVehicle(playerid, DataVehicles[slot][playerid][vvehicle]))
                            return SendClientMessage(playerid, Erro, "Você não está em seu veículo");

                        ShowPlayerDialog(playerid, MAIN_VEHICLES_RELEASE_INPUT, DIALOG_STYLE_INPUT, "{FF0000}Código de Confirmação", "{FFFFFF}Digite abaixo o código da sua conta.\n\n{FF4000}Obs: É o mesmo código usado para registrar sua conta!", "Continuar", "Cancelar");
                        return 1;
                    }
                }
                return 1;
            }
        }
        return 1;
    }
    if(dialogid == MAIN_VEHICLES_RELEASE_INPUT && response)
    {
        if(!strlen(inputtext))
            return ShowPlayerDialog(playerid, MAIN_VEHICLES_RELEASE_INPUT, DIALOG_STYLE_INPUT, "{FF0000}Código de Confirmação", "{FFFFFF}Digite abaixo o código da sua conta.\n{FF0000}Código Incorreto!\n\n{FF4000}Obs: É o mesmo código usado para registrar sua conta!", "Continuar", "Cancelar");

        if(!IsValidCodingAccount(playerid, inputtext))
            return ShowPlayerDialog(playerid, MAIN_VEHICLES_RELEASE_INPUT, DIALOG_STYLE_INPUT, "{FF0000}Código de Confirmação", "{FFFFFF}Digite abaixo o código da sua conta.\n{FF0000}Código Incorreto!\n\n{FF4000}Obs: É o mesmo código usado para registrar sua conta!", "Continuar", "Cancelar");

        for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
        {
            if(ModifyingVehicle[playerid] == slot)
            {
                format(String, sizeof(String), "| VENDA | Você vendeu o seu veículo %s por {00A800}$%s", getVehicleName(DataVehicles[slot][playerid][vmodel]), IsMoney(DataVehicles[slot][playerid][vdevaluation], "."));
                SendClientMessage(playerid, -1, String);

                PlayerInfo[playerid][Dinheiro] += DataVehicles[slot][playerid][vdevaluation];
                UpdatePlayerMoney(playerid);

                new query[100];
                mysql_format(IDConexao, query, sizeof(query), "DELETE FROM `Vehicles` WHERE `slot`='%d' AND `id_contas`='%d'", slot, PlayerInfo[playerid][ID]);
                mysql_query(IDConexao, query);

                DestroyVehicle(DataVehicles[slot][playerid][vvehicle]);
                DataVehicles[slot][playerid][vmodel] = 0;
                DataVehicles[slot][playerid][vmessage] = 0;
                DataVehicles[slot][playerid][vplate] = 0;
                DataVehicles[slot][playerid][vlock] = false;
                DataVehicles[slot][playerid][vx] = 0;
                DataVehicles[slot][playerid][vy] = 0;
                DataVehicles[slot][playerid][vz] = 0;
                DataVehicles[slot][playerid][va] = 0;
                DataVehicles[slot][playerid][vlife] = 0;
                DataVehicles[slot][playerid][vdevaluation] = 0;
                DataVehicles[slot][playerid][vkm] = 0;
                DataVehicles[slot][playerid][vgasoline] = 0;
                DataVehicles[slot][playerid][vfines] = 0;
                DataVehicles[slot][playerid][vconnected] = false;
                DataVehicles[slot][playerid][vmod1] = 0;
                DataVehicles[slot][playerid][vmod2] = 0;
                DataVehicles[slot][playerid][vmod3] = 0;
                DataVehicles[slot][playerid][vmod4] = 0;
                DataVehicles[slot][playerid][vmod5] = 0;
                DataVehicles[slot][playerid][vmod6] = 0;
                DataVehicles[slot][playerid][vmod7] = 0;
                DataVehicles[slot][playerid][vmod8] = 0;
                DataVehicles[slot][playerid][vmod9] = 0;
                DataVehicles[slot][playerid][vmod10] = 0;
                DataVehicles[slot][playerid][vmod11] = 0;
                DataVehicles[slot][playerid][vmod12] = 0;
                DataVehicles[slot][playerid][vmod13] = 0;
                DataVehicles[slot][playerid][vmod14] = 0;
                DataVehicles[slot][playerid][vmod15] = 0;
                DataVehicles[slot][playerid][vmod16] = 0;
                DataVehicles[slot][playerid][vmod17] = 0;
                DataVehicles[slot][playerid][vpaintjob] = 0;
                DataVehicles[slot][playerid][vcolor1] = 0;
                DataVehicles[slot][playerid][vcolor2] = 0;
                return 1;
            }
        }
        return 1;
    }
    if(dialogid == MAIN_VEHICLES_EDIT_MSG && response)
    {
        for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
        {
            if(ModifyingVehicle[playerid] == slot)
            {
                if(!strlen(inputtext))
                    return ShowPlayerDialog(playerid, MAIN_VEHICLES_EDIT_MSG, DIALOG_STYLE_INPUT, "{FF0000}Alterar mensagem", "{FFFFFF}Digite abaixo a nova mensagem do seu veículo:", "Continuar", "Cancelar");

                if(strlen(inputtext) > 30)
                    return ShowPlayerDialog(playerid, MAIN_VEHICLES_EDIT_MSG, DIALOG_STYLE_INPUT, "{FF0000}Alterar mensagem", "{FFFFFF}Digite abaixo a nova mensagem do seu veículo:\n{FF4000}ERRO: digite uma mensagem com no máximo 30 caracteres!", "Continuar", "Cancelar");

                format(DataVehicles[slot][playerid][vmessage], 30, inputtext);

                UpdateVehicles(playerid, slot);

                format(String, sizeof(String), "Mensagem do seu veículo foi alterada para \"%s\"", DataVehicles[slot][playerid][vmessage]);
                SendClientMessage(playerid, White, String);
                return 1;
            }
        }
        return 1;
    }
    if(dialogid == MAIN_VEHICLES_EDIT_PLATE && response)
    {
        for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
        {
            if(ModifyingVehicle[playerid] == slot)
            {
                if(!strlen(inputtext))
                    return ShowPlayerDialog(playerid, MAIN_VEHICLES_EDIT_PLATE, DIALOG_STYLE_INPUT, "{FF0000}Alterar placa", "{FFFFFF}Digite abaixo novos números para placa do seu veículo:", "Continuar", "Cancelar");

                if(strlen(inputtext) > 10)
                    return ShowPlayerDialog(playerid, MAIN_VEHICLES_EDIT_PLATE, DIALOG_STYLE_INPUT, "{FF0000}Alterar placa", "{FFFFFF}Digite abaixo novos números para placa do seu veículo:\n{FF4000}ERRO: digite uma mensagem com no máximo 10 caracteres!", "Continuar", "Cancelar");

                new Float:x, Float:y, Float:z;

                format(DataVehicles[slot][playerid][vplate], 10, inputtext);

                GetVehiclePos(DataVehicles[slot][playerid][vvehicle], x, y, z);
                GetVehicleHealth(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vlife]);

                SetVehicleNumberPlate(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vplate]);
                SetVehicleToRespawn(DataVehicles[slot][playerid][vvehicle]);
                SetVehiclePos(DataVehicles[slot][playerid][vvehicle], x, y, z);

                TuneThisCar(playerid, slot);

                PutPlayerInVehicle(playerid, DataVehicles[slot][playerid][vvehicle], 0);

                UpdateVehicles(playerid, slot);

                format(String, sizeof(String), "Os números da placa do seu veículo foi alterado para \"%s\"", DataVehicles[slot][playerid][vplate]);
                SendClientMessage(playerid, White, String);
                return 1;
            }
        }
        return 1;
    }
    if(dialogid == MAIN_VEHICLES_EDIT_COLORS1 && response)
    {
        for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
        {
            if(ModifyingVehicle[playerid] == slot)
            {
                if(!IsNumeric(inputtext))
                    return ShowPlayerDialog(playerid, MAIN_VEHICLES_EDIT_COLORS1, DIALOG_STYLE_INPUT, "{FF0000}Alterar pinturas", "{FFFFFF}Digite abaixo a {FF0000}primeira{FFFFFF} cor ID para seu veículo\n\n{FF4000}Erro: Digite apenas números!", "Continuar", "Cancelar");

                if(strval(inputtext) < 0 || strval(inputtext) > 255)
                    return ShowPlayerDialog(playerid, MAIN_VEHICLES_EDIT_COLORS1, DIALOG_STYLE_INPUT, "{FF0000}Alterar pinturas", "{FFFFFF}Digite abaixo a {FF0000}primeira{FFFFFF} cor ID para seu veículo\n\n{FF4000}Erro: Digite uma cor ID entre 0-255!", "Continuar", "Cancelar");

                DataVehicles[slot][playerid][vcolor1] = strval(inputtext);
                ShowPlayerDialog(playerid, MAIN_VEHICLES_EDIT_COLORS2, DIALOG_STYLE_INPUT, "{FF0000}Alterar pinturas", "{FFFFFF}Digite abaixo a {FF0000}segunda{FFFFFF} cor ID para seu veículo\n\nExemplo: 3", "Continuar", "Cancelar");
                return 1;
            }
        }
        return 1;
    }
    if(dialogid == MAIN_VEHICLES_EDIT_COLORS2 && response)
    {
        for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
        {
            if(ModifyingVehicle[playerid] == slot)
            {
                if(!IsNumeric(inputtext))
                    return ShowPlayerDialog(playerid, MAIN_VEHICLES_EDIT_COLORS2, DIALOG_STYLE_INPUT, "{FF0000}Alterar pinturas", "{FFFFFF}Digite abaixo a {FF0000}segunda{FFFFFF} cor ID para seu veículo\n\n{FF4000}Erro: Digite apenas números!", "Continuar", "Cancelar");

                if(strval(inputtext) < 0 || strval(inputtext) > 255)
                    return ShowPlayerDialog(playerid, MAIN_VEHICLES_EDIT_COLORS2, DIALOG_STYLE_INPUT, "{FF0000}Alterar pinturas", "{FFFFFF}Digite abaixo a {FF0000}segunda{FFFFFF} cor ID para seu veículo\n\n{FF4000}Erro: Digite uma cor ID entre 0-255!", "Continuar", "Cancelar");

                DataVehicles[slot][playerid][vcolor2] = strval(inputtext);

                ChangeVehicleColor(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vcolor1], DataVehicles[slot][playerid][vcolor2]);

                UpdateVehicles(playerid, slot);

                SendClientMessage(playerid, White, "Pintura do seu veículo foi alterada com sucesso");
                return 1;
            }
        }
        return 1;
    }
    return 1;
}

hook OnVehicleDeath(vehicleid, killerid)
{
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
        {
            if(vehicleid == DataVehicles[slot][i][vvehicle])
            {
                UpdateVehicles(i, slot);
                return 1;
            }
        }
    }
    return 1;
}

hook OnVehicleMod(playerid, vehicleid, componentid)
{
    new Varz = InitComponents(componentid);

    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
        {
            if(vehicleid == DataVehicles[slot][i][vvehicle])
            {
                switch(Varz)
                {
                    case 1: DataVehicles[slot][playerid][vmod1] = componentid;
                    case 2: DataVehicles[slot][playerid][vmod2] = componentid;
                    case 3: DataVehicles[slot][playerid][vmod3] = componentid;
                    case 4: DataVehicles[slot][playerid][vmod4] = componentid;
                    case 5: DataVehicles[slot][playerid][vmod5] = componentid;
                    case 6: DataVehicles[slot][playerid][vmod6] = componentid;
                    case 7: DataVehicles[slot][playerid][vmod7] = componentid;
                    case 8: DataVehicles[slot][playerid][vmod8] = componentid;
                    case 9: DataVehicles[slot][playerid][vmod9] = componentid;
                    case 10: DataVehicles[slot][playerid][vmod10] = componentid;
                    case 11: DataVehicles[slot][playerid][vmod11] = componentid;
                    case 12: DataVehicles[slot][playerid][vmod12] = componentid;
                    case 13: DataVehicles[slot][playerid][vmod13] = componentid;
                    case 14: DataVehicles[slot][playerid][vmod14] = componentid;
                    case 15: DataVehicles[slot][playerid][vmod15] = componentid;
                    case 16: DataVehicles[slot][playerid][vmod16] = componentid;
                    case 17: DataVehicles[slot][playerid][vmod17] = componentid;
                }
                UpdateVehicles(playerid, slot);
                return 1;
            }
        }
    }
    return 1;
}

forward DB_LoadVehicles(playerid, slot);
public DB_LoadVehicles(playerid, slot)
{
    if(cache_num_rows())
    {
        new tmp[30];

        cache_get_value_int(0, "model", DataVehicles[slot][playerid][vmodel]);
        cache_get_value_name(0, "message", tmp); format(DataVehicles[slot][playerid][vmessage], 30, tmp);
        cache_get_value_name(0, "plate", tmp); format(DataVehicles[slot][playerid][vplate], 10, tmp);
        cache_get_value_int(0, "lock", DataVehicles[slot][playerid][vlock]);
        cache_get_value_float(0, "x", DataVehicles[slot][playerid][vx]);
        cache_get_value_float(0, "y", DataVehicles[slot][playerid][vy]);
        cache_get_value_float(0, "z", DataVehicles[slot][playerid][vz]);
        cache_get_value_float(0, "a", DataVehicles[slot][playerid][va]);
        cache_get_value_float(0, "life", DataVehicles[slot][playerid][vlife]);
        cache_get_value_int(0, "devaluation", DataVehicles[slot][playerid][vdevaluation]);
        cache_get_value_float(0, "km", DataVehicles[slot][playerid][vkm]);
        cache_get_value_int(0, "gasoline", DataVehicles[slot][playerid][vgasoline]);
        cache_get_value_int(0, "fines", DataVehicles[slot][playerid][vfines]);
        cache_get_value_int(0, "mod1", DataVehicles[slot][playerid][vmod1]);
        cache_get_value_int(0, "mod2", DataVehicles[slot][playerid][vmod2]);
        cache_get_value_int(0, "mod3", DataVehicles[slot][playerid][vmod3]);
        cache_get_value_int(0, "mod4", DataVehicles[slot][playerid][vmod4]);
        cache_get_value_int(0, "mod5", DataVehicles[slot][playerid][vmod5]);
        cache_get_value_int(0, "mod6", DataVehicles[slot][playerid][vmod6]);
        cache_get_value_int(0, "mod7", DataVehicles[slot][playerid][vmod7]);
        cache_get_value_int(0, "mod8", DataVehicles[slot][playerid][vmod8]);
        cache_get_value_int(0, "mod9", DataVehicles[slot][playerid][vmod9]);
        cache_get_value_int(0, "mod10", DataVehicles[slot][playerid][vmod10]);
        cache_get_value_int(0, "mod11", DataVehicles[slot][playerid][vmod11]);
        cache_get_value_int(0, "mod12", DataVehicles[slot][playerid][vmod12]);
        cache_get_value_int(0, "mod13", DataVehicles[slot][playerid][vmod13]);
        cache_get_value_int(0, "mod14", DataVehicles[slot][playerid][vmod14]);
        cache_get_value_int(0, "mod15", DataVehicles[slot][playerid][vmod15]);
        cache_get_value_int(0, "mod16", DataVehicles[slot][playerid][vmod16]);
        cache_get_value_int(0, "mod17", DataVehicles[slot][playerid][vmod17]);
        cache_get_value_int(0, "paintjobs", DataVehicles[slot][playerid][vpaintjob]);
        cache_get_value_int(0, "color1", DataVehicles[slot][playerid][vcolor1]);
        cache_get_value_int(0, "color2", DataVehicles[slot][playerid][vcolor2]);
    }
    return 1;
}

stock UpdateVehicles(playerid, slot)
{
    new _str[500];

    GetVehicleHealth(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vlife]);

    mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Vehicles` SET `model`='%d', `message`='%e', `plate`='%e', `lock`='%d', `x`='%f', `y`='%f', `z`='%f', `a`='%f', `life`='%f', `devaluation`='%d', `km`='%f', `gasoline`='%d', `fines`='%d' WHERE `slot`='%d' AND `id_contas`='%d'",
    DataVehicles[slot][playerid][vmodel],
    DataVehicles[slot][playerid][vmessage],
    DataVehicles[slot][playerid][vplate],
    DataVehicles[slot][playerid][vlock],
    DataVehicles[slot][playerid][vx],
    DataVehicles[slot][playerid][vy],
    DataVehicles[slot][playerid][vz],
    DataVehicles[slot][playerid][va],
    DataVehicles[slot][playerid][vlife],
    DataVehicles[slot][playerid][vdevaluation],
    DataVehicles[slot][playerid][vkm],
    DataVehicles[slot][playerid][vgasoline],
    DataVehicles[slot][playerid][vfines],
    slot,
    PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, _str);

    mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Vehicles` SET `mod1`='%d', `mod2`='%d', `mod3`='%d', `mod4`='%d', `mod5`='%d', `mod6`='%d', `mod7`='%d', `mod8`='%d', `mod9`='%d', `mod10`='%d', `mod11`='%d', `mod12`='%d', `mod13`='%d', `mod14`='%d', `mod15`='%d', `mod16`='%d', `mod17`='%d', `paintjobs`='%d', `color1`='%d', `color2`='%d' WHERE `slot`='%d' AND `id_contas`='%d'",
    DataVehicles[slot][playerid][vmod1],
    DataVehicles[slot][playerid][vmod2],
    DataVehicles[slot][playerid][vmod3],
    DataVehicles[slot][playerid][vmod4],
    DataVehicles[slot][playerid][vmod5],
    DataVehicles[slot][playerid][vmod6],
    DataVehicles[slot][playerid][vmod7],
    DataVehicles[slot][playerid][vmod8],
    DataVehicles[slot][playerid][vmod9],
    DataVehicles[slot][playerid][vmod10],
    DataVehicles[slot][playerid][vmod11],
    DataVehicles[slot][playerid][vmod12],
    DataVehicles[slot][playerid][vmod13],
    DataVehicles[slot][playerid][vmod14],
    DataVehicles[slot][playerid][vmod15],
    DataVehicles[slot][playerid][vmod16],
    DataVehicles[slot][playerid][vmod17],
    DataVehicles[slot][playerid][vpaintjob],
    DataVehicles[slot][playerid][vcolor1],
    DataVehicles[slot][playerid][vcolor2],
    slot,
    PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, _str);
    return 1;
}

stock TuneThisCar(playerid, slot)
{
    if(DataVehicles[slot][playerid][vmod1])
    {
        AddVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod1]);
    }
    if(DataVehicles[slot][playerid][vmod2])
    {
        AddVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod2]);
    }
    if(DataVehicles[slot][playerid][vmod3])
    {
        AddVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod3]);
    }
    if(DataVehicles[slot][playerid][vmod4])
    {
        AddVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod4]);
    }
    if(DataVehicles[slot][playerid][vmod5])
    {
        AddVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod5]);
    }
    if(DataVehicles[slot][playerid][vmod6])
    {
        AddVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod6]);
    }
    if(DataVehicles[slot][playerid][vmod7])
    {
        AddVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod7]);
    }
    if(DataVehicles[slot][playerid][vmod8])
    {
        AddVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod8]);
    }
    if(DataVehicles[slot][playerid][vmod9])
    {
        AddVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod9]);
    }
    if(DataVehicles[slot][playerid][vmod10])
    {
        AddVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod10]);
    }
    if(DataVehicles[slot][playerid][vmod11])
    {
        AddVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod11]);
    }
    if(DataVehicles[slot][playerid][vmod12])
    {
        AddVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod12]);
    }
    if(DataVehicles[slot][playerid][vmod13])
    {
        AddVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod13]);
    }
    if(DataVehicles[slot][playerid][vmod14])
    {
        AddVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod14]);
    }
    if(DataVehicles[slot][playerid][vmod15])
    {
        AddVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod15]);
    }
    if(DataVehicles[slot][playerid][vmod16])
    {
        AddVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod16]);
    }
    if(DataVehicles[slot][playerid][vmod17])
    {
        AddVehicleComponent(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vmod17]);
    }
    if(DataVehicles[slot][playerid][vcolor1] || DataVehicles[slot][playerid][vcolor2])
    {
        ChangeVehicleColor(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vcolor1], DataVehicles[slot][playerid][vcolor2]);
    }
    if(DataVehicles[slot][playerid][vpaintjob] == 0 || DataVehicles[slot][playerid][vpaintjob] == 1 || DataVehicles[slot][playerid][vpaintjob] == 2)
    {
        ChangeVehiclePaintjob(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vpaintjob]);
    }

    SetVehicleHealth(DataVehicles[slot][playerid][vvehicle], DataVehicles[slot][playerid][vlife]);
    return 1;
}

stock InitComponents(componentid)
{
    new i;
    for(i=0; i < 20; i++)
    {
        if(vspoiler[i][0] == componentid) { return 1; }
    }
    for(i=0; i < 3; i++)
    {
        if(vnitro[i][0] == componentid) { return 2; }
    }
    for(i=0; i < 23; i++)
    {
        if(vfbumper[i][0] == componentid) { return 3; }
    }
    for(i=0; i < 22; i++)
    {
        if(vrbumper[i][0] == componentid) { return 4; }
    }
    for(i=0; i < 28; i++)
    {
        if(vexhaust[i][0] == componentid) { return 5; }
    }
    for(i=0; i < 2; i++)
    {
        if(vbventr[i][0] == componentid) { return 6; }
    }
    for(i=0; i < 2; i++)
    {
        if(vbventl[i][0] == componentid) { return 7; }
    }
    for(i=0; i < 4; i++)
    {
        if(vbscoop[i][0] == componentid) { return 8; }
    }
    for(i=0; i < 13; i++)
    {
        if(vrscoop[i][0] == componentid) { return 9; }
    }
    for(i=0; i < 21; i++)
    {
        if(vlskirt[i][0] == componentid) { return 10; }
    }
    for(i=0; i < 21; i++)
    {
        if(vrskirt[i][0] == componentid) { return 11; }
    }

    if(vhydraulics[0][0] == componentid) { return 12; }

    if(vbase[0][0] == componentid) { return 13; }

    for(i=0; i<2; i++)
    {
        if(vrbbars[i][0] == componentid) { return 14; }
    }
    for(i=0; i < 2; i++)
    {
        if(vfbbars[i][0] == componentid) { return 15; }
    }
    for(i=0; i < 17; i++)
    {
        if(vwheels[i][0] == componentid) { return 16; }
    }
    for(i=0; i < 2; i++)
    {
        if(vlights[i][0] == componentid) { return 17; }
    }
    return 0;
}

stock HaveEmptyVehicleMenuSlots(playerid)
{
    for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
    {
        if(!DataVehicles[slot][playerid][vmodel])
        {
            return true;
        }
    }
    return false;
}

/******************************************************************************/
/*****************************• COMMANDS VEHICLES •****************************/
/******************************************************************************/

CMD:menuveiculos(playerid)
{
    new txt[1000];

    for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
    {
        if(!DataVehicles[slot][playerid][vmodel])
        {
            format(String, sizeof(String), "{FF0000}%dº\t{FFFFFF}Disponivel para Compra\t N/A\n", (slot+1));
            strcat(txt, String);
        }
        else
        {
            if(DataVehicles[slot][playerid][vconnected])
            {
                format(String, sizeof(String), "{00FF00}%dº\t{FFFFFF}%s\t {00FF00}Conectado \n", (slot+1), getVehicleName(DataVehicles[slot][playerid][vmodel]));
            }
            else
            {
                format(String, sizeof(String), "{FF0000}%dº\t{FFFFFF}%s\t {FF0000}Desconectado \n", (slot+1), getVehicleName(DataVehicles[slot][playerid][vmodel]));
            }
            strcat(txt, String);
        }
    }
    ShowPlayerDialog(playerid, MAIN_VEHICLES, DIALOG_STYLE_TABLIST, "{FF0000}Menu Veículos", txt, "Selecionar", "Cancelar");
    return 1;
}
