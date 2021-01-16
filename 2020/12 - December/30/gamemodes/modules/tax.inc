#include YSI\y_hooks

#define MAX_TAX_HOUSE       7
#define MAX_TAX_BUSINESS    7
#define HOUSE_TAX_VALUE     250
#define BUSINESS_TAX_VALUE  250

stock SendTax()
{
    new query[100];

    for(new i = 0; i < MAX_HOUSES; i++)
    {
        mysql_format(IDConexao, query, 100, "SELECT `Nome` FROM `Houses` WHERE `Nome`='N/A' AND `id`='%d'", i);
        mysql_query(IDConexao, query);

        if(cache_num_rows() == 0)
        {
            if(GetTaxHouse(i) >= MAX_TAX_HOUSE)
            {
                mysql_format(IDConexao, query, 100, "UPDATE `Houses` SET `IPTU`='0' WHERE `id`='%d'", i);
                mysql_query(IDConexao, query);

                ReleaseHouse(i);
            }
            else
            {
                mysql_format(IDConexao, query, 100, "UPDATE `Houses` SET `IPTU`='%d' WHERE `id`='%d'", ( GetTaxHouse(i) + 1 ), i);
                mysql_query(IDConexao, query);
            }
        }
    }
    for(new i = 0; i < MAX_BUSINESS; i++)
    {
        mysql_format(IDConexao, query, 100, "SELECT `Nome` FROM `Business` WHERE `Nome`='N/A' AND `id`='%d'", i);
        mysql_query(IDConexao, query);

        if(cache_num_rows() == 0)
        {
            if(GetTaxBusiness(i) >= MAX_TAX_BUSINESS)
            {
                mysql_format(IDConexao, query, 100, "UPDATE `Business` SET `IPTU`='0' WHERE `id`='%d'", i);
                mysql_query(IDConexao, query);

                ReleaseBusiness(i);
            }
            else
            {
                mysql_format(IDConexao, query, 100, "UPDATE `Business` SET `IPTU`='%d' WHERE `id`='%d'", ( GetTaxBusiness(i) + 1 ), i);
                mysql_query(IDConexao, query);
            }
        }
    }
    return 1;
}

stock GetTaxHouse(houseeid)
{
    new query[100], tax = 0;

    mysql_format(IDConexao, query, 100, "SELECT `IPTU` FROM `Houses` WHERE `id`='%d'", houseeid);
    mysql_query(IDConexao, query);

    if(cache_num_rows() == 0) return 0;

    cache_get_value_int(0, "IPTU", tax);
    return tax;
}

stock GetTaxBusiness(businessid)
{
    new query[100], tax = 0;

    mysql_format(IDConexao, query, 100, "SELECT `IPTU` FROM `Business` WHERE `id`='%d'", businessid);
    mysql_query(IDConexao, query);

    if(cache_num_rows() == 0) return 0;

    cache_get_value_int(0, "IPTU", tax);
    return tax;
}
