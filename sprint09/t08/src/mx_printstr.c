#include <unistd.h>

void mx_printstr(const char *s) {
	int length = 0;

	while (s[length] != '\0') {
		length++;
	}

	write(1, s, length);
}

