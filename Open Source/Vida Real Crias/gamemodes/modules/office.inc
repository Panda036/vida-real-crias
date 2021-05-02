#include YSI\y_hooks

hook OnGameModeInit()
{
    RespawnVeiculos = TextDrawCreate(317.799987, 192.346771, "");
    TextDrawLetterSize(RespawnVeiculos, 0.400000, 1.600000);
    TextDrawAlignment(RespawnVeiculos, 2);
    TextDrawSetOutline(RespawnVeiculos, -1);
    TextDrawFont(RespawnVeiculos, 1);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    Spying[playerid] = INVALID_PLAYER_ID;

    SetTimerEx("OnPlayerUpdateCreate", 3000, true, "d", playerid);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    viewcmds[playerid] = false;
	return 1;
}

hook OnPlayerExitVehicle(playerid, vehicleid)
{
    if(IsPlayerIntern(playerid))
    {
        for(new i = 0; i < MAX_VEHICLES; i++)
        {
            if(vehicleid == PublicVehicle[i][pv_vehicle] && PublicVehicle[i][pv_adm])
            {
                VehicleAdmin[playerid] = 0;
                DestroyVehicleEx(vehicleid);
                return 1;
            }
        }
    }
	return 1;
}

public OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
{
    if(IsPlayerIntern(playerid) && GetPlayerInterior(playerid) == 0 && !IsArena[playerid])
    {
        if(IsPlayerInAnyVehicle(playerid))
        {
            SetVehiclePos(GetPlayerVehicleID(playerid), fX, fY, fZ);
            PutPlayerInVehicle(playerid, GetPlayerVehicleID(playerid), GetPlayerVehicleSeat(playerid));
        }
        else
        {
            SetPlayerPosFindZ(playerid, fX, fY, fZ);
        }
    }
	return 1;
}

forward Respawn1();
public Respawn1()
{
    TextDrawHideForAll(RespawnVeiculos);
    SetTimer("Respawn2", 12*1000, false);
    return 1;
}

forward Respawn2();
public Respawn2()
{
    TextDrawSetString(RespawnVeiculos, "~r~>> ~w~Respawn de veiculos nao em uso em ~g~15 ~w~segundos... ~r~<<");
    TextDrawShowForAll(RespawnVeiculos);
    SetTimer("Respawn3", 3000, false);
    return 1;
}

forward Respawn3();
public Respawn3()
{
    TextDrawHideForAll(RespawnVeiculos);
    SetTimer("CountDown", 7000, false);
    return 1;
}

forward CountDown();
public CountDown()
{
    if(Count > 0)
    {
        GameTextForAll(ContadorTxT[Count-1], 2500, 3);
        Count--;
        SetTimer("CountDown", 1000, 0);
    }
    else
    {
        Respawnando = false;
        TextDrawHideForAll(RespawnVeiculos);
        SendClientMessageToAll(Yellow, "Todos os veiculos não em uso foram respawnados");
        GameTextForAll("~g~]] ~w~RESPAWNANDO~g~ ]]", 2500, 3);
        Count = 5;

        for(new vehicleid = 0; vehicleid < MAX_VEHICLES; vehicleid++)
        {
            if(PublicVehicle[vehicleid][pv_vehicle] == INVALID_VEHICLE_ID) continue;

            if(IsVehicleInUse(PublicVehicle[vehicleid][pv_vehicle])) continue;

            if(PublicVehicle[vehicleid][pv_id] == INVALID_PLAYER_ID)
            {
                if(IsVehicleBase(vehicleid) || IsVehicleSingle(vehicleid))
                {
                    DestroyVehicleEx(PublicVehicle[vehicleid][pv_vehicle]);
                    continue;
                }

                SetVehicleToRespawn(PublicVehicle[vehicleid][pv_vehicle]);
                continue;
            }

            new playerid = PublicVehicle[vehicleid][pv_id];

            if(!PV_Profission[playerid]){
                SetVehicleToRespawn(PublicVehicle[vehicleid][pv_vehicle]);
                continue;
            }

            DestroyPlayerVehicle(playerid);
            SendClientMessage(playerid, Red, "Seu veículo profissão não em uso destruído");
            continue;
        }
    }
    return 1;
}

forward RestartServer();
public RestartServer()
{
    SendClientMessageToAll(0xB9FFFFAA, "VRC-BOT ~ O Servidor reiniciará em 1 minuto");
    SetTimer("RestartServer1", 58000, false);
    return 1;
}

forward RestartServer1();
public RestartServer1()
{
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        Kick(i);
	}

    SendClientMessageToAll(0xB9FFFFAA, "VRC-BOT ~ O Servidor reiniciou, aguarde");
    SetTimer("RestartServer2", 2000, false);
    return 1;
}

forward RestartServer2();
public RestartServer2()
{
    SendRconCommand("gmx");
    return 1;
}

forward OnPlayerUpdateCreate(playerid);
public OnPlayerUpdateCreate(playerid)
{
    if(!PlayerInfo[playerid][Logado]) return 0;

    if(AntiAfk[playerid][aa_afk])
    {
        format(String, 100, "%s - AFK", PlayerInfo[playerid][Nome]);
        SetPlayerName(playerid, String);
    }

    if(IsPlayerYoutuber(playerid))
    {
        if(!IsPlayerMemberBaseEx(playerid))
            return SetPlayerChatBubble(playerid, "{800000}Youtuber", 0xFFFFFFAA, 50.0, 3000);

        new baseid = GetPlayerBaseID(playerid);

        format(String, 100, "{800000}Youtuber{FFFFFF} - {%s}%s", BaseInfo[baseid][bi_tagcolor], BaseInfo[baseid][bi_tag]);
        SetPlayerChatBubble(playerid, String, 0xFFFFFFAA, 50.0, 3000);
        return 1;
    }
    else if(IsPlayerVip(playerid))
    {
        if(!IsPlayerMemberBaseEx(playerid))
        {
            format(String, 100, "{%s}VIP", VipInfo[playerid][tagcolor]);
            SetPlayerChatBubble(playerid, String, 0xFFFFFFAA, 50.0, 3000);
            return 1;
        }

        new baseid = GetPlayerBaseID(playerid);

        format(String, 100, "{%s}VIP{FFFFFF} - {%s}%s", VipInfo[playerid][tagcolor], BaseInfo[baseid][bi_tagcolor], BaseInfo[baseid][bi_tag]);
        SetPlayerChatBubble(playerid, String, 0xFFFFFFAA, 50.0, 3000);
        return 1;
    }
    else if(IsPlayerIntern(playerid))
    {
        if(!IsPlayerMemberBaseEx(playerid))
        {
            format(String, 100, "%s", CargoAdminColor(playerid));
            SetPlayerChatBubble(playerid, String, 0x328E0AAA, 50.0, 3000);
            return 1;
        }

        new baseid = GetPlayerBaseID(playerid);

        format(String, 100, "%s{FFFFFF} - {%s}%s", CargoAdminColor(playerid), BaseInfo[baseid][bi_tagcolor], BaseInfo[baseid][bi_tag]);
        SetPlayerChatBubble(playerid, String, 0x328E0AAA, 50.0, 3000);
        return 1;
    }

    if(!IsPlayerMemberBaseEx(playerid)) return 0;

    new baseid = GetPlayerBaseID(playerid);

    format(String, 100, "{%s}%s", BaseInfo[baseid][bi_tagcolor], BaseInfo[baseid][bi_tag]);
    SetPlayerChatBubble(playerid, String, 0xFFFFFFAA, 50.0, 3000);
    return 1;
}

forward HideTextRespawn();
public HideTextRespawn()
{
    TextDrawHideForAll(RespawnVeiculos);
    return 1;
}

forward UnlockingReport(playerid);
public UnlockingReport(playerid)
{
    PlayerInfo[playerid][blockReport] = false;
    return true;
}

forward UnlockingDoubt(playerid);
public UnlockingDoubt(playerid)
{
    PlayerInfo[playerid][blockDoubt] = false;
    return true;
}

forward UnlockingAd(playerid);
public UnlockingAd(playerid)
{
    PlayerInfo[playerid][blockAd] = false;
    return true;
}

stock IsVehicleInUse(vehicleid)
{
    new VeiculoRcd;
    for(new i; i <= MAX_PLAYERS; i++)
    {
        if(GetPlayerVehicleID(i) == vehicleid)
            VeiculoRcd = vehicleid;
        if(GetVehicleTrailer(GetPlayerVehicleID(i)) == vehicleid)
            VeiculoRcd = vehicleid;
    }
    return VeiculoRcd;
}

stock CargoAdmin(playerid)
{
    new var[21];
    if(PlayerInfo[playerid][Admin] == 1 && PlayerInfo[playerid][sexo] == SEX_BOY) var = "Estagiário";
    if(PlayerInfo[playerid][Admin] == 1 && PlayerInfo[playerid][sexo] == SEX_GIRL) var = "Estagiária";
    if(PlayerInfo[playerid][Admin] == 2) var = "Ajudante";
    if(PlayerInfo[playerid][Admin] == 3 && PlayerInfo[playerid][sexo] == SEX_BOY) var = "Moderador";
    if(PlayerInfo[playerid][Admin] == 3 && PlayerInfo[playerid][sexo] == SEX_GIRL) var = "Moderadora";
    if(PlayerInfo[playerid][Admin] == 4 && PlayerInfo[playerid][sexo] == SEX_BOY) var = "Administrador";
    if(PlayerInfo[playerid][Admin] == 4 && PlayerInfo[playerid][sexo] == SEX_GIRL) var = "Administradora";
    if(PlayerInfo[playerid][Admin] == 5 && PlayerInfo[playerid][sexo] == SEX_BOY) var = "Coordenador";
    if(PlayerInfo[playerid][Admin] == 5 && PlayerInfo[playerid][sexo] == SEX_GIRL) var = "Coordenadora";
    if(PlayerInfo[playerid][Admin] == 6) var = "Desenvolvedor";
    return var;
}

stock CargoAdminColor(playerid)
{
    new var[50];
    if(PlayerInfo[playerid][Admin] == 1 && PlayerInfo[playerid][sexo] == SEX_BOY) var = "{804000}Estagiário{FFFFFF}";
    if(PlayerInfo[playerid][Admin] == 1 && PlayerInfo[playerid][sexo] == SEX_GIRL) var = "{804000}Estagiária{FFFFFF}";
    if(PlayerInfo[playerid][Admin] == 2) var = "{FFFF00}Ajudante{FFFFFF}";
    if(PlayerInfo[playerid][Admin] == 3 && PlayerInfo[playerid][sexo] == SEX_BOY) var = "{FF8C00}Moderador{FFFFFF}";
    if(PlayerInfo[playerid][Admin] == 3 && PlayerInfo[playerid][sexo] == SEX_GIRL) var = "{FF8C00}Moderadora{FFFFFF}";
    if(PlayerInfo[playerid][Admin] == 4 && PlayerInfo[playerid][sexo] == SEX_BOY) var = "{008BCE}Administrador{FFFFFF}";
    if(PlayerInfo[playerid][Admin] == 4 && PlayerInfo[playerid][sexo] == SEX_GIRL) var = "{008BCE}Administradora{FFFFFF}";
    if(PlayerInfo[playerid][Admin] == 5 && PlayerInfo[playerid][sexo] == SEX_BOY) var = "{FF0000}Coordenador{FFFFFF}";
    if(PlayerInfo[playerid][Admin] == 5 && PlayerInfo[playerid][sexo] == SEX_GIRL) var = "{FF0000}Coordenadora{FFFFFF}";
    if(PlayerInfo[playerid][Admin] == 6) var = "{328E0A}Desenvolvedor{FFFFFF}";
    return var;
}

stock GetFreeSeat(vehicleid)
{
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerInAnyVehicle(i) && GetPlayerVehicleID(i) == vehicleid)
        {
            for(new j = 0; j < 9; j++)
            {
                if(GetPlayerVehicleSeat(i) == j) continue;
                else return j;
            }
            return -1;
        }
    }
    return 1;
}

stock IsPlayerIntern(playerid)
{
    if(PlayerInfo[playerid][Admin] >= 1 && PlayerInfo[playerid][Admin] <= 6) return true;
    return false;
}

stock IsPlayerHelper(playerid)
{
    if(PlayerInfo[playerid][Admin] >= 2 && PlayerInfo[playerid][Admin] <= 6) return true;
    return false;
}

stock IsPlayerModerator(playerid)
{
    if(PlayerInfo[playerid][Admin] >= 3 && PlayerInfo[playerid][Admin] <= 6) return true;
    return false;
}

stock IsPlayerAdministrator(playerid)
{
    if(PlayerInfo[playerid][Admin] >= 4 && PlayerInfo[playerid][Admin] <= 6) return true;
    return false;
}

stock IsPlayerCoordinator(playerid)
{
    if(PlayerInfo[playerid][Admin] >= 5 && PlayerInfo[playerid][Admin] <= 6) return true;
    return false;
}

stock IsPlayerDeveloper(playerid)
{
    if(PlayerInfo[playerid][Admin] == 6) return true;
    return false;
}

//COMMANDS

#include modules\player\command\cmds_intern
#include modules\player\command\cmds_helper
#include modules\player\command\cmds_moderator
#include modules\player\command\cmds_administrator
#include modules\player\command\cmds_coordinator
#include modules\player\command\cmds_developer

alias:vercomandos("vercmds");
alias:criarveiculo("cv");
