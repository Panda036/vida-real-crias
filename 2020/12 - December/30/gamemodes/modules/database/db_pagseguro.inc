#include YSI\y_hooks

new MySQL:IDPagseguro;

hook OnGameModeInit()
{
    IDPagseguro = mysql_connect("162.241.203.232", "vidare19_pagseguro", "5GV5Q2CCg8", "vidare19_pagseguro");

    if(mysql_errno(IDPagseguro))
    {
        print(" =============[ PAGSEGURO ]=============");
        print(" |                                     |");
        print(" |           Banco de Dados            |");
        print(" |               Falhou                |");
        print(" |                                     |");
        print(" =============[ PAGSEGURO ]=============");
    }
    else
    {
        print(" =============[ PAGSEGURO ]=============");
        print(" |                                     |");
        print(" |           Banco de Dados            |");
        print(" |        Conectado com sucesso        |");
        print(" |                                     |");
        print(" =============[ PAGSEGURO ]=============");

        new dbpag[1000];
        strins(dbpag, "CREATE TABLE IF NOT EXISTS `transaction` (", strlen(dbpag));
        strins(dbpag, "`id` int AUTO_INCREMENT NOT NULL, ", strlen(dbpag));
        strins(dbpag, "`transaction` varchar(255) NOT NULL, ", strlen(dbpag));
        strins(dbpag, "`status` int(1) NOT NULL, ", strlen(dbpag));
        strins(dbpag, "`value` int(11) NOT NULL, ", strlen(dbpag));
        strins(dbpag, "PRIMARY KEY (`id`))", strlen(dbpag));
        mysql_query(IDPagseguro, dbpag, false);
    }
    return 1;
}

stock NameState(stateid)
{
    new status[25];

    switch(stateid)
    {
        case 0: status = "Pendente";
        case 1: status = "Aguardando pagamento";
        case 2: status = "Em análise";
        case 3: status = "Pago";
        case 4: status = "Disponível";
        case 5: status = "Em disputa";
        case 6: status = "Devolvida";
        case 7: status = "Cancelada";
        case 8: status = "Ativado";
        default: status = "Inválido";
    }
    return status;
}
