#include <stdio.h>

int main(void){
    int nums[] = {1, 2, 3, 4, 5};
    int *p;

    p = nums; // nums 상수 - &nums[0] 이렇게 써도 작동함, 배열의 이름은 첫번째 주소값의 상수와 같다?
    for(int i =0; i < 5;++i){
        printf("%d 번째의 원소는 : %d\n", i, nums[i]);
        printf("%d 번째의 원소는 : %d\n", i, p[i]);
        printf("%d 번째의 원소는 : %d\n", i, *(p + i));
    }
    return 0;
}