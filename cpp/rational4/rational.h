#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
#include "gcd.h"

class Rational {
    friend std::ostream& operator<<(std::ostream& out, const Rational& rhs);

private:
    int num_; // 분자
    int den_; // 분모

    void reduce();      //helper funtion or tool function

public:
    
    Rational(int num = 0, int den = 1);

    bool operator==(const Rational& rhs);
    bool operator!=(const Rational& rhs);

    const Rational operator+(const Rational& rhs);
    const Rational operator-(const Rational& rhs);

    Rational& operator+=(const Rational& rhs);

    Rational& operator++();      // 전위 ++
    Rational operator++(int);    // 후위 ++
};

#endif
