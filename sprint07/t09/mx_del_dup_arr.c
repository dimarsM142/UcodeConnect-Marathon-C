#include <stdlib.h>

int *mx_copy_int_arr(const int*, int);

int *mx_del_dup_arr(int *src, int src_size, int *dst_size) {
    if (src == NULL) {
        return NULL;
    }
    int arrn[src_size];
    int count = 0;
    for (int i = 0; i < src_size; i++) {
        int check = -1;
        for(int j = 0; j < i; j++) {
            if(src[i] == src[j]) {
                check = 1;
            }
        }
        if(check == 1) { 
            continue;
        }
        arrn[count] = src[i];
        count++;
    }
    int temp[count];
    for (int i = 0; i < count; i++) {
        temp[i] = arrn[i];
    }
    int *rarr = mx_copy_int_arr(temp, count);
    *dst_size = count;
    return rarr;
}
