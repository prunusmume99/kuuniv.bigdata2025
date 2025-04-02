#include "bookSql.h"

int main(void)
{
    MYSQL *conn;
    char *host = "localhost";
    char *user = "myuser";
    char *pass = "0124";
    char *db = "mydb";
    int port = 3306;
    int choice;

    conn = mysql_init(NULL);
    if (mysql_real_connect(conn, host, user, pass, db, port, NULL, 0))
        printf("MySQL 연결 성공\n");
    else
    {
        printf("MySQL 연결 실패: %s\n", mysql_error(conn));
        return 1;
    }

    while (1)
    {
        print_menu();
        printf("메뉴 선택: ");
        if (scanf("%d", &choice) != 1)
        {
            clear_input_buffer();
            printf("잘못된 입력입니다.\n");
            continue;
        }
        clear_input_buffer(); // 개행 문자 제거

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
        case EXIT:
            printf("시스템을 종료합니다.\n");
            mysql_close(conn);
            exit(0);
        default:
            printf("잘못된 선택입니다. 다시 입력해주세요.\n");
            break;
        }
    }

    mysql_close(conn);
    return 0;
}
