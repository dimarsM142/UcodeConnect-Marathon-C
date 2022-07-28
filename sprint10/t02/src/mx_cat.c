#include "../inc/header.h"

int main(int argc, char *argv[]) {
    char temp;
    if (argc == 1) {
        while (read(0, &temp, 1))
            write(1, &temp, 1);
    }
    int fread;
    for(int i = 1; i < argc; i++) {
        fread = open(argv[i], O_RDONLY);
        if (fread < 0) {
            mx_printerr("mx_cat: ");
            mx_printerr(argv[i]);
            mx_printerr(": No such file or directory\n");
            exit(-1);
        }
        else
            while (read(fread, &temp, 1)) {
                write(1, &temp, 1);
            }
        close(fread);
    }
    return 0;
}
