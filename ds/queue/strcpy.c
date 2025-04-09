#include <stdio.h>

/*
void my_strcpy(char *des, const char *src) {
    int i = 0; 
    for (i=0 ; src[i] ; ++i) {
        des[i] = src[i];
    }
    des[i] = '\0';
}
*/

void my_strcpy(char *des, const char *src) {
    while (*des++ = *src++);
}

// 데니스 리치 책엔 이렇게 한줄로 적혀 있는데 위에 코드처럼 해석할 수 있어야함


int main(void) {
    char str[100];
    char *str2 = "hello, world";  // 괄호 제거

    // my_strcpy 함수 호출 (구현한 함수 이름과 일치시킴)
    my_strcpy(str, str2);
    printf("str : %s\n", str);

    return 0;
}
