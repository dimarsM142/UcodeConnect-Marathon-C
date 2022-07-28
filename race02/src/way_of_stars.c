#include "../inc/header.h"

void way(int *px, int *py, char **matrix_of_char, int len, int end_x, int end_y, int **matrix, int ryad, int stovp, int max) {
    for (int i = 0; i < len ; ++i) {
        matrix_of_char[py[i]][px[i]] = '*';
    }
    matrix_of_char[end_y][end_x] = '*';

    for (int i = 0; i < ryad; i++)  {
        for (int j = 0; j < stovp; j++) {
            if (matrix[i][j] == max) {
                if (matrix_of_char[i][j] == '*') {
                    matrix_of_char[i][j] ='X';
                } 
                else {
                    matrix_of_char[i][j] = 'D';
                } 
            }
        }
    }
}
