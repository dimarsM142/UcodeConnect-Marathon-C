int mx_count_words(const char *str, char delimeter) {
    int counter_2 = 0;
    int counter_1 = 1;
    while (str[counter_2] == delimeter || str[counter_2] == '\0') {
        if (str[counter_2] == '\0')
            return 0;
        counter_2++;
    }
    while (str[counter_2] != '\0') {
        if (str[counter_2] == delimeter && str[counter_2 + 1] != '\0' && str[counter_2 + 1] != delimeter) {
            counter_1++;
        }
        counter_2++;
    } 
    return counter_1;
}
