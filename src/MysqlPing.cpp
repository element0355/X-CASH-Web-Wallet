//
// Created by mwo on 12/07/18.
//

#include "easylogging++.h"
#include "om_log.h"

#include "MysqlPing.h"


namespace xmreg
{

MysqlPing::MysqlPing(
        std::shared_ptr<MySqlConnector> _conn,
        uint64_t _ping_time)
        : conn {_conn}, ping_time {_ping_time}
{}

void
MysqlPing::operator()()
{
    while (keep_looping)
    {
        std::this_thread::sleep_for(chrono::seconds(ping_time));

        OMINFO << "Mysql ping is ignored." ;

        ++counter;
    }
}

}
