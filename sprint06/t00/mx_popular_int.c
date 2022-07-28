int mx_popular_int(const int *arr, int size) {
    int counter = 0;
    int max_counter = 0;
    int num_counter = 0;
    int j = 0;
    for(int i = 0; i < size; i++) {
        counter = 0;
        for(j = 0; j < size; j++) {
            if(arr[i] == arr[j]){
                counter++; 
            }
            if(counter > max_counter) {
                max_counter = counter;
                num_counter = j;
            }   
        }
    }
    return arr[num_counter];
}
