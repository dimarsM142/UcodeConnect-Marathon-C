void mx_printchar(char);
void mx_printstr(const char *);
char *mx_strchr(const char *, int);

int main(int argc, char *argv[]) {
    argc++;
    char* n = argv[0];
    int counter = 0;
    int i = 0;
    while(n[i]) {
        if(n[i] == '/') {
            counter++;
        }
        i++;
    }
    for(int i = 0; i < counter; i++) {
        n = mx_strchr(n, '/');
        if(n[0] == '/')
            n = mx_strchr(n, n[1]);
    }
    mx_printstr(n);
    mx_printchar('\n');
    return 0;
}
