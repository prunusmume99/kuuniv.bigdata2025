#include <iostream>
#include <memory>
using namespace std;


void useShared(shared_ptr<int> ptr) {
    cout << "넘겨 받은 ptr 의 use count :  " << ptr.use_count() << endl; 
}

int main() {
    auto a = make_shared<int>(100);
    auto b = a;  // 포인터에 대한 참조가 생겼다!
    auto c = a;
    
    useShared(move(a)); // 3
    //useShared(a)

    cout << "a use_count: " << a.use_count() << endl;
    cout << "b use_count: " << b.use_count() << endl; 
    return 0;

}