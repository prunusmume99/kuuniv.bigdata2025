#include <stdio.h>

int main(void)
{
    int length;
    int height;
    int area;

    printf("Enter triangle's length : ");
    scanf("%d", &length);
    printf("Enter triangle's height : ");
    scanf("%d", &height);

    area = length * height / 2;

    printf("Triangle's area is: %d\n", area); 
    return 0;
}
