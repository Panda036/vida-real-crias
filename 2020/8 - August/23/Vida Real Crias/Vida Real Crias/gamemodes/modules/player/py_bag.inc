#include YSI\y_hooks

enum e_aol
{
    aol_model,
    aol_value
};

new AttachmentObjectsList[][e_aol] =
{
    {18632, 180},
    {18633, 40},
    {18634, 40},
    {18635, 30},
    {18636, 20},
    {18637, 60},
    {18638, 25},
    {18639, 20},
    {18640, 25},
    {18975, 40},
    {19136, 40},
    {19274, 50},
    {18641, 35},
    {18642, 120},
    {18643, 150},
    {18644, 15},
    {18645, 25},
    {18890, 70},
    {18891, 10},
    {18892, 10},
    {18893, 10},
    {18894, 10},
    {18895, 10},
    {18896, 10},
    {18897, 10},
    {18898, 10},
    {18899, 10},
    {18900, 10},
    {18901, 10},
    {18902, 10},
    {18903, 10},
    {18904, 10},
    {18905, 10},
    {18906, 10},
    {18907, 10},
    {18908, 10},
    {18909, 10},
    {18910, 10},
    {18911, 10},
    {18912, 10},
    {18913, 10},
    {18914, 10},
    {18915, 10},
    {18916, 10},
    {18917, 10},
    {18918, 10},
    {18919, 10},
    {18920, 10},
    {18921, 25},
    {18922, 25},
    {18923, 25},
    {18924, 25},
    {18925, 25},
    {18926, 20},
    {18927, 20},
    {18928, 20},
    {18929, 20},
    {18930, 20},
    {18931, 20},
    {18932, 20},
    {18933, 20},
    {18934, 20},
    {18935, 20},
    {19006, 15},
    {19007, 15},
    {19008, 15},
    {19009, 15},
    {19010, 15},
    {19011, 15},
    {19012, 15},
    {19013, 15},
    {19014, 15},
    {19015, 15},
    {19016, 15},
    {19017, 15},
    {19018, 15},
    {19019, 15},
    {19020, 15},
    {19021, 15},
    {19022, 15},
    {19023, 20},
    {19024, 15},
    {19025, 15},
    {19026, 15},
    {19027, 15},
    {19028, 15},
    {19029, 15},
    {19030, 15},
    {19031, 15},
    {19032, 15},
    {19033, 15},
    {19034, 15},
    {19035, 15},
    {19036, 30},
    {19037, 30},
    {19038, 30},
    {19039, 45},
    {19040, 45},
    {19041, 45},
    {19042, 45},
    {19043, 45},
    {19044, 45},
    {19045, 45},
    {19046, 45},
    {19047, 45},
    {19048, 45},
    {19049, 45},
    {19050, 45},
    {19317, 220},
    {19318, 200},
    {19515, 330},
    {331, 50},
    {334, 35},
    {336, 30},
    {337, 45},
    {339, 60}
};

new AttachmentBones[][24] =
{
    {"Coluna vertebral"},
    {"Cabeça"},
    {"Braço esquerdo"},
    {"Braço direito"},
    {"Mão esquerda"},
    {"Mão direita"},
    {"Coxa esquerda"},
    {"Coxa direita"},
    {"Pé esquerdo"},
    {"Pé direito"},
    {"Panturrilha direita"},
    {"Panturrilha esquerda"},
    {"Antebraço esquerdo"},
    {"Antebraço direito"},
    {"Clavícula esquerda"},
    {"Clavícula direita"},
    {"Pescoço"},
    {"Mandíbula"}
};

new ModifyingSlot[MAX_PLAYERS];
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
    if(dialogid == school_bag && response)
    {
        switch(listitem)
        {
            case 0:
            {
                new txt[2000];

                strcat(txt, "{CCCCCC}Nome\t {CCCCCC}Posição\t {CCCCCC}Status\n");

                if(IsPlayerVip(playerid) || IsPlayerIntern(playerid))
                {
                    for(new slot = 0; slot < MAX_ACCESSORIES; slot++)
                    {
                        if(ao[playerid][slot][ao_model])
                        {
                            format(String, 100, "{FFFFFF}%s\t {FF4000}%s\t %s\n", AccessoriesName(ao[playerid][slot][ao_model]), AttachmentBones[ ( ao[playerid][slot][ao_bone] - 1 ) ], ( ao[playerid][slot][ao_connected] ? ("{1B6302}Conectado") : ("{FF0000}Desconectado") ));
                            strcat(txt, String);
                        }
                        else
                        {
                            strcat(txt, "{FFFFFF}N/A\t {FF4000}N/A\t {FF0000}N/A\n");
                        }
                    }
                }
                else
                {
                    for(new slot = 0; slot < 5; slot++)
                    {
                        if(ao[playerid][slot][ao_model])
                        {
                            format(String, 100, "{FFFFFF}%s\t {FF4000}%s\t %s\n", AccessoriesName(ao[playerid][slot][ao_model]), AttachmentBones[ ( ao[playerid][slot][ao_bone] - 1 ) ], ( ao[playerid][slot][ao_connected] ? ("{1B6302}Conectado") : ("{FF0000}Desconectado") ));
                            strcat(txt, String);
                        }
                        else
                        {
                            strcat(txt, "{FFFFFF}N/A\t {FF4000}N/A\t {FF0000}N/A\n");
                        }
                    }
                }

                ShowPlayerDialog(playerid, school_bag_acce, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Acessórios", txt, "Continuar", "Cancelar");
                return 1;
            }
            case 1:
            {
                ShowPlayerDialog(playerid, school_bag_weapon, DIALOG_STYLE_LIST, "{FF0000}Armas", "{FFFFFF}Pegar arma\nGuardar arma", "Continuar", "Cancelar");
                return 1;
            }
        }
        return 1;
    }
    if(dialogid == school_bag_acce && response)
    {
        for(new slot = 0; slot < MAX_ACCESSORIES; slot++)
        {
            if(listitem == slot)
            {
                if(!ao[playerid][slot][ao_model])
                    return SendClientMessage(playerid, Erro, "Não tem acessório neste slot");

                ModifyingSlot[playerid] = slot;

                new txt[50];
                strcat(txt, ( ao[playerid][ModifyingSlot[playerid]][ao_connected] ? ("Desconectar\n") : ("Conectar\n")));
                strcat(txt, "Editar\n");
                strcat(txt, "Vender\n");

                format(String, sizeof(String), "{FF0000}%s", AccessoriesName(ao[playerid][ModifyingSlot[playerid]][ao_model]));

                ShowPlayerDialog(playerid, school_bag_acce_edit, DIALOG_STYLE_LIST, String, txt, "Continuar", "Cancelar");
                break;
            }
        }
        return 1;
    }
    if(dialogid == school_bag_acce_edit && response)
    {
        switch(listitem)
        {
            case 0:
            {
                if(ao[playerid][ModifyingSlot[playerid]][ao_connected])
                {
                    RemovePlayerAttachedObject(playerid, ModifyingSlot[playerid]);

                    ao[playerid][ModifyingSlot[playerid]][ao_connected] = false;

                    format(String, sizeof(String), "Acessório {1B6302}%s {FFFFFF}desconectado da {FF4000}%s", AccessoriesName(ao[playerid][ModifyingSlot[playerid]][ao_model]), AttachmentBones[ao[playerid][ModifyingSlot[playerid]][ao_bone] - 1]);
                    SendClientMessage(playerid, White, String);
                }
                else
                {
                    SetPlayerAttachedObject(playerid, ModifyingSlot[playerid],
                    ao[playerid][ModifyingSlot[playerid]][ao_model],
                    ao[playerid][ModifyingSlot[playerid]][ao_bone],
                    ao[playerid][ModifyingSlot[playerid]][ao_x],
                    ao[playerid][ModifyingSlot[playerid]][ao_y],
                    ao[playerid][ModifyingSlot[playerid]][ao_z],
                    ao[playerid][ModifyingSlot[playerid]][ao_rx],
                    ao[playerid][ModifyingSlot[playerid]][ao_ry],
                    ao[playerid][ModifyingSlot[playerid]][ao_rz],
                    ao[playerid][ModifyingSlot[playerid]][ao_sx],
                    ao[playerid][ModifyingSlot[playerid]][ao_sy],
                    ao[playerid][ModifyingSlot[playerid]][ao_sz]);

                    ao[playerid][ModifyingSlot[playerid]][ao_connected] = true;

                    format(String, sizeof(String), "Acessório {1B6302}%s {FFFFFF}conectado na {FF4000}%s", AccessoriesName(ao[playerid][ModifyingSlot[playerid]][ao_model]), AttachmentBones[ao[playerid][ModifyingSlot[playerid]][ao_bone] - 1]);
                    SendClientMessage(playerid, White, String);
                }
                return 1;
            }
            case 1:
            {
                if(!ao[playerid][ModifyingSlot[playerid]][ao_connected])
                    return SendClientMessage(playerid, Erro, "Conecte o acessório para poder editar");

                EditAttachedObject(playerid, ModifyingSlot[playerid]);
                return 1;
            }
            case 2: ShowPlayerDialog(playerid, school_bag_acce_sell, DIALOG_STYLE_MSGBOX, "{FF0000}Confirmação de Venda", "{FFFFFF}Deseja continuar com a venda do acessório?", "Sim", "Não");
        }
        return 1;
    }
    if(dialogid == school_bag_acce_sell && response)
    {
        if(ao[playerid][ModifyingSlot[playerid]][ao_connected]) RemovePlayerAttachedObject(playerid, ModifyingSlot[playerid]);

        PlayerInfo[playerid][Dinheiro] += ao[playerid][ModifyingSlot[playerid]][ao_value];
        UpdatePlayerMoney(playerid);

        format(String, 100, "Acessório \"{FF4000}%s{FFFFFF}\" vendido por {1B6302}$%s", AccessoriesName(ao[playerid][ModifyingSlot[playerid]][ao_model]), IsMoney(ao[playerid][ModifyingSlot[playerid]][ao_value], "."));

        new query[100];
        mysql_format(IDConexao, query, 100, "DELETE FROM `Accessories` WHERE `slot`='%d' AND `id_contas`='%d'", ModifyingSlot[playerid], PlayerInfo[playerid][ID]);
        mysql_query(IDConexao, query);

        ao[playerid][ModifyingSlot[playerid]][ao_model] = 0;
        ao[playerid][ModifyingSlot[playerid]][ao_value] = 0;
        ao[playerid][ModifyingSlot[playerid]][ao_bone] = 0;
        ao[playerid][ModifyingSlot[playerid]][ao_x] = 0;
        ao[playerid][ModifyingSlot[playerid]][ao_y] = 0;
        ao[playerid][ModifyingSlot[playerid]][ao_z] = 0;
        ao[playerid][ModifyingSlot[playerid]][ao_rx] = 0;
        ao[playerid][ModifyingSlot[playerid]][ao_ry] = 0;
        ao[playerid][ModifyingSlot[playerid]][ao_rz] = 0;
        ao[playerid][ModifyingSlot[playerid]][ao_sx] = 0;
        ao[playerid][ModifyingSlot[playerid]][ao_sy] = 0;
        ao[playerid][ModifyingSlot[playerid]][ao_sz] = 0;

        SendClientMessage(playerid, White, String);
        return 1;
    }
    if(dialogid == school_bag_weapon && response)
    {
        switch(listitem)
        {
            case 0:
            {
                new txt[2000];

                strcat(txt, "{CCCCCC}Arma\t {1B6302}Munição\n\n");

                if(IsPlayerVip(playerid) || IsPlayerIntern(playerid))
                {
                    for(new slot = 0; slot < MAX_SLOT_BAG; slot++)
                    {
                        if(BagInfo[slot][playerid][bi_weaponid])
                        {
                            GetWeaponName(BagInfo[slot][playerid][bi_weaponid], gunname, sizeof(gunname));

                            format(String, sizeof(String), "{CCCCCC}%s\t {1B6302}%s\n", gunname, IsMoney(BagInfo[slot][playerid][bi_ammunation], "."));
                            strcat(txt, String);
                        }
                        else
                        {
                            strcat(txt, "{CCCCCC}N/A\t {1B6302}0\n\n");
                        }
                    }
                }
                else
                {
                    for(new slot = 0; slot < 5; slot++)
                    {
                        if(BagInfo[slot][playerid][bi_weaponid])
                        {
                            GetWeaponName(BagInfo[slot][playerid][bi_weaponid], gunname, sizeof(gunname));

                            format(String, sizeof(String), "{CCCCCC}%s\t {1B6302}%s\n", gunname, IsMoney(BagInfo[slot][playerid][bi_ammunation], "."));
                            strcat(txt, String);
                        }
                        else
                        {
                            strcat(txt, "{CCCCCC}N/A\t {1B6302}0\n\n");
                        }
                    }
                }

                ShowPlayerDialog(playerid, school_bag_get, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Mochila", txt, "Continuar", "Cancelar");
                return 1;
            }
            case 1:
            {
                if(!GetPlayerWeapon(playerid))
                    return SendClientMessage(playerid, Erro, "Você não tem arma em sua mão");

                if(IsPlayerVip(playerid) || IsPlayerIntern(playerid))
                {
                    for(new slot = 0; slot < MAX_SLOT_BAG; slot++)
                    {
                        if(!BagInfo[slot][playerid][bi_weaponid])
                        {
                            for(new i = 0; i < 13; ++i)
                    		{
                                GetPlayerWeaponData(playerid, i, Armas[i][0], Armas[i][1]);

                                if(GetPlayerWeapon(playerid) == Armas[i][0])
                                {
                                    BagInfo[slot][playerid][bi_weaponid] = Armas[i][0];
                                    BagInfo[slot][playerid][bi_ammunation] = Armas[i][1];
                                }
                    		}

                    		RemovePlayerWeapon(playerid, GetPlayerWeapon(playerid)) ;

                            GetWeaponName(BagInfo[slot][playerid][bi_weaponid], gunname, sizeof(gunname));

                            format(String, sizeof(String), "Você guardou em sua mochila {FF8000}%s {FFFFFF}com {FF4000}%s {FFFFFF}balas", gunname, IsMoney(BagInfo[slot][playerid][bi_ammunation], "."));
                            SendClientMessage(playerid, White, String);

                            UpdatePlayerBag(playerid, slot);
                            return 1;
                        }
                    }
                }
                else
                {
                    for(new slot = 0; slot < 5; slot++)
                    {
                        if(!BagInfo[slot][playerid][bi_weaponid])
                        {
                            for(new i = 0; i < 13; ++i)
                    		{
                                GetPlayerWeaponData(playerid, i, Armas[i][0], Armas[i][1]) ;

                                if(GetPlayerWeapon(playerid) == Armas[i][0])
                                {
                                    BagInfo[slot][playerid][bi_weaponid] = Armas[i][0];
                                    BagInfo[slot][playerid][bi_ammunation] = Armas[i][1];
                                }
                    		}

                    		RemovePlayerWeapon(playerid, GetPlayerWeapon(playerid)) ;

                            GetWeaponName(BagInfo[slot][playerid][bi_weaponid], gunname, sizeof(gunname));

                            format(String, sizeof(String), "Você guardou em sua mochila {FF8000}%s {FFFFFF}com {FF4000}%s {FFFFFF}balas", gunname, IsMoney(BagInfo[slot][playerid][bi_ammunation], "."));
                            SendClientMessage(playerid, White, String);

                            UpdatePlayerBag(playerid, slot);
                            return 1;
                        }
                    }
                }
                return SendClientMessage(playerid, Erro, "Sua mochila não tem mais espaço");
            }
        }
        return 1;
    }
    if(dialogid == school_bag_get && response)
    {
        for(new slot = 0; slot < MAX_SLOT_BAG; slot++)
        {
            if(listitem == slot)
            {
                if(!BagInfo[slot][playerid][bi_weaponid])
                    return SendClientMessage(playerid, Erro, "Não tem nenhuma arma nesse slot");

                GivePlayerWeapon(playerid, BagInfo[slot][playerid][bi_weaponid], BagInfo[slot][playerid][bi_ammunation]);

                GetWeaponName(BagInfo[slot][playerid][bi_weaponid], gunname, sizeof(gunname));

                format(String, sizeof(String), "Você pegou de sua mochila uma {FF8000}%s {FFFFFF}com {FF4000}%s {FFFFFF}balas", gunname, IsMoney(BagInfo[slot][playerid][bi_ammunation], "."));
                SendClientMessage(playerid, White, String);

                BagInfo[slot][playerid][bi_weaponid] = 0;
                BagInfo[slot][playerid][bi_ammunation] = 0;
                UpdatePlayerBag(playerid, slot);
                break;
            }
        }
        return 1;
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
    new query[100];

    mysql_format(IDConexao, query, sizeof(query), "UPDATE `Bag` SET `weapon%d`='%d', `ammun%d`='%d' WHERE `id_contas`='%d'", slotid, BagInfo[slotid][playerid][bi_weaponid], slotid, BagInfo[slotid][playerid][bi_ammunation], PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);
    return 1;
}

CMD:mochila(playerid)
{
    if(!PlayerInfo[playerid][bag])
        return SendClientMessage(playerid, Erro, "Você não tem mochila");

    ShowPlayerDialog(playerid, school_bag, DIALOG_STYLE_LIST, "{FF0000}Mochila", "{FFFFFF}Acessórios\nArmas", "Continuar", "Cancelar");
    return 1;
}
