#include "../inc/header.h"

char *mx_strstr(const char *s1, const char *s2) {
	if (mx_strlen(s2) > mx_strlen(s1)) 
		return 0;
    int i = 0;
    while (s1[i] != 0) {
        if(mx_strncmp(&s1[i], s2, mx_strlen(s2)) == 0)
			return mx_strchr(&s1[i], s2[0]);
        i++;
    }
	return 0;
}
