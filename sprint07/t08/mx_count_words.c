int mx_count_words(const char *str, char delimeter) {
    int counter = 1;
    int i = 0;
    while (str[i] == delimeter) {
       if (str[i] == '\0')
           return 0;
       i++;
    }
    while (str[i] != '\0') {
        if (str[i] == delimeter && str[i+1] != '\0' && str[i+1] != delimeter) {
            counter++;
        }
        i++;
    }
    return counter;
}
