#include <stdbool.h>
#include <stdlib.h>

void mx_strdel(char**);
int mx_strlen(const char *);
char *mx_strncpy(char*, const char*, int);
char *mx_strnew(const int);
bool mx_isspace(char);
char *mx_strtrim(const char*);

char *mx_del_extra_whitespaces(const char *str)
{
    char *temp = mx_strtrim(str);
    int count = 0;
    for (int i = 0; i < mx_strlen(temp); i++) {
        if (mx_isspace(temp[i]) && !mx_isspace(temp[i + 1])) {
            count++;
        } else if(!mx_isspace(temp[i])) {
            count++;
        }
    }
    int j = 0;
    char *str2 = mx_strnew(count);
    for (int i = 0; i < mx_strlen(temp); i++) {
        if (mx_isspace(temp[i]) && !mx_isspace(temp[i + 1])) {
            str2[j] = ' ';
            j++;
        } else if(!mx_isspace(temp[i])){
            str2[j] = temp[i];
            j++;
        }
    }
    mx_strdel(&temp);
    return str2;
}
