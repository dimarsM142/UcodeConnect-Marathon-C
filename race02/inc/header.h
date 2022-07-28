#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>
#include <unistd.h>

int mx_strlen(const char *s);
void mx_printchar(char c);
void mx_printint(int n);
bool mx_isdigit(int c);
bool mx_isspace(char c);
void mx_printstr(const char *s);
int mx_strcmp(const char *s1, const char *s2);
void mx_strdel(char **str);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strnew(const int size);
char *mx_strtrim(const char *str);
void mx_printerr(const char *s);
int mx_atoi(const char *str);
char *mx_file_to_str(const char *filename);
int dist(int **grid, int start_x, int start_y, int stovp, int ryad);
int lee(int **matrix, int start_x, int start_y, int end_x, int end_y, int stovp, int ryad, int *px, int *py);
void way(int *px, int *py, char **matrix_of_char, int len, int end_x, int end_y, int **matrix, int ryad, int stovp, int max);


char **mx_str_to_matrix(char * str, int row, int column);
int **mx_str_to_imatrix(char *str, int row, int column);
#endif
