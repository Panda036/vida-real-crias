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
