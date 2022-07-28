#include <stdbool.h>

bool mx_isdigit(int);
bool mx_isspace(char);
int mx_atoi(const char *);
void mx_printchar(char);
void mx_printint(int);
int mx_strlen(const char *);

int main(int argc, char *argv[]) {
    if(argc != 3) {
        return 0;
    }
    int arg_first = mx_atoi(argv[1]);
    int arg_second = mx_atoi(argv[2]);
    if(arg_first < 0 || arg_first > 9 || arg_second < 0 || arg_second > 9) {
        return 0;
    }
    if(arg_second < arg_first) {
        int t = arg_first;
        arg_first = arg_second;
        arg_second = t;
    }
    for(int i = arg_first; i <= arg_second; i++) {
        for(int j = arg_first; j <= arg_second; j++) {
            mx_printint(i * j);
                if(j != arg_second) {
                    mx_printchar('\t');
                }
        }
        mx_printchar('\n');
    }
    return 0;
}
