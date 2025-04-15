#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational {
    friend std::ostream& operator<<(std::ostream& out, const Rational& rhs);

// 내부구현 (숨겨야할 것들)
private: 
    int num;  // numerator
    int den;  // denominator

    void reduce(); // 약분
    static int gcd(int a, int b); // 최대공약수

// 사용자 인터페이스 
public:  
    Rational(int num = 0, int den = 1);     // 기본 & 사용자 지정 생성자
    Rational(const Rational& rhs);          // 복사 생성자
    ~Rational();                            // 소멸자

    Rational& operator=(const Rational& rhs); // 대입 연산자
    bool operator==(const Rational& rhs) const; // 비교 연산자

    int numerator() const;
    int denominator() const;

    void numerator(int n);
    void denominator(int d);
};

#endif
