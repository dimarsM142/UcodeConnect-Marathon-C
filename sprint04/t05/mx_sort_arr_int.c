void mx_sort_arr_int(int *arr, int size) {
    int check = 1;
    int t;
    while(check)
    {
        check = 0;
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i] > arr[i+1])
            {
                t = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = t;
                check = 1;
            }
        }
    }
}
