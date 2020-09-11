#include YSI\y_hooks

#undef MAX_ACCESSORIES
#define MAX_ACCESSORIES 5
#define MAX_STORE_ACCESSORIES   116

new accestoreid[MAX_PLAYERS];

hook OnPlayerDisconnect(playerid, reason)
{
    accestoreid[playerid] = 0;
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == cost_accessories && response)
    {
        for(new x = 0; x < MAX_STORE_ACCESSORIES; x++)
        {
            if(listitem == x)
            {
                for(new slot = 0; slot < MAX_ACCESSORIES; slot++)
                {
                    if(!ao[playerid][slot][ao_model])
                    {
                        accestoreid[playerid] = x;
                        ModifyingSlot[playerid] = slot;

                        new txt[500];

                        for(new max_bone = 18, boneid = 0; boneid < max_bone; boneid++)
                        {
                            format(String, sizeof(String), "{CCCCCC}%s \n", AttachmentBones[boneid]);
                            strcat(txt, String);
                        }


                        format(String, sizeof(String), "{FF0000}Escolha posição do(a) %s", AccessoriesName(AttachmentObjectsList[x][aol_model]));

                        ShowPlayerDialog(playerid, cost_accessories1, DIALOG_STYLE_LIST, String, txt, "Continuar", "Cancelar");
                        return 1;
                    }
                }
            }
        }
        return 1;
    }
    if(dialogid == cost_accessories1 && response)
    {
        for(new max_bone = 18, boneid = 0; boneid < max_bone; boneid++)
        {
            if(listitem == boneid)
            {
                ao[playerid][ModifyingSlot[playerid]][ao_model] = AttachmentObjectsList[accestoreid[playerid]][aol_model];
                ao[playerid][ModifyingSlot[playerid]][ao_value] = AttachmentObjectsList[accestoreid[playerid]][aol_value];
                ao[playerid][ModifyingSlot[playerid]][ao_bone] = (boneid + 1);
                ao[playerid][ModifyingSlot[playerid]][ao_x] = 0;
                ao[playerid][ModifyingSlot[playerid]][ao_y] = 0;
                ao[playerid][ModifyingSlot[playerid]][ao_z] = 0;
                ao[playerid][ModifyingSlot[playerid]][ao_rx] = 0;
                ao[playerid][ModifyingSlot[playerid]][ao_ry] = 0;
                ao[playerid][ModifyingSlot[playerid]][ao_rz] = 0;
                ao[playerid][ModifyingSlot[playerid]][ao_sx] = 1.200;
                ao[playerid][ModifyingSlot[playerid]][ao_sy] = 1.100;
                ao[playerid][ModifyingSlot[playerid]][ao_sz] = 0.500;

                new query[500];
                mysql_format(IDConexao, query, 500, "INSERT INTO `Accessories` (`model`, `value`, `bone`, `sx`, `sy`, `sz`, `slot`, `id_contas`) VALUES ('%d', '%d', '%d', '%f', '%f', '%f', '%d', '%d')",
                ao[playerid][ModifyingSlot[playerid]][ao_model],
                ao[playerid][ModifyingSlot[playerid]][ao_value],
                ao[playerid][ModifyingSlot[playerid]][ao_bone],
                ao[playerid][ModifyingSlot[playerid]][ao_sx],
                ao[playerid][ModifyingSlot[playerid]][ao_sy],
                ao[playerid][ModifyingSlot[playerid]][ao_sz],
                ModifyingSlot[playerid],
                PlayerInfo[playerid][ID]);
                mysql_query(IDConexao, query);

                accestoreid[playerid] = 0;
                ModifyingSlot[playerid] = 0;
                return 1;
            }
        }
        return 1;
    }
    return 0;
}

public OnPlayerEditAttachedObject(playerid, response, index, modelid, boneid, Float:fOffsetX, Float:fOffsetY, Float:fOffsetZ, Float:fRotX, Float:fRotY, Float:fRotZ, Float:fScaleX, Float:fScaleY, Float:fScaleZ)
{
    if(!response)
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

        SendClientMessage(playerid, Erro, "Não foi salvo as configurações do acessório");
        return 1;
    }

    if(fScaleX < 0.0 || fScaleX > 1.5 || fScaleY < 0.0 || fScaleY > 1.5 || fScaleZ < 0.0 || fScaleZ > 1.5)
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
        SendClientMessage(playerid, Erro, "Seu item está muito distante/perto");
        return 1;
	}
	if(fOffsetX < -0.5 || fOffsetX > 0.5 || fOffsetY < -0.5 || fOffsetY > 0.5 || fOffsetZ < -0.5 || fOffsetZ > 0.5)
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
        SendClientMessage(playerid, Erro, "Seu item é muito grande/pequeno");
        return 1;
	}

    ao[playerid][ModifyingSlot[playerid]][ao_x] = fOffsetX;
    ao[playerid][ModifyingSlot[playerid]][ao_y] = fOffsetY;
    ao[playerid][ModifyingSlot[playerid]][ao_z] = fOffsetZ;
    ao[playerid][ModifyingSlot[playerid]][ao_rx] = fRotX;
    ao[playerid][ModifyingSlot[playerid]][ao_ry] = fRotY;
    ao[playerid][ModifyingSlot[playerid]][ao_rz] = fRotZ;
    ao[playerid][ModifyingSlot[playerid]][ao_sx] = fScaleX;
    ao[playerid][ModifyingSlot[playerid]][ao_sy] = fScaleY;
    ao[playerid][ModifyingSlot[playerid]][ao_sz] = fScaleZ;

    new query[1000];
    mysql_format(IDConexao, query, sizeof(query), "UPDATE `Accessories` SET `model`='%d', `bone`='%d', `x`='%f', `y`='%f', `z`='%f', `rx`='%f', `ry`='%f', `rz`='%f', `sx`='%f', `sy`='%f', `sz`='%f' WHERE `slot`='%d' AND `id_contas`='%d'",
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
    ao[playerid][ModifyingSlot[playerid]][ao_sz],
    ModifyingSlot[playerid],
    PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);

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
    return 0;
}

hook OnPlayerSpawn(playerid)
{
    for(new slot; slot < MAX_ACCESSORIES; slot++)
	{
        if(ao[playerid][slot][ao_connected])
        {
            SetPlayerAttachedObject(playerid, slot,
            ao[playerid][slot][ao_model],
            ao[playerid][slot][ao_bone],
            ao[playerid][slot][ao_x],
            ao[playerid][slot][ao_y],
            ao[playerid][slot][ao_z],
            ao[playerid][slot][ao_rx],
            ao[playerid][slot][ao_ry],
            ao[playerid][slot][ao_rz],
            ao[playerid][slot][ao_sx],
            ao[playerid][slot][ao_sy],
            ao[playerid][slot][ao_sz]);
        }
	}
	return 1;
}

forward DB_LoadAccessories(playerid, slot);
public DB_LoadAccessories(playerid, slot)
{
    if(cache_num_rows() == 0) return 0;

    cache_get_value_int(0, "model", ao[playerid][slot][ao_model]);
    cache_get_value_int(0, "value", ao[playerid][slot][ao_value]);
    cache_get_value_int(0, "bone", ao[playerid][slot][ao_bone]);
    cache_get_value_float(0, "x", ao[playerid][slot][ao_x]);
    cache_get_value_float(0, "y", ao[playerid][slot][ao_y]);
    cache_get_value_float(0, "z", ao[playerid][slot][ao_z]);
    cache_get_value_float(0, "rx", ao[playerid][slot][ao_rx]);
    cache_get_value_float(0, "ry", ao[playerid][slot][ao_ry]);
    cache_get_value_float(0, "rz", ao[playerid][slot][ao_rz]);
    cache_get_value_float(0, "sx", ao[playerid][slot][ao_sx]);
    cache_get_value_float(0, "sy", ao[playerid][slot][ao_sy]);
    cache_get_value_float(0, "sz", ao[playerid][slot][ao_sz]);
    return 1;
}

stock AccessoriesName(accessoriesid)
{
    new var[30];

    switch(accessoriesid)
    {
        case 18632: var = "Vara de Pesca";
        case 18633: var = "Chave Inglesa";
        case 18634: var = "Pé de Cabra";
        case 18635: var = "Martelo";
        case 18636: var = "Boné Policia";
        case 18637: var = "Escudo Policia";
        case 18638: var = "Capacete1";
        case 18639: var = "Chapeu Preto";
        case 18640: var = "Capacete2";
        case 18975: var = "Cabelo1";
        case 19136: var = "Cabelo2";
        case 19274: var = "Peruca de Palhaço";
        case 18641: var = "Lanterna Pequena";
        case 18642: var = "Taser";
        case 18643: var = "Ponteiro Laser";
        case 18644: var = "Chave de Fenda";
        case 18645: var = "Capacete";
        case 18890: var = "Ancinho";
        case 18891: var = "Bandana1";
        case 18892: var = "Bandana2";
        case 18893: var = "Bandana3";
        case 18894: var = "Bandana4";
        case 18895: var = "Bandana5";
        case 18896: var = "Bandana6";
        case 18897: var = "Bandana7";
        case 18898: var = "Bandana8";
        case 18899: var = "Bandana9";
        case 18900: var = "Bandana10";
        case 18901: var = "Bandana11";
        case 18902: var = "Bandana12";
        case 18903: var = "Bandana13";
        case 18904: var = "Bandana14";
        case 18905: var = "Bandana15";
        case 18906: var = "Bandana16";
        case 18907: var = "Bandana17";
        case 18908: var = "Bandana18";
        case 18909: var = "Bandana19";
        case 18910: var = "Bandana20";
        case 18911: var = "Bandana21";
        case 18912: var = "Bandana22";
        case 18913: var = "Bandana23";
        case 18914: var = "Bandana24";
        case 18915: var = "Bandana25";
        case 18916: var = "Bandana26";
        case 18917: var = "Bandana27";
        case 18918: var = "Bandana28";
        case 18919: var = "Bandana29";
        case 18920: var = "Bandana30";
        case 18921: var = "Boina1";
        case 18922: var = "Boina2";
        case 18923: var = "Boina3";
        case 18924: var = "Boina4";
        case 18925: var = "Boina5";
        case 18926: var = "Boné1";
        case 18927: var = "Boné2";
        case 18928: var = "Boné3";
        case 18929: var = "Boné4";
        case 18930: var = "Boné5";
        case 18931: var = "Boné6";
        case 18932: var = "Boné7";
        case 18933: var = "Boné8";
        case 18934: var = "Boné9";
        case 18935: var = "Boné10";
        case 19006: var = "Óculos1";
        case 19007: var = "Óculos2";
        case 19008: var = "Óculos3";
        case 19009: var = "Óculos4";
        case 19010: var = "Óculos5";
        case 19011: var = "Óculos6";
        case 19012: var = "Óculos7";
        case 19013: var = "Óculos8";
        case 19014: var = "Óculos9";
        case 19015: var = "Óculos10";
        case 19016: var = "Óculos11";
        case 19017: var = "Óculos12";
        case 19018: var = "Óculos13";
        case 19019: var = "Óculos14";
        case 19020: var = "Óculos15";
        case 19021: var = "Óculos16";
        case 19022: var = "Óculos17";
        case 19023: var = "Óculos18";
        case 19024: var = "Óculos19";
        case 19025: var = "Óculos20";
        case 19026: var = "Óculos21";
        case 19027: var = "Óculos22";
        case 19028: var = "Óculos23";
        case 19029: var = "Óculos24";
        case 19030: var = "Óculos25";
        case 19031: var = "Óculos26";
        case 19032: var = "Óculos27";
        case 19033: var = "Óculos28";
        case 19034: var = "Óculos29";
        case 19035: var = "Óculos30";
        case 19036: var = "Mascara1";
        case 19037: var = "Mascara2";
        case 19038: var = "Mascara3";
        case 19039: var = "Relógio1";
        case 19040: var = "Relógio2";
        case 19041: var = "Relógio3";
        case 19042: var = "Relógio4";
        case 19043: var = "Relógio5";
        case 19044: var = "Relógio6";
        case 19045: var = "Relógio7";
        case 19046: var = "Relógio8";
        case 19047: var = "Relógio9";
        case 19048: var = "Relógio10";
        case 19049: var = "Relógio11";
        case 19050: var = "Relógio12";
        case 19317: var = "Guitarra1";
        case 19318: var = "Guitarra2";
        case 19515: var = "Colete";
        case 331: var = "Soco Inglês";
        case 334: var = "Cacetéte";
        case 336: var = "Taco";
        case 337: var = "Pá";
        case 339: var = "Katana";
        default: var = "Nome Inválido";
    }
    return var;
}

CMD:acessorios(playerid)
{
    if(!IsPlayerInDynamicCP(playerid, CPS_StoreSkins[0]))
        return SendClientMessage(playerid, Erro, "Você não está no checkpoint da loja de skins");

    if(!PlayerInfo[playerid][bag])
        return SendClientMessage(playerid, Erro, "Você não tem mochila, compre uma em qualquer utilitário");

    for(new slot = 0; slot < MAX_ACCESSORIES; slot++)
    {
        if(!ao[playerid][slot][ao_model])
        {
            accestoreid[playerid] = 0;

            new txt[3600], str[100];

            strcat(txt, "{CCCCCC}Nome\t {1B6302}Preço\n");

            for(new x = 0; x < MAX_STORE_ACCESSORIES; x++)
            {
                format(str, 100, "{CCCCCC}%s\t {1B6302}$%s\n", AccessoriesName(AttachmentObjectsList[x][aol_model]), IsMoney(AttachmentObjectsList[x][aol_value], "."));
                strcat(txt, str);
            }

            ShowPlayerDialog(playerid, cost_accessories, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Acessórios", txt, "Comprar", "Cancelar");
            return 1;
        }
    }
    return SendClientMessage(playerid, Erro, "Você alcançou o limite de acessórios");
}
