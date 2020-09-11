#include YSI\y_hooks

enum e_tdi
{
    PlayerText:tdi_name,
    PlayerText:tdi_skin,
    PlayerText:tdi_skinid,
    PlayerText:tdi_level,
    PlayerText:tdi_exp,
    PlayerText:tdi_reais,
    PlayerText:tdi_disease,
    PlayerText:tdi_vaccine,
    PlayerText:tdi_vip,
    PlayerText:tdi_health,
    PlayerText:tdi_medic_kit,
    PlayerText:tdi_nonstop,
    PlayerText:tdi_sex,
    PlayerText:tdi_money,
    PlayerText:tdi_c4,
    PlayerText:tdi_kd,
    PlayerText:tdi_warning,
    PlayerText:tdi_cnh_a,
    PlayerText:tdi_cnh_b,
    PlayerText:tdi_cnh_c,
    PlayerText:tdi_cnh_cht,
    PlayerText:tdi_cnh_arrais,
    PlayerText:tdi_email,
    PlayerText:tdi_closed
};

new Text:TDIdentity[4];
new PlayerText:TDPlayerIdentity[MAX_PLAYERS][e_tdi];
new bool:Identity[MAX_PLAYERS];

hook OnGameModeInit()
{
    TDIdentity[0] = TextDrawCreate(198.232864, 106.933273, "box");
    TextDrawLetterSize(TDIdentity[0], 0.000000, 23.198961);
    TextDrawTextSize(TDIdentity[0], 442.000000, 0.000000);
    TextDrawAlignment(TDIdentity[0], 1);
    TextDrawColor(TDIdentity[0], -1);
    TextDrawUseBox(TDIdentity[0], 1);
    TextDrawBoxColor(TDIdentity[0], -2139062172);
    TextDrawSetShadow(TDIdentity[0], 0);
    TextDrawSetOutline(TDIdentity[0], 0);
    TextDrawBackgroundColor(TDIdentity[0], 255);
    TextDrawFont(TDIdentity[0], 1);
    TextDrawSetProportional(TDIdentity[0], 1);
    TextDrawSetShadow(TDIdentity[0], 0);

    TDIdentity[1] = TextDrawCreate(200.833023, 110.033226, "box");
    TextDrawLetterSize(TDIdentity[1], 0.000000, 22.427682);
    TextDrawTextSize(TDIdentity[1], 299.600158, 0.000000);
    TextDrawAlignment(TDIdentity[1], 1);
    TextDrawColor(TDIdentity[1], -1);
    TextDrawUseBox(TDIdentity[1], 1);
    TextDrawBoxColor(TDIdentity[1], 100);
    TextDrawSetShadow(TDIdentity[1], 0);
    TextDrawSetOutline(TDIdentity[1], 0);
    TextDrawBackgroundColor(TDIdentity[1], 255);
    TextDrawFont(TDIdentity[1], 1);
    TextDrawSetProportional(TDIdentity[1], 1);
    TextDrawSetShadow(TDIdentity[1], 0);

    TDIdentity[2] = TextDrawCreate(305.470886, 110.033226, "box");
    TextDrawLetterSize(TDIdentity[2], 0.000000, 22.428682);
    TextDrawTextSize(TDIdentity[2], 439.478515, 0.000000);
    TextDrawAlignment(TDIdentity[2], 1);
    TextDrawColor(TDIdentity[2], -1);
    TextDrawUseBox(TDIdentity[2], 1);
    TextDrawBoxColor(TDIdentity[2], 100);
    TextDrawSetShadow(TDIdentity[2], 0);
    TextDrawSetOutline(TDIdentity[2], 0);
    TextDrawBackgroundColor(TDIdentity[2], 255);
    TextDrawFont(TDIdentity[2], 1);
    TextDrawSetProportional(TDIdentity[2], 1);
    TextDrawSetShadow(TDIdentity[2], 0);

    TDIdentity[3] = TextDrawCreate(438.609252, 97.783393, "Vida_Real_Crias~n~~g~Identidade");
    TextDrawLetterSize(TDIdentity[3], 0.318944, 1.710832);
    TextDrawAlignment(TDIdentity[3], 3);
    TextDrawColor(TDIdentity[3], -1);
    TextDrawSetShadow(TDIdentity[3], 0);
    TextDrawSetOutline(TDIdentity[3], 1);
    TextDrawBackgroundColor(TDIdentity[3], 255);
    TextDrawFont(TDIdentity[3], 3);
    TextDrawSetProportional(TDIdentity[3], 1);
    TextDrawSetShadow(TDIdentity[3], 0);
    return 1;
}

hook OnPlayerConnect(playerid, reason)
{
    TDPlayerIdentity[playerid][tdi_name] = CreatePlayerTextDraw(playerid, 249.238632, 127.933074, "AQUIVAISEUNOMEENTENDEU");
    PlayerTextDrawLetterSize(playerid, TDPlayerIdentity[playerid][tdi_name], 0.175577, 1.115833);
    PlayerTextDrawAlignment(playerid, TDPlayerIdentity[playerid][tdi_name], 2);
    PlayerTextDrawColor(playerid, TDPlayerIdentity[playerid][tdi_name], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_name], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerIdentity[playerid][tdi_name], 1);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerIdentity[playerid][tdi_name], 255);
    PlayerTextDrawFont(playerid, TDPlayerIdentity[playerid][tdi_name], 1);
    PlayerTextDrawSetProportional(playerid, TDPlayerIdentity[playerid][tdi_name], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_name], 0);

    TDPlayerIdentity[playerid][tdi_skin] = CreatePlayerTextDraw(playerid, 173.486282, 153.000854, "");
    PlayerTextDrawLetterSize(playerid, TDPlayerIdentity[playerid][tdi_skin], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, TDPlayerIdentity[playerid][tdi_skin], 147.000000, 142.000000);
    PlayerTextDrawAlignment(playerid, TDPlayerIdentity[playerid][tdi_skin], 1);
    PlayerTextDrawColor(playerid, TDPlayerIdentity[playerid][tdi_skin], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_skin], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerIdentity[playerid][tdi_skin], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerIdentity[playerid][tdi_skin], -256);
    PlayerTextDrawFont(playerid, TDPlayerIdentity[playerid][tdi_skin], 5);
    PlayerTextDrawSetProportional(playerid, TDPlayerIdentity[playerid][tdi_skin], 0);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_skin], 0);
    PlayerTextDrawSetPreviewModel(playerid, TDPlayerIdentity[playerid][tdi_skin], 0);
    PlayerTextDrawSetPreviewRot(playerid, TDPlayerIdentity[playerid][tdi_skin], 0.000000, 0.000000, 0.000000, 1.000000);

    TDPlayerIdentity[playerid][tdi_skinid] = CreatePlayerTextDraw(playerid, 250.856567, 139.557159, "Skin_(ID:0)");
    PlayerTextDrawLetterSize(playerid, TDPlayerIdentity[playerid][tdi_skinid], 0.214932, 1.034165);
    PlayerTextDrawAlignment(playerid, TDPlayerIdentity[playerid][tdi_skinid], 2);
    PlayerTextDrawColor(playerid, TDPlayerIdentity[playerid][tdi_skinid], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_skinid], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerIdentity[playerid][tdi_skinid], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerIdentity[playerid][tdi_skinid], 255);
    PlayerTextDrawFont(playerid, TDPlayerIdentity[playerid][tdi_skinid], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerIdentity[playerid][tdi_skinid], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_skinid], 0);

    TDPlayerIdentity[playerid][tdi_level] = CreatePlayerTextDraw(playerid, 310.146362, 123.683250, "Level:_1200");
    PlayerTextDrawLetterSize(playerid, TDPlayerIdentity[playerid][tdi_level], 0.179570, 1.141666);
    PlayerTextDrawAlignment(playerid, TDPlayerIdentity[playerid][tdi_level], 1);
    PlayerTextDrawColor(playerid, TDPlayerIdentity[playerid][tdi_level], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_level], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerIdentity[playerid][tdi_level], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerIdentity[playerid][tdi_level], 255);
    PlayerTextDrawFont(playerid, TDPlayerIdentity[playerid][tdi_level], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerIdentity[playerid][tdi_level], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_level], 0);

    TDPlayerIdentity[playerid][tdi_exp] = CreatePlayerTextDraw(playerid, 310.146362, 133.283508, "EXPERIENCIA:_4");
    PlayerTextDrawLetterSize(playerid, TDPlayerIdentity[playerid][tdi_exp], 0.179570, 1.141666);
    PlayerTextDrawAlignment(playerid, TDPlayerIdentity[playerid][tdi_exp], 1);
    PlayerTextDrawColor(playerid, TDPlayerIdentity[playerid][tdi_exp], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_exp], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerIdentity[playerid][tdi_exp], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerIdentity[playerid][tdi_exp], 255);
    PlayerTextDrawFont(playerid, TDPlayerIdentity[playerid][tdi_exp], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerIdentity[playerid][tdi_exp], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_exp], 0);

    TDPlayerIdentity[playerid][tdi_reais] = CreatePlayerTextDraw(playerid, 310.146362, 142.884094, "REAIS:_R$10,00");
    PlayerTextDrawLetterSize(playerid, TDPlayerIdentity[playerid][tdi_reais], 0.179570, 1.141666);
    PlayerTextDrawAlignment(playerid, TDPlayerIdentity[playerid][tdi_reais], 1);
    PlayerTextDrawColor(playerid, TDPlayerIdentity[playerid][tdi_reais], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_reais], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerIdentity[playerid][tdi_reais], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerIdentity[playerid][tdi_reais], 255);
    PlayerTextDrawFont(playerid, TDPlayerIdentity[playerid][tdi_reais], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerIdentity[playerid][tdi_reais], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_reais], 0);

    TDPlayerIdentity[playerid][tdi_disease] = CreatePlayerTextDraw(playerid, 310.146362, 152.584686, "DOENCA:_COVID19");
    PlayerTextDrawLetterSize(playerid, TDPlayerIdentity[playerid][tdi_disease], 0.179570, 1.141666);
    PlayerTextDrawAlignment(playerid, TDPlayerIdentity[playerid][tdi_disease], 1);
    PlayerTextDrawColor(playerid, TDPlayerIdentity[playerid][tdi_disease], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_disease], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerIdentity[playerid][tdi_disease], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerIdentity[playerid][tdi_disease], 255);
    PlayerTextDrawFont(playerid, TDPlayerIdentity[playerid][tdi_disease], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerIdentity[playerid][tdi_disease], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_disease], 0);

    TDPlayerIdentity[playerid][tdi_vaccine] = CreatePlayerTextDraw(playerid, 310.146362, 162.185272, "VACINA(S):_0");
    PlayerTextDrawLetterSize(playerid, TDPlayerIdentity[playerid][tdi_vaccine], 0.179570, 1.141666);
    PlayerTextDrawAlignment(playerid, TDPlayerIdentity[playerid][tdi_vaccine], 1);
    PlayerTextDrawColor(playerid, TDPlayerIdentity[playerid][tdi_vaccine], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_vaccine], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerIdentity[playerid][tdi_vaccine], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerIdentity[playerid][tdi_vaccine], 255);
    PlayerTextDrawFont(playerid, TDPlayerIdentity[playerid][tdi_vaccine], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerIdentity[playerid][tdi_vaccine], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_vaccine], 0);

    TDPlayerIdentity[playerid][tdi_vip] = CreatePlayerTextDraw(playerid, 310.146362, 171.285827, "VIP:_SIM");
    PlayerTextDrawLetterSize(playerid, TDPlayerIdentity[playerid][tdi_vip], 0.179570, 1.141666);
    PlayerTextDrawAlignment(playerid, TDPlayerIdentity[playerid][tdi_vip], 1);
    PlayerTextDrawColor(playerid, TDPlayerIdentity[playerid][tdi_vip], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_vip], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerIdentity[playerid][tdi_vip], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerIdentity[playerid][tdi_vip], 255);
    PlayerTextDrawFont(playerid, TDPlayerIdentity[playerid][tdi_vip], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerIdentity[playerid][tdi_vip], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_vip], 0);

    TDPlayerIdentity[playerid][tdi_health] = CreatePlayerTextDraw(playerid, 310.146362, 180.386383, "PLANO_DE_SAUDE:_NAO");
    PlayerTextDrawLetterSize(playerid, TDPlayerIdentity[playerid][tdi_health], 0.179570, 1.141666);
    PlayerTextDrawAlignment(playerid, TDPlayerIdentity[playerid][tdi_health], 1);
    PlayerTextDrawColor(playerid, TDPlayerIdentity[playerid][tdi_health], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_health], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerIdentity[playerid][tdi_health], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerIdentity[playerid][tdi_health], 255);
    PlayerTextDrawFont(playerid, TDPlayerIdentity[playerid][tdi_health], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerIdentity[playerid][tdi_health], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_health], 0);

    TDPlayerIdentity[playerid][tdi_medic_kit] = CreatePlayerTextDraw(playerid, 310.146362, 189.586944, "KIT_MEDICO(S):_0");
    PlayerTextDrawLetterSize(playerid, TDPlayerIdentity[playerid][tdi_medic_kit], 0.179570, 1.141666);
    PlayerTextDrawAlignment(playerid, TDPlayerIdentity[playerid][tdi_medic_kit], 1);
    PlayerTextDrawColor(playerid, TDPlayerIdentity[playerid][tdi_medic_kit], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_medic_kit], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerIdentity[playerid][tdi_medic_kit], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerIdentity[playerid][tdi_medic_kit], 255);
    PlayerTextDrawFont(playerid, TDPlayerIdentity[playerid][tdi_medic_kit], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerIdentity[playerid][tdi_medic_kit], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_medic_kit], 0);

    TDPlayerIdentity[playerid][tdi_nonstop] = CreatePlayerTextDraw(playerid, 310.146362, 198.487487, "SALDO_SEM_PARAR:_$3.100");
    PlayerTextDrawLetterSize(playerid, TDPlayerIdentity[playerid][tdi_nonstop], 0.179570, 1.141666);
    PlayerTextDrawAlignment(playerid, TDPlayerIdentity[playerid][tdi_nonstop], 1);
    PlayerTextDrawColor(playerid, TDPlayerIdentity[playerid][tdi_nonstop], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_nonstop], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerIdentity[playerid][tdi_nonstop], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerIdentity[playerid][tdi_nonstop], 255);
    PlayerTextDrawFont(playerid, TDPlayerIdentity[playerid][tdi_nonstop], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerIdentity[playerid][tdi_nonstop], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_nonstop], 0);

    TDPlayerIdentity[playerid][tdi_sex] = CreatePlayerTextDraw(playerid, 310.146362, 207.388031, "SEXO:_MASCULINO");
    PlayerTextDrawLetterSize(playerid, TDPlayerIdentity[playerid][tdi_sex], 0.179570, 1.141666);
    PlayerTextDrawAlignment(playerid, TDPlayerIdentity[playerid][tdi_sex], 1);
    PlayerTextDrawColor(playerid, TDPlayerIdentity[playerid][tdi_sex], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_sex], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerIdentity[playerid][tdi_sex], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerIdentity[playerid][tdi_sex], 255);
    PlayerTextDrawFont(playerid, TDPlayerIdentity[playerid][tdi_sex], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerIdentity[playerid][tdi_sex], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_sex], 0);

    TDPlayerIdentity[playerid][tdi_money] = CreatePlayerTextDraw(playerid, 310.146362, 216.488586, "DINHEIRO:_$250.400");
    PlayerTextDrawLetterSize(playerid, TDPlayerIdentity[playerid][tdi_money], 0.179570, 1.141666);
    PlayerTextDrawAlignment(playerid, TDPlayerIdentity[playerid][tdi_money], 1);
    PlayerTextDrawColor(playerid, TDPlayerIdentity[playerid][tdi_money], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_money], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerIdentity[playerid][tdi_money], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerIdentity[playerid][tdi_money], 255);
    PlayerTextDrawFont(playerid, TDPlayerIdentity[playerid][tdi_money], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerIdentity[playerid][tdi_money], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_money], 0);

    TDPlayerIdentity[playerid][tdi_c4] = CreatePlayerTextDraw(playerid, 310.146362, 225.189117, "DINAMITES:_4");
    PlayerTextDrawLetterSize(playerid, TDPlayerIdentity[playerid][tdi_c4], 0.179570, 1.141666);
    PlayerTextDrawAlignment(playerid, TDPlayerIdentity[playerid][tdi_c4], 1);
    PlayerTextDrawColor(playerid, TDPlayerIdentity[playerid][tdi_c4], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_c4], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerIdentity[playerid][tdi_c4], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerIdentity[playerid][tdi_c4], 255);
    PlayerTextDrawFont(playerid, TDPlayerIdentity[playerid][tdi_c4], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerIdentity[playerid][tdi_c4], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_c4], 0);

    TDPlayerIdentity[playerid][tdi_kd] = CreatePlayerTextDraw(playerid, 310.146362, 233.889648, "MATOU:_10000_-_MORREU:_400000");
    PlayerTextDrawLetterSize(playerid, TDPlayerIdentity[playerid][tdi_kd], 0.179570, 1.141666);
    PlayerTextDrawAlignment(playerid, TDPlayerIdentity[playerid][tdi_kd], 1);
    PlayerTextDrawColor(playerid, TDPlayerIdentity[playerid][tdi_kd], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_kd], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerIdentity[playerid][tdi_kd], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerIdentity[playerid][tdi_kd], 255);
    PlayerTextDrawFont(playerid, TDPlayerIdentity[playerid][tdi_kd], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerIdentity[playerid][tdi_kd], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_kd], 0);

    TDPlayerIdentity[playerid][tdi_warning] = CreatePlayerTextDraw(playerid, 310.146362, 242.890197, "AVISO(S):_2");
    PlayerTextDrawLetterSize(playerid, TDPlayerIdentity[playerid][tdi_warning], 0.179570, 1.141666);
    PlayerTextDrawAlignment(playerid, TDPlayerIdentity[playerid][tdi_warning], 1);
    PlayerTextDrawColor(playerid, TDPlayerIdentity[playerid][tdi_warning], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_warning], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerIdentity[playerid][tdi_warning], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerIdentity[playerid][tdi_warning], 255);
    PlayerTextDrawFont(playerid, TDPlayerIdentity[playerid][tdi_warning], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerIdentity[playerid][tdi_warning], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_warning], 0);

    TDPlayerIdentity[playerid][tdi_cnh_a] = CreatePlayerTextDraw(playerid, 310.146362, 251.990753, "CATEGORIA_A:_SIM");
    PlayerTextDrawLetterSize(playerid, TDPlayerIdentity[playerid][tdi_cnh_a], 0.180102, 1.141666);
    PlayerTextDrawAlignment(playerid, TDPlayerIdentity[playerid][tdi_cnh_a], 1);
    PlayerTextDrawColor(playerid, TDPlayerIdentity[playerid][tdi_cnh_a], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_cnh_a], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerIdentity[playerid][tdi_cnh_a], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerIdentity[playerid][tdi_cnh_a], 255);
    PlayerTextDrawFont(playerid, TDPlayerIdentity[playerid][tdi_cnh_a], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerIdentity[playerid][tdi_cnh_a], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_cnh_a], 0);

    TDPlayerIdentity[playerid][tdi_cnh_b] = CreatePlayerTextDraw(playerid, 310.146362, 260.491271, "CATEGORIA_B:_SIM");
    PlayerTextDrawLetterSize(playerid, TDPlayerIdentity[playerid][tdi_cnh_b], 0.179570, 1.141666);
    PlayerTextDrawAlignment(playerid, TDPlayerIdentity[playerid][tdi_cnh_b], 1);
    PlayerTextDrawColor(playerid, TDPlayerIdentity[playerid][tdi_cnh_b], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_cnh_b], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerIdentity[playerid][tdi_cnh_b], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerIdentity[playerid][tdi_cnh_b], 255);
    PlayerTextDrawFont(playerid, TDPlayerIdentity[playerid][tdi_cnh_b], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerIdentity[playerid][tdi_cnh_b], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_cnh_b], 0);

    TDPlayerIdentity[playerid][tdi_cnh_c] = CreatePlayerTextDraw(playerid, 310.146362, 269.891845, "CATEGORIA_C:_SIM");
    PlayerTextDrawLetterSize(playerid, TDPlayerIdentity[playerid][tdi_cnh_c], 0.179570, 1.141666);
    PlayerTextDrawAlignment(playerid, TDPlayerIdentity[playerid][tdi_cnh_c], 1);
    PlayerTextDrawColor(playerid, TDPlayerIdentity[playerid][tdi_cnh_c], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_cnh_c], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerIdentity[playerid][tdi_cnh_c], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerIdentity[playerid][tdi_cnh_c], 255);
    PlayerTextDrawFont(playerid, TDPlayerIdentity[playerid][tdi_cnh_c], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerIdentity[playerid][tdi_cnh_c], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_cnh_c], 0);

    TDPlayerIdentity[playerid][tdi_cnh_cht] = CreatePlayerTextDraw(playerid, 310.146362, 279.092407, "CHT:_SIM");
    PlayerTextDrawLetterSize(playerid, TDPlayerIdentity[playerid][tdi_cnh_cht], 0.179570, 1.141666);
    PlayerTextDrawAlignment(playerid, TDPlayerIdentity[playerid][tdi_cnh_cht], 1);
    PlayerTextDrawColor(playerid, TDPlayerIdentity[playerid][tdi_cnh_cht], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_cnh_cht], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerIdentity[playerid][tdi_cnh_cht], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerIdentity[playerid][tdi_cnh_cht], 255);
    PlayerTextDrawFont(playerid, TDPlayerIdentity[playerid][tdi_cnh_cht], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerIdentity[playerid][tdi_cnh_cht], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_cnh_cht], 0);

    TDPlayerIdentity[playerid][tdi_cnh_arrais] = CreatePlayerTextDraw(playerid, 310.146362, 288.092956, "ARRAIS:_SIM");
    PlayerTextDrawLetterSize(playerid, TDPlayerIdentity[playerid][tdi_cnh_arrais], 0.179570, 1.141666);
    PlayerTextDrawAlignment(playerid, TDPlayerIdentity[playerid][tdi_cnh_arrais], 1);
    PlayerTextDrawColor(playerid, TDPlayerIdentity[playerid][tdi_cnh_arrais], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_cnh_arrais], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerIdentity[playerid][tdi_cnh_arrais], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerIdentity[playerid][tdi_cnh_arrais], 255);
    PlayerTextDrawFont(playerid, TDPlayerIdentity[playerid][tdi_cnh_arrais], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerIdentity[playerid][tdi_cnh_arrais], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_cnh_arrais], 0);

    TDPlayerIdentity[playerid][tdi_email] = CreatePlayerTextDraw(playerid, 310.146362, 296.793487, "E-MAIL:_HENRIQUECALENZO2018@GMAIL.COM");
    PlayerTextDrawLetterSize(playerid, TDPlayerIdentity[playerid][tdi_email], 0.128032, 1.106665);
    PlayerTextDrawAlignment(playerid, TDPlayerIdentity[playerid][tdi_email], 1);
    PlayerTextDrawColor(playerid, TDPlayerIdentity[playerid][tdi_email], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_email], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerIdentity[playerid][tdi_email], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerIdentity[playerid][tdi_email], 255);
    PlayerTextDrawFont(playerid, TDPlayerIdentity[playerid][tdi_email], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerIdentity[playerid][tdi_email], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_email], 0);

    TDPlayerIdentity[playerid][tdi_closed] = CreatePlayerTextDraw(playerid, 202.112670, 110.600021, "LD_BEAT:cross");
    PlayerTextDrawLetterSize(playerid, TDPlayerIdentity[playerid][tdi_closed], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, TDPlayerIdentity[playerid][tdi_closed], 9.009930, 9.009907);
    PlayerTextDrawAlignment(playerid, TDPlayerIdentity[playerid][tdi_closed], 1);
    PlayerTextDrawColor(playerid, TDPlayerIdentity[playerid][tdi_closed], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_closed], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerIdentity[playerid][tdi_closed], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerIdentity[playerid][tdi_closed], 255);
    PlayerTextDrawFont(playerid, TDPlayerIdentity[playerid][tdi_closed], 4);
    PlayerTextDrawSetProportional(playerid, TDPlayerIdentity[playerid][tdi_closed], 0);
    PlayerTextDrawSetShadow(playerid, TDPlayerIdentity[playerid][tdi_closed], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerIdentity[playerid][tdi_closed], true);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    Identity[playerid] = false;
    return 1;
}

stock ShowTDPlayerIdentity(playerid)
{
    Identity[playerid] = true;
    SelectTextDraw(playerid, Green);

    TextDrawShowForPlayer(playerid, TDIdentity[0]);
    TextDrawShowForPlayer(playerid, TDIdentity[1]);
    TextDrawShowForPlayer(playerid, TDIdentity[2]);
    TextDrawShowForPlayer(playerid, TDIdentity[3]);

    PlayerTextDrawShow(playerid, TDPlayerIdentity[playerid][tdi_name]);
    PlayerTextDrawShow(playerid, TDPlayerIdentity[playerid][tdi_skin]);
    PlayerTextDrawShow(playerid, TDPlayerIdentity[playerid][tdi_skinid]);
    PlayerTextDrawShow(playerid, TDPlayerIdentity[playerid][tdi_level]);
    PlayerTextDrawShow(playerid, TDPlayerIdentity[playerid][tdi_exp]);
    PlayerTextDrawShow(playerid, TDPlayerIdentity[playerid][tdi_reais]);
    PlayerTextDrawShow(playerid, TDPlayerIdentity[playerid][tdi_disease]);
    PlayerTextDrawShow(playerid, TDPlayerIdentity[playerid][tdi_vaccine]);
    PlayerTextDrawShow(playerid, TDPlayerIdentity[playerid][tdi_vip]);
    PlayerTextDrawShow(playerid, TDPlayerIdentity[playerid][tdi_health]);
    PlayerTextDrawShow(playerid, TDPlayerIdentity[playerid][tdi_medic_kit]);
    PlayerTextDrawShow(playerid, TDPlayerIdentity[playerid][tdi_nonstop]);
    PlayerTextDrawShow(playerid, TDPlayerIdentity[playerid][tdi_sex]);
    PlayerTextDrawShow(playerid, TDPlayerIdentity[playerid][tdi_money]);
    PlayerTextDrawShow(playerid, TDPlayerIdentity[playerid][tdi_c4]);
    PlayerTextDrawShow(playerid, TDPlayerIdentity[playerid][tdi_kd]);
    PlayerTextDrawShow(playerid, TDPlayerIdentity[playerid][tdi_warning]);
    PlayerTextDrawShow(playerid, TDPlayerIdentity[playerid][tdi_cnh_a]);
    PlayerTextDrawShow(playerid, TDPlayerIdentity[playerid][tdi_cnh_b]);
    PlayerTextDrawShow(playerid, TDPlayerIdentity[playerid][tdi_cnh_c]);
    PlayerTextDrawShow(playerid, TDPlayerIdentity[playerid][tdi_cnh_cht]);
    PlayerTextDrawShow(playerid, TDPlayerIdentity[playerid][tdi_cnh_arrais]);
    PlayerTextDrawShow(playerid, TDPlayerIdentity[playerid][tdi_email]);
    PlayerTextDrawShow(playerid, TDPlayerIdentity[playerid][tdi_closed]);
    return 1;
}

stock HideTDPlayerIdentity(playerid)
{
    Identity[playerid] = false;
    CancelSelectTextDraw(playerid);

    TextDrawHideForPlayer(playerid, TDIdentity[0]);
    TextDrawHideForPlayer(playerid, TDIdentity[1]);
    TextDrawHideForPlayer(playerid, TDIdentity[2]);
    TextDrawHideForPlayer(playerid, TDIdentity[3]);

    PlayerTextDrawHide(playerid, TDPlayerIdentity[playerid][tdi_name]);
    PlayerTextDrawHide(playerid, TDPlayerIdentity[playerid][tdi_skin]);
    PlayerTextDrawHide(playerid, TDPlayerIdentity[playerid][tdi_skinid]);
    PlayerTextDrawHide(playerid, TDPlayerIdentity[playerid][tdi_level]);
    PlayerTextDrawHide(playerid, TDPlayerIdentity[playerid][tdi_exp]);
    PlayerTextDrawHide(playerid, TDPlayerIdentity[playerid][tdi_reais]);
    PlayerTextDrawHide(playerid, TDPlayerIdentity[playerid][tdi_disease]);
    PlayerTextDrawHide(playerid, TDPlayerIdentity[playerid][tdi_vaccine]);
    PlayerTextDrawHide(playerid, TDPlayerIdentity[playerid][tdi_vip]);
    PlayerTextDrawHide(playerid, TDPlayerIdentity[playerid][tdi_health]);
    PlayerTextDrawHide(playerid, TDPlayerIdentity[playerid][tdi_medic_kit]);
    PlayerTextDrawHide(playerid, TDPlayerIdentity[playerid][tdi_nonstop]);
    PlayerTextDrawHide(playerid, TDPlayerIdentity[playerid][tdi_sex]);
    PlayerTextDrawHide(playerid, TDPlayerIdentity[playerid][tdi_money]);
    PlayerTextDrawHide(playerid, TDPlayerIdentity[playerid][tdi_c4]);
    PlayerTextDrawHide(playerid, TDPlayerIdentity[playerid][tdi_kd]);
    PlayerTextDrawHide(playerid, TDPlayerIdentity[playerid][tdi_warning]);
    PlayerTextDrawHide(playerid, TDPlayerIdentity[playerid][tdi_cnh_a]);
    PlayerTextDrawHide(playerid, TDPlayerIdentity[playerid][tdi_cnh_b]);
    PlayerTextDrawHide(playerid, TDPlayerIdentity[playerid][tdi_cnh_c]);
    PlayerTextDrawHide(playerid, TDPlayerIdentity[playerid][tdi_cnh_cht]);
    PlayerTextDrawHide(playerid, TDPlayerIdentity[playerid][tdi_cnh_arrais]);
    PlayerTextDrawHide(playerid, TDPlayerIdentity[playerid][tdi_email]);
    PlayerTextDrawHide(playerid, TDPlayerIdentity[playerid][tdi_closed]);
    return 1;
}
