#include "../inc/calculator.h"

int mx_atoi(const char *str) {
  	int temp = 0;
    int flag = 0;
  	int result = 0;
  	for (unsigned int i = 0; str[i]; ++i) {
    	if (!mx_isspace(str[i])) {
      		if (mx_isdigit(str[i]))
        		result = result * 10 + (str[i] - '0');
      		else if (mx_isspace(str[i + 1]) && str[i] == '-')
        		return NOT_NUM;
      		else {
        		if (str[i] == '-') {
                    if (!str[i + 1])
                        return NOT_NUM;
          			else if (temp == 0 && flag == 0)
          				temp = 1;
          			else
          				return NOT_NUM;
        		}
                else if (str[i] == '+') {
                    if (!str[i + 1])
                        return NOT_NUM;
                    else if (flag == 0 && temp == 0) {
                        flag = 1;
                    }
                    else
                        return NOT_NUM;
                }
        		else
        			return NOT_NUM;
      		}
    	}
  	}
    if(temp == 1) {
        return -result;
    }
    else {
        return result;
    }
}
