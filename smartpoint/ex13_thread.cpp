#include <iostream>
#include <thread>
#include <mutex>    //mutually execlusive
using namespace std;

int counter = 0;
mutex mtx; // mutex object
void increment()
{
    for (int i = 0; i < 1000; ++i)
    {
        lock_guard<mutex> lock(mtx); // lock the mutex
        ++counter;
    }
}


int main(){
    thread t1(increment);
    thread t2(increment);

    //execution
    // ..
    t1.join();  // wait for thread t1 to finish
    t2.join();  // wait for thread t2 to finish
    //excution - main thread ... t1 thread ... t2 thread

    cout << "Final counter value: " << counter << endl;

    return 0;


}