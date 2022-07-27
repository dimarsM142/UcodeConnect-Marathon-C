void mx_printchar(char);

void mx_printint(int n) {
    int start = n;
    int i = 0;
    while(n != 0) {
        start = start / 10;
        i++;
    }
    int array[i];
    int counter_arr = 0;
    while(n != 0) { 
        array[counter_arr] = n % 10;
        n = n / 10;
        counter_arr++;
    }
    for(int j = counter_arr - 1; j >= 0; j--) {
        mx_printchar(array[j] + 48);
    }
}
