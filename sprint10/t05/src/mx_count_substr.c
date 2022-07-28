#include "../inc/header.h"

int mx_count_substr(const char *str, const char *sub){
    int len1 = mx_strlen(str);
    int len2 = mx_strlen(sub);
    int temp, count = 0, count1 = 0;
    for(int i = 0; i < len1; ){
        temp = 0; count = 0;
        while((str[i] == sub[temp])){
            count++; i++; temp++;
        }
        if(count == len2){
            count1++;
            count = 0;
        }
        else
            i++;
    }
    return count1;
}

