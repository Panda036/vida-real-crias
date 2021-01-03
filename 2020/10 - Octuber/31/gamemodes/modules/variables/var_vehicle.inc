enum e_pv
{
    pv_id,
    pv_vehicle,
    pv_gasoline,
    Float:pv_km,
    Text3D:pv_label,

    //StrongCarDriver
    bool:pv_loaded,
    pv_place,
    pv_security,

    //Gari
    pv_trash,

    //Admin
    bool:pv_adm,

    //Base
    pv_base,
    pv_listvehicleid,

    //Private
    pv_slot,

    //Neon
    pv_neon1,
    pv_neon2
};

new PublicVehicle[MAX_VEHICLES][e_pv];
