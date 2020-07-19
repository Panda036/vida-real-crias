#include YSI\y_hooks

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER)
    {
        switch(GetPlayerWeapon(playerid))
        {
            case 24..27: SetPlayerArmedWeapon(playerid, 0); //Proibindo algumas armas db
        }
    }
    return 1;
}
