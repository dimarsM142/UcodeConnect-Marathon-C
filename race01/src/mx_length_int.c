#include "../inc/header.h"

int mx_length_int(int number) {
    int counter = 0;
    while (number) {
	    number /= 10;
	    counter++;
    }
    return counter;
}
