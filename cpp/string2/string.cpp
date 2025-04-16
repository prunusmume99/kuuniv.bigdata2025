#include "string.h"
#include <cassert>
#include <cstring>

// 출력 연산자
std::ostream& operator<<(std::ostream& out, const String& rhs)
{
    return out << rhs.str_;
}

// 기본 생성자
String::String()
    : str_(new char[1]), len_(0)
{
    assert(str_);
    str_[0] = '\0';
}

// 문자열 생성자
String::String(const char *s)
    : str_(new char[strlen(s) + 1]), len_(strlen(s))
{
    assert(str_);
    strcpy(str_, s);
}

// 복사 생성자
String::String(const String& rhs)
    : str_(new char[rhs.len_ + 1]), len_(rhs.len_)
{
    assert(str_);
    strcpy(str_, rhs.str_);
}

// 소멸자
String::~String()
{
    delete[] str_;
}

// 복사 대입 연산자
String& String::operator=(const String& rhs)
{
    if (this != &rhs) {
        delete[] str_;
        str_ = new char[rhs.len_ + 1];
        assert(str_);
        strcpy(str_, rhs.str_);
        len_ = rhs.len_;
    }
    return *this;
}

// 비교 연산자
bool String::operator==(const String& rhs) const
{
    return strcmp(str_, rhs.str_) == 0;
}

// 문자열 덧셈 연산자
const String String::operator+(const String& rhs) const
{
    size_t newLen = len_ + rhs.len_;
    char* buf = new char[newLen + 1];
    strcpy(buf, str_);
    strcat(buf, rhs.str_);

    String result(buf);
    delete[] buf;
    return result;
}

// C-style 문자열 반환
const char* String::c_str() const {
    return str_;
}

// 문자열 길이 반환
int String::size() const {
    return len_;
}
