#include <stdio.h>
#include <string.h>

int main(void){
    const char * str1= "hello, world";
    char str2[] = "stack char array";
    int str1Len = strlen(str1);
    int str2Len = strlen(str2);
    printf("str1Len : %d str2Len : %d\n", str1Len, str2Len);
   
   char str3[30];
   strcpy(str3, str1);
   str3[0] = 'H';
   printf("%s\n", str3);
   
    if(strcmp(str1, str3) == 0)
    {
        printf("두 문자열 str1, str2는 같다.\n");
    }
        else
        {
        printf("두 문자열은 다르다. %d \n", strcmp(str1, str3));
        }

        strcat(str3, str1);
        printf("%s\n", str3);

        return 0;
    }
   