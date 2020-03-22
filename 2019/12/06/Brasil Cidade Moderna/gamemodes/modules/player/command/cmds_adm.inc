    //NIVEL I
    if(strcmp(cmd, "/avls", true)==0)
    {
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        SetPlayerPos(playerid,1022.4510,-1121.5958,23.8719);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para Área Vip de Los Santos!");
    }
    if(strcmp(cmd, "/avlv", true)==0)
    {
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        SetPlayerPos(playerid,2015.0763,1106.6337,10.8203);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para Área Vip de Las Venturas!");
    }
    if(strcmp(cmd, "/avsf", true)==0)
    {
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

    	SetPlayerPos(playerid,-2664.4136,-7.4449,6.1328);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para Área Vip de San Fierro!");
        return 1;
    }
    if(strcmp(cmd, "/apls", true)==0)
	{
	    if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        SetPlayerPos(playerid,1962.2162,-2178.3967,13.5469);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para o Aeroporto de Los Santos!");
        return 1;
    }
    if(strcmp(cmd, "/aplv", true)==0)
	{
	    if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        SetPlayerPos(playerid, 1712.0634, 1606.1857, 10.0156);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para o Aeroporto de Las Venturas!");
        return 1;
    }
    if(strcmp(cmd, "/apsf", true)==0)
	{
		if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

	    SetPlayerPos(playerid,-1740.7712,-579.3079,16.3359);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para o Aeroporto de San Fierro!");
        return 1;
    }
    if(strcmp(cmd, "/apab", true)==0)
	{
		if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        SetPlayerPos(playerid,431.5682,2506.1760,16.4844);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para o Aeroporto Abandonado!");
        return 1;
    }
    if(strcmp(cmd, "/agls", true)==0)
	{
		if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        SetPlayerPos(playerid,1154.0808,-1771.9812,16.5992);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para Agencia de Los Santos!");
        return 1;
    }
    if(strcmp(cmd, "/aglv", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        SetPlayerPos(playerid,937.8450,1733.1957,8.8516);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para Agencia de Las Venturas!");
        return 1;
    }
    if(strcmp(cmd, "/agsf", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        SetPlayerPos(playerid,-2171.8110,252.0813,35.3378);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para Agencia de San Fierro!");
        return 1;
    }
    if(strcmp(cmd, "/pfls", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        SetPlayerPos(playerid,1481.0637,-1770.9515,18.7958);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para Prefeitura de Los Santos!");
        return 1;
    }
    if(strcmp(cmd, "/pflv", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        SetPlayerPos(playerid,2447.0620,2376.2354,12.1635);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para Prefeitura de Las Venturas!");
        return 1;
    }
    if(strcmp(cmd, "/pfsf", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

	    SetPlayerPos(playerid,-2765.8796,375.5812,6.3347);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para Prefeitura de San Fierro!");
        return 1;
    }
    if(strcmp(cmd, "/dpls", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

	    SetPlayerPos(playerid,1554.8657,-1675.6693,16.1953);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para o Departamento de Polícia de Los Santos!");
        return 1;
    }
    if(strcmp(cmd, "/dplv", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

	    SetPlayerPos(playerid,2290.1218,2430.9775,10.8203);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para o Departamento de Polícia de Las Venturas!");
        return 1;
    }
    if(strcmp(cmd, "/dpsf", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

	    SetPlayerPos(playerid,-1605.5848,710.8436,13.8672);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para o Departamento de Polícia de San Fierro!");
        return 1;
    }
    if(strcmp(cmd, "/dpdm", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

	    SetPlayerPos(playerid,627.7621,-571.7207,17.5526);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para o Departamento de Polícia de Dillimore!");
        return 1;
    }
    if(strcmp(cmd, "/hpls", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

	    SetPlayerPos(playerid,1172.6787,-1323.3129,15.4022);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para o Hospital de Los Santos!");
        return 1;
    }
    if(strcmp(cmd, "/hplv", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

	    SetPlayerPos(playerid,1607.3579,1815.6309,10.8203);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para o Hospital de Las Venturas!");
        return 1;
    }
    if(strcmp(cmd, "/hpsf", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

	    SetPlayerPos(playerid,-2655.0662,639.1497,14.4531);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para o Hospital de San Fierro!");
        return 1;
    }
    if(strcmp(cmd, "/hpeq", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

	    SetPlayerPos(playerid,-1514.8217,2520.3232,55.9185);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para o Hospital de El Quebrados!");
        return 1;
    }
    if(strcmp(cmd, "/hpmg", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

	    SetPlayerPos(playerid,1241.8073,327.1022,19.7555);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para o Hospital de Montgomery!");
        return 1;
    }
    if(strcmp(cmd, "/hpfc", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

	    SetPlayerPos(playerid,-320.0716,1049.2637,20.3403);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para o Hospital de Fort Carson!");
        return 1;
    }
    if(strcmp(cmd, "/bcls", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

	    SetPlayerPos(playerid,1778.3052,-1663.5337,14.4362);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para o Banco de Los Santos!");
        return 1;
    }
    if(strcmp(cmd, "/bclv", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

	    SetPlayerPos(playerid,2388.6733,2466.0430,10.8203);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para o Banco de Las Venturas!");
        return 1;
    }
    if(strcmp(cmd, "/bcsf", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

	    SetPlayerPos(playerid,-2649.8374,376.0090,6.1563);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para o Banco de San Fierro!");
        return 1;
    }
    if(strcmp(cmd, "/bcfc", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

	    SetPlayerPos(playerid,-180.3883,1133.1510,19.7422);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para o Banco de Fort Carson!");
        return 1;
    }
    if(strcmp(cmd, "/bcmg", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

	    SetPlayerPos(playerid,1372.9271,405.2487,19.9555);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para o Banco de Montgomery!");
        return 1;
    }
    if(strcmp(cmd, "/bcpc", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

	    SetPlayerPos(playerid,2302.9521,-16.2789,26.4844);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para o Banco de Palomino Creek!");
        return 1;
    }
    if(strcmp(cmd, "/bclb", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

	    SetPlayerPos(playerid,-828.0650,1503.6166,19.7585);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para o Banco de Las Barrancas!");
        return 1;
    }
    if(strcmp(cmd, "/bceq", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

	    SetPlayerPos(playerid,-1480.8273,2592.3015,55.8359);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para o Banco de El Quebrados!");
        return 1;
    }
    if(strcmp(cmd, "/bcbb", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

	    SetPlayerPos(playerid,207.7767,-62.5814,1.6498);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para o Banco de BlueBerry!");
        return 1;
    }
    if(strcmp(cmd, "/ibls", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

	    SetPlayerPos(playerid,1798.4763,-1578.3191,14.0849);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para Imobiliaria de Los Santos!");
        return 1;
    }
    if(strcmp(cmd, "/iblv", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

	    SetPlayerPos(playerid,2413.2390,1123.8374,10.8203);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para Imobiliaria de Las Venturas!");
        return 1;
    }
    if(strcmp(cmd, "/ibsf", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

	    SetPlayerPos(playerid,-1881.1293,822.7573,35.1773);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para Imobiliaria de San Fierro!");
        return 1;
    }
    if(strcmp(cmd, "/aels", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

	    SetPlayerPos(playerid,1519.0413,-1453.5895,14.2073);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para o Auto Escola de Los Santos!");
        return 1;
    }
    if(strcmp(cmd, "/aelv", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

	    SetPlayerPos(playerid,2183.2483,2295.2205,10.8203);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para o Auto Escola de Las Venturas!");
        return 1;
    }
    if(strcmp(cmd, "/aesf", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

	    SetPlayerPos(playerid,-2026.5950,-101.3410,35.1641);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para Auto Escola de San Fierro!");
        return 1;
    }
    if(strcmp(cmd, "/dtls", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

	    SetPlayerPos(playerid,1310.1411,-1367.8086,13.5408);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para o Detran de Los Santos!");
        return 1;
    }
    if(strcmp(cmd, "/dtlv", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

	    SetPlayerPos(playerid,1173.1600,1349.0011,10.9219);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para o Detran de Las Venturas!");
        return 1;
    }
    if(strcmp(cmd, "/dtsf", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

	    SetPlayerPos(playerid,-2720.6375,127.7373,7.0391);
        SendClientMessage(playerid, adm, "| BCM-Admin | Você se teletransportou para o Detran de San Fierro!");
        return 1;
    }
    if(strcmp(cmd, "/tps", true)==0)
    {
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new textos[1000];
        strcat(textos, "{FF0000}•{FFFFFF} /avls - avlv - avsf : Áreas VIP's \n");
        strcat(textos, "{FF0000}•{FFFFFF} /apls - aplv - apsf - /apab : Aeroportos \n");
        strcat(textos, "{FF0000}•{FFFFFF} /agls - aglv - agsf : Agencia de Empregos \n");
        strcat(textos, "{FF0000}•{FFFFFF} /pfls - pflv - pfsf : Prefeitura \n");
        strcat(textos, "{FF0000}•{FFFFFF} /dpls - dplv - dpsf - dpfm : Departamento de Polícia \n");
        strcat(textos, "{FF0000}•{FFFFFF} /hpls - hplv - hpsf : Hospital \n");
        strcat(textos, "{FF0000}•{FFFFFF} /hpeq - hpmg - hpfc : Hospital \n");
        strcat(textos, "{FF0000}•{FFFFFF} /bcls - bclv - bcsf : Banco \n");
        strcat(textos, "{FF0000}•{FFFFFF} /bcfc - bcmg - bcpc : Banco \n");
        strcat(textos, "{FF0000}•{FFFFFF} /bclb - bceq - bcbb : Banco \n");
        strcat(textos, "{FF0000}•{FFFFFF} /ibls - iblv - ibsf : Imobilíaria \n");
        strcat(textos, "{FF0000}•{FFFFFF} /aels - aelv - aesf : Auto Escola \n");
        strcat(textos, "{FF0000}•{FFFFFF} /dtls - dtlv - dtsf : Detran \n");
        ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Teletransportes", textos, "Fechar", "");
        return 1;
    }
    if(strcmp(cmd, "/comandosadm", true)==0)
    {
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new txt[2800];
        strcat(txt, "{FF0000}Comandos \t\t{1CEB00}Informações\n");
        strcat(txt, "{87CEFF}/Desalgemar [id] \t\t{FFFFFF}Para desalgemar um(a) jogador(a)\n");
        strcat(txt, "{87CEFF}/Lc \t\t{FFFFFF}Para limpar o chat para todos jogador(a)\n");
        strcat(txt, "{87CEFF}/CorNome \t\t{FFFFFF}Para alterar a cor do nome\n");
        strcat(txt, "{87CEFF}/RespawnVeiculos \t\t{FFFFFF}Para Respawnar todos os veiculos não em uso\n");
        strcat(txt, "{87CEFF}/Desprocurar [id] \t\t{FFFFFF}Para desprocurar um(a) jogador(a)\n");
        strcat(txt, "{87CEFF}/Camuflar [id] \t\t{FFFFFF}Para camufle-se no mini-map\n");
        strcat(txt, "{87CEFF}/PararCamuflar [id]  \t\t{FFFFFF}Para parar de se camuflar no mini-map\n");
        strcat(txt, "{87CEFF}/Espiar [id] \t\t{FFFFFF}Para espiar um(a) jogador(a)\n");
        strcat(txt, "{87CEFF}/PararEspiar [id] \t\t{FFFFFF}Para parar de espiar o(a) jogador(a)\n");
        strcat(txt, "{87CEFF}/Avisar [id] \t\t{FFFFFF}Para avisar um(a) jogador(a)\n");
        strcat(txt, "{87CEFF}/Ejetar [id] \t\t{FFFFFF}Para ejetar um(a) jogador(a) de um veículo\n");
        strcat(txt, "{87CEFF}/Injetar [id] \t\t{FFFFFF}Para colocar um(a) jogador(a) em um veículo\n");
        strcat(txt, "{87CEFF}/GodMod \t\t{FFFFFF}Para ficar com vida infinita\n");
        strcat(txt, "{87CEFF}/Kick [id] \t\t{FFFFFF}Para kickar um(a) jogador(a) \n");
        strcat(txt, "{87CEFF}/Tapa [id] \t\t{FFFFFF}Para dar um(a) tapa em um(a) jogador(a) \n");
        ShowPlayerDialog(playerid, cmds_adm_pg1, DIALOG_STYLE_TABLIST_HEADERS, "{C0C0C0}Comandos da Admininstração - Página {00CA00}1", txt, "Próxima", "Cancelar");
        return 1;
    }
    if(strcmp(cmd, "/d", true) == 0)
    {
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128], tmp1[128], id;

        tmp = strtok(cmdtext, idx);
        tmp1 = strrest(cmdtext, idx);

        if(!strlen(tmp) || !strlen(tmp1))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /D [id] [resposta]");

        id = strval(tmp);

        format(String, sizeof(String), "| Resposta | Você respondeu a duvida ou o relatório do jogador(a) %s[%d]", PlayerInfo[id][Nome], id);
        SendClientMessage(playerid, -1, String);
        format(String, sizeof(String), "| Resposta | %s %s respondeu : %s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], tmp1);
        SendClientMessage(id, adm, String);
    	return 1;
	}
    if(strcmp(cmd, "/desalgemar", true)==0)
    {
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new id, tmp[128];

        tmp = strtok(cmdtext, idx);

        if(!strlen(tmp))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /Desalgemar [id]");

        id = strval(tmp);

        if(PlayerInfo[id][Logado] == false)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não conectado(a)!");

        if(Algemado[id] == false)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não está algemado(a)!");

        Algemado[id]=false;
        RemovePlayerAttachedObject(id, 4);
        TogglePlayerControllable(id, true);
        SetPlayerSpecialAction(id, SPECIAL_ACTION_NONE);
        format(String, sizeof(String), "| BCM-Admin | O(A) %s %s desalgemo você", CargoAdmin(playerid), PlayerInfo[playerid][Nome]);
        SendClientMessage(id, adm, String);
        SendClientMessage(playerid, -1, "| BCM-Admin | Comando efetuado com sucesso!");
        return 1;
    }                                                          //NIVEL 1
    if(strcmp(cmd, "/lc", true)==0)
    {
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        for(new i=0; i < 50; i++)
        {
            SendClientMessageToAll(-1, "");
        }
        return 1;
    }
    if(strcmp(cmd, "/cornome", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        ShowPlayerDialog(playerid, colorname, DIALOG_STYLE_INPUT, "{FF0000}Cor nick", "{FFFFFF}Digite um codigo em '{FF0000}HTML{FFFFFF}' abaixo\nPesquise no Google algo como {00FF00}Cores em HTML {FFFFFF}:\n{FF0000}Exemplo {FFFFFF}00FF00 = {00FF00}Calenzo", "Alterar", "Cancelar");
        return 1;
    }
    if(strcmp(cmd, "/desprocurar", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new id, tmp[128];

        tmp = strtok(cmdtext, idx);

        if(!strlen(tmp))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /Desprocurar [id]");

        id = strval(tmp);

        if(PlayerInfo[id][Logado] == false)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não conectado(a)!");

        if(PlayerInfo[id][Estrelas] == 0)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não está procurado(a)!");

        PlayerInfo[id][Estrelas]=0;
        format(String, sizeof(String), "%d", PlayerInfo[id][Estrelas]);
        PlayerTextDrawSetString(id, PlayerBarStatus[id][1], String);
        PlayerTextDrawShow(id, PlayerBarStatus[id][1]);
        format(String, sizeof(String), "| BCM-Admin | O(A) %s %s removeu todas as suas estrelas", CargoAdmin(id), PlayerInfo[playerid][Nome]);
        SendClientMessage(id, adm, String);
        format(String, sizeof(String), "| BCM-Admin | Você removeu todas as estrelas do jogador(a) %s[%d]", PlayerInfo[id][Nome], id);
        SendClientMessage(playerid, adm, String);
        return 1;
    }
    if(strcmp(cmd, "/camuflar", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        SendClientMessage(playerid, -1, "| BCM-Admin | Comando efetuado com sucesso!!");

        for(new i; i != MAX_PLAYERS; i++)
            return SetPlayerMarkerForPlayer(i, playerid, 0xFFFFFF00);
        return 1;
    }
    if(strcmp(cmd, "/pararcamuflar", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        SendClientMessage(playerid, -1, "| BCM-Admin | Comando efetuado com sucesso!!");

        for(new i; i <= MAX_PLAYERS; i++)
            return SetPlayerMarkerForPlayer(i, playerid, GetPlayerColor(playerid));
        return 1;
    }
    if(strcmp(cmd, "/respawnveiculos", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        if(Respawnando == true)
            return SendClientMessage(playerid, Erro, "| ERRO | Veiculos não em uso já está sendo respawnados!");

        Respawnando=true;
        TextDrawSetString(RespawnVeiculos, "~r~>> ~w~Respawn de veiculos nao em uso em ~g~30 ~w~segundos... ~r~<<");
        TextDrawShowForAll(RespawnVeiculos);
        SetTimer("Respawn1", 3000, false);
        return 1;
    }
    if(strcmp(cmd, "/avisar", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128], tmp1[128], id;

        tmp = strtok(cmdtext, idx);
        tmp1 = strrest(cmdtext, idx);

        if(!strlen(tmp) || !strlen(tmp1))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /Avisar [id] [Motivo do Aviso]");

        id = strval(tmp);

        if(PlayerInfo[id][Logado] == false)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não conectado(a)!");

        if(playerid == id)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não pode efetuar comando em sí mesmo!");

        if(PrisonEnum[id][pTempo] != 0)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) jogador(a) está preso!");

        PlayerInfo[id][Avisos]++;
        format(String, sizeof(String), "| BCM-Admin | O(A) %s %s avisou o(a) jogador(a) %s ( %d/3 )( Motivo: %s )", CargoAdmin(playerid), PlayerInfo[playerid][Nome], PlayerInfo[id][Nome], PlayerInfo[id][Avisos], tmp1);
        SendClientMessageToAll(Vermelho, String);
        //MySQL Salvando Direto
        mysql_format(IDConexao, String, sizeof(String), "UPDATE Contas SET Aviso='%i' WHERE Nome='%e'", PlayerInfo[id][Avisos], PlayerInfo[id][Nome]);
        mysql_query(IDConexao, String);

        if(PlayerInfo[id][Avisos] == 3)
        {
            PlayerInfo[id][Avisos] = 0;
            PrisonEnum[id][pTempo] = 60*30;
            format(PrisonEnum[id][pCadeia], 7, "Federal");
            format(PrisonEnum[id][pMotivo], 24, tmp);
            format(PrisonEnum[id][pResponsavel], 24, PlayerInfo[playerid][Nome]);

            format(String, sizeof(String), "| BCM-Admin | Por receber 3 avisos o(a) jogador(a) %s foi preso por 30 minutos!", PlayerInfo[id][Nome]);
            SendClientMessageToAll(Vermelho, String);
            SendClientMessage(id, 0x2894FFAA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Preso ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            SendClientMessage(id, Branco, "» Você está preso!");
            format(String, sizeof(String), "» Foi preso por ( %s )", PlayerInfo[id][Nome]);
            SendClientMessage(id, Branco, String);
            format(String, sizeof(String), "» Motivo da prisão ( %s )", tmp);
            SendClientMessage(id, Branco, String);
            SendClientMessage(id, 0x2894FFAA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Preso ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

            //MySQL Salvando Direto
            mysql_format(IDConexao, String, sizeof(String), "UPDATE Contas SET Aviso='%i' WHERE Nome='%e'", PlayerInfo[id][Avisos], PlayerInfo[id][Nome]);
            mysql_query(IDConexao, String);

            mysql_format(IDConexao, String, sizeof(String), "INSERT INTO `Prisoes` (Nome, Responsavel, Cadeia, Motivo, Tempo) VALUES ('%e', '%e', '%e', '%e', '%d')", PlayerInfo[id][Nome], PrisonEnum[id][pResponsavel], PrisonEnum[id][pCadeia], PrisonEnum[id][pMotivo], PrisonEnum[id][pTempo]);
            mysql_query(IDConexao, String);

            mysql_format(IDConexao, String, sizeof(String), "SELECT * FROM `Prisoes` WHERE `Nome`='%e'", PlayerInfo[id][Nome]);
            mysql_tquery(IDConexao, String, "DBLoadPrisons", "i", id);
        }
        return 1;
    }
	if(strcmp(cmd, "/espiar", true) == 0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128], id;

        tmp = strtok(cmdtext, idx);

        if(!strlen(tmp))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /espiar [id]");

        id = strval(tmp);

        if(PlayerInfo[id][Logado] == false)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não conectado(a)!");

        if(playerid == id)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não pode efetuar comando em sí mesmo!");

        TogglePlayerSpectating(playerid, true);
        PlayerSpectatePlayer(playerid, id);
        SetPlayerInterior(playerid, GetPlayerInterior(id));
        SendClientMessage(playerid, -1, "| BCM-Admin | Comando efetuado com sucesso!");
        return 1;
	}
 	if(strcmp(cmd, "/pararespiar", true) == 0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        SetPlayerInterior(playerid, 0);
        TogglePlayerSpectating(playerid, false);
        SendClientMessage(playerid, -1, "| BCM-Admin | Comando efetuado com sucesso!");
        return 1;
	}
	if(strcmp(cmd, "/tapa", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128], id;

        tmp = strtok(cmdtext, idx);

        if(!strlen(tmp))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /Tapa [id]");

        id = strval(tmp);

        if(PlayerInfo[id][Logado] == false)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não conectado(a)!");

        if(playerid == id)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não pode efetuar comando em sí mesmo!");

        GetPlayerPos(id, X, Y, Z);
        SetPlayerPos(id, X, Y, Z+50);
        format(String, sizeof(String), "| BCM-Admin | O(A) %s %s te deu um tapa!", CargoAdmin(playerid), PlayerInfo[playerid][Nome]);
        SendClientMessage(id, adm, String);
        format(String, sizeof(String), "| BCM-Admin | Você deu um tapa no jogador(a) %s[%d]", PlayerInfo[id][Nome], id);
        SendClientMessage(playerid, adm, String);
        return 1;
	}
    if(strcmp(cmd, "/kick", true) == 0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128], tmp1[128], id;

        tmp = strtok(cmdtext, idx);
        tmp1 = strrest(cmdtext, idx);

        if(!strlen(tmp) || !strlen(tmp1))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /Kick [id] [Motivo do Kick]");

        id = strval(tmp);

        if(PlayerInfo[id][Logado] == false)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não conectado(a)!");

        if(playerid == id)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não pode efetuar comando em sí mesmo!");

        GameTextForPlayer(id,"~r~kickado~w~!", 2500, 3);
        format(String, sizeof(String), "| BCM-Admin | O(A) %s %s kickou o(a) jogador(a) %s ( Motivo: %s )", CargoAdmin(playerid), PlayerInfo[playerid][Nome], PlayerInfo[id][Nome], tmp1);
        SendClientMessageToAll(Vermelho, String);
        format(String, sizeof(String), "| BCM-Admin | Você kickou o(a) Jogador(a) %s[%d]", PlayerInfo[id][Nome], id);
        SendClientMessage(playerid, adm, String);
        Kick(id);
        return 1;
    }
    if(strcmp(cmd, "/enchervida", true)==0)
    {
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128], id;

        tmp = strtok(cmdtext, idx);

        if(!strlen(tmp))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /EncherVida [id]");

        id = strval(tmp);

        if(PlayerInfo[id][Logado] == false)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não conectado(a)!");

        if(playerid == id)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não pode efetuar comando em sí mesmo!");

        SetPlayerHealth(id, 100);
        format(String, sizeof(String), "| BCM-Admin | O(A) %s %s[%d] encheu sua vida", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid);
        SendClientMessage(id, -1, String);
        format(String, sizeof(String), "| BCM-Admin | Você encheu a vida do(a) jogador(a) %s[%d]", PlayerInfo[id][Nome], id);
        SendClientMessage(playerid, -1, String);
        return 1;
    }
    if(strcmp(cmd, "/enchercolete", true)==0)
    {
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128], id;

        tmp = strtok(cmdtext, idx);

        if(!strlen(tmp))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /EncherColete [id]");

        id = strval(tmp);

        if(PlayerInfo[id][Logado] == false)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não conectado(a)!");

        if(playerid == id)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não pode efetuar comando em sí mesmo!");

        SetPlayerArmour(id, 100);
        format(String, sizeof(String), "| BCM-Admin | O(A) %s %s[%d] encheu seu {FF0000}colete", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid);
        SendClientMessage(id, -1, String);
        format(String, sizeof(String), "| BCM-Admin | Você encheu o {FF0000}colete{FFFFFF} do(a) jogador(a) %s[%d]", PlayerInfo[id][Nome], id);
        SendClientMessage(playerid, -1, String);
        return 1;
    }
    if(strcmp(cmd, "/ir", true)==0)
    {
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128], id;

        tmp = strtok(cmdtext, idx);

        if(!strlen(tmp))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /Ir [id]");

        id = strval(tmp);

        if(PlayerInfo[id][Logado]==false)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não conectado(a)!");

        if(playerid == id)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não pode efetuar comando em sí mesmo!");

        GetPlayerPos(id, X, Y, Z);
        SetPlayerPos(playerid, X, Y, Z);
        SetPlayerInterior(playerid, GetPlayerInterior(id));

        format(String, sizeof(String), "| BCM-Admin | O(A) %s %s[%d] veio até sua posição", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid);
        SendClientMessage(id, -1, String);
        format(String, sizeof(String), "| BCM-Admin | Você foi até a posição do jogador(a) %s[%d]", PlayerInfo[id][Nome], id);
        SendClientMessage(playerid, -1, String);
        return 1;
    }
    if(strcmp(cmd, "/trazer", true)==0)
    {
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128], id;

        tmp = strtok(cmdtext, idx);

        if(!strlen(tmp))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /Trazer [id]");

        id = strval(tmp);

        if(PlayerInfo[id][Logado]==false)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não conectado(a)!");

        if(playerid == id)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não pode efetuar comando em sí mesmo!");

        GetPlayerPos(playerid, X, Y, Z);
        SetPlayerPos(id, X, Y, Z);
        SetPlayerInterior(id, GetPlayerInterior(playerid));

        format(String, sizeof(String), "| BCM-Admin | O(A) %s %s[%d] puxou você", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid);
        SendClientMessage(id, -1, String);
        format(String, sizeof(String), "| BCM-Admin | Você puxou jogador(a) %s[%d]", PlayerInfo[id][Nome], id);
        SendClientMessage(playerid, -1, String);
        return 1;
    }
    if(strcmp(cmd,"/punicao", true)==0)
    {
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128], tmp1[128], tmp2[128], tempo, id;

        tmp = strtok(cmdtext, idx);
        tmp1 = strtok(cmdtext, idx);
        tmp2 = strrest(cmdtext, idx);

        if(!strlen(tmp) || !strlen(tmp1) || !strlen(tmp2))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /Punicao [id][Tempo da Cadeia][Motivo da Cadeia]");

        id = strval(tmp);
        tempo = strval(tmp1);

        if(PlayerInfo[id][Logado] == false)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não conectado(a)!");

        if(playerid == id)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não pode efetuar comando em sí mesmo!");

        if(tempo <= 0 || tempo > 1000)
            return SendClientMessage(playerid, Erro, "| ERRO | Tempo só permitido entre 1 e 1000!");

        if(PrisonEnum[id][pTempo] != 0)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) já está preso(a)!");

        KillTimer(PerseguicaoTime[id]);
        format(PrisonEnum[id][pCadeia], 15, "Federal");
        format(PrisonEnum[id][pMotivo], 128, tmp2);
        PrisonEnum[id][pTempo] = tempo*60;

        GameTextForPlayer(id, "~w~~h~PRESO!", 2000, 0);
        format(String, sizeof(String), "| BCM-Admin | O(A) %s %s prendeu o(a) jogador(a) %s por %d minutos ( Motivo: %s )", CargoAdmin(playerid), PlayerInfo[playerid][Nome], PlayerInfo[id][Nome], tempo, tmp2);
        SendClientMessageToAll(0x76EE00AA, String);

        mysql_format(IDConexao, String, sizeof(String), "INSERT INTO `Prisoes` (Nome, Responsavel, Cadeia, Motivo, Tempo) VALUES ('%e', '%e', '%e', '%e', '%d')", PlayerInfo[id][Nome], PlayerInfo[playerid][Nome], PrisonEnum[id][pCadeia], PrisonEnum[id][pMotivo], PrisonEnum[id][pTempo]);
        mysql_query(IDConexao, String);
        mysql_format(IDConexao, String, sizeof(String), "SELECT * FROM `Prisoes` WHERE `Nome`='%e'", PlayerInfo[id][Nome]);
        mysql_tquery(IDConexao, String, "DBLoadPrisons", "d", id);
        return 1;
    }
	if(strcmp(cmd, "/despunicao", true)==0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128], id;

        tmp = strtok(cmdtext, idx);

        if(!strlen(tmp))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /Despunicao [id]");

        id = strval(tmp);

        if(PlayerInfo[id][Logado] == false)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não conectado(a)!");

        if(playerid == id)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não pode efetuar comando em sí mesmo!");

        if(PrisonEnum[id][pTempo] == 0)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não esta preso(a)!");


        SetPlayerInterior(id, 0);
        SetPlayerHealth(id, 100);
        SetPlayerPos(id, 1554.8657,-1675.6693,16.1953);

        PrisonEnum[id][pCadeia] = 0;
        PrisonEnum[id][pTempo] = 0;
        format(PrisonEnum[id][pMotivo], 1, "");

        mysql_format(IDConexao, String, sizeof(String), "DELETE FROM `Prisoes` WHERE `Nome`='%e'", PlayerInfo[id][Nome]);
        mysql_query(IDConexao, String);

        PlayerTextDrawHide(id, TempoPresidio[id][2]);
        PlayerTextDrawHide(id, TempoPresidio[id][1]);
        PlayerTextDrawHide(id, TempoPresidio[id][0]);

        GameTextForPlayer(id, "~w~Solto!", 3000, 0);
        format(String, sizeof(String), "| BCM-Admin | Você soltou o(a) jogador(a) %s[%d] da prisão", PlayerInfo[id][Nome], id);
        SendClientMessage(playerid, adm, String);
        format(String, sizeof(String), "| BCM-Admin | O(A) %s %s[%d] soltou você da prisão", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid);
        SendClientMessage(id, adm, String);
        return 1;
	}
    if(strcmp(cmd, "/criarveiculo", true)==0)
    {
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        if(IsPlayerInAnyVehicle(playerid))
            return SendClientMessage(playerid, Erro,"| ERRO | Você está em um veiculo!");

        new tmp[128], tmp1[128], tmp2[128], id;

        tmp = strtok(cmdtext, idx);
        tmp1 = strtok(cmdtext, idx);
        tmp2 = strtok(cmdtext, idx);

        if(!strlen(tmp) || !strlen(tmp1) || !strlen(tmp2))
            return SendClientMessage(playerid, Erro,"| ERRO | Digite: /CriarVeiculo [id-carro] [id-cor] [id-cor]");

        id = strval(tmp);
        Cor1 = strval(tmp1);
        Cor2 = strval(tmp2);

        if(id < 400 || id > 611)
            return SendClientMessage(playerid, Erro,"| ERRO | ID do Veiculo Inválido, Digite entre: 400 a 611");

        if(Cor1 < 0 || Cor1 > 255)
            return SendClientMessage(playerid, Erro,"| ERRO | ID da Cor Inválida, Digite entre: 0 a 255");

        if(Cor2 < 0 || Cor2 > 255)
            return SendClientMessage(playerid, Erro,"| ERRO | ID da Cor Inválida, Digite entre: 0 a 255");

        cVehicle[playerid] = true;
        GetPlayerFacingAngle(playerid, A);
        GetPlayerPos(playerid, X, Y, Z);
        CarroAdmin[playerid] = CreateVehicle(id,X-2,Y,Z,A,Cor2,Cor1,0);
        PutPlayerInVehicle(playerid, CarroAdmin[playerid], 0);
        if(GetPlayerInterior(playerid))
        LinkVehicleToInterior(CarroAdmin[playerid], GetPlayerInterior(playerid));
        format(String, sizeof(String), "| BCM-Admin | Você criou o veículo {FFFFFF}'{0CB80C}%s{FFFFFF}' {0080FF}ID {FFFFFF}'{0CB80C}%d{FFFFFF}' !", VehicleNames[GetVehicleModel(GetPlayerVehicleID(playerid))-400], id);
        SendClientMessage(playerid, adm, String);
        SendClientMessage(playerid, adm, "| BCM-Admin | Ao sair do veículo ele será automaticamente deletado!");
        return 1;
    }
    if(strcmp(cmd,"/ac",true)==0)
    {
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128];

        strmid(tmp, cmdtext, 3, strlen(cmdtext));

        if(!strlen(tmp))
            return SendClientMessage(playerid,Erro, "| ERRO | Digite: /Ac [mensagem]");

        format(String, sizeof(String), "| Chat-Admin | %s %s [%d] diz: %s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid, tmp);
        ChatAdmin(adm, String);
        return 1;
	}
    if(strcmp(cmd,"/a",true)==0)
    {
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128];

        strmid(tmp,cmdtext,2,strlen(cmdtext));

        if(!strlen(tmp))
            return SendClientMessage(playerid,Erro, "| ERRO | Digite: /A [mensagem]");

        format(String, sizeof(String), "* %s %s: %s", CargoAdmin(playerid),PlayerInfo[playerid][Nome], tmp);
        SendClientMessageToAll(0x0099CCAA, String);
        return 1;
	}
    if(strcmp(cmd, "/cnn", true) == 0)
    {
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128];

        strmid(tmp,cmdtext,4,strlen(cmdtext));

        if(!strlen(tmp))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /Cnn [mensagem]");

        format(String, sizeof(String), "~r~# ~p~%s~w~: %s ~r~#", PlayerInfo[playerid][Nome], tmp);
        TextDrawSetString(RespawnVeiculos, String);
        TextDrawShowForPlayer(playerid, RespawnVeiculos);
        SetTimerEx("HideTextRespawn", 1500, false, "d", playerid);
        return 1;
    }
    if(strcmp(cmd, "/ann", true) == 0)
    {
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128];

        strmid(tmp,cmdtext,4,strlen(cmdtext));

		if(!strlen(tmp))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /Ann [mensagem]");

		format(String, sizeof(String), "~r~#~w~%s ~r~#", tmp);
		TextDrawSetString(RespawnVeiculos, String);
		TextDrawShowForPlayer(playerid, RespawnVeiculos);
		SetTimerEx("HideTextRespawn", 1500, false, "d", playerid);
        return 1;
    }
	if(strcmp(cmd, "/injetar", true) == 0)
    {
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128], id;

    	tmp = strtok(cmdtext, idx);

    	if(!strlen(tmp))
            return SendClientMessage(playerid, Vermelho, "| ERRO | Digite: /Injetar [id]");

        id = strval(tmp);

        if(PlayerInfo[id][Logado] == false)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não conectado(a)!");

        if(playerid == id)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não pode efetuar comando em sí mesmo!");

    	PutPlayerInVehicle(id, GetPlayerVehicleID(playerid), 1);
    	SendClientMessage(playerid, adm, "| BCM-Admin | Comando efetuado com sucesso!");
    	format(String, sizeof(String), "| CMR-Admin | O(A) %s %s te colocou dentro de seu veiculo para o ajuda-lo!", CargoAdmin(playerid), PlayerInfo[playerid][Nome]);
    	SendClientMessage(id, adm, String);
    	return 1;
	}
	if(strcmp(cmd, "/ejetar", true) == 0)
	{
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128], id;

        tmp = strtok(cmdtext, idx);

        if(!strlen(tmp))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /Ejetar [id]");

        id = strval(tmp);

        if(PlayerInfo[id][Logado] == false)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não conectado(a)!");

        if(playerid == id)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não pode efetuar comando em sí mesmo!");

        RemovePlayerFromVehicle(id);
        SendClientMessage(playerid, adm, "| BCM-Admin | Comando efetuado com sucesso!");
        format(String, sizeof(String), "| BCM-Admin | O(A) %s %s ejetou você do seu veiculo!", CargoAdmin(playerid), PlayerInfo[playerid][Nome]);
        SendClientMessage(id, adm, String);
        return 1;
	}
    if(strcmp(cmd, "/godmod", true)==0)
    {
        if(!IsPlayerHelper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        SetPlayerHealth(playerid, 9999999);
        SendClientMessage(playerid, -1, "| BCM-Admin | Comando efetuado com sucesso!");
        return 1;
    }
    if(strcmp(cmd, "/banir", true) == 0)                                        //NIVEL 2
	{
        if(!IsPlayerModerator(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128], tmp1[128], id;

        tmp = strtok(cmdtext, idx);
        tmp1 = strrest(cmdtext, idx);

		if(!strlen(tmp) || !strlen(tmp1))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /Banir [ID/Nome do(a) Jogador(a)] [Motivo do Banimento]");

        id = strval(tmp);

        if(playerid == id)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não pode efetuar comando em sí mesmo!");

        format(BanidosEnum[id][bResponsavel], 24, PlayerInfo[playerid][Nome]);
        format(BanidosEnum[id][bMotivo], 24, tmp1);

        getdate(Ano, Mes, Dia);
        format(String, sizeof(String), "%02d/%02d/%04d", Dia, Mes, Ano);
        format(BanidosEnum[id][bDia], 24, String);

        format(BanidosEnum[id][bVencimento], 24, "Permanente");

        gettime(Hora, Min, Seg);
        format(String, sizeof(String), "%02d:%02d", Hora, Min);
        format(BanidosEnum[id][bHora], 24, String);

        mysql_format(IDConexao, String, sizeof(String), "INSERT INTO Banidos (Nome, Responsavel, Motivo, Dia, Vencimento, Hora) VALUES ('%e', '%e', '%e', '%e', '%e', '%e')", PlayerInfo[id][Nome], BanidosEnum[id][bResponsavel], BanidosEnum[id][bMotivo], BanidosEnum[id][bDia], BanidosEnum[id][bVencimento], BanidosEnum[id][bHora]);
        mysql_query(IDConexao, String);

		format(String, sizeof(String), "| BCM-Admin | O(A) %s %s baniu o(a) jogador(a) %s ( Motivo : %s )", CargoAdmin(playerid), PlayerInfo[playerid][Nome], PlayerInfo[id][Nome], tmp1);
        SendClientMessageToAll(Vermelho, String);
        Kick(id);
        return 1;
    }
    if(strcmp(cmd,"/dararma", true)==0)                                         //NIVEL 3
    {
        if(!IsPlayerAdmininstrator(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128], tmp1[128], idarma, id;

        tmp = strtok(cmdtext, idx);
        tmp1 = strtok(cmdtext, idx);

		if(!strlen(tmp) || !strlen(tmp1))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /DarArma [id] [id-arma]");

        id = strval(tmp);
		idarma = strval(tmp1);

		GivePlayerWeapon(id, idarma, 100000);
		SendClientMessage(playerid, adm, "| BCM-Admin | Comando efetuado com sucesso!");
		format(String, sizeof(String), "| BCM-Admin | O(A) %s %s te deu a arma ID {FFFFFF}'{0CB80C}%d{FFFFFF}'", CargoAdmin(playerid),PlayerInfo[playerid][Nome],idarma);
        SendClientMessage(id, adm, String);
        return 1;
	}
    if(strcmp(cmd,"/dardinheiro", true)==0)
    {
        if(!IsPlayerAdmininstrator(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128], tmp1[128], grana, id;

		tmp = strtok(cmdtext, idx);
		tmp1 = strtok(cmdtext, idx);

		if(!strlen(tmp) || !strlen(tmp1))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /DarDinheiro [id] [Quantidade de Dinheiro]");

        id = strval(tmp);
		grana = strval(tmp1);

        if(PlayerInfo[id][Logado] == false)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não está conectado(a)!");

        if(playerid == id)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não pode efetuar comando em sí mesmo!");

        PlayerInfo[id][Dinheiro] += grana;
        UpdatePlayerMoney(id);

		format(String, sizeof(String), "| BCM-Admin | Você deu {019303}$%s {0080FF}para o jogador(a) %s[%d]", IsMoney(grana, "."), PlayerInfo[id][Nome], id);
        SendClientMessage(playerid, adm, String);
		format(String, sizeof(String), "| BCM-Admin | O(A) %s %s deu para você {019303}$%s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], IsMoney(grana, "."));
        SendClientMessage(id, adm, String);
        return 1;
    }
    if(strcmp(cmd,"/removerdinheiro", true)==0)
    {
        if(!IsPlayerAdmininstrator(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128], tmp1[128], grana, id;

        tmp = strtok(cmdtext, idx);
        tmp1 = strtok(cmdtext, idx);

		if(!strlen(tmp) || !strlen(tmp1))
            return SendClientMessage(playerid, Erro, "Digite: /Removerdinheiro [id] [Quantidade de Dinheiro]");

        id = strval(tmp);
		grana = strval(tmp1);

		if(PlayerInfo[id][Logado] == false)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não está conectado(a)!");

        if(playerid == id)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não pode efetuar comando em sí mesmo!");

        PlayerInfo[id][Dinheiro] -= grana;
        UpdatePlayerMoney(id);

		format(String, sizeof(String), "| BCM-Admin | Você removeu {019303}$%s{FFFFFF} do(a) jogador(a) %s[%d]", IsMoney(grana, "."), PlayerInfo[id][Nome], id);
        SendClientMessage(playerid, adm, String);
		format(String, sizeof(String), "| BCM-Admin | O(A) %s %s removeu de você {019303}$%s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], IsMoney(grana, "."));
        SendClientMessage(id, adm, String);
        return 1;
    }
    if(strcmp(cmd,"/darvip", true)==0)
    {
        if(!IsPlayerAdmininstrator(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128], tmp1[128], id;

		tmp = strtok(cmdtext, idx);
		tmp1 = strtok(cmdtext, idx);

		if(!strlen(tmp) || !strlen(tmp1))
			return SendClientMessage(playerid, Erro, "| ERRO | Digite: /Darvip [id] [Quantidade de Dia(s)]");

        id = strval(tmp);
		Dia = strval(tmp1);

		if(Dia < 1 || Dia > 60)
            return SendClientMessage(playerid, Erro, "| ERRO | Quantidade inválida!");

		if(PlayerInfo[id][Logado] == false)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não está conectado(a)!");

        if(playerid == id)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não pode efetuar comando em sí mesmo!");

        if(IsPlayerHelper(id))
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) é membro da admininstração!");

		format(String, sizeof(String), "| BCM-Admin | Você deu %d dia(s) de VIP para o(a) jogador(a) %s[%d]", Dia, PlayerInfo[id][Nome], id);
        SendClientMessage(playerid, adm, String);
		format(String, sizeof(String), "| BCM-Admin | O(A) %s %s deu %d dia(s) de VIP para você!", CargoAdmin(playerid), PlayerInfo[playerid][Nome], Dia);
        SendClientMessage(id, adm, String);
        SetVip(id, Dia);
        return 1;
    }
    if(strcmp(cmd,"/removervip", true)==0)
    {
        if(!IsPlayerAdmininstrator(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128], id;

        tmp = strtok(cmdtext, idx);

		if(!strlen(tmp))
			return SendClientMessage(playerid, Erro, "| ERRO | Digite: /Removervip [id]");

        id = strval(tmp);

		if(PlayerInfo[id][Logado] == false)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não está conectado(a)!");

        if(playerid == id)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não pode efetuar comando em sí mesmo!");

        if(VipInfo[id][Vip] == false)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não é VIP!");

		format(String, sizeof(String), "| BCM-Admin | Você removeu VIP do(a) jogador(a) %s[%d]", PlayerInfo[id][Nome], id);
        SendClientMessage(playerid, adm, String);
		format(String, sizeof(String), "| BCM-Admin | O(A) %s %s removeu o VIP de você", CargoAdmin(playerid), PlayerInfo[playerid][Nome]);
        SendClientMessage(id, adm, String);
        RemoveVip(id);
        return 1;
    }
    if(strcmp(cmd, "/DarSkin", true)==0)
    {
        if(!IsPlayerAdmininstrator(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128], tmp1[128], Idskin, id;

		tmp = strtok(cmdtext, idx);
		tmp1 = strtok(cmdtext, idx);

		if(!strlen(tmp) || !strlen(tmp1))
			return SendClientMessage(playerid, Erro, "| ERRO | Digite: /DarSkin [id] [id-skin]");

        id = strval(tmp);
		Idskin = strval(tmp1);

		if(PlayerInfo[id][Logado] == false)
           	return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não está conectado(a)!");

        PlayerInfo[id][Skin] = Idskin;
		SetPlayerSkin(id, PlayerInfo[id][Skin]);

		format(String, sizeof(String), "| BCM-Admin | Você deu a skin ID {FFFFFF}'{0CB80C}%d{FFFFFF}'{0080FF} para o jogador(a) %s", Idskin, PlayerInfo[id][Nome]);
        SendClientMessage(playerid, adm, String);
        format(String, sizeof(String), "| BCM-Admin | O(A) %s %s lê deu a skin ID {FFFFFF}'{0CB80C}%d{FFFFFF}'", CargoAdmin(playerid), PlayerInfo[playerid][Nome], Idskin);
        SendClientMessage(id, adm, String);
        mysql_format(IDConexao, String, sizeof(String), "UPDATE Contas SET Skin='%d' WHERE Nome='%e'", PlayerInfo[id][Skin], PlayerInfo[id][Nome]);
        mysql_query(IDConexao, String);
        return 1;
    }
    if(strcmp(cmd,"/darlevel", true)==0)                                        //NIVEL 4
    {
		if(!IsPlayerAdmininstrator(playerid))
			return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128], tmp1[128], level, id;

		tmp = strtok(cmdtext, idx);
		tmp1 = strtok(cmdtext, idx);

		if(!strlen(tmp) || !strlen(tmp1))
			return SendClientMessage(playerid, Erro, "Digite: /Darlevel [id] [quantia]");

        id = strval(tmp);
        level = strval(tmp1);

		if(PlayerInfo[id][Logado]==false)
           	return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não está conectado(a)!");

        PlayerInfo[id][Level] += level;
        SetPlayerScore(id, PlayerInfo[id][Level]);

		format(String, sizeof(String), "| BCM-Admin | Você deu %d level(s) para o jogador(a) %s[%d]", level, PlayerInfo[id][Nome], id);
        SendClientMessage(playerid, adm, String);
		format(String, sizeof(String), "| BCM-Admin | O(A) %s %s deu para você %d level(s)", CargoAdmin(playerid), PlayerInfo[playerid][Nome], level);
        SendClientMessage(id, adm, String);
        mysql_format(IDConexao, String, sizeof(String), "UPDATE Contas SET Level='%i' WHERE Nome='%e'", PlayerInfo[id][Level], PlayerInfo[id][Nome]);
        mysql_query(IDConexao, String);
        return 1;
    }
    if(strcmp(cmd,"/removerlevel", true)==0)
    {
        if(!IsPlayerAdmininstrator(playerid))
			return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128], tmp1[128], level, id;

   		tmp = strtok(cmdtext, idx);
		tmp1 = strtok(cmdtext, idx);

		if(!strlen(tmp) || !strlen(tmp1))
			return SendClientMessage(playerid, Erro, "| ERRO | Digite: /Removerlevel [id] [quantia]");

        id = strval(tmp);
        level = strval(tmp1);

		if(PlayerInfo[id][Logado] == false)
           	return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não está conectado(a)!");

        PlayerInfo[id][Level] -= level;
        SetPlayerScore(id, PlayerInfo[id][Level]);

		format(String, sizeof(String), "| BCM-Admin | Você removeu %d level(s) do(a) jogador(a) %s[%d]", level, PlayerInfo[id][Nome], id);
        SendClientMessage(playerid, adm, String);
		format(String, sizeof(String), "| BCM-Admin | O(A) %s %s removeu de você %d level(s)", CargoAdmin(playerid), PlayerInfo[playerid][Nome], level);
        SendClientMessage(id, adm, String);
        mysql_format(IDConexao, String, sizeof(String), "UPDATE Contas SET Level='%i' WHERE Nome='%e'", PlayerInfo[id][Level], PlayerInfo[id][Nome]);
        mysql_query(IDConexao, String);
        return 1;
    }
    if(strcmp(cmd,"/darreais", true)==0)
    {
        if(!IsPlayerAdmininstrator(playerid))
			return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128], tmp1[128], real, id;

   		tmp = strtok(cmdtext, idx);
		tmp1 = strtok(cmdtext, idx);

		if(!strlen(tmp) || !strlen(tmp1))
			return SendClientMessage(playerid, Erro, "| ERRO | Digite: /DarReais [id] [quantia]");

        id = strval(tmp);
        real = strval(tmp1);

		if(PlayerInfo[id][Logado] == false)
           	return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não está conectado(a)!");

        if(playerid == id)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não pode efetuar comando em sí mesmo!");

        PlayerInfo[id][Reais] += real;
		format(String, sizeof(String), "| BCM-Admin | Você deu {31B404}R$%s{FFFFFF} para o(a) jogador(a) %s[%d]", IsMoney(real, "."), PlayerInfo[id][Nome], id);
        SendClientMessage(playerid, adm, String);
		format(String, sizeof(String), "| BCM-Admin | O(A) %s %s deu para você {31B404}R$%s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], IsMoney(real, "."));
        SendClientMessage(id, adm, String);

        mysql_format(IDConexao, String, sizeof(String), "UPDATE Contas SET `Reais`='%d' WHERE `ID`='%d'", PlayerInfo[id][Reais], PlayerInfo[id][ID]);
        mysql_query(IDConexao, String);
        return 1;
    }
    if(strcmp(cmd,"/removerreais", true)==0)
    {
        if(!IsPlayerAdmininstrator(playerid))
			return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128], tmp1[128], real, id;

   		tmp = strtok(cmdtext, idx);
		tmp1 = strtok(cmdtext, idx);

		if(!strlen(tmp) || !strlen(tmp1))
			return SendClientMessage(playerid, Erro, "| ERRO | Digite: /RemoverReais [id] [quantia]");

        id = strval(tmp);
        real = strval(tmp1);

		if(PlayerInfo[id][Logado] == false)
           	return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não está conectado(a)!");

        if(playerid == id)
            return SendClientMessage(playerid, Erro, "| ERRO | Você não pode efetuar comando em sí mesmo!");

        PlayerInfo[id][Reais] -= real;
		format(String, sizeof(String), "| BCM-Admin | Você removeu {31B404}R$%s{FFFFFF} do(a) jogador(a) %s[%d]", IsMoney(real), PlayerInfo[id][Nome], id);
        SendClientMessage(playerid, adm, String);
		format(String, sizeof(String), "| BCM-Admin | O(A) %s %s removeu de você {31B404}R$%s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], IsMoney(real));
        SendClientMessage(id, adm, String);

        mysql_format(IDConexao, String, sizeof(String), "UPDATE Contas SET `Reais`='%d' WHERE `ID`='%d'", PlayerInfo[id][Reais], PlayerInfo[id][ID]);
        mysql_query(IDConexao, String);
        return 1;
    }
    if(strcmp(cmd, "/fecharservidor", true)==0)
    {
        if(!IsPlayerDeveloper(playerid))
			return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128];

        tmp = strrest(cmdtext, idx);

        if(!strlen(tmp))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /FecharServidor [senha]");

        format(String, sizeof(String), "password %s", tmp);
	    SendRconCommand(String);
        format(String, sizeof(String), "| BCM-Admin | O(A) %s %s trancou o servidor", CargoAdmin(playerid), PlayerInfo[playerid][Nome]);
        SendClientMessageToAll(adm, String);
        format(String, sizeof(String), "| BCM-Admin | Senha do servidor {FF0000}%s", tmp);
        SendClientMessage(playerid, adm, String);
        return 1;
    }
    if(strcmp(cmd, "/abrirservidor", true)==0)
    {
        if(!IsPlayerDeveloper(playerid))
			return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

	    SendRconCommand("password 0");
        format(String, sizeof(String), "| BCM-Admin | O(A) %s %s abriu o servidor", CargoAdmin(playerid), PlayerInfo[playerid][Nome]);
        SendClientMessageToAll(adm, String);
        SendClientMessage(playerid, adm, "| BCM-Admin | O servidor acaba de ser destrancado por você");
        return 1;
    }
    if(strcmp(cmd, "/daradmin", true)==0)
    {
        if(!IsPlayerDeveloper(playerid))
			return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128], tmp1[128], nivel, id;

		tmp = strtok(cmdtext, idx);
  		tmp1 = strtok(cmdtext, idx);

		if(!strlen(tmp) || !strlen(tmp1))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /Daradmin [id] [nivel]");

        id = strval(tmp);
        nivel = strval(tmp1);

		if(PlayerInfo[id][Logado] == false)
            return SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não está conectado(a)!");

		if(nivel == 0)
		{
            PlayerInfo[id][Admin] = nivel;
            format(String, sizeof(String), "| BCM-Admin | Você removeu o(a) jogador(a) %s[%d] da Admininstração!", PlayerInfo[id][Nome], id, CargoAdmin(id));
            SendClientMessage(playerid, adm, String);
            format(String, sizeof(String), "| BCM-Admin | O(A) %s %s[%d] removeu você da Admininstração!", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid, CargoAdmin(id));
            SendClientMessage(id, adm, String);
            return 1;
  		}

		if(nivel < PlayerInfo[id][Admin])
		{
            PlayerInfo[id][Admin] = nivel;
            format(String, sizeof(String), "| BCM-Admin | Você rebaixou o(a) jogador(a) %s[%d] para %s", PlayerInfo[id][Nome], id, CargoAdmin(id));
            SendClientMessage(playerid, adm, String);
            format(String, sizeof(String), "| BCM-Admin | O(A) %s %s[%d] rebaixou você para %s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid, CargoAdmin(id));
            SendClientMessage(id, adm, String);
            return 1;
		}

		if(nivel > PlayerInfo[id][Admin])
		{
            PlayerInfo[id][Admin] = nivel;
            format(String, sizeof(String), "| BCM-Admin | Você promoveu o(a) jogador(a) %s[%d] para %s", PlayerInfo[id][Nome], id, CargoAdmin(id));
            SendClientMessage(playerid, adm, String);
            format(String, sizeof(String), "| BCM-Admin | O(A) %s %s[%d] promoveu você para %s", CargoAdmin(playerid), PlayerInfo[playerid][Nome], playerid, CargoAdmin(id));
            SendClientMessage(id, adm, String);
      	}

        mysql_format(IDConexao, String, sizeof(String), "UPDATE Contas SET Admin='%i' WHERE Nome='%e'", PlayerInfo[id][Admin], PlayerInfo[id][Nome]);
        mysql_query(IDConexao, String);
        return 1;
    }
    if(strcmp(cmd, "/reiniciar", true)==0)
	{
        if(!IsPlayerDeveloper(playerid))
			return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

		SendClientMessageToAll(0xB9FFFFAA, "| BCM-Admin | O Server reiniciara em 2 minutos!");
		SetTimer("RestartServer", 1000*60, false);
        return 1;
    }
    if(strcmp(cmd, "/dropcolumn", true)==0)
    {
        if(!IsPlayerDeveloper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128], tmp1[128];

        tmp = strtok(cmdtext, idx);
        tmp1 = strtok(cmdtext, idx);

        if(!strlen(tmp) || !strlen(tmp1))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /DropColumn [name-table][name-column]");

        mysql_format(IDConexao, String, sizeof(String), "ALTER TABLE %s DROP COLUMN %s", tmp, tmp1);
        mysql_query(IDConexao, String);
        format(String, sizeof(String), "| BCM-Admin | You drop column %s in table %s", tmp1, tmp);
        SendClientMessage(playerid, adm, String);
        return 1;
    }
    if(strcmp(cmd, "/addcolumn", true)==0)
    {
        if(!IsPlayerDeveloper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        new tmp[128], tmp1[128];

        tmp = strtok(cmdtext, idx);
        tmp1 = strtok(cmdtext, idx);

        if(!strlen(tmp) || !strlen(tmp1))
            return SendClientMessage(playerid, Erro, "| ERRO | Digite: /AddColumn [name-table][name-column]");

        mysql_format(IDConexao, String, sizeof(String), "ALTER TABLE %s ADD %s varchar(24) NOT NULL DEFAULT 'N/A'", tmp, tmp1);
        mysql_query(IDConexao, String);
        format(String, sizeof(String), "| BCM-Admin | You add column %s in table %s", tmp1, tmp);
        SendClientMessage(playerid, adm, String);
        return 1;
    }
    if(strcmp(cmd, "/salvarcontas", true)==0)
    {
        if(!IsPlayerDeveloper(playerid))
            return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        for(new i=0; i < MAX_PLAYERS; i++)
        {
            if(IsPlayerConnected(i) && PlayerInfo[i][Logado] == true)
            {
                format(String, sizeof(String), "| BCM-Admin | Conta do jogador(a) %s[%d] foi salva com sucesso!", PlayerInfo[i][Nome], i);
                SendClientMessage(playerid, adm, String);
                SaveAccounts(i);
            }
        }
        return 1;
    }
