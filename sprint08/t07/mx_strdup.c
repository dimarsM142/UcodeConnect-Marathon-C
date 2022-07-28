#include "create_new_agents.h"

char* mx_strcpy(char *, const char *);
int mx_strlen(const char * str);
char *mx_strnew(const int size);

char *mx_strdup(const char * str) {
    if(str == NULL) {
        return NULL;
    }
    char *result = mx_strnew(mx_strlen(str));    
    return mx_strcpy(result, str);
}
