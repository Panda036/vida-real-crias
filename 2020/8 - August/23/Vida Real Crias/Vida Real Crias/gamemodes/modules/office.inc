#include YSI\y_hooks

new Count = 5;
new ContadorTxT[5][19] =
{
	"~y~] ]~w~ 1 ~y~] ]",
	"~y~] ]~w~ 2 ~y~] ]",
	"~r~] ]~w~ 3 ~r~] ]",
	"~r~] ]~w~ 4 ~r~] ]",
	"~r~] ]~w~ 5 ~r~] ]"
};

new bool:LiberarRelatorio[MAX_PLAYERS];
new bool:LiberarDuvida[MAX_PLAYERS];

new bool:Respawnando;
new Text:RespawnVeiculos;

new Float:stopspying[4];

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

forward RestartServer();
public RestartServer()
{
    SendClientMessageToAll(0xB9FFFFAA, "O Server reiniciara em 1 minuto");
    SetTimer("RestartServer1", 58000, false);
    return 1;
}

forward RestartServer1();
public RestartServer1()
{
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(PlayerInfo[i][Logado])
        {
            LeftArena(i);
            LeftBusiness(i);
            LeftHouse(i);
            LeftEnterExit(i);
            SaveAccounts(i);
            Kick(i);
        }
	}

    SendClientMessageToAll(0xB9FFFFAA, "O Server reinicio aguarde");
    SetTimer("RestartServer2", 2000, false);
    return 1;
}

forward RestartServer2();
public RestartServer2()
{
    SendRconCommand("gmx");
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
        Count=5;

        for(new i; i < MAX_VEHICLES; i++)
        {
            if(!IsVehicleInUse(i)){ SetVehicleToRespawn(i); }
        }
    }
    return 1;
}

forward OnPlayerUpdateCreate(playerid);
public OnPlayerUpdateCreate(playerid)
{
    if(!PlayerInfo[playerid][Logado]) return 0;

    if(IsPlayerYoutuber(playerid))
    {
        format(String, 100, "[{800000}Youtuber{FFFFFF}]%s", (AntiAfk[playerid][aa_afk] ? ("{FFFFFF} - AFK") : (#)));

        SetPlayerChatBubble(playerid, String, 0xFFFFFFAA, 50.0, 3000);
    }
    else if(IsPlayerVip(playerid))
    {
        format(String, 100, "[{%s}VIP{FFFFFF}]%s", VipInfo[playerid][tagcolor], (AntiAfk[playerid][aa_afk] ? ("{FFFFFF} - AFK") : (#)));

        SetPlayerChatBubble(playerid, String, 0xFFFFFFAA, 50.0, 3000);
    }
    else if(IsPlayerIntern(playerid))
    {
        format(String, 100, "%s%s", CargoAdmin(playerid), (AntiAfk[playerid][aa_afk] ? ("{FFFFFF} - AFK") : (#)));

        switch(PlayerInfo[playerid][Admin])
        {
            case 1: SetPlayerChatBubble(playerid, String, 0x804000AA, 50.0, 3000);
            case 2: SetPlayerChatBubble(playerid, String, 0xFFFF00AA, 50.0, 3000);
            case 3: SetPlayerChatBubble(playerid, String, 0xFF8C00AA, 50.0, 3000);
            case 4: SetPlayerChatBubble(playerid, String, 0x008BCEAA, 50.0, 3000);
            case 5: SetPlayerChatBubble(playerid, String, 0xFF0000AA, 50.0, 3000);
            case 6: SetPlayerChatBubble(playerid, String, 0x328E0AAA, 50.0, 3000);
        }
    }
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
    LiberarRelatorio{playerid} = false;
    return true;
}

forward UnlockingDoubt(playerid);
public UnlockingDoubt(playerid)
{
    LiberarDuvida{playerid} = false;
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
    if(PlayerInfo[playerid][Admin] == 1 && !strcmp(PlayerInfo[playerid][sexo], "Masculino")) var = "Estagiário";
    if(PlayerInfo[playerid][Admin] == 1 && !strcmp(PlayerInfo[playerid][sexo], "Feminino")) var = "Estagiária";
    if(PlayerInfo[playerid][Admin] == 2) var = "Ajudante";
    if(PlayerInfo[playerid][Admin] == 3 && !strcmp(PlayerInfo[playerid][sexo], "Masculino")) var = "Moderador";
    if(PlayerInfo[playerid][Admin] == 3 && !strcmp(PlayerInfo[playerid][sexo], "Feminino")) var = "Moderadora";
    if(PlayerInfo[playerid][Admin] == 4 && !strcmp(PlayerInfo[playerid][sexo], "Masculino")) var = "Administrador";
    if(PlayerInfo[playerid][Admin] == 4 && !strcmp(PlayerInfo[playerid][sexo], "Feminino")) var = "Administradora";
    if(PlayerInfo[playerid][Admin] == 5 && !strcmp(PlayerInfo[playerid][sexo], "Masculino")) var = "Coordenador";
    if(PlayerInfo[playerid][Admin] == 5 && !strcmp(PlayerInfo[playerid][sexo], "Feminino")) var = "Coordenadora";
    if(PlayerInfo[playerid][Admin] == 6) var = "Desenvolvedor";
    return var;
}

stock CargoAdminColor(playerid)
{
    new var[50];
    if(PlayerInfo[playerid][Admin] == 1 && !strcmp(PlayerInfo[playerid][sexo], "Masculino")) var = "{804000}Estagiário{FFFFFF}";
    if(PlayerInfo[playerid][Admin] == 1 && !strcmp(PlayerInfo[playerid][sexo], "Feminino")) var = "{804000}Estagiária{FFFFFF}";
    if(PlayerInfo[playerid][Admin] == 2) var = "{FFFF00}Ajudante{FFFFFF}";
    if(PlayerInfo[playerid][Admin] == 3 && !strcmp(PlayerInfo[playerid][sexo], "Masculino")) var = "{FF8C00}Moderador{FFFFFF}";
    if(PlayerInfo[playerid][Admin] == 3 && !strcmp(PlayerInfo[playerid][sexo], "Feminino")) var = "{FF8C00}Moderadora{FFFFFF}";
    if(PlayerInfo[playerid][Admin] == 4 && !strcmp(PlayerInfo[playerid][sexo], "Masculino")) var = "{008BCE}Administrador{FFFFFF}";
    if(PlayerInfo[playerid][Admin] == 4 && !strcmp(PlayerInfo[playerid][sexo], "Feminino")) var = "{008BCE}Administradora{FFFFFF}";
    if(PlayerInfo[playerid][Admin] == 5 && !strcmp(PlayerInfo[playerid][sexo], "Masculino")) var = "{FF0000}Coordenador{FFFFFF}";
    if(PlayerInfo[playerid][Admin] == 5 && !strcmp(PlayerInfo[playerid][sexo], "Feminino")) var = "{FF0000}Coordenadora{FFFFFF}";
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

new CountClearChat[MAX_PLAYERS] = 10;

forward OnClearChat(playerid);
public OnClearChat(playerid)
{
    switch(CountClearChat[playerid])
    {
        case 0:
        {
            CountClearChat[playerid] = 10;
            return 1;
        }
        case 2, 4, 6, 8, 10:
        {
            for(new i = 0; i < 30; i++)
            {
                SendClientMessageToAll(White, "");
            }
        }
    }

    CountClearChat[playerid]--;
    SetTimerEx("OnClearChat", 500, false, "d", playerid);
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

stock IsPlayerAdmininstrator(playerid)
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

/******************************************************************************/
/*************************| COMMANDS ADMININSTRATION |*************************/
/******************************************************************************/

//=• INTERN'S

CMD:avls(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    SetPlayerPos(playerid,1022.4510,-1121.5958,23.8719);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para Área Vip de Los Santos");
    return 1;
}
CMD:avlv(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    SetPlayerPos(playerid,2015.0763,1106.6337,10.8203);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para Área Vip de Las Venturas");
    return 1;
}
CMD:avsf(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    SetPlayerPos(playerid,-2664.4136,-7.4449,6.1328);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para Área Vip de San Fierro");
    return 1;
}
CMD:apls(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    SetPlayerPos(playerid,1962.2162,-2178.3967,13.5469);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para o Aeroporto de Los Santos");
    return 1;
}
CMD:aplv(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    SetPlayerPos(playerid, 1712.0634, 1606.1857, 10.0156);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para o Aeroporto de Las Venturas");
    return 1;
}
CMD:apsf(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid,-1740.7712,-579.3079,16.3359);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para o Aeroporto de San Fierro");
    return 1;
}
CMD:apab(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    SetPlayerPos(playerid,431.5682,2506.1760,16.4844);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para o Aeroporto Abandonado");
    return 1;
}
CMD:agls(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    SetPlayerPos(playerid,1154.0808,-1771.9812,16.5992);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para Agencia de Los Santos");
    return 1;
}
CMD:aglv(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    SetPlayerPos(playerid,937.8450,1733.1957,8.8516);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para Agencia de Las Venturas");
    return 1;
}
CMD:agsf(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    SetPlayerPos(playerid,-2171.8110,252.0813,35.3378);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para Agencia de San Fierro");
    return 1;
}
CMD:pfls(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    SetPlayerPos(playerid,1481.0637,-1770.9515,18.7958);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para Prefeitura de Los Santos");
    return 1;
}
CMD:pflv(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    SetPlayerPos(playerid,2447.0620,2376.2354,12.1635);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para Prefeitura de Las Venturas");
    return 1;
}
CMD:pfsf(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid,-2765.8796,375.5812,6.3347);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para Prefeitura de San Fierro");
    return 1;
}
CMD:dpls(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid,1554.8657,-1675.6693,16.1953);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para o Departamento de Polícia de Los Santos");
    return 1;
}
CMD:dplv(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid,2290.1218,2430.9775,10.8203);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para o Departamento de Polícia de Las Venturas");
    return 1;
}
CMD:dpsf(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid,-1605.5848,710.8436,13.8672);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para o Departamento de Polícia de San Fierro");
    return 1;
}
CMD:dpdm(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid,627.7621,-571.7207,17.5526);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para o Departamento de Polícia de Dillimore");
    return 1;
}
CMD:dpfc(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid, -217.5554, 979.1621, 19.5025);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para o Departamento de Polícia de Fort Carson");
    return 1;
}
CMD:dpap(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid, -2162.0627, -2385.7957, 30.6250);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para o Departamento de Polícia de Angel Pine");
    return 1;
}
CMD:dpeq(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid, -1390.0345, 2638.0100, 55.9844);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para o Departamento de Polícia de El Quebrados");
    return 1;
}
CMD:hpls(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid,1172.6787,-1323.3129,15.4022);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para o Hospital de Los Santos");
    return 1;
}
CMD:hplv(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid,1607.3579,1815.6309,10.8203);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para o Hospital de Las Venturas");
    return 1;
}
CMD:hpsf(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid,-2655.0662,639.1497,14.4531);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para o Hospital de San Fierro");
    return 1;
}
CMD:hpeq(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid,-1514.8217,2520.3232,55.9185);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para o Hospital de El Quebrados");
    return 1;
}
CMD:hpmg(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid,1241.8073,327.1022,19.7555);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para o Hospital de Montgomery");
    return 1;
}
CMD:hpfc(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid,-320.0716,1049.2637,20.3403);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para o Hospital de Fort Carson");
    return 1;
}
CMD:bcls(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid,1778.3052,-1663.5337,14.4362);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para o Banco de Los Santos");
    return 1;
}
CMD:bclv(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid,2388.6733,2466.0430,10.8203);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para o Banco de Las Venturas");
    return 1;
}
CMD:bcsf(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid,-2649.8374,376.0090,6.1563);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para o Banco de San Fierro");
    return 1;
}
CMD:bcfc(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid,-180.3883,1133.1510,19.7422);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para o Banco de Fort Carson");
    return 1;
}
CMD:bcmg(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid,1372.9271,405.2487,19.9555);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para o Banco de Montgomery");
    return 1;
}
CMD:bcpc(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid,2302.9521,-16.2789,26.4844);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para o Banco de Palomino Creek");
    return 1;
}
CMD:bclb(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid,-828.0650,1503.6166,19.7585);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para o Banco de Las Barrancas");
    return 1;
}
CMD:bceq(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid,-1480.8273,2592.3015,55.8359);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para o Banco de El Quebrados");
    return 1;
}
CMD:bcbb(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid,207.7767,-62.5814,1.6498);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para o Banco de BlueBerry");
    return 1;
}
CMD:ibls(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid,1798.4763,-1578.3191,14.0849);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para Imobiliaria de Los Santos");
    return 1;
}
CMD:iblv(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid,2413.2390,1123.8374,10.8203);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para Imobiliaria de Las Venturas");
    return 1;
}
CMD:ibsf(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid,-1881.1293,822.7573,35.1773);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para Imobiliaria de San Fierro");
    return 1;
}
CMD:aels(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid,1519.0413,-1453.5895,14.2073);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para o Auto Escola de Los Santos");
    return 1;
}
CMD:aelv(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid,2183.2483,2295.2205,10.8203);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para o Auto Escola de Las Venturas");
    return 1;
}
CMD:aesf(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid,-2026.5950,-101.3410,35.1641);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para Auto Escola de San Fierro");
    return 1;
}
CMD:dtls(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid,1310.1411,-1367.8086,13.5408);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para o Detran de Los Santos");
    return 1;
}
CMD:dtlv(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid,1173.1600,1349.0011,10.9219);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para o Detran de Las Venturas");
    return 1;
}
CMD:dtsf(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid,-2720.6375,127.7373,7.0391);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para o Detran de San Fierro");
    return 1;
}
CMD:bs(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

	SetPlayerPos(playerid, -2429.4663, 2329.1987, 4.9844);
    SendClientMessage(playerid, adm, "| VRC-Admin | Você se teletransportou para Bayside");
    return 1;
}
CMD:tps(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new textos[1000];
    strcat(textos, "{FF0000}•{FFFFFF} /avls - avlv - avsf : Áreas VIP's \n");
    strcat(textos, "{FF0000}•{FFFFFF} /apls - aplv - apsf - /apab : Aeroportos \n");
    strcat(textos, "{FF0000}•{FFFFFF} /agls - aglv - agsf : Agencia de Empregos \n");
    strcat(textos, "{FF0000}•{FFFFFF} /pfls - pflv - pfsf : Prefeitura \n");
    strcat(textos, "{FF0000}•{FFFFFF} /dpls - dplv - dpsf - dpdm : Departamento de Polícia \n");
    strcat(textos, "{FF0000}•{FFFFFF} /dpap - dpfc - dpeq : Departamento de Polícia \n");
    strcat(textos, "{FF0000}•{FFFFFF} /hpls - hplv - hpsf : Hospital \n");
    strcat(textos, "{FF0000}•{FFFFFF} /hpeq - hpmg - hpfc : Hospital \n");
    strcat(textos, "{FF0000}•{FFFFFF} /bcls - bclv - bcsf : Banco \n");
    strcat(textos, "{FF0000}•{FFFFFF} /bcfc - bcmg - bcpc : Banco \n");
    strcat(textos, "{FF0000}•{FFFFFF} /bclb - bceq - bcbb : Banco \n");
    strcat(textos, "{FF0000}•{FFFFFF} /ibls - iblv - ibsf : Imobilíaria \n");
    strcat(textos, "{FF0000}•{FFFFFF} /aels - aelv - aesf : Auto Escola \n");
    strcat(textos, "{FF0000}•{FFFFFF} /dtls - dtlv - dtsf : Detran \n");
    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Teletransportes", textos, "Fechar", "");
    return 1;
}
CMD:vertutorial(playerid, params[])
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new id;

    if(sscanf(params, "d", id))
        return SendClientMessage(playerid, Erro, "Digite: /VerTurorial [id]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(PlayerInfo[id][tutorial])
    {
        SendClientMessage(playerid, adm, "O(A) Jogador(a) está no turorial");
    }
    else
    {
        SendClientMessage(playerid, adm, "O(A) Jogador(a) não está no turorial");
    }
    return 1;
}
CMD:r(playerid, params[])
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new id, txt[128];

    if(sscanf(params, "us[128]", id, txt))
        return SendClientMessage(playerid, Erro, "Digite: /R [id/nome] [resposta]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    format(String, MAX_STRING, "| Resposta | Você respondeu a duvida ou o relatório do jogador(a) %s[%d]", PlayerInfo[id][Nome], id);
    SendClientMessage(playerid, White, String);
    format(String, MAX_STRING, "| Resposta | %s %s respondeu : %s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], txt);
    SendClientMessage(id, adm, String);
    return 1;
}
CMD:lc(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    OnClearChat(playerid);
    return 1;
}

CMD:cornome(playerid)
{
    if(!IsPlayerHelper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    ShowPlayerDialog(playerid, colorname, DIALOG_STYLE_INPUT, "{FF0000}Cor nome", "{FFFFFF}Digite um codigo em '{FF0000}HTML{FFFFFF}' abaixo\nPesquise no Google algo como {00FF00}Cores em HTML {FFFFFF}:\n{FF0000}Exemplo {FFFFFF}00FF00 = {00FF00}Calenzo", "Alterar", "Cancelar");
    return 1;
}

CMD:desprocurar(playerid, params[])
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new id;

    if(sscanf(params, "u", id))
        return SendClientMessage(playerid, Erro, "Digite: /Desprocurar [id/nome]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(PlayerInfo[id][Estrelas] == 0)
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) não está procurado(a)");

    PlayerInfo[id][Estrelas] = 0;
    format(String, sizeof(String), "%d", PlayerInfo[id][Estrelas]);
    PlayerTextDrawSetString(id, PlayerBarStatus[id][1], String);
    PlayerTextDrawShow(id, PlayerBarStatus[id][1]);

    format(String, sizeof(String), "| VRC-Admin | O(A) %s %s removeu todas as suas estrelas", CargoAdmin(id), PlayerInfo[playerid][Nome]);
    SendClientMessage(id, adm, String);
    format(String, sizeof(String), "| VRC-Admin | Você removeu todas as estrelas do jogador(a) %s[%d]", PlayerInfo[id][Nome], id);
    SendClientMessage(playerid, adm, String);
    return 1;
}
CMD:respawnveiculos(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    if(Respawnando)
        return SendClientMessage(playerid, Erro, "Veiculos não em uso já está sendo respawnados");

    Respawnando = true;
    TextDrawSetString(RespawnVeiculos, "~r~>> ~w~Respawn de veiculos nao em uso em ~g~30 ~w~segundos... ~r~<<");
    TextDrawShowForAll(RespawnVeiculos);
    SetTimer("Respawn1", 3*1000, false);
    return 1;
}
CMD:avisar(playerid, params[])
{
    if(!IsPlayerHelper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new id, cause[24];

    if(sscanf(params, "us[24]", id, cause))
        return SendClientMessage(playerid, Erro, "Digite: /Avisar [id/nome] [motivo]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    if(PrisonEnum[id][pTempo] != 0)
        return SendClientMessage(playerid, Erro, "O(A) jogador(a) está preso");

    PlayerInfo[id][Avisos]++;
    format(String, sizeof(String), "| VRC-Admin | O(A) %s %s avisou o(a) jogador(a) %s ( %d/3 )( Motivo: %s )", CargoAdmin(playerid), PlayerInfo[playerid][Nome], PlayerInfo[id][Nome], PlayerInfo[id][Avisos], cause);
    SendClientMessageToAll(Red, String);

    mysql_format(IDConexao, String, sizeof(String), "UPDATE `Identidade` SET `avisos`='%d' WHERE `id_contas`='%d'", PlayerInfo[id][Avisos], PlayerInfo[id][ID]);
    mysql_query(IDConexao, String);

    if(PlayerInfo[id][Avisos] == 3)
    {
        PlayerInfo[id][Avisos] = 0;
        PrisonEnum[id][pTempo] = 60*30;
        format(PrisonEnum[id][pCadeia], 7, "Federal");
        format(PrisonEnum[id][pMotivo], 24, cause);
        format(PrisonEnum[id][pResponsavel], 24, PlayerInfo[playerid][Nome]);

        format(String, sizeof(String), "| VRC-Admin | Por receber 3 avisos o(a) jogador(a) %s foi preso por 30 minutos!", PlayerInfo[id][Nome]);
        SendClientMessageToAll(Red, String);
        SendClientMessage(id, 0x2894FFAA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Preso ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        SendClientMessage(id, White, "» Você está preso");
        format(String, sizeof(String), "» Foi preso por ( %s )", PlayerInfo[id][Nome]);
        SendClientMessage(id, White, String);
        format(String, sizeof(String), "» Motivo da prisão ( %s )", cause);
        SendClientMessage(id, White, String);
        SendClientMessage(id, 0x2894FFAA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Preso ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

        mysql_format(IDConexao, String, sizeof(String), "UPDATE `Identidade` SET `avisos`='%d' WHERE `id_contas`='%d'", PlayerInfo[id][Avisos], PlayerInfo[id][ID]);
        mysql_query(IDConexao, String);

        mysql_format(IDConexao, String, sizeof(String), "INSERT INTO `Prisoes` (`Nome`, `Responsavel`, `Cadeia`, `Motivo`, `Tempo`) VALUES ('%e', '%e', '%e', '%e', '%d')", PlayerInfo[id][Nome], PrisonEnum[id][pResponsavel], PrisonEnum[id][pCadeia], PrisonEnum[id][pMotivo], PrisonEnum[id][pTempo]);
        mysql_query(IDConexao, String);

        mysql_format(IDConexao, String, sizeof(String), "SELECT * FROM `Prisoes` WHERE `ID`='%d'", PlayerInfo[id][ID]);
        mysql_tquery(IDConexao, String, "DBLoadPrisons", "i", id);
    }
    return 1;
}

CMD:espiar(playerid, params[])
{
    if(!IsPlayerHelper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new id;

    if(sscanf(params, "u", id))
        return SendClientMessage(playerid, Erro, "Digite: /Espiar [id/nome]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    if(PlayerInfo[id][tutorial])
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) está no tutorial");

    GetPlayerFacingAngle(playerid, stopspying[3]);
    GetPlayerPos(playerid, stopspying[0], stopspying[1], stopspying[2]);

    TogglePlayerSpectating(playerid, true);
    PlayerSpectatePlayer(playerid, id);
    SetPlayerInterior(playerid, GetPlayerInterior(id));
    SendClientMessage(playerid, adm, "| VRC-Admin | Comando efetuado com sucesso");
    return 1;
}
CMD:pararespiar(playerid)
{
    if(!IsPlayerHelper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    SetPlayerInterior(playerid, 0);
    TogglePlayerSpectating(playerid, false);
    SetPlayerFacingAngle(playerid, stopspying[3]);
    SetPlayerPos(playerid, stopspying[0], stopspying[1], stopspying[2]);
    SendClientMessage(playerid, adm, "| VRC-Admin | Comando efetuado com sucesso");
    return 1;
}
CMD:tapa(playerid, params[])
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new id, Float:x, Float:y, Float:z;

    if(sscanf(params, "u", id))
        return SendClientMessage(playerid, Erro, "Digite: /Tapa [id/nome]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    GetPlayerPos(id, x, y, z);
    SetPlayerPos(id, x, y, z+50);
    format(String, sizeof(String), "| VRC-Admin | O(A) %s %s te deu um tapa!", CargoAdmin(playerid), PlayerInfo[playerid][Nome]);
    SendClientMessage(id, adm, String);
    format(String, sizeof(String), "| VRC-Admin | Você deu um tapa no jogador(a) %s[%d]", PlayerInfo[id][Nome], id);
    SendClientMessage(playerid, adm, String);
    return 1;
}
CMD:kick(playerid, params[])
{
    if(!IsPlayerHelper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new id, tmp[128];

    if(sscanf(params, "us[128]", id, tmp))
        return SendClientMessage(playerid, Erro, "Digite: /Kick [id/nome] [motivo]");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    GameTextForPlayer(id,"~r~kickado~w~!", 2500, 3);
    format(String, sizeof(String), "| VRC-Admin | O(A) %s %s kickou o(a) jogador(a) %s ( Motivo: %s )", CargoAdmin(playerid), PlayerInfo[playerid][Nome], PlayerInfo[id][Nome], tmp);
    SendClientMessageToAll(Red, String);
    format(String, sizeof(String), "| VRC-Admin | Você kickou o(a) Jogador(a) %s[%d]", PlayerInfo[id][Nome], id);
    SendClientMessage(playerid, adm, String);
    Kick(id);
    return 1;
}
CMD:enchervida(playerid, params[])
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new id;

    if(sscanf(params, "u", id))
        return SendClientMessage(playerid, Erro, "Digite: /EncherVida [id/nome]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    SetPlayerHealth(id, 100);
    format(String, sizeof(String), "| VRC-Admin | O(A) %s %s[%d] encheu sua vida", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid);
    SendClientMessage(id, adm, String);
    format(String, sizeof(String), "| VRC-Admin | Você encheu a vida do(a) jogador(a) %s[%d]", PlayerInfo[id][Nome], id);
    SendClientMessage(playerid, adm, String);
    return 1;
}
CMD:enchercolete(playerid, params[])
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new id;

    if(sscanf(params, "u", id))
        return SendClientMessage(playerid, Erro, "Digite: /EncherColete [id/nome]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    SetPlayerArmour(id, 100);
    format(String, sizeof(String), "| VRC-Admin | O(A) %s %s[%d] encheu seu colete", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid);
    SendClientMessage(id, adm, String);
    format(String, sizeof(String), "| VRC-Admin | Você encheu o colete do(a) jogador(a) %s[%d]", PlayerInfo[id][Nome], id);
    SendClientMessage(playerid, adm, String);
    return 1;
}
CMD:ir(playerid, params[])
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new id, Float:x, Float:y, Float:z;

    if(sscanf(params, "u", id))
        return SendClientMessage(playerid, Erro, "Digite: /Ir [id/nome]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    if(GetPlayerInterior(id) != 0 || GetPlayerInterior(playerid) != 0)
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a)/Você está em um interior");

    if(PlayerInfo[id][tutorial])
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) está no tutorial");

    GetPlayerPos(id, x, y, z);
    SetPlayerPos(playerid, x, y, z);
    SetPlayerInterior(playerid, GetPlayerInterior(id));

    format(String, sizeof(String), "| VRC-Admin | O(A) %s %s[%d] veio até sua posição", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid);
    SendClientMessage(id, adm, String);
    format(String, sizeof(String), "| VRC-Admin | Você foi até a posição do jogador(a) %s[%d]", PlayerInfo[id][Nome], id);
    SendClientMessage(playerid, adm, String);
    return 1;
}

CMD:trazer(playerid, params[])
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new id, Float:x, Float:y, Float:z;

    if(sscanf(params, "u", id))
        return SendClientMessage(playerid, Erro, "Digite: /Trazer [id/nome]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    if(GetPlayerInterior(id) != 0 || GetPlayerInterior(playerid) != 0)
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a)/Você está em um interior");

    if(PlayerInfo[id][tutorial])
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) está no tutorial");

    GetPlayerPos(playerid, x, y, z);
    SetPlayerPos(id, x, y, z);
    SetPlayerInterior(id, GetPlayerInterior(playerid));

    format(String, sizeof(String), "| VRC-Admin | O(A) %s %s[%d] puxou você", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid);
    SendClientMessage(id, adm, String);
    format(String, sizeof(String), "| VRC-Admin | Você puxou jogador(a) %s[%d]", PlayerInfo[id][Nome], id);
    SendClientMessage(playerid, adm, String);
    return 1;
}
CMD:punicao(playerid, params[])
{
    if(!IsPlayerHelper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new id, tempo, tmp[128];

    if(sscanf(params, "uds[128]", id, tempo, tmp))
        return SendClientMessage(playerid, Erro, "Digite: /Punicao [id/nome] [tempo] [motivo]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    if(tempo <= 0 || tempo > 1000)
            return SendClientMessage(playerid, Erro, "Tempo só permitido entre 1 e 1000");

    if(PrisonEnum[id][pTempo] != 0)
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) já está preso(a)");

    KillTimer(PerseguicaoTime[id]);

    format(PrisonEnum[id][pCadeia], 15, "Federal");
    format(PrisonEnum[id][pMotivo], 128, tmp);
    PrisonEnum[id][pTempo] = tempo*60;

    ResetPlayerWeapons(id);
    SetPlayerInterior(id, 10);
    SetPlayerHealth(id, 99999);
    SetPlayerPos(id, 223.5335, 110.3779, 999.0156);

    PlayerTextDrawShow(id, TempoPresidio[id][1]);
    PlayerTextDrawShow(id, TempoPresidio[id][0]);

    format(String, sizeof(String), "| VRC-Admin | O(A) %s %s prendeu o(a) jogador(a) %s por %d minutos ( Motivo: %s )", CargoAdmin(playerid), PlayerInfo[playerid][Nome], PlayerInfo[id][Nome], tempo, PrisonEnum[id][pMotivo]);
    SendClientMessageToAll(adm, String);

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
CMD:despunicao(playerid, params[])
{
    if(!IsPlayerHelper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new id;

    if(sscanf(params, "u", id))
        return SendClientMessage(playerid, Erro, "Digite: /Despunicao [id/nome]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    if(PrisonEnum[id][pTempo] == 0)
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) não esta preso(a)");

    KillTimer(TempoPreso[id]);

    SetPlayerInterior(id, 0);
    SetPlayerHealth(id, 100);
    SetPlayerPos(id, 1554.8657,-1675.6693,16.1953);

    PrisonEnum[id][pCadeia] = 0;
    PrisonEnum[id][pTempo] = 0;
    format(PrisonEnum[id][pMotivo], 1, "");

    mysql_format(IDConexao, String, sizeof(String), "DELETE FROM `Prison` WHERE `id_contas`='%d'", PlayerInfo[id][ID]);
    mysql_query(IDConexao, String);

    PlayerTextDrawHide(id, TempoPresidio[id][2]);
    PlayerTextDrawHide(id, TempoPresidio[id][1]);
    PlayerTextDrawHide(id, TempoPresidio[id][0]);

    GameTextForPlayer(id, "~w~Solto!", 3000, 0);
    format(String, sizeof(String), "| VRC-Admin | Você soltou o(a) jogador(a) %s[%d] da prisão", PlayerInfo[id][Nome], id);
    SendClientMessage(playerid, adm, String);
    format(String, sizeof(String), "| VRC-Admin | O(A) %s %s[%d] soltou você da prisão", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid);
    SendClientMessage(id, adm, String);
    return 1;
}
CMD:criarveiculo(playerid, params[])
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    if(IsPlayerInAnyVehicle(playerid))
        return SendClientMessage(playerid, Erro,"Você está em um veiculo");

    new id, color1, color2, Float:x, Float:y, Float:z, Float:a;

    if(sscanf(params, "ddd", id, color1, color2))
        return SendClientMessage(playerid, Erro,"Digite: /CriarVeiculo [id-carro] [id-cor] [id-cor]");

    if(id < 400 || id > 611)
        return SendClientMessage(playerid, Erro,"ID do Veiculo Inválido, Digite entre: 400 a 611");

    if(color1 < 0 || color1 > 255)
        return SendClientMessage(playerid, Erro,"ID da Cor Inválida, Digite entre: 0 a 255");

    if(color2 < 0 || color2 > 255)
        return SendClientMessage(playerid, Erro,"ID da Cor Inválida, Digite entre: 0 a 255");

    GetPlayerFacingAngle(playerid, a);
    GetPlayerPos(playerid, x, y, z);

    VehicleAdmin[playerid] = CreateVehicleEx(id, x-2, y, z, a, color1, color2, true);

    PutPlayerInVehicle(playerid, VehicleAdmin[playerid], 0);
    LinkVehicleToInterior(VehicleAdmin[playerid], GetPlayerInterior(playerid));

    format(String, 128, "| VRC-Admin | Você criou o veículo %s ID %d", getVehicleName(GetVehicleModel(id)), id);
    SendClientMessage(playerid, adm, String);
    return 1;
}
CMD:ac(playerid, params[])
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new tmp[128];

    if(sscanf(params, "s[128]", tmp))
        return SendClientMessage(playerid,Erro, "Digite: /Ac [mensagem]");

    format(String, 128, "| Chat-Admin | %s %s [%d] diz: %s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid, tmp);

    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerIntern(i))
        {
            SendClientMessage(i, adm, String);
        }
    }

    #if !SERVER_OFFLINE
        format(String, 128, "%s %s [%d] diz: ```%s```", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid, tmp);
        DCC_SendChannelMessage(Channels[dsc_admin], String);
    #endif

    return 1;
}
CMD:a(playerid, params[])
{
    if(!IsPlayerHelper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new tmp[128];

    if(sscanf(params, "s[128]", tmp))
        return SendClientMessage(playerid,Erro, "Digite: /A [mensagem]");

    format(String, sizeof(String), "* %s %s: %s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], tmp);
    SendClientMessageToAll(0x0099CCAA, String);
    return 1;
}
CMD:cnn(playerid, params[])
{
    if(!IsPlayerHelper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new tmp[128];

    if(sscanf(params, "s[128]", tmp))
        return SendClientMessage(playerid, Erro, "Digite: /Cnn [mensagem]");

    TextConverter(tmp);

    format(String, sizeof(String), "~r~# ~p~%s~w~: %s ~r~#", PlayerInfo[playerid][Nome], tmp);
    TextDrawSetString(RespawnVeiculos, String);
    TextDrawShowForAll(RespawnVeiculos);
    SetTimer("HideTextRespawn", 1500, false);
    return 1;
}
CMD:ann(playerid, params[])
{
    if(!IsPlayerHelper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new tmp[128];

    if(sscanf(params, "s[128]", tmp))
        return SendClientMessage(playerid, Erro, "Digite: /Ann [mensagem]");

    TextConverter(tmp);

    format(String, sizeof(String), "~r~#~w~%s ~r~#", tmp);
    TextDrawSetString(RespawnVeiculos, String);
	TextDrawShowForAll(RespawnVeiculos);
	SetTimer("HideTextRespawn", 1500, false);
    return 1;
}
CMD:injetar(playerid, params[])
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new id;

    if(sscanf(params, "u", id))
        return SendClientMessage(playerid, Erro, "Digite: /Injetar [id/nome]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    new vehicleid = GetPlayerVehicleID(playerid);

    PutPlayerInVehicle(id, vehicleid, GetFreeSeat(vehicleid));

    SendClientMessage(playerid, adm, "| VRC-Admin | Comando efetuado com sucesso");
    format(String, sizeof(String), "| VRC-Admin | O(A) %s %s te colocou dentro de seu veiculo para o ajuda-lo!", CargoAdmin(playerid), PlayerInfo[playerid][Nome]);
    SendClientMessage(id, adm, String);
    return 1;
}
CMD:ejetar(playerid, params[])
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new id;

    if(sscanf(params, "u", id))
        return SendClientMessage(playerid, Erro, "Digite: /Ejetar [id/nome]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    RemovePlayerFromVehicle(id);
    SendClientMessage(playerid, adm, "| VRC-Admin | Comando efetuado com sucesso");
    format(String, sizeof(String), "| VRC-Admin | O(A) %s %s ejetou você do seu veiculo!", CargoAdmin(playerid), PlayerInfo[playerid][Nome]);
    SendClientMessage(id, adm, String);
    return 1;
}
CMD:godmodon(playerid)
{
    if(!IsPlayerHelper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    SetPlayerHealth(playerid, 99999);
    SetPlayerArmour(playerid, 99999);
    SendClientMessage(playerid, adm, "| VRC-Admin | Comando efetuado com sucesso");
    return 1;
}
CMD:godmodoff(playerid)
{
    if(!IsPlayerHelper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    SetPlayerHealth(playerid, 100);
    SetPlayerArmour(playerid, 0);
    SendClientMessage(playerid, adm, "| VRC-Admin | Comando efetuado com sucesso");
    return 1;
}
CMD:banir(playerid, params[])
{
    if(!IsPlayerModerator(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    ShowTDPlayerBan(playerid);
    return 1;
}
CMD:dararma(playerid, params[])
{
    if(!IsPlayerAdmininstrator(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new id, idarma;

	if(sscanf(params, "ud", id, idarma))
        return SendClientMessage(playerid, Erro, "Digite: /DarArma [id/nome] [id-arma]");

	GivePlayerWeapon(id, idarma, 900);
	SendClientMessage(playerid, adm, "| VRC-Admin | Comando efetuado com sucesso");
	format(String, sizeof(String), "| VRC-Admin | O(A) %s %s te deu a arma ID '%d'", CargoAdmin(playerid),PlayerInfo[playerid][Nome],idarma);
    SendClientMessage(id, adm, String);
    return 1;
}
CMD:pagarevento(playerid, params[])
{
    if(!IsPlayerAdmininstrator(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new grana, id;

    if(sscanf(params, "ud", id, grana))
        return SendClientMessage(playerid, Erro, "Digite: /PagarEvento [id/nome] [quantia]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    if(grana > 1000000)
        return SendClientMessage(playerid, Erro, "Você não pode pagar mais do que $1.000.000");

    PlayerInfo[id][Dinheiro] += grana;
    UpdatePlayerMoney(id);

	format(String, sizeof(String), "| VRC-Admin | Você pagou $%s para o jogador(a) %s[%d] que ganhou o evento", IsMoney(grana, "."), PlayerInfo[id][Nome], id);
    SendClientMessage(playerid, adm, String);
	format(String, sizeof(String), "| VRC-Admin | O(A) %s %s lê pagou $%s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], IsMoney(grana, "."));
    SendClientMessage(id, adm, String);
    return 1;
}

CMD:darlevel(playerid, params[])
{
	if(!IsPlayerAdmininstrator(playerid))
		return SendClientMessage(playerid, Erro, "Comando Inválido");

    new level, id;

    if(sscanf(params, "ud", id, level))
		return SendClientMessage(playerid, Erro, "Digite: /Darlevel [id/nome] [quantia]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    PlayerInfo[id][Level] += level;
    SetPlayerScore(id, PlayerInfo[id][Level]);

	format(String, sizeof(String), "| VRC-Admin | Você deu %d level(s) para o jogador(a) %s[%d]", level, PlayerInfo[id][Nome], id);
    SendClientMessage(playerid, adm, String);
	format(String, sizeof(String), "| VRC-Admin | O(A) %s %s deu para você %d level(s)", CargoAdmin(playerid), PlayerInfo[playerid][Nome], level);
    SendClientMessage(id, adm, String);

    mysql_format(IDConexao, String, sizeof(String), "UPDATE `Identidade` SET `level`='%d' WHERE `id_contas`='%d'", PlayerInfo[id][Level], PlayerInfo[id][ID]);
    mysql_query(IDConexao, String);
    return 1;
}
CMD:removerlevel(playerid, params[])
{
    if(!IsPlayerAdmininstrator(playerid))
		return SendClientMessage(playerid, Erro, "Comando Inválido");

    new level, id;

    if(sscanf(params, "ud", id, level))
		return SendClientMessage(playerid, Erro, "Digite: /Removerlevel [id/nome] [quantia]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    PlayerInfo[id][Level] -= level;
    SetPlayerScore(id, PlayerInfo[id][Level]);

	format(String, sizeof(String), "| VRC-Admin | Você removeu %d level(s) do(a) jogador(a) %s[%d]", level, PlayerInfo[id][Nome], id);
    SendClientMessage(playerid, adm, String);
	format(String, sizeof(String), "| VRC-Admin | O(A) %s %s removeu de você %d level(s)", CargoAdmin(playerid), PlayerInfo[playerid][Nome], level);
    SendClientMessage(id, adm, String);

    mysql_format(IDConexao, String, sizeof(String), "UPDATE Contas SET Level='%i' WHERE Nome='%e'", PlayerInfo[id][Level], PlayerInfo[id][Nome]);
    mysql_query(IDConexao, String);
    return 1;
}
CMD:darreais(playerid, params[])
{
    if(!IsPlayerAdmininstrator(playerid))
		return SendClientMessage(playerid, Erro, "Comando Inválido");

    new real, id;

    if(sscanf(params, "ud", id, real))
		return SendClientMessage(playerid, Erro, "Digite: /DarReais [id/nome] [quantia]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    PlayerInfo[id][Reais] += real;

	format(String, sizeof(String), "| VRC-Admin | Você deu R$%s para o(a) jogador(a) %s[%d]", IsMoney(real, "."), PlayerInfo[id][Nome], id);
    SendClientMessage(playerid, adm, String);
	format(String, sizeof(String), "| VRC-Admin | O(A) %s %s deu para você R$%s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], IsMoney(real, "."));
    SendClientMessage(id, adm, String);

    mysql_format(IDConexao, String, sizeof(String), "UPDATE `Identidade` SET `reais`='%d' WHERE `id_contas`='%d'", PlayerInfo[id][Reais], PlayerInfo[id][ID]);
    mysql_query(IDConexao, String);
    return 1;
}
CMD:removerreais(playerid, params[])
{
    if(!IsPlayerAdmininstrator(playerid))
		return SendClientMessage(playerid, Erro, "Comando Inválido");

    new real, id;

    if(sscanf(params, "ud", id, real))
		return SendClientMessage(playerid, Erro, "Digite: /RemoverReais [id/nome] [quantia]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    PlayerInfo[id][Reais] -= real;
	format(String, sizeof(String), "| VRC-Admin | Você removeu R$%s do(a) jogador(a) %s[%d]", IsMoney(real), PlayerInfo[id][Nome], id);
    SendClientMessage(playerid, adm, String);
	format(String, sizeof(String), "| VRC-Admin | O(A) %s %s removeu de você R$%s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], IsMoney(real));
    SendClientMessage(id, adm, String);

    mysql_format(IDConexao, String, sizeof(String), "UPDATE `Identidade` SET `reais`='%d' WHERE `id_contas`='%d'", PlayerInfo[id][Reais], PlayerInfo[id][ID]);
    mysql_query(IDConexao, String);
    return 1;
}
CMD:fecharservidor(playerid, params[])
{
    if(!IsPlayerDeveloper(playerid))
		return SendClientMessage(playerid, Erro, "Comando Inválido");

    new tmp[128];

    if(sscanf(params, "s[128]", tmp))
        return SendClientMessage(playerid, Erro, "Digite: /FecharServidor [senha]");

    format(String, sizeof(String), "password %s", tmp);
	SendRconCommand(String);
    format(String, sizeof(String), "| VRC-Admin | O(A) %s %s trancou o servidor", CargoAdmin(playerid), PlayerInfo[playerid][Nome]);
    SendClientMessageToAll(adm, String);
    format(String, sizeof(String), "| VRC-Admin | Senha do servidor {FF0000}%s", tmp);
    SendClientMessage(playerid, adm, String);
    return 1;
}
CMD:abrirservidor(playerid)
{
    if(!IsPlayerDeveloper(playerid))
		return SendClientMessage(playerid, Erro, "Comando Inválido");

	SendRconCommand("password 0");
    format(String, sizeof(String), "| VRC-Admin | O(A) %s %s abriu o servidor", CargoAdmin(playerid), PlayerInfo[playerid][Nome]);
    SendClientMessageToAll(adm, String);
    SendClientMessage(playerid, adm, "| VRC-Admin | O servidor acaba de ser destrancado por você");
    return 1;
}
CMD:daradmin(playerid, params[])
{
    if(!IsPlayerDeveloper(playerid))
		return SendClientMessage(playerid, Erro, "Comando Inválido");

    new nivel, id;

    if(sscanf(params, "ud", id, nivel))
        return SendClientMessage(playerid, Erro, "Digite: /Daradmin [id/nome] [1-5]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(nivel < 0 || nivel > 5)
        return SendClientMessage(playerid, Erro, "Digite um cargo entre 1-5");

    if(nivel == PlayerInfo[id][Admin])
    {
        format(String, sizeof(String), "O(A) Jogador(a) já é %s!", CargoAdmin(id));
        SendClientMessage(playerid, Erro, String);
        return 1;
    }

    if(nivel == 0)
	{
        PlayerInfo[id][Admin] = nivel;
        format(String, sizeof(String), "| VRC-Admin | Você removeu o(a) jogador(a) %s[%d] da Admininstração!", PlayerInfo[id][Nome], id, CargoAdmin(id));
        SendClientMessage(playerid, adm, String);
        format(String, sizeof(String), "| VRC-Admin | O(A) %s %s[%d] removeu você da Admininstração!", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid, CargoAdmin(id));
        SendClientMessage(id, adm, String);
  	}
	else if(nivel < PlayerInfo[id][Admin])
	{
        PlayerInfo[id][Admin] = nivel;
        format(String, sizeof(String), "| VRC-Admin | Você rebaixou o(a) jogador(a) %s[%d] para %s", PlayerInfo[id][Nome], id, CargoAdmin(id));
        SendClientMessage(playerid, adm, String);
        format(String, sizeof(String), "| VRC-Admin | O(A) %s %s[%d] rebaixou você para %s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid, CargoAdmin(id));
        SendClientMessage(id, adm, String);
	}
	else if(nivel > PlayerInfo[id][Admin])
	{
        PlayerInfo[id][Admin] = nivel;
        format(String, sizeof(String), "| VRC-Admin | Você promoveu o(a) jogador(a) %s[%d] para %s", PlayerInfo[id][Nome], id, CargoAdmin(id));
        SendClientMessage(playerid, adm, String);
        format(String, sizeof(String), "| VRC-Admin | O(A) %s %s[%d] promoveu você para %s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid, CargoAdmin(id));
        SendClientMessage(id, adm, String);
    }

    mysql_format(IDConexao, String, sizeof(String), "UPDATE `Identidade` SET `admin`='%d' WHERE `id_contas`='%d'", PlayerInfo[id][Admin], PlayerInfo[id][ID]);
    mysql_query(IDConexao, String);
    return 1;
}
CMD:reiniciar(playerid)
{
    if(!IsPlayerDeveloper(playerid))
		return SendClientMessage(playerid, Erro, "Comando Inválido");

	SendClientMessageToAll(0xB9FFFFAA, "O Server reiniciara em 2 minutos");
	SetTimer("RestartServer", 60000, false);
    return 1;
}
CMD:salvarcontas(playerid)
{
    if(!IsPlayerDeveloper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(PlayerInfo[i][Logado])
        {
            format(String, sizeof(String), "| VRC-Admin | Conta do jogador(a) %s[%d] foi salva com sucesso!", PlayerInfo[i][Nome], i);
            SendClientMessage(playerid, adm, String);
            SaveAccounts(i);
        }
    }
    return 1;
}
CMD:vercomandos(playerid, params[])
{
    if(!IsPlayerHelper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new tmp[5];

    if(sscanf(params, "s[5]", tmp))
        return SendClientMessage(playerid, Erro, "Digite: /VerComandos [On/Off]");

    if(!strcmp(tmp, "on", true))
    {
        if(viewcmds[playerid] == true)
            return SendClientMessage(playerid, Erro, "Ver comandos já está ativado");

        viewcmds[playerid] = true;
    }
    else if(!strcmp(tmp, "off", true))
    {
        if(viewcmds[playerid] == false)
            return SendClientMessage(playerid, Erro, "Ver comandos já está desativado");

        viewcmds[playerid] = false;
    }
    else return SendClientMessage(playerid, Erro, "Digite: /VerComandos [On/Off]");

    SendClientMessage(playerid, adm, "| VRC-Admin | Comando efetuado com sucesso");
    return 1;
}
CMD:comandosadm(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new txt[3000];
    strcat(txt, "{FF0000}Comandos \t\t{1CEB00}Informações\n");

    switch(PlayerInfo[playerid][Admin])
    {
        case 1:
        {
            strcat(txt, "{87CEFF}/Ac \t\t{FFFFFF}Para digitar no chat da admininstração \n");
            strcat(txt, "{87CEFF}/Tps \t\t{FFFFFF}Para ver os teletransportes\n");
            strcat(txt, "{87CEFF}/Desprocurar \t\t{FFFFFF}Para desprocurar um(a) jogador(a)\n");
            strcat(txt, "{87CEFF}/Lc \t\t{FFFFFF}Para limpar o chat para todos jogador(a)\n");
            strcat(txt, "{87CEFF}/Ir \t\t{FFFFFF}Para ir até um(a) jogador(a) \n");
            strcat(txt, "{87CEFF}/Trazer \t\t{FFFFFF}Para puxar um(a) jogador(a) \n");
            strcat(txt, "{87CEFF}/Ejetar \t\t{FFFFFF}Para ejetar um(a) jogador(a) de um veículo\n");
            strcat(txt, "{87CEFF}/Injetar \t\t{FFFFFF}Para colocar um(a) jogador(a) em um veículo\n");
            strcat(txt, "{87CEFF}/Tapa \t\t{FFFFFF}Para dar um(a) tapa em um(a) jogador(a) \n");
            strcat(txt, "{87CEFF}/CriarVeiculo \t\t{FFFFFF}Para criar um veiculo em sua posição \n");
            strcat(txt, "{87CEFF}/EncherVida \t\t{FFFFFF}Para recuperar a vida de um(a) jogador(a) \n");
            strcat(txt, "{87CEFF}/EncherColete \t\t{FFFFFF}Para recuperar o colete de um(a) jogador(a) \n");
            strcat(txt, "{87CEFF}/R \t\t{FFFFFF}Para responder a dúvida de um(a) jogador(a)\n");
            strcat(txt, "{87CEFF}/RespawnVeiculos \t\t{FFFFFF}Para Respawnar todos os veiculos não em uso\n");
            strcat(txt, "{87CEFF}/Deslogar \t\t{FFFFFF}Para deslogar como membro da administração\n");
       }
        case 2:
        {
          	strcat(txt, "{87CEFF}/A \t\t{FFFFFF}Para mandar mensagem(ns) global\n");
            strcat(txt, "{87CEFF}/Ann \t\t{FFFFFF}Para mandar mensagem(ns) na tela\n");
            strcat(txt, "{87CEFF}/Cnn \t\t{FFFFFF}Para mandar mensagem(ns) na tela com o nome\n");
            strcat(txt, "{87CEFF}/CorNome \t\t{FFFFFF}Para alterar a cor do nome\n");
            strcat(txt, "{87CEFF}/Espiar \t\t{FFFFFF}Para espiar um(a) jogador(a)\n");
            strcat(txt, "{87CEFF}/PararEspiar \t\t{FFFFFF}Para parar de espiar o(a) jogador(a)\n");
            strcat(txt, "{87CEFF}/Avisar \t\t{FFFFFF}Para avisar um(a) jogador(a)\n");
            strcat(txt, "{87CEFF}/GodModOn \t\t{FFFFFF}Para ficar com vida infinita\n");
            strcat(txt, "{87CEFF}/GodModOff \t\t{FFFFFF}Para remover a vida infinita\n");
            strcat(txt, "{87CEFF}/Kick \t\t{FFFFFF}Para kickar um(a) jogador(a) \n");
        	strcat(txt, "{87CEFF}/Punicao \t\t{FFFFFF}Para prender um(a) jogador(a) \n");
        	strcat(txt, "{87CEFF}/Despunicao \t\t{FFFFFF}Para soltar um(a) jogador(a) \n");
        }
        case 3:
        {
            strcat(txt, "{87CEFF}/Banir \t\t{FFFFFF}Para banir um(a) jogador(a) permanente\n");
        }
        case 4:
        {
            strcat(txt, "{87CEFF}/DarArma \t\t{FFFFFF}Para dar uma arma para um(a) jogador(a)\n");
            strcat(txt, "{87CEFF}/IrCasa \t\t{FFFFFF}Para se teletransportar para a casa com esse id\n");
            strcat(txt, "{87CEFF}/PagarEvento \t\t{FFFFFF}Para pagar ao vencedor(a) do evento\n");
        }
        case 5:
        {
            strcat(txt, "{87CEFF}/Reiniciar \t\t{FFFFFF}Para reiniciar o servidor\n");
            strcat(txt, "{87CEFF}/AbrirServidor \t\t{FFFFFF}Para retirar a senha do servidor\n");
            strcat(txt, "{87CEFF}/FecharServidor \t\t{FFFFFF}Para fechar o servidor com senha\n");
        }
        case 6:
        {
            strcat(txt, "{87CEFF}/DarAdmin \t\t{FFFFFF}Para promover/rebaixar/remover jogador(a) da admininstração\n");
            strcat(txt, "{87CEFF}/DarLevel \t\t{FFFFFF}Para dar level(s) para um(a) jogador(a)\n");
            strcat(txt, "{87CEFF}/RemoverLevel \t\t{FFFFFF}Para remover level(s) de um(a) jogador(a)\n");
            strcat(txt, "{87CEFF}/DarReais \t\t{FFFFFF}Para dar real(is) de um(a) jogador(a)\n");
            strcat(txt, "{87CEFF}/RemoverReais \t\t{FFFFFF}Para remover real(is) de um(a) jogador(a)\n");
            strcat(txt, "{87CEFF}/SalvarContas \t\t{FFFFFF}Para salvar todas as contas logadas no servidor\n");
        }
    }

    format(String, sizeof(String), "{C0C0C0}Comandos de {00CA00}%s", CargoAdmin(playerid));

    if(IsPlayerMobile(playerid))
    {
        ShowPlayerDialog(playerid, 0, DIALOG_STYLE_LIST, String, txt, "Fechar", #);
    }
    else
    {
        ShowPlayerDialog(playerid, 0, DIALOG_STYLE_TABLIST_HEADERS, String, txt, "Fechar", #);
    }
    return 1;
}
CMD:deslogar(playerid)
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    PlayerInfo[playerid][Admin] = 0;
    SetPlayerSkin(playerid, PlayerInfo[playerid][skin]);
    SendClientMessage(playerid, Yellow, "Agora você não está mas exercendo sua função");
    return 1;
}

alias:vercomandos("vercmds");
alias:criarveiculo("cv");
