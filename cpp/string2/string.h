#ifndef STRING_H
#define STRING_H

#include <iostream>

class String
{
    friend std::ostream& operator<<(std::ostream& out, const String& rhs);

private:
    char *str_;
    int len_;

public:
    String();                            // 기본 생성자
    String(const char *s);              // 문자열 생성자
    String(const String& rhs);          // 복사 생성자
    ~String();                          // 소멸자

    String& operator=(const String& rhs);           // 복사 대입 연산자
    bool operator==(const String& rhs) const;       // 비교 연산자
    const String operator+(const String& rhs) const;// 문자열 덧셈

    const char* c_str() const;          // C-style 문자열 반환
    int size() const;                   // 문자열 길이 반환
};

#endif
