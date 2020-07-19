#if !defined _samp_included
    #error "N-Mail: Defina A_SAMP!"
#endif

#include a_http

#if !defined n_mail_include
    #define n_mail_include
#endif

#define URL_ENVIOEMAIL "br-me.net/publico/nmail/index.php" // Altere

#define SMTP_HOST "br-me.net" // Altere
#define SMTP_PORTA 25 // Altere

new nmail_http_request, m_mailmail[1024];

/*
    native SendEmail(de[], para[], titulo[], mensagem[], charset[] = "utf-8", type[]="text/html");
    native SendEmailSMTP(user_smtp[], senha_smtp[], para[], titulo[], mensagem[], host_smtp[]=SMTP_HOST, porta_smtp=SMTP_PORTA, authtype_smtp[] = "PLAIN", charset[] = "utf-8", type[]="text/html");
*/

forward Mail_HTTP(index, response_code, data[]);
stock SendEmail(de[], para[], titulo[], mensagem[], charset[]="utf-8", type[]="text/html") {
    format(m_mailmail, sizeof(m_mailmail), "de=%s&para=%s&tit=%s&msg=%s&charset=%s&type=%s", de, para, titulo, mensagem, charset, type);
    return HTTP(nmail_http_request, HTTP_POST, URL_ENVIOEMAIL, m_mailmail, "Mail_HTTP");
}
stock SendEmailSMTP(user_smtp[], senha_smtp[], para[], titulo[], mensagem[], host_smtp[]=SMTP_HOST, porta_smtp = SMTP_PORTA, authtype_smtp[] = "PLAIN", charset[]="utf-8", type[]="text/html") {
    format(m_mailmail, sizeof(m_mailmail),"de=%s&senha=%s&para=%s&tit=%s&msg=%s&host=%s&porta=%i&auth=%s&charset=%s&type=%s", user_smtp, senha_smtp, para, titulo, mensagem, host_smtp, porta_smtp, authtype_smtp, charset, type);
    return HTTP(nmail_http_request, HTTP_POST, ""#URL_ENVIOEMAIL"?autenticado=1", m_mailmail, "Mail_HTTP");
}

public Mail_HTTP(index, response_code, data[]) {
    nmail_http_request++;
    if(strlen(data) > 0)
        printf("[NMail] Script: %s", data);
    return 1;
}

/*
        Necessário os arquivos para o envio de e-mails.
        Em uma hospedagem pública, você pode usar outros smtp's

    ////////////////////////////////////////////////////
    ////        www.brasilmegatrucker.com            ///
    ////////////////////////////////////////////////////
*/
