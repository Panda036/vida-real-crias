//Original by:      Xeon™           http://forum.sa-mp.com/member.php?u=302228
//Mod by: RazorG                    http://forum.sa-mp.com/member.php?u=279148
//Alias by: Day & RazorG            http://forum.sa-mp.com/member.php?u=218386


#if !defined DDCMD_ALIAS
    #define DDCMD_ALIAS true
#endif

#if DDCMD_ALIAS

#define DDcommand:%0(%1)  ddkmd_%0(%1); public ddkmd_%0(%1)
#define DDalias:%0(%1,%2); DDcommand:%0(DCC_Channel:channel,DCC_User:userid,params[]) return ddkmd_%1(%2);

// Remove espaços
#define ddkmd_%0\32;%1(  ddkmd_%1(
#define C@DD1_%0\32;%1:  C@DD1_%1:
#define F@DD0_%0\32;%1(  F@DD0_%1(
#define forward%9C@DD1_%0\32;%1:  forward C@DD1_%1:
// Divide o comando em dois macros c@DD0:c@DD1:
#define DDCMD:%0(%1)    ddcmd:%0(%1)
#define ddcmd:%0(%1)    c@DD0:c@DD1:%0(%1)

/*
 * c@DD0 - Detecta se existe algum DDalias
 * c@DD1 - Comando sem DDalias
 */

/*
 * %0 - Nome do comando
 * %1 - Parametros do comando
 * %2 - DDaliases
 */
#define c@DD0:c@DD1:%0(%1)<%2>              DDalias_cmd(%0(%1)<%2>)

/*
 * %0 - Nome do comando
 * %1 - Parametros do comando
 */
#define c@DD1:%0(%1)                      _DD_fix_();DDcommand:%0(%1)

// Converte os DDaliases para serem analizados recursivamente por C@DD0
#define DDalias_cmd(%0(%1)<%2>)            C@DD0(%0(%1)),%2, ENDDD,

// Analiza os DDaliases recursivamente
#define C@DD0(%9(%8)),%0\32;%1,            DDalias_analyze:%1(%9(%8));C@DD0(%9(%8)),

// Nenhum outro DDalias encontrado, então cria o comando
#define C@DD1_ENDDD:%1(%0);C@DD0(%9(%8)),      DDcommand:%9(%8)

// Analiza
#define DDalias_analyze:%0(%9(%8))         forward C@DD1_%0:DDALIAS:%0(%9,DDanalyze_params(%8))

// Oculta a tag C@DD1_*: com uma declaração, que após a parte da pré-compilação é ignorada e cria um DDalias
#define DDALIAS:%0(%1,%2);                 F@DD0_%0(); DDalias:%0(%1,%2);

/*
 * Analiza os parametros e retorna quantos tem no formato
 * %0 - Parametros para verificar
 */
#define DDanalyze_params(%0) p@DD0:p@DD1:(%0)

#define p@DD0:p@DD1:(%0,%1,%2) channel,userid,params
#define p@DD1:(%0,%1)          channel,userid


#else

#define DDCMD:%1(%2) \
    forward ddkmd_%1(%2); \
    public ddkmd_%1(%2)

#define ddcmd(%1,%2,%3) \
    DDCMD:%1(%2, %3, %4)

#endif


#if !defined    DCC_COMMAND_PREFIX
    new    DCC_COMMAND_PREFIX[]= {'!'};
#endif

public OnGameModeInit()
{
    if (funcidx("DCC_OnGameModeInit") != -1)
    {
        return CallLocalFunction("DCC_OnGameModeInit", "");
    }
    return 1;
}

#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif
#define OnGameModeInit DCC_OnGameModeInit

forward DCC_OnGameModeInit();
forward DCC_OnChannelMessage(DCC_Channel:channel, DCC_User:author, const message[]);
public DCC_OnChannelMessage(DCC_Channel:channel, DCC_User:author, const message[])
{
    print("EXE 1");

    for(new i = 0, s = sizeof(DCC_COMMAND_PREFIX); i < s; i++)
    {
        if (message[0] == DCC_COMMAND_PREFIX[i])
        {
            new function[32], pos = 0;
            while (message[++pos] > ' ')
            {
                function[pos - 1] = tolower(message[pos]);
                if (pos > (sizeof(function) - 1))
                    break;
            }

            format(function, sizeof(function), "ddkmd_%s", function);

            while (message[pos] == ' ')
                pos++;

            if (!message[pos])
                CallLocalFunction(function, "dds", _:channel, _:author, "\1");
            else
                CallLocalFunction(function, "dds", _:channel, _:author, message[pos]);

            return 1;
        }

    }

    #if defined DCC_OCM
        return DCC_OCM(channel, author, message);
    #else
        return 1;
    #endif
}

#if defined _ALS_DCC_OnChannelMessage
    #undef DCC_OnChannelMessage
#else
    #define _ALS_DCC_OnChannelMessage
#endif

#define DCC_OnChannelMessage DCC_OCM

#if defined DCC_OCM
    forward DCC_OCM(DCC_Channel:channel, DCC_User:author, const message[]);
#endif


//-------------------------------------------

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

//--------------------------------------------
