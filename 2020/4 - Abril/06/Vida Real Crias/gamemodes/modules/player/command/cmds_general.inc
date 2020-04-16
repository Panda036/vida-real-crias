#include YSI\y_hooks

new bool:BlockTransfer[MAX_PLAYERS];

hook OnPlayerDisconnect(playerid, reason)
{
    BlockTransfer[playerid] = false;
    return 1;
}

public OnPlayerCommandReceived(playerid, cmd[], params[], flags)
{
    if(PlayerInfo[playerid][Logado] == false){
        SendClientMessage(playerid, Erro, "Você não está logado");
        return 0;
    }
    if(AntiAfk[playerid][aa_afk] == true){
        SendClientMessage(playerid, Erro, "Antes de usar comando, digite: /Sairafk");
        return 0;
    }
    if(Algemado[playerid] == true){
        SendClientMessage(playerid, Erro, "Você está algemado e não pode usar comando");
        return 0;
    }
    if(PrisonEnum[playerid][pTempo] != 0)
    {
        if(!strcmp(PrisonEnum[playerid][pCadeia], "Municipal"))
        {
            if(!strcmp(cmd, "aceitar") || !strcmp(cmd, "recusar") || !strcmp(cmd, "advogados") || !strcmp(cmd, "advogado")) return 1;
        }
        SendClientMessage(playerid, Erro, "Você está preso e não pode usar comando");
        return 0;
    }
    if(IsArena[playerid])
    {
        if(!strcmp(cmd, "sairarena")) return 1;

        SendClientMessage(playerid, Erro, "Você está na arena e não pode usar comando");
        return 0;
    }
    if(PlayerInfo[playerid][tutorial]){
        SendClientMessage(playerid, Erro, "Você está no tutorial e não pode usar comando");
        return 0;
    }
    if(PlayerInfo[playerid][load]){
        SendClientMessage(playerid, Erro, "Seus dados estão sendo carregado, aguarde alguns segundos...");
        return 0;
    }
    return 1;
}

public OnPlayerCommandPerformed(playerid, cmd[], params[], result, flags)
{
    if(result == -1)
    {
        SendClientMessage(playerid, Erro, "Comando Inválido");
        return 0;
    }

    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerHelper(i) && viewcmds[i] == true)
        {
            format(String, sizeof(String), "| VRC-Admin | O(A) jogador(a) %s[%d] digitou o comando: %s", PlayerInfo[playerid][Nome], playerid, cmd);
            SendClientMessage(i, adm, String);
        }
    }
    return 1;
}

forward UnlockTransfer(playerid);
public UnlockTransfer(playerid)
{
    BlockTransfer[playerid] = false;
    return 1;
}

/******************************************************************************/
/*****************************| COMMANDS GERAIS |******************************/
/******************************************************************************/

CMD:reabastecer(playerid)
{
    if(!PlayerInfo[playerid][havegallon])
        return SendClientMessage(playerid, Erro, "Você não tem nenhum Galão de Combustível");

    if(!PlayerInfo[playerid][gallon])
        return SendClientMessage(playerid, Erro, "Seu Galão de Combustível está vazio");

    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
        {
            if(IsPlayerInRangeOfPoint(playerid, 7.0, DataVehicles[slot][i][vx], DataVehicles[slot][i][vy], DataVehicles[slot][i][vz]) && DataVehicles[slot][i][vconnected])
            {
                if(IsPlayerInAnyVehicle(playerid))
                    return SendClientMessage(playerid, Erro, "Para reabastecer precisa sair do veículo");

                if(DataVehicles[slot][i][vgasoline])
                    return SendClientMessage(playerid, Erro, "Esse veículo ainda tem gasolina");

                PlayerInfo[playerid][gallon] = 0;
                DataVehicles[slot][i][vgasoline] = 10;
                SendClientMessage(playerid, White, "O veículo foi reabastecido, mesmo assim vá até o Posto de Gasolina mas próximo");
                return 1;
            }
        }
    }
    SendClientMessage(playerid, Erro, "Você não está perto de nenhum veículo");
    return 1;
}
CMD:vendercelular(playerid)
{
    if(PlayerInfo[playerid][cellphone] == 0)
        return SendClientMessage(playerid, Erro, "Você não tem nenhum celular");

    PlayerInfo[playerid][cellphone] = 0;

    new _str[100];
    mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Itens` SET `celular`='0' WHERE `id_contas`='%d'", PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, _str);

    SendClientMessage(playerid, Green, "Celular vendido com sucesso");
    return 1;
}
CMD:usarkit(playerid)
{
    if(PlayerInfo[playerid][medicalkit] == 0)
        return SendClientMessage(playerid, Erro, "Você não tem nenhum Kit Médico");

    new Float:health;
    GetPlayerHealth(playerid, health);

    if(health > 50.0)
        return SendClientMessage(playerid, Erro, "Sua vida precisa estar abaixo de 50 porcento");

    PlayerInfo[playerid][medicalkit]--;
    SetPlayerHealth(playerid, 100);

    new _str[100];
    mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Itens` SET `kitmedicos`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][medicalkit], PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, _str);

    format(String, sizeof(String), "| KIT-MÉDICO | Você utilizou um kit médico e a sua vida foi recuperada ( Kit médico disponivél: %d )", PlayerInfo[playerid][medicalkit]);
    SendClientMessage(playerid, Green, String);
    return 1;
}
CMD:sms(playerid, params[])
{
    if(PlayerInfo[playerid][cellphone] == 0)
        return SendClientMessage(playerid, Erro, "Você não tem um celular");

    if(PlayerInfo[playerid][sms] == 0)
        return SendClientMessage(playerid, Erro, "Você não tem sms suficiente");

    new tmp[128], id;

    if(sscanf(params, "us[128]", id, tmp))
        return SendClientMessage(playerid, Erro, "Digite: /Sms [id/nome] [mensagem]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(playerid == id)
            return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    if(PlayerInfo[id][cellphone] == 0)
        return SendClientMessage(playerid, Erro, "O(A) Jogador(a) não tem celular");

    format(String,sizeof(String), "| SMS | Mensagem enviada para %s[%d] ( %s )", PlayerInfo[id][Nome], id, tmp);
    SendClientMessage(playerid, 0xFF8000AA, String);
    GameTextForPlayer(playerid, "~w~mensagem ~w~enviada!" , 2500, 1);
    PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
    PlayerInfo[playerid][sms]--;

    format(String,sizeof(String), "| SMS | Mensagem recebida de %s[%d] ( %s )", PlayerInfo[playerid][Nome], playerid, tmp);
    SendClientMessage(id, 0xFF8000AA, String);
    GameTextForPlayer(id, "~w~mensagem ~w~recebida!" , 2500, 1);
    PlayerPlaySound(id, 1085, 0.0, 0.0, 0.0);

    new _query[70];
    mysql_format(IDConexao, _query, sizeof(_query), "UPDATE `Itens` SET `sms`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][sms], PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, _query);
    return 1;
}
CMD:comandoscasa(playerid)
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
CMD:reais(playerid)
{
    ShowPlayerDialog(playerid, main_reais, DIALOG_STYLE_LIST, "{FF0000}Reais", "{FFFFFF}Comprar VIP", "Continuar", "Cancelar");
    return 1;
}
CMD:profissao(playerid)
{
    new txt[1500];

    if(!IsPlayerMobile(playerid))
        { strcat(txt, "{FF0000}Comandos \t\t {FFFFFF}Informações \n"); }

    switch(PlayerInfo[playerid][Profissao])
    {
        case unemployed:
        {
            new string[1000];
            strcat(string, "{FFFFFF}Você está desempregado, para conseguir um vá até a Agencia de Empregos em uma das 3 cidades de san andreas \n\n");
            strcat(string, "{FFFFFF}Los Santos - Está localizado perto da praia de Santa Maria \n\n");
            strcat(string, "{FFFFFF}Las Venturas - Está localizado perto do Aero Porto \n\n");
            strcat(string, "{FFFFFF}San Fierro - Está localizado perto da Estação Ferroviária \n\n");
            strcat(string, "{FFFFFF}Todas as Agências de Empregos tem um simbolo de uma {1e90ff}Caveira Azul {FFFFFF}no Radar \n\n");
            ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Desempregado", string, "Fechar", #);
            return 1;
        }
        case newspaperdelivery:
        {
            strcat(txt, "{80FF80}/Pegarjornais {FFFFFF}\t\t Para pegar 20 jornais \n");
            strcat(txt, "{80FF80}/Cancelar {FFFFFF}\t\t Para cancelar as entregas \n\n");
        }
        case icecream:
        {
            strcat(txt, "{80FF80}/VenderSorvete {FFFFFF}\t\t Para oferecer sorvete à um determinado jogador(a) \n\n");
        }
        case pizzaboy:
        {
            strcat(txt, "{FFFF80}Precione \"Y\"{FFFFFF}\t\t Para pegar 10 Pizzas prontas \n");
            strcat(txt, "{FFFF80}Precione \"N\" {FFFFFF}\t\t Para fazer a entrega da Pizza \n");
            strcat(txt, "{FFFF80}/Cancelar {FFFFFF}\t\t Para cancelar as entregas \n\n");
        }
        case gari:
        {
            strcat(txt, "{D56A00}/ColetarLixo {FFFFFF}\t\t Para pegar um lixo \n");
            strcat(txt, "{D56A00}/RemoverLixo {FFFFFF}\t\t Para remover um lixo de sua mão\n");
        }
        case paramedic:
        {
            strcat(txt, "{00FF80}/VenderCura {FFFFFF}\t\t Para oferecer cura à um determinado jogador(a) \n");
            strcat(txt, "{00FF80}/VenderVacina {FFFFFF}\t\t Para oferecer vacina à um determinado jogador(a) \n");
            strcat(txt, "{00FF80}/Uniforme {FFFFFF}\t\t Para uniformizar-se \n");
        }
        case lawyer:
        {
            strcat(txt, "{8000FF}/Presos {FFFFFF}\t\t Para ver s jogador(a) que está preso(a) \n");
            strcat(txt, "{8000FF}/Soltar {FFFFFF}\t\t Para soltar um determinado jogador(a) \n\n");
        }
        case taxi:
        {
            strcat(txt, "{FFFF00}/Localizar {FFFFFF}\t\t Para localizar o cliente \n\n");
        }
        case tanker:
        {
            strcat(txt, "{808080}/Carregar {FFFFFF}\t\t Para carregar o tanque de petróleo \n");
            strcat(txt, "{808080}/Descarregar {FFFFFF}\t\t Para descarregar o tanque de petróleo \n\n");
        }
        case military..interpol:
        {
            strcat(txt, "{FFFFFF}Aperte '{4AA5FF}F{FFFFFF}' ou '{4AA5FF}Enter{FFFFFF}' {FFFFFF}\t\t Para abrir o portão do derpartamento\n");
            strcat(txt, "{4AA5FF}/Prenderarmas {FFFFFF}\t\t Para apreender as armas de um(a) jogador(a) \n");
            strcat(txt, "{4AA5FF}/Localizar  {FFFFFF}\t\t Para localizar o(a) procurado(a) \n");
            strcat(txt, "{4AA5FF}/Algemar {FFFFFF}\t\t Para algemar o(a) procurado(a) \n");
            strcat(txt, "{4AA5FF}/Prender {FFFFFF}\t\t Para prender o(a) procurado(a) \n");
            strcat(txt, "{4AA5FF}/Abordar {FFFFFF}\t\t Para abordar o(a) procurado(a) \n");
            strcat(txt, "{4AA5FF}/Tapete {FFFFFF}\t\t Para criar/remover um tapete de pregos \n");
            strcat(txt, "{4AA5FF}/Barreira {FFFFFF}\t\t Para criar/remover uma barreira \n");
            strcat(txt, "{4AA5FF}/Equipar {FFFFFF}\t\t Para equipar armas e colete \n");
            strcat(txt, "{4AA5FF}/Uniforme {FFFFFF}\t\t Para uniformizar-se \n");
            strcat(txt, "{4AA5FF}/RemoverUniforme {FFFFFF}\t\t Para remover o uniforme \n\n");
        }
        case internalaffairs:
        {
            strcat(txt, "{8080C0}/PrenderPolicial [id] [motivo] {FFFFFF}\t\t Para prender o(a) policial \n\n");
        }
        case thief:
        {
            strcat(txt, "{FF8080}/PlanejarRoubo {FFFFFF}\t\t Para começar a roubar os gás \n");
            strcat(txt, "{FF8080}/PegarGas {FFFFFF}\t\t Para pegar o gás \n");
            strcat(txt, "{FF8080}/CancelarRoubo {FFFFFF}\t\t Para cancelar o roubo \n");
            strcat(txt, "{FF8080}/ColocarGas {FFFFFF}\t\t Para colocar o gás no caminhão \n\n");
        }
    }

    format(String, sizeof(String), "{FF0000}%s", NameProfission(PlayerInfo[playerid][Profissao]));
    strcat(txt, "{0080FF}/Cp [mensagem] {FFFFFF}\t\t Para usar o chat profissão \n");
    strcat(txt, "{0080FF}/Hq {FFFFFF}\t\t Para localizar o local do seu trabalho \n");

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
CMD:trabalhar(playerid)
{
    if(!AgenciaEncaminhado[playerid])
        return SendClientMessage(playerid, Erro,"Você não foi encaminhado por nenhuma Agencia de Empregos");

    if(!IsPlayerInRangeOfPoint(playerid, 2.0, PlayerAgency[playerid][pa_x], PlayerAgency[playerid][pa_y], PlayerAgency[playerid][pa_z]))
    {
        format(String, sizeof(String), "Você não está na HQ de %s", NameProfission(PlayerInfo[playerid][Semprofissao]));
        SendClientMessage(playerid, Erro, String);
        return 1;
    }

    GetForwardedAgency(playerid, PlayerAgency[playerid][pa_profission]);
    return 1;
}
CMD:partida(playerid)
{
    new vehicleid = GetPlayerVehicleID(playerid), mot, lu, alar, por, cap, porma, ob;

    if(!IsPlayerInAnyVehicle(playerid))
        return SendClientMessage(playerid, Erro, "Você não está em um veículo");

    if(IsPlayerInAnyBike(vehicleid))
        return SendClientMessage(playerid, Erro, "Você está em uma bicicleta");

    GetVehicleParamsEx(vehicleid,  mot, lu, alar, por, cap, porma, ob);

    if(mot == 0)
    {
        for(new i = 0; i < MAX_PLAYERS; i++)
        {
            for(new slot = 0; slot < MAX_MAIN_VEHICLES; slot++)
            {
                if(vehicleid == DataVehicles[slot][i][vvehicle])
                {
                    if(!DataVehicles[slot][i][vgasoline]) return SendClientMessage(playerid, Erro, "Este veículo não tem Gasolina");
                }
            }
        }

        SetVehicleParamsEx(vehicleid, 1, 1, alar, por, cap, porma, ob);
        SendClientMessage(playerid, Green, "Veiculo ligado");

        if(Fueling[playerid])
        {
            Fueling[playerid] = false;
            SendClientMessage(playerid, Yellow, "O abastecimento foi cancelado");
        }
    }
    else
    {
        SendClientMessage(playerid, Green, "Veiculo desligado");
        SetVehicleParamsEx(vehicleid, 0, 0, alar, por, cap, porma, ob);
    }
    return 1;
}
CMD:radio(playerid, params[])
{
    new tmp[128];

    if(sscanf(params, "s[128]", tmp))
        return SendClientMessage(playerid, Erro, "Digite: /Radio [Link.mp3]");

    PlayAudioStreamForPlayer(playerid, tmp);
    SendClientMessage(playerid, White, "Para pausar digite: /radio stop ou espaço apenas");
    return 1;
}
CMD:radios(playerid)
{
    new txt[500];
    strcat(txt, "{FFFFFF}Rádio Jovem Pan\nRádio Hunter\n");
    strcat(txt, "{FFFFFF}Rádio Massa FM \nRádio Reggae141\n");
    strcat(txt, "{FF0000}Desligar Radios");
    ShowPlayerDialog(playerid, radio, DIALOG_STYLE_LIST, "{FF0000}MP3", txt, "Continuar", "Fechar");
    return 1;
}
CMD:mudarnome(playerid)
{
    if(PlayerInfo[playerid][Reais] < 7)
        return SendClientMessage(playerid, Erro, "Você não tem Reais o suficiente para mudar o nome");

    ShowPlayerDialog(playerid, rename, DIALOG_STYLE_INPUT, "{FF0000}Mudar nome", "{FFFFFF}Digite seu novo nick e clique em {FF0000}Mudar\n{FFFFFF}Por favor não coloque {FF0000}ESPAÇO {FFFFFF}em seu nome:", "Mudar", "Sair");
    return 1;
}
CMD:meulevel(playerid)
{
    new txt[128];
    format(String, sizeof(String), "{FFFFFF} Nick: {FF0000}%s \n\n", PlayerInfo[playerid][Nome]);
    strcat(txt, String);
    format(String, sizeof(String), "{FFFFFF} Level: {1b6302}%d \n\n", PlayerInfo[playerid][Level]);
    strcat(txt, String);
    format(String, sizeof(String), "{FFFFFF} Experiência: {f29b0d}%d \n\n", PlayerInfo[playerid][Exp]);
    strcat(txt, String);
    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{00FF00}Meu Level", txt, "Fechar", "");
    return 1;
}
CMD:ajuda(playerid)
{
    new txt[200];
    strcat(txt, "{FFFFFF}Level \n");
    strcat(txt, "{FFFFFF}Salário \n");
    strcat(txt, "{FFFFFF}Comandos \n");
    strcat(txt, "{FFFFFF}Contatos \n");
    strcat(txt, "{FFFFFF}Casa \n");
    strcat(txt, "{FFFFFF}Empresa \n");
    strcat(txt, "{FFFFFF}Veículo \n");
    strcat(txt, "{FFFFFF}Mercadoria \n");
    ShowPlayerDialog(playerid, help, DIALOG_STYLE_LIST, "{FF0000}Ajuda", txt, "Continuar", "Cancelar");
    return 1;
}
CMD:entrar(playerid)
{
    EntrarInterior(playerid);
    return 1;
}
CMD:sair(playerid)
{
    SairInterior(playerid);
    return 1;
}
CMD:identidade(playerid)
{
    new txt[1000];
    format(String, sizeof(String), "{FFFFFF}» Level: {00C40A}%d \n", PlayerInfo[playerid][Level]);
    strcat(txt, String);
    format(String, sizeof(String), "{FFFFFF}» Experiência: {00C40A}%d \n", PlayerInfo[playerid][Exp]);
    strcat(txt, String);
    format(String, sizeof(String), "{FFFFFF}» Reais: {00C40A}R$%d,00 \n", PlayerInfo[playerid][Reais]);
    strcat(txt, String);

    if(PlayerInfo[playerid][vaccine])
    {
        format(String, sizeof(String), "{FFFFFF}» Vacinas: {00C40A}%d \n", PlayerInfo[playerid][vaccine]);
        strcat(txt, String);
    }
    else
    {
        strcat(txt, "{FFFFFF}» Vacinas: {F84300}0 \n");
    }
    if(PlayerInfo[playerid][disease])
    {
        format(String, sizeof(String), "{FFFFFF}» Doença: {F84300}%s \n", DiseaseName(playerid));
        strcat(txt, String);
    }
    else
    {
        format(String, sizeof(String), "{FFFFFF}» Doença: {00C40A}%s \n", DiseaseName(playerid));
        strcat(txt, String);
    }
    if(VipInfo[playerid][Vip])
    {
        strcat(txt, "{FFFFFF}» VIP: {00C40A}Sim \n");
    }
    else
    {
        strcat(txt, "{FFFFFF}» VIP: {F84300}Não \n");
    }
    if(PlayerInfo[playerid][healthplan])
    {
        strcat(txt, "{FFFFFF}» Plano de Saúde: {00C40A}Sim \n");
    }
    else
    {
        strcat(txt, "{FFFFFF}» Plano de Saúde: {F84300}Não \n");
    }

    format(String, sizeof(String), "{FFFFFF}» Kit médicos: {00C40A}%d \n", PlayerInfo[playerid][medicalkit]);
    strcat(txt, String);
    format(String, sizeof(String), "{FFFFFF}» Saldo Sem Parar: {00C40A}$%s \n", IsMoney(PlayerInfo[playerid][nonstop], "."));
    strcat(txt, String);
    format(String, sizeof(String), "{FFFFFF}» Sexo: {00C40A}%s \n", PlayerInfo[playerid][sexo]);
    strcat(txt, String);
    format(String, sizeof(String), "{FFFFFF}» Skin ID: {00C40A}%d \n", PlayerInfo[playerid][skin]);
    strcat(txt, String);
    format(String, sizeof(String), "{FFFFFF}» Dinheiro: {00C40A}$%s \n", IsMoney(PlayerInfo[playerid][Dinheiro], "."));
    strcat(txt, String);
    format(String, sizeof(String), "{FFFFFF}» Matou: {00C40A}%d {FFFFFF}- Morreu: {f84300}%d \n", PlayerInfo[playerid][Matou], PlayerInfo[playerid][Morreu]);
    strcat(txt, String);
    format(String, sizeof(String), "{FFFFFF}» Avisos: {f84300}%d \n", PlayerInfo[playerid][Avisos]);
    strcat(txt, String);
    if(PlayerInfo[playerid][cnh_a])
    {
        format(String, sizeof(String), "{FFFFFF}» Categoria A: {00C40A}Sim \n");
    }
    else
    {
        format(String, sizeof(String), "{FFFFFF}» Categoria A: {f84300}Não \n");
    }
    strcat(txt, String);
    if(PlayerInfo[playerid][cnh_b])
    {
        format(String, sizeof(String), "{FFFFFF}» Categoria B: {00C40A}Sim \n");
    }
    else
    {
        format(String, sizeof(String), "{FFFFFF}» Categoria B: {f84300}Não \n");
    }
    strcat(txt, String);
    if(PlayerInfo[playerid][cnh_c])
    {
        format(String, sizeof(String), "{FFFFFF}» Categoria C: {00C40A}Sim \n");
    }
    else
    {
        format(String, sizeof(String), "{FFFFFF}» Categoria C: {f84300}Não \n");
    }
    strcat(txt, String);
    if(PlayerInfo[playerid][cnh_cht])
    {
        format(String, sizeof(String), "{FFFFFF}» CHT: {00C40A}Sim \n");
    }
    else
    {
        format(String, sizeof(String), "{FFFFFF}» CHT: {f84300}Não \n");
    }
    strcat(txt, String);
    if(PlayerInfo[playerid][cnh_arrais])
    {
        format(String, sizeof(String), "{FFFFFF}» Arrais: {00C40A}Sim \n");
    }
    else
    {
        format(String, sizeof(String), "{FFFFFF}» Arrais: {f84300}Não \n");
    }
    strcat(txt, String);
    format(String, sizeof(String), "{FFFFFF}» E-mail: {00C40A}%s \n", PlayerInfo[playerid][Email]);
    strcat(txt, String);

    format(String, sizeof(String), "{0080FF}Identidade de {FFFFFF}%s", PlayerInfo[playerid][Nome]);

    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, String, txt, "Fechar", "");
    return 1;
}
CMD:statusmostrar(playerid)
{
    StatusMostrar(playerid);
    return 1;
}
CMD:statusocultar(playerid)
{
    StatusOcultar(playerid);
    return 1;
}
CMD:relatorio(playerid, params[])
{
    if(LiberarRelatorio{playerid} == true)
        return SendClientMessage(playerid, Erro, "Relatório bloqueado por flood, aguarde alguns segundos");

    new id, tmp[128];

    if(sscanf(params, "us[128]", id, tmp))
        return SendClientMessage(playerid, Erro, "Digite: /Relatorio [id/nome] [relatório]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    LiberarRelatorio{playerid} = true;
    SetTimerEx("UnlockingReport", 30*1000, false, "i", playerid);

    SendClientMessage(playerid, White, "Seu relatorio foi enviado com sucesso para a Adminstração");
    format(String, sizeof(String), "Relatório de %s[%d] acusando: %s[%d] de %s", PlayerInfo[playerid][Nome], playerid, PlayerInfo[id][Nome], id, tmp);

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
    if(LiberarDuvida{playerid} == true)
        return SendClientMessage(playerid, Erro, "Duvida bloqueada por flood, aguarde alguns segundos");

    new tmp[128];

    if(sscanf(params, "s[128]", tmp))
        return SendClientMessage(playerid, Erro, "Digite: /Duvida [duvida]");

    LiberarDuvida{playerid} = true;
    SetTimerEx("UnlockingDoubt", 30*1000, false, "i", playerid);

    SendClientMessage(playerid, White, "Sua duvida foi enviada a Administraçáo, aguarde à resposta");
    format(String, sizeof(String), "Duvida de %s[%d]: %s", PlayerInfo[playerid][Nome], playerid, tmp);

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
CMD:creditos(playerid)
{
    new txt[1500];
    strcat(txt, "{FF0000} GameMode: {FFFFFF}Vida Real Crias - VRC RPG v1.0.0 \n\n");
    strcat(txt, "{FFFFFF} Desenvolvido e Atualizado por: {088fd2}Henrique Calenzo \n\n");
    strcat(txt, "{1b6302} Agradecimentos Especiais; \n\n");
    strcat(txt, "{f29b0d} pBlueG - {FFFFFF}MySQL \n");
    strcat(txt, "{f29b0d} Emmet_ - {FFFFFF}sscanf \n");
    strcat(txt, "{f29b0d} Incognito - {FFFFFF}streamer \n");
    strcat(txt, "{f29b0d} YourShadow - {FFFFFF}Pawn.CMD \n");
    strcat(txt, "{f29b0d} rootcause - {FFFFFF}Ideia de sistemas ( Casas, Empresas e Gari ) \n");
    strcat(txt, "{218721} VidaaRealCrias.wordpress.com/ \n\n");
    strcat(txt, "{FFFFFF} © Copyright 2020 - 2020 Vida Real Crias ");
    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{00CED1}Créditos{FFFFFF}",txt, "Fechar", "");
    return 1;
}
CMD:regras(playerid)
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
CMD:vantagensvip(playerid)
{
    new txt[1000];
	strcat(txt, "{FFFF00}»{FFFFFF} Sistema auto tuning \n");
    strcat(txt, "{FFFF00}»{FFFFFF} Neon personalizado \n");
	strcat(txt, "{FFFF00}»{FFFFFF} Nitro infinito \n");
	strcat(txt, "{FFFF00}»{FFFFFF} Nick com prefixo [VIP] no chat \n");
	strcat(txt, "{FFFF00}»{FFFFFF} Mudar a cor da Tag [VIP] \n");
	strcat(txt, "{FFFF00}»{FFFFFF} Reparo de veículo \n");
	strcat(txt, "{FFFF00}»{FFFFFF} Virar veículo caso capote-o \n");
	strcat(txt, "{FFFF00}»{FFFFFF} Pintar veículo \n");
	strcat(txt, "{FFFF00}»{FFFFFF} Tunar veículo \n");
	strcat(txt, "{FFFF00}»{FFFFFF} Colete \n");
	strcat(txt, "{FFFF00}»{FFFFFF} Jetpack \n");
	strcat(txt, "{FFFF00}»{FFFFFF} Tag VIP acima da skin \n");
    strcat(txt, "{FFFF00}»{FFFFFF} Chat exclusivo VIP \n");
    strcat(txt, "{FFFF00}»{FFFFFF} UP 3/3 experiências \n");
    strcat(txt, "{FFFF00}»{FFFFFF} Não paga kit arena \n");
    strcat(txt, "{FFFF00}»{FFFFFF} Salário VIP \n");
	ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FFFFFF}Vantagens VIP", txt, "Fechar", "");
	return 1;
}
CMD:comandosvip(playerid)
{
    new txt[1000];
    strcat(txt, "{FFFFFF}» {FFFF00}/Neon {FFFFFF}- Adicione luzes personalizada em seu veículo \n");
    strcat(txt, "{FFFFFF}» {FFFF00}/Jetpack {FFFFFF}- Para pegar uma mochila a jato \n");
	strcat(txt, "{FFFFFF}» {FFFF00}/Colete {FFFFFF}- Para pegar um colete \n");
	strcat(txt, "{FFFFFF}» {FFFF00}/Virar {FFFFFF}- Para virar seu veículo \n");
	strcat(txt, "{FFFFFF}» {FFFF00}/Pintar {FFFFFF}- Para pintar o seu veículo \n");
	strcat(txt, "{FFFFFF}» {FFFF00}/Tunar {FFFFFF}- Para tunar o seu veículo \n");
	strcat(txt, "{FFFFFF}» {FFFF00}/Paintjob {FFFFFF}- Para personalizar a pintura do seu veículo \n");
	strcat(txt, "{FFFFFF}» {FFFF00}/Tag {FFFFFF}- Para mudar a cor da TAG [VIP] \n");
	strcat(txt, "{FFFFFF}» {FFFF00}/V {FFFFFF}- Chat exclusivo VIP \n");
    strcat(txt, "{FFFFFF}» {FFFF00}/VOn {FFFFFF}- Ligue o chat VIP \n");
    strcat(txt, "{FFFFFF}» {FFFF00}/VOff {FFFFFF}- Desligue o chat VIP \n");
    strcat(txt, "{FFFFFF}» {FFFF00}/Vencimento {FFFFFF}- Para ver o dia do vencimento do seu vip \n");
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
CMD:toplevel(playerid)
{
    new playerScores[MAX_PLAYERS][rankingEnum], index, string[1000];

    for(new i; i != MAX_PLAYERS; ++i)
    {
      	if(!IsPlayerNPC(i) && PlayerInfo[i][Logado])
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
CMD:admins(playerid)
{
    new Counts, STR[1400], STX[50], adminon;
    new const Ranks[][] =
    {
        "{804000}Estagiário(a)",
        "{FFFF00}Ajudante",
        "{FF8C00}Moderador(a)",
        "{008bce}Admininstrador(a)",
        "{FF0000}Cordenador(a)",
        "{328E0A}Desenvolvedor(a)"
    };

    for(new x = 0; x < MAX_PLAYERS; x++)
    {
        if(IsPlayerIntern(x) && PlayerInfo[x][Logado])
        {
            format(STR, 1400, "%s {FFFFFF}%s \t%s \t{1B6302}Online\n", STR, PlayerInfo[x][Nome], Ranks[PlayerInfo[x][Admin] - 1]);
            adminon++;
        }
        Counts++;
    }

    if(adminon == 0)
    {
        ShowPlayerDialog(playerid, 5000, DIALOG_STYLE_MSGBOX, "{FFFFFF}Admins Online [ {FF0000}0{FFFFFF} ]", "{FF0000}Náo há administrador ( ADM ) online no momento!", "Fechar", #);
    }
    else
    {
        format(STX, 200, "{FFFFFF}Admins Online [ {328E0A}%d{FFFFFF} ]", adminon);
        ShowPlayerDialog(playerid, 500, DIALOG_STYLE_LIST, STX, STR, "Fechar", #);
    }
    return 1;
}
CMD:presos(playerid)
{
    if(!(IsPlayerInRangeOfPoint(playerid, 2.0, 248.9497, 67.6059, 1003.6406)  || IsPlayerInRangeOfPoint(playerid, 2.0, 252.1618, 67.7849, 1003.6478)))
        return SendClientMessage(playerid, Erro, "Você não está em nenhum departamento de polícia");

    new _str[1400], _stx[50], presoson, hours, minutes, seconds;

    for(new x = 0; x < MAX_PLAYERS; x++)
    {
        if(PrisonEnum[x][pTempo] && PlayerInfo[x][Logado])
        {
            formatSeconds(PrisonEnum[x][pTempo], hours, minutes, seconds);
            format(_str, 1400, "%s{FFFFFF} %s{FFFFFF}[%d] \t%02d:%02d:%02d \t{C50000}%s \n", _str, PlayerInfo[x][Nome], x, hours, minutes, seconds, PrisonEnum[x][pCadeia]);
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
    else if(IceCreamOffer[playerid])
    {
        IceCreamOffer[playerid] = false;
        IceCreamAccepted[playerid] = true;
        return 1;
    }
    else if(ParamedicOffer[playerid])
    {
        ParamedicOffer[playerid] = false;
        ParamedicAccepted[playerid] = true;
        return 1;
    }
    else
    {
        SendClientMessage(playerid, Erro, "Você não recebeu nenhuma oferta");
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
    else if(IceCreamOffer[playerid])
    {
        IceCreamOffer[playerid] = false;
        IceCreamRefused[playerid] = true;
        return 1;
    }
    else if(ParamedicOffer[playerid])
    {
        ParamedicOffer[playerid] = false;
        ParamedicRefused[playerid] = true;
        return 1;
    }
    else
    {
        SendClientMessage(playerid, Erro, "Você não recebeu nenhuma oferta");
    }
    return 1;
}
CMD:advogados(playerid)
{
    new _str[1400], advon = 0;

    for(new x = 0; x < MAX_PLAYERS; x++)
    {
        if(PlayerInfo[x][Profissao] == lawyer && PlayerInfo[x][Logado] == true)
        {
            format(_str, sizeof(_str), "%s{8000FF} %s{FFFFFF} [%d] \n", _str, PlayerInfo[x][Nome], x);
            advon++;
        }
    }

    if(advon == 0)
    {
        ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FFFFFF}Advogados Online [ {FF0000}0{FFFFFF} ]", "{FF0000}Náo há advogados online no momento!", "Fechar", #);
    }
    else
    {
        format(String, sizeof(String), "{FFFFFF}Advogados Online [ {328E0A}%d{FFFFFF} ]", advon);
        ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, String, _str, "Fechar", #);
    }
    return 1;
}
CMD:advogado(playerid, params[])
{
    if(!PrisonEnum[playerid][pTempo])
        return SendClientMessage(playerid, Erro, "Você não está preso para poder contatar um advogado(a)");

    new id, tmp[128];

    if(sscanf(params, "us[128]", id, tmp))
        return SendClientMessage(playerid, Erro, "Digite: /Advogado [id/nome] [mensagem]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    if(PlayerInfo[id][Profissao] != lawyer)
        return SendClientMessage(playerid, Erro, "Jogador(a) não é advogado(a)");

    format(String,sizeof(String), "Mensagem enviada para o advogado(a) %s[%d] ( %s )", PlayerInfo[id][Nome], id, tmp);
    SendClientMessage(playerid, 0x8000FFAA, String);
    format(String,sizeof(String), "Mensagem recebida do presidiário %s[%d] ( %s )", PlayerInfo[playerid][Nome], playerid, tmp);
    SendClientMessage(id, 0x8000FFAA, String);
    return 1;
}
CMD:vips(playerid)
{
    new txt[3000], j = 0;

    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerVip(i) && PlayerInfo[i][Logado])
        {
            format(txt, sizeof(txt), "%s {FFFFFF}%s[%d] \n", txt, PlayerInfo[i][Nome], i);
            j++;
        }
    }

    if(!j)
        return ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Vips", "{FFFFFF}Não tem vips online no momento", "Fechar", #);

    ShowPlayerDialog(playerid, vipss, DIALOG_STYLE_LIST, "{FF0000}Vips", txt, "Fechar", #);
    return 1;
}
CMD:transferir(playerid, params[])
{
    if(BlockTransfer[playerid])
        return SendClientMessage(playerid, Erro, "Você acabou de transferir, aguarde alguns minutos...");

    new id, value;

    if(sscanf(params, "dd", id, value))
        return SendClientMessage(playerid, Erro, "Digite: /Transferir [id] [valor]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não está conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    if(GetDistanceBetweenPlayers(playerid, id) > 10)
        return SendClientMessage(playerid, Erro, "Você está muito longe, chegue mais perto");

    if(value < 1 || value > 50000)
        return SendClientMessage(playerid, Erro, "Valores apenas de $1 até $50.000");

    PlayerInfo[playerid][Dinheiro] -= value;
    UpdatePlayerMoney(playerid);
    PlayerInfo[id][Dinheiro] += value;
    UpdatePlayerMoney(id);

    format(String, sizeof(String), "Transferência de $%s para o jogador(a) %s[%d]", IsMoney(value, "."), PlayerInfo[id][Nome], id);
    SendClientMessage(playerid, Yellow, String);
    format(String, sizeof(String), "O(A) Jogador(a) %s[%d] transferiu $%s para você", PlayerInfo[playerid][Nome], playerid, IsMoney(value, "."));
    SendClientMessage(id, Yellow, String);

    BlockTransfer[playerid] = true;
    SetTimerEx("UnlockTransfer", 300000, false, "d", playerid);
    return 1;
}
