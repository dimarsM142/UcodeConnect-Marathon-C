#include "../inc/header.h"

void mx_printint(int n) {
    if(n == 0) {
        mx_printchar(48);
        return;
    }
    if( n < 0) {
        mx_printchar(45);
        n *= -1;
    }
    int start = n;
    int i = 0;
    while(start != 0) {
        start = start / 10;
        i++;
    }
    int array[i];
    int counter_arr = 0;
    while(n != 0) { 
        array[counter_arr] = n % 10;
        n = n / 10;
        counter_arr++;
    }
    for(int j = counter_arr - 1; j >= 0; j--) {
        mx_printchar(array[j] + 48);
    }
}
