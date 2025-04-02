#include "bowling.h"

int main(void)
{
    MYSQL *conn;
    Player player1, player2;
    int mode; // 1: 수동, 2: 자동
    char answer;

    // MySQL 연결 준비
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, DB_PORT, NULL, 0)) {
        fprintf(stderr, "MySQL 연결 실패: %s\n", mysql_error(conn));
        exit(1);
    }
    printf("MySQL 연결 성공\n");

    // 결과 저장 테이블 생성
    createTablesIfNotExists(conn);

    // 플레이어 이름 입력
    printf("플레이어 1의 이름을 입력하세요: ");
    if (fgets(player1.name, sizeof(player1.name), stdin) != NULL) {
        size_t len = strlen(player1.name);
        if (len > 0 && player1.name[len - 1] == '\n')
            player1.name[len - 1] = '\0';
    }
    printf("플레이어 2의 이름을 입력하세요: ");
    if (fgets(player2.name, sizeof(player2.name), stdin) != NULL) {
        size_t len = strlen(player2.name);
        if (len > 0 && player2.name[len - 1] == '\n')
            player2.name[len - 1] = '\0';
    }

    // 게임 모드 선택
    printf("\n게임 모드를 선택하세요:\n");
    printf("1. 수동 모드 (직접 점수 입력)\n");
    printf("2. 자동 모드 (랜덤 점수 생성)\n");
    printf("선택: ");
    if (scanf("%d", &mode) != 1) {
        clear_input_buffer();
        fprintf(stderr, "잘못된 입력입니다.\n");
        exit(1);
    }
    clear_input_buffer();

    // 플레이어 1 게임 진행
    printf("\n[%s의 게임 진행]\n", player1.name);
    if (mode == 1)
        manualGamePlayer(&player1);
    else if (mode == 2) {
        srand((unsigned int) time(NULL));
        autoGamePlayer(&player1);
    } else {
        fprintf(stderr, "잘못된 모드 선택\n");
        exit(1);
    }

    // 플레이어 2 게임 진행
    printf("\n[%s의 게임 진행]\n", player2.name);
    if (mode == 1)
        manualGamePlayer(&player2);
    else if (mode == 2) {
        srand((unsigned int) time(NULL) + 1);
        autoGamePlayer(&player2);
    }

    // 최종 점수 계산 및 스코어보드 출력
    player1.finalScore = calculateScore(player1.rolls, player1.nRolls);
    player2.finalScore = calculateScore(player2.rolls, player2.nRolls);

    printf("\n플레이어 %s님의 최종 점수: %d점\n", player1.name, player1.finalScore);
    displayScoreBoard(player1.rolls, player1.nRolls, player1.name);
    fflush(stdout);

    printf("\n플레이어 %s님의 최종 점수: %d점\n", player2.name, player2.finalScore);
    displayScoreBoard(player2.rolls, player2.nRolls, player2.name);
    fflush(stdout);

    // 두 플레이어 결과 비교 및 승자 출력
    compareResults(player1, player2);

    // DB에 결과 저장
    saveResult(conn, player1.name, player1.finalScore);
    saveResult(conn, player2.name, player2.finalScore);
    printf("\n게임 결과 및 점수가 데이터베이스에 저장되었습니다.\n");

    // SQL 테이블 결과 확인 메뉴
    do {
        printf("\n결과값을 다시 확인하시겠습니까? (Y/N): ");
        if (scanf(" %c", &answer) != 1) {
            clear_input_buffer();
            continue;
        }
        clear_input_buffer();
        if (answer == 'Y' || answer == 'y') {
            displaySQLResults(conn);
        }
    } while (answer == 'Y' || answer == 'y');

    printf("프로그램을 종료합니다.\n");
    mysql_close(conn);
    return 0;
}
