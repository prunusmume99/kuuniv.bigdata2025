// 문자열을 쓰는 두 가지 방법 
#include <stdio.h>

int main(void)
{
    const char *str1 = "hello"; //변화를 줄 수 없다.
    char str2[] = "hello"; //변화를 줄 수 있다.
    char str3[] = {'h', 'e', 'l','l','o','\0'};
    char str4 = 'h';
    printf("%s\n", str1);
    printf("%s\n", str2);
    printf("%s\n", str3);
    printf("%c\n", str4);
    printf("%p\n", &str1);
    printf("%p\n", &str2);
    printf("%p\n", &str3);
    printf("%p\n", &str4);

    //str1[0] = 'H';
    printf("%s\n", str1);
    return 0;
}