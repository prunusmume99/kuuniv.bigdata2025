#include <iostream>
#include <vector>
#include <string>
#include "processor.hpp"

using namespace std;

constexpr int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

int main() {
    // constexpr 테스트
    constexpr int fact = factorial(5);
    cout << "Factorial of 5 is: " << fact << endl; // 컴파일 타임 계산

    // 범위 기반 for문
    vector<string> input = {"hello", "", "world"};
    Processor proc(input);

    auto transformed = proc.transform();
    cout << "transformed data: " << endl;
    for (const auto &s : transformed) {
        cout << s << endl;
    }

    // if constexpr 테스트
    cout << "Compute test:" << endl;
    cout << "Int 10       : " << proc.compute(10) << endl;
    cout << "Float 10.0   : " << proc.compute(10.0) << endl;
    cout << "String test  : " << proc.compute(string("test")) << endl;

    //nullptr 테스트
    string *ptr = nullptr; // 초기화
    cout << "Pointer is : " << (ptr == nullptr ? "null" : "non-null") << endl;
    string a = "Non nullptr!!!";
    ptr = &a;
    cout << "Pointer is : " << (ptr == nullptr ? "null" : "non-null") << endl;
    return 0;
    
}
