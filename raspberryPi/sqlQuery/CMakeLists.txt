cmake_minimum_required(VERSION 3.10)
project(bookSql)

set(SOURCES
    src/bookSql.c
    src/main.c
)

add_executable(bookSql ${SOURCES})
target_include_directories(bookSql PRIVATE include)

# library setting
target_include_directories(bookSql PRIVATE /usr/include/mysql)
target_link_directories(bookSql PRIVATE /usr/lib/mysql)
target_link_libraries(bookSql PRIVATE mysqlclient)