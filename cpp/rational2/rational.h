#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
private:
    int num;   // 분자
    int den;   // 분모

    void reduce(); // 약분

public:
    Rational();                     // 기본 생성자
    Rational(int num);              // 정수 생성자 (den = 1)
    Rational(int num, int den);     // 분자 + 분모 생성자
    ~Rational();                    // 소멸자

    void operator=(const Rational& r);
    bool operator==(const Rational& r);

    int numerator();               // get: 분자
    int denominator();             // get: 분모

    void numerator(int n);         // set: 분자
    void denominator(int d);       // set: 분모
};

#endif
