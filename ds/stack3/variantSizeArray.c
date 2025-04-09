#include <stdio.h>

int main(void){

int size;
scanf("%d", &size);

int array[size];  
// C99 99년 표준부터 가능함 - C++ 문법인데 C언어에 영향을 준 케이스 
// 중간부터 선언해도 실행 가능함 

for (int i = 0; i <size; ++i){
    array[i] = i +1;
}

for (int i = 0; i < size; ++i){
    printf("%d", array[i]);
}
printf("\n");

return 0;
}