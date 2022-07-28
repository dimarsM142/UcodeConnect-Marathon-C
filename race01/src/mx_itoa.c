#include "../inc/header.h"

char *mx_itoa(long long number) {
    char *result = NULL;
    int size = 0;
    long long temp = number;
     if (number < 0) {
        size++;
        temp *= -1;
    }
    if (number == 0) {
        result = mx_strnew(1);
        result[0] = '0';
        return result;
    }
	while (temp) {
        size++;
		temp /= 10;
	}
    result = mx_strnew(size);
    if (number < 0) {
        number *= -1;
        result[0] = '-';
    }
    result[size] = '\0';
    size--;
    while (number != 0 && size >= 0) {
        if(result[size] == '-') {
            break;
        }
        result[size] = (number % 10) + '0';
        size--;
        number /= 10;
    }
    return result;
}

