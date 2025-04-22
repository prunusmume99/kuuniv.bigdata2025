#ifndef SAFEARRAY_H
#define SAFEARRAY_H

#include "array.h"

// #define ARRAY_SIZE 100
// extern const int ARRAY_SIZE;

class SafeArray : public Array{
    //->array의 함수와 변수 긁어옴 //public private는 어디에 있는게 대상이냐
private:
    // 줄게 읍따 이마리야

public:
    // SafeArray(){}
    // SafeArray(const SafeArray& ){ /*memberwise copy*/ }
    // ~SafeArray(){}
    // SafeArray& operator=(const SafeArray& ){ /*memberwise copy*/ }
    // SafeArray *operator&() {return this;}
    // const SafeArray* operator&() const {return this};

    explicit SafeArray(int size = Array::getDefaultArraySize());
    SafeArray(const int *pArr , int size);
    SafeArray(const SafeArray& rhs);
    // ~SafeArray(){}
    SafeArray& operator=(const SafeArray& rhs);

    bool operator==(const SafeArray& rhs)const;

    virtual int& operator[](int index);
    virtual const int& operator[](int index) const;
    // int size(); // array쪽에 이미 있기에 가져오면 됨 -> Array::size() is inherited by public

};

#endif