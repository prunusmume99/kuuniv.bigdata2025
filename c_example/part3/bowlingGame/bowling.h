#ifndef BOWLING_H
#define BOWLING_H

#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DB_HOST "localhost"
#define DB_USER "myuser"
#define DB_PASS "0124"
#define DB_NAME "mydb"
#define DB_PORT 3306

#define MAX_ROLLS 21

// 플레이어 정보를 담을 구조체
typedef struct {
    char name[50];
    int rolls[MAX_ROLLS];
    int nRolls;
    int finalScore;
} Player;

// 함수 프로토타입 선언
void clear_input_buffer(void);
void manualGamePlayer(Player *p);
void autoGamePlayer(Player *p);
int calculateScore(const int rolls[], int nRolls);
void displayScoreBoard(const int rolls[], int nRolls, const char *playerName);
void compareResults(Player p1, Player p2);
void saveResult(MYSQL *conn, const char *player, int score);
void createTablesIfNotExists(MYSQL *conn);
int getBiasedFirstAttempt(void);
void displaySQLResults(MYSQL *conn);

#endif /* BOWLING_H */
