// * 이 프로그램은  int 와 float 값의 연산을 데모하는 프로그램입니다.
#include <stdio.h>

int main()
{
    int celsius;
    
    printf("input celsius temp: ? ");
    scanf("%d", &celsius);
    printf("celsius temp : %d\n", celsius);

    double fahr;
    // 9/5를 하면 결과가 int여서 1이 된다.
    fahr = 9.0 / 5.0 * celsius + 32;
    printf("fahr temp : %f\n", fahr);

    return 0;
}
