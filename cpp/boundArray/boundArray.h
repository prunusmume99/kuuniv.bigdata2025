// boundArray.h
#ifndef BOUNDARRAY_H
#define BOUNDARRAY_H

#include "safeArray.h"
#include <stdexcept>

// BoundArray: 지정된 하한(lower_)과 상한(upper_) 범위 내에서 인덱스를 안전하게 다루는 배열 클래스
class BoundArray : public SafeArray {
private:
    int lower_;  // 인덱스 시작 값
    int upper_;  // 인덱스 끝 값 (상한, 포함하지 않음)

public:
    // 생성자: 하한(lower)과 상한(upper) 지정
    BoundArray(int lower, int upper);
    // 생성자: 크기(size) 지정 (하한 0)
    explicit BoundArray(int size);
    // 기본 생성자: SafeArray 기본 크기 사용 (하한 0, 상한은 배열 크기)
    BoundArray();
    // 복사 생성자
    BoundArray(const BoundArray& rhs);
    // 대입 연산자
    BoundArray& operator=(const BoundArray& rhs);
    // 동등 비교 연산자
    bool operator==(const BoundArray& rhs) const;

    // 인덱스 범위 접근자
    int lower() const;
    int upper() const;

    // 인덱스 연산자: 범위 벗어나면 예외 발생
    int& operator[](int index);
    const int& operator[](int index) const;
};

#endif  // BOUNDARRAY_H
