/************************************************************
* OWNER :
*        Henrique Calenzo
*
* START DATE :
*       24/06/2020
*
* NOTES :
*       Copyright Vida Real Crias 2019 - 2020.  All rights reserved.
*
*/

#include modules\database\db_bases

#include YSI\y_hooks

hook OnGameModeInit()
{
    //Base ID:4
    CreateDynamicObject(8210, -75.51639, -315.37888, 5.90660,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(987, -75.45000, -384.02689, 4.31540,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(987, -75.45000, -372.15430, 4.31540,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(987, -75.45000, -361.95380, 4.31540,   0.00000, 0.00000, -90.00000);

    //Machine Weapon
    CreateDynamicObject(18885, 2131.91577, -2284.01099, 20.71170, 0.00000, 0.00000, 225.00000);

    //Machine food
    CreateDynamicObject(1776, 2134.24927, -2281.72095, 20.58335,   0.00000, 0.00000, 225.00000);

    //Door and Wall for interior
    CreateDynamicObject(3109, 2119.67578, -2275.15601, 20.83970, 0.00000, 0.00000, 46.00000);
    CreateDynamicObject(19459, 2177.96118, -2255.01587, 16.33571, 0.00000, 0.00000, 313.93149);
    CreateDynamicObject(19459, 2177.96118, -2255.01587, 12.88840, 180.00000, 0.00000, 313.93149);

    //Base Enter Object
    CreateDynamicObject(3749, -489.74841, -562.07550, 29.91760, 0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3749, 1067.39734, 1362.07642, 15.68420, 0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3749, 997.13770, 2133.24023, 15.59720, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(3749, 1017.84210, 2133.53345, 15.62200, 0.00000, 0.00000, 90.00000);
    CreateDynamicObject(3749, -75.35417, -352.12625, 6.26710, 0.00000, 0.00000, 90.00000);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    //Base 3
    RemoveBuildingForPlayer(playerid, 3474, 978.2891, 2094.9922, 16.7422, 0.25);

    SetTimer("OnBaseRelease", 5000, true);

    SetTimerEx("OnPlayerInBase", 2000, true, "d", playerid);
    return 1;
}

hook OnPlayerDisconnect(playerid)
{
    KillTimer(t_getweapon[playerid]);
    t_getweapon[playerid] = 0;
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(PRESSED(KEY_SECONDARY_ATTACK))
    {
        if(InBase[playerid] == -1)
        {
            for(new baseid = 0; baseid < MAX_BASES; baseid++)
            {
                if(IsPlayerInRangeOfPoint(playerid, 2.0, BaseEnter[baseid][be_x], BaseEnter[baseid][be_y], BaseEnter[baseid][be_z]))
                {
                    if(BaseInfo[baseid][bi_lock] && !IsPlayerOwnerBase(playerid, baseid))
                    {
                        InBase[playerid] = baseid;
                        ShowPlayerDialog(playerid, base_locked, DIALOG_STYLE_INPUT, "{FF0000}Senha Base", "{FFFFFF}Digite à senha desta Base para poder entrar", "Continuar", "Cancelar");
                        return 1;
                    }

                    InBase[playerid] = baseid;
                    SetPlayerVirtualWorld(playerid, InBase[playerid]);
                    SetPlayerInterior(playerid, 0);
                    SetPlayerFacingAngle(playerid, -45.0);
                    SetPlayerPos(playerid, 2120.77, -2272.97, 20.67);

                    format(String, MAX_STRING, (IsPlayerOwnerBase(playerid, baseid) ? ("Seja bem-vindo(a) à sua Base ID %d, %s") : ("Seja bem-vindo(a) à Base ID %d, que pertencê ao jogador(a) %s")), baseid, BaseInfo[baseid][bi_owner]);
                    SendClientMessage(playerid, color_base, String);
                    break;
                }
            }
            return 1;
        }
        else
        {
            if(IsPlayerInRangeOfPoint(playerid, 2.0, 2120.77, -2272.97, 20.67))
            {
                new baseid = InBase[playerid];

                SetPlayerVirtualWorld(playerid, 0);
                SetPlayerInterior(playerid, 0);
                SetPlayerFacingAngle(playerid, BaseEnter[baseid][be_a]);
                SetPlayerPos(playerid, BaseEnter[baseid][be_x], BaseEnter[baseid][be_y], BaseEnter[baseid][be_z]);
                InBase[playerid] = -1;
                return 1;
            }
            else if(IsPlayerInRangeOfPoint(playerid, 1.5, 2131.91, -2284.01, 20.71))
            {
                if(!IsPlayerMemberBaseEx(playerid, InBase[playerid]))
                    return SendClientMessage(playerid, Erro, "Você não tem permissão");

                if(t_getweapon[playerid])
                    return SendClientMessage(playerid, Erro, "Aguarde alguns segundos para poder pegar arma");

                new txt[500];
                strcat(txt, "{FFFFFF}Granada de explosão\n");
                strcat(txt, "{FFFFFF}Granada de Gás\n");
                strcat(txt, "{FFFFFF}Molotov\n");
                strcat(txt, "{FFFFFF}9mm\n");
                strcat(txt, "{FFFFFF}9mm + Silenciador\n");
                strcat(txt, "{FFFFFF}Desert Eagle\n");
                strcat(txt, "{FFFFFF}Shotgun\n");
                strcat(txt, "{FFFFFF}Sawnoff Shotgun\n");
                strcat(txt, "{FFFFFF}Combat Shotgun\n");
                strcat(txt, "{FFFFFF}Micro SMG/Uzi\n");
                strcat(txt, "{FFFFFF}MP5\n");
                strcat(txt, "{FFFFFF}AK-47\n");
                strcat(txt, "{FFFFFF}M4\n");
                strcat(txt, "{FFFFFF}Tec-9\n");
                strcat(txt, "{FFFFFF}Contry Rifle\n");
                strcat(txt, "{FFFFFF}Sniper Rifle\n");
                ShowPlayerDialog(playerid, base_weapon, DIALOG_STYLE_LIST, "{FF0000}Base Armas", txt, "Pegar", "Cancelar");
                return 1;
            }
            else if(IsPlayerInRangeOfPoint(playerid, 1.5, 2134.24, -2281.72, 20.58))
            {
                ApplyAnimation(playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0);

                PlayerInfo[playerid][Health] += 20.0;
                UpdatePlayerHealth(playerid);

                Progress[playerid][Fome] -= 20.0;
                Progress[playerid][Sede] -= 20.0;

                if(Progress[playerid][Fome] < 0.0) Progress[playerid][Fome] = 0.0;
                if(Progress[playerid][Sede] < 0.0) Progress[playerid][Sede] = 0.0;

                UpdateProgressBar(playerid);
                return 1;
            }
            return 1;
        }
    }
	return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(InBase[playerid] != -1)
    {
        switch(dialogid)
        {
            case base_weapon:
            {
                switch(listitem)
                {
                    case 0: GivePlayerWeapon(playerid, 16, 1);
                    case 1: GivePlayerWeapon(playerid, 17, 1);
                    case 2: GivePlayerWeapon(playerid, 18, 1);
                    case 3: GivePlayerWeapon(playerid, 22, 500);
                    case 4: GivePlayerWeapon(playerid, 23, 500);
                    case 5: GivePlayerWeapon(playerid, 24, 500);
                    case 6: GivePlayerWeapon(playerid, 25, 900);
                    case 7: GivePlayerWeapon(playerid, 26, 900);
                    case 8: GivePlayerWeapon(playerid, 27, 1500);
                    case 9: GivePlayerWeapon(playerid, 28, 1500);
                    case 10: GivePlayerWeapon(playerid, 29, 1500);
                    case 11: GivePlayerWeapon(playerid, 30, 2000);
                    case 12: GivePlayerWeapon(playerid, 31, 2000);
                    case 13: GivePlayerWeapon(playerid, 32, 1500);
                    case 14: GivePlayerWeapon(playerid, 33, 1500);
                    case 15: GivePlayerWeapon(playerid, 34, 500);
                }

                t_getweapon[playerid] = SetTimerEx("UnlockToGetWeapon", 10000, false, "d", playerid);
                return 1;
            }
            case base_menu:
            {
                switch(listitem)
                {
                    case 0:
                    {
                        if(!response) return 0;

                        new baseid = InBase[playerid];

                        if(!IsPlayerOwnerBase(playerid, baseid) && !IsPlayerSubBase(playerid, baseid))
                            return SendClientMessage(playerid, Erro, "Você não tem permissão");

                        ShowPlayerDialog(playerid, base_tag_color, DIALOG_STYLE_INPUT, "{FF0000}Alterar cor TAG", "{FFFFFF}Digite uma nova cor HTML para TAG da Base", "Continuar", "Cancelar");
                        return 1;
                    }
                    case 1:
                    {
                        if(!response) return 0;

                        new baseid = InBase[playerid];

                        if(!IsPlayerOwnerBase(playerid, baseid) && !IsPlayerSubBase(playerid, baseid))
                            return SendClientMessage(playerid, Erro, "Você não tem permissão");

                        ShowPlayerDialog(playerid, base_tag, DIALOG_STYLE_INPUT, "{FF0000}Alterar TAG", "{FFFFFF}Digite uma nova TAG para sua Base", "Continuar", "Cancelar");
                        return 1;
                    }
                    case 2:
                    {
                        if(!response) return 0;

                        new baseid = InBase[playerid];

                        if(!IsPlayerOwnerBase(playerid, baseid) && !IsPlayerSubBase(playerid, baseid))
                            return SendClientMessage(playerid, Erro, "Você não tem permissão");

                        ShowPlayerDialog(playerid, base_name, DIALOG_STYLE_INPUT, "{FF0000}Alterar Nome", "{FFFFFF}Digite um novo nome para sua Base", "Continuar", "Cancelar");
                        return 1;
                    }
                    case 3:
                    {
                        if(!response) return 0;

                        new baseid = InBase[playerid];

                        if(!IsPlayerOwnerBase(playerid, baseid) && !IsPlayerSubBase(playerid, baseid))
                            return SendClientMessage(playerid, Erro, "Você não tem permissão");

                        ShowPlayerDialog(playerid, base_dm, DIALOG_STYLE_LIST, "{FF0000}Death Match", (BaseInfo[InBase[playerid]][bi_dm] ? ("{FFFFFF}Desativar DM") : ("{FFFFFF}Ativar DM")), "Continuar", "Cancelar");
                        return 1;
                    }
                    case 4:
                    {
                        if(!response) return 0;

                        new baseid = InBase[playerid];

                        if(!IsPlayerOwnerBase(playerid, baseid) && !IsPlayerSubBase(playerid, baseid))
                            return SendClientMessage(playerid, Erro, "Você não tem permissão");

                        new txt[200];

                        strcat(txt, "{FFFFFF}Alterar senha\n");
                        format(String, MAX_STRING, "{FFFFFF}%s\n", BaseInfo[InBase[playerid]][bi_lock] ? ("Destrancar") : ("Trancar"));
                        strcat(txt, String);

                        ShowPlayerDialog(playerid, base_lock, DIALOG_STYLE_LIST, "{FF0000}Alterar Status", txt, "Continuar", "Cancelar");
                        return 1;
                    }
                    case 5:
                    {
                        if(!response) return 0;

                        new baseid = InBase[playerid];

                        if(!IsPlayerOwnerBase(playerid, baseid) && !IsPlayerSubBase(playerid, baseid))
                            return SendClientMessage(playerid, Erro, "Você não tem permissão");

                        BaseInfo[baseid][bi_invasion] = (BaseInfo[baseid][bi_invasion] ? 0 : 1);

                        new query[200];
                        mysql_format(IDConexao, query, 200, "UPDATE `Base` SET `invasion`='%d' WHERE `id`='%d'", BaseInfo[baseid][bi_invasion], baseid);
                        mysql_query(IDConexao, query);

                        SendClientMessage(playerid, White, (BaseInfo[baseid][bi_invasion] ? ("Invasão de base ativada") : ("Invasão de base desativada")));
                        return 1;
                    }
                    case 6:
                    {
                        if(!response) return 0;

                        new baseid = InBase[playerid];

                        if(!IsPlayerMemberBaseEx(playerid, baseid))
                            return SendClientMessage(playerid, Erro, "Você não tem permissão");

                        new txt[816];

                        for(new memberid = 0; memberid < MAX_BASE_MEMBERS; memberid++)
                        {
                            format(String, MAX_STRING, "{FFFFFF}%s\n", BaseMember[baseid][memberid]);
                            strcat(txt, String);
                        }

                        ShowPlayerDialog(playerid, base_members, DIALOG_STYLE_LIST, "{FF0000}Membros Base", txt, "Continuar", "Cancelar");
                        return 1;
                    }
                    case 7:
                    {
                        if(!response) return 0;

                        new baseid = InBase[playerid];

                        if(!IsPlayerOwnerBase(playerid, baseid) && !IsPlayerSubBase(playerid, baseid))
                            return SendClientMessage(playerid, Erro, "Você não tem permissão");

                        new txt[300];

                        strcat(txt, (!IsPlayerMobile(playerid) ? ("{CCCCCC}ID\t {FFFFFF}Nome\t Status\n") : (#)));

                        for(new i = 0; i < MAX_VEHICLE_BASE; i++)
                        {
                            format(String, MAX_STRING, "{CCCCCC}%dº\t {FFFFFF}%s\t %s\n", (i + 1), getVehicleName(VehicleBase[baseid][i][vb_model]), (VehicleBase[baseid][i][vb_connect] ? ("{1B6302}Conectado") : ("{FF4000}Desconectado")));
                            strcat(txt, String);
                        }

                        ShowPlayerDialog(playerid, base_vehicle, ( IsPlayerMobile(playerid) ? DIALOG_STYLE_LIST : DIALOG_STYLE_TABLIST_HEADERS ), "{FF0000}Veículos Base", txt, "Continuar", "Cancelar");
                        return 1;
                    }
                    case 8:
                    {
                        if(!response) return 0;

                        new baseid = InBase[playerid];

                        if(!IsPlayerOwnerBase(playerid, baseid))
                            return SendClientMessage(playerid, Erro, "Você não tem permissão");

                        new txt[200];

                        strcat(txt, (!IsPlayerMobile(playerid) ? ("{FF0000}Funções \t\t {1CEB00}Status \n") : (#)));

                        format(String, 100, "{FFFFFF}Vendendo: \t\t %s\n", (BaseInfo[baseid][bi_selling] ? ("Sim") : ("Não")));
                        strcat(txt, String);
                        format(String, 100, "{FFFFFF}Alterar Valor: \t\t $%s \n", IsMoney(BaseInfo[baseid][bi_price], "."));
                        strcat(txt, String);

                        ShowPlayerDialog(playerid, base_sell_list, (!IsPlayerMobile(playerid) ? (DIALOG_STYLE_TABLIST_HEADERS) : (DIALOG_STYLE_LIST)), "{FF0000}Vender/Alterar preço", txt, "Selecionar", "Cancelar");
                        return 1;
                    }
                    case 9:
                    {
                        if(!response) return 0;

                        if(!IsPlayerOwnerBase(playerid, InBase[playerid]))
                            return SendClientMessage(playerid, Erro, "Você não tem permissão");

                        ShowPlayerDialog(playerid, base_code, DIALOG_STYLE_INPUT, "{FF0000}Código de Confirmação", "{FFFFFF}Para liberar sua base para o servidor é necessário o código de confirmação\n\n{FF4000}Obs: o código de vericação é o mesmo usado para registrar sua conta!", "Continuar", "Cancelar");
                        return 1;
                    }
                    case 10:
                    {
                        if(!response) return 0;

                        new baseid = InBase[playerid];

                        if(!IsPlayerOwnerBase(playerid, baseid) && !IsPlayerSubBase(playerid, baseid))
                            return SendClientMessage(playerid, Erro, "Você não tem permissão");

                        new txt[200];

                        format(String, 150, "{FFFFFF}Valor: {1B6302}R$ -%d,00\n\n", BASE_REAIS_RENOVATION);
                        strcat(txt, String);
                        strcat(txt, "{FF4000}Deseja continuar com a renovação?");

                        ShowPlayerDialog(playerid, base_renovation, DIALOG_STYLE_MSGBOX, "{FF0000}Renovaçào de base", txt, "Renovar", "Cancelar");
                        return 1;
                    }
                }
                return 1;
            }
            case base_sell_list:
            {
                if(!response) return 0;

                new baseid = InBase[playerid];

                if(!IsPlayerOwnerBase(playerid, baseid)) return 0;

                switch(listitem)
                {
                    case 0:
                    {
                        if(!BaseInfo[baseid][bi_selling] && !BaseInfo[baseid][bi_price])
                            return SendClientMessage(playerid, Erro, "Primeiro altere o valor de sua base para continuar");

                        BaseInfo[baseid][bi_selling] = (BaseInfo[baseid][bi_selling] ? 0 : 1);
                        SendClientMessage(playerid, color_base, (BaseInfo[baseid][bi_selling] ? ("Agora sua base está à venda") : ("Agora sua base não está mais à venda")));

                        new query[200];
                        mysql_format(IDConexao, query, 200, "UPDATE `Bases` SET `selling`='%d' WHERE `id`='%d'", BaseInfo[baseid][bi_selling], baseid);
                        mysql_query(IDConexao, query);

                        UpdateBaseInformation(baseid);
                        return 1;
                    }
                    case 1:
                    {
                        new txt[200];
                        strcat(txt, "{FFFFFF}Digite abaixo um preço que será somado com valor padrão.\n\n");
                        format(String, 100, "{FF4000}Observação: valor padrão é $%s", IsMoney(BASE_MONEY, "."));
                        strcat(txt, String);

                        ShowPlayerDialog(playerid, base_sell_value, DIALOG_STYLE_INPUT, "{FF0000}Alterar preço", txt, "Selecionar", "Cancelar");
                        return 1;
                    }
                }
                return 1;
            }
            case base_sell_value:
            {
                if(!response) return 0;

                new baseid = InBase[playerid], txt[200];

                if(!IsPlayerOwnerBase(playerid, baseid)) return 0;

                if(!IsNumeric(inputtext))
                {
                    strcat(txt, "{FFFFFF}Digite abaixo um preço que será somado com valor padrão.\n\n");
                    format(String, 100, "{FF4000}Observação: valor padrão é $%s", IsMoney(BASE_MONEY, "."));
                    strcat(txt, String);
                    ShowPlayerDialog(playerid, base_sell_value, DIALOG_STYLE_INPUT, "{FF0000}Alterar preço", txt, "Selecionar", "Cancelar");
                    return 1;
                }
                if(strval(inputtext) < 1 || strval(inputtext) > MAX_PRICE_BASE)
                {
                    strcat(txt, "{FFFFFF}Digite abaixo um preço que será somado com valor padrão.\n\n");
                    format(String, 100, "{FF4000}Observação: valor máximo para vemda é de: $%s", IsMoney(MAX_PRICE_BASE, "."));
                    strcat(txt, String);
                    ShowPlayerDialog(playerid, base_sell_value, DIALOG_STYLE_INPUT, "{FF0000}Alterar preço", txt, "Selecionar", "Cancelar");
                    return 1;
                }

                BaseInfo[baseid][bi_price] = ( strval(inputtext) + BASE_MONEY);

                new query[200];
                mysql_format(IDConexao, query, 200, "UPDATE `Bases` SET `price`='%d' WHERE `id`='%d'", BaseInfo[baseid][bi_price], baseid);
                mysql_query(IDConexao, query);

                UpdateBaseInformation(baseid);

                SendClientMessage(playerid, color_base, "O preço da base foi alterado");
                return 1;
            }
            case base_renovation:
            {
                if(!response)
                    return SendClientMessage(playerid, Erro, "Renovação de base cancelada");

                if(PlayerInfo[playerid][Reais] < BASE_REAIS_RENOVATION)
                    return SendClientMessage(playerid, Erro, "Reais insuficiente para renovação");

                PlayerInfo[playerid][Reais] -= BASE_REAIS_RENOVATION;
                UpdatePlayerReais(playerid);

                new baseid = InBase[playerid];

                BaseInfo[baseid][bi_renovation] += ONE_MONTH;

                new query[200];
                mysql_format(IDConexao, query, 200, "UPDATE `Bases` SET `renovation`='%d' WHERE `id`='%d'", BaseInfo[baseid][bi_renovation], baseid);
                mysql_query(IDConexao, query);

                SendClientMessage(playerid, color_base, "Renovação de base efetuada");
                return 1;
            }
            case base_tag_color:
            {
                if(!response) return 0;

                if(strlen(inputtext) != 6)
                    return ShowPlayerDialog(playerid, base_tag_color, DIALOG_STYLE_INPUT, "{FF0000}Alterar cor TAG", "{FFFFFF}Digite uma nova cor HTML para TAG da Base\n\n{FF4000}Digite uma cor HTML de 6 digitos", "Continuar", "Cancelar");

                new baseid = InBase[playerid];

                format(BaseInfo[baseid][bi_tagcolor], 10, inputtext);

                new query[200];
                mysql_format(IDConexao, query, 200, "UPDATE `Base` SET `tagcolor`='%s' WHERE `id`='%d'", inputtext, baseid);
                mysql_query(IDConexao, query);

                format(String, MAX_STRING, "Cor da TAG de sua base foi alterada para [{%s}%s{FFFFFF}]", BaseInfo[baseid][bi_tagcolor], BaseInfo[baseid][bi_tag]);
                SendClientMessage(playerid, White, String);
                return 1;
            }
            case base_name:
            {
                if(!response) return 0;

                if(!IsValidNameBase(inputtext))
                    return ShowPlayerDialog(playerid, base_name, DIALOG_STYLE_INPUT, "{FF0000}Nome Base", "{FFFFFF}Digite um novo nome de sua Base\n{FF4000}Erro, o nome de sua Base!", "Continuar", "Cancelar");

                new result = AlterNameBase(InBase[playerid], inputtext);

                if(!result)
                    return ShowPlayerDialog(playerid, base_name, DIALOG_STYLE_INPUT, "{FF0000}Nome Base", "{FFFFFF}Digite um novo nome de sua Base\n{FF4000}Erro, o nome de Base digitado já existente!", "Continuar", "Cancelar");

                format(String, MAX_STRING, "Nome da Base alterada para \"%s\"", inputtext);
                SendClientMessage(playerid, color_base, String);
                return 1;
            }
            case base_vehicle:
            {
                if(!response) return 0;

                VehicleBaseList[playerid] = listitem;

                new baseid = InBase[playerid];
                new listid = listitem;
                new txt[200];

                strcat(txt, ( VehicleBase[baseid][listid][vb_connect] ? ("{FFFFFF}Desconectar veículo \n") : ("{FFFFFF}Conectar veículo \n")));

                format(String, MAX_STRING, "{FF0000}%dº %s", (listid + 1), getVehicleName(VehicleBase[baseid][listid][vb_model]));

                ShowPlayerDialog(playerid, base_vehicle_state, DIALOG_STYLE_LIST, String, txt, "Continuar", "Cancelar");
                return 1;
            }
            case base_vehicle_state:
            {
                if(response)
                    return OnBaseStateVehicle(InBase[playerid], VehicleBaseList[playerid]);
            }
            case base_members:
            {
                if(!response) return 0;

                memberID[playerid] = listitem;

                new baseid = InBase[playerid];
                new memberid = listitem;

                if(!IsPlayerMemberBaseEx(playerid, baseid))
                    return SendClientMessage(playerid, Erro, "Você não tem permissão");

                if(strcmp(BaseMember[baseid][memberid], PlayerInfo[playerid][Nome]) && !IsPlayerOwnerBase(playerid))
                    return SendClientMessage(playerid, Erro, "Você não tem permissão");

                format(String, MAX_STRING, "{FF0000}%s", BaseMember[baseid][memberid]);

                new txt[200];

                if(!IsPlayerOwnerBase(playerid, baseid))
                    strcat(txt, !strcmp(BaseMember[baseid][memberid], "N/A") ? (#) : ("{FFFFFF}Revogar da base\n"));
                else
                    strcat(txt, !strcmp(BaseMember[baseid][memberid], "N/A") ? ("{FFFFFF}Adicionar membro\n") : ("{FFFFFF}Remover membro\n"));

                if(IsPlayerOwnerBase(playerid, baseid) && strcmp(BaseMember[baseid][memberid], "N/A"))
                    strcat(txt, !strcmp(BaseInfo[baseid][bi_sub], "N/A") ? ("{FFFFFF}Promover p/ sub-lider\n") : ("{FFFFFF}Rebaixar sub-lider\n"));

                ShowPlayerDialog(playerid, base_members_alter, DIALOG_STYLE_LIST, String, txt, "Continuar", "Cancelar");
                return 1;
            }
            case base_members_alter:
            {
                if(!response) return 0;

                new baseid = InBase[playerid];
                new memberid = memberID[playerid];

                switch(listitem)
                {
                    case 0:
                    {
                        if(!strcmp(BaseMember[baseid][memberid], "N/A"))
                            return ShowPlayerDialog(playerid, base_members_add, DIALOG_STYLE_INPUT, "{FF0000}Adicionar membro", "{FFFFFF}Digite abaixo o ID do jogador(a)", "Continuar", "Cancelar");

                        if(!strcmp(BaseInfo[baseid][bi_sub], BaseMember[baseid][memberid])) format(BaseInfo[baseid][bi_sub], MAX_PLAYER_NAME, "N/A");

                        format(BaseMember[baseid][memberid], MAX_PLAYER_NAME, "N/A");
                        UpdateMemberBase(baseid, memberid);

                        SendClientMessage(playerid, color_base, (!strcmp(BaseMember[baseid][memberid], PlayerInfo[playerid][Nome]) ? ("Você revogou da base") : ("Jogador(a) removido da Base")));
                        return 1;
                    }
                    case 1:
                    {
                        if(strcmp(BaseInfo[baseid][bi_sub], BaseMember[baseid][memberid]))
                        {
                            if(strcmp(BaseInfo[baseid][bi_sub], "N/A"))
                                return SendClientMessage(playerid, Erro, "Já tem um sub-lider nesta base, primeiro remova-o");

                            format(BaseInfo[baseid][bi_sub], MAX_PLAYER_NAME, BaseMember[baseid][memberid]);
                            UpdateSubBase(baseid);
                            return 1;
                        }

                        format(BaseInfo[baseid][bi_sub], MAX_PLAYER_NAME, "N/A");
                        UpdateMemberBase(baseid, memberid);

                        SendClientMessage(playerid, color_base, "Jogador(a) rebaixado para membro base");
                        return 1;
                    }
                }
                return 1;
            }
            case base_members_add:
            {
                if(!response) return 0;

                new baseid = InBase[playerid];
                new memberid = memberID[playerid];

                if(strval(inputtext) < 0 || strval(inputtext) >= MAX_PLAYERS)
                    return ShowPlayerDialog(playerid, base_members_add, DIALOG_STYLE_INPUT, "{FF0000}Adicionar membro", "{FFFFFF}Digite abaixo o ID do jogador(a)\n{FF4000}ID inválido", "Continuar", "Cancelar");

                new id = strval(inputtext);

                if(id == playerid)
                    return ShowPlayerDialog(playerid, base_members_add, DIALOG_STYLE_INPUT, "{FF0000}Adicionar membro", "{FFFFFF}Digite abaixo o ID do jogador(a)\n{FF4000}Não é possível adicionar você mesmo", "Continuar", "Cancelar");

                if(!PlayerInfo[id][Logado])
                    return ShowPlayerDialog(playerid, base_members_add, DIALOG_STYLE_INPUT, "{FF0000}Adicionar membro", "{FFFFFF}Digite abaixo o ID do jogador(a)\n{FF4000}Jogador(a) não está logado(a)", "Continuar", "Cancelar");

                if(InBase[id] != baseid)
                    return ShowPlayerDialog(playerid, base_members_add, DIALOG_STYLE_INPUT, "{FF0000}Adicionar membro", "{FFFFFF}Digite abaixo o ID do jogador(a)\n{FF4000}Jogador(a) não está em sua Base", "Continuar", "Cancelar");

                if(IsPlayerMemberBase(id))
                    return ShowPlayerDialog(playerid, base_members_add, DIALOG_STYLE_INPUT, "{FF0000}Adicionar membro", "{FFFFFF}Digite abaixo o ID do jogador(a)\n{FF4000}Jogador(a) já pertênce à uma Base", "Continuar", "Cancelar");

                format(String, MAX_STRING, "Você adicionou o(a) jogador(a) %s[%d] como membro desta Base", PlayerInfo[id][Nome], id);
                SendClientMessage(playerid, color_base, String);
                format(String, MAX_STRING, "O(A) Jogador(a) %s[%d] adicionou você como membro desta Base", PlayerInfo[playerid][Nome], playerid);
                SendClientMessage(id, color_base, String);

                format(BaseMember[baseid][memberid], MAX_PLAYER_NAME, PlayerInfo[id][Nome]);
                UpdateMemberBase(baseid, memberid);
                return 1;
            }
            case base_dm:
            {
                if(!response) return 0;

                new baseid = InBase[playerid];

                BaseInfo[baseid][bi_dm] = (BaseInfo[baseid][bi_dm] ? 0 : 1);

                new query[200];
                mysql_format(IDConexao, query, 200, "UPDATE `Bases` SET `dm`='%d' WHERE `id`='%d'", BaseInfo[baseid][bi_dm], baseid);
                mysql_query(IDConexao, query);
                return 1;
            }
            case base_tag:
            {
                if(!response) return 0;

                if(!IsValidTagBase(inputtext))
                    return ShowPlayerDialog(playerid, base_tag, DIALOG_STYLE_INPUT, "{FF0000}Alterar TAG", "{FFFFFF}Digite uma nova TAG para sua Base\n{FF4000}TAG inválida", "Continuar", "Cancelar");

                new result = AlterTagBase(InBase[playerid], inputtext);

                if(!result)
                    return ShowPlayerDialog(playerid, base_tag, DIALOG_STYLE_INPUT, "{FF0000}Alterar TAG", "{FFFFFF}Digite uma nova TAG para sua Base\n{FF4000}Erro, TAG de Base digitada já existente!", "Continuar", "Cancelar");

                format(String, MAX_STRING, "TAG da Base alterada para \"%s\"", inputtext);
                SendClientMessage(playerid, color_base, String);
                return 1;
            }
            case base_lock:
            {
                if(!response) return 0;

                switch(listitem)
                {
                    case 0:
                    {
                        ShowPlayerDialog(playerid, base_pass, DIALOG_STYLE_INPUT, "{FF0000}Alterar senha", "{FFFFFF}Digite abaixo à nova senha da Base", "Continuar", "Cancelar");
                        return 1;
                    }
                    case 1:
                    {
                        new baseid = InBase[playerid];

                        BaseInfo[baseid][bi_lock] = (BaseInfo[baseid][bi_lock] ? 0 : 1);

                        new query[200];
                        mysql_format(IDConexao, query, 200, "UPDATE `Bases` SET `lock`='%d' WHERE `id`='%d'", BaseInfo[baseid][bi_lock], baseid);
                        mysql_query(IDConexao, query);

                        SendClientMessage(playerid, color_base, (BaseInfo[baseid][bi_lock] ? ("Base trancada") : ("Base destrancada")));
                        UpdateBaseInformation(baseid);
                        return 1;
                    }
                }
                return 1;
            }
            case base_pass:
            {
                if(!response) return 0;

                if(!IsValidPassBase(inputtext))
                    return ShowPlayerDialog(playerid, base_pass, DIALOG_STYLE_INPUT, "{FF0000}Alterar senha", "{FFFFFF}Digite abaixo à nova senha da Base\n{FF4000}Erro, somente letras e números!", "Continuar", "Cancelar");

                new baseid = InBase[playerid];

                format(BaseInfo[baseid][bi_pass], MAX_BASE_PASS, inputtext);

                new query[200];
                mysql_format(IDConexao, query, 200, "UPDATE `Bases` SET `pass`='%e' WHERE `id`='%d'", BaseInfo[baseid][bi_pass], baseid);
                mysql_query(IDConexao, query);
                return 1;
            }
            case base_locked:
            {
                if(!response){
                    InBase[playerid] = -1;
                    return 0;
                }

                if(!IsValidPassBase(inputtext))
                    return ShowPlayerDialog(playerid, base_locked, DIALOG_STYLE_INPUT, "{FF0000}Senha Base", "{FFFFFF}Digite à senha desta Base para poder entrar\n{FF4000}Senha Inválida!", "Continuar", "Cancelar");

                if(strcmp(BaseInfo[InBase[playerid]][bi_pass], inputtext))
                    return ShowPlayerDialog(playerid, base_locked, DIALOG_STYLE_INPUT, "{FF0000}Senha Base", "{FFFFFF}Digite à senha desta Base para poder entrar\n{FF4000}Senha Inválida!", "Continuar", "Cancelar");

                SetPlayerVirtualWorld(playerid, InBase[playerid]);
                SetPlayerInterior(playerid, 0);
                SetPlayerFacingAngle(playerid, -45.0);
                SetPlayerPos(playerid, 2120.77, -2272.97, 20.67);

                if(!strcmp(BaseInfo[InBase[playerid]][bi_owner], PlayerInfo[playerid][Nome]))
                    format(String, MAX_STRING, "Seja bem-vindo(a) à sua Base ID %d, %s", InBase[playerid], BaseInfo[InBase[playerid]][bi_owner]);
                else
                    format(String, MAX_STRING, "Seja bem-vindo(a) à Base ID %d, que pertencê ao jogador(a) %s", InBase[playerid], BaseInfo[InBase[playerid]][bi_owner]);

                return 1;
            }
            case base_code:
            {
                if(!response) return 0;

                new baseid = InBase[playerid];

                if(!strlen(inputtext))
                    return ShowPlayerDialog(playerid, base_code, DIALOG_STYLE_INPUT, "{FF0000}Código de Confirmação", "{FFFFFF}Para liberar sua base para o servidor é necessário o código de confirmação\n\n{FF4000}Obs: o código de vericação é o mesmo usado para registrar sua conta!", "Continuar", "Cancelar");

                if(!IsValidCodingAccount(playerid, inputtext))
                    return ShowPlayerDialog(playerid, base_code, DIALOG_STYLE_INPUT, "{FF0000}Código de Confirmação", "{FFFFFF}Para liberar sua base para o servidor é necessário o código de confirmação\n\n{FF4000}Obs: o código de vericação é o mesmo usado para registrar sua conta!", "Continuar", "Cancelar");

                if(!IsPlayerInRangeOfPoint(playerid, 20.0, 2120.77, -2272.97, 20.67) || baseid == -1)
                    return SendClientMessage(playerid, Erro, "Você não está dentro de uma Base");

                if(!IsPlayerOwnerBase(playerid, baseid) && !IsPlayerMemberBase(playerid, baseid))
                    return SendClientMessage(playerid, Erro, "Você não pertence à essa Base");

                PlayerInfo[playerid][Dinheiro] += BASE_MONEY;
                UpdatePlayerMoney(playerid);

                GetPlayer2DZone(zone, MAX_ZONE_NAME, BaseEnter[baseid][be_x], BaseEnter[baseid][be_y]);

                format(String, MAX_STRING, "O(A) Jogador(a) %s[%d] liberou à Base ID %d na localizada em ( %s )", PlayerInfo[playerid][Nome], playerid, baseid, zone);
                SendClientMessageToAll(color_base, String);

                SellBase(baseid);
                return 1;
            }
        }
        return 1;
    }
	return 1;
}

forward UnlockToGetWeapon(playerid);
public UnlockToGetWeapon(playerid)
{
    KillTimer(t_getweapon[playerid]);
    t_getweapon[playerid] = 0;
    return 1;
}

forward OnPlayerInBase(playerid);
public OnPlayerInBase(playerid)
{
    if(!PlayerInfo[playerid][Logado]) return 0;

    if(IsPlayerInBase(playerid))
    {
        new baseid = GetPlayerBaseID(playerid, true);

        if(!WarningLeftBase[playerid]) WarningLeftBase[playerid] = true;

        if(PlayerInfo[playerid][Estrelas] || (!IsBaseInvasionActive(baseid) && !IsPlayerMemberBaseEx(playerid, baseid)))
        {
            new Float:x, Float:y, Float:z, Float:angle;

            x = BaseGate[baseid][bg_x];
            y = BaseGate[baseid][bg_y];
            z = BaseGate[baseid][bg_z];
            angle = BaseGate[baseid][bg_rz];

            x -= -6.0 * floatsin(-angle, degrees);
            y -= -6.0 * floatcos(-angle, degrees);

            SetPlayerPos(playerid, x, y, z);

            SendClientMessage(playerid, Erro, (PlayerInfo[playerid][Estrelas] ? ("Você está procurado(a) e não pode ficar em bases") : ("Bloqueio contra invasão de base ativado e não poderá invadir")));
        }

        SetPlayerArmour(playerid, 0);

        format(String, MAX_STRING, "%s ( DM : %s ~w~)", BaseInfo[baseid][bi_name], (IsPlayerInBaseDmOn(playerid, baseid) ? ("~g~Liberado") : ("~r~Bloqueado")));
        PlayerTextDrawSetString(playerid, TDBase[playerid][0], String);
        PlayerTextDrawShow(playerid, TDBase[playerid][0]);
    } else {
        PlayerTextDrawHide(playerid, TDBase[playerid][0]);
    }
    return 1;
}

forward OnBaseRelease();
public OnBaseRelease()
{
    for(new baseid = 0; baseid < MAX_BASES; baseid++)
    {
        if(gettime() >= BaseInfo[baseid][bi_renovation] && BaseInfo[baseid][bi_renovation] && strcmp(BaseInfo[baseid][bi_owner], "N/A"))
        {
            SellBase(baseid);

            GetPlayer2DZone(zone, MAX_ZONE_NAME, BaseEnter[baseid][be_x], BaseEnter[baseid][be_y]);

            format(String, MAX_STRING, "O Servidor liberou à Base ID %d na localizada em ( %s )", baseid, zone);
            SendClientMessageToAll(color_base, String);
        }
    }
    return 1;
}

forward OnClosedGateBase(baseid);
public OnClosedGateBase(baseid)
{
    t_basegatestate[baseid] = false;
    KillTimer(t_basegate[baseid]);
    MoveDynamicObject(BaseInfo[baseid][bi_gate], BaseGate[baseid][bg_x], BaseGate[baseid][bg_y], BaseGate[baseid][bg_z], 3.00, BaseGate[baseid][bg_rx], BaseGate[baseid][bg_ry], BaseGate[baseid][bg_rz]);
    return 1;
}

stock CreateBases(baseid)
{
    BaseInfo[baseid][bi_gate] = CreateDynamicObject(19912, BaseGate[baseid][bg_x], BaseGate[baseid][bg_y], BaseGate[baseid][bg_z]+(!strcmp(BaseInfo[baseid][bi_owner], "N/A") ? 5 : 0), BaseGate[baseid][bg_rx], BaseGate[baseid][bg_ry], BaseGate[baseid][bg_rz]);

    UpdateBaseInformation(baseid);
    return 1;
}

stock IsPlayerMemberBaseEx(playerid, baseid = -1)
{
    if(baseid == -1)
    {
        for(baseid = 0; baseid < MAX_BASES; baseid++)
        {
            if(IsPlayerOwnerBase(playerid, baseid) || IsPlayerMemberBase(playerid, baseid) || IsPlayerSubBase(playerid, baseid)) return 1;
        }
    }
    else
    {
        if(IsPlayerOwnerBase(playerid, baseid) || IsPlayerMemberBase(playerid, baseid) || IsPlayerSubBase(playerid, baseid)) return 1;
    }
    return 0;
}

stock IsPlayerOwnerBase(playerid, baseid = -1)
{
    if(baseid == -1)
    {
        for(baseid = 0; baseid < MAX_BASES; baseid++)
        {
            if(!strcmp(BaseInfo[baseid][bi_owner], PlayerInfo[playerid][Nome])) return 1;
        }
    }
    else
    {
        if(!strcmp(BaseInfo[baseid][bi_owner], PlayerInfo[playerid][Nome])) return 1;
    }
    return 0;
}


stock IsPlayerSubBase(playerid, baseid = -1)
{
    if(baseid == -1)
    {
        for(baseid = 0; baseid < MAX_BASES; baseid++)
        {
            if(!strcmp(BaseInfo[baseid][bi_sub], PlayerInfo[playerid][Nome])) return 1;
        }
    }
    else
    {
        if(!strcmp(BaseInfo[baseid][bi_sub], PlayerInfo[playerid][Nome])) return 1;
    }
    return 0;
}

stock IsPlayerMemberBase(playerid, baseid = -1)
{
    if(baseid == -1)
    {
        for(baseid = 0; baseid < MAX_BASES; baseid++)
        {
            for(new memberid = 0; memberid < MAX_BASE_MEMBERS; memberid++)
            {
                if(!strcmp(BaseMember[baseid][memberid], PlayerInfo[playerid][Nome])) return 1;
            }
        }
    }
    else
    {
        for(new memberid = 0; memberid < MAX_BASE_MEMBERS; memberid++)
        {
            if(!strcmp(BaseMember[baseid][memberid], PlayerInfo[playerid][Nome])) return 1;
        }
    }
    return 0;
}

stock IsPlayerInBaseDmOn(playerid, baseid = -1)
{
    if(baseid == -1)
    {
        for(baseid = 0; baseid < MAX_BASES; baseid++)
        {
            if(IsPlayerInBase(playerid, baseid) && BaseInfo[baseid][bi_dm]) return 1;
        }
    }
    else
    {
        if(IsPlayerInBase(playerid, baseid) && BaseInfo[baseid][bi_dm]) return 1;
    }
    return 0;
}

stock IsPlayerInBase(playerid, baseid = -1)
{
    if(baseid == -1)
    {
        new Float:x, Float:y, Float:z;

        GetPlayerPos(playerid, x, y, z);

        if(x >= -622.7690 && y >= -562.3445 && x <= -466.2568 && y <= -468.5537) return 1;
        else if(x >= 1018.8382 && y >= 1224.4216 && x <= 1096.8944 && y <= 1303.4072 || x >= 1036.9548 && y >= 1303.4061 && x <= 1096.8943 && y <= 1361.7371 ||
                x >= 1036.9253 && y >= 1303.4033 && x <= 1039.5199 && y <= 1342.3506 || x >= 1031.7721 && y >= 1303.4032 && x <= 1036.5660 && y <= 1334.2289 ||
                x >= 1028.6987 && y >= 1303.4032 && x <= 1034.0125 && y <= 1325.7626 || x >= 1023.1514 && y >= 1303.4039 && x <= 1026.9672 && y <= 1315.0371 ||
                x >= 1022.9932 && y >= 1303.4032 && x <= 1023.4048 && y <= 1309.2631 || x >= 1020.4333 && y >= 1303.4054 && x <= 1020.7974 && y <= 1305.6315 ||
                x >= 1019.0767 && y >= 1303.4039 && x <= 1019.9484 && y <= 1304.9445 || x >= 1017.9532 && y >= 1302.8744 && x <= 1034.7126 && y <= 1314.1195 ) return 1;
        else if(x >= 917.8503 && y >= 2043.2698 && x <= 996.9685 && y <= 2182.8928) return 1;
        else if(x >= 1017.6026 && y >= 2063.3311 && x <= 1063.0876 && y <= 2204.9478 || x >= 1057.9935 && y >= 2063.4001 && x <= 1110.8730 && y <= 2167.2715) return 1;
        else if(x >= -75.9046 && y >= -395.7499 && x <= 17.7032 && y <= -218.8085 || x >= -75.5820 && y >= -223.7936 && x <= 11.1240 && y <= -217.8870 ||
                x >= -75.5820 && y >= -223.2824 && x <= -27.7116 && y <= -213.8926 || x >= -75.5814 && y >= -224.4550 && x <= -55.2397 && y <= -210.9430 ||
                x >= -76.1073 && y >= -218.2808 && x <= 18.4185 && y <= -213.6626 || x >= -75.5820 && y >= -223.4636 && x <= -68.2678 && y <= -209.1320 ||
                x >= -75.8807 && y >= -213.6625 && x <= -36.4671 && y <= -211.6581 ) return 1;
    }
    else
    {
        new Float:x, Float:y, Float:z;

        GetPlayerPos(playerid, x, y, z);

        switch(baseid)
        {
            case 0:
            {
                if(x >= -622.7690 && y >= -562.3445 && x <= -466.2568 && y <= -468.5537) return 1;
            }
            case 1:
            {
                if(x >= 1018.8382 && y >= 1224.4216 && x <= 1096.8944 && y <= 1303.4072 || x >= 1036.9548 && y >= 1303.4061 && x <= 1096.8943 && y <= 1361.7371 ||
                    x >= 1036.9253 && y >= 1303.4033 && x <= 1039.5199 && y <= 1342.3506 || x >= 1031.7721 && y >= 1303.4032 && x <= 1036.5660 && y <= 1334.2289 ||
                    x >= 1028.6987 && y >= 1303.4032 && x <= 1034.0125 && y <= 1325.7626 || x >= 1023.1514 && y >= 1303.4039 && x <= 1026.9672 && y <= 1315.0371 ||
                    x >= 1022.9932 && y >= 1303.4032 && x <= 1023.4048 && y <= 1309.2631 || x >= 1020.4333 && y >= 1303.4054 && x <= 1020.7974 && y <= 1305.6315 ||
                    x >= 1019.0767 && y >= 1303.4039 && x <= 1019.9484 && y <= 1304.9445 || x >= 1017.9532 && y >= 1302.8744 && x <= 1034.7126 && y <= 1314.1195 )
                    return 1;
            }
            case 2:
            {
                if(x >= 917.8503 && y >= 2043.2698 && x <= 996.9685 && y <= 2182.8928) return 1;
            }
            case 3:
            {
                if(x >= 1017.6026 && y >= 2063.3311 && x <= 1063.0876 && y <= 2204.9478 ||
                    x >= 1057.9935 && y >= 2063.4001 && x <= 1110.8730 && y <= 2167.2715) return 1;
            }
            case 4:
            {
                if(x >= -75.9046 && y >= -395.7499 && x <= 17.7032 && y <= -218.8085 || x >= -75.5820 && y >= -223.7936 && x <= 11.1240 && y <= -217.8870 ||
                x >= -75.5820 && y >= -223.2824 && x <= -27.7116 && y <= -213.8926 || x >= -75.5814 && y >= -224.4550 && x <= -55.2397 && y <= -210.9430 ||
                x >= -76.1073 && y >= -218.2808 && x <= 18.4185 && y <= -213.6626 || x >= -75.5820 && y >= -223.4636 && x <= -68.2678 && y <= -209.1320 ||
                x >= -75.8807 && y >= -213.6625 && x <= -36.4671 && y <= -211.6581 )
                    return 1;
            }
            default:
                return 0;
        }
    }
    return 0;
}

stock LeftBase(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 100.0, 2120.77, -2272.97, 20.67) && InBase[playerid] != -1)
    {
        PlayerInfo[playerid][PosX] = BaseEnter[InBase[playerid]][be_x];
        PlayerInfo[playerid][PosY] = BaseEnter[InBase[playerid]][be_y];
        PlayerInfo[playerid][PosZ] = BaseEnter[InBase[playerid]][be_z];
        PlayerInfo[playerid][PosA] = BaseEnter[InBase[playerid]][be_a];
        InBase[playerid] = -1;
        return 1;
    }
    return 1;
}

stock UpdateBaseInformation(baseid)
{
    if(IsValidDynamicPickup(BaseInfo[baseid][bi_pickup])) DestroyDynamicPickup(BaseInfo[baseid][bi_pickup]);
    if(IsValidDynamicMapIcon(BaseInfo[baseid][bi_map])) DestroyDynamicMapIcon(BaseInfo[baseid][bi_map]);

    if(!strcmp(BaseInfo[baseid][bi_owner], "N/A") && BaseInfo[baseid][bi_selling])
    {
        format(String, 255, "{31B404}Base à Venda ( ID:%d )\n{CE9F01}Dinheiro: {31B404}$%s\n{CE9F01}Reais: {31B404}R$%s\n{6495ED}/ComprarBase", baseid, IsMoney(BASE_MONEY, "."), IsMoney(BASE_REAIS, "."));

        BaseInfo[baseid][bi_pickup] = CreateDynamicPickup(BASE_PICKUP_SELL, 23, BaseEnter[baseid][be_x], BaseEnter[baseid][be_y], BaseEnter[baseid][be_z], 0, -1, -1, 100.0);
        BaseInfo[baseid][bi_map] = CreateDynamicMapIcon(BaseEnter[baseid][be_x], BaseEnter[baseid][be_y], BaseEnter[baseid][be_z], BASE_MAP_SELL, -1, 0, -1, -1, 50.0);

        if(IsValidDynamic3DTextLabel(BaseInfo[baseid][bi_label]))
        {
            UpdateDynamic3DTextLabelText(BaseInfo[baseid][bi_label], 0xFFFFFFFF, String);
        }
        else
        {
            BaseInfo[baseid][bi_label] = CreateDynamic3DTextLabel(String, 0xFFFFFFFF, BaseEnter[baseid][be_x], BaseEnter[baseid][be_y], BaseEnter[baseid][be_z]+0.50, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, -1, -1, 20.0, -1, 0);
        }
    }
    else if(strcmp(BaseInfo[baseid][bi_owner], "N/A") && BaseInfo[baseid][bi_selling])
    {
        format(String, 255, "{FFD700}%s ( ID:%d )\n{FFFFFF}Pertence: %s\n{FFFFFF}O(A) proprietário(a) está vendendo à base por {31B404}$%s\n %s \n{6495ED}/ComprarBase", BaseInfo[baseid][bi_name], baseid, BaseInfo[baseid][bi_owner], IsMoney(BaseInfo[baseid][bi_price], "."), (BaseInfo[baseid][bi_lock] ? ("{FFFFFF}Trancada") : ("{FFFFFF}Destrancada")));

        BaseInfo[baseid][bi_pickup] = CreateDynamicPickup(BASE_PICKUP_SELL, 23, BaseEnter[baseid][be_x], BaseEnter[baseid][be_y], BaseEnter[baseid][be_z], 0, -1, -1, 100.0);
        BaseInfo[baseid][bi_map] = CreateDynamicMapIcon(BaseEnter[baseid][be_x], BaseEnter[baseid][be_y], BaseEnter[baseid][be_z], BASE_MAP_SELL, -1, 0, -1, -1, 50.0);

        if(IsValidDynamic3DTextLabel(BaseInfo[baseid][bi_label]))
        {
            UpdateDynamic3DTextLabelText(BaseInfo[baseid][bi_label], 0xFFFFFFFF, String);
        }
        else
        {
            BaseInfo[baseid][bi_label] = CreateDynamic3DTextLabel(String, 0xFFFFFFFF, BaseEnter[baseid][be_x], BaseEnter[baseid][be_y], BaseEnter[baseid][be_z]+0.50, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, -1, -1, 20.0, -1, 0);
        }
    }
    else if(strcmp(BaseInfo[baseid][bi_owner], "N/A") && !BaseInfo[baseid][bi_selling])
    {
        format(String, 255, "{FFD700}%s ( ID:%d )\n{FFFFFF}Pertence: %s\n %s \n{6495ED}/EntrarBase", BaseInfo[baseid][bi_name], baseid, BaseInfo[baseid][bi_owner], (BaseInfo[baseid][bi_lock] ? ("{FFFFFF}Trancada") : ("{FFFFFF}Destrancada")));

        BaseInfo[baseid][bi_pickup] = CreateDynamicPickup(BASE_PICKUP_BUY, 23, BaseEnter[baseid][be_x], BaseEnter[baseid][be_y], BaseEnter[baseid][be_z], 0, -1, -1, 100.0);
        BaseInfo[baseid][bi_map] = CreateDynamicMapIcon(BaseEnter[baseid][be_x], BaseEnter[baseid][be_y], BaseEnter[baseid][be_z], BASE_MAP_BUY, -1, 0, -1, -1, 50.0);

        if(IsValidDynamic3DTextLabel(BaseInfo[baseid][bi_label]))
        {
            UpdateDynamic3DTextLabelText(BaseInfo[baseid][bi_label], 0xFFFFFFFF, String);
        }
        else
        {
            BaseInfo[baseid][bi_label] = CreateDynamic3DTextLabel(String, 0xFFFFFFFF, BaseEnter[baseid][be_x], BaseEnter[baseid][be_y], BaseEnter[baseid][be_z]+0.50, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, -1, -1, 20.0, -1, 0);
        }
    }
    return 1;
}

stock BuyBase(baseid, owner[] = "N/A")
{
    if(!IsValidBase(baseid))
        return 0;

    format(BaseInfo[baseid][bi_tag], MAX_BASE_TAG_NAME, "N.A");
    format(BaseInfo[baseid][bi_name], MAX_BASE_NAME, "N/A");
    format(BaseInfo[baseid][bi_owner], MAX_PLAYER_NAME, owner);
    format(BaseInfo[baseid][bi_sub], MAX_PLAYER_NAME, "N/A");

    BaseInfo[baseid][bi_selling] = 0;
    BaseInfo[baseid][bi_price] = 0;
    BaseInfo[baseid][bi_dm] = 0;
    BaseInfo[baseid][bi_lock] = 0;

    format(BaseInfo[baseid][bi_pass], MAX_BASE_PASS, "N/A");
    format(BaseInfo[baseid][bi_tagcolor], MAX_BASE_PASS, "FF0000");
    BaseInfo[baseid][bi_renovation] = (gettime() + ONE_MONTH);

    new query[500];
    mysql_format(IDConexao, query, 500, "UPDATE `Bases` SET `tag`='%e', `name`='%e', `owner`='%e', `sub`='%e', `selling`='%d', `price`='%d', `dm`='%d', `lock`='%d', `pass`='%e', `tagcolor`='%s', `renovation`='%d' WHERE `id`='%d'",
    BaseInfo[baseid][bi_tag],
    BaseInfo[baseid][bi_name],
    BaseInfo[baseid][bi_owner],
    BaseInfo[baseid][bi_sub],
    BaseInfo[baseid][bi_selling],
    BaseInfo[baseid][bi_price],
    BaseInfo[baseid][bi_dm],
    BaseInfo[baseid][bi_lock],
    BaseInfo[baseid][bi_pass],
    BaseInfo[baseid][bi_tagcolor],
    BaseInfo[baseid][bi_renovation],
    baseid);
    mysql_query(IDConexao, query);

    UpdateBaseInformation(baseid);
    StateDoorBase(baseid);
    return 1;
}

stock SellBase(baseid, owner[] = "N/A")
{
    if(!IsValidBase(baseid))
        return 0;

    format(BaseInfo[baseid][bi_tag], MAX_BASE_TAG_NAME, "N.A");
    format(BaseInfo[baseid][bi_name], MAX_BASE_NAME, "N/A");
    format(BaseInfo[baseid][bi_owner], MAX_PLAYER_NAME, owner);
    format(BaseInfo[baseid][bi_sub], MAX_PLAYER_NAME, "N/A");

    BaseInfo[baseid][bi_selling] = 1;
    BaseInfo[baseid][bi_price] = 0;
    BaseInfo[baseid][bi_dm] = 0;
    BaseInfo[baseid][bi_lock] = 0;

    format(BaseInfo[baseid][bi_pass], MAX_BASE_PASS, "N/A");
    format(BaseInfo[baseid][bi_tagcolor], MAX_BASE_PASS, "FF0000");

    if(!strcmp(owner, "N/A"))
        BaseInfo[baseid][bi_renovation] = 0;

    new query[500];
    mysql_format(IDConexao, query, 500, "UPDATE `Bases` SET `tag`='%e', `name`='%e', `owner`='%e', `sub`='%e', `selling`='%d', `price`='%d', `dm`='%d', `lock`='%d', `pass`='%e', `tagcolor`='%s', `renovation`='%d' WHERE `id`='%d'",
    BaseInfo[baseid][bi_tag],
    BaseInfo[baseid][bi_name],
    BaseInfo[baseid][bi_owner],
    BaseInfo[baseid][bi_sub],
    BaseInfo[baseid][bi_selling],
    BaseInfo[baseid][bi_price],
    BaseInfo[baseid][bi_dm],
    BaseInfo[baseid][bi_lock],
    BaseInfo[baseid][bi_pass],
    BaseInfo[baseid][bi_tagcolor],
    BaseInfo[baseid][bi_renovation],
    baseid);
    mysql_query(IDConexao, query);

    UpdateBaseInformation(baseid);
    DisconnectBaseAllVehicle(baseid);
    StateDoorBase(baseid);
    return 1;
}

stock AlterNameBase(baseid, name[])
{
    for(new i = 0; i < MAX_BASES; i++)
    {
        if(!strcmp(BaseInfo[i][bi_name], name)) return 0;
    }

    format(BaseInfo[baseid][bi_name], MAX_BASE_NAME, name);

    new query[200];
    mysql_format(IDConexao, query, 200, "UPDATE `Bases` SET `name`='%e' WHERE `id`='%d'", BaseInfo[baseid][bi_name], baseid);
    mysql_query(IDConexao, query);

    UpdateBaseInformation(baseid);
    return 1;
}

stock AlterTagBase(baseid, name[])
{
    for(new i = 0; i < MAX_BASES; i++)
    {
        if(!strcmp(BaseInfo[i][bi_tag], name)) return 0;
    }

    format(BaseInfo[baseid][bi_tag], MAX_BASE_TAG_NAME, name);

    new query[200];
    mysql_format(IDConexao, query, 200, "UPDATE `Bases` SET `tag`='%e' WHERE `id`='%d'", BaseInfo[baseid][bi_tag], baseid);
    mysql_query(IDConexao, query);

    UpdateBaseInformation(baseid);
    return 1;
}

stock IsBaseVehicleConnect(baseid, listid)
{
    if(!IsValidBase(baseid))
        return 0;

    return ( VehicleBase[baseid][listid][vb_connect] ? true : false );
}

stock ConnectBaseVehicle(baseid, listid)
{
    if(!IsValidBase(baseid))
        return 0;

    return CreateVehicleEx(BASE_VEHICLE_MODEL, PlaceVehicleBase[baseid][listid][pvb_x], PlaceVehicleBase[baseid][listid][pvb_y], PlaceVehicleBase[baseid][listid][pvb_z], PlaceVehicleBase[baseid][listid][pvb_a], 0, 0, -1, baseid, listid);
}

stock DisconnectBaseVehicle(baseid, listid)
{
    if(!IsValidBase(baseid))
        return 0;

    return DestroyVehicleEx(VehicleBase[baseid][listid][vb_id]);
}

stock OnBaseStateVehicle(baseid, listid)
{
    if(!IsValidBase(baseid))
        return 0;

    return ( IsBaseVehicleConnect(baseid, listid) ? DisconnectBaseVehicle(baseid, listid) : ConnectBaseVehicle(baseid, listid) );
}

stock DisconnectBaseAllVehicle(baseid)
{
    if(!IsValidBase(baseid))
        return 0;

    for(new listid = 0; listid < MAX_VEHICLE_BASE; listid++)
    {
        if(IsBaseVehicleConnect(baseid, listid))
        {
            DisconnectBaseVehicle(baseid, listid);
        }
    }
    return 1;
}

stock IsValidBase(baseid)
{
    if(baseid >= 0  || baseid < MAX_BASES) return 1;
    return 0;
}

stock IsValidNameBase(name[])
{
	new i, len = strlen(name);

	if(len < 3) return 0;

	while(i < len)
	{
		switch(name[i])
		{
			case 'a'..'z', 'A'..'Z', '0'..'9', '.', '_', ' ':
				i++;
			default:
				return 0;
		}
	}
	return 1;
}

stock IsValidTagBase(name[])
{
	new i, len = strlen(name);

	if(len < 2) return 0;

	while(i < len)
	{
		switch(name[i])
		{
			case 'a'..'z', 'A'..'Z', '0'..'9', '.':
				i++;
			default:
				return 0;
		}
	}
	return 1;
}

stock IsValidPassBase(pass[])
{
	new i, len = strlen(pass);

	if(len < 1 || len > MAX_BASE_PASS) return 0;

	while(i < len)
	{
		switch(pass[i])
		{
			case 'a'..'z', 'A'..'Z', '0'..'9':
				i++;
			default:
				return 0;
		}
	}
	return 1;
}

stock GetPlayerBaseID(playerid, place = false)
{
    if(place)
    {
        for(new baseid = 0; baseid < MAX_BASES; baseid++)
        {
            if(IsPlayerInBase(playerid, baseid)) return baseid;
        }
    }
    else
    {
        for(new baseid = 0; baseid < MAX_BASES; baseid++)
        {
            if(IsPlayerMemberBaseEx(playerid, baseid)) return baseid;
        }
    }
    return -1;
}

stock StateDoorBase(baseid)
{
    MoveDynamicObject(BaseInfo[baseid][bi_gate], BaseGate[baseid][bg_x], BaseGate[baseid][bg_y], BaseGate[baseid][bg_z]+(!strcmp(BaseInfo[baseid][bi_owner], "N/A") ? 5 : 0), 3.00, BaseGate[baseid][bg_rx], BaseGate[baseid][bg_ry], BaseGate[baseid][bg_rz]);
    return 1;
}

stock IsBaseInvasionActive(baseid)
{
    return ( BaseInfo[baseid][bi_invasion] ? true : false );
}

/******************************************************************************/
/******************************| COMMANDS BASES |******************************/
/******************************************************************************/

CMD:cb(playerid, params[])
{
    if(!IsPlayerMemberBaseEx(playerid))
        return SendClientMessage(playerid, Erro, "Você não é membro de uma Base");

    new tmp[128];

    if(sscanf(params, "s[128]", tmp))
        return SendClientMessage(playerid, Erro, "Digite: /Cb [mensagem]");

    for(new player = 0; player < MAX_PLAYERS; player++)
    {
        if(!IsPlayerMemberBaseEx(player)) continue;

        if(GetPlayerBaseID(playerid) == GetPlayerBaseID(player))
        {
            format(String, MAX_STRING, "Chat-Base ~ %s[%d] diz: %s", PlayerInfo[playerid][Nome], playerid, tmp);
            SendClientMessage(player, color_base, String);
        }
    }
    return 1;
}
CMD:irbase(playerid, params[])
{
    if(!IsPlayerIntern(playerid))
        return SendClientMessage(playerid, Erro, "Comando Inválido");

    new baseid;

    if(sscanf(params, "d", baseid))
        return SendClientMessage(playerid, Erro, "Digite: /IrBase [base-id]");

    if(baseid < 0  || baseid >= MAX_BASES)
        return SendClientMessage(playerid, Erro, "Base inválida");

    SetPlayerFacingAngle(playerid, BaseEnter[baseid][be_a]);
    SetPlayerPos(playerid, BaseEnter[baseid][be_x], BaseEnter[baseid][be_y], BaseEnter[baseid][be_z]);

    format(String, MAX_STRING, "Você se teletransportou para Base %s ID:%d", BaseInfo[baseid][bi_name], baseid);
    SendClientMessage(playerid, adm, String);
    return 1;
}
CMD:menubase(playerid)
{
    if(!IsPlayerInRangeOfPoint(playerid, 20.0, 2120.77, -2272.97, 20.67) || InBase[playerid] == -1)
        return SendClientMessage(playerid, Erro, "Você não está dentro de uma Base");

    if(!IsPlayerOwnerBase(playerid, InBase[playerid]) && !IsPlayerMemberBase(playerid, InBase[playerid]))
        return SendClientMessage(playerid, Erro, "Você não pertence à essa Base");

    new txt[500], count, baseid = InBase[playerid];

    strcat(txt, (!IsPlayerMobile(playerid) ? ("{FF8000}Função\t {FF8000}Status\n") : (#)));

    format(String, MAX_STRING, "{FFFFFF}Alterar cor TAG\t [{%s}%s{FFFFFF}]\n", BaseInfo[baseid][bi_tagcolor], BaseInfo[baseid][bi_tag]);
    strcat(txt, String);
    format(String, MAX_STRING, "{FFFFFF}Alterar TAG\t {CCCCCC}[%s]\n", BaseInfo[baseid][bi_tag]);
    strcat(txt, String);
    format(String, MAX_STRING, "{FFFFFF}Alterar nome\t {CCCCCC}%s\n", BaseInfo[baseid][bi_name]);
    strcat(txt, String);
    format(String, MAX_STRING, "{FFFFFF}DeathMatch\t %s\n", (BaseInfo[baseid][bi_dm] ? ("{1B6302}ON") : ("{FF4000}OFF")));
    strcat(txt, String);
    format(String, MAX_STRING, "{FFFFFF}Alterar status\t {CCCCCC}%s\n", BaseInfo[baseid][bi_pass]);
    strcat(txt, String);
    format(String, MAX_STRING, "{FFFFFF}%s invasão\n", (BaseInfo[baseid][bi_invasion] ? ("Desativar") : ("Ativar")));
    strcat(txt, String);

    for(new memberid = 0; memberid < MAX_BASE_MEMBERS; memberid++)
    {
        if(strcmp(BaseMember[baseid][memberid], "N/A")) count++;
    }

    format(String, MAX_STRING, "{FFFFFF}Membros\t {CCCCCC}%d\n", count);
    strcat(txt, String);

    strcat(txt, "{FFFFFF}Conectar/Desconectar veículos\n");
    strcat(txt, "{FFFFFF}Vender/Alterar preço\n");
    strcat(txt, "{FFFFFF}Vender para o servidor\n");

    new value = (BaseInfo[baseid][bi_renovation] - gettime()), days, hours, minutes, seconds;

    TimeConvertEx(value, days, hours, minutes, seconds);

    if(value > 86400)
        format(String, 30, "%dDia(s) %02d:%02d:%02d", days, hours, minutes, seconds);
    else if(value > 3600)
        format(String, 20, "%02d:%02d:%02d", hours, minutes, seconds);
    else
        format(String, 10, "%02d:%02d", minutes, seconds);

    format(String, 200, "{FFFFFF}Renovação\t {FF4000}%s\n", String);
    strcat(txt, String);

    ShowPlayerDialog(playerid, base_menu, (IsPlayerMobile(playerid) ? DIALOG_STYLE_LIST : DIALOG_STYLE_TABLIST_HEADERS), "{FF0000}Menu Base", txt, "Continuar", "Cancelar");
    return 1;
}
CMD:comprarbase(playerid)
{
    for(new baseid = 0; baseid < MAX_BASES; baseid++)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, BaseEnter[baseid][be_x], BaseEnter[baseid][be_y], BaseEnter[baseid][be_z]))
        {
            if(!BaseInfo[baseid][bi_selling])
                return SendClientMessage(playerid, Erro, "Essa Base não está à venda");

            if(IsPlayerMemberBaseEx(playerid))
                return SendClientMessage(playerid, Erro, "Você já pertênce à uma Base");

            GetPlayer2DZone(zone, MAX_ZONE_NAME, BaseEnter[baseid][be_x], BaseEnter[baseid][be_y]);

            if(!strcmp(BaseInfo[baseid][bi_owner], "N/A"))
            {
                if(PlayerInfo[playerid][Dinheiro] < BASE_MONEY || PlayerInfo[playerid][Reais] < BASE_REAIS)
                    return SendClientMessage(playerid, Erro, "Você não tem Dinheiro e/ou Reais o suficiente");

                PlayerInfo[playerid][Dinheiro] -= BASE_MONEY;
                UpdatePlayerMoney(playerid);
                PlayerInfo[playerid][Reais] -= BASE_REAIS;
                UpdatePlayerReais(playerid);

                format(String, MAX_STRING, "O(A) Jogador(a) %s comprou a base ID %d que pertencia ao jogador(a) %s localizada em %s", PlayerInfo[playerid][Nome], baseid, BaseInfo[baseid][bi_owner], zone);
                SendClientMessageToAll(color_base, String);
            }
            else
            {
                new id = GetPlayerID(BaseInfo[baseid][bi_owner]);

                if(id == INVALID_PLAYER_ID)
                    return SendClientMessage(playerid, Erro, "O(A) proprietário(a) dessa base não está conectado(a)");

                if(PlayerInfo[playerid][Dinheiro] < BaseInfo[baseid][bi_price])
                    return SendClientMessage(playerid, Erro, "Você não tem dinheiro o suficiente");

                PlayerInfo[id][SaldoBancario] += BaseInfo[baseid][bi_price];
                SetIntQuery(id, "Identidade", "saldobancario", PlayerInfo[id][SaldoBancario]);
                PlayerInfo[playerid][Dinheiro] -= BaseInfo[baseid][bi_price];
                UpdatePlayerMoney(playerid);

                format(String, MAX_STRING, "O(A) Jogador(a) %s comprou a sua base e o seu dinheiro foi transferido direto pra sua conta bancária!", PlayerInfo[playerid][Nome], baseid, BaseInfo[baseid][bi_owner], zone);
                SendClientMessage(id, color_base, String);
                format(String, MAX_STRING, "O(A) Jogador(a) %s comprou a base ID %d que pertencia ao jogador(a) %s localizada em %s", PlayerInfo[playerid][Nome], baseid, BaseInfo[baseid][bi_owner], zone);
                SendClientMessageToAll(color_base, String);
            }

            BuyBase(baseid, PlayerInfo[playerid][Nome]);
            return 1;
        }
    }
    return SendClientMessage(playerid, Erro, "Você não está perto da porta de uma Base");
}
CMD:entrarbase(playerid)
{
    for(new baseid = 0; baseid < MAX_BASES; baseid++)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, BaseEnter[baseid][be_x], BaseEnter[baseid][be_y], BaseEnter[baseid][be_z]))
        {
            InBase[playerid] = baseid;
            SetPlayerVirtualWorld(playerid, InBase[playerid]);
            SetPlayerInterior(playerid, 0);
            SetPlayerFacingAngle(playerid, -45.0);
            SetPlayerPos(playerid, 2120.77, -2272.97, 20.67);

            format(String, MAX_STRING, (IsPlayerOwnerBase(playerid, baseid) ? ("Seja bem-vindo(a) à sua Base ID %d, %s") : ("Seja bem-vindo(a) à Base ID %d, que pertencê ao jogador(a) %s")), baseid, BaseInfo[baseid][bi_owner]);
            SendClientMessage(playerid, color_base, String);
            return 1;
        }
    }
    return SendClientMessage(playerid, Erro, "Você não está perto da porta de uma Base");
}
CMD:sairbase(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2120.77, -2272.97, 20.67) && InBase[playerid] != -1)
    {
        SetPlayerVirtualWorld(playerid, 0);
        SetPlayerInterior(playerid, 0);
        SetPlayerFacingAngle(playerid, BaseEnter[InBase[playerid]][be_a]);
        SetPlayerPos(playerid, BaseEnter[InBase[playerid]][be_x], BaseEnter[InBase[playerid]][be_y], BaseEnter[InBase[playerid]][be_z]);
        InBase[playerid] = -1;
        return 1;
    }
    return SendClientMessage(playerid, Erro, "Você não está perto da porta de uma Base");
}
CMD:abrirbase(playerid)
{
    for(new baseid = 0; baseid < MAX_BASES; baseid++)
    {
        if(IsPlayerInRangeOfPoint(playerid, 10.0, BaseGate[baseid][bg_x], BaseGate[baseid][bg_y], BaseGate[baseid][bg_z]))
        {
            if(!IsPlayerMemberBaseEx(playerid, baseid))
                return SendClientMessage(playerid, Erro, "Você não pertence à essa Base");

            if(t_basegatestate[baseid]) KillTimer(t_basegate[baseid]);

            MoveDynamicObject(BaseInfo[baseid][bi_gate], BaseGate[baseid][bg_x], BaseGate[baseid][bg_y], BaseGate[baseid][bg_z]+5.14, 3.00, BaseGate[baseid][bg_rx], BaseGate[baseid][bg_ry], BaseGate[baseid][bg_rz]);

            t_basegatestate[baseid] = true;
            t_basegate[baseid] = SetTimerEx("OnClosedGateBase", 5000, false, "d", baseid);

            SendClientMessage(playerid, Green, "Você abriu portão da Base, em 5 segundos será fechado automaticamente");
            return 1;
        }
    }
    return SendClientMessage(playerid, Erro, "Você não está perto do portão de uma Base");
}
CMD:liberarbase(playerid, params[])
{
    if(!IsPlayerDeveloper(playerid))
		return SendClientMessage(playerid, Erro, "Comando Inválido");

    new baseid;

    if(sscanf(params, "d", baseid))
		return SendClientMessage(playerid, Erro, "Digite: /LiberarBase [base-id]");

    if(baseid < 0 || baseid > MAX_BASES)
        return SendClientMessage(playerid, Erro, "Base ID inválido");

    SellBase(baseid);

    format(String, MAX_STRING, "O(A) %s %s liberou à Base ID %d localizada em ( %s )", CargoAdmin(playerid), PlayerInfo[playerid][Nome], baseid, zone);
    SendClientMessageToAll(color_base, String);
    return 1;
}
