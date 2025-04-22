#include "data_process.hpp"
#include <iostream>

using namespace std;

int main()
{
    vector<string> words = {"apple", "ant", "banana", "bear", "cat"};
    DataProcessor processor(words);

    auto sorted = processor.sort_by_length();

    cout << "Original data (from processor.data_) : " << std::endl;
    for (const auto &word : processor.data_)  // 원본 데이터 출력
        cout << word << endl;

    cout << "\nSorted by length : " << endl;
    for (const auto &word : sorted)           // 길이 기준 정렬 결과 출력
        cout << word << endl;

    cout << "\nFiltered by prefix 'b' : " << endl;
    auto filtered = processor.filter_by_prefix("b"); // 접두사 'b'로 필터링
    for (const auto &word : filtered)           // 필터링 결과 출력
        for (const auto &word : filtered)
            cout << word << endl;
    
    //capture mutable 사용
    int min_length = 4;
    auto count_long = [=]() mutable 
    {
        int count = 0;
        for( const auto &word : words){
            if(word.length() >= min_length){
                cout << word << endl;
                count++;
            }
        }min_length++;
        cout << "min_length = " << min_length << endl;
        return count;
    };
    cout << "\nWords with length >= 4\n" << count_long() << endl;
    cout << "\nAfter mutable change, min_length = " << min_length << endl;

    return 0;
}
