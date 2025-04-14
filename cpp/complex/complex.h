#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
private:     // 내부 구현된 부분 implemetation  멤버변수(생성자, 소멸자 제일 먼저 생각)
    double re;     // real part
    double im;     // imaginary part

public:      // 껍데기 interface  멤버함수
    Complex(double re, double im);   // 생성자
    Complex(double re);              // 생성자
    //Complex(double im);               
    // 위에 함수 Complex , double, re 함수이름, 인자 타입, 인자 갯수 같아서 중복이라서 안됨  
    Complex();                       // 생성자
    ~Complex();                      // 소멸자

    double real();                   //get 
    double imag();              

    void real(double re);            //set
    void imag(double im);

};


#endif
