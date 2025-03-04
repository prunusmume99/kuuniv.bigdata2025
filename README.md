# KUUNIV Big Data 2025 - 2025.03.04

## 📌 오늘의 학습 내용

---

## 🕐 1교시: VMware 설치 및 Ubuntu 22.04 설치
- **VMware 설치**
- **Ubuntu 22.04 설치**

---

## 🕑 2교시: GitHub 활용
- **GitHub 계정 생성**
- **GitHub 저장소 생성**
- **GitHub 저장소 Clone**

---

## 🕒 3교시: 리눅스 설명
- **Linux 개요 및 기본 개념 설명**

---

## 🕓 4교시: 간단한 프로그램 작성 (`infinit.c`)

### ✅ 코드 내용:
```c
int main()
{
  while(1);
  return 0;
}

## 🕔 5교시: C 언어 설명

### 🔹 자료형(Data Types)
- **숫자형(Numeric Types)**
  - 정수형(Integer)
  - 실수형(Floating Point)

---

## 🕕 6교시: 온도 변환 프로그램 (`celcius2fahr.c`)

### ✅ 코드 내용:
```c
// * 이 프로그램은 int 와 float 값의 연산을 데모하는 프로그램입니다.
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



