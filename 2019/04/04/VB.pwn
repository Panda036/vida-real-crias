#include                                                              < a_samp >
#include                                                             < a_mysql >
#include                                                             < sscanf2 >
#include                                                             < foreach >
#include                                                            < streamer >

/////////// MSGS FORMATAdAS ////////////
#define MessageFormat(%1,%2,%3,%4) do{format(String,sizeof(String),%3,%4);\
SendClientMessage(%1,%2,String );}while(IsPlayerConnected(-1))
#define MessageFormatAll(%1,%2,%3) do{format(String,sizeof(String),%2,%3);\
SendClientMessageToAll(%1,String );}while(IsPlayerConnected(-1))

#define segundos(%0) (1000 * %0)
#define minutos(%0) (1000 * %0 * 60)
#define horas(%0) (1000 * %0 * 60 * 60)
#define dias(%0) (1000 * %0 * 60 * 60  * 24)
#define semanas(%0) (1000 * %0 * 60 * 60  * 24 * 7)
#define meses(%0) (1000 * %0 * 60 * 60  * 24 * 30)
#define anos(%0) (1000 * %0 * 60 * 60  * 24 * 30 * 12)
#define decadas(%0) (1000 * %0 * 60 * 60  * 24 * 30 * 12 * 10)
#define seculos(%0) (1000 * %0 * 60 * 60  * 24 * 30 * 12 * 10 * 10)

#define Kick(%0) SetTimerEx("Kicka", 100, false, "i", %0)
#define Ban(%0) SetTimerEx("Bana", 100, false, "i", %0)

#define PRESSED(%0) \
    (((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))

/////////////// MAX_MIN //////////////
#undef MAX_PLAYERS
#define MAX_PLAYERS                 20
#undef MAX_PLAYER_NAME
#define MAX_PLAYER_NAME             24
#define MIN_PLAYER_NAME             6
#define MAX_PLAYER_PASS             24
#define MIN_PLAYER_PASS             6
#define MIN_PLAYER_EMAIL            15
#define MAX_PLAYER_EMAIL            50
#define MAX_CHECKPOINTS            500

////////////// DEFINES ///////////////
#define MenuAgencia               1000
#define MenuMafia                 1001
#define Honesta                   1002
#define Transporte                1003
#define Policia                   1004
#define Governo                   1005
#define menuajuda                 1006
#define menutunagem               1007
#define menuapaintjob             1008
#define menunitro                 1009
#define menuhidraulica            1010
#define menuroda                  1011
#define TAGVIP                    1012
#define mudarnick                 1013
#define menuradio                 1014

////////////// CORES GM //////////////
#define Branco              0xFFFFFFAA
#define Azul                0x0000FFAA
#define Verde               0x00FF40AA
#define Verde_Escurinho     0x00C40AAA
#define Verde_Escuro        0x00C40AAA
#define Vermelho            0xFF0000AA
#define Amarelo             0xFFFF00AA
#define Laranja             0xFF8000AA
#define Rosa                0xFF00FFAA
#define Roxo                0x8000FFAA
#define Erro                0xFF4000AA
#define Aviso               0xFFFF80AA
#define adm                 0xB0FF30AA
#define c_vip               0x0080FFAA
#define C_Info              0xFFFF00AA

////////////// HONESTA ///////////////
#define Desempregado                0
#define EntregadorJornal            1

///////////// TRANSPORTE /////////////
#define Taxi                        2

////////////// POLICIA ///////////////
#define Policia_Civil               3

////////////// POLICIA ///////////////
#define Corregedoria                4

/////////////// MAFIA ////////////////
#define Ladrao_de_Gas               5

//////////// COR EMPREGOS ////////////
#define C_Desempregado      0xFFFFFFAA
#define C_EntregadorJornal  0x80FF80AA
#define C_Taxi              0xFFFF00AA
#define C_Policia_Civil     0x359AFFAA
#define C_Corregedoria      0x8080C0AA
#define C_Ladrao_de_Gas     0xFF8080AA

////////// SALARIO EMPREGOS //////////
#define Salarios_Desempregado      150
#define Salarios_EntregadorJornal  500
#define Salarios_C_Taxi            500
#define Salarios_Policia_Civil    1000

enum pInfo
{
    ID,
    IP,
    Profissao,
    Semprofissao,
    Nome,
    Senha,
    Email,
    Admin,
    minUP,
    segUP,
    Level,
    Exp,
    Coins,
    Vip,
    CorVIP,
    Vencimento,
    Skin,
    Avisos,
    Dinheiro,
    Banco,
    Matou,
    Morreu,
    Interior,
    Preso,
    MotivoPrisao,
    Float:PosX,
    Float:PosY,
    Float:PosZ,
    Float:PosA,
    bool:Afk,
    bool:Logado
}

enum attached_object_data
{
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

enum e_hospital
{
	Float:xH,
	Float:yH,
	Float:zH,
	Float:xH2,
	Float:yH2,
	Float:zH3,
	interior
};

enum
{
    NAME_LOGIN,
    PASS_LOGIN,
    NAME_REGISTER,
    PASS_REGISTER,
    EMAIL_REGISTER
};

enum rankingEnum
{
    player_Score,
    player_ID
}

enum ppInfo
{
    pNome[MAX_PLAYER_NAME],
    pSenha[MAX_PLAYER_PASS],
    pEmail[MAX_PLAYER_EMAIL],
};

new pPlayerInfo[MAX_PLAYERS][ppInfo];
new PlayerInfo[MAX_PLAYERS][pInfo];
new ao[MAX_PLAYERS][MAX_PLAYER_ATTACHED_OBJECTS][attached_object_data];

//Variáveis
new MySQL:IDConexao;
new tmp[256], tmp2[256], tmp3[256];
new String[256], Query[5000];
new ProfissaoonAgencia[MAX_PLAYERS];
new ProfissaoonMafia[MAX_PLAYERS];
new TempoPreso[MAX_PLAYERS];
new CarroAdmin[MAX_PLAYERS];
new SkinPlayer[MAX_PLAYERS];
new UPRelogio[MAX_PLAYERS];
new AvisoBAN[MAX_PLAYERS];
new Float:X, Float:Y, Float:Z, Float:A;
new Ano, Mes, Dia, Hora, Min, Seg;
new Sem_Chat_Global=0;
new IPP[32], id, Cor1, Cor2;
new TimerProcurando[MAX_PLAYERS];
new localizado[MAX_PLAYERS]=0;
new LocalizarID[MAX_PLAYERS]=0;

//Ladrao Gas
new bool:PegouGas[MAX_PLAYERS];

//Veiculos de Profissão
new CRRTAXI[6];
new BKJORNAL[15];
new VCPOLICIA[38];
new BKNOVATOS[5];
new CARROLG[6];

//Boleanas
new bool:LiberarRelatorio[MAX_PLAYERS char];
new bool:LiberarDuvida[MAX_PLAYERS char];
new bool:TemDuvidaOuRelatorio[MAX_PLAYERS char];
new bool:cVehicle[MAX_PLAYERS];
new bool:Algemado[MAX_PLAYERS];
new bool:Abordado[MAX_PLAYERS];
new bool:Respawnando;

//Textdraw
new PlayerText:PlayerLogin[MAX_PLAYERS][13];
new PlayerText:PlayerRegistro[MAX_PLAYERS][21];
new PlayerText:PlayerStatus[MAX_PLAYERS][29];
new PlayerText:CarregandoInterior[MAX_PLAYERS];
new PlayerText:PlayerPreso[MAX_PLAYERS][3];
new Text:RespawnVeiculos;
new Text:txtDateDisp;
new Text:txtTimeDisp;

//Checkpoints
new cp_mafia;
new cp_agencia;
new cp_profissoes[MAX_PLAYERS];

//Pickups sistema do entrar
new entrando[MAX_PLAYERS];

//Portas
new PortaPolicia;

//contador
new Count = 5;
new ContadorTxT[5][19] ={
	"~y~] ]~w~ 1 ~y~] ]",
	"~y~] ]~w~ 2 ~y~] ]",
	"~r~] ]~w~ 3 ~r~] ]",
	"~r~] ]~w~ 4 ~r~] ]",
	"~r~] ]~w~ 5 ~r~] ]"
};

new MSGs[16][128] =
{
    "{FFFFFF}[!] {76EE00}Para ver seu level ~~> /Meulevel",
    "{FFFFFF}[!] {76EE00}Jogar em nosso servidor é um privilegio e não direito!",
    "{FFFFFF}[!] {76EE00}Ofensa á Staff Será Punido com Ban",
    "{FFFFFF}[!] {76EE00}Se cadastrem no Fórum e fique por dentro das novidades ~~> /Ajuda ~~> Contatos",
    "{FFFFFF}[!] {76EE00}Viu uma pessoa dando Teleporte? /Relatorio",
    "{FFFFFF}[!] {FF8C00}Inscreva-se em nosso canal no YouTube: www.youtube.com/channel/UCMijwRnIbRf2RerUEST-sqg?view_as=subscriber",
    "{FFFFFF}[!] {76EE00}Deseja VIP ? Acesse nosso site e confira: www.vidabrasileira.forumeiros.com",
    "{FFFFFF}[!] {76EE00}Bem vindo(a) ao Vida Brasileira",
    "{FFFFFF}[!] {76EE00}Para ver os Players Level Alto Digite ~~> /Toplevel",
    "{FFFFFF}[!] {76EE00}Chame Seus Amigo pro Servidor Fica Mais Divertido",
    "{FFFFFF}[!] {76EE00}Para evitar punições, sempre respeite as regras, use: /Regras",
    "{FFFFFF}[!] {76EE00}Caso esteja com pouco combustivel, procure um dos 10 postos espalhados por San Andreas",
    "{FFFFFF}[!] {76EE00}Veja Todos Contatos do Servidor: /Ajuda ~~> Contatos",
    "{FFFFFF}[!] {76EE00}Para denuciar Cheaters ou Abusers ~~> /Relatorio",
    "{FFFFFF}[!] {76EE00}Para ver as vantagens VIP /Vantagensvip",
    "{FFFFFF}[!] {76EE00}Está precisando de ajuda e não tem nenhum admin online ? ~~> /Ajuda"
};

new PlayerVehicle[212][] =
{
    "Landstalker", "Bravura", "Buffalo", "Linerunner", "Perrenial", "Sentinel", "Dumper", "Firetruck", "Trashmaster", "Stretch", "Manana",
    "Infernus", "Voodoo", "Pony", "Mule", "Cheetah", "Ambulance", "Leviathan", "Moonbeam", "Esperanto", "Taxi", "Washington", "Bobcat",
    "Whoopee", "BF Injection", "Hunter", "Premier", "Enforcer", "Securicar", "Banshee", "Predator", "Bus", "Rhino", "Barracks", "Hotknife",
    "Trailer 1", "Previon", "Coach", "Cabbie", "Stallion", "Rumpo", "RC Bandit", "Romero", "Packer", "Monster", "Admiral", "Squalo",
    "Seasparrow", "Pizzaboy", "Tram", "Trailer 2", "Turismo", "Speeder", "Reefer", "Tropic", "Flatbed", "Yankee", "Caddy", "Solair",
    "Berkley's RC Van", "Skimmer", "PCJ-600", "Faggio", "Freeway", "RC Baron", "RC Raider", "Glendale", "Oceanic", "Sanchez", "Sparrow",
    "Patriot", "Quad", "Coastguard", "Dinghy", "Hermes", "Sabre", "Rustler", "ZR-350", "Walton", "Regina", "Comet", "BMX", "Burrito",
    "Camper", "Marquis", "Baggage", "Dozer", "Maverick", "News Chopper", "Rancher", "FBI Rancher", "Virgo", "Greenwood", "Jetmax", "Hotring",
    "Sandking", "Blista Compact", "Police Maverick", "Boxvillde", "Benson", "Mesa", "RC Goblin", "Hotring Racer A", "Hotring Racer B",
    "Bloodring Banger", "Rancher", "Super GT", "Elegant", "Journey", "Bike", "Mountain Bike", "Beagle", "Cropduster","Stunt",  "Tanker",
    "Roadtrain", "Nebula", "Majestic", "Buccaneer", "Shamal", "Hydra", "FCR-900", "NRG-500", "HPV1000", "Cement Truck", "Tow Truck", "Fortune",
    "Cadrona", "FBI Truck", "Willard", "Forklift", "Tractor", "Combine", "Feltzer", "Remington", "Slamvan", "Blade", "Freight", "Streak",
    "Vortex", "Vincent", "Bullet", "Clover", "Sadler", "Firetruck LA", "Hustler", "Intruder", "Primo", "Cargobob", "Tampa", "Sunrise", "Merit",
    "Utility", "Nevada", "Yosemite", "Windsor", "Monster A", "Monster B", "Uranus", "Jester", "Sultan", "Stratum", "Elegy", "Raindance",
    "RC Tiger", "Flash", "Tahoma", "Savanna", "Bandito", "Freight Flat", "Streak Carriage", "Kart", "Mower", "Dune", "Sweeper", "Broadway",
    "Tornado", "AT-400", "DFT-30", "Huntley", "Stafford", "BF-400", "News Van", "Tug", "Trailer 3", "Emperor", "Wayfarer", "Euros", "Hotdog",
    "Club", "Freight Carriage", "Trailer 4", "Andromada", "Dodo", "RC Cam", "Launch", "Police Car (LSPD)", "Police Car (SFPD)",
    "Police Car (LVPD)", "Police Ranger", "Picador", "S.W.A.T", "Alpha", "Phoenix", "Glendale", "Sadler", "Luggage Trailer A",
    "Luggage Trailer B", "Stairs", "Boxville", "Tiller", "Utility Trailer"
};

enum SAZONE_MAIN
{
    SAZONE_NAME[28],
    Float:SAZONE_AREA[6]
};

static const gSAZones[][SAZONE_MAIN] =
{
{"The Big Ear",	                {-410.00,1403.30,-3.00,-137.90,1681.20,200.00}},
{"Aldea Malvada",               {-1372.10,2498.50,0.00,-1277.50,2615.30,200.00}},
{"Angel Pine",                  {-2324.90,-2584.20,-6.10,-1964.20,-2212.10,200.00}},
{"Arco del Oeste",              {-901.10,2221.80,0.00,-592.00,2571.90,200.00}},
{"Avispa Country Club",         {-2646.40,-355.40,0.00,-2270.00,-222.50,200.00}},
{"Avispa Country Club",         {-2831.80,-430.20,-6.10,-2646.40,-222.50,200.00}},
{"Avispa Country Club",         {-2361.50,-417.10,0.00,-2270.00,-355.40,200.00}},
{"Avispa Country Club",         {-2667.80,-302.10,-28.80,-2646.40,-262.30,71.10}},
{"Avispa Country Club",         {-2470.00,-355.40,0.00,-2270.00,-318.40,46.10}},
{"Avispa Country Club",         {-2550.00,-355.40,0.00,-2470.00,-318.40,39.70}},
{"Back o Beyond",               {-1166.90,-2641.10,0.00,-321.70,-1856.00,200.00}},
{"Battery Point",               {-2741.00,1268.40,-4.50,-2533.00,1490.40,200.00}},
{"Bayside",                     {-2741.00,2175.10,0.00,-2353.10,2722.70,200.00}},
{"Bayside Marina",              {-2353.10,2275.70,0.00,-2153.10,2475.70,200.00}},
{"Beacon Hill",                 {-399.60,-1075.50,-1.40,-319.00,-977.50,198.50}},
{"Blackfield",                  {964.30,1203.20,-89.00,1197.30,1403.20,110.90}},
{"Blackfield",                  {964.30,1403.20,-89.00,1197.30,1726.20,110.90}},
{"Blackfield Chapel",           {1375.60,596.30,-89.00,1558.00,823.20,110.90}},
{"Blackfield Chapel",           {1325.60,596.30,-89.00,1375.60,795.00,110.90}},
{"Blackfield Intersection",     {1197.30,1044.60,-89.00,1277.00,1163.30,110.90}},
{"Blackfield Intersection",     {1166.50,795.00,-89.00,1375.60,1044.60,110.90}},
{"Blackfield Intersection",     {1277.00,1044.60,-89.00,1315.30,1087.60,110.90}},
{"Blackfield Intersection",     {1375.60,823.20,-89.00,1457.30,919.40,110.90}},
{"Blueberry",                   {104.50,-220.10,2.30,349.60,152.20,200.00}},
{"Blueberry",                   {19.60,-404.10,3.80,349.60,-220.10,200.00}},
{"Blueberry Acres",             {-319.60,-220.10,0.00,104.50,293.30,200.00}},
{"Caligula's Palace",           {2087.30,1543.20,-89.00,2437.30,1703.20,110.90}},
{"Caligula's Palace",           {2137.40,1703.20,-89.00,2437.30,1783.20,110.90}},
{"Calton Heights",              {-2274.10,744.10,-6.10,-1982.30,1358.90,200.00}},
{"Chinatown",                   {-2274.10,578.30,-7.60,-2078.60,744.10,200.00}},
{"City Hall",                   {-2867.80,277.40,-9.10,-2593.40,458.40,200.00}},
{"Come-A-Lot",                  {2087.30,943.20,-89.00,2623.10,1203.20,110.90}},
{"Commerce",                    {1323.90,-1842.20,-89.00,1701.90,-1722.20,110.90}},
{"Commerce",                    {1323.90,-1722.20,-89.00,1440.90,-1577.50,110.90}},
{"Commerce",                    {1370.80,-1577.50,-89.00,1463.90,-1384.90,110.90}},
{"Commerce",                    {1463.90,-1577.50,-89.00,1667.90,-1430.80,110.90}},
{"Commerce",                    {1583.50,-1722.20,-89.00,1758.90,-1577.50,110.90}},
{"Commerce",                    {1667.90,-1577.50,-89.00,1812.60,-1430.80,110.90}},
{"Conference Center",           {1046.10,-1804.20,-89.00,1323.90,-1722.20,110.90}},
{"Conference Center",           {1073.20,-1842.20,-89.00,1323.90,-1804.20,110.90}},
{"Cranberry Station",           {-2007.80,56.30,0.00,-1922.00,224.70,100.00}},
{"Creek",                       {2749.90,1937.20,-89.00,2921.60,2669.70,110.90}},
{"Dillimore",                   {580.70,-674.80,-9.50,861.00,-404.70,200.00}},
{"Doherty",                     {-2270.00,-324.10,-0.00,-1794.90,-222.50,200.00}},
{"Doherty",                     {-2173.00,-222.50,-0.00,-1794.90,265.20,200.00}},
{"Downtown",                    {-1982.30,744.10,-6.10,-1871.70,1274.20,200.00}},
{"Downtown",                    {-1871.70,1176.40,-4.50,-1620.30,1274.20,200.00}},
{"Downtown",                    {-1700.00,744.20,-6.10,-1580.00,1176.50,200.00}},
{"Downtown",                    {-1580.00,744.20,-6.10,-1499.80,1025.90,200.00}},
{"Downtown",                    {-2078.60,578.30,-7.60,-1499.80,744.20,200.00}},
{"Downtown",                    {-1993.20,265.20,-9.10,-1794.90,578.30,200.00}},
{"Downtown Los Santos",         {1463.90,-1430.80,-89.00,1724.70,-1290.80,110.90}},
{"Downtown Los Santos",         {1724.70,-1430.80,-89.00,1812.60,-1250.90,110.90}},
{"Downtown Los Santos",         {1463.90,-1290.80,-89.00,1724.70,-1150.80,110.90}},
{"Downtown Los Santos",         {1370.80,-1384.90,-89.00,1463.90,-1170.80,110.90}},
{"Downtown Los Santos",         {1724.70,-1250.90,-89.00,1812.60,-1150.80,110.90}},
{"Downtown Los Santos",         {1370.80,-1170.80,-89.00,1463.90,-1130.80,110.90}},
{"Downtown Los Santos",         {1378.30,-1130.80,-89.00,1463.90,-1026.30,110.90}},
{"Downtown Los Santos",         {1391.00,-1026.30,-89.00,1463.90,-926.90,110.90}},
{"Downtown Los Santos",         {1507.50,-1385.20,110.90,1582.50,-1325.30,335.90}},
{"East Beach",                  {2632.80,-1852.80,-89.00,2959.30,-1668.10,110.90}},
{"East Beach",                  {2632.80,-1668.10,-89.00,2747.70,-1393.40,110.90}},
{"East Beach",                  {2747.70,-1668.10,-89.00,2959.30,-1498.60,110.90}},
{"East Beach",                  {2747.70,-1498.60,-89.00,2959.30,-1120.00,110.90}},
{"East Los Santos",             {2421.00,-1628.50,-89.00,2632.80,-1454.30,110.90}},
{"East Los Santos",             {2222.50,-1628.50,-89.00,2421.00,-1494.00,110.90}},
{"East Los Santos",             {2266.20,-1494.00,-89.00,2381.60,-1372.00,110.90}},
{"East Los Santos",             {2381.60,-1494.00,-89.00,2421.00,-1454.30,110.90}},
{"East Los Santos",             {2281.40,-1372.00,-89.00,2381.60,-1135.00,110.90}},
{"East Los Santos",             {2381.60,-1454.30,-89.00,2462.10,-1135.00,110.90}},
{"East Los Santos",             {2462.10,-1454.30,-89.00,2581.70,-1135.00,110.90}},
{"Easter Basin",                {-1794.90,249.90,-9.10,-1242.90,578.30,200.00}},
{"Easter Basin",                {-1794.90,-50.00,-0.00,-1499.80,249.90,200.00}},
{"Easter Bay Airport",          {-1499.80,-50.00,-0.00,-1242.90,249.90,200.00}},
{"Easter Bay Airport",          {-1794.90,-730.10,-3.00,-1213.90,-50.00,200.00}},
{"Easter Bay Airport",          {-1213.90,-730.10,0.00,-1132.80,-50.00,200.00}},
{"Easter Bay Airport",          {-1242.90,-50.00,0.00,-1213.90,578.30,200.00}},
{"Easter Bay Airport",          {-1213.90,-50.00,-4.50,-947.90,578.30,200.00}},
{"Easter Bay Airport",          {-1315.40,-405.30,15.40,-1264.40,-209.50,25.40}},
{"Easter Bay Airport",          {-1354.30,-287.30,15.40,-1315.40,-209.50,25.40}},
{"Easter Bay Airport",          {-1490.30,-209.50,15.40,-1264.40,-148.30,25.40}},
{"Easter Bay Chemicals",        {-1132.80,-768.00,0.00,-956.40,-578.10,200.00}},
{"Easter Bay Chemicals",        {-1132.80,-787.30,0.00,-956.40,-768.00,200.00}},
{"El Castillo del Diablo",      {-464.50,2217.60,0.00,-208.50,2580.30,200.00}},
{"El Castillo del Diablo",      {-208.50,2123.00,-7.60,114.00,2337.10,200.00}},
{"El Castillo del Diablo",      {-208.50,2337.10,0.00,8.40,2487.10,200.00}},
{"El Corona",                   {1812.60,-2179.20,-89.00,1970.60,-1852.80,110.90}},
{"El Corona",                   {1692.60,-2179.20,-89.00,1812.60,-1842.20,110.90}},
{"El Quebrados",                {-1645.20,2498.50,0.00,-1372.10,2777.80,200.00}},
{"Esplanade East",              {-1620.30,1176.50,-4.50,-1580.00,1274.20,200.00}},
{"Esplanade East",              {-1580.00,1025.90,-6.10,-1499.80,1274.20,200.00}},
{"Esplanade East",              {-1499.80,578.30,-79.60,-1339.80,1274.20,20.30}},
{"Esplanade North",             {-2533.00,1358.90,-4.50,-1996.60,1501.20,200.00}},
{"Esplanade North",             {-1996.60,1358.90,-4.50,-1524.20,1592.50,200.00}},
{"Esplanade North",             {-1982.30,1274.20,-4.50,-1524.20,1358.90,200.00}},
{"Fallen Tree",                 {-792.20,-698.50,-5.30,-452.40,-380.00,200.00}},
{"Fallow Bridge",               {434.30,366.50,0.00,603.00,555.60,200.00}},
{"Fern Ridge",                  {508.10,-139.20,0.00,1306.60,119.50,200.00}},
{"Financial",                   {-1871.70,744.10,-6.10,-1701.30,1176.40,300.00}},
{"Fisher's Lagoon",             {1916.90,-233.30,-100.00,2131.70,13.80,200.00}},
{"Flint Intersection",          {-187.70,-1596.70,-89.00,17.00,-1276.60,110.90}},
{"Flint Range",                 {-594.10,-1648.50,0.00,-187.70,-1276.60,200.00}},
{"Fort Carson",                 {-376.20,826.30,-3.00,123.70,1220.40,200.00}},
{"Foster Valley",               {-2270.00,-430.20,-0.00,-2178.60,-324.10,200.00}},
{"Foster Valley",               {-2178.60,-599.80,-0.00,-1794.90,-324.10,200.00}},
{"Foster Valley",               {-2178.60,-1115.50,0.00,-1794.90,-599.80,200.00}},
{"Foster Valley",               {-2178.60,-1250.90,0.00,-1794.90,-1115.50,200.00}},
{"Frederick Bridge",            {2759.20,296.50,0.00,2774.20,594.70,200.00}},
{"Gant Bridge",                 {-2741.40,1659.60,-6.10,-2616.40,2175.10,200.00}},
{"Gant Bridge",                 {-2741.00,1490.40,-6.10,-2616.40,1659.60,200.00}},
{"Ganton",                      {2222.50,-1852.80,-89.00,2632.80,-1722.30,110.90}},
{"Ganton",                      {2222.50,-1722.30,-89.00,2632.80,-1628.50,110.90}},
{"Garcia",                      {-2411.20,-222.50,-0.00,-2173.00,265.20,200.00}},
{"Garcia",                      {-2395.10,-222.50,-5.30,-2354.00,-204.70,200.00}},
{"Garver Bridge",               {-1339.80,828.10,-89.00,-1213.90,1057.00,110.90}},
{"Garver Bridge",               {-1213.90,950.00,-89.00,-1087.90,1178.90,110.90}},
{"Garver Bridge",               {-1499.80,696.40,-179.60,-1339.80,925.30,20.30}},
{"Glen Park",                   {1812.60,-1449.60,-89.00,1996.90,-1350.70,110.90}},
{"Glen Park",                   {1812.60,-1100.80,-89.00,1994.30,-973.30,110.90}},
{"Glen Park",                   {1812.60,-1350.70,-89.00,2056.80,-1100.80,110.90}},
{"Green Park",                 {176.50,1305.40,-3.00,338.60,1520.70,200.00}},
{"Greenglass College",          {964.30,1044.60,-89.00,1197.30,1203.20,110.90}},
{"Greenglass College",          {964.30,930.80,-89.00,1166.50,1044.60,110.90}},
{"Hampton Barns",               {603.00,264.30,0.00,761.90,366.50,200.00}},
{"Hankypanky Point",            {2576.90,62.10,0.00,2759.20,385.50,200.00}},
{"Harry Gold Parkway",          {1777.30,863.20,-89.00,1817.30,2342.80,110.90}},
{"Hashbury",                    {-2593.40,-222.50,-0.00,-2411.20,54.70,200.00}},
{"Hilltop Farm",                {967.30,-450.30,-3.00,1176.70,-217.90,200.00}},
{"Hunter Quarry",               {337.20,710.80,-115.20,860.50,1031.70,203.70}},
{"Idlewood",                    {1812.60,-1852.80,-89.00,1971.60,-1742.30,110.90}},
{"Idlewood",                    {1812.60,-1742.30,-89.00,1951.60,-1602.30,110.90}},
{"Idlewood",                    {1951.60,-1742.30,-89.00,2124.60,-1602.30,110.90}},
{"Idlewood",                    {1812.60,-1602.30,-89.00,2124.60,-1449.60,110.90}},
{"Idlewood",                    {2124.60,-1742.30,-89.00,2222.50,-1494.00,110.90}},
{"Idlewood",                    {1971.60,-1852.80,-89.00,2222.50,-1742.30,110.90}},
{"Jefferson",                   {1996.90,-1449.60,-89.00,2056.80,-1350.70,110.90}},
{"Jefferson",                   {2124.60,-1494.00,-89.00,2266.20,-1449.60,110.90}},
{"Jefferson",                   {2056.80,-1372.00,-89.00,2281.40,-1210.70,110.90}},
{"Jefferson",                   {2056.80,-1210.70,-89.00,2185.30,-1126.30,110.90}},
{"Jefferson",                   {2185.30,-1210.70,-89.00,2281.40,-1154.50,110.90}},
{"Jefferson",                   {2056.80,-1449.60,-89.00,2266.20,-1372.00,110.90}},
{"Julius Thruway East",         {2623.10,943.20,-89.00,2749.90,1055.90,110.90}},
{"Julius Thruway East",         {2685.10,1055.90,-89.00,2749.90,2626.50,110.90}},
{"Julius Thruway East",         {2536.40,2442.50,-89.00,2685.10,2542.50,110.90}},
{"Julius Thruway East",         {2625.10,2202.70,-89.00,2685.10,2442.50,110.90}},
{"Julius Thruway North",        {2498.20,2542.50,-89.00,2685.10,2626.50,110.90}},
{"Julius Thruway North",        {2237.40,2542.50,-89.00,2498.20,2663.10,110.90}},
{"Julius Thruway North",        {2121.40,2508.20,-89.00,2237.40,2663.10,110.90}},
{"Julius Thruway North",        {1938.80,2508.20,-89.00,2121.40,2624.20,110.90}},
{"Julius Thruway North",        {1534.50,2433.20,-89.00,1848.40,2583.20,110.90}},
{"Julius Thruway North",        {1848.40,2478.40,-89.00,1938.80,2553.40,110.90}},
{"Julius Thruway North",        {1704.50,2342.80,-89.00,1848.40,2433.20,110.90}},
{"Julius Thruway North",        {1377.30,2433.20,-89.00,1534.50,2507.20,110.90}},
{"Julius Thruway South",        {1457.30,823.20,-89.00,2377.30,863.20,110.90}},
{"Julius Thruway South",        {2377.30,788.80,-89.00,2537.30,897.90,110.90}},
{"Julius Thruway West",         {1197.30,1163.30,-89.00,1236.60,2243.20,110.90}},
{"Julius Thruway West",         {1236.60,2142.80,-89.00,1297.40,2243.20,110.90}},
{"Juniper Hill",                {-2533.00,578.30,-7.60,-2274.10,968.30,200.00}},
{"Juniper Hollow",              {-2533.00,968.30,-6.10,-2274.10,1358.90,200.00}},
{"K.A.C.C. Military Fuels",     {2498.20,2626.50,-89.00,2749.90,2861.50,110.90}},
{"Kincaid Bridge",              {-1339.80,599.20,-89.00,-1213.90,828.10,110.90}},
{"Kincaid Bridge",              {-1213.90,721.10,-89.00,-1087.90,950.00,110.90}},
{"Kincaid Bridge",              {-1087.90,855.30,-89.00,-961.90,986.20,110.90}},
{"King's",                      {-2329.30,458.40,-7.60,-1993.20,578.30,200.00}},
{"King's",                      {-2411.20,265.20,-9.10,-1993.20,373.50,200.00}},
{"King's",                      {-2253.50,373.50,-9.10,-1993.20,458.40,200.00}},
{"LVA Freight Depot",           {1457.30,863.20,-89.00,1777.40,1143.20,110.90}},
{"LVA Freight Depot",           {1375.60,919.40,-89.00,1457.30,1203.20,110.90}},
{"LVA Freight Depot",           {1277.00,1087.60,-89.00,1375.60,1203.20,110.90}},
{"LVA Freight Depot",           {1315.30,1044.60,-89.00,1375.60,1087.60,110.90}},
{"LVA Freight Depot",           {1236.60,1163.40,-89.00,1277.00,1203.20,110.90}},
{"Las Barrancas",               {-926.10,1398.70,-3.00,-719.20,1634.60,200.00}},
{"Las Brujas",                  {-365.10,2123.00,-3.00,-208.50,2217.60,200.00}},
{"Las Colinas",                 {1994.30,-1100.80,-89.00,2056.80,-920.80,110.90}},
{"Las Colinas",                 {2056.80,-1126.30,-89.00,2126.80,-920.80,110.90}},
{"Las Colinas",                 {2185.30,-1154.50,-89.00,2281.40,-934.40,110.90}},
{"Las Colinas",                 {2126.80,-1126.30,-89.00,2185.30,-934.40,110.90}},
{"Las Colinas",                 {2747.70,-1120.00,-89.00,2959.30,-945.00,110.90}},
{"Las Colinas",                 {2632.70,-1135.00,-89.00,2747.70,-945.00,110.90}},
{"Las Colinas",                 {2281.40,-1135.00,-89.00,2632.70,-945.00,110.90}},
{"Las Payasadas",               {-354.30,2580.30,2.00,-133.60,2816.80,200.00}},
{"Las Venturas Airport",        {1236.60,1203.20,-89.00,1457.30,1883.10,110.90}},
{"Las Venturas Airport",        {1457.30,1203.20,-89.00,1777.30,1883.10,110.90}},
{"Las Venturas Airport",        {1457.30,1143.20,-89.00,1777.40,1203.20,110.90}},
{"Las Venturas Airport",        {1515.80,1586.40,-12.50,1729.90,1714.50,87.50}},
{"Last Dime Motel",             {1823.00,596.30,-89.00,1997.20,823.20,110.90}},
{"Leafy Hollow",                {-1166.90,-1856.00,0.00,-815.60,-1602.00,200.00}},
{"Liberty City",                {-1000.00,400.00,1300.00,-700.00,600.00,1400.00}},
{"Lil' Probe Inn",              {-90.20,1286.80,-3.00,153.80,1554.10,200.00}},
{"Linden Side",                 {2749.90,943.20,-89.00,2923.30,1198.90,110.90}},
{"Linden Station",              {2749.90,1198.90,-89.00,2923.30,1548.90,110.90}},
{"Linden Station",              {2811.20,1229.50,-39.50,2861.20,1407.50,60.40}},
{"Little Mexico",               {1701.90,-1842.20,-89.00,1812.60,-1722.20,110.90}},
{"Little Mexico",               {1758.90,-1722.20,-89.00,1812.60,-1577.50,110.90}},
{"Los Flores",                  {2581.70,-1454.30,-89.00,2632.80,-1393.40,110.90}},
{"Los Flores",                  {2581.70,-1393.40,-89.00,2747.70,-1135.00,110.90}},
{"Los Santos International",    {1249.60,-2394.30,-89.00,1852.00,-2179.20,110.90}},
{"Los Santos International",    {1852.00,-2394.30,-89.00,2089.00,-2179.20,110.90}},
{"Los Santos International",    {1382.70,-2730.80,-89.00,2201.80,-2394.30,110.90}},
{"Los Santos International",    {1974.60,-2394.30,-39.00,2089.00,-2256.50,60.90}},
{"Los Santos International",    {1400.90,-2669.20,-39.00,2189.80,-2597.20,60.90}},
{"Los Santos International",    {2051.60,-2597.20,-39.00,2152.40,-2394.30,60.90}},
{"Marina",                      {647.70,-1804.20,-89.00,851.40,-1577.50,110.90}},
{"Marina",                      {647.70,-1577.50,-89.00,807.90,-1416.20,110.90}},
{"Marina",                      {807.90,-1577.50,-89.00,926.90,-1416.20,110.90}},
{"Market",                      {787.40,-1416.20,-89.00,1072.60,-1310.20,110.90}},
{"Market",                      {952.60,-1310.20,-89.00,1072.60,-1130.80,110.90}},
{"Market",                      {1072.60,-1416.20,-89.00,1370.80,-1130.80,110.90}},
{"Market",                      {926.90,-1577.50,-89.00,1370.80,-1416.20,110.90}},
{"Market Station",              {787.40,-1410.90,-34.10,866.00,-1310.20,65.80}},
{"Martin Bridge",               {-222.10,293.30,0.00,-122.10,476.40,200.00}},
{"Missionary Hill",             {-2994.40,-811.20,0.00,-2178.60,-430.20,200.00}},
{"Montgomery",                  {1119.50,119.50,-3.00,1451.40,493.30,200.00}},
{"Montgomery",                  {1451.40,347.40,-6.10,1582.40,420.80,200.00}},
{"Montgomery Intersection",     {1546.60,208.10,0.00,1745.80,347.40,200.00}},
{"Montgomery Intersection",     {1582.40,347.40,0.00,1664.60,401.70,200.00}},
{"Mulholland",                  {1414.00,-768.00,-89.00,1667.60,-452.40,110.90}},
{"Mulholland",                  {1281.10,-452.40,-89.00,1641.10,-290.90,110.90}},
{"Mulholland",                  {1269.10,-768.00,-89.00,1414.00,-452.40,110.90}},
{"Mulholland",                  {1357.00,-926.90,-89.00,1463.90,-768.00,110.90}},
{"Mulholland",                  {1318.10,-910.10,-89.00,1357.00,-768.00,110.90}},
{"Mulholland",                  {1169.10,-910.10,-89.00,1318.10,-768.00,110.90}},
{"Mulholland",                  {768.60,-954.60,-89.00,952.60,-860.60,110.90}},
{"Mulholland",                  {687.80,-860.60,-89.00,911.80,-768.00,110.90}},
{"Mulholland",                  {737.50,-768.00,-89.00,1142.20,-674.80,110.90}},
{"Mulholland",                  {1096.40,-910.10,-89.00,1169.10,-768.00,110.90}},
{"Mulholland",                  {952.60,-937.10,-89.00,1096.40,-860.60,110.90}},
{"Mulholland",                  {911.80,-860.60,-89.00,1096.40,-768.00,110.90}},
{"Mulholland",                  {861.00,-674.80,-89.00,1156.50,-600.80,110.90}},
{"Mulholland Intersection",     {1463.90,-1150.80,-89.00,1812.60,-768.00,110.90}},
{"North Rock",                  {2285.30,-768.00,0.00,2770.50,-269.70,200.00}},
{"Ocean Docks",                 {2373.70,-2697.00,-89.00,2809.20,-2330.40,110.90}},
{"Ocean Docks",                 {2201.80,-2418.30,-89.00,2324.00,-2095.00,110.90}},
{"Ocean Docks",                 {2324.00,-2302.30,-89.00,2703.50,-2145.10,110.90}},
{"Ocean Docks",                 {2089.00,-2394.30,-89.00,2201.80,-2235.80,110.90}},
{"Ocean Docks",                 {2201.80,-2730.80,-89.00,2324.00,-2418.30,110.90}},
{"Ocean Docks",                 {2703.50,-2302.30,-89.00,2959.30,-2126.90,110.90}},
{"Ocean Docks",                 {2324.00,-2145.10,-89.00,2703.50,-2059.20,110.90}},
{"Ocean Flats",                 {-2994.40,277.40,-9.10,-2867.80,458.40,200.00}},
{"Ocean Flats",                 {-2994.40,-222.50,-0.00,-2593.40,277.40,200.00}},
{"Ocean Flats",                 {-2994.40,-430.20,-0.00,-2831.80,-222.50,200.00}},
{"Octane Springs",              {338.60,1228.50,0.00,664.30,1655.00,200.00}},
{"Old Venturas Strip",          {2162.30,2012.10,-89.00,2685.10,2202.70,110.90}},
{"Palisades",                   {-2994.40,458.40,-6.10,-2741.00,1339.60,200.00}},
{"Palomino Creek",              {2160.20,-149.00,0.00,2576.90,228.30,200.00}},
{"Paradiso",                    {-2741.00,793.40,-6.10,-2533.00,1268.40,200.00}},
{"Pershing Square",             {1440.90,-1722.20,-89.00,1583.50,-1577.50,110.90}},
{"Pilgrim",                     {2437.30,1383.20,-89.00,2624.40,1783.20,110.90}},
{"Pilgrim",                     {2624.40,1383.20,-89.00,2685.10,1783.20,110.90}},
{"Pilson Intersection",         {1098.30,2243.20,-89.00,1377.30,2507.20,110.90}},
{"Pirates in Men's Pants",      {1817.30,1469.20,-89.00,2027.40,1703.20,110.90}},
{"Playa del Seville",           {2703.50,-2126.90,-89.00,2959.30,-1852.80,110.90}},
{"Prickle Pine",                {1534.50,2583.20,-89.00,1848.40,2863.20,110.90}},
{"Prickle Pine",                {1117.40,2507.20,-89.00,1534.50,2723.20,110.90}},
{"Prickle Pine",                {1848.40,2553.40,-89.00,1938.80,2863.20,110.90}},
{"Prickle Pine",                {1938.80,2624.20,-89.00,2121.40,2861.50,110.90}},
{"Queens",                      {-2533.00,458.40,0.00,-2329.30,578.30,200.00}},
{"Queens",                      {-2593.40,54.70,0.00,-2411.20,458.40,200.00}},
{"Queens",                      {-2411.20,373.50,0.00,-2253.50,458.40,200.00}},
{"Randolph Industrial Estate",  {1558.00,596.30,-89.00,1823.00,823.20,110.90}},
{"Redsands East",               {1817.30,2011.80,-89.00,2106.70,2202.70,110.90}},
{"Redsands East",               {1817.30,2202.70,-89.00,2011.90,2342.80,110.90}},
{"Redsands East",               {1848.40,2342.80,-89.00,2011.90,2478.40,110.90}},
{"Redsands West",               {1236.60,1883.10,-89.00,1777.30,2142.80,110.90}},
{"Redsands West",               {1297.40,2142.80,-89.00,1777.30,2243.20,110.90}},
{"Redsands West",               {1377.30,2243.20,-89.00,1704.50,2433.20,110.90}},
{"Redsands West",               {1704.50,2243.20,-89.00,1777.30,2342.80,110.90}},
{"Regular Tom",                 {-405.70,1712.80,-3.00,-276.70,1892.70,200.00}},
{"Richman",                     {647.50,-1118.20,-89.00,787.40,-954.60,110.90}},
{"Richman",                     {647.50,-954.60,-89.00,768.60,-860.60,110.90}},
{"Richman",                     {225.10,-1369.60,-89.00,334.50,-1292.00,110.90}},
{"Richman",                     {225.10,-1292.00,-89.00,466.20,-1235.00,110.90}},
{"Richman",                     {72.60,-1404.90,-89.00,225.10,-1235.00,110.90}},
{"Richman",                     {72.60,-1235.00,-89.00,321.30,-1008.10,110.90}},
{"Richman",                     {321.30,-1235.00,-89.00,647.50,-1044.00,110.90}},
{"Richman",                     {321.30,-1044.00,-89.00,647.50,-860.60,110.90}},
{"Richman",                     {321.30,-860.60,-89.00,687.80,-768.00,110.90}},
{"Richman",                     {321.30,-768.00,-89.00,700.70,-674.80,110.90}},
{"Robada Intersection",         {-1119.00,1178.90,-89.00,-862.00,1351.40,110.90}},
{"Roca Escalante",              {2237.40,2202.70,-89.00,2536.40,2542.50,110.90}},
{"Roca Escalante",              {2536.40,2202.70,-89.00,2625.10,2442.50,110.90}},
{"Rockshore East",              {2537.30,676.50,-89.00,2902.30,943.20,110.90}},
{"Rockshore West",              {1997.20,596.30,-89.00,2377.30,823.20,110.90}},
{"Rockshore West",              {2377.30,596.30,-89.00,2537.30,788.80,110.90}},
{"Rodeo",                       {72.60,-1684.60,-89.00,225.10,-1544.10,110.90}},
{"Rodeo",                       {72.60,-1544.10,-89.00,225.10,-1404.90,110.90}},
{"Rodeo",                       {225.10,-1684.60,-89.00,312.80,-1501.90,110.90}},
{"Rodeo",                       {225.10,-1501.90,-89.00,334.50,-1369.60,110.90}},
{"Rodeo",                       {334.50,-1501.90,-89.00,422.60,-1406.00,110.90}},
{"Rodeo",                       {312.80,-1684.60,-89.00,422.60,-1501.90,110.90}},
{"Rodeo",                       {422.60,-1684.60,-89.00,558.00,-1570.20,110.90}},
{"Rodeo",                       {558.00,-1684.60,-89.00,647.50,-1384.90,110.90}},
{"Rodeo",                       {466.20,-1570.20,-89.00,558.00,-1385.00,110.90}},
{"Rodeo",                       {422.60,-1570.20,-89.00,466.20,-1406.00,110.90}},
{"Rodeo",                       {466.20,-1385.00,-89.00,647.50,-1235.00,110.90}},
{"Rodeo",                       {334.50,-1406.00,-89.00,466.20,-1292.00,110.90}},
{"Royal Casino",                {2087.30,1383.20,-89.00,2437.30,1543.20,110.90}},
{"San Andreas Sound",           {2450.30,385.50,-100.00,2759.20,562.30,200.00}},
{"Santa Flora",                 {-2741.00,458.40,-7.60,-2533.00,793.40,200.00}},
{"Santa Maria Beach",           {342.60,-2173.20,-89.00,647.70,-1684.60,110.90}},
{"Santa Maria Beach",           {72.60,-2173.20,-89.00,342.60,-1684.60,110.90}},
{"Shady Cabin",                 {-1632.80,-2263.40,-3.00,-1601.30,-2231.70,200.00}},
{"Shady Creeks",                {-1820.60,-2643.60,-8.00,-1226.70,-1771.60,200.00}},
{"Shady Creeks",                {-2030.10,-2174.80,-6.10,-1820.60,-1771.60,200.00}},
{"Sobell Rail Yards",           {2749.90,1548.90,-89.00,2923.30,1937.20,110.90}},
{"Spinybed",                    {2121.40,2663.10,-89.00,2498.20,2861.50,110.90}},
{"Starfish Casino",             {2437.30,1783.20,-89.00,2685.10,2012.10,110.90}},
{"Starfish Casino",             {2437.30,1858.10,-39.00,2495.00,1970.80,60.90}},
{"Starfish Casino",             {2162.30,1883.20,-89.00,2437.30,2012.10,110.90}},
{"Temple",                      {1252.30,-1130.80,-89.00,1378.30,-1026.30,110.90}},
{"Temple",                      {1252.30,-1026.30,-89.00,1391.00,-926.90,110.90}},
{"Temple",                      {1252.30,-926.90,-89.00,1357.00,-910.10,110.90}},
{"Temple",                      {952.60,-1130.80,-89.00,1096.40,-937.10,110.90}},
{"Temple",                      {1096.40,-1130.80,-89.00,1252.30,-1026.30,110.90}},
{"Temple",                      {1096.40,-1026.30,-89.00,1252.30,-910.10,110.90}},
{"The Camel's Toe",             {2087.30,1203.20,-89.00,2640.40,1383.20,110.90}},
{"The Clown's Pocket",          {2162.30,1783.20,-89.00,2437.30,1883.20,110.90}},
{"The Emerald Isle",            {2011.90,2202.70,-89.00,2237.40,2508.20,110.90}},
{"The Farm",                    {-1209.60,-1317.10,114.90,-908.10,-787.30,251.90}},
{"The Four Dragons Casino",     {1817.30,863.20,-89.00,2027.30,1083.20,110.90}},
{"The High Roller",             {1817.30,1283.20,-89.00,2027.30,1469.20,110.90}},
{"The Mako Span",               {1664.60,401.70,0.00,1785.10,567.20,200.00}},
{"The Panopticon",              {-947.90,-304.30,-1.10,-319.60,327.00,200.00}},
{"The Pink Swan",               {1817.30,1083.20,-89.00,2027.30,1283.20,110.90}},
{"The Sherman Dam",             {-968.70,1929.40,-3.00,-481.10,2155.20,200.00}},
{"The Strip",                   {2027.40,863.20,-89.00,2087.30,1703.20,110.90}},
{"The Strip",                   {2106.70,1863.20,-89.00,2162.30,2202.70,110.90}},
{"The Strip",                   {2027.40,1783.20,-89.00,2162.30,1863.20,110.90}},
{"The Strip",                   {2027.40,1703.20,-89.00,2137.40,1783.20,110.90}},
{"The Visage",                  {1817.30,1863.20,-89.00,2106.70,2011.80,110.90}},
{"The Visage",                  {1817.30,1703.20,-89.00,2027.40,1863.20,110.90}},
{"Unity Station",               {1692.60,-1971.80,-20.40,1812.60,-1932.80,79.50}},
{"Valle Ocultado",              {-936.60,2611.40,2.00,-715.90,2847.90,200.00}},
{"Verdant Bluffs",              {930.20,-2488.40,-89.00,1249.60,-2006.70,110.90}},
{"Verdant Bluffs",              {1073.20,-2006.70,-89.00,1249.60,-1842.20,110.90}},
{"Verdant Bluffs",              {1249.60,-2179.20,-89.00,1692.60,-1842.20,110.90}},
{"Verdant Meadows",             {37.00,2337.10,-3.00,435.90,2677.90,200.00}},
{"Verona Beach",                {647.70,-2173.20,-89.00,930.20,-1804.20,110.90}},
{"Verona Beach",                {930.20,-2006.70,-89.00,1073.20,-1804.20,110.90}},
{"Verona Beach",                {851.40,-1804.20,-89.00,1046.10,-1577.50,110.90}},
{"Verona Beach",                {1161.50,-1722.20,-89.00,1323.90,-1577.50,110.90}},
{"Verona Beach",                {1046.10,-1722.20,-89.00,1161.50,-1577.50,110.90}},
{"Vinewood",                    {787.40,-1310.20,-89.00,952.60,-1130.80,110.90}},
{"Vinewood",                    {787.40,-1130.80,-89.00,952.60,-954.60,110.90}},
{"Vinewood",                    {647.50,-1227.20,-89.00,787.40,-1118.20,110.90}},
{"Vinewood",                    {647.70,-1416.20,-89.00,787.40,-1227.20,110.90}},
{"Whitewood Estates",           {883.30,1726.20,-89.00,1098.30,2507.20,110.90}},
{"Whitewood Estates",           {1098.30,1726.20,-89.00,1197.30,2243.20,110.90}},
{"Willowfield",                 {1970.60,-2179.20,-89.00,2089.00,-1852.80,110.90}},
{"Willowfield",                 {2089.00,-2235.80,-89.00,2201.80,-1989.90,110.90}},
{"Willowfield",                 {2089.00,-1989.90,-89.00,2324.00,-1852.80,110.90}},
{"Willowfield",                 {2201.80,-2095.00,-89.00,2324.00,-1989.90,110.90}},
{"Willowfield",                 {2541.70,-1941.40,-89.00,2703.50,-1852.80,110.90}},
{"Willowfield",                 {2324.00,-2059.20,-89.00,2541.70,-1852.80,110.90}},
{"Willowfield",                 {2541.70,-2059.20,-89.00,2703.50,-1941.40,110.90}},
{"Yellow Bell Station",         {1377.40,2600.40,-21.90,1492.40,2687.30,78.00}},
{"Los Santos",                  {44.60,-2892.90,-242.90,2997.00,-768.00,900.00}},
{"Las Venturas",                {869.40,596.30,-242.90,2997.00,2993.80,900.00}},
{"Bone County",                 {-480.50,596.30,-242.90,869.40,2993.80,900.00}},
{"Tierra Robada",               {-2997.40,1659.60,-242.90,-480.50,2993.80,900.00}},
{"Tierra Robada",               {-1213.90,596.30,-242.90,-480.50,1659.60,900.00}},
{"San Fierro",                  {-2997.40,-1115.50,-242.90,-1213.90,1659.60,900.00}},
{"Red County",                  {-1213.90,-768.00,-242.90,2997.00,596.30,900.00}},
{"Flint County",                {-1213.90,-2892.90,-242.90,44.60,-768.00,900.00}},
{"Whetstone",                   {-2997.40,-2892.90,-242.90,-1213.90,-1115.50,900.00}}
};

main(){}

public OnGameModeInit()
{
    ShowPlayerMarkers(PLAYER_MARKERS_MODE_STREAMED);

    //IDConexao = mysql_connect("127.0.0.1", "root", "", "samp");
    IDConexao = mysql_connect("127.0.0.1", "server_161", "qmw4anelhx", "server_161_calenzo");

    strins(String,"CREATE TABLE IF NOT EXISTS Contas (ID int AUTO_INCREMENT PRIMARY KEY, IP int(24) NOT NULL, Profissao int(3) NOT NULL,", strlen(String));
    strins(String,"Nome varchar(24) NOT NULL, Senha varchar(24) NOT NULL, Email varchar(30) NOT NULL, Admin int(1) NOT NULL, minUP int(1) NOT NULL,", strlen(String));
    strins(String,"segUP int(2) NOT NULL, Level int(20) NOT NULL, Exp int(1) NOT NULL, Coins int(20) NOT NULL, Vip int(1) NOT NULL, CorVIP int(1) NOT NULL,", strlen(String));
    strins(String,"Vencimento int(30) NOT NULL, Skin int(3) NOT NULL, Aviso int(1) NOT NULL, Dinheiro int(20) NOT NULL, Banco int(20) NOT NULL,", strlen(String));
    strins(String,"Matou int(10) NOT NULL, Morreu int(10) NOT NULL, Interior int(1) NOT NULL,Preso int(30) NOT NULL, MotivoPrisao varchar(30) NOT NULL,", strlen(String));
    strins(String,"PosX float(20) NOT NULL, PosY float(20) NOT NULL, PosZ float(20) NOT NULL, PosA float(20) NOT NULL)", strlen(String));
    mysql_query(IDConexao, String, false);

    if(mysql_errno(IDConexao) != 0)
    {
        print("Falha na conexão ao banco de dados Mysql");
        SendRconCommand("exit");
    } else {
        print("Conexão ao banco de dado Mysql efetuada com sucesso");
    }

    //Hq de Entregador de Jornal
    BKJORNAL[0] = AddStaticVehicleEx(510, 784.9813, -1356.2255, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[1] = AddStaticVehicleEx(510, 784.9813, -1358.1863, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[2] = AddStaticVehicleEx(510, 784.9813, -1360.1813, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[3] = AddStaticVehicleEx(510, 784.9813, -1362.1833, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[4] = AddStaticVehicleEx(510, 784.9813, -1364.1859, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[5] = AddStaticVehicleEx(510, 784.9813, -1345.0000, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[6] = AddStaticVehicleEx(510, 784.9813, -1343.0000, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[7] = AddStaticVehicleEx(510, 784.9813, -1341.0000, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[8] = AddStaticVehicleEx(510, 784.9810, -1339.0000, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[9] = AddStaticVehicleEx(510, 784.9810, -1337.0000, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[10] = AddStaticVehicleEx(510, 784.9813, -1346.8591, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[11] = AddStaticVehicleEx(510, 784.9813, -1348.7258, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[12] = AddStaticVehicleEx(510, 784.9813, -1350.6263, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[13] = AddStaticVehicleEx(510, 784.9813, -1352.5315, 13.1522, 90.0000, 1, 1, 100);
    BKJORNAL[14] = AddStaticVehicleEx(510, 784.9813, -1354.4387, 13.1522, 90.0000, 1, 1, 100);

    //Hq Taxi
    CRRTAXI[0] = CreateVehicle(420, 2230.0000, -1340.0000, 23.5839, 90.0000, -1, -1, 100);
    CRRTAXI[1] = CreateVehicle(420, 2230.0000, -1344.0000, 23.5839, 90.0000, -1, -1, 100);
    CRRTAXI[2] = CreateVehicle(420, 2230.0000, -1348.0000, 23.5839, 90.0000, -1, -1, 100);
    CRRTAXI[3] = CreateVehicle(420, 2230.0000, -1352.0000, 23.5839, 90.0000, -1, -1, 100);
    CRRTAXI[4] = CreateVehicle(420, 2230.0000, -1356.0000, 23.5839, 90.0000, -1, -1, 100);
    CRRTAXI[5] = CreateVehicle(420, 2230.0000, -1360.0000, 23.5839, 90.0000, -1, -1, 100);

    //Hq policia ls
    VCPOLICIA[0] = AddStaticVehicleEx(523,1605.0000,-1605.0000,13.0002,90.0000,-1,-1,100);
    VCPOLICIA[1] = AddStaticVehicleEx(523,1604.9994,-1608.0200,13.0002,90.0000,-1,-1,100);
    VCPOLICIA[2] = AddStaticVehicleEx(523,1604.9994,-1611.0000,13.0002,90.0000,-1,-1,100);
    VCPOLICIA[3] = AddStaticVehicleEx(523,1604.9994,-1614.0000,13.0002,90.0000,-1,-1,100);
    VCPOLICIA[4] = AddStaticVehicleEx(523,1604.9994,-1617.0000,13.0002,90.0000,-1,-1,100);
    VCPOLICIA[5] = AddStaticVehicleEx(523,1604.9994,-1620.0000,13.0002,90.0000,-1,-1,100);
    VCPOLICIA[6] = AddStaticVehicleEx(523,1604.9994,-1623.0000,13.0002,90.0000,-1,-1,100);
    VCPOLICIA[7] = AddStaticVehicleEx(523,1604.9994,-1626.0000,13.0002,90.0000,-1,-1,100);
    VCPOLICIA[8] = AddStaticVehicleEx(523,1604.9994,-1629.0000,13.0002,90.0000,-1,-1,100);
    VCPOLICIA[9] = AddStaticVehicleEx(523,1604.9994,-1632.0000,13.0002,90.0000,-1,-1,100);
    VCPOLICIA[10] = AddStaticVehicleEx(598,1551.0000,-1606.0000,13.0802,180.0000,-1,-1,100);
    VCPOLICIA[11] = AddStaticVehicleEx(598,1554.9801,-1606.0016,13.0802,180.0000,-1,-1,100);
    VCPOLICIA[12] = AddStaticVehicleEx(598,1559.0000,-1605.9719,13.0802,180.0000,-1,-1,100);
    VCPOLICIA[13] = AddStaticVehicleEx(598,1563.0000,-1606.0000,13.0802,180.0000,-1,-1,100);
    VCPOLICIA[14] = AddStaticVehicleEx(598,1567.0000,-1606.0010,13.0802,180.0000,-1,-1,100);
    VCPOLICIA[15] = AddStaticVehicleEx(598,1571.0000,-1606.0010,13.0802,180.0000,-1,-1,100);
    VCPOLICIA[16] = AddStaticVehicleEx(598,1575.0000,-1606.0010,13.0802,180.0000,-1,-1,100);
    VCPOLICIA[17] = AddStaticVehicleEx(598,1579.0000,-1606.0010,13.0802,180.0000,-1,-1,100);
    VCPOLICIA[18] = AddStaticVehicleEx(598, 2252.0000, 2476.5591, 10.4215, 180.0000, -1, -1, 100);
    VCPOLICIA[19] = AddStaticVehicleEx(598, 2255.9714, 2476.5591, 10.4215, 180.0000, -1, -1, 100);
    VCPOLICIA[20] = AddStaticVehicleEx(598, 2260.4031, 2476.5591, 10.4215, 180.0000, -1, -1, 100);
    VCPOLICIA[21] = AddStaticVehicleEx(598, 2269.3093, 2476.5591, 10.4215, 180.0000, -1, -1, 100);
    VCPOLICIA[22] = AddStaticVehicleEx(598, 2273.3691, 2476.5591, 10.4215, 180.0000, -1, -1, 100);
    VCPOLICIA[23] = AddStaticVehicleEx(598, 2277.8213, 2476.5591, 10.4215, 180.0000, -1, -1, 100);
    VCPOLICIA[24] = AddStaticVehicleEx(598, 2282.3047, 2476.5940, 10.4215, 180.0000, -1, -1, 100);
    VCPOLICIA[25] = AddStaticVehicleEx(497, -220.9945, 995.6248, 19.7057, -90.0000, -1, -1, 100);
    VCPOLICIA[26] = AddStaticVehicleEx(599, -209.1601, 998.7247, 19.7419, 180.0000, -1, -1, 100);
    VCPOLICIA[27] = AddStaticVehicleEx(598, -214.1810, 972.8283, 18.9690, -90.0000, -1, -1, 100);
    VCPOLICIA[28] = AddStaticVehicleEx(497, -1680.3081, 704.7817, 30.9151, 0.0000, -1, -1, 100);
    VCPOLICIA[29] = AddStaticVehicleEx(523, -1581.6348, 652.1369, 6.6743, 0.0000, -1, -1, 100);
    VCPOLICIA[30] = AddStaticVehicleEx(523, -1587.7535, 652.1369, 6.6743, 0.0000, -1, -1, 100);
    VCPOLICIA[31] = AddStaticVehicleEx(523, -1593.5933, 652.1369, 6.6743, 0.0000, -1, -1, 100);
    VCPOLICIA[32] = AddStaticVehicleEx(523, -1599.4490, 652.1369, 6.6743, 0.0000, -1, -1, 100);
    VCPOLICIA[33] = AddStaticVehicleEx(598, -1610.7079, 651.8018, 6.8743, 0.0000, -1, -1, 100);
    VCPOLICIA[34] = AddStaticVehicleEx(598, -1616.5802, 651.8018, 6.8743, 0.0000, -1, -1, 100);
    VCPOLICIA[35] = AddStaticVehicleEx(598, -1622.5671, 651.8018, 6.8743, 0.0000, -1, -1, 100);
    VCPOLICIA[36] = AddStaticVehicleEx(598, -1628.4109, 651.8018, 6.8743, 0.0000, -1, -1, 100);
    VCPOLICIA[37] = AddStaticVehicleEx(598, -1634.2976, 651.8018, 6.8743, 0.0000, -1, -1, 100);

    BKNOVATOS[0] = AddStaticVehicleEx(481,828.0000,-1336.0000,13.0416,359.3848,1,1,100);
    BKNOVATOS[1] = AddStaticVehicleEx(481,830.0000,-1336.0000,13.0416,359.3848,1,1,100);
    BKNOVATOS[2] = AddStaticVehicleEx(481,832.0000,-1336.0000,13.0416,359.3848,1,1,100);
    BKNOVATOS[3] = AddStaticVehicleEx(481,834.0000,-1336.0000,13.0416,359.3848,1,1,100);
    BKNOVATOS[4] = AddStaticVehicleEx(481,836.0000,-1336.0000,13.0416,359.3848,1,1,100);

    CARROLG[0] = AddStaticVehicleEx(478,-451.0000,2210.0000,42.3809,0.0000,129,129,100);
    CARROLG[1] = AddStaticVehicleEx(478,-447.0000,2210.0000,42.3809,0.0000,129,129,100);
    CARROLG[2] = AddStaticVehicleEx(478,-443.0000,2210.0000,42.3809,0.0000,129,129,100);
    CARROLG[3] = AddStaticVehicleEx(478,-439.0000,2210.0000,42.3809,0.0000,129,129,100);
    CARROLG[4] = AddStaticVehicleEx(478,-435.0000,2210.0000,42.3809,0.0000,129,129,100);
    CARROLG[5] = AddStaticVehicleEx(478,-431.0000,2210.0000,42.3809,0.0000,129,129,100);

    //TextDraws
    txtDateDisp = TextDrawCreate(551.690856, 4.726683, ""); //Data
    TextDrawLetterSize(txtDateDisp, 0.250799, 1.908619);
    TextDrawAlignment(txtDateDisp, 2);
    TextDrawColor(txtDateDisp, -1);
    TextDrawSetShadow(txtDateDisp, 0);
    TextDrawSetOutline(txtDateDisp, 1);
    TextDrawBackgroundColor(txtDateDisp, 255);
    TextDrawFont(txtDateDisp, 3);
    TextDrawSetProportional(txtDateDisp, 1);
    TextDrawSetShadow(txtDateDisp, 0);

    txtTimeDisp = TextDrawCreate(576.693359, 21.317758, ""); //Hora
    TextDrawLetterSize(txtTimeDisp, 0.574198, 2.405065);
    TextDrawAlignment(txtTimeDisp, 2);
    TextDrawColor(txtTimeDisp, -1);
    TextDrawSetShadow(txtTimeDisp, 0);
    TextDrawSetOutline(txtTimeDisp, 1);
    TextDrawBackgroundColor(txtTimeDisp, 255);
    TextDrawFont(txtTimeDisp, 3);
    TextDrawSetProportional(txtTimeDisp, 1);
    TextDrawSetShadow(txtTimeDisp, 0);

    RespawnVeiculos = TextDrawCreate(317.799987, 192.346771, "");
    TextDrawLetterSize(RespawnVeiculos, 0.400000, 1.600000);
    TextDrawAlignment(RespawnVeiculos, 2);
    TextDrawColor(RespawnVeiculos, -1);
    TextDrawSetShadow(RespawnVeiculos, 0);
    TextDrawSetOutline(RespawnVeiculos, -1);
    TextDrawBackgroundColor(RespawnVeiculos, 255);
    TextDrawFont(RespawnVeiculos, 1);
    TextDrawSetProportional(RespawnVeiculos, 1);
    TextDrawSetShadow(RespawnVeiculos, 0);

    //Objects
    CreateObject(19302,250.49590,63.33670,1003.84442,0.00000,0.00000,90.00000);//250.49590, 63.33670, 1006.37250
    PortaPolicia = CreateObject(19302,246.39900,72.49900,1003.85809,0.00000,0.00000,0.00000);// 246.39900, 72.49900, 1007.10938

    //Checkpoints
    cp_mafia = CreateDynamicCP(2360.1792,-652.2457,128.0910,1.0,-1,0,-1,1000.0);
    cp_agencia = CreateDynamicCP(1490.8159,1305.7130,1093.2964,1.0,-1,3,-1,1000.0);

    //TextLabels
    Create3DTextLabel("Agencia de Empregos",0xFFFFFFFF,1154.0808,-1771.9812,16.5992,50.0,0);
    Create3DTextLabel("Agencia de Empregos",0xFFFFFFFF,937.8450,1733.1957,8.8516,50.0,0);
    Create3DTextLabel("Agencia de Empregos",0xFFFFFFFF,-2171.8110,252.0813,35.3378,50.0,0);
    Create3DTextLabel("Prefeitura",0xFFFFFFFF,1481.0637,-1770.9515,18.7958,50.0,0);
    Create3DTextLabel("Prefeitura",0xFFFFFFFF,2447.0620,2376.2354,12.1635,50.0,0);
    Create3DTextLabel("Prefeitura",0xFFFFFFFF,-2765.8796,375.5812,6.3347,50.0,0);
    Create3DTextLabel("Departamento de Polícia",0xFFFFFFFF,1554.8657,-1675.6693,16.1953,50.0,0);
    Create3DTextLabel("Departamento de Polícia",0xFFFFFFFF,2290.1218,2430.9775,10.8203,50.0,0);
    Create3DTextLabel("Departamento de Polícia",0xFFFFFFFF,-1605.5848,710.8436,13.8672,50.0,0);
    Create3DTextLabel("Departamento de Polícia",0xFFFFFFFF,627.7621,-571.7207,17.5526,50.0,0);
    Create3DTextLabel("Hospital",0xFFFFFFFF,1172.6787,-1323.3129,15.4022,50.0,0);
    Create3DTextLabel("Hospital",0xFFFFFFFF,1607.3579,1815.6309,10.8203,50.0,0);
    Create3DTextLabel("Hospital",0xFFFFFFFF,-2655.0662,639.1497,14.4531,50.0,0);
    Create3DTextLabel("Hospital",0xFFFFFFFF,-1514.8217,2520.3232,55.9185,50.0,0);
    Create3DTextLabel("Hospital",0xFFFFFFFF,1241.8073,327.1022,19.7555,50.0,0);
    Create3DTextLabel("Hospital",0xFFFFFFFF,-320.0716,1049.2637,20.3403,50.0,0);
    Create3DTextLabel("Banco",0xFFFFFFFF,1778.3052,-1663.5337,14.4362,50.0,0);
    Create3DTextLabel("Banco",0xFFFFFFFF,2388.6733,2466.0430,10.8203,50.0,0);
    Create3DTextLabel("Banco",0xFFFFFFFF,-2649.8374,376.0090,6.1563,50.0,0);
    Create3DTextLabel("Banco",0xFFFFFFFF,-180.3883,1133.1510,19.7422,50.0,0);
    Create3DTextLabel("Banco",0xFFFFFFFF,1372.9271,405.2487,19.9555,50.0,0);
    Create3DTextLabel("Banco",0xFFFFFFFF,2302.9521,-16.2789,26.4844,50.0,0);
    Create3DTextLabel("Banco",0xFFFFFFFF,-828.0650,1503.6166,19.7585,50.0,0);
    Create3DTextLabel("Banco",0xFFFFFFFF,-1480.8273,2592.3015,55.8359,50.0,0);
    Create3DTextLabel("Banco",0xFFFFFFFF,207.7767,-62.5814,1.6498,50.0,0);
    Create3DTextLabel("Imobiliaria",0xFFFFFFFF,1798.4763,-1578.3191,14.0849,50.0,0);
    Create3DTextLabel("Imobiliaria",0xFFFFFFFF,2413.2390,1123.8374,10.8203,50.0,0);
    Create3DTextLabel("Imobiliaria",0xFFFFFFFF,-1881.1293,822.7573,35.1773,50.0,0);
    Create3DTextLabel("Auto Escola",0xFFFFFFFF,1519.0413,-1453.5895,14.2073,50.0,0);
    Create3DTextLabel("Auto Escola",0xFFFFFFFF,2183.2483,2295.2205,10.8203,50.0,0);
    Create3DTextLabel("Auto Escola",0xFFFFFFFF,-2026.5950,-101.3410,35.1641,50.0,0);
    Create3DTextLabel("Detran",0xFFFFFFFF,1310.1411,-1367.8086,13.5408,50.0,0);
    Create3DTextLabel("Detran",0xFFFFFFFF,1173.1600,1349.0011,10.9219,50.0,0);
    Create3DTextLabel("Detran",0xFFFFFFFF,-2720.6375,127.7373,7.0391,50.0,0);

    //desabilitando interiores,stunt bonus, anims
    UsePlayerPedAnims();
	EnableStuntBonusForAll(0);
	DisableInteriorEnterExits();

    //Timers
    SetTimer("ProcessGameTime", segundos(1), true);
    SetTimer("RandomMSGs", minutos(20), true);

    //Rcon Commands
	SetGameModeText("Brasil - VB v1.0.0 BETA");
	SendRconCommand("mapname San Andreas");
	SendRconCommand("hostname Vida Brasileira ® | Server: 1 | #Ultra-h.com");
	SendRconCommand("language Português - Brasil");
	return 1;
}

public OnGameModeExit()
{
    mysql_close(IDConexao);
	return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
    TogglePlayerSpectating(playerid, true);
    InterpolateCameraPos(playerid,-2397.553710,1436.038452,140.798019,-2876.055175,1382.189697,159.150161,17000);
    InterpolateCameraLookAt(playerid,-2401.776855,1438.431640,139.599197,-2872.188964,1384.818359,157.377395,17000);
	return 1;
}

public OnPlayerConnect(playerid)
{
    //LOGIN
    foreach(Player, i){
    PlayerLogin[i][0] = CreatePlayerTextDraw(i, 248.500030, 108.317626, "box");
    PlayerTextDrawLetterSize(i, PlayerLogin[i][0], 0.000000, 5.720955);
    PlayerTextDrawTextSize(i, PlayerLogin[i][0], 390.319946, 0.000000);
    PlayerTextDrawAlignment(i, PlayerLogin[i][0], 1);
    PlayerTextDrawColor(i, PlayerLogin[i][0], -1);
    PlayerTextDrawUseBox(i, PlayerLogin[i][0], 1);
    PlayerTextDrawBoxColor(i, PlayerLogin[i][0], 130);
    PlayerTextDrawSetShadow(i, PlayerLogin[i][0], 0);
    PlayerTextDrawSetOutline(i, PlayerLogin[i][0], 0);
    PlayerTextDrawBackgroundColor(i, PlayerLogin[i][0], 255);
    PlayerTextDrawFont(i, PlayerLogin[i][0], 1);
    PlayerTextDrawSetProportional(i, PlayerLogin[i][0], 1);
    PlayerTextDrawSetShadow(i, PlayerLogin[i][0], 0);

    PlayerLogin[i][1] = CreatePlayerTextDraw(i, 248.800201, 163.838088, "box");
    PlayerTextDrawLetterSize(i, PlayerLogin[i][1], 0.000000, 20.999986);
    PlayerTextDrawTextSize(i, PlayerLogin[i][1], 390.000000, 0.000000);
    PlayerTextDrawAlignment(i, PlayerLogin[i][1], 1);
    PlayerTextDrawColor(i, PlayerLogin[i][1], -1);
    PlayerTextDrawUseBox(i, PlayerLogin[i][1], 1);
    PlayerTextDrawBoxColor(i, PlayerLogin[i][1], -1061109710);
    PlayerTextDrawSetShadow(i, PlayerLogin[i][1], 0);
    PlayerTextDrawSetOutline(i, PlayerLogin[i][1], 0);
    PlayerTextDrawBackgroundColor(i, PlayerLogin[i][1], 255);
    PlayerTextDrawFont(i, PlayerLogin[i][1], 1);
    PlayerTextDrawSetProportional(i, PlayerLogin[i][1], 1);
    PlayerTextDrawSetShadow(i, PlayerLogin[i][1], 0);

    PlayerLogin[i][2] = CreatePlayerTextDraw(i, 259.199768, 212.399978, "box");
    PlayerTextDrawLetterSize(i, PlayerLogin[i][2], 0.000000, 1.680000);
    PlayerTextDrawTextSize(i, PlayerLogin[i][2], 378.840576, 0.000000);
    PlayerTextDrawAlignment(i, PlayerLogin[i][2], 1);
    PlayerTextDrawColor(i, PlayerLogin[i][2], -1);
    PlayerTextDrawUseBox(i, PlayerLogin[i][2], 1);
    PlayerTextDrawBoxColor(i, PlayerLogin[i][2], -156);
    PlayerTextDrawSetShadow(i, PlayerLogin[i][2], 0);
    PlayerTextDrawSetOutline(i, PlayerLogin[i][2], 0);
    PlayerTextDrawBackgroundColor(i, PlayerLogin[i][2], 255);
    PlayerTextDrawFont(i, PlayerLogin[i][2], 1);
    PlayerTextDrawSetProportional(i, PlayerLogin[i][2], 1);
    PlayerTextDrawSetShadow(i, PlayerLogin[i][2], 0);

    PlayerLogin[i][3] = CreatePlayerTextDraw(i, 259.199768, 254.602554, "box");
    PlayerTextDrawLetterSize(i, PlayerLogin[i][3], 0.000000, 1.680000);
    PlayerTextDrawTextSize(i, PlayerLogin[i][3], 378.840576, 0.000000);
    PlayerTextDrawAlignment(i, PlayerLogin[i][3], 1);
    PlayerTextDrawColor(i, PlayerLogin[i][3], -1);
    PlayerTextDrawUseBox(i, PlayerLogin[i][3], 1);
    PlayerTextDrawBoxColor(i, PlayerLogin[i][3], -156);
    PlayerTextDrawSetShadow(i, PlayerLogin[i][3], 0);
    PlayerTextDrawSetOutline(i, PlayerLogin[i][3], 0);
    PlayerTextDrawBackgroundColor(i, PlayerLogin[i][3], 255);
    PlayerTextDrawFont(i, PlayerLogin[i][3], 1);
    PlayerTextDrawSetProportional(i, PlayerLogin[i][3], 1);
    PlayerTextDrawSetShadow(i, PlayerLogin[i][3], 0);

    PlayerLogin[i][4] = CreatePlayerTextDraw(i, 297.399932, 294.533386, "box");
    PlayerTextDrawLetterSize(i, PlayerLogin[i][4], 0.000000, 2.120000);
    PlayerTextDrawTextSize(i, PlayerLogin[i][4], 340.799987, 0.000000);
    PlayerTextDrawAlignment(i, PlayerLogin[i][4], 1);
    PlayerTextDrawColor(i, PlayerLogin[i][4], -1);
    PlayerTextDrawUseBox(i, PlayerLogin[i][4], 1);
    PlayerTextDrawBoxColor(i, PlayerLogin[i][4], -2147483393);
    PlayerTextDrawSetShadow(i, PlayerLogin[i][4], 0);
    PlayerTextDrawSetOutline(i, PlayerLogin[i][4], 0);
    PlayerTextDrawBackgroundColor(i, PlayerLogin[i][4], 255);
    PlayerTextDrawFont(i, PlayerLogin[i][4], 1);
    PlayerTextDrawSetProportional(i, PlayerLogin[i][4], 1);
    PlayerTextDrawSetShadow(i, PlayerLogin[i][4], 0);

    PlayerLogin[i][5] = CreatePlayerTextDraw(i, 346.599822, 329.875640, "box");
    PlayerTextDrawLetterSize(i, PlayerLogin[i][5], 0.000000, 1.952006);
    PlayerTextDrawTextSize(i, PlayerLogin[i][5], 384.949951, 0.000000);
    PlayerTextDrawAlignment(i, PlayerLogin[i][5], 1);
    PlayerTextDrawColor(i, PlayerLogin[i][5], -1);
    PlayerTextDrawUseBox(i, PlayerLogin[i][5], 1);
    PlayerTextDrawBoxColor(i, PlayerLogin[i][5], 8388863);
    PlayerTextDrawSetShadow(i, PlayerLogin[i][5], 0);
    PlayerTextDrawSetOutline(i, PlayerLogin[i][5], 0);
    PlayerTextDrawBackgroundColor(i, PlayerLogin[i][5], 255);
    PlayerTextDrawFont(i, PlayerLogin[i][5], 1);
    PlayerTextDrawSetProportional(i, PlayerLogin[i][5], 1);
    PlayerTextDrawSetShadow(i, PlayerLogin[i][5], 0);

    PlayerLogin[i][6] = CreatePlayerTextDraw(i, 276.599792, 119.715545, "Vida~n~___Brasileira");
    PlayerTextDrawLetterSize(i, PlayerLogin[i][6], 0.400000, 1.600000);
    PlayerTextDrawAlignment(i, PlayerLogin[i][6], 1);
    PlayerTextDrawColor(i, PlayerLogin[i][6], -1);
    PlayerTextDrawSetShadow(i, PlayerLogin[i][6], 0);
    PlayerTextDrawSetOutline(i, PlayerLogin[i][6], 1);
    PlayerTextDrawBackgroundColor(i, PlayerLogin[i][6], 190);
    PlayerTextDrawFont(i, PlayerLogin[i][6], 1);
    PlayerTextDrawSetProportional(i, PlayerLogin[i][6], 1);
    PlayerTextDrawSetShadow(i, PlayerLogin[i][6], 0);

    PlayerLogin[i][7] = CreatePlayerTextDraw(i, 257.100067, 199.871292, "Nome:");
    PlayerTextDrawLetterSize(i, PlayerLogin[i][7], 0.211999, 1.211732);
    PlayerTextDrawAlignment(i, PlayerLogin[i][7], 1);
    PlayerTextDrawColor(i, PlayerLogin[i][7], -1);
    PlayerTextDrawSetShadow(i, PlayerLogin[i][7], 0);
    PlayerTextDrawSetOutline(i, PlayerLogin[i][7], 0);
    PlayerTextDrawBackgroundColor(i, PlayerLogin[i][7], 255);
    PlayerTextDrawFont(i, PlayerLogin[i][7], 1);
    PlayerTextDrawSetProportional(i, PlayerLogin[i][7], 1);
    PlayerTextDrawSetShadow(i, PlayerLogin[i][7], 0);

    PlayerLogin[i][8] = CreatePlayerTextDraw(i, 257.100067, 241.873855, "Senha:");
    PlayerTextDrawLetterSize(i, PlayerLogin[i][8], 0.211999, 1.211732);
    PlayerTextDrawAlignment(i, PlayerLogin[i][8], 1);
    PlayerTextDrawColor(i, PlayerLogin[i][8], -1);
    PlayerTextDrawSetShadow(i, PlayerLogin[i][8], 0);
    PlayerTextDrawSetOutline(i, PlayerLogin[i][8], 0);
    PlayerTextDrawBackgroundColor(i, PlayerLogin[i][8], 255);
    PlayerTextDrawFont(i, PlayerLogin[i][8], 1);
    PlayerTextDrawSetProportional(i, PlayerLogin[i][8], 1);
    PlayerTextDrawSetShadow(i, PlayerLogin[i][8], 0);

    PlayerLogin[i][9] = CreatePlayerTextDraw(i, 262.100189, 214.391067, "CLIQUE_AQUI_PARA_COLOCAR_SEU_NOME");
    PlayerTextDrawLetterSize(i, PlayerLogin[i][9], 0.133597, 1.032528);
    PlayerTextDrawAlignment(i, PlayerLogin[i][9], 1);
    PlayerTextDrawColor(i, PlayerLogin[i][9], 100);
    PlayerTextDrawSetShadow(i, PlayerLogin[i][9], 0);
    PlayerTextDrawSetOutline(i, PlayerLogin[i][9], 0);
    PlayerTextDrawBackgroundColor(i, PlayerLogin[i][9], 255);
    PlayerTextDrawFont(i, PlayerLogin[i][9], 2);
    PlayerTextDrawSetProportional(i, PlayerLogin[i][9], 1);
    PlayerTextDrawSetShadow(i, PlayerLogin[i][9], 0);
    PlayerTextDrawSetSelectable(i, PlayerLogin[i][9], true);
    PlayerTextDrawTextSize(i, PlayerLogin[i][9], 378.000000, 10.000000);

    PlayerLogin[i][10] = CreatePlayerTextDraw(i, 261.500213, 256.204895, "CLIQUE_AQUI_PARA_COLOCAR_SUA_SENHA");
    PlayerTextDrawLetterSize(i, PlayerLogin[i][10], 0.126598, 1.061950);
    PlayerTextDrawAlignment(i, PlayerLogin[i][10], 1);
    PlayerTextDrawColor(i, PlayerLogin[i][10], 100);
    PlayerTextDrawSetShadow(i, PlayerLogin[i][10], 0);
    PlayerTextDrawSetOutline(i, PlayerLogin[i][10], 0);
    PlayerTextDrawBackgroundColor(i, PlayerLogin[i][10], 255);
    PlayerTextDrawFont(i, PlayerLogin[i][10], 2);
    PlayerTextDrawSetProportional(i, PlayerLogin[i][10], 1);
    PlayerTextDrawSetShadow(i, PlayerLogin[i][10], 0);
    PlayerTextDrawSetSelectable(i, PlayerLogin[i][10], true);
    PlayerTextDrawTextSize(i, PlayerLogin[i][10], 378.000000, 10.000000);

    PlayerLogin[i][11] = CreatePlayerTextDraw(i, 300.500091, 296.726745, "Entrar");
    PlayerTextDrawLetterSize(i, PlayerLogin[i][11], 0.360399, 1.550221);
    PlayerTextDrawAlignment(i, PlayerLogin[i][11], 1);
    PlayerTextDrawColor(i, PlayerLogin[i][11], -1);
    PlayerTextDrawSetShadow(i, PlayerLogin[i][11], 0);
    PlayerTextDrawSetOutline(i, PlayerLogin[i][11], 1);
    PlayerTextDrawBackgroundColor(i, PlayerLogin[i][11], 255);
    PlayerTextDrawFont(i, PlayerLogin[i][11], 1);
    PlayerTextDrawSetProportional(i, PlayerLogin[i][11], 1);
    PlayerTextDrawSetShadow(i, PlayerLogin[i][11], 0);
    PlayerTextDrawSetSelectable(i, PlayerLogin[i][11], true);
    PlayerTextDrawTextSize(i, PlayerLogin[i][11], 340.000000, 10.000000);

    PlayerLogin[i][12] = CreatePlayerTextDraw(i, 348.800048, 330.775543, "Registrar");
    PlayerTextDrawLetterSize(i, PlayerLogin[i][12], 0.219599, 1.385955);
    PlayerTextDrawAlignment(i, PlayerLogin[i][12], 1);
    PlayerTextDrawColor(i, PlayerLogin[i][12], -1);
    PlayerTextDrawSetShadow(i, PlayerLogin[i][12], 0);
    PlayerTextDrawSetOutline(i, PlayerLogin[i][12], 1);
    PlayerTextDrawBackgroundColor(i, PlayerLogin[i][12], 255);
    PlayerTextDrawFont(i, PlayerLogin[i][12], 1);
    PlayerTextDrawSetProportional(i, PlayerLogin[i][12], 1);
    PlayerTextDrawSetShadow(i, PlayerLogin[i][12], 0);
    PlayerTextDrawSetSelectable(i, PlayerLogin[i][12], true);
    PlayerTextDrawTextSize(i, PlayerLogin[i][12], 382.000000, 10.000000);

    //REGISTRO
    PlayerRegistro[i][0] = CreatePlayerTextDraw(i, 216.000137, 84.671127, "box");
    PlayerTextDrawLetterSize(i, PlayerRegistro[i][0], 0.000000, 5.120001);
    PlayerTextDrawTextSize(i, PlayerRegistro[i][0], 425.538818, 0.000000);
    PlayerTextDrawAlignment(i, PlayerRegistro[i][0], 1);
    PlayerTextDrawColor(i, PlayerRegistro[i][0], -1);
    PlayerTextDrawUseBox(i, PlayerRegistro[i][0], 1);
    PlayerTextDrawBoxColor(i, PlayerRegistro[i][0], 100);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][0], 0);
    PlayerTextDrawSetOutline(i, PlayerRegistro[i][0], 0);
    PlayerTextDrawBackgroundColor(i, PlayerRegistro[i][0], 255);
    PlayerTextDrawFont(i, PlayerRegistro[i][0], 1);
    PlayerTextDrawSetProportional(i, PlayerRegistro[i][0], 1);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][0], 0);

    PlayerRegistro[i][1] = CreatePlayerTextDraw(i, 216.199951, 135.637664, "box");
    PlayerTextDrawLetterSize(i, PlayerRegistro[i][1], 0.000000, 19.719972);
    PlayerTextDrawTextSize(i, PlayerRegistro[i][1], 301.200012, 0.000000);
    PlayerTextDrawAlignment(i, PlayerRegistro[i][1], 1);
    PlayerTextDrawColor(i, PlayerRegistro[i][1], -1);
    PlayerTextDrawUseBox(i, PlayerRegistro[i][1], 1);
    PlayerTextDrawBoxColor(i, PlayerRegistro[i][1], -1061109660);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][1], 0);
    PlayerTextDrawSetOutline(i, PlayerRegistro[i][1], 0);
    PlayerTextDrawBackgroundColor(i, PlayerRegistro[i][1], 255);
    PlayerTextDrawFont(i, PlayerRegistro[i][1], 1);
    PlayerTextDrawSetProportional(i, PlayerRegistro[i][1], 1);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][1], 0);

    PlayerRegistro[i][2] = CreatePlayerTextDraw(i, 305.499908, 135.739974, "box");
    PlayerTextDrawLetterSize(i, PlayerRegistro[i][2], 0.000000, 19.720031);
    PlayerTextDrawTextSize(i, PlayerRegistro[i][2], 425.499847, 0.000000);
    PlayerTextDrawAlignment(i, PlayerRegistro[i][2], 1);
    PlayerTextDrawColor(i, PlayerRegistro[i][2], -1);
    PlayerTextDrawUseBox(i, PlayerRegistro[i][2], 1);
    PlayerTextDrawBoxColor(i, PlayerRegistro[i][2], -1061109660);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][2], 0);
    PlayerTextDrawSetOutline(i, PlayerRegistro[i][2], 0);
    PlayerTextDrawBackgroundColor(i, PlayerRegistro[i][2], 255);
    PlayerTextDrawFont(i, PlayerRegistro[i][2], 1);
    PlayerTextDrawSetProportional(i, PlayerRegistro[i][2], 1);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][2], 0);

    PlayerRegistro[i][3] = CreatePlayerTextDraw(i, 196.600036, 152.217773, "");
    PlayerTextDrawLetterSize(i, PlayerRegistro[i][3], 0.000000, 0.000000);
    PlayerTextDrawTextSize(i, PlayerRegistro[i][3], 121.000000, 130.000000);
    PlayerTextDrawAlignment(i, PlayerRegistro[i][3], 1);
    PlayerTextDrawColor(i, PlayerRegistro[i][3], -1);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][3], 0);
    PlayerTextDrawSetOutline(i, PlayerRegistro[i][3], 0);
    PlayerTextDrawBackgroundColor(i, PlayerRegistro[i][3], 0);
    PlayerTextDrawFont(i, PlayerRegistro[i][3], 5);
    PlayerTextDrawSetProportional(i, PlayerRegistro[i][3], 0);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][3], 0);
    PlayerTextDrawSetPreviewModel(i, PlayerRegistro[i][3], SkinPlayer[playerid]);
    PlayerTextDrawSetPreviewRot(i, PlayerRegistro[i][3], 0.000000, 0.000000, 0.000000, 1.000000);

    PlayerRegistro[i][4] = CreatePlayerTextDraw(i, 218.800079, 293.239929, "box");
    PlayerTextDrawLetterSize(i, PlayerRegistro[i][4], 0.000000, 1.879999);
    PlayerTextDrawTextSize(i, PlayerRegistro[i][4], 255.579269, 0.000000);
    PlayerTextDrawAlignment(i, PlayerRegistro[i][4], 1);
    PlayerTextDrawColor(i, PlayerRegistro[i][4], -1);
    PlayerTextDrawUseBox(i, PlayerRegistro[i][4], 1);
    PlayerTextDrawBoxColor(i, PlayerRegistro[i][4], -2147483393);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][4], 0);
    PlayerTextDrawSetOutline(i, PlayerRegistro[i][4], 0);
    PlayerTextDrawBackgroundColor(i, PlayerRegistro[i][4], 41215);
    PlayerTextDrawFont(i, PlayerRegistro[i][4], 1);
    PlayerTextDrawSetProportional(i, PlayerRegistro[i][4], 1);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][4], 0);

    PlayerRegistro[i][5] = CreatePlayerTextDraw(i, 260.302612, 293.239929, "box");
    PlayerTextDrawLetterSize(i, PlayerRegistro[i][5], 0.000000, 1.879999);
    PlayerTextDrawTextSize(i, PlayerRegistro[i][5], 298.569396, 0.000000);
    PlayerTextDrawAlignment(i, PlayerRegistro[i][5], 1);
    PlayerTextDrawColor(i, PlayerRegistro[i][5], -1);
    PlayerTextDrawUseBox(i, PlayerRegistro[i][5], 1);
    PlayerTextDrawBoxColor(i, PlayerRegistro[i][5], -2147483393);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][5], 0);
    PlayerTextDrawSetOutline(i, PlayerRegistro[i][5], 0);
    PlayerTextDrawBackgroundColor(i, PlayerRegistro[i][5], 255);
    PlayerTextDrawFont(i, PlayerRegistro[i][5], 1);
    PlayerTextDrawSetProportional(i, PlayerRegistro[i][5], 1);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][5], 0);

    PlayerRegistro[i][6] = CreatePlayerTextDraw(i, 310.500061, 176.555496, "box");
    PlayerTextDrawLetterSize(i, PlayerRegistro[i][6], 0.000000, 1.456001);
    PlayerTextDrawTextSize(i, PlayerRegistro[i][6], 417.000000, 0.000000);
    PlayerTextDrawAlignment(i, PlayerRegistro[i][6], 1);
    PlayerTextDrawColor(i, PlayerRegistro[i][6], -1);
    PlayerTextDrawUseBox(i, PlayerRegistro[i][6], 1);
    PlayerTextDrawBoxColor(i, PlayerRegistro[i][6], -126);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][6], 0);
    PlayerTextDrawSetOutline(i, PlayerRegistro[i][6], 0);
    PlayerTextDrawBackgroundColor(i, PlayerRegistro[i][6], 255);
    PlayerTextDrawFont(i, PlayerRegistro[i][6], 1);
    PlayerTextDrawSetProportional(i, PlayerRegistro[i][6], 1);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][6], 0);

    PlayerRegistro[i][7] = CreatePlayerTextDraw(i, 311.500030, 213.755508, "box");
    PlayerTextDrawLetterSize(i, PlayerRegistro[i][7], 0.000000, 1.456001);
    PlayerTextDrawTextSize(i, PlayerRegistro[i][7], 417.750091, 0.000000);
    PlayerTextDrawAlignment(i, PlayerRegistro[i][7], 1);
    PlayerTextDrawColor(i, PlayerRegistro[i][7], -1);
    PlayerTextDrawUseBox(i, PlayerRegistro[i][7], 1);
    PlayerTextDrawBoxColor(i, PlayerRegistro[i][7], -126);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][7], 0);
    PlayerTextDrawSetOutline(i, PlayerRegistro[i][7], 0);
    PlayerTextDrawBackgroundColor(i, PlayerRegistro[i][7], 255);
    PlayerTextDrawFont(i, PlayerRegistro[i][7], 1);
    PlayerTextDrawSetProportional(i, PlayerRegistro[i][7], 1);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][7], 0);

    PlayerRegistro[i][8] = CreatePlayerTextDraw(i, 312.100067, 250.057723, "box");
    PlayerTextDrawLetterSize(i, PlayerRegistro[i][8], 0.000000, 1.456001);
    PlayerTextDrawTextSize(i, PlayerRegistro[i][8], 418.350128, 0.000000);
    PlayerTextDrawAlignment(i, PlayerRegistro[i][8], 1);
    PlayerTextDrawColor(i, PlayerRegistro[i][8], -1);
    PlayerTextDrawUseBox(i, PlayerRegistro[i][8], 1);
    PlayerTextDrawBoxColor(i, PlayerRegistro[i][8], -126);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][8], 0);
    PlayerTextDrawSetOutline(i, PlayerRegistro[i][8], 0);
    PlayerTextDrawBackgroundColor(i, PlayerRegistro[i][8], 255);
    PlayerTextDrawFont(i, PlayerRegistro[i][8], 1);
    PlayerTextDrawSetProportional(i, PlayerRegistro[i][8], 1);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][8], 0);

    PlayerRegistro[i][9] = CreatePlayerTextDraw(i, 344.400115, 282.000213, "box");
    PlayerTextDrawLetterSize(i, PlayerRegistro[i][9], 0.000000, 1.920001);
    PlayerTextDrawTextSize(i, PlayerRegistro[i][9], 384.930419, 0.000000);
    PlayerTextDrawAlignment(i, PlayerRegistro[i][9], 1);
    PlayerTextDrawColor(i, PlayerRegistro[i][9], -1);
    PlayerTextDrawUseBox(i, PlayerRegistro[i][9], 1);
    PlayerTextDrawBoxColor(i, PlayerRegistro[i][9], 8388863);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][9], 0);
    PlayerTextDrawSetOutline(i, PlayerRegistro[i][9], 0);
    PlayerTextDrawBackgroundColor(i, PlayerRegistro[i][9], 255);
    PlayerTextDrawFont(i, PlayerRegistro[i][9], 1);
    PlayerTextDrawSetProportional(i, PlayerRegistro[i][9], 1);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][9], 0);

    PlayerRegistro[i][10] = CreatePlayerTextDraw(i, 270.500122, 92.619934, "Vida~n~___Brasileira");
    PlayerTextDrawLetterSize(i, PlayerRegistro[i][10], 0.400000, 1.600000);
    PlayerTextDrawAlignment(i, PlayerRegistro[i][10], 1);
    PlayerTextDrawColor(i, PlayerRegistro[i][10], -1);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][10], 0);
    PlayerTextDrawSetOutline(i, PlayerRegistro[i][10], 2);
    PlayerTextDrawBackgroundColor(i, PlayerRegistro[i][10], 42);
    PlayerTextDrawFont(i, PlayerRegistro[i][10], 1);
    PlayerTextDrawSetProportional(i, PlayerRegistro[i][10], 1);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][10], 0);

    PlayerRegistro[i][11] = CreatePlayerTextDraw(i, 259.200134, 140.720092, "");
    PlayerTextDrawLetterSize(i, PlayerRegistro[i][11], 0.229200, 1.032533);
    PlayerTextDrawAlignment(i, PlayerRegistro[i][11], 2);
    PlayerTextDrawColor(i, PlayerRegistro[i][11], -1);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][11], 0);
    PlayerTextDrawSetOutline(i, PlayerRegistro[i][11], 1);
    PlayerTextDrawBackgroundColor(i, PlayerRegistro[i][11], 255);
    PlayerTextDrawFont(i, PlayerRegistro[i][11], 1);
    PlayerTextDrawSetProportional(i, PlayerRegistro[i][11], 1);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][11], 0);

    PlayerRegistro[i][12] = CreatePlayerTextDraw(i, 308.799987, 163.617813, "Nome:");
    PlayerTextDrawLetterSize(i, PlayerRegistro[i][12], 0.206398, 1.311287);
    PlayerTextDrawAlignment(i, PlayerRegistro[i][12], 1);
    PlayerTextDrawColor(i, PlayerRegistro[i][12], -1);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][12], 0);
    PlayerTextDrawSetOutline(i, PlayerRegistro[i][12], 0);
    PlayerTextDrawBackgroundColor(i, PlayerRegistro[i][12], 255);
    PlayerTextDrawFont(i, PlayerRegistro[i][12], 1);
    PlayerTextDrawSetProportional(i, PlayerRegistro[i][12], 1);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][12], 0);

    PlayerRegistro[i][13] = CreatePlayerTextDraw(i, 309.700042, 200.820083, "Senha:");
    PlayerTextDrawLetterSize(i, PlayerRegistro[i][13], 0.206398, 1.311287);
    PlayerTextDrawAlignment(i, PlayerRegistro[i][13], 1);
    PlayerTextDrawColor(i, PlayerRegistro[i][13], -1);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][13], 0);
    PlayerTextDrawSetOutline(i, PlayerRegistro[i][13], 0);
    PlayerTextDrawBackgroundColor(i, PlayerRegistro[i][13], 255);
    PlayerTextDrawFont(i, PlayerRegistro[i][13], 1);
    PlayerTextDrawSetProportional(i, PlayerRegistro[i][13], 1);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][13], 0);

    PlayerRegistro[i][14] = CreatePlayerTextDraw(i, 310.100006, 237.722335, "E-mail:");
    PlayerTextDrawLetterSize(i, PlayerRegistro[i][14], 0.206398, 1.231287);
    PlayerTextDrawAlignment(i, PlayerRegistro[i][14], 1);
    PlayerTextDrawColor(i, PlayerRegistro[i][14], -1);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][14], 0);
    PlayerTextDrawSetOutline(i, PlayerRegistro[i][14], 0);
    PlayerTextDrawBackgroundColor(i, PlayerRegistro[i][14], 255);
    PlayerTextDrawFont(i, PlayerRegistro[i][14], 1);
    PlayerTextDrawSetProportional(i, PlayerRegistro[i][14], 1);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][14], 0);

    PlayerRegistro[i][15] = CreatePlayerTextDraw(i, 227.900192, 294.575500, "ld_beat:left");
    PlayerTextDrawLetterSize(i, PlayerRegistro[i][15], 0.000000, 0.000000);
    PlayerTextDrawTextSize(i, PlayerRegistro[i][15], 16.060001, 16.000000);
    PlayerTextDrawAlignment(i, PlayerRegistro[i][15], 1);
    PlayerTextDrawColor(i, PlayerRegistro[i][15], -1);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][15], 0);
    PlayerTextDrawSetOutline(i, PlayerRegistro[i][15], 0);
    PlayerTextDrawBackgroundColor(i, PlayerRegistro[i][15], 255);
    PlayerTextDrawFont(i, PlayerRegistro[i][15], 4);
    PlayerTextDrawSetProportional(i, PlayerRegistro[i][15], 0);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][15], 0);
    PlayerTextDrawSetSelectable(i, PlayerRegistro[i][15], true);

    PlayerRegistro[i][16] = CreatePlayerTextDraw(i, 271.002807, 294.575500, "ld_beat:right");
    PlayerTextDrawLetterSize(i, PlayerRegistro[i][16], 0.000000, 0.000000);
    PlayerTextDrawTextSize(i, PlayerRegistro[i][16], 16.060001, 16.000000);
    PlayerTextDrawAlignment(i, PlayerRegistro[i][16], 1);
    PlayerTextDrawColor(i, PlayerRegistro[i][16], -1);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][16], 0);
    PlayerTextDrawSetOutline(i, PlayerRegistro[i][16], 0);
    PlayerTextDrawBackgroundColor(i, PlayerRegistro[i][16], 255);
    PlayerTextDrawFont(i, PlayerRegistro[i][16], 4);
    PlayerTextDrawSetProportional(i, PlayerRegistro[i][16], 0);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][16], 0);
    PlayerTextDrawSetSelectable(i, PlayerRegistro[i][16], true);

    PlayerRegistro[i][17] = CreatePlayerTextDraw(i, 312.299987, 177.562347, "CLIQUE_AQUI_PARA_COLOCAR_SEU_NOME");
    PlayerTextDrawLetterSize(i, PlayerRegistro[i][17], 0.111397, 1.017374);
    PlayerTextDrawAlignment(i, PlayerRegistro[i][17], 1);
    PlayerTextDrawColor(i, PlayerRegistro[i][17], 100);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][17], 0);
    PlayerTextDrawSetOutline(i, PlayerRegistro[i][17], 0);
    PlayerTextDrawBackgroundColor(i, PlayerRegistro[i][17], 255);
    PlayerTextDrawFont(i, PlayerRegistro[i][17], 2);
    PlayerTextDrawSetProportional(i, PlayerRegistro[i][17], 1);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][17], 0);
    PlayerTextDrawSetSelectable(i, PlayerRegistro[i][17], true);
    PlayerTextDrawTextSize(i, PlayerRegistro[i][17], 415.000000, 10.000000);

    PlayerRegistro[i][18] = CreatePlayerTextDraw(i, 312.900024, 214.564605, "CLIQUE_AQUI_PARA_COLOCAR_SUA_SENHA");
    PlayerTextDrawLetterSize(i, PlayerRegistro[i][18], 0.104598, 1.037153);
    PlayerTextDrawAlignment(i, PlayerRegistro[i][18], 1);
    PlayerTextDrawColor(i, PlayerRegistro[i][18], 100);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][18], 0);
    PlayerTextDrawSetOutline(i, PlayerRegistro[i][18], 0);
    PlayerTextDrawBackgroundColor(i, PlayerRegistro[i][18], 255);
    PlayerTextDrawFont(i, PlayerRegistro[i][18], 2);
    PlayerTextDrawSetProportional(i, PlayerRegistro[i][18], 1);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][18], 0);
    PlayerTextDrawSetSelectable(i, PlayerRegistro[i][18], true);
    PlayerTextDrawTextSize(i, PlayerRegistro[i][18], 415.000000, 10.000000);

    PlayerRegistro[i][19] = CreatePlayerTextDraw(i, 313.500030, 250.964569, "CLIQUE_AQUI_PARA_COLOCAR_SEU_E-MAIL");
    PlayerTextDrawLetterSize(i, PlayerRegistro[i][19], 0.103597, 1.001731);
    PlayerTextDrawAlignment(i, PlayerRegistro[i][19], 1);
    PlayerTextDrawColor(i, PlayerRegistro[i][19], 100);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][19], 0);
    PlayerTextDrawSetOutline(i, PlayerRegistro[i][19], 0);
    PlayerTextDrawBackgroundColor(i, PlayerRegistro[i][19], 255);
    PlayerTextDrawFont(i, PlayerRegistro[i][19], 2);
    PlayerTextDrawSetProportional(i, PlayerRegistro[i][19], 1);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][19], 0);
    PlayerTextDrawSetSelectable(i, PlayerRegistro[i][19], true);
    PlayerTextDrawTextSize(i, PlayerRegistro[i][19], 415.000000, 10.000000);

    PlayerRegistro[i][20] = CreatePlayerTextDraw(i, 347.100128, 283.291229, "Registrar");
    PlayerTextDrawLetterSize(i, PlayerRegistro[i][20], 0.254400, 1.351111);
    PlayerTextDrawAlignment(i, PlayerRegistro[i][20], 1);
    PlayerTextDrawColor(i, PlayerRegistro[i][20], -1);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][20], 0);
    PlayerTextDrawSetOutline(i, PlayerRegistro[i][20], -1);
    PlayerTextDrawBackgroundColor(i, PlayerRegistro[i][20], 255);
    PlayerTextDrawFont(i, PlayerRegistro[i][20], 1);
    PlayerTextDrawSetProportional(i, PlayerRegistro[i][20], 1);
    PlayerTextDrawSetShadow(i, PlayerRegistro[i][20], 0);
    PlayerTextDrawSetSelectable(i, PlayerRegistro[i][20], true);
    PlayerTextDrawTextSize(i, PlayerRegistro[i][20], 380.000000, 10.000000);

    //Status
    PlayerStatus[i][0] = CreatePlayerTextDraw(i, 559.696166, 295.111968, "box");
    PlayerTextDrawLetterSize(i, PlayerStatus[i][0], 0.000000, 16.298648);
    PlayerTextDrawTextSize(i, PlayerStatus[i][0], 636.076538, 0.000000);
    PlayerTextDrawAlignment(i, PlayerStatus[i][0], 1);
    PlayerTextDrawUseBox(i, PlayerStatus[i][0], 1);
    PlayerTextDrawBoxColor(i, PlayerStatus[i][0], 130);

    PlayerStatus[i][1] = CreatePlayerTextDraw(i, 560.699951, 296.777862, "box");
    PlayerTextDrawLetterSize(i, PlayerStatus[i][1], 0.000000, 1.939012);
    PlayerTextDrawTextSize(i, PlayerStatus[i][1], 634.797485, 0.000000);
    PlayerTextDrawAlignment(i, PlayerStatus[i][1], 1);
    PlayerTextDrawUseBox(i, PlayerStatus[i][1], 1);
    PlayerTextDrawBoxColor(i, PlayerStatus[i][1], -2139062222);

    PlayerStatus[i][2] = CreatePlayerTextDraw(i, 560.699951, 320.579315, "box");
    PlayerTextDrawLetterSize(i, PlayerStatus[i][2], 0.000000, 1.465988);
    PlayerTextDrawTextSize(i, PlayerStatus[i][2], 634.797485, 0.000000);
    PlayerTextDrawAlignment(i, PlayerStatus[i][2], 1);
    PlayerTextDrawUseBox(i, PlayerStatus[i][2], 1);
    PlayerTextDrawBoxColor(i, PlayerStatus[i][2], -2139062222);

    PlayerStatus[i][3] = CreatePlayerTextDraw(i, 560.699951, 339.880493, "box");
    PlayerTextDrawLetterSize(i, PlayerStatus[i][3], 0.000000, 1.465988);
    PlayerTextDrawTextSize(i, PlayerStatus[i][3], 634.797485, 0.000000);
    PlayerTextDrawAlignment(i, PlayerStatus[i][3], 1);
    PlayerTextDrawUseBox(i, PlayerStatus[i][3], 1);
    PlayerTextDrawBoxColor(i, PlayerStatus[i][3], -2139062222);

    PlayerStatus[i][4] = CreatePlayerTextDraw(i, 560.699951, 359.381683, "box");
    PlayerTextDrawLetterSize(i, PlayerStatus[i][4], 0.000000, 1.465988);
    PlayerTextDrawTextSize(i, PlayerStatus[i][4], 634.797485, 0.000000);
    PlayerTextDrawAlignment(i, PlayerStatus[i][4], 1);
    PlayerTextDrawUseBox(i, PlayerStatus[i][4], 1);
    PlayerTextDrawBoxColor(i, PlayerStatus[i][4], -2139062222);

    PlayerStatus[i][5] = CreatePlayerTextDraw(i, 560.699951, 378.482849, "box");
    PlayerTextDrawLetterSize(i, PlayerStatus[i][5], 0.000000, 1.465988);
    PlayerTextDrawTextSize(i, PlayerStatus[i][5], 634.797485, 0.000000);
    PlayerTextDrawAlignment(i, PlayerStatus[i][5], 1);
    PlayerTextDrawUseBox(i, PlayerStatus[i][5], 1);
    PlayerTextDrawBoxColor(i, PlayerStatus[i][5], -2139062222);

    PlayerStatus[i][6] = CreatePlayerTextDraw(i, 560.699951, 397.984039, "box");
    PlayerTextDrawLetterSize(i, PlayerStatus[i][6], 0.000000, 1.465988);
    PlayerTextDrawTextSize(i, PlayerStatus[i][6], 634.797485, 0.000000);
    PlayerTextDrawAlignment(i, PlayerStatus[i][6], 1);
    PlayerTextDrawUseBox(i, PlayerStatus[i][6], 1);
    PlayerTextDrawBoxColor(i, PlayerStatus[i][6], -2139062222);

    PlayerStatus[i][7] = CreatePlayerTextDraw(i, 560.699951, 417.085205, "box");
    PlayerTextDrawLetterSize(i, PlayerStatus[i][7], 0.000000, 1.419983);
    PlayerTextDrawTextSize(i, PlayerStatus[i][7], 635.000000, 0.000000);
    PlayerTextDrawAlignment(i, PlayerStatus[i][7], 1);
    PlayerTextDrawUseBox(i, PlayerStatus[i][7], 1);
    PlayerTextDrawBoxColor(i, PlayerStatus[i][7], -2139062222);

    PlayerStatus[i][8] = CreatePlayerTextDraw(i, 560.699951, 434.986297, "box");
    PlayerTextDrawLetterSize(i, PlayerStatus[i][8], 0.000000, 0.626972);
    PlayerTextDrawTextSize(i, PlayerStatus[i][8], 633.000000, 0.000000);
    PlayerTextDrawAlignment(i, PlayerStatus[i][8], 1);
    PlayerTextDrawUseBox(i, PlayerStatus[i][8], 1);
    PlayerTextDrawBoxColor(i, PlayerStatus[i][8], -2139062222);

    PlayerStatus[i][9] = CreatePlayerTextDraw(i, 577.499877, 341.800140, "box");
    PlayerTextDrawLetterSize(i, PlayerStatus[i][9], 0.000000, 1.139001);
    PlayerTextDrawTextSize(i, PlayerStatus[i][9], 633.830200, 0.000000);
    PlayerTextDrawAlignment(i, PlayerStatus[i][9], 1);
    PlayerTextDrawUseBox(i, PlayerStatus[i][9], 1);
    PlayerTextDrawBoxColor(i, PlayerStatus[i][9], -1061109660);

    PlayerStatus[i][10] = CreatePlayerTextDraw(i, 577.499877, 360.801300, "box"); //273px
    PlayerTextDrawLetterSize(i, PlayerStatus[i][10], 0.000000, 1.139001);
    PlayerTextDrawTextSize(i, PlayerStatus[i][10], 633.830200, 0.000000);
    PlayerTextDrawBoxColor(i, PlayerStatus[i][10], -1061109660);
    PlayerTextDrawUseBox(i, PlayerStatus[i][10], 1);

    PlayerStatus[i][11] = CreatePlayerTextDraw(i, 577.499877, 380.202484, "box");
    PlayerTextDrawLetterSize(i, PlayerStatus[i][11], 0.000000, 1.139001);
    PlayerTextDrawTextSize(i, PlayerStatus[i][11], 633.830200, 0.000000);
    PlayerTextDrawAlignment(i, PlayerStatus[i][11], 1);
    PlayerTextDrawUseBox(i, PlayerStatus[i][11], 1);
    PlayerTextDrawBoxColor(i, PlayerStatus[i][11], -1061109660);

    PlayerStatus[i][12] = CreatePlayerTextDraw(i, 577.499877, 399.303649, "box");
    PlayerTextDrawLetterSize(i, PlayerStatus[i][12], 0.000000, 1.139001);
    PlayerTextDrawTextSize(i, PlayerStatus[i][12], 633.830200, 0.000000);
    PlayerTextDrawAlignment(i, PlayerStatus[i][12], 1);
    PlayerTextDrawUseBox(i, PlayerStatus[i][12], 1);
    PlayerTextDrawBoxColor(i, PlayerStatus[i][12], -1061109660);

    PlayerStatus[i][13] = CreatePlayerTextDraw(i, 577.499877, 418.404815, "box");
    PlayerTextDrawLetterSize(i, PlayerStatus[i][13], 0.000000, 1.139001);
    PlayerTextDrawTextSize(i, PlayerStatus[i][13], 633.830200, 0.000000);
    PlayerTextDrawAlignment(i, PlayerStatus[i][13], 1);
    PlayerTextDrawUseBox(i, PlayerStatus[i][13], 1);
    PlayerTextDrawBoxColor(i, PlayerStatus[i][13], -1061109660);

    PlayerStatus[i][14] = CreatePlayerTextDraw(i, 577.499877, 341.800140, "box");
    PlayerTextDrawLetterSize(i, PlayerStatus[i][14], 0.000000, 1.139001);
    PlayerTextDrawTextSize(i, PlayerStatus[i][14], 633.830200, 0.000000);
    PlayerTextDrawAlignment(i, PlayerStatus[i][14], 1);
    PlayerTextDrawUseBox(i, PlayerStatus[i][14], 1);
    PlayerTextDrawBoxColor(i, PlayerStatus[i][14], -106);

    PlayerStatus[i][15] = CreatePlayerTextDraw(i, 577.499877, 360.801300, "box");
    PlayerTextDrawLetterSize(i, PlayerStatus[i][15], 0.000000, 1.139001);
    PlayerTextDrawTextSize(i, PlayerStatus[i][15], 633.830200, 0.000000);
    PlayerTextDrawAlignment(i, PlayerStatus[i][15], 1);
    PlayerTextDrawUseBox(i, PlayerStatus[i][15], 1);
    PlayerTextDrawBoxColor(i, PlayerStatus[i][15], -106);

    PlayerStatus[i][16] = CreatePlayerTextDraw(i, 577.499877, 380.202484, "box");
    PlayerTextDrawLetterSize(i, PlayerStatus[i][16], 0.000000, 1.139001);
    PlayerTextDrawTextSize(i, PlayerStatus[i][16], 633.830200, 0.000000);
    PlayerTextDrawAlignment(i, PlayerStatus[i][16], 1);
    PlayerTextDrawUseBox(i, PlayerStatus[i][16], 1);
    PlayerTextDrawBoxColor(i, PlayerStatus[i][16], -106);

    PlayerStatus[i][17] = CreatePlayerTextDraw(i, 577.499877, 399.303649, "box");
    PlayerTextDrawLetterSize(i, PlayerStatus[i][17], 0.000000, 1.139001);
    PlayerTextDrawTextSize(i, PlayerStatus[i][17], 633.830200, 0.000000);
    PlayerTextDrawAlignment(i, PlayerStatus[i][17], 1);
    PlayerTextDrawUseBox(i, PlayerStatus[i][17], 1);
    PlayerTextDrawBoxColor(i, PlayerStatus[i][17], -106);

    PlayerStatus[i][18] = CreatePlayerTextDraw(i, 577.499877, 418.404815, "box");
    PlayerTextDrawLetterSize(i, PlayerStatus[i][18], 0.000000, 1.139001);
    PlayerTextDrawTextSize(i, PlayerStatus[i][18], 633.830200, 0.000000);
    PlayerTextDrawAlignment(i, PlayerStatus[i][18], 1);
    PlayerTextDrawUseBox(i, PlayerStatus[i][18], 1);
    PlayerTextDrawBoxColor(i, PlayerStatus[i][18], -106);

    PlayerStatus[i][19] = CreatePlayerTextDraw(i, 562.000000, 285.200012, "Status");
    PlayerTextDrawLetterSize(i, PlayerStatus[i][19], 0.400000, 1.600000);
    PlayerTextDrawAlignment(i, PlayerStatus[i][19], 1);
    PlayerTextDrawColor(i, PlayerStatus[i][19], -2139062017);
    PlayerTextDrawSetShadow(i, PlayerStatus[i][19], 1);
    PlayerTextDrawSetOutline(i, PlayerStatus[i][19], 1);
    PlayerTextDrawBackgroundColor(i, PlayerStatus[i][19], 61);
    PlayerTextDrawFont(i, PlayerStatus[i][19], 0);
    PlayerTextDrawSetProportional(i, PlayerStatus[i][19], 1);
    PlayerTextDrawSetShadow(i, PlayerStatus[i][19], 1);

    UPRelogio[i] = SetTimerEx("RelogioUP",segundos(1),true,"i",i);
    PlayerStatus[i][20] = CreatePlayerTextDraw(i, 598.600097, 302.655731, "");
    PlayerTextDrawLetterSize(i, PlayerStatus[i][20], 0.331000, 1.130000);
    PlayerTextDrawAlignment(i, PlayerStatus[i][20], 2);
    PlayerTextDrawColor(i, PlayerStatus[i][20], -1);
    PlayerTextDrawSetShadow(i, PlayerStatus[i][20], 0);
    PlayerTextDrawSetOutline(i, PlayerStatus[i][20], -1);
    PlayerTextDrawBackgroundColor(i, PlayerStatus[i][20], 255);
    PlayerTextDrawFont(i, PlayerStatus[i][20], 3);
    PlayerTextDrawSetProportional(i, PlayerStatus[i][20], 1);
    PlayerTextDrawSetShadow(i, PlayerStatus[i][20], 0);

    PlayerStatus[i][21] = CreatePlayerTextDraw(i, 597.096435, 319.744506, "0");
    PlayerTextDrawLetterSize(i, PlayerStatus[i][21], 0.399000, 1.600000);
    PlayerTextDrawAlignment(i, PlayerStatus[i][21], 2);
    PlayerTextDrawColor(i, PlayerStatus[i][21], -1);
    PlayerTextDrawSetShadow(i, PlayerStatus[i][21], 0);
    PlayerTextDrawSetOutline(i, PlayerStatus[i][21], -1);
    PlayerTextDrawBackgroundColor(i, PlayerStatus[i][21], 255);
    PlayerTextDrawFont(i, PlayerStatus[i][21], 1);
    PlayerTextDrawSetProportional(i, PlayerStatus[i][21], 1);
    PlayerTextDrawSetShadow(i, PlayerStatus[i][21], 0);

    PlayerStatus[i][22] = CreatePlayerTextDraw(i, 558.999877, 318.977905, "");
    PlayerTextDrawLetterSize(i, PlayerStatus[i][22], 0.000000, 0.000000);
    PlayerTextDrawTextSize(i, PlayerStatus[i][22], 16.000000, 17.000000);
    PlayerTextDrawAlignment(i, PlayerStatus[i][22], 1);
    PlayerTextDrawColor(i, PlayerStatus[i][22], -1);
    PlayerTextDrawSetShadow(i, PlayerStatus[i][22], 0);
    PlayerTextDrawSetOutline(i, PlayerStatus[i][22], 0);
    PlayerTextDrawBackgroundColor(i, PlayerStatus[i][22], 0);
    PlayerTextDrawFont(i, PlayerStatus[i][22], 5);
    PlayerTextDrawSetProportional(i, PlayerStatus[i][22], 0);
    PlayerTextDrawSetShadow(i, PlayerStatus[i][22], 0);
    PlayerTextDrawSetPreviewModel(i, PlayerStatus[i][22], 1247);
    PlayerTextDrawSetPreviewRot(i, PlayerStatus[i][22], 0.000000, 0.000000, 0.000000, 1.000000);

    PlayerStatus[i][23] = CreatePlayerTextDraw(i, 558.999877, 338.179077, "");
    PlayerTextDrawLetterSize(i, PlayerStatus[i][23], 0.000000, 0.000000);
    PlayerTextDrawTextSize(i, PlayerStatus[i][23], 16.000000, 17.000000);
    PlayerTextDrawAlignment(i, PlayerStatus[i][23], 1);
    PlayerTextDrawColor(i, PlayerStatus[i][23], -1);
    PlayerTextDrawSetShadow(i, PlayerStatus[i][23], 0);
    PlayerTextDrawSetOutline(i, PlayerStatus[i][23], 0);
    PlayerTextDrawBackgroundColor(i, PlayerStatus[i][23], 0);
    PlayerTextDrawFont(i, PlayerStatus[i][23], 5);
    PlayerTextDrawSetProportional(i, PlayerStatus[i][23], 0);
    PlayerTextDrawSetShadow(i, PlayerStatus[i][23], 0);
    PlayerTextDrawSetPreviewModel(i, PlayerStatus[i][23], 2880);
    PlayerTextDrawSetPreviewRot(i, PlayerStatus[i][23], 0.000000, 0.000000, 0.000000, 1.000000);

    PlayerStatus[i][24] = CreatePlayerTextDraw(i, 558.999877, 357.580261, "");
    PlayerTextDrawLetterSize(i, PlayerStatus[i][24], 0.000000, 0.000000);
    PlayerTextDrawTextSize(i, PlayerStatus[i][24], 16.000000, 17.000000);
    PlayerTextDrawAlignment(i, PlayerStatus[i][24], 1);
    PlayerTextDrawColor(i, PlayerStatus[i][24], -1);
    PlayerTextDrawSetShadow(i, PlayerStatus[i][24], 0);
    PlayerTextDrawSetOutline(i, PlayerStatus[i][24], 0);
    PlayerTextDrawBackgroundColor(i, PlayerStatus[i][24], 0);
    PlayerTextDrawFont(i, PlayerStatus[i][24], 5);
    PlayerTextDrawSetProportional(i, PlayerStatus[i][24], 0);
    PlayerTextDrawSetShadow(i, PlayerStatus[i][24], 0);
    PlayerTextDrawSetPreviewModel(i, PlayerStatus[i][24], 1484);
    PlayerTextDrawSetPreviewRot(i, PlayerStatus[i][24], 0.000000, 0.000000, 0.000000, 1.000000);

    PlayerStatus[i][25] = CreatePlayerTextDraw(i, 558.999877, 376.581420, "");
    PlayerTextDrawLetterSize(i, PlayerStatus[i][25], 0.000000, 0.000000);
    PlayerTextDrawTextSize(i, PlayerStatus[i][25], 16.000000, 17.000000);
    PlayerTextDrawAlignment(i, PlayerStatus[i][25], 1);
    PlayerTextDrawColor(i, PlayerStatus[i][25], -1);
    PlayerTextDrawSetShadow(i, PlayerStatus[i][25], 0);
    PlayerTextDrawSetOutline(i, PlayerStatus[i][25], 0);
    PlayerTextDrawBackgroundColor(i, PlayerStatus[i][25], 0);
    PlayerTextDrawFont(i, PlayerStatus[i][25], 5);
    PlayerTextDrawSetProportional(i, PlayerStatus[i][25], 0);
    PlayerTextDrawSetShadow(i, PlayerStatus[i][25], 0);
    PlayerTextDrawSetPreviewModel(i, PlayerStatus[i][25], 14866);
    PlayerTextDrawSetPreviewRot(i, PlayerStatus[i][25], 0.000000, 0.000000, 0.000000, 1.000000);

    PlayerStatus[i][26] = CreatePlayerTextDraw(i, 551.499389, 371.911193, "");
    PlayerTextDrawLetterSize(i, PlayerStatus[i][26], 0.000000, 0.000000);
    PlayerTextDrawTextSize(i, PlayerStatus[i][26], 32.000000, 64.000000);
    PlayerTextDrawAlignment(i, PlayerStatus[i][26], 1);
    PlayerTextDrawColor(i, PlayerStatus[i][26], -1);
    PlayerTextDrawSetShadow(i, PlayerStatus[i][26], 0);
    PlayerTextDrawSetOutline(i, PlayerStatus[i][26], 0);
    PlayerTextDrawBackgroundColor(i, PlayerStatus[i][26], 0);
    PlayerTextDrawFont(i, PlayerStatus[i][26], 5);
    PlayerTextDrawSetProportional(i, PlayerStatus[i][26], 0);
    PlayerTextDrawSetShadow(i, PlayerStatus[i][26], 0);
    PlayerTextDrawSetPreviewModel(i, PlayerStatus[i][26], 1665);
    PlayerTextDrawSetPreviewRot(i, PlayerStatus[i][26], 0.000000, 0.000000, 0.000000, 1.000000);

    PlayerStatus[i][27] = CreatePlayerTextDraw(i, 559.199523, 414.600250, "");
    PlayerTextDrawLetterSize(i, PlayerStatus[i][27], 0.000000, 0.000000);
    PlayerTextDrawTextSize(i, PlayerStatus[i][27], 15.000000, 17.000000);
    PlayerTextDrawAlignment(i, PlayerStatus[i][27], 1);
    PlayerTextDrawColor(i, PlayerStatus[i][27], -1);
    PlayerTextDrawSetShadow(i, PlayerStatus[i][27], 0);
    PlayerTextDrawSetOutline(i, PlayerStatus[i][27], 0);
    PlayerTextDrawBackgroundColor(i, PlayerStatus[i][27], 0);
    PlayerTextDrawFont(i, PlayerStatus[i][27], 5);
    PlayerTextDrawSetProportional(i, PlayerStatus[i][27], 0);
    PlayerTextDrawSetShadow(i, PlayerStatus[i][27], 0);
    PlayerTextDrawSetPreviewModel(i, PlayerStatus[i][27], 1240);
    PlayerTextDrawSetPreviewRot(i, PlayerStatus[i][27], 0.000000, 0.000000, 0.000000, 1.000000);

    PlayerStatus[i][28] = CreatePlayerTextDraw(i, 561.500854, 432.500152, "www.vidabrasileira.forumeiros.com");
    PlayerTextDrawLetterSize(i, PlayerStatus[i][28], 0.117500, 1.017333);
    PlayerTextDrawAlignment(i, PlayerStatus[i][28], 1);
    PlayerTextDrawColor(i, PlayerStatus[i][28], -1);
    PlayerTextDrawSetShadow(i, PlayerStatus[i][28], 0);
    PlayerTextDrawSetOutline(i, PlayerStatus[i][28], 1);
    PlayerTextDrawBackgroundColor(i, PlayerStatus[i][28], 255);
    PlayerTextDrawFont(i, PlayerStatus[i][28], 1);
    PlayerTextDrawSetProportional(i, PlayerStatus[i][28], 1);
    PlayerTextDrawSetShadow(i, PlayerStatus[i][28], 0);

    CarregandoInterior[i] = CreatePlayerTextDraw(i, 252.800033, 399.066589, "Carregando_Interior...");
    PlayerTextDrawLetterSize(i, CarregandoInterior[i], 0.400000, 1.600000);
    PlayerTextDrawAlignment(i, CarregandoInterior[i], 1);
    PlayerTextDrawColor(i, CarregandoInterior[i], -1);
    PlayerTextDrawSetShadow(i, CarregandoInterior[i], 0);
    PlayerTextDrawSetOutline(i, CarregandoInterior[i], -1);
    PlayerTextDrawBackgroundColor(i, CarregandoInterior[i], 255);
    PlayerTextDrawFont(i, CarregandoInterior[i], 1);
    PlayerTextDrawSetProportional(i, CarregandoInterior[i], 1);
    PlayerTextDrawSetShadow(i, CarregandoInterior[i], 0);

    PlayerPreso[i][0] = CreatePlayerTextDraw(i, 39.499961, 311.260009, "box");
    PlayerTextDrawLetterSize(i, PlayerPreso[i][0], 0.000000, 2.400000);
    PlayerTextDrawTextSize(i, PlayerPreso[i][0], 133.699920, 0.000000);
    PlayerTextDrawAlignment(i, PlayerPreso[i][0], 1);
    PlayerTextDrawColor(i, PlayerPreso[i][0], -1);
    PlayerTextDrawUseBox(i, PlayerPreso[i][0], 1);
    PlayerTextDrawBoxColor(i, PlayerPreso[i][0], 70);
    PlayerTextDrawSetShadow(i, PlayerPreso[i][0], 0);
    PlayerTextDrawSetOutline(i, PlayerPreso[i][0], 0);
    PlayerTextDrawBackgroundColor(i, PlayerPreso[i][0], 255);
    PlayerTextDrawFont(i, PlayerPreso[i][0], 1);
    PlayerTextDrawSetProportional(i, PlayerPreso[i][0], 1);
    PlayerTextDrawSetShadow(i, PlayerPreso[i][0], 0);

    PlayerPreso[i][1] = CreatePlayerTextDraw(i, 22.999994, 277.453369, "");
    PlayerTextDrawLetterSize(i, PlayerPreso[i][1], 0.000000, 0.000000);
    PlayerTextDrawTextSize(i, PlayerPreso[i][1], 56.000000, 88.000000);
    PlayerTextDrawAlignment(i, PlayerPreso[i][1], 1);
    PlayerTextDrawColor(i, PlayerPreso[i][1], -1);
    PlayerTextDrawSetShadow(i, PlayerPreso[i][1], 0);
    PlayerTextDrawSetOutline(i, PlayerPreso[i][1], 0);
    PlayerTextDrawBackgroundColor(i, PlayerPreso[i][1], 0);
    PlayerTextDrawFont(i, PlayerPreso[i][1], 5);
    PlayerTextDrawSetProportional(i, PlayerPreso[i][1], 0);
    PlayerTextDrawSetShadow(i, PlayerPreso[i][1], 0);
    PlayerTextDrawSetPreviewModel(i, PlayerPreso[i][1], 19053);
    PlayerTextDrawSetPreviewRot(i, PlayerPreso[i][1], 0.000000, 0.000000, 0.000000, 1.000000);

    PlayerPreso[i][2] = CreatePlayerTextDraw(i, 97.899589, 313.362457, "");
    PlayerTextDrawLetterSize(i, PlayerPreso[i][2], 0.181997, 1.694576);
    PlayerTextDrawAlignment(i, PlayerPreso[i][2], 2);
    PlayerTextDrawColor(i, PlayerPreso[i][2], -1);
    PlayerTextDrawSetShadow(i, PlayerPreso[i][2], 0);
    PlayerTextDrawSetOutline(i, PlayerPreso[i][2], -1);
    PlayerTextDrawBackgroundColor(i, PlayerPreso[i][2], 255);
    PlayerTextDrawFont(i, PlayerPreso[i][2], 2);
    PlayerTextDrawSetProportional(i, PlayerPreso[i][2], 1);
    PlayerTextDrawSetShadow(i, PlayerPreso[i][2], 0);
    }

    ZerandoVariaveis(playerid);
    PlayAudioStreamForPlayer(playerid, "http://listen.shoutcast.com:80/RadioHunter-TheHitzChannel");
    format(String, sizeof(String), "Efetuando_Login_%d", playerid);
    SetPlayerName(playerid, String);
    SelectTextDraw(playerid, Verde);
    CarregarLogin(playerid);
    CarregarPickups();

    //Timers
    SetTimerEx("limparchat", segundos(4), false, "i", playerid);
    SetTimerEx("AtualizarTagBubble", segundos(1), true, "i", playerid);
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
    SalvarContas(playerid);
    ZerandoVariaveis(playerid);
    DeletarSair(playerid);
    KillTimer(UPRelogio[playerid]);
    TextDrawHideForPlayer(playerid, txtTimeDisp);
    TextDrawHideForPlayer(playerid, txtDateDisp);
	return 1;
}

public OnPlayerSpawn(playerid)
{
    QuebrarLogin(playerid), QuebrarRegistro(playerid);
    Statusmostrar(playerid), CancelSelectTextDraw(playerid);
    StopAudioStreamForPlayer(playerid);
    TextDrawShowForPlayer(playerid, txtTimeDisp);
    TextDrawShowForPlayer(playerid, txtDateDisp);
    return 1;
}

public OnPlayerDeath(playerid, killerid, reason)
{
    SendDeathMessage(killerid, playerid, reason);

    if(IsPlayerInLs(playerid)){
        SetSpawnInfo(playerid, 0, PlayerInfo[playerid][Skin], 1175.1531,-1312.8925,13.9880,266.1378,0,0,0,0,0,0);
        ClearAnimations(playerid);
        SetPlayerSpecialAction(playerid,SPECIAL_ACTION_NONE);
    } else if(IsPlayerInLv(playerid)){
        SetSpawnInfo(playerid, 0, PlayerInfo[playerid][Skin], 1607.0583,1821.1628,10.8280,356.5667,0,0,0,0,0,0);
        ClearAnimations(playerid);
        SetPlayerSpecialAction(playerid,SPECIAL_ACTION_NONE);
    } else if(IsPlayerInFc(playerid)){
        SetSpawnInfo(playerid, 0, PlayerInfo[playerid][Skin], -316.3103,1053.5731,20.2879,1.6997,0,0,0,0,0,0);
        ClearAnimations(playerid);
        SetPlayerSpecialAction(playerid,SPECIAL_ACTION_NONE);
    } else if(IsPlayerInSf(playerid)){
        SetSpawnInfo(playerid, 0, PlayerInfo[playerid][Skin], -2652.3159,636.1181,14.4531,179.9128,0,0,0,0,0,0);
        ClearAnimations(playerid);
    } else if(IsPlayerInMc(playerid)){
        SetSpawnInfo(playerid, 0, PlayerInfo[playerid][Skin], -2202.3843,-2292.3999,30.6250,321.0372,0,0,0,0,0,0);
        ClearAnimations(playerid);
        SetPlayerSpecialAction(playerid,SPECIAL_ACTION_NONE);
    }

    PlayerInfo[playerid][Morreu]++;
    PlayerInfo[killerid][Matou]++;
	return 1;
}

public OnVehicleSpawn(vehicleid)
{
	return 1;
}

public OnVehicleDeath(vehicleid, killerid)
{
	return 1;
}

public OnPlayerText(playerid, text[])
{
    //Ofensa ao Servidor
    if(PlayerInfo[playerid][Logado] == true) {
    if(strfind(text, "server lixo", true) != -1 || strfind(text, "sv lixo", true) != -1 || strfind(text, "serve bosta", true) != -1 || strfind(text, "sv lixu", true) != -1 || strfind(text, "serve fdp", true) != -1 || strfind(text, "serve lixo", true) != -1 || strfind(text, "cervi lixo", true) != -1
    || strfind(text, "server coco", true) != -1 ||strfind(text, "adm fdp", true) != -1 || strfind(text, "staff lixo", true) != -1 || strfind(text, "adm viado", true) != -1 || strfind(text, "adm troxa", true) != -1 || strfind(text, "admins viados", true) != -1 || strfind(text, "adm troxa", true) != -1
    || strfind(text, "serve troxa", true) != -1 ||strfind(text, "adm lixo", true) != -1 || strfind(text, "server lix", true) != -1 || strfind(text, "çervi lixo", true) != -1 || strfind(text, "serv lixo", true) != -1  || strfind(text, "Derrubar o server", true) != -1  || strfind(text, "VB lixo", true) != -1  || strfind(text, "la lixo", true) != -1  || strfind(text, "quer ser adm ", true) != -1  || strfind(text, "meu server", true) != -1) {
    SendClientMessage(playerid, Erro, "| ERRO | Se continuar vai ser punido com ban!");
    AvisoBAN[playerid]++;
    if(AvisoBAN[playerid] == 3){
    format(String, sizeof(String), "| VB-Admin | [V.B]Guardiao baniu o(a) jogador(a) %s ( Motivo: Ofensa ao Servidor )" , PlayerName(playerid));
	SendClientMessageToAll(Vermelho, String);
    SendClientMessage(playerid, Branco, "| BANIDO | Você foi banido(a) pelo motivo ' Ofensa ao Servidor '");
	SendClientMessage(playerid, Branco, "| BANIDO | Se você acha que foi banido injustamente, tire um Print (F8) desse Ban");
	SendClientMessage(playerid, Branco, "| BANIDO | Entre em nosso fórum:www.LosCrakudos.forumeiros.com!!! E crie um Tópico em 'Banidos'.");
	SendClientMessage(playerid, Branco, "| BANIDO | E aguarde a Administração analizar seu caso!");
    GameTextForPlayer(playerid,"~r~banido~w~!", 2500, 3);
    Kick(playerid);
    }
    return 0;
    }
    }

    //Ofensa
    if(PlayerInfo[playerid][Logado] == true) {
    if(strfind(text, "Guardiao Fdp", true) != -1 || strfind(text, "Bot Fdp", true) != -1 || strfind(text, "bot bosta", true) != -1 || strfind(text, "guardião otr", true) != -1 || strfind(text, "guardião lixo", true) != -1 || strfind(text, "guardiao tnc", true) != -1 || strfind(text, "guardião lixu", true) != -1
    || strfind(text, "Bot Lixo", true) != -1 ||strfind(text, "adm fdp", true) != -1 || strfind(text, "guardiao bost", true) != -1 || strfind(text, "guardiao pnc", true) != -1 || strfind(text, "guardião troxa", true) != -1 || strfind(text, "vai tomar no cu guardiao", true) != -1 || strfind(text, "guardião lx", true) != -1
    || strfind(text, "Bot Troxa", true) != -1 ||strfind(text, "Tnc Bot", true) != -1 || strfind(text, "guardiao lixo", true) != -1 || strfind(text, "guardião pnc", true) != -1 || strfind(text, "guardião otario", true) != -1) {
    SendClientMessage(playerid, Erro, "| ERRO | Se continuar vai ser punido com ban!");
    AvisoBAN[playerid]++;
    if(AvisoBAN[playerid] == 3){
    format(String, sizeof(String), "| VB-Admin | [V.B]Guardiao baniu o(a) jogador(a) %s ( Motivo: Ofensa )" ,PlayerName(playerid));
	SendClientMessageToAll(Vermelho, String);
    SendClientMessage(playerid, Branco, "| BANIDO | Você foi banido(a) pelo motivo ' Ofensa '");
	SendClientMessage(playerid, Branco, "| BANIDO | Se você acha que foi banido injustamente, tire um Print (F8) desse Ban");
	SendClientMessage(playerid, Branco, "| BANIDO | Entre em nosso fórum:www.LosCrakudos.forumeiros.com!!! E crie um Tópico em 'Banidos'.");
	SendClientMessage(playerid, Branco, "| BANIDO | E aguarde a Administração analizar seu caso!");
    GameTextForPlayer(playerid,"~r~banido~w~!", 2500, 3);
    Kick(playerid);
    }
    return 0;
    }
    }

    //DIVULGAÇÃO DE SITE OU EMAIL
    if(PlayerInfo[playerid][Logado] == true) {
    if(strfind(text, ".com.br", true) != -1 || strfind(text, ".com", true) != -1 || strfind(text, ".net", true) != -1 || strfind(text, ".org.br", true) != -1 || strfind(text, ".org", true) != -1 || strfind(text, ".tk", true) != -1
    || strfind(text, "@hotmail", true) != -1 ||strfind(text, "@gmail", true) != -1 || strfind(text, "@outlook", true) != -1 || strfind(text, ".net.br", true) != -1 || strfind(text, "youtube.com", true) != -1 || strfind(text, "loskatchorros", true) != -1 || strfind(text, "@boV.Bom.br", true) != -1
    || strfind(text, ".tv.br", true) != -1 ||strfind(text, ".blogspot.com", true) != -1 || strfind(text, ".art.br", true) != -1 || strfind(text, ".br", true) != -1) {
    SendClientMessage(playerid, Erro, "| ERRO | Se continuar vai ser punido com ban!");
    AvisoBAN[playerid]++;
    if(AvisoBAN[playerid] == 3){
    format(String, sizeof(String), "| VB-Admin | [V.B]Guardiao kickou o(a) jogador(a) %s ( Motivo: Divulgação )" ,PlayerName(playerid));
	SendClientMessageToAll(Vermelho, String);
    SendClientMessage(playerid, Branco, "| KICK | Você foi kickado por tentar divulgar!");
    SendClientMessage(playerid, Branco, "| KICK | Se voltar a divulgar será banido permanente!");
    GameTextForPlayer(playerid,"~r~kickado~w~!", 2500, 3);
    Kick(playerid);
    }
    return 0;
    }
    }

    //Divulgação de IP
    if(PlayerInfo[playerid][Logado] == true) {
    if(strfind(text, ":7720", true) != -1 || strfind(text, ":7-7-7-7", true) != -1 || strfind(text, ":7772", true) != -1 || strfind(text, ":7773", true) != -1 ||  strfind(text, ":7780", true) != -1 || strfind(text, ":7784", true) != -1 || strfind(text, ":7788", true) != -1 || strfind(text, ":7782", true) != -1 || strfind(text, ":8686", true) != -1
    || strfind(text, ":7787", true) != -1 ||strfind(text, ":7080", true) != -1 || strfind(text, "7777", true) != -1 || strfind(text, ":2222", true) != -1 || strfind(text, ":7998", true) != -1) {
    SendClientMessage(playerid, Erro, "| ERRO | Se continuar vai ser punido com ban!");
    AvisoBAN[playerid]++;
    if(AvisoBAN[playerid] == 3){
    format(String, sizeof(String), "| VB-Admin | [V.B]Guardiao baniu o(a) jogador(a) %s ( Motivo: Divugação de IP )" ,PlayerName(playerid));
	SendClientMessageToAll(Vermelho, String);
    Kick(playerid);
    }
    return 0;
    }
    }

    if(PlayerInfo[playerid][Afk] == true) {
    SendClientMessage(playerid, Erro, "| ERRO | Antes de falar, digite: /Sairafk");
    return false;
    }

    if(PlayerInfo[playerid][Logado] == false) {
    SendClientMessage(playerid, Erro, "| ERRO | Você não está logado!");
    return false;
    }

    if(PlayerInfo[playerid][Preso] >= 1) {
    SendClientMessage(playerid, Erro, "| ERRO | Você está preso e não pode falar!");
    return false;
    }

    if(PlayerInfo[playerid][Vip] == 1 && PlayerInfo[playerid][CorVIP]== 0) {
    format(String, sizeof(String), "%s {FFFFFF}[{FFFFFF}VIP{FFFFFF}][%d]: %s", PlayerName(playerid), playerid, text);
    ProxDetector(30.0, playerid, String, GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid));
    return false;
	}
    if(PlayerInfo[playerid][Vip] == 1 && PlayerInfo[playerid][CorVIP]== 1) {
    format(String, sizeof(String), "%s {FFFFFF}[{FF0000}VIP{FFFFFF}][%d]: %s", PlayerName(playerid), playerid, text);
    ProxDetector(30.0, playerid, String, GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid));
    return false;
	}
    if(PlayerInfo[playerid][Vip] == 1 && PlayerInfo[playerid][CorVIP]== 2) {
    format(String, sizeof(String), "%s {FFFFFF}[{00FF00}VIP{FFFFFF}][%d]: %s", PlayerName(playerid), playerid, text);
    ProxDetector(30.0, playerid, String, GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid));
    return false;
	}
    if(PlayerInfo[playerid][Vip] == 1 && PlayerInfo[playerid][CorVIP]== 3) {
    format(String, sizeof(String), "%s {FFFFFF}[{0000FF}VIP{FFFFFF}][%d]: %s", PlayerName(playerid), playerid, text);
    ProxDetector(30.0, playerid, String, GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid));
    return false;
	}
    if(PlayerInfo[playerid][Vip] == 1 && PlayerInfo[playerid][CorVIP]== 4) {
    format(String, sizeof(String), "%s {FFFFFF}[{FFFF00}VIP{FFFFFF}][%d]: %s", PlayerName(playerid), playerid, text);
    ProxDetector(30.0, playerid, String, GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid));
    return false;
	}
    if(PlayerInfo[playerid][Vip] == 1 && PlayerInfo[playerid][CorVIP]== 5) {
    format(String, sizeof(String), "%s {FFFFFF}[{FF00FF}VIP{FFFFFF}][%d]: %s", PlayerName(playerid), playerid, text);
    ProxDetector(30.0, playerid, String, GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid));
    return false;
	}
    if(PlayerInfo[playerid][Vip] == 1 && PlayerInfo[playerid][CorVIP]== 6) {
    format(String, sizeof(String), "%s {FFFFFF}[{00FFFF}VIP{FFFFFF}][%d]: %s", PlayerName(playerid), playerid, text);
    ProxDetector(30.0, playerid, String, GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid));
    return false;
	}
    if(PlayerInfo[playerid][Vip] == 1 && PlayerInfo[playerid][CorVIP]== 7) {
    format(String, sizeof(String), "%s {FFFFFF}[{FF00FF}VIP{FFFFFF}][%d]: %s", PlayerName(playerid), playerid, text);
    ProxDetector(30.0, playerid, String, GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid));
    return false;
	}
    if(PlayerInfo[playerid][Admin] == 5){
    format(String, sizeof(String), "%s {FFFFFF}[{328E0A}Staff{FFFFFF}][%d]: %s", PlayerName(playerid), playerid, text);
    ProxDetector(30.0, playerid, String, GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid));
    return false;
    }
    if(PlayerInfo[playerid][Admin] == 4){
    format(String, sizeof(String), "%s {FFFFFF}[{FF0000}Sub-Staff{FFFFFF}][%d]: %s", PlayerName(playerid), playerid, text);
    ProxDetector(30.0, playerid, String, GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid));
    return false;
    }
    if(PlayerInfo[playerid][Admin] == 3){
    format(String, sizeof(String), "%s {FFFFFF}[{008bce}Admininstrador(a){FFFFFF}][%d]: %s", PlayerName(playerid), playerid, text);
    ProxDetector(30.0, playerid, String, GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid));
    return false;
    }
    if(PlayerInfo[playerid][Admin] == 2){
    format(String, sizeof(String), "%s {FFFFFF}[{FF8C00}Moderador(a){FFFFFF}][%d]: %s", PlayerName(playerid), playerid, text);
    ProxDetector(30.0, playerid, String, GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid));
    return false;
    }
    if(PlayerInfo[playerid][Admin] == 1){
    format(String, sizeof(String), "%s {FFFFFF}[{FFFF00}Ajudante{FFFFFF}][%d]: %s", PlayerName(playerid), playerid, text);
    ProxDetector(30.0, playerid, String, GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid));
    return false;
    }
    if(Sem_Chat_Global==0){
    format(String, sizeof(String), "%s {FFFFFF}[%d]: %s", PlayerName(playerid), playerid, text);
    ProxDetector(30.0, playerid, String, GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid), GetPlayerColor(playerid));
    return false;
    }
    return 1;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
    new cmd[128], idx;
    cmd = strtok(cmdtext, idx);

    if(PlayerInfo[playerid][Logado] == false){
    SendClientMessage(playerid, Erro, "| ERRO | Você não está logado!");
    return 1;
    }

    if(PlayerInfo[playerid][Afk] == true){
    SendClientMessage(playerid, Erro, "| ERRO | Antes de usar comando, digite: /Sairafk");
    return 1;
    }

    if(PlayerInfo[playerid][Preso] >= 1){
    SendClientMessage(playerid, Erro, "| ERRO | Você está preso e não pode usar comando!");
    return 1;
    }

    if(Algemado[playerid] == true){
    SendClientMessage(playerid, Erro, "| ERRO | Você está algemado e não pode usar comando!");
    return 1;
    }

    //MessageFormat(i, adm, "| VB-Log | O(A) jogador(a) %s [%d] digitou o comando ( %s )", PlayerName(playerid), playerid, cmd);

    //CMDS ADMINS                                                               //NIVEL 1
    if(strcmp(cmd, "/arenarc", true)==0)
	{
        if(IsPlayerAjudante(playerid))
        {
            SetPlayerPos(playerid, -975.975708,1060.983032,1345.671875);
            SetPlayerInterior(playerid, 10);
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
    }
    if(strcmp(cmd, "/respawn", true)==0)
	{
        if(IsPlayerAjudante(playerid))
        {
            if(Respawnando==false)
            {
                TextDrawSetString(RespawnVeiculos, "~r~>> ~w~Respawn de veiculos nao usados em ~g~30 ~w~segundos... ~r~<<");
                TextDrawShowForAll(RespawnVeiculos);
                SetTimer("Respawn1", segundos(3), false);
                Respawnando=true;
            } else {
                SendClientMessage(playerid, Erro, "| ERRO | Veiculos não em uso já está sendo respawnados!");
            }
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
    }
    if(strcmp(cmd, "/aviso", true)==0)
	{
        if(IsPlayerAjudante(playerid))
        {
            tmp = strtok(cmdtext, idx);
            tmp2 = strrest(cmdtext, idx);

            if(!strlen(tmp) || !strlen(tmp2)){
            SendClientMessage(playerid, Erro, "| ERRO | Digite: /Aviso [ID do(a) Jogador(a)] [Motivo do Aviso]");
            return 1;
            }

            id = strval(tmp);

            if(PlayerInfo[id][Logado]==false){
            SendClientMessage(playerid, Vermelho, "| ERRO | O(A) Jogador(a) não conectado(a)");
            return 1;
            }

            PlayerInfo[id][Avisos]++;
            MessageFormatAll(Vermelho, "| VB-Admin | O(A) %s %s avisou o(a) jogador(a) %s ( %d/3 )( Motivo: %s )", CargoAdmin(playerid), PlayerName(playerid),  PlayerName(id), PlayerInfo[id][Avisos], tmp2);
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
    }
	if(strcmp(cmd, "/espiar", true) == 0)
	{
        if(IsPlayerAjudante(playerid))
        {
            tmp = strtok(cmdtext, idx);

        	if(!strlen(tmp)) {
         	SendClientMessage(playerid, Vermelho, "| ERRO | Digite: /espiar [ID do(a) Jogador(a)]");
          	return 1;
           	}

            id = strval(tmp);

            if(PlayerInfo[id][Logado]==false){
            SendClientMessage(playerid, Vermelho, "| ERRO | O(A) Jogador(a) não conectado(a)");
            return 1;
            }

        	TogglePlayerSpectating(playerid, true);
         	PlayerSpectatePlayer(playerid, id);
          	SetPlayerInterior(playerid, GetPlayerInterior(id));
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
	}
 	if(strcmp(cmd, "/pararespiar", true) == 0)
	{
        if(IsPlayerAjudante(playerid))
        {
            TogglePlayerSpectating(playerid, false);
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
	}
	if(strcmp(cmd, "/tapa", true)==0)
	{
        if(IsPlayerAjudante(playerid))
        {
            tmp = strtok(cmdtext, idx);

            if(!strlen(tmp)){
            SendClientMessage(playerid, Erro, "| ERRO | Digite: /Tapa [ID do(a) Jogador(a)]");
            return 1;
            }

            id = strval(tmp);

            if(PlayerInfo[id][Logado]==false){
            SendClientMessage(playerid, Vermelho, "| ERRO | O(A) Jogador(a) não conectado(a)");
            return 1;
            }

            SetPlayerInterior(id, GetPlayerInterior(id));
            GetPlayerPos(id, X, Y, Z);
            SetPlayerPos(id, X, Y, Z+50);
            MessageFormat(id, adm, "| VB-Admin | O(A) %s %s te deu um tapa!", CargoAdmin(playerid),PlayerName(playerid));
            MessageFormat(playerid, adm, "| VB-Admin | Você deu um tapa no jogador(a) %s ", PlayerName(id));
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
	}
    if(strcmp(cmd, "/kick", true) == 0)
	{
        if(IsPlayerAjudante(playerid))
        {
            tmp = strtok(cmdtext, idx);
            tmp2 = strrest(cmdtext, idx);

            if(!strlen(tmp) || !strlen(tmp2)){
            SendClientMessage(playerid, Erro, "| ERRO | Digite: /Kick [ID do(a) Jogador(a)] [Motivo do Kick]");
            return 1;
            }

            id = strval(tmp);

            if(PlayerInfo[id][Logado]==false){
            SendClientMessage(playerid, Vermelho, "| ERRO | O(A) Jogador(a) não conectado(a)");
            return 1;
            }

            MessageFormatAll(Vermelho, "| VB-Admin | O(A) %s %s kickou o(a) jogador(a) %s ( Motivo: %s )", CargoAdmin(playerid), PlayerName(playerid), PlayerName(id), tmp2);
            MessageFormat(playerid, Vermelho, "| INFO | Você kickou o(a) Jogador(a) %s", PlayerName(id));
            GameTextForPlayer(id,"~r~kickado~w~!", 2500, 3);
    	    Kick(id);
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
    }
    if(strcmp(cmd, "/setcolete", true)==0)
    {
        if(IsPlayerAjudante(playerid))
        {
            tmp = strtok(cmdtext, idx);

            if(!strlen(tmp)){
            SendClientMessage(playerid, Erro, "| ERRO | Digite: /Setcolete [ID do(a) Jogador(a)]");
            return 1;
            }

            id = strval(tmp);

            if(PlayerInfo[id][Logado]==false){
            SendClientMessage(playerid, Vermelho, "| ERRO | O(A) Jogador(a) não conectado(a)");
            return 1;
            }

            SetPlayerArmour(id, 100);
            MessageFormat(id, adm, "| VB-Admin | O(A) %s %s[%d] encheu seu colete", CargoAdmin(playerid), PlayerName(playerid), playerid);
            MessageFormat(playerid, adm, "| VB-Admin | Você encheu o colete do(a) jogador(a) %s[%d]", PlayerName(id), id);
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
    }
    if(strcmp(cmd, "/setvida", true)==0)
    {
        if(IsPlayerAjudante(playerid))
        {
            tmp = strtok(cmdtext, idx);

            if(!strlen(tmp)){
            SendClientMessage(playerid, Erro, "| ERRO | Digite: /Setvida [ID do(a) Jogador(a)]");
            return 1;
            }

            id = strval(tmp);

            if(PlayerInfo[id][Logado]==false){
            SendClientMessage(playerid, Vermelho, "| ERRO | O(A) Jogador(a) não conectado(a)");
            return 1;
            }

            SetPlayerHealth(id, 100);
            MessageFormat(id, adm, "| VB-Admin | O(A) %s %s[%d] encheu sua vida", CargoAdmin(playerid), PlayerName(playerid), playerid);
            MessageFormat(playerid, adm, "| VB-Admin | Você encheu a vida do(a) jogador(a) %s[%d]", PlayerName(id), id);
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
    }
    if(strcmp(cmd, "/ir", true)==0)
    {
        if(IsPlayerAjudante(playerid))
        {
            tmp = strtok(cmdtext, idx);

            if(!strlen(tmp)){
            SendClientMessage(playerid, Erro, "| ERRO | Digite: /Ir [ID do(a) Jogador(a)]");
            return 1;
            }

            id = strval(tmp);

            if(PlayerInfo[id][Logado]==false){
            SendClientMessage(playerid, Vermelho, "| ERRO | O(A) Jogador(a) não conectado(a)");
            return 1;
            }

            GetPlayerPos(id, X, Y, Z);
            SetPlayerPos(playerid, X, Y, Z);
            SetPlayerInterior(playerid, GetPlayerInterior(id));
            MessageFormat(id, adm, "| VB-Admin | O(A) %s %s[%d] veio até sua posição", CargoAdmin(playerid), PlayerName(playerid), playerid);
            MessageFormat(playerid, adm, "| VB-Admin | Você foi até a posição do jogador(a) %s[%d]", PlayerName(id), id);
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
    }
    if(strcmp(cmd, "/trazer", true)==0)
    {
        if(IsPlayerAjudante(playerid))
        {
            tmp = strtok(cmdtext, idx);

            if(!strlen(tmp)){
            SendClientMessage(playerid, Erro, "| ERRO | Digite: /Trazer [ID do(a) Jogador(a)]");
            return 1;
            }

            id = strval(tmp);

            if(PlayerInfo[id][Logado]==false){
            SendClientMessage(playerid, Vermelho, "| ERRO | O(A) Jogador(a) não conectado(a)");
            return 1;
            }

            GetPlayerPos(playerid, X, Y, Z);
            SetPlayerPos(id, X, Y, Z);
            SetPlayerInterior(id, GetPlayerInterior(playerid));
            MessageFormat(id, adm, "| VB-Admin | O(A) %s %s[%d] puxou você", CargoAdmin(playerid), PlayerName(playerid), playerid);
            MessageFormat(playerid, adm, "| VB-Admin | Você puxou jogador(a) %s[%d]", PlayerName(id), id);
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
    }
    if(strcmp(cmd,"/cadeia", true)==0)
    {
        if(IsPlayerAjudante(playerid))
        {
            tmp = strtok(cmdtext, idx);
            tmp2 = strtok(cmdtext, idx);
            tmp3 = strrest(cmdtext, idx);

            if(!strlen(tmp) || !strlen(tmp2) || !strlen(tmp3)){
            SendClientMessage(playerid, Erro, "| ERRO | Digite: /Cadedia [ID do(a) Jogador(a)][Tempo da Cadeia][Motivo da Cadeia]");
            return 1;
            }

            id = strval(tmp);
            new tempo = strval(tmp2);

            if(PlayerInfo[id][Logado]==false){
            SendClientMessage(playerid, Vermelho, "| ERRO | O(A) Jogador(a) não conectado(a)");
            return 1;
            }

            if(tempo > 1000){
            SendClientMessage(playerid, Erro, "| ERRO | Tempo só permitido abaixo de 1000!");
            return 1;
            }

            ResetPlayerWeapons(id);
            KillTimer(UPRelogio[playerid]);
            SetPlayerInterior(id, 10);
            SetPlayerHealth(id, 99999);
            SetPlayerPos(id, 223.5335,110.3779,999.0156);
            PlayerInfo[id][Preso]=tempo*60;
            format(PlayerInfo[id][MotivoPrisao], 128, tmp3);
            PlayerTextDrawShow(id, PlayerPreso[id][1]);
            PlayerTextDrawShow(id, PlayerPreso[id][0]);
            MessageFormatAll(adm, "| VB-Admin | O(A) %s %s prendeu o(a) jogador(a) %s por %d minutos ( Motivo: %s )", CargoAdmin(playerid), PlayerName(playerid), PlayerName(id), tempo, tmp3);
            GameTextForPlayer( id, "~w~~h~PRESO!", 3000, 0);
            SendClientMessage(id, 0x2894FFAA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Preso ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            SendClientMessage(id, Branco, "» Você está preso!");
            MessageFormat(id, Branco, "» Foi preso por ( %s )", PlayerName(playerid));
            MessageFormat(id, Branco, "» Motivo da prisão ( %s )", tmp3);
            SendClientMessage(id, 0x2894FFAA, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Preso ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            SistemaPresidio(id);
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
    }
	if(strcmp(cmd, "/soltar", true)==0)
	{
        if(IsPlayerAjudante(playerid))
        {
            tmp = strtok(cmdtext, idx);

            if(!strlen(tmp)) return SendClientMessage(playerid, Vermelho, "| ERRO | Digite: /Soltar [ID do(a) Jogador(a)]") ;

            id = strval(tmp);

            if(PlayerInfo[id][Logado]==false){
            SendClientMessage(playerid, Vermelho, "| ERRO | O(A) Jogador(a) não conectado(a)");
            return 1;
            }

            if(PlayerInfo[id][Preso] == 0){
            MessageFormat(playerid, Vermelho, "| ERRO | O(A) Jogador(a) %s(ID:%d) não está preso(a)", PlayerName(id), id);
            return 1;
            }

            GameTextForPlayer(id, "~w~Solto!", 3000, 0 );
            SetPlayerInterior(id, 0);
            SetPlayerHealth(id, 100);
            SetPlayerPos(id, 1554.8657,-1675.6693,16.1953);
            PlayerInfo[id][Preso]=0;
            format(PlayerInfo[id][MotivoPrisao], 128, tmp3);
            PlayerTextDrawHide(id,PlayerPreso[id][2]);
            PlayerTextDrawHide(id,PlayerPreso[id][1]);
            PlayerTextDrawHide(id,PlayerPreso[id][0]);
            MessageFormat(playerid, adm, "| INFO | Você soltou o(a) jogador(a) %s[%d] da prisão", PlayerName(id), id);
            MessageFormat(id, adm, "| VB-Admin | O(A) %s %s[%d] soltou você da prisão!", CargoAdmin(playerid), PlayerName(playerid), playerid);
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
	}
    if(strcmp(cmd, "/cv", true)==0)
    {
        if(IsPlayerAjudante(playerid))
        {
            tmp = strtok(cmdtext, idx);
            tmp2 = strtok(cmdtext, idx);
            tmp3 = strtok(cmdtext, idx);

            if(!strlen(tmp) || !strlen(tmp2) || !strlen(tmp3)){
            SendClientMessage(playerid, Erro,"| ERRO | Digite: /Cv [ID do(a) Jogador(a)] [ID da Cor1] [ID da Cor2]");
            return 1;
            }

            id = strval(tmp);
            Cor1 = strval(tmp2);
            Cor2 = strval(tmp3);

            if(id < 400 || id > 611){
            SendClientMessage(playerid, Erro,"| ERRO | ID do Veiculo Inválido, Digite entre: 400 a 611");
            return 1;
            }

            if(Cor1 < 0 || Cor2 > 255){
            SendClientMessage(playerid, Erro,"| ERRO | ID da Cor Inválida, Digite entre: 0 a 255");
            return 1;
            }

            cVehicle[playerid] = true;
            GetPlayerFacingAngle(playerid, A);
            GetPlayerPos(playerid, X, Y, Z);
            CarroAdmin[playerid] = CreateVehicle(id,X-2,Y,Z,A,Cor2,Cor1,0);
            PutPlayerInVehicle(playerid,CarroAdmin[playerid],0);
            if(GetPlayerInterior(playerid))
            LinkVehicleToInterior(CarroAdmin[playerid],GetPlayerInterior(playerid));
            MessageFormat(playerid, adm, "| VB-Admin | Você criou o veículo {FFFFFF}'{0CB80C}%s{FFFFFF}' {13A9F6}ID {FFFFFF}'{0CB80C}%d{FFFFFF}' !", PlayerVehicle[GetVehicleModel(GetPlayerVehicleID(playerid))-400], id);
            SendClientMessage(playerid, Aviso, "| INFO | Ao sair do veículo ele será automaticamente deletado!");
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
    }
    if(strcmp(cmd,"/achat",true)==0)
    {
        if(IsPlayerAjudante(playerid))
        {
            strmid(tmp, cmdtext, 6, strlen(cmdtext));

            if(!strlen(tmp)){
            SendClientMessage(playerid,Erro, "| ERRO | Digite: /Achat [Texto]");
            return 1;
            }

            format(String, sizeof(String), "| Chat-Admin | %s [%d] diz: %s", PlayerName(playerid), playerid, tmp);
            ChatAdmin(0x800080AA, String);
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
	}
    if(strcmp(cmd,"/a",true)==0)
    {
        if(IsPlayerAjudante(playerid))
        {
            strmid(tmp,cmdtext,2,strlen(cmdtext));

            if(!strlen(tmp)){
            SendClientMessage(playerid,Erro, "| ERRO | Digite: /A [Texto]");
            return 1;
            }

            format(String, sizeof(String), "* %s %s: %s", CargoAdmin(playerid),PlayerName(playerid), tmp);
            SendClientMessageToAll(0x0099CCAA, String);
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
	}
    if(strcmp(cmd, "/cnn", true) == 0)
    {
        if(IsPlayerAjudante(playerid))
        {
            strmid(tmp,cmdtext,4,strlen(cmdtext));

            if(!strlen(tmp)){
            SendClientMessage(playerid, Erro, "| ERRO | Digite: /Cnn [Texto]");
            return 1;
            }

            format(String, sizeof(String), "~r~# ~p~%s~w~: %s ~r~#", PlayerName(playerid), tmp);
            TextDrawSetString(RespawnVeiculos, String);
            TextDrawShowForPlayer(playerid, RespawnVeiculos);
            SetTimerEx("TimerTextoTela", 1500, false, "d", playerid);
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
    }
    if(strcmp(cmd, "/ann", true) == 0)
    {
        if(IsPlayerAjudante(playerid))
        {
            strmid(tmp,cmdtext,4,strlen(cmdtext));

            if (!strlen(tmp)){
            SendClientMessage(playerid, Erro, "| ERRO | Digite: /Ann [Texto]");
            return 1;
            }

            format(String, sizeof(String), "~r~#~w~%s ~r~#", tmp);
            TextDrawSetString(RespawnVeiculos, String);
            TextDrawShowForPlayer(playerid, RespawnVeiculos);
            SetTimerEx("TimerTextoTela", 1500, false, "d", playerid);
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
    }
    if(strcmp(cmd, "/banir", true) == 0)                                        //NIVEL 2
	{
        if(IsPlayerModerador(playerid))
        {
            tmp = strtok(cmdtext, idx);
            tmp2 = strrest(cmdtext, idx);

            if(!strlen(tmp) || !strlen(tmp2)){
            SendClientMessage(playerid, Erro, "| ERRO | Digite: /Banir [ID/Nome do(a) Jogador(a)] [Motivo do Banimento]");
            return 1;
            }

            id = strval(tmp);

            //getdate(Ano, Mes, Dia);
    	    //gettime(Hora, Min, Seg);
            //GetPlayerIp(playerid, IPP, sizeof(IPP));

            MessageFormatAll(Vermelho, "| VB-Admin | O(A) %s %s baniu o(a) jogador(a) %s ( Motivo : %s )", CargoAdmin(playerid), PlayerName(playerid), PlayerName(id), tmp2);
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
    }
    if(strcmp(cmd,"/setarma", true)==0)                                         //NIVEL 3
    {
        if(IsPlayerAdmininstrador(playerid))
        {
            tmp = strtok(cmdtext, idx);
            tmp2 = strtok(cmdtext, idx);

            if(!strlen(tmp) || !strlen(tmp2)){
            SendClientMessage(playerid, Erro, "| ERRO | Digite: /Setarma [ID do(a) Jogador(a)] [ID da Arma]");
            return 1;
            }

            id = strval(tmp);
            new idarma = strval(tmp2);

            GivePlayerWeapon(id, idarma, 100000);
            SendClientMessage(playerid, adm, "| INFO |  Comando efetuado com sucesso!");
            MessageFormat(id, adm, "| VB-Admin | O(A) %s %s te deu a arma ID {FFFFFF}'{0CB80C}%d{FFFFFF}'", CargoAdmin(playerid),PlayerName(playerid),idarma);
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
	}
    if(strcmp(cmd,"/setdinheiro", true)==0)
    {
        if(IsPlayerAdmininstrador(playerid))
        {
            tmp = strtok(cmdtext, idx);
            tmp2 = strtok(cmdtext, idx);

            if(!strlen(tmp) || !strlen(tmp2)){
            SendClientMessage(playerid, Vermelho, "Digite: /SetDinheiro [ID do(a) Jogador(a)] [Quantidade de Dinheiro]");
            return 1;
            }

            id = strval(tmp);
            new grana = strval(tmp2);

            if(PlayerInfo[id][Logado]==false){
            SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não está conectado(a)");
            return  1;
            }

            MessageFormat(playerid, adm, "| VB-Admin | Você setou $%d para o jogador(a) %s[%d]", grana, PlayerName(id), id);
            MessageFormat(id, adm, "| VB-Admin | O(A) %s %s deu para você $%d", CargoAdmin(playerid), PlayerName(playerid), grana);
            GivePlayerMoney(id, grana);
            PlayerInfo[id][Dinheiro]=PlayerInfo[id][Dinheiro]+grana;
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
    }
    if(strcmp(cmd,"/removerdinheiro", true)==0)
    {
        if(IsPlayerAdmininstrador(playerid))
        {
            tmp = strtok(cmdtext, idx);
            tmp2 = strtok(cmdtext, idx);

            if(!strlen(tmp) || !strlen(tmp2)){
            SendClientMessage(playerid, Vermelho, "Digite: /Removerdinheiro [ID do(a) Jogador(a)] [Quantidade de Dinheiro]");
            return 1;
            }

            id = strval(tmp);
            new grana = strval(tmp2);

            if(PlayerInfo[id][Logado]==false){
            SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não está conectado(a)");
            return  1;
            }

            MessageFormat(playerid, adm, "| VB-Admin | Você removeu $%d do(a) jogador(a) %s[%d]", grana, PlayerName(id), id);
            MessageFormat(id, adm, "| VB-Admin | O(A) %s %s removeu de você $%d", CargoAdmin(playerid), PlayerName(playerid), grana);
            GivePlayerMoney(id, -grana);
            PlayerInfo[id][Dinheiro]=PlayerInfo[id][Dinheiro]-grana;
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
    }
	if(strcmp(cmd,"/setvip", true)==0)
    {
        if(IsPlayerAdmininstrador(playerid))
        {
            tmp = strtok(cmdtext, idx);
            tmp2 = strtok(cmdtext, idx);

            if(!strlen(tmp) || !strlen(tmp2)){
            SendClientMessage(playerid, Erro, "| ERRO | Digite: /Setvip [ID do(a) Jogador(a)] [Quantidade de Dia(s)]");
            return 1;
            }

            id = strval(tmp);
            Dia = strval(tmp2);

            if(Dia < 1 || Dia > 60){
            SendClientMessage(playerid, Erro, "| ERRO | Quantidade inválida!");
            return 1;
            }

            if(IsPlayerAjudante(id)){
            SendClientMessage(playerid, Erro, "| ERRO | Não é permetido membro da admininstração com VIP!");
            return 1;
            }

            if(PlayerInfo[id][Logado]==false){
            SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não está conectado(a)");
            return  1;
            }

            PlayerInfo[id][Vip]=1;
            ConverterDias(id, Dia);
            MessageFormat(playerid, adm, "| VB-Admin | Você deu %d dia(s) de VIP para o(a) jogador(a) %s[%d]", Dia, PlayerName(id), id);
            MessageFormat(id, adm, "| INFO | O(A) %s %s setou %d dia(s) de VIP para você!", CargoAdmin(playerid), PlayerName(playerid), Dia);
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
    }
    if(strcmp(cmd,"/removervip", true)==0)
    {
        if(IsPlayerAdmininstrador(playerid))
        {
            tmp = strtok(cmdtext, idx);
            tmp2 = strtok(cmdtext, idx);

            if(!strlen(tmp) || !strlen(tmp2)){
            SendClientMessage(playerid, Erro, "| ERRO | Digite: /Removervip [ID do(a) Jogador(a)] [Quantidade de Dia(s)]");
            return 1;
            }

            id = strval(tmp);
            Dia = strval(tmp2);

            if(IsPlayerAjudante(id)){
            SendClientMessage(playerid, Erro, "| ERRO | Não é permetido membro da admininstração com VIP!");
            return 1;
            }

            if(PlayerInfo[id][Logado]==false){
            SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não está conectado(a)");
            return  1;
            }

            ConverterDias(id, -Dia);
            PlayerInfo[id][Vip]=0;
            MessageFormat(playerid, adm, "| VB-Admin | Você removeu %d dia(s) de VIP do(a) jogador(a) %s[%d]", Dia, PlayerName(id), id);
            MessageFormat(id, adm, "| INFO | O(A) %s %s removeu %d dia(s) de VIP de você!", CargoAdmin(playerid), PlayerName(playerid), Dia);
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
    }
    if(strcmp(cmd, "/setskin", true)==0)
    {
        if(IsPlayerAdmininstrador(playerid))
        {
            tmp = strtok(cmdtext, idx);
            tmp2 = strtok(cmdtext, idx);

            if(!strlen(tmp) || !strlen(tmp2)){
            SendClientMessage(playerid, Erro, "| ERRO | Digite: /Setskin [ID do(a) Jogador(a)] [ID da Skin do(a) Jogador(a)]");
            return 1;
            }

            id = strval(tmp);
            new Idskin = strval(tmp2);

            if(PlayerInfo[id][Logado]==false){
            SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não está conectado(a)");
            return  1;
            }

            PlayerInfo[id][Skin]=Idskin;
            SetPlayerSkin(id, Idskin);
            MessageFormat(playerid, adm, "| VB-Admin | Você setou a skin {13A9F6}ID {FFFFFF}'{0CB80C}%d{FFFFFF}' {B0FF30}para o jogador(a) %s", Idskin, PlayerName(id));
            MessageFormat(id, adm, "| VB-Admin | O(A) %s %s lê setou a skin {13A9F6}ID {FFFFFF}'{0CB80C}%d{FFFFFF}'", CargoAdmin(playerid), PlayerName(playerid), Idskin);
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
    }
    if(strcmp(cmd,"/setlevel", true)==0)                                        //NIVEL 4
    {
        if(IsPlayerSub(playerid))
        {
            tmp = strtok(cmdtext, idx);
            tmp2 = strtok(cmdtext, idx);

            if(!strlen(tmp) || !strlen(tmp2)){
            SendClientMessage(playerid, Vermelho, "Digite: /Setlevel [ID do(a) Jogador(a)] [Level do(a) Jogador(a)]");
            return 1;
            }

            id = strval(tmp);
            new level = strval(tmp2);

            if(PlayerInfo[id][Logado]==false){
            SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não está conectado(a)");
            return  1;
            }

            MessageFormat(playerid, adm, "| VB-Admin | Você deu %d levels para o jogador(a) %s[%d]", level, PlayerName(id), id);
            MessageFormat(id, adm, "| VB-Admin | O(A) %s %s deu para você %d levels", CargoAdmin(playerid), PlayerName(playerid), level);
            SetPlayerScore(id, PlayerInfo[id][Level]+level);
            PlayerInfo[id][Level]=PlayerInfo[id][Level]+level;
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
    }
    if(strcmp(cmd,"/removerlevel", true)==0)
    {
        if(IsPlayerSub(playerid))
        {
            tmp = strtok(cmdtext, idx);
            tmp2 = strtok(cmdtext, idx);

            if(!strlen(tmp) || !strlen(tmp2)){
            SendClientMessage(playerid, Vermelho, "Digite: /Removerlevel [ID do(a) Jogador(a)] [Level do(a) Jogador(a)]");
            return 1;
            }

            id = strval(tmp);
            new level = strval(tmp2);

            if(PlayerInfo[id][Logado]==false){
            SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não está conectado(a)");
            return  1;
            }

            MessageFormat(playerid, adm, "| VB-Admin | Você removeu %d levels do(a) jogador(a) %s[%d]", level, PlayerName(id), id);
            MessageFormat(id, adm, "| VB-Admin | O(A) %s %s removeu de você %d levels", CargoAdmin(playerid), PlayerName(playerid), level);
            SetPlayerScore(id, PlayerInfo[id][Level]-level);
            PlayerInfo[id][Level]=PlayerInfo[id][Level]-level;
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
    }
    if(strcmp(cmd, "/reiniciar", true)==0)
	{
        if(IsPlayerSub(playerid))
        {
            SendClientMessageToAll(0xB9FFFFAA, "| INFO | O Server reiniciara em 2 minutos !");
            SetTimer("ReiniciandoServer", minutos(1), false);
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
    }
    if(strcmp(cmd, "/setadmin", true)==0)                                       //NIVEL 5
    {

        if(IsPlayerDesen(playerid) || IsPlayerAdmin(playerid))
        {
            tmp = strtok(cmdtext, idx);
            tmp2 = strtok(cmdtext, idx);

            if(!strlen(tmp) || !strlen(tmp2)){
            SendClientMessage(playerid, Erro, "| ERRO | Digite: /Setadmin [ID do(a) Jogador(a)] [Nivel]");
            return 1;
            }

            id = strval(tmp);
            new nivel = strval(tmp2);

            if(PlayerInfo[id][Logado]==false){
            SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não está conectado(a)");
            return  1;
            }

            if(nivel == 0){
            PlayerInfo[id][Admin]=nivel;
            MessageFormat(playerid, adm, "| VB-Admin | Você removeu o(a) jogador(a) %s[%d] da Admininstração!", PlayerName(id), id, CargoAdmin(id));
            MessageFormat(id, adm, "| VB-Admin | O(A) %s %s[%d] removeu você da Admininstração!", CargoAdmin(playerid), PlayerName(playerid), playerid, CargoAdmin(id));
            SetPlayerChatBubble(playerid, "", GetPlayerColor(playerid), 100.0, 100000);
            return 1;
            }

            if(nivel < PlayerInfo[id][Admin]){
            PlayerInfo[id][Admin]=nivel;
            MessageFormat(playerid, adm, "| VB-Admin | Você rebaixou o(a) jogador(a) %s[%d] para %s", PlayerName(id), id, CargoAdmin(id));
            MessageFormat(id, adm, "| VB-Admin | O(A) %s %s[%d] rebaixou você para %s", CargoAdmin(playerid), PlayerName(playerid), playerid, CargoAdmin(id));
            return 1;
            }

            if(nivel > PlayerInfo[id][Admin]){
            PlayerInfo[id][Admin]=nivel;
            MessageFormat(playerid, adm, "| VB-Admin | Você promoveu o(a) jogador(a) %s[%d] para %s", PlayerName(id), id, CargoAdmin(id));
            MessageFormat(id, adm, "| VB-Admin | O(A) %s %s[%d] promoveu você para %s", CargoAdmin(playerid), PlayerName(playerid), playerid, CargoAdmin(id));
            return 1;
            }
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
    }
    if(strcmp(cmd, "/apls", true)==0){//tp começa aqui
    if(PlayerInfo[playerid][Admin] < 1 || PlayerInfo[playerid][Admin] > 5)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,1962.2162,-2178.3967,13.5469);
    }
    if(strcmp(cmd, "/aplv", true)==0){
    if(PlayerInfo[playerid][Admin] < 1 || PlayerInfo[playerid][Admin] > 5)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,1712.0634,1606.1857,10.0156);
    }
    if(strcmp(cmd, "/apsf", true)==0){
    if(PlayerInfo[playerid][Admin] < 1 || PlayerInfo[playerid][Admin] > 5)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,-1740.7712,-579.3079,16.3359);
    }
    if(strcmp(cmd, "/apab", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,431.5682,2506.1760,16.4844);
    }
    if(strcmp(cmd, "/agls", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,1154.0808,-1771.9812,16.5992);
    }
    if(strcmp(cmd, "/aglv", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,937.8450,1733.1957,8.8516);
    }
    if(strcmp(cmd, "/agsf", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,-2171.8110,252.0813,35.3378);
    }
    if(strcmp(cmd, "/pfls", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,1481.0637,-1770.9515,18.7958);
    }
    if(strcmp(cmd, "/pflv", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,2447.0620,2376.2354,12.1635);
    }
    if(strcmp(cmd, "/pfsf", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,-2765.8796,375.5812,6.3347);
    }
    if(strcmp(cmd, "/dpls", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,1554.8657,-1675.6693,16.1953);
    }
    if(strcmp(cmd, "/dplv", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,2290.1218,2430.9775,10.8203);
    }
    if(strcmp(cmd, "/dpsf", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,-1605.5848,710.8436,13.8672);
    }
    if(strcmp(cmd, "/dpdm", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,627.7621,-571.7207,17.5526);
    }
    if(strcmp(cmd, "/hpls", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,1172.6787,-1323.3129,15.4022);
    }
    if(strcmp(cmd, "/hplv", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,1607.3579,1815.6309,10.8203);
    }
    if(strcmp(cmd, "/hpsf", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,-2655.0662,639.1497,14.4531);
    }
    if(strcmp(cmd, "/hpeq", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,-1514.8217,2520.3232,55.9185);
    }
    if(strcmp(cmd, "/hpmg", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,1241.8073,327.1022,19.7555);
    }
    if(strcmp(cmd, "/hpfc", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,-320.0716,1049.2637,20.3403);
    }
    if(strcmp(cmd, "/bcls", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,1778.3052,-1663.5337,14.4362);
    }
    if(strcmp(cmd, "/bclv", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,2388.6733,2466.0430,10.8203);
    }
    if(strcmp(cmd, "/bcsf", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,-2649.8374,376.0090,6.1563);
    }
    if(strcmp(cmd, "/bcfc", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,-180.3883,1133.1510,19.7422);
    }
    if(strcmp(cmd, "/bcmg", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,1372.9271,405.2487,19.9555);
    }
    if(strcmp(cmd, "/bcpc", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,2302.9521,-16.2789,26.4844);
    }
    if(strcmp(cmd, "/bclb", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,-828.0650,1503.6166,19.7585);
    }
    if(strcmp(cmd, "/bceq", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,-1480.8273,2592.3015,55.8359);
    }
    if(strcmp(cmd, "/bcbb", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,207.7767,-62.5814,1.6498);
    }
    if(strcmp(cmd, "/ibls", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,1798.4763,-1578.3191,14.0849);
    }
    if(strcmp(cmd, "/iblv", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,2413.2390,1123.8374,10.8203);
    }
    if(strcmp(cmd, "/ibsf", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,-1881.1293,822.7573,35.1773);
    }
    if(strcmp(cmd, "/aels", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,1519.0413,-1453.5895,14.2073);
    }
    if(strcmp(cmd, "/aelv", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,2183.2483,2295.2205,10.8203);
    }
    if(strcmp(cmd, "/aesf", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,-2026.5950,-101.3410,35.1641);
    }
    if(strcmp(cmd, "/dtls", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,1310.1411,-1367.8086,13.5408);
    }
    if(strcmp(cmd, "/dtlv", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,1173.1600,1349.0011,10.9219);
    }
    if(strcmp(cmd, "/dtsf", true)==0){
    if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
    return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
    return SetPlayerPos(playerid,-2720.6375,127.7373,7.0391);
    }
    if(strcmp(cmd, "/comandosadm", true)==0)
    {
        if(PlayerInfo[playerid][Admin]<=0 || PlayerInfo[playerid][Admin]>=6)
        return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");

        if(PlayerInfo[playerid][Admin]==1)
        {
            new textos[2800];
            strcat(textos, "{FF0000}•{FFFFFF} /ir                                                   \n");
            strcat(textos, "{FF0000}•{FFFFFF} /espiar                                               \n");
            strcat(textos, "{FF0000}•{FFFFFF} /pararespiar                                          \n");
            strcat(textos, "{FF0000}•{FFFFFF} /aviso                                                \n");
            strcat(textos, "{FF0000}•{FFFFFF} /kick                                                 \n");
            strcat(textos, "{FF0000}•{FFFFFF} /tapa                                                 \n");
    		strcat(textos, "{FF0000}•{FFFFFF} /trazer                                               \n");
    		strcat(textos, "{FF0000}•{FFFFFF} /cadeia                                               \n");
    		strcat(textos, "{FF0000}•{FFFFFF} /soltar                                               \n");
            strcat(textos, "{FF0000}•{FFFFFF} /setvida                                              \n");
            strcat(textos, "{FF0000}•{FFFFFF} /setcolete                                            \n");
            strcat(textos, "{FF0000}•{FFFFFF} /cv                                                   \n");
    		strcat(textos, "{FF0000}•{FFFFFF} /achat                                                \n");
      		strcat(textos, "{FF0000}•{FFFFFF} /a                                                    \n");
        	strcat(textos, "{FF0000}•{FFFFFF} /ann                                                  \n");
          	strcat(textos, "{FF0000}•{FFFFFF} /cnn                                                  \n");
            strcat(textos, "{FF0000}•{FFFFFF} /apls - aplv - apsf - /apab : Aeroportos              \n");
            strcat(textos, "{FF0000}•{FFFFFF} /agls - aglv - agsf : Agencia de Empregos             \n");
            strcat(textos, "{FF0000}•{FFFFFF} /pfls - pflv - pfsf : Prefeitura                      \n");
            strcat(textos, "{FF0000}•{FFFFFF} /dpls - dplv - dpsf - dpfm : Departamento de Polícia  \n");
            strcat(textos, "{FF0000}•{FFFFFF} /hpls - hplv - hpsf : Hospital                        \n");
            strcat(textos, "{FF0000}•{FFFFFF} /hpeq - hpmg - hpfc : Hospital                        \n");
            strcat(textos, "{FF0000}•{FFFFFF} /bcls - bclv - bcsf : Banco                           \n");
            strcat(textos, "{FF0000}•{FFFFFF} /bcfc - bcmg - bcpc : Banco                           \n");
            strcat(textos, "{FF0000}•{FFFFFF} /bclb - bceq - bcbb : Banco                           \n");
            strcat(textos, "{FF0000}•{FFFFFF} /ibls - iblv - ibsf : Imobilíaria                     \n");
            strcat(textos, "{FF0000}•{FFFFFF} /aels - aelv - aesf : Auto Escola                     \n");
            strcat(textos, "{FF0000}•{FFFFFF} /dtls - dtlv - dtsf : Detran                          \n");
    		ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Comandos da Admininstração", textos, "Fechar", "");
    		return 1;
        }
        if(PlayerInfo[playerid][Admin]==2)
        {
            new textos[2800];
            strcat(textos, "{FF0000}•{FFFFFF} /banir                                                \n");
    		ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Comandos da Admininstração", textos, "Fechar", "");
    		return 1;
        }
        if(PlayerInfo[playerid][Admin]==3)
        {
            new textos[2800];
            strcat(textos, "{FF0000}•{FFFFFF} /setarma                                              \n");
            strcat(textos, "{FF0000}•{FFFFFF} /setskin                                              \n");
            strcat(textos, "{FF0000}•{FFFFFF} /setdinheiro                                          \n");
            strcat(textos, "{FF0000}•{FFFFFF} /removerdinheiro                                         \n");
            strcat(textos, "{FF0000}•{FFFFFF} /setvip                                               \n");
            strcat(textos, "{FF0000}•{FFFFFF} /removervip                                           \n");
    		ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Comandos da Admininstração", textos, "Fechar", "");
    		return 1;
        }
        if(PlayerInfo[playerid][Admin]==4)
        {
            new textos[2800];
            strcat(textos, "{FF0000}•{FFFFFF} /reiniciar                                            \n");
            strcat(textos, "{FF0000}•{FFFFFF} /setlevel                                             \n");
            strcat(textos, "{FF0000}•{FFFFFF} /removerlevel                                         \n");
    		ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Comandos da Admininstração", textos, "Fechar", "");
    		return 1;
        }
        if(PlayerInfo[playerid][Admin]==5)
        {
            new textos[2800];
            strcat(textos, "{FF0000}•{FFFFFF} /setadmin                                             \n");
    		ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Comandos da Admininstração", textos, "Fechar", "");
    		return 1;
        }
    }

    //CMDS VIPS
    if(strcmp(cmd, "/tunar", true) == 0)
	{
        if(IsPlayerAjudante(playerid) || IsPlayerVip(playerid))
        {
            if(!(IsPlayerInAnyVehicle(playerid) == 1)){
            SendClientMessage(playerid, Erro, "| ERRO | Você não está em um carro!");
            return 1;
            }

            if(!(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)){
            SendClientMessage(playerid, Erro, "| ERRO | Você não está dirigindo!");
            return 1;
            }

            ShowPlayerDialog(playerid, menutunagem,DIALOG_STYLE_LIST,"{FF0000}Tunar","{FFFFFF}PaintJobs \nNitros \nRodas \nHidraulica","Concluir","Fechar");
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
    }
    if(strcmp(cmd, "/tag", true)==0)
    {
        if(IsPlayerAjudante(playerid) || IsPlayerVip(playerid))
        {
            new textos[1000];
            strcat(textos, "{FFFFFF}VIP \n{FF0000}VIP \n");
            strcat(textos, "{00FF00}VIP \n{0000FF}VIP \n");
            strcat(textos, "{FFFF00}VIP \n{FF00FF}VIP \n");
            strcat(textos, "{00FFFF}VIP \n{FF00FF}VIP \n");
            ShowPlayerDialog(playerid, TAGVIP, DIALOG_STYLE_LIST, "{FF0000}Tag VIP", textos, "Fechar", "");
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
    }
    if(strcmp(cmd, "/vencimento", true)==0)
    {
        if(IsPlayerAjudante(playerid) || IsPlayerVip(playerid))
        {
            new textos[50];
            format(String, sizeof(String), "{FFD700}Nick: {FFFFFF}%s\n\n", PlayerName(playerid));
            strcat(textos, String);
            format(String, sizeof(String), "{FFD700}Vencimento: {FFFFFF}%s \n\n", convertTimestamp(PlayerInfo[playerid][Vencimento], 1));
            strcat(textos, String);
            strcat(textos, "{FFD700} Aproveite o seu VIP até o ultimo segundo! \n");
            ShowPlayerDialog(playerid, 5000, DIALOG_STYLE_MSGBOX, "{FFD700}Vencimento", textos, "Fechar", "");
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
    }
	if(strcmp(cmd, "/reparar", true) == 0)
    {
        if(IsPlayerAjudante(playerid) || IsPlayerVip(playerid))
        {
            if(!(IsPlayerInAnyVehicle(playerid) == 1)){
            SendClientMessage(playerid, Erro, "| ERRO | Você não está em um carro!");
            return 1;
            }

            if(!(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)){
            SendClientMessage(playerid, Erro, "| ERRO | Você não está dirigindo!");
            return 1;
            }

            SendClientMessage(playerid, c_vip, "| VIP | Veículo reparado com sucesso");
            RepairVehicle(GetPlayerVehicleID(playerid));
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
    	return 1;
	}
    if (strcmp("/virar", cmdtext, true, 10) == 0)
    {
        if(IsPlayerAjudante(playerid) || IsPlayerVip(playerid))
        {
            if(!(IsPlayerInAnyVehicle(playerid) == 1)){
            SendClientMessage(playerid, Erro, "| ERRO | Você não está em um carro!");
            return 1;
            }

            if(!(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)){
            SendClientMessage(playerid, Erro, "| ERRO | Você não está dirigindo!");
            return 1;
            }

            GetPlayerPos(playerid, X, Y, Z);
            GetVehicleZAngle(GetPlayerVehicleID(playerid), A);
            SetVehiclePos(GetPlayerVehicleID(playerid), X, Y, Z);
            SetVehicleZAngle(GetPlayerVehicleID(playerid), A);
            SendClientMessage(playerid, c_vip, "| VIP | Veículo virado com sucesso");
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
	}
    if(strcmp( cmdtext, "/colete", true) == 0)
    {
        if(IsPlayerAjudante(playerid) || IsPlayerVip(playerid))
        {
            SetPlayerArmour(playerid, 100);
            SendClientMessage(playerid, c_vip, "| VIP | Colete criado com sucesso");
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
        }
        return 1;
    }
    if(strcmp(cmd,"/v",true)==0)
    {
        if(IsPlayerAjudante(playerid) || IsPlayerVip(playerid))
        {
            strmid(tmp, cmdtext, 2, strlen(cmdtext));

            if(!strlen(tmp)){
            SendClientMessage(playerid,Erro, "| ERRO | Digite: /V [Texto]");
            return 1;
            }

            format(String, sizeof(String), "| Chat-Vip | %s [%d] diz: %s", PlayerName(playerid), playerid, tmp);
            ChatVIP(c_vip, String);
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Você não tem permissão");
        }
        return 1;
	}
    if(strcmp(cmd, "/jetpack", true) == 0)
    {
        if(IsPlayerAjudante(playerid) || IsPlayerVip(playerid))
        {
            if(IsPlayerInAnyVehicle(playerid) == 1){
            SendClientMessage(playerid, Erro, "| ERRO | Você precisa sair do veiculo!");
            return 1;
            }

            SendClientMessage(playerid, c_vip ,"| VIP | Jetpack criado com sucesso");
            SetPlayerSpecialAction(playerid, 2);
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Você não tem permissão");
        }
        return 1;
    }
    if(strcmp(cmd, "/djetpack", true) == 0)
    {
        if(IsPlayerAjudante(playerid) || IsPlayerVip(playerid))
        {
            SendClientMessage(playerid, c_vip ,"| VIP | Jetpack criado com sucesso");
            ClearAnimations(playerid);
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Você não tem permissão");
        }
        return 1;
    }
    if(strcmp(cmd, "/pintar", true) == 0)
    {
        if(IsPlayerAjudante(playerid) || IsPlayerVip(playerid))
        {
            if(!(IsPlayerInAnyVehicle(playerid) == 1)){
            SendClientMessage(playerid, Erro, "| ERRO | Você não está em um carro!");
            return 1;
            }

            if(!(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)){
            SendClientMessage(playerid, Erro, "| ERRO | Você não está dirigindo!");
            return 1;
            }

            tmp = strtok(cmdtext, idx);
            tmp2 = strtok(cmdtext,idx);

            if(!strlen(tmp)){
            SendClientMessage(playerid, Vermelho, "| ERRO | Digite: /Pintar [Cor1] [Cor2]");
            return 1;
            }
            if(!strlen(tmp2)){
            SendClientMessage(playerid, Vermelho, "| ERRO | Digite: /Pintar [Cor1] [Cor2]");
            return 1;
            }

            Cor1 = strval(tmp);
            Cor2 = strval(tmp2);

            ChangeVehicleColor(GetPlayerVehicleID(playerid),Cor1,Cor2);
            format(String, sizeof(String), "| VIP | Veículo pintado com sucesso");
            SendClientMessage(playerid, c_vip, String);
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Você não tem permissão");
        }
        return 1;
	}
    //CMDS PROFISSÕES
    if(strcmp(cmd, "/cp", true)==0)
	{
        strmid(tmp, cmdtext, 3, strlen(cmdtext));

    	if(!strlen(tmp)) return SendClientMessage(playerid, Vermelho, "| ERRO | Digite: /Cp [texto]");

        for (new i; i < MAX_PLAYERS; i++)
        {
            if(PlayerInfo[i][Profissao] == PlayerInfo[playerid][Profissao])
            {
                format(String, sizeof(String), "| Chat-Profissão | %s [%d] diz: %s", PlayerName(playerid), playerid, tmp);
                SendClientMessage(i, GetPlayerColor(playerid), String);
            }
        }
        return 1;
	}
    if(strcmp(cmd, "/Hq", true)==0)
	{
        if(PlayerInfo[playerid][Profissao] == EntregadorJornal){                //Honesta
            SetPlayerCheckpoint(playerid, 785.2020,-1327.7697,13.5469, 1.0);
        } else if(PlayerInfo[playerid][Profissao] == Taxi){                     //Transportes
            SetPlayerCheckpoint(playerid, 2229.5803,-1368.1969,23.9922, 1.0);
        } else if(PlayerInfo[playerid][Profissao] == Policia_Civil){            //Policia
            SetPlayerCheckpoint(playerid, 1579.5728,-1635.3932,13.5611, 1.0);
        } else if(PlayerInfo[playerid][Profissao] == Ladrao_de_Gas){            //Mafia
            SetPlayerCheckpoint(playerid, -453.7872,2230.1296,42.4993, 1.0);
        }
     	return 1;
	}
    if(strcmp(cmd, "/Pegarjornal", true)==0)                                 //EntregadorJornal
    {
        if(PlayerInfo[playerid][Profissao] == EntregadorJornal)
        {
            for(new i; i < sizeof(BKJORNAL); i ++) if(GetPlayerVehicleID(playerid) == BKJORNAL[i])
            {
                if(IsPlayerInRangeOfPoint(playerid, 10.0, X, Y, Z))
                {

                } else {
                    SendClientMessage(playerid, Erro, "| ERRO | Você não está na sua HQ");
                }
            } else {
                SendClientMessage(playerid, Erro, "| ERRO | Você não está em uma Mountain Bike");
            }
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Você não pertence a essa profissão!");
        }
        return 1;
    }
    if(strcmp(cmd, "/Cancelarentrega", true)==0)
    {
        if(PlayerInfo[playerid][Profissao] == EntregadorJornal)
        {

        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Você não pertence a essa profissão!");
        }
        return 1;
    }                                                                           //POLICIA CIVIL
    if(strcmp(cmd, "/localizar", true)==0)
    {
        if(PlayerInfo[playerid][Profissao] == Policia_Civil)
        {
            tmp = strtok(cmdtext, idx);

            if(!strlen(tmp)){
            SendClientMessage(playerid, Erro, "| ERRO | Digite: /Localizar [ID do(a) Jogador(a)]");
            return 1;
            }

            id = strval(tmp);

            if(PlayerInfo[id][Logado]==false){
            SendClientMessage(playerid, Vermelho, "| ERRO | O(A) Jogador(a) não conectado(a)");
            return 1;
            }

            if(id==playerid){
            SendClientMessage(playerid, Vermelho, "| ERRO | Você não pode executar comando em você mesmo");
            return 1;
            }

            TimerProcurando[playerid] = SetTimerEx("GPSUpdate", 1500, true, "dd", playerid, id);
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Você não pertence a essa profissão!");
    	}
        return 1;
    }
    if(strcmp(cmd, "/uniforme", true) == 0)
	{
        if(PlayerInfo[playerid][Profissao] == Policia_Civil)
        {
            if(IsPlayerInRangeOfPoint(playerid, 1.0, 254.1715,74.3339,1003.6406))
            {
                SetPlayerSkin(playerid, 287);
            } else {
                SendClientMessage(playerid, Erro, "| ERRO | Você não está no local correto");
            }
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Você não pertence a essa profissão!");
    	}
        return 1;
    }
    if(strcmp(cmd, "/equipar", true) == 0)
	{
        if(PlayerInfo[playerid][Profissao] == Policia_Civil)
        {
            if(IsPlayerInRangeOfPoint(playerid, 1.0, 254.1715,74.3339,1003.6406))
            {
                GivePlayerWeapon(playerid, 31, 2000);
                GivePlayerWeapon(playerid, 28, 2000);
                GivePlayerWeapon(playerid, 24, 2000);
                SetPlayerArmour(playerid, 100);
            } else {
                SendClientMessage(playerid, Erro, "| ERRO | Você não está no local correto");
            }
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Você não pertence a essa profissão!");
    	}
        return 1;
    }
    if(strcmp(cmd, "/abordar", true) == 0)
	{
        if(PlayerInfo[playerid][Profissao] == Policia_Civil)
        {
            if(IsPlayerUniformePM(playerid))
            {
            	tmp = strtok(cmdtext, idx);

            	if(!strlen(tmp)){
                SendClientMessage(playerid, Erro, "| ERRO | Digite: /abordar [ID Procurado(a)]");
                return 1;
                }

                id = strval(tmp);

            	if(PlayerInfo[id][Logado]==false){
            	SendClientMessage(playerid, Erro, "| ERRO | Jogador(a) não está conectado(a)!");
                return 1;
                }

                if(playerid == id){
                SendClientMessage(playerid, Erro, "| ERRO | Você não pode abordar você mesmo!");
                return 1;
                }

            	if(GetDistanceBetweenPlayers(playerid, id) > 15){
            	SendClientMessage(playerid, Erro, "| ERRO | Você está muito longe, chegue mais perto!");
                return 1;
                }

                if(Abordado[id]==true){
                SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) já está abordado(a)!");
                return 1;
                }

                Abordado[id]=true;
            	GameTextForPlayer(id, "~b~Abordagem!", 3000, 0);
            	MessageFormat(id, 0x2894FFAA, " | ABORDAGEM | Você foi abordado pelo Policial %s", PlayerName(playerid));
            	MessageFormat(playerid, 0x2894FFAA, " | ABORDAGEM | Você abordou o(a) Jogador(a) %s", PlayerName(id));
            } else {
                SendClientMessage(playerid, Erro, "| ERRO | Você não está com o uniforme!");
        	}
    	} else {
            SendClientMessage(playerid, Erro, "| ERRO | Você não pertence a essa profissão!");
    	}
     	return 1;
	}
    if(strcmp(cmd, "/algemar", true) == 0)
	{
        if(PlayerInfo[playerid][Profissao] == Policia_Civil)
        {
            if(IsPlayerUniformePM(playerid))
            {
            	tmp = strtok(cmdtext, idx);

            	if(!strlen(tmp)){
                SendClientMessage(playerid, Erro, "| ERRO | Digite: /algemar [ID Procurado(a)]");
                return 1;
                }

                id = strval(tmp);

            	if(PlayerInfo[id][Logado]==false){
            	SendClientMessage(playerid, Erro, "| ERRO | Jogador(a) não está conectado(a)!");
                return 1;
                }

                if(playerid == id){
                SendClientMessage(playerid, Erro, "| ERRO | Você não pode algemar você mesmo!");
                return 1;
                }

            	if(GetDistanceBetweenPlayers(playerid, id) > 15){
            	SendClientMessage(playerid, Erro, "| ERRO | Você está muito longe, chegue mais perto!");
                return 1;
                }

                if(Abordado[id]==false){
                SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) não está abordado(a)!");
                return 1;
                }

                if(IsPlayerInAnyVehicle(id) == 1){
                SendClientMessage(playerid, Erro, "| ERRO | O(A) Jogador(a) está em um veiculo!");
                return 1;
                }

            	GameTextForPlayer(id, "~b~ALGEMADO!", 3000, 0);
            	MessageFormat(id, 0x2894FFAA, " | ALGEMADO | Você foi algemado pelo Policial %s ", PlayerName(playerid));
            	MessageFormat(playerid, 0x2894FFAA, " | ALGEMADO | Você algemou o(a) Jogador(a) %s ", PlayerName(id));
                SetPlayerAttachedObject(id,4,19418,6,-0.031999,0.024000,-0.024000,-7.900000,-32.000011,-72.299987,1.115998,1.322000,1.406000);
                SetPlayerSpecialAction(id, SPECIAL_ACTION_CUFFED);
                TogglePlayerControllable(id, false);
            	Algemado[id]=true;
                Abordado[id]=false;
            } else {
                SendClientMessage(playerid, Erro, "| ERRO | Você não está com o uniforme!");
        	}
    	} else {
            SendClientMessage(playerid, Erro, "| ERRO | Você não pertence a essa profissão!");
    	}
     	return 1;
	}
    if(strcmp(cmd, "/prender", true) == 0)
    {
        if(PlayerInfo[playerid][Profissao] == Policia_Civil)
        {
            if(IsPlayerUniformePM(playerid))
            {
                tmp = strtok(cmdtext, idx);

                if(!strlen(tmp)){
                SendClientMessage(playerid, Erro, "| ERRO | /Prender [ID]");
                return 1;
                }

                id = strval(tmp);

                if(PlayerInfo[id][Logado]==false){
                SendClientMessage(playerid, Erro, "| ERRO | Jogador(a) não está conectado(a)!");
                return 1;
                }

                if(Algemado[id] == false){
                SendClientMessage(playerid, Erro, "| ERRO | O(a) Jogador(a) precisa estar algemado para prender!");
                return 1;
                }

                if(GetDistanceBetweenPlayers(playerid, id) > 15){
                SendClientMessage(playerid, Erro, "| ERRO | Você está muito longe, chegue mais perto!");
                return 1;
                }

                if(playerid == id){
                SendClientMessage(playerid, Erro, "| ERRO | Você não pode prender você mesmo!");
                return 1;
                }

                /*if(IsPlayerInLs(playerid)){
                    Dplos[id] = 1;
                } else if(IsPlayerInLv(playerid)){
                    Dpventura[id] = 1;
                } else if(IsPlayerInFc(playerid)){
                    Dpford[id] = 1;
                } else if(IsPlayerInMc(playerid)){
                    Dpmc[id] = 1;
                } else if(IsPlayerInSf(playerid)){
                    Dpsan[id] = 1;
                }*/

                PlayerInfo[playerid][Dinheiro]=PlayerInfo[playerid][Dinheiro]+500;
                GivePlayerMoney(playerid, PlayerInfo[playerid][Dinheiro]);
                MessageFormat(id, 0x2894FFAA, "| INFO | Você foi preso pelo Policial %s ( Motivo: Procurado(a) )", PlayerName(playerid));
                MessageFormat(playerid, 0x2894FFAA, "| INFO | Você prendeu o(a) Jogador(a) %s ( Procurado(a) )", PlayerName(id));
                SendClientMessage(playerid, 0x2894FFAA, "| INFO | Você recebeu a recompensa de $500 por prender um jogador(a) que estava sendo procurado(a) pela policia.");
                format(String, sizeof(String),"| CORREGEDORIA | O Policial %s(ID: %d) Prendeu o(a) Jogador(a) %s(ID: %d) ( Motivo: Procurado(a) )", PlayerName(playerid), playerid, PlayerName(id), id);
                MSGCorregedoria(C_Corregedoria, String);
                GameTextForPlayer(id, "~w~PRESO!", 3000, 0);
                Algemado[id] = false;
                ResetPlayerWeapons(id);
                SetPlayerFacingAngle(id, 1.2072);
                SetPlayerPos(id, 264.2374,77.4612,1001.0391);
                SetPlayerInterior(id, 6);
                SetPlayerHealth(id, 99999);
                PlayerInfo[id][Preso]=5*60;
                TogglePlayerControllable(id, true);
                RemovePlayerAttachedObject(id, 4);
                SetPlayerSpecialAction(id, SPECIAL_ACTION_NONE);
                format(PlayerInfo[playerid][MotivoPrisao], 128, "Procurado(a)");
                SistemaPresidio(id);
            } else {
                SendClientMessage(playerid, Erro, "| ERRO | Você não está com o uniforme!");
        	}
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Você não pertence a essa profissão!");
        }
        return 1;
    }                                                                           //Ladrão de Gás
    if(strcmp(cmd, "/roubargas", true)==0)
    {
        if(PlayerInfo[playerid][Profissao] == Ladrao_de_Gas)
        {
            CreateObject(1370,-404.0782,2206.0208,42.4297,0.0,0.0,0.0);
            SendClientMessage(playerid, C_Ladrao_de_Gas, "| INFO | Foi marcado no mini-mapa o checkpoint para roubar o Bujão de Gás");
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Você não pertence a essa profissão!");
        }
        return 1;
    }
    if(strcmp(cmd, "/pegargas", true)==0)
    {
        if(PlayerInfo[playerid][Profissao] == Ladrao_de_Gas)
        {
            if(PegouGas[playerid]==false)
            {
                PegouGas[playerid]=true;
                RemoveBuildingForPlayer(playerid,1370,-404.0782,2206.0208,42.4297,0.0);
                SetPlayerAttachedObject(playerid,2,1370,5,0.1,0.07,0.039999,180.0,0.0,0.0,1.0,1.0,1.0);
            } else {
                SendClientMessage(playerid, Erro, "| ERRO | Você já está com um Bujão de Gás");
            }
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Você não pertence a essa profissão!");
        }
        return 1;
    }
    if(strcmp(cmd, "/colocargas", true)==0)
    {
        if(PlayerInfo[playerid][Profissao] == Ladrao_de_Gas)
        {
            if(PegouGas[playerid]==true)
            {
                RemovePlayerAttachedObject(playerid, 2);
                SetPlayerAttachedObject(playerid,2,1370,5,0.1,0.070000,0.039999,1.0,1.0,1.0,180.0,0.0,0.0);
                PegouGas[playerid]=false;
            } else {
                SendClientMessage(playerid, Erro, "| ERRO | Você não tem nenhum Bujão de Gás na mão");
            }
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Você não pertence a essa profissão!");
        }
        return 1;
    }
    if(strcmp(cmd, "/edit", true)==0)
    {
        EditAttachedObject(playerid, 2);
        return 1;
    }

    //CMDS GERAIS
    if(strcmp(cmd, "/radio", true)==0)
    {
        tmp = strrest(cmdtext, idx);
        if(!strlen(tmp)) return SendClientMessage(playerid, Erro, "| ERRO | Digite: /radio [Link.mp3]");
        PlayAudioStreamForPlayer(playerid, tmp);
        SendClientMessage(playerid, Branco, "| INFO | Para pausar digite: /radio stop ou espaço apenas!");
        return 1;
    }
    if(strcmp(cmd, "/radios", true)==0)
    {
        new texto[500];
        strcat(texto, "{FFFFFF}Rádio Jovem Pan \nRádio Hunter    \n");
        strcat(texto, "{FFFFFF}Rádio Massa FM  \nRádio Reggae141 \n");
        strcat(texto, "{FF0000}Desligar Radios ");
        ShowPlayerDialog(playerid, menuradio, DIALOG_STYLE_LIST, "{FF0000}MP3", texto, "Continuar", "Fechar");
        return 1;
    }
    if(strcmp(cmd, "/mudarnick", true)==0)
    {
        if(PlayerInfo[playerid][Coins] >= 7)
        {
            ShowPlayerDialog(playerid, mudarnick, DIALOG_STYLE_INPUT, "{FF0000}Mudar nick", "{FFFFFF}Digite seu novo nick :", "Continuar", "Fechar");
        } else {
            SendClientMessage(playerid, Erro, "| ERRO | Você não tem coins o suficiente para mudar o nick");
        }
        return 1;
    }
    if(strcmp(cmd, "/d", true)==0)
    {
        limparchat(playerid);
        return 1;
    }
    if(strcmp(cmd, "/meulevel", true)==0)
    {
        new textos[100];
        format(String, sizeof(String), "{FFFFFF} Nick: {FF0000}%s \n\n", PlayerName(playerid));
        strcat(textos, String);
        format(String, sizeof(String), "{FFFFFF} Level: {1b6302}%d \n\n", PlayerInfo[playerid][Level]);
        strcat(textos, String);
        format(String, sizeof(String), "{FFFFFF} Experiência: {f29b0d}%d \n\n", PlayerInfo[playerid][Exp]);
        strcat(textos, String);
        ShowPlayerDialog(playerid, menuajuda, DIALOG_STYLE_MSGBOX, "{0000FF}Meu Level", textos, "Fechar", "");
        return 1;
    }
    if(strcmp(cmd, "/ajuda", true)==0)
    {
        new textos[200];
        strcat(textos, "{FFFFFF} Level \n");
        strcat(textos, "{FFFFFF} Salário \n");
        strcat(textos, "{FFFFFF} Comandos \n");
        strcat(textos, "{FFFFFF} Contatos \n");
        strcat(textos, "{FFFFFF} Casa \n");
        strcat(textos, "{FFFFFF} Base \n");
        strcat(textos, "{FFFFFF} Empresa \n");
        strcat(textos, "{FFFFFF} Veículo \n");
        strcat(textos, "{FFFFFF} Loteria \n");
        strcat(textos, "{FFFFFF} Mercadoria \n");
        ShowPlayerDialog(playerid, menuajuda, DIALOG_STYLE_LIST, "{FF0000}Ajuda", textos, "Continuar", "Fechar");
        return 1;
    }
    if(strcmp(cmd, "/entrar", true)==0)
	{
        EntrarInterior(playerid);
        return 1;
    }
    if(strcmp(cmd, "/Sair", true) == 0)
	{
        SairInterior(playerid);
        return 1;
    }
    if(strcmp(cmd, "/profissao", true)==0)
    {
        if(PlayerInfo[playerid][Profissao]==Desempregado){
    	new string[1000];
        strcat(string, "{FFFFFF}Você está desempregado, para conseguir um vá até a Agencia de Empregos em uma das 3 cidades de san andreas \n\n");
        strcat(string, "{FFFFFF}Los Santos - Está localizado perto da praia de Santa Maria \n\n");
        strcat(string, "{FFFFFF}Las Venturas - Está localizado perto do Aero Porto \n\n");
        strcat(string, "{FFFFFF}San Fierro - Está localizado perto da Estação Ferroviária \n\n");
        strcat(string, "{FFFFFF}Todas as Agências de Empregos tem um simbolo de uma {1e90ff}Caveira Azul {FFFFFF}no Radar \n\n");
        ShowPlayerDialog(playerid, Desempregado, DIALOG_STYLE_MSGBOX, "{FF0000}Desempregado", string, "Fechar", "");
        } else if(PlayerInfo[playerid][Profissao]==EntregadorJornal){
    	new string[1000];
        strcat(string, "{80FF80}/Pegarjornal {FFFFFF}- Pegue 50 Jornais para entregar \n");
        strcat(string, "{80FF80}/Cancelarentrega {FFFFFF}- Cancele as entregas de jornais \n");
        strcat(string, "{80FF80}/Hq {FFFFFF}- Localize seu trabalho \n");
        strcat(string, "{80FF80}/Cp [texto]{FFFFFF}- Chat profissão \n");
        ShowPlayerDialog(playerid, EntregadorJornal, DIALOG_STYLE_MSGBOX, "{FF0000}Comandos Entregador Jornal", string, "Fechar", "");
        } else if(PlayerInfo[playerid][Profissao]==Taxi){
    	new string[1000];
        strcat(string, "{FFFF00}/Localizar [ID] {FFFFFF}- Localize o cliente \n");
        strcat(string, "{FFFF00}/Hq {FFFFFF}- Localize seu trabalho \n");
        strcat(string, "{FFFF00}/Cp [texto]{FFFFFF}- Chat profissão \n");
        ShowPlayerDialog(playerid, Taxi, DIALOG_STYLE_MSGBOX, "{FF0000}Comandos Taxi", string, "Fechar", "");
        } else if(PlayerInfo[playerid][Profissao]==Policia_Civil){
    	new string[1000];
        strcat(string, "{4AA5FF}/Prenderarmas [ID] {FFFFFF}- Para apreender as armas de um player \n");
        strcat(string, "{4AA5FF}/Localizar [ID] {FFFFFF}- Para localizar procurado \n");
        strcat(string, "{4AA5FF}/Algemar [ID] {FFFFFF}- Para algemar um player antes de prende-lo \n");
        strcat(string, "{4AA5FF}/Prender [ID] {FFFFFF}- Para coloca-lo na cadeia \n");
        strcat(string, "{4AA5FF}/Abordar [ID] {FFFFFF}- Para abordar um player procurado \n");
        strcat(string, "{4AA5FF}/Tapete {FFFFFF}- Para Criar um Tapete de Pregos \n");
        strcat(string, "{4AA5FF}/Hq {FFFFFF}- Localize seu trabalho \n");
        strcat(string, "{4AA5FF}/Cp [texto]{FFFFFF}- Chat Profissão \n");
        ShowPlayerDialog(playerid, Policia_Civil, DIALOG_STYLE_MSGBOX, "{FF0000}Comandos Policial Militar", string, "Fechar", "");
        } else if(PlayerInfo[playerid][Profissao]==Corregedoria){
    	new string[1000];
        strcat(string, "{8080C0}/Prender [ID] {FFFFFF}- Para coloca-lo na cadeia \n");
        strcat(string, "{8080C0}/Hq {FFFFFF}- Localize seu trabalho \n");
        strcat(string, "{8080C0}/Cp [texto]{FFFFFF}- Chat Profissão \n");
        ShowPlayerDialog(playerid, Corregedoria, DIALOG_STYLE_MSGBOX, "{FF0000}Comandos Policial Militar", string, "Fechar", "");
        }
        return 1;
	}
    if(strcmp(cmd, "/cargo", true)==0)
    {
        if(ProfissaoonMafia[playerid] == 0){
        SendClientMessage(playerid, Erro,"| ERRO | Você não foi encaminhado por nenhuma Area de Drogas!");
        return 1;
        }

        if(PlayerInfo[playerid][Semprofissao]==Ladrao_de_Gas && IsPlayerInRangeOfPoint(playerid, 2.0, -453.7872,2230.1296,42.4993)){        //Mafia
        SendClientMessage(playerid,C_Ladrao_de_Gas,"| CARGO | Apartir de agora você ira exerce o cargo Ladrão de Gás");
        SendClientMessage(playerid,C_Ladrao_de_Gas,"| CARGO | Para saber os comandos do cargo, digite: /Comandos");
        PlayerInfo[playerid][Profissao]=Ladrao_de_Gas;
        ProfissaoonMafia[playerid]=0;
        Logarprof(playerid);
        } else {
            MessageFormat(playerid, Erro, "| ERRO | Você não está na HQ de %s ", GetProfissao(playerid));
        }
        return 1;
    }
    if(strcmp(cmd, "/trabalhar", true)==0)
    {
        if(ProfissaoonAgencia[playerid] == 0){
        SendClientMessage(playerid, Erro,"| ERRO | Você não foi encaminhado por nenhuma Agencia!");
        return 1;
        }

        if(PlayerInfo[playerid][Semprofissao]==EntregadorJornal && IsPlayerInRangeOfPoint(playerid, 2.0, 785.2020,-1327.7697,13.5469)){         //Honesta
        SendClientMessage(playerid,C_EntregadorJornal,"| PROFISSÃO | Apartir de agora você ira exerce a profissão Entregador(a) de Jornal");
        SendClientMessage(playerid,C_EntregadorJornal,"| PROFISSÃO | Para saber os comandos da profissão, digite: /Profissao");
        PlayerInfo[playerid][Profissao]=EntregadorJornal;
        ProfissaoonAgencia[playerid]=0;
        Logarprof(playerid);
        PlayerPlaySound(playerid,1057,0,0,0);
        } else if(PlayerInfo[playerid][Semprofissao]==Taxi && IsPlayerInRangeOfPoint(playerid, 2.0, 2229.5803,-1368.1969,23.9922)){             //Transporte
        SendClientMessage(playerid,C_Taxi,"| PROFISSÃO | Apartir de agora você ira exerce a profissão Taxi");
        SendClientMessage(playerid,C_Taxi,"| PROFISSÃO | Para saber os comandos da profissão, digite: /Profissao");
        PlayerInfo[playerid][Profissao]=Taxi;
        ProfissaoonAgencia[playerid]=0;
        Logarprof(playerid);
        PlayerPlaySound(playerid,1057,0,0,0);
        } else if(PlayerInfo[playerid][Semprofissao]==Policia_Civil && IsPlayerInRangeOfPoint(playerid, 2.0, 1579.5728,-1635.3932,13.5611)){    //Policia
        SendClientMessage(playerid,C_Policia_Civil,"| PROFISSÃO | Apartir de agora você ira exerce a profissão Policia Civil");
        SendClientMessage(playerid,C_Policia_Civil,"| PROFISSÃO | Para saber os comandos da profissão, digite: /Profissao");
        PlayerInfo[playerid][Profissao]=Policia_Civil;
        ProfissaoonAgencia[playerid]=0;
        Logarprof(playerid);
        PlayerPlaySound(playerid,1057,0,0,0);
        } else if(PlayerInfo[playerid][Semprofissao]==Corregedoria && IsPlayerInRangeOfPoint(playerid, 2.0, 2339.9778,2457.2256,14.9688)){      //Governo
        SendClientMessage(playerid,C_Corregedoria,"| PROFISSÃO | Apartir de agora você ira exerce a profissão Corregedoria");
        SendClientMessage(playerid,C_Corregedoria,"| PROFISSÃO | Para saber os comandos da profissão, digite: /Profissao");
        PlayerInfo[playerid][Profissao]=Corregedoria;
        ProfissaoonAgencia[playerid]=0;
        Logarprof(playerid);
        PlayerPlaySound(playerid,1057,0,0,0);
        } else {
            MessageFormat(playerid, Erro, "| ERRO | Você não está na HQ de %s ", GetProfissao(playerid));
        }
        return 1;
    }
    if(strcmp(cmd, "/identidade", true) == 0)
    {
        new DialogStatus[1000], DialogStatus2[100];
        format(String, sizeof(String),"{0080FF}Identidade de {FFFFFF}%s", PlayerName(playerid));
        strcat(DialogStatus2, String);
        format(String, sizeof(String),"{FFFFFF}» Level: {00FF00}%d \n", PlayerInfo[playerid][Level]);
        strcat(DialogStatus, String);
        format(String, sizeof(String),"{FFFFFF}» Experiência: {00FF00}%d \n", PlayerInfo[playerid][Exp]);
        strcat(DialogStatus, String);
        format(String, sizeof(String),"{FFFFFF}» Coins: {00FF00}R$%d \n", PlayerInfo[playerid][Coins]);
        strcat(DialogStatus, String);
        if(PlayerInfo[playerid][Vip]==0){
        format(String, sizeof(String),"{FFFFFF}» VIP: {f84300}Não \n");
        strcat(DialogStatus, String);
        }if(PlayerInfo[playerid][Vip]==1){
        format(String, sizeof(String),"{FFFFFF}» VIP: {00FF00}Sim \n");
        strcat(DialogStatus, String);
        }format(String, sizeof(String),"{FFFFFF}» Skin ID: {00FF00}%d \n", PlayerInfo[playerid][Skin]);
        strcat(DialogStatus, String);
        format(String, sizeof(String),"{FFFFFF}» Dinheiro: {00FF00}%d \n", PlayerInfo[playerid][Dinheiro]);
        strcat(DialogStatus, String);
        format(String, sizeof(String),"{FFFFFF}» Matou: {00FF00}%d {FFFFFF}- Morreu: {f84300}%d \n", PlayerInfo[playerid][Matou], PlayerInfo[playerid][Morreu]);
        strcat(DialogStatus, String);
        format(String, sizeof(String),"{FFFFFF}» Avisos: {f84300}%d \n", PlayerInfo[playerid][Avisos]);
        strcat(DialogStatus, String);
        format(String, sizeof(String),"{FFFFFF}» E-mail: {00FF00}%s \n", PlayerInfo[playerid][Email]);
        strcat(DialogStatus, String);
        ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, DialogStatus2, DialogStatus, "Fechar", "");
        return 1;
    }
    if(strcmp(cmd, "/statusmostrar", true) == 0)
    {
        Statusmostrar(playerid);
        return 1;
    }
    if(strcmp(cmd, "/statusocultar", true) == 0)
    {
        Statusocultar(playerid);
        return 1;
    }
    if(strcmp(cmd, "/relatorio", true) == 0)
    {
    	if(LiberarRelatorio{playerid} == true)
        return SendClientMessage(playerid, Erro, "| ERRO | Relatório bloqueado por flood, aguarde alguns segundos!");

        tmp = strtok(cmdtext, idx);
        tmp2 = strrest(cmdtext, idx);

        if(!strlen(tmp)) return SendClientMessage(playerid, Erro, "| ERRO | Digite: /Relatorio [ID] [Motivo]");
        if(!strlen(tmp2)) return SendClientMessage(playerid, Erro, "| ERRO | Digite: /Relatorio [ID] [Motivo]");

        TemDuvidaOuRelatorio[playerid] = true;
        LiberarRelatorio{playerid} = true;
    	SetTimerEx("LiberouRelatorio", 30000, false, "i", playerid);

        SendClientMessage(playerid, Branco, "| Relatório | Seu relatorio foi enviado com sucesso para a Adminstração!");
    	format(String, sizeof(String), "| Relatório | Relatório de %s[%d] acusando: %s[%d] de %s", PlayerName(playerid), playerid, PlayerName(id), id, tmp2);
    	Relatorio(0x80FFFFAA, String);
    	return 1;
	}
    if(strcmp(cmd, "/duvida", true) == 0)
    {
    	if(LiberarDuvida{playerid} == true)
        return SendClientMessage(playerid, Erro, "| ERRO | Duvida bloqueada por flood, aguarde alguns segundos!");

        tmp = strrest(cmdtext, idx);

        if(!strlen(tmp)) return SendClientMessage(playerid, Erro, "| ERRO | Digite: /Duvida [Sua duvida]");

        TemDuvidaOuRelatorio[playerid] = true;
    	LiberarDuvida{playerid} = true;
    	SetTimerEx("LiberouDuvida", 30000, false, "i", playerid);

        SendClientMessage(playerid, Branco, "| Duvida | Sua duvida foi enviada a Administraçáo, aguarde umá resposta!");
    	format(String, sizeof(String), "| DUVIDA | Duvida de %s[%d]: %s", PlayerName(playerid), playerid, tmp);
    	Duvida(0x80FFFFAA, String);
    	return 1;
	}
    if(strcmp(cmd, "/responder", true) == 0)
    {
        tmp = strtok(cmdtext, idx);
        tmp2 = strrest(cmdtext, idx);

        if(!strlen(tmp)) return SendClientMessage(playerid, Erro, "| ERRO | Digite: /Responder [ID] [Responder]");
        if(!strlen(tmp2)) return SendClientMessage(playerid, Erro, "| ERRO | Digite: /Responder [ID] [Responder]");

        id = strval(tmp);

        if(TemDuvidaOuRelatorio[id] == false)
        return SendClientMessage(playerid, Erro, "| ERRO | Esse 'ID' não tem duvida ou relatorio!");

        MessageFormat(playerid, Branco, "| Resposta | Você respondeu a duvida ou o relatório do jogador(a) %s[%d]", PlayerName(id), id);
        format(String, sizeof(String), "| Resposta | %s %s respondeu : %s", CargoAdmin(playerid), PlayerName(playerid), tmp2);
        RespondendoDuvidaOuRelatorio(0x80FFFFAA, String);
        TemDuvidaOuRelatorio[id] = false;
    	return 1;
	}
    if(strcmp(cmdtext,"/creditos", true)== 0)
	{
        new textos[1500];
        strcat(textos, "{FF0000} GameMode: {FFFFFF}Vida Brasileira - V.B RPG v1.0.0 \n\n");
        strcat(textos, "{FFFFFF} Desenvolvido e Atualizado por: {088fd2}Henrique Calenzo \n\n");
        strcat(textos, "{1b6302} Agradecimentos Especiais; \n\n");
        strcat(textos, "{f29b0d} Y_Less - {FFFFFF}pelo SSCANF2 & Foreach \n");
        strcat(textos, "{f29b0d} pBlueG - {FFFFFF}pelo Mysql \n");
        strcat(textos, "{f29b0d} JaimeOliveira_. - {FFFFFF}pelos testes & Ideias \n");
        strcat(textos, "{f29b0d} PARANOICO - {FFFFFF}pelos testes \n");
        strcat(textos, "{f29b0d} OszmYago - {FFFFFF}pelos testes \n\n");
        strcat(textos, "{218721} Www.VidaBrasileira.forumeiros.com \n\n");
        strcat(textos, "{FFFFFF} © Copyright 2019 - 2019 Vida Brasileira ");
        ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{00CED1}Créditos{FFFFFF}",textos, "Fechar", "");
        return 1;
	}
    if(strcmp(cmd, "/regras", true)==0)
	{
        new textogrande[3000];
		strcat(textogrande, "{FFFFFF}»{FF0000} Vaga de Adm {FFFFFF}- Nunca fique pedindo se tem vagas para Ajudante/Moderador/Administrador, todos jogadores sempre sáo avaliados\naquele que joga direito e ajuda os demais jogadores sempre tem uma grande chance quando abrimos Vagas\n\n");
		strcat(textogrande, "{FFFFFF}»{FF0000} Drive By DB {FFFFFF}- Nunca mate um jogador de dentro de um veiculo, é proibido e receberá puniçóes\n\n");
		strcat(textogrande, "{FFFFFF}»{FF0000} Death Match / DM{FFFFFF}- Não faça DM em locais Públicos ( Ex: Prefeituras, Bancos, agência, etc..) pois receberá punições,\n usem a favela, la vocês ganham armas e o DM é liberado\n\n");
		strcat(textogrande, "{FFFFFF}»{FF0000} Ofensas, Provocacoes e Perturbacoes - {FFFFFF}Perturbaçáo excessiva(floods, discussoes, etc... ) ou palavreado de origem\nofensiva no chat Público, seja por religiao ou preconceito, bem como assuntos náo relacionados ao jogo, como\nprovocacoes e criticas a jogadores ou a administradores, sera entendido como perturbaçáo e receberá punicoes\n\n");
		strcat(textogrande, "{FFFFFF}»{FF0000} Divugaçáo {FFFFFF}- É proibido Mensagens que contenham assuntos ou propagandas relacionados a outros servidores\nbem como divugacoes que ip ou de cheats\n\n");
		strcat(textogrande, "{FFFFFF}»{FF0000} Anti-AFK{FFFFFF}- Nunca tente sabotar o AFK é proibido e se algum ADM pegar sabotando será banido sem aviso\n\n");
		strcat(textogrande, "{FFFFFF}»{FF0000} Cheater{FFFFFF}- Qualquer programa ou 'mods' que possa lhe dar vantagem em jogo ou perante outros jogadores\nserá considerado como uso de cheater e será banido sem aviso\n\n");
		strcat(textogrande, "{FFFFFF}»{FF0000} Beneficios{FFFFFF}-  Nunca fique pedidndo pra algum ADM dar ( level dinheiro etc... ) vocé deve jogar para conseguir\n\n");
		strcat(textogrande, "{FFFFFF}»{FF0000} Anti-RPG{FFFFFF}- Nunca se atire na frente de veiculos, náo saia do servidor ( algemado, perseguiçóes, etc... ) caso contrario\n receberá puniçóes e até banimento\n\n");
		strcat(textogrande, "{FFFFFF}»{FF0000} Abuso de Bugs{FFFFFF}- Nunca abuse de bugs, sempre reporte-os para administraçáo caso contrario banido sem aviso previo\n\n");
		strcat(textogrande, "{0AB752}» VIPs seráo julgados da mesma forma que os demais jogadores\n\n");
        ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Regras", textogrande, "Fechar", "");
		return 1;
	}
    if(strcmp(cmd, "/vantagensvip", true)==0)
	{
        new textos[1000];
		strcat(textos, "{FFFF00}»{FFFFFF} Sistema auto tuning \n");
		strcat(textos, "{FFFF00}»{FFFFFF} Nitro infinito \n");
		strcat(textos, "{FFFF00}»{FFFFFF} Nick com prefixo [VIP] no chat \n");
		strcat(textos, "{FFFF00}»{FFFFFF} Mudar a cor da Tag [VIP] \n");
		strcat(textos, "{FFFF00}»{FFFFFF} Reparo de veículo \n");
		strcat(textos, "{FFFF00}»{FFFFFF} Virar veículo caso capote-o \n");
		strcat(textos, "{FFFF00}»{FFFFFF} Pintar veículo \n");
		strcat(textos, "{FFFF00}»{FFFFFF} Tunar Veículo \n");
		strcat(textos, "{FFFF00}»{FFFFFF} Colete \n");
		strcat(textos, "{FFFF00}»{FFFFFF} Jetpack \n");
		strcat(textos, "{FFFF00}»{FFFFFF} Tag VIP acima da skin \n");
		strcat(textos, "{FFFF00}»{FFFFFF} Chat exclusivo VIP \n");
		ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FFFFFF}Vantagens VIP", textos, "Fechar", "");
		return 1;
	}
    if(strcmp(cmd, "/comandosvip", true)==0)
	{
        new textos[1000];
		strcat(textos, "{FFFFFF}» {FFFF00}/Jetpack {FFFFFF}- Para pegar uma mochila a jato \n");
		strcat(textos, "{FFFFFF}» {FFFF00}/Colete {FFFFFF}- Para pegar um colete \n");
		strcat(textos, "{FFFFFF}» {FFFF00}/Virar {FFFFFF}- Para virar seu veículo \n");
		strcat(textos, "{FFFFFF}» {FFFF00}/Pintar {FFFFFF}- Para pintar o seu veículo \n");
		strcat(textos, "{FFFFFF}» {FFFF00}/Tunar {FFFFFF}- Para tunar o seu veículo \n");
		strcat(textos, "{FFFFFF}» {FFFF00}/Paintjob {FFFFFF}- Para personalizar a pintura do seu veículo \n");
		strcat(textos, "{FFFFFF}» {FFFF00}/Tag {FFFFFF}- Para mudar a cor da TAG [VIP] \n");
		strcat(textos, "{FFFFFF}» {FFFF00}/V {FFFFFF}- Chat exclusivo VIP \n");
        strcat(textos, "{FFFFFF}» {FFFF00}/VOn {FFFFFF}- Ligue o chat VIP \n");
        strcat(textos, "{FFFFFF}» {FFFF00}/VOff {FFFFFF}- Desligue o chat VIP \n");
        strcat(textos, "{FFFFFF}» {FFFF00}/Vencimento {FFFFFF}- Para ver o dia do vencimento do seu vip \n");
		ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FFFFFF}Comandos VIP", textos, "Fechar", "");
		return 1;
	}
    if(strcmp(cmd, "/animes", true)==0)
    {
        new textos[1000];
        strcat(textos, "{FFFFFF}/dance 1-4 ~ /maosacima ~ /bebado ~ /bomba ~ /mirar ~ /merda ~ /pormascara \n");
        strcat(textos, "/roubar ~ /cruzar ~ /deitar ~ /abaixar ~ /vomitar ~ /comer ~ /chamar ~ /passaramao \n");
        strcat(textos, "/cobrar ~ /overdose ~ /fumar ~ /sentar ~ /conversar ~ /fodase ~ /luta ~ /observar  \n");
        strcat(textos, "/mijar ~ /parar \n");
        ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Animes", textos, "Fechar", "");
        return 1;
    }
    if(strcmp(cmd, "/dance", true)==0)
    {
    	tmp = strtok(cmdtext, idx);

    	if(!strlen(tmp))
    	return SendClientMessage(playerid,0xFF0000FF,"| ERRO | Use: /dance [1-4]");

    	new animationplayed = strval(tmp);

    	if(animationplayed < 1 || animationplayed > 4)
    	return SendClientMessage(playerid,0xFF0000FF,">Digite /dance [1-4]");

    	if(animationplayed == 1){
    	   SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE1);
    	} else if(animationplayed == 2){
    	   SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE2);
    	} else if(animationplayed == 3){
    	   SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE3);
    	} else if(animationplayed == 4){
    	   SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE4);
    	}
    	return 1;
	}
	if(strcmp(cmd, "/maoscima", true)==0){
    SetPlayerSpecialAction(playerid, 10);
	return 1;
	}
	if(strcmp(cmd, "/bebado", true)==0){
	ApplyAnimation(playerid, "PED", "WALK_DRUNK", 4.0, 1, 1, 1, 1, 0);
	return 1;
	}
	if(strcmp(cmd, "/bomba", true)==0){
	ClearAnimations(playerid);
	ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/mirar", true)==0){
	ApplyAnimation(playerid, "ped", "ARRESTgun", 4.0, 0, 1, 1, 1, -1);
	return 1;
	}
	if(strcmp(cmd, "/merda", true)==0){
	ApplyAnimation(playerid, "RAPPING", "Laugh_01", 4.0, 0, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/pormascara", true)==0){
	ApplyAnimation(playerid, "SHOP", "ROB_Shifty", 4.0, 0, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/roubar", true)==0){
	ApplyAnimation(playerid, "SHOP", "ROB_Loop_Threat", 4.0, 1, 0, 0, 0, 0);
	return 1;
	}
    if(strcmp(cmd, "/cruzar", true)==0){
	ApplyAnimation(playerid, "COP_AMBIENT", "Coplook_loop", 4.0, 0, 1, 1, 1, -1);
	return 1;
	}
	if(strcmp(cmd, "/deitar", true)==0){
	ApplyAnimation(playerid, "BEACH", "bather", 4.0, 1, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/abaixar", true)==0){
	ApplyAnimation(playerid, "ped", "cower", 3.0, 1, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/vomitar", true)==0){
	ApplyAnimation(playerid, "FOOD", "EAT_Vomit_P", 3.0, 0, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/comer", true)==0){
	ApplyAnimation(playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/chamar", true)==0){
	ApplyAnimation(playerid, "ON_LOOKERS", "wave_loop", 4.0, 1, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/passaramao",  true)==0){
	ApplyAnimation(playerid, "SWEET", "sweet_ass_slap", 4.0, 0, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/cobrar", true)==0){
	ApplyAnimation(playerid, "DEALER", "DEALER_DEAL", 4.0, 0, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/overdose", true)==0){
	ApplyAnimation(playerid, "CRACK", "crckdeth2", 4.0, 1, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/fumar", true)==0){
	ApplyAnimation(playerid, "SMOKING", "M_smklean_loop", 4.0, 1, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/sentar", true)==0){
	ApplyAnimation(playerid, "BEACH", "ParkSit_M_loop", 4.0, 1, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/conversar", true)==0){
	ApplyAnimation(playerid, "PED", "IDLE_CHAT", 4.0, 0, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/fodase", true)==0){
	ApplyAnimation(playerid, "PED", "fucku", 4.0, 0, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/luta", true) == 0){
	ApplyAnimation(playerid, "PARK", "Tai_Chi_Loop", 4.0, 1, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/observar", true)==0){
	ApplyAnimation(playerid, "BAR", "dnk_stndF_loop", 4.0, 1, 0, 0, 0, 0);
	return 1;
	}
	if(strcmp(cmd, "/mijar", true)==0){
	SetPlayerSpecialAction(playerid, 68);
	return 1;
	}
    if(strcmp(cmd, "/parar", true)==0){
    ClearAnimations(playerid);
    return 1;
    }
    if(strcmp(cmd, "/toplevel", true)==0)
    {
        new playerScores[MAX_PLAYERS][rankingEnum], index;

        for(new i; i != MAX_PLAYERS; ++i)
    	{
      		if(PlayerInfo[i][Logado]==true && !IsPlayerNPC(i))
      		{
    			playerScores[index][player_Score] = GetPlayerScore(i);
    			playerScores[index++][player_ID] = i;
    		}
    	}

    	GetPlayerHighestScores(playerScores, 0, index);
    	new score_Text[1000] = "\n", player_Name[MAX_PLAYER_NAME];

        for(new i; i < 10; ++i)
        {
         	if(i < index)
            {
                GetPlayerName(playerScores[i][player_ID], player_Name, sizeof(player_Name));
                format(score_Text, sizeof(score_Text), "%s\n {1b6302}%dº\t\t {FFFFFF}%s\t\t{F87A02}%d", score_Text, i + 1, player_Name, playerScores[i][player_Score]);
            } else {
                format(score_Text, sizeof(score_Text), "%s\n {1b6302}%dº\t\t {FFFFFF}N/A\t\t\t {F87A02}0", score_Text, i + 1);
            }
   	    }
   	    ShowPlayerDialog(playerid, 2742, DIALOG_STYLE_LIST, "{FFFFFF}TOP                        Nome                               Level", score_Text, "Fechar", "");
     	return 1;
    }
    if(strcmp(cmd, "/admins", true)==0)
    {
        new Counts, STR[1400], STX[50], adminon;
    	new const Ranks[][] =
    	{
        	"{FFFFFF}[ {FFFF00}Ajudante{FFFFFF} ]",
        	"{FFFFFF}[ {FF8C00}Moderador(a){FFFFFF} ]",
        	"{FFFFFF}[ {008bce}Admininstrador(a){FFFFFF} ]",
        	"{FFFFFF}[ {FF0000}Sub-Staff{FFFFFF} ]",
        	"{FFFFFF}[ {328E0A}Staff{FFFFFF} ]"
    	};

    	for(new x = 0; x <= MAX_PLAYERS; x++)
     	{
        	if(!IsPlayerConnected(x)) continue;
        	if(PlayerInfo[x][Admin])
        	{
            	if(PlayerInfo[x][Admin] >= 1 && PlayerInfo[x][Admin] <= 5)
            	{
                	format(STR, 1400, "%s{FFFFFF} %s {FFFFFF}[%d] %s \n", STR, PlayerName(x), x, Ranks[PlayerInfo[x][Admin] - 1]);
                    adminon++;
            	}
            	Counts++;
         	}
    	}

    	if(adminon == 0)
    	{
            ShowPlayerDialog(playerid, 5000, DIALOG_STYLE_MSGBOX, "{FFFFFF}Admins Online [ {FF0000}0{FFFFFF} ]", "{FF0000}Náo há administrador ( ADM ) online no momento!'", "Fechar", "");
    	} else {
        	format(STX, 200, "{FFFFFF}Admins Online [ {328E0A}%d{FFFFFF} ]", adminon);
        	ShowPlayerDialog(playerid, 500, DIALOG_STYLE_LIST, STX, STR, "Fechar", "");
    	}
     	return 1;
    }
	return SendClientMessage(playerid, Erro, "| ERRO | Comando Inválido!");
}

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    foreach(Player, i)
    {
        for(new v; v < sizeof(BKJORNAL); v ++) if(vehicleid == BKJORNAL[v])
        {
            if(!ispassenger && vehicleid != INVALID_VEHICLE_ID && PlayerInfo[i][Profissao] != EntregadorJornal)
            {
                ClearAnimations(i);
                return SendClientMessage(i, Erro,"| ERRO | Veiculo exclusivo da profissão Entregador(a) de Jornal!");
            }
        }
        for(new v; v < sizeof(VCPOLICIA); v++) if(vehicleid == VCPOLICIA[v])
        {
            if(!ispassenger && vehicleid != INVALID_VEHICLE_ID && PlayerInfo[i][Profissao] != Policia_Civil)
            {
                ClearAnimations(i);
                return SendClientMessage(i, Erro,"| ERRO | Veiculo exclusivo da profissão Policia!");
            }
            if(!ispassenger && vehicleid != INVALID_VEHICLE_ID && !IsPlayerUniformePM(i))
            {
                ClearAnimations(i);
                return SendClientMessage(i, Erro,"| ERRO | Você não está com o uniforme!");
            }
        }
        for(new v; v < sizeof(CRRTAXI); v++) if(vehicleid == CRRTAXI[v] || vehicleid == CRRTAXI[v])
        {
            if(!ispassenger && vehicleid != INVALID_VEHICLE_ID && PlayerInfo[i][Profissao] != Taxi)
            {
                ClearAnimations(i);
                return SendClientMessage(i, Erro,"| ERRO | Veiculo exclusivo da profissão Taxista!");
            }
        }
        for(new v; v < sizeof(BKNOVATOS); v++) if(vehicleid == BKNOVATOS[v] || vehicleid == BKNOVATOS[v])
        {
            if(!ispassenger && vehicleid != INVALID_VEHICLE_ID && PlayerInfo[i][Level] > 5)
            {
                ClearAnimations(i);
                return SendClientMessage(i, Erro,"| ERRO | Bike exclusiva para novatos!");
            }
        }
        for(new v; v < sizeof(CARROLG); v++) if(vehicleid == CARROLG[v] || vehicleid == CARROLG[v])
        {
            if(!ispassenger && vehicleid != INVALID_VEHICLE_ID && PlayerInfo[i][Profissao] != Ladrao_de_Gas)
            {
                ClearAnimations(i);
                return SendClientMessage(i, Erro,"| ERRO | Veiculo exclusivo do cargo Ladrão de Gás!");
            }
        }
    }
    return 1;
}

public OnPlayerExitVehicle(playerid, vehicleid)
{
    DeletarSair(playerid);
	return 1;
}

public OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(newstate == PLAYER_STATE_DRIVER)
    {
        SendClientMessage(playerid, Branco, "| INFO | Para ligar ou desligar o veiculo digite '{CECECE}/Partida{FFFFFF}' ou pressione a tecla '{CECECE}Y{FFFFFF}'");
    }
    return 1;
}

public OnPlayerEnterCheckpoint(playerid)
{
	return 1;
}

public OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(checkpointid == cp_mafia)
    {
        ShowPlayerDialog(playerid, MenuMafia, DIALOG_STYLE_LIST, "{FF0000}Cargos", "{FFFFFF}Ladrão de gás ", "Selecionar", "Fechar");
    }
    if(checkpointid == cp_agencia)
    {
        ShowPlayerDialog(playerid, MenuAgencia, DIALOG_STYLE_LIST, "{FF0000}Menu Empregos", "{FFFFFF}Classe » {80FF80}Honesta \n{FFFFFF}Classe » {80FFFF}Transporte \n{FFFFFF}Classe » {51A8FF}Policia \n{FFFFFF}Classe » {626262}Governo ", "Selecionar", "Fechar");
        return 1;
    }
    if(checkpointid == cp_profissoes[playerid])
    {
        DestroyDynamicCP(cp_profissoes[playerid]);
        SendClientMessage(playerid, Verde, "| GPS | Você chegou a o local marcado!");
    }
	return 1;
}

public OnPlayerLeaveCheckpoint(playerid)
{
	return 1;
}

public OnPlayerEnterRaceCheckpoint(playerid)
{
	return 1;
}

public OnPlayerLeaveRaceCheckpoint(playerid)
{
	return 1;
}

public OnRconCommand(cmd[])
{
	return 1;
}

public OnPlayerRequestSpawn(playerid)
{
	return 1;
}

public OnObjectMoved(objectid)
{
	return 1;
}

public OnPlayerObjectMoved(playerid, objectid)
{
	return 1;
}

public OnPlayerPickUpPickup(playerid, pickupid)
{
    if(pickupid == entrando[0] || pickupid == entrando[1] || pickupid == entrando[2])
    {
        SendClientMessage(playerid, Branco, "| INFO | Para entrar na casa digite {CFCDCD}'/Entrar'{FFFFFF} ou pressione a tecla {CFCDCD}'F'");
        return 1;
    }
	return 1;
}

public OnVehicleMod(playerid, vehicleid, componentid)
{
	return 1;
}

public OnVehiclePaintjob(playerid, vehicleid, paintjobid)
{
	return 1;
}

public OnVehicleRespray(playerid, vehicleid, color1, color2)
{
	return 1;
}

public OnPlayerSelectedMenuRow(playerid, row)
{
	return 1;
}

public OnPlayerExitedMenu(playerid)
{
	return 1;
}

public OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
{
	return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(PRESSED(KEY_FIRE))
	{
        if(IsPlayerAjudante(playerid) || IsPlayerVip(playerid))
        {
            if(IsPlayerInAnyVehicle(playerid))
            {
                if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
                {
                    if(NitroInfinito(GetPlayerVehicleID(playerid)))
                    {
                        AddVehicleComponent(GetPlayerVehicleID(playerid), 1010);
                        RepairVehicle(GetPlayerVehicleID(playerid));
                    }
                }
            }
    	}
        return 1;
    }
    if(PRESSED(KEY_YES) && IsPlayerInAnyVehicle(playerid))
    {
    	new mot, lu, alar, por, cap, porma, ob;
    	new vehicleid = GetPlayerVehicleID(playerid);
    	GetVehicleParamsEx(vehicleid, mot, lu, alar, por, cap, porma, ob);
    	if(mot == VEHICLE_PARAMS_OFF)
        {
            SetVehicleParamsEx(vehicleid, VEHICLE_PARAMS_ON, lu, alar, por, cap, porma, ob);
            SendClientMessage(playerid, Verde, "| INFO | Veiculo ligado!");
    	} else {
    	    SendClientMessage(playerid, Verde, "| INFO | Veiculo desligado!");
            SetVehicleParamsEx(vehicleid, VEHICLE_PARAMS_OFF, lu, alar, por, cap, porma, ob);
    	}
    }
    if(newkeys == KEY_SECONDARY_ATTACK)
    {
        if(IsPlayerAjudante(playerid) || PlayerInfo[playerid][Profissao] == Policia_Civil)
        {
            AbrindoPortaPolicia(playerid);
        }
        EntrarInterior(playerid);
        SairInterior(playerid);
        return true;
    }
	return 1;
}

public OnRconLoginAttempt(ip[], password[], success)
{
	return 1;
}

public OnPlayerUpdate(playerid)
{
	return 1;
}

public OnPlayerStreamIn(playerid, forplayerid)
{
	return 1;
}

public OnPlayerStreamOut(playerid, forplayerid)
{
	return 1;
}

public OnVehicleStreamIn(vehicleid, forplayerid)
{
	return 1;
}

public OnVehicleStreamOut(vehicleid, forplayerid)
{
	return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == NAME_LOGIN)
    {
        format(pPlayerInfo[playerid][pNome], MAX_PLAYER_NAME, inputtext);
        if(pPlayerInfo[playerid][pNome] == 0) return 0;
        PlayerTextDrawSetString(playerid, PlayerLogin[playerid][9], inputtext);
        PlayerTextDrawShow(playerid, PlayerLogin[playerid][9]);
        return 1;
    }
    if(dialogid == PASS_LOGIN)
    {
        format(pPlayerInfo[playerid][pSenha], MAX_PLAYER_PASS, inputtext);
        if(pPlayerInfo[playerid][pSenha] == 0) return 0;
        for(new i=0; i < strlen(inputtext); i++)
        {
            inputtext[i] = ']';
        }
        PlayerTextDrawSetString(playerid, PlayerLogin[playerid][10], inputtext);
        PlayerTextDrawShow(playerid, PlayerLogin[playerid][10]);
        return 1;
    }
    if(dialogid == NAME_REGISTER)
    {
        format(pPlayerInfo[playerid][pNome], MAX_PLAYER_NAME, inputtext);
        if(strlen(inputtext) <= 0) return 0;
        if(strlen(inputtext) < MIN_PLAYER_NAME || strlen(inputtext) > MAX_PLAYER_NAME)
        {
            SendClientMessage(playerid, Aviso, "| AVISO | Digite um nome entre 6 a 24 caracteres!");
            pPlayerInfo[playerid][pNome]=0;
            return 1;
        }
        PlayerTextDrawSetString(playerid, PlayerRegistro[playerid][17], inputtext);
        PlayerTextDrawShow(playerid, PlayerRegistro[playerid][17]);
        return 1;
    }
    if(dialogid == PASS_REGISTER)
    {
        format(pPlayerInfo[playerid][pSenha], MAX_PLAYER_PASS, inputtext);
        if(strlen(inputtext) <= 0) return 0;
        if(strlen(inputtext) < MIN_PLAYER_PASS || strlen(inputtext) > MAX_PLAYER_PASS)
        {
            SendClientMessage(playerid, Aviso, "| AVISO | Digite uma senha entre 6 a 24 caracteres!");
            pPlayerInfo[playerid][pSenha]=0;
            return 1;
        }
        for(new i=0; i < strlen(inputtext); i++)
        {
            inputtext[i] = ']';
        }
        PlayerTextDrawSetString(playerid, PlayerRegistro[playerid][18], inputtext);
        PlayerTextDrawShow(playerid, PlayerRegistro[playerid][18]);
        return 1;
    }
    if(dialogid == EMAIL_REGISTER)
    {
        format(pPlayerInfo[playerid][pEmail], MAX_PLAYER_NAME, inputtext);
        if(strlen(inputtext) <= 0) return 0;
        if(strlen(inputtext) < MIN_PLAYER_EMAIL || strlen(inputtext) > MAX_PLAYER_EMAIL)
        {
            SendClientMessage(playerid, Aviso, "| AVISO | Digite um e-mail com no minimo 15 caracteres!");
            pPlayerInfo[playerid][pEmail]=0;
            return 1;
        }
        PlayerTextDrawSetString(playerid, PlayerRegistro[playerid][19], inputtext);
        PlayerTextDrawShow(playerid, PlayerRegistro[playerid][19]);
        return 1;
    }
    if(dialogid == MenuMafia)
    {
        if(response)
        {
            switch(listitem)
            {
                case 0:
                {
                    if(PlayerInfo[playerid][Level] >= 0)
                    PlayerPlaySound(playerid,1057,0,0,0);
                    cp_profissoes[playerid] = CreateDynamicCP(-453.7872,2230.1296,42.4993,1.0,-1,-1,playerid,1000.0);
                    PlayerInfo[playerid][Profissao]=Desempregado;
                    PlayerInfo[playerid][Semprofissao]=Ladrao_de_Gas;
                    ProfissaoonMafia[playerid]=1;
                    Logarprof(playerid);
                    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Encaminhamento - {FFFFFF}Agencia de Empregos", "{FFFFFF}Você foi aceito no cargo {00FF00}Ladrão de Gás \n\n{FFFFFF}Para iniciar os serviços siga o checkpoint {FF0000}Vermelho {FFFFFF}em seu radar", "Fechar", "");
                }
            }
        }
        return 1;
    }
    if(dialogid == MenuAgencia)
    {
        if(response)
        {
            switch(listitem)
            {
                case 0:
                {
                    new string[200];
                    strcat(string,"{FFFFFF}Profissão\t{FF0000}Level\t{1CEB00}Salario \n{FFFFFF}Entregador(a) de Jornal\t {F71616}0\t {1CEB00}$150");
                    ShowPlayerDialog(playerid, Honesta, DIALOG_STYLE_TABLIST_HEADERS, "{00ff00}Honesta", string, "Selecionar", "Voltar");
                }
                case 1:
                {
                    new string[200];
                    strcat(string,"{FFFFFF}Profissão\t{FF0000}Level\t{1CEB00}Salario \n{FFFFFF}Taxi\t{F71616}5\t {1CEB00}$500");
                    ShowPlayerDialog(playerid, Transporte, DIALOG_STYLE_TABLIST_HEADERS, "{707070}Transporte", string, "Selecionar", "Voltar");
                }
                case 2:
                {
                    new string[200];
                    strcat(string,"{FFFFFF}Profissão\t{FF0000}Level\t{1CEB00}Salario \n{FFFFFF}Policia municipal\t {F71616}100\t {1CEB00}$1000");
                    ShowPlayerDialog(playerid, Policia, DIALOG_STYLE_TABLIST_HEADERS, "{0000ff}Policia", string, "Selecionar", "Voltar");
                }
                case 3:
                {
                    new string[200];
                    strcat(string,"{FFFFFF}Profissão\t {FF0000}Level\t {1CEB00}Salario \n{FFFFFF}Corregedoria\t {F71616}1000\t {1CEB00}$6000");
                    ShowPlayerDialog(playerid, Governo, DIALOG_STYLE_TABLIST_HEADERS, "{0000ff}Policia", string, "Selecionar", "Voltar");
                }
            }
        }
        return 1;
    }
    if(dialogid == Honesta)
    {
        if(response)
        {
            switch(listitem)
            {
                case 0:
                {
                    if(PlayerInfo[playerid][Level] >= 0)
                    PlayerPlaySound(playerid,1057,0,0,0);
                    cp_profissoes[playerid] = CreateDynamicCP(785.2020,-1327.7697,13.5469,1.0,-1,-1,playerid,1000.0);
                    PlayerInfo[playerid][Profissao]=Desempregado;
                    PlayerInfo[playerid][Semprofissao]=EntregadorJornal;
                    ProfissaoonAgencia[playerid]=1;
                    Logarprof(playerid);
                    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Encaminhamento - {FFFFFF}Agencia de Empregos", "{FFFFFF}Você foi aceito no emprego {00FF00}Entregador(a) de Jornal \n\n{FFFFFF}Para iniciar os serviços siga o checkpoint {FF0000}Vermelho {FFFFFF}em seu radar ", "Fechar", "");
                }
            }
        }
        if(!response)
        {
            ShowPlayerDialog(playerid, MenuAgencia, DIALOG_STYLE_LIST, "{FF0000}Menu Empregos", "{FFFFFF}Classe » {80FF80}Honesta \n{FFFFFF}Classe » {80FFFF}Transporte \n{FFFFFF}Classe » {51A8FF}Policia \n{FFFFFF}Classe » {626262}Governo ", "Selecionar", "Fechar");
        }
        return 1;
    }
    if(dialogid == Transporte)
    {
        if(response)
        {
            switch(listitem)
            {
                case 0:
                {
                    if(PlayerInfo[playerid][Level] >= 5)
                    {
                        cp_profissoes[playerid] = CreateDynamicCP(2229.5803,-1368.1969,23.99221,1.0,-1,-1,playerid,1000.0);
                        PlayerPlaySound(playerid,1057,0,0,0);
                        PlayerInfo[playerid][Profissao]=Desempregado;
                        PlayerInfo[playerid][Semprofissao]=Taxi;
                        ProfissaoonAgencia[playerid]=1;
                        Logarprof(playerid);
                        ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Encaminhamento - {FFFFFF}Agencia de Empregos", "{FFFFFF}Você foi aceito no emprego {00FF00}Taxi \n\n{FFFFFF}Para iniciar os serviços siga o checkpoint {FF0000}Vermelho {FFFFFF}em seu radar ", "Fechar", "");
                    } else {
                        SendClientMessage(playerid, Erro, "| ERRO | Você não tem level suficiente para pegar essa profissão.");
                    }
                }
            }
        }
        if(!response)
        {
            ShowPlayerDialog(playerid, MenuAgencia, DIALOG_STYLE_LIST, "{FF0000}Menu Empregos", "{FFFFFF}Classe » {80FF80}Honesta \n{FFFFFF}Classe » {80FFFF}Transporte \n{FFFFFF}Classe » {51A8FF}Policia \n{FFFFFF}Classe » {626262}Governo ", "Selecionar", "Fechar");
        }
        return 1;
    }
    if(dialogid == Policia)
    {
        if(response)
        {
            switch(listitem)
            {
                case 0:
                {
                    if(PlayerInfo[playerid][Level] >= 100)
                    {
                        cp_profissoes[playerid] = CreateDynamicCP(1579.5728,-1635.3932,13.5611,1.0,-1,-1,playerid,1000.0);
                        PlayerPlaySound(playerid,1057,0,0,0);
                        PlayerInfo[playerid][Profissao]=Desempregado;
                        PlayerInfo[playerid][Semprofissao]=Policia_Civil;
                        ProfissaoonAgencia[playerid]=1;
                        Logarprof(playerid);
                        ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Encaminhamento - {FFFFFF}Agencia de Empregos", "{FFFFFF}Você foi aceito no emprego {00FF00}Policia Civil \n\n{FFFFFF}Para iniciar os serviços siga o checkpoint {FF0000}Vermelho {FFFFFF}em seu radar ", "Fechar", "");
                    } else {
                        SendClientMessage(playerid, Erro, "| ERRO | Você não tem level suficiente para pegar essa profissão.");
                    }
                }
            }
        }
        if(!response)
        {
            ShowPlayerDialog(playerid, MenuAgencia, DIALOG_STYLE_LIST, "{FF0000}Menu Empregos", "{FFFFFF}Classe » {80FF80}Honesta \n{FFFFFF}Classe » {80FFFF}Transporte \n{FFFFFF}Classe » {51A8FF}Policia \n{FFFFFF}Classe » {626262}Governo ", "Selecionar", "Fechar");
        }
        return 1;
    }
    if(dialogid == Governo)
    {
        if(response)
        {
            switch(listitem)
            {
                case 0:
                {
                    if(PlayerInfo[playerid][Level] >= 1000)
                    {
                        cp_profissoes[playerid] = CreateDynamicCP(2339.9778,2457.2256,14.9688,1.0,-1,-1,playerid,1000.0);
                        PlayerPlaySound(playerid,1057,0,0,0);
                        PlayerInfo[playerid][Profissao]=Desempregado;
                        PlayerInfo[playerid][Semprofissao]=Corregedoria;
                        ProfissaoonAgencia[playerid]=1;
                        Logarprof(playerid);
                        ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Encaminhamento - {FFFFFF}Agencia de Empregos", "{FFFFFF}Você foi aceito no emprego {00FF00}Corregedoria \n\n{FFFFFF}Para iniciar os serviços siga o checkpoint {FF0000}Vermelho {FFFFFF}em seu radar ", "Fechar", "");
                    } else {
                        SendClientMessage(playerid, Erro, "| ERRO | Você não tem level suficiente para pegar essa profissão.");
                    }
                }
            }
        }
        if(!response)
        {
            ShowPlayerDialog(playerid, MenuAgencia, DIALOG_STYLE_LIST, "{FF0000}Menu Empregos", "{FFFFFF}Classe » {80FF80}Honesta \n{FFFFFF}Classe » {80FFFF}Transporte \n{FFFFFF}Classe » {51A8FF}Policia \n{FFFFFF}Classe » {626262}Governo ", "Selecionar", "Fechar");
        }
        return 1;
    }
    if(dialogid == menuajuda)
    {
        if(response)
        {
            if(listitem == 0)
            {
                new textos[500];
            	strcat(textos, "{a4a4a4}A cada 10 minutos jogado você ganhará 1 ponto de experiência \n");
                strcat(textos, "{a4a4a4}Juntando 6 pontos de experiência você ganhará +1 level \n\n");
                strcat(textos, "{a4a4a4}Jogadores(as) VIPs terá que juntar 5 experiência para ganhar +1 level \n\n");
                strcat(textos, "{FFFFFF}»{66cdaa} /MeuLevel {FFFFFF}- Para ver seu level \n");
                ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Ajuda Level", textos, "Fechar", "");
            }
            if(listitem == 1)
            {
                new textos[500];
            	strcat(textos, "{a4a4a4}O Salário é creditado em sua conta bancária ao completar UP ( 6/6 ) \n\n");
                strcat(textos, "{a4a4a4}Jogadores(as) VIPs terá salário creditado ao completar UP ( 5/5 ) \n\n");
                strcat(textos, "{a4a4a4}Cada profissão tem um salário diferente e justo \n\n");
                strcat(textos, "{a4a4a4}Cargos da mafia não recebem salário \n");
                ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Ajuda Salário", textos, "Fechar", "");
            }
            if(listitem == 2)
            {
                new textos[2000];
            	strcat(textos, "{00FFFF}»{FFFFFF} /Regras {FFFFFF}- Para ver as regras do servidor\n");
            	strcat(textos, "{00FFFF}»{FFFFFF} /Creditos {FFFFFF}- Para ver os créditos do servidor\n");
            	strcat(textos, "{00FFFF}»{FFFFFF} /Admins {FFFFFF}- Para ver os Admins online no momento\n");
            	strcat(textos, "{00FFFF}»{FFFFFF} /MeuLevel {FFFFFF}- Para ver seu level atual\n");
            	strcat(textos, "{00FFFF}»{FFFFFF} /VantagensVip {FFFFFF}- Para saber as vantagens V.I.P\n");
            	strcat(textos, "{00FFFF}»{FFFFFF} /Sairafk {FFFFFF}- Para sair do modo AFK\n");
            	strcat(textos, "{00FFFF}»{FFFFFF} /Profissao {FFFFFF}- Para ver os comandos da profissão\n");
            	strcat(textos, "{00FFFF}»{FFFFFF} /Abastecer {FFFFFF}- Para abastecer um veículo em um determinado posto\n");
            	strcat(textos, "{00FFFF}»{FFFFFF} /Animes {FFFFFF}- Para ver a lista de animes disponível\n");
            	strcat(textos, "{00FFFF}»{FFFFFF} /190 [Denúncia] {FFFFFF}- Para fazer uma denúncia á policia\n");
            	strcat(textos, "{00FFFF}»{FFFFFF} /193 [Local] {FFFFFF}- Para chamar a equipe de paramédicos\n");
            	strcat(textos, "{00FFFF}»{FFFFFF} /Duvida [Duvida]{FFFFFF}- Para tirar alguma dúvida com algum membro da Administração\n");
            	strcat(textos, "{00FFFF}»{FFFFFF} /Relatorio [Playerid][Denucia]{FFFFFF}- Para denunciar algum jogador fora das regras ou usando hack\n");
            	strcat(textos, "{00FFFF}»{FFFFFF} /Transferir {FFFFFF}- Para transferir uma determinada quantia a um determinado jogador\n");
            	strcat(textos, "{00FFFF}»{FFFFFF} /identidade {FFFFFF}- Para ver sua identidade\n");
            	strcat(textos, "{00FFFF}»{FFFFFF} /Toplevel {FFFFFF}- Para ver os Level Alto\n");
            	strcat(textos, "{00FFFF}»{FFFFFF} /Taxi [Local]{FFFFFF}- Chamar um Taxi\n");
            	strcat(textos, "{00FFFF}»{FFFFFF} /Mecanico [Local]{FFFFFF}- Chamar um Mecanico\n");
            	strcat(textos, "{00FFFF}»{FFFFFF} /Radio {FFFFFF}- Para ligar a Rádio \n");
            	ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Ajuda Comandos", textos, "Fechar", "");
            }
            if(listitem == 3)
            {
                new textos[500];
                strcat(textos, "{FFFFFF}» {FF0000}Fórum: {FFFFFF}www.vidabrasileira.forumeiros.com \n");
                strcat(textos, "{FFFFFF}» {FF0000}Facebook: {FFFFFF}Em Breve \n");
                strcat(textos, "{FFFFFF}» {FF0000}IP do TeamSpeak³: {FFFFFF}Em Breve \n");
                strcat(textos, "{FFFFFF}» {FF0000}IP do Servidor 1 ( v1.0.0 ) {FFFFFF}198.100.144.190:2556 \n");
                ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Contatos", textos, "Fechar", "");
            }
        }
    }
    if(dialogid == TAGVIP)
    {
        if(response)
        {
            switch(listitem)
            {
                case 0:
                {
                    PlayerInfo[playerid][CorVIP]=0;
                }
                case 1:
                {
                    PlayerInfo[playerid][CorVIP]=1;
                }
                case 2:
                {
                    PlayerInfo[playerid][CorVIP]=2;
                }
                case 3:
                {
                    PlayerInfo[playerid][CorVIP]=3;
                }
                case 4:
                {
                    PlayerInfo[playerid][CorVIP]=4;
                }
                case 5:
                {
                    PlayerInfo[playerid][CorVIP]=5;
                }
                case 6:
                {
                    PlayerInfo[playerid][CorVIP]=6;
                }
                case 7:
                {
                    PlayerInfo[playerid][CorVIP]=7;
                }
            }
        }
    }
    //TUNAR
    if(dialogid == menutunagem)
	{
        if(response)
		{
            if(listitem == 0)
    		{
                ShowPlayerDialog(playerid, menuapaintjob,DIALOG_STYLE_LIST,"{FF0000}Paint Jobs","{FFFFFF}PaintJob 1 \nPaintJob 2\nPaintJob 3 \nRemover PaintJob","Concluir","Voltar");
            }
            if(listitem == 1)
    		{
                ShowPlayerDialog(playerid, menunitro,DIALOG_STYLE_LIST,"{FF0000}Nitros","{FFFFFF}Nitro 2\nNitro 5 \nNitro 10 \nRemover Nitro","Concluir","Voltar");
            }
            if(listitem == 2)
    		{
                ShowPlayerDialog(playerid, menuroda,DIALOG_STYLE_LIST,"{FF0000}Rodas","{FFFFFF}Shadow \nMega \nRimshine \nWires \nClassic \nTwist \nCutter \nSwitch \nGrove \nDollar \nTrance \nAtomic \nRemover Rodas","Concluir","Voltar");
            }
            if(listitem == 3)
    		{
                ShowPlayerDialog(playerid, menuhidraulica,DIALOG_STYLE_LIST,"{FF0000}Hidraulica","{FFFFFF}Hidraulica \nRemover Hidraulica","Concluir","Voltar");
            }
            return true;
        }
        return true;
    }
    if(dialogid == menunitro)
	{
        if(response)
		{
            if(listitem == 0)
			{
                AddVehicleComponent(GetPlayerVehicleID(playerid), 1009); // Nitro 1
            }
            if(listitem == 1)
			{
                AddVehicleComponent(GetPlayerVehicleID(playerid), 1008); // Nitro 2
            }
            if(listitem == 2)
			{
                AddVehicleComponent(GetPlayerVehicleID(playerid), 1010); // Nitro 3
            }
            if(listitem == 3)
			{
                RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1009); // Nitro 1
                RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1008); // Nitro 2
                RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1010); // Nitro 3
            }
            return true;
		}
        if(response)
		{
            return ShowPlayerDialog(playerid, menutunagem,DIALOG_STYLE_LIST,"{FF0000}Tunar","{FFFFFF}PaintJobs \nNitros \nRodas \nHidraulica","Concluir","Fechar");
		}
		return true;
	}
    if(dialogid == menuapaintjob)
	{
        if(response)
        {
            if(listitem == 0)
			{
                ChangeVehiclePaintjob(GetPlayerVehicleID(playerid), 0);
            }
            if(listitem == 1)
			{
                ChangeVehiclePaintjob(GetPlayerVehicleID(playerid), 1);
            }
            if(listitem == 2)
			{
                ChangeVehiclePaintjob(GetPlayerVehicleID(playerid), 2);
   		 	}
            if(listitem == 3)
			{
                ChangeVehiclePaintjob(GetPlayerVehicleID(playerid), 3);
   		 	}
		 	return true;
		}
        if(response)
		{
            return ShowPlayerDialog(playerid, menutunagem,DIALOG_STYLE_LIST,"{FF0000}Tunar","{FFFFFF}PaintJobs \nNitros \nRodas \nHidraulica","Concluir","Fechar");
		}
		return true;
	}
    if(dialogid == menuroda)
	{
        if(response)
		{
            if(listitem == 0)
			{
                AddVehicleComponent(GetPlayerVehicleID(playerid), 1073); // Shadow
            }
            if(listitem == 1)
			{
                AddVehicleComponent(GetPlayerVehicleID(playerid), 1074); // Mega
            }
            if(listitem == 2)
			{
                AddVehicleComponent(GetPlayerVehicleID(playerid), 1075); // Rimshine
            }
            if(listitem == 3)
			{
                AddVehicleComponent(GetPlayerVehicleID(playerid), 1076); // Wires
            }
            if(listitem == 4)
			{
                AddVehicleComponent(GetPlayerVehicleID(playerid), 1077);  // Classic
            }
            if(listitem == 5)
			{
                AddVehicleComponent(GetPlayerVehicleID(playerid), 1078); //  Twist
            }
            if(listitem == 6)
			{
                AddVehicleComponent(GetPlayerVehicleID(playerid), 1079); //  Cutter
            }
            if(listitem == 7)
   			{
                AddVehicleComponent(GetPlayerVehicleID(playerid), 1080); //  Switch
            }
            if(listitem == 8)
			{
                AddVehicleComponent(GetPlayerVehicleID(playerid), 1081); //  Grove
            }
            if(listitem == 9)
			{
                AddVehicleComponent(GetPlayerVehicleID(playerid), 1082); //  Import
            }
            if(listitem == 10)
			{
                AddVehicleComponent(GetPlayerVehicleID(playerid), 1083); //  Dollar
            }
            if(listitem == 11)
			{
                AddVehicleComponent(GetPlayerVehicleID(playerid), 1084); // Trance
            }
            if(listitem == 12)
			{
                AddVehicleComponent(GetPlayerVehicleID(playerid), 1085); // Atomic
            }
            if(listitem == 13)
			{
                RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1073);
                RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1074);
                RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1075);
                RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1076);
                RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1077);
                RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1078);
                RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1079);
                RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1080);
                RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1081);
                RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1082);
                RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1083);
                RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1084);
                RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1085);
            }
			return true;
		}
        if(response)
		{
            return ShowPlayerDialog(playerid, menutunagem,DIALOG_STYLE_LIST,"{FF0000}Tunar","{FFFFFF}PaintJobs \nNitros \nRodas \nHidraulica","Concluir","Fechar");
		}
		return true;
	}
    if(dialogid == menuhidraulica)
	{
        if(response)
		{
            if(listitem == 0)
			{
                AddVehicleComponent(GetPlayerVehicleID(playerid), 1087); // Hidraulica
			}
            if(listitem == 1)
			{
                RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1087); // Hidraulica
			}
			return true;
		}
        if(!response)
		{
            return ShowPlayerDialog(playerid, menutunagem,DIALOG_STYLE_LIST,"{FF0000}Tunar","{FFFFFF}PaintJobs \nNitros \nRodas \nHidraulica","Concluir","Fechar");
		}
		return true;
	}
    if(dialogid == mudarnick)
    {
        if(response)
        {
            mysql_format(IDConexao, Query, sizeof(Query), "SELECT * FROM Contas WHERE Nome='%s'", inputtext);
            mysql_query(IDConexao, Query);

            if(!(cache_num_rows() > 0))
            {
                new aname[MAX_PLAYERS];
                GetPlayerName(playerid, aname, sizeof(aname));
                SetPlayerName(playerid, inputtext);
                MessageFormatAll(C_Info, "| NICK | O(A) jogador(a) %s mudou o nick para ( %s )", aname, PlayerName(playerid));
                mysql_format(IDConexao, Query, sizeof(Query), "UPDATE Contas SET Nome='%s' WHERE ID='%d'", inputtext, PlayerInfo[playerid][ID]);
                mysql_query(IDConexao, Query);
            } else {
                ShowPlayerDialog(playerid, mudarnick, DIALOG_STYLE_INPUT, "{FF0000}Mudar nick", "{FF0000}Erro {FFFFFF}nome já em uso:", "Continuar", "Fechar");
            }
        }
    }
    if(dialogid == menuradio)
    {
        if(response)
        {
            switch(listitem)
            {
                case 0:
                {
                    return PlayAudioStreamForPlayer(playerid, "");
                }
                case 1:
                {
                    return PlayAudioStreamForPlayer(playerid, "http://listen.shoutcast.com:80/RadioHunter-TheHitzChannel");
                }
                case 2:
                {
                    return PlayAudioStreamForPlayer(playerid, "");
                }
                case 3:
                {
                    return PlayAudioStreamForPlayer(playerid, "");
                }
                case 4:
                {
                    return StopAudioStreamForPlayer(playerid);
                }
            }
        }
        return 1;
    }
	return 1;
}

public OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{
    if(playertextid == PlayerLogin[playerid][9]) // se clicou em nome
    {
        ShowPlayerDialog(playerid, NAME_LOGIN, DIALOG_STYLE_INPUT, "{FF0000}Nome", "{FFFFFF}Digite seu nome em baixo para efetuar login : \n\n{FF0000}AVISO: Se o seu nome tiver caracteres especiais pode ser exibido como espaço,{FFFFFF} \nMas não se preocupe, isso não afetará o nick digitado", "Continuar", "");
        return 1;
    }
    if(playertextid == PlayerLogin[playerid][10]) // se clicou em senha
    {
        ShowPlayerDialog(playerid, PASS_LOGIN, DIALOG_STYLE_PASSWORD, "{FF0000}Senha", "{FFFFFF}Digite sua senha em baixo para efetuar login : \n\n{FF0000}Sua senha será escondida por *", "Continuar", "");
        return 1;
    }
    if(playertextid == PlayerLogin[playerid][11])
    {
        mysql_format(IDConexao, Query, sizeof(Query), "SELECT * FROM Contas WHERE Nome='%s'", pPlayerInfo[playerid][pNome]);
        mysql_query(IDConexao, Query);

        if(cache_num_rows() > 0)
        {
            mysql_format(IDConexao, Query, sizeof(Query), "SELECT * FROM Contas WHERE Nome='%s' AND Senha='%s'", pPlayerInfo[playerid][pNome], pPlayerInfo[playerid][pSenha]);
        	mysql_query(IDConexao, Query);

            if(cache_num_rows() > 0)
            {
                mysql_format(IDConexao, Query, sizeof(Query), "SELECT * FROM Contas WHERE Nome='%s'", pPlayerInfo[playerid][pNome]);
                mysql_tquery(IDConexao, Query, "CarregarContas", "d", pPlayerInfo[playerid][pNome]);
                CarregarContas(playerid);

            } else {
                ShowPlayerDialog(playerid,0,DIALOG_STYLE_MSGBOX,"{FF0000}Erro","{FFFFFF}Senha errada!","Concluir","");
            }
        } else {
            ShowPlayerDialog(playerid,0,DIALOG_STYLE_MSGBOX,"{FF0000}Erro","{FFFFFF}Conta não registrada!","Concluir","");
        }
        return 1;
    }
    if(playertextid == PlayerLogin[playerid][12]) //registrar
    {
        SkinPlayer[playerid]=0;
        QuebrarLogin(playerid);
        CarregarRegistro(playerid);

        PlayerTextDrawSetString(playerid, PlayerRegistro[playerid][11], SkinList(playerid));
        PlayerTextDrawShow(playerid, PlayerRegistro[playerid][11]);
        return 1;
    }
    if(playertextid == PlayerRegistro[playerid][15]) // <<
    {
        SkinPlayer[playerid]--;

        if(SkinPlayer[playerid] == -1){
        ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}ERRO", "{FFFFFF}Não tem mais skin!", "Concluir", "");
        SkinPlayer[playerid]=0;
        }

        if(SkinPlayer[playerid] == 23){
        SkinPlayer[playerid]=22;
        }

        if(SkinPlayer[playerid] == 211){
        SkinPlayer[playerid]=210;
        }

        if(SkinPlayer[playerid] == 217){
        SkinPlayer[playerid]=216;
        }

        PlayerTextDrawSetString(playerid, PlayerRegistro[playerid][11], SkinList(playerid));
        PlayerTextDrawSetPreviewModel(playerid, PlayerRegistro[playerid][3], SkinPlayer[playerid]);
        PlayerTextDrawShow(playerid, PlayerRegistro[playerid][11]);
        PlayerTextDrawShow(playerid, PlayerRegistro[playerid][3]);
        return 1;
    }
    if(playertextid == PlayerRegistro[playerid][16]) //>>
    {
        SkinPlayer[playerid]++;

        if(SkinPlayer[playerid] == 312){
        ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}ERRO", "{FFFFFF}Não tem mais skin!", "Concluir", "");
        SkinPlayer[playerid]=311;
        }

        if(SkinPlayer[playerid] == 23){
        SkinPlayer[playerid]=24;
        }

        if(SkinPlayer[playerid] == 211){
        SkinPlayer[playerid]=212;
        }

        if(SkinPlayer[playerid] == 217){
        SkinPlayer[playerid]=218;
        }

        PlayerTextDrawSetString(playerid, PlayerRegistro[playerid][11], SkinList(playerid));
        PlayerTextDrawSetPreviewModel(playerid, PlayerRegistro[playerid][3], SkinPlayer[playerid]);
        PlayerTextDrawShow(playerid, PlayerRegistro[playerid][11]);
        PlayerTextDrawShow(playerid, PlayerRegistro[playerid][3]);
        return 1;
    }
    if(playertextid == PlayerRegistro[playerid][17])
    {
        ShowPlayerDialog(playerid, NAME_REGISTER, DIALOG_STYLE_INPUT, "{FF0000}Nome", "{FFFFFF}Digite seu nome em baixo para efetuar o registro : \n\n{FF0000}AVISO: Se o seu nome tiver caracteres especiais pode ser exibido como espaço,{FFFFFF} \nMas não se preocupe, isso não afetará o nick digitado", "Concluir", "");
        return 1;
    }
    if(playertextid == PlayerRegistro[playerid][18])
    {
        ShowPlayerDialog(playerid, PASS_REGISTER, DIALOG_STYLE_PASSWORD, "{FF0000}Senha", "{FFFFFF}Digite sua senha em baixo para efetuar o registro : \n\n{FF0000}Sua senha será escondida por *", "Concluir", "");
        return 1;
    }
    if(playertextid == PlayerRegistro[playerid][19])
    {
        ShowPlayerDialog(playerid, EMAIL_REGISTER, DIALOG_STYLE_INPUT, "{FF0000}E-mail", "{FFFFFF}Digite seu e-mail em baixo para efetuar o registro : \n\n{FF0000}AVISO: Se o seu nome tiver caracteres especiais pode ser exibido como espaço,{FFFFFF} \nMas não se preocupe, isso não afetará o nick digitado", "Concluir", "");
        return 1;
    }
    if(playertextid == PlayerRegistro[playerid][20])
    {
        if(pPlayerInfo[playerid][pNome]==0)
        return ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Erro", "{FFFFFF}Coloque um nome!", "Concluir", "");
        if(pPlayerInfo[playerid][pSenha]==0)
        return ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Erro", "{FFFFFF}Coloque uma senha!", "Concluir", "");
        if(pPlayerInfo[playerid][pEmail]==0)
        return ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Erro", "{FFFFFF}Coloque um e-mail!", "Concluir", "");

        mysql_format(IDConexao, Query, sizeof(Query), "SELECT * FROM Contas WHERE Nome='%s'", pPlayerInfo[playerid][pNome]);
        mysql_query(IDConexao, Query);

        if(!(cache_num_rows() > 0))
        {
            mysql_format(IDConexao, Query, sizeof(Query), "SELECT * FROM Contas WHERE Email='%s'", pPlayerInfo[playerid][pEmail]);
            mysql_query(IDConexao, Query);

            if(!(cache_num_rows() > 0))
            {
                mysql_format(IDConexao, Query, sizeof(Query), "INSERT INTO Contas (Nome, Senha, Email) VALUES ('%s', '%s', '%s')", pPlayerInfo[playerid][pNome], pPlayerInfo[playerid][pSenha], pPlayerInfo[playerid][pEmail]);
                mysql_tquery(IDConexao, Query, "RegistrarContas", "i", playerid);
                RegistrarContas(playerid);

            } else {
                ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Erro", "{FFFFFF}Email já em uso!", "Concluir", "");
            }
        } else {
            ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{FF0000}Erro", "{FFFFFF}Nome já em uso!", "Concluir", "");
        }
        return 1;
    }
    return 1;
}

public OnPlayerClickPlayer(playerid, clickedplayerid, source)
{
	return 1;
}

public OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
{
    if(IsPlayerAjudante(playerid))
    {
        if(IsPlayerInAnyVehicle(playerid))
        {
            SetVehiclePos(GetPlayerVehicleID(playerid),fX,fY,fZ);
            PutPlayerInVehicle(playerid,GetPlayerVehicleID(playerid),GetPlayerVehicleSeat(playerid));
        } else {
            SetPlayerPosFindZ(playerid,fX,fY,fZ);
        }
    }
	return 1;
}

public OnPlayerEditAttachedObject(playerid, response, index, modelid, boneid, Float:fOffsetX, Float:fOffsetY, Float:fOffsetZ, Float:fRotX, Float:fRotY, Float:fRotZ, Float:fScaleX, Float:fScaleY, Float:fScaleZ)
{
    if(response)
    {
        SendClientMessage(playerid, Verde, "Attached object edition saved.");
        ao[playerid][index][ao_x] = fOffsetX;
        ao[playerid][index][ao_y] = fOffsetY;
        ao[playerid][index][ao_z] = fOffsetZ;
        ao[playerid][index][ao_rx] = fRotX;
        ao[playerid][index][ao_ry] = fRotY;
        ao[playerid][index][ao_rz] = fRotZ;
        ao[playerid][index][ao_sx] = fScaleX;
        ao[playerid][index][ao_sy] = fScaleY;
        ao[playerid][index][ao_sz] = fScaleZ;
    } else {
        SendClientMessage(playerid, Vermelho, "Attached object edition not saved.");

        new i = index;
        SetPlayerAttachedObject(playerid, index, modelid, boneid, ao[playerid][i][ao_x], ao[playerid][i][ao_y], ao[playerid][i][ao_z], ao[playerid][i][ao_rx], ao[playerid][i][ao_ry], ao[playerid][i][ao_rz], ao[playerid][i][ao_sx], ao[playerid][i][ao_sy], ao[playerid][i][ao_sz]);
    }
    return 1;
}

forward Respawn1();
public Respawn1()
{
    TextDrawHideForAll(RespawnVeiculos);
    SetTimer("Respawn2", segundos(12), false);
    return 1;
}

forward Respawn2();
public Respawn2()
{
    TextDrawSetString(RespawnVeiculos, "~r~>> ~w~Respawn de veiculos nao usados em ~g~15 ~w~segundos...~r~<<");
    TextDrawShowForAll(RespawnVeiculos);
    SetTimer("Respawn3", segundos(3), false);
    return 1;
}

forward Respawn3();
public Respawn3()
{
    TextDrawHideForAll(RespawnVeiculos);
    SetTimer("CountDown", segundos(7), false);
    return 1;
}

forward CountDown();
public CountDown()
{
    if (Count > 0)
    {
        GameTextForAll(ContadorTxT[Count-1], 2500, 3);
        Count--;
        SetTimer("CountDown", 1000, 0);
    } else {
        TextDrawHideForAll(RespawnVeiculos);
        SendClientMessageToAll(C_Info, "| INFO | Todos os veiculos não em uso foram respawnados!");
        Respawnando=false;
        GameTextForAll("~g~]] ~w~RESPAWNANDO~g~ ]]", 2500, 3);
        Count=5;
        for(new i; i < MAX_VEHICLES; i++)
        {
            if(!IsVehicleInUse(i))
            {
                SetVehicleToRespawn(i);
            }
        }
    }
    return 1;
}

forward GPSUpdate(playerid, playerid2);
public GPSUpdate(playerid, playerid2)
{
    if(IsPlayerConnected(playerid2))
    {
        if(PlayerInfo[playerid2][Preso] <= 0)
        {
           	DisablePlayerCheckpoint(playerid);
            new Float:Distnace = GetDistanceBetweenPlayers(playerid,playerid2);
            GetPlayerPos(playerid2,X,Y,Z);
            SetPlayerCheckpoint(playerid, X,Y,Z, 1.0);
    		if(Distnace <= 3.0)
            {
                DisablePlayerCheckpoint(playerid);
                KillTimer(TimerProcurando[playerid]);
    			localizado[playerid]=0;
    			LocalizarID[playerid]=0;
            }
        } else {
            DisablePlayerCheckpoint(playerid);
            KillTimer(TimerProcurando[playerid]);
    		localizado[playerid]=0;
    		LocalizarID[playerid]=0;
            SendClientMessage(playerid, Verde_Escurinho, "| GPS | O(A) Jogador(a) foi preso!");
        }
    } else {
        DisablePlayerCheckpoint(playerid);
        KillTimer(TimerProcurando[playerid]);
		localizado[playerid]=0;
		LocalizarID[playerid]=0;
        SendClientMessage(playerid, Verde_Escurinho, "| GPS | O(A) Jogador(a) desconectou-se!");
    }
    return 1;
}

forward ProcessGameTime();
public ProcessGameTime()
{
    new Mess[20];
    gettime(Hora, Min);
    getdate(Ano, Mes, Dia);

    if(Mes == 1){
        Mess = "Janeiro";
    } else if(Mes == 2){
        Mess = "Fevereiro";
    } else if(Mes == 3){
        Mess = "Marco";
    } else if(Mes == 4){
        Mess = "Abril";
    } else if(Mes == 5){
        Mess = "Maio";
    } else if(Mes == 6){
        Mess = "Junho";
    } else if(Mes == 7){
        Mess = "Julho";
    } else if(Mes == 8){
        Mess = "Agosto";
    } else if(Mes == 9){
        Mess = "Setembro";
    } else if(Mes == 10){
        Mess = "Outubro";
    } else if(Mes == 11){
        Mess = "Novembro";
    } else if(Mes == 12){
        Mess = "Dezembro";
    }

    if(Hora == 24){
        SetWorldTime(0), Hora=0;
    } else if(Hora == 1){
        SetWorldTime(1);
    } else if(Hora == 2){
        SetWorldTime(2);
    } else if(Hora == 3){
        SetWorldTime(3);
    } else if(Hora == 4){
        SetWorldTime(4);
    } else if(Hora == 5){
        SetWorldTime(5);
    } else if(Hora == 6){
        SetWorldTime(6);
    } else if(Hora == 7){
        SetWorldTime(7);
    } else if(Hora == 8){
        SetWorldTime(8);
    } else if(Hora == 9){
        SetWorldTime(9);
    } else if(Hora == 10){
        SetWorldTime(10);
    } else if(Hora == 11){
        SetWorldTime(11);
    } else if(Hora == 12){
        SetWorldTime(12);
    } else if(Hora == 13){
        SetWorldTime(13);
    } else if(Hora == 14){
        SetWorldTime(14);
    } else if(Hora == 15){
        SetWorldTime(15);
    } else if(Hora == 16){
        SetWorldTime(16);
    } else if(Hora == 17){
        SetWorldTime(20);
    } else if(Hora == 18){
        SetWorldTime(21);
    } else if(Hora == 19){
        SetWorldTime(22);
    } else if(Hora == 20){
        SetWorldTime(23);
    } else if(Hora == 21){
        SetWorldTime(24);
    } else if(Hora == 22){
        SetWorldTime(25);
    } else if(Hora == 23){
        SetWorldTime(26);
    }

    format(String, sizeof String, "%02d:%02d", Hora+1, Min);
    TextDrawSetString(txtTimeDisp, String);
    format(String, sizeof String, "%02d_de_%s_de_%02d", Dia, Mess, Ano);
    TextDrawSetString(txtDateDisp, String);
    return 1;
}

forward Kicka(p);
public Kicka(p) {
    #undef Kick
    Kick(p);
    #define Kick(%0) SetTimerEx("Kicka", 100, false, "i", %0)
    return 1;
}

forward Bana(p);
public Bana(p) {
    #undef Ban
    Ban(p);
    #define Ban(%0) SetTimerEx("Bana", 100, false, "i", %0)
    return 1;
}

forward AbrindoPortaPolicia(playerid);
public AbrindoPortaPolicia(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 246.39900,72.49900,1003.85809))
    {
        MoveObject(PortaPolicia,246.39900,72.49900,1007.10938,3.0);
        SetTimerEx("FechandoPortaPolicia", segundos(5), false, "i", playerid);
        SendClientMessage(playerid, Verde_Escurinho, "| INFO | O Portão do Departamento de Policia foi aberto e fechara em 5 segundos");
    }
    return 1;
}

forward FechandoPortaPolicia(playerid);
public FechandoPortaPolicia(playerid)
{
    MoveObject(PortaPolicia,246.39900,72.49900,1003.85809,3.0);
    return 1;
}

forward ProxDetector(Float:radi, playerid, string[], col1, col2, col3, col4, col5);
public ProxDetector(Float:radi, playerid, string[], col1, col2, col3, col4, col5)
{
    if(IsPlayerConnected(playerid)){
        new Float:posx, Float:posy, Float:posz;
        new Float:oldposx, Float:oldposy, Float:oldposz;
        new Float:tempposx, Float:tempposy, Float:tempposz;
        GetPlayerPos(playerid, oldposx, oldposy, oldposz);
        for(new i = 0; i < MAX_PLAYERS; i++){
            if(IsPlayerConnected(i)){
                GetPlayerPos(i, posx, posy, posz);
                tempposx = (oldposx -posx);
                tempposy = (oldposy -posy);
                tempposz = (oldposz -posz);
                if (((tempposx < radi/16) && (tempposx > -radi/16)) && ((tempposy < radi/16) && (tempposy > -radi/16)) && ((tempposz < radi/16) && (tempposz > -radi/16))) {
                    SendClientMessage(i, col1, string);
                } else if (((tempposx < radi/8) && (tempposx > -radi/8)) && ((tempposy < radi/8) && (tempposy > -radi/8)) && ((tempposz < radi/8) && (tempposz > -radi/8))) {
                    SendClientMessage(i, col2, string);
                } else if (((tempposx < radi/4) && (tempposx > -radi/4)) && ((tempposy < radi/4) && (tempposy > -radi/4)) && ((tempposz < radi/4) && (tempposz > -radi/4))) {
                    SendClientMessage(i, col3, string);
                } else if (((tempposx < radi/2) && (tempposx > -radi/2)) && ((tempposy < radi/2) && (tempposy > -radi/2)) && ((tempposz < radi/2) && (tempposz > -radi/2))) {
                    SendClientMessage(i, col4, string);
                } else if (((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi))) {
                    SendClientMessage(i, col5, string);
                }
            }
        }
    }
    return 1;
}

forward TimerTextoTela(playerid);
public TimerTextoTela(playerid)
{
    TextDrawHideForPlayer(playerid, RespawnVeiculos);
    return 1;
}

forward RandomMSGs(COLOR, const string[]);
public RandomMSGs(COLOR, const string[])
{
    new random1 = random(sizeof(MSGs));
    format(String, sizeof(String), "%s", MSGs[random1]);
    return SendClientMessageToAll(COLOR,String);
}

forward ChatAdmin(COLOR, const string[]);
public ChatAdmin(COLOR, const string[])
{
    foreach(Player, i)
    {
        if(PlayerInfo[i][Admin]==1 || PlayerInfo[i][Admin]==2 || PlayerInfo[i][Admin]==3 || PlayerInfo[i][Admin]==4 || PlayerInfo[i][Admin]==5)
        {
            SendClientMessage(i, COLOR, string);
        }
    }
    return 1;
}

forward ChatVIP(COLOR, const string[]);
public ChatVIP(COLOR, const string[])
{
    foreach(Player, i)
    {
        if(PlayerInfo[i][Admin] ==1||PlayerInfo[i][Admin]==2||PlayerInfo[i][Admin]==3||PlayerInfo[i][Admin]==4|| PlayerInfo[i][Admin]==5||PlayerInfo[i][Vip]==1)
        {
            SendClientMessage(i, COLOR, string);
        }
    }
    return 1;
}

forward LiberouRelatorio(playerid);
public LiberouRelatorio(playerid)
{
    LiberarRelatorio{playerid} = false;
    return true;
}

forward LiberouDuvida(playerid);
public LiberouDuvida(playerid)
{
    LiberarDuvida{playerid} = false;
    return true;
}

forward Relatorio(COLOR, const string[]);
public Relatorio(COLOR, const string[])
{
    foreach(Player, i)
    {
        if(PlayerInfo[i][Admin]==1 || PlayerInfo[i][Admin]==2 || PlayerInfo[i][Admin]==3 || PlayerInfo[i][Admin]==4 || PlayerInfo[i][Admin]==5)
        {
            SendClientMessage(i, COLOR, String);
            GameTextForPlayer(i, "~n~~r~RELATORIO" , 3000, 3);
            PlayerPlaySound(i,1057,0,0,0);
        }
    }
    return 1;
}

forward Duvida(COLOR, const string[]);
public Duvida(COLOR, const string[])
{
    foreach(Player, i)
    {
        if(PlayerInfo[i][Admin]==1 || PlayerInfo[i][Admin]==2 || PlayerInfo[i][Admin]==3 || PlayerInfo[i][Admin]==4 || PlayerInfo[i][Admin]==5)
        {
            SendClientMessage(i, COLOR, String);
            GameTextForPlayer(i, "~n~~b~DUVIDA" , 3000, 3);
            PlayerPlaySound(i, 1057,0,0,0);
        }
    }
    return 1;
}

forward RespondendoDuvidaOuRelatorio(COLOR, const string[]);
public RespondendoDuvidaOuRelatorio(COLOR, const string[])
{
    foreach(Player, i)
    {
        if(TemDuvidaOuRelatorio[i] == true)
        {
            SendClientMessage(i, COLOR, String);
            GameTextForPlayer(i, "~n~~b~DUVIDA" , 3000, 3);
            PlayerPlaySound(i, 1057,0,0,0);
        }
    }
    return 1;
}

forward MSGCorregedoria(COLOR, const string[]);
public MSGCorregedoria(COLOR, const string[])
{
    foreach(Player, i)
    {
        if(PlayerInfo[i][Profissao] == Corregedoria)
        {
            SendClientMessage(i, COLOR, string);
        }
    }
    return 1;
}

forward limparchat(playerid);
public limparchat(playerid)
{
    for(new h=0; h < 20; h++)
    {
        SendClientMessage(playerid, -1, " ");
        h++;
    }
    return 1;
}

forward CarregarContas(playerid);
public CarregarContas(playerid)
{
    cache_get_value_int(0, "ID", PlayerInfo[playerid][ID]);
    cache_get_value_int(0, "IP", PlayerInfo[playerid][IP]);
    cache_get_value_int(0, "Profissao", PlayerInfo[playerid][Profissao]);
    cache_get_value_name(0, "Nome", PlayerInfo[playerid][Nome]);
    cache_get_value_name(0, "Senha", PlayerInfo[playerid][Senha]);
    cache_get_value_name(0, "Email", PlayerInfo[playerid][Email]);
    cache_get_value_int(0, "Admin", PlayerInfo[playerid][Admin]);
    cache_get_value_int(0, "minUP", PlayerInfo[playerid][minUP]);
    cache_get_value_int(0, "segUP", PlayerInfo[playerid][segUP]);
    cache_get_value_int(0, "Level", PlayerInfo[playerid][Level]);
    cache_get_value_int(0, "Exp", PlayerInfo[playerid][Exp]);
    cache_get_value_int(0, "Coins", PlayerInfo[playerid][Coins]);
    cache_get_value_int(0, "Vip", PlayerInfo[playerid][Vip]);
    cache_get_value_int(0, "CorVIP", PlayerInfo[playerid][CorVIP]);
    cache_get_value_int(0, "Skin", PlayerInfo[playerid][Skin]);
    cache_get_value_int(0, "Dinheiro", PlayerInfo[playerid][Dinheiro]);
    cache_get_value_int(0, "Banco", PlayerInfo[playerid][Banco]);
    cache_get_value_int(0, "Matou", PlayerInfo[playerid][Matou]);
    cache_get_value_int(0, "Morreu", PlayerInfo[playerid][Morreu]);
    cache_get_value_int(0, "Interior", PlayerInfo[playerid][Interior]);
    cache_get_value_int(0, "Preso", PlayerInfo[playerid][Preso]);
    cache_get_value_float(0, "PosX", PlayerInfo[playerid][PosX]);
    cache_get_value_float(0, "PosY", PlayerInfo[playerid][PosY]);
    cache_get_value_float(0, "PosZ", PlayerInfo[playerid][PosZ]);
    cache_get_value_float(0, "PosA", PlayerInfo[playerid][PosA]);

    SendClientMessage(playerid, Verde, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    MessageFormat(playerid, Branco, "» Logado com sucesso {008040}%s{FFFFFF}!", pPlayerInfo[playerid][pNome]);
    SendClientMessage(playerid, Verde, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    TogglePlayerSpectating(playerid, false);
    PlayerInfo[playerid][Logado] = true;

    SetPlayerName(playerid, pPlayerInfo[playerid][pNome]);
    SetPlayerScore(playerid, PlayerInfo[playerid][Level]);
    GivePlayerMoney(playerid, PlayerInfo[playerid][Dinheiro]);
    SetSpawnInfo(playerid,0,PlayerInfo[playerid][Skin],
    PlayerInfo[playerid][PosX],PlayerInfo[playerid][PosY],
    PlayerInfo[playerid][PosZ],PlayerInfo[playerid][PosA],0,0,0,0,0,0);
    Logarprof(playerid);
    QuebrarLogin(playerid);
    SpawnPlayer(playerid);
    VerificarCadeia(playerid);
    return 1;
}

forward RegistrarContas(playerid);
public RegistrarContas(playerid)
{
    PlayerInfo[playerid][ID]=cache_insert_id();
    PlayerInfo[playerid][Skin]=SkinPlayer[playerid];
    PlayerInfo[playerid][Logado]=true;
    TogglePlayerSpectating(playerid, false);

    SetPlayerName(playerid, pPlayerInfo[playerid][pNome]);
    SetPlayerScore(playerid, PlayerInfo[playerid][Level]);
    GivePlayerMoney(playerid, PlayerInfo[playerid][Dinheiro]);
    SetSpawnInfo(playerid,0,SkinPlayer[playerid],816.2747,-1343.7556,13.5289,1.8391,0,0,0,0,0,0);
    QuebrarRegistro(playerid);
    Logarprof(playerid);
    SpawnPlayer(playerid);
    return 1;
}

forward RelogioUP(playerid);
public RelogioUP(playerid)
{
    if(PlayerInfo[playerid][segUP]== 0 && PlayerInfo[playerid][minUP] == 0)
    {
        if(PlayerInfo[playerid][Logado] == true)
        {
            if(PlayerInfo[playerid][Afk] == false)
            {
                //dini_IntSet(file, "Tempo", dini_Int(file, "Tempo")+1);
                //====== [EXP] ======
                if(PlayerInfo[playerid][Exp] == 4)
                {
                    PlayerInfo[playerid][Level]++;
                    PlayerInfo[playerid][Exp] = 0;
                    format(String, sizeof(String), "| UP | Você juntou 5 de Experiência e ganhou +1 level ( %d ) ",PlayerInfo[playerid][Level]);
                    SendClientMessage(playerid, 0x75EA00AA, String);
                    PlayerPlaySound(playerid, 1057, 0, 0, 0);
                } else {
                    PlayerInfo[playerid][Exp]++;
                    format(String, sizeof(String), "| UP | Você ganhou +1 de Experiência ( %d/5 )",PlayerInfo[playerid][Exp]);
                    PlayerPlaySound(playerid, 1057, 0, 0, 0);
                    GameTextForPlayer(playerid, "~w~UP!", 3000, 6);
                    SendClientMessage(playerid, 0x75EA00AA, String);
                }
            }
        }
    }

    if(PlayerInfo[playerid][segUP]==-1)
    {
        if(PlayerInfo[playerid][minUP]==0)
        PlayerInfo[playerid][minUP]=10;
        PlayerInfo[playerid][segUP]=59;
        PlayerInfo[playerid][minUP]--;
    }
    format(String, sizeof(String), "~w~+~b~UP: ~w~%02d:%02d", PlayerInfo[playerid][minUP],PlayerInfo[playerid][segUP]);
    PlayerTextDrawSetString(playerid, PlayerStatus[playerid][20], String);
    PlayerInfo[playerid][segUP]--;
    return 1;
}

forward CarregarInterior(playerid);
public CarregarInterior(playerid)
{
    TogglePlayerControllable(playerid, 1);
    PlayerTextDrawHide(playerid, CarregandoInterior[playerid]);
    return 1;
}

forward Logarprof(playerid);
public Logarprof(playerid)
{
    if(PlayerInfo[playerid][Profissao]==Desempregado)
    return SetPlayerColor(playerid,C_Desempregado);
    else if(PlayerInfo[playerid][Profissao]==EntregadorJornal)
    return SetPlayerColor(playerid,C_EntregadorJornal);
    else if(PlayerInfo[playerid][Profissao]==Taxi)
    return SetPlayerColor(playerid,C_Taxi);
    else if(PlayerInfo[playerid][Profissao]==Policia_Civil)
    return SetPlayerColor(playerid,C_Policia_Civil);
    else if(PlayerInfo[playerid][Profissao]==Corregedoria)
    return SetPlayerColor(playerid,C_Corregedoria);
    else if(PlayerInfo[playerid][Profissao]==Ladrao_de_Gas)
    return SetPlayerColor(playerid,C_Ladrao_de_Gas);
    return 1;
}

forward AtualizarTagBubble(playerid);
public AtualizarTagBubble(playerid)
{
    if(PlayerInfo[playerid][Admin] == 5)
    {
        SetPlayerChatBubble(playerid, "Staff", 0x328E0AAA, 100.0, 100000);
    }
    if(PlayerInfo[playerid][Admin] == 4)
    {
        SetPlayerChatBubble(playerid, "Sub-Staff", 0xFF0000AA, 100.0, 100000);
    }
    if(PlayerInfo[playerid][Admin] == 3)
    {
        SetPlayerChatBubble(playerid, "Administrador(a)", 0x008bceAA, 100.0, 100000);
    }
    if(PlayerInfo[playerid][Admin] == 2)
    {
        SetPlayerChatBubble(playerid, "Moderador(a)", 0xFF8C00AA, 100.0, 100000);
    }
    if(PlayerInfo[playerid][Admin] == 1)
    {
        SetPlayerChatBubble(playerid, "Ajudante", 0xFFFF00AA, 100.0, 100000);
    }
    if(PlayerInfo[playerid][Vip] == 1)
    {
        if(PlayerInfo[playerid][CorVIP]==0){
            format(String, sizeof(String), "{FFFFFF}[{FFFFFF}VIP{FFFFFF}]", PlayerInfo[playerid][CorVIP]);
            SetPlayerChatBubble(playerid, String, GetPlayerColor(playerid), 100.0, 100000);
        } else if(PlayerInfo[playerid][CorVIP]==1){
            format(String, sizeof(String), "{FFFFFF}[{FF0000}VIP{FFFFFF}]", PlayerInfo[playerid][CorVIP]);
            SetPlayerChatBubble(playerid, String, GetPlayerColor(playerid), 100.0, 100000);
        } else if(PlayerInfo[playerid][CorVIP]==2){
            format(String, sizeof(String), "{FFFFFF}[{00FF00}VIP{FFFFFF}]", PlayerInfo[playerid][CorVIP]);
            SetPlayerChatBubble(playerid, String, GetPlayerColor(playerid), 100.0, 100000);
        } else if(PlayerInfo[playerid][CorVIP]==3){
            format(String, sizeof(String), "{FFFFFF}[{0000FF}VIP{FFFFFF}]", PlayerInfo[playerid][CorVIP]);
            SetPlayerChatBubble(playerid, String, GetPlayerColor(playerid), 100.0, 100000);
        } else if(PlayerInfo[playerid][CorVIP]==4){
            format(String, sizeof(String), "{FFFFFF}[{FFFF00}VIP{FFFFFF}]", PlayerInfo[playerid][CorVIP]);
            SetPlayerChatBubble(playerid, String, GetPlayerColor(playerid), 100.0, 100000);
        } else if(PlayerInfo[playerid][CorVIP]==5){
            format(String, sizeof(String), "{FFFFFF}[{FF00FF}VIP{FFFFFF}]", PlayerInfo[playerid][CorVIP]);
            SetPlayerChatBubble(playerid, String, GetPlayerColor(playerid), 100.0, 100000);
        } else if(PlayerInfo[playerid][CorVIP]==6){
            format(String, sizeof(String), "{FFFFFF}[{00FFFF}VIP{FFFFFF}]", PlayerInfo[playerid][CorVIP]);
            SetPlayerChatBubble(playerid, String, GetPlayerColor(playerid), 100.0, 100000);
        } else if(PlayerInfo[playerid][CorVIP]==7){
            format(String, sizeof(String), "{FFFFFF}[{FF00FF}VIP{FFFFFF}]", PlayerInfo[playerid][CorVIP]);
            SetPlayerChatBubble(playerid, String, GetPlayerColor(playerid), 100.0, 100000);
        }
    }
}

forward ReiniciandoServer(playerid);
public ReiniciandoServer(playerid)
{
    SendClientMessageToAll(0xB9FFFFAA, "| INFO | O Server reiniciara em 1 minuto !");
    return SetTimer("ReiniciandoServer2", 60000, false);

}

forward ReiniciandoServer2(playerid);
public ReiniciandoServer2(playerid)
{
    for(new i; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerConnected(i))
        {
            SendClientMessageToAll(0xB9FFFFAA, "| INFO | O Server reinicio aguarde!");
            SalvarContas(i);
            Kick(i);
            return SendRconCommand("gmx");
    	}
	}
    return 1;
}

forward SistemaPresidio(playerid);
public SistemaPresidio(playerid)
{
    if(PlayerInfo[playerid][Preso] < 1)
    {
        PlayerTextDrawHide(playerid,PlayerPreso[playerid][2]);
        PlayerTextDrawHide(playerid,PlayerPreso[playerid][1]);
        PlayerTextDrawHide(playerid,PlayerPreso[playerid][0]);
        PlayerTextDrawShow(playerid,PlayerStatus[playerid][20]);
        KillTimer(TempoPreso[playerid]);
        UPRelogio[playerid] = SetTimerEx("RelogioUP",segundos(1),true,"i",playerid);
        PlayerInfo[playerid][Preso]=0;
        PlayerInfo[playerid][Logado]=true;
        GameTextForPlayer(playerid, "~w~SOLTO!", 3000, 0 );
        SendClientMessage(playerid,0xA9C4E4AA, "| INFO | Você cumpriu sua pena e está livre novamente!");
        SetPlayerPos(playerid,1551.6987,-1675.3806,15.9631);
        SetPlayerInterior(playerid, 0);
        SetPlayerHealth(playerid, 100);

    } else if(PlayerInfo[playerid][Preso] > 0){

        PlayerInfo[playerid][Preso]--;
        TempoPreso[playerid] = SetTimerEx("SistemaPresidio",segundos(1),false,"d",playerid);
        formatSeconds(PlayerInfo[playerid][Preso], Hora, Min, Seg);
        format(String,sizeof(String),"PRESO : %02d:%02d:%02d", Hora, Min, Seg);
        PlayerTextDrawSetString(playerid,PlayerPreso[playerid][2], String);
        PlayerTextDrawSetString(playerid,PlayerStatus[playerid][20], "~w~+~b~UP: ~w~Pausado");
        PlayerTextDrawShow(playerid,PlayerStatus[playerid][20]);
        PlayerTextDrawShow(playerid,PlayerPreso[playerid][2]);
    }
    return 1;
}

SalvarContas(playerid)
{
    GetPlayerFacingAngle(playerid, PlayerInfo[playerid][PosA]);
    GetPlayerPos(playerid, PlayerInfo[playerid][PosX],
    PlayerInfo[playerid][PosY],PlayerInfo[playerid][PosZ]);
    PlayerInfo[playerid][IP] = GetPlayerIp(playerid, IPP, sizeof(IPP));

    //PlayerInfo[playerid][minUP] = dini_Int(file, "Relogioupm"); //RELOGIO UP
    //PlayerInfo[playerid][segUP]= dini_Int(file, "Relogioups");

    mysql_format(IDConexao, Query, sizeof(Query), "UPDATE Contas SET Profissao=%d, IP=%d, Admin=%d, minUP=%d, segUP=%d, Level=%d, Exp=%d, Coins=%d, Vip=%d, CorVIP=%d, Skin=%d, Aviso=%d, Dinheiro=%d, Banco=%d, Matou=%d, Morreu=%d, Interior=%d, Preso=%d, PosX=%f, PosY=%f, PosZ=%f, PosA=%f WHERE ID=%d",
    PlayerInfo[playerid][Profissao],
    PlayerInfo[playerid][IP],
    PlayerInfo[playerid][Admin],
    PlayerInfo[playerid][minUP],
    PlayerInfo[playerid][segUP],
    PlayerInfo[playerid][Level],
    PlayerInfo[playerid][Exp],
    PlayerInfo[playerid][Coins],
    PlayerInfo[playerid][Vip],
    PlayerInfo[playerid][CorVIP],
    PlayerInfo[playerid][Skin],
    PlayerInfo[playerid][Avisos],
    PlayerInfo[playerid][Dinheiro],
    PlayerInfo[playerid][Banco],
    PlayerInfo[playerid][Matou],
    PlayerInfo[playerid][Morreu],
    PlayerInfo[playerid][Interior],
    PlayerInfo[playerid][Preso],
    PlayerInfo[playerid][PosX],
    PlayerInfo[playerid][PosY],
    PlayerInfo[playerid][PosZ],
    PlayerInfo[playerid][PosA],
    PlayerInfo[playerid][ID]);
    mysql_query(IDConexao, Query);
    return 1;
}

VerificarCadeia(playerid)
{
    if(PlayerInfo[playerid][Preso] > 0)
    {
        KillTimer(UPRelogio[playerid]);
        PlayerTextDrawShow(playerid, PlayerPreso[playerid][1]);
        PlayerTextDrawShow(playerid, PlayerPreso[playerid][0]);
        SetPlayerPos(id, 223.5335,110.3779,999.0156);
        SetPlayerHealth(id, 99999);
        SetPlayerInterior(id, 10);
        ResetPlayerWeapons(id);
        SistemaPresidio(playerid);
    }
    return 1;
}

IsVehicleInUse(vehicleid)
{
    new VeiculoRcd;
    for(new i; i < MAX_PLAYERS; i++)
    {
        if(GetPlayerVehicleID(i) == vehicleid)
            VeiculoRcd = vehicleid;
        if(GetVehicleTrailer(GetPlayerVehicleID(i)) == vehicleid)
            VeiculoRcd = vehicleid;
    }
    return VeiculoRcd;
}

GetPlayerHighestScores(array[][rankingEnum], left, right)
{
    new tempLeft = left, tempRight = right,
        pivot = array[(left + right) / 2][player_Score], tempVar;

    while(tempLeft <= tempRight)
    {
        while(array[tempLeft][player_Score] > pivot) tempLeft++;
        while(array[tempRight][player_Score] < pivot) tempRight--;

        if(tempLeft <= tempRight)
        {
            tempVar = array[tempLeft][player_Score], array[tempLeft][player_Score] = array[tempRight][player_Score], array[tempRight][player_Score] = tempVar;
            tempVar = array[tempLeft][player_ID], array[tempLeft][player_ID] = array[tempRight][player_ID], array[tempRight][player_ID] = tempVar;
            tempLeft++, tempRight--;
        }
    }
    if(left < tempRight) GetPlayerHighestScores(array, left, tempRight);
    if(tempLeft < right) GetPlayerHighestScores(array, tempLeft, right);
}

stock GetPlayer2DZone(playerid, zoneada[], len)
{
    new Float:x,Float:y,Float:z;
    GetPlayerPos(playerid, x, y, z);
    for(new i = 0; i != sizeof(gSAZones); i++)
    {
        if(x >= gSAZones[i][SAZONE_AREA][0] && x <= gSAZones[i][SAZONE_AREA][3] && y >= gSAZones[i][SAZONE_AREA][1] && y <= gSAZones[i][SAZONE_AREA][4])
        {
            return format(zoneada, len, gSAZones[i][SAZONE_NAME], 0);
        }
    }
    return 0;
}

IsPlayerInLs(playerid)
{
    new Float:x,Float:y,Float:z;
    GetPlayerPos(playerid, x, y, z);
    if(x >= -735.7062 && y >= -2954.502 && x <= 2931.147 && y <= 373.692) return 1;
    else return 0;
}

IsPlayerInLv(playerid)
{
    new Float:x,Float:y,Float:z;
    GetPlayerPos(playerid, x, y, z);
    if(x >= 852.4849 && y >= 490.4708 && x <= 2931.147 && y <= 2896.113) return 1;
    else return 0;
}

IsPlayerInFc(playerid)
{
    new Float:x,Float:y,Float:z;
    GetPlayerPos(playerid, x, y, z);
    if(x >= -1167.788 && y >= 502.1487 && x <= 922.5522 && y <= 2942.825) return 1;
    else return 0;
}

IsPlayerInSf(playerid)
{
    new Float:x,Float:y,Float:z;
    GetPlayerPos(playerid, x, y, z);
    if(x >= -2942.825 && y >= -2931.147 && x <= -992.6194 && y <= 2931.147) return 1;
    else return 0;
}

IsPlayerInMc(playerid)
{
    new Float:x,Float:y,Float:z;
    GetPlayerPos(playerid, x, y, z);
    if(x >= -2202.3843 && y >= -2292.3999 && x <= 30.6250 && y <= 321.0372) return 1;
    else return 0;
}

DeletarSair(playerid)
{
    if(cVehicle[playerid])
    {
        DestroyVehicle(GetPlayerVehicleID(playerid));
        cVehicle[playerid] = false;
        return 1;
    }
    return 1;
}

strtok(const string[], &index)
{
    new length = strlen(string);
    while ((index < length) && (string[index] <= ' '))
    {
        index++;
    }

    new offset = index;
    new result[20];
    while ((index < length) && (string[index] > ' ') && ((index - offset) < (sizeof(result) - 1)))
    {
        result[index - offset] = string[index];
        index++;
    }
    result[index - offset] = EOS;
    return result;
}

strrest(const string[], &index)
{
	new length = strlen(string);
	while ((index < length) && (string[index] <= ' '))
	{
		index++;
	}
	new offset = index;
	new result[128];
	while ((index < length) && ((index - offset) < (sizeof(result) - 1)))
	{
		result[index - offset] = string[index];
		index++;
	}
	result[index - offset] = EOS;
	return result;
}

ConverterDias(playerid, dias)
{
	if(PlayerInfo[playerid][Vip] < 1)
    {
        PlayerInfo[playerid][Vencimento]=(gettime() + (dias * 86400));
	} else {
		PlayerInfo[playerid][Vencimento]=PlayerInfo[playerid][Vencimento]+(dias * 86400);
	}
	return 1;
}

GetProfissao(playerid)
{
    new var[30];
    switch(PlayerInfo[playerid][Semprofissao])
    {
        case 0: var = "Desempregado(a)";
        case 1: var = "Entregador(a) de Jornal";
        case 2: var = "Taxi";
        case 3: var = "Policia";
        case 4: var = "Corregedoria";
        case 5: var = "Ladrão de Gás";
    }
    return var;
}

CargoAdmin(playerid)
{
    new var[21];
    switch(PlayerInfo[playerid][Admin])
    {
        case 1: var = "Ajudante";
        case 2: var = "Moderador(a)";
        case 3: var = "Administrador(a)";
        case 4: var = "Sub-Staff";
        case 5: var = "Staff";
    }
    return var;
}

PlayerName(playerid)
{
    static pName[MAX_PLAYER_NAME];
    GetPlayerName(playerid, pName, sizeof(pName));
    return pName;
}

EntrarInterior(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1154.0808,-1771.9812,16.5992)) //Agencia LS
    {
        entrando[playerid]=1;
        SetPlayerPos(playerid,1494.4989,1303.6678,1093.2964);
        SetPlayerFacingAngle(playerid, 359.9018);
        SetPlayerInterior(playerid, 3);
        TogglePlayerControllable(playerid, 0);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 937.8450,1733.1957,8.8516))    //Agencia LV
    {
        entrando[playerid]=2;
        SetPlayerPos(playerid,1494.4989,1303.6678,1093.2964);
        SetPlayerFacingAngle(playerid, 359.9018);
        SetPlayerInterior(playerid, 3);
        TogglePlayerControllable(playerid, 0);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -2171.8110,252.0813,35.3378))  //Agencia SF
    {
        entrando[playerid]=3;
        SetPlayerPos(playerid,1494.4989,1303.6678,1093.2964);
        SetPlayerFacingAngle(playerid, 359.9018);
        SetPlayerInterior(playerid, 3);
        TogglePlayerControllable(playerid, 0);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1481.0637,-1770.9515,18.7958)) //Prefeitura LS
    {
        entrando[playerid]=1;
        SetPlayerInterior(playerid, 3);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 384.808624,173.804992,1008.382812);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2447.0620,2376.2354,12.1635))  //Prefeitura LV
    {
        entrando[playerid]=2;
        SetPlayerInterior(playerid, 3);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 384.808624,173.804992,1008.382812);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -2765.8796,375.5812,6.3347))   //Prefeitura SF
    {
        entrando[playerid]=3;
        SetPlayerInterior(playerid, 3);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 384.808624,173.804992,1008.382812);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1554.8657,-1675.6693,16.1953)) // Departamento LS
    {
        entrando[playerid]=1;
        SetPlayerInterior(playerid, 6);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 246.8748,63.0608,1003.6406);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2290.1218,2430.9775,10.8203))  // Departamento LV
    {
        entrando[playerid]=2;
        SetPlayerInterior(playerid, 6);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 246.8748,63.0608,1003.6406);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -1605.5848,710.8436,13.8672))  // Departamento SF
    {
        entrando[playerid]=3;
        SetPlayerInterior(playerid, 6);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 246.8748,63.0608,1003.6406);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 627.7621,-571.7207,17.5526))  // Departamento DM
    {
        entrando[playerid]=4;
        SetPlayerInterior(playerid, 6);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 246.8748,63.0608,1003.6406);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1172.6787,-1323.3129,15.4022)) // Hospital LS
    {
        entrando[playerid]=1;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 1104.6949,1515.8959,4452.8071);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1607.3579,1815.6309,10.8203))  // Hospital LV
    {
        entrando[playerid]=2;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 1104.6949,1515.8959,4452.8071);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -2655.0662,639.1497,14.4531))  // Hospital SF
    {
        entrando[playerid]=3;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 1104.6949,1515.8959,4452.8071);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -1514.8217,2520.3232,55.9185))  // Hospital EL
    {
        entrando[playerid]=4;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 1104.6949,1515.8959,4452.8071);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1241.8073,327.1022,19.7555))  // Hospital MG
    {
        entrando[playerid]=5;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 1104.6949,1515.8959,4452.8071);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -320.0716,1049.2637,20.3403))  // Hospital FC
    {
        entrando[playerid]=6;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 1104.6949,1515.8959,4452.8071);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1778.3052,-1663.5337,14.4362)) // Banco LS
    {
        entrando[playerid]=1;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 2315.952880,-1.618174,26.742187);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2388.6733,2466.0430,10.8203))  // Banco LV
    {
        entrando[playerid]=2;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 2315.952880,-1.618174,26.742187);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -2649.8374,376.0090,6.1563))   // Banco SF
    {
        entrando[playerid]=3;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 2315.952880,-1.618174,26.742187);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -180.3883,1133.1510,19.7422))  // Banco FC
    {
        entrando[playerid]=4;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 2315.952880,-1.618174,26.742187);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1372.9271,405.2487,19.9555))   // Banco MG
    {
        entrando[playerid]=5;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 2315.952880,-1.618174,26.742187);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2302.9521,-16.2789,26.4844))   // Banco PC
    {
        entrando[playerid]=6;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 2315.952880,-1.618174,26.742187);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -828.0650,1503.6166,19.7585))  // Banco LB
    {
        entrando[playerid]=7;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 2315.952880,-1.618174,26.742187);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -1480.8273,2592.3015,55.8359)) // Banco EQ
    {
        entrando[playerid]=8;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 2315.952880,-1.618174,26.742187);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 207.7767,-62.5814,1.6498))     // Banco BB
    {
        entrando[playerid]=9;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 2315.952880,-1.618174,26.742187);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1798.4763,-1578.3191,14.0849)) // Imobiliaria LS
    {
        entrando[playerid]=1;
        //SetPlayerInterior(playerid, 3);
        TogglePlayerControllable(playerid, 0);
        //SetPlayerPos(playerid, 1038.531372,0.111030,1001.284484);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2413.2390,1123.8374,10.8203))  // Imobiliaria LV
    {
        entrando[playerid]=2;
        //SetPlayerInterior(playerid, 3);
        TogglePlayerControllable(playerid, 0);
        //SetPlayerPos(playerid, 1038.531372,0.111030,1001.284484);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -1881.1293,822.7573,35.1773))  // Imobiliaria SF
    {
        entrando[playerid]=3;
        //SetPlayerInterior(playerid, 3);
        TogglePlayerControllable(playerid, 0);
        //SetPlayerPos(playerid, 1038.531372,0.111030,1001.284484);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1519.0413,-1453.5895,14.2073)) // Auto Escola LS
    {
        entrando[playerid]=1;
        SetPlayerInterior(playerid, 3);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, -2029.798339,-106.675910,1035.171875);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2183.2483,2295.2205,10.8203))  // Auto Escola LV
    {
        entrando[playerid]=2;
        SetPlayerInterior(playerid, 3);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, -2029.798339,-106.675910,1035.171875);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -2026.5950,-101.3410,35.1641)) // Auto Escola SF
    {
        entrando[playerid]=3;
        SetPlayerInterior(playerid, 3);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, -2029.798339,-106.675910,1035.171875);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1310.1411,-1367.8086,13.5408)) // Detran LS
    {
        entrando[playerid]=1;
        SetPlayerInterior(playerid, 3);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 833.269775,10.588416,1004.179687);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1173.1600,1349.0011,10.9219))  // Detran LV
    {
        entrando[playerid]=2;
        SetPlayerInterior(playerid, 3);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 833.269775,10.588416,1004.179687);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -2720.6375,127.7373,7.0391))   // Detran SF
    {
        entrando[playerid]=3;
        SetPlayerInterior(playerid, 3);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 833.269775,10.588416,1004.179687);
        PlayerTextDrawShow(playerid, CarregandoInterior[playerid]);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    return 1;
}

SairInterior(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1494.4989,1303.6678,1093.2964) && entrando[playerid]==1)         //Agencia LS
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid,1154.0808,-1771.9812,16.5992);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1494.4989,1303.6678,1093.2964) && entrando[playerid]==2)       //Agencia LV
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid,937.8450,1733.1957,8.8516);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1494.4989,1303.6678,1093.2964) && entrando[playerid]==3)       //Agencia SF
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid,-2171.8110,252.0813,35.3378);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 384.808624,173.804992,1008.382812) && entrando[playerid]==1)   //Prefeitura LS
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 1481.0637,-1770.9515,18.7958);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 384.808624,173.804992,1008.382812) && entrando[playerid]==2)   //Prefeitura LV
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 2447.0620,2376.2354,12.1635);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 384.808624,173.804992,1008.382812) && entrando[playerid]==3)   //Prefeitura SF
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, -2765.8796,375.5812,6.3347);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 246.8748,63.0608,1003.6406) && entrando[playerid]==1)    // Departamento LS
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 1554.8657,-1675.6693,16.1953);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 246.8748,63.0608,1003.6406) && entrando[playerid]==2)    // Departamento LV
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 2290.1218,2430.9775,10.8203);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 246.8748,63.0608,1003.6406) && entrando[playerid]==3)    // Departamento SF
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, -1605.5848,710.8436,13.8672);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 246.8748,63.0608,1003.6406) && entrando[playerid]==4)    // Departamento DM
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 627.7621,-571.7207,17.5526);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1104.6949,1515.8959,4452.8071) && entrando[playerid]==1)       // Hospital LS
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 1172.6787,-1323.3129,15.4022);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1104.6949,1515.8959,4452.8071) && entrando[playerid]==2)       // Hospital LV
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 1607.3579,1815.6309,10.8203);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1104.6949,1515.8959,4452.8071) && entrando[playerid]==3)       // Hospital SF
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, -2655.0662,639.1497,14.4531);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1104.6949,1515.8959,4452.8071) && entrando[playerid]==4)       // Hospital EQ
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, -1514.8217,2520.3232,55.9185);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1104.6949,1515.8959,4452.8071) && entrando[playerid]==5)       // Hospital MG
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 1241.8073,327.1022,19.7555);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1104.6949,1515.8959,4452.8071) && entrando[playerid]==6)       // Hospital FC
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, -320.0716,1049.2637,20.3403);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2315.952880,-1.618174,26.742187) && entrando[playerid]==1)     // Banco LS
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 1778.3052,-1663.5337,14.4362);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2315.952880,-1.618174,26.742187) && entrando[playerid]==2)     // Banco LV
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 2388.6733,2466.0430,10.8203);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2315.952880,-1.618174,26.742187) && entrando[playerid]==3)     // Banco SF
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, -2649.8374,376.0090,6.1563);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2315.952880,-1.618174,26.742187) && entrando[playerid]==4)     // Banco FC
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, -180.3883,1133.1510,19.7422);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2315.952880,-1.618174,26.742187) && entrando[playerid]==5)     // Banco MG
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 1372.9271,405.2487,19.9555);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2315.952880,-1.618174,26.742187) && entrando[playerid]==6)     // Banco PC
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 302.9521,-16.2789,26.4844);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2315.952880,-1.618174,26.742187) && entrando[playerid]==7)     // Banco LB
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, -828.0650,1503.6166,19.7585);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2315.952880,-1.618174,26.742187) && entrando[playerid]==8)     // Banco EQ
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, -1480.8273,2592.3015,55.8359);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2315.952880,-1.618174,26.742187) && entrando[playerid]==9)     // Banco BB
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 207.7767,-62.5814,1.6498);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1798.4763,-1578.3191,14.0849) && entrando[playerid]==1)    // Imobiliaria LS
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 1798.4763,-1578.3191,14.0849);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2413.2390,1123.8374,10.8203) && entrando[playerid]==2)     // Imobiliaria LV
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 2413.2390,1123.8374,10.8203);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -1881.1293,822.7573,35.1773) && entrando[playerid]==3)     // Imobiliaria SF
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, -1881.1293,822.7573,35.1773);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -2029.798339,-106.675910,1035.171875) && entrando[playerid]==1)     // Auto Escola LS
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 1519.0413,-1453.5895,14.2073);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -2029.798339,-106.675910,1035.171875) && entrando[playerid]==2)      // Auto Escola LV
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 2183.2483,2295.2205,10.8203);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -2029.798339,-106.675910,1035.171875) && entrando[playerid]==3)      // Auto Escola SF
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, -2026.5950,-101.3410,35.1641);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 833.269775,10.588416,1004.179687) && entrando[playerid]==1)     // Detran LS
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 1310.1411,-1367.8086,13.5408);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 833.269775,10.588416,1004.179687) && entrando[playerid]==2)   // Detran LV
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 1173.1600,1349.0011,10.9219);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 833.269775,10.588416,1004.179687) && entrando[playerid]==3)   // Detran SF
    {
        entrando[playerid]=0;
        SetPlayerInterior(playerid, 0);
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, -2720.6375,127.7373,7.0391);
        SetTimerEx("CarregarInterior", 1000, false, "d", playerid);
    }
    return 1;
}

CarregarLogin(playerid)
{
    PlayerTextDrawShow(playerid, PlayerLogin[playerid][0]);
    PlayerTextDrawShow(playerid, PlayerLogin[playerid][1]);
    PlayerTextDrawShow(playerid, PlayerLogin[playerid][2]);
    PlayerTextDrawShow(playerid, PlayerLogin[playerid][3]);
    PlayerTextDrawShow(playerid, PlayerLogin[playerid][4]);
    PlayerTextDrawShow(playerid, PlayerLogin[playerid][5]);
    PlayerTextDrawShow(playerid, PlayerLogin[playerid][6]);
    PlayerTextDrawShow(playerid, PlayerLogin[playerid][7]);
    PlayerTextDrawShow(playerid, PlayerLogin[playerid][8]);
    PlayerTextDrawShow(playerid, PlayerLogin[playerid][9]);
    PlayerTextDrawShow(playerid, PlayerLogin[playerid][10]);
    PlayerTextDrawShow(playerid, PlayerLogin[playerid][11]);
    PlayerTextDrawShow(playerid, PlayerLogin[playerid][12]);
    return 1;
}

CarregarRegistro(playerid)
{
    PlayerTextDrawShow(playerid, PlayerRegistro[playerid][0]);
    PlayerTextDrawShow(playerid, PlayerRegistro[playerid][1]);
    PlayerTextDrawShow(playerid, PlayerRegistro[playerid][2]);
    PlayerTextDrawShow(playerid, PlayerRegistro[playerid][3]);
    PlayerTextDrawShow(playerid, PlayerRegistro[playerid][4]);
    PlayerTextDrawShow(playerid, PlayerRegistro[playerid][5]);
    PlayerTextDrawShow(playerid, PlayerRegistro[playerid][6]);
    PlayerTextDrawShow(playerid, PlayerRegistro[playerid][7]);
    PlayerTextDrawShow(playerid, PlayerRegistro[playerid][8]);
    PlayerTextDrawShow(playerid, PlayerRegistro[playerid][9]);
    PlayerTextDrawShow(playerid, PlayerRegistro[playerid][10]);
    PlayerTextDrawShow(playerid, PlayerRegistro[playerid][11]);
    PlayerTextDrawShow(playerid, PlayerRegistro[playerid][12]);
    PlayerTextDrawShow(playerid, PlayerRegistro[playerid][13]);
    PlayerTextDrawShow(playerid, PlayerRegistro[playerid][14]);
    PlayerTextDrawShow(playerid, PlayerRegistro[playerid][15]);
    PlayerTextDrawShow(playerid, PlayerRegistro[playerid][16]);
    PlayerTextDrawShow(playerid, PlayerRegistro[playerid][17]);
    PlayerTextDrawShow(playerid, PlayerRegistro[playerid][18]);
    PlayerTextDrawShow(playerid, PlayerRegistro[playerid][19]);
    PlayerTextDrawShow(playerid, PlayerRegistro[playerid][20]);
    return 1;
}

Statusmostrar(playerid)
{
    PlayerTextDrawShow(playerid, PlayerStatus[playerid][0]);
    PlayerTextDrawShow(playerid, PlayerStatus[playerid][1]);
    PlayerTextDrawShow(playerid, PlayerStatus[playerid][2]);
    PlayerTextDrawShow(playerid, PlayerStatus[playerid][3]);
    PlayerTextDrawShow(playerid, PlayerStatus[playerid][4]);
    PlayerTextDrawShow(playerid, PlayerStatus[playerid][5]);
    PlayerTextDrawShow(playerid, PlayerStatus[playerid][6]);
    PlayerTextDrawShow(playerid, PlayerStatus[playerid][7]);
    PlayerTextDrawShow(playerid, PlayerStatus[playerid][8]);
    PlayerTextDrawShow(playerid, PlayerStatus[playerid][9]);
    PlayerTextDrawShow(playerid, PlayerStatus[playerid][10]);
    PlayerTextDrawShow(playerid, PlayerStatus[playerid][11]);
    PlayerTextDrawShow(playerid, PlayerStatus[playerid][12]);
    PlayerTextDrawShow(playerid, PlayerStatus[playerid][13]);
    PlayerTextDrawShow(playerid, PlayerStatus[playerid][14]);
    PlayerTextDrawShow(playerid, PlayerStatus[playerid][15]);
    PlayerTextDrawShow(playerid, PlayerStatus[playerid][16]);
    PlayerTextDrawShow(playerid, PlayerStatus[playerid][17]);
    PlayerTextDrawShow(playerid, PlayerStatus[playerid][18]);
    PlayerTextDrawShow(playerid, PlayerStatus[playerid][19]);
    PlayerTextDrawShow(playerid, PlayerStatus[playerid][20]);
    PlayerTextDrawShow(playerid, PlayerStatus[playerid][21]);
    PlayerTextDrawShow(playerid, PlayerStatus[playerid][22]);
    PlayerTextDrawShow(playerid, PlayerStatus[playerid][23]);
    PlayerTextDrawShow(playerid, PlayerStatus[playerid][24]);
    PlayerTextDrawShow(playerid, PlayerStatus[playerid][25]);
    PlayerTextDrawShow(playerid, PlayerStatus[playerid][26]);
    PlayerTextDrawShow(playerid, PlayerStatus[playerid][27]);
    PlayerTextDrawShow(playerid, PlayerStatus[playerid][28]);
    return 1;
}

Statusocultar(playerid)
{
    PlayerTextDrawHide(playerid, PlayerStatus[playerid][0]);
    PlayerTextDrawHide(playerid, PlayerStatus[playerid][1]);
    PlayerTextDrawHide(playerid, PlayerStatus[playerid][2]);
    PlayerTextDrawHide(playerid, PlayerStatus[playerid][3]);
    PlayerTextDrawHide(playerid, PlayerStatus[playerid][4]);
    PlayerTextDrawHide(playerid, PlayerStatus[playerid][5]);
    PlayerTextDrawHide(playerid, PlayerStatus[playerid][6]);
    PlayerTextDrawHide(playerid, PlayerStatus[playerid][7]);
    PlayerTextDrawHide(playerid, PlayerStatus[playerid][8]);
    PlayerTextDrawHide(playerid, PlayerStatus[playerid][9]);
    PlayerTextDrawHide(playerid, PlayerStatus[playerid][10]);
    PlayerTextDrawHide(playerid, PlayerStatus[playerid][11]);
    PlayerTextDrawHide(playerid, PlayerStatus[playerid][12]);
    PlayerTextDrawHide(playerid, PlayerStatus[playerid][13]);
    PlayerTextDrawHide(playerid, PlayerStatus[playerid][14]);
    PlayerTextDrawHide(playerid, PlayerStatus[playerid][15]);
    PlayerTextDrawHide(playerid, PlayerStatus[playerid][16]);
    PlayerTextDrawHide(playerid, PlayerStatus[playerid][17]);
    PlayerTextDrawHide(playerid, PlayerStatus[playerid][18]);
    PlayerTextDrawHide(playerid, PlayerStatus[playerid][19]);
    PlayerTextDrawHide(playerid, PlayerStatus[playerid][20]);
    PlayerTextDrawHide(playerid, PlayerStatus[playerid][21]);
    PlayerTextDrawHide(playerid, PlayerStatus[playerid][22]);
    PlayerTextDrawHide(playerid, PlayerStatus[playerid][23]);
    PlayerTextDrawHide(playerid, PlayerStatus[playerid][24]);
    PlayerTextDrawHide(playerid, PlayerStatus[playerid][25]);
    PlayerTextDrawHide(playerid, PlayerStatus[playerid][26]);
    PlayerTextDrawHide(playerid, PlayerStatus[playerid][27]);
    PlayerTextDrawHide(playerid, PlayerStatus[playerid][28]);
    return 1;
}

QuebrarLogin(playerid)
{
    PlayerTextDrawHide(playerid, PlayerLogin[playerid][0]);
    PlayerTextDrawHide(playerid, PlayerLogin[playerid][1]);
    PlayerTextDrawHide(playerid, PlayerLogin[playerid][2]);
    PlayerTextDrawHide(playerid, PlayerLogin[playerid][3]);
    PlayerTextDrawHide(playerid, PlayerLogin[playerid][4]);
    PlayerTextDrawHide(playerid, PlayerLogin[playerid][5]);
    PlayerTextDrawHide(playerid, PlayerLogin[playerid][6]);
    PlayerTextDrawHide(playerid, PlayerLogin[playerid][7]);
    PlayerTextDrawHide(playerid, PlayerLogin[playerid][8]);
    PlayerTextDrawHide(playerid, PlayerLogin[playerid][9]);
    PlayerTextDrawHide(playerid, PlayerLogin[playerid][10]);
    PlayerTextDrawHide(playerid, PlayerLogin[playerid][11]);
    PlayerTextDrawHide(playerid, PlayerLogin[playerid][12]);
    return 1;
}

QuebrarRegistro(playerid)
{
    PlayerTextDrawHide(playerid, PlayerRegistro[playerid][0]);
    PlayerTextDrawHide(playerid, PlayerRegistro[playerid][1]);
    PlayerTextDrawHide(playerid, PlayerRegistro[playerid][2]);
    PlayerTextDrawHide(playerid, PlayerRegistro[playerid][3]);
    PlayerTextDrawHide(playerid, PlayerRegistro[playerid][4]);
    PlayerTextDrawHide(playerid, PlayerRegistro[playerid][5]);
    PlayerTextDrawHide(playerid, PlayerRegistro[playerid][6]);
    PlayerTextDrawHide(playerid, PlayerRegistro[playerid][7]);
    PlayerTextDrawHide(playerid, PlayerRegistro[playerid][8]);
    PlayerTextDrawHide(playerid, PlayerRegistro[playerid][9]);
    PlayerTextDrawHide(playerid, PlayerRegistro[playerid][10]);
    PlayerTextDrawHide(playerid, PlayerRegistro[playerid][11]);
    PlayerTextDrawHide(playerid, PlayerRegistro[playerid][12]);
    PlayerTextDrawHide(playerid, PlayerRegistro[playerid][13]);
    PlayerTextDrawHide(playerid, PlayerRegistro[playerid][14]);
    PlayerTextDrawHide(playerid, PlayerRegistro[playerid][15]);
    PlayerTextDrawHide(playerid, PlayerRegistro[playerid][16]);
    PlayerTextDrawHide(playerid, PlayerRegistro[playerid][17]);
    PlayerTextDrawHide(playerid, PlayerRegistro[playerid][18]);
    PlayerTextDrawHide(playerid, PlayerRegistro[playerid][19]);
    PlayerTextDrawHide(playerid, PlayerRegistro[playerid][20]);
    return 1;
}

ZerandoVariaveis(playerid)
{
    PlayerInfo[playerid][ID]=0;
    PlayerInfo[playerid][IP]=0;
    PlayerInfo[playerid][Profissao]=0;
    PlayerInfo[playerid][Semprofissao]=0;
    PlayerInfo[playerid][Nome]=0;
    PlayerInfo[playerid][Senha]=0;
    PlayerInfo[playerid][Email]=0;
    PlayerInfo[playerid][Admin]=0;
    PlayerInfo[playerid][minUP]=9;
    PlayerInfo[playerid][segUP]=59;
    PlayerInfo[playerid][Level]=0;
    PlayerInfo[playerid][Coins]=0;
    PlayerInfo[playerid][Vip]=0;
    PlayerInfo[playerid][CorVIP]=0;
    PlayerInfo[playerid][Vencimento]=0;
    PlayerInfo[playerid][Skin]=0;
    PlayerInfo[playerid][Dinheiro]=0;
    PlayerInfo[playerid][Banco]=0;
    PlayerInfo[playerid][Afk]=false;
    PlayerInfo[playerid][Preso]=0;
    PlayerInfo[playerid][MotivoPrisao]=0;
    PlayerInfo[playerid][Matou]=0;
    PlayerInfo[playerid][Morreu]=0;
    PlayerInfo[playerid][Interior]=0;
    PlayerInfo[playerid][PosX]=0;
    PlayerInfo[playerid][PosY]=0;
    PlayerInfo[playerid][PosZ]=0;
    PlayerInfo[playerid][PosA]=0;
    PlayerInfo[playerid][Logado]=false;
    pPlayerInfo[playerid][pNome]=0;
    pPlayerInfo[playerid][pSenha]=0;
    pPlayerInfo[playerid][pEmail]=0;
    entrando[playerid]=0;
    PegouGas[playerid]=false;
    UPRelogio[playerid]=0;
    Algemado[playerid]=false;
    Abordado[playerid]=false;
    ProfissaoonAgencia[playerid]=0;
    ProfissaoonMafia[playerid]=0;
    return 1;
}

CarregarPickups()
{
    CreatePickup(1314,1,1154.0808,-1771.9812,16.5992);          // Agencia LS
    CreatePickup(1314,1,937.8450,1733.1957,8.8516);             // Agencia LV
    CreatePickup(1314,1,-2171.8110,252.0813,35.3378);           // Agencia SF
    CreatePickup(1239,1,1481.0637,-1770.9515,18.7958);          // Prefeitura LS
    CreatePickup(1239,1,2447.0620,2376.2354,12.1635);           // Prefeitura LV
    CreatePickup(1239,1,-2765.8796,375.5812,6.3347);            // Prefeitura SF
    CreatePickup(1247,1,1554.8657,-1675.6693,16.1953);          // Departamento LS
    CreatePickup(1247,1,2290.1218,2430.9775,10.8203);           // Departamento LV
    CreatePickup(1247,1,-1605.5848,710.8436,13.8672);           // Departamento SF
    CreatePickup(1247,1,627.7621,-571.7207,17.5526);            // Departamento DM
    CreatePickup(1240,1,1172.6787,-1323.3129,15.4022);          // Hospital LS
    CreatePickup(1240,1,1607.3579,1815.6309,10.8203);           // Hospital LV
    CreatePickup(1240,1,-2655.0662,639.1497,14.4531);           // Hospital SF
    CreatePickup(1240,1,-1514.8217,2520.3232,55.9185);          // Hospital EQ
    CreatePickup(1240,1,1241.8073,327.1022,19.7555);            // Hospital MG
    CreatePickup(1240,1,-320.0716,1049.2637,20.3403);           // Hospital FC
    CreatePickup(1274,1,1778.3052,-1663.5337,14.4362);          // Banco LS
    CreatePickup(1274,1,2388.6733,2466.0430,10.8203);           // Banco LV
    CreatePickup(1274,1,-2649.8374,376.0090,6.1563);            // Banco SF
    CreatePickup(1274,1,-180.3883,1133.1510,19.7422);           // Banco FC
    CreatePickup(1274,1,1372.9271,405.2487,19.9555);            // Banco MG
    CreatePickup(1274,1,2302.9521,-16.2789,26.4844);            // Banco PC
    CreatePickup(1274,1,-828.0650,1503.6166,19.7585);           // Banco LB
    CreatePickup(1274,1,-1480.8273,2592.3015,55.8359);          // Banco EQ
    CreatePickup(1274,1,207.7767,-62.5814,1.6498);              // Banco BB
    CreatePickup(19523,1,1798.4763,-1578.3191,14.0849);         // Imobiliaria LS
    CreatePickup(19523,1,2413.2390,1123.8374,10.8203);          // Imobiliaria LV
    CreatePickup(19523,1,-1881.1293,822.7573,35.1773);          // Imobiliaria SF
    CreatePickup(19134,1,1519.0413,-1453.5895,14.2073);         // Auto Escola LS
    CreatePickup(19134,1,2183.2483,2295.2205,10.8203);          // Auto Escola LV
    CreatePickup(19134,1,-2026.5950,-101.3410,35.1641);         // Auto Escola SF
    CreatePickup(19132,1,1310.1411,-1367.8086,13.5408);         // Detran LS
    CreatePickup(19132,1,1173.1600,1349.0011,10.9219);          // Detran LV
    CreatePickup(19132,1,-2720.6375,127.7373,7.0391);           // Detran SF
    CreatePickup(1210,1,785.2020,-1327.7697,13.5469);           // Trabalhar Entregador de Jornal
    CreatePickup(1210,1,2229.5803,-1368.1969,23.9922);          // Trabalhar Taxi
    CreatePickup(1210,1,1579.5728,-1635.3932,13.5611);          // Trabalhar Policia Civil
    CreatePickup(1210,1,2339.9778,2457.2256,14.9688);           // Trabalhar Corregedoria
    CreatePickup(1210,1,-453.7872,2230.1296,42.4993);           // Trabalhar Ladrão de Gás
    CreatePickup(1318,1,1494.4989,1303.6678,1093.2964);         // Agencia
    CreatePickup(1318,1,384.808624,173.804992,1008.382812);     // Prefeitura
    CreatePickup(1318,1,246.8748,63.0608,1003.6406);            // Departamento
    CreatePickup(1318,1,1104.6949,1515.8959,4452.8071);         // Hospital
    CreatePickup(1318,1,2315.952880,-1.618174,26.742187);       // Banco
    CreatePickup(1318,1,1798.4763,-1578.3191,14.0849);          // Imobiliaria
    CreatePickup(1318,1,-2029.798339,-106.675910,1035.171875);  // Auto Escola
    CreatePickup(1318,1,833.269775,10.588416,1004.179687);      // Detran
    CreatePickup(1242,1,254.1715,74.3339,1003.6406);            // Departamento de Policia /Equipar
    return 1;
}

formatSeconds(seconds, &hours_left, &minutes_left, &seconds_left)
{
    hours_left = seconds/60/60;
    minutes_left = (seconds - hours_left*60*60 )/60;
    seconds_left = (seconds - hours_left*60*60 - minutes_left*60);
    return 1;
}

convertTimestamp( timestamp, _form=0 )
{
    timestamp -= 10800;
    new year = 1970, day = 0, month = 0, hour = 0, mins = 0, sec = 0, returnstring[32];

    new days_of_month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    new names_of_month[12][10] = {"Janeiro","Fevereiro","Março","Abril","Maio","Junho","Julho","Agosto","Setembro","Outubro","Novembro","Dezembro"};

    while(timestamp>31622400){
        timestamp -= 31536000;
        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0) ) timestamp -= 86400;
        year++;
    }

    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) days_of_month[1] = 29;
     else days_of_month[1] = 28;


    while(timestamp>86400){
        timestamp -= 86400, day++;
        if(day == days_of_month[month]) day=0, month++;
    }

    while(timestamp > 60){
        timestamp -= 60, mins++;
        if(mins == 60) mins = 0, hour++;
    }

    sec = timestamp;

    switch(_form)
    {
        case 1: format(returnstring, 31, "%02d/%02d/%d %02d:%02d:%02d", day+1, month+1, year, hour, mins, sec);
        case 2: format(returnstring, 31, "%s %02d, %d, %02d:%02d:%02d", names_of_month[month],day+1,year, hour, mins, sec);
        case 3: format(returnstring, 31, "%d %c%c%c %d, %02d:%02d", day+1,names_of_month[month][0],names_of_month[month][1],names_of_month[month][2], year,hour,mins);
        case 4: format(returnstring, 31, "%02d.%02d.%d-%02d:%02d:%02d", day+1, month+1, year, hour, mins, sec);
        default: format(returnstring, 31, "%02d:%02d:%02d %02d/%02d/%d", hour, mins, sec, day+1, month+1, year);
    }
    return returnstring;
}

GetDistanceBetweenPlayers(playerid,playerid2)
{
    new Float:x1,Float:y1,Float:z1,Float:x2,Float:y2,Float:z2;
    new Float:dis;
    GetPlayerPos(playerid,x1,y1,z1);
    GetPlayerPos(playerid2,x2,y2,z2);
    dis = floatsqroot(floatpower(floatabs(floatsub(x2,x1)),2)+floatpower(floatabs(floatsub(y2,y1)),2)+floatpower(floatabs(floatsub(z2,z1)),2));
    return floatround(dis);
}

IsPlayerAjudante(playerid)
{
    if(PlayerInfo[playerid][Admin] >= 1 && PlayerInfo[playerid][Admin] <= 5) return true;
    return false;
}

IsPlayerModerador(playerid)
{
    if(PlayerInfo[playerid][Admin] >= 2 && PlayerInfo[playerid][Admin] <= 5) return true;
    return false;
}

IsPlayerAdmininstrador(playerid)
{
    if(PlayerInfo[playerid][Admin] >= 3 && PlayerInfo[playerid][Admin] <= 5) return true;
    return false;
}

IsPlayerSub(playerid)
{
    if(PlayerInfo[playerid][Admin] >= 4 && PlayerInfo[playerid][Admin] <= 5) return true;
    return false;
}

IsPlayerDesen(playerid)
{
    if(PlayerInfo[playerid][Admin] == 5) return true;
    return false;
}

IsPlayerVip(playerid)
{
    if(PlayerInfo[playerid][Vip] >= 1) return true;
    return false;
}

IsPlayerUniformePM(playerid)
{
    if(GetPlayerSkin(playerid) == 287) return true;
    return false;
}

SkinList(playerid)
{
    new var[17];
    switch(SkinPlayer[playerid])
    {
        case 0: var = "cj (ID:0)";
        case 1: var = "truth (ID:1)";
        case 2: var = "maccer (ID:2)";
        case 3: var = "andre (ID:3)";
        case 4: var = "bbthin (ID:4)";
        case 5: var = "bb (ID:5)";
        case 6: var = "emmet (ID:6)";
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

NitroInfinito(arg0)
{
new var0 = GetVehicleModel(arg0);
switch(var0) {
case 444:
return 0;
case 581:
return 0;
case 586:
return 0;
case 481:
return 0;
case 509:
return 0;
case 446:
return 0;
case 556:
return 0;
case 443:
return 0;
case 452:
return 0;
case 453:
return 0;
case 454:
return 0;
case 472:
return 0;
case 473:
return 0;
case 484:
return 0;
case 493:
return 0;
case 595:
return 0;
case 462:
return 0;
case 463:
return 0;
case 468:
return 0;
case 521:
return 0;
case 522:
return 0;
case 417:
return 0;
case 425:
return 0;
case 447:
return 0;
case 487:
return 0;
case 488:
return 0;
case 497:
return 0;
case 501:
return 0;
case 548:
return 0;
case 563:
return 0;
case 406:
return 0;
case 520:
return 0;
case 539:
return 0;
case 553:
return 0;
case 557:
return 0;
case 573:
return 0;
case 460:
return 0;
case 593:
return 0;
case 464:
return 0;
case 476:
return 0;
case 511:
return 0;
case 512:
return 0;
case 577:
return 0;
case 592:
return 0;
case 471:
return 0;
case 448:
return 0;
case 461:
return 0;
case 523:
return 0;
case 510:
return 0;
case 430:
return 0;
case 465:
return 0;
case 469:
return 0;
case 513:
return 0;
case 519:
return 0;
}
return 1;
}
