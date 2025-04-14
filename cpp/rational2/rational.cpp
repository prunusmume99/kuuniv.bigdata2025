#include "rational.h"
#include <cstdlib>  // abs

static int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void Rational::reduce() {
    int g = gcd(abs(num), abs(den));
    num /= g;
    den /= g;

    if (den < 0) {
        num *= -1;
        den *= -1;
    }
}

Rational::Rational() {
    num = 0;
    den = 1;
}

Rational::Rational(int num) {
    this->num = num;
    this->den = 1;
}

Rational::Rational(int num, int den) {
    if (den == 0) {
        this->num = 0;
        this->den = 1;
    } else {
        this->num = num;
        this->den = den;
        reduce();
    }
}

Rational::~Rational() {
}

void Rational::operator=(const Rational& r) {
    this->num = r.num;
    this->den = r.den;
}

bool Rational::operator==(const Rational& r) {
    return (this->num == r.num && this->den == r.den);
}

int Rational::numerator() {
    return num;
}

int Rational::denominator() {
    return den;
}

void Rational::numerator(int n) {
    this->num = n;
    reduce();
}

void Rational::denominator(int d) {
    if (d == 0) {
        this->num = 0;
        this->den = 1;
    } else {
        this->den = d;
    }
    reduce();
}
