#include <stdbool.h>

void mx_sort(int *arr, int size, bool (*f)(int, int)) {
    int min_idx;
    for (int i = 0; i < size -1; i++) {
        min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if ((*f)(arr[min_idx] , arr[j]))
                min_idx = j;
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
