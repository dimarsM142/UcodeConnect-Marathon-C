#include "../inc/header.h"

void check_params(char *operand1, char *operator, char *operand2, char *result, char *argv[]) {
    if(operator == NULL) {
        mx_printerr("Invalid operation: ");
        mx_printerr(argv[2]);
        mx_printerr("\n");
        exit(-1);
    }
    if(mx_strlen(operator) != 1) {
        mx_printerr("Invalid operation: ");
        mx_printerr(argv[2]);
        mx_printerr("\n");
        exit(-1);
    }
    if (*operator != '*' && *operator != '-' && *operator != '+' && *operator != '/' && *operator != '?') {
        mx_printerr("Invalid operation: ");
        mx_printerr(argv[2]);
        mx_printerr("\n");
        exit(-1);
    }
    if(result == NULL) {
        mx_printerr("Invalid result: ");
        mx_printerr(argv[4]);
        mx_printerr("\n");
        exit(-1);
    }
    if(operand1 == NULL) {
        mx_printerr("Invalid operand: ");
        mx_printerr(argv[1]);
        mx_printerr("\n");
        exit(-1);
    }
    if(operand2 == NULL) {
        mx_printerr("Invalid operand: ");
        mx_printerr(argv[3]);
        mx_printerr("\n");
        exit(-1);
    }
    for(int i = 0; i < mx_strlen(operand1); i++) {
        if(operand1[0] == '-' && operand1[1] == '\0') {
            mx_printerr("Invalid operand: ");
            mx_printerr(argv[1]);
            mx_printerr("\n");
            exit(-1);
        }
        if(operand1[i] == '-' && i == 0) {
            continue;
        }
        if(!mx_isdigit(operand1[i]) && operand1[i] != '?' ) {
            mx_printerr("Invalid operand: ");
            mx_printerr(argv[1]);
            mx_printerr("\n");
            exit(-1);
        }
    }
    for(int i = 0; i < mx_strlen(operand2); i++) {
        if(operand2[0] == '-' && operand2[1] == '\0') {
            mx_printerr("Invalid operand: ");
            mx_printerr(argv[3]);
            mx_printerr("\n");
            exit(-1);
        }
        if(operand2[i] == '-' && i == 0) {
            continue;
        }
        if(!mx_isdigit(operand2[i]) && operand2[i] != '?' ) {
            mx_printerr("Invalid operand: ");
            mx_printerr(argv[3]);
            mx_printerr("\n");
            exit(-1);
        }
    }
    for(int i = 0; i < mx_strlen(result); i++) {
        if(result[0] == '-' && result[1] == '\0') {
            mx_printerr("Invalid operand: ");
            mx_printerr(argv[4]);
            mx_printerr("\n");
            exit(-1);
        }
        if(result[i] == '-' && i == 0) {
            continue;
        }
        if(!mx_isdigit(result[i]) && result[i] != '?' ) {
            mx_printerr("Invalid operand: ");
            mx_printerr(argv[4]);
            mx_printerr("\n");
            exit(-1);
        }
    }    
}
