    if(strcmp(cmd, "/tunar", true) == 0)
	{
        if(IsPlayerVip(playerid) || IsPlayerHelper(playerid))
        {
            if(!IsPlayerInAnyVehicle(playerid))
                return SendClientMessage(playerid, Erro, "| ERRO | Você não está em um carro!");

            if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
                return SendClientMessage(playerid, Erro, "| ERRO | Você não está dirigindo!");

            ShowPlayerDialog(playerid, tuning, DIALOG_STYLE_LIST,"{FF0000}Tunar","{FFFFFF}PaintJobs \nNitros \nRodas \nHidraulica","Concluir","Fechar");
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Você não tem permissão!");
        }
        return 1;
    }
    if(strcmp(cmd, "/tag", true)==0)
    {
        if(!IsPlayerVip(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Você não tem permissão!");

        ShowPlayerDialog(playerid, vip_color_tag, DIALOG_STYLE_INPUT, "{FF0000}Tag VIP", "{FFFFFF}Digite um codigo em '{FF0000}HTML{FFFFFF}' abaixo\nPesquise no Google algo como {00FF00}Cores em HTML {FFFFFF}:\n{FF0000}Exemplo {FFFFFF}00FF00 = {00FF00}VIP", "Alterar", "Cancelar");
        return 1;
    }
    if(strcmp(cmd, "/vencimento", true)==0)
    {
        if(!IsPlayerVip(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Você não tem permissão!");

        new str[128];
        format(String, sizeof(String), "{FFFFFF} Nick: {{FF0000}}%s \n\n", PlayerInfo[playerid][Nome]);
        strcat(str, String);
        format(String, sizeof(String), "{FFFFFF} Vencimento: {f29b0d}%d {FFFFFF}dias \n\n", VipInfo[playerid][Dias]);
        strcat(str, String);
        ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{1b6302}Vencimento VIP ", String, "Fechar", #);
        return 1;
    }
	if(strcmp(cmd, "/reparar", true) == 0)
    {
        if(IsPlayerVip(playerid) || IsPlayerHelper(playerid))
        {
            if(Perseguicao[playerid] == true)
                return SendClientMessage(playerid, Erro, "| ERRO | Você está em perseguição e não poderar reparar o veiculo!");

            if(!IsPlayerInAnyVehicle(playerid))
                return SendClientMessage(playerid, Erro, "| ERRO | Você não está em um carro!");

            if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
                return SendClientMessage(playerid, Erro, "| ERRO | Você não está dirigindo!");

            if(IsPlayerVip(playerid))
                { SendClientMessage(playerid, 0x00E100AA, "| VIP | Veículo reparado com sucesso!"); }

            if(IsPlayerHelper(playerid))
                { SendClientMessage(playerid, adm, "| BCM-Admin | Veículo reparado com sucesso!"); }

            RepairVehicle(GetPlayerVehicleID(playerid));
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Você não tem permissão!");
        }
    	return 1;
	}
    if (strcmp("/virar", cmdtext, true, 10) == 0)
    {
        if(IsPlayerVip(playerid) || IsPlayerHelper(playerid))
        {
            if(!IsPlayerInAnyVehicle(playerid))
                return SendClientMessage(playerid, Erro, "| ERRO | Você não está em um carro!");

            if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
                return SendClientMessage(playerid, Erro, "| ERRO | Você não está dirigindo!");

            if(IsPlayerVip(playerid))
                { SendClientMessage(playerid, 0x00E100AA, "| VIP | Veículo virado com sucesso!"); }

            if(IsPlayerHelper(playerid))
                { SendClientMessage(playerid, adm, "| BCM-Admin | Veículo virado com sucesso!"); }

            GetVehicleZAngle(GetPlayerVehicleID(playerid), A);
            SetVehicleZAngle(GetPlayerVehicleID(playerid), A);
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Você não tem permissão!");
        }
        return 1;
	}
    if(strcmp(cmd, "/colete", true)==0)
    {
        if(IsPlayerVip(playerid) || IsPlayerHelper(playerid))
        {
            if(IsPlayerVip(playerid))
                { SendClientMessage(playerid, 0x00E100AA, "| VIP | Colete criado com sucesso!"); }

            if(IsPlayerHelper(playerid))
                { SendClientMessage(playerid, adm, "| BCM-Admin | Colete criado com sucesso!"); }

            SetPlayerArmour(playerid, 100);
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Você não tem permissão!");
        }
        return 1;
    }
    if(strcmp(cmd, "/v", true)==0)
    {
        if(IsPlayerHelper(playerid) || IsPlayerVip(playerid))
        {
            new tmp[128];

            strmid(tmp, cmdtext, 2, strlen(cmdtext));

            if(!strlen(tmp))
                return SendClientMessage(playerid,Erro, "| ERRO | Digite: /V [mensagem]");

            if(IsPlayerVip(playerid))
                { format(String, sizeof(String), "| Chat-Vip | %s [%d] diz: %s", PlayerInfo[playerid][Nome], playerid, tmp); }

            if(IsPlayerHelper(playerid))
                { format(String, sizeof(String), "| Chat-Vip | %s %s [%d] diz: %s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid, tmp); }

            ChatVIP(0x00E100AA, String);
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Você não tem permissão!");
        }
        return 1;
	}
    if(strcmp(cmd, "/jetpack", true) == 0)
    {
        if(!(IsPlayerHelper(playerid) || IsPlayerVip(playerid)))
            return SendClientMessage(playerid, Erro, "| ERRO | Você não tem permissão!");

        if(IsPlayerInAnyVehicle(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Você precisa sair do veiculo!");

        if(IsPlayerVip(playerid))
            { SendClientMessage(playerid, 0x00E100AA, "| VIP | Jetpack criado com sucesso!"); }

        if(IsPlayerHelper(playerid))
            { SendClientMessage(playerid, adm, "| BCM-Admin | Jetpack criado com sucesso!"); }

        SetPlayerSpecialAction(playerid, 2);
        return 1;
    }
    if(strcmp(cmd, "/pintar", true) == 0)
    {
        if(!(IsPlayerHelper(playerid) || IsPlayerVip(playerid)))
            return SendClientMessage(playerid, Erro, "| ERRO | Você não tem permissão!");

        if(!IsPlayerInAnyVehicle(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Você não está em um veiculo!");

        if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não está dirigindo!");

        new tmp[128], tmp1[128], cor1, cor2;

        tmp = strtok(cmdtext, idx);
        tmp1 = strtok(cmdtext, idx);

        if(!strlen(tmp) || !strlen(tmp1))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /Pintar [cor-id] [cor-id]");

        if(IsPlayerVip(playerid))
            { SendClientMessage(playerid, 0x00E100AA, "| VIP | Veículo pintado com sucesso!"); }

        if(IsPlayerHelper(playerid))
            { SendClientMessage(playerid, adm, "| BCM-Admin | Veículo pintado com sucesso!"); }

        cor1 = strval(tmp);
        cor2 = strval(tmp1);

        ChangeVehicleColor(GetPlayerVehicleID(playerid), cor1, cor2);
        return 1;
	}
