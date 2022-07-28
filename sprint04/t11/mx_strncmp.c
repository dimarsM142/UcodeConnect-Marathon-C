int mx_strncmp(const char *s1, const char *s2, int n) {
    while (*s1 == *s2 && *s1 != '\0' && n != 0) {
        s1++;
        s2++;
        n--;
    }
    if(n != 0){
        return (int)(*s1 - *s2);
    }
    else {
        return 0;
    }
}
