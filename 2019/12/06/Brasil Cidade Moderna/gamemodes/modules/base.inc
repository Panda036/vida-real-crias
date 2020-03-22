#include YSI\y_hooks

// PickUp 1314
// MapIcon Dono: 62 - Vendendo: 61, Liberada: 60

/*enum IBase
{
    bDono,
    bName
}

new BaseInfo[MAX_BASES][IBase];*/

new BaseColors[3] =
{
    0xFF0000AA,
    0x000000AA,
    0xFFFFFFAA
};

new BaseOne[2];
new BaseGate;
new bool:BaseGateMoving[MAX_PLAYERS];

hook OnGameModeInit()
{
    CreateObject(3475, 2193.44116, -1781.11597, 17.18732,   0.00000, 0.00000, 0.00000);
    CreateObject(3475, 2193.43945, -1775.29333, 17.18730,   0.00000, 0.00000, 0.00000);
    CreateObject(3475, 2193.46387, -1769.36267, 17.18730,   0.00000, 0.00000, 0.00000);
    CreateObject(3475, 2193.43042, -1786.92114, 17.18732,   0.00000, 0.00000, 0.00000);
    CreateObject(3475, 2193.43164, -1792.72681, 17.18732,   0.00000, 0.00000, 0.00000);
    CreateObject(3475, 2193.44141, -1798.53210, 17.18732,   0.00000, 0.00000, 0.00000);
    CreateObject(3475, 2193.48267, -1804.31604, 17.18732,   0.00000, 0.00000, 0.00000);
    CreateObject(3475, 2193.48779, -1810.11694, 17.18732,   0.00000, 0.00000, 0.00000);
    CreateObject(3475, 2176.78735, -1829.58667, 14.76640,   0.00000, 0.00000, 90.00000);
    CreateObject(3749, 2184.53711, -1764.08191, 18.22983,   0.00000, 0.00000, 0.00000);
    CreateObject(3475, 2192.98486, -1813.19055, 17.18730,   0.00000, 0.00000, 180.00000);

    BaseGate = CreateObject(980, 2184.54248, -1764.15894, 15.16890,   0.00000, 0.00000, 0.00000);

    CreateDynamicMapIcon(2177.3479, -1770.5210, 13.5391, 60, 50, -1, -1, -1, 150.0);

    BaseOne[0] = GangZoneCreate(2129.0784, -1785.6256, 2177.2463, -1766.5287);
    BaseOne[1] = GangZoneCreate(2135.0696, -1830.2554, 2193.9294, -1770.3149);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    RemoveBuildingForPlayer(playerid, 1308, 2091.1641, -1826.8359, 12.7031, 0.25);
    RemoveBuildingForPlayer(playerid, 1308, 2128.3125, -1826.8359, 12.7031, 0.25);
    RemoveBuildingForPlayer(playerid, 1308, 2128.3125, -1786.7109, 12.7031, 0.25);
    RemoveBuildingForPlayer(playerid, 1308, 2155.6719, -1790.6406, 12.7031, 0.25);
    RemoveBuildingForPlayer(playerid, 1308, 2171.5703, -1761.6406, 12.7031, 0.25);
    RemoveBuildingForPlayer(playerid, 1308, 2190.4141, -1772.7188, 12.7031, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 2105.0859, -1765.6094, 10.8047, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 2209.0625, -1766.6172, 12.0938, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 2209.8984, -1807.6953, 12.0938, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 2213.0391, -1688.8984, 12.0938, 0.25);

    SetTimerEx("OnPlayerBase", 100, true, "i", playerid);
    SetTimerEx("OpeningBasePort", 1000, true, "i", playerid);
    return 1;
}

forward OnPlayerBase(playerid);
public OnPlayerBase(playerid)
{
    if(IsPlayerInBase(playerid))
    {
        new randomstr = random(sizeof(BaseColors));
        GangZoneShowForPlayer(playerid, BaseOne[0], BaseColors[randomstr]);
        GangZoneShowForPlayer(playerid, BaseOne[1], BaseColors[randomstr]);
        return 1;
    } else {
        GangZoneHideForPlayer(playerid, BaseOne[0]);
        GangZoneHideForPlayer(playerid, BaseOne[1]);
    }
    return 1;
}

IsPlayerInBase(playerid)
{
    new Float:x,Float:y,Float:z;
    GetPlayerPos(playerid, x, y, z);
    if(x >= 2135.0696 && y >= -1830.2554 && x <= 2193.9294 && y <= -1770.3149 || x >= 2129.0784 && y >= -1785.6256 && x <= 2177.2463 && y <= -1766.5287) return true;
    else return false;
}

forward OpeningBasePort(playerid);
public OpeningBasePort(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 5.0, 2184.6638, -1764.6041, 13.3765) && BaseGateMoving[playerid] == false)
    {
        BaseGateMoving[playerid] = true;
        MoveObject(BaseGate, 2184.54248, -1764.15894, 20.71560, 3.0);
        SendClientMessage(playerid, 0x00C40AAA, "| BASE | O Portão da Base foi aberto e fechara em 5 segundos!");
        SetTimerEx("ClosingBasePort", 5000, true, "i", playerid);
    }
    return 1;
}

forward ClosingBasePort(playerid);
public ClosingBasePort(playerid)
{
    BaseGateMoving[playerid] = false;
    MoveObject(BaseGate, 2184.54248, -1764.15894, 15.16890, 3.0);
    return 1;
}
