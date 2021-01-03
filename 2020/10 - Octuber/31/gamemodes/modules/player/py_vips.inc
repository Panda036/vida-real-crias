#include YSI\y_hooks

#define ConvertDays(%0) (gettime() + (86400 * (%0)))

enum VipI
{
    bool:Vip,
    Tempo,
    tagcolor[10]
};

new VipInfo[MAX_PLAYERS][VipI];
new cps_areavip;
new t_vip[MAX_PLAYERS];
new t_jetpack[MAX_PLAYERS];

hook OnGameModeInit()
{
    new db_vip[400];
    strins(db_vip, "CREATE TABLE IF NOT EXISTS `Vips`(", strlen(db_vip));
    strins(db_vip, "`id` int AUTO_INCREMENT,", strlen(db_vip));
    strins(db_vip, "`time` int(5) NOT NULL,", strlen(db_vip));
    strins(db_vip, "`tagcolor` varchar(10) NOT NULL DEFAULT 'FF0000',", strlen(db_vip));
    strins(db_vip, "`id_contas` int NOT NULL,", strlen(db_vip));
    strins(db_vip, "PRIMARY KEY(`id`),", strlen(db_vip));
    strins(db_vip, "FOREIGN KEY (`id_contas`) REFERENCES `Contas`(`id`) ON DELETE CASCADE)", strlen(db_vip));
    mysql_query(IDConexao, db_vip, false);

    cps_areavip = CreateDynamicCP(-783.7917, 495.3470, 1376.1953, 1.0, -1, -1, -1, 30.0);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    t_vip[playerid] = SetTimerEx("OnPlayerVIP", 1000, true, "d", playerid);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    DB_SaveVips(playerid);

    KillTimer(t_jetpack[playerid]);
    KillTimer(t_vip[playerid]);
    VipInfo[playerid][Vip] = false;
    VipInfo[playerid][Tempo] = 0;
    VipInfo[playerid][tagcolor] = 0;
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
                for(new vehicleid = 0; vehicleid < MAX_VEHICLES; vehicleid++)
                {
                    if(GetPlayerVehicleID(playerid) == PublicVehicle[vehicleid][pv_vehicle])
                    {
                        if(IsValidDynamicObject(PublicVehicle[vehicleid][pv_neon1])) DestroyDynamicObject(PublicVehicle[vehicleid][pv_neon1]);
                        if(IsValidDynamicObject(PublicVehicle[vehicleid][pv_neon2])) DestroyDynamicObject(PublicVehicle[vehicleid][pv_neon2]);
                        return 1;
                    }
                }
            }
            case 1:
            {
                for(new vehicleid = 0; vehicleid < MAX_VEHICLES; vehicleid++)
                {
                    if(GetPlayerVehicleID(playerid) == PublicVehicle[vehicleid][pv_vehicle])
                    {
                        if(IsValidDynamicObject(PublicVehicle[vehicleid][pv_neon1])) DestroyDynamicObject(PublicVehicle[vehicleid][pv_neon1]);
                        if(IsValidDynamicObject(PublicVehicle[vehicleid][pv_neon2])) DestroyDynamicObject(PublicVehicle[vehicleid][pv_neon2]);

                        PublicVehicle[vehicleid][pv_neon1] = CreateDynamicObject(18647,0,0,0,0,0,0);
                        PublicVehicle[vehicleid][pv_neon2] = CreateDynamicObject(18647,0,0,0,0,0,0);

                        AttachDynamicObjectToVehicle(PublicVehicle[vehicleid][pv_neon1], PublicVehicle[vehicleid][pv_vehicle], -0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
                        AttachDynamicObjectToVehicle(PublicVehicle[vehicleid][pv_neon2], PublicVehicle[vehicleid][pv_vehicle], 0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
                        return 1;
                    }
                }
            }
            case 2:
            {
                for(new vehicleid = 0; vehicleid < MAX_VEHICLES; vehicleid++)
                {
                    if(GetPlayerVehicleID(playerid) == PublicVehicle[vehicleid][pv_vehicle])
                    {
                        if(IsValidDynamicObject(PublicVehicle[vehicleid][pv_neon1])) DestroyDynamicObject(PublicVehicle[vehicleid][pv_neon1]);
                        if(IsValidDynamicObject(PublicVehicle[vehicleid][pv_neon2])) DestroyDynamicObject(PublicVehicle[vehicleid][pv_neon2]);

                        PublicVehicle[vehicleid][pv_neon1] = CreateDynamicObject(18652,0,0,0,0,0,0);
                        PublicVehicle[vehicleid][pv_neon2] = CreateDynamicObject(18652,0,0,0,0,0,0);

                        AttachDynamicObjectToVehicle(PublicVehicle[vehicleid][pv_neon1], PublicVehicle[vehicleid][pv_vehicle], -0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
                        AttachDynamicObjectToVehicle(PublicVehicle[vehicleid][pv_neon2], PublicVehicle[vehicleid][pv_vehicle], 0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
                        return 1;
                    }
                }
            }
            case 3:
            {
                for(new vehicleid = 0; vehicleid < MAX_VEHICLES; vehicleid++)
                {
                    if(GetPlayerVehicleID(playerid) == PublicVehicle[vehicleid][pv_vehicle])
                    {
                        if(IsValidDynamicObject(PublicVehicle[vehicleid][pv_neon1])) DestroyDynamicObject(PublicVehicle[vehicleid][pv_neon1]);
                        if(IsValidDynamicObject(PublicVehicle[vehicleid][pv_neon2])) DestroyDynamicObject(PublicVehicle[vehicleid][pv_neon2]);

                        PublicVehicle[vehicleid][pv_neon1] = CreateDynamicObject(18648,0,0,0,0,0,0);
                        PublicVehicle[vehicleid][pv_neon2] = CreateDynamicObject(18648,0,0,0,0,0,0);

                        AttachDynamicObjectToVehicle(PublicVehicle[vehicleid][pv_neon1], PublicVehicle[vehicleid][pv_vehicle], -0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
                        AttachDynamicObjectToVehicle(PublicVehicle[vehicleid][pv_neon2], PublicVehicle[vehicleid][pv_vehicle], 0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
                        return 1;
                    }
                }
            }
            case 4:
            {
                for(new vehicleid = 0; vehicleid < MAX_VEHICLES; vehicleid++)
                {
                    if(GetPlayerVehicleID(playerid) == PublicVehicle[vehicleid][pv_vehicle])
                    {
                        if(IsValidDynamicObject(PublicVehicle[vehicleid][pv_neon1])) DestroyDynamicObject(PublicVehicle[vehicleid][pv_neon1]);
                        if(IsValidDynamicObject(PublicVehicle[vehicleid][pv_neon2])) DestroyDynamicObject(PublicVehicle[vehicleid][pv_neon2]);

                        PublicVehicle[vehicleid][pv_neon1] = CreateDynamicObject(18649,0,0,0,0,0,0);
                        PublicVehicle[vehicleid][pv_neon2] = CreateDynamicObject(18649,0,0,0,0,0,0);

                        AttachDynamicObjectToVehicle(PublicVehicle[vehicleid][pv_neon1], PublicVehicle[vehicleid][pv_vehicle], -0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
                        AttachDynamicObjectToVehicle(PublicVehicle[vehicleid][pv_neon2], PublicVehicle[vehicleid][pv_vehicle], 0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
                        return 1;
                    }
                }
            }
            case 5:
            {
                for(new vehicleid = 0; vehicleid < MAX_VEHICLES; vehicleid++)
                {
                    if(GetPlayerVehicleID(playerid) == PublicVehicle[vehicleid][pv_vehicle])
                    {
                        if(IsValidDynamicObject(PublicVehicle[vehicleid][pv_neon1])) DestroyDynamicObject(PublicVehicle[vehicleid][pv_neon1]);
                        if(IsValidDynamicObject(PublicVehicle[vehicleid][pv_neon2])) DestroyDynamicObject(PublicVehicle[vehicleid][pv_neon2]);

                        PublicVehicle[vehicleid][pv_neon1] = CreateDynamicObject(18651,0,0,0,0,0,0);
                        PublicVehicle[vehicleid][pv_neon2] = CreateDynamicObject(18651,0,0,0,0,0,0);

                        AttachDynamicObjectToVehicle(PublicVehicle[vehicleid][pv_neon1], PublicVehicle[vehicleid][pv_vehicle], -0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
                        AttachDynamicObjectToVehicle(PublicVehicle[vehicleid][pv_neon2], PublicVehicle[vehicleid][pv_vehicle], 0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
                        return 1;
                    }
                }
            }
            case 6:
            {
                for(new vehicleid = 0; vehicleid < MAX_VEHICLES; vehicleid++)
                {
                    if(GetPlayerVehicleID(playerid) == PublicVehicle[vehicleid][pv_vehicle])
                    {
                        if(IsValidDynamicObject(PublicVehicle[vehicleid][pv_neon1])) DestroyDynamicObject(PublicVehicle[vehicleid][pv_neon1]);
                        if(IsValidDynamicObject(PublicVehicle[vehicleid][pv_neon2])) DestroyDynamicObject(PublicVehicle[vehicleid][pv_neon2]);

                        PublicVehicle[vehicleid][pv_neon1] = CreateDynamicObject(18650,0,0,0,0,0,0);
                        PublicVehicle[vehicleid][pv_neon2] = CreateDynamicObject(18650,0,0,0,0,0,0);

                        AttachDynamicObjectToVehicle(PublicVehicle[vehicleid][pv_neon1], PublicVehicle[vehicleid][pv_vehicle], -0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
                        AttachDynamicObjectToVehicle(PublicVehicle[vehicleid][pv_neon2], PublicVehicle[vehicleid][pv_vehicle], 0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
                        return 1;
                    }
                }
            }
        }
        return 1;
    }
    if(dialogid == vip_color_tag && response)
    {
        if(strlen(inputtext) != 6)
            return ShowPlayerDialog(playerid, vip_color_tag, DIALOG_STYLE_INPUT, "{FF0000}Tag VIP", "{FFFFFF}Digite um codigo em '{FF0000}HTML{FFFFFF}' abaixo\nPesquise no Google algo como {00FF00}Cores em HTML {FFFFFF}:\n{FF0000}Exemplo {FFFFFF}00FF00 = {00FF00}VIP", "Alterar", "Cancelar");

        format(VipInfo[playerid][tagcolor], 10, inputtext);

        format(String, sizeof(String), "A cor da sua tag [{%s}VIP{FFFFFF}] foi alterada", inputtext);
        SendClientMessage(playerid, White, String);

        DB_SaveVips(playerid);
        return 1;
    }
    return 1;
}

forward DB_LoadVips(playerid);
public DB_LoadVips(playerid)
{
    if(cache_num_rows() > 0)
    {
        new tmp[10];
        VipInfo[playerid][Vip] = true;
        cache_get_value_int(0, "time", VipInfo[playerid][Tempo]);
        cache_get_value_name(0, "tagcolor", tmp); format(VipInfo[playerid][tagcolor], 10, tmp);
    }
    else
    {
        VipInfo[playerid][Vip] = false;
        VipInfo[playerid][Tempo] = 0;
        VipInfo[playerid][tagcolor] = 0;
    }
    return 1;
}

forward OnPlayerVIP(playerid);
public OnPlayerVIP(playerid)
{
    if(!PlayerInfo[playerid][Logado] || !VipInfo[playerid][Vip]) return 0;

    if(VipInfo[playerid][Tempo] < gettime())
    {
        RemoveVip(playerid);
    }
    return 1;
}

stock OnPlayerGiveVIP(playerid, days, reaisspent)
{
    if(IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Você é membro da administração e não pode ter VIP");

    if(IsPlayerVip(playerid))
    {
        VipInfo[playerid][Tempo] += (86400 * days);
        DB_SaveVips(playerid);
    }
    else
    {
        VipInfo[playerid][Vip] = true;
        VipInfo[playerid][Tempo] = ConvertDays(days);
        format(VipInfo[playerid][tagcolor], 10, "FF0000");

        new query[100];
        mysql_format(IDConexao, query, sizeof(query), "INSERT INTO `Vips` (`time`, `id_contas`) VALUES ('%d', '%d')", VipInfo[playerid][Tempo], PlayerInfo[playerid][ID]);
        mysql_tquery(IDConexao, query);
    }

    SendClientMessage(playerid, 0x09CC57AA, "~~~~~~~~~~~~~~~~~~~~~~~~~ Ativação de VIP ~~~~~~~~~~~~~~~~~~~~~~~~~");
    format(String, sizeof String, "» Reais antigo: {1B6302}%d,00", (PlayerInfo[playerid][Reais] + reaisspent));
    SendClientMessage(playerid, White, String);
    format(String, sizeof String, "» Reais atual: {FF0000}%d,00", PlayerInfo[playerid][Reais]);
    SendClientMessage(playerid, White, String);
    format(String, sizeof String, "» VIP %s: {FFFF00}%d dias", (IsPlayerVip(playerid) ? ("renovado") : ("ativado")), days);
    SendClientMessage(playerid, White, String);
    SendClientMessage(playerid, White, "» Veja suas novas informações - /ComandosVip");
    SendClientMessage(playerid, 0x09CC57AA, "~~~~~~~~~~~~~~~~~~~~~~~~~ Ativação de VIP ~~~~~~~~~~~~~~~~~~~~~~~~~");
    return 1;
}

stock RemoveVip(playerid)
{
    new query[100];
    mysql_format(IDConexao, query, 100, "DELETE FROM `Vips` WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query);

    VipInfo[playerid][Tempo] = 0;
    VipInfo[playerid][Vip] = false;
    SendClientMessage(playerid, Red, "Infelizmente seus dias VIP expirou");
    return 1;
}

stock DB_SaveVips(playerid)
{
    if(!VipInfo[playerid][Vip]) return 0;

    new Query[200];
    mysql_format(IDConexao, Query, sizeof(Query), "UPDATE `Vips` SET `time`='%d', `tagcolor`='%e' WHERE `id_contas`='%d'", VipInfo[playerid][Tempo], VipInfo[playerid][tagcolor], PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, Query);
    return 1;
}

stock IsPlayerVip(playerid)
{
    if(VipInfo[playerid][Vip]) return true;
    return false;
}

stock TimeConvertEx(sec, &days, &hours, &minutes, &seconds)
{
    days = floatround(sec / 86400);
    hours = floatround((sec - (days * 86400)) / 3600);
    minutes = floatround((sec - (days * 86400) - (hours * 3600)) / 60);
    seconds = sec % 60;
    return 1;
}

/******************************************************************************/
/*****************************| COMMANDS LAWYER |******************************/
/******************************************************************************/

CMD:neon(playerid)
{
    if(!(IsPlayerVip(playerid) || IsPlayerIntern(playerid)))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsPlayerInAnyVehicle(playerid))
        return SendClientMessage(playerid, Erro, "Você não está em um veículo");

    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
        return SendClientMessage(playerid, Erro, "Você não está de motorista");

    new hour;

    gettime(hour);

    if(hour > 6 && hour < 18)
        return SendClientMessage(playerid, Erro, "Ainda não está de noite");

    ShowPlayerDialog(playerid, neon, DIALOG_STYLE_LIST, "{FF0000}Neon VIPs", "{FF0000}Remover Neon\n{FFFFFF}Vermelho\nBranco\nAzul\nVerde\nRosa\nAmarelo", "Concluir", "Cancelar");
    return 1;
}
CMD:tunar(playerid)
{
    if(!IsPlayerVip(playerid) && !IsPlayerIntern(playerid) && !IsPlayerYoutuber(playerid))
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

    new txt[200], str[100], value = ( VipInfo[playerid][Tempo] - gettime() ), days, hours, minutes, seconds;

    if(value > 86400) //+1d
    {
        TimeConvertEx(value, days, hours, minutes, seconds);

        format(str, 30, "%dDia(s) %02d:%02d:%02d", days, hours, minutes, seconds);
    }
    else if(value > 3600) //+1hr
    {
        TimeConvertEx(value, days, hours, minutes, seconds);

        format(str, 20, "%02d:%02d:%02d", hours, minutes, seconds);
    }
    else //+1min
    {
        TimeConvertEx(value, days, hours, minutes, seconds);

        format(str, 10, "%02d:%02d", minutes, seconds);
    }

    format(String, sizeof(String), "{FFFFFF} Nick: {FF0000}%s \n\n", PlayerInfo[playerid][Nome]);
    strcat(txt, String);
    format(String, sizeof(String), "{FFFFFF} Vencimento: {f29b0d}%s \n\n", str);
    strcat(txt, String);
    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{1b6302}Vencimento VIP ", txt, "Fechar", #);
    return 1;
}
CMD:reparar(playerid)
{
    if(!IsPlayerVip(playerid) && !IsPlayerIntern(playerid) && !IsPlayerYoutuber(playerid))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(Perseguicao[playerid] == true)
        return SendClientMessage(playerid, Erro, "Você está em perseguição e não poderar reparar o veiculo");

    if(!IsPlayerInAnyVehicle(playerid))
        return SendClientMessage(playerid, Erro, "Você não está em um veículo");

    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
        return SendClientMessage(playerid, Erro, "Você não está dirigindo");

    new vehicleid = GetPlayerVehicleID(playerid);

    if(IsBrokenVehicle(vehicleid))
        return SendClientMessage(playerid, Erro, "Este veículo está quebrado, compre kit reparo ou chame um mecânico");

    RepairVehicle(vehicleid);
    SendClientMessage(playerid, C_VIP, "Veículo reparado com sucesso");
    return 1;
}
CMD:virar(playerid)
{
    if(!IsPlayerVip(playerid) && !IsPlayerIntern(playerid) && !IsPlayerYoutuber(playerid))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsPlayerInAnyVehicle(playerid))
        return SendClientMessage(playerid, Erro, "Você não está em um carro");

    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
        return SendClientMessage(playerid, Erro, "Você não está dirigindo");

    new Float:a;
    GetVehicleZAngle(GetPlayerVehicleID(playerid), a);
    SetVehicleZAngle(GetPlayerVehicleID(playerid), a);
    SendClientMessage(playerid, C_VIP, "Veículo virado com sucesso");
    return 1;
}
CMD:colete(playerid)
{
    if(!IsPlayerVip(playerid) && !IsPlayerIntern(playerid) && !IsPlayerYoutuber(playerid))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    SetPlayerArmour(playerid, 100);
    SendClientMessage(playerid, C_VIP, "Colete criado com sucesso");
    return 1;
}
CMD:v(playerid, params[])
{
    if(!IsPlayerVip(playerid) && !IsPlayerIntern(playerid) && !IsPlayerYoutuber(playerid))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    new tmp[128];

    if(sscanf(params, "s[128]", tmp))
        return SendClientMessage(playerid,Erro, "Digite: /V [mensagem]");

    if(IsPlayerVip(playerid)) format(String, 128, "Chat-Vip ~ %s [%d] diz: %s", PlayerInfo[playerid][Nome], playerid, tmp);

    else if(IsPlayerIntern(playerid)) format(String, 128, "Chat-Vip ~ %s %s [%d] diz: %s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid, tmp);

    else if(IsPlayerYoutuber(playerid)) format(String, 128, "Chat-Vip ~ Youtuber %s [%d] diz: %s", PlayerInfo[playerid][Nome], playerid, tmp);


    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerIntern(i) || IsPlayerVip(i) || IsPlayerYoutuber(i))
        {
            SendClientMessage(i, C_VIP, String);
        }
    }

    #if !SERVER_OFFLINE
        TextConverterDiscord(tmp);

        format(String, 256, "%s [%d] diz: ```%s```", PlayerInfo[playerid][Nome], playerid, tmp);
        DCC_SendChannelMessage(Channels[dsc_vip], String);
    #endif

    return 1;
}
CMD:pintar(playerid, params[])
{
    if(!IsPlayerVip(playerid) && !IsPlayerIntern(playerid) && !IsPlayerYoutuber(playerid))
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    if(!IsPlayerInAnyVehicle(playerid))
        return SendClientMessage(playerid, Erro, "Você não está em um veiculo");

    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
        return SendClientMessage(playerid, Erro, "Você não está dirigindo");

    new color1, color2;

    if(sscanf(params, "dd", color1, color2))
        return SendClientMessage(playerid, Erro, "Digite: /Pintar [cor-id] [cor-id]");

    ChangeVehicleColor(GetPlayerVehicleID(playerid), color1, color2);
    SendClientMessage(playerid, C_VIP, "Veículo pintado com sucesso");
    return 1;
}

CMD:ativar(playerid)
{
    if(IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Membros da administração não pode ativar o mesmo");

    if(PlayerInfo[playerid][active])
        return SendClientMessage(playerid, Erro, "Só é possível ativar apenas uma vez");

    PlayerInfo[playerid][active] = 1;

    new query[100];
    mysql_format(IDConexao, query, 100, "UPDATE `Itens` SET `active`=1 WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_tquery(IDConexao, query);

    OnPlayerGiveVIP(playerid, 5, 0);
    return 1;
}
