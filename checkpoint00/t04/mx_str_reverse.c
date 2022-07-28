void mx_str_reverse(char *s) {
    int counter_1 = 0;
    while(s[counter_1] != '\0') {
        counter_1++;
    }
    int counter_2 = 0;
    while(counter_2 != counter_1 / 2) {
        char temp = s[counter_2];
        s[counter_2] = s[counter_1 - 1 - counter_2];
        s[counter_1 - 1 - counter_2] = temp;
        counter_2++;
    }
}
