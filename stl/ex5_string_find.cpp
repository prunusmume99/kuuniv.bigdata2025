#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sentence;
    cout << "문장을 입력하세요! "<< endl;
    getline(cin, sentence, '\n');
    
    string find_character, replace_character;
    cout << endl
         << "find : ";
    getline(cin, find_character, '\n');
    cout << "replace : ";
    getline(cin, replace_character, '\n');
    
    int index = 0;
    while(true)
    {
        int index = sentence.find(find_character, index); 
        if (index == -1)
             break; // 더 이상 찾을 수 없으면 종료
        sentence.replace(index, find_character.length(), replace_character); // 찾은 문자열을 대체
    }
    cout << sentence << endl;
    return 0;
}