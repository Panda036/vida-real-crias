//Safety by Henrique Calenzo 03/01
//Validity until February

#include YSI\y_hooks

#define limit_month     2
#define limit_year      2021

hook OnGameModeInit()
{
    new date[3];

    getdate(date[0], date[1], date[2]);

    if(date[1] >= limit_month && date[2] == limit_year)
    {
        print(" =======================================");
        print(" |                                     |");
        print(" |           SAFETY - BLOCK            |");
        print(" |     * update date your server *     |");
        print(" |                                     |");
        print(" =======================================");
        SendRconCommand("exit");
        return 1;
    }
	return 1;
}
