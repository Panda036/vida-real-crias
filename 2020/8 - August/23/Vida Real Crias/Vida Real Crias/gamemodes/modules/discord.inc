#if !SERVER_OFFLINE

#include YSI\y_hooks
#include discord-connector
// #include ddcmd

enum
{
    DCC_Channel:dsc_vip,
    DCC_Channel:dsc_admin
};

new DCC_Channel:Channels[3];

enum
{
    DCC_User:us_rafael,
    DCC_User:us_alex,
    DCC_User:us_gabriel,
    DCC_User:us_i
};

new DCC_User:Users[4];

hook OnGameModeInit()
{
    Channels[dsc_vip] = DCC_FindChannelById("695302633648554015");
    Channels[dsc_admin] = DCC_FindChannelById("695302694801506416");

    Users[us_rafael] = DCC_FindUserById("640265435240988672");
    Users[us_alex] = DCC_FindUserById("356105497285492739");
    Users[us_gabriel] = DCC_FindUserById("594252354405007361");
    Users[us_i] = DCC_FindUserById("471743289909837824");

    SetTimer("OnStaffCoding", 1000, true);
    return 1;
}

/*
public DCC_OCM(DCC_Channel:channel, DCC_User:author, const message[])
{
    print("EXE 1");

    if(channel == DCC_Channel:DCC_FindUserById("714846649943326801")) print("EXE 3");

    format(String, 128, "[Discord] %s: %s", GetNickDiscord(author), message);
    SendClientMessageToAll(White, String);

    printf("EXE 2 : %s", String);
	return 1;
}
*/

forward OnStaffCoding();
public OnStaffCoding()
{
    new hour, minutes, secunds;

    gettime(hour, minutes, secunds);

    if(hour == 5 && minutes == 5 && secunds == 0)
    {
        mysql_tquery(IDConexao, "SELECT `code` FROM `Staffs` WHERE `nivel`='1'", "OnSendCodeAdmin", "d", us_rafael);

        mysql_tquery(IDConexao, "SELECT `code` FROM `Staffs` WHERE `nivel`='4'", "OnSendCodeAdmin", "d", us_alex);

        mysql_tquery(IDConexao, "SELECT `code` FROM `Staffs` WHERE `nivel`='5'", "OnSendCodeAdmin", "d", us_gabriel);

        mysql_tquery(IDConexao, "SELECT `code` FROM `Staffs` WHERE `nivel`='6'", "OnSendCodeAdmin", "d", us_i);
    }
    return 1;
}

forward OnSendCodeAdmin(userid);
public OnSendCodeAdmin(userid)
{
    if(cache_num_rows() == 0) return 1;

    new code[31];

    cache_get_value_name(0, "code", code);

    DCC_CreatePrivateChannel(Users[userid], "OnPrivateChannel", "sd", code, userid);
    return 1;
}

forward OnPrivateChannel(cod[], userid);
public OnPrivateChannel(cod[], userid)
{
    new DCC_Channel:channel = DCC_GetCreatedPrivateChannel(), year, month, day;

    if(!channel) return 0;

    getdate(year, month, day);

    format(String, 128, "%02d/%02d: %s", day, month, cod);
    DCC_SendChannelMessage(channel, String);
    return 1;
}

stock GetNickDiscord(DCC_User:author)
{
    new nick[27];
    DCC_GetUserName(author, nick, 26);
    return nick;
}
stock IsDiscordBot(DCC_User:author)
{
    new bool:Isabot;
    DCC_IsUserBot(author, Isabot);
    return Isabot;
}

#endif
