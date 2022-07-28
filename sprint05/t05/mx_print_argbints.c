int mx_atoi(const char *);
void mx_printchar(char);
void mx_printint(int);

int main(int argc, char *argv[]) {
    int a[argc - 1];
    for(int i = 1; i < argc; i++) {
        a[i - 1] = mx_atoi(argv[i]);
    }
    for(int i = 0; i < argc - 1; i++) { 
        int key = a[i];
        int flag = 0;
        if(key < 0) {
            key = key + 2147483648;
            if(key < 0) {
                key *= -1;
            }
            flag =1;
        }
        int t_arr[32];
        for (int j = 0; j < 32; j++) {
            t_arr[j] = key % 2;
            key /= 2;
        }
        mx_printint(flag);
        for(int j = 30; j >= 0; j--) {
            mx_printint(t_arr[j]);
        }
        mx_printchar('\n');
    }
}
