int mx_strcmp(const char *, const char *);
int mx_strlen(const char *);

int mx_selection_sort(char **arr, int size)
{  
    int counter = 0;
    for (int i = 0; i < size-1; i++)
    {
        int minimal_index = i;
        for (int j = i+1; j < size; j++) {
            if (mx_strlen(arr[j]) < mx_strlen(arr[minimal_index])) {
                minimal_index = j;
            }
            if (mx_strlen(arr[j]) == mx_strlen(arr[minimal_index])) {
                if(mx_strcmp(arr[j], arr[minimal_index]) < 0) {
                    minimal_index = j;
                }
            }
        }
        if(i != minimal_index) {
            char* temp = arr[minimal_index];
            arr[minimal_index] = arr[i];
            arr[i] = temp;
            counter++;
        }
    }
    return counter;
}
