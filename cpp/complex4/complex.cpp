#include "complex.h"

std::ostream& operator<<(std::ostream& out, const Complex& rhs)
{
    return out << "(" << rhs.re_ << ", " << rhs.im_ << "i)";
}

Complex::Complex(double re, double im)
{
    re_ = re;       
    im_ = im;      
}

Complex& Complex::operator+=(const Complex& rhs)
{
    /*this->*/re_ += rhs.re_;
    /*this->*/im_ += rhs.im_;

    return *this;
}

bool Complex::operator==(const Complex& rhs)
{
    return this->re_ == rhs.re_ && this->im_ == rhs.im_;
}

bool Complex::operator!=(const Complex& rhs)
{
    
    return ! this->operator==(rhs); 
}

const Complex Complex::operator+(const Complex& rhs)
{
    Complex result(this->re_ + rhs.re_, this->im_ + rhs.im_);

    return result;
}

const Complex Complex::operator-(const Complex& rhs)
{
    Complex result(this->re_ - rhs.re_, this->im_ - rhs.im_);

    return result;
}

Complex& Complex::operator++()
{
    re_ += 1.0; 

    return *this;
}

Complex Complex::operator++(int )
{
    Complex tmp = *this; 
    re_ += 1.0;

    return tmp;
}

// - * + /
// % X

// ++, -- X

// // 전위 증가 (++c)
// Complex& Complex::operator++()
// {
//     ++re_; // 실수부만 증가
//     return *this;
// }

// // 후위 증가 (c++)
// Complex Complex::operator++(int)
// {
//     Complex tmp = *this;
//     ++re_;
//     return tmp;
// }
