#include YSI\y_hooks

enum VipI
{
    bool:Vip,
    Tempo,
    Dias,
};

new VipInfo[MAX_PLAYERS][VipI];
new cps_areavip;

hook OnGameModeInit()
{
    mysql_query(IDConexao, "CREATE TABLE IF NOT EXISTS `Vips`(`days` int(5) NOT NULL, `time` int(5) NOT NULL, `id_contas` int NOT NULL, FOREIGN KEY (`id_contas`) REFERENCES `Contas`(`id`) ON DELETE CASCADE )", false);

    cps_areavip = CreateDynamicCP(-783.7917, 495.3470, 1376.1953, 1.0, -1, -1, -1, 30.0);

    SetTimer("Check_Vip", 1000, true);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    DB_SaveVips(playerid);
	return 1;
}

hook OnPlayerEnterCheckpoint(playerid)
{
    if(IsPlayerInDynamicCP(playerid, cps_areavip))
    {
        ShowPlayerDialog(playerid, vip_area, DIALOG_STYLE_LIST, "{FFFFFF}Armas área [{FF0000}VIP{FFFFFF}]", "{FFFFFF}Chainsaw \nCombate Shotgun \nSawnoff \nUZI \nMP5 \nTec-9 \nM4 \nAK-47 \nRifle \nSniper", "Escolher", "Cancelar");
        return 1;
    }
	return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == neon && response)
    {
        switch(listitem)
        {
            case 0:
            {
                DestroyObject(GetPVarInt(playerid, "neon"));
                DeletePVar(playerid, "Status");
                DestroyObject(GetPVarInt(playerid, "neon1"));
                DeletePVar(playerid, "Status");
                DestroyObject(GetPVarInt(playerid, "neon2"));
                DeletePVar(playerid, "Status");
                DestroyObject(GetPVarInt(playerid, "neon3"));
                DeletePVar(playerid, "Status");
                DestroyObject(GetPVarInt(playerid, "neon4"));
                DeletePVar(playerid, "Status");
                DestroyObject(GetPVarInt(playerid, "neon5"));
                DeletePVar(playerid, "Status");
                DestroyObject(GetPVarInt(playerid, "neon6"));
                DeletePVar(playerid, "Status");
                DestroyObject(GetPVarInt(playerid, "neon7"));
                DeletePVar(playerid, "Status");
                DestroyObject(GetPVarInt(playerid, "neon8"));
                DeletePVar(playerid, "Status");
                DestroyObject(GetPVarInt(playerid, "neon9"));
                DeletePVar(playerid, "Status");
                DestroyObject(GetPVarInt(playerid, "neon10"));
                DeletePVar(playerid, "Status");
                DestroyObject(GetPVarInt(playerid, "neon11"));
            }
            case 1:
            {
                SetPVarInt(playerid, "neon6", CreateObject(18652,0,0,0,0,0,0));
                SetPVarInt(playerid, "neon7", CreateObject(18652,0,0,0,0,0,0));
                AttachObjectToVehicle(GetPVarInt(playerid, "neon6"), GetPlayerVehicleID(playerid), -0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
                AttachObjectToVehicle(GetPVarInt(playerid, "neon7"), GetPlayerVehicleID(playerid), 0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
            }
            case 2:
            {
                SetPVarInt(playerid, "neon", CreateObject(18648,0,0,0,0,0,0));
                SetPVarInt(playerid, "neon1", CreateObject(18648,0,0,0,0,0,0));
                AttachObjectToVehicle(GetPVarInt(playerid, "neon"), GetPlayerVehicleID(playerid), -0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
                AttachObjectToVehicle(GetPVarInt(playerid, "neon1"), GetPlayerVehicleID(playerid), 0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
            }
            case 3:
            {
                SetPVarInt(playerid, "neon4", CreateObject(18649,0,0,0,0,0,0));
                SetPVarInt(playerid, "neon5", CreateObject(18649,0,0,0,0,0,0));
                AttachObjectToVehicle(GetPVarInt(playerid, "neon4"), GetPlayerVehicleID(playerid), -0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
                AttachObjectToVehicle(GetPVarInt(playerid, "neon5"), GetPlayerVehicleID(playerid), 0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
            }
            case 4:
            {
                SetPVarInt(playerid, "neon8", CreateObject(18651,0,0,0,0,0,0));
                SetPVarInt(playerid, "neon9", CreateObject(18651,0,0,0,0,0,0));
                AttachObjectToVehicle(GetPVarInt(playerid, "neon8"), GetPlayerVehicleID(playerid), -0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
                AttachObjectToVehicle(GetPVarInt(playerid, "neon9"), GetPlayerVehicleID(playerid), 0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
            }
            case 5:
            {
                SetPVarInt(playerid, "neon10", CreateObject(18650,0,0,0,0,0,0));
                SetPVarInt(playerid, "neon11", CreateObject(18650,0,0,0,0,0,0));
                AttachObjectToVehicle(GetPVarInt(playerid, "neon10"), GetPlayerVehicleID(playerid), -0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
                AttachObjectToVehicle(GetPVarInt(playerid, "neon11"), GetPlayerVehicleID(playerid), 0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
            }
        }
        return 1;
    }
    return 1;
}

forward DB_LoadVips(playerid);
public DB_LoadVips(playerid)
{
    if(cache_num_rows() > 0)
    {
        VipInfo[playerid][Vip] = true;
        cache_get_value_int(0, "days", VipInfo[playerid][Dias]);
        cache_get_value_int(0, "time", VipInfo[playerid][Tempo]);
    } else {
        VipInfo[playerid][Vip] = false;
        VipInfo[playerid][Dias] = 0;
        VipInfo[playerid][Tempo] = 0;
    }
    return 1;
}

forward Check_Vip();
public Check_Vip()
{
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(PlayerInfo[i][Logado] && VipInfo[i][Vip])
        {
            if(VipInfo[i][Tempo] > 0)
            {
                VipInfo[i][Tempo] = gettime() - ExpireVIP(i);
            } else {
                RemoveVip(i);
            }
        }
    }
    return 1;
}

stock SetVip(playerid, days)
{
    new Query[100];
    if(VipInfo[playerid][Vip])
    {
        format(String, sizeof String, "•» Seu VIP foi renovado. +%d dias.", days);
        VipInfo[playerid][Tempo] += days;
        VipInfo[playerid][Dias] += days;

        mysql_format(IDConexao, Query, sizeof(Query), "UPDATE `Vips` SET `days`='%d', `time`='%d' WHERE `id_contas`='%d'", VipInfo[playerid][Dias], VipInfo[playerid][Tempo], PlayerInfo[playerid][ID]);
        mysql_tquery(IDConexao, Query);
    }
    else
    {
        format(String, sizeof String, "•» Seu VIP de %d dias foi ativado", days);

        VipInfo[playerid][Tempo] = days;
        VipInfo[playerid][Dias] = days;
        VipInfo[playerid][Vip] = true;

        mysql_format(IDConexao, Query, sizeof(Query), "INSERT INTO `Vips` (`days`, `time`, `id_contas`) VALUES ('%d', '%d', '%d')", VipInfo[playerid][Dias], VipInfo[playerid][Tempo], PlayerInfo[playerid][ID]);
        mysql_tquery(IDConexao, Query);
    }
    SendClientMessage(playerid, 0x09CC57AA, "~~~~~~~~~~~~~~~~~~~~~~~~~ VIP ~~~~~~~~~~~~~~~~~~~~~~~~~");
    SendClientMessage(playerid, -1, String);
    SendClientMessage(playerid, -1, "•» Veja suas novas informações - /comandosvip");
    SendClientMessage(playerid, 0x09CC57AA, "~~~~~~~~~~~~~~~~~~~~~~~~~ VIP ~~~~~~~~~~~~~~~~~~~~~~~~~");
    return 1;
}

stock DB_SaveVips(playerid)
{
    if(VipInfo[playerid][Vip])
    {
        new Query[100];
        mysql_format(IDConexao, Query, sizeof(Query), "UPDATE `Vips` SET `days`='%d', `time`='%d' WHERE `id_contas`='%d'", VipInfo[playerid][Dias], VipInfo[playerid][Tempo], PlayerInfo[playerid][ID]);
        mysql_tquery(IDConexao, Query);
    }
    return 1;
}

stock ExpireVIP(playerid)
{
    new days = VipInfo[playerid][Dias] * 86400; // 86400 == 24horas
    return days;
}

stock RemoveVip(playerid)
{
    new query[70];
    mysql_format(IDConexao, query, sizeof(query), "DELETE FROM `Vips` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query);

    VipInfo[playerid][Tempo] = 0;
    VipInfo[playerid][Vip] = false;
    VipInfo[playerid][Dias] = 0;
    SendClientMessage(playerid, 0x00E100AA, "Infelizmente seus dias VIP expirou");
    return 1;
}

stock ChatVIP(COLOR, const string[])
{
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerHelper(i) || IsPlayerVip(i))
        {
            SendClientMessage(i, COLOR, string);
        }
    }
    return 1;
}

stock IsPlayerVip(playerid)
{
    if(VipInfo[playerid][Vip]) return true;
    return false;
}

/******************************************************************************/
/*****************************| COMMANDS LAWYER |******************************/
/******************************************************************************/

CMD:neon(playerid)
{
    if(!(IsPlayerVip(playerid) || IsPlayerHelper(playerid)))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsPlayerInAnyVehicle(playerid))
        return SendClientMessage(playerid, Erro, "Você não está em um carro");

    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
        return SendClientMessage(playerid, Erro, "Você não está dirigindo");

    new hour;

    gettime(hour);

    if(hour >= 6 && hour <= 18)
        return SendClientMessage(playerid, Erro, "Ainda não está de noite");

    DestroyObject(GetPVarInt(playerid, "neon"));
    DeletePVar(playerid, "Status");
    DestroyObject(GetPVarInt(playerid, "neon1"));
    DeletePVar(playerid, "Status");
    DestroyObject(GetPVarInt(playerid, "neon2"));
    DeletePVar(playerid, "Status");
    DestroyObject(GetPVarInt(playerid, "neon3"));
    DeletePVar(playerid, "Status");
    DestroyObject(GetPVarInt(playerid, "neon4"));
    DeletePVar(playerid, "Status");
    DestroyObject(GetPVarInt(playerid, "neon5"));
    DeletePVar(playerid, "Status");
    DestroyObject(GetPVarInt(playerid, "neon6"));
    DeletePVar(playerid, "Status");
    DestroyObject(GetPVarInt(playerid, "neon7"));
    DeletePVar(playerid, "Status");
    DestroyObject(GetPVarInt(playerid, "neon8"));
    DeletePVar(playerid, "Status");
    DestroyObject(GetPVarInt(playerid, "neon9"));
    DeletePVar(playerid, "Status");
    DestroyObject(GetPVarInt(playerid, "neon10"));
    DeletePVar(playerid, "Status");
    DestroyObject(GetPVarInt(playerid, "neon11"));
    ShowPlayerDialog(playerid, neon, DIALOG_STYLE_LIST, "{FF0000}Neon VIPs", "{FF0000}Remover Neon\n{FFFFFF}Branco \nAzul \nVerde \nRosa \nAmarelo", "Concluir", "Cancelar");
    return 1;
}
CMD:tunar(playerid)
{
    if(!(IsPlayerVip(playerid) || IsPlayerHelper(playerid)))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsPlayerInAnyVehicle(playerid))
        return SendClientMessage(playerid, Erro, "Você não está em um carro");

    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
        return SendClientMessage(playerid, Erro, "Você não está dirigindo");

    ShowPlayerDialog(playerid, tuning, DIALOG_STYLE_LIST,"{FF0000}Tunar","{FFFFFF}PaintJobs \nNitros \nRodas \nHidraulica","Concluir","Fechar");
    return 1;
}
CMD:tag(playerid)
{
    if(!IsPlayerVip(playerid))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    ShowPlayerDialog(playerid, vip_color_tag, DIALOG_STYLE_INPUT, "{FF0000}Tag VIP", "{FFFFFF}Digite um codigo em '{FF0000}HTML{FFFFFF}' abaixo\nPesquise no Google algo como {00FF00}Cores em HTML {FFFFFF}:\n{FF0000}Exemplo {FFFFFF}00FF00 = {00FF00}VIP", "Alterar", "Cancelar");
    return 1;
}
CMD:vencimento(playerid)
{
    if(!IsPlayerVip(playerid))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    new str[128];
    format(String, sizeof(String), "{FFFFFF} Nick: {{FF0000}}%s \n\n", PlayerInfo[playerid][Nome]);
    strcat(str, String);
    format(String, sizeof(String), "{FFFFFF} Vencimento: {f29b0d}%d {FFFFFF}dias \n\n", VipInfo[playerid][Dias]);
    strcat(str, String);
    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{1b6302}Vencimento VIP ", String, "Fechar", #);
    return 1;
}
CMD:reparar(playerid)
{
    if(!(IsPlayerVip(playerid) || IsPlayerHelper(playerid)))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(Perseguicao[playerid] == true)
        return SendClientMessage(playerid, Erro, "Você está em perseguição e não poderar reparar o veiculo");

    if(!IsPlayerInAnyVehicle(playerid))
        return SendClientMessage(playerid, Erro, "Você não está em um carro");

    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
        return SendClientMessage(playerid, Erro, "Você não está dirigindo");

    if(IsPlayerVip(playerid))
        { SendClientMessage(playerid, 0x00E100AA, "Veículo reparado com sucesso"); }

    if(IsPlayerHelper(playerid))
        { SendClientMessage(playerid, adm, "| VRC-Admin | Veículo reparado com sucesso"); }

    RepairVehicle(GetPlayerVehicleID(playerid));
    return 1;
}
CMD:virar(playerid)
{
    if(!(IsPlayerVip(playerid) || IsPlayerHelper(playerid)))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsPlayerInAnyVehicle(playerid))
        return SendClientMessage(playerid, Erro, "Você não está em um carro");

    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
        return SendClientMessage(playerid, Erro, "Você não está dirigindo");

    if(IsPlayerVip(playerid))
        { SendClientMessage(playerid, 0x00E100AA, "Veículo virado com sucesso"); }

    if(IsPlayerHelper(playerid))
        { SendClientMessage(playerid, adm, "| VRC-Admin | Veículo virado com sucesso"); }

    new Float:a;
    GetVehicleZAngle(GetPlayerVehicleID(playerid), a);
    SetVehicleZAngle(GetPlayerVehicleID(playerid), a);
    return 1;
}
CMD:colete(playerid)
{
    if(!(IsPlayerVip(playerid) || IsPlayerHelper(playerid)))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(IsPlayerVip(playerid))
        { SendClientMessage(playerid, 0x00E100AA, "Colete criado com sucesso"); }

    if(IsPlayerHelper(playerid))
        { SendClientMessage(playerid, adm, "| VRC-Admin | Colete criado com sucesso"); }

    SetPlayerArmour(playerid, 100);
    return 1;
}
CMD:v(playerid, params[])
{
    if(!(IsPlayerVip(playerid) || IsPlayerHelper(playerid)))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    new tmp[128];

    if(sscanf(params, "s[128]", tmp))
        return SendClientMessage(playerid,Erro, "Digite: /V [mensagem]");

    if(IsPlayerVip(playerid))
        { format(String, sizeof(String), "| Chat-Vip | %s [%d] diz: %s", PlayerInfo[playerid][Nome], playerid, tmp); }

    if(IsPlayerHelper(playerid))
        { format(String, sizeof(String), "| Chat-Vip | %s %s [%d] diz: %s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid, tmp); }

    ChatVIP(0x00E100AA, String);
    return 1;
}
CMD:jetpack(playerid)
{
    if(!(IsPlayerHelper(playerid) || IsPlayerVip(playerid)))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(IsPlayerInAnyVehicle(playerid))
        return SendClientMessage(playerid, Erro, "Você precisa sair do veiculo");

    if(GetPlayerInterior(playerid))
        return SendClientMessage(playerid, Erro, "Não é possível criar jetpack dentro de interior");

    if(IsPlayerVip(playerid))
        { SendClientMessage(playerid, 0x00E100AA, "Jetpack criado com sucesso"); }

    if(IsPlayerHelper(playerid))
        { SendClientMessage(playerid, adm, "| VRC-Admin | Jetpack criado com sucesso"); }

    SetPlayerSpecialAction(playerid, 2);
    return 1;
}
CMD:pintar(playerid, params[])
{
    if(!(IsPlayerHelper(playerid) || IsPlayerVip(playerid)))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsPlayerInAnyVehicle(playerid))
        return SendClientMessage(playerid, Erro, "Você não está em um veiculo");

    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
        return SendClientMessage(playerid, Erro, "Você não está dirigindo");

    new color1, color2;

    if(sscanf(params, "dd", color1, color2))
        return SendClientMessage(playerid, Erro, "Digite: /Pintar [cor-id] [cor-id]");

    if(IsPlayerVip(playerid))
        { SendClientMessage(playerid, 0x00E100AA, "Veículo pintado com sucesso"); }

    if(IsPlayerHelper(playerid))
        { SendClientMessage(playerid, adm, "| VRC-Admin | Veículo pintado com sucesso"); }

    ChangeVehicleColor(GetPlayerVehicleID(playerid), color1, color2);
    return 1;
}
