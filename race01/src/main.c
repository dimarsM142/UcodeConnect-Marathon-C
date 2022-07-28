 #include "../inc/header.h"

int main(int argc, char *argv[]) {
    char *operand1;
    char *operation;
    char *operand2;
    char *result;
    if(argc != 5) {
        mx_printerr("usage: ./part_of_the_matrix [operand1] [operation] [operand2] [result]");
        mx_printerr("\n");
        return -1;
    }
    operand1 = mx_strtrim(argv[1]); 
    operation = mx_strtrim(argv[2]);
    operand2 = mx_strtrim(argv[3]);
    result = mx_strtrim(argv[4]);
    
    check_params(operand1, operation, operand2, result, argv);
    operators(operand1, operation, operand2, result);
    free(operand1); 
    operand1 = NULL;
    free(operation); 
    operation = NULL;
    free(operand2); 
    operand2 = NULL;
    free(result); 
    result = NULL;
    return 0;
}
