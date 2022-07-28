#include <unistd.h>

void mx_printerr(const char *s) {
    int i = 0;
    for (; s[i] != '\0'; i++) {
    }
    write(2, s, i);
}
