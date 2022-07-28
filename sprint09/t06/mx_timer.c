#include <time.h>
#include <stdlib.h>

double mx_timer(void (*f)()) {
    if(clock() < 0) {
        return -1;
    }
    if(*f == NULL) {
        return -1;
    }
    clock_t first = clock();
    f();
    clock_t second = clock();
    return ((double)(second - first) / CLOCKS_PER_SEC); 
}
