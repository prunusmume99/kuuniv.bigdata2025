# kuuniv.bigdata2025

___
## 2025-03-04
___

1교시
Vmware 설치
Ubuntu 22.04 설치

2교시
Github 계정 생성
Github 저장소 생성
Github 저장소 Clone

3교시
리눅스 설명
#4교시
간단한 프로그램 작성 nano (infinit.c)
>코드 내용
>  int main()
  {
      while(1) ;
      return 0 ;
  }

#5교시
*C 언어 설명
  *자료형
  *숫자형 - 정수형, 실수형

#6교시
온도 예제 작성 celcius2fahr.c
>  #include <stdio.h>

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

#7교시
*makefile 작성
>  TARGET = infinit limit celsius2fahr fahr2celsius charNumber

all : ${TARGET}

infinit : $@
limit : $@
celsius2fahr : $@
fahr2celus : $@
charNumber : $@

clean : 
	rm ${TARGET}

 
*make 실행
*char 설명 및 예제 작성 charNumber.c
>  #include <stdio.h>

  int main()
{
      char ch1 = 'A';
      char ch2 = 65;
      char ch3 ;

      printf("ch1: %c Number: %d\n", ch1, ch1);
      printf("ch2: %c Number: %d\n", ch2, ch2);
      printf("Input A character: ");
      scanf("%c", &ch3);
      printf("\nch3: %c Number: %d\n", ch3, ch3);

      return 0 ;
}

8교시
복습 및 정리

