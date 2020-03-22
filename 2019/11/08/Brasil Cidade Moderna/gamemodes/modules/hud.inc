#include YSI\y_hooks

new Text:txtDateDisp, Text:txtTimeDisp;

hook OnGameModeInit()
{
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

    SetTimer("ProcessGameTime", 1000, true);
	return 1;
}

hook OnPlayerSpawn(playerid)
{
    TextDrawShowForPlayer(playerid, txtTimeDisp);
    TextDrawShowForPlayer(playerid, txtDateDisp);
	return 1;
}

forward ProcessGameTime(); public ProcessGameTime()
{
    static Mess[20];
    gettime(Hora, Min);
    getdate(Ano, Mes, Dia);

    switch(Mes)
    {
        case 1:
            Mess = "Janeiro";
        case 2:
            Mess = "Fevereiro";
        case 3:
            Mess = "Marco";
        case 4:
            Mess = "Abril";
        case 5:
            Mess = "Maio";
        case 6:
            Mess = "Junho";
        case 7:
            Mess = "Julho";
        case 8:
            Mess = "Agosto";
        case 9:
            Mess = "Setembro";
        case 10:
            Mess = "Outubro";
        case 11:
            Mess = "Novembro";
        case 12:
            Mess = "Dezembro";
    }

    for(new x=0; x <= 23; ++x)
    {
        if(Hora == 17)
            SetWorldTime(20);
        else if(Hora == 18)
            SetWorldTime(20);
        else if(Hora == 19)
            SetWorldTime(20);
        else if(Hora == 20)
            SetWorldTime(20);
        else
            SetWorldTime(x);
    }

    format(String, sizeof(String), "%02d:%02d", Hora, Min);
    TextDrawSetString(txtTimeDisp, String);
    format(String, sizeof(String), "%02d_de_%s_de_%02d", Dia, Mess, Ano);
    TextDrawSetString(txtDateDisp, String);
    return 1;
}
