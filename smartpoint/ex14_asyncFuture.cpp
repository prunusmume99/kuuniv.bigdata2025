#include <chrono>
#include <future>
#include <iostream>
#include <vector>
#include <thread>
using namespace std;

int slowAdd(int a, int b)
{
    for (int i = 0; i < 5; ++i)
    {
        cout << "slowAdd 실행 중 " << a << endl;
        this_thread::sleep_for(chrono::microseconds(400'000));
    }
    return a + b;
}

int main()
{
    vector<future<int>> result;
    for (int i = 0; i < 4; ++i)
        result.push_back(async(slowAdd, i + 1, 3));
    cout << "계산 중 ..." << endl;
    for (int i = 0; i < 4; ++i)
        cout << "결과 : " << result[i].get() << endl;
    return 0;
}