#include <iostream>
using namespace std;

int main() {
    //cout << "hello, world" << endl;
    //std::cout << "hello, world";
    operator << (std::cout, "hello, world");
    //std::cout.operator<<("hello, world");

    //std::out << std::endl;
    //operator << (std::out, std::endl);
    //std::cout.operator << (std::endl); // cout이 결과값
   
    operator<<(cout, "hello, world").operator<<(endl);
    return 0;
}
