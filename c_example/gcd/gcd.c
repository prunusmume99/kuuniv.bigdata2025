// #include "gcd.h"

// int gcd(int a, int b)
// {
//     int remain;
//     // remain = a % b;
//     while (remain = a % b)
//     {
//         a = b;
//         b = remain;
//         // remain = a % b;
//     }
//     return b;
// }

#include "gcd.h"

int gcd(int a, int b)
{
    int remain;
    while ((remain = a % b)) {
        a = b;
        b = remain;
    }
    return b;
}
