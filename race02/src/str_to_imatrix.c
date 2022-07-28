#include "../inc/header.h"

int **mx_str_to_imatrix(char *str, int row, int column) {
    int **res = (int **)malloc(row * 8);
    for (int i = 0; i < row; i++) {
        res[i] = (int *)malloc(column * 4);
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
                if (str[2 *(j + (i * (column)))] == '#') {
                    res[i][j] = -2;
                }
                if (str[2*(j + (i * (column)))] == '.') {
                    res[i][j] = -1;
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
