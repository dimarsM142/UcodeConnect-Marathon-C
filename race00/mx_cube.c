void mx_printchar(char);

void mx_cube (int n) {
    if (n <= 1) {
        return;
    }
    int count = 0;
    for(int i = 0; i < n / 2 + 1; i++) {
         mx_printchar(' ');
    }
    mx_printchar('+');
    for(int i = n / 2; i < n * 2 + n / 2 ; i++) {
         mx_printchar('-');
    }
    mx_printchar('+');
     mx_printchar('\n');
     for(int i = 0; i <= (n - 2) / 2; i++){
        for(int j = 0; j <= n * 2 + n / 2 + 1; j++) {
            if(j == n / 2 - i|| j == n * 2  + n / 2  + 1 - i ){
                mx_printchar('/');
            }
            else {
                mx_printchar(' ');
            }
            if( j == n * 2 + n / 2 + 1){
                mx_printchar('|');
            }
        }
        mx_printchar('\n');
    }
    mx_printchar('+');
    for(int i = 0; i <= n * 2 + n / 2 + 1 ; i++){
        if(i < n * 2)
            mx_printchar('-');
        else if (i == n * 2) {
            mx_printchar('+');
        }
        else if(i == n * 2 + n / 2 + 1) {
            mx_printchar('|');
        }
        else{
            mx_printchar(' ');
        }
    }
    mx_printchar('\n');
    for(int i = 0; i <= n - 1 ; i++){
        for(int j = 0; j <= n * 2 + n / 2 + 1; j++) {
           if(j == 0 || j == n * 2 + 1 ){
                mx_printchar('|');
            }
            else {
                mx_printchar(' ');
            }
            if(j == n * 2 + n / 2 + 1 && i < ((n -1 )/ 2)) {
                mx_printchar('|');
            }
            if(j == n * 2 + n / 2 + 1 && i == (n-1) / 2) {
                mx_printchar('+');
                count++;
            }
            if(j == n * 2 + n / 2  + 1 - count && i == (n-1) / 2 + count) {
                mx_printchar('/');
                count++;
            }
        }
        mx_printchar('\n');
    }
    mx_printchar('+');
    for(int i = 0; i < n * 2; i++){
        mx_printchar('-');
    }
    mx_printchar('+');
    mx_printchar('\n');
}
