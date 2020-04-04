#include YSI\y_hooks

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(PRESSED(KEY_YES))
    {
        if(IsPlayerInRangeOfPoint(playerid, 1.0, 354.45, 164.66, 1019.98) || IsPlayerInRangeOfPoint(playerid, 1.0, 356.30, 164.72, 1019.99))
        {
            ShowPlayerDialog(playerid, DIALOG_BANK, DIALOG_STYLE_LIST, "{FF0000}Banco", "{FFFFFF}Saldo \nSaque \nDeposito", "Selecionar", "Cancelar");
        }
        return 1;
    }
	return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == DIALOG_BANK)
    {
        if(!response) return 0;

        if(listitem == 0)
        {
            format(String, sizeof(String), "{FFFFFF}Nick: {FF0000}%s \n\n{FFFFFF}Saldo: {008000}$%s \n", PlayerInfo[playerid][Nome], IsMoney(PlayerInfo[playerid][SaldoBancario], "."));
            ShowPlayerDialog(playerid, bank_balance, DIALOG_STYLE_MSGBOX, "{00A800}Saldo Bancario", String, "Fechar", #);
        }
        if(listitem == 1)
        {
            ShowPlayerDialog(playerid, bank_draft, DIALOG_STYLE_INPUT, "{00A800}Saque Bancario", "{FFFFFF}Digite abaixo o valor do saque:", "Sacar", "Voltar");
        }
        if(listitem == 2)
        {
            ShowPlayerDialog(playerid, bank_deposit, DIALOG_STYLE_INPUT, "{00A800}Deposito Bancario", "{FFFFFF}Digite abaixo o valor do deposito:", "Depositar", "Voltar");
        }
        return 1;
    }
    if(dialogid == bank_draft)
    {
        if(!response)
            return ShowPlayerDialog(playerid, DIALOG_BANK, DIALOG_STYLE_LIST, "{FF0000}Banco", "{FFFFFF}Saldo \nSaque \nDeposito", "Selecionar", "Cancelar");

        if(response)
        {
            if(!IsNumeric(inputtext))
                return ShowPlayerDialog(playerid, bank_draft, DIALOG_STYLE_INPUT, "{00A800}Saque Bancário", "{FFFFFF}Digite abaixo o valor do saque: \n\n{FF0000}Erro, digite somente números!", "Sacar", "Voltar");

            if(strval(inputtext) > PlayerInfo[playerid][SaldoBancario])
                return ShowPlayerDialog(playerid, bank_draft, DIALOG_STYLE_INPUT, "{00A800}Saque Bancário", "{FFFFFF}Digite abaixo o valor do saque: \n\n{FF0000}Erro, você digitou um valor maior que seu saldo bancário!", "Sacar", "Voltar");

            new saldo = PlayerInfo[playerid][SaldoBancario];
            PlayerInfo[playerid][SaldoBancario] -= strval(inputtext);
            PlayerInfo[playerid][Dinheiro] += strval(inputtext);
            UpdatePlayerMoney(playerid);

            mysql_format(IDConexao, String, sizeof(String), "UPDATE `Identidade` SET `Dinheiro`='%d', `SaldoBancario`='%d' WHERE `ID`='%d'", PlayerInfo[playerid][Dinheiro], PlayerInfo[playerid][SaldoBancario], PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, String);

            format(String, sizeof(String), "{FFFFFF}Nick: {FF0000}%s \n\n{FFFFFF}Saldo Antigo: {008000}$%s \n{FFFFFF}Saldo Atual: {FF4000}$%s\n{FFFFFF}Valor Sacado: {FFFF00}$%s", PlayerInfo[playerid][Nome], IsMoney(saldo, "."), IsMoney(PlayerInfo[playerid][SaldoBancario], "."), IsMoney(strval(inputtext), "."));
            ShowPlayerDialog(playerid, bank_balance, DIALOG_STYLE_MSGBOX, "{00A800}Saque Bancario", String, "Fechar", #);
        }
        return 1;
    }
    if(dialogid == bank_deposit)
    {
        if(!response)
            return ShowPlayerDialog(playerid, DIALOG_BANK, DIALOG_STYLE_LIST, "{FF0000}Banco", "{FFFFFF}Saldo \nSaque \nDeposito", "Selecionar", "Cancelar");

        if(response)
        {
            if(!IsNumeric(inputtext))
                return ShowPlayerDialog(playerid, bank_deposit, DIALOG_STYLE_INPUT, "{00A800}Deposito Bancario", "{FFFFFF}Digite abaixo o valor do deposito: \n\n{FF0000}Erro, digite somente números!", "Depositar", "Voltar");

            if(strval(inputtext) > PlayerInfo[playerid][Dinheiro])
                return ShowPlayerDialog(playerid, bank_deposit, DIALOG_STYLE_INPUT, "{00A800}Deposito Bancario", "{FFFFFF}Digite abaixo o valor do deposito: \n\n{FF0000}Erro, você digitou um valor maior que seu dinheiro em mões!", "Depositar", "Voltar");

            new saldo = PlayerInfo[playerid][SaldoBancario];
            PlayerInfo[playerid][SaldoBancario] += strval(inputtext);
            PlayerInfo[playerid][Dinheiro] -= strval(inputtext);
            GivePlayerMoney(playerid, -strval(inputtext));

            mysql_format(IDConexao, String, sizeof(String), "UPDATE `Identidade` SET `Dinheiro`='%d', `SaldoBancario`='%d' WHERE `ID`='%d'", PlayerInfo[playerid][Dinheiro], PlayerInfo[playerid][SaldoBancario], PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, String);

            format(String, sizeof(String), "{FFFFFF}Nick: {FF0000}%s \n\n{FFFFFF}Saldo Antigo: {008000}$%s \n{FFFFFF}Saldo Atual: {FF4000}$%s\n{FFFFFF}Valor Sacado: {FFFF00}$%s", PlayerInfo[playerid][Nome], IsMoney(saldo, "."), IsMoney(PlayerInfo[playerid][SaldoBancario], "."), IsMoney(strval(inputtext), "."));
            ShowPlayerDialog(playerid, bank_balance, DIALOG_STYLE_MSGBOX, "{00A800}Saque Bancario", String, "Fechar", #);
        }
        return 1;
    }
    return 1;
}
