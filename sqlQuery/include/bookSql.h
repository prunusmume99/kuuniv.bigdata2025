#pragma once

#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// sudo apt install libmysql++*
// dpkg -L libmysqlclient-dev | grep mysql.h
// cc -o bookSql bookSql.c -I/usr/include/mysql -L/usr/lib/mysql -lmysqlclient
// libmysqlclient.so libmysqlclient.a

typedef struct
{
    int bookid;
    char bookname[40];
    char publisher[40];
    int price;
} Book;

enum menu
{
    SELECT,  // 0. 도서 조회
    INSERT,  // 1. 도서 추가
    DROP,    // 2. 도서 삭제
    ALTER,   // 3. 도서 변경
    QUERY,   // 4. 쿼리문 입력
    EXIT     // 5. 시스템 종료
};

void fetch_books(MYSQL *conn);
void add_books(MYSQL *conn);
void delete_books(MYSQL *conn);
void update_books(MYSQL *conn);
void query_books(MYSQL *conn);
void print_menu(void);

// 함수 선언만!
void clear_input_buffer(void);