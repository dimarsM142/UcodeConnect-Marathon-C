#include "../inc/header.h"

int mx_count_words(const char *str) {
    bool flag = 0;
    int count = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (mx_isspace(str[i])) {
            flag = false;
        }
        else if (!flag) {
            flag = true;
            count++;
        }
    }
    
    return count;
}
