#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

class Complex {
friend std::ostream& operator<<(std::ostream& out, const Complex& rhs);

private:
    double re_; 
    double im_;

public:
    Complex(double re = 0.0, double im = 0.0);  
    // Complex(const Complex& ) { } /* memberwise copy */
    // ~Complex() { }
    
    // Complex& operator=(const Complex& ) { /* memberwise copy */ return *this; }
    Complex& operator+=(const Complex& rhs);
    // +=, -=, *=, /=  ==> O 만들어 줘야함
    

    bool operator==(const Complex& rhs) const;
    bool operator!=(const Complex& rhs) const;
    

    const Complex operator+(const Complex& rhs) const; // 더하기 연산
    const Complex operator-(const Complex& rhs) const;

    
    Complex& operator++();      
    Complex operator++(int );   


    // &, |, ~, ^ ==> X 만들어 주지 않아도 됨

    // type casting ==> X 만들어 주지 않아도 됨

    // Complex *operator&() { return this; }
    // const Complex *operator&() const { return this; }

    //get
    double real() const;
    double imag() const;

    //set
    void real(double re);
    void imag(double im);

};
#endif