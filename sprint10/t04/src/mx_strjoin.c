#include "../inc/header.h"

char *mx_strjoin(char const *s1, char const *s2) {
    char *result_str;

    if (s1 == NULL && s2 == NULL) {
        return NULL;
    }
    else if (s1 == NULL) {
        result_str = mx_strdup(s2);
    }
    else if (s2 == NULL) {
        result_str = mx_strdup(s1);
    }
    else {
        result_str = mx_strcat((char *)s1, (char *)s2);
        free((char *)s1);
    }

    return result_str;
}
