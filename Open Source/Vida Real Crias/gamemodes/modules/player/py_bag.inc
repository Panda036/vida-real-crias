#include YSI\y_hooks

//Weapons
new gunname[32];
new Armas[13][2];

hook OnPlayerDisconnect(playerid, reason)
{
    for(new slot = 0; slot < MAX_SLOT_BAG; slot++)
    {
        BagInfo[slot][playerid][bi_weaponid] = 0;
        BagInfo[slot][playerid][bi_ammunation] = 0;
    }
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case school_bag:
        {
            if(!response) return 0;

            if(IsPlayerInAnyVehicle(playerid))
                return SendClientMessage(playerid, Erro, "Não é permitido usar mochilha em veículo");

            switch(listitem)
            {
                case 0:
                {
                    new txt[1000];

                    strcat(txt, (IsPlayerMobile(playerid) ? (#) : ("{CCCCCC}Nome\t {CCCCCC}Posição\t {CCCCCC}Status\n")));

                    for(new slot = 0; slot < MAX_ACCESSORIES; slot++)
                    {
                        if(ao[playerid][slot][ao_model])
                        {
                            format(String, 100, "{FFFFFF}%s\t {FF4000}%s\t %s\n", AccessoriesName(ao[playerid][slot][ao_model]), AttachmentBones[ ( ao[playerid][slot][ao_bone] - 1 ) ], ( ao[playerid][slot][ao_connected] != -1 ? ("{1B6302}Conectado") : ("{FF0000}Desconectado") ));
                            strcat(txt, String);
                        }
                        else
                        {
                            strcat(txt, "{FFFFFF}N/A\t {FF4000}N/A\t {FF0000}N/A\n");
                        }
                    }

                    ShowPlayerDialog(playerid, school_bag_acce, (IsPlayerMobile(playerid) ? DIALOG_STYLE_LIST : DIALOG_STYLE_TABLIST_HEADERS), "{FF0000}Acessórios", txt, "Continuar", "Cancelar");
                    return 1;
                }
                case 1: ShowPlayerDialog(playerid, school_bag_weapon, DIALOG_STYLE_LIST, "{FF0000}Armas", "{FFFFFF}Pegar arma\nGuardar arma", "Continuar", "Cancelar");
            }
            return 1;
        }
        case school_bag_acce:
        {
            if(!response) return 0;

            if(IsPlayerInAnyVehicle(playerid))
                return SendClientMessage(playerid, Erro, "Não é permitido usar mochilha em veículo");

            for(new slot = 0; slot < MAX_ACCESSORIES; slot++)
            {
                if(listitem == slot)
                {
                    if(!ao[playerid][slot][ao_model])
                        return SendClientMessage(playerid, Erro, "Não tem acessório neste slot");

                    ModifyingSlot[playerid] = slot;

                    new txt[50];
                    strcat(txt, ( ao[playerid][ModifyingSlot[playerid]][ao_connected] != -1 ? ("Desconectar\n") : ("Conectar\n")));
                    strcat(txt, "Editar\n");
                    strcat(txt, "Vender\n");

                    format(String, 50, "{FF0000}%s", AccessoriesName(ao[playerid][ModifyingSlot[playerid]][ao_model]));

                    ShowPlayerDialog(playerid, school_bag_acce_edit, DIALOG_STYLE_LIST, String, txt, "Continuar", "Cancelar");
                    break;
                }
            }
            return 1;
        }
        case school_bag_acce_edit:
        {
            if(!response) return 0;

            if(IsPlayerInAnyVehicle(playerid))
                return SendClientMessage(playerid, Erro, "Não é permitido usar mochilha em veículo");

            switch(listitem)
            {
                case 0:
                {
                    new slot = ModifyingSlot[playerid];

                    if(ao[playerid][slot][ao_connected] != -1)
                    {
                        RemoveAccessorySlotOccuped(playerid, slot);

                        format(String, MAX_STRING, "Acessório {1B6302}%s {FFFFFF}desconectado da {FF4000}%s", AccessoriesName(ao[playerid][slot][ao_model]), AttachmentBones[ao[playerid][slot][ao_bone] - 1]);
                        SendClientMessage(playerid, White, String);
                    }
                    else
                    {
                        if(getAccessoryCountConnected(playerid) >= MAX_ACCESSORIES_CONNECT)
                            return SendClientMessage(playerid, Erro, "Limite de acessórios conectado atingido");

                        SetAccessorySlotOccuped(playerid, slot);

                        format(String, MAX_STRING, "Acessório {1B6302}%s {FFFFFF}conectado na {FF4000}%s", AccessoriesName(ao[playerid][slot][ao_model]), AttachmentBones[ao[playerid][slot][ao_bone] - 1]);
                        SendClientMessage(playerid, White, String);
                    }
                    return 1;
                }
                case 1:
                {
                    new slot = ModifyingSlot[playerid];

                    if(ao[playerid][slot][ao_connected] == -1)
                        return SendClientMessage(playerid, Erro, "Conecte o acessório para poder editar");

                    EditAttachedObject(playerid, ao[playerid][slot][ao_connected]);
                    return 1;
                }
                case 2: ShowPlayerDialog(playerid, school_bag_acce_sell, DIALOG_STYLE_MSGBOX, "{FF0000}Confirmação de Venda", "{FFFFFF}Deseja continuar com a venda do acessório?", "Sim", "Não");
            }
            return 1;
        }
        case school_bag_acce_sell:
        {
            if(!response) return 0;

            if(IsPlayerInAnyVehicle(playerid))
                return SendClientMessage(playerid, Erro, "Não é permitido usar mochilha em veículo");

            new slot = ModifyingSlot[playerid];

            #if (EVENT_SWEET || EVENT_GIFT || EVENT_CHRISTMAS)
                if(ao[playerid][slot][ao_model] == 18728            ||
                    ao[playerid][slot][ao_model] == HALLOWEEN_HAT   ||
                     ao[playerid][slot][ao_model] == CHRISTMAS_HAT  ) return SendClientMessage(playerid, Erro, "Não é possível vender esse acessório durante evento");
            #endif

            PlayerInfo[playerid][Dinheiro] += ao[playerid][slot][ao_value];
            UpdatePlayerMoney(playerid);

            format(String, 100, "Acessório \"{FF4000}%s{FFFFFF}\" vendido por {1B6302}$%s", AccessoriesName(ao[playerid][slot][ao_model]), IsMoney(ao[playerid][slot][ao_value], "."));
            SendClientMessage(playerid, White, String);

            RemoveAccessorySlotOccuped(playerid, slot);

            new query[200];
            mysql_format(IDConexao, query, 200, "DELETE FROM `Accessories` WHERE `slot`='%d' AND `id_contas`='%d'", slot, PlayerInfo[playerid][ID]);
            mysql_query(IDConexao, query);

            ao[playerid][slot][ao_model] = 0;
            ao[playerid][slot][ao_value] = 0;
            ao[playerid][slot][ao_bone] = 0;
            ao[playerid][slot][ao_x] = 0;
            ao[playerid][slot][ao_y] = 0;
            ao[playerid][slot][ao_z] = 0;
            ao[playerid][slot][ao_rx] = 0;
            ao[playerid][slot][ao_ry] = 0;
            ao[playerid][slot][ao_rz] = 0;
            ao[playerid][slot][ao_sx] = 0;
            ao[playerid][slot][ao_sy] = 0;
            ao[playerid][slot][ao_sz] = 0;
            return 1;
        }
        case school_bag_weapon:
        {
            if(!response) return 0;

            if(IsPlayerInAnyVehicle(playerid))
                return SendClientMessage(playerid, Erro, "Não é permitido usar mochilha em veículo");

            switch(listitem)
            {
                case 0:
                {
                    new txt[2000], max_itens = ((IsPlayerVip(playerid) || IsPlayerIntern(playerid)) ? 10 : 5);

                    strcat(txt, (IsPlayerMobile(playerid) ? (#) : ("{CCCCCC}Arma\t {1B6302}Munição\n\n")));

                    for(new slot = 0; slot < max_itens; slot++)
                    {
                        if(!IsPlayerBagFree(playerid, slot))
                        {
                            GetWeaponName(BagInfo[slot][playerid][bi_weaponid], gunname, sizeof(gunname));

                            format(String, 100, "{CCCCCC}%s\t {1B6302}%s\n", gunname, IsMoney(BagInfo[slot][playerid][bi_ammunation], "."));
                            strcat(txt, String);
                            continue;
                        }

                        strcat(txt, "{CCCCCC}N/A\t {1B6302}0\n");
                        continue;
                    }

                    ShowPlayerDialog(playerid, school_bag_get, (IsPlayerMobile(playerid) ? DIALOG_STYLE_LIST : DIALOG_STYLE_TABLIST_HEADERS), "{FF0000}Mochila", txt, "Continuar", "Cancelar");
                    return 1;
                }
                case 1:
                {
                    if(!GetPlayerWeapon(playerid))
                        return SendClientMessage(playerid, Erro, "Você não tem arma em sua mão");

                    if(!IsPlayerBagFree(playerid))
                        return SendClientMessage(playerid, Erro, "Sua mochila não tem mais espaço");

                    new slot = GetPlayerBagSlotFree(playerid);

                    for(new i = 0; i < 13; ++i)
                    {
                        GetPlayerWeaponData(playerid, i, Armas[i][0], Armas[i][1]);

                        if(GetPlayerWeapon(playerid) == Armas[i][0])
                        {
                            BagInfo[slot][playerid][bi_weaponid] = Armas[i][0];
                            BagInfo[slot][playerid][bi_ammunation] = Armas[i][1];
                            break;
                        }
                    }

                    RemovePlayerWeapon(playerid, GetPlayerWeapon(playerid));

                    GetWeaponName(BagInfo[slot][playerid][bi_weaponid], gunname, sizeof(gunname));

                    format(String, MAX_STRING, "Você guardou em sua mochila {FF8000}%s {FFFFFF}com {FF4000}%s {FFFFFF}balas", gunname, IsMoney(BagInfo[slot][playerid][bi_ammunation], "."));
                    SendClientMessage(playerid, White, String);

                    UpdatePlayerBag(playerid, slot);
                    return 1;
                }
            }
            return 1;
        }
        case school_bag_get:
        {
            if(!response) return 0;

            if(IsPlayerInAnyVehicle(playerid))
                return SendClientMessage(playerid, Erro, "Não é permitido usar mochilha em veículo");

            for(new slot = 0; slot < MAX_SLOT_BAG; slot++)
            {
                if(listitem != slot) continue;

                if(!BagInfo[slot][playerid][bi_weaponid])
                    return SendClientMessage(playerid, Erro, "Não tem nenhuma arma nesse slot");

                GivePlayerWeapon(playerid, BagInfo[slot][playerid][bi_weaponid], BagInfo[slot][playerid][bi_ammunation]);

                GetWeaponName(BagInfo[slot][playerid][bi_weaponid], gunname, sizeof(gunname));

                format(String, MAX_STRING, "Você pegou de sua mochila uma {FF8000}%s {FFFFFF}com {FF4000}%s {FFFFFF}balas", gunname, IsMoney(BagInfo[slot][playerid][bi_ammunation], "."));
                SendClientMessage(playerid, White, String);

                BagInfo[slot][playerid][bi_weaponid] = 0;
                BagInfo[slot][playerid][bi_ammunation] = 0;
                UpdatePlayerBag(playerid, slot);
                break;
            }
            return 1;
        }
    }
    return 1;
}

stock RemovePlayerWeapon(playerid, weaponid)
{
	new pWeaponData[13][2];

	for (new i = 0; i < 13; i++)
	{
	    GetPlayerWeaponData(playerid, i, pWeaponData[i][0], pWeaponData[i][1]);
	}

	ResetPlayerWeapons(playerid);

	for(new i = 0; i < 13; i++)
	{
		if(pWeaponData[i][0] != 0 && pWeaponData[i][0] != weaponid)
		{
			GivePlayerWeapon(playerid, pWeaponData[i][0], pWeaponData[i][1]);
		}
	}
	return 1;
}

stock UpdatePlayerBag(playerid, slotid)
{
    new query[200];
    mysql_format(IDConexao, query, 200, "UPDATE `Bag` SET `weapon%d`='%d', `ammun%d`='%d' WHERE `id_contas`='%d'", slotid, BagInfo[slotid][playerid][bi_weaponid], slotid, BagInfo[slotid][playerid][bi_ammunation], PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);
    return 1;
}


stock IsPlayerBagFree(playerid, slot = -1)
{
    if(slot == -1)
    {
        new max_itens = ((IsPlayerVip(playerid) || IsPlayerIntern(playerid)) ? 10 : 5);

        for(slot = 0; slot < max_itens; slot++)
        {
            if(!BagInfo[slot][playerid][bi_weaponid]) return 1;
        }
    }
    else
    {
        if(!BagInfo[slot][playerid][bi_weaponid]) return 1;
    }
    return 0;
}

stock GetPlayerBagSlotFree(playerid)
{
    new max_itens = ((IsPlayerVip(playerid) || IsPlayerIntern(playerid)) ? 10 : 5);

    for(new slot = 0; slot < max_itens; slot++)
    {
        if(!BagInfo[slot][playerid][bi_weaponid]) return slot;
    }
    return -1;
}

//-----------------------------------

CMD:mochila(playerid)
{
    if(!PlayerInfo[playerid][bag])
        return SendClientMessage(playerid, Erro, "Você não tem mochila");

    if(IsPlayerInAnyVehicle(playerid))
        return SendClientMessage(playerid, Erro, "Não é permitido usar mochilha em veículo");

    ShowPlayerDialog(playerid, school_bag, DIALOG_STYLE_LIST, "{FF0000}Mochila", "{FFFFFF}Acessórios\nArmas", "Continuar", "Cancelar");
    return 1;
}
