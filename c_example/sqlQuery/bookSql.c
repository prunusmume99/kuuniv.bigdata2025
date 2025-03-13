#include <mysql.h>
#include <stdio.h>
#include <string.h>
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
    SELECT,
    INSERT,
    DROP,
    ALTER,
    QUERY
};

void fetch_books(MYSQL *conn);
void add_books(MYSQL *conn);
void delete_books(MYSQL *conn);
void update_books(MYSQL *conn);
void query_books(MYSQL *conn);
void print_menu(void);

int main(void)
{
    MYSQL *conn;
    char *host = "localhost";
    char *user = "myuser";
    char *pass = "0124";
    char *db = "mydb";
    int port = 3306;
    int choice;

    // 연결
    conn = mysql_init(NULL); // DB 연결 요청 준비
    if (mysql_real_connect(conn, host, user, pass, db, port, NULL, 0))
        printf("MySQL 연결 성공\n");
    else
    {
        printf("MySQL 연결 실패\n");
        return 1;
    }
    while (true)
    {
        // printf("1 , 2 번 고르세요!");
        print_menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case SELECT:
            fetch_books(conn);
            break;
        case INSERT:
            add_books(conn);
            break;
        case DROP:
            delete_books(conn);
            break;
        case ALTER:
            update_books(conn);
            break;
        case QUERY:
            query_books(conn);
            break;
        }
    }

    mysql_close(conn);

    return 0;
}
void print_menu(void)
{
    system("clear");
    printf("=== 도서 관리 시스템 ===\n");
    printf("0. 도서 조회\n");
    printf("1. 도서 추가\n");
    printf("2. 도서 삭제\n");
    printf("3. 도서 변경\n");
    printf("4. 쿼리문 입력\n");
}

void add_books(MYSQL *conn)
{
    printf("--- 도서 추가 ---\n");
    Book newbook;
    char query[255];
    // 정보 입력 scanf
    printf("도서 ID: ");
    scanf("%d", &newbook.bookid);
    printf("도서 명: ");
    scanf("%s", newbook.bookname);
    printf("출판사: ");
    scanf("%s", newbook.publisher);
    printf("가격: ");
    scanf("%d", &newbook.price);
    // query 문 작성 strcpy... "insert ....."
    sprintf(query, "insert into Book values (%d, '%s', '%s', %d)", newbook.bookid, newbook.bookname, newbook.publisher, newbook.price);
    // query 요청 mysql_query();
    if (mysql_query(conn, query))
    {
        printf("데이터 입력 실패: %s\n", mysql_error(conn));
    }
    else
    {
        printf("입력 성공\n");
    }

    return;
}
void delete_books(MYSQL *conn)
{
    // index 번호 받기scanf
    // 지우는 쿼리

    int bookid;
    char query[256];
    
    printf("삭제할 도서의 id 입력: ");
    scanf("%d", &bookid);

    sprintf(query, "DELETE FROM Book WHERE bookid = %d", bookid);

    if(mysql_query(conn, query))
        printf("도서 삭제 실패: %s\n", mysql_error(conn));
    else
        printf("도서 삭제 성공\n");
}

void update_books(MYSQL *conn)
{
    // 모든 번호 받기scanf
    // 변경하는 쿼리

    int bookid, price;
    char bookname[100], publisher[100];
    char query[512];

    printf("수정할 도서의 ID 입력: ");
    scanf("%d", &bookid);
    printf("수정할 도서명 입력: ");
    scanf(" %99s", &bookname);
    printf("수정할 도서의 출판사명 입력: ");
    scanf(" %99s", &publisher);
    printf("수정할 도서의 가격 입력: ");
    scanf("%d", &price);

    sprintf(query,
        "UPDATE Book SET bookname='%s', publisher='%s', price=%d WHERE bookid=%d",
        bookname, publisher, price, bookid);
       
    if (mysql_query(conn, query))
        printf("도서 정보 수정 실패: %s\n", mysql_error(conn));
    else
        printf("도서 정보 수정 성공\n");

}
void query_books(MYSQL *conn)
{
    // 쿼리 스트링을 받아서
    // 쿼리 요청
    // 결과 프린트

    char query[256];
    MYSQL_RES *res;
    MYSQL_ROW row;

    printf("실행할 쿼리문 입력: ");
    // 공백이 포함된 쿼리문을 입력받기 위해 %[^\n] 사용
    scanf(" %[^\n]", query);

    if (mysql_query(conn, query)) {
        printf("쿼리 실행 실패: %s\n", mysql_error(conn));
        return;
    }

    res = mysql_store_result(conn);
    if (!res) {
        printf("결과 저장 실패: %s\n", mysql_error(conn));
        return;
    }

    int num_fields = mysql_num_fields(res);
    while ((row = mysql_fetch_row(res))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s\t", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }
    mysql_free_result(res);

    printf("엔터를 눌러 메뉴로 돌아갑니다.\n");
    getchar();  // 버퍼에 남은 개행 문자 제거
    getchar();  // 엔터 대기
}
void fetch_books(MYSQL *conn)
{
    MYSQL_RES *res;
    MYSQL_ROW row;
    char query[255];
    strcpy(query, "select * from Book");

    // 쿼리 요청
    if (mysql_query(conn, query))
    {
        printf("쿼리 실패");
        return;
    }
    res = mysql_store_result(conn);
    if (!res)
    {
        printf("가져오기 실패!\n");
        return;
    }
    Book *pBook;
    pBook = (Book *)malloc(sizeof(Book));
    int i = 0;
    // 데이터 베이스의 정보를 구조체에 저장 - ORM
    while (row = mysql_fetch_row(res))
    {
        (pBook + i)->bookid = atoi(row[0]);
        strcpy((pBook + i)->bookname, row[1]);
        strcpy((pBook + i)->publisher, row[2]);
        (pBook + i)->price = atoi(row[3]);
        ++i;
        pBook = realloc(pBook, i + 1);
    };
    for (int j = 0; j < i; ++j)
    {
        printf("%d \t%s \t%s \t%d \n",
               (pBook + j)->bookid, (pBook + j)->bookname,
               (pBook + j)->publisher, (pBook + j)->price);
    }
    free(pBook);
    // TODO: 여기 엔터만 쳐도 넘어가게 변경
    int temp;
    scanf("%d", &temp);
}