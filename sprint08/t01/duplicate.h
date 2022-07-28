#ifndef HEAD
#define HEAD

#include <stdlib.h>

int *mx_copy_int_arr(const int *, int);

typedef struct starr {
    int *arr;
    int size;
}    tmarr;

t_intarr *mx_del_dup_sarr(t_intarr *);

#endif
