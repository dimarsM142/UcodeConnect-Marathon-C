#include <stdbool.h>

bool mx_isspace(char c) {
    return c == ' ' || c == '\n' || c == '\v' || c == '\t' || c == '\f' || c == '\r';
}
