#include <stdio.h>

int mx_strlen(const char *s){
	int amount = 0;
	for (; *s;s++){
		amount++;
	}
	return amount;
}
