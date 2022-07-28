#include "../inc/header.h"

char *mx_file_to_str(const char *filename) {
    if (filename == NULL){
         return NULL;
    }
    int file_check = open(filename, O_RDONLY);
    if (file_check < 0){
         return NULL;
    }
    int length = 0;
    char buf;
    while (read(file_check, &buf, 1)){
        length++;
    }
    if (close(file_check) < 0){
         return NULL;
    }
    file_check = open(filename, O_RDONLY);
    if (file_check < 0){
         return NULL;
    }
    char *str = mx_strnew(length);
    for (int i = 0; read(file_check, &buf, 1); i++) {
        str[i] = buf;
    }
    if (close(file_check) < 0){
        return NULL;
    }
    return str;
}
