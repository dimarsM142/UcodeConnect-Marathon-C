#include <stdbool.h>

double mx_pow(double, unsigned int);

bool mx_is_narcissistic(int num) {
    int sum = 0;
    int counter = 0;
    int temp = num;
    while(temp != 0) {
        temp /= 10;
        counter++;
    } 
    temp = num;
    while(temp  > 0) {
        
        sum += mx_pow(temp % 10, counter);
        temp /= 10;
    }
    return sum == num;    
}
