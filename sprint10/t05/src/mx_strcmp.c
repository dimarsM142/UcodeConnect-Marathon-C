  int mx_strcmp(const  char *s1, const char *s2) {
    int count = 0;

    while (s1[count] == s2[count]) {
        if (s1[count] == '\0')
            return 0;
        count++;
    }  
    return s1[count]-s2[count];
}

