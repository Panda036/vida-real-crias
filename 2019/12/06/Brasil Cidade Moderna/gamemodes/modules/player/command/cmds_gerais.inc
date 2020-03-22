    if(strcmp(cmd, "/comandoscasa", true)==0)
    {
        new txt[300];
        strcat(txt, "{FF0000}Comandos \t\t {1CEB00}Informações \n");
        strcat(txt, "{87CEFF}/EntrarCasa \t\t Para entrar na casa\n");
        strcat(txt, "{87CEFF}/SairCasa \t\t Para sair da casa\n");
        strcat(txt, "{87CEFF}/ComprarCasa \t\t Para comprar a casa\n");
        strcat(txt, "{87CEFF}/MenuCasa \t\t Para ver outros comandos da casa\n");
        ShowPlayerDialog(playerid, MAIN_HOUSE_COMMAND, DIALOG_STYLE_TABLIST_HEADERS, "{C0C0C0}Comandos Casa", txt, "Fechar", #);
        return 1;
    }
    if(strcmp(cmd, "/reais", true)==0)
    {
        ShowPlayerDialog(playerid, reais, DIALOG_STYLE_LIST, "{FF0000}Reais", "{FFFFFF}Comprar VIP", "Continuar", "Cancelar");
        return 1;
    }
    if(strcmp(cmd, "/profissao", true)==0)
    {
        switch(PlayerInfo[playerid][Profissao])
        {
            case Desempregado:
            {
                new string[1000];
                strcat(string, "{FFFFFF}Você está desempregado, para conseguir um vá até a Agencia de Empregos em uma das 3 cidades de san andreas \n\n");
                strcat(string, "{FFFFFF}Los Santos - Está localizado perto da praia de Santa Maria \n\n");
                strcat(string, "{FFFFFF}Las Venturas - Está localizado perto do Aero Porto \n\n");
                strcat(string, "{FFFFFF}San Fierro - Está localizado perto da Estação Ferroviária \n\n");
                strcat(string, "{FFFFFF}Todas as Agências de Empregos tem um simbolo de uma {1e90ff}Caveira Azul {FFFFFF}no Radar \n\n");
                ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Desempregado", string, "Fechar", "");
            }
            case EntregadorJornais:
            {
                new string[1000];
                strcat(string, "{FF0000}Comandos \t\t {FFFFFF}Informações \n");
                strcat(string, "{80FF80}/Pegarjornais {FFFFFF}\t\t Para pegar 20 jornais \n");
                strcat(string, "{80FF80}/Cancelar {FFFFFF}\t\t Para cancelar as entregas dos jornais \n");
                strcat(string, "{80FF80}/Hq {FFFFFF}\t\t Para localizar o local do seu trabalho \n");
                strcat(string, "{80FF80}/Cp [mensagem] {FFFFFF}\t\t Para usar o chat profissão \n");
                ShowPlayerDialog(playerid, 0, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Entregador de Jornais", string, "Fechar", "");
            }
            case EntregadorPizzas:
            {
                new string[1000];
                strcat(string, "{FF0000}Comandos \t\t {FFFFFF}Informações \n");
                strcat(string, "{EDA909}/PegarPizzas {FFFFFF}\t\t Para pegar 10 pizzas \n");
                strcat(string, "{EDA909}/Cancelar {FFFFFF}\t\t Para cancelar as entregas de pizzas \n");
                strcat(string, "{EDA909}/Hq {FFFFFF}\t\t Para localizar o local do seu trabalho \n");
                strcat(string, "{EDA909}/Cp [mensagem] {FFFFFF}\t\t Para usar o chat profissão \n");
                ShowPlayerDialog(playerid, 0, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Entregador de Pizzas", string, "Fechar", "");
            }
            case VendedorSkins:
            {
                new string[1000];
                strcat(string, "{FF0000}Comandos \t\t {FFFFFF}Informações \n");
                strcat(string, "{FF80C0}/VenderSkin {FFFFFF}\t\t Para oferecer skin para um(a) jogador(a) \n");
                strcat(string, "{FF80C0}/Hq {FFFFFF}\t\t Para localizar o local do seu trabalho \n");
                strcat(string, "{FF80C0}/Cp [mensagem] {FFFFFF}\t\t Para usar o chat profissão \n");
                ShowPlayerDialog(playerid, 0, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Vendedor de Skins", string, "Fechar", "");
            }
            case Advogado:
            {
                new string[1000];
                strcat(string, "{FF0000}Comandos \t\t {FFFFFF}Informações \n");
                strcat(string, "{8000FF}/Presos {FFFFFF}\t\t Para ver s jogador(a) que está preso(a) \n");
                strcat(string, "{8000FF}/Soltar {FFFFFF}\t\t Para soltar um determinado jogador(a) \n");
                strcat(string, "{8000FF}/Hq {FFFFFF}\t\t Para localizar o local do seu trabalho \n");
                strcat(string, "{8000FF}/Cp [mensagem] {FFFFFF}\t\t Para usar o chat profissão \n");
                ShowPlayerDialog(playerid, 0, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Entregador Jornal", string, "Fechar", "");
            }
            case Taxi:
            {
            	new string[1000];
                strcat(string, "{FF0000}Comandos \t\t {FFFFFF}Informações \n");
                strcat(string, "{FFFF00}/Localizar [id] {FFFFFF}\t\t Para localizar o cliente \n");
                strcat(string, "{FFFF00}/Hq {FFFFFF}\t\t Para localizar o local do seu trabalho \n");
                strcat(string, "{FFFF00}/Cp [mensagem] {FFFFFF}\t\t Para usar o chat profissão \n");
                ShowPlayerDialog(playerid, 0, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Taxi", string, "Fechar", "");
            }
            case PoliciaMunicipal:
            {
                new string[1000];
                strcat(string, "{FF0000}Comandos \t\t {FFFFFF}Informações \n");
                strcat(string, "{FFFFFF}Aperte '{4AA5FF}Y{FFFFFF}' {FFFFFF}\t\t Para equipar uniforme e armas dentro do departamento\n");
                strcat(string, "{FFFFFF}Aperte '{4AA5FF}F{FFFFFF}' ou '{4AA5FF}Enter{FFFFFF}' {FFFFFF}\t\t Para abrir o portão do derpartamento\n");
                strcat(string, "{4AA5FF}/Prenderarmas [id] {FFFFFF}\t\t Para apreender as armas de um(a) jogador(a) \n");
                strcat(string, "{4AA5FF}/Localizar [id] {FFFFFF}\t\t Para localizar o(a) procurado(a) \n");
                strcat(string, "{4AA5FF}/Algemar [id] {FFFFFF}\t\t Para algemar o(a) procurado(a) \n");
                strcat(string, "{4AA5FF}/Prender [id] {FFFFFF}\t\t Para prender o(a) procurado(a) \n");
                strcat(string, "{4AA5FF}/Abordar [id] {FFFFFF}\t\t Para abordar o(a) procurado(a) \n");
                strcat(string, "{4AA5FF}/Hq {FFFFFF}\t\t Para localizar o local do seu trabalho \n");
                strcat(string, "{4AA5FF}/Cp [mensagem] {FFFFFF}\t\t Para usar o chat profissão \n");
                ShowPlayerDialog(playerid, 0, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Policial Militar", string, "Fechar", #);
            }
            case Corregedoria:
            {
                new string[1000];
                strcat(string, "{FF0000}Comandos \t\t {FFFFFF}Informações \n");
                strcat(string, "{8080C0}/PrenderPolicial [id] {FFFFFF}\t\t Para prender o(a) policial \n");
                strcat(string, "{8080C0}/Hq {FFFFFF}\t\t Para localizar o local do seu trabalho \n");
                strcat(string, "{8080C0}/Cp [mensagem] {FFFFFF}\t\t Para usar o chat profissão \n");
                ShowPlayerDialog(playerid, 0, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Corregedoria", string, "Fechar", "");
            }
            case LadraoGas:
            {
            	new string[1000];
                strcat(string, "{FF0000}Comandos \t\t {FFFFFF}Informações \n");
                strcat(string, "{FF8080}/PlanejarRoubo {FFFFFF}\t\t Para começar a roubar os gás \n");
                strcat(string, "{FF8080}/PegarGas {FFFFFF}\t\t Para pegar o gás \n");
                strcat(string, "{FF8080}/CancelarRoubo {FFFFFF}\t\t Para cancelar o roubo \n");
                strcat(string, "{FF8080}/ColocarGas {FFFFFF}\t\t Para colocar o gás no caminhão \n");
                strcat(string, "{FF8080}/Hq {FFFFFF}\t\t Para localizar o local do seu trabalho \n");
                strcat(string, "{FF8080}/Cp [mensagem] {FFFFFF}\t\t Para usar o chat profissão \n");
                ShowPlayerDialog(playerid, 0, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Ladrão de Gás", string, "Fechar", "");
            }
        }
        return 1;
	}
    if(strcmp(cmd, "/trabalhar", true)==0)
    {
        if(AgenciaEncaminhado[playerid] == false)
            return SendClientMessage(playerid, Erro,"| ERRO | Você não foi encaminhado por nenhuma Agencia!");

        if(PlayerInfo[playerid][Semprofissao] == EntregadorJornais && IsPlayerInRangeOfPoint(playerid, 2.0, 785.2020,-1327.7697,13.5469))
        {
            SendClientMessage(playerid, 0x80FF80AA, "| PROFISSÃO | Apartir de agora você ira exerce a profissão Entregador de Jornais");
            SendClientMessage(playerid, 0x80FF80AA, "| PROFISSÃO | Para saber os comandos da profissão, digite: /Profissao");
            PlayerInfo[playerid][Profissao] = EntregadorJornais;
            PlayerInfo[playerid][Semprofissao] = 0;
            SetColorProfession(playerid);
            PlayerPlaySound(playerid, 1057, 0, 0, 0);
            DestroyPickup(AgenciaPickup[playerid]);
            DestroyDynamicMapIcon(AgenciaMapIcon[playerid]);
            AgenciaEncaminhado[playerid] = false;
        }
        else if(PlayerInfo[playerid][Semprofissao] == EntregadorPizzas && IsPlayerInRangeOfPoint(playerid, 2.0, 2107.9692, -1788.2231, 13.5608))
        {
            SendClientMessage(playerid, 0xEDA909AA, "| PROFISSÃO | Apartir de agora você ira exerce a profissão Entregador de Pizzas");
            SendClientMessage(playerid, 0xEDA909AA, "| PROFISSÃO | Para saber os comandos da profissão, digite: /Profissao");
            PlayerInfo[playerid][Profissao] = EntregadorPizzas;
            PlayerInfo[playerid][Semprofissao] = 0;
            SetColorProfession(playerid);
            PlayerPlaySound(playerid, 1057, 0, 0, 0);
            DestroyPickup(AgenciaPickup[playerid]);
            DestroyDynamicMapIcon(AgenciaMapIcon[playerid]);
            AgenciaEncaminhado[playerid] = false;
        }
        else if(PlayerInfo[playerid][Semprofissao] == VendedorSkins && IsPlayerInRangeOfPoint(playerid, 2.0, 2251.76929, -1665.62854, 15.58825))
        {
            SendClientMessage(playerid, 0xFF80C0AA, "| PROFISSÃO | Apartir de agora você ira exerce a profissão Vendedor de Skins");
            SendClientMessage(playerid, 0xFF80C0AA, "| PROFISSÃO | Para saber os comandos da profissão, digite: /Profissao");
            PlayerInfo[playerid][Profissao] = VendedorSkins;
            PlayerInfo[playerid][Semprofissao] = 0;
            SetColorProfession(playerid);
            PlayerPlaySound(playerid, 1057, 0, 0, 0);
            DestroyPickup(AgenciaPickup[playerid]);
            DestroyDynamicMapIcon(AgenciaMapIcon[playerid]);
            AgenciaEncaminhado[playerid] = false;
        }
        else if(PlayerInfo[playerid][Semprofissao] == Advogado && IsPlayerInRangeOfPoint(playerid, 2.0, -2051.2988,459.8927,35.1719))
        {
            SendClientMessage(playerid, 0x8000FFAA, "| PROFISSÃO | Apartir de agora você ira exerce a profissão Advogado");
            SendClientMessage(playerid, 0x8000FFAA, "| PROFISSÃO | Para saber os comandos da profissão, digite: /Profissao");
            PlayerInfo[playerid][Profissao] = Advogado;
            PlayerInfo[playerid][Semprofissao] = 0;
            SetColorProfession(playerid);
            PlayerPlaySound(playerid, 1057, 0, 0, 0);
            DestroyPickup(AgenciaPickup[playerid]);
            DestroyDynamicMapIcon(AgenciaMapIcon[playerid]);
            AgenciaEncaminhado[playerid] = false;
        }
        else if(PlayerInfo[playerid][Semprofissao] == Taxi && IsPlayerInRangeOfPoint(playerid, 2.0, 2229.5803,-1368.1969,23.9922))
        {
            SendClientMessage(playerid, 0xFFFF00AA, "| PROFISSÃO | Apartir de agora você ira exerce a profissão Taxi");
            SendClientMessage(playerid, 0xFFFF00AA, "| PROFISSÃO | Para saber os comandos da profissão, digite: /Profissao");
            PlayerInfo[playerid][Profissao] = Taxi;
            PlayerInfo[playerid][Semprofissao] = 0;
            SetColorProfession(playerid);
            PlayerPlaySound(playerid, 1057, 0, 0, 0);
            DestroyPickup(AgenciaPickup[playerid]);
            DestroyDynamicMapIcon(AgenciaMapIcon[playerid]);
            AgenciaEncaminhado[playerid] = false;
        }
        else if(PlayerInfo[playerid][Semprofissao] == PoliciaMunicipal && IsPlayerInRangeOfPoint(playerid, 2.0, 1579.5728,-1635.3932,13.5611))
        {
            SendClientMessage(playerid, 0x66B3FFAA, "| PROFISSÃO | Apartir de agora você ira exerce a profissão Policia Municipal");
            SendClientMessage(playerid, 0x66B3FFAA, "| PROFISSÃO | Para saber os comandos da profissão, digite: /Profissao");
            PlayerInfo[playerid][Profissao] = PoliciaMunicipal;
            PlayerInfo[playerid][Semprofissao] = 0;
            SetColorProfession(playerid);
            PlayerPlaySound(playerid, 1057, 0, 0, 0);
            DestroyPickup(AgenciaPickup[playerid]);
            DestroyDynamicMapIcon(AgenciaMapIcon[playerid]);
            AgenciaEncaminhado[playerid] = false;
        }
        else if(PlayerInfo[playerid][Semprofissao] == Corregedoria && IsPlayerInRangeOfPoint(playerid, 2.0, 2339.9778,2457.2256,14.9688))
        {
            SendClientMessage(playerid, 0x8080C0AA, "| PROFISSÃO | Apartir de agora você ira exerce a profissão Corregedoria");
            SendClientMessage(playerid, 0x8080C0AA, "| PROFISSÃO | Para saber os comandos da profissão, digite: /Profissao");
            PlayerInfo[playerid][Profissao] = Corregedoria;
            PlayerInfo[playerid][Semprofissao] = 0;
            SetColorProfession(playerid);
            PlayerPlaySound(playerid, 1057, 0, 0, 0);
            DestroyPickup(AgenciaPickup[playerid]);
            DestroyDynamicMapIcon(AgenciaMapIcon[playerid]);
            AgenciaEncaminhado[playerid] = false;
        }
        else if(PlayerInfo[playerid][Semprofissao] == LadraoGas && IsPlayerInRangeOfPoint(playerid, 2.0, -453.7872,2230.1296,42.4993))
        {
            SendClientMessage(playerid, 0xFF8080AA, "| CARGO | Apartir de agora você ira exerce o cargo Ladrão");
            SendClientMessage(playerid, 0xFF8080AA, "| CARGO | Para saber os comandos do cargo, digite: /Profissao");
            PlayerInfo[playerid][Profissao] = LadraoGas;
            PlayerInfo[playerid][Semprofissao] = 0;
            SetColorProfession(playerid);
            PlayerPlaySound(playerid, 1057, 0, 0, 0);
            DestroyPickup(AgenciaPickup[playerid]);
            DestroyDynamicMapIcon(AgenciaMapIcon[playerid]);
            AgenciaEncaminhado[playerid] = false;
        } else {
            format(String, sizeof(String), "| ERRO | Você não está na HQ de %s", PlayerInfo[playerid][Semprofissao]);
            SendClientMessage(playerid, Erro, String);
        }
        return 1;
    }
    if(strcmp(cmd, "/partida", true)==0)
    {
        new vehicleid = GetPlayerVehicleID(playerid), mot, lu, alar, por, cap, porma, ob;

        GetVehicleParamsEx(vehicleid,  mot, lu, alar, por, cap, porma, ob);

        if(!IsPlayerInAnyVehicle(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Você não está em um veículo!");

        if(IsPlayerInAnyBike(vehicleid))
            return SendClientMessage(playerid, Erro, "| ERRO | Você está em uma bicicleta!");

        if(mot == VEHICLE_PARAMS_OFF)
        {
            SetVehicleParamsEx(vehicleid, VEHICLE_PARAMS_ON, lu, alar, por, cap, porma, ob);
            SendClientMessage(playerid, Verde, "| INFO | Veiculo ligado!");
        } else {
        	SendClientMessage(playerid, Verde, "| INFO | Veiculo desligado!");
            SetVehicleParamsEx(vehicleid, VEHICLE_PARAMS_OFF, lu, alar, por, cap, porma, ob);
        }
        return 1;
    }
    if(strcmp(cmd, "/radio", true)==0)
    {
        new tmp[128];

        tmp = strrest(cmdtext, idx);

        if(!strlen(tmp))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /Radio [Link.mp3]");

        PlayAudioStreamForPlayer(playerid, tmp);
        SendClientMessage(playerid, Branco, "| RÁDIO | Para pausar digite: /radio stop ou espaço apenas!");
        return 1;
    }
    if(strcmp(cmd, "/radios", true)==0)
    {
        static texto[500];
        strcat(texto, "{FFFFFF}Rádio Jovem Pan \nRádio Hunter    \n");
        strcat(texto, "{FFFFFF}Rádio Massa FM  \nRádio Reggae141 \n");
        strcat(texto, "{FF0000}Desligar Radios ");
        ShowPlayerDialog(playerid, radio, DIALOG_STYLE_LIST, "{FF0000}MP3", texto, "Continuar", "Fechar");
        return 1;
    }
    if(strcmp(cmd, "/mudarnick", true)==0)
    {
        if(PlayerInfo[playerid][Reais] < 7000)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não tem Reais o suficiente para mudar o nick");

        ShowPlayerDialog(playerid, rename, DIALOG_STYLE_INPUT, "{FF0000}Mudar nick", "{FFFFFF}Digite seu novo nick e clique em {FF0000}Mudar\n{FFFFFF}Por favor não coloque {FF0000}ESPAÇO {FFFFFF}em seu nick:", "Mudar", "Sair");
        return 1;
    }
    if(strcmp(cmd, "/meulevel", true)==0)
    {
        static str[128];
        format(String, sizeof(String), "{FFFFFF} Nick: {FF0000}%s \n\n", PlayerInfo[playerid][Nome]);
        strcat(str, String);
        format(String, sizeof(String), "{FFFFFF} Level: {1b6302}%d \n\n", PlayerInfo[playerid][Level]);
        strcat(str, String);
        format(String, sizeof(String), "{FFFFFF} Experiência: {f29b0d}%d \n\n", PlayerInfo[playerid][Exp]);
        strcat(str, String);
        ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FFFFF}Meu Level", str, "Fechar", "");
        return 1;
    }
    if(strcmp(cmd, "/ajuda", true)==0)
    {
        new textos[200];
        strcat(textos, "{FFFFFF}Level \n");
        strcat(textos, "{FFFFFF}Salário \n");
        strcat(textos, "{FFFFFF}Comandos \n");
        strcat(textos, "{FFFFFF}Contatos \n");
        strcat(textos, "{FFFFFF}Casa \n");
        strcat(textos, "{FFFFFF}Base \n");
        strcat(textos, "{FFFFFF}Empresa \n");
        strcat(textos, "{FFFFFF}Veículo \n");
        strcat(textos, "{FFFFFF}Loteria \n");
        strcat(textos, "{FFFFFF}Mercadoria \n");
        ShowPlayerDialog(playerid, help, DIALOG_STYLE_LIST, "{FF0000}Ajuda", textos, "Continuar", "Cancelar");
        return 1;
    }
    if(strcmp(cmd, "/entrar", true)==0)
	{
        EntrarInterior(playerid);
        return 1;
    }
    if(strcmp(cmd, "/Sair", true) == 0)
	{
        SairInterior(playerid);
        return 1;
    }
    if(strcmp(cmd, "/identidade", true) == 0)
    {
        new str[1000], str1[100];
        format(str1, sizeof(str1), "{0080FF}Identidade de {FFFFFF}%s", PlayerInfo[playerid][Nome]);

        format(String, sizeof(String), "{FFFFFF}» Level: {00C40A}%d \n", PlayerInfo[playerid][Level]);
        strcat(str, String);
        format(String, sizeof(String), "{FFFFFF}» Experiência: {00C40A}%d \n", PlayerInfo[playerid][Exp]);
        strcat(str, String);
        format(String, sizeof(String), "{FFFFFF}» Reais: {00C40A}R$%d \n", PlayerInfo[playerid][Reais]);
        strcat(str, String);
        if(VipInfo[playerid][Vip] == false)
        {
            format(String, sizeof(String), "{FFFFFF}» VIP: {f84300}Não \n");
        }
        if(VipInfo[playerid][Vip] == true)
        {
            format(String, sizeof(String), "{FFFFFF}» VIP: {00C40A}Sim \n");
        }
        strcat(str, String);
        format(String, sizeof(String), "{FFFFFF}» Skin ID: {00C40A}%d \n", PlayerInfo[playerid][Skin]);
        strcat(str, String);
        format(String, sizeof(String), "{FFFFFF}» Dinheiro: {00C40A}%d \n", PlayerInfo[playerid][Dinheiro]);
        strcat(str, String);
        format(String, sizeof(String), "{FFFFFF}» Matou: {00C40A}%d {FFFFFF}- Morreu: {f84300}%d \n", PlayerInfo[playerid][Matou], PlayerInfo[playerid][Morreu]);
        strcat(str, String);
        format(String, sizeof(String), "{FFFFFF}» Avisos: {f84300}%d \n", PlayerInfo[playerid][Avisos]);
        strcat(str, String);
        format(String, sizeof(String), "{FFFFFF}» E-mail: {00C40A}%s \n", PlayerInfo[playerid][Email]);
        strcat(str, String);
        ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, str1, str, "Fechar", "");
        return 1;
    }
    if(strcmp(cmd, "/statusmostrar", true) == 0)
    {
        StatusMostrar(playerid);
        return 1;
    }
    if(strcmp(cmd, "/statusocultar", true) == 0)
    {
        StatusOcultar(playerid);
        return 1;
    }
    if(strcmp(cmd, "/relatorio", true) == 0)
    {
    	if(LiberarRelatorio{playerid} == true)
            return SendClientMessage(playerid, Erro, "| ERRO | Relatório bloqueado por flood, aguarde alguns segundos!");

        new tmp[128], tmp1[128], id;

        tmp = strtok(cmdtext, idx);
        tmp1 = strrest(cmdtext, idx);

        if(!strlen(tmp) || !strlen(tmp1))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /Relatorio [ID] [Motivo]");

        id = strval(tmp);

        LiberarRelatorio{playerid} = true;
    	SetTimerEx("UnlockingReport", 30*1000, false, "i", playerid);

        SendClientMessage(playerid, Branco, "| Relatório | Seu relatorio foi enviado com sucesso para a Adminstração!");
    	format(String, sizeof(String), "| Relatório | Relatório de %s[%d] acusando: %s[%d] de %s", PlayerInfo[playerid][Nome], playerid, PlayerInfo[id][Nome], id, tmp1);
    	Report(0x80FFFFAA, String);
    	return 1;
	}
    if(strcmp(cmd, "/duvida", true) == 0)
    {
    	if(LiberarDuvida{playerid} == true)
            return SendClientMessage(playerid, Erro, "| ERRO | Duvida bloqueada por flood, aguarde alguns segundos!");

        new tmp[128];

        tmp = strrest(cmdtext, idx);

        if(!strlen(tmp))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /Duvida [duvida]");

    	LiberarDuvida{playerid} = true;
    	SetTimerEx("UnlockingDoubt", 30*1000, false, "i", playerid);

        SendClientMessage(playerid, Branco, "| Duvida | Sua duvida foi enviada a Administraçáo, aguarde à resposta!");
    	format(String, sizeof(String), "| Duvida | Duvida de %s[%d]: %s", PlayerInfo[playerid][Nome], playerid, tmp);
    	Doubt(0x80FFFFAA, String);
    	return 1;
	}
    if(strcmp(cmdtext,"/creditos", true)== 0)
	{
        new textos[1500];
        strcat(textos, "{FF0000} GameMode: {FFFFFF}Vida Brasileira - B.C.M RPG v1.0.0 \n\n");
        strcat(textos, "{FFFFFF} Desenvolvido e Atualizado por: {088fd2}Henrique Calenzo \n\n");
        strcat(textos, "{1b6302} Agradecimentos Especiais; \n\n");
        strcat(textos, "{f29b0d} pBlueG - {FFFFFF}pelo Mysql \n");
        strcat(textos, "{f29b0d} JaimeOliveira_. - {FFFFFF}pelos testes & Ideias \n");
        strcat(textos, "{f29b0d} PARANOICO - {FFFFFF}pelos testes \n");
        strcat(textos, "{f29b0d} RamoS. - {FFFFFF}pelos testes \n");
        strcat(textos, "{f29b0d} OszmYago - {FFFFFF}pelos testes \n\n");
        strcat(textos, "{218721} Www.VidaBrasileira.forumeiros.com \n\n");
        strcat(textos, "{FFFFFF} © Copyright 2019 - 2019 Vida Brasileira ");
        ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{00CED1}Créditos{FFFFFF}",textos, "Fechar", "");
        return 1;
	}
    if(strcmp(cmd, "/regras", true)==0)
	{
        new textogrande[3000];
		strcat(textogrande, "{FFFFFF}»{FF0000} Vaga de Adm {FFFFFF}- Nunca fique pedindo se tem vagas para Ajudante/Moderador/Administrador, todos jogadores sempre sáo avaliados\naquele que joga direito e ajuda os demais jogadores sempre tem uma grande chance quando abrimos Vagas\n\n");
		strcat(textogrande, "{FFFFFF}»{FF0000} Drive By DB {FFFFFF}- Nunca mate um jogador de dentro de um veiculo, é proibido e receberá puniçóes\n\n");
		strcat(textogrande, "{FFFFFF}»{FF0000} Death Match / DM{FFFFFF}- Não faça DM em locais Públicos ( Ex: Prefeituras, Bancos, agência, etc..) pois receberá punições,\n usem a favela, la vocês ganham armas e o DM é liberado\n\n");
		strcat(textogrande, "{FFFFFF}»{FF0000} Ofensas, Provocacoes e Perturbacoes - {FFFFFF}Perturbaçáo excessiva(floods, discussoes, etc... ) ou palavreado de origem\nofensiva no chat Público, seja por religiao ou preconceito, bem como assuntos náo relacionados ao jogo, como\nprovocacoes e criticas a jogadores ou a administradores, sera entendido como perturbaçáo e receberá punicoes\n\n");
		strcat(textogrande, "{FFFFFF}»{FF0000} Divugaçáo {FFFFFF}- É proibido Mensagens que contenham assuntos ou propagandas relacionados a outros servidores\nbem como divugacoes que ip ou de cheats\n\n");
		strcat(textogrande, "{FFFFFF}»{FF0000} Anti-AFK{FFFFFF}- Nunca tente sabotar o AFK é proibido e se algum ADM pegar sabotando será banido sem aviso\n\n");
		strcat(textogrande, "{FFFFFF}»{FF0000} Cheater{FFFFFF}- Qualquer programa ou 'mods' que possa lhe dar vantagem em jogo ou perante outros jogadores\nserá considerado como uso de cheater e será banido sem aviso\n\n");
		strcat(textogrande, "{FFFFFF}»{FF0000} Beneficios{FFFFFF}-  Nunca fique pedidndo pra algum ADM dar ( level dinheiro etc... ) vocé deve jogar para conseguir\n\n");
		strcat(textogrande, "{FFFFFF}»{FF0000} Anti-RPG{FFFFFF}- Nunca se atire na frente de veiculos, náo saia do servidor ( algemado, perseguiçóes, etc... ) caso contrario\n receberá puniçóes e até banimento\n\n");
		strcat(textogrande, "{FFFFFF}»{FF0000} Abuso de Bugs{FFFFFF}- Nunca abuse de bugs, sempre reporte-os para administraçáo caso contrario banido sem aviso previo\n\n");
		strcat(textogrande, "{0AB752}» VIPs seráo julgados da mesma forma que os demais jogadores\n\n");
        ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Regras", textogrande, "Fechar", "");
		return 1;
	}
    if(strcmp(cmd, "/vantagensvip", true)==0)
	{
        new textos[1000];
		strcat(textos, "{FFFF00}»{FFFFFF} Sistema auto tuning \n");
		strcat(textos, "{FFFF00}»{FFFFFF} Nitro infinito \n");
		strcat(textos, "{FFFF00}»{FFFFFF} Nick com prefixo [VIP] no chat \n");
		strcat(textos, "{FFFF00}»{FFFFFF} Mudar a cor da Tag [VIP] \n");
		strcat(textos, "{FFFF00}»{FFFFFF} Reparo de veículo \n");
		strcat(textos, "{FFFF00}»{FFFFFF} Virar veículo caso capote-o \n");
		strcat(textos, "{FFFF00}»{FFFFFF} Pintar veículo \n");
		strcat(textos, "{FFFF00}»{FFFFFF} Tunar Veículo \n");
		strcat(textos, "{FFFF00}»{FFFFFF} Colete \n");
		strcat(textos, "{FFFF00}»{FFFFFF} Jetpack \n");
		strcat(textos, "{FFFF00}»{FFFFFF} Tag VIP acima da skin \n");
		strcat(textos, "{FFFF00}»{FFFFFF} Chat exclusivo VIP \n");
		ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FFFFFF}Vantagens VIP", textos, "Fechar", "");
		return 1;
	}
    if(strcmp(cmd, "/comandosvip", true)==0)
	{
        new textos[1000];
		strcat(textos, "{FFFFFF}» {FFFF00}/Jetpack {FFFFFF}- Para pegar uma mochila a jato \n");
		strcat(textos, "{FFFFFF}» {FFFF00}/Colete {FFFFFF}- Para pegar um colete \n");
		strcat(textos, "{FFFFFF}» {FFFF00}/Virar {FFFFFF}- Para virar seu veículo \n");
		strcat(textos, "{FFFFFF}» {FFFF00}/Pintar {FFFFFF}- Para pintar o seu veículo \n");
		strcat(textos, "{FFFFFF}» {FFFF00}/Tunar {FFFFFF}- Para tunar o seu veículo \n");
		strcat(textos, "{FFFFFF}» {FFFF00}/Paintjob {FFFFFF}- Para personalizar a pintura do seu veículo \n");
		strcat(textos, "{FFFFFF}» {FFFF00}/Tag {FFFFFF}- Para mudar a cor da TAG [VIP] \n");
		strcat(textos, "{FFFFFF}» {FFFF00}/V {FFFFFF}- Chat exclusivo VIP \n");
        strcat(textos, "{FFFFFF}» {FFFF00}/VOn {FFFFFF}- Ligue o chat VIP \n");
        strcat(textos, "{FFFFFF}» {FFFF00}/VOff {FFFFFF}- Desligue o chat VIP \n");
        strcat(textos, "{FFFFFF}» {FFFF00}/Vencimento {FFFFFF}- Para ver o dia do vencimento do seu vip \n");
		ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FFFFFF}Comandos VIP", textos, "Fechar", "");
		return 1;
	}
    if(strcmp(cmd, "/animes", true)==0)
    {
        new textos[1000];
        strcat(textos, "{FFFFFF}/dance 1-4 ~ /maosacima ~ /bebado ~ /bomba ~ /mirar ~ /merda ~ /pormascara \n");
        strcat(textos, "/roubar ~ /cruzar ~ /deitar ~ /abaixar ~ /vomitar ~ /comer ~ /chamar ~ /passaramao \n");
        strcat(textos, "/cobrar ~ /overdose ~ /fumar ~ /sentar ~ /conversar ~ /fodase ~ /luta ~ /observar  \n");
        strcat(textos, "/mijar ~ /parar \n");
        ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Animes", textos, "Fechar", "");
        return 1;
    }
    if(strcmp(cmd, "/dance", true)==0)
    {
        new tmp[128], id;

    	tmp = strtok(cmdtext, idx);

    	if(!strlen(tmp))
    	return SendClientMessage(playerid, 0xFF0000FF,"| ERRO | Use: /dance [1-4]");

        id = strval(tmp);

    	if(id < 1 || id > 4)
    	return SendClientMessage(playerid, 0xFF0000FF,">Digite /dance [1-4]");

    	if(id == 1)
        {
    	   SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DANCE1);
    	}
        else if(id == 2)
        {
    	   SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DANCE2);
    	}
        else if(id == 3)
        {
    	   SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DANCE3);
    	}
        else if(id == 4)
        {
    	   SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DANCE4);
    	}
    	return 1;
	}
	if(strcmp(cmd, "/maoscima", true)==0){
    SetPlayerSpecialAction(playerid, 10);
	return 1;
	}
	if(strcmp(cmd, "/bebado", true)==0){
	ApplyAnimation(playerid, "PED", "WALK_DRUNK", 4.0, 1, 1, 1, 1, 0);
	return 1;
	}
	if(strcmp(cmd, "/bomba", true)==0){
	ClearAnimations(playerid);
	ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/mirar", true)==0){
	ApplyAnimation(playerid, "ped", "ARRESTgun", 4.0, 0, 1, 1, 1, -1);
	return 1;
	}
	if(strcmp(cmd, "/merda", true)==0){
	ApplyAnimation(playerid, "RAPPING", "Laugh_01", 4.0, 0, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/pormascara", true)==0){
	ApplyAnimation(playerid, "SHOP", "ROB_Shifty", 4.0, 0, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/roubar", true)==0){
	ApplyAnimation(playerid, "SHOP", "ROB_Loop_Threat", 4.0, 1, 0, 0, 0, 0);
	return 1;
	}
    if(strcmp(cmd, "/cruzar", true)==0){
	ApplyAnimation(playerid, "COP_AMBIENT", "Coplook_loop", 4.0, 0, 1, 1, 1, -1);
	return 1;
	}
	if(strcmp(cmd, "/deitar", true)==0){
	ApplyAnimation(playerid, "BEACH", "bather", 4.0, 1, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/abaixar", true)==0){
	ApplyAnimation(playerid, "ped", "cower", 3.0, 1, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/vomitar", true)==0){
	ApplyAnimation(playerid, "FOOD", "EAT_Vomit_P", 3.0, 0, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/comer", true)==0){
	ApplyAnimation(playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/chamar", true)==0){
	ApplyAnimation(playerid, "ON_LOOKERS", "wave_loop", 4.0, 1, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/passaramao",  true)==0){
	ApplyAnimation(playerid, "SWEET", "sweet_ass_slap", 4.0, 0, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/cobrar", true)==0){
	ApplyAnimation(playerid, "DEALER", "DEALER_DEAL", 4.0, 0, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/overdose", true)==0){
	ApplyAnimation(playerid, "CRACK", "crckdeth2", 4.0, 1, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/fumar", true)==0){
	ApplyAnimation(playerid, "SMOKING", "M_smklean_loop", 4.0, 1, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/sentar", true)==0){
	ApplyAnimation(playerid, "BEACH", "ParkSit_M_loop", 4.0, 1, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/conversar", true)==0){
	ApplyAnimation(playerid, "PED", "IDLE_CHAT", 4.0, 0, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/fodase", true)==0){
	ApplyAnimation(playerid, "PED", "fucku", 4.0, 0, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/luta", true) == 0){
	ApplyAnimation(playerid, "PARK", "Tai_Chi_Loop", 4.0, 1, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/observar", true)==0){
	ApplyAnimation(playerid, "BAR", "dnk_stndF_loop", 4.0, 1, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/mijar", true)==0){
	SetPlayerSpecialAction(playerid, 68);
	return 1;
	}
    if(strcmp(cmd, "/parar", true)==0){
    ClearAnimations(playerid);
    return 1;
    }
    if(strcmp(cmd, "/toplevel", true)==0)
    {
        new playerScores[MAX_PLAYERS][rankingEnum], index, string[1000];

        for(new i; i != MAX_PLAYERS; ++i)
    	{
      		if(IsPlayerConnected(i) && !IsPlayerNPC(i))
      		{
    			playerScores[index][player_Score] = PlayerInfo[i][Level];
    			playerScores[index++][player_ID] = i;
    		}
    	}

    	GetPlayerHighestScores(playerScores, 0, index);
    	new score_Text[1000] = "\n", player_Name[MAX_PLAYER_NAME];

        for(new i; i != 10; ++i)
        {
            if(i < index)
            {
                GetPlayerName(playerScores[i][player_ID], player_Name, sizeof(player_Name));
                format(score_Text, sizeof(score_Text), "{1b6302}%dº\t {FFFFFF}%s\t {F87A02}%d\n", i+1, player_Name, playerScores[i][player_Score]);
                strcat(string, score_Text, sizeof(string));
            } else {
                format(score_Text, sizeof(score_Text), "{1b6302}%dº\t {FFFFFF}N/A\t {F87A02}0\n", i + 1);
                strcat(string, score_Text, sizeof(string));
            }
       	}
        format(score_Text, sizeof(score_Text), "{FFFFFF}Top\t Nome\t Level\n%s", string);
        ShowPlayerDialog(playerid, 0, DIALOG_STYLE_TABLIST_HEADERS, "Top {00FF00}Level", score_Text, "Fechar", "");
        return 1;
    }
    if(strcmp(cmd, "/admins", true)==0)
    {
        new Counts, STR[1400], STX[50], adminon;
    	new const Ranks[][] =
    	{
        	"{FFFFFF}[ {FFFF00}Ajudante{FFFFFF} ]",
        	"{FFFFFF}[ {FF8C00}Moderador(a){FFFFFF} ]",
        	"{FFFFFF}[ {008bce}Admininstrador(a){FFFFFF} ]",
        	"{FFFFFF}[ {FF0000}Cordenador(a){FFFFFF} ]",
        	"{FFFFFF}[ {328E0A}Desenvolvedor(a){FFFFFF} ]"
    	};

    	for(new x = 0; x <= MAX_PLAYERS; x++)
     	{
        	if(!IsPlayerConnected(x)) continue;
        	if(PlayerInfo[x][Admin])
        	{
            	if(PlayerInfo[x][Admin] >= 1 && PlayerInfo[x][Admin] <= 5)
            	{
                	format(STR, 1400, "%s{FFFFFF} %s {FFFFFF}[%d] %s \n", STR, PlayerInfo[x][Nome], x, Ranks[PlayerInfo[x][Admin] - 1]);
                    adminon++;
            	}
            	Counts++;
         	}
    	}

    	if(adminon == 0)
    	{
            ShowPlayerDialog(playerid, 5000, DIALOG_STYLE_MSGBOX, "{FFFFFF}Admins Online [ {FF0000}0{FFFFFF} ]", "{FF0000}Náo há administrador ( ADM ) online no momento!", "Fechar", "");
    	} else {
        	format(STX, 200, "{FFFFFF}Admins Online [ {328E0A}%d{FFFFFF} ]", adminon);
        	ShowPlayerDialog(playerid, 500, DIALOG_STYLE_LIST, STX, STR, "Fechar", "");
    	}
     	return 1;
    }
    if(!strcmp(cmd, "/presos", true))
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 248.9497, 67.6059, 1003.6406)  || IsPlayerInRangeOfPoint(playerid, 2.0, 252.1618, 67.7849, 1003.6478))
        {
            new _str[1400], _stx[50], presoson;

            for(new x = 0; x < MAX_PLAYERS; x++)
         	{
            	if(PrisonEnum[x][pTempo] != 0 && PlayerInfo[x][Logado] == true)
            	{
                    formatSeconds(PrisonEnum[x][pTempo], Hora, Min, Seg);
                    format(_str, 1400, "%s{FFFFFF} %s{FFFFFF}[%d] \t%02d:%02d:%02d \t{C50000}%s \n", _str, PlayerInfo[x][Nome], x, Hora, Min, Seg, PrisonEnum[x][pCadeia]);
                    presoson++;
             	}
        	}

        	if(presoson == 0)
        	{
                ShowPlayerDialog(playerid, 5000, DIALOG_STYLE_MSGBOX, "{FFFFFF}Presos Online [ {FF0000}0{FFFFFF} ]", "{FF0000}Náo há presos online no momento!", "Fechar", "");
        	}
            else
            {
            	format(_stx, 200, "{FFFFFF}Presos Online [ {328E0A}%d{FFFFFF} ]", presoson);
            	ShowPlayerDialog(playerid, 500, DIALOG_STYLE_LIST, _stx, _str, "Fechar", "");
        	}
        }
        else
        {
            SendClientMessage(playerid, Erro, "| ERRO | Você não está em nenhum departamento de polícia!");
        }
     	return 1;
    }
