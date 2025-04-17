#include <iostream>
#include "array.h"

int main() {
    int nums[] = {1, 2, 3, 4, 5};

    Array arr1(nums, 5);
    Array arr2(10);
    Array arr3;                      // 기본 크기(100)로 생성
    Array arr4 = arr1;

    std::cout << "Default size is: " << Array::getArraySize() << '\n';

    arr2 = arr1;
    if (arr1 == arr2) {
        std::cout << "arr1 and arr2 are equal\n";
    } else {
        std::cout << "arr1 and arr2 are not equal\n";
    }

    return 0;
}
