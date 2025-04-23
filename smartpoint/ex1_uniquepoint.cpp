#include <iostream>
#include <memory>
using namespace std;

class Myclass
{
public:
    int test_a;
    Myclass()
    {
        cout << "Myclass 생성!!" << endl;
        test_a = 100;
    }
    ~Myclass() { cout << "Myclass 소멸!!" << endl; }
};

int main()
{
    auto ptr = make_unique<Myclass>(); // heap 에 만들어진 메모리.
    cout << ptr->test_a << endl;
    return 0;
}