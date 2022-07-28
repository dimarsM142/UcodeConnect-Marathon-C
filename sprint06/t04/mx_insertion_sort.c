int mx_strlen(const char *s);

int mx_insertion_sort(char **arr, int size) {
    int count = 0;
    for (int i = 1; i < size; i++){
        char *num = arr[i];
        int c = i - 1;
        while (c >= 0 && (mx_strlen(arr[c]) > mx_strlen(num))) {
            arr[c + 1] = arr[c];
            c--;
            count++;
        }
        arr[c + 1] = num;
    }
    return count;
}
