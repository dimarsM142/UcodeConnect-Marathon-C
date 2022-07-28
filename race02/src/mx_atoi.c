#include "../inc/header.h"

int mx_atoi(const char *str) {
	long long result = 0;
	int is_below_zero;
	if(str[0] == '-') {
	is_below_zero = -1;
	}
	else {
		is_below_zero = 1;
	}
	if (!(mx_isdigit(str[0])) && str[0] != '-' && str[0] != '+') {
		return -1;
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
		return -1;
	}
	return result * is_below_zero;
}
