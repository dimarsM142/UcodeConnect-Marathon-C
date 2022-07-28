#include <unistd.h>

int main(int argc, char *argv[]) {
    char nl = '\n';
    for(int counter = 1; counter < argc; counter++) {
        int length = 0;
        while(argv[counter][length] != '\0') {
            length++;
        }
        write(1, argv[counter], length);
        write(1, &nl, 1);
    }
    return 0;
}
