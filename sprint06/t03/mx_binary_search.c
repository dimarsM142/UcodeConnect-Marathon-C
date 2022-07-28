int mx_strcmp(const char *s1, const char *s2);

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int left = 0;
    int right = size - 1;
    while(left <= right) {
        *count = *count + 1;
        int middle = left + (right - left) / 2;
        if(mx_strcmp(arr[middle], s) == 0)
            return middle;
        if(mx_strcmp(s, arr[middle]) > 0) {
            left = middle + 1;
        }
        if(mx_strcmp(s, arr[middle]) < 0) {
            right = middle -1;
        }

    }
    *count = 0;
    return -1;
}
