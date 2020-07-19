#include YSI\y_hooks

new MessageList[16][128] =
{
    "{FFFFFF}[!] {76EE00}Para ver seu level ~~> /Meulevel",
    "{FFFFFF}[!] {76EE00}Jogar em nosso servidor é um privilegio e não direito!",
    "{FFFFFF}[!] {76EE00}Ofensa à Administração será punido com ban",
    "{FFFFFF}[!] {76EE00}Vejam o fórum e fique por dentro das novidades ~~> /Ajuda ~~> Contatos",
    "{FFFFFF}[!] {76EE00}Viu uma pessoa dando Teleporte? /Relatorio",
    "{FFFFFF}[!] {FF8C00}Inscreva-se em nosso canal no YouTube: www.youtube.com/channel/UCMijwRnIbRf2RerUEST-sqg?",
    "{FFFFFF}[!] {76EE00}Deseja VIP ? Acesse nosso site e confira: https://vidaarealcrias.wordpress.com/",
    "{FFFFFF}[!] {76EE00}Bem vindo(a) ao servidor Vida Real Crias",
    "{FFFFFF}[!] {76EE00}Para ver os Players Level Alto Digite ~~> /Toplevel",
    "{FFFFFF}[!] {76EE00}Chame Seus Amigo pro Servidor Fica Mais Divertido",
    "{FFFFFF}[!] {76EE00}Para evitar punições, sempre respeite as regras, use: /Regras",
    "{FFFFFF}[!] {76EE00}Caso esteja com pouco combustivel, procure um dos 10 postos espalhados por San Andreas",
    "{FFFFFF}[!] {76EE00}Veja Todos Contatos do Servidor: /Ajuda ~~> Contatos",
    "{FFFFFF}[!] {76EE00}Para denuciar Cheaters ou Abusers ~~> /Relatorio",
    "{FFFFFF}[!] {76EE00}Para ver as vantagens VIP /Vantagensvip",
    "{FFFFFF}[!] {76EE00}Está precisando de ajuda e não tem nenhum admin online ? ~~> /Ajuda"
};

hook OnGameModeInit()
{
    SetTimer("RandomMSGs", 1000*60*20, true);
    return 1;
}

forward RandomMSGs(COLOR, const string[]);
public RandomMSGs(COLOR, const string[])
{
    new rand = random(sizeof(MessageList));
    SendClientMessageToAll(COLOR, MessageList[rand]);
    return 1;
}
