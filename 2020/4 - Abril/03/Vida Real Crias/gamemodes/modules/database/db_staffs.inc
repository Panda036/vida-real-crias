#include YSI\y_hooks

#define MAX_CARGO_STAFFS (7)

hook OnGameModeInit()
{
    new db_staffs[200];
    strins(db_staffs, "CREATE TABLE IF NOT EXISTS `Staffs` (", strlen(db_staffs));
    strins(db_staffs, "`nivel` int(1) AUTO_INCREMENT,", strlen(db_staffs));
    strins(db_staffs, "`code` varchar(30) NOT NULL,", strlen(db_staffs));
    strins(db_staffs, "PRIMARY KEY (`nivel`))", strlen(db_staffs));
    mysql_query(IDConexao, db_staffs, false);

    mysql_query(IDConexao, "TRUNCATE TABLE `Staffs`");

    for(new i = 1; i < MAX_CARGO_STAFFS; i++)
    {
        OnPlayerStaffsCoding();
    }
	return 1;
}

stock OnPlayerStaffsCoding()
{
    new query[200], coding[31];

    format(coding, 31, GetRandomString(30));

    mysql_format(IDConexao, query, sizeof(query), "SELECT `code` FROM `Staffs` WHERE `code`='%e'", coding);
    mysql_query(IDConexao, query);

    if(cache_num_rows() != 0)
        return OnPlayerStaffsCoding();

    mysql_format(IDConexao, query, sizeof(query), "INSERT INTO `Staffs` (`code`) VALUES ('%e')", coding);
    mysql_query(IDConexao, query);
    return 1;
}

