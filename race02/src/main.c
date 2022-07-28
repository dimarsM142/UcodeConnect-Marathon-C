#include "../inc/header.h"

int main(int argc, char *argv[]) {
    if(argc != 6) {
        mx_printerr("usage: ");
        mx_printerr(argv[0]);
        mx_printerr(" [file_name] [x1] [y1] [x2] [y2]\n");
        exit(0);
    }
    int file = open(argv[1], O_RDONLY);
    if(file < 0)
    {
        mx_printerr("map does not exist\n");
        exit(0);
    }
    if(close(file) < 0) {
        mx_printerr("error\n");
        exit(0);
    }

    char *str = mx_file_to_str(argv[1]);
    int stovp = 0;
    int ryad = 0;

    int temp1 = 0;
    for(int i = 0; i < mx_strlen(str); i++){
        if(str[i] == '\n') {
            if(ryad == 0) {
                temp1 = i;
            }
            else {
                if(i + 1 != (temp1 + 1) * (ryad + 1)) {
                    mx_printerr("map error\n");
                    exit(0);
                }
            }
            if(i != mx_strlen(str) - 1 && (str[i+1] == ',' || str[i-1] == ',')) {
                mx_printerr("map error\n");
                exit(0);
            }
            ryad++;
        }
    }

    int start_x = mx_atoi(argv[2]);
    if(start_x == -1) {
        mx_printerr("map error\n");
        exit(0);
    }
    int start_y = mx_atoi(argv[3]);
    if(start_y == -1) {
        mx_printerr("map error\n");
        exit(0);
    }
    int end_x = mx_atoi(argv[4]);
    if(end_x == -1) {
        mx_printerr("map error\n");
        exit(0);
    }
    int end_y = mx_atoi(argv[5]);
    if(end_y == -1) {
        mx_printerr("map error\n");
        exit(0);
    }

    stovp = ((mx_strlen(str) / ryad)) / 2;

    int px[ryad * stovp];
    int py[ryad * stovp];

    int **matrix_of_int = mx_str_to_imatrix(str, ryad, stovp);
    char **matrix_of_char = mx_str_to_matrix(str, ryad, stovp);

    if (start_x >= stovp || end_x >= stovp || start_x < 0 || end_x < 0 || start_y < 0 || end_y < 0 |start_y >= ryad || end_y >= ryad) 
    {
        mx_printerr("points are out of map range\n");
        exit(0);
    }

    int max = dist(matrix_of_int, start_x, start_y, stovp, ryad);
    int len = lee(matrix_of_int, start_x, start_y, end_x, end_y, stovp, ryad, px, py);
    
    
    mx_printstr("dist=");
    mx_printint(max);
    mx_printchar('\n');
    
    mx_printstr("exit=");
    mx_printint(len);
    mx_printchar('\n');

    
    way(px, py, matrix_of_char, len, end_x, end_y, matrix_of_int, ryad, stovp, max);

    int fd = open("path.txt", O_WRONLY | O_TRUNC);
    if (fd < 0) {
        fd = open("path.txt", O_CREAT | O_WRONLY);
        if (fd < 0) {
            mx_printerr("error\n");
            exit(0);
        }
    }
    char nl = '\n';
    for (int i = 0; i < ryad; i++) {
        for (int j = 0; j < stovp; j++) {
            char temp = matrix_of_char[i][j];
            write(fd, &temp, 1);
        }
        write(fd, &nl, 1);
    }

    if(close(fd) < 0) {
        mx_printerr("error\n");
        exit(0);
    }
    for(int i = 0; i < ryad; i++) {
        free(matrix_of_int[i]);
    }
    free(matrix_of_int);
    for(int i = 0; i < ryad; i++) {
        free(matrix_of_char[i]);
    }
    free(matrix_of_char);
    free(str);
    return 0;
}
