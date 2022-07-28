#include <unistd.h>

void mx_printint(int n) {
    int temp = 0;
    if(n == 0) {
        temp = 48;
        write(1, &temp, 1);
        return;
    }
    if( n < 0) {
        temp = 45;
        write(1, &temp, 1);
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
        temp = array[j] + 48;
        write(1, &temp, 1);
    }
}
