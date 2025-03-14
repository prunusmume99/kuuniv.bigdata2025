#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// MySQL 접속 정보 (환경에 맞게 수정)
#define DB_HOST "localhost"
#define DB_USER "myuser"
#define DB_PASS "0124"
#define DB_NAME "mydb"
#define DB_PORT 3306

// 최대 투구 수 (최대 21회 : 10프레임에서 스트라이크나 스페어 발생 시)
#define MAX_ROLLS 21

// 함수 선언
void clear_input_buffer(void);
int manualGame(int rolls[], int *nRolls);
int autoGame(int rolls[], int *nRolls);
int calculateScore(const int rolls[], int nRolls);
void saveResult(MYSQL *conn, const char *player, const char *mode, int score);
void createTableIfNotExists(MYSQL *conn);

int main(void)
{
    MYSQL *conn;
    char player[50];
    int mode; // 1: 수동, 2: 자동
    int rolls[MAX_ROLLS] = {0};
    int nRolls = 0;
    int finalScore = 0;

    // MySQL 연결 준비
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, DB_PORT, NULL, 0)) {
        fprintf(stderr, "MySQL 연결 실패: %s\n", mysql_error(conn));
        exit(1);
    }
    printf("MySQL 연결 성공\n");

    // 결과 저장 테이블이 없으면 생성
    createTableIfNotExists(conn);

    // 플레이어 이름 입력
    printf("플레이어 이름을 입력하세요: ");
    if(fgets(player, sizeof(player), stdin) != NULL) {
        size_t len = strlen(player);
        if(len > 0 && player[len-1]=='\n') {
            player[len-1] = '\0';
        }
    }

    // 모드 선택
    printf("게임 모드를 선택하세요:\n");
    printf("1. 수동 모드 (직접 점수 입력)\n");
    printf("2. 자동 모드 (랜덤 점수 생성)\n");
    printf("선택: ");
    if(scanf("%d", &mode) != 1) {
        clear_input_buffer();
        fprintf(stderr, "잘못된 입력입니다.\n");
        exit(1);
    }
    clear_input_buffer();

    // 게임 실행
    if(mode == 1)
        finalScore = manualGame(rolls, &nRolls);
    else if(mode == 2) {
        srand((unsigned int) time(NULL));
        finalScore = autoGame(rolls, &nRolls);
    }
    else {
        fprintf(stderr, "잘못된 모드 선택\n");
        exit(1);
    }

    // 최종 점수 계산
    finalScore = calculateScore(rolls, nRolls);

    // 결과 출력
    printf("\n플레이어 %s님의 최종 점수: %d\n", player, finalScore);

    // 결과 SQL 테이블에 저장 (모드 문자열은 "Manual" 또는 "Auto")
    saveResult(conn, player, (mode==1) ? "Manual" : "Auto", finalScore);

    mysql_close(conn);
    return 0;
}

void clear_input_buffer(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

// manualGame: 사용자로부터 각 투구의 점수를 입력받음.
// 10프레임 볼링 게임 (10번째 프레임에서 보너스 투구 포함)
int manualGame(int rolls[], int *nRolls)
{
    int frame = 0;
    int roll = 0;
    int pins, firstRoll;
    *nRolls = 0;

    printf("\n[수동 모드]\n");
    for(frame = 1; frame <= 10; frame++) {
        printf("Frame %d:\n", frame);
        // 첫 번째 투구
        printf("  첫 번째 투구: ");
        if(scanf("%d", &pins) != 1) {
            clear_input_buffer();
            fprintf(stderr, "잘못된 입력\n");
            exit(1);
        }
        clear_input_buffer();
        rolls[(*nRolls)++] = pins;
        firstRoll = pins;

        // 10프레임의 경우
        if(frame == 10) {
            // 만약 스트라이크이면 2회 추가 투구
            if(firstRoll == 10) {
                printf("  두 번째 투구: ");
                if(scanf("%d", &pins) != 1) {
                    clear_input_buffer();
                    fprintf(stderr, "잘못된 입력\n");
                    exit(1);
                }
                clear_input_buffer();
                rolls[(*nRolls)++] = pins;

                printf("  세 번째 투구: ");
                if(scanf("%d", &pins) != 1) {
                    clear_input_buffer();
                    fprintf(stderr, "잘못된 입력\n");
                    exit(1);
                }
                clear_input_buffer();
                rolls[(*nRolls)++] = pins;
            }
            else {
                // 첫 번째 투구가 10이 아니라면 두 번째 투구
                printf("  두 번째 투구: ");
                if(scanf("%d", &pins) != 1) {
                    clear_input_buffer();
                    fprintf(stderr, "잘못된 입력\n");
                    exit(1);
                }
                clear_input_buffer();
                rolls[(*nRolls)++] = pins;
                if(firstRoll + pins == 10) {  // 스페어인 경우 보너스 투구
                    printf("  보너스 투구: ");
                    if(scanf("%d", &pins) != 1) {
                        clear_input_buffer();
                        fprintf(stderr, "잘못된 입력\n");
                        exit(1);
                    }
                    clear_input_buffer();
                    rolls[(*nRolls)++] = pins;
                }
            }
        }
        else {
            // 1~9프레임: 첫 번째 투구가 스트라이크이면 바로 다음 프레임으로,
            // 아니면 두 번째 투구 입력
            if(firstRoll == 10) {
                printf("  스트라이크!\n");
            }
            else {
                printf("  두 번째 투구: ");
                if(scanf("%d", &pins) != 1) {
                    clear_input_buffer();
                    fprintf(stderr, "잘못된 입력\n");
                    exit(1);
                }
                clear_input_buffer();
                rolls[(*nRolls)++] = pins;
            }
        }
    }
    return 0; // 실제 점수 계산은 별도의 함수에서 수행
}

// autoGame: 자동으로 랜덤 점수를 생성하여 게임 진행
int autoGame(int rolls[], int *nRolls)
{
    int frame, pins, firstRoll;
    *nRolls = 0;

    printf("\n[자동 모드]\n");
    for(frame = 1; frame <= 10; frame++) {
        printf("Frame %d:\n", frame);
        // 첫 번째 투구 (0~10)
        firstRoll = rand() % 11;
        rolls[(*nRolls)++] = firstRoll;
        printf("  첫 번째 투구: %d\n", firstRoll);

        if(frame == 10) {
            if(firstRoll == 10) { // 스트라이크: 두 번 더
                pins = rand() % 11;
                rolls[(*nRolls)++] = pins;
                printf("  두 번째 투구: %d\n", pins);
                pins = rand() % 11;
                rolls[(*nRolls)++] = pins;
                printf("  세 번째 투구: %d\n", pins);
            } else {
                // 두 번째 투구 (첫 투구와 합쳐 10 이하)
                pins = rand() % (11 - firstRoll);
                rolls[(*nRolls)++] = pins;
                printf("  두 번째 투구: %d\n", pins);
                if(firstRoll + pins == 10) { // 스페어: 보너스 투구
                    pins = rand() % 11;
                    rolls[(*nRolls)++] = pins;
                    printf("  보너스 투구: %d\n", pins);
                }
            }
        }
        else {
            if(firstRoll == 10) {
                printf("  스트라이크!\n");
            }
            else {
                // 두 번째 투구: 첫 투구와 합쳐 10 이하
                pins = rand() % (11 - firstRoll);
                rolls[(*nRolls)++] = pins;
                printf("  두 번째 투구: %d\n", pins);
            }
        }
    }
    return 0;
}

// calculateScore: 볼링 점수 계산 (스트라이크, 스페어 보너스 포함)
// 표준 볼링 점수 계산 방식 적용
int calculateScore(const int rolls[], int nRolls)
{
    int score = 0;
    int rollIndex = 0;
    int frame;
    for(frame = 0; frame < 10; frame++) {
        if(rolls[rollIndex] == 10) { // 스트라이크
            score += 10 + rolls[rollIndex + 1] + rolls[rollIndex + 2];
            rollIndex += 1;
        } else if(rolls[rollIndex] + rolls[rollIndex + 1] == 10) { // 스페어
            score += 10 + rolls[rollIndex + 2];
            rollIndex += 2;
        } else { // 일반 프레임
            score += rolls[rollIndex] + rolls[rollIndex + 1];
            rollIndex += 2;
        }
    }
    return score;
}

// createTableIfNotExists: 볼링 결과 저장 테이블 생성 (존재하지 않을 경우)
void createTableIfNotExists(MYSQL *conn)
{
    const char *query =
        "CREATE TABLE IF NOT EXISTS BowlingResults ("
        "id INT AUTO_INCREMENT PRIMARY KEY, "
        "player VARCHAR(50), "
        "mode VARCHAR(20), "
        "score INT, "
        "playtime DATETIME DEFAULT CURRENT_TIMESTAMP)";
    if(mysql_query(conn, query)) {
        fprintf(stderr, "테이블 생성 실패: %s\n", mysql_error(conn));
        exit(1);
    }
}

// saveResult: 게임 결과를 데이터베이스에 저장
void saveResult(MYSQL *conn, const char *player, const char *mode, int score)
{
    char query[512];
    snprintf(query, sizeof(query),
             "INSERT INTO BowlingResults (player, mode, score) VALUES ('%s', '%s', %d)",
             player, mode, score);
    if(mysql_query(conn, query)) {
        fprintf(stderr, "결과 저장 실패: %s\n", mysql_error(conn));
    }
    else {
        printf("게임 결과가 데이터베이스에 저장되었습니다.\n");
    }
}
