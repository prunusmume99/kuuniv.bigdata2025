#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    cout << "문장을 넣으시오! (끝내려면 0 입력) " << endl;
    string word;
    vector<int> sizes;
    vector<string> sentence;

    while (true)
    {
        cin >> word;
        if (word == "0") break;

        sizes.push_back(word.size());
        sentence.push_back(word);
    }

    if (sizes.empty()) {
        cout << "입력된 단어가 없습니다!" << endl;
        return 0;
    }

    sort(sizes.begin(), sizes.end());

    cout << "가장 짧은 길이는 : " << sizes[0] << endl;
    cout << "가장 긴 길이는 : " << sizes[sizes.size() - 1] << endl;

    for (auto v : sentence){
        cout << v << " ";
    }
    cout << endl;
    return 0;
}


// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <string>

// using namespace std;

// int main()
// {
//     cout << "문장을 넣으시오! " << endl;
//     string word;
//     vector<int> sizes;
//     vector<string> sentence;
//     while (word != "0")
//     {
//         cin >> word; // 단어를 입력받음
//         sizes.push_back(word.size());
//         sentence.push_back(word); // 단어를 벡터에 저장
//     }

//     sort(sizes.begin(), sizes.end()); // 정렬

//     cout << "가장 짧은 길이는 : " << sizes[0] << endl;
//     cout << "가장 긴 길이는 : " << sizes[sizes.size() - 1] << endl; // 가장 마지막 원소에 접근
//     for (auto v : sentence){ // 모던 형식의 for문
//         cout << v << " ";
//     }
//     cout << endl;
//     return 0;
    
// }