#include <cassert>
#include "safeArray.h"


SafeArray::SafeArray(int size)
: Array(size)
{

}

SafeArray::SafeArray(const int *pArr , int size)
: Array(pArr, size)
{

}

SafeArray::SafeArray(const SafeArray& rhs)
: Array((Array)rhs)
{  //slicing하여 array관련 내용만 남게 타입캐스팅

}
SafeArray& SafeArray::operator=(const SafeArray& rhs)
{
        if (this != &rhs){
        this->Array::operator=((Array)rhs);
        // safearray 쪽에서 추가된게 있으면 여기에 추가
    }
    return *this;
}

bool SafeArray::operator==(const SafeArray& rhs)const
{
    return this->Array::operator==((Array)rhs);
}

int& SafeArray::operator[](int index)
{
    assert(index >= 0 && index < this->size()); //this->Array::size() 에서 Array::생략하여 표기
    return this->Array::operator[](index);
}

const int& SafeArray::operator[](int index) const
{
    assert(index >= 0 && index < this->size());
    return this->Array::operator[](index);
}