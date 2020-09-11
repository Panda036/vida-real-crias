#include YSI\y_hooks

enum enum_slp
{
    slp_sex[10],
    slp_skinid
};

new SkinList[MAX_PLAYERS];
new SkinListPolice[21][enum_slp] =
{
    {"Feminino", 191},
    {"Masculino", 265},
    {"Masculino", 266},
    {"Masculino", 267},
    {"Masculino", 280},
    {"Masculino", 281},
    {"Masculino", 282},
    {"Masculino", 283},
    {"Masculino", 284},
    {"Masculino", 285},
    {"Masculino", 286},
    {"Masculino", 287},
    {"Masculino", 288},
    {"Masculino", 300},
    {"Masculino", 301},
    {"Masculino", 302},
    {"Feminino", 306},
    {"Feminino", 307},
    {"Feminino", 309},
    {"Masculino", 310},
    {"Masculino", 311}
};

hook OnGameModeInit()
{
    CreateDynamic3DTextLabel("{808080}Uniforme\n{FFFFFF}Precione \"N\"", 0xFFFFFFFF, 254.54, 78.19, 1003.64, 30.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
    CreateDynamicPickup(1275, 1, 254.54, 78.19, 1003.64);

    CreateDynamicCP(248.9497, 67.6059, 1003.6406, 1.0, -1, -1, -1, 30.0);   //CPS Presos
    return 1;
}

hook OnPlayerConnected(playerid)
{
    SetTimerEx("wheeldamage", 200, true, "d", playerid);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(PRESSED(KEY_SECONDARY_ATTACK))
    {
        if(IsPlayerHelper(playerid) || IsPlayerPolice(playerid))
        {
            OpeningPolicePort(playerid);
        }
    }
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
	return 1;
}

forward ObjectDestroy(playerid);
public ObjectDestroy(playerid)
{
    if(TapeteInfo[playerid][tpt_obj])
        { DestroyDynamicObject(TapeteInfo[playerid][tpt_obj]); }
    if(TapeteInfo[playerid][tpt_label])
        { DestroyDynamic3DTextLabel(TapeteInfo[playerid][tpt_label]); }
    if(BarrierObj[playerid])
        { DestroyDynamicObject(BarrierObj[playerid]); }
    if(BarrierLabel[playerid])
        { DestroyDynamic3DTextLabel(BarrierLabel[playerid]); }
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
    format(String, sizeof(String), "O(A) jogador(a) %s[%d] não está sendo mais perseguido pela pocilia por passar 5 minutos!", PlayerInfo[playerid][Nome], playerid);
    SendClientMessage(playerid, 0x2894FFAA, String);
    SendClientMessage(playerid, 0xB9FFFFAA, "Você não está mas em perseguição");
    KillTimer(PerseguicaoTime[playerid]);
    Perseguicao[playerid] = false;
    Abordado[playerid] = false;
    return 1;
}

stock IsPlayerPolice(playerid)
{
    switch(PlayerInfo[playerid][Profissao])
    {
        case military..interpol: return 1;
        case navy..aeronautics: return 1;
        default: return 0;
    }
    return 1;
}

stock IsPlayerUniformPM(playerid)
{
    for(new i = 0; i < 21; i++)
    {
        if(GetPlayerSkin(playerid) == SkinListPolice[i][slp_skinid]) return true;
    }
    return false;
}

/******************************************************************************/
/*****************************| COMMANDS POLICE |******************************/
/******************************************************************************/

CMD:barreira(playerid)
{
    if(!IsPlayerPolice(playerid))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsPlayerUniformPM(playerid))
        return SendClientMessage(playerid, Erro, "Você não está com o uniforme");

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

        format(String, sizeof(String), "{FFFFFF}%s {FF0000}%s", NameProfission(PlayerInfo[playerid][Profissao]), PlayerInfo[playerid][Nome]);
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

    if(!IsPlayerUniformPM(playerid))
        return SendClientMessage(playerid, Erro, "Você não está com o uniforme");

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

        format(String, sizeof(String), "{FFFFFF}%s {FF0000}%s", NameProfission(PlayerInfo[playerid][Profissao]), PlayerInfo[playerid][Nome]);
        TapeteInfo[playerid][tpt_obj] = CreateDynamicObject(2899, TapeteInfo[playerid][tpt_x], TapeteInfo[playerid][tpt_y], TapeteInfo[playerid][tpt_z]-0.9, 0.0, 0.0, a-90, -1, -1, -1, 200.0);
        TapeteInfo[playerid][tpt_label] = CreateDynamic3DTextLabel(String, 0xFFFFFFFF, TapeteInfo[playerid][tpt_x], TapeteInfo[playerid][tpt_y], TapeteInfo[playerid][tpt_z]-0.9, 200.0);

        GameTextForPlayer(playerid,"~w~Tapede criado", 3000, 1);
        SetTimerEx("ObjectDestroy", 600000, false, "d", playerid);
    }
 	return 1;
}

CMD:equipar(playerid)
{
    if(!IsPlayerInRangeOfPoint(playerid, 1.5, 254.1715,74.3339,1003.6406))
        return SendClientMessage(playerid, Erro, "Você não está no vestiário do Departamento de Polícia");

    if(!IsPlayerPolice(playerid))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

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
    if(!IsPlayerInRangeOfPoint(playerid, 1.5, 254.1715,74.3339,1003.6406))
        return SendClientMessage(playerid, Erro, "Você não está no vestiário do Departamento de Polícia");

    if(!IsPlayerPolice(playerid))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsPlayerUniformPM(playerid))
        return SendClientMessage(playerid, Erro, "Você não está com o uniforme");

    SetPlayerSkin(playerid, PlayerInfo[playerid][skin]);
    SendClientMessage(playerid, White, "Uniforme removido");
    return 1;
}
CMD:prenderarmas(playerid, params[])
{
    if(!IsPlayerPolice(playerid))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsPlayerUniformPM(playerid))
        return SendClientMessage(playerid, Erro, "Você não está com o uniforme");

    new id;

    if(sscanf(params, "u", id))
        return SendClientMessage(playerid, Erro, "Digite: /Prenderarmas [id/nome]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não está conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    if(GetDistanceBetweenPlayers(playerid, id) > 15)
        return SendClientMessage(playerid, Erro, "Você está muito longe, chegue mais perto");

    if(PlayerInfo[id][Estrelas] == 0)
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) não está procurado(a)");

    ResetPlayerWeapons(id);
    format(String, sizeof(String), "Você prendeu todas as armas do(a) jogador(a) %s[%d]!", PlayerInfo[id][Nome], id);
    SendClientMessage(playerid, 0x2894FFAA, String);
    format(String, sizeof(String), "O(A) Policial %s[%d] prendeu todas as suas armas!", PlayerInfo[playerid][Nome], playerid);
    SendClientMessage(id, 0x2894FFAA, String);
    return 1;
}
CMD:perseguicao(playerid, params[])
{
    if(!IsPlayerPolice(playerid))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsPlayerUniformPM(playerid))
        return SendClientMessage(playerid, Erro, "Você não está com o uniforme");

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

    Perseguicao[id]=true;
    PerseguicaoTime[id] = SetTimerEx("ExitPersecution", 1000*60*5, false, "i", id);
    format(String, sizeof(String), "O(A) Policial %s[%d] iniciou uma perseguição no(a) jogador(a) %s[%d] por não se render!", PlayerInfo[playerid][Nome], playerid, PlayerInfo[id][Nome], id);
    SendClientMessageToAll(0x2894FFAA, String);
    return 1;
}
CMD:abordar(playerid, params[])
{
    if(!IsPlayerPolice(playerid))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsPlayerUniformPM(playerid))
        return SendClientMessage(playerid, Erro, "Você não está com o uniforme");

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

    if(PlayerInfo[id][Estrelas] == 0)
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) não está procurado(a)");

    Abordado[id] = true;
    GameTextForPlayer(id, "~b~Abordagem!", 1000, 0);
    format(String, 128, "Você foi abordado pelo Policial %s[%d]", PlayerInfo[playerid][Nome], playerid);
    SendClientMessage(id, 0x2894FFAA, String);
    format(String, 128, "Você abordou o(a) Jogador(a) %s[%d]", PlayerInfo[id][Nome], id);
    SendClientMessage(playerid, 0x2894FFAA, String);
    return 1;
}
CMD:algemar(playerid, params[])
{
    if(!IsPlayerPolice(playerid))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsPlayerUniformPM(playerid))
        return SendClientMessage(playerid, Erro, "Você não está com o uniforme");

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

    if(Algemado[id])
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) já está algemado(a)");

    if(IsPlayerInAnyVehicle(playerid) == 1)
        return SendClientMessage(playerid, Erro, "Você está em um veiculo");

    if(IsPlayerInAnyVehicle(id) == 1)
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) está em um veiculo");

    Abordado[id] = false;
    Algemado[id] = true;
    TogglePlayerControllable(id, false);
    SetPlayerSpecialAction(id, SPECIAL_ACTION_CUFFED);
    SetPlayerAttachedObject(id,4,19418,6,-0.031999,0.024000,-0.024000,-7.900000,-32.000011,-72.299987,1.115998,1.322000,1.406000);

    GameTextForPlayer(id, "~b~ALGEMADO!", 1000, 0);
    format(String, 128, "Você algemou o(a) Jogador(a) %s[%d]", PlayerInfo[id][Nome], id);
    SendClientMessage(playerid, 0x2894FFAA, String);
    format(String, 128, "Você foi algemado pelo Policial %s[%d]", PlayerInfo[playerid][Nome], playerid);
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

    if(!Algemado[id])
        return SendClientMessage(playerid, Erro, "O(a) Jogador(a) precisa estar algemado para prender");

    Algemado[id] = false;
    RemovePlayerAttachedObject(id, 4);
    TogglePlayerControllable(id, true);
    SetPlayerSpecialAction(id, SPECIAL_ACTION_NONE);
    PlayerInfo[playerid][Dinheiro] += ( PlayerInfo[id][Estrelas]*100 );
    UpdatePlayerMoney(playerid);

    KillTimer(PerseguicaoTime[playerid]);
    format(PrisonEnum[id][pCadeia], 15, "Municipal");
    format(PrisonEnum[id][pMotivo], 15, "Procurado(a)");
    PrisonEnum[id][pTempo] = PlayerInfo[id][Estrelas]*60;

    ResetPlayerWeapons(id);
    SetPlayerInterior(id, 6);
    SetPlayerHealth(id, 99999);
    SetPlayerPos(id, 264.2374, 77.4612, 1001.0391);

    PlayerTextDrawShow(id, TempoPresidio[id][1]);
    PlayerTextDrawShow(id, TempoPresidio[id][0]);

    format(String, sizeof(String), "Você foi preso pelo Policial %s ( Motivo: Procurado(a) )", PlayerInfo[playerid][Nome]);
    SendClientMessage(id, 0x2894FFAA, String);
    format(String, sizeof(String), "Você prendeu o(a) Jogador(a) %s ( Procurado(a) )", PlayerInfo[id][Nome]);
    SendClientMessage(playerid, 0x2894FFAA, String);
    format(String, sizeof(String), "Você recebeu a recompensa de $%d por prender um jogador(a) que estava sendo procurado(a) pela policia", PlayerInfo[id][Estrelas]*100);
    SendClientMessage(playerid, 0x2894FFAA, String);

    GameTextForPlayer(id, "~w~~h~PRESO!", 2000, 0);
    SendClientMessage(id, 0x2894FFAA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Prisão ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    SendClientMessage(id, White, "•» Você está preso");
    format(String, sizeof(String), "•» Foi preso por ( %s )", PlayerInfo[playerid][Nome]);
    SendClientMessage(id, White, String);
    format(String, sizeof(String), "•» Motivo da prisão ( %s )", PrisonEnum[id][pMotivo]);
    SendClientMessage(id, White, String);
    SendClientMessage(id, 0x2894FFAA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Prisão ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    mysql_format(IDConexao, String, sizeof(String), "INSERT INTO `Prison` (`responsible`, `chain`, `reason`, `time`, `id_contas`) VALUES ('%e', '%e', '%e', '%d', '%d')", PlayerInfo[playerid][Nome], PrisonEnum[id][pCadeia], PrisonEnum[id][pMotivo], PrisonEnum[id][pTempo], PlayerInfo[id][ID]);
    mysql_query(IDConexao, String);

    PrisonSystem(id);
    return 1;
}

CMD:procurados(playerid)
{
    if(!IsPlayerPolice(playerid))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsPlayerUniformPM(playerid))
        return SendClientMessage(playerid, Erro, "Você não está com o uniforme");

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
