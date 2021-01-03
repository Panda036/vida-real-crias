enum pInfo
{
    ID,
    Profissao,
    Semprofissao,
    Nome[MAX_PLAYER_NAME],
    Senha[MAX_PLAYER_PASS],
    Email[MAX_PLAYER_EMAIL],
    Code[10],
    Admin,
    minUP,
    segUP,
    Level,
    Exp,
    Reais,
    Estrelas,
    Dinheiro,
    Float:Health,
    SaldoBancario,
    Matou,
    Morreu,
    Interior,
    tutorial,
    lastlogin,
    Float:PosX,
    Float:PosY,
    Float:PosZ,
    Float:PosA,
    bool:Logado,
    bool:load,
    bool:frozen,

    fines_a,
    fines_b,
    fines_c,
    fines_cht,
    fines_arrais,

    sexo,
    skin,
    bool:healthplan,
    disease,

    medicalkit,
    cellphone,
    sms,
    credits,
    bool:havegallon,
    gallon,
    nonstop,
    vaccine,
    cannabis,
    bag,
    c4,
    active,
    kitrepair,
    jetpackgas,

    youtube,

    t_timeburglar,
    t_burglarbox,
    t_transaction,
    t_transactionbox,

    hud_backcolor[7],
    hud_color[7],
    hud_fontcolor[7],

    bool:pds_in,
    pds_type[10],
    pds_vehicleid,

    bool:blockDoubt,
    bool:blockReport,
    bool:blockAd
};

enum ppInfo
{
    pNome[MAX_PLAYER_NAME],
    pSenha[MAX_PLAYER_PASS],
    pSenhaConfirm[MAX_PLAYER_PASS],
    pEmail[MAX_PLAYER_EMAIL]
};

new pPlayerInfo[MAX_PLAYERS][ppInfo];
new PlayerInfo[MAX_PLAYERS][pInfo];
