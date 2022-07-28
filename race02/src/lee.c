#include "../inc/header.h"

int lee(int **matrix, int start_x, int start_y, int end_x, int end_y, int stovp, int ryad, int *px, int *py)  {

    int len;
    int direction_x[4] = {1, 0, -1, 0};
    int direction_y[4] = {0, 1, 0, -1};
    int d; 
    int x; 
    int y; 
    int k;
    bool stop = false;
    if (matrix[start_y][start_x] == -2 ) 
    {
        mx_printerr("entry point cannot be an obstacle\n");
        exit(0);
    }

    if (matrix[end_y][end_x] == -2 ) 
    {
        mx_printerr("exit point cannot be an obstacle\n");
        exit(0);
    }

    d = 0;

    matrix[start_y][start_x] = 0; 

    while (!stop) {
        stop = true;

        for (y = 0; y < ryad; y++) {
            for (x = 0; x < stovp; x++) {
                if (matrix[y][x] == d) {
                    for (k = 0; k < 4; k++) {

                        int iy = y + direction_y[k]; 
                        int ix = x + direction_x[k];

                        if (iy >= 0 && iy < ryad && ix >= 0 && ix < stovp && matrix[iy][ix] == -1 ) {
                            stop = false;  
                            matrix[iy][ix] = d + 1;
                        }
                    }
                }
            }   
        }
            
        d++;
    }

    if (matrix[end_y][end_x] == -1) {
        mx_printerr("route not found\n");
        exit(0);
    }

    len = matrix[end_y][end_x];    

    x = end_x;
    y = end_y;
    d = len;

    while (d > 0) {
        px[d] = x;
        py[d] = y;
        d--;
        for (k = 0; k < 4; k++) {

            int iy = y + direction_y[k]; 
            int ix = x + direction_x[k];

            if (iy >= 0 && iy < ryad && ix >= 0 && ix < stovp && matrix[iy][ix] == d) {
                x = x + direction_x[k];
                y = y + direction_y[k];
                break;
            }
        }
    }

    px[0] = start_x;
    py[0] = start_y;      

    return len;
}
