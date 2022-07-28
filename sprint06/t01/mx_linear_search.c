int mx_strcmp(const char *, const char *);

int mx_linear_search(char **arr, const char *s) {
    if(!arr)
        return -1;
    if(!s)
        return -1;
    int i = 0;
    while(arr[i]) {
        if(mx_strcmp(arr[i], s) == 0) {
            return i;
        }
        i++;
    }
    return -1;
}
