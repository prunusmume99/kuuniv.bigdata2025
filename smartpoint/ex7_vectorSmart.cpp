#include <memory>
#include <iostream>
#include <vector>
using namespace std;

class Data {
public:
    int value;
    Data(int v) : value(v) {} 
};

// struct Data {
//         int value;
//         Data(int v) : value(v) {}
//     };

// C 에서의 struct
// C++ 에서의 class
// C++ struct(member function) 가능

// c++ struct, class 차이점
// struct는 public, class는 private
// c와 c++의 호환성 때문에? 이렇게 만들었다고함


int main(){
    vector<shared_ptr<Data>> dataList;
    dataList.push_back(make_shared<Data>(1));
    dataList.push_back(make_shared<Data>(2));
    
    shared_ptr<vector<Data>> dataList2 = make_shared<vector<Data>>();  // 포인터 초기화 추가
    dataList2->push_back(Data(10));
    dataList2->push_back(Data(20));

    for(const auto & data : dataList) 
        cout << "Value: " << data->value << endl;

    for(const auto & data : *dataList2)  // 두 번째 루프는 dataList2 기반으로 수정
        cout << "Value: " << data.value << endl;

    return 0;
}
