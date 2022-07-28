#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        write(2, "usage: ./read_file [file_path]\n", 31);
        return -1;
    }
    ssize_t ref;
    int file_open = open(argv[1], O_RDONLY);
    if(file_open < 0) {
        write(2, "error\n", 6);
        return -1;
    }
    char text;
    while ((ref = read(file_open, &text, 1)) > 0) {
        write(1, &text, 1);
        if(ref < 0) {
            write(2, "error\n", 6);
            return -1;
        }
    }
    close(file_open);
    return 0;
}
