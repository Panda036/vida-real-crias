#include YSI\y_hooks

stock ClickTextDrawSkinsStore(playerid, PlayerText:playertextid)
{
    if(playertextid == TDPlayerSkinsStore[playerid][2]) //exit
    {
        HideTDPlayerSkinsStore(playerid);

        SetSpawnInfo(playerid, 0, PlayerInfo[playerid][skin], 217.3514, -98.5038, 1005.2578, 200.0, 0, 0, 0, 0, 0, 0);

        SpawnPlayer(playerid);
        return 1;
    }
    if(playertextid == TDPlayerSkinsStore[playerid][3]) //buy
    {
        if(SkinsListStore[skinidlist[playerid]][sls_sex] != PlayerInfo[playerid][sexo])
            return SendClientMessage(playerid, Erro, "Seu sexo não é o mesmo que a skin selecionada");

        if(PlayerInfo[playerid][Dinheiro] < SkinsListStore[skinidlist[playerid]][sls_price])
            return SendClientMessage(playerid, Erro, "Você não tem dinheiro suficiente");

        PlayerInfo[playerid][Dinheiro] -= SkinsListStore[skinidlist[playerid]][sls_price];
        UpdatePlayerMoney(playerid);

        if(strcmp(BusinessInfo[idbusiness[playerid]][cName], "N/A"))
            { BusinessInfo[idbusiness[playerid]][cSafe] += SkinsListStore[skinidlist[playerid]][sls_price]; }

        HideTDPlayerSkinsStore(playerid);
        PlayerInfo[playerid][skin] = SkinsListStore[skinidlist[playerid]][sls_skinid];
        SetIntQuery(playerid, "Identidade", "skin", PlayerInfo[playerid][skin]);
        SetSpawnInfo(playerid, 0, PlayerInfo[playerid][skin], 217.3514, -98.5038, 1005.2578, 200.0, 0, 0, 0, 0, 0, 0);
        SpawnPlayer(playerid);

        format(String, MAX_STRING, "Você comprou a skin {FF4000}%s{FFFFFF} por {1b6302}$%d", SkinListName(SkinsListStore[skinidlist[playerid]][sls_skinid]), SkinsListStore[skinidlist[playerid]][sls_price]);
        SendClientMessage(playerid, White, String);
        return 1;
    }
    if(playertextid == TDPlayerSkinsStore[playerid][4]) //left
    {
        if(skinidlist[playerid] == 0)
            return SendClientMessage(playerid, Erro, "Não tem mais skins");

        skinidlist[playerid]--;

        SetPlayerSkin(playerid, SkinsListStore[skinidlist[playerid]][sls_skinid]);
        format(String, 50, "~r~%s", (SkinsListStore[skinidlist[playerid]][sls_sex] == SEX_BOY ? ("Masculino") : ("Feminino")));
        PlayerTextDrawSetString(playerid, TDPlayerSkinsStore[playerid][0], String);
        PlayerTextDrawShow(playerid, TDPlayerSkinsStore[playerid][0]);
        format(String, 50, "~g~$%d", SkinsListStore[skinidlist[playerid]][sls_price]);
        PlayerTextDrawSetString(playerid, TDPlayerSkinsStore[playerid][1], String);
        PlayerTextDrawShow(playerid, TDPlayerSkinsStore[playerid][1]);
        return 1;
    }
    if(playertextid == TDPlayerSkinsStore[playerid][5]) //right
    {
        if(skinidlist[playerid] == 217)
            return SendClientMessage(playerid, Erro, "Não tem mais skins");

        skinidlist[playerid]++;

        SetPlayerSkin(playerid, SkinsListStore[skinidlist[playerid]][sls_skinid]);
        format(String, 50, "~r~%s", (SkinsListStore[skinidlist[playerid]][sls_sex] == SEX_BOY ? ("Masculino") : ("Feminino")));
        PlayerTextDrawSetString(playerid, TDPlayerSkinsStore[playerid][0], String);
        PlayerTextDrawShow(playerid, TDPlayerSkinsStore[playerid][0]);
        format(String, 50, "~g~$%d", SkinsListStore[skinidlist[playerid]][sls_price]);
        PlayerTextDrawSetString(playerid, TDPlayerSkinsStore[playerid][1], String);
        PlayerTextDrawShow(playerid, TDPlayerSkinsStore[playerid][1]);
        return 1;
    }
    return 1;
}

stock ShowTDPlayerSkinsStore(playerid)
{
    CostSkin[playerid] = true;

    SetPlayerVirtualWorld(playerid, (playerid + 1));

    skinidlist[playerid] = 0;
    SetPlayerSkin(playerid, SkinsListStore[skinidlist[playerid]][sls_skinid]);

    TogglePlayerControllable(playerid, false);
    SelectTextDraw(playerid, Green);

    for(new i = 0; i < 7; i++)
    {
        TextDrawShowForPlayer(playerid, TDSkinsStore[i]);
    }
    for(new i = 0; i < 6; i++)
    {
        PlayerTextDrawShow(playerid, TDPlayerSkinsStore[playerid][i]);
    }
    return 1;
}

stock HideTDPlayerSkinsStore(playerid)
{
    CostSkin[playerid] = false;

    SetPlayerVirtualWorld(playerid, 0);

    TogglePlayerControllable(playerid, true);
    CancelSelectTextDraw(playerid);

    for(new i = 0; i < 7; i++)
    {
        TextDrawHideForPlayer(playerid, TDSkinsStore[i]);
    }
    for(new i = 0; i < 6; i++)
    {
        PlayerTextDrawHide(playerid, TDPlayerSkinsStore[playerid][i]);
    }

    SetSpawnInfo(playerid, 0, PlayerInfo[playerid][skin], 217.3514, -98.5038, 1005.2578, 200.0, 0, 0, 0, 0, 0, 0);

    SpawnPlayer(playerid);
    return 1;
}
