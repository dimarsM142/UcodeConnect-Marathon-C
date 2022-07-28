#include <stdbool.h>

bool mx_isdigit(int);
bool mx_isspace(char);

int mx_atoi(const char *str) {
    int i;
    long long check = 0;
    if(str[0] == '-') {
        for (i = 1; (mx_isdigit(str[i]) && !mx_isspace(str[i])); i++) {
            check = (str[i] - '0') + (10 * check);
        }
        while(check < -2147483647 - 1) {
            check = check + 2147483647 + 2147483647;
        }
        return -(int)check;
    }
    for (i = 0; (mx_isdigit(str[i]) && !mx_isspace(str[i])); i++) {
        check = (check * 10) + (str[i] - '0');
    }
    while(check > 2147483647) {
        check = check - 2147483648 - 2147483648;
    }
    return (int)check;
}
