#include <stdio.h>

int main(void){
    int nums1[] = {1, 2, 3, 4, 5};
    int nums2[5];

    // nums2 = nums1; deep copy
    for(int i = 0; i < 5; ++i){
        nums2[i] = nums1[i];
    }
    printf("nums1 의 주소값 %p", nums1); // = &nums1[0]
    printf("nums2 의 주소값 %p", nums2); // = &nums2[0]
    // nums1 과 nums2는 서로 독립적인 메모리이다.
    nums2[3] = 14;
    // shallow copy nums1 과 nums3 은 메모리를 공유한다.
    int *nums3;
    nums3 = nums1;
    printf("nums3의 주소값 %p", nums3);
    nums3[2] = 23;
    for(int i = 0; i < 5; ++i){
        printf("nums1 %d : %d \n", i, nums1[i]); 
        printf("nums2 %d : %d \n", i, nums2[i]);
        printf("nums3 %d : %d \n", i, nums3[i]);
    }
    return 0 ;
}