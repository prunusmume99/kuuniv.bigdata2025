// 랜덤 한 수(0 ~ 100) 20개 프린트.
// qsort 정렬 후 프린트.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main(void)
{
    int nums[20] = {0};
    srand(time(NULL));
    for (int i = 0; i < 20; ++i)
    {
        nums[i] = rand() % 101;
    }
    for (int i = 0; i < 20; ++i)
        printf("%d", nums[i]);
    printf("\n");

    // bubble sorting
    qsort(nums, 20, sizeof(nums[0]), compare);

    for (int i = 0; i < 20; ++i)
        printf("%d, ", nums[i]);
    printf("\n");
    return 0;
}