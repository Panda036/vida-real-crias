#include YSI\y_hooks

new bank_name[MAX_PLAYER_NAME][MAX_PLAYERS];

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(PRESSED(KEY_YES))
    {
        if(IsPlayerInRangeOfPoint(playerid, 1.0, 354.45, 164.66, 1019.98) || IsPlayerInRangeOfPoint(playerid, 1.0, 356.30, 164.72, 1019.99))
        {
            ShowPlayerDialog(playerid, bank, DIALOG_STYLE_LIST, "{FF0000}Banco", "{FFFFFF}Saldo \nSaque \nDeposito \nTransferência", "Selecionar", "Cancelar");
        }
        return 1;
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

            if(strval(inputtext) > PlayerInfo[playerid][SaldoBancario])
                return ShowPlayerDialog(playerid, bank_draft, DIALOG_STYLE_INPUT, "{00A800}Saque Bancário", "{FFFFFF}Digite abaixo o valor do saque: \n\n{FF4000}Erro, você digitou um valor maior que seu saldo bancário!", "Sacar", "Voltar");

            PlayerInfo[playerid][SaldoBancario] -= strval(inputtext);
            PlayerInfo[playerid][Dinheiro] += strval(inputtext);

            SetIntQuery(playerid, "Identidade", "SaldoBancario", PlayerInfo[playerid][SaldoBancario]);
            UpdatePlayerMoney(playerid);

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

            if(strval(inputtext) > PlayerInfo[playerid][Dinheiro])
                return ShowPlayerDialog(playerid, bank_deposit, DIALOG_STYLE_INPUT, "{00A800}Depósito Bancário", "{FFFFFF}Digite abaixo o valor do deposito: \n\n{FF4000}Erro, você digitou um valor maior que seu dinheiro em mões!", "Depositar", "Voltar");

            PlayerInfo[playerid][SaldoBancario] += strval(inputtext);
            PlayerInfo[playerid][Dinheiro] -= strval(inputtext);

            SetIntQuery(playerid, "Identidade", "SaldoBancario", PlayerInfo[playerid][SaldoBancario]);
            UpdatePlayerMoney(playerid);

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

                PlayerInfo[playerid][SaldoBancario] -= strval(inputtext);
                SetIntQuery(playerid, "Identidade", "SaldoBancario", PlayerInfo[playerid][SaldoBancario]);

                PlayerInfo[id][SaldoBancario] += strval(inputtext);
                SetIntQuery(id, "Identidade", "SaldoBancario", PlayerInfo[id][SaldoBancario]);

                format(String, MAX_STRING, "O(A) Jogador(a) %s[%d] transferiu para sua conta bancária ( $%s )", PlayerInfo[playerid][Nome], playerid, IsMoney(strval(inputtext), "."));
                SendClientMessage(id, Yellow, String);

                format(String, MAX_STRING, "Você transferiu $%s para o(a) jogador(a) %s[%d]", IsMoney(strval(inputtext), "."), PlayerInfo[id][Nome], id);
                SendClientMessage(playerid, Yellow, String);

                new query[200];
                mysql_format(IDConexao, query, 200, "INSERT INTO `Transfer` (`value`, `date`, `id_received`, `id_contas`) VALUES ('%d', NOW(), '%d', '%d')", strval(inputtext), PlayerInfo[id][ID], PlayerInfo[playerid][ID]);
                mysql_query(IDConexao, query);
                return 1;
            }

            SendClientMessage(playerid, Erro, "O(A) Jogador(a) não está conectado(a)");
            return 1;
        }
    }
    return 1;
}
