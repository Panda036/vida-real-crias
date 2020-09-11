#include YSI\y_hooks

enum attached_object_data
{
    bool:ao_connected,
    ao_model,
    ao_value,
    ao_bone,
    Float:ao_x,
    Float:ao_y,
    Float:ao_z,
    Float:ao_rx,
    Float:ao_ry,
    Float:ao_rz,
    Float:ao_sx,
    Float:ao_sy,
    Float:ao_sz
}

new ao[MAX_PLAYERS][MAX_PLAYER_ATTACHED_OBJECTS][attached_object_data];

hook OnPlayerDisconnect(playerid, reason)
{
    for(new slot = 0; slot < MAX_PLAYER_ATTACHED_OBJECTS; slot++)
    {
        if(ao[playerid][slot][ao_connected]) RemovePlayerAttachedObject(playerid, slot);

        ao[playerid][slot][ao_connected] = false;
        ao[playerid][slot][ao_model] = 0;
        ao[playerid][slot][ao_bone] = 0;
        ao[playerid][slot][ao_x] = 0;
        ao[playerid][slot][ao_y] = 0;
        ao[playerid][slot][ao_z] = 0;
        ao[playerid][slot][ao_rx] = 0;
        ao[playerid][slot][ao_ry] = 0;
        ao[playerid][slot][ao_rz] = 0;
        ao[playerid][slot][ao_sx] = 0;
        ao[playerid][slot][ao_sy] = 0;
        ao[playerid][slot][ao_sz] = 0;
    }
    return 1;
}

/*
public OnPlayerEditAttachedObject(playerid, response, index, modelid, boneid, Float:fOffsetX, Float:fOffsetY, Float:fOffsetZ, Float:fRotX, Float:fRotY, Float:fRotZ, Float:fScaleX, Float:fScaleY, Float:fScaleZ)
{
    return 0;
}
*/
