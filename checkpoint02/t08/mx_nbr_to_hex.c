#include <stdlib.h>
#include <stdio.h>

char *mx_strnew(const int size) {
    if(size < 0) {
        return NULL;
    }
    char *result = (char *)malloc(size + 1);
    for(int i = 0; i <= size; i++) {
        result[i] = '\0';
    }
    return result;
}

char *mx_nbr_to_hex(unsigned long nbr) {
    int i = 0;
    int j;
    unsigned long number = nbr;
    char *current;

    while( nbr > 0) {
        i++;
        nbr /= 16;
    }
    j = (i)*sizeof(char);
    current = mx_strnew(j);
    while( number > 0) {
        current[i-1] = "0123456789abcdef"[number % 16];
        i--;
        number /= 16;
    } 
    current[j] = (char)0;
    return current;
}
