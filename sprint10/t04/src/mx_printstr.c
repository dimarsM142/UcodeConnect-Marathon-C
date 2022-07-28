#include "../inc/header.h"

void mx_printstr(const char *str) {
    write(1, str, mx_strlen(str));
}
