#include "../inc/header.h"

void operators(char *operand1, char *operator, char *operand2, char *result) {
    if (*operator == '?') {
        operators(operand1, "+", operand2, result);
        operators(operand1, "-", operand2, result);             
        operators(operand1, "*", operand2, result);
        operators(operand1, "/", operand2, result);
        return;
    }
    int size_operand1,  size_operand2, size_result;
    bool is_question1 = false, is_question2 = false, is_question_result = false;
    bool is_number1 = false, is_number2 = false, is_number_result = false;
    bool change_operand1 = false, change_operand2 = false, change_result = false;
    bool digit_operand1 = false, digit_operand2 = false, digit_result = false;
    size_operand1 = mx_strlen(operand1);
    size_operand2 = mx_strlen(operand2);
    size_result = mx_strlen(result);

    for(int i = 0; i < size_operand1; i++) {
        if(operand1[i] == '?') {
            is_question1 = true;
        }
        if(mx_isdigit(operand1[i])) {
            is_number1 = true;
        }
        if(is_question1 && is_number1) {
            break;
        }
    }
    for(int i = 0; i < size_operand2; i++) {
        if(operand2[i] == '?') {
            is_question2 = true;
        }
        if(mx_isdigit(operand2[i])) {
            is_number2 = true;
        }
        if(is_question2 && is_number2) {
            break;
        }
    }
    for(int i = 0; i < size_result; i++) {
        if(result[i] == '?') {
            is_question_result = true;
        }
        if(mx_isdigit(result[i])) {
            is_number_result = true;
        }
        if(is_question_result && is_number_result) {
            break;
        }
    }
        if (operand1[0] == '-') {
        digit_operand1= true;
        operand1++;
        size_operand1--;
    } 

    if (operand2[0] == '-') {
        digit_operand2 = true;
        operand2++;
        size_operand2--;
    }

    if (result[0] == '-') {
        digit_result = true;
        result++;
        size_result--;
    }
    int op1_intmiss = mx_atoi(operand1, 0);
    int op2_intmiss = mx_atoi(operand2, 0);
    int res_intmiss = mx_atoi(result, 0);
    int int_op1 = mx_atoi(operand1, 1) * mx_pow(10, mx_strlen(operand1) - mx_length_int(mx_atoi(operand1, 1)));
    int int_op2 = mx_atoi(operand2, 1) * mx_pow(10, mx_strlen(operand2) - mx_length_int(mx_atoi(operand2, 1)));
    int int_res = mx_atoi(result, 1) * mx_pow(10, mx_strlen(result) - mx_length_int(mx_atoi(result, 1)));
    if((is_question1 && is_number1) || (is_number2 && is_question2) || (is_question_result && is_number_result) || digit_operand1 || digit_operand2 || digit_result) {
        
        for(long long i = int_op1; i < mx_pow(10, size_operand1); i++) {
            char *temp_i = mx_itoa(i);
            change_operand1 = false;
            for (int i = 0; i < size_operand1 - mx_strlen(temp_i); i++) {
                    if (mx_isdigit(operand1[i]) && operand1[i] != '0') {
                    change_operand1 = true;
                    break;
                }
            }
            if(!change_operand1) {
                for(int i = size_operand1 - mx_strlen(temp_i), j = 0; i < size_operand1; i++) {
                    if(temp_i[j] != operand1[i] && operand1[i] != '?') {
                        change_operand1 = true;
                        break;
                    }
                    j++;
                }
            }
            
            free(temp_i);
            temp_i = NULL;

            if (change_operand1) {
                continue;
            }

            for(long long j = int_op2; j < mx_pow(10, size_operand2); j++) {
                char *temp_j = mx_itoa(j);
                change_operand2 = false;
                for (int i = 0; i < size_operand2 - mx_strlen(temp_j); i++) {
                    if (mx_isdigit(operand2[i]) && operand2[i] != '0') {
                        change_operand2 = true;
                        break;
                    }
                }
                if(!change_operand2) {
                    for(int i = size_operand2 - mx_strlen(temp_j), j = 0; i < size_operand2; i++) {
                        if(temp_j[j] != operand2[i] && operand2[i] != '?') {
                            change_operand2 = true;
                            break;
                        }
                        j++;
                    }
                }
                
                free(temp_j);
                temp_j = NULL;

                if (change_operand2) {
                    continue;
                }
                for(long long count = int_res; count < mx_pow(10, size_result); count++) {  
                    char *temp_count = mx_itoa(count);
                    change_result = false;
                    for (int i = 0; i < size_result - mx_strlen(temp_count); i++) {
                        if (mx_isdigit(result[i]) && result[i] != '0') {
                            change_result = true;
                            break;
                        }
                    } 
                    if(!change_result) {
                        for(int i = size_result - mx_strlen(temp_count), j = 0; i < size_result; i++) {
                            if(temp_count[j] != result[i] && result[i] != '?') {
                                change_result = true;
                                break;
                            }
                            j++;
                        }
                    }
                    
                    free(temp_count);
                    temp_count = NULL;

                    if (change_result) {
                        continue;
                    }
                    if (digit_operand1) {
                       i *= -1;
                    }
                    if (digit_operand2) {
                       j *= -1;
                    }
                    if (digit_result) {
                       count *= -1;
                    }

                    if(mx_strncmp("+", operator, 1) == 0) {
                        if(i + j == count) {
                            mx_printint(i);
                            mx_printchar(' ');
                            mx_printstr(operator);
                            mx_printchar(' ');
                            mx_printint(j);
                            mx_printstr(" = ");
                            mx_printint(count);
                            mx_printchar('\n');
                        }
                    }
                    if(mx_strncmp("-", operator, 1) == 0) {
                        if(i - j == count){
                            mx_printint(i);
                            mx_printchar(' ');
                            mx_printstr(operator);
                            mx_printchar(' ');
                            mx_printint(j);
                            mx_printstr(" = ");
                            mx_printint(count);
                            mx_printchar('\n');
                        }
                    }
                    if(mx_strncmp("*", operator, 1) == 0) {
                        if(i * j == count) {
                            mx_printint(i);
                            mx_printchar(' ');
                            mx_printstr(operator);
                            mx_printchar(' ');
                            mx_printint(j);
                            mx_printstr(" = ");
                            mx_printint(count);
                            mx_printchar('\n');
                        }
                    }
                    if(mx_strncmp("/", operator, 1) == 0) {
                            if(j != 0 && i / j == count){
                                mx_printint(i);
                                mx_printchar(' ');
                                mx_printstr(operator);
                                mx_printchar(' ');
                                mx_printint(j);
                                mx_printstr(" = ");
                                mx_printint(count);
                                mx_printchar('\n');
                            }
                    }
                    if (digit_operand1) {
                       i *= -1;
                    }
                    if (digit_operand2) {
                       j *= -1;
                    }
                    if (digit_result) {
                       count *= -1;
                    }
                    if(res_intmiss > 0) {
                        break;
                    }
                }
                if(op2_intmiss > 0) {
                    break;
                }
            }
            if(op1_intmiss > 0) {
                break;
            }
        }
        if (digit_operand1)
            operand1--;
        if (digit_operand2)
            operand2--;
        if (digit_result)
            result--;

    }
    else {
        if(is_number1 && !is_number_result && is_number2){
            for(int i = 0; i < mx_pow(10, size_result); i++){
                if(mx_strncmp("+", operator, 1) == 0) {
                    if(i == mx_atoi(operand1, 0) + mx_atoi(operand2, 0)){
                        mx_printstr(operand1);
                        mx_printchar(' ');
                        mx_printstr(operator);
                        mx_printchar(' ');
                        mx_printstr(operand2);
                        mx_printstr(" = ");
                        mx_printint(i);
                        mx_printchar('\n');
                    }
                }
                if(mx_strncmp("-", operator, 1) == 0) {
                    if(i == (mx_atoi(operand1, 0) - mx_atoi(operand2, 0))){
                        mx_printstr(operand1);
                        mx_printchar(' ');
                        mx_printstr(operator);
                        mx_printchar(' ');
                        mx_printstr(operand2);
                        mx_printstr(" = ");
                        mx_printint(i);
                        mx_printchar('\n');
                    }
                }
                if(mx_strncmp("*", operator, 1) == 0) {
                    if(i == (mx_atoi(operand1, 0) * mx_atoi(operand2, 0))){
                        mx_printstr(operand1);
                        mx_printchar(' ');
                        mx_printstr(operator);
                        mx_printchar(' ');
                        mx_printstr(operand2);
                        mx_printstr(" = ");
                        mx_printint(i);
                        mx_printchar('\n');
                    }
            }
                if(mx_strncmp("/", operator, 1) == 0) {
                    if(mx_atoi(operand2, 0) == 0){
                        continue;
                    }
                    if(mx_atoi(operand1, 0) / mx_atoi(operand2, 0) == i){
                        mx_printstr(operand1);
                        mx_printchar(' ');
                        mx_printstr(operator);
                        mx_printchar(' ');
                        mx_printstr(operand2);
                        mx_printstr(" = ");
                        mx_printint(i);
                        mx_printchar('\n');
                    }
                }
        }   
    }   
        if(!is_number1 && is_number_result && is_number2) {
            for(int i = 0; i < mx_pow(10, size_operand1); i++){
                if(mx_strncmp("+", operator, 1) == 0) {
                    if(i == mx_atoi(result, 0) - mx_atoi(operand2, 0)){
                        mx_printint(i);
                        mx_printchar(' ');
                        mx_printstr(operator);
                        mx_printchar(' ');
                        mx_printstr(operand2);
                        mx_printstr(" = ");
                        mx_printstr(result);
                        mx_printchar('\n');
                    }
                }
                if(mx_strncmp("-", operator, 1) == 0) {
                    if(i == (mx_atoi(result, 0) + mx_atoi(operand2, 0))){
                        mx_printint(i);
                        mx_printchar(' ');
                        mx_printstr(operator);
                        mx_printchar(' ');
                        mx_printstr(operand2);
                        mx_printstr(" = ");
                        mx_printstr(result);
                        mx_printchar('\n');
                    }   
                }
                if(mx_strncmp("*", operator, 1) == 0) {
                    if(i * mx_atoi(operand2, 0) == mx_atoi(result, 0)) {
                        mx_printint(i);
                        mx_printchar(' ');
                        mx_printstr(operator);
                        mx_printchar(' ');
                        mx_printstr(operand2);
                        mx_printstr(" = ");
                        mx_printstr(result);
                        mx_printchar('\n');
                    }
                }   
                if(mx_strncmp("/", operator, 1) == 0) {
                    if(mx_atoi(operand2, 0) == 0){
                        continue;
                    }
                    if(i / mx_atoi(operand2, 0) == mx_atoi(result, 0)){
                        mx_printint(i);
                        mx_printchar(' ');
                        mx_printstr(operator);
                        mx_printchar(' ');
                        mx_printstr(operand2);
                        mx_printstr(" = ");
                        mx_printstr(result);
                        mx_printchar('\n');
                    }
                }
            }   
        }   
        if(is_number1 && is_number_result && !is_number2) {
            for(int i = 0; i < mx_pow(10, size_operand2); i++){
                if(mx_strncmp("+", operator, 1) == 0) {
                    if(i == mx_atoi(result, 0) - mx_atoi(operand1, 0)){
                        mx_printstr(operand1);
                        mx_printchar(' ');
                        mx_printstr(operator);
                        mx_printchar(' ');
                        mx_printint(i);
                        mx_printstr(" = ");
                        mx_printstr(result);
                        mx_printchar('\n');
                    }
                }
                if(mx_strncmp("-", operator, 1) == 0) {
                    if(i == (mx_atoi(operand1, 0) - mx_atoi(result, 0))){
                        mx_printstr(operand1);
                        mx_printchar(' ');
                        mx_printstr(operator);
                        mx_printchar(' ');
                        mx_printint(i);
                        mx_printstr(" = ");
                        mx_printstr(result);
                        mx_printchar('\n');
                    }
                }
                if(mx_strncmp("*", operator, 1) == 0) {
                    if(mx_atoi(operand1, 0) * i == mx_atoi(result, 0)){
                        mx_printstr(operand1);
                        mx_printchar(' ');
                        mx_printstr(operator);
                        mx_printchar(' ');
                        mx_printint(i);
                        mx_printstr(" = ");
                        mx_printstr(result);
                        mx_printchar('\n');
                    }
                }
                if(mx_strncmp("/", operator, 1) == 0) {
                    if(i == 0){
                            continue;
                    }
                    if(mx_atoi(operand1, 0) / i == mx_atoi(result, 0)){
                        mx_printstr(operand1);
                        mx_printchar(' ');
                        mx_printstr(operator);
                        mx_printchar(' ');
                        mx_printint(i);
                        mx_printstr(" = ");
                        mx_printstr(result);
                        mx_printchar('\n');
                    }
                }
            }
        }
        if(!is_number1 && is_number_result && !is_number2) {
            for(int i = 0; i < mx_pow(10, size_operand1); i++){
                for(int j = 0; j < mx_pow(10, size_operand2); j++){
                    if(mx_strncmp("+", operator, 1) == 0) {
                        if(i + j == mx_atoi(result, 0)) {
                            mx_printint(i);
                            mx_printchar(' ');
                            mx_printstr(operator);
                            mx_printchar(' ');
                            mx_printint(j);
                            mx_printstr(" = ");
                            mx_printstr(result);
                            mx_printchar('\n');
                        }
                    }
                    if(mx_strncmp("-", operator, 1) == 0) {
                        if((i - j) == mx_atoi(result, 0)){
                            mx_printint(i);
                            mx_printchar(' ');
                            mx_printstr(operator);
                            mx_printchar(' ');
                            mx_printint(j);
                            mx_printstr(" = ");
                            mx_printstr(result);
                            mx_printchar('\n');
                        }
                    }
                    if(mx_strncmp("*", operator, 1) == 0) {
                        if((i * j) == mx_atoi(result, 0)){
                            mx_printint(i);
                            mx_printchar(' ');
                            mx_printstr(operator);
                            mx_printchar(' ');
                            mx_printint(j);
                            mx_printstr(" = ");
                            mx_printstr(result);
                            mx_printchar('\n');
                        }
                    }
                    if(mx_strncmp("/", operator, 1) == 0) {
                        if(j == 0){
                            continue;
                        }
                        if(i / j == mx_atoi(result, 0)){
                            mx_printint(i);
                            mx_printchar(' ');
                            mx_printstr(operator);
                            mx_printchar(' ');
                            mx_printint(j);
                            mx_printstr(" = ");
                            mx_printstr(result);
                            mx_printchar('\n');
                        }
                    }
                }
            }
        }   
        if(!is_number1 && !is_number_result && is_number2) {
               for(int i = 0; i < mx_pow(10, size_operand1); i++){
                for(int j = 0; j < mx_pow(10, size_result); j++){
                    if(mx_strncmp("+", operator, 1) == 0) {
                        if(i + mx_atoi(operand2, 0) == j) {
                            mx_printint(i);
                            mx_printchar(' ');
                            mx_printstr(operator);
                            mx_printchar(' ');
                            mx_printstr(operand2);
                            mx_printstr(" = ");
                            mx_printint(j);
                            mx_printchar('\n');
                        }
                    }
                    if(mx_strncmp("-", operator, 1) == 0) {
                        if(i - mx_atoi(operand2, 0) == j){
                            mx_printint(i);
                            mx_printchar(' ');
                            mx_printstr(operator);
                            mx_printchar(' ');
                            mx_printstr(operand2);
                            mx_printstr(" = ");
                            mx_printint(j);
                            mx_printchar('\n');
                        }
                    }
                    if(mx_strncmp("*", operator, 1) == 0) {
                        if(i * mx_atoi(operand2, 0) == j ) {
                            mx_printint(i);
                            mx_printchar(' ');
                            mx_printstr(operator);
                            mx_printchar(' ');
                            mx_printstr(operand2);
                            mx_printstr(" = ");
                            mx_printint(j);
                            mx_printchar('\n');
                        }
                    }
                    if(mx_strncmp("/", operator, 1) == 0) {
                        if(mx_atoi(operand2, 0) == 0){
                        continue;
                    }
                        if(i / mx_atoi(operand2, 0) == j){
                            mx_printint(i);
                            mx_printchar(' ');
                            mx_printstr(operator);
                            mx_printchar(' ');
                            mx_printstr(operand2);
                            mx_printstr(" = ");
                            mx_printint(j);
                            mx_printchar('\n');
                        }
                    }
                }
            }
        }
        if(is_number1 && !is_number_result && !is_number2) {
            for(int i = 0; i < mx_pow(10, size_operand2); i++){
                for(int j = 0; j < mx_pow(10, size_result); j++){
                    if(mx_strncmp("+", operator, 1) == 0) {
                        if(mx_atoi(operand1, 0) + i == j) {
                            mx_printstr(operand1);
                            mx_printchar(' ');
                            mx_printstr(operator);
                            mx_printchar(' ');
                            mx_printint(i);
                            mx_printstr(" = ");
                            mx_printint(j);
                            mx_printchar('\n');
                        }
                    }
                    if(mx_strncmp("-", operator, 1) == 0) {
                        if(mx_atoi(operand1, 0) - i == j){
                            mx_printstr(operand1);
                            mx_printchar(' ');
                            mx_printstr(operator);
                            mx_printchar(' ');
                            mx_printint(i);
                            mx_printstr(" = ");
                            mx_printint(j);
                            mx_printchar('\n');
                        }
                    }
                    if(mx_strncmp("*", operator, 1) == 0) {
                        if(mx_atoi(operand1, 0) * i == j ) {
                            mx_printstr(operand1);
                            mx_printchar(' ');
                            mx_printstr(operator);
                            mx_printchar(' ');
                            mx_printint(i);
                            mx_printstr(" = ");
                            mx_printint(j);
                            mx_printchar('\n');
                        }
                    }
                    if(mx_strncmp("/", operator, 1) == 0) {
                        if(i == 0){
                            continue;
                        }
                        if(mx_atoi(operand1, 0) / i == j){
                            mx_printstr(operand1);
                            mx_printchar(' ');
                            mx_printstr(operator);
                            mx_printchar(' ');
                            mx_printint(i);
                            mx_printstr(" = ");
                            mx_printint(j);
                            mx_printchar('\n');
                        }
                    }
                }
            }
        }
        if(!is_number1 && !is_number_result && !is_number2) { 
            for(int i = 0; i < mx_pow(10, size_operand1); i++){
                for(int j = 0; j < mx_pow(10, size_operand2); j++){
                    for(int count = 0 ; count < mx_pow(10, size_operand2); count++){
                        if(mx_strncmp("+", operator, 1) == 0) {
                            if(i + j == count) {
                                mx_printint(i);
                                mx_printchar(' ');
                                mx_printstr(operator);
                                mx_printchar(' ');
                                mx_printint(j);
                                mx_printstr(" = ");
                                mx_printint(count);
                                mx_printchar('\n');
                            }
                        }
                        if(mx_strncmp("-", operator, 1) == 0) {
                            if(i - j == count){
                                mx_printint(i);
                                mx_printchar(' ');
                                mx_printstr(operator);
                                mx_printchar(' ');
                                mx_printint(j);
                                mx_printstr(" = ");
                                mx_printint(count);
                                mx_printchar('\n');
                            }
                        }
                        if(mx_strncmp("*", operator, 1) == 0) {
                            if(i * j == count) {
                                mx_printint(i);
                                mx_printchar(' ');
                                mx_printstr(operator);
                                mx_printchar(' ');
                                mx_printint(j);
                                mx_printstr(" = ");
                                mx_printint(count);
                                mx_printchar('\n');
                            }
                        }
                        if(mx_strncmp("/", operator, 1) == 0) {
                            if(j == 0){
                                continue;
                            }
                            if(i / j == count){
                                mx_printint(i);
                                mx_printchar(' ');
                                mx_printstr(operator);
                                mx_printchar(' ');
                                mx_printint(j);
                                mx_printstr(" = ");
                                mx_printint(count);
                                mx_printchar('\n');
                            }
                        }
                    }

                }
            }
        }
        if(is_number1 && is_number_result && is_number2) { 
            if(mx_strncmp("+", operator, 1) == 0) {
                if(mx_atoi(operand1, 0) + mx_atoi(operand2, 0) == mx_atoi(result, 0)) {
                    mx_printstr(operand1);
                    mx_printchar(' ');
                    mx_printstr(operator);
                    mx_printchar(' ');
                    mx_printstr(operand2);
                    mx_printstr(" = ");
                    mx_printstr(result);
                    mx_printchar('\n');
                }
            }
            if(mx_strncmp("-", operator, 1) == 0) {
                if(mx_atoi(operand1, 0) - mx_atoi(operand2, 0) == mx_atoi(result, 0)) {
                    mx_printstr(operand1);
                    mx_printchar(' ');
                    mx_printstr(operator);
                    mx_printchar(' ');
                    mx_printstr(operand2);
                    mx_printstr(" = ");
                    mx_printstr(result);
                    mx_printchar('\n');
                }
            }
            if(mx_strncmp("*", operator, 1) == 0) {
                if(mx_atoi(operand1, 0) * mx_atoi(operand2, 0) == mx_atoi(result, 0)) {
                    mx_printstr(operand1);
                    mx_printchar(' ');
                    mx_printstr(operator);
                    mx_printchar(' ');
                    mx_printstr(operand2);
                    mx_printstr(" = ");
                    mx_printstr(result);
                    mx_printchar('\n');
                }
            }
            if(mx_strncmp("/", operator, 1) == 0 && mx_atoi(operand2, 0))  {
                if(mx_atoi(operand1, 0) / mx_atoi(operand2, 0) == mx_atoi(result, 0)) {
                    mx_printstr(operand1);
                    mx_printchar(' ');
                    mx_printstr(operator);
                    mx_printchar(' ');
                    mx_printstr(operand2);
                    mx_printstr(" = ");
                    mx_printstr(result);
                    mx_printchar('\n');
                }
            }
        } 
    }
}
