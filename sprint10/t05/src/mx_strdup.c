#include "../inc/header.h"

char *mx_strdup(const char * str) {
    if(str == NULL) {
        return NULL;
    }
    char *result = mx_strnew(mx_strlen(str));    
    return mx_strcpy(result, str);
}

