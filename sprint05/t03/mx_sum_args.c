int mx_atoi(const char *);
void mx_printchar(char);
void mx_printint(int);

int main(int argc, char* argv[]) {
    if(argc == 1){
        return 0;
    }     
    int res = 0;
    for(int i = 1; i < argc; i++) {
        res += mx_atoi(argv[i]);
    }
    mx_printint(res);
    mx_printchar('\n');
    return 0;
}
