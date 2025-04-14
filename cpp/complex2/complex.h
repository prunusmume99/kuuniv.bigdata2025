#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
private:
    double re;  // 실수부
    double im;  // 허수부

public:
    Complex();                     // 기본 생성자
    Complex(double re);            // 실수만 받는 생성자
    Complex(double re, double im); // 실수 + 허수 생성자
    ~Complex();                    // 소멸자

    // void 형태 아닌거 알고 있음 (인자 전달하는것만 생각하려고 적어놓은 것)- 내일 4.15 수정
    //void operator = (Complex c);   // 멤버함수
    //void operator=(const Complex *pc);
    void operator=(const Complex &rc);

    //int operator==(const Complex& rc);         //read only 라 const
    bool operator==(const Complex& rc);

    double real();                 // getter: 실수부
    double imag();                 // getter: 허수부

    void real(double re);         // setter: 실수부
    void imag(double im);         // setter: 허수부
};

#endif
