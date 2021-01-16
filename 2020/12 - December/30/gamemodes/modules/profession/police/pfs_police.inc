#include YSI\y_hooks

enum enum_slp
{
    slp_sex[10],
    slp_skinid
};

new SkinList[MAX_PLAYERS];
new SkinListPolice[21][enum_slp] =
{
    {SEX_GIRL, 191},
    {SEX_BOY, 265},
    {SEX_BOY, 266},
    {SEX_BOY, 267},
    {SEX_BOY, 280},
    {SEX_BOY, 281},
    {SEX_BOY, 282},
    {SEX_BOY, 283},
    {SEX_BOY, 284},
    {SEX_BOY, 285},
    {SEX_BOY, 286},
    {SEX_BOY, 287},
    {SEX_BOY, 288},
    {SEX_BOY, 300},
    {SEX_BOY, 301},
    {SEX_BOY, 302},
    {SEX_GIRL, 306},
    {SEX_GIRL, 307},
    {SEX_GIRL, 309},
    {SEX_BOY, 310},
    {SEX_BOY, 311}
};

hook OnGameModeInit()
{
    CreateDynamic3DTextLabel("{808080}Uniforme\n{FFFFFF}Precione \"N\"", 0xFFFFFFFF, 254.54, 78.19, 1003.64, 30.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
    CreateDynamicPickup(1275, 1, 254.54, 78.19, 1003.64);

    CreateDynamicCP(248.9497, 67.6059, 1003.6406, 1.0, -1, -1, -1, 30.0);   //CPS Presos

    CreateVehicleLocation(1576.23, -1620.31, 13.54);
    CreateVehicleLocation(2241.78, 2449.55, 10.82);
    CreateVehicleLocation(-1617.03, 675.57, 7.18);
    CreateVehicleLocation(620.26, -608.16, 17.23);
    CreateVehicleLocation(-218.50, 984.47, 19.53);
    CreateVehicleLocation(-2177.26, -2371.92, 30.62);
    CreateVehicleLocation(-1393.64, 2643.55, 55.93);
    return 1;
}

hook OnPlayerConnected(playerid)
{
    Handcuffed[playerid] = INVALID_PLAYER_ID;

    SetTimerEx("wheeldamage", 200, true, "d", playerid);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(PRESSED(KEY_NO) && IsPlayerInRangeOfPoint(playerid, 1.0, 254.54, 78.19, 1003.64))
	{
        if(!IsPlayerPolice(playerid))
            return SendClientMessage(playerid, Erro, "Você não tem permissão");

        if(IsPlayerUniformPM(playerid))
            return SendClientMessage(playerid, Erro, "Você já está uniformizado(a)");

        SkinList[playerid] = 0;

        PlayerTextDrawSetPreviewModel(playerid, TDPlayerSkinList[playerid][0], SkinListPolice[SkinList[playerid]][slp_skinid]);
        PlayerTextDrawSetString(playerid, TDPlayerSkinList[playerid][4], SkinListPolice[SkinList[playerid]][slp_sex]);

        ShowTDPlayerSkinList(playerid);
        return 1;
	}
    if(PRESSED(KEY_YES))
    {
        if(!IsPlayerInDepartamentPolice(playerid, 2.0))
            return 0;

        if(!IsPlayerPolice(playerid))
            return SendClientMessage(playerid, Erro, "Você não tem permissão");

        if(!IsPlayerUniformPM(playerid))
            return SendClientMessage(playerid, Erro, "Você não está uniformizado(a)");

        new txt[200];

        strcat(txt, "{FFFFFF}Police LS\n");
        strcat(txt, "{FFFFFF}Police LV\n");
        strcat(txt, "{FFFFFF}Police SF\n");
        strcat(txt, "{FFFFFF}Police Ranger\n");
        strcat(txt, "{FFFFFF}S.W.A.T\n");
        strcat(txt, "{FFFFFF}HPV1000\n");
        strcat(txt, "{FFFFFF}FBI Rancher\n");
        strcat(txt, "{FFFFFF}FBI Truck\n");
        strcat(txt, "{FFFFFF}Enforcer\n");

        ShowPlayerDialog(playerid, police_vehicle, DIALOG_STYLE_LIST, "{FF0000}Selecione seu veículo", txt, "Selecionar", "Cancelar");
        return 1;
	}
	return 1;
}

forward ObjectDestroy(playerid);
public ObjectDestroy(playerid)
{
    if(IsValidDynamicObject(TapeteInfo[playerid][tpt_obj])) DestroyDynamicObject(TapeteInfo[playerid][tpt_obj]);
    if(IsValidDynamic3DTextLabel(TapeteInfo[playerid][tpt_label])) DestroyDynamic3DTextLabel(TapeteInfo[playerid][tpt_label]);
    if(IsValidDynamicObject(BarrierObj[playerid])) DestroyDynamicObject(BarrierObj[playerid]);
    if(IsValidDynamic3DTextLabel(BarrierLabel[playerid])) DestroyDynamic3DTextLabel(BarrierLabel[playerid]);
    return 1;
}

#define takedamage(%1,%2,%3,%4) %1 | (%2 << 1) | (%3 << 2) | (%4 << 3)

forward wheeldamage(playerid);
public wheeldamage(playerid)
{
    new Dano[4];

    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerInAnyVehicle(playerid))
        {
            if(PlayerInfo[playerid][Estrelas] > 0 && IsPlayerInRangeOfPoint(playerid, 5.0, TapeteInfo[i][tpt_x], TapeteInfo[i][tpt_y], TapeteInfo[i][tpt_z]) && TapeteInfo[i][tpt_obj])
            {
                GetVehicleDamageStatus(GetPlayerVehicleID(playerid), Dano[0], Dano[1], Dano[2], Dano[3]);
                UpdateVehicleDamageStatus(GetPlayerVehicleID(playerid), Dano[0], Dano[1], Dano[2], takedamage(1, 1, 1, 1));
            }
    	}
    }
    return 1;
}

forward ExitPersecution(playerid);
public ExitPersecution(playerid)
{
    format(String, MAX_STRING, "O(A) jogador(a) %s[%d] não está sendo mais perseguido pela pocilia por passar 5 minutos", PlayerInfo[playerid][Nome], playerid);
    SendClientMessageToAll(0x2894FFAA, String);
    SendClientMessage(playerid, 0xB9FFFFAA, "Você não está mais em perseguição");

    if(Perseguicao[playerid]){
        Perseguicao[playerid] = false;
        KillTimer(t_persecution[playerid]);
    }
    return 1;
}

forward ExitHandcuff(playerid);
public ExitHandcuff(playerid)
{
    SendClientMessage(playerid, 0xB9FFFFAA, "Você não está mais algemado(a)");

    if(Handcuffed[playerid] != INVALID_PLAYER_ID)
    {
        Handcuffed[playerid] = INVALID_PLAYER_ID;
        KillTimer(t_handcuffed[playerid]);

        RemovePlayerAttachedObject(playerid, 4);
        TogglePlayerControllable(playerid, true);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
    }
    return 1;
}

forward ExitApproach(playerid);
public ExitApproach(playerid)
{
    SendClientMessage(playerid, 0xB9FFFFAA, "Você não está mais abordado(a)");

    if(Abordado[playerid]){
        Abordado[playerid] = false;
        KillTimer(t_approach[playerid]);
    }
    return 1;
}

stock IsPlayerPolice(playerid)
{
    switch(PlayerInfo[playerid][Profissao])
    {
        case municipalguard..interpol: return 1;
        case navy..aeronautics: return 1;
        default: return 0;
    }
    return 1;
}

stock IsPlayerUniformPM(playerid)
{
    for(new i = 0; i < 21; i++)
    {
        if(GetPlayerSkin(playerid) == SkinListPolice[i][slp_skinid]) return 1;
    }
    return 0;
}

stock ClickTextDrawPolice(playerid, PlayerText:playertextid)
{
    if(playertextid == TDPlayerSkinList[playerid][1]) //Escolher
    {
        if(PlayerInfo[playerid][sexo] != SkinListPolice[SkinList[playerid]][slp_sex])
            return SendClientMessage(playerid, Erro, "Sexo Inválido");

        if((SkinListPolice[SkinList[playerid]][slp_skinid] == 287 || SkinListPolice[SkinList[playerid]][slp_skinid] == 191) && ( PlayerInfo[playerid][Profissao] != navy && PlayerInfo[playerid][Profissao] != army && PlayerInfo[playerid][Profissao] != aeronautics ))
            return SendClientMessage(playerid, Erro, "Você não trabalhar para as forças armadas!");

        HideTDPlayerSkinList(playerid);
        SetPlayerSkin(playerid, SkinListPolice[SkinList[playerid]][slp_skinid]);
        return 1;
    }
    if(playertextid == TDPlayerSkinList[playerid][2]) //left
    {
        if(SkinList[playerid] == 0)
            return SendClientMessage(playerid, Erro, "Não tem mais skins");

        SkinList[playerid]--;

        PlayerTextDrawSetPreviewModel(playerid, TDPlayerSkinList[playerid][0], SkinListPolice[SkinList[playerid]][slp_skinid]);
        PlayerTextDrawShow(playerid, TDPlayerSkinList[playerid][0]);
        PlayerTextDrawSetString(playerid, TDPlayerSkinList[playerid][4], SkinListPolice[SkinList[playerid]][slp_sex]);
        PlayerTextDrawShow(playerid, TDPlayerSkinList[playerid][4]);
        return 1;
    }
    if(playertextid == TDPlayerSkinList[playerid][3]) //right
    {
        if(SkinList[playerid] == 20)
            return SendClientMessage(playerid, Erro, "Não tem mais skins");

        SkinList[playerid]++;

        PlayerTextDrawSetPreviewModel(playerid, TDPlayerSkinList[playerid][0], SkinListPolice[SkinList[playerid]][slp_skinid]);
        PlayerTextDrawShow(playerid, TDPlayerSkinList[playerid][0]);
        PlayerTextDrawSetString(playerid, TDPlayerSkinList[playerid][4], SkinListPolice[SkinList[playerid]][slp_sex]);
        PlayerTextDrawShow(playerid, TDPlayerSkinList[playerid][4]);
        return 1;
    }

    if(playertextid == TDPlayerSkinList[playerid][5]) return HideTDPlayerSkinList(playerid); //exit

    return 1;
}

stock IsVehiclePolice(vehicleid)
{
    switch(GetVehicleModel(vehicleid))
    {
        case 596, 598, 597, 599, 601, 523, 490, 528, 427: return 1;
    }
    return 0;
}

stock IsPlayerInDepartamentPolice(playerid, Float:angle = 100.0)
{
    if(IsPlayerInRangeOfPoint(playerid, angle, 1576.23, -1620.31, 13.54)) return 1;
    else if(IsPlayerInRangeOfPoint(playerid, angle, 2241.78, 2449.55, 10.82)) return 1;
    else if(IsPlayerInRangeOfPoint(playerid, angle, -1617.03, 675.57, 7.18)) return 1;
    else if(IsPlayerInRangeOfPoint(playerid, angle, 620.26, -608.16, 17.23)) return 1;
    else if(IsPlayerInRangeOfPoint(playerid, angle, -218.50, 984.47, 19.53)) return 1;
    else if(IsPlayerInRangeOfPoint(playerid, angle, -2177.26, -2371.92, 30.62)) return 1;
    else if(IsPlayerInRangeOfPoint(playerid, angle, -1393.64, 2643.55, 55.93)) return 1;
    return 0;
}

stock GetPlayerDepartamentPoliceID(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 100.0, 1576.23, -1620.31, 13.54)) return DEPARTAMENT_POLICE_LS;
    else if(IsPlayerInRangeOfPoint(playerid, 100.0, 2241.78, 2449.55, 10.82)) return DEPARTAMENT_POLICE_LV;
    else if(IsPlayerInRangeOfPoint(playerid, 100.0, -1617.03, 675.57, 7.18)) return DEPARTAMENT_POLICE_SF;
    else if(IsPlayerInRangeOfPoint(playerid, 100.0, 620.26, -608.16, 17.23)) return DEPARTAMENT_POLICE_DM;
    else if(IsPlayerInRangeOfPoint(playerid, 100.0, -218.50, 984.47, 19.53)) return DEPARTAMENT_POLICE_FC;
    else if(IsPlayerInRangeOfPoint(playerid, 100.0, -2177.26, -2371.92, 30.62)) return DEPARTAMENT_POLICE_AP;
    else if(IsPlayerInRangeOfPoint(playerid, 100.0, -1393.64, 2643.55, 55.93)) return DEPARTAMENT_POLICE_EQ;
    return -1;
}

/******************************************************************************/
/*****************************| COMMANDS POLICE |******************************/
/******************************************************************************/

CMD:barreira(playerid)
{
    if(!IsPlayerPolice(playerid))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(PlayerInfo[playerid][Profissao] == municipalguard)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsVehiclePolice(LastVehicle[playerid]))
        return SendClientMessage(playerid, Erro, "Seu último veículo não é da policia");

    if(BarrierObj[playerid])
    {
        DestroyDynamicObject(BarrierObj[playerid]);
        DestroyDynamic3DTextLabel(BarrierLabel[playerid]);
        BarrierObj[playerid] = 0;
        GameTextForPlayer(playerid, "~w~Barreira removida", 3000, 1);
    }
    else
    {
        if(GetPlayerInterior(playerid) != 0)
            return SendClientMessage(playerid, Erro, "Não é possível criar tapete em interior");

        if(IsPlayerInAnyVehicle(playerid))
            return SendClientMessage(playerid, Erro, "Não é possível criar tapete em um veículo");

        new Float:x, Float:y, Float:z, Float:a;

        GetPlayerFacingAngle(playerid, a);
        GetPlayerPos(playerid, x, y, z);

        format(String, 50, "{FFFFFF}%s {FF0000}%s", (PlayerInfo[playerid][sexo] == SEX_BOY ? ("Jogador") : ("Jogadora")), PlayerInfo[playerid][Nome]);
        BarrierLabel[playerid] = CreateDynamic3DTextLabel(String, 0xFFFFFFFF, x, y, z-0.9, 200.0);
        BarrierObj[playerid] = CreateDynamicObject(981, x, y, z, 0.0, 0.0, a+180, -1, -1, -1, 200.0);
        SetPlayerPos(playerid, x, y+2, z);

        SetTimerEx("ObjectDestroy", 600000, false, "d", playerid);
        GameTextForPlayer(playerid, "~w~Barreira criada", 3000, 1);
    }
    return 1;
}
CMD:tapete(playerid)
{
    if(!IsPlayerPolice(playerid))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(PlayerInfo[playerid][Profissao] == municipalguard)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsVehiclePolice(LastVehicle[playerid]))
        return SendClientMessage(playerid, Erro, "Seu último veículo não é da policia");

    if(TapeteInfo[playerid][tpt_obj])
    {
        DestroyDynamic3DTextLabel(TapeteInfo[playerid][tpt_label]);
        DestroyDynamicObject(TapeteInfo[playerid][tpt_obj]);
        TapeteInfo[playerid][tpt_obj] = 0;

        GameTextForPlayer(playerid, "~w~Tapede removido", 3000, 1);
    }
    else
    {
        if(GetPlayerInterior(playerid) != 0)
            return SendClientMessage(playerid, Erro, "Não é possível criar tapete em interior");

        if(IsPlayerInAnyVehicle(playerid))
            return SendClientMessage(playerid, Erro, "Não é possível criar tapete em um veículo");

        new Float:a;

        GetPlayerPos(playerid, TapeteInfo[playerid][tpt_x], TapeteInfo[playerid][tpt_y], TapeteInfo[playerid][tpt_z]);
        GetPlayerFacingAngle(playerid, a);

        format(String, 50, "{FFFFFF}%s {FF0000}%s", (PlayerInfo[playerid][sexo] == SEX_BOY ? ("Jogador") : ("Jogadora")), PlayerInfo[playerid][Nome]);
        TapeteInfo[playerid][tpt_obj] = CreateDynamicObject(2899, TapeteInfo[playerid][tpt_x], TapeteInfo[playerid][tpt_y], TapeteInfo[playerid][tpt_z]-0.9, 0.0, 0.0, a-90, -1, -1, -1, 200.0);
        TapeteInfo[playerid][tpt_label] = CreateDynamic3DTextLabel(String, 0xFFFFFFFF, TapeteInfo[playerid][tpt_x], TapeteInfo[playerid][tpt_y], TapeteInfo[playerid][tpt_z]-0.9, 200.0);

        GameTextForPlayer(playerid,"~w~Tapede criado", 3000, 1);
        SetTimerEx("ObjectDestroy", 600000, false, "d", playerid);
    }
 	return 1;
}

CMD:equipar(playerid)
{
    if(!IsPlayerPolice(playerid))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsPlayerInRangeOfPoint(playerid, 1.5, 254.1715,74.3339,1003.6406))
        return SendClientMessage(playerid, Erro, "Você não está no vestiário do Departamento de Polícia");

    if(!IsPlayerUniformPM(playerid))
        return SendClientMessage(playerid, Erro, "Você não está com o uniforme");

    SetPlayerArmour(playerid, 100.0);
    GivePlayerWeapon(playerid, 31, 2000);
    GivePlayerWeapon(playerid, 24, 2000);
    GivePlayerWeapon(playerid, 28, 2000);
    SendClientMessage(playerid, White, "Armas equipadas");
    return 1;
}
CMD:removeruniforme(playerid)
{
    if(!IsPlayerPolice(playerid))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsPlayerInRangeOfPoint(playerid, 1.5, 254.1715,74.3339,1003.6406))
        return SendClientMessage(playerid, Erro, "Você não está no vestiário do Departamento de Polícia");

    if(!IsPlayerUniformPM(playerid))
        return SendClientMessage(playerid, Erro, "Você não está com o uniforme");

    SetPlayerSkin(playerid, PlayerInfo[playerid][skin]);
    SendClientMessage(playerid, White, "Uniforme removido");
    return 1;
}
CMD:prenderarmas(playerid, params[])
{
    if(!IsPlayerPolice(playerid) && !IsPlayerModerator(playerid))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(PlayerInfo[playerid][Profissao] == municipalguard)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsVehiclePolice(LastVehicle[playerid]) && !IsPlayerModerator(playerid))
        return SendClientMessage(playerid, Erro, "Seu último veículo não é da policia");

    new id;

    if(sscanf(params, "u", id))
        return SendClientMessage(playerid, Erro, "Digite: /Prenderarmas [id/nome]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não está conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    if(GetDistanceBetweenPlayers(playerid, id) > 15 && !IsPlayerModerator(playerid))
        return SendClientMessage(playerid, Erro, "Você está muito longe, chegue mais perto");

    if(PlayerInfo[id][Estrelas] == 0 && !IsPlayerModerator(playerid))
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) não está procurado(a)");

    ResetPlayerWeapons(id);
    format(String, MAX_STRING, "Você prendeu todas as armas do(a) jogador(a) %s[%d]!", PlayerInfo[id][Nome], id);
    SendClientMessage(playerid, 0x2894FFAA, String);
    format(String, MAX_STRING, "O(A) %s %s[%d] prendeu todas as suas armas!", (!IsPlayerModerator(playerid) ? ("Policial") : (CargoAdmin(playerid))), PlayerInfo[playerid][Nome], playerid);
    SendClientMessage(id, 0x2894FFAA, String);
    return 1;
}
CMD:perseguicao(playerid, params[])
{
    if(!IsPlayerPolice(playerid))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsVehiclePolice(LastVehicle[playerid]))
        return SendClientMessage(playerid, Erro, "Seu último veículo não é da policia");

    new id;

    if(sscanf(params, "u", id))
        return SendClientMessage(playerid, Erro, "Digite: /Perseguicao [id/nome]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não está conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    if(GetDistanceBetweenPlayers(playerid, id) > 15)
        return SendClientMessage(playerid, Erro, "Você está muito longe, chegue mais perto");

    if(Abordado[id] == false)
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) não está abordado(a)");

    if(Perseguicao[id] == true)
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) já está em perseguição");

    Perseguicao[id] = true;
    t_persecution[id] = SetTimerEx("ExitPersecution", 300000, false, "d", id);
    format(String, MAX_STRING, "O(A) Policial %s[%d] iniciou uma perseguição no(a) jogador(a) %s[%d] por não se render!", PlayerInfo[playerid][Nome], playerid, PlayerInfo[id][Nome], id);
    SendClientMessageToAll(0x2894FFAA, String);
    return 1;
}
CMD:abordar(playerid, params[])
{
    if(!IsPlayerPolice(playerid))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsVehiclePolice(LastVehicle[playerid]))
        return SendClientMessage(playerid, Erro, "Seu último veículo não é da policia");

    new id;

    if(sscanf(params, "u", id))
        return SendClientMessage(playerid, Erro, "Digite: /abordar [id/nome]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não está conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    if(GetDistanceBetweenPlayers(playerid, id) > 15)
        return SendClientMessage(playerid, Erro, "Você está muito longe, chegue mais perto");

    if(Abordado[id])
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) já está abordado(a)");

    if(!PlayerInfo[id][Estrelas])
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) não está procurado(a)");

    t_approach[id] = SetTimerEx("ExitApproach", 120000, false, "d", id);

    Abordado[id] = true;
    GameTextForPlayer(id, "~b~Abordagem!", 1000, 0);
    format(String, MAX_STRING, "Você foi abordado pelo Policial %s[%d]", PlayerInfo[playerid][Nome], playerid);
    SendClientMessage(id, 0x2894FFAA, String);
    format(String, MAX_STRING, "Você abordou o(a) Jogador(a) %s[%d]", PlayerInfo[id][Nome], id);
    SendClientMessage(playerid, 0x2894FFAA, String);
    return 1;
}
CMD:algemar(playerid, params[])
{
    if(!IsPlayerPolice(playerid))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsVehiclePolice(LastVehicle[playerid]))
        return SendClientMessage(playerid, Erro, "Seu último veículo não é da policia");

    new id;

    if(sscanf(params, "u", id))
            return SendClientMessage(playerid, Erro, "Digite: /algemar [id/nome]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não está conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    if(GetDistanceBetweenPlayers(playerid, id) > 15)
        return SendClientMessage(playerid, Erro, "Você está muito longe, chegue mais perto");

    if(!Abordado[id])
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) não está abordado(a)");

    if(Handcuffed[id] != INVALID_PLAYER_ID)
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) já está algemado(a)");

    if(IsPlayerInAnyVehicle(playerid) == 1)
        return SendClientMessage(playerid, Erro, "Você está em um veiculo");

    if(IsPlayerInAnyVehicle(id) == 1)
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) está em um veiculo");

    if(Perseguicao[id]){
        Perseguicao[id] = false;
        KillTimer(t_persecution[id]);
    }

    t_handcuffed[id] = SetTimerEx("ExitHandcuff", 120000, false, "d", id);

    Abordado[id] = false;
    Handcuffed[id] = playerid;
    TogglePlayerControllable(id, false);
    SetPlayerSpecialAction(id, SPECIAL_ACTION_CUFFED);
    SetPlayerAttachedObject(id,4,19418,6,-0.031999,0.024000,-0.024000,-7.900000,-32.000011,-72.299987,1.115998,1.322000,1.406000);

    GameTextForPlayer(id, "~b~ALGEMADO!", 1000, 0);
    format(String, MAX_STRING, "Você algemou o(a) Jogador(a) %s[%d]", PlayerInfo[id][Nome], id);
    SendClientMessage(playerid, 0x2894FFAA, String);
    format(String, MAX_STRING, "Você foi algemado pelo Policial %s[%d]", PlayerInfo[playerid][Nome], playerid);
    SendClientMessage(id, 0x2894FFAA, String);
    return 1;
}
CMD:prender(playerid, params[])
{
    if(!IsPlayerPolice(playerid))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsPlayerUniformPM(playerid))
        return SendClientMessage(playerid, Erro, "Você não está com o uniforme");

    new id;

    if(sscanf(params, "u", id))
        return SendClientMessage(playerid, Erro, "/Prender [id/nome]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não está conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    if(PrisonEnum[id][pTempo] != 0)
        return SendClientMessage(playerid, Erro, "O(A) jogador(a) está preso");

    if(GetDistanceBetweenPlayers(playerid, id) > 15)
        return SendClientMessage(playerid, Erro, "Você está muito longe, chegue mais perto");

    if(Handcuffed[id] == INVALID_PLAYER_ID)
        return SendClientMessage(playerid, Erro, "O(a) Jogador(a) precisa estar algemado para prender");

    if(Handcuffed[id] != playerid)
        return SendClientMessage(playerid, Erro, "O(a) Jogador(a) não foi algemado(a) por você");

    PlayerInfo[playerid][Dinheiro] += ( PlayerInfo[id][Estrelas] * 200 );
    UpdatePlayerMoney(playerid);

    format(String, MAX_STRING, "Você foi preso pelo Policial %s ( Motivo: Procurado(a) )", PlayerInfo[playerid][Nome]);
    SendClientMessage(id, 0x2894FFAA, String);
    format(String, MAX_STRING, "Você prendeu o(a) Jogador(a) %s ( Procurado(a) )", PlayerInfo[id][Nome]);
    SendClientMessage(playerid, 0x2894FFAA, String);
    format(String, MAX_STRING, "Você recebeu a recompensa de $%d por prender um jogador(a) que estava sendo procurado(a) pela policia", PlayerInfo[id][Estrelas]*100);
    SendClientMessage(playerid, 0x2894FFAA, String);

    SetPlayerPrision(PlayerInfo[id][Nome], PlayerInfo[playerid][Nome], "Municipal", "Procurado(a)", PlayerInfo[id][Estrelas]);
    return 1;
}
CMD:procurados(playerid)
{
    if(!IsPlayerPolice(playerid) && !IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsVehiclePolice(LastVehicle[playerid]) && !IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Seu último veículo não é da policia");

    new txt[4000], count = 0;

    strcat(txt, "{CCCCCC}ID\t {1B6302}Nome\t {FF4000}Estrelas\n");

    for(new player = 0; player < MAX_PLAYERS; player++)
    {
        if(!PlayerInfo[player][Logado]) continue;

        if(!PlayerInfo[player][Estrelas]) continue;

        count++;
        format(String, MAX_STRING, "{CCCCCC}%d\t {1B6302}%s\t {FF4000}%d\n", player, PlayerInfo[player][Nome], PlayerInfo[player][Estrelas]);
        strcat(txt, String);
    }

    if(count)
        ShowPlayerDialog(playerid, 0, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Procurados", txt, "Fechar", #);
    else
        ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Procurados", "{FF4000}Não temos procurados online no momento!", "Fechar", #);

    return 1;
}
CMD:procurar(playerid, params[])
{
    if(!IsPlayerPolice(playerid))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(PlayerInfo[playerid][Profissao] == municipalguard)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsVehiclePolice(LastVehicle[playerid]))
        return SendClientMessage(playerid, Erro, "Seu último veículo não é da policia");

    new id, reason[50];

    if(sscanf(params, "us[50]", id, reason))
        return SendClientMessage(playerid, Erro, "Digite: /Procurar [id/nome] [motivo]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não está conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    if(GetDistanceBetweenPlayers(playerid, id) > 15)
        return SendClientMessage(playerid, Erro, "Você está muito longe, chegue mais perto");

    if(PlayerInfo[id][Estrelas])
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) já está procurado(a)");

    PlayerInfo[id][Estrelas] += 1;
    UpdatePlayerStar(id);

    format(String, MAX_STRING, "Você colocou como procurado(a) o(a) jogador(a) %s[%d] por ( %s )", PlayerInfo[id][Nome], id, reason);
    SendClientMessage(playerid, 0x2894FFAA, String);
    format(String, MAX_STRING, "O(A) Policial %s[%d] lê colocou como procurado(a) por ( %s )", PlayerInfo[playerid][Nome], playerid, reason);
    SendClientMessage(id, 0x2894FFAA, String);
    return 1;
}
CMD:arrombarcasa(playerid, params[])
{
    if(!IsPlayerPolice(playerid))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsVehiclePolice(LastVehicle[playerid]))
        return SendClientMessage(playerid, Erro, "Seu último veículo não é da policia");

    new houseid;

    if(sscanf(params, "d", houseid))
        return SendClientMessage(playerid, Erro, "Digite: /ArrombarCasa [casa-id]");

    if(!IsPlayerInRangeOfPoint(playerid, 2.0, HouseInfo[houseid][iconx], HouseInfo[houseid][icony], HouseInfo[houseid][iconz]))
        return SendClientMessage(playerid, Erro, "Você não está perto da porta da casa");

    if(HouseInfo[houseid][hBreaking])
        return SendClientMessage(playerid, Erro, "Já arrombaram está casa");

    HouseInfo[houseid][hBreaking] = true;

    SetTimerEx("OnHouseBreaking", 300000, false, "d", houseid);

    format(String, MAX_STRING, "Casa ID %d foi arrombada pelo Policial %s[%d]", houseid, PlayerInfo[playerid][Nome], playerid);
    SendClientMessageToAll(0x2894FFAA, String);
    return 1;
}
