enum hInfo
{
    hID,
    hNome[MAX_PLAYER_NAME],
    hM1[MAX_PLAYER_NAME],
    hM2[MAX_PLAYER_NAME],
    hM3[MAX_PLAYER_NAME],
    hM4[MAX_PLAYER_NAME],
    hM5[MAX_PLAYER_NAME],
    hM6[MAX_PLAYER_NAME],
    hMensagem[30],
    hAlugando[5],
    hVendendo[5],
    hUp,
    hUpMax,
    hPreco,
    hCusto,
    hReais,
    hPadrao,
    hCofre,
    hInterior,
    hTrancada[5],
    hSenha[24],
    Float:iconx,
    Float:icony,
    Float:iconz,
    Float:hInteriorX,
    Float:hInteriorY,
    Float:hInteriorZ,
    hResidents,

    Text3D:hLabel,
    hPickup,
    hMap,

    //Sweet System
    bool:hSweet,
    hPumpkin
}

new HouseInfo[MAX_HOUSES][hInfo];

new LastHouseID[MAX_PLAYERS];
new dentrocasa[MAX_PLAYERS];
new HouseContinueTimer[MAX_PLAYERS];
new bool:HouseContinue[MAX_PLAYERS];
new listidUpDown[MAX_PLAYERS];
