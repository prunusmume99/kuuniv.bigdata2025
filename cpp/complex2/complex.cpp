#include "complex.h"

Complex::Complex()
{
    this->re = 0.0;
    this->im = 0.0;
}

Complex::Complex(double re)
{
    this->re = re;
    this->im = 0.0;
}

Complex::Complex(double re, double im)
{
    this->re = re;
    this->im = im;
}

Complex::~Complex()
{
}

// void Complex::operator=(Complex c)
// {
//     this->re = c.re;
//     this->im = c.im;
// }

// void Complex::operator=(const Complex *pc)
// {
//     this->re = pc->re;
//     this->im = pc->im;

// }

void Complex::operator=(const Complex& rc)
{
    this->re = rc.re;
    this->im = rc.im;
}


// int Complex::operator==(const Complex& rc)
// {
//    if(this->re == rc.re && this ->im == rc.im)
//    {
//     return 1;
//    } else {
//     return 0;
//    }
// }

bool Complex::operator==(const Complex& rc)
{
//    if(this->re == rc.re && this ->im == rc.im)
//    {
//     return true;
//    } else {
//     return false;
//    }

    return (this->re == rc.re && this->im == rc.im);
}

double Complex::real()
{
    return this->re;
}

double Complex::imag()  // <-- void였던 부분 수정!
{
    return this->im;
}

void Complex::real(double re)
{
    this->re = re;
}

void Complex::imag(double im)  // <-- 미완성된 줄 완성!
{
    this->im = im;
}
