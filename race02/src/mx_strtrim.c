#include "../inc/header.h"

char *mx_strtrim(const char *str) {
    if (!str) {
        return NULL;
    }
    int length = mx_strlen(str);
    int start = 0;
    int last = 0;
    char *result;

    for (int i = 0; mx_isspace(str[i]); i++) {
        start++;
    }
    for (int j = length - 1; mx_isspace(str[j]); j--) {
        last++;
    }

    result = mx_strnew(length - start - last);
    mx_strncpy(result, str + start, length - start - last);
    return result;
}
