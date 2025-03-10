#include <stdio.h>

// 함수 원형: 2차원 배열(각 행은 int[4])의 포인터, 행의 개수 n, 열의 개수 m
int sumMatrix(int (*pM)[4], int n, int m);

int main(void){
    // 올바른 2차원 배열 초기화
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {11, 12, 13, 14},
        {21, 22, 23, 24}
    };

    // 2차원 배열의 전체 크기 / 한 행의 크기 = 행의 개수 (3)
    int n = sizeof(matrix) / sizeof(matrix[0]);
    // 한 행의 크기 / int의 크기 = 열의 개수 (4)
    int m = sizeof(matrix[0]) / sizeof(int);

    // sumMatrix 함수를 호출할 때 n, m 모두 넘겨야 함
    int sum = sumMatrix(matrix, n, m);

    printf("sum of Matrix : %d\n", sum);
    return 0;
}

int sumMatrix(int (*pM)[4], int n, int m){
    int sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            sum += pM[i][j];
        }
    }
    return sum;
}
