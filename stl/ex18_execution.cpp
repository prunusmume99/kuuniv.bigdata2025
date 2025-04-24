//  g++ -std=c++17 ex18_excution.cpp -ltbb -o ex18_excution
#include <algorithm>
#include <chrono>
#include <cmath>
// #include <execution> // 병렬처리. cpp 17이후
#include <iostream>
#include <numeric>
#include <random>
#include <vector>
using namespace std;

int main()
{
    vector<int> data = {1, 2, 3, 4, 5};
    double mean = accumulate(data.begin(), data.end(), 0.0) / data.size();
    double sq_sum = accumulate(data.begin(), data.end(), 0.0,
                               [mean](double acc, int val)
                               { return acc + (val - mean) * (val - mean); });
    double variance = sq_sum / data.size();

    cout << "평균 : " << mean << endl;
    cout << "분산 : " << variance << endl;
    vector<int> vec(1'000'000);
    iota(vec.begin(), vec.end(), 0);
    shuffle(vec.begin(), vec.end(), mt19937(random_device{}()));

    auto start = chrono::high_resolution_clock::now();
    // 실행 시간이 걸리는 코드
    // sort(execution::par, vec.begin(), vec.end());
    sort(vec.begin(), vec.end());
    auto end = chrono::high_resolution_clock::now();

    cout << "병렬 정렬 소요 시간 : " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;
    return 0;
}