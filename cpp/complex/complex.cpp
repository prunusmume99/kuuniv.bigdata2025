#include "complex.h"

Complex::Complex(double re, double im)
{
    this->re = re;
    this->im = im;
}

Complex::Complex(double re)
{
    this->re = re;
    this->im = 0.0;
}

Complex::Complex()
{
    this->re = 0.0;
    this->im = 0.0;
}

Complex::~Complex()
{

}


double Complex::real()
{
    return this->re;
}

double Complex::imag()
{
    return this->im;
}

void Complex::real(double re)           // get 함수 이름
{
    this->re = re;
}

void Complex::imag(double im)           // set 함수 이름
{
    this->im = im;
}

