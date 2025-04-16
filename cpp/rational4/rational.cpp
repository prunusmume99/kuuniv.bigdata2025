#include "rational.h"
#include "gcd.h"
#include <cassert>

std::ostream& operator<<(std::ostream& out, const Rational& rhs)
{
    return out << "(" << rhs.num_ << "/" << rhs.den_ << ")";
}

void Rational::reduce()
{
    int g = gcd(num_, den_);
    num_ = num_ / g;
    den_ = den_ / g;
}

Rational::Rational(int num, int den)
: num_(num), den_(den)
{
//     num_ = num;
//     den_ = den;
    assert(den );
    this->reduce();
}

bool Rational::operator==(const Rational& rhs)
{
    return num_ * rhs.den_ == den_ * rhs.num_;
}

bool Rational::operator!=(const Rational& rhs)
{
    return !this->operator==(rhs);
}



const Rational Rational::operator+(const Rational& rhs)
{
    return Rational(num_ * rhs.den_ + rhs.num_ * den_, den_ * rhs.den_);
}

const Rational Rational::operator-(const Rational& rhs)
{
    return Rational(num_ * rhs.den_ - rhs.num_ * den_, den_ * rhs.den_);
}



Rational& Rational::operator+=(const Rational& rhs)
{
    num_ = num_ * rhs.den_ + rhs.num_ * den_;
    den_ = den_ * rhs.den_;
    return *this;
}

Rational& Rational::operator++()
{
    num_ += den_;       // 1 더하기에 해당
    //complex 에서는 re_ += 1.0 
    // 1.0은 실수형 숫자니까 1이란 수를 더하는게 딱 맞지만 
    // Rational 에서는 1을 분수 형태로 더해야함
    // 따라서 분모를 기준으로 분자에 더하는 것 ->num_ += den_
    return *this;
}

Rational Rational::operator++(int)
{
    Rational tmp = *this;
    num_ += den_;
    return tmp;
}
