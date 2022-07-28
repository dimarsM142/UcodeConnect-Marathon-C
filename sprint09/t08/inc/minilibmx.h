#ifndef MINILIBMX_H
#define MINILIBMX_H

#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>

#define NOT_NUM -666666

void mx_printchar(char c);
void mx_printint(int n);
void mx_printerr(const char *s);
void mx_printstr(const char *s);
int mx_strlen(const char *s);
int mx_strcmp(const char *s1, const char *s2);
int mx_atoi(const char *str);
bool mx_isdigit(int c);
bool mx_isspace(char c);
char *mx_strcpy(char *dst, const char *src);

#endif 
