#include <stdbool.h>
#include <stdio.h>

bool mx_isdigit(int);
bool mx_isspace(char);

int mx_atoi(const char *str) {
    int i;
    long long check = 0;
    if(str[0] == '-') {
        if(str[1] == 45 || !mx_isdigit(str[1]) || mx_isspace(str[1])) {
            return 0;
        }
        for (i = 1; str[i] != '\0'; i++) {
            if (!mx_isdigit(str[i])) {
                return 0;
            }
            check = (check * 10) + (str[i] - '0');
        }
        while(check < -2147483647 - 1) {
            check = check + 2147483647 + 2147483647;
        }
        return -(int)check;
    }
    if(str[0] == '+') {
        for (i = 1; str[i] != '\0'; i++) {
            
            check = (check * 10) + (str[i] - '0');
            if (!mx_isdigit(str[i])) {
                return 0;
            }
        }
        return (int)check;
    }
    for (i = 0; str[i] != '\0'; i++) {
        check = (check * 10) + (str[i] - '0');
        if (!mx_isdigit(str[i])) {
            return 0;
        }
    }
    while(check > 2147483647) {
        check = check - 2147483648 - 2147483648;
    }
    return (int)check;
}
