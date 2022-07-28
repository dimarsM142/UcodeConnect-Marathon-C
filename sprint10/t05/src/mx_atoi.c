#include "../inc/header.h"

int mx_atoi(const char *str) {
    int result = 0;
    bool sign = false;
    if(*str) {
        while(mx_isspace(*str))
            str++;
        if (*str == '-') {
            sign = true;
            str++;   
        }
        else if (*str == '+')
            str++; 
        while (mx_isdigit(*str)) {
            result *= 10;
            if (sign)
                result -= *str-48;
            else
                result += *str-48;
            str++;
        }
    }
    return result;
}


