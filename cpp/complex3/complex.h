#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

//class Complex;      //클래스가 밑에 정의될거라고 알려줌 6번 라인-Complex 쓴거 7번에서 선언 

class Complex{
friend std::ostream& operator<<(std::ostream& out,const Complex& rhs);

private:
    double re;
    double im;

public: 
    Complex(double re = 0.0, double im = 0.0);      // default argument vs parameter
    Complex(const Complex& rhs);                    // copy constructor 복사 생성자
    ~Complex();

    Complex& operator=(const Complex& rhs );
    
    bool operator==(const Complex& rhs);

    // + * - /
    //  % 는 만들수 없음

    // +
    const Complex operator+(const Complex& rhs);
    // -
    const Complex operator-(const Complex& rhs);


    //get set

};

#endif