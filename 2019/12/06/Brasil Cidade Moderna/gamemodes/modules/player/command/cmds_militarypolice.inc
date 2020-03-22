    if(!strcmp(cmd, "/prenderarmas", true))
    {
        if(PlayerInfo[playerid][Profissao] != PoliciaMunicipal)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não tem permissão!");

        if(!IsPlayerUniformePM(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Você não está com o uniforme!");

        new tmp[128], id;

        tmp = strtok(cmdtext, idx);

        if(!strlen(tmp))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /Prenderarmas [id]");

        id = strval(tmp);

        if(PlayerInfo[id][Logado] == false)
            return SendClientMessage(playerid, Erro, "| ERRO | Jogador(a) não está conectado(a)!");

        if(playerid == id)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não pode efetuar comando em sí mesmo!");

        if(GetDistanceBetweenPlayers(playerid, id) > 15)
            return SendClientMessage(playerid, Erro, "| ERRO | Você está muito longe, chegue mais perto!");

        if(PlayerInfo[id][Estrelas] == 0)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não está procurado(a)!");

        ResetPlayerWeapons(id);
        format(String, sizeof(String), " | POLICIA | Você prendeu todas as armas do(a) jogador(a) %s[%d]!", PlayerInfo[id][Nome], id);
        SendClientMessage(playerid, 0x2894FFAA, String);
        format(String, sizeof(String), " | POLICIA | O(A) Policial %s[%d] prendeu todas as suas armas!", PlayerInfo[playerid][Nome], playerid);
        SendClientMessage(id, 0x2894FFAA, String);
        return 1;
    }
    if(!strcmp(cmd, "/perseguicao", true))
    {
        if(PlayerInfo[playerid][Profissao] != PoliciaMunicipal)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não tem permissão!");

        if(!IsPlayerUniformePM(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Você não está com o uniforme!");

        new tmp[128], id;

        tmp = strtok(cmdtext, idx);

        if(!strlen(tmp))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /Perseguicao [id]");

        id = strval(tmp);

        if(PlayerInfo[id][Logado] == false)
            return SendClientMessage(playerid, Erro, "| ERRO | Jogador(a) não está conectado(a)!");

        if(playerid == id)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não pode efetuar comando em sí mesmo!");

        if(GetDistanceBetweenPlayers(playerid, id) > 15)
            return SendClientMessage(playerid, Erro, "| ERRO | Você está muito longe, chegue mais perto!");

        if(Abordado[id] == false)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não está abordado(a)!");

        if(Perseguicao[id] == true)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) já está em perseguição!");

        Perseguicao[id]=true;
        PerseguicaoTime[id] = SetTimerEx("ExitPersecution", 1000*60*5, false, "i", id);
        format(String, sizeof(String), "PERSEGUIÇÃO: O(A) Policial %s[%d] iniciou uma perseguição no(a) jogador(a) %s[%d] por não se render!", PlayerInfo[playerid][Nome], playerid, PlayerInfo[id][Nome], id);
        SendClientMessageToAll(0x2894FFAA, String);
        return 1;
    }
    if(!strcmp(cmd, "/localizar", true))
    {
        if(PlayerInfo[playerid][Profissao] != PoliciaMunicipal)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não tem permissão!");

        if(!IsPlayerUniformePM(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Você não está com o uniforme!");

        new tmp[128], id;

        tmp = strtok(cmdtext, idx);

        if(!strlen(tmp))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /Localizar [id]");

        id = strval(tmp);

        if(PlayerInfo[id][Logado] == false)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não conectado(a)!");

        if(playerid == id)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não pode efetuar comando em sí mesmo!");

        if(PlayerInfo[id][Estrelas] == 0)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não está procurado(a)!");

        if(localizado[id] == true)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) já foi localizado(a)!");

        TimerProcurando[id] = SetTimerEx("GPSUpdate", 1500, true, "dd", playerid, id);
        SendClientMessage(playerid, Verde, "GPS:{FFFFFF} Jogador(a) localizado(a) com sucesso!");
        return 1;
    }
    if(!strcmp(cmd, "/deslocalizar", true))
    {
        if(PlayerInfo[playerid][Profissao] != PoliciaMunicipal)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não tem permissão!");

        if(!IsPlayerUniformePM(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Você não está com o uniforme!");

        new tmp[128], id;

        tmp = strtok(cmdtext, idx);

        if(!strlen(tmp))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /Deslocalizar [id]");

        id = strval(tmp);

        if(PlayerInfo[id][Logado] == false)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não conectado(a)!");

        if(playerid == id)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não pode efetuar comando em sí mesmo!");

        if(PlayerInfo[id][Estrelas] == 0)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não está procurado(a)!");

        if(localizado[id] == false)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não está localizado(a)!");

        DisablePlayerCheckpoint(id);
        KillTimer(TimerProcurando[id]);
    	localizado[id]=false;
        SendClientMessage(playerid, Verde, "| GPS | Jogador(a) deslocalizado(a) com sucesso!");
        return 1;
    }
    if(!strcmp(cmd, "/abordar", true))
	{
        if(PlayerInfo[playerid][Profissao] != PoliciaMunicipal)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não tem permissão!");

        if(!IsPlayerUniformePM(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Você não está com o uniforme!");

        new tmp[128], id;

        tmp = strtok(cmdtext, idx);

        if(!strlen(tmp))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /abordar [ID Procurado(a)]");

        id = strval(tmp);

        if(PlayerInfo[id][Logado] == false)
            return SendClientMessage(playerid, Erro, "| ERRO | Jogador(a) não está conectado(a)!");

        if(playerid == id)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não pode efetuar comando em sí mesmo!");

        if(GetDistanceBetweenPlayers(playerid, id) > 15)
            return SendClientMessage(playerid, Erro, "| ERRO | Você está muito longe, chegue mais perto!");

        if(Abordado[id] == true)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) já está abordado(a)!");

        if(PlayerInfo[id][Estrelas] == 0)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não está procurado(a)!");

        Abordado[id] = true;
        GameTextForPlayer(id, "~b~Abordagem!", 1000, 0);
        format(String, sizeof(String), " | ABORDAGEM | Você foi abordado pelo Policial %s[%d]", PlayerInfo[playerid][Nome], playerid);
        SendClientMessage(id, 0x2894FFAA, String);
        format(String, sizeof(String), " | ABORDAGEM | Você abordou o(a) Jogador(a) %s[%d]", PlayerInfo[id][Nome], id);
        SendClientMessage(playerid, 0x2894FFAA, String);
     	return 1;
	}
    if(!strcmp(cmd, "/algemar", true))
	{
        if(PlayerInfo[playerid][Profissao] != PoliciaMunicipal)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não tem permissão!");

        if(!IsPlayerUniformePM(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Você não está com o uniforme!");

        new tmp[128], id;

        tmp = strtok(cmdtext, idx);

        if(!strlen(tmp))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /algemar [ID Procurado(a)]");

        id = strval(tmp);

        if(PlayerInfo[id][Logado]==false)
            return SendClientMessage(playerid, Erro, "| ERRO | Jogador(a) não está conectado(a)!");

        if(playerid == id)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não pode efetuar comando em sí mesmo!");

        if(GetDistanceBetweenPlayers(playerid, id) > 15)
            return SendClientMessage(playerid, Erro, "| ERRO | Você está muito longe, chegue mais perto!");

        if(Abordado[id] == false)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não está abordado(a)!");

        if(IsPlayerInAnyVehicle(playerid) == 1)
            return SendClientMessage(playerid, Erro, "| ERRO | Você está em um veiculo!");

        if(IsPlayerInAnyVehicle(id) == 1)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) está em um veiculo!");

        Algemado[id] = true;
        Abordado[id] = false;
        TogglePlayerControllable(id, false);
        SetPlayerSpecialAction(id, SPECIAL_ACTION_CUFFED);
        SetPlayerAttachedObject(id,4,19418,6,-0.031999,0.024000,-0.024000,-7.900000,-32.000011,-72.299987,1.115998,1.322000,1.406000);

        GameTextForPlayer(id, "~b~ALGEMADO!", 1000, 0);
        format(String, sizeof(String), " | ALGEMADO | Você algemou o(a) Jogador(a) %s ", PlayerInfo[id][Nome]);
        SendClientMessage(playerid, 0x2894FFAA, String);
        format(String, sizeof(String), " | ALGEMADO | Você foi algemado pelo Policial %s ", PlayerInfo[playerid][Nome]);
        SendClientMessage(id, 0x2894FFAA, String);
     	return 1;
	}
    if(!strcmp(cmd, "/prender", true))
    {
        if(PlayerInfo[playerid][Profissao] != PoliciaMunicipal)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não tem permissão!");

        if(!IsPlayerUniformePM(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Você não está com o uniforme!");

        new tmp[128], id;

        tmp = strtok(cmdtext, idx);

        if(!strlen(tmp))
            return SendClientMessage(playerid, Erro, "| ERRO | /Prender [ID]");

        id = strval(tmp);

        if(PlayerInfo[id][Logado] == false)
            return SendClientMessage(playerid, Erro, "| ERRO | Jogador(a) não está conectado(a)!");

        if(playerid == id)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não pode efetuar comando em sí mesmo!");

        if(PrisonEnum[id][pTempo] != 0)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) jogador(a) está preso!");

        if(GetDistanceBetweenPlayers(playerid, id) > 15)
            return SendClientMessage(playerid, Erro, "| ERRO | Você está muito longe, chegue mais perto!");

        if(Algemado[id] == false)
            return SendClientMessage(playerid, Erro, "| ERRO | O(a) Jogador(a) precisa estar algemado para prender!");

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

        GameTextForPlayer(id, "~w~PRESO!", 1000, 0);
        format(String, sizeof(String), "| PRISÃO | Você foi preso pelo Policial %s ( Motivo: Procurado(a) )", PlayerInfo[playerid][Nome]);
        SendClientMessage(id, 0x2894FFAA, String);
        format(String, sizeof(String), "| POLICIA | Você prendeu o(a) Jogador(a) %s ( Procurado(a) )", PlayerInfo[id][Nome]);
        SendClientMessage(playerid, 0x2894FFAA, String);
        format(String, sizeof(String), "| POLICIA | Você recebeu a recompensa de $%d por prender um jogador(a) que estava sendo procurado(a) pela policia", PlayerInfo[id][Estrelas]*100);
        SendClientMessage(playerid, 0x2894FFAA, String);

        mysql_format(IDConexao, String, sizeof(String), "INSERT INTO `Prisoes` (Nome, Responsavel, Cadeia, Motivo, Tempo) VALUES ('%e', '%e', '%e', '%e', '%d')", PlayerInfo[id][Nome], PlayerInfo[playerid][Nome], PrisonEnum[id][pCadeia], PrisonEnum[id][pMotivo], PrisonEnum[id][pTempo]);
        mysql_query(IDConexao, String);
        mysql_format(IDConexao, String, sizeof(String), "SELECT * FROM `Prisoes` WHERE `Nome`='%e'", PlayerInfo[id][Nome]);
        mysql_tquery(IDConexao, String, "DBLoadPrisons", "d", id);
        return 1;
    }
