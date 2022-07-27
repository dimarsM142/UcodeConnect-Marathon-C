#include <unistd.h>

void mx_matrix_voice(void) {
	char *voice = "\a";
	write(1, voice, 1);
}

