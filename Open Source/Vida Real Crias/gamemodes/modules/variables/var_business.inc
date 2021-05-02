enum cInfo
{
    cID,
    cName[MAX_PLAYER_NAME],
    cEmployee1[MAX_PLAYER_NAME],
    cEmployee2[MAX_PLAYER_NAME],
    cEmployee3[MAX_PLAYER_NAME],
    cEmployee4[MAX_PLAYER_NAME],
    cDeliveries,
    cEDeliveries1,
    cEDeliveries2,
    cEDeliveries3,
    cEDeliveries4,
    cStatus[30],
    cMessage[30],
    cSelling[5],
    cPrice,
    cCost,
    cStandard,
    cSafe,
    cInterior,
    cIcon,
    cProduction,
    Float:cIconX,
    Float:cIconY,
    Float:cIconZ,
    Float:cInteriorX,
    Float:cInteriorY,
    Float:cInteriorZ,
    cEmployee
}

new BusinessInfo[MAX_BUSINESS][cInfo];
new Text3D:CompanyLabel[MAX_BUSINESS];
new CompanyMapIcon[MAX_BUSINESS];
new CompanyPickup[MAX_BUSINESS];

new withinbusiness[MAX_PLAYERS];
new idbusiness[MAX_PLAYERS];

new bool:Mercadoria[MAX_PLAYERS];
new bool:EntregouMercadoria[MAX_PLAYERS];
