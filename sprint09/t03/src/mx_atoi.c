#include "../inc/header.h"

int mx_atoi(const char *str) {
    bool minus = false;
    bool none = false;
    int num = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-' && mx_isdigit(str[i + 1]))
            minus = true;
        else if (str[i] == '+' && mx_isdigit(str[i + 1]))
            continue;
        else if (!mx_isdigit(str[i]) || mx_isspace(str[i])) {
            none = true;
            break;
        }
        if (mx_isdigit(str[i]))
            num = num * 10 + (int)str[i] - 48;
    }

    return minus ? -num : num;
}

