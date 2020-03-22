#include YSI\y_hooks

new CRRTAXI[6];
new BKJORNAL[15];
new VCPOLICIA[38];
new BKNOVATOS[5];
new CARROLG[6];

hook OnGameModeInit()
{
    BKJORNAL[0] = AddStaticVehicleEx(510, 784.9813, -1356.2255, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[1] = AddStaticVehicleEx(510, 784.9813, -1358.1863, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[2] = AddStaticVehicleEx(510, 784.9813, -1360.1813, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[3] = AddStaticVehicleEx(510, 784.9813, -1362.1833, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[4] = AddStaticVehicleEx(510, 784.9813, -1364.1859, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[5] = AddStaticVehicleEx(510, 784.9813, -1345.0000, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[6] = AddStaticVehicleEx(510, 784.9813, -1343.0000, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[7] = AddStaticVehicleEx(510, 784.9813, -1341.0000, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[8] = AddStaticVehicleEx(510, 784.9810, -1339.0000, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[9] = AddStaticVehicleEx(510, 784.9810, -1337.0000, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[10] = AddStaticVehicleEx(510, 784.9813, -1346.8591, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[11] = AddStaticVehicleEx(510, 784.9813, -1348.7258, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[12] = AddStaticVehicleEx(510, 784.9813, -1350.6263, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[13] = AddStaticVehicleEx(510, 784.9813, -1352.5315, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[14] = AddStaticVehicleEx(510, 784.9813, -1354.4387, 13.1522, 90.0000, 1, 1, 100);

    CRRTAXI[0] = AddStaticVehicleEx(420, 2230.0000, -1340.0000, 23.5839, 90.0000, -1, -1, 100);
    CRRTAXI[1] = AddStaticVehicleEx(420, 2230.0000, -1344.0000, 23.5839, 90.0000, -1, -1, 100);
    CRRTAXI[2] = AddStaticVehicleEx(420, 2230.0000, -1348.0000, 23.5839, 90.0000, -1, -1, 100);
    CRRTAXI[3] = AddStaticVehicleEx(420, 2230.0000, -1352.0000, 23.5839, 90.0000, -1, -1, 100);
    CRRTAXI[4] = AddStaticVehicleEx(420, 2230.0000, -1356.0000, 23.5839, 90.0000, -1, -1, 100);
    CRRTAXI[5] = AddStaticVehicleEx(420, 2230.0000, -1360.0000, 23.5839, 90.0000, -1, -1, 100);

    VCPOLICIA[0] = AddStaticVehicleEx(523,1605.0000,-1605.0000,13.0002,90.0000,-1,-1,100);
    VCPOLICIA[1] = AddStaticVehicleEx(523,1604.9994,-1608.0200,13.0002,90.0000,-1,-1,100);
    VCPOLICIA[2] = AddStaticVehicleEx(523,1604.9994,-1611.0000,13.0002,90.0000,-1,-1,100);
    VCPOLICIA[3] = AddStaticVehicleEx(523,1604.9994,-1614.0000,13.0002,90.0000,-1,-1,100);
    VCPOLICIA[4] = AddStaticVehicleEx(523,1604.9994,-1617.0000,13.0002,90.0000,-1,-1,100);
    VCPOLICIA[5] = AddStaticVehicleEx(523,1604.9994,-1620.0000,13.0002,90.0000,-1,-1,100);
    VCPOLICIA[6] = AddStaticVehicleEx(523,1604.9994,-1623.0000,13.0002,90.0000,-1,-1,100);
    VCPOLICIA[7] = AddStaticVehicleEx(523,1604.9994,-1626.0000,13.0002,90.0000,-1,-1,100);
    VCPOLICIA[8] = AddStaticVehicleEx(523,1604.9994,-1629.0000,13.0002,90.0000,-1,-1,100);
    VCPOLICIA[9] = AddStaticVehicleEx(523,1604.9994,-1632.0000,13.0002,90.0000,-1,-1,100);
    VCPOLICIA[10] = AddStaticVehicleEx(598,1551.0000,-1606.0000,13.0802,180.0000,-1,-1,100);
    VCPOLICIA[11] = AddStaticVehicleEx(598,1554.9801,-1606.0016,13.0802,180.0000,-1,-1,100);
    VCPOLICIA[12] = AddStaticVehicleEx(598,1559.0000,-1605.9719,13.0802,180.0000,-1,-1,100);
    VCPOLICIA[13] = AddStaticVehicleEx(598,1563.0000,-1606.0000,13.0802,180.0000,-1,-1,100);
    VCPOLICIA[14] = AddStaticVehicleEx(598,1567.0000,-1606.0010,13.0802,180.0000,-1,-1,100);
    VCPOLICIA[15] = AddStaticVehicleEx(598,1571.0000,-1606.0010,13.0802,180.0000,-1,-1,100);
    VCPOLICIA[16] = AddStaticVehicleEx(598,1575.0000,-1606.0010,13.0802,180.0000,-1,-1,100);
    VCPOLICIA[17] = AddStaticVehicleEx(598,1579.0000,-1606.0010,13.0802,180.0000,-1,-1,100);
    VCPOLICIA[18] = AddStaticVehicleEx(598,2252.0000, 2476.5591,10.4215,180.0000,-1,-1,100);
    VCPOLICIA[19] = AddStaticVehicleEx(598,2255.9714,2476.5591,10.4215,180.0000,-1,-1,100);
    VCPOLICIA[20] = AddStaticVehicleEx(598,2260.4031,2476.5591,10.4215,180.0000,-1,-1,100);
    VCPOLICIA[21] = AddStaticVehicleEx(598,2269.3093,2476.5591,10.4215,180.0000,-1,-1,100);
    VCPOLICIA[22] = AddStaticVehicleEx(598,2273.3691,2476.5591,10.4215,180.0000,-1,-1,100);
    VCPOLICIA[23] = AddStaticVehicleEx(598,2277.8213,2476.5591,10.4215,180.0000,-1,-1,100);
    VCPOLICIA[24] = AddStaticVehicleEx(598,2282.3047,2476.5940,10.4215,180.0000,-1,-1,100);
    VCPOLICIA[25] = AddStaticVehicleEx(497,-220.9945,995.6248,19.7057,-90.0000,-1,-1,100);
    VCPOLICIA[26] = AddStaticVehicleEx(599,-209.1601,998.7247,19.7419,180.0000,-1,-1,100);
    VCPOLICIA[27] = AddStaticVehicleEx(598,-214.1810,972.8283,18.9690,-90.0000,-1,-1,100);
    VCPOLICIA[28] = AddStaticVehicleEx(497,-1680.3081,704.7817,30.9151,0.0000,-1,-1,100);
    VCPOLICIA[29] = AddStaticVehicleEx(523,-1581.6348,652.1369,6.6743,0.0000,-1,-1,100);
    VCPOLICIA[30] = AddStaticVehicleEx(523,-1587.7535,652.1369,6.6743,0.0000,-1,-1,100);
    VCPOLICIA[31] = AddStaticVehicleEx(523,-1593.5933,652.1369,6.6743,0.0000,-1,-1,100);
    VCPOLICIA[32] = AddStaticVehicleEx(523,-1599.4490,652.1369,6.6743,0.0000,-1,-1,100);
    VCPOLICIA[33] = AddStaticVehicleEx(598,-1610.7079,651.8018,6.8743,0.0000,-1,-1,100);
    VCPOLICIA[34] = AddStaticVehicleEx(598,-1616.5802,651.8018,6.8743,0.0000,-1,-1,100);
    VCPOLICIA[35] = AddStaticVehicleEx(598,-1622.5671,651.8018,6.8743,0.0000,-1,-1,100);
    VCPOLICIA[36] = AddStaticVehicleEx(598,-1628.4109,651.8018,6.8743,0.0000,-1,-1,100);
    VCPOLICIA[37] = AddStaticVehicleEx(598,-1634.2976,651.8018,6.8743,0.0000,-1,-1,100);

    BKNOVATOS[0] = AddStaticVehicleEx(481,828.0000,-1336.0000,13.0416,359.3848,1,1,100);
    BKNOVATOS[1] = AddStaticVehicleEx(481,830.0000,-1336.0000,13.0416,359.3848,1,1,100);
    BKNOVATOS[2] = AddStaticVehicleEx(481,832.0000,-1336.0000,13.0416,359.3848,1,1,100);
    BKNOVATOS[3] = AddStaticVehicleEx(481,834.0000,-1336.0000,13.0416,359.3848,1,1,100);
    BKNOVATOS[4] = AddStaticVehicleEx(481,836.0000,-1336.0000,13.0416,359.3848,1,1,100);

    CARROLG[0] = AddStaticVehicleEx(478,-451.0000,2210.0000,42.3809,0.0000,129,129,100);
    CARROLG[1] = AddStaticVehicleEx(478,-447.0000,2210.0000,42.3809,0.0000,129,129,100);
    CARROLG[2] = AddStaticVehicleEx(478,-443.0000,2210.0000,42.3809,0.0000,129,129,100);
    CARROLG[3] = AddStaticVehicleEx(478,-439.0000,2210.0000,42.3809,0.0000,129,129,100);
    CARROLG[4] = AddStaticVehicleEx(478,-435.0000,2210.0000,42.3809,0.0000,129,129,100);
    CARROLG[5] = AddStaticVehicleEx(478,-431.0000,2210.0000,42.3809,0.0000,129,129,100);
    return 1;
}

hook OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    for(new i; i < sizeof(BKJORNAL); i ++) if(vehicleid == BKJORNAL[i])
    {
        if(!ispassenger && vehicleid != INVALID_VEHICLE_ID && PlayerInfo[playerid][Profissao] != EntregadorJornal)
        {
            ClearAnimations(playerid);
            return SendClientMessage(playerid, Erro, "| ERRO | Veiculo exclusivo da profissão Entregador(a) de Jornal!");
        }
    }
    for(new i; i < sizeof(VCPOLICIA); i++) if(vehicleid == VCPOLICIA[i])
    {
        if(!ispassenger && vehicleid != INVALID_VEHICLE_ID && PlayerInfo[playerid][Profissao] != PoliciaMunicipal && PlayerInfo[playerid][Profissao] != Corregedoria)
        {
            ClearAnimations(playerid);
            return SendClientMessage(playerid, Erro, "| ERRO | Veiculo exclusivo da profissãoo Policia!");
        }
        if(!ispassenger && vehicleid != INVALID_VEHICLE_ID && !IsPlayerUniformePM(playerid) && PlayerInfo[playerid][Profissao] == PoliciaMunicipal)
        {
            ClearAnimations(playerid);
            return SendClientMessage(playerid, Erro, "| ERRO | Você não está com o uniforme!");
        }
    }
    for(new i; i < sizeof(CRRTAXI); i++) if(vehicleid == CRRTAXI[i] || vehicleid == CRRTAXI[i])
    {
        if(!ispassenger && vehicleid != INVALID_VEHICLE_ID && PlayerInfo[playerid][Profissao] != Taxi)
        {
            ClearAnimations(playerid);
            return SendClientMessage(playerid, Erro, "| ERRO | Veiculo exclusivo da profissão Taxista!");
        }
    }
    for(new i; i < sizeof(BKNOVATOS); i++) if(vehicleid == BKNOVATOS[i] || vehicleid == BKNOVATOS[i])
    {
        if(!ispassenger && vehicleid != INVALID_VEHICLE_ID && PlayerInfo[playerid][Level] > 5)
        {
            ClearAnimations(playerid);
            return SendClientMessage(playerid, Erro, "| ERRO | Bike exclusiva para novatos!");
        }
    }
    for(new i; i < sizeof(CARROLG); i++) if(vehicleid == CARROLG[i] || vehicleid == CARROLG[i])
    {
        if(!ispassenger && vehicleid != INVALID_VEHICLE_ID && PlayerInfo[playerid][Profissao] != LadraoGas)
        {
            ClearAnimations(playerid);
            return SendClientMessage(playerid, Erro, "| ERRO | Veiculo exclusivo do cargo Ladrão de Gás!");
        }
    }
    return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(newstate == PLAYER_STATE_DRIVER)
    {
        SendClientMessage(playerid, -1, "| INFO | Para ligar ou desligar o veiculo digite '{CECECE}/Partida{FFFFFF}' ou pressione a tecla '{CECECE}Y{FFFFFF}'");
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(PRESSED(KEY_FIRE))
	{
        if(Perseguicao[playerid] == false)
        {
            if(IsPlayerHelper(playerid) || IsPlayerVip(playerid))
            {
                if(IsPlayerInAnyVehicle(playerid))
                {
                    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
                    {
                        if(NitroInfinito(GetPlayerVehicleID(playerid)))
                        {
                            AddVehicleComponent(GetPlayerVehicleID(playerid), 1010);
                            RepairVehicle(GetPlayerVehicleID(playerid));
                        }
                    }
                }
        	}
        }
        return 1;
    }
    if(PRESSED(KEY_YES))
    {
        if(IsPlayerInAnyVehicle(playerid))
        {
        	new mot, lu, alar, por, cap, porma, ob;
        	GetVehicleParamsEx(GetPlayerVehicleID(playerid), mot, lu, alar, por, cap, porma, ob);
        	if(mot == VEHICLE_PARAMS_OFF)
            {
                SetVehicleParamsEx(GetPlayerVehicleID(playerid), VEHICLE_PARAMS_ON, lu, alar, por, cap, porma, ob);
                SendClientMessage(playerid, Verde, "| INFO | Veiculo ligado!");
        	} else {
        	    SendClientMessage(playerid, Verde, "| INFO | Veiculo desligado!");
                SetVehicleParamsEx(GetPlayerVehicleID(playerid), VEHICLE_PARAMS_OFF, lu, alar, por, cap, porma, ob);
        	}
        }
    }
	return 1;
}
