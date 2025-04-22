#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v; // empty vector
    v.push_back(1); // add 1 to the end
    v.push_back(11);
    v.push_back(111);
    v.push_back(1238);
    // cout << "v 의 첫번째 원소는 : " << v[0] << endl; // print the first element
    // cout << "v 의 두번째 원소는 : " << v[1] << endl;
    // cout << "v 의 세번째 원소는 : " << v[2] << endl;
    // vector<int>::iterator it ;
    auto it = v.begin() + 2; // auto : 컴파일 시 자료형을 알아서 맞춰줌
    v.erase(it); // 111 삭제
    v.at(0) = 2; // 1을 2로 변경
    
    // 1. for 문을 사용하는 방법
    for (auto i = 0; i < v.size(); i++)
    {
        cout << "v 의 " << i + 1 << " 번째 원소는 : " << v.at(i) << endl;
    }
    return 0;
}