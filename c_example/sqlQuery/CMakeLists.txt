cmake_minimum_required(VERSION 3.00)
project(bookSql)

set(CMAKE_C_COMPILER "/usr/bin/gcc")

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(bookSql /home/yj/kuuniv.bigdata2025/c_example/sqlQuery/bookSql.c)
target_include_directories(bookSql PRIVATE /usr/include/mysql)
target_link_directories(bookSql PRIVATE /usr/lib/mysql)
target_link_libraries(bookSql PRIVATE mysqlclient)