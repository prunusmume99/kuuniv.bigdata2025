#ifndef ARRAY_H
#define ARRAY_H

class Array {
private:
    int* pArr_;
    int  size_;

public:
    static const int ARRAY_SIZE;
    static int getArraySize();

    explicit Array(int size = ARRAY_SIZE);
    Array(const int* pArr, int size);
    Array(const Array& rhs);
    ~Array();

    Array& operator=(const Array& rhs);
    bool operator==(const Array& rhs) const;

    // ✅ 연산자 오버로딩 추가: 큐에서 직관적 사용
    int& operator[](int index);             // 수정 가능 버전
    const int& operator[](int index) const; // 읽기 전용 버전

    int size() const; // 기존 getSize() 대신 간단히 이름 축소
};

#endif
