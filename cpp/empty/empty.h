#ifndef EMPTY_H
#define EMPTY_H

class Empty{

public:
    // Empty() {}   - 기본
    // Empty(const Empty& rhs ) {/* memberwise copy */} - 복사
    // ~Empty() {}  - 소멸자

    // Empty(const Empty& rhs ) {/* memberwise copy */ return *this; } - 치환
    // Empty* operator&() { return this; }  - 앰퍼센트
    // cosnt Empty* operator&() const { return this; }   - const 상수 객체 

};

#endif