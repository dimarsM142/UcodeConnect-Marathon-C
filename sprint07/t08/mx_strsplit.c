#include <stdlib.h>
#include <stdio.h>

int mx_count_words(const char *, char);
char *mx_strncpy(char *, const char *, int);
void mx_strdel(char **);
char *mx_strnew(const int);

char **mx_strsplit(char const *s, char c) {
    int i = 0;
    int counter;
    int len; 
    int start;
    char **result = (char**)mx_strnew(mx_count_words(s, c));
    while (s[i] == c) {
       if (s[i]=='\0') {
           return NULL;
       }
       i++;
    }
    for (counter = 0; counter < mx_count_words(s, c); counter++) {
        len = 0;
        start = i;
        while (s[i] != c && s[i] != '\0') {
            len++;
            i++;
        }
        result[counter] = mx_strnew(len);
        mx_strncpy(result[counter], &s[start], len);
        while (s[i] == c) {
           i++;
        }
    }
    result[mx_count_words(s, c)] = NULL;
    return result;
}
