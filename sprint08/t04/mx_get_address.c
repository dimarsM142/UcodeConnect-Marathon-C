#include "get_address.h"

char *mx_get_address(void *p) {
	unsigned long adr = (unsigned long)&p;
	char* str_adr = mx_nbr_to_hex(adr);
	int len = mx_strlen(str_adr);

	char* result = (char*)malloc(len + 2);
	*result++ = '0';
	*result++ = 'x';

	mx_strcpy(result, str_adr);
	free(str_adr);
	
	return result -= 2;
}
