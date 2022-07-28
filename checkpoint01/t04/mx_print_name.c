#include <unistd.h>

static void mx_printint(int n) {
    int temp = 48;
    if (n == 0) {
        temp = 48;
        write(1, &temp, 1);
        return;
    }
    if (n < 0) {
        temp = 45;
        write(1, &temp, 1);
        n *= -1;
    }
    int new_temp = n;
    int counter = 0;
    while(new_temp != 0) {
        new_temp = new_temp / 10;
        counter++;
    }
    int array[counter];
    int count_mass = 0;
    while(n != 0) { 
        array[count_mass] = n % 10;
        n /= 10;
        count_mass++;
    }
    for(int j = count_mass - 1; j >= 0; j--) {
        temp = array[j] + 48;
        write(1, &temp, 1);;
    }
}

int main(int argc, char * argv[]) {
    int i = 0;
    char new_line = '\n';
    for (; argv[0][i] != '\0'; i++) {

    }
    write(1, argv[0], i);
    write(1, &new_line, 1);
    mx_printint(argc);
    write(1, &new_line, 1);
    return 0;
}
