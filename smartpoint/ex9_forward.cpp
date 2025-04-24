#include <iostream>
#include <utility>
using namespace std;

void process(string &&s)
{
    cout << "Rvalue: 참조: " << s << endl;
}

void wrapper(string &&s)
{
    process(forward<string>(s));
}

int main()
{
    wrapper(string("hello, world!!"));
    return 0;
}