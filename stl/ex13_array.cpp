#include <array>
#include <iostream>
#include <deque>
#include <list>
#include <set>
#include <unordered_map>
//고정 크기 배열, STL 중에서 속도가 가장 빠름.
//그냥 배열보다는 살짝 느림

using namespace std;

int main(){
    //array
    array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(const auto& x : arr)
    cout << x << " "; // 배열 요소 출력
    cout << endl;
    // array는 고정 크기 배열로, 크기를 변경할 수 없다.
    // array는 STL 컨테이너 중에서 가장 빠르다.
    // array는 메모리 사용이 효율적이다.
    // array는 STL 알고리즘과 함께 사용할 수 있다.
    // array는 포인터와 비슷하게 동작한다.


    //deque
    deque<int> dq = {1, 2, 3};
    dq.push_back(4); // 뒤에 추가
    dq.push_front(0); // 앞에 추가
    dq.emplace_back(5); // 뒤에 추가
    dq.emplace_front(-1); // 앞에 추가
    dq.insert(dq.begin() + 3, 2.5); // 중간에 추가
    dq.erase(dq.begin() + 3); // 중간에 삭제
        for (const auto &v : dq)
        cout << v << " ";
    cout << endl;

    dq.pop_back(); // 뒤에서 삭제
    dq.pop_front(); // 앞에서 삭제
    // dq.erase(dq.begin() + 2); // 중간에서 삭제
    // dq.clear(); // 모든 요소 삭제
    
    for(const auto &v : dq)
        cout << v << " ";
    cout << endl;
    //deque는 양쪽에서 삽입과 삭제가 가능하다. 
    //deque는 vector보다 느리지만, list보다는 빠르다.
    //deque는 메모리 사용이 비효율적이다.

    //list 삽입 삭제 
    list<int> lst = {1, 2, 3};
    auto it = lst.begin();
    ++it; // it은 2를 가리킴
    lst.insert(lst.begin(), +2, 3); // 앞에 삽입
    for(const auto &v : lst)
        cout << v << " ";
    cout << endl;

    //set 집합 - 중복이 없는 자료들, 자동 정렬
    set<int> s = {3, 1, 2, 2, 1};
    for (const auto &v : s)
        cout << v << " "; // 1 2 3
    cout << endl;
    cout << " s 집합의 크기는 : " << s.size() << endl; // 3

    //unordered_map 
    //해쉬 테이블 기반의 자료 -> 아주 아주 아주~~~~ 빠른 접근
    //key-value 쌍으로 이루어져 있다.
    //key는 중복이 없고, value는 중복이 가능하다.
    //key는 해쉬 함수를 통해서 해쉬 테이블에 저장된다.
    //데이터가 굉장히 많을 때 100만개 이상일 때
    unordered_map<string, int> um;
    um["apple"] = 100;
    um["banana"] = 150;
    um["mango"] = 200;
    // 모든 것을 가지고 오려면 map 사용
    for(const auto& [key, val] : um){
        cout << key << " : " << val << endl;
    }
    // 참조가 빠르다
    cout << um["apple"] << endl; // 100

    return 0;
}