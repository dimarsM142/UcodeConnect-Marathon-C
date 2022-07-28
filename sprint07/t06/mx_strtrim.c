#include <stdlib.h>
#include <stdbool.h>

bool mx_isspace(char);
int mx_strlen(const char*);
char *mx_strnew(const int);
void mx_strdel(char **);
char *mx_strncpy(char *, const char *, int);

char *mx_strtrim(const char *str) {
    char *temp = mx_strnew(mx_strlen(str));
    temp = mx_strncpy(temp, str, mx_strlen(str));
    int start_counter = 0;
    int end_counter = mx_strlen(str) - 1;
    while(mx_isspace(str[start_counter])) {
        start_counter++;
    }
    while(mx_isspace(str[end_counter])) {
        end_counter--;
    }
    char *result = mx_strnew(end_counter - start_counter + 1);
    int j = 0;
    for (int i = start_counter; i <= end_counter; i++) {
        result[j] = temp[i];
        j++;
    }
    mx_strdel(&temp);
    return result;
}
