    if(strcmp(cmd, "/cp", true)==0)
	{
        new tmp[128];

        strmid(tmp, cmdtext, 3, strlen(cmdtext));

        if(PlayerInfo[playerid][Profissao] == Desempregado) return OnPlayerCommandText(playerid,"/Comandos");

    	if(!strlen(tmp)) return SendClientMessage(playerid, Erro, "| ERRO | Digite: /Cp [texto]");

        for (new i; i < MAX_PLAYERS; i++)
        {
            if(PlayerInfo[i][Profissao] == PlayerInfo[playerid][Profissao])
            {
                format(String, sizeof(String), "| Chat-Profissão | %s [%d] diz: %s", PlayerInfo[playerid][Nome], playerid, tmp);
                SendClientMessage(i, GetPlayerColor(playerid), String);
            }
        }
        return 1;
	}
    if(strcmp(cmd, "/hq", true)==0)
	{
        switch(PlayerInfo[playerid][Profissao])
        {
            case EntregadorJornal:
                SetPlayerCheckpoint(playerid, 785.2020,-1327.7697,13.5469, 1.0);
            case Taxi:
                SetPlayerCheckpoint(playerid, 2229.5803,-1368.1969,23.9922, 1.0);
            case PoliciaMunicipal:
                SetPlayerCheckpoint(playerid, 1579.5728,-1635.3932,13.5611, 1.0);
            case LadraoGas:
                SetPlayerCheckpoint(playerid, -453.7872,2230.1296,42.4993, 1.0);
        }
     	return 1;
	}
