//Safety by Henrique Calenzo 03/01
//Validity until February

#include YSI\y_hooks

#define month_limit 8

hook OnGameModeInit()
{
    new date[3];

    getdate(date[0], date[1], date[2]);

    if(date[1] >= month_limit)
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
