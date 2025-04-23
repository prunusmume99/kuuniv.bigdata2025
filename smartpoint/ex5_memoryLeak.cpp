#include <memory>
#include <iostream>
using namespace std;

class B;

class A{
public:
    shared_ptr<B> b_ptr;
    ~A() {
        cout << "A destructor called" << endl;
    }
};

class B{
public:
    shared_ptr<A> a_ptr;
    ~B() {
        cout << "B destructor called" << endl;
    }
};  

int main() {
    auto a = make_shared<A>();
    auto b = make_shared<B>();

    a->b_ptr = b;
    b->a_ptr = a;
    
    return 0;
}