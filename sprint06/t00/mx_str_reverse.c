#include <stdio.h>
int mx_strlen(const char *);
void mx_swap_char(char *, char *);

void mx_str_reverse(char *s) {
    int counter = 0;
    while(counter != mx_strlen(s) / 2) {
        mx_swap_char(&s[counter], &s[mx_strlen(s) - 1 - counter]);
        counter++;
    }
}
