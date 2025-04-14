#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{
private:
    int num;   // numerator (분자)
    int den;   // denominator (분모)

    void reduce();  // 최대공약수로 약분

public:
    Rational(int num, int den);   // 생성자: 분자, 분모
    Rational(int num);            // 생성자: 정수 → num/1
    Rational();                   // 생성자: 기본값 0/1
    ~Rational();                  // 소멸자

    int numerator();              // get
    int denominator();

    void numerator(int num);     // set
    void denominator(int den);
};

#endif
