#include <iostream>
#include <future>
#include <thread>
#include <chrono>

using namespace std;

int slowAdd(int a, int b) {
    this_thread::sleep_for(chrono::seconds(2)); // Simulate a long computation
    return a + b;
}

int main(){
    future<int> result = async(launch::async, slowAdd, 2, 3);
    cout << "계산 중 ..." << endl;
    cout << "결과: " << result.get() << endl; // Wait for the result
    
    
    return 0;
}