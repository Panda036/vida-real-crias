#include YSI\y_hooks

#define MAX_TAX_HOUSE       7
#define MAX_TAX_BUSINESS    7
#define HOUSE_TAX_VALUE     250
#define BUSINESS_TAX_VALUE  250

stock SendTax()
{
    new query[100];

    for(new houseid = 0; houseid < MAX_HOUSES; houseid++)
    {
        mysql_format(IDConexao, query, 100, "SELECT `Nome` FROM `Houses` WHERE `Nome`='N/A' AND `id`='%d'", houseid);
        mysql_query(IDConexao, query);

        if(cache_num_rows()) continue;

        new tax = GetTaxHouse(houseid);

        if(tax >= MAX_TAX_HOUSE)
        {
            ReleaseHouse(houseid);
            mysql_format(IDConexao, query, 100, "UPDATE `Houses` SET `IPTU`='0' WHERE `id`='%d'", houseid);
        }
        else
        {
            mysql_format(IDConexao, query, 100, "UPDATE `Houses` SET `IPTU`='%d' WHERE `id`='%d'", (tax+1), houseid);
        }

        mysql_query(IDConexao, query);
        break;
    }
    for(new businessid = 0; businessid < MAX_BUSINESS; businessid++)
    {
        mysql_format(IDConexao, query, 100, "SELECT `Nome` FROM `Business` WHERE `Nome`='N/A' AND `id`='%d'", businessid);
        mysql_query(IDConexao, query);

        new tax = GetTaxBusiness(businessid);

        if(cache_num_rows()) continue;

        if(tax >= MAX_TAX_BUSINESS)
        {
            ReleaseBusiness(businessid);
            mysql_format(IDConexao, query, 100, "UPDATE `Business` SET `IPTU`='0' WHERE `id`='%d'", businessid);
        }
        else
        {
            mysql_format(IDConexao, query, 100, "UPDATE `Business` SET `IPTU`='%d' WHERE `id`='%d'", (tax+1), businessid);
        }

        mysql_query(IDConexao, query);
        break;
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
