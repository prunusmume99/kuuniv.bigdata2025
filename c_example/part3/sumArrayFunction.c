#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int sumArray(int pArray[], int size);

int main(void)
{
    int nums[20] = {0};
    srand(time(NULL));
    for (int i=0; i < 20; ++i){
        nums[i] = rand () % 101;
        printf("%d, ", nums[i]);
    }
    printf("\n");

    int sum = sumArray(nums, sizeof(nums) / sizeof(int));
    printf("sum : %d\n", sum);
    return 0;
}

int sumArray(int pArray[], int size) {
    // 20 = sizeof(pArray)/sizeof(int)??
    // 배열을 넘길 때 반드시 주소와 사이즈를 같이 넘겨야 한다.
    // int *p = pArray;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += pArray[i];  // 배열의 각 원소를 누적
    }
    return sum;
}