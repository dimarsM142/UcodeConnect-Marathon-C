#include "../inc/header.h"

char *mx_strnew(const int size) {
    char *result = NULL;
    if(size < 0) {
        return NULL;
    }
    result = (char *)malloc(size + 1);
    for(int i = 0; i <= size; i++) {
        result[i] = '\0';
    }
    return result;
}
