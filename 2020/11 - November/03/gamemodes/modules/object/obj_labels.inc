#include YSI\y_hooks

hook OnGameModeInit()
{
    for(new pickupid = 0; pickupid < MAX_PLACE_PUBLIC; pickupid++)
    {
        CreateDynamic3DTextLabel(EnterExit[pickupid][ee_name], 0xFFFFFFFF, EnterExit[pickupid][ee_x], EnterExit[pickupid][ee_y], EnterExit[pickupid][ee_z], 30.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, WORLD_DEFAULT, 0);

        CreateDynamic3DTextLabel("Saída", 0xFFFFFFFF, EnterExit[pickupid][ee_lx], EnterExit[pickupid][ee_ly], EnterExit[pickupid][ee_lz], 30.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, WORLD_DEFAULT, EnterExit[pickupid][ee_interior]);

    }

    CreateDynamic3DTextLabel("Light", 0xFFFFFFFF, -2521.30, -623.65, 132.77, 30.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, WORLD_DEFAULT, 0);

    CreateDynamic3DTextLabel("Precione \"{1B6302}Y{FFFFFF}\"\n{FFFFFF}Para Acessar o Banco", 0xFFFFFFFF, 354.40, 164.66, 1019.98, 30.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, WORLD_DEFAULT, 3);
    CreateDynamic3DTextLabel("Precione \"{1B6302}Y{FFFFFF}\"\n{FFFFFF}Para Acessar o Banco", 0xFFFFFFFF, 356.40, 164.66, 1019.99, 30.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, WORLD_DEFAULT, 3);

    CreateDynamic3DTextLabel("Está perdido?\n\"{FF0000}/Gps{FFFFFF}{FFFFFF}\"", 0xFFFFFFFF, 826.49, -1337.05, 13.54, 30.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, WORLD_DEFAULT, 0);
    return 1;
}
