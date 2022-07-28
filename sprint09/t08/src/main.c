#include "../inc/calculator.h"
#include "../inc/minilibmx.h"

int main (int argc, char *argv[]) {
    if (argc != 4) {
        mx_printerr("usage: ./calc [operand1] [operation] [operand2]\n");
        return -1;
    }

    enum e_error error = -1;
    enum e_operation operator_enum;
    t_operation operation;

    if (mx_atoi(argv[1]) == NOT_NUM || mx_atoi(argv[3]) == NOT_NUM) {
        error = INCORRECT_OPERAND;
    }

    int first_num = mx_atoi(argv[1]);
    int second_num = mx_atoi(argv[3]);
    char *operator_char = argv[2];

    if (mx_strcmp(operator_char, "+") == 0) {
        operator_enum = ADD;
        operation.op = operator_enum;
        operation.f = mx_add;
    }
    else if (mx_strcmp(operator_char, "-") == 0) {
        operator_enum = SUB;
        operation.op = operator_enum;
        operation.f = mx_sub;
    }
    else if (mx_strcmp(operator_char, "*") == 0) {
        operator_enum = MUL;
        operation.op = operator_enum;
        operation.f = mx_mul;
    }
    else if (mx_strcmp(operator_char, "/") == 0) {
        operator_enum = DIV;
        operation.op = operator_enum;
        operation.f = mx_div;
    }
    else if (mx_strcmp(operator_char, "%") == 0) {
        operator_enum = MOD;
        operation.op = operator_enum;
        operation.f = mx_mod;
    }
    else {
        error = INCORRECT_OPERATION;
    }

    if (second_num == 0 && operator_enum == DIV) {
        error = DIV_BY_ZERO;
    }

    if (error == INCORRECT_OPERAND) {
        mx_printerr("error: invalid number\n");
        return -1;
    }
    else if (error == INCORRECT_OPERATION) {
        mx_printerr("error: invalid operation\n");
        return -1;
    }
    else if (error == DIV_BY_ZERO) {
        mx_printerr("error: division by zero\n");
        return -1;
    }

    int result = operation.f(first_num, second_num);

    mx_printint (result);
    mx_printchar('\n');
    return 0;
}
