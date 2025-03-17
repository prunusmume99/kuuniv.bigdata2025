#include "bowling.h"

void clear_input_buffer(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int getBiasedFirstAttempt(void)
{
    int chance = rand() % 100;
    if (chance < 60) {
        int value = (rand() % 4) + 7;  // 7 ~ 10
        return value > 10 ? 10 : value;
    } else {
        return rand() % 11;
    }
}

void manualGamePlayer(Player *p)
{
    int frame, pins, firstAttempt, secondAttempt;
    p->nRolls = 0;

    for (frame = 1; frame <= 10; frame++) {
        printf("\n[%s] Frame %d 시작\n", p->name, frame);
        printf("  첫 번째 투구: ");
        if (scanf("%d", &pins) != 1) {
            clear_input_buffer();
            fprintf(stderr, "잘못된 입력\n");
            exit(1);
        }
        clear_input_buffer();
        p->rolls[p->nRolls++] = pins;
        firstAttempt = pins;
        printf("  결과: 첫 번째 투구에서 %d개의 핀을 쓰러뜨렸습니다.\n", firstAttempt);

        if (frame == 10) {
            if (firstAttempt == 10) {
                printf("  스트라이크! 10프레임 보너스 투구 진행.\n");
                printf("  두 번째 투구: ");
                if (scanf("%d", &pins) != 1) {
                    clear_input_buffer();
                    fprintf(stderr, "잘못된 입력\n");
                    exit(1);
                }
                clear_input_buffer();
                p->rolls[p->nRolls++] = pins;
                printf("  결과: 두 번째 투구에서 %d개의 핀을 쓰러뜨렸습니다.\n", pins);

                printf("  세 번째 투구: ");
                if (scanf("%d", &pins) != 1) {
                    clear_input_buffer();
                    fprintf(stderr, "잘못된 입력\n");
                    exit(1);
                }
                clear_input_buffer();
                p->rolls[p->nRolls++] = pins;
                printf("  결과: 세 번째 투구에서 %d개의 핀을 쓰러뜨렸습니다.\n", pins);
            } else {
                printf("  두 번째 투구: ");
                if (scanf("%d", &pins) != 1) {
                    clear_input_buffer();
                    fprintf(stderr, "잘못된 입력\n");
                    exit(1);
                }
                clear_input_buffer();
                p->rolls[p->nRolls++] = pins;
                secondAttempt = pins;
                printf("  결과: 두 번째 투구에서 %d개의 핀을 쓰러뜨렸습니다.\n", secondAttempt);
                if (firstAttempt + secondAttempt == 10) {
                    printf("  스페어! 10프레임 보너스 투구 진행.\n");
                    printf("  보너스 투구: ");
                    if (scanf("%d", &pins) != 1) {
                        clear_input_buffer();
                        fprintf(stderr, "잘못된 입력\n");
                        exit(1);
                    }
                    clear_input_buffer();
                    p->rolls[p->nRolls++] = pins;
                    printf("  결과: 보너스 투구에서 %d개의 핀을 쓰러뜨렸습니다.\n", pins);
                } else {
                    printf("  오픈 프레임입니다. 이번 프레임 점수: %d점\n", firstAttempt + secondAttempt);
                }
            }
        } else {
            if (firstAttempt == 10) {
                printf("  스트라이크! 이번 프레임 점수는 10점 + 다음 두 투구 보너스.\n");
            } else {
                printf("  두 번째 투구: ");
                if (scanf("%d", &pins) != 1) {
                    clear_input_buffer();
                    fprintf(stderr, "잘못된 입력\n");
                    exit(1);
                }
                clear_input_buffer();
                p->rolls[p->nRolls++] = pins;
                secondAttempt = pins;
                printf("  결과: 두 번째 투구에서 %d개의 핀을 쓰러뜨렸습니다.\n", secondAttempt);
                if (firstAttempt + secondAttempt == 10) {
                    printf("  스페어! 이번 프레임 점수는 10점 + 다음 투구 보너스.\n");
                } else {
                    printf("  오픈 프레임입니다. 이번 프레임 점수: %d점\n", firstAttempt + secondAttempt);
                }
            }
        }
    }
}

void autoGamePlayer(Player *p)
{
    int frame, pins, firstAttempt, secondAttempt;
    p->nRolls = 0;

    for (frame = 1; frame <= 10; frame++) {
        printf("\n[%s] Frame %d 시작\n", p->name, frame);
        firstAttempt = getBiasedFirstAttempt();
        p->rolls[p->nRolls++] = firstAttempt;
        printf("  첫 번째 투구: %d (랜덤 생성)\n", firstAttempt);
        printf("  결과: 첫 번째 투구에서 %d개의 핀을 쓰러뜨렸습니다.\n", firstAttempt);

        if (frame == 10) {
            if (firstAttempt == 10) {
                printf("  스트라이크! 10프레임 보너스 투구 진행.\n");
                pins = rand() % 11;
                p->rolls[p->nRolls++] = pins;
                printf("  두 번째 투구: %d (랜덤 생성)\n", pins);
                printf("  결과: 두 번째 투구에서 %d개의 핀을 쓰러뜨렸습니다.\n", pins);
                pins = rand() % 11;
                p->rolls[p->nRolls++] = pins;
                printf("  세 번째 투구: %d (랜덤 생성)\n", pins);
                printf("  결과: 세 번째 투구에서 %d개의 핀을 쓰러뜨렸습니다.\n", pins);
            } else {
                pins = rand() % (11 - firstAttempt);
                p->rolls[p->nRolls++] = pins;
                printf("  두 번째 투구: %d (랜덤 생성)\n", pins);
                printf("  결과: 두 번째 투구에서 %d개의 핀을 쓰러뜨렸습니다.\n", pins);
                if (firstAttempt + pins == 10) {
                    printf("  스페어! 10프레임 보너스 투구 진행.\n");
                    pins = rand() % 11;
                    p->rolls[p->nRolls++] = pins;
                    printf("  보너스 투구: %d (랜덤 생성)\n", pins);
                    printf("  결과: 보너스 투구에서 %d개의 핀을 쓰러뜨렸습니다.\n", pins);
                } else {
                    printf("  오픈 프레임입니다. 이번 프레임 점수: %d점\n", firstAttempt + pins);
                }
            }
        } else {
            if (firstAttempt == 10) {
                printf("  스트라이크! 이번 프레임 점수는 10점 + 다음 두 투구 보너스.\n");
            } else {
                pins = rand() % (11 - firstAttempt);
                p->rolls[p->nRolls++] = pins;
                printf("  두 번째 투구: %d (랜덤 생성)\n", pins);
                printf("  결과: 두 번째 투구에서 %d개의 핀을 쓰러뜨렸습니다.\n", pins);
                if (firstAttempt + pins == 10) {
                    printf("  스페어! 이번 프레임 점수는 10점 + 다음 투구 보너스.\n");
                } else {
                    printf("  오픈 프레임입니다. 이번 프레임 점수: %d점\n", firstAttempt + pins);
                }
            }
        }
    }
}

int calculateScore(const int rolls[], int nRolls)
{
    int score = 0;
    int rollIndex = 0;
    for (int frame = 0; frame < 10; frame++) {
        if (rolls[rollIndex] == 10) {
            score += 10 + rolls[rollIndex + 1] + rolls[rollIndex + 2];
            rollIndex++;
        } else if (rolls[rollIndex] + rolls[rollIndex + 1] == 10) {
            score += 10 + rolls[rollIndex + 2];
            rollIndex += 2;
        } else {
            score += rolls[rollIndex] + rolls[rollIndex + 1];
            rollIndex += 2;
        }
    }
    return score;
}

void displayScoreBoard(const int rolls[], int nRolls, const char *playerName)
{
    int frameScores[10] = {0};
    int cumulative[10] = {0};
    int rollIndex = 0;
    int frame;
    for (frame = 0; frame < 10; frame++) {
        if (rolls[rollIndex] == 10) {
            frameScores[frame] = 10 + rolls[rollIndex + 1] + rolls[rollIndex + 2];
            rollIndex++;
        } else if (rolls[rollIndex] + rolls[rollIndex + 1] == 10) {
            frameScores[frame] = 10 + rolls[rollIndex + 2];
            rollIndex += 2;
        } else {
            frameScores[frame] = rolls[rollIndex] + rolls[rollIndex + 1];
            rollIndex += 2;
        }
        cumulative[frame] = (frame == 0) ? frameScores[0] : cumulative[frame - 1] + frameScores[frame];
    }

    printf("\n[%s의 볼링 스코어보드]\n", playerName);
    printf("+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+\n");
    printf("|");
    for (frame = 0; frame < 10; frame++) {
        printf(" Frame%-3d|", frame + 1);
    }
    printf("\n+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+\n");
    printf("|");
    for (frame = 0; frame < 10; frame++) {
        printf("   %-4d |", frameScores[frame]);
    }
    printf("\n+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+\n");
    printf("|");
    for (frame = 0; frame < 10; frame++) {
        printf(" Cumul%-3d|", cumulative[frame]);
    }
    printf("\n+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+\n");
}

void compareResults(Player p1, Player p2)
{
    printf("\n=== 최종 결과 비교 ===\n");
    printf("%s: %d점\n", p1.name, p1.finalScore);
    printf("%s: %d점\n", p2.name, p2.finalScore);
    if (p1.finalScore > p2.finalScore)
        printf("승자: %s\n", p1.name);
    else if (p2.finalScore > p1.finalScore)
        printf("승자: %s\n", p2.name);
    else
        printf("두 플레이어의 점수가 같습니다. 무승부입니다.\n");
}

void createTablesIfNotExists(MYSQL *conn)
{
    const char *query1 =
        "CREATE TABLE IF NOT EXISTS GameResults ("
        "id INT AUTO_INCREMENT PRIMARY KEY, "
        "username VARCHAR(50), "
        "score INT, "
        "game_date DATETIME DEFAULT CURRENT_TIMESTAMP"
        ")";
    if (mysql_query(conn, query1)) {
        fprintf(stderr, "GameResults 테이블 생성 실패: %s\n", mysql_error(conn));
        exit(1);
    }

    const char *query2 =
        "CREATE TABLE IF NOT EXISTS UserGameCount ("
        "username VARCHAR(50), "
        "game_date DATE, "
        "game_count INT, "
        "PRIMARY KEY(username, game_date)"
        ")";
    if (mysql_query(conn, query2)) {
        fprintf(stderr, "UserGameCount 테이블 생성 실패: %s\n", mysql_error(conn));
        exit(1);
    }
}

void saveResult(MYSQL *conn, const char *player, int score)
{
    char query[512];
    snprintf(query, sizeof(query),
             "INSERT INTO GameResults (username, score) VALUES ('%s', %d)",
             player, score);
    if (mysql_query(conn, query)) {
        fprintf(stderr, "게임 결과 저장 실패: %s\n", mysql_error(conn));
        return;
    }
    snprintf(query, sizeof(query),
             "INSERT INTO UserGameCount (username, game_date, game_count) "
             "VALUES ('%s', CURDATE(), 1) "
             "ON DUPLICATE KEY UPDATE game_count = game_count + 1",
             player);
    if (mysql_query(conn, query)) {
        fprintf(stderr, "게임 횟수 업데이트 실패: %s\n", mysql_error(conn));
        return;
    }
    printf("\n%s님의 게임 결과 및 게임 횟수가 데이터베이스에 저장되었습니다.\n", player);
}

void displaySQLResults(MYSQL *conn)
{
    MYSQL_RES *res;
    MYSQL_ROW row;

    if (mysql_query(conn, "SELECT id, username, score, game_date FROM GameResults ORDER BY game_date DESC")) {
        fprintf(stderr, "GameResults 조회 실패: %s\n", mysql_error(conn));
    } else {
        res = mysql_store_result(conn);
        if (res == NULL) {
            fprintf(stderr, "GameResults 결과 저장 실패: %s\n", mysql_error(conn));
        } else {
            printf("\n[GameResults 테이블]\n");
            printf("ID\tUsername\tScore\tGame Date\n");
            while ((row = mysql_fetch_row(res)) != NULL) {
                printf("%s\t%s\t%s\t%s\n", row[0], row[1], row[2], row[3]);
            }
            mysql_free_result(res);
        }
    }

    if (mysql_query(conn, "SELECT username, game_date, game_count FROM UserGameCount ORDER BY game_date DESC")) {
        fprintf(stderr, "UserGameCount 조회 실패: %s\n", mysql_error(conn));
    } else {
        res = mysql_store_result(conn);
        if (res == NULL) {
            fprintf(stderr, "UserGameCount 결과 저장 실패: %s\n", mysql_error(conn));
        } else {
            printf("\n[UserGameCount 테이블]\n");
            printf("Username\tGame Date\tGame Count\n");
            while ((row = mysql_fetch_row(res)) != NULL) {
                printf("%s\t%s\t%s\n", row[0], row[1], row[2]);
            }
            mysql_free_result(res);
        }
    }
}
