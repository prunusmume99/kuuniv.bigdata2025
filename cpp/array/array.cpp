#include "array.h"
#include <cassert>
#include <algorithm>

const int Array::ARRAY_SIZE = 100;

int Array::getArraySize() {
    return ARRAY_SIZE;
}

Array::Array(int size)
    : pArr_(new int[size]), size_(size)
{
    assert(pArr_);
}

Array::Array(const int* pArr, int size)
    : pArr_(new int[size]), size_(size)
{
    assert(pArr_);
    for (int i = 0; i < size; ++i)
        pArr_[i] = pArr[i];
}

Array::Array(const Array& rhs)
    : pArr_(new int[rhs.size_]), size_(rhs.size_)
{
    assert(pArr_);
    for (int i = 0; i < size_; ++i)
        pArr_[i] = rhs.pArr_[i];
}

Array::~Array() {
    delete[] pArr_;
}

Array& Array::operator=(const Array& rhs) {
    if (this != &rhs) {
        delete[] pArr_;
        size_ = rhs.size_;
        pArr_ = new int[size_];
        assert(pArr_);
        for (int i = 0; i < size_; ++i)
            pArr_[i] = rhs.pArr_[i];
    }
    return *this;
}

bool Array::operator==(const Array& rhs) const {
    if (size_ != rhs.size_)
        return false;
    for (int i = 0; i < size_; ++i)
        if (pArr_[i] != rhs.pArr_[i])
            return false;
    return true;
}

int& Array::operator[](int index) {
    assert(index >= 0 && index < size_);
    return pArr_[index];
}

const int& Array::operator[](int index) const {
    assert(index >= 0 && index < size_);
    return pArr_[index];
}

int Array::size() const {
    return size_;
}
