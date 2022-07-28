#include "../inc/header.h"

void mx_printint(int n) {
    if (n == 0)
         mx_printchar('0');
    else if (n == -2147483648){
        mx_printchar('-');
        mx_printchar('2');
        mx_printchar('1');
        mx_printchar('4');
        mx_printchar('7');
        mx_printchar('4');
        mx_printchar('8');
        mx_printchar('3');
        mx_printchar('6');
        mx_printchar('4');
        mx_printchar('8');
    }
    else{
    char array [100];
    int  i = 0;
    int value;
    if (n < 0)
        value = -1 * n;
    else
        value = n;
    while (value > 0){
        array[i] = value % 10;
        value /= 10;
        i++;
    }
    if (n < 0)
        mx_printchar('-');
    for (int j = i-1; j >= 0; j--)
        mx_printchar((char)array[j]+48); 
    }
}


