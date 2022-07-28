#include <stdlib.h>

int mx_strlen(const char*);
char *mx_strjoin(char const *, char const *);
char *mx_strdup(const char *);
char *mx_strnew(const int);
void mx_strdel(char **);

char *mx_concat_words(char **words) {
    if(words == NULL) {
        return NULL;
    }
    char *result = mx_strdup(words[0]);
    for (int i = 1; words[i] != NULL; i++) {
        char *temp = mx_strjoin(result, " ");
        mx_strdel(&result);
        result = mx_strjoin(temp, words[i]);
        mx_strdel(&temp);
    }
    return result;
}
