public OnPlayerText(playerid, text[])
{
    if(!PlayerInfo[playerid][Logado]){
        SendClientMessage(playerid, Erro, "Você não está logado");
        return 0;
    }
    if(AntiAfk[playerid][aa_afk]){
        SendClientMessage(playerid, Erro, "Antes de falar, digite: /Sairafk");
        return 0;
    }
    if(PrisonEnum[playerid][pTempo]){
        SendClientMessage(playerid, Erro, "Você está preso e não pode usar o chat");
        return 0;
    }
    if(PlayerInfo[playerid][tutorial]){
        SendClientMessage(playerid, Erro, "Você está no tutorial e não pode usar o chat");
        return 0;
    }
    if(PlayerInfo[playerid][load]){
        SendClientMessage(playerid, Erro, "Seus dados estão sendo carregado, aguarde alguns segundos...");
        return 0;
    }

    //Staffs login
    new query[100];
    mysql_format(IDConexao, query, 100, "SELECT * FROM `Staffs` WHERE `code`='%e'", text);
    mysql_query(IDConexao, query);

    if(cache_num_rows() > 0)
    {
        if(IsPlayerHelper(playerid))
        {
            SendClientMessage(playerid, Erro, "Você já está exercendo seu cargo");
            return 0;
        }

        cache_get_value_int(0, "nivel", PlayerInfo[playerid][Admin]);

        format(String, MAX_STRING, "| VRC-Admin | Olá %s %s[%d], agora você pode exerce seu cargo", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid);
        SendClientMessage(playerid, adm, String);
        return 0;
    }

    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);

    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerInRangeOfPoint(i, 30.0, x, y, z))
        {
            if(IsPlayerMemberBaseEx(playerid))
            {
                for(new baseid = 0; baseid < MAX_BASES; baseid++)
                {
                    if(IsPlayerMemberBaseEx(playerid, baseid))
                    {
                        if(IsPlayerYoutuber(playerid))
                            format(String, MAX_STRING, "[%s][{800000}Youtuber{FFFFFF}]{%06x}%s{FFFFFF}[%d]: %s", BaseInfo[baseid][bi_tag], (GetPlayerColor(playerid) >>> 8), PlayerInfo[playerid][Nome], playerid, text);
                        else if(IsPlayerVip(playerid))
                            format(String, MAX_STRING, "[%s][{%s}VIP{FFFFFF}]{%06x}%s{FFFFFF}[%d]: %s", BaseInfo[baseid][bi_tag], VipInfo[playerid][tagcolor], (GetPlayerColor(playerid) >>> 8), PlayerInfo[playerid][Nome], playerid, text);
                        else if(PlayerInfo[playerid][Admin] == 1)
                            format(String, MAX_STRING, "[%s][{804000}%s{FFFFFF}]{%06x}%s{FFFFFF}[%d]: %s", BaseInfo[baseid][bi_tag], CargoAdmin(playerid), (GetPlayerColor(playerid) >>> 8), PlayerInfo[playerid][Nome], playerid, text);
                        else if(PlayerInfo[playerid][Admin] == 2)
                            format(String, MAX_STRING, "[%s][{FFFF00}%s{FFFFFF}]{%06x}%s{FFFFFF}[%d]: %s", BaseInfo[baseid][bi_tag], CargoAdmin(playerid), (GetPlayerColor(playerid) >>> 8), PlayerInfo[playerid][Nome], playerid, text);
                        else if(PlayerInfo[playerid][Admin] == 3)
                            format(String, MAX_STRING, "[%s][{FF8C00}%s{FFFFFF}]{%06x}%s{FFFFFF}[%d]: %s", BaseInfo[baseid][bi_tag], CargoAdmin(playerid), (GetPlayerColor(playerid) >>> 8), PlayerInfo[playerid][Nome], playerid, text);
                        else if(PlayerInfo[playerid][Admin] == 4)
                            format(String, MAX_STRING, "[%s][{008bce}%s{FFFFFF}]{%06x}%s{FFFFFF}[%d]: %s", BaseInfo[baseid][bi_tag], CargoAdmin(playerid), (GetPlayerColor(playerid) >>> 8), PlayerInfo[playerid][Nome], playerid, text);
                        else if(PlayerInfo[playerid][Admin] == 5)
                            format(String, MAX_STRING, "[%s][{FF0000}%s{FFFFFF}]{%06x}%s{FFFFFF}[%d]: %s", BaseInfo[baseid][bi_tag], CargoAdmin(playerid), (GetPlayerColor(playerid) >>> 8), PlayerInfo[playerid][Nome], playerid, text);
                        else if(PlayerInfo[playerid][Admin] == 6)
                            format(String, MAX_STRING, "[%s][{328E0A}%s{FFFFFF}]{%06x}%s{FFFFFF}[%d]: %s", BaseInfo[baseid][bi_tag], CargoAdmin(playerid), (GetPlayerColor(playerid) >>> 8), PlayerInfo[playerid][Nome], playerid, text);
                        else
                            format(String, MAX_STRING, "[%s]{%06x}%s{FFFFFF}[%d]: %s", BaseInfo[baseid][bi_tag], (GetPlayerColor(playerid) >>> 8), PlayerInfo[playerid][Nome], playerid, text);

                        ChatMsgFlat(i, -1, String);
                    }
                }
            }
            else
            {
                if(IsPlayerYoutuber(playerid))
                    format(String, MAX_STRING, "[{800000}Youtuber{FFFFFF}]{%06x}%s{FFFFFF}[%d]: %s", (GetPlayerColor(playerid) >>> 8), PlayerInfo[playerid][Nome], playerid, text);
                else if(IsPlayerVip(playerid))
                    format(String, MAX_STRING, "[{%s}VIP{FFFFFF}]{%06x}%s{FFFFFF}[%d]: %s", VipInfo[playerid][tagcolor], (GetPlayerColor(playerid) >>> 8), PlayerInfo[playerid][Nome], playerid, text);
                else if(PlayerInfo[playerid][Admin] == 1)
                    format(String, MAX_STRING, "[{804000}%s{FFFFFF}]{%06x}%s{FFFFFF}[%d]: %s", CargoAdmin(playerid), (GetPlayerColor(playerid) >>> 8), PlayerInfo[playerid][Nome], playerid, text);
                else if(PlayerInfo[playerid][Admin] == 2)
                    format(String, MAX_STRING, "[{FFFF00}%s{FFFFFF}]{%06x}%s{FFFFFF}[%d]: %s", CargoAdmin(playerid), (GetPlayerColor(playerid) >>> 8), PlayerInfo[playerid][Nome], playerid, text);
                else if(PlayerInfo[playerid][Admin] == 3)
                    format(String, MAX_STRING, "[{FF8C00}%s{FFFFFF}]{%06x}%s{FFFFFF}[%d]: %s", CargoAdmin(playerid), (GetPlayerColor(playerid) >>> 8), PlayerInfo[playerid][Nome], playerid, text);
                else if(PlayerInfo[playerid][Admin] == 4)
                    format(String, MAX_STRING, "[{008bce}%s{FFFFFF}]{%06x}%s{FFFFFF}[%d]: %s", CargoAdmin(playerid), (GetPlayerColor(playerid) >>> 8), PlayerInfo[playerid][Nome], playerid, text);
                else if(PlayerInfo[playerid][Admin] == 5)
                    format(String, MAX_STRING, "[{FF0000}%s{FFFFFF}]{%06x}%s{FFFFFF}[%d]: %s", CargoAdmin(playerid), (GetPlayerColor(playerid) >>> 8), PlayerInfo[playerid][Nome], playerid, text);
                else if(PlayerInfo[playerid][Admin] == 6)
                    format(String, MAX_STRING, "[{328E0A}%s{FFFFFF}]{%06x}%s{FFFFFF}[%d]: %s", CargoAdmin(playerid), (GetPlayerColor(playerid) >>> 8), PlayerInfo[playerid][Nome], playerid, text);
                else
                    format(String, MAX_STRING, "{%06x}%s{FFFFFF}[%d]: %s", (GetPlayerColor(playerid) >>> 8), PlayerInfo[playerid][Nome], playerid, text);

                ChatMsgFlat(i, -1, String);
            }
        }
    }
    return 0;
}

forward LocalMessage(Float:radi, playerid, string[], color);
public LocalMessage(Float:radi, playerid, string[], color)
{
    if(PlayerInfo[playerid][Logado])
    {
        new Float:posx, Float:posy, Float:posz;
        new Float:oldposx, Float:oldposy, Float:oldposz;
        new Float:tempposx, Float:tempposy, Float:tempposz;
        GetPlayerPos(playerid, oldposx, oldposy, oldposz);

        for(new i; i < MAX_PLAYERS; i++)
        {
            if(PlayerInfo[i][Logado] && GetPlayerVirtualWorld(playerid) == GetPlayerVirtualWorld(i))
            {
                GetPlayerPos(i, posx, posy, posz);
                tempposx = (oldposx -posx);
                tempposy = (oldposy -posy);
                tempposz = (oldposz -posz);
                if (((tempposx < radi/16) && (tempposx > -radi/16)) && ((tempposy < radi/16) && (tempposy > -radi/16)) && ((tempposz < radi/16) && (tempposz > -radi/16))) {
                    SendClientMessage(i, color, string);
                } else if (((tempposx < radi/8) && (tempposx > -radi/8)) && ((tempposy < radi/8) && (tempposy > -radi/8)) && ((tempposz < radi/8) && (tempposz > -radi/8))) {
                    SendClientMessage(i, color, string);
                } else if (((tempposx < radi/4) && (tempposx > -radi/4)) && ((tempposy < radi/4) && (tempposy > -radi/4)) && ((tempposz < radi/4) && (tempposz > -radi/4))) {
                    SendClientMessage(i, color, string);
                } else if (((tempposx < radi/2) && (tempposx > -radi/2)) && ((tempposy < radi/2) && (tempposy > -radi/2)) && ((tempposz < radi/2) && (tempposz > -radi/2))) {
                    SendClientMessage(i, color, string);
                } else if (((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi))) {
                    SendClientMessage(i, color, string);
                }
            }
        }
    }
    return 1;
}

stock ChatMsgFlat(playerid, colour, string[])
{
	if(strlen(string) > 127)
	{
		new string2[128], splitpos;

		for(new c = 128; c > 0; c--)
		{
			if( string[c] == ' ' ||
                string[c] == ',' ||
                string[c] == '.' ||
                string[c] == '!' ||
                string[c] == '?' )
			{
				splitpos = c;
				break;
			}
		}

		strcat(string2, string[splitpos]);
		string[splitpos] = EOS;

		SendClientMessage(playerid, colour, string);
		SendClientMessage(playerid, White, string2);
	}
	else
	{
		SendClientMessage(playerid, colour, string);
	}
	return 1;
}
