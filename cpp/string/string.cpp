#include "string.h"
#include <cstring>
#include <cassert>


std::ostream& operator<<(std::ostream& out, const String& rhs)
{
    return out << rhs.str;
}

String::String() {
    this->str = new char[1];
    this->str[0] = '\0';
    this->len = 0;
}

String::String(const char *s) {
    this->str = new char[strlen(s) + 1];
    assert(this->str);
    strcpy(this->str, s);
    this->len = strlen(s);
}

String::String(const String& rhs) {
    this->str = new char[rhs.len + 1];
    assert(this->str);
    strcpy(this->str, rhs.str);
    this->len = rhs.len;
}

String::~String() {
    delete[] this->str;
}

String& String::operator=(const String& rhs) {
    if (this != &rhs) {
        delete[] this->str;
        this->str = new char[rhs.len + 1];
        assert(this->str);
        strcpy(this->str, rhs.str);
        this->len = rhs.len;
    }
    return *this;
}

bool String::operator==(const String& rhs) {
    return strcmp(this->str, rhs.str) == 0;
}

const String String::operator+(const String& rhs)
{
    int newLen = this->len + rhs.len;
    char* buf = new char[newLen + 1];  // 동적 메모리 확보
    strcpy(buf, this->str);
    strcat(buf, rhs.str);

    String result(buf);  // 복사 생성자 호출됨 → 내부에서 복사함

    return result;
}


std::ostream&operator<<(std::ostream& out, const String& rhs);
const char* String::c_str() const {
    return this->str;
}

int String::size() const {
    return this->len;
}
