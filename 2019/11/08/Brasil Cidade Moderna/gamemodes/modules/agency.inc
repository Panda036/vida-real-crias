#include YSI\y_hooks

hook OnPlayerConnect(playerid)
{
    SetTimerEx("UpdateAgencyMapIcon", 5000, true, "i", playerid);
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == agency)
    {
        if(response)
        {
            switch(listitem)
            {
                case 0:
                {
                    new string[200];
                    strcat(string,"{FFFFFF}Profissão\t{FF0000}Level\t{1CEB00}Salario \n{FFFFFF}Entregador(a) de Jornal\t {F71616}0\t {1CEB00}$250\n{FFFFFF}Advogado(a)\t {F71616}100\t {1CEB00}$1000");
                    ShowPlayerDialog(playerid, honest, DIALOG_STYLE_TABLIST_HEADERS, "{00ff00}Honesta", string, "Selecionar", "Voltar");
                }
                case 1:
                {
                    new string[200];
                    strcat(string,"{FFFFFF}Profissão\t{FF0000}Level\t{1CEB00}Salario \n{FFFFFF}Taxi\t{F71616}5\t {1CEB00}$350");
                    ShowPlayerDialog(playerid, transport, DIALOG_STYLE_TABLIST_HEADERS, "{707070}Transporte", string, "Selecionar", "Voltar");
                }
                case 2:
                {
                    new string[200];
                    strcat(string,"{FFFFFF}Profissão\t{FF0000}Level\t{1CEB00}Salario \n{FFFFFF}Policia Municipal\t {F71616}100\t {1CEB00}$1000");
                    ShowPlayerDialog(playerid, police, DIALOG_STYLE_TABLIST_HEADERS, "{0000ff}Policia", string, "Selecionar", "Voltar");
                }
                case 3:
                {
                    new string[200];
                    strcat(string,"{FFFFFF}Profissão\t {FF0000}Level\t {1CEB00}Salario \n{FFFFFF}Corregedoria\t {F71616}1000\t {1CEB00}$5000");
                    ShowPlayerDialog(playerid, government, DIALOG_STYLE_TABLIST_HEADERS, "{0000ff}Policia", string, "Selecionar", "Voltar");
                }
            }
        }
        return 1;
    }
    if(dialogid == mob)
    {
        if(response)
        {
            switch(listitem)
            {
                case 0:
                {
                    if(PlayerInfo[playerid][Level] < 0)
                        return 0;

                    if(IsPlayerUniformePM(playerid))
                        { SetPlayerSkin(playerid, PlayerInfo[playerid][Skin]); }

                    //Evitando Bugs
                    DestroyPickup(PEmprego[playerid]);
                    RemovePlayerMapIcon(playerid, 35);

                    PlayerInfo[playerid][Profissao] = Desempregado;
                    PlayerInfo[playerid][Semprofissao] = LadraoGas;
                    PEmprego[playerid] = CreatePickup(1210, 1, -453.7872, 2230.1296, 42.4993);
                    SetPlayerMapIcon(playerid, 35, -453.7872, 2230.1296, 42.4993, 53, 0, MAPICON_GLOBAL);
                    SetColorProfession(playerid);
                    PlayerPlaySound(playerid, 1057, 0, 0, 0);
                    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Encaminhamento - {FFFFFF}Agencia de Empregos", "{FFFFFF}Você foi aceito no cargo {00FF00}Ladrão de Gás \n\n{FFFFFF}Para iniciar os serviços siga a bandeira {FF0000}Preta e Branca {FFFFFF}em seu radar", "Fechar", "");
                }
            }
        }
        return 1;
    }
    if(dialogid == honest)
    {
        if(!response)
            return ShowPlayerDialog(playerid, agency, DIALOG_STYLE_LIST, "{FF0000}Menu Empregos", "{FFFFFF}Classe » {80FF80}Honesta \n{FFFFFF}Classe » {80FFFF}Transporte \n{FFFFFF}Classe » {51A8FF}Policia \n{FFFFFF}Classe » {626262}Governo ", "Selecionar", "Fechar");

        if(response)
        {
            switch(listitem)
            {
                case 0:
                {
                    if(PlayerInfo[playerid][Level] < 0)
                        return 0;

                    if(IsPlayerUniformePM(playerid))
                        { SetPlayerSkin(playerid, PlayerInfo[playerid][Skin]); }

                    //Evitando Bugs
                    DestroyPickup(PEmprego[playerid]);
                    RemovePlayerMapIcon(playerid, 35);

                    PlayerInfo[playerid][Profissao] = Desempregado;
                    PlayerInfo[playerid][Semprofissao] = EntregadorJornal;
                    PEmprego[playerid] = CreatePickup(1210, 1, 785.2020, -1327.7697, 13.5469);
                    SetPlayerMapIcon(playerid, 35, 785.2020, -1327.7697, 13.5469, 53, 0, MAPICON_GLOBAL);
                    SetColorProfession(playerid);
                    PlayerPlaySound(playerid, 1057, 0, 0, 0);
                    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Encaminhamento - {FFFFFF}Agencia de Empregos", "{FFFFFF}Você foi aceito no emprego {00FF00}Entregador(a) de Jornal \n\n{FFFFFF}Para iniciar os serviços siga a bandeira {FF0000}Preta e Branca {FFFFFF}em seu radar", "Fechar", "");
                }
                case 1:
                {
                    if(PlayerInfo[playerid][Level] < 100)
                        return SendClientMessage(playerid, Erro, "| ERRO | Você não tem level suficiente para pegar essa profissão.");

                    if(IsPlayerUniformePM(playerid))
                        { SetPlayerSkin(playerid, PlayerInfo[playerid][Skin]); }

                    //Evitando Bugs
                    DestroyPickup(PEmprego[playerid]);
                    RemovePlayerMapIcon(playerid, 35);

                    PlayerInfo[playerid][Profissao] = Desempregado;
                    PlayerInfo[playerid][Semprofissao] = EntregadorJornal;
                    PEmprego[playerid] = CreatePickup(1210, 1, 785.2020, -1327.7697, 13.5469);
                    SetPlayerMapIcon(playerid, 35, 785.2020, -1327.7697, 13.5469, 53, 0, MAPICON_GLOBAL);
                    SetColorProfession(playerid);
                    PlayerPlaySound(playerid, 1057, 0, 0, 0);
                    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Encaminhamento - {FFFFFF}Agencia de Empregos", "{FFFFFF}Você foi aceito no emprego {00FF00}Entregador(a) de Jornal \n\n{FFFFFF}Para iniciar os serviços siga a bandeira {FF0000}Preta e Branca {FFFFFF}em seu radar", "Fechar", "");
                }
            }
        }
        return 1;
    }
    if(dialogid == transport)
    {
        if(!response)
            return ShowPlayerDialog(playerid, agency, DIALOG_STYLE_LIST, "{FF0000}Menu Empregos", "{FFFFFF}Classe » {80FF80}Honesta \n{FFFFFF}Classe » {80FFFF}Transporte \n{FFFFFF}Classe » {51A8FF}Policia \n{FFFFFF}Classe » {626262}Governo ", "Selecionar", "Fechar");

        if(response)
        {
            switch(listitem)
            {
                case 0:
                {
                    if(PlayerInfo[playerid][Level] < 5)
                        return SendClientMessage(playerid, Erro, "| ERRO | Você não tem level suficiente para pegar essa profissão.");

                    if(IsPlayerUniformePM(playerid))
                        { SetPlayerSkin(playerid, PlayerInfo[playerid][Skin]); }

                    //Evitando Bugs
                    DestroyPickup(PEmprego[playerid]);
                    RemovePlayerMapIcon(playerid, 35);

                    PlayerInfo[playerid][Profissao] = Desempregado;
                    PlayerInfo[playerid][Semprofissao] = Taxi;
                    PEmprego[playerid] = CreatePickup(1210, 1, 2229.5803, -1368.1969, 23.99221);
                    SetPlayerMapIcon(playerid, 35, 2229.5803, -1368.1969, 23.99221, 53, 0, MAPICON_GLOBAL);
                    SetColorProfession(playerid);
                    PlayerPlaySound(playerid, 1057, 0, 0, 0);
                    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Encaminhamento - {FFFFFF}Agencia de Empregos", "{FFFFFF}Você foi aceito no emprego {00FF00}Taxi \n\n{FFFFFF}Para iniciar os serviços siga a bandeira {FF0000}Preta e Branca {FFFFFF}em seu radar", "Fechar", "");
                }
            }
        }
        return 1;
    }
    if(dialogid == police)
    {
        if(!response)
            return ShowPlayerDialog(playerid, agency, DIALOG_STYLE_LIST, "{FF0000}Menu Empregos", "{FFFFFF}Classe » {80FF80}Honesta \n{FFFFFF}Classe » {80FFFF}Transporte \n{FFFFFF}Classe » {51A8FF}Policia \n{FFFFFF}Classe » {626262}Governo ", "Selecionar", "Fechar");

        if(response)
        {
            switch(listitem)
            {
                case 0:
                {
                    if(PlayerInfo[playerid][Level] < 100)
                        return SendClientMessage(playerid, Erro, "| ERRO | Você não tem level suficiente para pegar essa profissão.");

                    if(IsPlayerUniformePM(playerid))
                        { SetPlayerSkin(playerid, PlayerInfo[playerid][Skin]); }

                    //Evitando Bugs
                    DestroyPickup(PEmprego[playerid]);
                    RemovePlayerMapIcon(playerid, 35);

                    PlayerInfo[playerid][Profissao] = Desempregado;
                    PlayerInfo[playerid][Semprofissao] = PoliciaMunicipal;
                    PEmprego[playerid] = CreatePickup(1210, 1, 1579.5728, -1635.3932, 13.5611);
                    SetPlayerMapIcon(playerid, 35, 1579.5728, -1635.3932, 13.5611, 53, 0, MAPICON_GLOBAL);
                    SetColorProfession(playerid);
                    PlayerPlaySound(playerid, 1057, 0, 0, 0);
                    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Encaminhamento - {FFFFFF}Agencia de Empregos", "{FFFFFF}Você foi aceito no emprego {00FF00}Policia Municipal \n\n{FFFFFF}Para iniciar os serviï¿½os siga a bandeira {FF0000}Preta e Branca {FFFFFF}em seu radar", "Fechar", "");
                }
            }
        }
        return 1;
    }
    if(dialogid == government)
    {
        if(!response)
            return ShowPlayerDialog(playerid, agency, DIALOG_STYLE_LIST, "{FF0000}Menu Empregos", "{FFFFFF}Classe » {80FF80}Honesta \n{FFFFFF}Classe » {80FFFF}Transporte \n{FFFFFF}Classe » {51A8FF}Policia \n{FFFFFF}Classe » {626262}Governo ", "Selecionar", "Fechar");

        if(response)
        {
            switch(listitem)
            {
                case 0:
                {
                    if(PlayerInfo[playerid][Level] < 1000)
                        return SendClientMessage(playerid, Erro, "| ERRO | Você não tem level suficiente para pegar essa profissão.");

                    if(IsPlayerUniformePM(playerid))
                        { SetPlayerSkin(playerid, PlayerInfo[playerid][Skin]); }

                    //Evitando Bugs
                    DestroyPickup(PEmprego[playerid]);
                    RemovePlayerMapIcon(playerid, 35);

                    PlayerInfo[playerid][Profissao] = Desempregado;
                    PlayerInfo[playerid][Semprofissao] = Corregedoria;
                    PEmprego[playerid] = CreatePickup(1210, 1, 2339.9778, 2457.2256, 14.9688);
                    SetPlayerMapIcon(playerid, 35, 2339.9778, 2457.2256, 14.9688, 53, 0, MAPICON_GLOBAL);
                    SetColorProfession(playerid);
                    PlayerPlaySound(playerid, 1057, 0, 0, 0);
                    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Encaminhamento - {FFFFFF}Agencia de Empregos", "{FFFFFF}Você foi aceito no emprego {00FF00}Corregedoria \n\n{FFFFFF}Para iniciar os serviços siga a bandeira {FF0000}Preta e Branca {FFFFFF}em seu radar", "Fechar", "");
                }
            }
        }
        return 1;
    }
    return 1;
}

forward UpdateAgencyMapIcon(playerid);
public UpdateAgencyMapIcon(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 200.0, 1154.0808,-1771.9812,16.5992)) //Agencia LS
    {
        SetPlayerMapIcon(playerid,0,1154.0808,-1771.9812,16.5992,23,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 0);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, 937.8450,1733.1957,8.8516))    //Agencia LV
    {
        SetPlayerMapIcon(playerid,1,937.8450,1733.1957,8.8516,23,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 1);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, -2171.8110,252.0813,35.3378))  //Agencia SF
    {
        SetPlayerMapIcon(playerid,2,-2171.8110,252.0813,35.3378,23,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 2);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, 1481.0637,-1770.9515,18.7958)) //Prefeitura LS
    {
        SetPlayerMapIcon(playerid,3,1481.0637,-1770.9515,18.7958,42,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 3);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, 2447.0620,2376.2354,12.1635))  //Prefeitura LV
    {
        SetPlayerMapIcon(playerid,4,2447.0620,2376.2354,12.1635,42,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 4);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, -2765.8796,375.5812,6.3347))   //Prefeitura SF
    {
        SetPlayerMapIcon(playerid,5,-2765.8796,375.5812,6.3347,42,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 5);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, 1554.8657,-1675.6693,16.1953)) // Departamento LS
    {
        SetPlayerMapIcon(playerid,6,1554.8657,-1675.6693,16.1953,30,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 6);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, 2290.1218,2430.9775,10.8203))  // Departamento LV
    {
        SetPlayerMapIcon(playerid,7,2290.1218,2430.9775,10.8203,30,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 7);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, -1605.5848,710.8436,13.8672))  // Departamento SF
    {
        SetPlayerMapIcon(playerid,8,-1605.5848,710.8436,13.8672,30,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 8);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, 627.7621,-571.7207,17.5526))  // Departamento DM
    {
        SetPlayerMapIcon(playerid,9,627.7621,-571.7207,17.5526,30,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 9);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, 1172.6787,-1323.3129,15.4022)) // Hospital LS
    {
        SetPlayerMapIcon(playerid,10,1172.6787,-1323.3129,15.4022,22,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 10);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, 1607.3579,1815.6309,10.8203))  // Hospital LV
    {
        SetPlayerMapIcon(playerid,11,1607.3579,1815.6309,10.8203,22,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 11);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, -2655.0662,639.1497,14.4531))  // Hospital SF
    {
        SetPlayerMapIcon(playerid,12,-2655.0662,639.1497,14.4531,22,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 12);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, -1514.8217,2520.3232,55.9185))  // Hospital EL
    {
        SetPlayerMapIcon(playerid,13,-1514.8217,2520.3232,55.9185,22,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 13);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, 1241.8073,327.1022,19.7555))  // Hospital MG
    {
        SetPlayerMapIcon(playerid,14,1241.8073,327.1022,19.7555,22,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 14);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, -320.0716,1049.2637,20.3403))  // Hospital FC
    {
        SetPlayerMapIcon(playerid,15,-320.0716,1049.2637,20.3403,22,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 15);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, -2223.1670,-2293.6865,31.6719))  // Hospital AP
    {
        SetPlayerMapIcon(playerid,16,-2223.1670,-2293.6865,31.6719,22,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 16);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, 1778.3052,-1663.5337,14.4362)) // Banco LS
    {
        SetPlayerMapIcon(playerid,17,1778.3052,-1663.5337,14.4362,52,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 17);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, 2388.6733,2466.0430,10.8203))  // Banco LV
    {
        SetPlayerMapIcon(playerid,18,2388.6733,2466.0430,10.8203,52,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 18);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, -2649.8374,376.0090,6.1563))   // Banco SF
    {
        SetPlayerMapIcon(playerid,19,-2649.8374,376.0090,6.1563,52,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 19);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, -180.3883,1133.1510,19.7422))  // Banco FC
    {
        SetPlayerMapIcon(playerid,20,-180.3883,1133.1510,19.7422,52,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 20);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, 1372.9271,405.2487,19.9555))   // Banco MG
    {
        SetPlayerMapIcon(playerid,21,1372.9271,405.2487,19.9555,52,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 21);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, 2302.9521,-16.2789,26.4844))   // Banco PC
    {
        SetPlayerMapIcon(playerid,22,2302.9521,-16.2789,26.4844,52,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 22);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, -828.0650,1503.6166,19.7585))  // Banco LB
    {
        SetPlayerMapIcon(playerid,23,-828.0650,1503.6166,19.7585,52,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 23);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, -1480.8273,2592.3015,55.8359)) // Banco EQ
    {
        SetPlayerMapIcon(playerid,24,-1480.8273,2592.3015,55.8359,52,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 24);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, 207.7767,-62.5814,1.6498))     // Banco BB
    {
        SetPlayerMapIcon(playerid,25,207.7767,-62.5814,1.6498,52,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 25);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, 1798.4763,-1578.3191,14.0849)) // Imobiliaria LS
    {
        SetPlayerMapIcon(playerid,26,1798.4763,-1578.3191,14.0849,58,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 26);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, 2413.2390,1123.8374,10.8203))  // Imobiliaria LV
    {
        SetPlayerMapIcon(playerid,27,2413.2390,1123.8374,10.8203,58,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 27);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, -1881.1293,822.7573,35.1773))  // Imobiliaria SF
    {
        SetPlayerMapIcon(playerid,28,-1881.1293,822.7573,35.1773,58,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 28);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, 1519.0413,-1453.5895,14.2073)) // Auto Escola LS
    {
        SetPlayerMapIcon(playerid,29,1519.0413,-1453.5895,14.2073,36,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 29);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, 2183.2483,2295.2205,10.8203))  // Auto Escola LV
    {
        SetPlayerMapIcon(playerid,30,2183.2483,2295.2205,10.8203,36,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 30);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, -2026.5950,-101.3410,35.1641)) // Auto Escola SF
    {
        SetPlayerMapIcon(playerid,31,-2026.5950,-101.3410,35.1641,36,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 31);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, 1310.1411,-1367.8086,13.5408)) // Detran LS
    {
        SetPlayerMapIcon(playerid,32,1310.1411,-1367.8086,13.5408,19,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 32);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, 1173.1600,1349.0011,10.9219))  // Detran LV
    {
        SetPlayerMapIcon(playerid,33,1173.1600,1349.0011,10.9219,19,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 33);
    }
    if(IsPlayerInRangeOfPoint(playerid, 200.0, -2720.6375,127.7373,7.0391))   // Detran SF
    {
        SetPlayerMapIcon(playerid,34,-2720.6375,127.7373,7.0391,19,MAPICON_LOCAL);
    } else {
        RemovePlayerMapIcon(playerid, 34);
    }
    return 1;
}
