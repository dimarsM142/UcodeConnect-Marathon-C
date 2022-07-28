char *mx_strstr(const char *s1, const char *s2);
char *mx_strchr(const char *s, int c);
int mx_strlen(const char *s);
int mx_strncmp(const char*s1, const char*s2, int n);

int mx_count_substr(const char *str, const char *sub) {
	int len = mx_strlen(sub);
	int counter = 0;

	for (str = mx_strstr(str, sub); str != 0; str = mx_strstr(str + len, sub)) {
		counter++;
	}
	return counter;
}
