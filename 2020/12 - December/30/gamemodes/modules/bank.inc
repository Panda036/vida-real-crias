#include YSI\y_hooks

new bank_name[MAX_PLAYER_NAME][MAX_PLAYERS];
new laserBank[10];
new hackingBank;
new hackBank;

hook OnGameModeInit()
{
    new textWallBank = CreateDynamicObject(19353, 918.80920, 1646.01721, 1102.85974, 0.00000, 0.00000, 0.00000);
    SetDynamicObjectMaterialText(textWallBank, 0, "{1B6302}VRC Bank", 50, "Arial", 15, 1, 0x1B6302AA, 0, 1);

    new wallBank[4];
    wallBank[0] = CreateDynamicObject(19376, 904.83020, 1641.18958, 1101.77368, 0.00000, 0.00000, 0.00000);
    wallBank[1] = CreateDynamicObject(19376, 904.82678, 1650.77563, 1101.77368, 0.00000, 0.00000, 0.00000);
    wallBank[2] = CreateDynamicObject(19376, 925.65997, 1650.79529, 1101.77368, 0.00000, 0.00000, 0.00000);
    wallBank[3] = CreateDynamicObject(19376, 925.65833, 1641.20947, 1101.77368, 0.00000, 0.00000, 0.00000);

    laserBank[0] = CreateDynamicObject(18643, 922.16400, 1649.57666, 1100.50000, 0.00000, 0.00000, 0.00000);
    laserBank[1] = CreateDynamicObject(18643, 922.16400, 1649.57666, 1101.00000, 0.00000, 0.00000, 0.00000);
    laserBank[2] = CreateDynamicObject(18643, 922.16400, 1649.57666, 1101.50000, 0.00000, 0.00000, 0.00000);
    laserBank[3] = CreateDynamicObject(18643, 922.16400, 1649.57666, 1102.00000, 0.00000, 0.00000, 0.00000);
    laserBank[4] = CreateDynamicObject(18643, 922.16400, 1649.57666, 1102.50000, 0.00000, 0.00000, 0.00000);
    laserBank[5] = CreateDynamicObject(18643, 922.16400, 1649.57666, 1103.00000, 0.00000, 0.00000, 0.00000);
    laserBank[6] = CreateDynamicObject(18643, 922.16400, 1649.57666, 1104.00000, 0.00000, 0.00000, 0.00000);
    laserBank[7] = CreateDynamicObject(18643, 922.16400, 1649.57666, 1103.50000, 0.00000, 0.00000, 0.00000);
    laserBank[8] = CreateDynamicObject(18643, 922.16400, 1649.57666, 1104.50000, 0.00000, 0.00000, 0.00000);
    laserBank[9] = CreateDynamicObject(18643, 922.16400, 1649.57666, 1105.00000, 0.00000, 0.00000, 0.00000);

    for(new i = 0; i < sizeof(wallBank); i++){
        SetDynamicObjectMaterial(wallBank[i], 0, 10765, "airportgnd_sfse", "white", 0);
    }

    //Alarme
    CreateDynamicObject(19273, 921.36761, 1649.72351, 1101.63403, 0.00000, 0.00000, 180.00000);

    CreateDynamicObject(19376, 909.98608, 1641.20959, 1100.00000, 0.00000, 90.00000, 0.00000);
    CreateDynamicObject(19376, 909.98608, 1650.84094, 1100.00000, 0.00000, 90.00000, 0.00000);
    CreateDynamicObject(19376, 920.47137, 1641.20959, 1100.00000, 0.00000, 90.00000, 0.00000);
    CreateDynamicObject(19376, 920.47137, 1650.84094, 1100.00000, 0.00000, 90.00000, 0.00000);
    CreateDynamicObject(19449, 922.46863, 1655.41333, 1106.03235, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(19449, 922.46863, 1655.40503, 1099.26013, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(19379, 920.49139, 1641.18958, 1105.49524, 0.00000, 90.00000, 0.00000);
    CreateDynamicObject(19379, 909.99902, 1641.20959, 1105.49524, 0.00000, 90.00000, 0.00000);
    CreateDynamicObject(19379, 920.49139, 1650.79529, 1105.49524, 0.00000, 90.00000, 0.00000);
    CreateDynamicObject(19379, 910.00000, 1650.79529, 1105.49524, 0.00000, 90.00000, 0.00000);
    CreateDynamicObject(19449, 912.84979, 1655.41333, 1099.26013, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(19449, 903.19562, 1655.38330, 1106.03198, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(19449, 903.21271, 1655.41907, 1099.26013, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(19449, 912.84979, 1655.41333, 1106.03198, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(1649, 917.32349, 1655.40613, 1102.66589, 0.00000, 0.00000, 0.00000);
    CreateDynamicObject(1649, 912.89563, 1655.41907, 1102.66589, 0.00000, 0.00000, 0.00000);
    CreateDynamicObject(1649, 908.52557, 1655.40503, 1102.66589, 0.00000, 0.00000, 0.00000);
    CreateDynamicObject(1649, 921.75079, 1655.40503, 1102.66589, 0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19449, 904.54822, 1655.41907, 1102.19373, 90.00000, 90.00000, 0.00000);
    CreateDynamicObject(19449, 925.74591, 1655.41907, 1102.19373, 90.00000, 90.00000, 0.00000);
    CreateDynamicObject(19449, 922.46863, 1636.60693, 1106.03235, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(19449, 922.46863, 1636.60693, 1099.26013, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(19449, 912.84979, 1636.60693, 1099.26013, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(19449, 903.21271, 1636.60693, 1099.26013, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(19449, 912.84979, 1636.60693, 1106.03198, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(19449, 903.19562, 1636.60693, 1106.03198, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(1649, 908.52557, 1636.60693, 1102.66589, 0.00000, 0.00000, 180.00000);
    CreateDynamicObject(1649, 912.89563, 1636.60693, 1102.66589, 0.00000, 0.00000, 180.00000);
    CreateDynamicObject(1649, 917.34192, 1636.59912, 1102.66589, 0.00000, 0.00000, 180.00000);
    CreateDynamicObject(1649, 921.75079, 1636.60693, 1102.66589, 0.00000, 0.00000, 180.00000);
    CreateDynamicObject(19449, 925.74591, 1636.60693, 1102.19373, 90.00000, 90.00000, 0.00000);
    CreateDynamicObject(19449, 904.54822, 1636.60693, 1102.19373, 90.00000, 90.00000, 0.00000);
    CreateDynamicObject(1501, 905.00000, 1644.51074, 1100.08130, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(1501, 904.96997, 1647.52405, 1100.08130, 0.00000, 0.00000, -90.00000);
    CreateDynamicObject(2008, 914.47028, 1646.65259, 1100.02734, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(2008, 914.47028, 1644.56604, 1100.02734, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(1892, 914.25201, 1650.85229, 1100.08472, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(1892, 914.25201, 1640.12207, 1100.08472, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(1427, 914.01813, 1648.80713, 1100.58679, 0.00000, 0.00000, 110.00000);
    CreateDynamicObject(1427, 914.07770, 1649.93213, 1100.58679, 0.00000, 0.00000, -110.00000);
    CreateDynamicObject(1422, 914.42297, 1653.95203, 1100.40649, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(1422, 914.42297, 1638.17017, 1100.40649, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(1427, 914.01813, 1642.15649, 1100.58679, 0.00000, 0.00000, 110.00000);
    CreateDynamicObject(1427, 914.07770, 1643.48523, 1100.58679, 0.00000, 0.00000, -110.00000);
    CreateDynamicObject(2332, 919.35419, 1643.66016, 1100.46606, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(2332, 919.36761, 1643.66016, 1101.34607, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(2332, 919.35419, 1645.29346, 1100.46606, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(2332, 919.35419, 1645.29346, 1101.34607, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(2332, 919.35419, 1646.94617, 1100.46606, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(2332, 919.35419, 1646.94617, 1101.34595, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(2332, 919.35419, 1648.56848, 1100.46606, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(2332, 919.35419, 1648.56848, 1101.34595, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(19449, 918.82001, 1647.75623, 1101.82007, 90.00000, 0.00000, 0.00000);
    CreateDynamicObject(19449, 918.82001, 1644.26941, 1101.82007, 90.00000, 0.00000, 0.00000);
    CreateDynamicObject(19449, 920.46460, 1649.59375, 1101.82007, 90.00000, 90.00000, 0.00000);
    CreateDynamicObject(19449, 920.48523, 1642.44385, 1101.82007, 90.00000, 90.00000, 0.00000);
    CreateDynamicObject(19449, 923.98499, 1642.44385, 1101.82007, 90.00000, 90.00000, 0.00000);
    CreateDynamicObject(2267, 904.93628, 1651.13098, 1102.58569, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(19173, 904.92023, 1640.62732, 1102.55090, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(1763, 905.80347, 1640.12878, 1100.08496, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(1702, 910.03601, 1637.89453, 1100.08508, 0.00000, 0.00000, 180.00000);
    CreateDynamicObject(11737, 906.26257, 1645.21484, 1100.08472, 0.00000, 0.00000, -90.00000);
    CreateDynamicObject(11737, 906.26257, 1646.73291, 1100.08472, 0.00000, 0.00000, -90.00000);

    CreateDynamic3DTextLabel("Precione \"{1B6302}Y{FFFFFF}\"\n{FFFFFF}Para Acessar o Banco", 0xFFFFFFFF, 912.00, 1647.00, 1101.00, 30.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, WORLD_DEFAULT, 0);
    CreateDynamic3DTextLabel("Precione \"{1B6302}Y{FFFFFF}\"\n{FFFFFF}Para Acessar o Banco", 0xFFFFFFFF, 912.00, 1645.00, 1101.00, 30.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, WORLD_DEFAULT, 0);

    CreateDynamicPickup(1274, 1, 912.00, 1647.00, 1101.00);
    CreateDynamicPickup(1274, 1, 912.00, 1645.00, 1101.00);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    SetTimerEx("OnPlayerBankAreaRestricted", 1000, true, "d", playerid);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(PRESSED(KEY_YES))
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 912.00, 1647.00, 1101.00) || IsPlayerInRangeOfPoint(playerid, 2.0, 912.00, 1647.00, 1101.00))
            return ShowPlayerDialog(playerid, bank, DIALOG_STYLE_LIST, "{FF0000}Banco", "{FFFFFF}Saldo \nSaque \nDeposito \nTransferência", "Selecionar", "Cancelar");
    }
	return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case bank:
        {
            if(!response) return 0;

            switch(listitem)
            {
                case 0:
                {
                    format(String, 200, "{FFFFFF}Nick: {FF0000}%s \n\n{FFFFFF}Saldo: {008000}$%s \n", PlayerInfo[playerid][Nome], IsMoney(PlayerInfo[playerid][SaldoBancario], "."));
                    ShowPlayerDialog(playerid, bank_balance, DIALOG_STYLE_MSGBOX, "{00A800}Saldo Bancario", String, "Fechar", #);
                }
                case 1: ShowPlayerDialog(playerid, bank_draft, DIALOG_STYLE_INPUT, "{00A800}Saque Bancário", "{FFFFFF}Digite abaixo o valor do saque:", "Sacar", "Voltar");
                case 2: ShowPlayerDialog(playerid, bank_deposit, DIALOG_STYLE_INPUT, "{00A800}Depósito Bancário", "{FFFFFF}Digite abaixo o valor do deposito:", "Depositar", "Voltar");
                case 3: ShowPlayerDialog(playerid, bank_transfer, DIALOG_STYLE_INPUT, "{00A800}Transferência Bancária", "{FFFFFF}Digite abaixo o nome do Jogador(a):", "Próximo", "Voltar");
            }
            return 1;
        }
        case bank_draft:
        {
            if(!response)
                return ShowPlayerDialog(playerid, bank, DIALOG_STYLE_LIST, "{FF0000}Banco", "{FFFFFF}Saldo \nSaque \nDeposito", "Selecionar", "Cancelar");

            if(!IsNumeric(inputtext))
                return ShowPlayerDialog(playerid, bank_draft, DIALOG_STYLE_INPUT, "{00A800}Saque Bancário", "{FFFFFF}Digite abaixo o valor do saque: \n\n{FF4000}Erro, digite somente números!", "Sacar", "Voltar");

            if(strval(inputtext) < 1 || strval(inputtext) > PlayerInfo[playerid][SaldoBancario])
                return ShowPlayerDialog(playerid, bank_draft, DIALOG_STYLE_INPUT, "{00A800}Saque Bancário", "{FFFFFF}Digite abaixo o valor do saque: \n\n{FF4000}Erro, você digitou um valor maior que seu saldo bancário!", "Sacar", "Voltar");

            PlayerInfo[playerid][SaldoBancario] -= strval(inputtext);
            PlayerInfo[playerid][Dinheiro] += strval(inputtext);

            UpdatePlayerMoney(playerid);
            SetIntQuery(playerid, "Identidade", "saldobancario", PlayerInfo[playerid][SaldoBancario]);

            format(String, 200, "{FFFFFF}Nick: {FF0000}%s \n\n{FFFFFF}Saldo Antigo: {008000}$%s \n{FFFFFF}Saldo Atual: {FF4000}$%s\n{FFFFFF}Valor Sacado: {FFFF00}$%s", PlayerInfo[playerid][Nome], IsMoney((PlayerInfo[playerid][SaldoBancario] + strval(inputtext)) , "."), IsMoney(PlayerInfo[playerid][SaldoBancario], "."), IsMoney(strval(inputtext), "."));

            ShowPlayerDialog(playerid, bank_balance, DIALOG_STYLE_MSGBOX, "{00A800}Saque Bancario", String, "Fechar", #);
            return 1;
        }
        case bank_deposit:
        {
            if(!response)
                return ShowPlayerDialog(playerid, bank, DIALOG_STYLE_LIST, "{FF0000}Banco", "{FFFFFF}Saldo \nSaque \nDeposito", "Selecionar", "Cancelar");

            if(!IsNumeric(inputtext))
                return ShowPlayerDialog(playerid, bank_deposit, DIALOG_STYLE_INPUT, "{00A800}Depósito Bancário", "{FFFFFF}Digite abaixo o valor do deposito: \n\n{FF4000}Erro, digite somente números!", "Depositar", "Voltar");

            if(strval(inputtext) < 1 || strval(inputtext) > PlayerInfo[playerid][Dinheiro])
                return ShowPlayerDialog(playerid, bank_deposit, DIALOG_STYLE_INPUT, "{00A800}Depósito Bancário", "{FFFFFF}Digite abaixo o valor do deposito: \n\n{FF4000}Erro, você digitou um valor maior que seu dinheiro em mões!", "Depositar", "Voltar");

            PlayerInfo[playerid][SaldoBancario] += strval(inputtext);
            PlayerInfo[playerid][Dinheiro] -= strval(inputtext);

            UpdatePlayerMoney(playerid);
            SetIntQuery(playerid, "Identidade", "saldobancario", PlayerInfo[playerid][SaldoBancario]);

            format(String, 200, "{FFFFFF}Nick: {FF0000}%s \n\n{FFFFFF}Saldo Antigo: {008000}$%s \n{FFFFFF}Saldo Atual: {FF4000}$%s\n{FFFFFF}Valor Depositado: {FFFF00}$%s", PlayerInfo[playerid][Nome], IsMoney((PlayerInfo[playerid][SaldoBancario] - strval(inputtext)), "."), IsMoney(PlayerInfo[playerid][SaldoBancario], "."), IsMoney(strval(inputtext), "."));

            ShowPlayerDialog(playerid, bank_balance, DIALOG_STYLE_MSGBOX, "{00A800}Depósito Bancário", String, "Fechar", #);
            return 1;
        }
        case bank_transfer:
        {
            if(!response)
                return ShowPlayerDialog(playerid, bank, DIALOG_STYLE_LIST, "{FF0000}Banco", "{FFFFFF}Saldo \nSaque \nDeposito", "Selecionar", "Cancelar");

            new id = GetPlayerID(inputtext);

            if(id == INVALID_PLAYER_ID)
                return SendClientMessage(playerid, Erro, "O(A) Jogador(a) não está conectado(a)");

            if(id == playerid)
                return SendClientMessage(playerid, Erro, "Não é possível transferir para sí mesmo!");

            format(bank_name[playerid], MAX_PLAYER_NAME, PlayerInfo[id][Nome]);

            format(String, 200, "{FFFFFF}Digite abaixo o valor da sua transfência para o(a) jogador(a) %s[%d]:", PlayerInfo[id][Nome], id);
            ShowPlayerDialog(playerid, bank_transfer_value, DIALOG_STYLE_INPUT, "{00A800}Transferência Bancária", String, "Próximo", "Cancelar");
            return 1;
        }
        case bank_transfer_value:
        {
            if(!response)
                return SendClientMessage(playerid, Erro, "Transferência cancelada");

            new t_transactionbox = GetIntQuery(playerid, "Timers", "transactionbox");

            if((gettime() - t_transactionbox) < 3600)
            {
                new days, hours, minutes, seconds;

                TimeConvertEx(3600 - (gettime() - t_transactionbox), days, hours, minutes, seconds);

                if(minutes)
                    format(String, 128, "Você acabou de transferir, aguarde %d minuto e %d segundos...", minutes, seconds);
                else
                    format(String, 128, "Você acabou de transferir, aguarde %d segundos...", seconds);

                SendClientMessage(playerid, Erro, String);
                return 1;
            }

            for(new id = 0; id < MAX_PLAYERS; id++)
            {
                if(!PlayerInfo[id][Logado]) continue;

                if(strcmp(bank_name[playerid], PlayerInfo[id][Nome])) continue;

                if(!IsNumeric(inputtext))
                {
                    format(String, 200, "{FFFFFF}Digite abaixo o valor da sua transfência para o(a) jogador(a) %s[%d]:\n\n{FF4000}Erro, digite somente números!", PlayerInfo[id][Nome], id);
                    ShowPlayerDialog(playerid, bank_transfer_value, DIALOG_STYLE_INPUT, "{00A800}Transferência Bancária", String, "Próximo", "Cancelar");
                    return 1;
                }
                if(strval(inputtext) > PlayerInfo[playerid][SaldoBancario])
                {
                    format(String, 200, "{FFFFFF}Digite abaixo o valor da sua transfência para o(a) jogador(a) %s[%d]:\n\n{FF4000}Erro, você digitou um valor maior que seu saldo bancário!", PlayerInfo[id][Nome], id);
                    ShowPlayerDialog(playerid, bank_transfer_value, DIALOG_STYLE_INPUT, "{00A800}Transferência Bancária", String, "Próximo", "Cancelar");
                    return 1;
                }
                if(strval(inputtext) < 50000 || strval(inputtext) > 1000000)
                {
                    format(String, MAX_STRING, "{FFFFFF}Digite abaixo o valor da sua transfência para o(a) jogador(a) %s[%d]:\n\n{FF4000}Erro, valores apenas de $50.000 até $1.000.000", PlayerInfo[id][Nome], id);
                    ShowPlayerDialog(playerid, bank_transfer_value, DIALOG_STYLE_INPUT, "{00A800}Transferência Bancária", String, "Próximo", "Cancelar");
                    return 1;
                }

                SetIntQuery(playerid, "Timers", "transactionbox", gettime());

                PlayerInfo[playerid][SaldoBancario] -= strval(inputtext);
                SetIntQuery(playerid, "Identidade", "saldobancario", PlayerInfo[playerid][SaldoBancario]);
                PlayerInfo[id][SaldoBancario] += strval(inputtext);
                SetIntQuery(id, "Identidade", "saldobancario", PlayerInfo[id][SaldoBancario]);

                format(String, MAX_STRING, "O(A) Jogador(a) %s[%d] transferiu para sua conta bancária ( $%s )", PlayerInfo[playerid][Nome], playerid, IsMoney(strval(inputtext), "."));
                SendClientMessage(id, Yellow, String);
                format(String, MAX_STRING, "Você transferiu $%s para conta bancária do(a) jogador(a) %s[%d]", IsMoney(strval(inputtext), "."), PlayerInfo[id][Nome], id);
                SendClientMessage(playerid, Yellow, String);

                new query[300];
                mysql_format(IDConexao, query, 300, "INSERT INTO `Transfer` (`value`, `date`, `id_received`, `id_contas`) VALUES ('%d', NOW(), '%d', '%d')", strval(inputtext), PlayerInfo[id][ID], PlayerInfo[playerid][ID]);
                mysql_query(IDConexao, query);
                return 1;
            }

            SendClientMessage(playerid, Erro, "O(A) Jogador(a) não está conectado(a)");
            return 1;
        }
    }
    return 1;
}

forward OnPlayerBankAreaRestricted(playerid);
public OnPlayerBankAreaRestricted(playerid)
{
    new Float:x, Float:y, Float:z;

    GetPlayerPos(playerid, x, y, z);

    if(x >= 919.2560 && y >= 1642.8801 && x <= 925.2238 && y <= 1649.6013)
    {
        if(hackBank != INVALID_PLAYER_ID) return 1;

        SetPlayerFacingAngle(playerid, 180.00);
        SetPlayerPos(playerid, 923.09, 1652.69, 1101.08);
        SendClientMessage(playerid, Erro, "Local restrito, não tente novamente");
        return 1;
    }
    return 1;
}
forward OnPlayerHackingBank(playerid);
public OnPlayerHackingBank(playerid)
{
    SendClientMessage(playerid, Profission[PlayerInfo[playerid][Profissao]][pfs_color], "Sitema hackeado, prossiga com assalto");

    DestroyDynamicObject(laserBank[0]);
    DestroyDynamicObject(laserBank[1]);
    DestroyDynamicObject(laserBank[2]);
    DestroyDynamicObject(laserBank[3]);
    DestroyDynamicObject(laserBank[4]);
    DestroyDynamicObject(laserBank[5]);
    DestroyDynamicObject(laserBank[6]);
    DestroyDynamicObject(laserBank[7]);
    DestroyDynamicObject(laserBank[8]);
    DestroyDynamicObject(laserBank[9]);

    hackingBank = INVALID_PLAYER_ID;
    hackBank = playerid;
    TogglePlayerControllable(playerid, true);
    ClearAnimations(playerid);

    //Sound

    SetTimer("OnBankResetSystem", 120000, false);
    return 1;
}

forward OnBankResetSystem();
public OnBankResetSystem()
{
    format(String, MAX_STRING, "O Sistema do banco foi restaurado após o roubo do ladrão %s[%d]", PlayerInfo[hackBank][Nome], hackBank);
    SendClientMessageToAll(Yellow, String);

    hackBank = INVALID_PLAYER_ID;
    hackingBank = INVALID_PLAYER_ID;

    laserBank[0] = CreateDynamicObject(18643, 922.16400, 1649.57666, 1100.50000, 0.00000, 0.00000, 0.00000);
    laserBank[1] = CreateDynamicObject(18643, 922.16400, 1649.57666, 1101.00000, 0.00000, 0.00000, 0.00000);
    laserBank[2] = CreateDynamicObject(18643, 922.16400, 1649.57666, 1101.50000, 0.00000, 0.00000, 0.00000);
    laserBank[3] = CreateDynamicObject(18643, 922.16400, 1649.57666, 1102.00000, 0.00000, 0.00000, 0.00000);
    laserBank[4] = CreateDynamicObject(18643, 922.16400, 1649.57666, 1102.50000, 0.00000, 0.00000, 0.00000);
    laserBank[5] = CreateDynamicObject(18643, 922.16400, 1649.57666, 1103.00000, 0.00000, 0.00000, 0.00000);
    laserBank[6] = CreateDynamicObject(18643, 922.16400, 1649.57666, 1104.00000, 0.00000, 0.00000, 0.00000);
    laserBank[7] = CreateDynamicObject(18643, 922.16400, 1649.57666, 1103.50000, 0.00000, 0.00000, 0.00000);
    laserBank[8] = CreateDynamicObject(18643, 922.16400, 1649.57666, 1104.50000, 0.00000, 0.00000, 0.00000);
    laserBank[9] = CreateDynamicObject(18643, 922.16400, 1649.57666, 1105.00000, 0.00000, 0.00000, 0.00000);
    return 1;
}
