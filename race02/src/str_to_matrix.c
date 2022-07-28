#include "../inc/header.h"

char **mx_str_to_matrix(char *str, int row, int column) {
    char **res = (char **)malloc(row * 8);
    for (int i = 0; i < row; i++) {
        res[i] = (char*)malloc(column);
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
                if (str[2 *(j + (i * (column)))] == '#') {
                    res[i][j] = '#';
                }
                if (str[2*(j + (i * (column)))] == '.') {
                    res[i][j] = '.';
                }
                if (str[j + i * (column + 1)] != ',' &&
                str[j + i * (column + 1)] != '\n' &&
                str[j + i * (column + 1)] != '.' &&
                str[j + i * (column + 1)] != '#') {
                    mx_printerr("map error\n");
                    exit(0);
                }
        }
    }
    return res;
}
