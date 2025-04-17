#include <stdio.h>

int main(void) {
    int nums[]  = { 1, 2, 3, 4, 5 };
    int nums2[5];                 // nums2 선언 추가
    int *p = nums;                // p = &nums[0] 과 동일

    // 포인터 연산 출력
    printf("*p           : %d\n", *p);
    printf("*(p + 1)     : %d\n", *(p + 1));  // %d로 수정

    // nums → nums2 복사
    for (int i = 0; i < 5; ++i) {
        nums2[i] = nums[i];
    }

    printf("nums2        : ");
    for (int i = 0; i < 5; ++i) {
        printf("%d ", nums2[i]);  // nums2 출력으로 수정
    }
    printf("\n");

    // 배열 비교 (요소별)
    int nums3[] = { 1, 2, 3, 4, 5 };
    int nums4[] = { 1, 2, 3, 4, 5 };

    int i;
    for (i = 0; i < 5; ++i) {
        if (nums3[i] != nums4[i]) {
            break;
        }
    }

    if (i == 5) {                  // 대입(=) → 비교(==)로 수정
        printf("nums3 and nums4 are equal\n");
    } else {
        printf("nums3 and nums4 are not equal\n");
    }

    return 0;
}
