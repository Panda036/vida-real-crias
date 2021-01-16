#if !SERVER_OFFLINE

#define MAX_CHANNEL 6
#define MAX_GUILD   1

#include YSI\y_hooks

enum
{
    DCC_Channel:dsc_vip,
    DCC_Channel:dsc_admin,
    DCC_Channel:dsc_staff,
    DCC_Channel:dsc_chatbot,
    DCC_Channel:dsc_register
};

new DCC_Channel:Channels[MAX_CHANNEL];

hook OnGameModeInit()
{
    DCC_SetBotActivity("Vida Real Crias");

    Channels[dsc_vip] = DCC_FindChannelById("695302633648554015");
    Channels[dsc_admin] = DCC_FindChannelById("695302694801506416");
    Channels[dsc_staff] = DCC_FindChannelById("695302694801506416");
    Channels[dsc_chatbot] = DCC_FindChannelById("695302617265340478");
    Channels[dsc_register] = DCC_FindChannelById("695302697477210162");

    SetTimer("OnStaffCoding", 60000, false);
    return 1;
}

public DCC_OnMessageCreate(DCC_Message:message)
{
    new DCC_Channel:channel, DCC_User:author, txt[MAX_STRING];

    DCC_GetMessageChannel(message, channel);
    DCC_GetMessageAuthor(message, author);
    DCC_GetMessageContent(message, txt, MAX_STRING);

    return DCC_OnChannelMessage(channel, author, txt);
}

forward DCC_OnChannelMessage(DCC_Channel:channel, DCC_User:author, const message[]);
public DCC_OnChannelMessage(DCC_Channel:channel, DCC_User:author, const message[])
{
    if(channel == Channels[dsc_register])
    {
        if(strcmp(message, "&registro", true)) return 0;

        new query[200], Cache:result, DCC_Guild:gd_vrc = DCC_FindGuildById("682670634156949527");

        mysql_format(IDConexao, query, 200, "SELECT `Nome` FROM `Contas` WHERE `Nome`='%e'", GetNickDiscord(author));
        result = mysql_query(IDConexao, query);

        if(cache_num_rows())
        {
            DCC_AddGuildMemberRole(gd_vrc, author, DCC_FindRoleById("692837778521849876"));

            format(String, MAX_STRING, ":white_check_mark: Registrado com sucesso %s, bom jogo :video_game:", GetNickDiscord(author));
        }
        else
        {
            format(String, MAX_STRING, ":x: Falha no seu registro %s", GetNickDiscord(author));
        }

        DCC_CreatePrivateChannel(author, "OnPrivateChannelRegister", "s", String);

        cache_delete(result);
        return 1;
    }
    return 1;
}

forward OnPrivateChannelRegister(const message[]);
public OnPrivateChannelRegister(const message[])
{
    new DCC_Channel:channel = DCC_GetCreatedPrivateChannel();

    DCC_SendChannelMessage(channel, message);
    return 1;
}

forward OnStaffCoding();
public OnStaffCoding()
{
    //new time[3];

    //gettime(time[0], time[1], time[2]);

    //if(time[0] != 05 || time[1] != 01 || time[2] != 00) return 0;

    mysql_query(IDConexao, "SELECT `id` FROM `DiscordCodeAuto`");

    if(cache_num_rows() == 0) return 0;

    for(new row = 0; row < cache_num_rows(); row++)
    {
        new userid[32+1], bool:has_role, DCC_Guild:gd_vrc = DCC_FindGuildById("682670634156949527");

        cache_get_value_name(row, "id", userid);

        DCC_HasGuildMemberRole(gd_vrc, DCC_FindUserById(userid), DCC_FindRoleById("692837561084674158"), has_role);
        if(has_role)
            mysql_tquery(IDConexao, "SELECT `code` FROM `Staffs` WHERE `nivel`='1'", "OnSendCodeAdmin", "s", userid);

        DCC_HasGuildMemberRole(gd_vrc, DCC_FindUserById(userid), DCC_FindRoleById("692837297342775358"), has_role);
        if(has_role)
            mysql_tquery(IDConexao, "SELECT `code` FROM `Staffs` WHERE `nivel`='2'", "OnSendCodeAdmin", "s", userid);

        DCC_HasGuildMemberRole(gd_vrc, DCC_FindUserById(userid), DCC_FindRoleById("692837186630057986"), has_role);
        if(has_role)
            mysql_tquery(IDConexao, "SELECT `code` FROM `Staffs` WHERE `nivel`='3'", "OnSendCodeAdmin", "s", userid);

        DCC_HasGuildMemberRole(gd_vrc, DCC_FindUserById(userid), DCC_FindRoleById("692837104350396517"), has_role);
        if(has_role)
            mysql_tquery(IDConexao, "SELECT `code` FROM `Staffs` WHERE `nivel`='4'", "OnSendCodeAdmin", "s", userid);

        DCC_HasGuildMemberRole(gd_vrc, DCC_FindUserById(userid), DCC_FindRoleById("682672546264645645"), has_role);
        if(has_role)
            mysql_tquery(IDConexao, "SELECT `code` FROM `Staffs` WHERE `nivel`='5'", "OnSendCodeAdmin", "s", userid);

        DCC_HasGuildMemberRole(gd_vrc, DCC_FindUserById(userid), DCC_FindRoleById("682672170693951549"), has_role);
        if(has_role)
            mysql_tquery(IDConexao, "SELECT `code` FROM `Staffs` WHERE `nivel`='6'", "OnSendCodeAdmin", "s", userid);
    }
    return 1;
}

forward OnSendCodeAdmin(userid[]);
public OnSendCodeAdmin(userid[])
{
    if(cache_num_rows() == 0) return 1;

    new code[31];

    cache_get_value_name(0, "code", code);

    DCC_CreatePrivateChannel(DCC_FindUserById(userid), "OnPrivateChannel", "ss", code, userid);
    return 1;
}

forward OnPrivateChannel(cod[], userid[]);
public OnPrivateChannel(cod[], userid[])
{
    new DCC_Channel:channel = DCC_GetCreatedPrivateChannel(), year, month, day, DCC_User:author = DCC_FindUserById(userid);

    if(!channel) return 0;

    getdate(year, month, day);

    format(String, 256, ":calendar_spiral: %02d/%02d ~ %s %s, seu codigo: ```%s```", day, month, GetStateDay(), GetNickDiscord(author), cod);
    DCC_SendChannelMessage(channel, String);
    return 1;
}

stock GetStateDay()
{
    new time[3], var[30];

    gettime(time[0], time[1], time[2]);

    switch(time[0])
    {
        case 0..5: var = ":rice_scene: Boa madrugada";
        case 6..11: var = ":city_dusk: Bom dia";
        case 12..18: var = ":city_sunrise: Boa tarde";
        case 19..23: var = ":rice_scene: Boa noite";
    }
    return var;
}

#endif
