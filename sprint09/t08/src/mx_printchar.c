#include <unistd.h>

void mx_printchar(char c){
	char* buff = &c;
	write(1, buff, 1); 
}
