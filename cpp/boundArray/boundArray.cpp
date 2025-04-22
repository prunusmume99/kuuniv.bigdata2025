#include "boundArray.h"
#include <stdexcept>  // std::out_of_range

// 하한(lower)과 상한(upper) 지정 생성자
BoundArray::BoundArray(int lower, int upper)
    : SafeArray(upper - lower), lower_(lower), upper_(upper) {}

// 크기(size) 지정 생성자 (하한 0)
BoundArray::BoundArray(int size)
    : SafeArray(size), lower_(0), upper_(size) {}

// 기본 생성자: SafeArray 기본 크기 사용, 하한 0, 상한은 getSize()로 설정
BoundArray::BoundArray()
    : SafeArray(), lower_(0), upper_(0) {
    upper_ = this->size();
}

// 복사 생성자
BoundArray::BoundArray(const BoundArray& rhs)
    : SafeArray(rhs), lower_(rhs.lower_), upper_(rhs.upper_) {}

// 대입 연산자
BoundArray& BoundArray::operator=(const BoundArray& rhs) {
    if (this != &rhs) {
        SafeArray::operator=(rhs);
        lower_ = rhs.lower_;
        upper_ = rhs.upper_;
    }
    return *this;
}

// 동등 비교 연산자
bool BoundArray::operator==(const BoundArray& rhs) const {
    return lower_ == rhs.lower_
        && upper_ == rhs.upper_
        && SafeArray::operator==(rhs);
}

// 하한 반환
int BoundArray::lower() const {
    return lower_;
}

// 상한 반환
int BoundArray::upper() const {
    return upper_;
}

// 인덱스 접근 연산자 (mutable)
int& BoundArray::operator[](int index) {
    if (index < lower_ || index >= upper_) {
        throw std::out_of_range("BoundArray: 인덱스 범위 벗어남");
    }
    return SafeArray::operator[](index - lower_);
}

// 인덱스 접근 연산자 (const)
const int& BoundArray::operator[](int index) const {
    if (index < lower_ || index >= upper_) {
        throw std::out_of_range("BoundArray: 인덱스 범위 벗어남");
    }
    return SafeArray::operator[](index - lower_);
}
