// 표준 입력을 받아서 (영어 문장)  - this is an apple 
// 단어 별 등장 횟수를 출력하는 프로그램

#include <iostream>
#include <sstream>      //문자열을 스트림처럼 다룰 수 있게 해주는 헤더 string - stream
#include <unordered_map>
#include <string>
#include <algorithm>   // sort
#include <cctype>    // tolower
using namespace std;

string clean_word(const string& word){
    string cleaned;
    for(char ch : word){
        if (isalpha(ch) || isdigit(ch))
            cleaned += tolower(ch); // 소문자로 변환
    }   return cleaned;
}

int main(){
    string line;
    getline(cin, line); // 표준 입력을 받는다.
    unordered_map<string, int> word_count; // 단어와 등장 횟수를 저장할 unordered_map
    istringstream iss(line); // 문자열을 스트림처럼 다룰 수 있게 해주는 객체
    string word;
    
    while (iss >> word) { // 단어를 하나씩 읽어온다.
        string cleaned_word = clean_word(word); // 단어를 정리한다.
        if (!cleaned_word.empty()) { // 비어있지 않으면
            word_count[cleaned_word]++; // 등장 횟수를 증가시킨다.
        }
    }
    // 단어와 등장 횟수를 출력한다.
    for (const auto& [key, value] : word_count) {
        cout << key << ": " << value << endl;
    }
    // 단어를 정렬한다.
}