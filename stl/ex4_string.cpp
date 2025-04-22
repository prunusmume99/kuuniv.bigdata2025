#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;

    cout << "아래에 문자열을 입력하세요!" << endl;
    getline(cin, s, '\n'); // '\n' : Enter 키를 누를 때까지 입력받음
    for (auto c : s){
        string first = s.substr(0, 1); // 첫번째 문자
        string sub = s.substr(1, s.size() - 1); // 나머지 문자
        s = sub + first; // 첫번째 문자를 맨 뒤로 보냄
        cout << s << endl;
    }
    return 0;
}