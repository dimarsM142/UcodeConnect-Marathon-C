void mx_printchar(char c);
int mx_strlen(const char*);
void mx_printstr(const char *s);
int mx_strcmp(const char *, const char *);

int main(int argc, char *argv[]) {
    int mustSort = 1;
    while (mustSort == 1) {
        mustSort = 0;
        for (int i = 1; i < argc - 1; i++) {
            if ((mx_strcmp(argv[i], argv[i+1])) >= 0) {       
                char *temp = argv[i];
                argv[i] = argv[i+1];
                argv[i+1] = temp;
                mustSort = 1;          
            }
        }
    }     
    for(int i = 1; i < argc; i++) {
        mx_printstr(argv[i]);
        mx_printchar('\n'); 
    }
    return 0;
}
