#include "bookSql.h"

void clear_input_buffer(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
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
    printf("5. 시스템 종료\n");
}

void add_books(MYSQL *conn)
{
    printf("--- 도서 추가 ---\n");
    Book newbook;
    char query[255];

    printf("도서 ID: ");
    scanf("%d", &newbook.bookid);
    clear_input_buffer();
    
    printf("도서 명: ");
    scanf("%s", newbook.bookname);
    clear_input_buffer();
    
    printf("출판사: ");
    scanf("%s", newbook.publisher);
    clear_input_buffer();
    
    printf("가격: ");
    scanf("%d", &newbook.price);
    clear_input_buffer();

    sprintf(query, "INSERT INTO Book VALUES (%d, '%s', '%s', %d)",
            newbook.bookid, newbook.bookname, newbook.publisher, newbook.price);
    if (mysql_query(conn, query))
        printf("데이터 입력 실패: %s\n", mysql_error(conn));
    else
        printf("입력 성공\n");

    printf("엔터를 눌러 메뉴로 돌아갑니다.\n");
    getchar();
}

void delete_books(MYSQL *conn)
{
    int bookid;
    char query[256];

    printf("삭제할 도서의 ID 입력: ");
    scanf("%d", &bookid);
    clear_input_buffer();

    sprintf(query, "DELETE FROM Book WHERE bookid = %d", bookid);
    if (mysql_query(conn, query))
        printf("도서 삭제 실패: %s\n", mysql_error(conn));
    else
        printf("도서 삭제 성공\n");

    printf("엔터를 눌러 메뉴로 돌아갑니다.\n");
    getchar();
}

void update_books(MYSQL *conn)
{
    int bookid, price;
    char bookname[100], publisher[100];
    char query[512];

    printf("수정할 도서의 ID 입력: ");
    scanf("%d", &bookid);
    clear_input_buffer();
    
    printf("수정할 도서명 입력: ");
    scanf("%s", bookname);
    clear_input_buffer();
    
    printf("수정할 도서의 출판사명 입력: ");
    scanf("%s", publisher);
    clear_input_buffer();
    
    printf("수정할 도서의 가격 입력: ");
    scanf("%d", &price);
    clear_input_buffer();

    sprintf(query,
        "UPDATE Book SET bookname='%s', publisher='%s', price=%d WHERE bookid=%d",
        bookname, publisher, price, bookid);
       
    if (mysql_query(conn, query))
        printf("도서 정보 수정 실패: %s\n", mysql_error(conn));
    else
        printf("도서 정보 수정 성공\n");

    printf("엔터를 눌러 메뉴로 돌아갑니다.\n");
    getchar();
}

void query_books(MYSQL *conn)
{
    char query[256];
    MYSQL_RES *res;
    MYSQL_ROW row;

    printf("실행할 쿼리문 입력: ");
    // 공백 포함 입력을 위해 %[^\n] 사용
    scanf(" %255[^\n]", query);
    clear_input_buffer();

    if (mysql_query(conn, query))
    {
        printf("쿼리 실행 실패: %s\n", mysql_error(conn));
        printf("엔터를 눌러 메뉴로 돌아갑니다.\n");
        getchar();
        return;
    }

    res = mysql_store_result(conn);
    if (!res)
    {
        printf("결과 저장 실패: %s\n", mysql_error(conn));
        printf("엔터를 눌러 메뉴로 돌아갑니다.\n");
        getchar();
        return;
    }

    int num_fields = mysql_num_fields(res);
    while ((row = mysql_fetch_row(res)))
    {
        for (int i = 0; i < num_fields; i++)
        {
            printf("%s\t", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }
    mysql_free_result(res);

    printf("엔터를 눌러 메뉴로 돌아갑니다.\n");
    getchar();
}

void fetch_books(MYSQL *conn)
{
    MYSQL_RES *res;
    MYSQL_ROW row;
    char query[255];
    strcpy(query, "SELECT * FROM Book");

    if (mysql_query(conn, query))
    {
        printf("쿼리 실패: %s\n", mysql_error(conn));
        printf("엔터를 눌러 메뉴로 돌아갑니다.\n");
        getchar();
        return;
    }
    res = mysql_store_result(conn);
    if (!res)
    {
        printf("가져오기 실패: %s\n", mysql_error(conn));
        printf("엔터를 눌러 메뉴로 돌아갑니다.\n");
        getchar();
        return;
    }
   
    Book *pBook = (Book *)malloc(sizeof(Book));
    int i = 0;
    // 데이터베이스의 정보를 구조체에 저장
    while ((row = mysql_fetch_row(res)))
    {
        (pBook + i)->bookid = atoi(row[0]);
        strcpy((pBook + i)->bookname, row[1]);
        strcpy((pBook + i)->publisher, row[2]);
        (pBook + i)->price = atoi(row[3]);
        ++i;
        pBook = realloc(pBook, sizeof(Book) * (i + 1));
    }
    for (int j = 0; j < i; ++j)
    {
        printf("%d \t%s \t%s \t%d \n",
               (pBook + j)->bookid, (pBook + j)->bookname,
               (pBook + j)->publisher, (pBook + j)->price);
    }
    free(pBook);
    mysql_free_result(res);

    printf("엔터를 눌러 메뉴로 돌아갑니다.\n");
    getchar();
}