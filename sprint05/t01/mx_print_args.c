void mx_printchar(char );
int mx_strlen(const char*);
void mx_printstr(const char *);

int main(int argc, char *argv[]) {
    for(int i = 1; i < argc; i++) {
        mx_printstr(argv[i]);
        mx_printchar('\n'); 
    }
    return 0;
}
