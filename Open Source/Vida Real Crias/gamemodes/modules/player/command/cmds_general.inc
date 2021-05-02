#include YSI\y_hooks

public OnPlayerCommandReceived(playerid, cmd[], params[], flags)
{
    if(!PlayerInfo[playerid][Logado]){
        SendClientMessage(playerid, Erro, "Voc� n�o est� logado");
        return 0;
    }

    if(strcmp(cmd, "sairafk"))
    {
        if(AntiAfk[playerid][aa_afk]){
            SendClientMessage(playerid, Erro, "Antes de usar comando, digite: /Sairafk");
            return 0;
        }
        if(Handcuffed[playerid] != INVALID_PLAYER_ID){
            SendClientMessage(playerid, Erro, "Voc� est� algemado e n�o pode usar comando");
            return 0;
        }
        if(PrisonEnum[playerid][pTempo] && !IsPlayerIntern(playerid))
        {
            if(!strcmp(PrisonEnum[playerid][pCadeia], "Municipal"))
            {
                if(!strcmp(cmd, "aceitar") || !strcmp(cmd, "recusar") || !strcmp(cmd, "advogados") || !strcmp(cmd, "advogado")) return 1;
            }
            SendClientMessage(playerid, Erro, "Voc� est� preso e n�o pode usar comando");
            return 0;
        }
        if(IsArena[playerid] && strcmp(cmd, "sairarena")){
            SendClientMessage(playerid, Erro, "Voc� est� na arena e n�o pode usar comando");
            return 0;
        }
        if(PlayerInfo[playerid][tutorial]){
            SendClientMessage(playerid, Erro, "Voc� est� no tutorial e n�o pode usar comando");
            return 0;
        }
        if(PlayerInfo[playerid][load]){
            SendClientMessage(playerid, Erro, "Seus dados est�o sendo carregado, aguarde alguns segundos...");
            return 0;
        }
        if(Light_Repairing[playerid]){
            SendClientMessage(playerid, Erro, "Voc� est� efetuando um reparo e n�o pode usar comandos");
            return 0;
        }
        if(PlayerRepairVehicle[playerid]){
            SendClientMessage(playerid, Erro, "Voc� est� efetuando um conserto e n�o pode usar comandos");
            return 0;
        }
        if(PlayerInfo[playerid][pds_in] && strcmp(cmd, "cancelarprova")){
            SendClientMessage(playerid, Erro, "Voc� est� realizando prova na Auto Escola e n�o pode usar comandos");
            return 0;
        }
        if(producerState[playerid]){
            SendClientMessage(playerid, Erro, "Voc� est� produzindo arma e n�o pode usar comandos");
            return 0;
        }
        if(MotoBoy[playerid][mb_getOrSet]){
            format(String, MAX_STRING, "Voc� est� %s o pedido e n�o pode usar comandos", ( MotoBoy[playerid][mb_business] ? ("pegando") : ("entregando")));
            SendClientMessage(playerid, Erro, String);
            return 0;
        }
        if(PlayerInfo[playerid][food]){
            SendClientMessage(playerid, Erro, "Voc� est� comendo/bebendo e n�o pode usar comandos");
            return 0;
        }
        if(PlayerInfo[playerid][frozen]){
            SendClientMessage(playerid, Erro, "Voc� est� congelado e n�o pode usar comandos");
            return 0;
        }
        if(hackingBank == playerid){
            SendClientMessage(playerid, Erro, "Voc� est� hackeando e n�o pode usar comandos");
            return 0;
        }
        if((PlayerInfo[playerid][hasDeath] || PlayerInfo[playerid][hasReborn]) && strcmp(cmd, "190") && strcmp(cmd, "192")){
            SendClientMessage(playerid, Erro, "Voc� est� morto/ferido e n�o pode usar comandos");
            return 0;
        }
        if(PlayerInfo[playerid][Profissao] == paramedic && PlayerInfo[playerid][doctorReborn] != INVALID_PLAYER_ID){
            SendClientMessage(playerid, Erro, "Voc� est� reanimando um(a) jogador(a) e n�o pode usar comandos");
            return 0;
        }
    }
    return 1;
}

public OnPlayerCommandPerformed(playerid, cmd[], params[], result, flags)
{
    if(result == -1)
    {
        SendClientMessage(playerid, Erro, "Comando Inv�lido");
        return 0;
    }

    PlayerInfo[playerid][typingCmd]++;
    if(PlayerInfo[playerid][typingCmd] >= 50)
    {
        PlayerInfo[playerid][typingCmd] = 0;

        AntiAfk[playerid][aa_warning]--;
        if(AntiAfk[playerid][aa_warning] < 0)
        {
            AntiAfk[playerid][aa_warning] = 0;
        }
    }

    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerHelper(i) && viewcmds[i] == true)
        {
            format(String, MAX_STRING, "VRC-Admin ~ %s[%d] digitou o comando: /%s", PlayerInfo[playerid][Nome], playerid, cmd);
            SendClientMessage(i, 0x0080FFAA, String);
            printf(String);
        }
    }
    return 1;
}

/******************************************************************************/
/*****************************| COMMANDS GERAIS |******************************/
/******************************************************************************/

CMD:reabastecer(playerid)
{
    if(!PlayerInfo[playerid][havegallon])
        return SendClientMessage(playerid, Erro, "Voc� n�o tem nenhum Gal�o de Combust�vel");

    if(!PlayerInfo[playerid][gallon])
        return SendClientMessage(playerid, Erro, "Seu Gal�o de Combust�vel est� vazio");

    new Float:x, Float:y, Float:z;

    for(new vehicleid = 0; vehicleid < MAX_VEHICLES; vehicleid++)
    {
        if(PublicVehicle[vehicleid][pv_vehicle] == INVALID_VEHICLE_ID)
            continue;

        GetVehiclePos(PublicVehicle[vehicleid][pv_vehicle], x , y, z);

        if(!IsPlayerInRangeOfPoint(playerid, 5.0, x, y, z))
            continue;

        if(IsPlayerInAnyVehicle(playerid))
            return SendClientMessage(playerid, Erro, "Para reabastecer precisa sair do ve�culo");

        if(PublicVehicle[vehicleid][pv_gasoline])
            return SendClientMessage(playerid, Erro, "Esse ve�culo ainda tem gasolina");

        PlayerInfo[playerid][gallon] = 0;
        PublicVehicle[vehicleid][pv_gasoline] = 10;
        SendClientMessage(playerid, White, "O ve�culo foi reabastecido, mesmo assim v� at� o Posto de Gasolina mas pr�ximo");
        return 1;
    }

    SendClientMessage(playerid, Erro, "Voc� est� longe do ve�culo, chegue mais perto");
    return 1;
}
CMD:vendercelular(playerid)
{
    if(PlayerInfo[playerid][cellphone] == 0)
        return SendClientMessage(playerid, Erro, "Voc� n�o tem nenhum celular");

    PlayerInfo[playerid][cellphone] = 0;
    SetIntQuery(playerid, "Itens", "celular", PlayerInfo[playerid][cellphone]);

    SendClientMessage(playerid, Green, "Celular vendido com sucesso");
    return 1;
}
CMD:usarkit(playerid)
{
    if(PlayerInfo[playerid][medicalkit] == 0)
        return SendClientMessage(playerid, Erro, "Voc� n�o tem nenhum Kit M�dico");

    new Float:health;
    GetPlayerHealth(playerid, health);

    if(health > 50.0)
        return SendClientMessage(playerid, Erro, "Sua vida precisa estar abaixo de 50 porcento");

    PlayerInfo[playerid][medicalkit]--;
    PlayerInfo[playerid][Health] = 100.0;
    SetPlayerHealth(playerid, PlayerInfo[playerid][Health]);
    SetIntQuery(playerid, "Itens", "kitmedicos", PlayerInfo[playerid][medicalkit]);

    format(String, MAX_STRING, "KIT-M�DICO ~ Voc� utilizou um kit m�dico e a sua vida foi recuperada ( Kit m�dico disponiv�l: %d )", PlayerInfo[playerid][medicalkit]);
    SendClientMessage(playerid, Green, String);
    return 1;
}
CMD:comandoscasa(playerid)
{
    new txt[300];
    strcat(txt, "{FF0000}Comandos \t\t {1CEB00}Informa��es \n");
    strcat(txt, "{87CEFF}/EntrarCasa \t\t Para entrar na casa\n");
    strcat(txt, "{87CEFF}/SairCasa \t\t Para sair da casa\n");
    strcat(txt, "{87CEFF}/ComprarCasa \t\t Para comprar a casa\n");
    strcat(txt, "{87CEFF}/MenuCasa \t\t Para ver outros comandos da casa\n");
    ShowPlayerDialog(playerid, MAIN_HOUSE_COMMAND, DIALOG_STYLE_TABLIST_HEADERS, "{C0C0C0}Comandos Casa", txt, "Fechar", #);
    return 1;
}
CMD:reais(playerid)
{
    ShowPlayerDialog(playerid, main_reais, DIALOG_STYLE_LIST, "{FF0000}Reais", "{FFFFFF}Comprar VIP", "Continuar", "Cancelar");
    return 1;
}
CMD:partida(playerid)
{
    new vehicleid = GetPlayerVehicleID(playerid), mot, lu, alar, por, cap, porma, ob;

    if(!IsPlayerInAnyVehicle(playerid))
        return SendClientMessage(playerid, Erro, "Voc� n�o est� em um ve�culo");

    if(IsBike(vehicleid))
        return SendClientMessage(playerid, Erro, "Voc� est� em uma bicicleta");

    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
        return SendClientMessage(playerid, Erro, "Voc� n�o est� como motorista");

    if(IsBrokenVehicle(vehicleid))
        return SendClientMessage(playerid, Erro, "Este ve�culo est� quebrado, compre kit reparo ou chame um mec�nico");

    GetVehicleParamsEx(vehicleid,  mot, lu, alar, por, cap, porma, ob);

    if(!mot)
    {
        for(new i = 0; i < MAX_VEHICLES; i++)
        {
            if(vehicleid != PublicVehicle[i][pv_vehicle]) continue;

            if(!PublicVehicle[i][pv_gasoline])
                return SendClientMessage(playerid, Erro, "Este ve�culo n�o tem Gasolina");

            break;
        }

        SetVehicleParamsEx(vehicleid, 1, 1, alar, por, cap, porma, ob);
        SendClientMessage(playerid, Green, "Veiculo ligado");

        if(Fueling[playerid]){
            Fueling[playerid] = false;
            SendClientMessage(playerid, Yellow, "O abastecimento foi cancelado");
        }
        return 1;
    }

    SendClientMessage(playerid, Green, "Veiculo desligado");
    SetVehicleParamsEx(vehicleid, 0, 0, alar, por, cap, porma, ob);
    return 1;
}
CMD:radios(playerid)
{
    new txt[150];
    strcat(txt, "{FFFFFF}Eletr�nicas\n");
    strcat(txt, "{FFFFFF}N/A\n");
    strcat(txt, "{FFFFFF}N/A\n");
    strcat(txt, "{FFFFFF}N/A\n");
    strcat(txt, "{FF0000}Desligar Radios");
    ShowPlayerDialog(playerid, radio, DIALOG_STYLE_LIST, "{FF0000}MP3", txt, "Continuar", "Fechar");
    return 1;
}
CMD:mudarnome(playerid)
{
    if(PlayerInfo[playerid][Reais] < 7)
        return SendClientMessage(playerid, Erro, "Voc� n�o tem Reais o suficiente para mudar o nome");

    ShowPlayerDialog(playerid, rename, DIALOG_STYLE_INPUT, "{FF0000}Mudar nome", "{FFFFFF}Digite seu novo nick e clique em {FF0000}Mudar\n{FFFFFF}Por favor n�o coloque {FF0000}ESPA�O {FFFFFF}em seu nome:", "Mudar", "Sair");
    return 1;
}
CMD:minhashoras(playerid)
{
    new txt[128];
    format(String, 200, "{FFFFFF} Nick: {FF0000}%s \n\n", PlayerInfo[playerid][Nome]);
    strcat(txt, String);
    format(String, 200, "{FFFFFF} Horas: {1B6302}%d \n\n", PlayerInfo[playerid][Level]);
    strcat(txt, String);
    format(String, 200, "{FFFFFF} Experi�ncia: {F29B0D}%d \n\n", PlayerInfo[playerid][Exp]);
    strcat(txt, String);
    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{00FF00}Minhas Horas", txt, "Fechar", "");
    return 1;
}
CMD:ajuda(playerid)
{
    new txt[200];
    strcat(txt, "{FFFFFF}Level \n");
    strcat(txt, "{FFFFFF}Sal�rio \n");
    strcat(txt, "{FFFFFF}Comandos \n");
    strcat(txt, "{FFFFFF}Contatos \n");
    strcat(txt, "{FFFFFF}Casa \n");
    strcat(txt, "{FFFFFF}Empresa \n");
    strcat(txt, "{FFFFFF}Base \n");
    strcat(txt, "{FFFFFF}Ve�culo \n");
    strcat(txt, "{FFFFFF}Mercadoria \n");
    ShowPlayerDialog(playerid, help, DIALOG_STYLE_LIST, "{FF0000}Ajuda", txt, "Continuar", "Cancelar");
    return 1;
}
CMD:identidade(playerid)
{
    if(IsPlayerMobile(playerid))
    {
        new txt[1000], days, hours, minutes, seconds;

        TimeConvertEx(( PlayerInfo[playerid][vaccine] - gettime() ), days, hours, minutes, seconds);

        format(String, 100, "{FFFFFF}� Level: {00C40A}%d \n", PlayerInfo[playerid][Level]);
        strcat(txt, String);
        format(String, 100, "{FFFFFF}� Experi�ncia: {00C40A}%d \n", PlayerInfo[playerid][Exp]);
        strcat(txt, String);
        format(String, 100, "{FFFFFF}� Reais: {00C40A}R$%d,00 \n", PlayerInfo[playerid][Reais]);
        strcat(txt, String);
        format(String, 100, "{FFFFFF}� Vacinas: %s%d \n", (IsPlayerVaccinated(playerid) ? ("{00C40A}") : ("{FF4000}")), (IsPlayerVaccinated(playerid) ? hours : 0));
        strcat(txt, String);
        format(String, 100, "{FFFFFF}� Doen�a: %s%s \n", (PlayerInfo[playerid][disease] ? ("{FF4000}") : ("{00C40A}")), DiseaseName(playerid));
        strcat(txt, String);
        format(String, 100, "{FFFFFF}� VIP: %s \n", (VipInfo[playerid][Vip] ? ("{00C40A}Sim") : ("{FF4000}N�o")));
        strcat(txt, String);
        format(String, 100, "{FFFFFF}� Plano de Sa�de: %s \n", (PlayerInfo[playerid][healthplan] ? ("{00C40A}Sim") : ("{FF4000}N�o")));
        strcat(txt, String);
        format(String, 100, "{FFFFFF}� Kit m�dicos: {00C40A}%d \n", PlayerInfo[playerid][medicalkit]);
        strcat(txt, String);
        format(String, 100, "{FFFFFF}� Saldo Sem Parar: {00C40A}$%s \n", IsMoney(PlayerInfo[playerid][nonstop], "."));
        strcat(txt, String);
        format(String, 100, "{FFFFFF}� Sexo: {00C40A}%s \n", (PlayerInfo[playerid][sexo] == SEX_BOY ? ("Masculino") : ("Feminino")));
        strcat(txt, String);
        format(String, 100, "{FFFFFF}� Skin ID: {00C40A}%d \n", PlayerInfo[playerid][skin]);
        strcat(txt, String);
        format(String, 100, "{FFFFFF}� Dinheiro: {00C40A}$%s \n", IsMoney(PlayerInfo[playerid][Dinheiro], "."));
        strcat(txt, String);
        format(String, 100, "{FFFFFF}� Dinamites: {00C40A}%d \n", GetIntQuery(playerid, "Itens", "c4"));
        strcat(txt, String);
        format(String, 100, "{FFFFFF}� Matou: {00C40A}%d {FFFFFF}- Morreu: {f84300}%d \n", PlayerInfo[playerid][Matou], PlayerInfo[playerid][Morreu]);
        strcat(txt, String);
        format(String, 100, "{FFFFFF}� Avisos: {f84300}%d \n", PlayerInfo[playerid][Avisos]);
        strcat(txt, String);
        format(String, 100, "{FFFFFF}� Categoria A: %s \n", (IsPlayerCnhType(playerid, "a") ? ("{00C40A}Sim") : ("{FF4000}N�o")));
        strcat(txt, String);
        format(String, 100, "{FFFFFF}� Categoria B: %s \n", (IsPlayerCnhType(playerid, "b") ? ("{00C40A}Sim") : ("{FF4000}N�o")));
        strcat(txt, String);
        format(String, 100, "{FFFFFF}� Categoria C: %s \n", (IsPlayerCnhType(playerid, "c") ? ("{00C40A}Sim") : ("{FF4000}N�o")));
        strcat(txt, String);
        format(String, 100, "{FFFFFF}� CHT: %s \n", (IsPlayerCnhType(playerid, "cht") ? ("{00C40A}Sim") : ("{FF4000}N�o")));
        strcat(txt, String);
        format(String, 100, "{FFFFFF}� Arrais: %s \n", (IsPlayerCnhType(playerid, "arrais") ? ("{00C40A}Sim") : ("{FF4000}N�o")));
        strcat(txt, String);
        format(String, 100, "{FFFFFF}� C�digo: {00C40A}%s \n", PlayerInfo[playerid][Code]);
        strcat(txt, String);
        format(String, 200, "{FFFFFF}� E-mail: {00C40A}%s \n", PlayerInfo[playerid][Email]);
        strcat(txt, String);

        format(String, 100, "{0080FF}Identidade de {FFFFFF}%s", PlayerInfo[playerid][Nome]);

        ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, String, txt, "Fechar", "");
        return 1;
    }
    else
    {
        if(Identity[playerid])
        {
            HideTDPlayerIdentity(playerid);
        }
        else
        {
            if(GetPlayerPing(playerid) > MAX_PING)
                return SendClientMessage(playerid, Erro, "Seu ping est� alto e voc� n�o pode usar textdraws ( Motivo: Evitar RT )");

            new days, hours, minutes, seconds;

            TimeConvertEx(( PlayerInfo[playerid][vaccine] - gettime() ), days, hours, minutes, seconds);

            PlayerTextDrawSetPreviewModel(playerid, TDPlayerIdentity[playerid][tdi_skin], PlayerInfo[playerid][skin]);

            format(String, 50, "~r~%s", PlayerInfo[playerid][Nome]);
            PlayerTextDrawSetString(playerid, TDPlayerIdentity[playerid][tdi_name], String);
            format(String, 50, "Skin (ID:%d)", PlayerInfo[playerid][skin]);
            PlayerTextDrawSetString(playerid, TDPlayerIdentity[playerid][tdi_skinid], String);
            format(String, 50, "Level: %d", PlayerInfo[playerid][Level]);
            PlayerTextDrawSetString(playerid, TDPlayerIdentity[playerid][tdi_level], String);
            format(String, 50, "Experiencia: %d", PlayerInfo[playerid][Exp]);
            PlayerTextDrawSetString(playerid, TDPlayerIdentity[playerid][tdi_exp], String);
            format(String, 50, "Reais: R$%d,00", PlayerInfo[playerid][Reais]);
            PlayerTextDrawSetString(playerid, TDPlayerIdentity[playerid][tdi_reais], String);
            format(String, 50, "Vacina(s): %s%d", (IsPlayerVaccinated(playerid) ? ("~g~") : ("~r~")), (IsPlayerVaccinated(playerid) ? hours : 0));
            PlayerTextDrawSetString(playerid, TDPlayerIdentity[playerid][tdi_vaccine], String);
            format(String, 50, "Doenca: %s%s", (PlayerInfo[playerid][disease] ? ("~r~") : ("~g~")), DiseaseName(playerid));
            PlayerTextDrawSetString(playerid, TDPlayerIdentity[playerid][tdi_disease], String);
            format(String, 50, "VIP: %s", (VipInfo[playerid][Vip] ? ("~g~Sim") : ("~r~N/A")));
            PlayerTextDrawSetString(playerid, TDPlayerIdentity[playerid][tdi_vip], String);
            format(String, 50, "Plano de Saude: %s", (PlayerInfo[playerid][healthplan] ? ("~g~Sim") : ("~r~N/A")));
            PlayerTextDrawSetString(playerid, TDPlayerIdentity[playerid][tdi_health], String);
            format(String, 50, "Kit medico(s): %d", PlayerInfo[playerid][medicalkit]);
            PlayerTextDrawSetString(playerid, TDPlayerIdentity[playerid][tdi_medic_kit], String);
            format(String, 50, "Saldo Sem Parar: %s", IsMoney(PlayerInfo[playerid][nonstop], "."));
            PlayerTextDrawSetString(playerid, TDPlayerIdentity[playerid][tdi_nonstop], String);
            format(String, 50, "Sexo: %s", (PlayerInfo[playerid][sexo] == SEX_BOY ? ("Masculino") : ("Feminino")));
            PlayerTextDrawSetString(playerid, TDPlayerIdentity[playerid][tdi_sex], String);
            format(String, 50, "Dinheiro: %s", IsMoney(PlayerInfo[playerid][Dinheiro], "."));
            PlayerTextDrawSetString(playerid, TDPlayerIdentity[playerid][tdi_money], String);
            format(String, 50, "Dinamites: %d", GetIntQuery(playerid, "Itens", "c4"));
            PlayerTextDrawSetString(playerid, TDPlayerIdentity[playerid][tdi_c4], String);
            format(String, 50, "Matou: %d - Morreu: %d", PlayerInfo[playerid][Matou], PlayerInfo[playerid][Morreu]);
            PlayerTextDrawSetString(playerid, TDPlayerIdentity[playerid][tdi_kd], String);
            format(String, 50, "Aviso(s): %d", PlayerInfo[playerid][Avisos]);
            PlayerTextDrawSetString(playerid, TDPlayerIdentity[playerid][tdi_warning], String);
            format(String, 50, "Categoria A: %s", (IsPlayerCnhType(playerid, "a") ? ("~g~Sim") : ("~r~N/A")));
            PlayerTextDrawSetString(playerid, TDPlayerIdentity[playerid][tdi_cnh_a], String);
            format(String, 50, "Categoria B: %s", (IsPlayerCnhType(playerid, "b") ? ("~g~Sim") : ("~r~N/A")));
            PlayerTextDrawSetString(playerid, TDPlayerIdentity[playerid][tdi_cnh_b], String);
            format(String, 50, "Categoria C: %s", (IsPlayerCnhType(playerid, "c") ? ("~g~Sim") : ("~r~N/A")));
            PlayerTextDrawSetString(playerid, TDPlayerIdentity[playerid][tdi_cnh_c], String);
            format(String, 50, "CHT: %s", (IsPlayerCnhType(playerid, "cht") ? ("~g~Sim") : ("~r~N/A")));
            PlayerTextDrawSetString(playerid, TDPlayerIdentity[playerid][tdi_cnh_cht], String);
            format(String, 50, "Arrais: %s", (IsPlayerCnhType(playerid, "arrais") ? ("~g~Sim") : ("~r~N/A")));
            PlayerTextDrawSetString(playerid, TDPlayerIdentity[playerid][tdi_cnh_arrais], String);
            format(String, 50, "E-mail: %s", PlayerInfo[playerid][Email]);
            PlayerTextDrawSetString(playerid, TDPlayerIdentity[playerid][tdi_email], String);

            ShowTDPlayerIdentity(playerid);
        }
    }
    return 1;
}
CMD:relatorio(playerid, params[])
{
    if(PlayerInfo[playerid][blockReport])
        return SendClientMessage(playerid, Erro, "Relat�rio bloqueado por flood, aguarde alguns segundos...");

    new id, tmp[128];

    if(sscanf(params, "us[128]", id, tmp))
        return SendClientMessage(playerid, Erro, "Digite: /Relatorio [id/nome] [relat�rio]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) n�o conectado(a)");

    PlayerInfo[playerid][blockReport] = true;
    SetTimerEx("UnlockingReport", 120000, false, "d", playerid);

    SendClientMessage(playerid, White, "Seu relatorio foi enviado com sucesso para a Adminstra��o");

    format(String, MAX_STRING, "Relat�rio de %s[%d] acusando: %s[%d] de %s", PlayerInfo[playerid][Nome], playerid, PlayerInfo[id][Nome], id, tmp);

    for(new i; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerIntern(i))
        {
            SendClientMessage(i, 0x80FFFFAA, String);
            GameTextForPlayer(i, "~n~~r~RELATORIO" , 3000, 3);
            PlayerPlaySound(i, 1057, 0, 0, 0);
        }
    }
    return 1;
}
CMD:duvida(playerid, params[])
{
    if(PlayerInfo[playerid][blockDoubt])
        return SendClientMessage(playerid, Erro, "Duvida bloqueada por flood, aguarde alguns segundos...");

    new tmp[128];

    if(sscanf(params, "s[128]", tmp))
        return SendClientMessage(playerid, Erro, "Digite: /Duvida [duvida]");

    PlayerInfo[playerid][blockDoubt] = true;
    SetTimerEx("UnlockingDoubt", 120000, false, "d", playerid);

    SendClientMessage(playerid, White, "Sua duvida foi enviada a Administra��o, aguarde � resposta");
    format(String, MAX_STRING, "Duvida de %s[%d]: %s", PlayerInfo[playerid][Nome], playerid, tmp);

    for(new i; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerIntern(i))
        {
            SendClientMessage(i, 0x80FFFFAA, String);
            GameTextForPlayer(i, "~n~~b~DUVIDA" , 3000, 3);
            PlayerPlaySound(i, 1057, 0, 0, 0);
        }
    }
    return 1;
}
CMD:anuncios(playerid, params[])
{
    if(PlayerInfo[playerid][blockAd])
        return SendClientMessage(playerid, Erro, "An�ncio bloqueado por flood, aguarde alguns segundos...");

    new txt[200];

    strcat(txt, "{FFFFFF}Casa\n");
    strcat(txt, "{FFFFFF}Empresa\n");
    strcat(txt, (IsPlayerYoutuber(playerid) ? ("{FFFFFF}Youtuber texto chat\n") : (#)));
    strcat(txt, (IsPlayerYoutuber(playerid) ? ("{FFFFFF}Youtuber texto tela\n") : (#)));

    ShowPlayerDialog(playerid, player_ads, DIALOG_STYLE_LIST, "{FF0000}VRC - An�ncios", txt, "Anunciar", "Cancelar");
    return 1;
}
CMD:creditos(playerid)
{
    new txt[1500];

    format(String, MAX_STRING, "{FF0000} GameMode: {FFFFFF}Vida Real Crias - VRC RPG v%s \n\n", SERVER_VERSION);
    strcat(txt, String);
    strcat(txt, "{FFFFFF} Desenvolvido e Atualizado por: {088fd2}Henrique Calenzo \n\n");
    strcat(txt, "{1b6302} Agradecimentos Especiais; \n\n");
    strcat(txt, "{f29b0d} pBlueG - {FFFFFF}MySQL \n");
    strcat(txt, "{f29b0d} Emmet_ - {FFFFFF}sscanf \n");
    strcat(txt, "{f29b0d} Incognito - {FFFFFF}streamer \n");
    strcat(txt, "{f29b0d} YourShadow - {FFFFFF}Pawn.CMD \n");
    strcat(txt, "{f29b0d} rootcause - {FFFFFF}Ideia de sistemas ( Casas, Empresas e Gari ) \n\n");
    format(String, MAX_STRING, "{218721} %s \n\n", SERVER_FORUM);
    strcat(txt, String);
    strcat(txt, "{FFFFFF} � Copyright 2020 - 2020 Vida Real Crias");
    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{00CED1}Cr�ditos{FFFFFF}",txt, "Fechar", "");
    return 1;
}
CMD:regras(playerid)
{
    new textogrande[3000];
	strcat(textogrande, "{FFFFFF}�{FF0000} Vaga de Adm {FFFFFF}- Nunca fique pedindo se tem vagas para Ajudante/Moderador/Administrador, todos jogadores sempre s�o avaliados\naquele que joga direito e ajuda os demais jogadores sempre tem uma grande chance quando abrimos Vagas\n\n");
	strcat(textogrande, "{FFFFFF}�{FF0000} Drive By DB {FFFFFF}- Nunca mate um jogador de dentro de um veiculo, � proibido e receber� puni��es\n\n");
	strcat(textogrande, "{FFFFFF}�{FF0000} Death Match / DM{FFFFFF}- Proibido Death Match, soco, chutes, tiros em ve�culos(em uso) ou em jogadores\n\n");
	strcat(textogrande, "{FFFFFF}�{FF0000} Ofensas, Provocacoes e Perturbacoes - {FFFFFF}Perturba��o excessiva(floods, discussoes, etc... ) ou palavreado de origem\nofensiva no chat P�blico, seja por religiao ou preconceito, bem como assuntos n�o relacionados ao jogo, como\nprovocacoes e criticas a jogadores ou a administradores, sera entendido como perturba��o e receber� punicoes\n\n");
	strcat(textogrande, "{FFFFFF}�{FF0000} Divuga��o {FFFFFF}- � proibido Mensagens que contenham assuntos ou propagandas relacionados a outros servidores\nbem como divugacoes que ip ou de cheats\n\n");
	strcat(textogrande, "{FFFFFF}�{FF0000} Anti-AFK{FFFFFF}- Nunca tente sabotar o AFK � proibido e se algum ADM pegar sabotando ser� banido sem aviso\n\n");
	strcat(textogrande, "{FFFFFF}�{FF0000} Cheater{FFFFFF}- Qualquer programa ou 'mods' que possa lhe dar vantagem em jogo ou perante outros jogadores\nser� considerado como uso de cheater e ser� banido sem aviso\n\n");
	strcat(textogrande, "{FFFFFF}�{FF0000} Beneficios{FFFFFF}-  Nunca fique pedidndo pra algum ADM dar ( level dinheiro etc... ) voc� deve jogar para conseguir\n\n");
	strcat(textogrande, "{FFFFFF}�{FF0000} Anti-RPG{FFFFFF}- Nunca se atire na frente de veiculos, n�o saia do servidor ( algemado, persegui��es, etc... ) caso contrario\n receber� puni��es e at� banimento\n\n");
	strcat(textogrande, "{FFFFFF}�{FF0000} Abuso de Bugs{FFFFFF}- Nunca abuse de bugs, sempre reporte-os para administra��o caso contrario banido sem aviso previo\n\n");
	strcat(textogrande, "{0AB752}� VIPs ser�o julgados da mesma forma que os demais jogadores\n\n");
    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Regras", textogrande, "Fechar", "");
	return 1;
}
CMD:vantagensvip(playerid)
{
    new txt[1000];
	strcat(txt, "{FFFF00}�{FFFFFF} Sistema auto tuning \n");
    strcat(txt, "{FFFF00}�{FFFFFF} Neon personalizado \n");
	strcat(txt, "{FFFF00}�{FFFFFF} Nitro infinito \n");
	strcat(txt, "{FFFF00}�{FFFFFF} Nick com prefixo [VIP] no chat \n");
	strcat(txt, "{FFFF00}�{FFFFFF} Mudar a cor da Tag [VIP] \n");
	strcat(txt, "{FFFF00}�{FFFFFF} Reparo de ve�culo \n");
	strcat(txt, "{FFFF00}�{FFFFFF} Virar ve�culo caso capote-o \n");
	strcat(txt, "{FFFF00}�{FFFFFF} Pintar ve�culo \n");
	strcat(txt, "{FFFF00}�{FFFFFF} Tunar ve�culo \n");
	strcat(txt, "{FFFF00}�{FFFFFF} Colete \n");
	strcat(txt, "{FFFF00}�{FFFFFF} Jetpack \n");
	strcat(txt, "{FFFF00}�{FFFFFF} Tag VIP acima da skin \n");
    strcat(txt, "{FFFF00}�{FFFFFF} Chat exclusivo VIP \n");
    strcat(txt, "{FFFF00}�{FFFFFF} Kit arena gr�tis\n");
    strcat(txt, "{FFFF00}�{FFFFFF} Sal�rio VIP \n");
    strcat(txt, "{FFFF00}�{FFFFFF} M�ximo 10 Ve�culos no ( menuveiculos )\n");
    strcat(txt, "{FFFF00}�{FFFFFF} M�ximo 10 Armas na ( mochila )\n");
	ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FFFFFF}Vantagens VIP", txt, "Fechar", "");
	return 1;
}
CMD:comandosvip(playerid)
{
    new txt[1000];
    strcat(txt, "{FFFFFF}� {FFFF00}/Neon {FFFFFF}- Adicione luzes personalizada em seu ve�culo \n");
    strcat(txt, "{FFFFFF}� {FFFF00}/Jetpack {FFFFFF}- Para pegar uma mochila a jato \n");
	strcat(txt, "{FFFFFF}� {FFFF00}/Colete {FFFFFF}- Para pegar um colete \n");
	strcat(txt, "{FFFFFF}� {FFFF00}/Virar {FFFFFF}- Para virar seu ve�culo \n");
	strcat(txt, "{FFFFFF}� {FFFF00}/Pintar {FFFFFF}- Para pintar o seu ve�culo \n");
	strcat(txt, "{FFFFFF}� {FFFF00}/Tunar {FFFFFF}- Para tunar o seu ve�culo \n");
	strcat(txt, "{FFFFFF}� {FFFF00}/Paintjob {FFFFFF}- Para personalizar a pintura do seu ve�culo \n");
	strcat(txt, "{FFFFFF}� {FFFF00}/Tag {FFFFFF}- Para mudar a cor da TAG [VIP] \n");
	strcat(txt, "{FFFFFF}� {FFFF00}/V {FFFFFF}- Chat exclusivo VIP \n");
    strcat(txt, "{FFFFFF}� {FFFF00}/VOn {FFFFFF}- Ligue o chat VIP \n");
    strcat(txt, "{FFFFFF}� {FFFF00}/VOff {FFFFFF}- Desligue o chat VIP \n");
    strcat(txt, "{FFFFFF}� {FFFF00}/Vencimento {FFFFFF}- Para ver o dia do vencimento do seu vip \n");
	ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FFFFFF}Comandos VIP", txt, "Fechar", "");
	return 1;
}
CMD:animes(playerid)
{
    new txt[1000];
    strcat(txt, "{FFFFFF}/dance 1-4 ~ /maosacima ~ /bebado ~ /bomba ~ /mirar ~ /merda ~ /pormascara \n");
    strcat(txt, "/roubar ~ /cruzar ~ /deitar ~ /abaixar ~ /vomitar ~ /comer ~ /chamar ~ /passaramao \n");
    strcat(txt, "/cobrar ~ /overdose ~ /fumar ~ /sentar ~ /conversar ~ /fodase ~ /luta ~ /observar  \n");
    strcat(txt, "/mijar ~ /parar \n");
    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Animes", txt, "Fechar", "");
    return 1;
}
CMD:dance(playerid, params[])
{
    new id;

    if(sscanf(params, "d", id))
    	return SendClientMessage(playerid, 0xFF0000FF,"Use: /dance [1-4]");

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
CMD:maoscima(playerid)
{
    SetPlayerSpecialAction(playerid, 10);
	return 1;
}
CMD:bebado(playerid)
{
	ApplyAnimation(playerid, "PED", "WALK_DRUNK", 4.0, 1, 1, 1, 1, 0);
	return 1;
}
CMD:bomba(playerid)
{
	ClearAnimations(playerid);
	ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0);
	return 1;
}
CMD:mirar(playerid)
{
	ApplyAnimation(playerid, "ped", "ARRESTgun", 4.0, 0, 1, 1, 1, -1);
	return 1;
}
CMD:merda(playerid)
{
	ApplyAnimation(playerid, "RAPPING", "Laugh_01", 4.0, 0, 0, 0, 0, 0);
	return 1;
}
CMD:pormascara(playerid)
{
	ApplyAnimation(playerid, "SHOP", "ROB_Shifty", 4.0, 0, 0, 0, 0, 0);
    return 1;
}
CMD:roubar(playerid)
{
	ApplyAnimation(playerid, "SHOP", "ROB_Loop_Threat", 4.0, 1, 0, 0, 0, 0);
	return 1;
}
CMD:cruzar(playerid)
{
	ApplyAnimation(playerid, "COP_AMBIENT", "Coplook_loop", 4.0, 0, 1, 1, 1, -1);
	return 1;
}
CMD:deitar(playerid)
{
	ApplyAnimation(playerid, "BEACH", "bather", 4.0, 1, 0, 0, 0, 0);
	return 1;
}
CMD:abaixar(playerid)
{
	ApplyAnimation(playerid, "ped", "cower", 3.0, 1, 0, 0, 0, 0);
	return 1;
}
CMD:vomitar(playerid)
{
	ApplyAnimation(playerid, "FOOD", "EAT_Vomit_P", 3.0, 0, 0, 0, 0, 0);
	return 1;
}
CMD:comer(playerid)
{
	ApplyAnimation(playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0);
	return 1;
}
CMD:chamar(playerid)
{
	ApplyAnimation(playerid, "ON_LOOKERS", "wave_loop", 4.0, 1, 0, 0, 0, 0);
	return 1;
}
CMD:passaramao(playerid)
{
	ApplyAnimation(playerid, "SWEET", "sweet_ass_slap", 4.0, 0, 0, 0, 0, 0);
	return 1;
}
CMD:cobrar(playerid)
{
	ApplyAnimation(playerid, "DEALER", "DEALER_DEAL", 4.0, 0, 0, 0, 0, 0);
	return 1;
}
CMD:overdose(playerid)
{
	ApplyAnimation(playerid, "CRACK", "crckdeth2", 4.0, 1, 0, 0, 0, 0);
	return 1;
}
CMD:fumar(playerid)
{
	ApplyAnimation(playerid, "SMOKING", "M_smklean_loop", 4.0, 1, 0, 0, 0, 0);
	return 1;
}
CMD:sentar(playerid)
{
	ApplyAnimation(playerid, "BEACH", "ParkSit_M_loop", 4.0, 1, 0, 0, 0, 0);
	return 1;
}
CMD:conversar(playerid)
{
	ApplyAnimation(playerid, "PED", "IDLE_CHAT", 4.0, 0, 0, 0, 0, 0);
    return 1;
}
CMD:fodase(playerid)
{
	ApplyAnimation(playerid, "PED", "fucku", 4.0, 0, 0, 0, 0, 0);
	return 1;
}
CMD:luta(playerid)
{
	ApplyAnimation(playerid, "PARK", "Tai_Chi_Loop", 4.0, 1, 0, 0, 0, 0);
	return 1;
}
CMD:observar(playerid)
{
	ApplyAnimation(playerid, "BAR", "dnk_stndF_loop", 4.0, 1, 0, 0, 0, 0);
	return 1;
}
CMD:mijar(playerid)
{
	SetPlayerSpecialAction(playerid, 68);
	return 1;
}
CMD:parar(playerid)
{
    ClearAnimations(playerid);
    return 1;
}
CMD:admins(playerid)
{
    new txt[1400], adminon;

    if(!IsPlayerMobile(playerid)) strcat(txt, "{FFFFFF}Nome\t {FFFFFF}Cargo\t {FFFFFF}Status\n");

    for(new x = 0; x < MAX_PLAYERS; x++)
    {
        if(!IsPlayerIntern(x)) continue;

        format(String, 100, "{FFFFFF}%s\t %s\t %s\n", PlayerInfo[x][Nome], CargoAdminColor(x), (AntiAfk[x][aa_afk] ? ("{FF4000}AFK") : ("{1B6302}Online")));
        strcat(txt, String);
        adminon++;
    }

    if(!adminon)
        return ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FFFFFF}Admins Online [ {FF0000}0{FFFFFF} ]", "{FF0000}N�o h� administrador ( ADM ) online no momento!", "Fechar", #);

    format(String, 100, "{FFFFFF}Admins Online [ {328E0A}%d{FFFFFF} ]", adminon);
    ShowPlayerDialog(playerid, 0, (IsPlayerMobile(playerid) ? DIALOG_STYLE_LIST : DIALOG_STYLE_TABLIST_HEADERS), String, txt, "Fechar", #);
    return 1;
}
CMD:presos(playerid)
{
    if(!(IsPlayerInRangeOfPoint(playerid, 2.0, 248.9497, 67.6059, 1003.6406)  || IsPlayerInRangeOfPoint(playerid, 2.0, 252.1618, 67.7849, 1003.6478)))
        return SendClientMessage(playerid, Erro, "Voc� n�o est� em nenhum departamento de pol�cia");

    new _str[1400], presoson, hours, minutes, seconds;

    for(new x = 0; x < MAX_PLAYERS; x++)
    {
        if(PrisonEnum[x][pTempo] && PlayerInfo[x][Logado])
        {
            formatSeconds(PrisonEnum[x][pTempo], hours, minutes, seconds);
            format(_str, 1400, "%s{FFFFFF} %s{FFFFFF}[%d] \t%02d:%02d:%02d \t{C50000}%s \n", _str, PlayerInfo[x][Nome], x, hours, minutes, seconds, PrisonEnum[x][pCadeia]);
            presoson++;
        }
    }

    if(!presoson)
        return ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FFFFFF}Presos Online [ {FF0000}0{FFFFFF} ]", "{FF0000}N�o h� presos online no momento!", "Fechar", "");

    format(String, MAX_STRING, "{FFFFFF}Presos Online [ {328E0A}%d{FFFFFF} ]", presoson);
    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_LIST, String, _str, "Fechar", "");
    return 1;
}

CMD:aceitar(playerid)
{
    if(AdvogadoOfertou[playerid])
    {
        AdvogadoOfertou[playerid] = false;
        AdvogadoAceitou[playerid] = true;
        return 1;
    }
    else if(ParamedicOffer[playerid])
    {
        ParamedicOffer[playerid] = false;
        ParamedicAccepted[playerid] = true;
        return 1;
    }
    else if(wpOffer[playerid])
    {
        wpOffer[playerid] = false;
        wpAccepted[playerid] = true;
        return 1;
    }
    else if(mechanicalOffer[playerid])
    {
        mechanicalOffer[playerid] = false;
        mechanicalAccepted[playerid] = true;
        return 1;
    }
    else
    {
        SendClientMessage(playerid, Erro, "Voc� n�o recebeu nenhuma oferta");
    }
    return 1;
}
CMD:recusar(playerid)
{
    if(AdvogadoOfertou[playerid])
    {
        AdvogadoOfertou[playerid] = false;
        AdvogadoRecusou[playerid] = true;
    }
    else if(ParamedicOffer[playerid])
    {
        ParamedicOffer[playerid] = false;
        ParamedicRefused[playerid] = true;
        return 1;
    }
    else if(wpOffer[playerid])
    {
        wpOffer[playerid] = false;
        wpRefused[playerid] = true;
    }
    else if(mechanicalOffer[playerid])
    {
        mechanicalOffer[playerid] = false;
        mechanicalRefused[playerid] = true;
        return 1;
    }
    else
    {
        SendClientMessage(playerid, Erro, "Voc� n�o recebeu nenhuma oferta");
    }
    return 1;
}
CMD:advogados(playerid)
{
    new txt[1400], advon = 0;

    for(new x = 0; x < MAX_PLAYERS; x++)
    {
        if(PlayerInfo[x][Profissao] == lawyer && PlayerInfo[x][Logado] == true)
        {
            format(String, 200, "{8000FF}%s {FFFFFF}[%d]\n", PlayerInfo[x][Nome], x);
            strcat(txt, String);
            advon++;
        }
    }

    if(!advon)
        return ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FFFFFF}Advogados Online [ {FF0000}0{FFFFFF} ]", "{FF0000}N�o h� advogados online no momento!", "Fechar", #);

    format(String, 200, "{FFFFFF}Advogados Online [ {328E0A}%d{FFFFFF} ]", advon);

    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, String, txt, "Fechar", #);
    return 1;
}
CMD:advogado(playerid, params[])
{
    if(!PrisonEnum[playerid][pTempo])
        return SendClientMessage(playerid, Erro, "Voc� n�o est� preso para poder contatar um advogado(a)");

    if(PlayerInfo[playerid][blockLawyer])
        return SendClientMessage(playerid, Erro, "Voc� acabou de falar com advogado, aguarde alguns segundos...");

    new id, tmp[128];

    if(sscanf(params, "us[128]", id, tmp))
        return SendClientMessage(playerid, Erro, "Digite: /Advogado [id/nome] [mensagem]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) n�o conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Voc� n�o pode efetuar comando em s� mesmo");

    if(PlayerInfo[id][Profissao] != lawyer)
        return SendClientMessage(playerid, Erro, "Jogador(a) n�o � advogado(a)");

    format(String, MAX_STRING, "Mensagem enviada para o advogado(a) %s[%d] ( %s )", PlayerInfo[id][Nome], id, tmp);
    SendClientMessage(playerid, 0x8000FFAA, String);
    format(String, MAX_STRING, "Mensagem recebida do presidi�rio %s[%d] ( %s )", PlayerInfo[playerid][Nome], playerid, tmp);
    SendClientMessage(id, 0x8000FFAA, String);

    PlayerInfo[playerid][blockLawyer] = true;
    SetTimerEx("OnPlayerBlockSendLawyer", 30000, false, "d", playerid);
    return 1;
}
CMD:vips(playerid)
{
    new txt[3000], vipON = 0;

    for(new player = 0; player < MAX_PLAYERS; player++)
    {
        if(!PlayerInfo[player][Logado]) continue;

        if(!IsPlayerVip(player)) continue;

        vipON++;
        format(String, 200, "{FFFF00}%s{FFFFFF}[%d]\n", PlayerInfo[player][Nome], player);
        strcat(txt, String);
    }

    if(!vipON)
        return ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Vips", "{FFFFFF}N�o tem vips online no momento", "Fechar", #);

    format(String, 200, "{FFFFFF}Vips Online [ {FFFF00}%d{FFFFFF} ]", vipON);

    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_LIST, String, txt, "Fechar", #);
    return 1;
}
CMD:transferir(playerid, params[])
{
    if((gettime() - GetIntQuery(playerid, "Timers", "transaction")) < 600)
        return SendClientMessage(playerid, Erro, "Voc� acabou de transferir, aguarde alguns segundos...");

    new id, value;

    if(sscanf(params, "dd", id, value))
        return SendClientMessage(playerid, Erro, "Digite: /Transferir [id] [valor]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) n�o est� conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Voc� n�o pode efetuar comando em s� mesmo");

    if(GetDistanceBetweenPlayers(playerid, id) > 10)
        return SendClientMessage(playerid, Erro, "Voc� est� muito longe, chegue mais perto");

    if(PlayerInfo[playerid][Dinheiro] < value)
        return SendClientMessage(playerid, Erro, "Voc� n�o tem dinheiro o suficiente");

    if(value < 1 || value > 50000)
        return SendClientMessage(playerid, Erro, "Valores apenas de $1 at� $50.000");

    new query[200];
    mysql_format(IDConexao, query, 200, "INSERT INTO `Transfer` (`value`, `date`, `id_received`, `id_contas`) VALUES ('%d', NOW(), '%d', '%d')", value, PlayerInfo[id][ID], PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);

    SetIntQuery(playerid, "Timers", "transaction", gettime());

    PlayerInfo[playerid][Dinheiro] -= value;
    UpdatePlayerMoney(playerid);
    PlayerInfo[id][Dinheiro] += value;
    UpdatePlayerMoney(id);

    format(String, MAX_STRING, "Transfer�ncia de $%s para o jogador(a) %s[%d]", IsMoney(value, "."), PlayerInfo[id][Nome], id);
    SendClientMessage(playerid, Yellow, String);
    format(String, MAX_STRING, "O(A) Jogador(a) %s[%d] transferiu $%s para voc�", PlayerInfo[playerid][Nome], playerid, IsMoney(value, "."));
    SendClientMessage(id, Yellow, String);
    return 1;
}
CMD:tophoras(playerid)
{
    new name[MAX_PLAYER_NAME], value, txt[2000];

    new Cache:result = mysql_query(IDConexao, "SELECT `Nome`, `Identidade`.`level` FROM `Contas` INNER JOIN `Identidade` ON (`Identidade`.`id_contas`=`Contas`.`id`) ORDER BY `Identidade`.`level` DESC LIMIT 10");

    strcat(txt, "{FFFFFF}Top\t {FFFFFF}Nome\t {FFFFFF}Horas\n");

    for(new row = 0; row < cache_num_rows(); row++)
    {
        cache_get_value_name(row, "Nome", name);
        cache_get_value_int(row, "level", value);

        format(String, 100, "{1b6302}%d�\t {FFFFFF}%s\t {F87A02}%d\n", (row + 1), name, value);
        strcat(txt, String);
    }

    cache_delete(result);
    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_TABLIST_HEADERS, "{FFFFFF}Top {1B6302}Horas", txt, "Fechar", #);
}
CMD:topdinheiro(playerid)
{
    new name[MAX_PLAYER_NAME], value, valuebank, txt[2000];

    new Cache:result = mysql_query(IDConexao, "SELECT `Nome`, `Identidade`.`dinheiro`, `Identidade`.`saldobancario` FROM `Contas` INNER JOIN `Identidade` ON (`Identidade`.`id_contas`=`Contas`.`id`) ORDER BY (`Identidade`.`dinheiro`+`Identidade`.`saldobancario`) DESC LIMIT 10");

    strcat(txt, "{FFFFFF}Top\t {FFFFFF}Nome\t {FFFFFF}Dinheiro\n");

    for(new row = 0; row < cache_num_rows(); row++)
    {
        cache_get_value_name(row, "Nome", name);
        cache_get_value_int(row, "dinheiro", value);
        cache_get_value_int(row, "saldobancario", valuebank);

        format(String, 100, "{1b6302}%d�\t {FFFFFF}%s\t {F87A02}$%s\n", (row + 1), name, IsMoney((value + valuebank), "."));
        strcat(txt, String);
    }

    cache_delete(result);
    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_TABLIST_HEADERS, "{FFFFFF}Top {1B6302}Dinheiro", txt, "Fechar", #);
    return 1;
}
CMD:topkill(playerid)
{
    new name[MAX_PLAYER_NAME], value, txt[2000];

    new Cache:result = mysql_query(IDConexao, "SELECT `Nome`, `Identidade`.`matou` FROM `Contas` INNER JOIN `Identidade` ON (`Identidade`.`id_contas`=`Contas`.`id`) ORDER BY `Identidade`.`matou` DESC LIMIT 10");

    strcat(txt, "{FFFFFF}Top\t {FFFFFF}Nome\t {FFFFFF}Kill\n");

    for(new row = 0; row < cache_num_rows(); row++)
    {
        cache_get_value_name(row, "Nome", name);
        cache_get_value_int(row, "matou", value);

        format(String, 100, "{1b6302}%d�\t {FFFFFF}%s\t {F87A02}%d\n", (row + 1), name, value);
        strcat(txt, String);
    }

    cache_delete(result);
    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_TABLIST_HEADERS, "{FFFFFF}Top {1B6302}Kill", txt, "Fechar", #);
    return 1;
}
CMD:topprocurado(playerid)
{
    new name[MAX_PLAYER_NAME], value, txt[2000];

    new Cache:result = mysql_query(IDConexao, "SELECT `Nome`, `Identidade`.`estrelas` FROM `Contas` INNER JOIN `Identidade` ON (`Identidade`.`id_contas`=`Contas`.`id`) ORDER BY `Identidade`.`estrelas` DESC LIMIT 10");

    strcat(txt, "{FFFFFF}Top\t {FFFFFF}Nome\t {FFFFFF}Estrelas\n");

    for(new row = 0; row < cache_num_rows(); row++)
    {
        cache_get_value_name(row, "Nome", name);
        cache_get_value_int(row, "estrelas", value);

        format(String, 100, "{1b6302}%d�\t {FFFFFF}%s\t {F87A02}%d\n", (row + 1), name, value);
        strcat(txt, String);
    }

    cache_delete(result);
    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_TABLIST_HEADERS, "{FFFFFF}Top {1B6302}Procurado", txt, "Fechar", #);
    return 1;
}
CMD:consertar(playerid)
{
    if(!PlayerInfo[playerid][kitrepair])
        return SendClientMessage(playerid, Erro, "Voc� n�o tem Kit Reparos");

    new Float:x, Float:y, Float:z;

    for(new vehicleid = 0; vehicleid < MAX_VEHICLES; vehicleid++)
    {
        GetVehiclePos(PublicVehicle[vehicleid][pv_vehicle], x, y, z);

        if(PublicVehicle[vehicleid][pv_vehicle] == INVALID_VEHICLE_ID)
            continue;

        if(!IsPlayerInRangeOfPoint(playerid, 5.0, x, y, z))
            continue;

        if(!IsBrokenVehicle(PublicVehicle[vehicleid][pv_vehicle]))
            return SendClientMessage(playerid, Erro, "Este ve�culo n�o est� quebrado");

        PlayerInfo[playerid][kitrepair] -= 1;

        new query[100];
        mysql_format(IDConexao, query, 100, "UPDATE `Itens` SET `kitrepair`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][kitrepair], PlayerInfo[playerid][ID]);
        mysql_query(IDConexao, query);

        TogglePlayerControllable(playerid, false);
        ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 1, 0, 0, 0, 0);
        PlayerRepairVehicle[playerid] = true;
        ShowTDLoading(playerid);

        RepairingVehicle(playerid, PublicVehicle[vehicleid][pv_vehicle]);
        return 1;
    }

    SendClientMessage(playerid, Erro, "Voc� est� longe do ve�culo, chegue mais perto");
    return 1;
}
CMD:codigo(playerid)
{
    format(String, MAX_STRING, "Seu c�digo: {FF4000}%s{FFFFFF}, n�o divulgue-o!", PlayerInfo[playerid][Code]);
    return SendClientMessage(playerid, White, String);
}
CMD:estudar(playerid)
{
    ShowPlayerDialog(playerid, study, DIALOG_STYLE_LIST, "{FF0000}Estudos", "{FFFFFF}Auto Escola", "Estudar", "Cancelar");
    return 1;
}
CMD:coresid(playerid)
{
	new str[3400], count=0;

	for(new i = 0; i < sizeof(VehHexColors); i++)
	{
		format(str, 3400, "%s{%06x}%03d ", str, VehHexColors[count] >>> 8, count);
		count++;

        switch(count)
        {
            case 15, 30, 45, 60, 75, 90, 105, 120, 135, 150, 165, 180, 195, 210, 225, 240: strcat(str, "\n");
        }
	}

    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Cores ID", str, "Fechar", #);
	return 1;
}
CMD:192(playerid)
{
    if(PlayerInfo[playerid][blockSOS])
        return SendClientMessage(playerid, Erro, "SOS bloqueado, aguarde alguns segundos...");

    if(!PlayerInfo[playerid][disease] && !PlayerInfo[playerid][hasReborn])
        return SendClientMessage(playerid, Erro, "Voc� n�o est� doente ou ferido(a)");

    new Float:x, Float:y, Float:z;

    GetPlayerPos(playerid, x, y, z);
    GetPlayer2DZone(zone, MAX_ZONE_NAME, x, y);

    for(new player = 0; player < MAX_PLAYERS; player++)
    {
        if(PlayerInfo[player][Profissao] == paramedic)
        {
            format(String, MAX_STRING, "O(A) Jogador(a) %s[%d] est� pedindo SOS na localidade ( %s )", PlayerInfo[playerid][Nome], playerid, zone);
            SendClientMessage(player, Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);
            continue;
        }
    }

    PlayerInfo[playerid][t_blockSOS] = SetTimerEx("OnPlayerBlockSOS", 60000, false, "d", playerid);

    PlayerInfo[playerid][blockSOS] = true;
    SendClientMessage(playerid, White, "Todas as autoridades online foi notificada de seu SOS");
    return 1;
}
CMD:190(playerid)
{
    if(!PlayerInfo[playerid][hasReborn])
        return SendClientMessage(playerid, Erro, "Voc� n�o est� ferido(a)");

    if(PlayerInfo[playerid][killeridReborn] == INVALID_PLAYER_ID)
        return SendClientMessage(playerid, Erro, "Ningu�m te feriu ou o(a) assasino(a) fugiu");

    new id = PlayerInfo[playerid][killeridReborn];

    PlayerInfo[playerid][killeridReborn] = INVALID_PLAYER_ID;
    KillTimer(PlayerInfo[playerid][t_reportMurter]);

    PlayerInfo[id][Estrelas] += 5;
    UpdatePlayerStar(id);

    new Float:x, Float:y, Float:z;

    GetPlayerPos(playerid, x, y, z);
    GetPlayer2DZone(zone, MAX_ZONE_NAME, x, y);

    format(String, MAX_STRING, "%s[%d] est� sendo procurado(a) por ferir gravimente %s[%d] nas localidade ( %s )", PlayerInfo[id][Nome], id, PlayerInfo[playerid][Nome], playerid, zone);
    SendClientMessageToAll(Profission[PlayerInfo[playerid][Profissao]][pfs_color], String);
    return 1;
}
CMD:mudarsenha(playerid)
{
    ShowPlayerDialog(playerid, alter_pass, DIALOG_STYLE_PASSWORD, "{FF0000}Alterar Senha", "{FFFFFF}Digite abaixo sua nova senha:", "Alterar", "Cancelar");
    return 1;
}
CMD:mudaremail(playerid)
{
    ShowPlayerDialog(playerid, alter_email, DIALOG_STYLE_INPUT, "{FF0000}Alterar Email", "{FFFFFF}Digite abaixo seu novo email:", "Alterar", "Cancelar");
    return 1;
}
CMD:celular(playerid)
{
    PlayerInfo[playerid][smsIdReceive] = INVALID_PLAYER_ID;

    new txt[300];
    strcat(txt, "{FFFFFF}GPS\n");
    strcat(txt, "{FFFFFF}Enviar SMS\n");
    format(String, 100, "{FFFFFF}%s SMS\n", (PlayerInfo[playerid][smsBlock]?("Desbloquear"):("Bloquear")));
    strcat(txt, String);

    ShowPlayerDialog(playerid, cellphone_list, DIALOG_STYLE_LIST, "{FF0000}Celular", txt, "Selecionar", "Cancelar");
    return 1;
}
CMD:sim(playerid)
{
    if(!Survey[s_state])
        return SendClientMessage(playerid, Erro, "N�o existe uma enquete, portanto n�o podera votar");

    if(SurveyVoted[playerid])
        return SendClientMessage(playerid, Erro, "O voto � apenas uma vez, aguarde o fim");

    Survey[s_yes]++;
    SurveyVoted[playerid] = true;
    SendClientMessage(playerid, Green, "Voto efetuado, aguarde o fim");
    return 1;
}
CMD:nao(playerid)
{
    if(!Survey[s_state])
        return SendClientMessage(playerid, Erro, "N�o existe uma enquete, portanto n�o podera votar");

    if(SurveyVoted[playerid])
        return SendClientMessage(playerid, Erro, "O voto � apenas uma vez, aguarde o fim");

    Survey[s_no]++;
    SurveyVoted[playerid] = true;
    SendClientMessage(playerid, Green, "Voto efetuado, aguarde o fim");
    return 1;
}
CMD:mecanico(playerid)
{
    if(PlayerInfo[playerid][blockMechanical])
        return SendClientMessage(playerid, Erro, "Voc� j� informou todos os mec�nicos, aguarde alguns segundos...");

    new zoneLocal[MAX_ZONE_NAME], Float:x, Float:y, Float:z;

    GetPlayerPos(playerid, x, y, z);
    GetPlayer2DZone(zoneLocal, MAX_ZONE_NAME, x, y);

    format(String, MAX_STRING, "O(A) Jogador(a) %s[%d] est� necessitando de mec�nico nas localidades ( %s )", PlayerInfo[playerid][Nome], playerid, zoneLocal);

    for(new player = 0; player < MAX_PLAYERS; player++)
    {
        if(PlayerInfo[player][Profissao] != mechanical) continue;

        SendClientMessage(player, Profission[PlayerInfo[player][Profissao]][pfs_color], String);
        continue;
    }

    PlayerInfo[playerid][blockMechanical] = true;
    SetTimerEx("OnPlayerBlockMechanical", 60000, false, "d", playerid);
    return 1;
}
