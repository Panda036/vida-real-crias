#include YSI\y_hooks

#define check_system                    1
#define name_login                      2
#define pass_login                      3
#define name_register                   4
#define pass_register                   5
#define pass_register_confirm           6
#define email_register                  7
#define sexo_register                   8
#define recover_account                 9
#define recover_account_pass            10
#define recover_account_pass_ok         11

#define cell_login_name                 12
#define cell_login_pass                 13
#define cell_register_name              14
#define cell_register_pass              15
#define cell_register_email             16
#define cell_register_sexo              17

#define DEFAULT_SKIN_BOY                97
#define DEFAULT_SKIN_GIRL               93

new Text:TDLogin[28];
new PlayerText:TDPlayerLogin[MAX_PLAYERS][5];
new Text:TDRegister[39];
new PlayerText:TDPlayerRegister[MAX_PLAYERS][6];
new t_login[MAX_PLAYERS];

hook OnGameModeInit()
{
    TDLogin[0] = TextDrawCreate(247.100860, 92.177764, "box");
    TextDrawLetterSize(TDLogin[0], 0.000000, 24.849990);
    TextDrawTextSize(TDLogin[0], 392.000000, 0.000000);
    TextDrawAlignment(TDLogin[0], 1);
    TextDrawColor(TDLogin[0], -1);
    TextDrawUseBox(TDLogin[0], 1);
    TextDrawBoxColor(TDLogin[0], 100);
    TextDrawSetShadow(TDLogin[0], 0);
    TextDrawSetOutline(TDLogin[0], 0);
    TextDrawBackgroundColor(TDLogin[0], 255);
    TextDrawFont(TDLogin[0], 1);
    TextDrawSetProportional(TDLogin[0], 1);
    TextDrawSetShadow(TDLogin[0], 0);

    TDLogin[1] = TextDrawCreate(262.000000, 145.866668, "ld_pool:ball");
    TextDrawLetterSize(TDLogin[1], 0.000000, 0.000000);
    TextDrawTextSize(TDLogin[1], 25.000000, 26.000000);
    TextDrawAlignment(TDLogin[1], 1);
    TextDrawColor(TDLogin[1], -92724737);
    TextDrawSetShadow(TDLogin[1], 0);
    TextDrawSetOutline(TDLogin[1], 0);
    TextDrawBackgroundColor(TDLogin[1], 255);
    TextDrawFont(TDLogin[1], 4);
    TextDrawSetProportional(TDLogin[1], 0);
    TextDrawSetShadow(TDLogin[1], 0);

    TDLogin[2] = TextDrawCreate(349.605346, 145.866668, "ld_pool:ball");
    TextDrawLetterSize(TDLogin[2], 0.000000, 0.000000);
    TextDrawTextSize(TDLogin[2], 25.000000, 26.000000);
    TextDrawAlignment(TDLogin[2], 1);
    TextDrawColor(TDLogin[2], -92724737);
    TextDrawSetShadow(TDLogin[2], 0);
    TextDrawSetOutline(TDLogin[2], 0);
    TextDrawBackgroundColor(TDLogin[2], 255);
    TextDrawFont(TDLogin[2], 4);
    TextDrawSetProportional(TDLogin[2], 0);
    TextDrawSetShadow(TDLogin[2], 0);

    TDLogin[3] = TextDrawCreate(276.100036, 149.133300, "box");
    TextDrawLetterSize(TDLogin[3], 0.000000, 2.162992);
    TextDrawTextSize(TDLogin[3], 362.000000, 0.000000);
    TextDrawAlignment(TDLogin[3], 1);
    TextDrawColor(TDLogin[3], -1);
    TextDrawUseBox(TDLogin[3], 1);
    TextDrawBoxColor(TDLogin[3], -92724737);
    TextDrawSetShadow(TDLogin[3], 0);
    TextDrawSetOutline(TDLogin[3], 0);
    TextDrawBackgroundColor(TDLogin[3], 255);
    TextDrawFont(TDLogin[3], 1);
    TextDrawSetProportional(TDLogin[3], 1);
    TextDrawSetShadow(TDLogin[3], 0);

    TDLogin[4] = TextDrawCreate(264.200134, 147.544586, "ld_pool:ball");
    TextDrawLetterSize(TDLogin[4], 0.000000, 0.000000);
    TextDrawTextSize(TDLogin[4], 22.739948, 22.069910);
    TextDrawAlignment(TDLogin[4], 1);
    TextDrawColor(TDLogin[4], 255);
    TextDrawSetShadow(TDLogin[4], 0);
    TextDrawSetOutline(TDLogin[4], 0);
    TextDrawBackgroundColor(TDLogin[4], 255);
    TextDrawFont(TDLogin[4], 4);
    TextDrawSetProportional(TDLogin[4], 0);
    TextDrawSetShadow(TDLogin[4], 0);

    TDLogin[5] = TextDrawCreate(350.105377, 147.544586, "ld_pool:ball");
    TextDrawLetterSize(TDLogin[5], 0.000000, 0.000000);
    TextDrawTextSize(TDLogin[5], 22.739948, 22.069910);
    TextDrawAlignment(TDLogin[5], 1);
    TextDrawColor(TDLogin[5], 255);
    TextDrawSetShadow(TDLogin[5], 0);
    TextDrawSetOutline(TDLogin[5], 0);
    TextDrawBackgroundColor(TDLogin[5], 255);
    TextDrawFont(TDLogin[5], 4);
    TextDrawSetProportional(TDLogin[5], 0);
    TextDrawSetShadow(TDLogin[5], 0);

    TDLogin[6] = TextDrawCreate(276.100036, 150.433380, "box");
    TextDrawLetterSize(TDLogin[6], 0.000000, 1.837996);
    TextDrawTextSize(TDLogin[6], 362.000000, 0.000000);
    TextDrawAlignment(TDLogin[6], 1);
    TextDrawColor(TDLogin[6], -1);
    TextDrawUseBox(TDLogin[6], 1);
    TextDrawBoxColor(TDLogin[6], 255);
    TextDrawSetShadow(TDLogin[6], 0);
    TextDrawSetOutline(TDLogin[6], 0);
    TextDrawBackgroundColor(TDLogin[6], 255);
    TextDrawFont(TDLogin[6], 1);
    TextDrawSetProportional(TDLogin[6], 1);
    TextDrawSetShadow(TDLogin[6], 0);

    TDLogin[7] = TextDrawCreate(261.500000, 192.969543, "ld_pool:ball");
    TextDrawLetterSize(TDLogin[7], 0.000000, 0.000000);
    TextDrawTextSize(TDLogin[7], 25.000000, 26.000000);
    TextDrawAlignment(TDLogin[7], 1);
    TextDrawColor(TDLogin[7], -92724737);
    TextDrawSetShadow(TDLogin[7], 0);
    TextDrawSetOutline(TDLogin[7], 0);
    TextDrawBackgroundColor(TDLogin[7], 255);
    TextDrawFont(TDLogin[7], 4);
    TextDrawSetProportional(TDLogin[7], 0);
    TextDrawSetShadow(TDLogin[7], 0);

    TDLogin[8] = TextDrawCreate(349.605346, 192.969543, "ld_pool:ball");
    TextDrawLetterSize(TDLogin[8], 0.000000, 0.000000);
    TextDrawTextSize(TDLogin[8], 25.000000, 25.509988);
    TextDrawAlignment(TDLogin[8], 1);
    TextDrawColor(TDLogin[8], -92724737);
    TextDrawSetShadow(TDLogin[8], 0);
    TextDrawSetOutline(TDLogin[8], 0);
    TextDrawBackgroundColor(TDLogin[8], 255);
    TextDrawFont(TDLogin[8], 4);
    TextDrawSetProportional(TDLogin[8], 0);
    TextDrawSetShadow(TDLogin[8], 0);

    TDLogin[9] = TextDrawCreate(276.100036, 195.958343, "box");
    TextDrawLetterSize(TDLogin[9], 0.000000, 2.146992);
    TextDrawTextSize(TDLogin[9], 362.000000, 0.000000);
    TextDrawAlignment(TDLogin[9], 1);
    TextDrawColor(TDLogin[9], -1);
    TextDrawUseBox(TDLogin[9], 1);
    TextDrawBoxColor(TDLogin[9], -92724737);
    TextDrawSetShadow(TDLogin[9], 0);
    TextDrawSetOutline(TDLogin[9], 0);
    TextDrawBackgroundColor(TDLogin[9], 255);
    TextDrawFont(TDLogin[9], 1);
    TextDrawSetProportional(TDLogin[9], 1);
    TextDrawSetShadow(TDLogin[9], 0);

    TDLogin[10] = TextDrawCreate(263.100067, 194.569641, "ld_pool:ball");
    TextDrawLetterSize(TDLogin[10], 0.000000, 0.000000);
    TextDrawTextSize(TDLogin[10], 22.739948, 22.069910);
    TextDrawAlignment(TDLogin[10], 1);
    TextDrawColor(TDLogin[10], 255);
    TextDrawSetShadow(TDLogin[10], 0);
    TextDrawSetOutline(TDLogin[10], 0);
    TextDrawBackgroundColor(TDLogin[10], 255);
    TextDrawFont(TDLogin[10], 4);
    TextDrawSetProportional(TDLogin[10], 0);
    TextDrawSetShadow(TDLogin[10], 0);

    TDLogin[11] = TextDrawCreate(350.105377, 194.447448, "ld_pool:ball");
    TextDrawLetterSize(TDLogin[11], 0.000000, 0.000000);
    TextDrawTextSize(TDLogin[11], 22.739948, 22.069910);
    TextDrawAlignment(TDLogin[11], 1);
    TextDrawColor(TDLogin[11], 255);
    TextDrawSetShadow(TDLogin[11], 0);
    TextDrawSetOutline(TDLogin[11], 0);
    TextDrawBackgroundColor(TDLogin[11], 255);
    TextDrawFont(TDLogin[11], 4);
    TextDrawSetProportional(TDLogin[11], 0);
    TextDrawSetShadow(TDLogin[11], 0);

    TDLogin[12] = TextDrawCreate(276.100036, 197.136230, "box");
    TextDrawLetterSize(TDLogin[12], 0.000000, 1.837996);
    TextDrawTextSize(TDLogin[12], 362.000000, 0.000000);
    TextDrawAlignment(TDLogin[12], 1);
    TextDrawColor(TDLogin[12], -1);
    TextDrawUseBox(TDLogin[12], 1);
    TextDrawBoxColor(TDLogin[12], 255);
    TextDrawSetShadow(TDLogin[12], 0);
    TextDrawSetOutline(TDLogin[12], 0);
    TextDrawBackgroundColor(TDLogin[12], 255);
    TextDrawFont(TDLogin[12], 1);
    TextDrawSetProportional(TDLogin[12], 1);
    TextDrawSetShadow(TDLogin[12], 0);

    TDLogin[13] = TextDrawCreate(261.500000, 235.472137, "ld_pool:ball");
    TextDrawLetterSize(TDLogin[13], 0.000000, 0.000000);
    TextDrawTextSize(TDLogin[13], 25.000000, 27.000000);
    TextDrawAlignment(TDLogin[13], 1);
    TextDrawColor(TDLogin[13], -16776961);
    TextDrawSetShadow(TDLogin[13], 0);
    TextDrawSetOutline(TDLogin[13], 0);
    TextDrawBackgroundColor(TDLogin[13], 255);
    TextDrawFont(TDLogin[13], 4);
    TextDrawSetProportional(TDLogin[13], 0);
    TextDrawSetShadow(TDLogin[13], 0);

    TDLogin[14] = TextDrawCreate(290.301757, 235.372131, "ld_pool:ball");
    TextDrawLetterSize(TDLogin[14], 0.000000, 0.000000);
    TextDrawTextSize(TDLogin[14], 25.000000, 27.000000);
    TextDrawAlignment(TDLogin[14], 1);
    TextDrawColor(TDLogin[14], -16776961);
    TextDrawSetShadow(TDLogin[14], 0);
    TextDrawSetOutline(TDLogin[14], 0);
    TextDrawBackgroundColor(TDLogin[14], 255);
    TextDrawFont(TDLogin[14], 4);
    TextDrawSetProportional(TDLogin[14], 0);
    TextDrawSetShadow(TDLogin[14], 0);

    TDLogin[15] = TextDrawCreate(276.498352, 237.949310, "box");
    TextDrawLetterSize(TDLogin[15], 0.000000, 2.360996);
    TextDrawTextSize(TDLogin[15], 300.594604, 0.000000);
    TextDrawAlignment(TDLogin[15], 1);
    TextDrawColor(TDLogin[15], -1);
    TextDrawUseBox(TDLogin[15], 1);
    TextDrawBoxColor(TDLogin[15], -16776961);
    TextDrawSetShadow(TDLogin[15], 0);
    TextDrawSetOutline(TDLogin[15], 0);
    TextDrawBackgroundColor(TDLogin[15], 255);
    TextDrawFont(TDLogin[15], 1);
    TextDrawSetProportional(TDLogin[15], 1);
    TextDrawSetShadow(TDLogin[15], 0);

    TDLogin[16] = TextDrawCreate(263.698486, 237.837158, "ld_pool:ball");
    TextDrawLetterSize(TDLogin[16], 0.000000, 0.000000);
    TextDrawTextSize(TDLogin[16], 22.739948, 22.069910);
    TextDrawAlignment(TDLogin[16], 1);
    TextDrawColor(TDLogin[16], 255);
    TextDrawSetShadow(TDLogin[16], 0);
    TextDrawSetOutline(TDLogin[16], 0);
    TextDrawBackgroundColor(TDLogin[16], 255);
    TextDrawFont(TDLogin[16], 4);
    TextDrawSetProportional(TDLogin[16], 0);
    TextDrawSetShadow(TDLogin[16], 0);

    TDLogin[17] = TextDrawCreate(290.500091, 237.981536, "ld_pool:ball");
    TextDrawLetterSize(TDLogin[17], 0.000000, 0.000000);
    TextDrawTextSize(TDLogin[17], 22.739948, 22.069910);
    TextDrawAlignment(TDLogin[17], 1);
    TextDrawColor(TDLogin[17], 255);
    TextDrawSetShadow(TDLogin[17], 0);
    TextDrawSetOutline(TDLogin[17], 0);
    TextDrawBackgroundColor(TDLogin[17], 255);
    TextDrawFont(TDLogin[17], 4);
    TextDrawSetProportional(TDLogin[17], 0);
    TextDrawSetShadow(TDLogin[17], 0);

    TDLogin[18] = TextDrawCreate(277.998443, 240.327270, "box");
    TextDrawLetterSize(TDLogin[18], 0.000000, 1.903010);
    TextDrawTextSize(TDLogin[18], 298.541809, 0.000000);
    TextDrawAlignment(TDLogin[18], 1);
    TextDrawColor(TDLogin[18], -1);
    TextDrawUseBox(TDLogin[18], 1);
    TextDrawBoxColor(TDLogin[18], 255);
    TextDrawSetShadow(TDLogin[18], 0);
    TextDrawSetOutline(TDLogin[18], 0);
    TextDrawBackgroundColor(TDLogin[18], 255);
    TextDrawFont(TDLogin[18], 1);
    TextDrawSetProportional(TDLogin[18], 1);
    TextDrawSetShadow(TDLogin[18], 0);

    TDLogin[19] = TextDrawCreate(321.603698, 235.772155, "ld_pool:ball");
    TextDrawLetterSize(TDLogin[19], 0.000000, 0.000000);
    TextDrawTextSize(TDLogin[19], 25.000000, 27.000000);
    TextDrawAlignment(TDLogin[19], 1);
    TextDrawColor(TDLogin[19], -1378294017);
    TextDrawSetShadow(TDLogin[19], 0);
    TextDrawSetOutline(TDLogin[19], 0);
    TextDrawBackgroundColor(TDLogin[19], 255);
    TextDrawFont(TDLogin[19], 4);
    TextDrawSetProportional(TDLogin[19], 0);
    TextDrawSetShadow(TDLogin[19], 0);

    TDLogin[20] = TextDrawCreate(348.105316, 235.872161, "ld_pool:ball");
    TextDrawLetterSize(TDLogin[20], 0.000000, 0.000000);
    TextDrawTextSize(TDLogin[20], 25.000000, 27.000000);
    TextDrawAlignment(TDLogin[20], 1);
    TextDrawColor(TDLogin[20], -1378294017);
    TextDrawSetShadow(TDLogin[20], 0);
    TextDrawSetOutline(TDLogin[20], 0);
    TextDrawBackgroundColor(TDLogin[20], 255);
    TextDrawFont(TDLogin[20], 4);
    TextDrawSetProportional(TDLogin[20], 0);
    TextDrawSetShadow(TDLogin[20], 0);

    TDLogin[21] = TextDrawCreate(334.601867, 238.471527, "box");
    TextDrawLetterSize(TDLogin[21], 0.000000, 2.332998);
    TextDrawTextSize(TDLogin[21], 360.000000, 0.000000);
    TextDrawAlignment(TDLogin[21], 1);
    TextDrawColor(TDLogin[21], -1);
    TextDrawUseBox(TDLogin[21], 1);
    TextDrawBoxColor(TDLogin[21], -1378294017);
    TextDrawSetShadow(TDLogin[21], 0);
    TextDrawSetOutline(TDLogin[21], 0);
    TextDrawBackgroundColor(TDLogin[21], 255);
    TextDrawFont(TDLogin[21], 1);
    TextDrawSetProportional(TDLogin[21], 1);
    TextDrawSetShadow(TDLogin[21], 0);

    TDLogin[22] = TextDrawCreate(323.902160, 238.137176, "ld_pool:ball");
    TextDrawLetterSize(TDLogin[22], 0.000000, 0.000000);
    TextDrawTextSize(TDLogin[22], 22.739948, 22.069910);
    TextDrawAlignment(TDLogin[22], 1);
    TextDrawColor(TDLogin[22], 255);
    TextDrawSetShadow(TDLogin[22], 0);
    TextDrawSetOutline(TDLogin[22], 0);
    TextDrawBackgroundColor(TDLogin[22], 255);
    TextDrawFont(TDLogin[22], 4);
    TextDrawSetProportional(TDLogin[22], 0);
    TextDrawSetShadow(TDLogin[22], 0);

    TDLogin[23] = TextDrawCreate(348.403656, 238.637207, "ld_pool:ball");
    TextDrawLetterSize(TDLogin[23], 0.000000, 0.000000);
    TextDrawTextSize(TDLogin[23], 22.739948, 22.069910);
    TextDrawAlignment(TDLogin[23], 1);
    TextDrawColor(TDLogin[23], 255);
    TextDrawSetShadow(TDLogin[23], 0);
    TextDrawSetOutline(TDLogin[23], 0);
    TextDrawBackgroundColor(TDLogin[23], 255);
    TextDrawFont(TDLogin[23], 4);
    TextDrawSetProportional(TDLogin[23], 0);
    TextDrawSetShadow(TDLogin[23], 0);

    TDLogin[24] = TextDrawCreate(336.201995, 240.949493, "box");
    TextDrawLetterSize(TDLogin[24], 0.000000, 1.903010);
    TextDrawTextSize(TDLogin[24], 357.000000, 0.000000);
    TextDrawAlignment(TDLogin[24], 1);
    TextDrawColor(TDLogin[24], -1);
    TextDrawUseBox(TDLogin[24], 1);
    TextDrawBoxColor(TDLogin[24], 255);
    TextDrawSetShadow(TDLogin[24], 0);
    TextDrawSetOutline(TDLogin[24], 0);
    TextDrawBackgroundColor(TDLogin[24], 255);
    TextDrawFont(TDLogin[24], 1);
    TextDrawSetProportional(TDLogin[24], 1);
    TextDrawSetShadow(TDLogin[24], 0);

    TDLogin[25] = TextDrawCreate(259.000000, 299.511169, "Nao_tem_conta?");
    TextDrawLetterSize(TDLogin[25], 0.224500, 1.214221);
    TextDrawAlignment(TDLogin[25], 1);
    TextDrawColor(TDLogin[25], -1);
    TextDrawSetShadow(TDLogin[25], 0);
    TextDrawSetOutline(TDLogin[25], -1);
    TextDrawBackgroundColor(TDLogin[25], 255);
    TextDrawFont(TDLogin[25], 1);
    TextDrawSetProportional(TDLogin[25], 1);
    TextDrawSetShadow(TDLogin[25], 0);

    TDLogin[26] = TextDrawCreate(264.500000, 100.255195, "VIDA_REAL_CRIAS");
    TextDrawLetterSize(TDLogin[26], 0.400000, 1.600000);
    TextDrawAlignment(TDLogin[26], 1);
    TextDrawColor(TDLogin[26], -5963521);
    TextDrawSetShadow(TDLogin[26], -1);
    TextDrawSetOutline(TDLogin[26], 1);
    TextDrawBackgroundColor(TDLogin[26], 255);
    TextDrawFont(TDLogin[26], 3);
    TextDrawSetProportional(TDLogin[26], 1);
    TextDrawSetShadow(TDLogin[26], -1);

    TDLogin[27] = TextDrawCreate(301.598724, 115.366539, "Copyright_2020_-_RPG");
    TextDrawLetterSize(TDLogin[27], 0.180500, 0.834664);
    TextDrawAlignment(TDLogin[27], 1);
    TextDrawColor(TDLogin[27], -1);
    TextDrawSetShadow(TDLogin[27], 0);
    TextDrawSetOutline(TDLogin[27], 1);
    TextDrawBackgroundColor(TDLogin[27], 255);
    TextDrawFont(TDLogin[27], 1);
    TextDrawSetProportional(TDLogin[27], 1);
    TextDrawSetShadow(TDLogin[27], 0);

    TDRegister[0] = TextDrawCreate(247.100860, 92.177764, "box");
    TextDrawLetterSize(TDRegister[0], 0.000000, 24.849990);
    TextDrawTextSize(TDRegister[0], 392.000000, 0.000000);
    TextDrawAlignment(TDRegister[0], 1);
    TextDrawColor(TDRegister[0], -1);
    TextDrawUseBox(TDRegister[0], 1);
    TextDrawBoxColor(TDRegister[0], 100);
    TextDrawSetShadow(TDRegister[0], 0);
    TextDrawSetOutline(TDRegister[0], 0);
    TextDrawBackgroundColor(TDRegister[0], 255);
    TextDrawFont(TDRegister[0], 1);
    TextDrawSetProportional(TDRegister[0], 1);
    TextDrawSetShadow(TDRegister[0], 0);

    TDRegister[1] = TextDrawCreate(262.000000, 145.866668, "ld_pool:ball");
    TextDrawLetterSize(TDRegister[1], 0.000000, 0.000000);
    TextDrawTextSize(TDRegister[1], 25.000000, 26.000000);
    TextDrawAlignment(TDRegister[1], 1);
    TextDrawColor(TDRegister[1], -92724737);
    TextDrawSetShadow(TDRegister[1], 0);
    TextDrawSetOutline(TDRegister[1], 0);
    TextDrawBackgroundColor(TDRegister[1], 255);
    TextDrawFont(TDRegister[1], 4);
    TextDrawSetProportional(TDRegister[1], 0);
    TextDrawSetShadow(TDRegister[1], 0);

    TDRegister[2] = TextDrawCreate(349.605346, 145.866668, "ld_pool:ball");
    TextDrawLetterSize(TDRegister[2], 0.000000, 0.000000);
    TextDrawTextSize(TDRegister[2], 25.000000, 26.000000);
    TextDrawAlignment(TDRegister[2], 1);
    TextDrawColor(TDRegister[2], -92724737);
    TextDrawSetShadow(TDRegister[2], 0);
    TextDrawSetOutline(TDRegister[2], 0);
    TextDrawBackgroundColor(TDRegister[2], 255);
    TextDrawFont(TDRegister[2], 4);
    TextDrawSetProportional(TDRegister[2], 0);
    TextDrawSetShadow(TDRegister[2], 0);

    TDRegister[3] = TextDrawCreate(276.100036, 149.133300, "box");
    TextDrawLetterSize(TDRegister[3], 0.000000, 2.162992);
    TextDrawTextSize(TDRegister[3], 362.000000, 0.000000);
    TextDrawAlignment(TDRegister[3], 1);
    TextDrawColor(TDRegister[3], -1);
    TextDrawUseBox(TDRegister[3], 1);
    TextDrawBoxColor(TDRegister[3], -92724737);
    TextDrawSetShadow(TDRegister[3], 0);
    TextDrawSetOutline(TDRegister[3], 0);
    TextDrawBackgroundColor(TDRegister[3], 255);
    TextDrawFont(TDRegister[3], 1);
    TextDrawSetProportional(TDRegister[3], 1);
    TextDrawSetShadow(TDRegister[3], 0);

    TDRegister[4] = TextDrawCreate(263.700134, 147.466766, "ld_pool:ball");
    TextDrawLetterSize(TDRegister[4], 0.000000, 0.000000);
    TextDrawTextSize(TDRegister[4], 22.739948, 22.069910);
    TextDrawAlignment(TDRegister[4], 1);
    TextDrawColor(TDRegister[4], 255);
    TextDrawSetShadow(TDRegister[4], 0);
    TextDrawSetOutline(TDRegister[4], 0);
    TextDrawBackgroundColor(TDRegister[4], 255);
    TextDrawFont(TDRegister[4], 4);
    TextDrawSetProportional(TDRegister[4], 0);
    TextDrawSetShadow(TDRegister[4], 0);

    TDRegister[5] = TextDrawCreate(350.105377, 147.544586, "ld_pool:ball");
    TextDrawLetterSize(TDRegister[5], 0.000000, 0.000000);
    TextDrawTextSize(TDRegister[5], 22.739948, 22.069910);
    TextDrawAlignment(TDRegister[5], 1);
    TextDrawColor(TDRegister[5], 255);
    TextDrawSetShadow(TDRegister[5], 0);
    TextDrawSetOutline(TDRegister[5], 0);
    TextDrawBackgroundColor(TDRegister[5], 255);
    TextDrawFont(TDRegister[5], 4);
    TextDrawSetProportional(TDRegister[5], 0);
    TextDrawSetShadow(TDRegister[5], 0);

    TDRegister[6] = TextDrawCreate(276.100036, 150.433380, "box");
    TextDrawLetterSize(TDRegister[6], 0.000000, 1.837996);
    TextDrawTextSize(TDRegister[6], 362.000000, 0.000000);
    TextDrawAlignment(TDRegister[6], 1);
    TextDrawColor(TDRegister[6], -1);
    TextDrawUseBox(TDRegister[6], 1);
    TextDrawBoxColor(TDRegister[6], 255);
    TextDrawSetShadow(TDRegister[6], 0);
    TextDrawSetOutline(TDRegister[6], 0);
    TextDrawBackgroundColor(TDRegister[6], 255);
    TextDrawFont(TDRegister[6], 1);
    TextDrawSetProportional(TDRegister[6], 1);
    TextDrawSetShadow(TDRegister[6], 0);

    TDRegister[7] = TextDrawCreate(261.500000, 177.568603, "ld_pool:ball");
    TextDrawLetterSize(TDRegister[7], 0.000000, 0.000000);
    TextDrawTextSize(TDRegister[7], 25.000000, 26.000000);
    TextDrawAlignment(TDRegister[7], 1);
    TextDrawColor(TDRegister[7], -92724737);
    TextDrawSetShadow(TDRegister[7], 0);
    TextDrawSetOutline(TDRegister[7], 0);
    TextDrawBackgroundColor(TDRegister[7], 255);
    TextDrawFont(TDRegister[7], 4);
    TextDrawSetProportional(TDRegister[7], 0);
    TextDrawSetShadow(TDRegister[7], 0);

    TDRegister[8] = TextDrawCreate(349.605346, 177.968627, "ld_pool:ball");
    TextDrawLetterSize(TDRegister[8], 0.000000, 0.000000);
    TextDrawTextSize(TDRegister[8], 25.000000, 25.509988);
    TextDrawAlignment(TDRegister[8], 1);
    TextDrawColor(TDRegister[8], -92724737);
    TextDrawSetShadow(TDRegister[8], 0);
    TextDrawSetOutline(TDRegister[8], 0);
    TextDrawBackgroundColor(TDRegister[8], 255);
    TextDrawFont(TDRegister[8], 4);
    TextDrawSetProportional(TDRegister[8], 0);
    TextDrawSetShadow(TDRegister[8], 0);

    TDRegister[9] = TextDrawCreate(276.100036, 180.757415, "box");
    TextDrawLetterSize(TDRegister[9], 0.000000, 2.146991);
    TextDrawTextSize(TDRegister[9], 362.000000, 0.000000);
    TextDrawAlignment(TDRegister[9], 1);
    TextDrawColor(TDRegister[9], -1);
    TextDrawUseBox(TDRegister[9], 1);
    TextDrawBoxColor(TDRegister[9], -92724737);
    TextDrawSetShadow(TDRegister[9], 0);
    TextDrawSetOutline(TDRegister[9], 0);
    TextDrawBackgroundColor(TDRegister[9], 255);
    TextDrawFont(TDRegister[9], 1);
    TextDrawSetProportional(TDRegister[9], 1);
    TextDrawSetShadow(TDRegister[9], 0);

    TDRegister[10] = TextDrawCreate(263.200073, 179.668731, "ld_pool:ball");
    TextDrawLetterSize(TDRegister[10], 0.000000, 0.000000);
    TextDrawTextSize(TDRegister[10], 22.739948, 22.069910);
    TextDrawAlignment(TDRegister[10], 1);
    TextDrawColor(TDRegister[10], 255);
    TextDrawSetShadow(TDRegister[10], 0);
    TextDrawSetOutline(TDRegister[10], 0);
    TextDrawBackgroundColor(TDRegister[10], 255);
    TextDrawFont(TDRegister[10], 4);
    TextDrawSetProportional(TDRegister[10], 0);
    TextDrawSetShadow(TDRegister[10], 0);

    TDRegister[11] = TextDrawCreate(350.105377, 179.946563, "ld_pool:ball");
    TextDrawLetterSize(TDRegister[11], 0.000000, 0.000000);
    TextDrawTextSize(TDRegister[11], 22.739948, 22.069910);
    TextDrawAlignment(TDRegister[11], 1);
    TextDrawColor(TDRegister[11], 255);
    TextDrawSetShadow(TDRegister[11], 0);
    TextDrawSetOutline(TDRegister[11], 0);
    TextDrawBackgroundColor(TDRegister[11], 255);
    TextDrawFont(TDRegister[11], 4);
    TextDrawSetProportional(TDRegister[11], 0);
    TextDrawSetShadow(TDRegister[11], 0);

    TDRegister[12] = TextDrawCreate(275.100036, 182.557525, "box");
    TextDrawLetterSize(TDRegister[12], 0.000000, 1.837996);
    TextDrawTextSize(TDRegister[12], 362.000000, 0.000000);
    TextDrawAlignment(TDRegister[12], 1);
    TextDrawColor(TDRegister[12], -1);
    TextDrawUseBox(TDRegister[12], 1);
    TextDrawBoxColor(TDRegister[12], 255);
    TextDrawSetShadow(TDRegister[12], 0);
    TextDrawSetOutline(TDRegister[12], 0);
    TextDrawBackgroundColor(TDRegister[12], 255);
    TextDrawFont(TDRegister[12], 1);
    TextDrawSetProportional(TDRegister[12], 1);
    TextDrawSetShadow(TDRegister[12], 0);

    TDRegister[13] = TextDrawCreate(264.500000, 100.255195, "VIDA_REAL_CRIAS");
    TextDrawLetterSize(TDRegister[13], 0.400000, 1.600000);
    TextDrawAlignment(TDRegister[13], 1);
    TextDrawColor(TDRegister[13], -5963521);
    TextDrawSetShadow(TDRegister[13], -1);
    TextDrawSetOutline(TDRegister[13], 1);
    TextDrawBackgroundColor(TDRegister[13], 255);
    TextDrawFont(TDRegister[13], 3);
    TextDrawSetProportional(TDRegister[13], 1);
    TextDrawSetShadow(TDRegister[13], -1);

    TDRegister[14] = TextDrawCreate(301.598724, 115.366539, "Copyright_2020_-_RPG");
    TextDrawLetterSize(TDRegister[14], 0.180500, 0.834662);
    TextDrawAlignment(TDRegister[14], 1);
    TextDrawColor(TDRegister[14], -1);
    TextDrawSetShadow(TDRegister[14], 0);
    TextDrawSetOutline(TDRegister[14], 1);
    TextDrawBackgroundColor(TDRegister[14], 255);
    TextDrawFont(TDRegister[14], 1);
    TextDrawSetProportional(TDRegister[14], 1);
    TextDrawSetShadow(TDRegister[14], 0);

    TDRegister[15] = TextDrawCreate(261.500000, 209.570556, "ld_pool:ball");
    TextDrawLetterSize(TDRegister[15], 0.000000, 0.000000);
    TextDrawTextSize(TDRegister[15], 25.000000, 26.000000);
    TextDrawAlignment(TDRegister[15], 1);
    TextDrawColor(TDRegister[15], -92724737);
    TextDrawSetShadow(TDRegister[15], 0);
    TextDrawSetOutline(TDRegister[15], 0);
    TextDrawBackgroundColor(TDRegister[15], 255);
    TextDrawFont(TDRegister[15], 4);
    TextDrawSetProportional(TDRegister[15], 0);
    TextDrawSetShadow(TDRegister[15], 0);

    TDRegister[16] = TextDrawCreate(349.605346, 209.770568, "ld_pool:ball");
    TextDrawLetterSize(TDRegister[16], 0.000000, 0.000000);
    TextDrawTextSize(TDRegister[16], 25.000000, 25.509988);
    TextDrawAlignment(TDRegister[16], 1);
    TextDrawColor(TDRegister[16], -92724737);
    TextDrawSetShadow(TDRegister[16], 0);
    TextDrawSetOutline(TDRegister[16], 0);
    TextDrawBackgroundColor(TDRegister[16], 255);
    TextDrawFont(TDRegister[16], 4);
    TextDrawSetProportional(TDRegister[16], 0);
    TextDrawSetShadow(TDRegister[16], 0);

    TDRegister[17] = TextDrawCreate(274.399932, 212.659362, "box");
    TextDrawLetterSize(TDRegister[17], 0.000000, 2.160989);
    TextDrawTextSize(TDRegister[17], 360.299896, 0.000000);
    TextDrawAlignment(TDRegister[17], 1);
    TextDrawColor(TDRegister[17], -1);
    TextDrawUseBox(TDRegister[17], 1);
    TextDrawBoxColor(TDRegister[17], -92724737);
    TextDrawSetShadow(TDRegister[17], 0);
    TextDrawSetOutline(TDRegister[17], 0);
    TextDrawBackgroundColor(TDRegister[17], 255);
    TextDrawFont(TDRegister[17], 1);
    TextDrawSetProportional(TDRegister[17], 1);
    TextDrawSetShadow(TDRegister[17], 0);

    TDRegister[18] = TextDrawCreate(263.200073, 211.470672, "ld_pool:ball");
    TextDrawLetterSize(TDRegister[18], 0.000000, 0.000000);
    TextDrawTextSize(TDRegister[18], 22.739948, 22.069910);
    TextDrawAlignment(TDRegister[18], 1);
    TextDrawColor(TDRegister[18], 255);
    TextDrawSetShadow(TDRegister[18], 0);
    TextDrawSetOutline(TDRegister[18], 0);
    TextDrawBackgroundColor(TDRegister[18], 255);
    TextDrawFont(TDRegister[18], 4);
    TextDrawSetProportional(TDRegister[18], 0);
    TextDrawSetShadow(TDRegister[18], 0);

    TDRegister[19] = TextDrawCreate(350.105377, 211.748504, "ld_pool:ball");
    TextDrawLetterSize(TDRegister[19], 0.000000, 0.000000);
    TextDrawTextSize(TDRegister[19], 22.739948, 22.069910);
    TextDrawAlignment(TDRegister[19], 1);
    TextDrawColor(TDRegister[19], 255);
    TextDrawSetShadow(TDRegister[19], 0);
    TextDrawSetOutline(TDRegister[19], 0);
    TextDrawBackgroundColor(TDRegister[19], 255);
    TextDrawFont(TDRegister[19], 4);
    TextDrawSetProportional(TDRegister[19], 0);
    TextDrawSetShadow(TDRegister[19], 0);

    TDRegister[20] = TextDrawCreate(274.500030, 214.559478, "box");
    TextDrawLetterSize(TDRegister[20], 0.000000, 1.837996);
    TextDrawTextSize(TDRegister[20], 361.000000, 0.000000);
    TextDrawAlignment(TDRegister[20], 1);
    TextDrawColor(TDRegister[20], -1);
    TextDrawUseBox(TDRegister[20], 1);
    TextDrawBoxColor(TDRegister[20], 255);
    TextDrawSetShadow(TDRegister[20], 0);
    TextDrawSetOutline(TDRegister[20], 0);
    TextDrawBackgroundColor(TDRegister[20], 255);
    TextDrawFont(TDRegister[20], 1);
    TextDrawSetProportional(TDRegister[20], 1);
    TextDrawSetShadow(TDRegister[20], 0);

    TDRegister[21] = TextDrawCreate(261.500000, 242.594757, "ld_pool:ball");
    TextDrawLetterSize(TDRegister[21], 0.000000, 0.000000);
    TextDrawTextSize(TDRegister[21], 25.000000, 26.000000);
    TextDrawAlignment(TDRegister[21], 1);
    TextDrawColor(TDRegister[21], -92724737);
    TextDrawSetShadow(TDRegister[21], 0);
    TextDrawSetOutline(TDRegister[21], 0);
    TextDrawBackgroundColor(TDRegister[21], 255);
    TextDrawFont(TDRegister[21], 4);
    TextDrawSetProportional(TDRegister[21], 0);
    TextDrawSetShadow(TDRegister[21], 0);

    TDRegister[22] = TextDrawCreate(349.105346, 242.916961, "ld_pool:ball");
    TextDrawLetterSize(TDRegister[22], 0.000000, 0.000000);
    TextDrawTextSize(TDRegister[22], 25.000000, 25.509988);
    TextDrawAlignment(TDRegister[22], 1);
    TextDrawColor(TDRegister[22], -92724737);
    TextDrawSetShadow(TDRegister[22], 0);
    TextDrawSetOutline(TDRegister[22], 0);
    TextDrawBackgroundColor(TDRegister[22], 255);
    TextDrawFont(TDRegister[22], 4);
    TextDrawSetProportional(TDRegister[22], 0);
    TextDrawSetShadow(TDRegister[22], 0);

    TDRegister[23] = TextDrawCreate(274.399932, 245.661376, "box");
    TextDrawLetterSize(TDRegister[23], 0.000000, 2.160989);
    TextDrawTextSize(TDRegister[23], 360.299896, 0.000000);
    TextDrawAlignment(TDRegister[23], 1);
    TextDrawColor(TDRegister[23], -1);
    TextDrawUseBox(TDRegister[23], 1);
    TextDrawBoxColor(TDRegister[23], -92724737);
    TextDrawSetShadow(TDRegister[23], 0);
    TextDrawSetOutline(TDRegister[23], 0);
    TextDrawBackgroundColor(TDRegister[23], 255);
    TextDrawFont(TDRegister[23], 1);
    TextDrawSetProportional(TDRegister[23], 1);
    TextDrawSetShadow(TDRegister[23], 0);

    TDRegister[24] = TextDrawCreate(263.200073, 244.572692, "ld_pool:ball");
    TextDrawLetterSize(TDRegister[24], 0.000000, 0.000000);
    TextDrawTextSize(TDRegister[24], 22.739948, 22.069910);
    TextDrawAlignment(TDRegister[24], 1);
    TextDrawColor(TDRegister[24], 255);
    TextDrawSetShadow(TDRegister[24], 0);
    TextDrawSetOutline(TDRegister[24], 0);
    TextDrawBackgroundColor(TDRegister[24], 255);
    TextDrawFont(TDRegister[24], 4);
    TextDrawSetProportional(TDRegister[24], 0);
    TextDrawSetShadow(TDRegister[24], 0);

    TDRegister[25] = TextDrawCreate(350.105377, 244.750518, "ld_pool:ball");
    TextDrawLetterSize(TDRegister[25], 0.000000, 0.000000);
    TextDrawTextSize(TDRegister[25], 22.739948, 22.069910);
    TextDrawAlignment(TDRegister[25], 1);
    TextDrawColor(TDRegister[25], 255);
    TextDrawSetShadow(TDRegister[25], 0);
    TextDrawSetOutline(TDRegister[25], 0);
    TextDrawBackgroundColor(TDRegister[25], 255);
    TextDrawFont(TDRegister[25], 4);
    TextDrawSetProportional(TDRegister[25], 0);
    TextDrawSetShadow(TDRegister[25], 0);

    TDRegister[26] = TextDrawCreate(274.500030, 247.361480, "box");
    TextDrawLetterSize(TDRegister[26], 0.000000, 1.837996);
    TextDrawTextSize(TDRegister[26], 361.000000, 0.000000);
    TextDrawAlignment(TDRegister[26], 1);
    TextDrawColor(TDRegister[26], -1);
    TextDrawUseBox(TDRegister[26], 1);
    TextDrawBoxColor(TDRegister[26], 255);
    TextDrawSetShadow(TDRegister[26], 0);
    TextDrawSetOutline(TDRegister[26], 0);
    TextDrawBackgroundColor(TDRegister[26], 255);
    TextDrawFont(TDRegister[26], 1);
    TextDrawSetProportional(TDRegister[26], 1);
    TextDrawSetShadow(TDRegister[26], 0);

    TDRegister[27] = TextDrawCreate(261.500000, 276.496826, "ld_pool:ball");
    TextDrawLetterSize(TDRegister[27], 0.000000, 0.000000);
    TextDrawTextSize(TDRegister[27], 25.000000, 26.000000);
    TextDrawAlignment(TDRegister[27], 1);
    TextDrawColor(TDRegister[27], -92724737);
    TextDrawSetShadow(TDRegister[27], 0);
    TextDrawSetOutline(TDRegister[27], 0);
    TextDrawBackgroundColor(TDRegister[27], 255);
    TextDrawFont(TDRegister[27], 4);
    TextDrawSetProportional(TDRegister[27], 0);
    TextDrawSetShadow(TDRegister[27], 0);

    TDRegister[28] = TextDrawCreate(285.701477, 276.496826, "ld_pool:ball");
    TextDrawLetterSize(TDRegister[28], 0.000000, 0.000000);
    TextDrawTextSize(TDRegister[28], 25.000000, 26.000000);
    TextDrawAlignment(TDRegister[28], 1);
    TextDrawColor(TDRegister[28], -92724737);
    TextDrawSetShadow(TDRegister[28], 0);
    TextDrawSetOutline(TDRegister[28], 0);
    TextDrawBackgroundColor(TDRegister[28], 255);
    TextDrawFont(TDRegister[28], 4);
    TextDrawSetProportional(TDRegister[28], 0);
    TextDrawSetShadow(TDRegister[28], 0);

    TDRegister[29] = TextDrawCreate(274.399932, 279.463439, "box");
    TextDrawLetterSize(TDRegister[29], 0.000000, 2.167993);
    TextDrawTextSize(TDRegister[29], 298.979003, 0.000000);
    TextDrawAlignment(TDRegister[29], 1);
    TextDrawColor(TDRegister[29], -1);
    TextDrawUseBox(TDRegister[29], 1);
    TextDrawBoxColor(TDRegister[29], -92724737);
    TextDrawSetShadow(TDRegister[29], 0);
    TextDrawSetOutline(TDRegister[29], 0);
    TextDrawBackgroundColor(TDRegister[29], 255);
    TextDrawFont(TDRegister[29], 1);
    TextDrawSetProportional(TDRegister[29], 1);
    TextDrawSetShadow(TDRegister[29], 0);

    TDRegister[30] = TextDrawCreate(263.200073, 278.474761, "ld_pool:ball");
    TextDrawLetterSize(TDRegister[30], 0.000000, 0.000000);
    TextDrawTextSize(TDRegister[30], 22.739948, 22.069910);
    TextDrawAlignment(TDRegister[30], 1);
    TextDrawColor(TDRegister[30], 255);
    TextDrawSetShadow(TDRegister[30], 0);
    TextDrawSetOutline(TDRegister[30], 0);
    TextDrawBackgroundColor(TDRegister[30], 255);
    TextDrawFont(TDRegister[30], 4);
    TextDrawSetProportional(TDRegister[30], 0);
    TextDrawSetShadow(TDRegister[30], 0);

    TDRegister[31] = TextDrawCreate(286.401489, 278.474761, "ld_pool:ball");
    TextDrawLetterSize(TDRegister[31], 0.000000, 0.000000);
    TextDrawTextSize(TDRegister[31], 22.739948, 22.069910);
    TextDrawAlignment(TDRegister[31], 1);
    TextDrawColor(TDRegister[31], 255);
    TextDrawSetShadow(TDRegister[31], 0);
    TextDrawSetOutline(TDRegister[31], 0);
    TextDrawBackgroundColor(TDRegister[31], 255);
    TextDrawFont(TDRegister[31], 4);
    TextDrawSetProportional(TDRegister[31], 0);
    TextDrawSetShadow(TDRegister[31], 0);

    TDRegister[32] = TextDrawCreate(274.500030, 281.241363, "box");
    TextDrawLetterSize(TDRegister[32], 0.000000, 1.799006);
    TextDrawTextSize(TDRegister[32], 295.000000, 0.000000);
    TextDrawAlignment(TDRegister[32], 1);
    TextDrawColor(TDRegister[32], -1);
    TextDrawUseBox(TDRegister[32], 1);
    TextDrawBoxColor(TDRegister[32], 255);
    TextDrawSetShadow(TDRegister[32], 0);
    TextDrawSetOutline(TDRegister[32], 0);
    TextDrawBackgroundColor(TDRegister[32], 255);
    TextDrawFont(TDRegister[32], 1);
    TextDrawSetProportional(TDRegister[32], 1);
    TextDrawSetShadow(TDRegister[32], 0);

    TDRegister[33] = TextDrawCreate(347.605346, 276.696838, "ld_pool:ball");
    TextDrawLetterSize(TDRegister[33], 0.000000, 0.000000);
    TextDrawTextSize(TDRegister[33], 25.000000, 25.509988);
    TextDrawAlignment(TDRegister[33], 1);
    TextDrawColor(TDRegister[33], 8388863);
    TextDrawSetShadow(TDRegister[33], 0);
    TextDrawSetOutline(TDRegister[33], 0);
    TextDrawBackgroundColor(TDRegister[33], 255);
    TextDrawFont(TDRegister[33], 4);
    TextDrawSetProportional(TDRegister[33], 0);
    TextDrawSetShadow(TDRegister[33], 0);

    TDRegister[34] = TextDrawCreate(322.503753, 276.496826, "ld_pool:ball");
    TextDrawLetterSize(TDRegister[34], 0.000000, 0.000000);
    TextDrawTextSize(TDRegister[34], 25.000000, 26.000000);
    TextDrawAlignment(TDRegister[34], 1);
    TextDrawColor(TDRegister[34], 8388863);
    TextDrawSetShadow(TDRegister[34], 0);
    TextDrawSetOutline(TDRegister[34], 0);
    TextDrawBackgroundColor(TDRegister[34], 255);
    TextDrawFont(TDRegister[34], 4);
    TextDrawSetProportional(TDRegister[34], 0);
    TextDrawSetShadow(TDRegister[34], 0);

    TDRegister[35] = TextDrawCreate(334.103576, 279.719085, "box");
    TextDrawLetterSize(TDRegister[35], 0.000000, 2.167993);
    TextDrawTextSize(TDRegister[35], 358.800048, 0.000000);
    TextDrawAlignment(TDRegister[35], 1);
    TextDrawColor(TDRegister[35], -1);
    TextDrawUseBox(TDRegister[35], 1);
    TextDrawBoxColor(TDRegister[35], 8388863);
    TextDrawSetShadow(TDRegister[35], 0);
    TextDrawSetOutline(TDRegister[35], 0);
    TextDrawBackgroundColor(TDRegister[35], 255);
    TextDrawFont(TDRegister[35], 1);
    TextDrawSetProportional(TDRegister[35], 1);
    TextDrawSetShadow(TDRegister[35], 0);

    TDRegister[36] = TextDrawCreate(347.805267, 278.474761, "ld_pool:ball");
    TextDrawLetterSize(TDRegister[36], 0.000000, 0.000000);
    TextDrawTextSize(TDRegister[36], 22.739948, 22.069910);
    TextDrawAlignment(TDRegister[36], 1);
    TextDrawColor(TDRegister[36], 255);
    TextDrawSetShadow(TDRegister[36], 0);
    TextDrawSetOutline(TDRegister[36], 0);
    TextDrawBackgroundColor(TDRegister[36], 255);
    TextDrawFont(TDRegister[36], 4);
    TextDrawSetProportional(TDRegister[36], 0);
    TextDrawSetShadow(TDRegister[36], 0);

    TDRegister[37] = TextDrawCreate(324.204132, 278.486022, "ld_pool:ball");
    TextDrawLetterSize(TDRegister[37], 0.000000, 0.000000);
    TextDrawTextSize(TDRegister[37], 22.739948, 22.069910);
    TextDrawAlignment(TDRegister[37], 1);
    TextDrawColor(TDRegister[37], 255);
    TextDrawSetShadow(TDRegister[37], 0);
    TextDrawSetOutline(TDRegister[37], 0);
    TextDrawBackgroundColor(TDRegister[37], 255);
    TextDrawFont(TDRegister[37], 4);
    TextDrawSetProportional(TDRegister[37], 0);
    TextDrawSetShadow(TDRegister[37], 0);

    TDRegister[38] = TextDrawCreate(336.403808, 281.163543, "box");
    TextDrawLetterSize(TDRegister[38], 0.000000, 1.825007);
    TextDrawTextSize(TDRegister[38], 357.000000, 0.000000);
    TextDrawAlignment(TDRegister[38], 1);
    TextDrawColor(TDRegister[38], -1);
    TextDrawUseBox(TDRegister[38], 1);
    TextDrawBoxColor(TDRegister[38], 255);
    TextDrawSetShadow(TDRegister[38], 0);
    TextDrawSetOutline(TDRegister[38], 0);
    TextDrawBackgroundColor(TDRegister[38], 255);
    TextDrawFont(TDRegister[38], 1);
    TextDrawSetProportional(TDRegister[38], 1);
    TextDrawSetShadow(TDRegister[38], 0);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    TDPlayerLogin[playerid][0] = CreatePlayerTextDraw(playerid, 318.000000, 153.111022, "CLIQUE_AQUI_PARA_COLOCAR_SEU_NOME");
    PlayerTextDrawLetterSize(playerid, TDPlayerLogin[playerid][0], 0.095999, 0.927999);
    PlayerTextDrawAlignment(playerid, TDPlayerLogin[playerid][0], 2);
    PlayerTextDrawColor(playerid, TDPlayerLogin[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerLogin[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerLogin[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerLogin[playerid][0], 255);
    PlayerTextDrawFont(playerid, TDPlayerLogin[playerid][0], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerLogin[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerLogin[playerid][0], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerLogin[playerid][0], true);
    PlayerTextDrawTextSize(playerid, TDPlayerLogin[playerid][0], 10.000000, 78.000000);

    TDPlayerLogin[playerid][1] = CreatePlayerTextDraw(playerid, 318.000000, 199.713867, "CLIQUE_AQUI_PARA_COLOCAR_SUA_SENHA");
    PlayerTextDrawLetterSize(playerid, TDPlayerLogin[playerid][1], 0.096999, 0.927999);
    PlayerTextDrawAlignment(playerid, TDPlayerLogin[playerid][1], 2);
    PlayerTextDrawColor(playerid, TDPlayerLogin[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerLogin[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerLogin[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerLogin[playerid][1], 255);
    PlayerTextDrawFont(playerid, TDPlayerLogin[playerid][1], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerLogin[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerLogin[playerid][1], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerLogin[playerid][1], true);
    PlayerTextDrawTextSize(playerid, TDPlayerLogin[playerid][1], 10.000000, 80.000000);

    TDPlayerLogin[playerid][2] = CreatePlayerTextDraw(playerid, 273.500000, 240.277862, "Entrar");
    PlayerTextDrawLetterSize(playerid, TDPlayerLogin[playerid][2], 0.306000, 1.506666);
    PlayerTextDrawAlignment(playerid, TDPlayerLogin[playerid][2], 1);
    PlayerTextDrawColor(playerid, TDPlayerLogin[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerLogin[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerLogin[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerLogin[playerid][2], 255);
    PlayerTextDrawFont(playerid, TDPlayerLogin[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, TDPlayerLogin[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerLogin[playerid][2], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerLogin[playerid][2], true);
    PlayerTextDrawTextSize(playerid, TDPlayerLogin[playerid][2], 303.000000, 12.000000);

    TDPlayerLogin[playerid][3] = CreatePlayerTextDraw(playerid, 331.003509, 241.877960, "Recuperar");
    PlayerTextDrawLetterSize(playerid, TDPlayerLogin[playerid][3], 0.218001, 1.316666);
    PlayerTextDrawAlignment(playerid, TDPlayerLogin[playerid][3], 1);
    PlayerTextDrawColor(playerid, TDPlayerLogin[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerLogin[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerLogin[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerLogin[playerid][3], 255);
    PlayerTextDrawFont(playerid, TDPlayerLogin[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, TDPlayerLogin[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerLogin[playerid][3], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerLogin[playerid][3], true);
    PlayerTextDrawTextSize(playerid, TDPlayerLogin[playerid][3], 365.000000, 12.000000);

    TDPlayerLogin[playerid][4] = CreatePlayerTextDraw(playerid, 318.003601, 299.511169, "Registrar-se");
    PlayerTextDrawLetterSize(playerid, TDPlayerLogin[playerid][4], 0.224500, 1.214221);
    PlayerTextDrawAlignment(playerid, TDPlayerLogin[playerid][4], 1);
    PlayerTextDrawColor(playerid, TDPlayerLogin[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerLogin[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerLogin[playerid][4], -1);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerLogin[playerid][4], 255);
    PlayerTextDrawFont(playerid, TDPlayerLogin[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, TDPlayerLogin[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerLogin[playerid][4], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerLogin[playerid][4], true);
    PlayerTextDrawTextSize(playerid, TDPlayerLogin[playerid][4], 360.000000, 12.000000);

    TDPlayerRegister[playerid][0] = CreatePlayerTextDraw(playerid, 317.200042, 153.455413, "CLIQUE_AQUI_PARA_COLOCAR_SEU_NOME");
    PlayerTextDrawLetterSize(playerid, TDPlayerRegister[playerid][0], 0.097500, 0.840888);
    PlayerTextDrawAlignment(playerid, TDPlayerRegister[playerid][0], 2);
    PlayerTextDrawColor(playerid, TDPlayerRegister[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerRegister[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerRegister[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerRegister[playerid][0], 255);
    PlayerTextDrawFont(playerid, TDPlayerRegister[playerid][0], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerRegister[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerRegister[playerid][0], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerRegister[playerid][0], true);
    PlayerTextDrawTextSize(playerid, TDPlayerRegister[playerid][0], 10.000000, 80.000000);

    TDPlayerRegister[playerid][1] = CreatePlayerTextDraw(playerid, 317.200042, 185.557373, "CLIQUE_AQUI_PARA_COLOCAR_SUA_SENHA");
    PlayerTextDrawLetterSize(playerid, TDPlayerRegister[playerid][1], 0.097500, 0.840888);
    PlayerTextDrawAlignment(playerid, TDPlayerRegister[playerid][1], 2);
    PlayerTextDrawColor(playerid, TDPlayerRegister[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerRegister[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerRegister[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerRegister[playerid][1], 255);
    PlayerTextDrawFont(playerid, TDPlayerRegister[playerid][1], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerRegister[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerRegister[playerid][1], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerRegister[playerid][1], true);
    PlayerTextDrawTextSize(playerid, TDPlayerRegister[playerid][1], 10.000000, 80.000000);

    TDPlayerRegister[playerid][2] = CreatePlayerTextDraw(playerid, 317.200042, 217.859344, "CLIQUE_AQUI_PARA_CONFIRMAR_SUA_SENHA");
    PlayerTextDrawLetterSize(playerid, TDPlayerRegister[playerid][2], 0.097500, 0.840888);
    PlayerTextDrawAlignment(playerid, TDPlayerRegister[playerid][2], 2);
    PlayerTextDrawColor(playerid, TDPlayerRegister[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerRegister[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerRegister[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerRegister[playerid][2], 255);
    PlayerTextDrawFont(playerid, TDPlayerRegister[playerid][2], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerRegister[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerRegister[playerid][2], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerRegister[playerid][2], true);
    PlayerTextDrawTextSize(playerid, TDPlayerRegister[playerid][2], 10.000000, 80.000000);

    TDPlayerRegister[playerid][3] = CreatePlayerTextDraw(playerid, 317.200042, 250.661346, "CLIQUE_AQUI_PARA_COLOCAR_SEU_EMAIL");
    PlayerTextDrawLetterSize(playerid, TDPlayerRegister[playerid][3], 0.097500, 0.840888);
    PlayerTextDrawAlignment(playerid, TDPlayerRegister[playerid][3], 2);
    PlayerTextDrawColor(playerid, TDPlayerRegister[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerRegister[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerRegister[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerRegister[playerid][3], 255);
    PlayerTextDrawFont(playerid, TDPlayerRegister[playerid][3], 2);
    PlayerTextDrawSetProportional(playerid, TDPlayerRegister[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerRegister[playerid][3], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerRegister[playerid][3], true);
    PlayerTextDrawTextSize(playerid, TDPlayerRegister[playerid][3], 10.000000, 80.000000);

    TDPlayerRegister[playerid][4] = CreatePlayerTextDraw(playerid, 286.600646, 283.333343, "Sexo");
    PlayerTextDrawLetterSize(playerid, TDPlayerRegister[playerid][4], 0.242999, 1.108442);
    PlayerTextDrawAlignment(playerid, TDPlayerRegister[playerid][4], 2);
    PlayerTextDrawColor(playerid, TDPlayerRegister[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerRegister[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerRegister[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerRegister[playerid][4], 255);
    PlayerTextDrawFont(playerid, TDPlayerRegister[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, TDPlayerRegister[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerRegister[playerid][4], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerRegister[playerid][4], true);
    PlayerTextDrawTextSize(playerid, TDPlayerRegister[playerid][4], 342.000000, 12.000000);

    TDPlayerRegister[playerid][5] = CreatePlayerTextDraw(playerid, 347.704376, 283.333343, "Registrar");
    PlayerTextDrawLetterSize(playerid, TDPlayerRegister[playerid][5], 0.242999, 1.108442);
    PlayerTextDrawAlignment(playerid, TDPlayerRegister[playerid][5], 2);
    PlayerTextDrawColor(playerid, TDPlayerRegister[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, TDPlayerRegister[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, TDPlayerRegister[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, TDPlayerRegister[playerid][5], 255);
    PlayerTextDrawFont(playerid, TDPlayerRegister[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, TDPlayerRegister[playerid][5], 1);
    PlayerTextDrawSetShadow(playerid, TDPlayerRegister[playerid][5], 0);
    PlayerTextDrawSetSelectable(playerid, TDPlayerRegister[playerid][5], true);
    PlayerTextDrawTextSize(playerid, TDPlayerRegister[playerid][5], 12.000000, 40.000000);

    ShowPlayerDialog(playerid, check_system, DIALOG_STYLE_MSGBOX, "{FF0000}ATENCÃO", "{FFFFFF}Por onde você vai jogar?\n\n{FF0000}Observação: Se você não selecionar a opção correta podera ocasionar em bugs!!!", "Android", "Computador");

    t_login[playerid] = SetTimerEx("OnPlayerLoginKick", 300000, false, "d", playerid);
    return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
    enum e_al
    {
        Float:e_al_x,
        Float:e_al_y,
        Float:e_al_z,
        Float:e_al_x1,
        Float:e_al_y1,
        Float:e_al_z1
    };

    new AnimsLogin[3][e_al] =
    {
        {161.9850, -1963.3818, 38.5807, 852.1138, -1957.2549, 85.3233}, //ls
        {2068.0583, 825.6366, 29.9414, 1812.3918, 2533.0408, 100.6096}, //lv
        {-2426.7578, 316.2170, 37.6387, -1628.6191, -415.7397, 80.0648} //sf
    };

    new rand = random(sizeof(AnimsLogin));

    TogglePlayerSpectating(playerid, true);
    InterpolateCameraPos(playerid, AnimsLogin[rand][e_al_x], AnimsLogin[rand][e_al_y], AnimsLogin[rand][e_al_z], AnimsLogin[rand][e_al_x1], AnimsLogin[rand][e_al_y1], AnimsLogin[rand][e_al_z1], 50000);
    InterpolateCameraLookAt(playerid, AnimsLogin[rand][e_al_x], AnimsLogin[rand][e_al_y], AnimsLogin[rand][e_al_z], AnimsLogin[rand][e_al_x1], AnimsLogin[rand][e_al_y1], AnimsLogin[rand][e_al_z1], 50000);
	return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    KillTimer(t_login[playerid]);
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case check_system:
        {
            if(response)
            {
                format(String, sizeof(String), "Android_Entrando_%d", playerid);
                IsMobile[playerid] = true;

                ShowPlayerDialog(playerid, cell_login_name, DIALOG_STYLE_INPUT, "{CCCCCC}Login - Nome", "{FFFFFF}Digite o seu nome para poder entrar e depois clique em \"{FF0000}Continuar{FFFFFF}\"\nSe não tiver conta clique em\"{00FF00}Registrar{FFFFFF}\"", "Continuar", "Registrar");
            }
            else
            {
                format(String, sizeof(String), "PC_Entrando_%d", playerid);
                IsMobile[playerid] = false;
                SelectTextDraw(playerid, Green);
                ShowTextDrawLogin(playerid);
                RemoveBugFirstAnimation(playerid);
            }

            SetPlayerName(playerid, String);
            TDPlayerBarStatus(playerid);
            TDVehicleBarStatus(playerid);
            return 1;
        }
        case cell_login_name:
        {
            if(response)
            {
                if(!strlen(inputtext))
                    return ShowPlayerDialog(playerid, cell_login_name, DIALOG_STYLE_INPUT, "{CCCCCC}Login - Nome", "{FFFFFF}Digite o seu nome para poder entrar e depois clique em \"{FF0000}Continuar{FFFFFF}\"\nSe não tiver conta clique em\"{00FF00}Registrar{FFFFFF}\"", "Continuar", "Registrar");

                format(pPlayerInfo[playerid][pNome], MAX_PLAYER_NAME, inputtext);

                mysql_format(IDConexao, String, sizeof(String), "SELECT `Nome` FROM `Contas` WHERE `Nome`='%s'", pPlayerInfo[playerid][pNome]);
                mysql_query(IDConexao, String);

                if(cache_num_rows() == 0)
                    return ShowPlayerDialog(playerid, cell_login_name, DIALOG_STYLE_INPUT, "{CCCCCC}Login - Nome", "{FFFFFF}Digite o seu nome para poder entrar e depois clique em \"{FF0000}Continuar{FFFFFF}\"\nSe não tiver conta clique em\"{00FF00}Registrar{FFFFFF}\"\n\n{FF0000}Conta não registrada", "Continuar", "Registrar");

                ShowPlayerDialog(playerid, cell_login_pass, DIALOG_STYLE_PASSWORD, "{CCCCCC}Login - Senha", "{FFFFFF}Digite a sua senha para poder entrar e depois clique em \"{FF0000}Entrar{FFFFFF}\"\nSe digitou nome errado clique em\"{00FF00}Voltar{FFFFFF}\"", "Entrar", "Voltar");
            }
            else
            {
                ShowPlayerDialog(playerid, cell_register_name, DIALOG_STYLE_INPUT, "{00FF00}Registro - Nome", "{FFFFFF}Digite seu novo nome e depois clique em \"{FF0000}Continuar{FFFFFF}\"\nSe já tiver conta clique em\"{00FF00}Voltar{FFFFFF}\"", "Continuar", "Voltar");
            }
            return 1;
        }
        case cell_login_pass:
        {
            if(response)
            {
                if(!strlen(inputtext))
                    return ShowPlayerDialog(playerid, cell_login_pass, DIALOG_STYLE_INPUT, "{CCCCCC}Login - Senha", "{FFFFFF}Digite a sua senha para poder entrar e depois clique em \"{FF0000}Entrar{FFFFFF}\"\nSe digitou nome errado clique em\"{00FF00}Voltar{FFFFFF}\"", "Entrar", "Voltar");

                format(pPlayerInfo[playerid][pSenha], MAX_PLAYER_PASS, inputtext);

                mysql_format(IDConexao, String, sizeof(String), "SELECT `Nome` AND `Senha` FROM `Contas` WHERE `Nome`='%e' AND `Senha`='%e'", pPlayerInfo[playerid][pNome], pPlayerInfo[playerid][pSenha]);
                mysql_query(IDConexao, String);

                if(cache_num_rows() == 0)
                    return ShowPlayerDialog(playerid, cell_login_pass, DIALOG_STYLE_INPUT, "{CCCCCC}Login - Senha", "{FFFFFF}Digite a sua senha para poder entrar e depois clique em \"{FF0000}Entrar{FFFFFF}\"\nSe digitou nome errado clique em\"{00FF00}Voltar\"\n\n{FF0000}Senha Incorreta", "Entrar", "Voltar");

                mysql_format(IDConexao, String, sizeof(String), "SELECT * FROM `Contas` WHERE Nome='%e'", pPlayerInfo[playerid][pNome]);
                mysql_tquery(IDConexao, String, "LoadAccounts", "d", playerid);
            }
            else
            {
                ShowPlayerDialog(playerid, cell_login_name, DIALOG_STYLE_INPUT, "{CCCCCC}Login - Nome", "{FFFFFF}Digite o seu nome para poder entrar e depois clique em \"{FF0000}Continuar{FFFFFF}\"\nSe não tiver conta clique em\"{00FF00}Registrar\"", "Continuar", "Registrar");
            }
            return 1;
        }
        case cell_register_name:
        {
            if(response)
            {
                if(!strlen(inputtext))
                    return ShowPlayerDialog(playerid, cell_register_name, DIALOG_STYLE_INPUT, "{00FF00}Registro - Nome", "{FFFFFF}Digite seu novo nome e depois clique em \"{FF0000}Continuar{FFFFFF}\"\nSe já tiver conta clique em\"{00FF00}Voltar{FFFFFF}\"", "Continuar", "Voltar");

                format(pPlayerInfo[playerid][pNome], MAX_PLAYER_NAME, inputtext);

                mysql_format(IDConexao, String, sizeof(String), "SELECT `Nome` FROM `Contas` WHERE `Nome`='%e'", pPlayerInfo[playerid][pNome]);
                mysql_query(IDConexao, String);

                if(cache_num_rows())
                    return ShowPlayerDialog(playerid, cell_register_name, DIALOG_STYLE_INPUT, "{00FF00}Registro - Nome", "{FFFFFF}Digite seu novo nome e depois clique em \"{FF0000}Continuar{FFFFFF}\"\nSe já tiver conta clique em\"{00FF00}Voltar\"\n\n{FF0000}Nome já em uso", "Continuar", "Voltar");

                ShowPlayerDialog(playerid, cell_register_pass, DIALOG_STYLE_PASSWORD, "{CCCCCC}Registro - Senha", "{FFFFFF}Digite a sua nova senha e depois clique em \"{FF0000}Continuar{FFFFFF}\"\nSe digitou nome errado clique em\"{00FF00}Voltar{FFFFFF}\"", "Continuar", "Voltar");
            }
            else
            {
                ShowPlayerDialog(playerid, cell_login_name, DIALOG_STYLE_INPUT, "{CCCCCC}Login - Nome", "{FFFFFF}Digite o seu nome para poder entrar e depois clique em \"{FF0000}Continuar{FFFFFF}\"\nSe não tiver conta clique em\"{00FF00}Registrar\"", "Continuar", "Registrar");
            }
            return 1;
        }
        case cell_register_pass:
        {
            if(response)
            {
                if(!strlen(inputtext))
                    return ShowPlayerDialog(playerid, cell_register_pass, DIALOG_STYLE_PASSWORD, "{CCCCCC}Registro - Senha", "{FFFFFF}Digite a sua nova senha e depois clique em \"{FF0000}Continuar{FFFFFF}\"\nSe digitou nome errado clique em\"{00FF00}Voltar{FFFFFF}\"", "Continuar", "Voltar");

                if(strlen(inputtext) < MIN_PLAYER_PASS || strlen(inputtext) > MAX_PLAYER_PASS)
                    return ShowPlayerDialog(playerid, cell_register_pass, DIALOG_STYLE_PASSWORD, "{CCCCCC}Registro - Senha", "{FFFFFF}Digite a sua nova senha e depois clique em \"{FF0000}Continuar{FFFFFF}\"\nSe digitou nome errado clique em\"{00FF00}Voltar\"\n\n{FF0000}Digite uma senha entre 6 a 30 caracteres", "Continuar", "Voltar");

                format(pPlayerInfo[playerid][pSenha], MAX_PLAYER_PASS, inputtext);

                ShowPlayerDialog(playerid, cell_register_email, DIALOG_STYLE_INPUT, "{00FF00}Registro - Email", "{FFFFFF}Digite abaixo seu email e clique em \"{FF0000}Continuar{FFFFFF}\"\nSe digitou sua sennha errada clique em\"{00FF00}Voltar{FFFFFF}\"", "Continuar", "Voltar");
            }
            else
            {
                ShowPlayerDialog(playerid, cell_register_name, DIALOG_STYLE_INPUT, "{00FF00}Registro - Nome", "{FFFFFF}Digite seu novo nome e depois clique em \"{FF0000}Continuar{FFFFFF}\"\nSe já tiver conta clique em\"{00FF00}Voltar{FFFFFF}\"", "Continuar", "Voltar");
            }
            return 1;
        }
        case cell_register_email:
        {
            if(response)
            {
                if(!strlen(inputtext))
                    return ShowPlayerDialog(playerid, cell_register_email, DIALOG_STYLE_INPUT, "{00FF00}Registro - Email", "{FFFFFF}Digite abaixo seu email e clique em \"{FF0000}Continuar{FFFFFF}\"\nSe digitou sua sennha errada clique em\"{00FF00}Voltar{FFFFFF}\"", "Continuar", "Voltar");

                if(strlen(inputtext) < MIN_PLAYER_EMAIL || strlen(inputtext) > MAX_PLAYER_EMAIL)
                    return ShowPlayerDialog(playerid, cell_register_email, DIALOG_STYLE_INPUT, "{00FF00}Registro - Email", "{FFFFFF}Digite abaixo seu email e clique em \"{FF0000}Continuar{FFFFFF}\"\nSe digitou sua sennha errada clique em\"{00FF00}Voltar\"\n\n{FF0000}Digite um email entre 10 a 50 caracteres", "Continuar", "Voltar");

                format(pPlayerInfo[playerid][pEmail], MAX_PLAYER_EMAIL, inputtext);

                mysql_format(IDConexao, String, sizeof(String), "SELECT `Email` FROM `Contas` WHERE `Email`='%e'", pPlayerInfo[playerid][pEmail]);
                mysql_query(IDConexao, String);

                if(cache_num_rows())
                    return ShowPlayerDialog(playerid, cell_register_email, DIALOG_STYLE_INPUT, "{00FF00}Registro - Email", "{FFFFFF}Digite abaixo seu email e clique em \"{FF0000}Continuar{FFFFFF}\"\nSe digitou sua sennha errada clique em\"{00FF00}Voltar\"\n\n{FF0000}Email já em uso", "Continuar", "Voltar");

                ShowPlayerDialog(playerid, cell_register_sexo, DIALOG_STYLE_MSGBOX, "{00FF00}Registro", "{FFFFFF}Escolha seu sexo", "Masculino", "Feminino");
            }
            else
            {
                ShowPlayerDialog(playerid, cell_register_pass, DIALOG_STYLE_PASSWORD, "{CCCCCC}Registro - Senha", "{FFFFFF}Digite a sua nova senha e depois clique em \"{FF0000}Continuar{FFFFFF}\"\nSe digitou nome errado clique em\"{00FF00}Voltar{FFFFFF}\"", "Continuar", "Voltar");
            }
            return 1;
        }
        case cell_register_sexo:
        {
            if(response)
            {
                format(PlayerInfo[playerid][sexo], 10, "Masculino");
                PlayerInfo[playerid][skin] = DEFAULT_SKIN_BOY;
            }
            else
            {
                format(PlayerInfo[playerid][sexo], 10, "Feminino");
                PlayerInfo[playerid][skin] = DEFAULT_SKIN_GIRL;
            }

            new coding[10];

            format(coding, 10, CreateRandomCode());

            format(String, sizeof(String),"Código: %s\n\nUse esse código para liberar o registro em nosso Servidor.", coding);
            SendEmail("Henriquecalenzo2018@hotmail.com", pPlayerInfo[playerid][pEmail], "Testes", "O sistema de e-mails realmente funciona.<br>Gostou? visite o <a href=\"http://forum.sa-mp.com\">Fórum SA-MP</a>");

            mysql_format(IDConexao, String, sizeof(String), "INSERT INTO `Contas` (`Nome`, `Senha`, `Email`, `Code`) VALUES ('%s', '%e', '%s', '%s')", pPlayerInfo[playerid][pNome], pPlayerInfo[playerid][pSenha], pPlayerInfo[playerid][pEmail], coding);
            mysql_tquery(IDConexao, String, "RegisterAccounts", "d", playerid);
            return 1;
        }
        case name_login:
        {
            if(!strlen(inputtext) || !response) return 0;

            format(pPlayerInfo[playerid][pNome], MAX_PLAYER_NAME, inputtext);

            PlayerTextDrawSetString(playerid, TDPlayerLogin[playerid][0], inputtext);
            PlayerTextDrawShow(playerid, TDPlayerLogin[playerid][0]);
            return 1;
        }
        case pass_login:
        {
            if(!strlen(inputtext) || !response) return 0;

            format(pPlayerInfo[playerid][pSenha], MAX_PLAYER_PASS, inputtext);

            for(new i=0; i < strlen(inputtext); i++)
                { inputtext[i] = ']'; }

            PlayerTextDrawSetString(playerid, TDPlayerLogin[playerid][1], inputtext);
            PlayerTextDrawShow(playerid, TDPlayerLogin[playerid][1]);
            return 1;
        }
        case name_register:
        {
            if(!strlen(inputtext) || !response) return 0;

            if(strlen(inputtext) < MIN_PLAYER_NAME || strlen(inputtext) > MAX_PLAYER_NAME)
                return SendClientMessage(playerid, 0xFFFF80AA, "Digite um nome entre 3 a 30 caracteres!");

            if(!IsValidUsername(inputtext))
                return SendClientMessage(playerid, 0xFFFF80AA, "| INFO | Digite um nome sem caracteres especiais!");

            format(pPlayerInfo[playerid][pNome], MAX_PLAYER_NAME, inputtext);

            PlayerTextDrawSetString(playerid, TDPlayerRegister[playerid][0], inputtext);
            PlayerTextDrawShow(playerid, TDPlayerRegister[playerid][0]);
            return 1;
        }
        case pass_register:
        {
            if(!strlen(inputtext) || !response) return 0;

            if(strlen(inputtext) < MIN_PLAYER_PASS || strlen(inputtext) > MAX_PLAYER_PASS)
                return SendClientMessage(playerid, 0xFFFF80AA, "Digite uma senha entre 6 a 30 caracteres!");

            format(pPlayerInfo[playerid][pSenha], MAX_PLAYER_PASS, inputtext);

            for(new i=0; i < strlen(inputtext); i++)
                { inputtext[i] = ']'; }

            PlayerTextDrawSetString(playerid, TDPlayerRegister[playerid][1], inputtext);
            PlayerTextDrawShow(playerid, TDPlayerRegister[playerid][1]);
            return 1;
        }
        case pass_register_confirm:
        {
            if(!strlen(inputtext) || !response) return 0;

            if(strlen(inputtext) < MIN_PLAYER_PASS || strlen(inputtext) > MAX_PLAYER_PASS)
                return SendClientMessage(playerid, 0xFFFF80AA, "Digite uma senha entre 6 a 30 caracteres!");

            format(pPlayerInfo[playerid][pSenhaConfirm], MAX_PLAYER_PASS, inputtext);

            for(new i=0; i < strlen(inputtext); i++)
                { inputtext[i] = ']'; }

            PlayerTextDrawSetString(playerid, TDPlayerRegister[playerid][2], inputtext);
            PlayerTextDrawShow(playerid, TDPlayerRegister[playerid][2]);
            return 1;
        }
        case email_register:
        {
            if(!strlen(inputtext) || !response) return 0;

            if(strlen(inputtext) < MIN_PLAYER_EMAIL || strlen(inputtext) > MAX_PLAYER_EMAIL)
                return SendClientMessage(playerid, 0xFFFF80AA, "Digite um e-mail entre 10 a 50 caracteres!");

            format(pPlayerInfo[playerid][pEmail], MAX_PLAYER_EMAIL, inputtext);

            PlayerTextDrawSetString(playerid, TDPlayerRegister[playerid][3], inputtext);
            PlayerTextDrawShow(playerid, TDPlayerRegister[playerid][3]);
            return 1;
        }
        case sexo_register:
        {
            if(response)
            {
                if(!strcmp(PlayerInfo[playerid][sexo], "Masculino"))
                    return SendClientMessage(playerid, Erro, "Você já selecionou o sexo \"masculino\"");

                format(PlayerInfo[playerid][sexo], 10, "Masculino");
                PlayerInfo[playerid][skin] = DEFAULT_SKIN_BOY;
            }
            else
            {
                if(!strcmp(PlayerInfo[playerid][sexo], "Feminino"))
                    return SendClientMessage(playerid, Erro, "Você já selecionou o sexo \"feminino\"");

                format(PlayerInfo[playerid][sexo], 10, "Feminino");
                PlayerInfo[playerid][skin] = DEFAULT_SKIN_GIRL;
            }

            PlayerTextDrawSetString(playerid, TDPlayerRegister[playerid][4], PlayerInfo[playerid][sexo]);
            PlayerTextDrawShow(playerid, TDPlayerRegister[playerid][4]);
            return 1;
        }
        case recover_account:
        {
            if(!strlen(inputtext) || !response) return 0;

            format(PlayerInfo[playerid][Code], 30, inputtext);

            PlayerTextDrawSetString(playerid, TDPlayerCoding[playerid][0], PlayerInfo[playerid][Code]);
            PlayerTextDrawShow(playerid, TDPlayerCoding[playerid][0]);
            return 1;
        }
        case recover_account_pass:
        {
            if(!strlen(inputtext) || !response) return 0;

            if(strlen(inputtext) < MIN_PLAYER_PASS || strlen(inputtext) > MAX_PLAYER_PASS)
                return SendClientMessage(playerid, 0xFFFF80AA, "Digite uma senha entre 6 a 30 caracteres!");

            format(pPlayerInfo[playerid][pSenha], MAX_PLAYER_PASS, inputtext);

            for(new i=0; i < strlen(inputtext); i++)
                { inputtext[i] = ']'; }

            PlayerTextDrawSetString(playerid, TDPlayerAlterPass[playerid][0], inputtext);
            PlayerTextDrawShow(playerid, TDPlayerAlterPass[playerid][0]);
            return 1;
        }
        case recover_account_pass_ok:
        {
            if(!strlen(inputtext) || !response) return 0;

            if(strlen(inputtext) < MIN_PLAYER_PASS || strlen(inputtext) > MAX_PLAYER_PASS)
                return SendClientMessage(playerid, 0xFFFF80AA, "Digite uma senha entre 6 a 30 caracteres!");

            format(pPlayerInfo[playerid][pSenhaConfirm], MAX_PLAYER_PASS, inputtext);

            for(new i=0; i < strlen(inputtext); i++)
                { inputtext[i] = ']'; }

            PlayerTextDrawSetString(playerid, TDPlayerAlterPass[playerid][1], inputtext);
            PlayerTextDrawShow(playerid, TDPlayerAlterPass[playerid][1]);
            return 1;
        }
    }
    return 1;
}

stock ClickTextDrawLoginRegister(playerid, PlayerText:playertextid)
{
    if(playertextid == TDPlayerLogin[playerid][0])
        return ShowPlayerDialog(playerid, name_login, DIALOG_STYLE_INPUT, "{FF0000}Nome", "{FFFFFF}Digite seu nome em baixo para efetuar login : \n\n{FF0000}AVISO: Se o seu nome tiver caracteres especiais pode ser exibido como espaço,{FFFFFF} \nMas não se preocupe, isso não afetará o nome digitado", "Continuar", "Cancelar");

    if(playertextid == TDPlayerLogin[playerid][1])
        return ShowPlayerDialog(playerid, pass_login, DIALOG_STYLE_PASSWORD, "{FF0000}Senha", "{FFFFFF}Digite sua senha em baixo para efetuar login : \n\n{FF0000}Sua senha será escondida por *", "Continuar", "Cancelar");

    if(playertextid == TDPlayerLogin[playerid][2])
    {
        if(pPlayerInfo[playerid][pNome] == 0 && pPlayerInfo[playerid][pSenha] == 0)
            return SendClientMessage(playerid, Erro, "Preencha os campos para proseguir");

        if(pPlayerInfo[playerid][pNome] == 0)
            return SendClientMessage(playerid, Erro, "Coloque seu nome");

        if(pPlayerInfo[playerid][pSenha] == 0)
            return SendClientMessage(playerid, Erro, "Coloque sua senha");

        mysql_format(IDConexao, String, sizeof(String), "SELECT `Nome` FROM `Contas` WHERE `Nome`='%s'", pPlayerInfo[playerid][pNome]);
        mysql_query(IDConexao, String);

        if(cache_num_rows() == 0)
            return SendClientMessage(playerid, Erro, "Conta não registrada");

        mysql_format(IDConexao, String, sizeof(String), "SELECT `Nome` AND `Senha` FROM `Contas` WHERE `Nome`='%e' AND `Senha`='%e'", pPlayerInfo[playerid][pNome], pPlayerInfo[playerid][pSenha]);
        mysql_query(IDConexao, String);

        if(cache_num_rows() == 0)
            return SendClientMessage(playerid, Erro, "Senha Incorreta");

        mysql_format(IDConexao, String, sizeof(String), "SELECT * FROM `Contas` WHERE Nome='%s'", pPlayerInfo[playerid][pNome]);
        mysql_tquery(IDConexao, String, "LoadAccounts", "d", playerid);
        return 1;
    }

    if(playertextid == TDPlayerLogin[playerid][3]){
        HideTextDrawLogin(playerid);
        TDCodingShow(playerid);
        return 1;
    }

    if(playertextid == TDPlayerLogin[playerid][4])
    {
        PlayerInfo[playerid][sexo] = -1;
        PlayerInfo[playerid][skin] = -1;
        HideTextDrawLogin(playerid);
        ShowTextDrawRegister(playerid);
        return 1;
    }
    if(playertextid == TDPlayerRegister[playerid][0])
        return ShowPlayerDialog(playerid, name_register, DIALOG_STYLE_INPUT, "{FF0000}Nome", "{FFFFFF}Digite seu nome em baixo para efetuar o registro : \n\n{FF0000}AVISO: Se o seu nome tiver caracteres especiais pode ser exibido como espaço,{FFFFFF} \nMas não se preocupe, isso não afetará o nome digitado", "Continuar", "Cancelar");

    if(playertextid == TDPlayerRegister[playerid][1])
        return ShowPlayerDialog(playerid, pass_register, DIALOG_STYLE_PASSWORD, "{FF0000}Senha", "{FFFFFF}Digite sua senha em baixo para efetuar o registro : \n\n{FF0000}Sua senha será escondida por *", "Continuar", "Cancelar");

    if(playertextid == TDPlayerRegister[playerid][2])
        return ShowPlayerDialog(playerid, pass_register_confirm, DIALOG_STYLE_PASSWORD, "{FF0000}Confirmar Senha", "{FFFFFF}Digite à mesma senha que digitou acima para efetuar o registro : \n\n{FF0000}Sua senha será escondida por *", "Continuar", "Cancelar");

    if(playertextid == TDPlayerRegister[playerid][3])
        return ShowPlayerDialog(playerid, email_register, DIALOG_STYLE_INPUT, "{FF0000}E-mail", "{FFFFFF}Digite seu e-mail em baixo para efetuar o registro : \n\n{FF0000}AVISO: Se o seu e-mail tiver caracteres especiais pode ser exibido como espaço,{FFFFFF} \nMas não se preocupe, isso não afetará o e-mail digitado", "Continuar", "Cancelar");

    if(playertextid == TDPlayerRegister[playerid][4])
        return ShowPlayerDialog(playerid, sexo_register, DIALOG_STYLE_MSGBOX, "{FF0000}Sexo", " ", "Masculino", "Feminino");

    if(playertextid == TDPlayerRegister[playerid][5])
    {
        if(pPlayerInfo[playerid][pNome] == 0)
            return SendClientMessage(playerid, Erro, "Coloque seu nome");

        if(pPlayerInfo[playerid][pSenha] == 0)
            return SendClientMessage(playerid, Erro, "Coloque sua senha");

        if(pPlayerInfo[playerid][pSenhaConfirm] == 0)
            return SendClientMessage(playerid, Erro, "Coloque à sua confirmação de senha");

        if(pPlayerInfo[playerid][pEmail] == 0)
            return SendClientMessage(playerid, Erro, "Coloque seu e-mail");

        if(PlayerInfo[playerid][sexo] == -1)
            return SendClientMessage(playerid, Erro, "Selecione seu sexo");

        mysql_format(IDConexao, String, sizeof(String), "SELECT * FROM Contas WHERE Nome='%s'", pPlayerInfo[playerid][pNome]);
        mysql_query(IDConexao, String);

        if(cache_num_rows())
            return SendClientMessage(playerid, Erro, "Nome já em uso, tente outro");

        if(strcmp(pPlayerInfo[playerid][pSenha], pPlayerInfo[playerid][pSenhaConfirm]))
            return SendClientMessage(playerid, Erro, "Às senhas digitadas não são iguais");

        mysql_format(IDConexao, String, sizeof(String), "SELECT * FROM Contas WHERE Email='%s'", pPlayerInfo[playerid][pEmail]);
        mysql_query(IDConexao, String);

        if(cache_num_rows())
            return SendClientMessage(playerid, Erro, "E-mail já em uso, tente outro");

        new coding[10];

        format(coding, 10, CreateRandomCode());

        format(String, sizeof(String),"Código: %s\n\nUse esse código para liberar o registro em nosso Servidor.", coding);
        SendEmail("Henriquecalenzo2018@hotmail.com", pPlayerInfo[playerid][pEmail], "Testes", "O sistema de e-mails realmente funciona.<br>Gostou? visite o <a href=\"http://forum.sa-mp.com\">Fórum SA-MP</a>");

        mysql_format(IDConexao, String, sizeof(String), "INSERT INTO `Contas` (`Nome`, `Senha`, `Email`, `Code`) VALUES ('%s', '%e', '%s', '%s')", pPlayerInfo[playerid][pNome], pPlayerInfo[playerid][pSenha], pPlayerInfo[playerid][pEmail], coding);
        mysql_tquery(IDConexao, String, "RegisterAccounts", "d", playerid);
        return 1;
    }

    //if(playertextid == TDPlayerCoding[playerid][0]) return ShowPlayerDialog(playerid, recover_account, DIALOG_STYLE_INPUT, "{FF0000}Recuperar Conta", "{FFFFFF}Digite abaixo o código de sua conta:", "Continuar", "Cancelar");

    /*
    if(playertextid == TDPlayerCoding[playerid][1])
    {
        if(PlayerInfo[playerid][Code] == 0)
            return SendClientMessage(playerid, Erro, "Coloque o código");

        new query[100];
        mysql_format(IDConexao, query, sizeof(query), "SELECT * FROM `Contas` WHERE `Code`='%e'", PlayerInfo[playerid][Code]);
        mysql_query(IDConexao, query);

        if(cache_num_rows() == 0)
            return SendClientMessage(playerid, Erro, "Código Inválido");

        cache_get_value_int(0, "ID", PlayerInfo[playerid][ID]);

        TDCodingHide(playerid);
        TDAlterPassShow(playerid);
        return 1;
    }
    */

    //if(playertextid == TDPlayerAlterPass[playerid][0]) return ShowPlayerDialog(playerid, recover_account_pass, DIALOG_STYLE_PASSWORD, "{FF0000}Recuperar Conta", "{FFFFFF}Digite abaixo sua nova senha:", "Continuar", "Cancelar");

    if(playertextid == TDPlayerAlterPass[playerid][1])
        return ShowPlayerDialog(playerid, recover_account_pass_ok, DIALOG_STYLE_PASSWORD, "{FF0000}Recuperar Conta", "{FFFFFF}Digite abaixo mais uma vez sua nova senha:", "Continuar", "Cancelar");

    if(playertextid == TDPlayerAlterPass[playerid][2])
    {
        if(pPlayerInfo[playerid][pSenha] == 0)
            return SendClientMessage(playerid, Erro, "Coloque sua nova senha");

        if(pPlayerInfo[playerid][pSenhaConfirm] == 0)
            return SendClientMessage(playerid, Erro, "Coloque a confirmação de sua senha");

        if(strcmp(pPlayerInfo[playerid][pSenha], pPlayerInfo[playerid][pSenhaConfirm]))
            return SendClientMessage(playerid, Erro, "Às senhas não são compatíveis");

        format(PlayerInfo[playerid][Senha], MAX_PLAYER_PASS, pPlayerInfo[playerid][pSenha]);
        TDAlterPassHide(playerid);

        new query[100];
        mysql_format(IDConexao, query, sizeof(query), "UPDATE `Contas` SET `Senha`='%e' WHERE `ID`='%d'", PlayerInfo[playerid][Senha], PlayerInfo[playerid][ID]);
        mysql_query(IDConexao, query);

        mysql_format(IDConexao, query, sizeof(query), "SELECT * FROM `Contas` WHERE `ID`='%d'", PlayerInfo[playerid][ID]);
        mysql_tquery(IDConexao, query, "LoadAccounts", "d", playerid);
        return 1;
    }
    return 1;
}

forward OnPlayerLoginKick(playerid);
public OnPlayerLoginKick(playerid)
{
    if(PlayerInfo[playerid][Logado]) return 0;

    KillTimer(t_login[playerid]);
    Kick(playerid);
    SendClientMessage(playerid, Red, "Você foi kickado por ficar ausente em login/registro por 5 minutos");
    return 1;
}

stock ShowTextDrawLogin(playerid)
{
    for(new i = 0; i < 5; ++i){
        PlayerTextDrawShow(playerid, TDPlayerLogin[playerid][i]); //Pro player
    }
    for(new i = 0; i < 28; ++i){
        TextDrawShowForPlayer(playerid, TDLogin[i]); //Global
    }
    return 1;
}

stock ShowTextDrawRegister(playerid)
{
    for(new i = 0; i < 6; ++i){
        PlayerTextDrawShow(playerid, TDPlayerRegister[playerid][i]); //Pro player
    }
    for(new i = 0; i < 39; ++i){
        TextDrawShowForPlayer(playerid, TDRegister[i]); //Global
    }
    return 1;
}

stock HideTextDrawLogin(playerid)
{
    for(new i = 0; i < 5; ++i){
        PlayerTextDrawHide(playerid, TDPlayerLogin[playerid][i]); //Pro player
    }
    for(new i = 0; i < 28; ++i){
        TextDrawHideForPlayer(playerid, TDLogin[i]); //Global
    }
    return 1;
}

stock HideTextDrawRegister(playerid)
{
    for(new i = 0; i < 6; ++i){
        PlayerTextDrawHide(playerid, TDPlayerRegister[playerid][i]); //Pro player
    }
    for(new i = 0; i < 39; ++i){
        TextDrawHideForPlayer(playerid, TDRegister[i]); //Global
    }
    return 1;
}

stock SkinListName(skinid)
{
    new var[17];
    switch(skinid)
    {
        case 0: var = "Cj_(ID:0)";
        case 1: var = "Truth_(ID:1)";
        case 2: var = "Maccer_(ID:2)";
        case 3: var = "andre_(ID:3)";
        case 4: var = "Bbthin_(ID:4)";
        case 5: var = "Bb_(ID:5)";
        case 6: var = "Emmet_(ID:6)";
        case 7: var = "male01 (ID:7)";
        case 8: var = "janitor (ID:8)";
        case 9: var = "bfori (ID:9)";
        case 10: var = "bfost (ID:10)";
        case 11: var = "vbfycrp (ID:11)";
        case 12: var = "bfyri (ID:12)";
        case 13: var = "bfyst (ID:13)";
        case 14: var = "bmori (ID:14)";
        case 15: var = "bmost (ID:15)";
        case 16: var = "bmyap (ID:16)";
        case 17: var = "bmybu (ID:17)";
        case 18: var = "bmybe (ID:18)";
        case 19: var = "bmydj (ID:19)";
        case 20: var = "bmyri (ID:20)";
        case 21: var = "bmycr (ID:21)";
        case 22: var = "bmyst (ID:22)";
        case 23: var = "wmybmx (ID:23)";
        case 24: var = "wbdyg1 (ID:24)";
        case 25: var = "wbdyg2 (ID:25)";
        case 26: var = "wmybp (ID:26)";
        case 27: var = "wmycon (ID:27)";
        case 28: var = "bmydrug (ID:28)";
        case 29: var = "wmydrug (ID:29)";
        case 30: var = "hmydrug (ID:30)";
        case 31: var = "dwfolc (ID:31)";
        case 32: var = "dwmolc1 (ID:32)";
        case 33: var = "dwmolc2 (ID:33)";
        case 34: var = "dwmylc1 (ID:34)";
        case 35: var = "hmogar (ID:35)";
        case 36: var = "wmygol1 (ID:36)";
        case 37: var = "wmygol2 (ID:37)";
        case 38: var = "hfori (ID:38)";
        case 39: var = "hfost (ID:39)";
        case 40: var = "hfyri (ID:40)";
        case 41: var = "hfyst (ID:41)";
        case 42: var = "jethro (ID:42)";
        case 43: var = "hmori (ID:43)";
        case 44: var = "hmost (ID:44)";
        case 45: var = "hmybe (ID:45)";
        case 46: var = "hmyri (ID:46)";
        case 47: var = "hmycr (ID:47)";
        case 48: var = "hmyst (ID:48)";
        case 49: var = "omokung (ID:49)";
        case 50: var = "wmymech (ID:50)";
        case 51: var = "bmymoun (ID:51)";
        case 52: var = "wmymoun (ID:52)";
        case 53: var = "ofori (ID:53)";
        case 54: var = "ofost (ID:54)";
        case 55: var = "ofyri (ID:55)";
        case 56: var = "ofyst (ID:56)";
        case 57: var = "omori (ID:57)";
        case 58: var = "omost (ID:58)";
        case 59: var = "omyri (ID:59)";
        case 60: var = "omyst (ID:60)";
        case 61: var = "wmyplt (ID:61)";
        case 62: var = "wmopj (ID:62)";
        case 63: var = "bfypro (ID:63)";
        case 64: var = "hfypro (ID:64)";
        case 65: var = "kendl (ID:65)";
        case 66: var = "bmypol1 (ID:66)";
        case 67: var = "bmypol2 (ID:67)";
        case 68: var = "wmoprea (ID:68)";
        case 69: var = "sbfyst (ID:69)";
        case 70: var = "wmosci (ID:70)";
        case 71: var = "wmysgrd (ID:71)";
        case 72: var = "swmyhp1 (ID:72)";
        case 73: var = "swmyhp2 (ID:73)";
        case 74: var = "Sem Nome (ID:74)";
        case 75: var = "swfopro (ID:75)";
        case 76: var = "wfystew (ID:76)";
        case 77: var = "swmotr1 (ID:77)";
        case 78: var = "wmotr1 (ID:78)";
        case 79: var = "bmotr1 (ID:79)";
        case 80: var = "vbmybox (ID:80)";
        case 81: var = "vwmybox (ID:81)";
        case 82: var = "vhmyelv (ID:82)";
        case 83: var = "vbmyelv (ID:83)";
        case 84: var = "vimyelv (ID:84)";
        case 85: var = "vwfypro (ID:85)";
        case 86: var = "ryder3 (ID:86)";
        case 87: var = "vwfyst1 (ID:87)";
        case 88: var = "wfori (ID:88)";
        case 89: var = "wfost (ID:89)";
        case 90: var = "wfyjg (ID:90)";
        case 91: var = "wfyri (ID:91)";
        case 92: var = "wfyro (ID:92)";
        case 93: var = "wfyst (ID:93)";
        case 94: var = "wmori (ID:94)";
        case 95: var = "wmost (ID:95)";
        case 96: var = "wmyjg (ID:96)";
        case 97: var = "wmylg (ID:97)";
        case 98: var = "wmyri (ID:98)";
        case 99: var = "wmyro (ID:99)";
        case 100: var = "wmycr (ID:100)";
        case 101: var = "wmyst (ID:101)";
        case 102: var = "ballas1 (ID:102)";
        case 103: var = "ballas2 (ID:103)";
        case 104: var = "ballas3 (ID:104)";
        case 105: var = "fam1 (ID:105)";
        case 106: var = "fam2 (ID:106)";
        case 107: var = "fam3 (ID:107)";
        case 108: var = "lsv1 (ID:108)";
        case 109: var = "lsv2 (ID:109)";
        case 110: var = "lsv3 (ID:110)";
        case 111: var = "maffa (ID:111)";
        case 112: var = "maffb (ID:112)";
        case 113: var = "mafboss (ID:113)";
        case 114: var = "vla1 (ID:114)";
        case 115: var = "vla2 (ID:115)";
        case 116: var = "vla3 (ID:116)";
        case 117: var = "triada (ID:117)";
        case 118: var = "triadb (ID:118)";
        case 119: var = "sindaco (ID:119)";
        case 120: var = "triboss (ID:120)";
        case 121: var = "dnb1 (ID:121)";
        case 122: var = "dnb2 (ID:122)";
        case 123: var = "dnb3 (ID:123)";
        case 124: var = "vmaff1 (ID:124)";
        case 125: var = "vmaff2 (ID:125)";
        case 126: var = "vmaff3 (ID:126)";
        case 127: var = "vmaff4 (ID:127)";
        case 128: var = "dnmylc (ID:128)";
        case 129: var = "dnfolc1 (ID:129)";
        case 130: var = "dnfolc2 (ID:130)";
        case 131: var = "dnfylc (ID:131)";
        case 132: var = "dnmolc1 (ID:132)";
        case 133: var = "dnmolc2 (ID:133)";
        case 134: var = "sbmotr2 (ID:134)";
        case 135: var = "swmotr2 (ID:135)";
        case 136: var = "sbmytr3 (ID:136)";
        case 137: var = "swmotr3 (ID:137)";
        case 138: var = "wfybe (ID:138)";
        case 139: var = "bfybe (ID:139)";
        case 140: var = "hfybe (ID:140)";
        case 141: var = "sofybu (ID:141)";
        case 142: var = "sbmyst (ID:142)";
        case 143: var = "sbmycr (ID:143)";
        case 144: var = "bmycg (ID:144)";
        case 145: var = "wfycrk (ID:145)";
        case 146: var = "hmycm (ID:146)";
        case 147: var = "wmybu (ID:147)";
        case 148: var = "bfybu (ID:148)";
        case 149: var = "smokev (ID:149)";
        case 150: var = "wfybu (ID:150)";
        case 151: var = "dwfylc1 (ID:151)";
        case 152: var = "wfypro (ID:152)";
        case 153: var = "wmyconb (ID:153)";
        case 154: var = "wmybe (ID:154)";
        case 155: var = "wmypizz (ID:155)";
        case 156: var = "bmobar (ID:156)";
        case 157: var = "cwfyhb (ID:157)";
        case 158: var = "cwmofr (ID:158)";
        case 159: var = "cwmohb1 (ID:159)";
        case 160: var = "cwmohb2 (ID:160)";
        case 161: var = "cwmyfr (ID:161)";
        case 162: var = "cwmyhb1 (ID:162)";
        case 163: var = "bmyboun (ID:163)";
        case 164: var = "wmyboun (ID:164)";
        case 165: var = "wmomib (ID:165)";
        case 166: var = "bmymib (ID:166)";
        case 167: var = "wmybell (ID:167)";
        case 168: var = "bmochil (ID:168)";
        case 169: var = "sofyri (ID:169)";
        case 170: var = "somyst (ID:170)";
        case 171: var = "vwmybjd (ID:171)";
        case 172: var = "vwfycrp (ID:172)";
        case 173: var = "sfr1 (ID:173)";
        case 174: var = "sfr2 (ID:174)";
        case 175: var = "sfr3 (ID:175)";
        case 176: var = "bmybar (ID:176)";
        case 177: var = "wmybar (ID:177)";
        case 178: var = "wfysex (ID:178)";
        case 179: var = "wmyammo (ID:179)";
        case 180: var = "bmytatt (ID:180)";
        case 181: var = "vwmycr (ID:181)";
        case 182: var = "vbmocd (ID:182)";
        case 183: var = "vbmycr (ID:183)";
        case 184: var = "vhmycr (ID:184)";
        case 185: var = "sbmyri (ID:185)";
        case 186: var = "somyri (ID:186)";
        case 187: var = "somybu (ID:187)";
        case 188: var = "swmyst (ID:188)";
        case 189: var = "wmyva (ID:189)";
        case 190: var = "copgrl3 (ID:190)";
        case 191: var = "gungrl3 (ID:191)";
        case 192: var = "mecgrl3 (ID:192)";
        case 193: var = "nurgrl3 (ID:193)";
        case 194: var = "crogrl3 (ID:194)";
        case 195: var = "gangrl3 (ID:195)";
        case 196: var = "cwfofr (ID:196)";
        case 197: var = "cwfohb (ID:197)";
        case 198: var = "cwfyfr1 (ID:198)";
        case 199: var = "cwfyfr2 (ID:199)";
        case 200: var = "cwmyhb2 (ID:200)";
        case 201: var = "dwfylc2 (ID:201)";
        case 202: var = "dwmylc2 (ID:202)";
        case 203: var = "omykara (ID:203)";
        case 204: var = "wmykara (ID:204)";
        case 205: var = "wfyburg (ID:205)";
        case 206: var = "vwmycd (ID:206)";
        case 207: var = "vhfypro (ID:207)";
        case 208: var = "suzie (ID:208)";
        case 209: var = "omonood (ID:209)";
        case 210: var = "omoboat (ID:210)";
        case 211: var = "wfyclot (ID:211)";
        case 212: var = "vwmotr1 (ID:212)";
        case 213: var = "vwmotr2 (ID:213)";
        case 214: var = "vwfywai (ID:214)";
        case 215: var = "sbfori (ID:215)";
        case 216: var = "swfyri (ID:216)";
        case 217: var = "wmyclot (ID:217)";
        case 218: var = "sbfost (ID:218)";
        case 219: var = "sbfyri (ID:219)";
        case 220: var = "sbmocd (ID:220)";
        case 221: var = "sbmori (ID:221)";
        case 222: var = "sbmost (ID:222)";
        case 223: var = "shmycr (ID:223)";
        case 224: var = "sofori (ID:224)";
        case 225: var = "sofost (ID:225)";
        case 226: var = "sofyst (ID:226)";
        case 227: var = "somobu (ID:227)";
        case 228: var = "somori (ID:228)";
        case 229: var = "somost (ID:229)";
        case 230: var = "swmotr5 (ID:230)";
        case 231: var = "swfori (ID:231)";
        case 232: var = "swfost (ID:232)";
        case 233: var = "swfyst (ID:233)";
        case 234: var = "swmocd (ID:234)";
        case 235: var = "swmori (ID:235)";
        case 236: var = "swmost (ID:236)";
        case 237: var = "shfypro (ID:237)";
        case 238: var = "sbfypro (ID:238)";
        case 239: var = "swmotr4 (ID:239)";
        case 240: var = "swmyri (ID:240)";
        case 241: var = "smyst (ID:241)";
        case 242: var = "smyst2 (ID:242)";
        case 243: var = "sfypro (ID:243)";
        case 244: var = "vbfyst2 (ID:244)";
        case 245: var = "vbfypro (ID:245)";
        case 246: var = "vhfyst3 (ID:246)";
        case 247: var = "bikera (ID:247)";
        case 248: var = "bikerb (ID:248)";
        case 249: var = "bmypimp (ID:249)";
        case 250: var = "swmycr (ID:250)";
        case 251: var = "wfylg (ID:251)";
        case 252: var = "wmyva2 (ID:252)";
        case 253: var = "bmosec (ID:253)";
        case 254: var = "bikdrug (ID:254)";
        case 255: var = "wmych (ID:255)";
        case 256: var = "sbfystr (ID:256)";
        case 257: var = "swfystr (ID:257)";
        case 258: var = "heck1 (ID:258)";
        case 259: var = "heck2 (ID:259)";
        case 260: var = "bmycon (ID:260)";
        case 261: var = "wmycd1 (ID:261)";
        case 262: var = "bmocd (ID:262)";
        case 263: var = "vwfywa2 (ID:263)";
        case 264: var = "wmoice (ID:264)";
        case 265: var = "tenpen (ID:265)";
        case 266: var = "pulaski (ID:266)";
        case 267: var = "hern (ID:267)";
        case 268: var = "dwayne (ID:268)";
        case 269: var = "smoke (ID:269)";
        case 270: var = "sweet (ID:270)";
        case 271: var = "ryder (ID:271)";
        case 272: var = "forelli (ID:272)";
        case 273: var = "tbone (ID:273)";
        case 274: var = "laemt1 (ID:274)";
        case 275: var = "lvemt1 (ID:275)";
        case 276: var = "sfemt1 (ID:276)";
        case 277: var = "lafd1 (ID:277)";
        case 278: var = "lvfd1 (ID:278)";
        case 279: var = "sffd1 (ID:279)";
        case 280: var = "lapd1 (ID:280)";
        case 281: var = "sfpd1 (ID:281)";
        case 282: var = "lvpd1 (ID:282)";
        case 283: var = "csher (ID:283)";
        case 284: var = "lapdm1 (ID:284)";
        case 285: var = "swat (ID:285)";
        case 286: var = "fbi (ID:286)";
        case 287: var = "army (ID:287)";
        case 288: var = "dsher (ID:288)";
        case 289: var = "zero (ID:289)";
        case 290: var = "rose (ID:290)";
        case 291: var = "paul (ID:291)";
        case 292: var = "cesar (ID:292)";
        case 293: var = "ogloc (ID:293)";
        case 294: var = "wuzimu (ID:294)";
        case 295: var = "torino (ID:295)";
        case 296: var = "jizzy (ID:296)";
        case 297: var = "maddogg (ID:297)";
        case 298: var = "cat (ID:298)";
        case 299: var = "claude (ID:299)";
        case 300: var = "lapdna (ID:300)";
        case 301: var = "sfpdna (ID:301)";
        case 302: var = "lvpdna (ID:302)";
        case 303: var = "lapdpc (ID:303)";
        case 304: var = "lapdpd (ID:304)";
        case 305: var = "lvpdpc (ID:305)";
        case 306: var = "wfyclpd (ID:306)";
        case 307: var = "vbfycpd (ID:307)";
        case 308: var = "wfyclem (ID:308)";
        case 309: var = "wfycllv (ID:309)";
        case 310: var = "csherna (ID:310)";
        case 311: var = "dsherna (ID:311)";
    }
    return var;
}
