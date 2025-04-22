#include <iostream>

using namespace std;
constexpr int square(int x) {return x * x;}

template<typename T>


auto process(T value) { // constexpr if를 사용하여 T가 정수형인지 확인
    if constexpr (is_integral_v<T>) {
        return value + 1; // 정수형일 경우 두 배로
    } else {
        return value + 0.5; // 그 외의 경우 그대로 반환
    }
}

int main(){
    constexpr int result = square(5); // 컴파일 타임에 계산됨
    cout << result << endl;
    cout << process(10) << endl; // 정수형 처리
    cout << process(5.6)<< endl; // 실수형 처리 

    return 0;
}