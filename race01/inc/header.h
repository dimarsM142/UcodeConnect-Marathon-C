#ifndef CALC_H
#define CALC_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

char *mx_strncpy(char *, const char *, int);
char *mx_strtrim(const char *str);
void mx_swap_char(char *, char *);
bool mx_isdigit(int c);
bool mx_isspace(char c);
long long mx_atoi(const char* str, bool flag);
void mx_printchar(char);
void mx_printint(int);
int mx_strncmp(const char*, const char*, int);
void mx_printerr(const char *);
void mx_str_reverse(char *);
char* mx_strcpy(char * , const char *);
int mx_strlen(const char *);
char *mx_strnew(const int);
char *mx_strdup(const char *);
void mx_printstr(const char *);
double mx_pow(double, unsigned int);
void mx_strdel(char **);
char *mx_itoa(long long);
int mx_length_int(int);

void operators(char *, char *, char *, char *);
void check_params(char *operand1, char *operator, char *operand2, char *result, char *argv[]);

#endif
