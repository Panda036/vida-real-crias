#include YSI\y_hooks

stock CheckVersionSAMP(playerid)
{
    new version[24];
    GetPlayerVersion(playerid, version, sizeof(version));

    if(strcmp(version, "0.3.7-R3", true) && strcmp(version, "0.3.7-R4", true))
    {
        SendClientMessage(playerid, Yellow, "Versão do SA-MP não suportada, use apartir da 0.3.7-R3");
        Kick(playerid);
        return 1;
    }
    return 1;
}
