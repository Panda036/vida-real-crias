#include YSI\y_hooks

#define MAX_LIGHT_ROUTE 3

enum e_lightroute
{
    Float:lr_x,
    Float:lr_y,
    Float:lr_z
};

new lightroute[MAX_LIGHT_ROUTE][e_lightroute] =
{
    {-1817.53, 2059.96, 7.94},      //Tierra Roubada
    {777.28, 2047.82, 5.71},        //Bony Conty
    {2689.59, -1965.88, 13.54}      //Los Santos Willowfield
};

enum e_lpr
{
    Float:lpr_x,
    Float:lpr_y,
    Float:lpr_z
};

new Light_Place_Repair[MAX_PLAYERS][e_lpr];
new bool:Light_Repairing[MAX_PLAYERS];
new light_cp[MAX_PLAYERS];
new light_route[MAX_PLAYERS] = -1;
new t_light[MAX_PLAYERS];

hook OnGameModeInit()
{
    CreateDynamic3DTextLabel("{808080}Uniforme\n{FFFFFF}Precione \"N\"", 0xFFFFFFFF, 215.65, 1828.79, 6.42, 30.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
    CreateDynamicPickup(1275, 1, 215.65, 1828.79, 6.42);

    SetDynamicObjectMaterialText(CreateDynamicObject(19353, -2521.00854, -625.28247, 136.43790, 0.00000, 0.00000, 90.00000), 0, "{008040}Light", 50, "Arial", 20, 1, 0x008040AA, 0, 1);
	return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(PRESSED(KEY_NO) && IsPlayerInRangeOfPoint(playerid, 1.0, 215.65, 1828.79, 6.42))
	{
        if(PlayerInfo[playerid][Profissao] != light)
            return SendClientMessage(playerid, Erro, "Voc� n�o tem permiss�o");

        if(GetPlayerSkin(playerid) == 277)
            return SendClientMessage(playerid, Erro, "Voc� j� est� uniformizado(a)");

        SetPlayerSkin(playerid, 277);
        SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Agora voc� est� uniformizado(a) e poder� exercer sua profiss�o");
        return 1;
	}
	return 1;
}

forward UnlockedLightRoute(playerid);
public UnlockedLightRoute(playerid)
{
    if(!Light_Repairing[playerid]) return 0;

    Light_Repairing[playerid] = false;
    TogglePlayerControllable(playerid, true);
    ClearAnimations(playerid);

    light_route[playerid]++;
    DestroyDynamicRaceCP(light_cp[playerid]);

    if(light_route[playerid] >= 3)//Finish
    {
        new value[MAX_PLAYERS];

        value[playerid] = RandomValueLight();

        PlayerInfo[playerid][Dinheiro] += value[playerid];
        UpdatePlayerMoney(playerid);

        format(String, 128, "Todos os consertos foram finalizados e voc� recebeu $%s", IsMoney(value[playerid], "."));
        SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);
        SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Volte para HQ para poder in�ciar � rota");

        GiveBonus(playerid, 500);

        light_route[playerid] = -1;
        Light_Place_Repair[playerid][lpr_x] = 0;
        Light_Place_Repair[playerid][lpr_y] = 0;
        Light_Place_Repair[playerid][lpr_z] = 0;
    }
    else
    {
        Light_Place_Repair[playerid][lpr_x] = lightroute[light_route[playerid]][lr_x];
        Light_Place_Repair[playerid][lpr_y] = lightroute[light_route[playerid]][lr_y];
        Light_Place_Repair[playerid][lpr_z] = lightroute[light_route[playerid]][lr_z];

        switch(light_route[playerid])
        {
            case 2: light_cp[playerid] = CreateDynamicRaceCP(1, Light_Place_Repair[playerid][lpr_x], Light_Place_Repair[playerid][lpr_y], Light_Place_Repair[playerid][lpr_z], -1, -1, -1, 3.0, -1, -1, playerid, -1.0);
            default: light_cp[playerid] = CreateDynamicRaceCP(0, Light_Place_Repair[playerid][lpr_x], Light_Place_Repair[playerid][lpr_y], Light_Place_Repair[playerid][lpr_z], lightroute[ light_route[playerid] + 1 ][lr_x], lightroute[ light_route[playerid] + 1 ][lr_y], lightroute[ light_route[playerid] + 1 ][lr_z], 3.0, -1, -1, playerid, -1.0);
        }

        GetPlayer2DZone(zone, MAX_ZONE_NAME, Light_Place_Repair[playerid][lpr_x], Light_Place_Repair[playerid][lpr_y]);
        format(String, 128, "Conserto efetuado, pr�ximo conserto na localidade ( %s )", zone);
        SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);
    }
    return 1;
}

stock RandomValueLight()
{
    new rand = random(10000);

    return (rand < 8000 ? ( RandomValueLight() ) : ( rand ));
}

stock Light_DynamicRaceCP(playerid)
{
    if(PlayerInfo[playerid][Profissao] == light && light_route[playerid] != -1 && IsPlayerInRangeOfPoint(playerid, 3.0, Light_Place_Repair[playerid][lpr_x], Light_Place_Repair[playerid][lpr_y], Light_Place_Repair[playerid][lpr_z]))
    {
        if(IsPlayerInAnyVehicle(playerid))
            return SendClientMessage(playerid, Erro, "Voc� est� em um ve�culo, saia para consertar o transformador");

        if(GetVehicleModel(LastVehicle[playerid]) != 552)
            return SendClientMessage(playerid, Erro, "Seu �ltimo ve�culo n�o � da Light");

        Light_Repairing[playerid] = true;
        TogglePlayerControllable(playerid, false);
        ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 1, 0, 0, 10000, 0);
        SetTimerEx("UnlockedLightRoute", 10000, false, "d", playerid);
        return 1;
    }
    return 1;
}

stock LeftPfsLight(playerid)
{
    if(PlayerInfo[playerid][Profissao] == light)
    {
        if(Light_Repairing[playerid]){
            Light_Repairing[playerid] = false;
            KillTimer(t_light[playerid]);
        }
        if(light_route[playerid] != -1){
            DestroyDynamicRaceCP(light_cp[playerid]);
            light_route[playerid] = -1;
        }

        Light_Place_Repair[playerid][lpr_x] = 0.0;
        Light_Place_Repair[playerid][lpr_y] = 0.0;
        Light_Place_Repair[playerid][lpr_z] = 0.0;
        return 1;
    }
    return 1;
}

/******************************************************************************/
/******************************| COMMANDS LIGHT |******************************/
/******************************************************************************/

CMD:iniciar(playerid)
{
    if(PlayerInfo[playerid][Profissao] != light)
        return SendClientMessage(playerid, Erro, "Voc� n�o tem permiss�o");

    if(GetPlayerSkin(playerid) != 277)
        return SendClientMessage(playerid, Erro, "Voc� n�o est� com uniforme, v� at� Light");

    if(!IsPlayerInAnyVehicle(playerid) || GetVehicleModel(GetPlayerVehicleID(playerid)) != 552)
        return SendClientMessage(playerid, Erro, "Voc� n�o est� em um ve�culo da Light");

    if(light_route[playerid] != -1)
        return SendClientMessage(playerid, Erro, "Voc� j� in�ciou uma rota, termine-a primeiro");

    if(!IsPlayerInRangeOfPoint(playerid, 100.0, -2516.58, -622.51, 132.75))
        return SendClientMessage(playerid, Erro, "Voc� n�o est� na sua HQ");

    light_route[playerid] = 0;

    Light_Place_Repair[playerid][lpr_x] = lightroute[light_route[playerid]][lr_x];
    Light_Place_Repair[playerid][lpr_y] = lightroute[light_route[playerid]][lr_y];
    Light_Place_Repair[playerid][lpr_z] = lightroute[light_route[playerid]][lr_z];

    light_cp[playerid] = CreateDynamicRaceCP(0, Light_Place_Repair[playerid][lpr_x], Light_Place_Repair[playerid][lpr_y], Light_Place_Repair[playerid][lpr_z], lightroute[light_route[playerid] + 1][lr_x], lightroute[light_route[playerid] + 1][lr_y], lightroute[light_route[playerid] + 1][lr_z], 3.0, -1, -1, playerid, -1.0);

    GetPlayer2DZone(zone, MAX_ZONE_NAME, Light_Place_Repair[playerid][lpr_x], Light_Place_Repair[playerid][lpr_y]);
    format(String, 128, "Primeiro conserto na localidade ( %s )", zone);
    SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Recebemos relat�rio de alguns transformadores queimado");
    SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);
    return 1;
}
