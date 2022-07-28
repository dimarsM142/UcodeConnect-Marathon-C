void mx_printchar(char);

void mx_pyramid(int n) {
    if(n <= 1 || n % 2 ) {
        return;
    }
    for(int i = 0; i <= n * 2; i++) {
        if(i == n - 1) {
            mx_printchar('/');
        } 
        else if(i == n) {
            mx_printchar('\\');
        }
        else {
            mx_printchar(' ');
        }
    }
    mx_printchar('\n');
     for(int i = 0; i < n - 2; i++) {
        for(int j = 0; j < 2 * n; j ++) {
            if(j == n - 2 - i) {
                mx_printchar('/');
            }    
            if(j == n + i - 1) {
                mx_printchar('\\');
            }
            if(j == n + 2 * i && i < n / 2 - 1) {
                mx_printchar('\\');
            }
            if(j == 2 * n - 3 && i >= n / 2 - 1) {
                mx_printchar('|');
            }
            else {
                mx_printchar(' ');
            }
        }
        mx_printchar('\n'); 
    }
    for(int i = 0; i <= 2 * n - 3; i++) {
        if(i == 0) {
            mx_printchar('/');
        }
        if(i == 2 * n - 3) {
            mx_printchar('\\');
        }
        else {
            mx_printchar('_');
        }
    }
    mx_printchar('|');
    mx_printchar('\n');
}
