	if(strcmp(cmd,"/venderskin", true)==0)
	{
    	if(PlayerInfo[playerid][Profissao] != VendedorSkins)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não tem permissão!");

        new tmp[128], tmp1[128], tmp2[128], id, idskin, ammount;

        tmp = strtok(cmdtext, idx);
        tmp1 = strtok(cmdtext, idx);
        tmp2 = strtok(cmdtext, idx);

        if(!strlen(tmp) || !strlen(tmp1) || !strlen(tmp2))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /VenderSkin [id] [id-idskin] [preço]");

    	id = strval(tmp);
    	idskin = strval(tmp1);
        ammount = strval(tmp2);

        if(PlayerInfo[id][Logado] == false)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não está conectado(a)!");

        if(playerid == id)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não pode efetuar comando em sí mesmo!");

        if(!(idskin >= 0 && idskin <= 311))
            return SendClientMessage(playerid, Erro, "| ERRO | ID de skin permitidos de 0 a 311!");

        if(idskin == 211 || idskin == 217)
            return SendClientMessage(playerid, Erro, "| ERRO | Skin reservada somente para membros da Administração!");

        if(ammount < 250  || ammount > 1000)
            return SendClientMessage(playerid, Erro, "| ERRO | Preço permitido de $250 a $1000!");

        format(String, sizeof(String), "| VENDEDOR DE SKINS | O(A) Vendedor(a) de skins %s[%d] te ofereceu a skin %d no valor de $%s", PlayerInfo[playerid][Nome], playerid, idskin, IsMoney(ammount));
        SendClientMessage(id, 0xFF80C0AA, String);
        format(String, sizeof(String), "| VENDEDOR DE SKINS | Você ofereceu a skin %d para o jogador(a) %s[%d] no valor de $%s", idskin, PlayerInfo[id][Nome], id, IsMoney(ammount));
        SendClientMessage(playerid, 0xFF80C0AA, String);
        SetTimerEx("SkinOffer", 1000, false, "iiii", playerid, id, idskin, ammount);
        OfferSkin[id] = true;
    	return 1;
	}
