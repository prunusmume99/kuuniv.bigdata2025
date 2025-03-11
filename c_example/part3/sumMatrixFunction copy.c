#include <stdio.h>

int sumMatrix(int *pM, int n, int m);

int main(void)
{
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {11, 12, 13, 14},
        {21, 22, 23, 24}};
    int sum = sumMatrix(matrix[0], (sizeof(matrix) / sizeof(int)) / (sizeof(matrix[0]) / sizeof(int)), sizeof(matrix[0]) / sizeof(int));
    printf("sum of Matrix : %d", sum);
    return 0;
}

int sumMatrix(int *pM, int n, int m)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            // sum += pM[i][j];
            sum += *(pM + j + i * 3);
            // sum += *(*(pM + i) + j);
        }
    }
    return sum;
}