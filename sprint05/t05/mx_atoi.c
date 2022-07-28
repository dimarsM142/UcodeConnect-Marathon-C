#include <stdbool.h>

bool mx_isdigit(int);
bool mx_isspace(char);

int mx_atoi(const char *str) {
    int i;
    long long check = 0;
    if(str[0] == '+') {
        for (i = 1; mx_isdigit(str[i]) || mx_isspace(str[i]); i++) {
            if (mx_isspace(str[i])) {
                continue;
            }
            
            check = (check * 10) + (str[i] - '0');
            if (!mx_isdigit(str[i]) && !mx_isspace(str[i])) {
                return 0;
            }
        }
        return (int)check;
    }
    if(str[0] == '-') {
        if(str[1] == 45 || !mx_isdigit(str[1])) {
            return 0;
        }
        for (i = 1; mx_isdigit(str[i]) || mx_isspace(str[i]); i++) {
            if (mx_isspace(str[i])) {
               continue;
            }
            if (!mx_isdigit(str[i]) && !mx_isspace(str[i])) {
                return 0;
            }
            check = (check * 10) + (str[i] - '0');
        }
        while(check < -2147483648) {
            check = check + 2147483647 + 2147483647;
        }
        return -(int)check;
    }
    int bool_f = 1;
    for (i = 0; mx_isdigit(str[i]) || mx_isspace(str[i]) || str[i] == '-' ; i++) {
        if (str[i] == '-' && mx_isdigit(str[i + 1])) {
            bool_f = -1;
            continue;
        }
        if (mx_isspace(str[i])) {
            continue;
        }
        check = (check * 10) + (str[i] - '0');
       
        if (!mx_isspace(str[i]) && str[i] != '-' && !mx_isdigit(str[i])) {
            return 0;
        }
    }
    while(check > 2147483647) {
        check = check - 2147483648 - 2147483648;
    }
    if (bool_f == 1) {
        return (int)check;
    }
    else  {
        return -(int)check;
    }
}
