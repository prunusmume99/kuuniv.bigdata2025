#include <cassert>
#include "rational.h"
#include <cstdlib> 

static int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

void Rational::reduce()
{
    int g = gcd(abs(num), abs(den));
    num /= g;
    den /= g;

    if (den < 0) {
        num *= -1;
        den *= -1;
    }
}

Rational::Rational(int num, int den)
{
    if (den == 0) {
        // 분모가 0이면 기본값 0/1로 설정
        this->num = 0;
        this->den = 1;
    } else {
        this->num = num;
        this->den = den;
        reduce();
    }
}

Rational::Rational(int num)
{
    this->num = num;
    this->den = 1;
}

Rational::Rational()
{
    this->num = 0;
    this->den = 1;
}

Rational::~Rational()
{
}

int Rational::numerator()
{
    return this->num;
}

int Rational::denominator()
{
    return this->den;
}

void Rational::numerator(int num)
{
    this->num = num;
    reduce();
}

void Rational::denominator(int den)
{
    if (den == 0) {
        // 잘못된 값이면 분모는 기본값 1로 유지
        this->den = 1;
        this->num = 0;
    } else {
        this->den = den;
    }
    reduce();
}


Rational::Rational(int num, int den)
{
    assert(dden != 0);

    this->num = num;
    this->den = den;
}

Rational::~Rational()
{

}