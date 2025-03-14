#include <stdio.h>

int main(void)
{
    FILE *fp;
    fp = fopen("output.txt", "w");
    if(fp == NULL)
    {
        printf("파일 열기 실패");
    }
    putc('A', fp);
    putc('A', stdout);
    fputc('B', fp);
    fputc('B', stdout);
    // puts depreciate 지원 종료
    fputs("puts로 문자가 간다.", fp);
    fputs("puts로 문자가 간다.",stdout);
    
    fprintf("puts로 문자가 간다.", fp);
    fprintf("puts로 문자가 간다.", stdout);

   
    // EOF == -1;

    fclose(fp);
    return 0;
}