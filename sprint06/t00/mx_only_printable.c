#include <unistd.h>

void mx_printchar(char);

void mx_only_printable() {
    for(int i = 126; i >= 32; i--){
        mx_printchar(i);
    }
    mx_printchar('\n');
}
