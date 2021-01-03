stock ClickTextDrawIdentity(playerid, PlayerText:playertextid)
{
    if(playertextid == TDPlayerIdentity[playerid][tdi_closed])
    {
        HideTDPlayerIdentity(playerid);
        return 1;
    }
    return 1;
}
