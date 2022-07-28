#include "../inc/header.h"

void mx_printint(int n) {
    int tmp = n;
    int count = 0;

    while (n) {
        n /= 10;
        count++;
    }
    
    if (tmp < 0) {
        mx_printchar('-');
        tmp *= -1;
    }

    char arr[count];

    int i = count - 1;
    while (tmp) {
        arr[i] = (tmp % 10) + '0';
        tmp /= 10;
        i--;
    }

    for (int i = 0; i < count; i++) {
         mx_printchar(arr[i]); 
    }
}
