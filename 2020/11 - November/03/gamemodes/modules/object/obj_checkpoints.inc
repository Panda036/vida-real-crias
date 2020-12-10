#include YSI\y_hooks

hook OnGameModeInit()
{
    cp_cnh = CreateDynamicCP(-2032.8086, -117.5343, 1035.1719, 1.0, -1, -1, -1, 30.0);

    cp_fines = CreateDynamicCP(823.4891, 3.1578, 1004.1797, 1.0, -1, -1, -1, 30.0);

    cp_mob = CreateDynamicCP(198.59, -234.24, 1.77, 1.0, -1, -1, -1, 30.0);

    CPS_StoreSkins[0] = CreateDynamicCP(207.5211, -101.4034, 1005.2578, 1.0, -1, -1);

    CPS_StoreWeapons[0] = CreateDynamicCP(295.7374, -37.5373, 1001.5156, 1.0, -1, -1);
    CPS_StoreWeapons[1] = CreateDynamicCP(312.3661, -165.0579, 999.6010, 1.0, -1, -1);
    CPS_StoreWeapons[2] = CreateDynamicCP(290.2912, -106.9782, 1001.5156, 1.0, -1, -1);
    CPS_StoreWeapons[3] = CreateDynamicCP(295.6494, -80.1824, 1001.5156, 1.0, -1, -1);
    CPS_StoreWeapons[4] = CreateDynamicCP(313.6798, -133.8826, 999.6016, 1.0, -1, -1);

    CPS_Utilities = CreateDynamicCP(-23.4721, -54.8974, 1003.5542, 1.0, -1, -1);

    CPS_Feed[0] = CreateDynamicCP(379.0999, -190.6961, 1000.6328, 1.0, -1, -1);
    CPS_Feed[1] = CreateDynamicCP(377.1639, -68.2976, 1001.5151, 1.0, -1, -1);
    CPS_Feed[2] = CreateDynamicCP(450.3587, -84.3551, 999.5547, 1.0, -1, -1);
    CPS_Feed[3] = CreateDynamicCP(369.4101, -6.6875, 1001.8516, 1.0, -1, -1);
    CPS_Feed[4] = CreateDynamicCP(375.5526, -119.6421, 1001.4995, 1.0, -1, -1);
    CPS_Feed[5] = CreateDynamicCP(-2653.4141, 1407.4714, 906.2771, 1.0, -1, -1);
    CPS_Feed[6] = CreateDynamicCP(1208.0060, -28.1842, 1000.9531, 1.0, -1, -1);
    CPS_Feed[7] = CreateDynamicCP(497.4057, -75.2601, 998.7578, 1.0, -1, -1);

    cp_mafia[0] = CreateDynamicCP(2445.82, -1970.11, 13.54, 1.0, -1, -1, -1, 50.0);
    cp_mafia[1] = CreateDynamicCP(2557.30, 2832.35, 10.82, 1.0, -1, -1, -1, 50.0);
    cp_mafia[2] = CreateDynamicCP(-2187.88, -234.58, 36.52, 1.0, -1, -1, -1, 50.0);

    cp_agencia = CreateDynamicCP(1490.8159, 1305.7130, 1093.2964, 1.0, -1, -1, -1, 30.0);

    cp_prision = CreateDynamicCP(248.94, 67.60, 1003.64, 1.0, -1, -1, -1, 30.0);
    return 1;
}

hook OnPlayerEnterCheckpoint(playerid)
{
    if(IsPlayerInDynamicCP(playerid, cp_prision))
        return PC_EmulateCommand(playerid, "/presos");

    if(IsPlayerInDynamicCP(playerid, cp_mob))
    {
        switch(PlayerInfo[playerid][Profissao])
        {
            case potplanter: ShowPlayerDialog(playerid, buy_cannabis, DIALOG_STYLE_INPUT, "{FF0000}Comprar Cannabis", "{FFFFFF}Digite abaixo a quantidade de muda de Cannabis que vai comprar\n\n{FF0000}Obs: Minímo 10 máximo 50", "Comprar", "Cancelar");
            case weaponproducer: ShowPlayerDialog(playerid, buy_weaponpiece, DIALOG_STYLE_INPUT, "{FF0000}Comprar Peça de Arma", "{FFFFFF}Digite abaixo a quantidade de peça de arma que vai comprar\n\n{FF0000}Obs: Minímo 10 máximo 50", "Comprar", "Cancelar");
        }
        return 1;
    }
    if(IsPlayerInDynamicCP(playerid, CPS_StoreSkins[0]))
    {
        SendClientMessage(playerid, C_PROPERTY, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        SendClientMessage(playerid, 0xFFFFFFAA, "Para comprar skin, digite: /Skins");
        SendClientMessage(playerid, 0xFFFFFFAA, "Para comprar acessório, digite: /Acessorios");
        SendClientMessage(playerid, C_PROPERTY, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        return 1;
    }
    if(IsPlayerInDynamicCP(playerid, CPS_Utilities))
    {
        new txt[1000];

        if(!IsPlayerMobile(playerid))
            { strcat(txt, "{FF0000}Produto \t {FF0000}Preço\t {CCCCCC}Unidade \n"); }

        strcat(txt, "{FFFFFF}Celular \t {00C40A}$1.000\t {CCCCCC}1 \n");
        strcat(txt, "{FFFFFF}Crédito SMS \t {00C40A}$500\t {CCCCCC}500 \n");
        strcat(txt, "{FFFFFF}Crédito Ligação \t {00C40A}$500\t {CCCCCC}500 \n");
        strcat(txt, "{FFFFFF}Galão de Combustível \t {00C40A}$100\t {CCCCCC}1 \n");
        strcat(txt, "{FFFFFF}Sem Parar \t {00C40A}$5.000\t {CCCCCC}5.000 \n");
        strcat(txt, "{FFFFFF}Mochila \t {00C40A}$900\t {CCCCCC}1 \n");
        strcat(txt, "{FFFFFF}Kit Reparos \t {00C40A}$1.200\t {CCCCCC}5 \n");

        ShowPlayerDialog(playerid, MAIN_UTILITIES, (IsPlayerMobile(playerid) ? DIALOG_STYLE_LIST : DIALOG_STYLE_TABLIST_HEADERS), "{FFD700}Menu Utilitários", txt, "Comprar", "Cancelar");
        return 1;
    }
    if(IsPlayerInDynamicCP(playerid, CPS_Feed[0]) || IsPlayerInDynamicCP(playerid, CPS_Feed[1]) || IsPlayerInDynamicCP(playerid, CPS_Feed[2]) || IsPlayerInDynamicCP(playerid, CPS_Feed[3]) || IsPlayerInDynamicCP(playerid, CPS_Feed[4]) || IsPlayerInDynamicCP(playerid, CPS_Feed[5]) || IsPlayerInDynamicCP(playerid, CPS_Feed[6]) || IsPlayerInDynamicCP(playerid, CPS_Feed[7]))
    {
        new txt[1000];

        if(!IsPlayerMobile(playerid))
            { strcat(txt, "{FF0000}Produto \t {FF0000}Preço \t {FF0000}Quantia\n"); }

        strcat(txt, "{FF0000}»» COMIDAS \n");
        strcat(txt, "{FFFFFF}Pizza \t {00C40A}$10 \t {C0C0C0}1\n");
        strcat(txt, "{FFFFFF}X-Bacon \t {00C40A}$5 \t {C0C0C0}1\n");
        strcat(txt, "{FFFFFF}X-Tudo \t {00C40A}$5 \t {C0C0C0}1\n");
        strcat(txt, "{FFFFFF}X-Salada \t {00C40A}$5 \t {C0C0C0}1\n");
        strcat(txt, "{FF0000}»» BEBIDAS \n");
        strcat(txt, "{FFFFFF}Água \t {00C40A}$2 \t {C0C0C0}1\n");
        strcat(txt, "{FFFFFF}Fanta \t {00C40A}$5 \t {C0C0C0}1\n");
        strcat(txt, "{FFFFFF}Coca-Cola \t {00C40A}$10 \t {C0C0C0}1\n");
        strcat(txt, "{FFFFFF}Dolly \t {00C40A}$5 \t {C0C0C0}1\n");
        strcat(txt, "{FFFFFF}Sprite \t {00C40A}$5 \t {C0C0C0}1\n");

        ShowPlayerDialog(playerid, MAIN_FEED, (IsPlayerMobile(playerid) ? DIALOG_STYLE_LIST : DIALOG_STYLE_TABLIST_HEADERS), "{FFD700}Menu Cardápio", txt, "Comprar", "Cancelar");
        return 1;
    }
    if(IsPlayerInDynamicCP(playerid, CPS_StoreWeapons[0]) || IsPlayerInDynamicCP(playerid, CPS_StoreWeapons[1]) || IsPlayerInDynamicCP(playerid, CPS_StoreWeapons[2]) || IsPlayerInDynamicCP(playerid, CPS_StoreWeapons[3]) || IsPlayerInDynamicCP(playerid, CPS_StoreWeapons[4]))
    {
        new txt[1000];

        if(!IsPlayerMobile(playerid))
            { strcat(txt, "{FF0000}Produto \t {FF0000}Preço \t {FF0000}Munição\n"); }

        strcat(txt, "{FFFFFF}AK-47 \t {00C40A}$3.250 \t {C0C0C0}750\n");
        strcat(txt, "{FFFFFF}M4A1 \t {00C40A}$3.500 \t {C0C0C0}650\n");
        strcat(txt, "{FFFFFF}Shotgun \t {00C40A}$500 \t {C0C0C0}500\n");
        strcat(txt, "{FFFFFF}Sawed-off \t {00C40A}$500 \t {C0C0C0}900\n");
        strcat(txt, "{FFFFFF}Combat Shotgun \t {00C40A}$500 \t {C0C0C0}500\n");
        strcat(txt, "{FFFFFF}Deagle \t {00C40A}$650 \t {C0C0C0}450\n");
        strcat(txt, "{FFFFFF}Silenced \t {00C40A}$500 \t {C0C0C0}350\n");
        strcat(txt, "{FFFFFF}Colt 45 \t {00C40A}$250 \t {C0C0C0}300\n");
        strcat(txt, "{FFFFFF}Dinamites \t {00C40A}$500 \t {C0C0C0}10 uni.\n");
        strcat(txt, "{FFFFFF}Colete 50% \t {00C40A}$2.000 \t {C0C0C0}1 uni.\n");
        strcat(txt, "{FFFFFF}Vender Armas \t {00C40A}$200 \t {C0C0C0}1 uni.\n");

        ShowPlayerDialog(playerid, MAIN_WEAPON, (IsPlayerMobile(playerid) ? DIALOG_STYLE_LIST : DIALOG_STYLE_TABLIST_HEADERS), "{FFD700}Menu Armas", txt, "Comprar", "Cancelar");
        return 1;
    }
    if(IsPlayerInDynamicCP(playerid, cp_cnh))
    {
        new txt[500];

        strcat(txt, "{FFFFFF}Categoria\t {FF8000}Veículos\t {1b6302}Valor/Status\n");

        format(String, MAX_STRING, "{FFFFFF}A\t {FF8000}Motos\t {1b6302}%s\n", (IsValidSchedulingCNH(playerid, "a") ? ("Agendado") : ("$800")));
        strcat(txt, String);

        format(String, MAX_STRING, "{FFFFFF}B\t {FF8000}Carros\t {1b6302}%s\n", (IsValidSchedulingCNH(playerid, "b") ? ("Agendado") : ("$1.600")));
        strcat(txt, String);

        format(String, MAX_STRING, "{FFFFFF}C\t {FF8000}Caminhões/Onibus/Carretas\t {1b6302}%s\n", (IsValidSchedulingCNH(playerid, "c") ? ("Agendado") : ("$2.400")));
        strcat(txt, String);

        format(String, MAX_STRING, "{FFFFFF}Cht\t {FF8000}Aéreos\t {1b6302}%s\n", (IsValidSchedulingCNH(playerid, "cht") ? ("Agendado") : ("$7.000")));
        strcat(txt, String);

        format(String, MAX_STRING, "{FFFFFF}Arrais\t {FF8000}Aquáticos\t {1b6302}%s\n", (IsValidSchedulingCNH(playerid, "arrais") ? ("Agendado") : ("$3.600")));
        strcat(txt, String);

        ShowPlayerDialog(playerid, main_cnh, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Carteira Nacional de Habilitação", txt, "Selecionar", "Fechar");
        return 1;
    }
    if(IsPlayerInDynamicCP(playerid, cp_fines))
    {
        new txt[500];

        strcat(txt, "{FFFFFF}Carteira\t {FFFF00}Multas\t {1b6302}Valor\n");

        format(String, 100, "{FFFFFF}Categoria A\t {FFFF00}%d\t {1b6302}$%s\n", PlayerInfo[playerid][fines_a], IsMoney(800, "."));
        strcat(txt, String);

        format(String, 100, "{FFFFFF}Categoria B\t {FFFF00}%d\t {1b6302}$%s\n", PlayerInfo[playerid][fines_b], IsMoney(1600, "."));
        strcat(txt, String);

        format(String, 100, "{FFFFFF}Categoria C\t {FFFF00}%d\t {1b6302}$%s\n", PlayerInfo[playerid][fines_c], IsMoney(2400, "."));
        strcat(txt, String);

        format(String, 100, "{FFFFFF}Cht\t {FFFF00}%d\t {1b6302}$%s\n", PlayerInfo[playerid][fines_cht], IsMoney(7000, "."));
        strcat(txt, String);

        format(String, 100, "{FFFFFF}Arrais\t {FFFF00}%d\t {1b6302}$%s\n", PlayerInfo[playerid][fines_arrais], IsMoney(3600, "."));
        strcat(txt, String);

        ShowPlayerDialog(playerid, main_fines, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Multas Detran", txt, "Selecionar", "Fechar");
        return 1;
    }
    Agency_Checkpoint(playerid);
	return 1;
}
