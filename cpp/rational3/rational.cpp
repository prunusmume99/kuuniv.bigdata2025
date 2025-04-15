#include "rational.h"
#include <cstdlib>  //abs 함수 사용하기 위해 필요함

// 최대공약수 greatest common divisor
// 두 정수 a, b의 쵀대공약수를 구함
int Rational::gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}


//유클리드호제법
// 두 수의 최대공약수를 빠르게 구하는 알고리즘
// gcd(a,b) = gcd( b, a % b)
// 큰 수를 작은 수로 나눈 나머지로 계속 바꿔가면서 반복해 가다가, 나머지가 0이 되는 순간
// 그때의 나누는 수가 최대 공약수

//알고리즘 흐름
// 큰 수 a를 작은 수 b로 나눔
// 나머지를 r이라고 할때 -> gcd(a, b) = gcd(b, r)
// 이 과정을 나머지가 0이 될 때까지 반복
// 그 때 나누는 수가 최대 공약수



//약분 reduction of a fraction
//분자 분모 최대공약수로 나누고 분모가 음수인 경우 부호를 문자로 옮김
void Rational::reduce() {
    int g = gcd(abs(num), abs(den));
    num /= g;
    den /= g;

    if (den < 0) {
        num *= -1;
        den *= -1;
    }
}

//일반 생성자
//사용자가 직접 분자와 분모 설정
Rational::Rational(int num, int den) : num(num), den(den == 0 ? 1 : den) {
    reduce();
}

//복사 생성자
Rational::Rational(const Rational& rhs) : num(rhs.num), den(rhs.den) {}

//소멸자
Rational::~Rational() {}

//대입 연산자 오버로딩
//같은 rational 타입 값 복사하고 약분
Rational& Rational::operator=(const Rational& rhs) {
    if (this != &rhs) {
        num = rhs.num;
        den = rhs.den;
        reduce();
    }
    return *this;
}


//비교 연산자
//두 객체의 분자, 분모가 같으면 true
bool Rational::operator==(const Rational& rhs) const {
    return num == rhs.num && den == rhs.den;
}

//get 분자
int Rational::numerator() const {
    return num;
}

//get 분모
int Rational::denominator() const {
    return den;
}

//set 분자 설정 후 약분
void Rational::numerator(int n) {
    num = n;
    reduce();
}

//set 분모 설정 후 약분
void Rational::denominator(int d) {
    den = (d == 0 ? 1 : d);
    reduce();
}

//출력 연산자
// (분자/분모) 형태로 출력
std::ostream& operator<<(std::ostream& out, const Rational& rhs) {
    out << "(" << rhs.num << "/" << rhs.den << ")";
    return out;
}
