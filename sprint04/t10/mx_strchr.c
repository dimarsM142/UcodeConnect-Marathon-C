char *mx_strchr(const char *s, int c) {
    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] == (char) c) {
            return (char *)&s[i];
        }
    }
    return 0;
}
