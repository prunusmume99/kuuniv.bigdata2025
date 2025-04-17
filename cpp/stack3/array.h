#ifndef ARRAY_H
#define ARRAY_H

class Array {
private:
    int* pArr_;
    int  size_;
public:
    static const int ARRAY_SIZE;         // static 멤버 상수
    static int getArraySize();           // static 멤버 함수

    Array(int size = ARRAY_SIZE);
    Array(const int* pArr, int size);
    Array(const Array& rhs);
    ~Array();

    Array& operator=(const Array& rhs);
    bool operator==(const Array& rhs) const;
};

#endif
