#include <stdio.h>

int main(void){
    int nums1[] = {1, 2, 3, 4, 5};
    int nums2[] = {1, 2, 3, 4, 5};

    if(nums1 == nums2){
        printf("nums1과 nums2는 같다\n");
    }
    else{
        printf("nums1과 nums2는 다르다\n");
    }

    int i;
    for(i =0; i < 5; ++i){
        if(nums1[i] != nums2[i])
        break;
    }
    if (i == 5) 
        printf("nums1 과 nums2의 원소는 모두 같다\n");
        else
        printf("nums1 과 nums2의 원소는 같지 않다\n");
    return 0;
}