#include "../inc/header.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        mx_printerr("usage: ");
        mx_printerr(argv[0]);
        mx_printerr(" [source_file] [target_file]\n");
        return -1;
    }
    int file_check = open(argv[1], O_RDONLY);
    if (file_check < 0) {
        mx_printerr("mx_cp: ");
        mx_printerr(argv[1]);
        mx_printerr(": No such file or directory\n");
        return -1;
    }
    char buf;
    int result_file = open(argv[2], O_CREAT | O_EXCL | O_WRONLY, S_IRUSR | S_IWUSR);
    while (read(file_check, &buf, 1)) {
        write(result_file, &buf, 1);
    }
    close(file_check);
    close(result_file);
    return 0;
}
