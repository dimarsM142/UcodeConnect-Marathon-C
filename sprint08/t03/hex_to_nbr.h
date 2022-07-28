#ifndef HEX_TO_NBR_H
#define HEX_TO_NBR_H

#include <stdlib.h>
#include <stdbool.h>

bool mx_isalpha(int);
bool mx_islower(int);
bool mx_isupper(int);
bool mx_isdigit(int);
unsigned long mx_hex_to_nbr(const char*);

#endif
