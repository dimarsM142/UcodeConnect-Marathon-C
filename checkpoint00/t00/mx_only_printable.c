#include <unistd.h>

void mx_only_printable() {
    for(int i = 126; i >= 32; i--){
        write(1, &i, 1);
    }
    int temp = 10;
    write(1, &temp, 1);
}
