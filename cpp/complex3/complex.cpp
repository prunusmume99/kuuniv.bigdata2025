#include "complex.h"

std::ostream& operator<<(std::ostream& out, const Complex& rhs)
{
    out << "(" << rhs.re << ", " << rhs.im << "i)";

    return out;
}

Complex::Complex(double re , double im)  // 0.0이라는 기본값만 (디폴트 인자) 
{
    this->re = re;
    this->im = im;
}

Complex::Complex(const Complex& rhs)     // right hand side (오른쪽에 피연산자가 옴)
{
    this->re = rhs.re;
    this->im = rhs.im;
}
Complex::~Complex()
{


}

Complex& Complex::operator=(const Complex& rhs)
{
    this->re = rhs.re;
    this->im = rhs.im;

    return *this;

}

bool Complex::operator==(const Complex& rhs)
{
    return this->re == rhs.re && this->im == rhs.im;

}

const Complex Complex::operator+(const Complex& rhs)  // 포인터 레퍼런스 둘다 못써서 일반변수로
{
    Complex result (this->re + rhs.re,       //c2 + c3
    this->im + rhs.im);

    return result;
}

const Complex Complex::operator-(const Complex& rhs)  // 포인터 레퍼런스 둘다 못써서 일반변수로
{
    Complex result (this->re - rhs.re,       //c2 + c3
    this->im - rhs.im);

    return result;
}