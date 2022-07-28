#include <stdlib.h>

static char* mx_strcpy(char * dst, const char * src) {
    char *tempptr = dst;
    while (*src) {
        *dst++ = *src++;
    }
    *dst = 0;
    return tempptr;
}

static char *mx_strnew(const int size) {
    if(size < 0) {
        return NULL;
    }
    char *result = (char *)malloc(size + 1);
    for(int i = 0; i <= size; i++) {
        result[i] = '\0';
    }
    return result;
}

char *mx_strdup(const char * str) {
    int len = 0;
    while(str[len] != '\0') {
        len++;
    }
    char *result = mx_strnew(len);    
    mx_strcpy(result, str);
    return result;
}
