#include YSI\y_hooks

hook OnGameModeInit()
{
    SetTimer("HourGame", 1000, true);
	return 1;
}

forward HourGame();
public HourGame()
{
    new Months[20];

    new hours, minutes, years, months, days;

    gettime(hours, minutes);
    getdate(years, months, days);

    switch(months)
    {
        case 1: Months = "Janeiro";
        case 2: Months = "Fevereiro";
        case 3: Months = "Marco";
        case 4: Months = "Abril";
        case 5: Months = "Maio";
        case 6: Months = "Junho";
        case 7: Months = "Julho";
        case 8: Months = "Agosto";
        case 9: Months = "Setembro";
        case 10: Months = "Outubro";
        case 11: Months = "Novembro";
        case 12: Months = "Dezembro";
    }

    switch(hours)
    {
        case 0..4: SetWorldTime(3);
        case 5: SetWorldTime(2);
        case 6..8: SetWorldTime(8);
        case 9..11: SetWorldTime(10);
        case 12: SetWorldTime(12);
        case 13: SetWorldTime(15);
        case 14: SetWorldTime(16);
        case 15..16: SetWorldTime(18);
        case 17: SetWorldTime(20);
        case 18: SetWorldTime(21);
        case 19..21: SetWorldTime(0);
        case 22..23: SetWorldTime(0);
    }

    format(String, 50, "%02d:%02d", hours, minutes);
    TextDrawSetString(txtTimeDisp, String);
    format(String, 100, "%02d_de_%s_de_%02d", days, Months, years);
    TextDrawSetString(txtDateDisp, String);
    return 1;
}
