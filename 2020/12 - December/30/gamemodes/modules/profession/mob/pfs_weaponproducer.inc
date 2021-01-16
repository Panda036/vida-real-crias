/***************************************************************
*
*   04/09/2020
*
*   Obs: N/A
*
*/

#include YSI\y_hooks

new producerState[MAX_PLAYERS];
new t_producer[MAX_PLAYERS];
new bool:wpOffer[MAX_PLAYERS];
new bool:wpRefused[MAX_PLAYERS];
new bool:wpAccepted[MAX_PLAYERS];
new wpCount[MAX_PLAYERS];

enum e_aarea
{
    Float:aa_x,
    Float:aa_y,
    Float:aa_z
};

new AssemblyArea[MAX_ZONE_WP][e_aarea] =
{
    {-2174.84, -249.44, 35.99},
    {-2160.67, -246.70, 35.99},
    {-2164.07, -246.73, 35.99},
    {-2167.75, -246.74, 35.99},
    {-2171.25, -246.63, 35.99},
    {-2174.77, -246.67, 35.99},
    {-2160.82, -249.40, 35.99},
    {-2164.15, -249.35, 35.99},
    {-2167.78, -249.37, 35.99},
    {-2171.27, -249.41, 35.99},
    {-2157.20, -246.74, 35.99},
    {-2157.22, -249.30, 35.99}
};

hook OnGameModeInit()
{
    for(new areaid = 0; areaid < MAX_ZONE_WP; areaid++)
    {
        CreateDynamic3DTextLabel("Área de Montagem\n{FF0000}Arma", 0xFFFFFFFF, AssemblyArea[areaid][aa_x], AssemblyArea[areaid][aa_y], AssemblyArea[areaid][aa_z], 30.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, WORLD_DEFAULT, 0);
        CreateDynamicPickup(2061, 1, AssemblyArea[areaid][aa_x], AssemblyArea[areaid][aa_y], AssemblyArea[areaid][aa_z]);
    }
    return 1;
}

hook OnPlayerConnect(playerid)
{
    //Remove gás and one bug
    RemoveBuildingForPlayer(playerid, 11088, -2166.8750, -236.5156, 40.8594, 0.25);
    RemoveBuildingForPlayer(playerid, 11282, -2166.8750, -236.5156, 40.8594, 0.25);
    RemoveBuildingForPlayer(playerid, 918, -2182.4453, -237.6953, 35.8750, 0.25);
    RemoveBuildingForPlayer(playerid, 918, -2153.0859, -256.2734, 35.8750, 0.25);
    RemoveBuildingForPlayer(playerid, 918, -2173.5938, -268.0781, 40.0781, 0.25);
    RemoveBuildingForPlayer(playerid, 918, -2148.4922, -230.8047, 35.8750, 0.25);
    RemoveBuildingForPlayer(playerid, 918, -2143.4688, -230.3438, 35.8750, 0.25);
    RemoveBuildingForPlayer(playerid, 918, -2167.8281, -246.0859, 35.8750, 0.25);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(PRESSED(KEY_NO) && PlayerInfo[playerid][Profissao] == weaponproducer)
    {
        for(new areaid = 0; areaid < MAX_ZONE_WP; areaid++)
        {
            if(IsPlayerInRangeOfPoint(playerid, 2.0, AssemblyArea[areaid][aa_x], AssemblyArea[areaid][aa_y], AssemblyArea[areaid][aa_z]))
            {
                if(producerState[playerid])
                    return SendClientMessage(playerid, Erro, "Você já está produzindo arma");

                if(!GetIntQuery(playerid, "Itens", "weaponpiece"))
                    return SendClientMessage(playerid, Erro, "Você não tem \"peças\" vá até o fornecedor");

                TogglePlayerControllable(playerid, false);
                ShowPlayerDialog(playerid, weapon_producer, DIALOG_STYLE_LIST, "{FF0000}Escolha à arma", "{FFFFFF}AK-47\nM4\nDesert Eagle\nUzi\nSawnoff\nCombat Shotgun\nSniper", "Continuar", "Fechar");
                return 1;
            }
        }
        return 1;
    }
	return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case weapon_producer:
        {

            if(!response)
                return TogglePlayerControllable(playerid, true);

            ShowTDLoading(playerid);
            SetIntQuery(playerid, "Itens", "weaponpiece", (GetIntQuery(playerid, "Itens", "weaponpiece")-1));
            return OnPlayerWeaponProducer(playerid, true, listitem);
        }
        case wp_get:
        {
            if(!response)
                return 1;

            new value = GetIntQuery(playerid, "WeaponProducer", wp_WeaponName(wp_WeaponID(listitem)));

            if(!value)
                return SendClientMessage(playerid, Erro, "Você não tem essa arma montada");

            GivePlayerWeapon(playerid, wp_WeaponID(listitem), 999);
            SetIntQuery(playerid, "WeaponProducer", wp_WeaponName(wp_WeaponID(listitem)), (value-1));
            return 1;
        }
    }
	return 1;
}

forward OnPlayerWeaponProducer(playerid, bool:status, weaponid);
public OnPlayerWeaponProducer(playerid, bool:status, weaponid)
{
    if(status)
    {
        producerState[playerid]++;

        ApplyAnimation(playerid, "DEALER", "DEALER_DEAL", 4.0, 0, 0, 0, 500, 0);

        PlayerTextDrawTextSize(playerid, TDPlayerLoading[playerid][0], (500.4 + ((104.3 * producerState[playerid]) / 60)), 0.0);
        PlayerTextDrawShow(playerid, TDPlayerLoading[playerid][0]);

        format(String, 10, "%d%%", returnPorcentage(producerState[playerid], 60));
        PlayerTextDrawSetString(playerid, TDPlayerLoading[playerid][1], String);
        PlayerTextDrawShow(playerid, TDPlayerLoading[playerid][1]);

        if(producerState[playerid] >= 60)
        {
            status = false;
            producerState[playerid] = 0;
        }

        t_producer[playerid] = SetTimerEx("OnPlayerWeaponProducer", 500, false, "dbd", playerid, status, weaponid);
    }
    else
    {
        switch(weaponid)
        {
            case 0: SetIntQuery(playerid, "WeaponProducer", "ak", (GetIntQuery(playerid, "WeaponProducer", "ak")+1));
            case 1: SetIntQuery(playerid, "WeaponProducer", "m4", (GetIntQuery(playerid, "WeaponProducer", "m4")+1));
            case 2: SetIntQuery(playerid, "WeaponProducer", "pistol", (GetIntQuery(playerid, "WeaponProducer", "pistol")+1));
            case 3: SetIntQuery(playerid, "WeaponProducer", "uzi", (GetIntQuery(playerid, "WeaponProducer", "uzi")+1));
            case 4: SetIntQuery(playerid, "WeaponProducer", "sawnoff", (GetIntQuery(playerid, "WeaponProducer", "sawnoff")+1));
            case 5: SetIntQuery(playerid, "WeaponProducer", "combat", (GetIntQuery(playerid, "WeaponProducer", "combat")+1));
            case 6: SetIntQuery(playerid, "WeaponProducer", "sniper", (GetIntQuery(playerid, "WeaponProducer", "sniper")+1));
        }

        HideTDLoading(playerid);
        ClearAnimations(playerid);
        TogglePlayerControllable(playerid, true);
        PlayerPlaySound(playerid, 1057, 0.0, 0.0, 10.0);

        SendClientMessage(playerid, Green, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        SendClientMessage(playerid, White, "Arma montada, você pode realizar as seguintes ações:");
        SendClientMessage(playerid, White, "- Pegar para sí");
        SendClientMessage(playerid, White, "- Vender para um(a) Jogador(a)");
        SendClientMessage(playerid, White, "- Vender para alguma empresa de armas");
        SendClientMessage(playerid, Green, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

        KillTimer(t_producer[playerid]);
    }
    return 1;
}

forward OfferWeapon(playerid, offerid, weaponid, value);
public OfferWeapon(playerid, offerid, weaponid, value)
{
    if(wpOffer[offerid])
    {
        if(wpCount[offerid] == 10)
        {
            SendClientMessage(playerid, Yellow, "Sua oferta foi recusada");
            SendClientMessage(offerid, Yellow, "Seu tempo de aceitar ou recusar acabou");
            wpCount[offerid] = 0;
            wpOffer[offerid] = false;
            return 1;
        }

        wpCount[offerid]++;
        switch(wpCount[offerid])
        {
            case 1, 3, 5, 7, 9: SendClientMessage(offerid, 0x00B57DAA, "Para aceitar ou recusar digite ( /aceitar ou /recusar )");
        }
        return SetTimerEx("OfferWeapon", 1000, false, "dddd", playerid, offerid, weaponid, value);
    }
    else
    {
        if(wpAccepted[offerid])
        {
            GivePlayerWeapon(offerid, weaponid, 2000);

            PlayerInfo[playerid][Dinheiro] += value;
            UpdatePlayerMoney(playerid);
            PlayerInfo[offerid][Dinheiro] -= value;
            UpdatePlayerMoney(offerid);

            SetIntQuery(playerid, "WeaponProducer", wp_WeaponName(weaponid), (GetIntQuery(playerid, "WeaponProducer", wp_WeaponName(weaponid))-1));

            SendClientMessage(offerid, 0xFFD993AA, "Você aceitou à oferta");
            SendClientMessage(playerid, 0xFFD993AA, "Sua oferta foi aceita");
            wpAccepted[offerid] = false;
        }
        else
        {
            SendClientMessage(playerid, 0xFFD993AA, "Sua oferta foi recusada");
            SendClientMessage(offerid, 0xFFD993AA, "Você recusou à oferta");
            wpRefused[offerid] = false;
        }
    }
    return 1;
}

stock wp_WeaponID(listitem)
{
    switch(listitem)
    {
        case 0: return 30;
        case 1: return 31;
        case 2: return 24;
        case 3: return 28;
        case 4: return 26;
        case 5: return 27;
        case 6: return 34;
    }
    return 1;
}

stock wp_WeaponName(weaponid)
{
    new str[10];

    switch(weaponid)
    {
        case 30: str = "ak";
        case 31: str = "m4";
        case 24: str = "pistol";
        case 28: str = "uzi";
        case 26: str = "sawnoff";
        case 27: str = "combat";
        case 34: str = "sniper";
    }
    return str;
}

/******************************************************************************/
/*******************************| COMMANDS WP |********************************/
/******************************************************************************/

CMD:armas(playerid)
{
    if(PlayerInfo[playerid][Profissao] != weaponproducer)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    new txt[500];

    strcat(txt, "{FF4000}Arma\t {1B6302}Quantia\t{CCCCCC}ID\n");

    format(String, MAX_STRING, "{FF4000}AK-47\t {1B6302}%d\t{CCCCCC}30\n", GetIntQuery(playerid, "WeaponProducer", "ak"));
    strcat(txt, String);
    format(String, MAX_STRING, "{FF4000}M4\t {1B6302}%d\t{CCCCCC}31\n", GetIntQuery(playerid, "WeaponProducer", "m4"));
    strcat(txt, String);
    format(String, MAX_STRING, "{FF4000}Desert Eagle\t {1B6302}%d\t{CCCCCC}24\n", GetIntQuery(playerid, "WeaponProducer", "pistol"));
    strcat(txt, String);
    format(String, MAX_STRING, "{FF4000}Uzi\t {1B6302}%d\t{CCCCCC}28\n", GetIntQuery(playerid, "WeaponProducer", "uzi"));
    strcat(txt, String);
    format(String, MAX_STRING, "{FF4000}Sawnoff\t {1B6302}%d\t{CCCCCC}26\n", GetIntQuery(playerid, "WeaponProducer", "sawnoff"));
    strcat(txt, String);
    format(String, MAX_STRING, "{FF4000}Combat Shotgun\t {1B6302}%d\t{CCCCCC}27\n", GetIntQuery(playerid, "WeaponProducer", "combat"));
    strcat(txt, String);
    format(String, MAX_STRING, "{FF4000}Sniper\t {1B6302}%d\t{CCCCCC}34\n", GetIntQuery(playerid, "WeaponProducer", "sniper"));
    strcat(txt, String);

    ShowPlayerDialog(playerid, wp_get, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Armas Montadas", txt, "Pegar", "Cancelar");
    return 1;
}
CMD:venderarma(playerid, params[])
{
    if(PlayerInfo[playerid][Profissao] != weaponproducer)
        return SendClientMessage(playerid, Erro, "Você não tem permissão");

    new id, weaponid, value;

    if(sscanf(params, "ddd", id, weaponid, value))
        return SendClientMessage(playerid, Erro, "/VenderArma [id][id-arma][valor]");

    if(id == INVALID_PLAYER_ID || !PlayerInfo[id][Logado])
        return SendClientMessage(playerid, Erro, "Jogador(a) não conectado(a)");

    if(playerid == id)
        return SendClientMessage(playerid, Erro, "Você não pode efetuar comando em sí mesmo");

    if(GetDistanceBetweenPlayers(playerid, id) > 15)
        return SendClientMessage(playerid, Erro, "Você está muito longe, chegue mais perto");

    if(!GetIntQuery(playerid, "WeaponProducer", wp_WeaponName(weaponid)))
        return SendClientMessage(playerid, Erro, "Você não tem essa arma montada");

    if(value < MIN_OFFER_WP || value > MAX_OFFER_WP)
    {
        format(String, MAX_STRING, "Digite um valor de %d à %d", MIN_OFFER_WP, MAX_OFFER_WP);
        SendClientMessage(playerid, Erro, String);
        return 1;
    }

    wpOffer[id] = true;
    OfferWeapon(playerid, id, weaponid, value);
    return 1;
}
