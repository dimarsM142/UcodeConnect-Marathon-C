#include <stdlib.h>

char* mx_strcpy(char *, const char *);
int mx_strlen(const char *);
char *mx_strnew(const int);

char *mx_strdup(const char * str) {
    if(str == NULL) {
        return NULL;
    }
    char *result = mx_strnew(mx_strlen(str));    
    return mx_strcpy(result, str);
}
