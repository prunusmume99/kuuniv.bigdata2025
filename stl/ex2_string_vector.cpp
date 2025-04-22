#include <iostream>
#include <string>
#include <vector>

using namespace std; 
/* ==> using 키워드란 간단하게 말하면, 네임스페이스를 생략하는 것! 
여러개의 네임스페이스를 둠으로 인해서 같은 이름의 함수를 적절하게 쓸수가 있는데,
같은 함수의 이름을 써도 서로 충돌이 일어나지 않게끔 네임스페이스를 쓴것.
근데 그렇게 하다보면 코드가 길어짐.
그래서 이 안에 스탠다드 관련된 함수와 겹치지 않는다는 확신이 들면 이렇게 써도 됨. 
하지만 불안하고 엄밀하게 쓰고 싶다면 아래와 같이 씀
*/

// using std::vector;

int main()
{
    vector<string> sv;
    string name;

    cout << "이름을 5개 입력하세요 : " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " >> ";
        getline(cin, name); // cin >> name; 은 공백을 기준으로 입력받기 때문에 getLine 사용
        sv.push_back(name); // push_back : 벡터의 끝에 원소를 추가하는 함수
    }
    name = sv.at(0); // 벡터의 첫번째 원소를 name에 저장
    for(int i = 1; i < sv.size(); ++i)
    {
        if (name < sv[i]) // string 의 비교 연산자 오버라이딩 (벡터의 i번째 원소가 name보다 크면)
            name = sv[i]; // name에 i번째 원소를 저장
    }
    cout << "사전에서 가장 뒤에 나오는 이름은: " << name << endl;
    return 0;
}