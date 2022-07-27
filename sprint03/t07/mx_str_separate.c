#include <stdio.h>
void mx_printchar(char);

void mx_str_separate(const char *str, char delim) {
    for(int i = 0; str[i] != '\0'; i++) {
        if (str[i] == delim) {
            while (str[i] == str[i+1]) {
                i++;
            }
            mx_printchar('\n');
        }
        else { 
            mx_printchar(str[i]);
        }
    }
    mx_printchar('\n');
}
