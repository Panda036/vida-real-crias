public OnPlayerDisconnect(playerid, reason)
{
    if(IsArena[playerid])
    {
        switch(Enter_Arena[playerid])
        {
            case 0:
            {
                PlayerInfo[playerid][PosX] = 2695.55;
                PlayerInfo[playerid][PosY] = -1704.70;
                PlayerInfo[playerid][PosZ] = 11.84;
                PlayerInfo[playerid][PosA] = 31.45;
                PlayerInfo[playerid][Interior] = 0;
            }
            case 1:
            {
                PlayerInfo[playerid][PosX] = 1099.56;
                PlayerInfo[playerid][PosY] = 1601.52;
                PlayerInfo[playerid][PosZ] = 12.54;
                PlayerInfo[playerid][PosA] = 174.62;
                PlayerInfo[playerid][Interior] = 0;
            }
            case 2:
            {
                PlayerInfo[playerid][PosX] = -2110.82;
                PlayerInfo[playerid][PosY] = -444.22;
                PlayerInfo[playerid][PosZ] = 38.73;
                PlayerInfo[playerid][PosA] = 270.19;
                PlayerInfo[playerid][Interior] = 0;
            }
        }
    }
    else if(dentrocasa[playerid] && IsPlayerInRangeOfPoint(playerid, 2.0, HouseInfo[houseid[playerid]][hInteriorX], HouseInfo[houseid[playerid]][hInteriorY], HouseInfo[houseid[playerid]][hInteriorZ]))
    {
        PlayerInfo[playerid][PosX] = HouseInfo[houseid[playerid]][iconx];
        PlayerInfo[playerid][PosY] = HouseInfo[houseid[playerid]][icony];
        PlayerInfo[playerid][PosZ] = HouseInfo[houseid[playerid]][iconz];
        PlayerInfo[playerid][PosA] = 0.0;
        PlayerInfo[playerid][Interior] = 0;
    }
    else if(withinbusiness[playerid] && IsPlayerInRangeOfPoint(playerid, 2.0, BusinessInfo[idbusiness[playerid]][cInteriorX], BusinessInfo[idbusiness[playerid]][cInteriorY], BusinessInfo[idbusiness[playerid]][cInteriorZ]))
    {
        PlayerInfo[playerid][PosX] = BusinessInfo[idbusiness[playerid]][cIconX];
        PlayerInfo[playerid][PosY] = BusinessInfo[idbusiness[playerid]][cIconY];
        PlayerInfo[playerid][PosZ] = BusinessInfo[idbusiness[playerid]][cIconZ];
        PlayerInfo[playerid][PosA] = 0.0;
        PlayerInfo[playerid][Interior] = 0;
    }
    else
    {
        PlayerInfo[playerid][Interior] = GetPlayerInterior(playerid);
        GetPlayerFacingAngle(playerid, PlayerInfo[playerid][PosA]);
        GetPlayerPos(playerid, PlayerInfo[playerid][PosX], PlayerInfo[playerid][PosY], PlayerInfo[playerid][PosZ]);
    }

    SaveAccounts(playerid);
    SaveIdentidade(playerid);

    PlayerInfo[playerid][ID] = 0;
    PlayerInfo[playerid][Profissao] = 0;
    PlayerInfo[playerid][Semprofissao] = 0;
    PlayerInfo[playerid][Nome] = 0;
    PlayerInfo[playerid][Senha] = 0;
    PlayerInfo[playerid][Email] = 0;
    PlayerInfo[playerid][Admin] = 0;
    PlayerInfo[playerid][minUP] = 0;
    PlayerInfo[playerid][segUP] = 0;
    PlayerInfo[playerid][Level] = 0;
    PlayerInfo[playerid][Exp] = 0;
    PlayerInfo[playerid][Reais] = 0;
    PlayerInfo[playerid][skin] = -1;
    PlayerInfo[playerid][Avisos] = 0;
    PlayerInfo[playerid][Estrelas] = 0;
    PlayerInfo[playerid][Dinheiro] = 0;
    PlayerInfo[playerid][SaldoBancario] = 0;
    PlayerInfo[playerid][Matou] = 0;
    PlayerInfo[playerid][Morreu] = 0;
    PlayerInfo[playerid][Interior] = 0;
    PlayerInfo[playerid][PosX] = 0;
    PlayerInfo[playerid][PosY] = 0;
    PlayerInfo[playerid][PosZ] = 0;
    PlayerInfo[playerid][PosA] = 0;
    PlayerInfo[playerid][sexo] = 0;
    PlayerInfo[playerid][Logado] = false;
    PlayerInfo[playerid][tutorial] = 0;
    PlayerInfo[playerid][load] = false;
    viewcmds[playerid] = false;
    IsMobile[playerid] = false;

    pPlayerInfo[playerid][pNome] = 0;
    pPlayerInfo[playerid][pSenha] = 0;
    pPlayerInfo[playerid][pEmail] = 0;
    VehicleAdmin[playerid] = 0;

    KillTimer(TempoPreso[playerid]);
    KillTimer(UPRelogio[playerid]);
	return 1;
}
