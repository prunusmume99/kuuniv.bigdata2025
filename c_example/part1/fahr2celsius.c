#include <stdio.h>

int main()
{
    int fahr;
    double celsius;
    
    fahr = 200;
    celsius = 5.0 / 9.0 * (fahr - 32);
    printf("fahrenheit temp : %d --> celsius temp: %f\n", fahr, celsius);
    
    return 0;
}
