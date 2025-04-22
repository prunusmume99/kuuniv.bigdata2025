#include <iostream>
#include "boundArray.h"

int main(){

    BoundArray arr1(1, 11);     //index : [0:11)
    BoundArray arr2(10);        //index : [0:10)
    BoundArray arr3;            //index : [0:100)

    for (int i = arr1.lower(); i != arr1.upper(); ++i){
        arr1[i] = i;
    }
    
    BoundArray arr4 = arr1;

    arr4 = arr1;

    arr4 == arr1;

    for (int i = arr4.lower(); i != arr4.upper(); ++i){
        std::cout << arr4[i] << std::endl;
    }

    return 0;

}