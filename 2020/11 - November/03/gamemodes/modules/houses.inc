#include YSI\y_hooks

#include modules\database\db_houses

hook OnPlayerDisconnect(playerid, reason)
{
    LastHouseID[playerid] = 0;
    dentrocasa[playerid] = 0;
    HouseContinue[playerid] = false;
    KillTimer(HouseContinueTimer[playerid]);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    new houseid = LastHouseID[playerid];

    if(newkeys == KEY_SECONDARY_ATTACK)
    {
        if(dentrocasa[playerid] == 0 && IsPlayerInRangeOfPoint(playerid, 1.5, HouseInfo[houseid][iconx], HouseInfo[houseid][icony], HouseInfo[houseid][iconz]))
        {
            if(IsPlayerOwnerHouse(playerid, houseid))
            {
                format(String, MAX_STRING, "Bem vindo(a) a Casa ID %d em que você mora, Digite: /MenuCasa para acessar o menu!", HouseInfo[houseid][hID]);
            }
            else
            {
                if(strcmp(HouseInfo[houseid][hTrancada], "Sim", true)==0)
                    return ShowPlayerDialog(playerid, MAIN_HOUSE_PASS, DIALOG_STYLE_INPUT, "{FF0000}Casa trancada", "{FFFFFF}Digite abaixo a senha da casa para entrar", "Entrar", "Cancelar");

                format(String, MAX_STRING, "Bem vindo(a) a Casa ID %d que pertence a %s", HouseInfo[houseid][hID], HouseInfo[houseid][hNome]);
            }

            dentrocasa[playerid] = 1;
            SendClientMessage(playerid, C_PROPERTY, String);
            SetPlayerVirtualWorld(playerid, HouseInfo[houseid][hID]);
            SetPlayerInterior(playerid, HouseInfo[houseid][hInterior]);
            SetPlayerPos(playerid, HouseInfo[houseid][hInteriorX], HouseInfo[houseid][hInteriorY], HouseInfo[houseid][hInteriorZ]);
            return 1;
        }
        else if(dentrocasa[playerid] == 1 && IsPlayerInRangeOfPoint(playerid, 2.0, HouseInfo[houseid][hInteriorX], HouseInfo[houseid][hInteriorY], HouseInfo[houseid][hInteriorZ]))
        {
            dentrocasa[playerid] = 0;
            SetPlayerVirtualWorld(playerid, 0);
            SetPlayerInterior(playerid, 0);
            SetPlayerPos(playerid, HouseInfo[houseid][iconx], HouseInfo[houseid][icony], HouseInfo[houseid][iconz]);

            format(String, MAX_STRING, (IsPlayerOwnerHouse(playerid, houseid) ? ("Você saiu da sua casa %s") : ("Você saiu da casa que pertence a %s")), HouseInfo[houseid][hNome]);
            SendClientMessage(playerid, C_PROPERTY, String);
            return 1;
        }
    }
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case MAIN_HOUSE:
        {
            new houseid = LastHouseID[playerid];

            if(!response) return 0;

            if(IsPlayerOwnerHouse(playerid, houseid))
            {
                if(listitem == 0)
                {
                    return ShowPlayerDialog(playerid, MAIN_HOUSE_ALTER_MSG, DIALOG_STYLE_INPUT, "{FFD700}Alterar Mensagem", "{FFFFFF}Digite abaixo a nova mensagem da sua casa", "Selecionar", "Cancelar");
                }
                else if(listitem == 1)
                {
                    return ShowPlayerDialog(playerid, MAIN_HOUSE_ALTER_PASS, DIALOG_STYLE_INPUT, "{FFD700}Alterar Senha", "{FFFFFF}Digite abaixo a nova senha da sua casa", "Selecionar", "Cancelar");
                }
                else if(listitem == 2)
                {
                    if(dentrocasa[playerid] != 1)
                        return SendClientMessage(playerid, Erro, "Você não está em uma casa");

                    if(strcmp(HouseInfo[houseid][hNome], PlayerInfo[playerid][Nome], true))
                        return SendClientMessage(playerid, Erro, "Você não é dono(a)/morador(a) dessa casa");

                    if(strcmp(HouseInfo[houseid][hTrancada], "Sim", true)==0)
                    {
                        format(HouseInfo[houseid][hTrancada], 24, "N/A");
                        format(String, MAX_STRING,"Agora a sua casa está aberta!", inputtext);
                        SendClientMessage(playerid, -1, String);
                    }
                    else if(strcmp(HouseInfo[houseid][hTrancada], "N/A", true)==0)
                    {
                        format(HouseInfo[houseid][hTrancada], 24, "Sim");
                        format(String, MAX_STRING,"Agora a sua casa está fechada com a senha {FF0000}%s", HouseInfo[houseid][hSenha]);
                        SendClientMessage(playerid, -1, String);
                    }

                    UpdateHouseExternal(houseid);
                    UpdateHouses(houseid);
                    return 1;
                }
                else if(listitem == 3)
                {
                    return ShowPlayerDialog(playerid, MAIN_HOUSE_SELF, DIALOG_STYLE_LIST, "{FFD700}Cofre", "{FFFFFF}Adicionar Dinheiro\nRemover Dinheiro", "Selecionar", "Cancelar");
                }
                else if(listitem == 4)
                {
                    new txt[2000];

                    strcat(txt, "{FFFFFF}Lista \t{FFFFFF}Interiores\t{FFFFFF}Preços\n");

                    for(new newup = 0; newup < (21+1); newup++)
                    {
                        switch(newup)
                        {
                            case 1..21:
                            {
                                if(newup > HouseInfo[houseid][hUpMax]) break;

                                if(HouseInfo[houseid][hUp] == newup)
                                {
                                    strcat(txt, "{CCCCCC}Up/Down \t{CCCCCC}Atual\t{CCCCCC}N/A\n");
                                    continue;
                                }

                                new price = ( (newup > HouseInfo[houseid][hUp]) ? ((GetPriceUpHouse(houseid) * (newup-HouseInfo[houseid][hUp]))) : ((GetPriceUpHouse(houseid) * (HouseInfo[houseid][hUp]-newup))) );

                                format(String, 60, "{FFFFFF}%s \t{87CEFF}%d/%d\t%s$%s\n", (newup > HouseInfo[houseid][hUp] ? ("Upgrade") : ("Downgrade")), newup, HouseInfo[houseid][hUpMax], (newup > HouseInfo[houseid][hUp] ? ("{FF4000}-") : ("{1B6302}+")), IsMoney(price, "."));
                                strcat(txt, String);
                            }
                        }
                    }

                    ShowPlayerDialog(playerid, MAIN_HOUSE_UPGRADE, DIALOG_STYLE_TABLIST_HEADERS, "{FFD700}Upgrade/Downgrade", txt, "Selecionar", "Cancelar");
                    return 1;
                }
                else if(listitem == 5)
                {
                    new txt[300];

                    switch(HouseInfo[houseid][hUp])
                    {
                        case 1, 2: ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FFD700}Morador(a)", "{FF4000}Sua casa não tem upgrade necessário para colocar moradores!", "Fechar", #);
                        case 3, 5:
                        {
                            format(String, 50, "{FFFFFF}%s \n", HouseInfo[houseid][hM1]);
                            strcat(txt, String);
                        }
                        case 6, 7, 8:
                        {
                            format(String, 50, "{FFFFFF}%s \n", HouseInfo[houseid][hM1]);
                            strcat(txt, String);
                            format(String, 50, "{FFFFFF}%s \n", HouseInfo[houseid][hM2]);
                            strcat(txt, String);
                        }
                        case 9, 10, 11:
                        {
                            format(String, 50, "{FFFFFF}%s \n", HouseInfo[houseid][hM1]);
                            strcat(txt, String);
                            format(String, 50, "{FFFFFF}%s \n", HouseInfo[houseid][hM2]);
                            strcat(txt, String);
                            format(String, 50, "{FFFFFF}%s \n", HouseInfo[houseid][hM3]);
                        }
                        case 12, 13, 14:
                        {
                            format(String, 50, "{FFFFFF}%s \n", HouseInfo[houseid][hM1]);
                            strcat(txt, String);
                            format(String, 50, "{FFFFFF}%s \n", HouseInfo[houseid][hM2]);
                            strcat(txt, String);
                            format(String, 50, "{FFFFFF}%s \n", HouseInfo[houseid][hM3]);
                            strcat(txt, String);
                            format(String, 50, "{FFFFFF}%s \n", HouseInfo[houseid][hM4]);
                        }
                        case 15, 16, 17:
                        {
                            format(String, 50, "{FFFFFF}%s \n", HouseInfo[houseid][hM1]);
                            strcat(txt, String);
                            format(String, 50, "{FFFFFF}%s \n", HouseInfo[houseid][hM2]);
                            strcat(txt, String);
                            format(String, 50, "{FFFFFF}%s \n", HouseInfo[houseid][hM3]);
                            strcat(txt, String);
                            format(String, 50, "{FFFFFF}%s \n", HouseInfo[houseid][hM4]);
                            strcat(txt, String);
                            format(String, 50, "{FFFFFF}%s \n", HouseInfo[houseid][hM5]);
                            strcat(txt, String);
                        }
                        case 18..21:
                        {
                            format(String, 50, "{FFFFFF}%s \n", HouseInfo[houseid][hM1]);
                            strcat(txt, String);
                            format(String, 50, "{FFFFFF}%s \n", HouseInfo[houseid][hM2]);
                            strcat(txt, String);
                            format(String, 50, "{FFFFFF}%s \n", HouseInfo[houseid][hM3]);
                            strcat(txt, String);
                            format(String, 50, "{FFFFFF}%s \n", HouseInfo[houseid][hM4]);
                            strcat(txt, String);
                            format(String, 50, "{FFFFFF}%s \n", HouseInfo[houseid][hM5]);
                            strcat(txt, String);
                            format(String, 50, "{FFFFFF}%s \n", HouseInfo[houseid][hM6]);
                            strcat(txt, String);
                        }
                    }

                    ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS, DIALOG_STYLE_LIST, "{FFD700}Morador(a)", txt, "Selecionar", "Cancelar");
                    return 1;
                }
                else if(listitem == 6)
                {
                    if(!strcmp(PlayerInfo[playerid][Nome], HouseInfo[houseid][hM1], true) ||
                        !strcmp(PlayerInfo[playerid][Nome], HouseInfo[houseid][hM2], true) ||
                        !strcmp(PlayerInfo[playerid][Nome], HouseInfo[houseid][hM3], true) ||
                        !strcmp(PlayerInfo[playerid][Nome], HouseInfo[houseid][hM4], true) ||
                        !strcmp(PlayerInfo[playerid][Nome], HouseInfo[houseid][hM5], true) ||
                        !strcmp(PlayerInfo[playerid][Nome], HouseInfo[houseid][hM6], true) )
                        return SendClientMessage(playerid, Erro, "Somente dono(a) pode usar essa opção");

                    new txt[200];

                    strcat(txt, "{FF0000}Funções \t\t {1CEB00}Status \n");

                    if(strcmp(HouseInfo[houseid][hVendendo], "Sim", true)==0)
                        { strcat(txt, "{FFFFFF}Vendendo: \t\t Sim\n");  }

                    if(strcmp(HouseInfo[houseid][hVendendo], "N/A", true)==0)
                        { strcat(txt, "{FFFFFF}Vendendo: \t\t Não\n"); }

                    format(String, MAX_STRING, "{FFFFFF}Alterar Valor: \t\t $%s \n", IsMoney(HouseInfo[houseid][hPreco], "."));
                    strcat(txt, String);
                    ShowPlayerDialog(playerid, MAIN_HOUSE_SELL_LIST, DIALOG_STYLE_TABLIST_HEADERS, "{FFD700}Vender Casa", txt, "Selecionar", "Cancelar");
                }
                else if(listitem == 7)
                {
                    ShowPlayerDialog(playerid, MAIN_HOUSE_RELEASE_AGREE, DIALOG_STYLE_INPUT, "{FF0000}Código de Confirmação", "{FFFFFF}Para liberar sua casa para o servidor é necessário o código de confirmação\n\n{FF4000}Obs: o código de vericação é o mesmo usado para registrar sua conta!", "Continuar", "Cancelar");
                    return 1;
                }
            }
            else if(!strcmp(PlayerInfo[playerid][Nome], HouseInfo[houseid][hM1], true))
            {
                if(listitem != 0) return 0;

                format(HouseInfo[houseid][hM1], MAX_PLAYER_NAME, "N/A");
                format(String, MAX_STRING, "Você revougou sua moradia na casa ID %d!", HouseInfo[houseid][hID]);
                SendClientMessage(playerid, C_PROPERTY, String);
                UpdateHouses(houseid);
            }
            else if(!strcmp(PlayerInfo[playerid][Nome], HouseInfo[houseid][hM2], true))
            {
                if(listitem != 0) return 0;

                format(HouseInfo[houseid][hM2], MAX_PLAYER_NAME, "N/A");
                format(String, MAX_STRING, "Você revougou sua moradia na casa ID %d!", HouseInfo[houseid][hID]);
                SendClientMessage(playerid, C_PROPERTY, String);
                UpdateHouses(houseid);
            }
            else if(!strcmp(PlayerInfo[playerid][Nome], HouseInfo[houseid][hM3], true))
            {
                if(listitem != 0) return 0;

                format(HouseInfo[houseid][hM3], MAX_PLAYER_NAME, "N/A");
                format(String, MAX_STRING, "Você revougou sua moradia na casa ID %d!", HouseInfo[houseid][hID]);
                SendClientMessage(playerid, C_PROPERTY, String);
                UpdateHouses(houseid);
            }
            else if(!strcmp(PlayerInfo[playerid][Nome], HouseInfo[houseid][hM4], true))
            {
                if(listitem != 0) return 0;

                format(HouseInfo[houseid][hM4], MAX_PLAYER_NAME, "N/A");
                format(String, MAX_STRING, "Você revougou sua moradia na casa ID %d!", HouseInfo[houseid][hID]);
                SendClientMessage(playerid, C_PROPERTY, String);
                UpdateHouses(houseid);
            }
            else if(!strcmp(PlayerInfo[playerid][Nome], HouseInfo[houseid][hM5], true))
            {
                if(listitem != 0) return 0;

                format(HouseInfo[houseid][hM5], MAX_PLAYER_NAME, "N/A");
                format(String, MAX_STRING, "Você revougou sua moradia na casa ID %d!", HouseInfo[houseid][hID]);
                SendClientMessage(playerid, C_PROPERTY, String);
                UpdateHouses(houseid);
            }
            else if(!strcmp(PlayerInfo[playerid][Nome], HouseInfo[houseid][hM6], true))
            {
                if(listitem != 0) return 0;

                format(HouseInfo[houseid][hM6], MAX_PLAYER_NAME, "N/A");
                format(String, MAX_STRING, "Você revougou sua moradia na casa ID %d!", HouseInfo[houseid][hID]);
                SendClientMessage(playerid, C_PROPERTY, String);
                UpdateHouses(houseid);
            }
            return 1;
        }
        case MAIN_HOUSE_ALTER_MSG:
        {
            new houseid = LastHouseID[playerid];

            if(!response) return 0;

            if(dentrocasa[playerid] == 0)
                return SendClientMessage(playerid, Erro, "Você não está em uma casa");

            if(strcmp(HouseInfo[houseid][hNome], PlayerInfo[playerid][Nome], true))
                return SendClientMessage(playerid, Erro, "Você não é dono(a) dessa casa");

            if(!IsValidMessageHouse(inputtext))
                return ShowPlayerDialog(playerid, MAIN_HOUSE_ALTER_MSG, DIALOG_STYLE_INPUT, "{FFD700}Alterar Mensagem", "{FFFFFF}Digite abaixo a nova mensagem da sua casa \n{FF0000}Alguns caracteres especias não são permitidos!", "Selecionar", "Cancelar");

            format(HouseInfo[houseid][hMensagem], 30, inputtext);
            format(String, MAX_STRING, "Agora a mensagem da sua casa é {FF0000}%s", inputtext);
            SendClientMessage(playerid, -1, String);

            UpdateHouseExternal(houseid);
            UpdateHouses(houseid);
            return 1;
        }
        case MAIN_HOUSE_ALTER_PASS:
        {
            new houseid = LastHouseID[playerid];

            if(!response) return 0;

            if(dentrocasa[playerid] == 0)
                return SendClientMessage(playerid, Erro, "Você não está em uma casa");

            if(strcmp(HouseInfo[houseid][hNome], PlayerInfo[playerid][Nome], true))
                return SendClientMessage(playerid, Erro, "Você não é dono(a) dessa casa");

            if(!IsValidUsername(inputtext))
                return ShowPlayerDialog(playerid, MAIN_HOUSE_ALTER_PASS, DIALOG_STYLE_INPUT, "{FFD700}Alterar Senha", "{FFFFFF}Digite abaixo a nova senha da sua casa \n{FF0000}Alguns caracteres especias não são permitidos!", "Selecionar", "Cancelar");

            format(HouseInfo[houseid][hSenha], 24, inputtext);
            format(String, MAX_STRING, "Agora a senha da sua casa é {FF0000}%s", inputtext);
            SendClientMessage(playerid, -1, String);
            UpdateHouses(houseid);
            return 1;
        }
        case MAIN_HOUSE_RELEASE_AGREE:
        {
            new houseid = LastHouseID[playerid];

            if(!response) return 0;

            if(!strlen(inputtext))
                return ShowPlayerDialog(playerid, MAIN_HOUSE_RELEASE_AGREE, DIALOG_STYLE_INPUT, "{FF0000}Código de Confirmação", "{FFFFFF}Pra liberar sua casa para o servidor é necessário o código de confirmação\n{FF0000}Código Incorreto!\n\n{FF4000}Obs: o código de vericação é o mesmo usado para registrar sua conta!", "Continuar", "Cancelar");

            if(!IsValidCodingAccount(playerid, inputtext))
                return ShowPlayerDialog(playerid, MAIN_HOUSE_RELEASE_AGREE, DIALOG_STYLE_INPUT, "{FF0000}Código de Confirmação", "{FFFFFF}Pra liberar sua casa para o servidor é necessário o código de confirmação\n{FF0000}Código Incorreto!\n\n{FF4000}Obs: o código de vericação é o mesmo usado para registrar sua conta!", "Continuar", "Cancelar");

            if(dentrocasa[playerid] == 0)
                return SendClientMessage(playerid, Erro, "Você não está em uma casa");

            if(strcmp(HouseInfo[houseid][hNome], PlayerInfo[playerid][Nome], true))
                return SendClientMessage(playerid, Erro, "Você não é dono(a) dessa casa");

            if(HouseInfo[houseid][hCofre] != 0)
                return SendClientMessage(playerid, Erro, "Você não removeu o dinheiro do cofre de sua casa");

            PlayerInfo[playerid][Dinheiro] += HouseInfo[houseid][hPadrao];
            UpdatePlayerMoney(playerid);

            if(HouseInfo[houseid][hUpMax] == 3)
            {
                HouseInfo[houseid][hCusto] = 70000;
                HouseInfo[houseid][hPadrao] = 63000;
            }
            else if(HouseInfo[houseid][hUpMax] == 6)
            {
                HouseInfo[houseid][hCusto] = 150000;
                HouseInfo[houseid][hPadrao] = 135000;
            }
            else if(HouseInfo[houseid][hUpMax] == 9)
            {
                HouseInfo[houseid][hCusto] = 240000;
                HouseInfo[houseid][hPadrao] = 216000;
            }
            else if(HouseInfo[houseid][hUpMax] == 12)
            {
                HouseInfo[houseid][hCusto] = 350000;
                HouseInfo[houseid][hPadrao] = 315000;
            }
            else if(HouseInfo[houseid][hUpMax] == 15)
            {
                HouseInfo[houseid][hCusto] = 400000;
                HouseInfo[houseid][hPadrao] = 360000;
            }
            else if(HouseInfo[houseid][hUpMax] == 18)
            {
                HouseInfo[houseid][hCusto] = 500000;
                HouseInfo[houseid][hPadrao] = 450000;
            }

            HouseInfo[houseid][hID] = houseid;
            format(HouseInfo[houseid][hNome], MAX_PLAYER_NAME, "N/A");
            format(HouseInfo[houseid][hM1], MAX_PLAYER_NAME, "N/A");
            format(HouseInfo[houseid][hM2], MAX_PLAYER_NAME, "N/A");
            format(HouseInfo[houseid][hM3], MAX_PLAYER_NAME, "N/A");
            format(HouseInfo[houseid][hM4], MAX_PLAYER_NAME, "N/A");
            format(HouseInfo[houseid][hM5], MAX_PLAYER_NAME, "N/A");
            format(HouseInfo[houseid][hM6], MAX_PLAYER_NAME, "N/A");
            format(HouseInfo[houseid][hMensagem], 30, "N/A");
            format(HouseInfo[houseid][hAlugando], 5, "N/A");
            format(HouseInfo[houseid][hVendendo], 5, "Sim");
            HouseInfo[houseid][hPreco] = 0;
            HouseInfo[houseid][hUp] = 1;
            format(HouseInfo[houseid][hTrancada], 5, "N/A");
            format(HouseInfo[houseid][hSenha], 5, "N/A");

            GetPlayer2DZone(zone, MAX_ZONE_NAME, HouseInfo[houseid][iconx], HouseInfo[houseid][icony]);
            format(String, MAX_STRING, "O(A) Jogador(a) %s liberou a casa ID %d localizada em ( %s )", PlayerInfo[playerid][Nome], HouseInfo[houseid][hID], zone);
            SendClientMessageToAll(-1, String);

            SetPlayerPos(playerid, HouseInfo[houseid][iconx], HouseInfo[houseid][icony], HouseInfo[houseid][iconz]);
            SetPlayerInterior(playerid, 0);
            SetPlayerVirtualWorld(playerid, 0);
            dentrocasa[playerid] = 0;

            UpgradeHouse(houseid);
            UpdateHouseExternal(houseid);
            UpdateHouses(houseid);
            return 1;
        }
        case MAIN_HOUSE_PASS:
        {
            new houseid = LastHouseID[playerid];

            if(!response) return 0;

            if(strlen(inputtext) == 0)
                return ShowPlayerDialog(playerid, MAIN_HOUSE_PASS, DIALOG_STYLE_INPUT, "{FFD700}Senha", "{FFFFFF}Digite abaixo a senha da casa para entrar \n{FF0000}Senha incorreta, tente novamente!", "Entrar", "Cancelar");

            if(strcmp(inputtext, HouseInfo[houseid][hSenha], true))
                return ShowPlayerDialog(playerid, MAIN_HOUSE_PASS, DIALOG_STYLE_INPUT, "{FFD700}Senha", "{FFFFFF}Digite abaixo a senha da casa para entrar \n{FF0000}Senha incorreta, tente novamente!", "Entrar", "Cancelar");

            SetPlayerVirtualWorld(playerid, HouseInfo[houseid][hID]);
            SetPlayerInterior(playerid, HouseInfo[houseid][hInterior]);
            SetPlayerPos(playerid, HouseInfo[houseid][hInteriorX], HouseInfo[houseid][hInteriorY], HouseInfo[houseid][hInteriorZ]);
            dentrocasa[playerid] = 1;
            format(String, MAX_STRING, "Bem vindo(a) a Casa ID %d que pertence a %s", HouseInfo[houseid][hID], HouseInfo[houseid][hNome]);
            SendClientMessage(playerid, C_PROPERTY, String);
            return 1;
        }
        case MAIN_HOUSE_SELL_LIST:
        {
            new houseid = LastHouseID[playerid];

            if(!response) return 0;

            switch(listitem)
            {
                case 0:
                {
                    if(!strcmp(HouseInfo[houseid][hVendendo], "Sim", true))
                    {
                        format(HouseInfo[houseid][hVendendo], 5, "N/A");
                        SendClientMessage(playerid, -1, "Agora sua casa não está mas à venda");
                    }
                    else if(!strcmp(HouseInfo[houseid][hVendendo], "N/A", true))
                    {
                        if(HouseInfo[houseid][hCofre] != 0)
                            return SendClientMessage(playerid, Erro, "Você não removeu o dinheiro do cofre de sua casa");

                        if(HouseInfo[houseid][hPreco] == 0)
                        {
                            HouseInfo[houseid][hPreco] = 0;
                            HouseInfo[houseid][hPreco] += HouseInfo[houseid][hPadrao];
                        }

                        format(HouseInfo[houseid][hVendendo], 5, "Sim");
                        format(String, MAX_STRING, "Agora sua casa está à venda no valor de {019303}$%s{FFFFFF}!", IsMoney(HouseInfo[houseid][hPreco], "."));
                        SendClientMessage(playerid, -1, String);
                    }

                    UpdateHouseExternal(houseid);
                    UpdateHouses(houseid);
                }
                case 1: ShowPlayerDialog(playerid, MAIN_HOUSE_SELL_INPUT, DIALOG_STYLE_INPUT, "{FFD700}Vender Casa", "{FFFFFF}Digite abaixo o valor que será somado com o valor padrão \nde sua casa automaticamente!", "Continuar", "Cancelar");
            }
            return 1;
        }
        case MAIN_HOUSE_SELL_INPUT:
        {
            new houseid = LastHouseID[playerid];

            if(!response) return 0;

            HouseInfo[houseid][hPreco] = 0;
            HouseInfo[houseid][hPreco] += HouseInfo[houseid][hPadrao] + strval(inputtext);

            format(String, MAX_STRING, "O valor da sua casa foi alterado para {019303}$%s{FFFFFF}, agora é só colocar a venda!", IsMoney(HouseInfo[houseid][hPreco], "."));
            SendClientMessage(playerid, -1, String);

            UpdateHouseExternal(houseid);
            UpdateHouses(houseid);
            return 1;
        }
        case MAIN_HOUSE_RESIDENTS:
        {
            new houseid = LastHouseID[playerid];

            if(!response) return 0;

            for(new listid = 0; listid < 6; listid++)
            {
                if(listitem == 0)
                {
                    HouseInfo[houseid][hResidents] = (listitem + 1);
                    ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS_LIST, DIALOG_STYLE_LIST, "{FFD700}Morador(a)", "{FFFFFF}Adicionar morador(a)\nRemover morador(a)", "Selecionar", "Cancelar");
                    break;
                }
            }
            return 1;
        }
        case MAIN_HOUSE_RESIDENTS_LIST:
        {
            new houseid = LastHouseID[playerid];

            if(!response) return 0;

            switch(listitem)
            {
                case 0:
                {
                    if(!strcmp(PlayerInfo[playerid][Nome], HouseInfo[houseid][hM1], true) ||
                    !strcmp(PlayerInfo[playerid][Nome], HouseInfo[houseid][hM2], true) ||
                    !strcmp(PlayerInfo[playerid][Nome], HouseInfo[houseid][hM3], true) ||
                    !strcmp(PlayerInfo[playerid][Nome], HouseInfo[houseid][hM4], true) ||
                    !strcmp(PlayerInfo[playerid][Nome], HouseInfo[houseid][hM5], true) ||
                    !strcmp(PlayerInfo[playerid][Nome], HouseInfo[houseid][hM6], true) )
                        return SendClientMessage(playerid, Erro, "Somente dono(a) pode usar essa opção");

                    switch(HouseInfo[houseid][hResidents])
                    {
                        case 1:
                        {
                            if(strcmp(HouseInfo[houseid][hM1], "N/A", true))
                                return SendClientMessage(playerid, Erro, "Essa vaga já tem morador(a)");
                        }
                        case 2:
                        {
                            if(strcmp(HouseInfo[houseid][hM2], "N/A", true))
                                return SendClientMessage(playerid, Erro, "Essa vaga já tem morador(a)");
                        }
                        case 3:
                        {
                            if(strcmp(HouseInfo[houseid][hM3], "N/A", true))
                                return SendClientMessage(playerid, Erro, "Essa vaga já tem morador(a)");
                        }
                        case 4:
                        {
                            if(strcmp(HouseInfo[houseid][hM4], "N/A", true))
                                return SendClientMessage(playerid, Erro, "Essa vaga já tem morador(a)");
                        }
                        case 5:
                        {
                            if(strcmp(HouseInfo[houseid][hM5], "N/A", true))
                                return SendClientMessage(playerid, Erro, "Essa vaga já tem morador(a)");
                        }
                        case 6:
                        {
                            if(strcmp(HouseInfo[houseid][hM6], "N/A", true))
                                return SendClientMessage(playerid, Erro, "Essa vaga já tem morador(a)");
                        }
                    }
                    ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS_INPUT, DIALOG_STYLE_INPUT, "{FFD700}Adicionar Morador(a)", "{FFFFFF}Digite abaixo o {FF0000}id{FFFFFF} do jogador(a)\nque você quer colocar como morador(a)", "Continuar", "Cancelar");
                    return 1;
                }
                case 1:
                {
                    switch(HouseInfo[houseid][hResidents])
                    {
                        case 1:
                        {
                            if(!strcmp(HouseInfo[houseid][hM1], "N/A", true))
                                return SendClientMessage(playerid, Erro, "Não tem nenhum morador(a) para remover");

                            format(String, MAX_STRING, "O(A) morador(a) %s foi removido da sua casa!", HouseInfo[houseid][hM1]);
                            SendClientMessage(playerid, C_PROPERTY, String);
                            format(HouseInfo[houseid][hM1], MAX_PLAYER_NAME, "N/A");
                        }
                        case 2:
                        {
                            if(!strcmp(HouseInfo[houseid][hM2], "N/A", true))
                                return SendClientMessage(playerid, Erro, "Não tem nenhum morador(a) para remover");

                            format(String, MAX_STRING, "O(A) morador(a) %s foi removido da sua casa!", HouseInfo[houseid][hM2]);
                            SendClientMessage(playerid, C_PROPERTY, String);
                            format(HouseInfo[houseid][hM2], MAX_PLAYER_NAME, "N/A");
                        }
                        case 3:
                        {
                            if(!strcmp(HouseInfo[houseid][hM3], "N/A", true))
                                return SendClientMessage(playerid, Erro, "Não tem nenhum morador(a) para remover");

                            format(String, MAX_STRING, "O(A) morador(a) %s foi removido da sua casa!", HouseInfo[houseid][hM3]);
                            SendClientMessage(playerid, C_PROPERTY, String);
                            format(HouseInfo[houseid][hM3], MAX_PLAYER_NAME, "N/A");
                        }
                        case 4:
                        {
                            if(!strcmp(HouseInfo[houseid][hM4], "N/A", true))
                                return SendClientMessage(playerid, Erro, "Não tem nenhum morador(a) para remover");

                            format(String, MAX_STRING, "O(A) morador(a) %s foi removido da sua casa!", HouseInfo[houseid][hM4]);
                            SendClientMessage(playerid, C_PROPERTY, String);
                            format(HouseInfo[houseid][hM4], MAX_PLAYER_NAME, "N/A");
                        }
                        case 5:
                        {
                            if(!strcmp(HouseInfo[houseid][hM5], "N/A", true))
                                return SendClientMessage(playerid, Erro, "Não tem nenhum morador(a) para remover");

                            format(String, MAX_STRING, "O(A) morador(a) %s foi removido da sua casa!", HouseInfo[houseid][hM5]);
                            SendClientMessage(playerid, C_PROPERTY, String);
                            format(HouseInfo[houseid][hM5], MAX_PLAYER_NAME, "N/A");
                        }
                        case 6:
                        {
                            if(!strcmp(HouseInfo[houseid][hM6], "N/A", true))
                                return SendClientMessage(playerid, Erro, "Não tem nenhum morador(a) para remover");

                            format(String, MAX_STRING, "O(A) morador(a) %s foi removido da sua casa!", HouseInfo[houseid][hM6]);
                            SendClientMessage(playerid, C_PROPERTY, String);
                            format(HouseInfo[houseid][hM6], MAX_PLAYER_NAME, "N/A");
                        }
                    }

                    UpdateHouses(houseid);
                }
            }
            return 1;
        }
        case MAIN_HOUSE_RESIDENTS_INPUT:
        {
            new houseid = LastHouseID[playerid];

            if(!response) return 0;

            new id = strval(inputtext);

            if(id < 0 || id >= MAX_PLAYERS)
                return ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS_INPUT, DIALOG_STYLE_INPUT, "{FFD700}Morador(a)", "{FFFFFF}Digite abaixo o {FF0000}id{FFFFFF} do jogador(a)\nque você quer colocar como morador(a)\n{FF4000}Jogador(a) não conectado(a)!", "Continuar", "Cancelar");

            if(PlayerInfo[id][Logado] == false)
                return ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS_INPUT, DIALOG_STYLE_INPUT, "{FFD700}Morador(a)", "{FFFFFF}Digite abaixo o {FF0000}id{FFFFFF} do jogador(a)\nque você quer colocar como morador(a)\n{FF4000}Jogador(a) não conectado(a)!", "Continuar", "Cancelar");

            if(id == playerid)
                return ShowPlayerDialog(playerid, MAIN_HOUSE_RESIDENTS_INPUT, DIALOG_STYLE_INPUT, "{FFD700}Morador(a)", "{FFFFFF}Digite abaixo o {FF0000}id{FFFFFF} do jogador(a)\nque você quer colocar como morador(a)\n{FF4000}Não pode colocar você como morador(a)!", "Continuar", "Cancelar");

            if(IsPlayerOwnerHouse(id))
                return SendClientMessage(playerid, Erro, "O(A) Jogador(a) já tem uma casa");

            if(IsPlayerResidentHouse(id))
                return SendClientMessage(playerid, Erro, "O(A) Jogador(a) já está de morador(a) em uma casa");

            if(!IsPlayerInRangeOfPoint(id, 10.0, HouseInfo[houseid][hInteriorX], HouseInfo[houseid][hInteriorY], HouseInfo[houseid][hInteriorZ]))
                return SendClientMessage(playerid, Erro, "O(A) Jogador(a) não está dentro da sua casa");

            switch(HouseInfo[houseid][hResidents])
            {
                case 1:
                {
                    format(HouseInfo[houseid][hM1], MAX_PLAYER_NAME, PlayerInfo[id][Nome]);
                    format(String, MAX_STRING, "Você colocou o jogador(a) %s para morar em sua casa!", HouseInfo[houseid][hM1]);
                    SendClientMessage(playerid, C_PROPERTY, String);
                }
                case 2:
                {
                    format(HouseInfo[houseid][hM2], MAX_PLAYER_NAME, PlayerInfo[id][Nome]);
                    format(String, MAX_STRING, "Você colocou o jogador(a) %s para morar em sua casa!", HouseInfo[houseid][hM2]);
                    SendClientMessage(playerid, C_PROPERTY, String);
                }
                case 3:
                {
                    format(HouseInfo[houseid][hM3], MAX_PLAYER_NAME, PlayerInfo[id][Nome]);
                    format(String, MAX_STRING, "Você colocou o jogador(a) %s para morar em sua casa!", HouseInfo[houseid][hM3]);
                    SendClientMessage(playerid, C_PROPERTY, String);
                }
                case 4:
                {
                    format(HouseInfo[houseid][hM4], MAX_PLAYER_NAME, PlayerInfo[id][Nome]);
                    format(String, MAX_STRING, "Você colocou o jogador(a) %s para morar em sua casa!", HouseInfo[houseid][hM4]);
                    SendClientMessage(playerid, C_PROPERTY, String);
                }
                case 5:
                {
                    format(HouseInfo[houseid][hM5], MAX_PLAYER_NAME, PlayerInfo[id][Nome]);
                    format(String, MAX_STRING, "Você colocou o jogador(a) %s para morar em sua casa!", HouseInfo[houseid][hM5]);
                    SendClientMessage(playerid, C_PROPERTY, String);
                }
                case 6:
                {
                    format(HouseInfo[houseid][hM6], MAX_PLAYER_NAME, PlayerInfo[id][Nome]);
                    format(String, MAX_STRING, "Você colocou o jogador(a) %s para morar em sua casa!", HouseInfo[houseid][hM6]);
                    SendClientMessage(playerid, C_PROPERTY, String);
                }
            }

            format(String, MAX_STRING, "O(A) Jogador(a) %s colocou voce para morar em sua casa, Digite: /MenuCasa para acessar o menu!", HouseInfo[houseid][hNome]);
            SendClientMessage(id, C_PROPERTY, String);
            UpdateHouses(houseid);
            return 1;
        }
        case MAIN_HOUSE_UPGRADE:
        {
            new houseid = LastHouseID[playerid];

            if(!response) return 0;

            if((listitem + 1) == HouseInfo[houseid][hUp])
                return SendClientMessage(playerid, Erro, "Esse interior já é o atual");

            new txt[200];

            listidUpDown[playerid] = (listitem + 1);

            format(String, MAX_STRING, "{FFFFFF}Tem certeza que ira fazer %sgrade desta casa?\n", ((HouseInfo[houseid][hUp] < listidUpDown[playerid]) ? ("Up") : ("Down")));
            strcat(txt, String);

            format(String, 10, "%sgrade", ((HouseInfo[houseid][hUp] < listidUpDown[playerid]) ? ("Up") : ("Down")));

            ShowPlayerDialog(playerid, MAIN_HOUSE_UPGRADE_AGREE, DIALOG_STYLE_MSGBOX, String, txt, "Sim", "Não");
            return 1;
        }
        case MAIN_HOUSE_UPGRADE_AGREE:
        {
            new houseid = LastHouseID[playerid];

            if(!response)
                return SendClientMessage(playerid, Erro, "Upgrade ou Downgrade cancelado");

            if(listidUpDown[playerid] == HouseInfo[houseid][hUp])
                return 0;

            if(listidUpDown[playerid] > HouseInfo[houseid][hUp])
            {
                if(HouseInfo[houseid][hUp] == 21)
                    return SendClientMessage(playerid, Erro, "Casa já está no Upgrade máximo");

                new total = ((listidUpDown[playerid] - HouseInfo[houseid][hUp]) * GetPriceUpHouse(houseid));

                if(PlayerInfo[playerid][Dinheiro] < total)
                    return SendClientMessage(playerid, Erro, "Saldo em mãos insuficiente");

                HouseInfo[houseid][hUp] = listidUpDown[playerid];
                HouseInfo[houseid][hPadrao] += total;

                PlayerInfo[playerid][Dinheiro] -= total;
                UpdatePlayerMoney(playerid);
            }
            else
            {
                if(HouseInfo[houseid][hUp] == 1)
                    return SendClientMessage(playerid, Erro, "Casa já está no downgrade máximo");

                new total = ((HouseInfo[houseid][hUp] - listidUpDown[playerid]) * GetPriceUpHouse(houseid));

                HouseInfo[houseid][hUp] = listidUpDown[playerid];
                HouseInfo[houseid][hPadrao] -= total;

                PlayerInfo[playerid][Dinheiro] += total;
                UpdatePlayerMoney(playerid);
            }

            UpgradeHouse(houseid);
            UpdateHouseExternal(houseid);
            UpdateHouses(houseid);

            SetPlayerVirtualWorld(playerid, HouseInfo[houseid][hID]);
            SetPlayerInterior(playerid, HouseInfo[houseid][hInterior]);
            SetPlayerPos(playerid, HouseInfo[houseid][hInteriorX], HouseInfo[houseid][hInteriorY], HouseInfo[houseid][hInteriorZ]);
            dentrocasa[playerid] = 1;
            return 1;
        }
        case MAIN_HOUSE_SELF:
        {
            new houseid = LastHouseID[playerid];

            if(!response) return 0;

            if(listitem == 0)
            {
                if(!strcmp(HouseInfo[houseid][hVendendo], "Sim", true))
                    return SendClientMessage(playerid, Erro, "Sua casa está à venda, retira-a da venda para poder guardar dinheiro em seu cofre");

                ShowPlayerDialog(playerid, MAIN_HOUSE_SELF_ADD, DIALOG_STYLE_INPUT, "{FFD700}Adicionar Dinheiro", "{FFFFFF}Digite abaixo a quantia de dinheiro que você deseja guardar no cofre de sua casa", "Continuar", "Cancelar");
            }
            else if(listitem == 1)
            {
                ShowPlayerDialog(playerid, MAIN_HOUSE_SELF_REMOVE, DIALOG_STYLE_INPUT, "{FFD700}Remover Dinheiro", "{FFFFFF}Digite abaixo a quantia de dinheiro que você deseja retirar do cofre de sua casa", "Continuar", "Cancelar");
            }
            return 1;
        }
        case MAIN_HOUSE_SELF_ADD:
        {
            new houseid = LastHouseID[playerid];

            if(!response) return 0;

            if(!IsNumeric(inputtext))
                return ShowPlayerDialog(playerid, MAIN_HOUSE_SELF_ADD, DIALOG_STYLE_INPUT, "{FFD700}Adicionar Dinheiro", "{FFFFFF}Digite abaixo a quantia de dinheiro que você deseja guardar no cofre de sua casa\n{FF4000}Erro, Digite apenas numeros!", "Continuar", "Cancelar");

            if(strval(inputtext) > PlayerInfo[playerid][Dinheiro])
                return ShowPlayerDialog(playerid, MAIN_HOUSE_SELF_ADD, DIALOG_STYLE_INPUT, "{FFD700}Adicionar Dinheiro", "{FFFFFF}Digite abaixo a quantia de dinheiro que você deseja guardar no cofre de sua casa\n{FF4000}Erro, você não tem todo esse dinheiro em mãos!", "Continuar", "Cancelar");

            PlayerInfo[playerid][Dinheiro] -= strval(inputtext);
            HouseInfo[houseid][hCofre] += strval(inputtext);
            UpdatePlayerMoney(playerid);
            UpdateHouses(houseid);

            format(String, MAX_STRING, "Você guardou $%s no cofre de sua casa", IsMoney(strval(inputtext), "."));
            SendClientMessage(playerid, C_PROPERTY, String);
            return 1;
        }
        case MAIN_HOUSE_SELF_REMOVE:
        {
            new houseid = LastHouseID[playerid];

            if(!response) return 0;

            if(!IsNumeric(inputtext))
                return ShowPlayerDialog(playerid, MAIN_HOUSE_SELF_REMOVE, DIALOG_STYLE_INPUT, "{FFD700}Adicionar Dinheiro", "{FFFFFF}Digite abaixo a quantia de dinheiro que você deseja retirar do cofre de sua casa\n{FF4000}Erro, Digite apenas numeros!", "Continuar", "Cancelar");

            if(strval(inputtext) > HouseInfo[houseid][hCofre])
                return ShowPlayerDialog(playerid, MAIN_HOUSE_SELF_REMOVE, DIALOG_STYLE_INPUT, "{FFD700}Adicionar Dinheiro", "{FFFFFF}Digite abaixo a quantia de dinheiro que você deseja retirar do cofre de sua casa\n{FF4000}Erro, você não tem todo esse dinheiro em sua casa!", "Continuar", "Cancelar");

            PlayerInfo[playerid][Dinheiro] += strval(inputtext);
            HouseInfo[houseid][hCofre] -= strval(inputtext);
            UpdatePlayerMoney(playerid);
            UpdateHouses(houseid);

            format(String, MAX_STRING, "Você retirou $%s do cofre de sua casa!", IsMoney(strval(inputtext), "."));
            SendClientMessage(playerid, C_PROPERTY, String);
            return 1;
        }
    }
    return 1;
}

forward CreateHouse(playerid, upgrademax, Cost, Standard, Reaiss, Float:iconX, Float:iconY, Float:iconZ);
public CreateHouse(playerid, upgrademax, Cost, Standard, Reaiss, Float:iconX, Float:iconY, Float:iconZ)
{
    new idhouse = cache_insert_id();

    HouseInfo[idhouse][hID] = idhouse;
    format(HouseInfo[idhouse][hNome], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[idhouse][hM1], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[idhouse][hM2], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[idhouse][hM3], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[idhouse][hM4], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[idhouse][hM5], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[idhouse][hM6], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[idhouse][hMensagem], 30, "N/A");
    format(HouseInfo[idhouse][hAlugando], 5, "N/A");
    format(HouseInfo[idhouse][hVendendo], 5, "Sim");
    HouseInfo[idhouse][hUp] = 1;
    HouseInfo[idhouse][hUpMax] = upgrademax;
    HouseInfo[idhouse][hCusto] = Cost;
    HouseInfo[idhouse][hPadrao] = Standard;
    HouseInfo[idhouse][hReais] = Reaiss;
    HouseInfo[idhouse][hCofre] = 0;
    format(HouseInfo[idhouse][hTrancada], 5, "N/A");
    format(HouseInfo[idhouse][hSenha], 5, "N/A");
    HouseInfo[idhouse][iconx] = iconX;
    HouseInfo[idhouse][icony] = iconY;
    HouseInfo[idhouse][iconz] = iconZ;

    GetPlayer2DZone(zone, MAX_ZONE_NAME, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony]);
    format(String, MAX_STRING, "VRC-Admin ~ O(A) %s %s criou a Casa ID %d localizada em %s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], HouseInfo[idhouse][hID], zone);
    SendClientMessageToAll(adm, String);

    CreateHouseExternal(idhouse);
    return 1;
}

forward OnHouseTimerContinue(playerid);
public OnHouseTimerContinue(playerid)
{
    KillTimer(HouseContinueTimer[playerid]);
    HouseContinue[playerid] = false;
    SendClientMessage(playerid, -1, "Seu tempo para usar o comando {FF0000}/continuar{FFFFFF} acabou");
    return 1;
}

stock UpdateHouseExternal(idhouse)
{
    DestroyDynamicMapIcon(HouseInfo[idhouse][hMap]);
    DestroyDynamicPickup(HouseInfo[idhouse][hPickup]);

    if(!strcmp(HouseInfo[idhouse][hNome], "N/A"))
    {
        if(HouseInfo[idhouse][hReais])
        {
            format(String, MAX_STRING, "{31B404}Casa à Venda ( ID:%d )\n{FFFFFF}Upgrade do Interior: %d/%d\n{CE9F01}Valor: {31B404}$%s\n{CE9F01}Reais: {31B404}R$%d,00\n{6495ED}/ComprarCasa", HouseInfo[idhouse][hID], HouseInfo[idhouse][hUp], HouseInfo[idhouse][hUpMax], IsMoney(HouseInfo[idhouse][hCusto], "."), HouseInfo[idhouse][hReais]);
        }
        else if(!HouseInfo[idhouse][hReais])
        {
            format(String, MAX_STRING, "{31B404}Casa à Venda ( ID:%d )\n{FFFFFF}Upgrade do Interior: %d/%d\n{CE9F01}Valor: {31B404}$%s\n{6495ED}/ComprarCasa", HouseInfo[idhouse][hID], HouseInfo[idhouse][hUp], HouseInfo[idhouse][hUpMax], IsMoney(HouseInfo[idhouse][hCusto], "."));
        }
        HouseInfo[idhouse][hMap] = CreateDynamicMapIcon(HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz], 31, -1, 0, -1, -1, 30.0);
        HouseInfo[idhouse][hPickup] = CreateDynamicPickup(1273, 23, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz], 0, -1, -1, 100.0);
        UpdateDynamic3DTextLabelText(HouseInfo[idhouse][hLabel], 0xFFFFFFFF, String);
    }
    else if(strcmp(HouseInfo[idhouse][hNome], "N/A"))
    {
        if(!strcmp(HouseInfo[idhouse][hVendendo], "N/A"))
        {
            format(String, MAX_STRING, "{FFD700}Casa de %s ( ID:%d )\n{FFFFFF}%s\n{FFFFFF}Upgrade do Interior: %d/%d\n{6BAF76}%s\n{6495ED}/EntrarCasa", HouseInfo[idhouse][hNome], HouseInfo[idhouse][hID], HouseInfo[idhouse][hMensagem], HouseInfo[idhouse][hUp], HouseInfo[idhouse][hUpMax], ( !strcmp(HouseInfo[idhouse][hTrancada], "Sim") ? ("Trancada") : ("Destrancada")));
        }
        else if(!strcmp(HouseInfo[idhouse][hVendendo], "Sim"))
        {
            format(String, MAX_STRING, "{FFD700}Casa de %s ( ID:%d )\n{FFFFFF}%s\n{FFFFFF}Upgrade do Interior: %d/%d\n{6BAF76}%s\n{FFFFFF}O(A) proprietário(a) está vendendo a casa por {019303}$%s\n{6495ED}/ComprarCasa", HouseInfo[idhouse][hNome], HouseInfo[idhouse][hID], HouseInfo[idhouse][hMensagem], HouseInfo[idhouse][hUp], HouseInfo[idhouse][hUpMax], ( !strcmp(HouseInfo[idhouse][hTrancada], "Sim") ? ("Trancada") : ("Destrancada")), IsMoney(HouseInfo[idhouse][hPreco], "."));
        }

        HouseInfo[idhouse][hMap] = CreateDynamicMapIcon(HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz], 32, -1, 0, -1, -1, 30.0);
        HouseInfo[idhouse][hPickup] = CreateDynamicPickup(19522, 23, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz], 0, -1, -1, 100.0);
        UpdateDynamic3DTextLabelText(HouseInfo[idhouse][hLabel], 0xFFFFFFFF, String);
    }
    return 1;
}

stock CreateHouseExternal(idhouse)
{
    if(!strcmp(HouseInfo[idhouse][hNome], "N/A"))
    {
        if(HouseInfo[idhouse][hReais])
        {
            format(String, MAX_STRING, "{31B404}Casa à Venda ( ID:%d )\n{FFFFFF}Upgrade do Interior: %d/%d\n{CE9F01}Valor: {31B404}$%s\n{CE9F01}Reais: {31B404}R$%d,00\n{6495ED}/ComprarCasa", HouseInfo[idhouse][hID], HouseInfo[idhouse][hUp], HouseInfo[idhouse][hUpMax], IsMoney(HouseInfo[idhouse][hCusto], "."), HouseInfo[idhouse][hReais]);
        }
        else if(!HouseInfo[idhouse][hReais])
        {
            format(String, MAX_STRING, "{31B404}Casa à Venda ( ID:%d )\n{FFFFFF}Upgrade do Interior: %d/%d\n{CE9F01}Valor: {31B404}$%s\n{6495ED}/ComprarCasa", HouseInfo[idhouse][hID], HouseInfo[idhouse][hUp], HouseInfo[idhouse][hUpMax], IsMoney(HouseInfo[idhouse][hCusto], "."));
        }

        HouseInfo[idhouse][hMap] = CreateDynamicMapIcon(HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz], 31, -1, 0, -1, -1, 30.0);
        HouseInfo[idhouse][hPickup] = CreateDynamicPickup(1273, 23, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz], 0, -1, -1, 100.0);
        HouseInfo[idhouse][hLabel] = CreateDynamic3DTextLabel(String, 0xFFFFFFFF, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz]+0.50, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, -1, -1, 20.0, -1, 0);
    }
    else if(strcmp(HouseInfo[idhouse][hNome], "N/A"))
    {
        if(!strcmp(HouseInfo[idhouse][hVendendo], "N/A"))
        {
            format(String, MAX_STRING, "{FFD700}Casa de %s ( ID:%d )\n{FFFFFF}%s\n{FFFFFF}Upgrade do Interior: %d/%d\n{6BAF76}%s\n{6495ED}/EntrarCasa", HouseInfo[idhouse][hNome], HouseInfo[idhouse][hID], HouseInfo[idhouse][hMensagem], HouseInfo[idhouse][hUp], HouseInfo[idhouse][hUpMax], ( !strcmp(HouseInfo[idhouse][hTrancada], "Sim") ? ("Trancada") : ("Destrancada")));
        }
        else if(!strcmp(HouseInfo[idhouse][hVendendo], "Sim"))
        {
            format(String, MAX_STRING, "{FFD700}Casa de %s ( ID:%d )\n{FFFFFF}%s\n{FFFFFF}Upgrade do Interior: %d/%d\n{6BAF76}%s\n{FFFFFF}O(A) proprietário(a) está vendendo a casa por {019303}$%s\n{6495ED}/ComprarCasa", HouseInfo[idhouse][hNome], HouseInfo[idhouse][hID], HouseInfo[idhouse][hMensagem], HouseInfo[idhouse][hUp], HouseInfo[idhouse][hUpMax], ( !strcmp(HouseInfo[idhouse][hTrancada], "Sim") ? ("Trancada") : ("Destrancada")), IsMoney(HouseInfo[idhouse][hPreco], "."));
        }

        HouseInfo[idhouse][hMap] = CreateDynamicMapIcon(HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz], 32, -1, 0, -1, -1, 30.0);
        HouseInfo[idhouse][hPickup] = CreateDynamicPickup(19522, 23, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz], 0, -1, -1, 100.0);
        HouseInfo[idhouse][hLabel] = CreateDynamic3DTextLabel(String, 0xFFFFFFFF, HouseInfo[idhouse][iconx], HouseInfo[idhouse][icony], HouseInfo[idhouse][iconz]+0.50, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, -1, -1, 20.0, -1, 0);
    }
    return 1;
}

stock UpgradeHouse(idhouse)
{
    switch(HouseInfo[idhouse][hUp])
    {
        case 1:
        {
            HouseInfo[idhouse][hInteriorX] = 267.4800;
            HouseInfo[idhouse][hInteriorY] = 305.0237;
            HouseInfo[idhouse][hInteriorZ] = 999.1484;
            HouseInfo[idhouse][hInterior] = 2;
        }
        case 2:
        {
            HouseInfo[idhouse][hInteriorX] = 244.5781;
            HouseInfo[idhouse][hInteriorY] = 305.0017;
            HouseInfo[idhouse][hInteriorZ] = 999.1484;
            HouseInfo[idhouse][hInterior] = 1;
        }
        case 3:
        {
            HouseInfo[idhouse][hInteriorX] = 2308.7378;
            HouseInfo[idhouse][hInteriorY] = -1211.6158;
            HouseInfo[idhouse][hInteriorZ] = 1049.0234;
            HouseInfo[idhouse][hInterior] = 6;
        }
        case 4:
        {
            HouseInfo[idhouse][hInteriorX] = 2333.0703;
            HouseInfo[idhouse][hInteriorY] = -1075.8330;
            HouseInfo[idhouse][hInteriorZ] = 1049.0234;
            HouseInfo[idhouse][hInterior] = 6;
        }
        case 5:
        {
            HouseInfo[idhouse][hInteriorX] = -42.6755;
            HouseInfo[idhouse][hInteriorY] = 1406.7865;
            HouseInfo[idhouse][hInteriorZ] = 1084.4297;
            HouseInfo[idhouse][hInterior] = 8;
        }
        case 6:
        {
            HouseInfo[idhouse][hInteriorX] = 223.1247;
            HouseInfo[idhouse][hInteriorY] = 1288.4781;
            HouseInfo[idhouse][hInteriorZ] = 1082.1406;
            HouseInfo[idhouse][hInterior] = 1;
        }
        case 7:
        {
            HouseInfo[idhouse][hInteriorX] = 261.0076;
            HouseInfo[idhouse][hInteriorY] = 1285.5956;
            HouseInfo[idhouse][hInteriorZ] = 1080.2578;
            HouseInfo[idhouse][hInterior] = 4;
        }
        case 8:
        {
            HouseInfo[idhouse][hInteriorX] = 226.1267;
            HouseInfo[idhouse][hInteriorY] = 1240.0048;
            HouseInfo[idhouse][hInteriorZ] = 1082.1406;
            HouseInfo[idhouse][hInterior] = 2;
        }
        case 9:
        {
            HouseInfo[idhouse][hInteriorX] = 2237.5969;
            HouseInfo[idhouse][hInteriorY] = -1079.6637;
            HouseInfo[idhouse][hInteriorZ] = 1049.0234;
            HouseInfo[idhouse][hInterior] = 2;
        }
        case 10:
        {
            HouseInfo[idhouse][hInteriorX] = 2365.2014;
            HouseInfo[idhouse][hInteriorY] = -1134.2975;
            HouseInfo[idhouse][hInteriorZ] = 1050.8750;
            HouseInfo[idhouse][hInterior] = 8;
        }
        case 11:
        {
            HouseInfo[idhouse][hInteriorX] = 295.2315;
            HouseInfo[idhouse][hInteriorY] = 1473.1649;
            HouseInfo[idhouse][hInteriorZ] = 1080.2578;
            HouseInfo[idhouse][hInterior] = 15;
        }
        case 12:
        {
            HouseInfo[idhouse][hInteriorX] = 260.6734;
            HouseInfo[idhouse][hInteriorY] = 1237.7909;
            HouseInfo[idhouse][hInteriorZ] = 1084.2578;
            HouseInfo[idhouse][hInterior] = 9;
        }
        case 13:
        {
            HouseInfo[idhouse][hInteriorX] = -261.8548;
            HouseInfo[idhouse][hInteriorY] = 1456.6841;
            HouseInfo[idhouse][hInteriorZ] = 1084.3672;
            HouseInfo[idhouse][hInterior] = 4;
        }
        case 14:
        {
            HouseInfo[idhouse][hInteriorX] = 235.3171;
            HouseInfo[idhouse][hInteriorY] = 1187.4275;
            HouseInfo[idhouse][hInteriorZ] = 1080.2578;
            HouseInfo[idhouse][hInterior] = 3;
        }
        case 15:
        {
            HouseInfo[idhouse][hInteriorX] = 2195.4243;
            HouseInfo[idhouse][hInteriorY] = -1204.5555;
            HouseInfo[idhouse][hInteriorZ] = 1049.0234;
            HouseInfo[idhouse][hInterior] = 6;
        }
        case 16:
        {
            HouseInfo[idhouse][hInteriorX] = 225.6588;
            HouseInfo[idhouse][hInteriorY] = 1022.2997;
            HouseInfo[idhouse][hInteriorZ] = 1084.0153;
            HouseInfo[idhouse][hInterior] = 7;
        }
        case 17:
        {
            HouseInfo[idhouse][hInteriorX] = 140.2825;
            HouseInfo[idhouse][hInteriorY] = 1367.8831;
            HouseInfo[idhouse][hInteriorZ] = 1083.8622;
            HouseInfo[idhouse][hInterior] = 5;
        }
        case 18:
        {
            HouseInfo[idhouse][hInteriorX] = 2317.8479;
            HouseInfo[idhouse][hInteriorY] = -1025.4985;
            HouseInfo[idhouse][hInteriorZ] = 1050.2109;
            HouseInfo[idhouse][hInterior] = 9;
        }
        case 19:
        {
            HouseInfo[idhouse][hInteriorX] = 0;
            HouseInfo[idhouse][hInteriorY] = 0;
            HouseInfo[idhouse][hInteriorZ] = 0;
            HouseInfo[idhouse][hInterior] = 0;
        }
        case 20:
        {
            HouseInfo[idhouse][hInteriorX] = 0;
            HouseInfo[idhouse][hInteriorY] = 0;
            HouseInfo[idhouse][hInteriorZ] = 0;
            HouseInfo[idhouse][hInterior] = 0;
        }
        case 21:
        {
            HouseInfo[idhouse][hInteriorX] = 1299.14;
            HouseInfo[idhouse][hInteriorY] = -794.77;
            HouseInfo[idhouse][hInteriorZ] = 1084.00;
            HouseInfo[idhouse][hInterior] = 5;
        }
    }
    return 1;
}

stock GetHouseID(playerid, pickupid)
{
    for(new i = 1; i < MAX_HOUSES; i++)
    {
        if(pickupid == HouseInfo[i][hPickup] && IsPlayerInRangeOfPoint(playerid, 1.5, HouseInfo[i][iconx], HouseInfo[i][icony], HouseInfo[i][iconz]))
        {
            SendClientMessage(playerid, -1, "Para entrar na casa digite {CFCDCD}'/EntrarCasa'{FFFFFF} ou pressione a tecla {CFCDCD}'F'");
            return LastHouseID[playerid] = i;
        }
    }
    return 0;
}

stock SpawnHouse(playerid)
{
    for(new houseid = 1; houseid < MAX_HOUSES; houseid++)
    {
        if(!IsPlayerOwnerHouse(playerid, houseid) && !IsPlayerResidentHouse(playerid, houseid)) continue;

        SetSpawnInfo(playerid, 0, PlayerInfo[playerid][skin], HouseInfo[houseid][iconx], HouseInfo[houseid][icony], HouseInfo[houseid][iconz], 0, 0, 0, 0, 0, 0, 0);
        SendClientMessage(playerid, -1, "Você tem 30 segundos para usar o comando {FF0000}/continuar{FFFFFF} e voltar a sua última posição");
        HouseContinueTimer[playerid] = SetTimerEx("OnHouseTimerContinue", 30000, false, "d", playerid);
        HouseContinue[playerid] = true;
    }

    if(!HouseContinue[playerid]){
        SetPlayerInterior(playerid, PlayerInfo[playerid][Interior]);
        SetSpawnInfo(playerid, 0, PlayerInfo[playerid][skin], PlayerInfo[playerid][PosX], PlayerInfo[playerid][PosY], PlayerInfo[playerid][PosZ], PlayerInfo[playerid][PosA], 0, 0, 0, 0, 0, 0);
    }

    Load_Tutorial(playerid);
    return 1;
}

stock LeftHouse(playerid)
{
    new houseid = LastHouseID[playerid];

    if(IsPlayerInRangeOfPoint(playerid, 50.0, HouseInfo[houseid][hInteriorX], HouseInfo[houseid][hInteriorY], HouseInfo[houseid][hInteriorZ]))
    {
        PlayerInfo[playerid][PosX] = HouseInfo[houseid][iconx];
        PlayerInfo[playerid][PosY] = HouseInfo[houseid][icony];
        PlayerInfo[playerid][PosZ] = HouseInfo[houseid][iconz];
        PlayerInfo[playerid][PosA] = 0.0;
    }
    return 1;
}

stock ReleaseHouse(idhousee)
{
    switch(HouseInfo[idhousee][hUpMax])
    {
        case 3:
        {
            HouseInfo[idhousee][hCusto] = 70000;
            HouseInfo[idhousee][hPadrao] = 63000;
        }
        case 6:
        {
            HouseInfo[idhousee][hCusto] = 150000;
            HouseInfo[idhousee][hPadrao] = 135000;
        }
        case 9:
        {
            HouseInfo[idhousee][hCusto] = 240000;
            HouseInfo[idhousee][hPadrao] = 216000;
        }
        case 12:
        {
            HouseInfo[idhousee][hCusto] = 350000;
            HouseInfo[idhousee][hPadrao] = 315000;
        }
        case 15:
        {
            HouseInfo[idhousee][hCusto] = 400000;
            HouseInfo[idhousee][hPadrao] = 360000;
        }
        case 18:
        {
            HouseInfo[idhousee][hCusto] = 500000;
            HouseInfo[idhousee][hPadrao] = 450000;
        }
    }

    HouseInfo[idhousee][hID] = idhousee;
    format(HouseInfo[idhousee][hNome], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[idhousee][hM1], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[idhousee][hM2], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[idhousee][hM3], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[idhousee][hM4], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[idhousee][hM5], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[idhousee][hM6], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[idhousee][hMensagem], 30, "N/A");
    format(HouseInfo[idhousee][hAlugando], 5, "N/A");
    format(HouseInfo[idhousee][hVendendo], 5, "Sim");
    HouseInfo[idhousee][hPreco] = 0;
    HouseInfo[idhousee][hUp] = 1;
    format(HouseInfo[idhousee][hTrancada], 5, "N/A");
    format(HouseInfo[idhousee][hSenha], 5, "N/A");

    UpgradeHouse(idhousee);
    UpdateHouseExternal(idhousee);
    UpdateHouses(idhousee);
    return 1;
}

stock GetPriceUpHouse(idhouse)
{
    switch(HouseInfo[idhouse][hUpMax])
    {
        case 3: return HOUSE_PRICE_UP3;
        case 6: return HOUSE_PRICE_UP6;
        case 9: return HOUSE_PRICE_UP9;
        case 12: return HOUSE_PRICE_UP12;
        case 15: return HOUSE_PRICE_UP15;
        case 18: return HOUSE_PRICE_UP18;
        case 21: return HOUSE_PRICE_UP21;
    }
    return 1;
}

stock IsPlayerOwnerHouse(playerid, idhouse = -1)
{
    new query[200];

    if(idhouse == -1)
        mysql_format(IDConexao, query, 200, "SELECT * FROM `Houses` WHERE `Nome`='%s'", PlayerInfo[playerid][Nome]);
    else
        mysql_format(IDConexao, query, 200, "SELECT * FROM `Houses` WHERE `Nome`='%s' AND `ID`='%d'", PlayerInfo[playerid][Nome], idhouse);

    mysql_query(IDConexao, query);

    if(cache_num_rows()) return 1;

    return 0;
}

stock IsPlayerResidentHouse(playerid, idhouse = -1)
{
    new query[500];

    if(idhouse == -1)
        mysql_format(IDConexao, query, 500, "SELECT * FROM `Houses` WHERE `M1`='%e' OR `M2`='%e' OR `M3`='%e' OR `M4`='%e' OR `M5`='%e' OR `M6`='%e'",
        PlayerInfo[playerid][Nome], PlayerInfo[playerid][Nome],
        PlayerInfo[playerid][Nome], PlayerInfo[playerid][Nome],
        PlayerInfo[playerid][Nome], PlayerInfo[playerid][Nome]);
    else
        mysql_format(IDConexao, query, 500, "SELECT * FROM `Houses` WHERE (`M1`='%e' OR `M2`='%e' OR `M3`='%e' OR `M4`='%e' OR `M5`='%e' OR `M6`='%e') AND `ID`='%d'",
        PlayerInfo[playerid][Nome], PlayerInfo[playerid][Nome],
        PlayerInfo[playerid][Nome], PlayerInfo[playerid][Nome],
        PlayerInfo[playerid][Nome], PlayerInfo[playerid][Nome],
        HouseInfo[idhouse][hID]);

    mysql_query(IDConexao, query);

    if(cache_num_rows()) return 1;

    return 0;
}

/******************************************************************************/
/*****************************| COMMANDS HOUSES |******************************/
/******************************************************************************/

CMD:dormir(playerid)
{
    new houseid = LastHouseID[playerid];

    if(dentrocasa[playerid] != 1)
        return SendClientMessage(playerid, Erro, "Você não está em uma casa");

    if(!IsPlayerInRangeOfPoint(playerid, 30.0, HouseInfo[houseid][hInteriorX], HouseInfo[houseid][hInteriorY], HouseInfo[houseid][hInteriorZ]))
        return SendClientMessage(playerid, Erro, "Você está muito longe da porta da sua casa");

    if(!IsPlayerResidentHouse(playerid, houseid))
        return SendClientMessage(playerid, Erro, "Você não é dono(a)/morador(a) dessa casa");

    if(Sleeping[playerid])
        return SendClientMessage(playerid, Erro, "Você já está dormindo");

    if(Progress[playerid][Sono] < 90.0)
        return SendClientMessage(playerid, Erro, "Você não está com sono");

    Sleep(playerid);
    return 1;
}
CMD:continuar(playerid)
{
    if(HouseContinue[playerid] == false)
        return SendClientMessage(playerid, Erro, "Seu tempo para usar o comando /continuar acabou");

    HouseContinue[playerid] = false;
    SetPlayerInterior(playerid, PlayerInfo[playerid][Interior]);
    SetPlayerPos(playerid, PlayerInfo[playerid][PosX], PlayerInfo[playerid][PosY], PlayerInfo[playerid][PosZ]);
    SendClientMessage(playerid, -1, "Você foi até sua última posição");
    KillTimer(HouseContinueTimer[playerid]);
    return 1;
}
CMD:ircasa(playerid, params[])
{
    if(!IsPlayerHelper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new id;

    if(sscanf(params, "d", id))
        return SendClientMessage(playerid, Erro, "Digite: /IrCasa [id-casa]");

    if(id < 1 || id >= MAX_HOUSES)
        return SendClientMessage(playerid, Erro, "Esse ID de Casa não existe");

    SetPlayerInterior(playerid, 0);
    SetPlayerPos(playerid, HouseInfo[id][iconx], HouseInfo[id][icony], HouseInfo[id][iconz]);

    format(String, MAX_STRING, "VRC-Admin ~ Você se teletransportou para a Casa ID %d", id);
    SendClientMessage(playerid, adm, String);
    return 1;
}
CMD:criarcasa(playerid, params[])
{
    if(!IsPlayerDeveloper(playerid))
		return SendClientMessage(playerid, Erro, "Comando Inválido");

    new Float:hPos[3], Cost, Standard, reaiss, upgrademax;

    if(sscanf(params, "dd", upgrademax, reaiss))
        return SendClientMessage(playerid, Erro, "Digite: /CriarCasa [Maxímo-Upgrade][Reais]");

    GetPlayerPos(playerid, hPos[0], hPos[1], hPos[2]);

    if(upgrademax != 3 && upgrademax != 6 && upgrademax != 9 && upgrademax != 12 && upgrademax != 15 && upgrademax != 18)
        return SendClientMessage(playerid, Erro, "Upgrades permitidos: 3, 6, 9, 12, 15 e 18");

    switch(upgrademax)
    {
        case 3:
        {
            Cost = 70000;
            Standard = 63000;
        }
        case 6:
        {
            Cost = 150000;
            Standard = 135000;
        }
        case 9:
        {
            Cost = 240000;
            Standard = 216000;
        }
        case 12:
        {
            Cost = 350000;
            Standard = 315000;
        }
        case 15:
        {
            Cost = 400000;
            Standard = 360000;
        }
        case 18:
        {
            Cost = 500000;
            Standard = 450000;
        }
        case 21:
        {
            Cost = 5000000;
            Standard = 4500000;
        }
    }

    new query[500];

    mysql_format(IDConexao, query, 500, "INSERT INTO `Houses` (`UpMax`,`Custo`, `Padrao`, `Reais`, `X`, `Y`, `Z`) VALUES ('%d', '%d', '%d', '%d', '%f', '%f', '%f')", upgrademax, Cost, Standard, reaiss, hPos[0], hPos[1], hPos[2]);
    mysql_tquery(IDConexao, query, "CreateHouse", "dddddfff", playerid, upgrademax, Cost, Standard, reaiss, hPos[0], hPos[1], hPos[2]);
    return 1;
}
CMD:editarcasa(playerid, params[])
{
    if(!IsPlayerDeveloper(playerid))
		return SendClientMessage(playerid, Erro, "Comando Inválido");

    new id, upgrademax;

    if(sscanf(params, "dd", id, upgrademax))
        return SendClientMessage(playerid, Erro, "Digite: /EditarCasa [id-casa] [máxímo-upgrade]");

    if(id < 1 || id >= MAX_HOUSES)
        return SendClientMessage(playerid, Erro, "Esse id de casa não existe");

    if(!(upgrademax == 3 || upgrademax == 6 || upgrademax == 9 || upgrademax == 12 || upgrademax == 15 || upgrademax == 18))
        return SendClientMessage(playerid, Erro, "Upgrades permitidos: 3, 6, 9, 12, 15 e 18");

    if(!IsPlayerInRangeOfPoint(playerid, 15.0, HouseInfo[id][iconx], HouseInfo[id][icony], HouseInfo[id][iconz]))
        return SendClientMessage(playerid, Erro, "Você não está perto da porta dessa casa");

    switch(upgrademax)
    {
        case 3:
        {
            HouseInfo[id][hCusto] = 70000;
            HouseInfo[id][hPadrao] = 63000;
        }
        case 6:
        {
            HouseInfo[id][hCusto] = 150000;
            HouseInfo[id][hPadrao] = 135000;
        }
        case 9:
        {
            HouseInfo[id][hCusto] = 240000;
            HouseInfo[id][hPadrao] = 216000;
        }
        case 12:
        {
            HouseInfo[id][hCusto] = 350000;
            HouseInfo[id][hPadrao] = 315000;
        }
        case 15:
        {
            HouseInfo[id][hCusto] = 400000;
            HouseInfo[id][hPadrao] = 360000;
        }
        case 18:
        {
            HouseInfo[id][hCusto] = 500000;
            HouseInfo[id][hPadrao] = 450000;
        }
        case 21:
        {
            HouseInfo[id][hCusto] = 5000000;
            HouseInfo[id][hPadrao] = 4500000;
        }
    }

    HouseInfo[id][hUpMax] = upgrademax;
    GetPlayerPos(playerid, HouseInfo[id][iconx], HouseInfo[id][icony], HouseInfo[id][iconz]);

    format(String, MAX_STRING, "VRC-Admin ~ O(A) %s %s editou a Casa ID %d", CargoAdmin(playerid), PlayerInfo[playerid][Nome], id);
    SendClientMessageToAll(adm, String);
    UpgradeHouse(id);
    UpdateHouseExternal(id);
    UpdateHouses(id);
    return 1;
}
CMD:liberarcasa(playerid, params[])
{
    if(!IsPlayerDeveloper(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new houseid;

    if(sscanf(params, "d", houseid))
        return SendClientMessage(playerid, Erro, "Digite: /LiberarCasa [id-casa]");

    if(houseid < 1 || houseid >= MAX_HOUSES)
        return SendClientMessage(playerid, Erro, "Esse id de casa não existe");

    if(strcmp(HouseInfo[houseid][hNome], "N/A", true)==0)
        return SendClientMessage(playerid, Erro, "Essa casa já está libera e não tem dono(a)");

    if(dentrocasa[playerid] == 1)
        return SendClientMessage(playerid, Erro, "Você não pode liberar nenhuma casa estando dentro de uma");

    GetPlayer2DZone(zone, MAX_ZONE_NAME, HouseInfo[houseid][iconx], HouseInfo[houseid][icony]);
    format(String, MAX_STRING, "VRC-Admin ~ O(A) %s %s liberou a Casa ID %d que pertencia a %s localizada em %s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], houseid, HouseInfo[houseid][hNome], zone);
    SendClientMessageToAll(adm, String);

    ReleaseHouse(houseid);
    return 1;
}
CMD:menucasa(playerid)
{
    new txt[500], houseid = LastHouseID[playerid];

    if(dentrocasa[playerid] != 1)
        return SendClientMessage(playerid, Erro, "Você não está em uma casa");

    if(IsPlayerOwnerHouse(playerid, houseid))
    {
        strcat(txt, "{FF0000}Funções \t\t {1CEB00}Status \n");

        format(String, 100, "{FFFFFF}Mensagem \t\t %s\n", HouseInfo[houseid][hMensagem]);
        strcat(txt, String);
        format(String, 100, "{FFFFFF}Senha \t\t {FF4500}%s\n", HouseInfo[houseid][hSenha]);
        strcat(txt, String);
        format(String, 100, "{FFFFFF}Trancada \t\t %s\n", (!strcmp(HouseInfo[houseid][hTrancada], "Sim", true) ? ("Sim") : ("Não")));
        strcat(txt, String);
        format(String, 100, "{FFFFFF}Cofre \t\t {2CC06B}$%s\n", IsMoney(HouseInfo[houseid][hCofre], "."));
        strcat(txt, String);
        format(String, 100, "{FFFFFF}Upgrade \t\t {87CEFF}%d/%d \n", HouseInfo[houseid][hUp], HouseInfo[houseid][hUpMax]);
        strcat(txt, String);
        strcat(txt, "{FFFFFF}Moradores \t\t \n");
        format(String, 100, "{FFFFFF}Vender/Alterar Preço Casa \t\t {2CC06B}$%s\n", IsMoney(HouseInfo[houseid][hPreco], "."));
        strcat(txt, String);
        format(String, 100, "{FFFFFF}Liberar Casa P/ o Servidor \t\t {2CC06B}$%s\n", IsMoney(HouseInfo[houseid][hPadrao], "."));
        strcat(txt, String);
        ShowPlayerDialog(playerid, MAIN_HOUSE, DIALOG_STYLE_TABLIST_HEADERS, "{FFD700}Menu Casa", txt, "Continuar", "Cancelar");
    }
    else if(IsPlayerResidentHouse(playerid, houseid))
    {
        strcat(txt, "{FFFFFF}Revogar Moradia \n");
        ShowPlayerDialog(playerid, MAIN_HOUSE, DIALOG_STYLE_LIST, "{FFD700}Menu Casa", txt, "Continuar", "Cancelar");
    }
    else
    {
        SendClientMessage(playerid, Erro, "Você não é dono(a)/morador(a) dessa casa");
    }
    return 1;
}
CMD:entrarcasa(playerid)
{
    if(dentrocasa[playerid] == 1)
        return SendClientMessage(playerid, Erro, "Você já está em uma casa");

    new houseid = LastHouseID[playerid];

    if(!IsPlayerInRangeOfPoint(playerid, 1.5, HouseInfo[houseid][iconx], HouseInfo[houseid][icony], HouseInfo[houseid][iconz]))
        return SendClientMessage(playerid, Erro, "Você não está em nenhuma porta de casa");

    if(strcmp(HouseInfo[houseid][hNome], PlayerInfo[playerid][Nome], true)==0)
    {
        format(String, MAX_STRING, "Bem vindo(a) a Casa ID %d em que você mora, Digite: /MenuCasa para acessar o menu!", HouseInfo[houseid][hID]);
    }
    else
    {
        if(strcmp(HouseInfo[houseid][hTrancada], "Sim", true)==0)
            return ShowPlayerDialog(playerid, MAIN_HOUSE_PASS, DIALOG_STYLE_INPUT, "{FF0000}Casa trancada", "{FFFFFF}Digite abaixo a senha da casa para entrar", "Entrar", "Cancelar");

        format(String, MAX_STRING, "Bem vindo(a) a Casa ID %d que pertence a %s", HouseInfo[houseid][hID], HouseInfo[houseid][hNome]);
    }

    dentrocasa[playerid] = 1;
    SendClientMessage(playerid, C_PROPERTY, String);
    SetPlayerVirtualWorld(playerid, HouseInfo[houseid][hID]);
    SetPlayerInterior(playerid, HouseInfo[houseid][hInterior]);
    SetPlayerPos(playerid, HouseInfo[houseid][hInteriorX], HouseInfo[houseid][hInteriorY], HouseInfo[houseid][hInteriorZ]);
    return 1;
}
CMD:saircasa(playerid)
{
    if(dentrocasa[playerid] != 1)
        return SendClientMessage(playerid, Erro, "Você não está em uma casa");

    new houseid = LastHouseID[playerid];

    if(!IsPlayerInRangeOfPoint(playerid, 2.0, HouseInfo[houseid][hInteriorX], HouseInfo[houseid][hInteriorY], HouseInfo[houseid][hInteriorZ]))
        return SendClientMessage(playerid, Erro, "Você está longe da porta");

    if(!strcmp(HouseInfo[houseid][hNome], PlayerInfo[playerid][Nome], true))
    {
        format(String, MAX_STRING, "Você saiu da sua casa %s", HouseInfo[houseid][hNome]);
    }
    else
    {
        format(String, MAX_STRING, "Você saiu da casa que pertence a %s", HouseInfo[houseid][hNome]);
    }

    dentrocasa[playerid] = 0;
    SendClientMessage(playerid, C_PROPERTY, String);
    SetPlayerVirtualWorld(playerid, 0);
    SetPlayerInterior(playerid, 0);
    SetPlayerPos(playerid, HouseInfo[houseid][iconx], HouseInfo[houseid][icony], HouseInfo[houseid][iconz]);
    return 1;
}
CMD:comprarcasa(playerid)
{
    new houseid = LastHouseID[playerid];

    if(!IsPlayerInRangeOfPoint(playerid, 1.5, HouseInfo[houseid][iconx], HouseInfo[houseid][icony], HouseInfo[houseid][iconz]))
        return SendClientMessage(playerid, Erro, "Você não está em nenhuma porta de casa");

    if(!Request_RealEstate[playerid][rre_house])
        return SendClientMessage(playerid, Erro, "Vcoê não tem requisição de compra de casas");

    new id;

    if(IsPlayerOwnerHouse(playerid))
        return SendClientMessage(playerid, Erro, "Você já tem uma casa");

    if(!strcmp(HouseInfo[houseid][hVendendo], "N/A"))
        return SendClientMessage(playerid, Erro, "Essa casa não está a venda");

    if(IsPlayerResidentHouse(playerid))
        return SendClientMessage(playerid, Erro, "Você está morando em um casa");

    GetPlayer2DZone(zone, MAX_ZONE_NAME, HouseInfo[houseid][iconx], HouseInfo[houseid][icony]);

    if(!strcmp(HouseInfo[houseid][hNome], "N/A"))
    {
        if(HouseInfo[houseid][hReais])
        {
            if(PlayerInfo[playerid][Dinheiro] < HouseInfo[houseid][hCusto] || PlayerInfo[playerid][Reais] < HouseInfo[houseid][hReais]) return SendClientMessage(playerid, Erro, "Você não tem esse dinheiro e/ou reais suficiente");
        }
        else if(!HouseInfo[houseid][hReais])
        {
            if(PlayerInfo[playerid][Dinheiro] < HouseInfo[houseid][hCusto]) return SendClientMessage(playerid, Erro, "Você não tem esse dinheiro em mãos");
        }

        PlayerInfo[playerid][Reais] -= HouseInfo[houseid][hReais];
        PlayerInfo[playerid][Dinheiro] -= HouseInfo[houseid][hCusto];
        format(String, MAX_STRING, "O(A) Jogador(a) %s comprou a casa ID %d localizada em %s", PlayerInfo[playerid][Nome], HouseInfo[houseid][hID], zone);
    }
    else if(strcmp(HouseInfo[houseid][hNome], "N/A"))
    {
        id = GetPlayerID(HouseInfo[houseid][hNome]);

        if(id == INVALID_PLAYER_ID)
            return SendClientMessage(playerid, Erro, "O(A) Proprietário(a) dessa casa não está conectado(a)");

        if(PlayerInfo[playerid][Dinheiro] < HouseInfo[houseid][hPreco])
            return SendClientMessage(playerid, Erro, "Você não tem esse dinheiro em mãos");

        format(String, MAX_STRING, "O(A) Jogador(a) %s comprou a sua casa e o seu dinheiro foi transferido direto pra sua conta bancária!", PlayerInfo[playerid][Nome], HouseInfo[houseid][hID], HouseInfo[houseid][hNome], zone);
        SendClientMessage(id, -1, String);
        format(String, MAX_STRING, "O(A) Jogador(a) %s comprou a casa ID %d que pertencia ao jogador(a) %s localizada em %s", PlayerInfo[playerid][Nome], HouseInfo[houseid][hID], HouseInfo[houseid][hNome], zone);

        PlayerInfo[id][SaldoBancario] += HouseInfo[houseid][hPreco];
        PlayerInfo[playerid][Dinheiro] -= HouseInfo[houseid][hPreco];
    }

    HouseInfo[houseid][hID] = houseid;
    format(HouseInfo[houseid][hNome], MAX_PLAYER_NAME, PlayerInfo[playerid][Nome]);
    format(HouseInfo[houseid][hM1], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[houseid][hM2], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[houseid][hM3], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[houseid][hM4], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[houseid][hM5], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[houseid][hM6], MAX_PLAYER_NAME, "N/A");
    format(HouseInfo[houseid][hMensagem], 15, "N/A");
    format(HouseInfo[houseid][hAlugando], 15, "N/A");
    format(HouseInfo[houseid][hVendendo], 5, "N/A");
    HouseInfo[houseid][hUp] = 1;
    HouseInfo[houseid][hPreco] = 0;
    format(HouseInfo[houseid][hTrancada], 5, "N/A");
    format(HouseInfo[houseid][hSenha], 24, "N/A");

    SendClientMessageToAll(-1, String);

    UpdatePlayerMoney(playerid);
    UpdatePlayerReais(playerid);

    UpgradeHouse(houseid);
    UpdateHouseExternal(houseid);
    UpdateHouses(houseid);
    return 1;
}
