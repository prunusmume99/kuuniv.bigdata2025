#include <iostream>

void func(int){
    std::cout << "int\n";
}
void func(int *){
    std::cout << "pointer\n";
}
void func(long){
    std::cout << "long\n";
}

int main(){
    int *ptr = nullptr; // nullptr로 초기화
    int *fp;
    if(ptr == nullptr) {
        std::cout << "ptr is null" << std::endl;
    }
    func(0L); // long 타입
    func(1);
    func(NULL); //nullpointer로 안가짐
    func(nullptr); // nullpointer로 가짐
    // nullptr은 null pointer 상수로, 포인터 타입으로 변환할 수 있음
    func(ptr); // pointer 타입
    func(fp); // pointer 타입
}