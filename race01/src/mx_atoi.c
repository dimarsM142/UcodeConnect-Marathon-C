#include "../inc/header.h"

long long mx_atoi(const char *str, bool flag) {
	if(flag == 1) {
    	int i;
    	long long n = 0;
    	if(str[0] == '-') {
    	    for (i = 1; (mx_isdigit(str[i]) && !mx_isspace(str[i])); i++) {
    	        n = (n * 10) + (str[i] - '0');
    	    }
    	    return -n;
	    }
    	for (i = 0; (mx_isdigit(str[i]) && !mx_isspace(str[i])); i++) {
        	n = (n * 10) + (str[i] - '0');
    	}
    	return n;
	}
	else {
		long long result = 0;
		int is_below_zero;
		if(str[0] == '-') {
			is_below_zero = -1;
		}
		else {
			is_below_zero = 1;
		}
		if(str[0] == 0){
			return 0;
		}
		if (!(mx_isdigit(str[0])) && str[0] != '-' && str[0] != '+') {
			return 0;
		}
		if (str[0] == '-' || str[0] == '+') {
			str++;
		}
		int i = 0;
		for(; str[i] != '\0'; i++) {
			if(!mx_isdigit(str[i])) {
				return 0;
			}

			result *= 10;
		
			result += str[i] - '0';

		}
		if (str[i] != '\0') {
			return 0;
		}

		return result * is_below_zero;
	}
}
