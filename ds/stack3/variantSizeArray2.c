#include <stdio.h>
#include <stdlib.h>

int main(void){

int size;
scanf("%d", &size);

// int array[size];  
// C99 99년 표준부터 가능함 - C++ 문법인데 C언어에 영향을 준 케이스 
// 중간부터 선언해도 실행 가능함 
int *pArr = malloc(sizeof(int) * size);
// 동적할당을 위해 힙 영역 공간 할당 sizeof(int)로 int (2바이트, 4바이트) 둘다 가능
// pArr == NULL ???


for (int i = 0; i <size; ++i){
    //*(pArr + i) = i + 1; // 힙 상에 할당된 각각의 공간들을 가리킴 역참조 
    pArr[i] = i + 1;
}

for (int i = 0; i < size; ++i){
    //printf("%d", *(pArr+ i));
    printf("%d", pArr[i]);
}
printf("\n");
free(pArr);
return 0;
}


//GPT 설명 코드

// #include <stdio.h>
// #include <stdlib.h> // malloc, free를 사용하기 위해 필요

// int main() {
//     int size;
//     printf("배열의 크기를 입력하세요: ");
//     scanf("%d", &size);  // 사용자로부터 배열 크기 입력 받음

//     // 힙 영역에 int형 size개의 공간 동적 할당
//     int *pArr = (int*)malloc(sizeof(int) * size);

//     // 메모리 할당 실패 시 예외 처리
//     if (pArr == NULL) {
//         printf("메모리 할당 실패\n");
//         return 1;
//     }

//     // 첫 번째 for문: 배열의 각 요소에 값 저장
//     for (int i = 0; i < size; ++i) {
//         *(pArr + i) = i + 1;  // i번째 요소에 i+1 값을 저장 (예: 1, 2, 3, ...)
//         // pArr[i] = i + 1; 와 동일한 표현
//     }

//     // 두 번째 for문: 배열의 각 요소 출력
//     for (int i = 0; i < size; ++i) {
//         printf("%d ", *(pArr + i));  // 저장된 실제 값을 출력
//         // printf("%d ", pArr[i]); 도 동일하게 작동함
//     }
//     printf("\n");  // 줄바꿈

//     // 동적으로 할당한 메모리 해제
//     free(pArr);

//     return 0;
// }
