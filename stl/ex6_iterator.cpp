#include <iostream>
#include <vector> //-->iterator정의 포함되어있음
using namespace std;

// class A : 
// public :
//     class B:
    
int main()
{
    vector<int> test_vector = {1, 2, 3, 4, 5, 6};
    
    for (vector<int>::iterator it = test_vector.begin(); it != test_vector.end(); ++it) // for 문 두번째 방식
    {
        cout << *it << endl;
    }

    // iterator 가 정의 - begin()과 end()를 통해서 반복자 생성
    // *it 역참조가 가능해야 한다.
    for (auto v : test_vector) // 세번째 방식 모던 C++ 문법
    {
        cout << v << endl;
    }

    for (auto &v : test_vector) // 컨테이너의 값을 변경
    {
        cout << v << endl;
    }

    for (const auto &v : test_vector) // 메모리 효율적으로 값 참고 할 때
    {
        cout << v << endl;
    }

    return 0;
}