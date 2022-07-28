#include <unistd.h>

void mx_printint(int n) {

	if (n == -2147483648) {
		write(1, "-2147483648", 11);
		return;
	}

	if (n < 0) {
		write(1, "-", 1);
        n *= -1;
	}

	if (n == 0) {
		write(1, "0", 1);
	}

	int length = 0, temp_n = n;

	while (temp_n != 0) {
		temp_n /= 10;
		length++;
	}

	char array[length];

	for (int i = 0; i < length; i++) {
		int d = n % 10;
		array[i] = d + 48;
		n /= 10;
	}

	for(int i = length - 1; i >= 0; i--) {
		write(1, &array[i], 1);
	}
}
