public OnPlayerConnect(playerid)
{
    SetPlayerColor(playerid, White);
    SetPlayerName(playerid, "Verificando_Dispositivo");

    switch(random(3))
    {
        case 0: PlayAudioStreamForPlayer(playerid, "https://dc433.4shared.com/img/knZ_Orvrca/df294554/dlink__2Fdownload_2FknZ_5FOrvrca_2Frute21MICHAEL_5FYACKSON_5FTRILLER.mp3_3Fsbsr_3D0fce3a67a8f34f215a2638e88a072f7ea59_26bip_3DMTcwLjIzMy4zMy4yMzc_26lgfp_3D52_26bip_3DMTcwLjIzMy4zMy4yMzc/preview.mp3");
        case 1: PlayAudioStreamForPlayer(playerid, "https://dc588.4shared.com/img/2MB72KENgm/65bf9de9/dlink__2Fdownload_2F2MB72KENgm_2FCjbeards_5F-_5FIn_5FMy_5FHeart.mp3_3Fsbsr_3Da344ca97cb717741b94d99494e876b75a59_26bip_3DMTcwLjIzMy4zMy4yMzc_26lgfp_3D52_26bip_3DMTcwLjIzMy4zMy4yMzc/preview.mp3");
        case 2: PlayAudioStreamForPlayer(playerid, "https://dc727.4shared.com/img/fmgmjQziee/138d219a/dlink__2Fdownload_2FfmgmjQziee_2FNEFFEX_5F-_5FRumors.mp3_3Fsbsr_3D1538e7ad20264cc50543cfca50292e0da59_26bip_3DMTcwLjIzMy4zMy4yMzc_26lgfp_3D52_26bip_3DMTcwLjIzMy4zMy4yMzc/preview.mp3");
    }

    SetTimerEx("OnClearChat", 1000, false, "d", playerid);
	return 1;
}

public OnPlayerEnterDynamicRaceCP(playerid)
{
    if(!PlayerInfo[playerid][pds_in])
    {
        Gari_DynamicRaceCP(playerid);
        BoyNewspaper_DynamicRaceCP(playerid);
        Light_DynamicRaceCP(playerid);
        Thief_DynamicRaceCP(playerid);
        Loader_DynamicRaceCP(playerid);
        Motoboy_DynamicRaceCP(playerid);
        Vehicles_DynamicRaceCP(playerid);
    }
    else
    {
        DS_DynamicRaceCP(playerid);
    }
	return 1;
}

public OnPlayerClickTextDraw(playerid, Text:clickedid)
{
    if(clickedid == Text:INVALID_TEXT_DRAW)
    {
        if(!PlayerInfo[playerid][Logado]) {
            SelectTextDraw(playerid, Green);
        }

        if(LocationConcessionaire[playerid]) {
            LocationConcessionaire[playerid] = 0;
            HideTDConcessionaire(playerid);
        }

        if(CostSkin[playerid]) {
            CostSkin[playerid] = 0;
            HideTDPlayerSkinsStore(playerid);
        }

        if(Identity[playerid]) {
            Identity[playerid] = false;
            HideTDPlayerIdentity(playerid);
        }

        if(Banimento[playerid][b_ban]) {
            Banimento[playerid][b_ban] = false;
            HideTDPlayerBan(playerid);
        }

        return 1;
    }
    return 1;
}

public OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{
    ClickTextDrawLoginRegister(playerid, playertextid);
    ClickTextDrawConcessionaire(playerid, playertextid);
    ClickTextDrawSkinsStore(playerid, playertextid);
    ClickTextDrawIdentity(playerid, playertextid);
    ClickTextDrawBan(playerid, playertextid);
    ClickTextDrawPolice(playerid, playertextid);
    return 1;
}

forward OnClearChat(playerid);
public OnClearChat(playerid)
{
    for(new i = 0; i < 50; i++)
    {
        SendClientMessage(playerid, White, "");
    }
    for(new i = 0; i < 50; i++)
    {
        SendClientMessage(playerid, White, "");
    }
    return 1;
}

stock formatSeconds(seconds, &hours_left, &minutes_left, &seconds_left)
{
    hours_left = seconds/60/60;
    minutes_left = (seconds - hours_left*60*60 )/60;
    seconds_left = (seconds - hours_left*60*60 - minutes_left*60);
    return 1;
}

stock GetDistanceBetweenPlayers(playerid,playerid2)
{
    new Float:x1,Float:y1,Float:z1,Float:x2,Float:y2,Float:z2;
    new Float:dis;
    GetPlayerPos(playerid,x1,y1,z1);
    GetPlayerPos(playerid2,x2,y2,z2);
    dis = floatsqroot(floatpower(floatabs(floatsub(x2,x1)),2)+floatpower(floatabs(floatsub(y2,y1)),2)+floatpower(floatabs(floatsub(z2,z1)),2));
    return floatround(dis);
}

stock HexToInt(string[])
{
    if(!string[0]) return 0;
    new cur = 1, res = 0;
    for(new i = strlen(string); i > 0; i--)
    {
        res += cur * (string[i - 1] - ((string[i - 1] < 58) ? (48) : (55)));
        cur = cur * 16;
    }
    return res;
}

stock IsNumeric(const string[])
{
    for (new i = 0, j = strlen(string); i < j; i++)
    {
        if(string[i] > '9' || string[i] < '0') return 0;
    }
    return 1;
}

stock IsValidUsername(name[])
{
	new i, len = strlen(name);

	if(len < 3) return 0;

	while(i < len)
	{
		switch(name[i])
		{
			case 'a'..'z', 'A'..'Z', '0'..'9', '.', '_':
				i++;
			default:
				return 0;
		}
	}
	return 1;
}

stock IsValidMessageHouse(name[])
{
	new i, len = strlen(name);

	if(len < 3) return 0;

	while(i < len)
	{
		switch(name[i])
		{
			case 'a'..'z', 'A'..'Z', '0'..'9', '.', '_', ' ', '{', '}', '?', '!':
				i++;
			default:
				return 0;
		}
	}
	return 1;
}

stock IsMoney(integer, delimiter[] = ",")
{
    new str[16];

    format(str, sizeof str, "%i", integer);

    for (new i = strlen(str) - 3, j = ((integer < 0) ? 1 : 0); i > j; i -= 3)
    {
        strins(str, delimiter, i, sizeof str);
    }
    return str;
}

stock GetPlayerID(playername[])
{
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(!strcmp(playername, PlayerInfo[i][Nome], true) && PlayerInfo[i][Logado])
        {
            return i;
        }
    }
    return INVALID_PLAYER_ID;
}

stock TextConverter(string[])
{
    for(new arraysize = 0; arraysize < strlen(string); arraysize++)
    {
        if(strfind(string, "â", true) != -1){new pos = strfind(string, "â", true); strdel(string, pos, pos+strlen("â")); strins(string, "™", pos, sizeof(pos));}
        if(strfind(string, "ã", true) != -1){new pos = strfind(string, "ã", true); strdel(string, pos, pos+strlen("ã")); strins(string, "š", pos, sizeof(pos));}
        if(strfind(string, "á", true) != -1){new pos = strfind(string, "á", true); strdel(string, pos, pos+strlen("á")); strins(string, "˜", pos, sizeof(pos));}
        if(strfind(string, "é", true) != -1){new pos = strfind(string, "é", true); strdel(string, pos, pos+strlen("é")); strins(string, "ž", pos, sizeof(pos));}
        if(strfind(string, "ú", true) != -1){new pos = strfind(string, "ú", true); strdel(string, pos, pos+strlen("ú")); strins(string, "“", pos, sizeof(pos));}
        if(strfind(string, "ó", true) != -1){new pos = strfind(string, "ó", true); strdel(string, pos, pos+strlen("ó")); strins(string, "¦", pos, sizeof(pos));}
        if(strfind(string, "ê", true) != -1){new pos = strfind(string, "ê", true); strdel(string, pos, pos+strlen("ê")); strins(string, "Ÿ", pos, sizeof(pos));}
        if(strfind(string, "í", true) != -1){new pos = strfind(string, "í", true); strdel(string, pos, pos+strlen("í")); strins(string, "¢", pos, sizeof(pos));}
        if(strfind(string, "ç", true) != -1){new pos = strfind(string, "ç", true); strdel(string, pos, pos+strlen("ç")); strins(string, "œ", pos, sizeof(pos));}
        if(strfind(string, "ô", true) != -1){new pos = strfind(string, "ô", true); strdel(string, pos, pos+strlen("ô")); strins(string, "§", pos, sizeof(pos));}
    }
    return 1;
}

stock TextConverterDiscord(string[])
{
    for(new arraysize = 0; arraysize < strlen(string); arraysize++)
    {
        if(strfind(string, "â", true) != -1){new pos = strfind(string, "â", true); strdel(string, pos, pos+strlen("â")); strins(string, "a", pos, sizeof(pos));}
        if(strfind(string, "ã", true) != -1){new pos = strfind(string, "ã", true); strdel(string, pos, pos+strlen("ã")); strins(string, "a", pos, sizeof(pos));}
        if(strfind(string, "á", true) != -1){new pos = strfind(string, "á", true); strdel(string, pos, pos+strlen("á")); strins(string, "a", pos, sizeof(pos));}
        if(strfind(string, "é", true) != -1){new pos = strfind(string, "é", true); strdel(string, pos, pos+strlen("é")); strins(string, "e", pos, sizeof(pos));}
        if(strfind(string, "ú", true) != -1){new pos = strfind(string, "ú", true); strdel(string, pos, pos+strlen("ú")); strins(string, "u", pos, sizeof(pos));}
        if(strfind(string, "ó", true) != -1){new pos = strfind(string, "ó", true); strdel(string, pos, pos+strlen("ó")); strins(string, "o", pos, sizeof(pos));}
        if(strfind(string, "ê", true) != -1){new pos = strfind(string, "ê", true); strdel(string, pos, pos+strlen("ê")); strins(string, "e", pos, sizeof(pos));}
        if(strfind(string, "í", true) != -1){new pos = strfind(string, "í", true); strdel(string, pos, pos+strlen("í")); strins(string, "i", pos, sizeof(pos));}
        if(strfind(string, "ç", true) != -1){new pos = strfind(string, "ç", true); strdel(string, pos, pos+strlen("ç")); strins(string, "c", pos, sizeof(pos));}
        if(strfind(string, "ô", true) != -1){new pos = strfind(string, "ô", true); strdel(string, pos, pos+strlen("ô")); strins(string, "o", pos, sizeof(pos));}
        if(strfind(string, "õ", true) != -1){new pos = strfind(string, "õ", true); strdel(string, pos, pos+strlen("õ")); strins(string, "o", pos, sizeof(pos));}
    }
    return 1;
}

stock CreateRandomCode()
{
    new code[10], Coding[36][2] =
    {
        "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
        "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "X", "W", "Y", "Z"
    };

    code[0] = random(sizeof(Coding));
    code[1] = random(sizeof(Coding));
    code[2] = random(sizeof(Coding));
    code[3] = random(sizeof(Coding));
    code[4] = random(sizeof(Coding));
    code[5] = random(sizeof(Coding));
    code[6] = random(sizeof(Coding));
    code[7] = random(sizeof(Coding));
    code[8] = random(sizeof(Coding));
    code[9] = random(sizeof(Coding));

    format(String, sizeof(String), "%s%s%s%s%s%s%s%s%s%s", Coding[code[0]], Coding[code[1]], Coding[code[2]], Coding[code[3]], Coding[code[4]], Coding[code[5]], Coding[code[6]], Coding[code[7]], Coding[code[8]], Coding[code[9]]);

    new query[100];

    mysql_format(IDConexao, query, sizeof(query), "SELECT `Code` FROM `Contas` WHERE `Code`='%e'", String);
    mysql_query(IDConexao, query);

    if(cache_num_rows() != 0) return CreateRandomCode();

    return String;
}

stock IsValidCodingAccount(playerid, coding[])
{
    new query[100];
    mysql_format(IDConexao, query, sizeof(query), "SELECT `Code` FROM `Contas` WHERE `Code`='%e' AND `id`='%d'", coding, PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);

    if(cache_num_rows() != 0) return true;
    return false;
}

stock alfabeto [ 1 + ('z' - 'a') ] = { 'a', 'b', ...};
stock numeros [ 1 + ('9' - '0') ] = { '0', '1', ...};

stock GetRandomString(size = 0xff)
{
    static stringBuff[0xff];

    if(size < 0xff && size) {

        for(new i; i != size; i++) stringBuff[i] = bool: random(2) ? numeros [random(sizeof numeros )] : alfabeto [random(sizeof alfabeto )];

        stringBuff[size] = EOS;
    }
    return stringBuff;
}

stock SkinListName(skinid)
{
    new var[17];
    switch(skinid)
    {
        case 0: var = "Cj_(ID:0)";
        case 1: var = "Truth_(ID:1)";
        case 2: var = "Maccer_(ID:2)";
        case 3: var = "andre_(ID:3)";
        case 4: var = "Bbthin_(ID:4)";
        case 5: var = "Bb_(ID:5)";
        case 6: var = "Emmet_(ID:6)";
        case 7: var = "male01 (ID:7)";
        case 8: var = "janitor (ID:8)";
        case 9: var = "bfori (ID:9)";
        case 10: var = "bfost (ID:10)";
        case 11: var = "vbfycrp (ID:11)";
        case 12: var = "bfyri (ID:12)";
        case 13: var = "bfyst (ID:13)";
        case 14: var = "bmori (ID:14)";
        case 15: var = "bmost (ID:15)";
        case 16: var = "bmyap (ID:16)";
        case 17: var = "bmybu (ID:17)";
        case 18: var = "bmybe (ID:18)";
        case 19: var = "bmydj (ID:19)";
        case 20: var = "bmyri (ID:20)";
        case 21: var = "bmycr (ID:21)";
        case 22: var = "bmyst (ID:22)";
        case 23: var = "wmybmx (ID:23)";
        case 24: var = "wbdyg1 (ID:24)";
        case 25: var = "wbdyg2 (ID:25)";
        case 26: var = "wmybp (ID:26)";
        case 27: var = "wmycon (ID:27)";
        case 28: var = "bmydrug (ID:28)";
        case 29: var = "wmydrug (ID:29)";
        case 30: var = "hmydrug (ID:30)";
        case 31: var = "dwfolc (ID:31)";
        case 32: var = "dwmolc1 (ID:32)";
        case 33: var = "dwmolc2 (ID:33)";
        case 34: var = "dwmylc1 (ID:34)";
        case 35: var = "hmogar (ID:35)";
        case 36: var = "wmygol1 (ID:36)";
        case 37: var = "wmygol2 (ID:37)";
        case 38: var = "hfori (ID:38)";
        case 39: var = "hfost (ID:39)";
        case 40: var = "hfyri (ID:40)";
        case 41: var = "hfyst (ID:41)";
        case 42: var = "jethro (ID:42)";
        case 43: var = "hmori (ID:43)";
        case 44: var = "hmost (ID:44)";
        case 45: var = "hmybe (ID:45)";
        case 46: var = "hmyri (ID:46)";
        case 47: var = "hmycr (ID:47)";
        case 48: var = "hmyst (ID:48)";
        case 49: var = "omokung (ID:49)";
        case 50: var = "wmymech (ID:50)";
        case 51: var = "bmymoun (ID:51)";
        case 52: var = "wmymoun (ID:52)";
        case 53: var = "ofori (ID:53)";
        case 54: var = "ofost (ID:54)";
        case 55: var = "ofyri (ID:55)";
        case 56: var = "ofyst (ID:56)";
        case 57: var = "omori (ID:57)";
        case 58: var = "omost (ID:58)";
        case 59: var = "omyri (ID:59)";
        case 60: var = "omyst (ID:60)";
        case 61: var = "wmyplt (ID:61)";
        case 62: var = "wmopj (ID:62)";
        case 63: var = "bfypro (ID:63)";
        case 64: var = "hfypro (ID:64)";
        case 65: var = "kendl (ID:65)";
        case 66: var = "bmypol1 (ID:66)";
        case 67: var = "bmypol2 (ID:67)";
        case 68: var = "wmoprea (ID:68)";
        case 69: var = "sbfyst (ID:69)";
        case 70: var = "wmosci (ID:70)";
        case 71: var = "wmysgrd (ID:71)";
        case 72: var = "swmyhp1 (ID:72)";
        case 73: var = "swmyhp2 (ID:73)";
        case 74: var = "Sem Nome (ID:74)";
        case 75: var = "swfopro (ID:75)";
        case 76: var = "wfystew (ID:76)";
        case 77: var = "swmotr1 (ID:77)";
        case 78: var = "wmotr1 (ID:78)";
        case 79: var = "bmotr1 (ID:79)";
        case 80: var = "vbmybox (ID:80)";
        case 81: var = "vwmybox (ID:81)";
        case 82: var = "vhmyelv (ID:82)";
        case 83: var = "vbmyelv (ID:83)";
        case 84: var = "vimyelv (ID:84)";
        case 85: var = "vwfypro (ID:85)";
        case 86: var = "ryder3 (ID:86)";
        case 87: var = "vwfyst1 (ID:87)";
        case 88: var = "wfori (ID:88)";
        case 89: var = "wfost (ID:89)";
        case 90: var = "wfyjg (ID:90)";
        case 91: var = "wfyri (ID:91)";
        case 92: var = "wfyro (ID:92)";
        case 93: var = "wfyst (ID:93)";
        case 94: var = "wmori (ID:94)";
        case 95: var = "wmost (ID:95)";
        case 96: var = "wmyjg (ID:96)";
        case 97: var = "wmylg (ID:97)";
        case 98: var = "wmyri (ID:98)";
        case 99: var = "wmyro (ID:99)";
        case 100: var = "wmycr (ID:100)";
        case 101: var = "wmyst (ID:101)";
        case 102: var = "ballas1 (ID:102)";
        case 103: var = "ballas2 (ID:103)";
        case 104: var = "ballas3 (ID:104)";
        case 105: var = "fam1 (ID:105)";
        case 106: var = "fam2 (ID:106)";
        case 107: var = "fam3 (ID:107)";
        case 108: var = "lsv1 (ID:108)";
        case 109: var = "lsv2 (ID:109)";
        case 110: var = "lsv3 (ID:110)";
        case 111: var = "maffa (ID:111)";
        case 112: var = "maffb (ID:112)";
        case 113: var = "mafboss (ID:113)";
        case 114: var = "vla1 (ID:114)";
        case 115: var = "vla2 (ID:115)";
        case 116: var = "vla3 (ID:116)";
        case 117: var = "triada (ID:117)";
        case 118: var = "triadb (ID:118)";
        case 119: var = "sindaco (ID:119)";
        case 120: var = "triboss (ID:120)";
        case 121: var = "dnb1 (ID:121)";
        case 122: var = "dnb2 (ID:122)";
        case 123: var = "dnb3 (ID:123)";
        case 124: var = "vmaff1 (ID:124)";
        case 125: var = "vmaff2 (ID:125)";
        case 126: var = "vmaff3 (ID:126)";
        case 127: var = "vmaff4 (ID:127)";
        case 128: var = "dnmylc (ID:128)";
        case 129: var = "dnfolc1 (ID:129)";
        case 130: var = "dnfolc2 (ID:130)";
        case 131: var = "dnfylc (ID:131)";
        case 132: var = "dnmolc1 (ID:132)";
        case 133: var = "dnmolc2 (ID:133)";
        case 134: var = "sbmotr2 (ID:134)";
        case 135: var = "swmotr2 (ID:135)";
        case 136: var = "sbmytr3 (ID:136)";
        case 137: var = "swmotr3 (ID:137)";
        case 138: var = "wfybe (ID:138)";
        case 139: var = "bfybe (ID:139)";
        case 140: var = "hfybe (ID:140)";
        case 141: var = "sofybu (ID:141)";
        case 142: var = "sbmyst (ID:142)";
        case 143: var = "sbmycr (ID:143)";
        case 144: var = "bmycg (ID:144)";
        case 145: var = "wfycrk (ID:145)";
        case 146: var = "hmycm (ID:146)";
        case 147: var = "wmybu (ID:147)";
        case 148: var = "bfybu (ID:148)";
        case 149: var = "smokev (ID:149)";
        case 150: var = "wfybu (ID:150)";
        case 151: var = "dwfylc1 (ID:151)";
        case 152: var = "wfypro (ID:152)";
        case 153: var = "wmyconb (ID:153)";
        case 154: var = "wmybe (ID:154)";
        case 155: var = "wmypizz (ID:155)";
        case 156: var = "bmobar (ID:156)";
        case 157: var = "cwfyhb (ID:157)";
        case 158: var = "cwmofr (ID:158)";
        case 159: var = "cwmohb1 (ID:159)";
        case 160: var = "cwmohb2 (ID:160)";
        case 161: var = "cwmyfr (ID:161)";
        case 162: var = "cwmyhb1 (ID:162)";
        case 163: var = "bmyboun (ID:163)";
        case 164: var = "wmyboun (ID:164)";
        case 165: var = "wmomib (ID:165)";
        case 166: var = "bmymib (ID:166)";
        case 167: var = "wmybell (ID:167)";
        case 168: var = "bmochil (ID:168)";
        case 169: var = "sofyri (ID:169)";
        case 170: var = "somyst (ID:170)";
        case 171: var = "vwmybjd (ID:171)";
        case 172: var = "vwfycrp (ID:172)";
        case 173: var = "sfr1 (ID:173)";
        case 174: var = "sfr2 (ID:174)";
        case 175: var = "sfr3 (ID:175)";
        case 176: var = "bmybar (ID:176)";
        case 177: var = "wmybar (ID:177)";
        case 178: var = "wfysex (ID:178)";
        case 179: var = "wmyammo (ID:179)";
        case 180: var = "bmytatt (ID:180)";
        case 181: var = "vwmycr (ID:181)";
        case 182: var = "vbmocd (ID:182)";
        case 183: var = "vbmycr (ID:183)";
        case 184: var = "vhmycr (ID:184)";
        case 185: var = "sbmyri (ID:185)";
        case 186: var = "somyri (ID:186)";
        case 187: var = "somybu (ID:187)";
        case 188: var = "swmyst (ID:188)";
        case 189: var = "wmyva (ID:189)";
        case 190: var = "copgrl3 (ID:190)";
        case 191: var = "gungrl3 (ID:191)";
        case 192: var = "mecgrl3 (ID:192)";
        case 193: var = "nurgrl3 (ID:193)";
        case 194: var = "crogrl3 (ID:194)";
        case 195: var = "gangrl3 (ID:195)";
        case 196: var = "cwfofr (ID:196)";
        case 197: var = "cwfohb (ID:197)";
        case 198: var = "cwfyfr1 (ID:198)";
        case 199: var = "cwfyfr2 (ID:199)";
        case 200: var = "cwmyhb2 (ID:200)";
        case 201: var = "dwfylc2 (ID:201)";
        case 202: var = "dwmylc2 (ID:202)";
        case 203: var = "omykara (ID:203)";
        case 204: var = "wmykara (ID:204)";
        case 205: var = "wfyburg (ID:205)";
        case 206: var = "vwmycd (ID:206)";
        case 207: var = "vhfypro (ID:207)";
        case 208: var = "suzie (ID:208)";
        case 209: var = "omonood (ID:209)";
        case 210: var = "omoboat (ID:210)";
        case 211: var = "wfyclot (ID:211)";
        case 212: var = "vwmotr1 (ID:212)";
        case 213: var = "vwmotr2 (ID:213)";
        case 214: var = "vwfywai (ID:214)";
        case 215: var = "sbfori (ID:215)";
        case 216: var = "swfyri (ID:216)";
        case 217: var = "wmyclot (ID:217)";
        case 218: var = "sbfost (ID:218)";
        case 219: var = "sbfyri (ID:219)";
        case 220: var = "sbmocd (ID:220)";
        case 221: var = "sbmori (ID:221)";
        case 222: var = "sbmost (ID:222)";
        case 223: var = "shmycr (ID:223)";
        case 224: var = "sofori (ID:224)";
        case 225: var = "sofost (ID:225)";
        case 226: var = "sofyst (ID:226)";
        case 227: var = "somobu (ID:227)";
        case 228: var = "somori (ID:228)";
        case 229: var = "somost (ID:229)";
        case 230: var = "swmotr5 (ID:230)";
        case 231: var = "swfori (ID:231)";
        case 232: var = "swfost (ID:232)";
        case 233: var = "swfyst (ID:233)";
        case 234: var = "swmocd (ID:234)";
        case 235: var = "swmori (ID:235)";
        case 236: var = "swmost (ID:236)";
        case 237: var = "shfypro (ID:237)";
        case 238: var = "sbfypro (ID:238)";
        case 239: var = "swmotr4 (ID:239)";
        case 240: var = "swmyri (ID:240)";
        case 241: var = "smyst (ID:241)";
        case 242: var = "smyst2 (ID:242)";
        case 243: var = "sfypro (ID:243)";
        case 244: var = "vbfyst2 (ID:244)";
        case 245: var = "vbfypro (ID:245)";
        case 246: var = "vhfyst3 (ID:246)";
        case 247: var = "bikera (ID:247)";
        case 248: var = "bikerb (ID:248)";
        case 249: var = "bmypimp (ID:249)";
        case 250: var = "swmycr (ID:250)";
        case 251: var = "wfylg (ID:251)";
        case 252: var = "wmyva2 (ID:252)";
        case 253: var = "bmosec (ID:253)";
        case 254: var = "bikdrug (ID:254)";
        case 255: var = "wmych (ID:255)";
        case 256: var = "sbfystr (ID:256)";
        case 257: var = "swfystr (ID:257)";
        case 258: var = "heck1 (ID:258)";
        case 259: var = "heck2 (ID:259)";
        case 260: var = "bmycon (ID:260)";
        case 261: var = "wmycd1 (ID:261)";
        case 262: var = "bmocd (ID:262)";
        case 263: var = "vwfywa2 (ID:263)";
        case 264: var = "wmoice (ID:264)";
        case 265: var = "tenpen (ID:265)";
        case 266: var = "pulaski (ID:266)";
        case 267: var = "hern (ID:267)";
        case 268: var = "dwayne (ID:268)";
        case 269: var = "smoke (ID:269)";
        case 270: var = "sweet (ID:270)";
        case 271: var = "ryder (ID:271)";
        case 272: var = "forelli (ID:272)";
        case 273: var = "tbone (ID:273)";
        case 274: var = "laemt1 (ID:274)";
        case 275: var = "lvemt1 (ID:275)";
        case 276: var = "sfemt1 (ID:276)";
        case 277: var = "lafd1 (ID:277)";
        case 278: var = "lvfd1 (ID:278)";
        case 279: var = "sffd1 (ID:279)";
        case 280: var = "lapd1 (ID:280)";
        case 281: var = "sfpd1 (ID:281)";
        case 282: var = "lvpd1 (ID:282)";
        case 283: var = "csher (ID:283)";
        case 284: var = "lapdm1 (ID:284)";
        case 285: var = "swat (ID:285)";
        case 286: var = "fbi (ID:286)";
        case 287: var = "army (ID:287)";
        case 288: var = "dsher (ID:288)";
        case 289: var = "zero (ID:289)";
        case 290: var = "rose (ID:290)";
        case 291: var = "paul (ID:291)";
        case 292: var = "cesar (ID:292)";
        case 293: var = "ogloc (ID:293)";
        case 294: var = "wuzimu (ID:294)";
        case 295: var = "torino (ID:295)";
        case 296: var = "jizzy (ID:296)";
        case 297: var = "maddogg (ID:297)";
        case 298: var = "cat (ID:298)";
        case 299: var = "claude (ID:299)";
        case 300: var = "lapdna (ID:300)";
        case 301: var = "sfpdna (ID:301)";
        case 302: var = "lvpdna (ID:302)";
        case 303: var = "lapdpc (ID:303)";
        case 304: var = "lapdpd (ID:304)";
        case 305: var = "lvpdpc (ID:305)";
        case 306: var = "wfyclpd (ID:306)";
        case 307: var = "vbfycpd (ID:307)";
        case 308: var = "wfyclem (ID:308)";
        case 309: var = "wfycllv (ID:309)";
        case 310: var = "csherna (ID:310)";
        case 311: var = "dsherna (ID:311)";
    }
    return var;
}

stock GetPlayerIDAccount(name[])
{
    new id_account, query[100];

    mysql_format(IDConexao, query, 100, "SELECT `id` FROM `Contas` WHERE `Nome`='%e' LIMIT 1", name);
    new Cache:result = mysql_query(IDConexao, query);

    switch(cache_num_rows())
    {
        case 0: id_account = INVALID_PLAYER_ID;
        case 1: cache_get_value_int(0, "id", id_account);
    }

    cache_delete(result);
    return id_account;
}

stock UpdatePlayerHealth(playerid)
{
    if(PlayerInfo[playerid][Health] > 100.0)
    {
        PlayerInfo[playerid][Health] = 100.0;
        SetPlayerHealth(playerid, PlayerInfo[playerid][Health]);
    }
    else if(PlayerInfo[playerid][Health] < 0.0)
    {
        PlayerInfo[playerid][Health] = 0.0;
        SetPlayerHealth(playerid, PlayerInfo[playerid][Health]);
    }
    else SetPlayerHealth(playerid, PlayerInfo[playerid][Health]);
    return 1;
}

stock UpdatePlayerStar(playerid)
{
    SetIntQuery(playerid, "Identidade", "estrelas", PlayerInfo[playerid][Estrelas]);

    format(String, MAX_STRING, "%d", PlayerInfo[playerid][Estrelas]);
    PlayerTextDrawSetString(playerid, PlayerBarStatus[playerid][1], String);

    if(statePlayer[playerid]) PlayerTextDrawShow(playerid, PlayerBarStatus[playerid][1]);

    return 1;
}

stock UpdatePlayerProfission(playerid)
{
    new query[150];
    mysql_format(IDConexao, query, sizeof(query), "UPDATE `Identidade` SET `profissao`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][Profissao], PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);
    return 1;
}

stock UpdatePlayerMoney(playerid)
{
    new _str[100];
    mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Identidade` SET `dinheiro`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][Dinheiro], PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, _str);
    ResetPlayerMoney(playerid);
    GivePlayerMoney(playerid, PlayerInfo[playerid][Dinheiro]);
    return 1;
}

stock UpdatePlayerReais(playerid)
{
    new _str[100];
    mysql_format(IDConexao, _str, sizeof(_str), "UPDATE `Identidade` SET `reais`='%d' WHERE `id_contas`='%d'", PlayerInfo[playerid][Reais], PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, _str);
    return 1;
}

stock UpdatePlayerLevel(playerid)
{
    new query[500];

    mysql_format(IDConexao, query, sizeof(query), "UPDATE `Identidade` SET `level`='%d', `experiencia`='%d', `minup`='%d', `segup`='%d' WHERE `id_contas`='%d'",
    PlayerInfo[playerid][Level],
    PlayerInfo[playerid][Exp],
    PlayerInfo[playerid][minUP],
    PlayerInfo[playerid][segUP],
    PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);
    return 1;
}

stock AccountIsLoggedIn(playerid)
{
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerConnected(i) && PlayerInfo[i][Logado])
        {
            if(!strcmp(PlayerInfo[i][Nome], pPlayerInfo[playerid][pNome])) return 1;
        }
    }
    return 0;
}

stock returnPorcentage(Float:x, Float:max)
{
    return floatround(((x*100)/max), floatround_floor);
}

stock GetIntQuery(playerid, table[], column[])
{
    new result, query[100];

    mysql_format(IDConexao, query, 100, "SELECT `%s` FROM `%s` WHERE `id_contas`='%d'", column, table, PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, query);

    if(cache_num_rows() == 0) return 0;

    cache_get_value_int(0, 0, result);

    return result;
}

stock SetIntQuery(playerid, table[], column[], value)
{
    new Cache:result, query[200];

    mysql_format(IDConexao, query, 200, "UPDATE `%s` SET `%s`='%d' WHERE `id_contas`='%d'", table, column, value, PlayerInfo[playerid][ID]);
    result = mysql_query(IDConexao, query);

    return cache_delete(result);
}
