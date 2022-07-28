#include "../inc/header.h"

bool compare_name(t_agent* ag1, t_agent* ag2){
    return mx_strcmp(ag1->name, ag2->name) < 0 ? true : false;
}

bool compare_power(t_agent* ag1, t_agent* ag2){
    return ag1->power < ag2->power ? true : false;
}

bool compare_strength(t_agent* ag1, t_agent* ag2){
    return ag1->strength < ag2->strength ? true : false;
}

void sort(t_agent **arr, bool (*compare)(t_agent*, t_agent*), int size){
    bool srswap = true;
    t_agent* tnum = malloc(sizeof(t_agent));
    while(srswap) {
        srswap = false;
        for(int i = 1; i < size; i++){
            if(compare(arr[i], arr[i - 1])){
                tnum = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = tnum;
                srswap = true;
            }
        }
    }
}

int main(int argc, char *argv[]){
    if(argc != 3 || mx_strlen(argv[1]) > 2){
        mx_printerr("usage: ./parse_agents [-p | -s | -n] [file_name]\n");
        exit(0);
    }
    char *somestr = mx_file_to_str(argv[2]);
    int amount = mx_count_substr(somestr, "agent");
    int scount = 0;
    t_agent **tarr = (t_agent**)malloc(amount * sizeof(t_agent*));
    for(int i = 0; i < amount; i++){
        tarr[i] = (t_agent*)malloc(sizeof(t_agent) * amount);
    }
    
    char infstr1[] = "agent {\n\tname: ";
    char infstr2[] = "\tpower: ";
    char infstr3[] = "\tstrength: ";
    char infstr4[] = "}\n";
    char *tmem;
    for(int i = 0; i < amount; i++){
        for(int j = 0; j < mx_strlen(infstr1); j++){
            if(*somestr != infstr1[j]){
                mx_printerr("error\n");
                exit(0);
            }
            somestr++;
        }
        tmem = malloc(50);
        while(*somestr != '\n'){
            tmem[scount] = *somestr;
            somestr++; scount++;
        }
        tarr[i]->name = tmem;
        free(tmem);
        tmem = malloc(50);
        tarr[i]->name[scount] = '\0';
        somestr++;
        for(int j = 0; j < mx_strlen(infstr2); j++){
            if(*somestr != infstr2[j]){
                mx_printerr("error\n");
                exit(0);
            }
            somestr++;
        }

        tarr[i]->power = mx_atoi(somestr);

        int ncount = tarr[i]->power;
        while (ncount > 0) {
            ncount /= 10;
            somestr++;
        }
        somestr++;
        for(int j = 0; j < mx_strlen(infstr3); j++){
            if(*somestr != infstr3[j]){
                mx_printerr("error\n");
                exit(0);
            }
            somestr++;
        }

        tarr[i]->strength = mx_atoi(somestr);

        ncount = tarr[i]->strength;
        while (ncount > 0) {
            ncount /= 10;
            somestr++;
        }
        somestr++;
        for(int j = 0; j < mx_strlen(infstr4); j++){
            if(*somestr != infstr4[j]){
                mx_printerr("error\n");
                exit(0);
            }
            somestr++;
        }
        scount = 0;
    }

    
    switch(argv[1][1]){
        case 'p':
            sort(tarr, compare_power, amount);
            break;
        case 's':
            sort(tarr, compare_strength, amount);
            break;
        case 'n':
            sort(tarr, compare_name, amount);
            break;
        default:
            mx_printerr("usage: ./parse_agents [-p | -s | -n] [file_name]\n");
            exit(0);
    }
    for (int i = 0; i < amount; i++) {
        mx_printstr("agent: ");
        mx_printstr(tarr[i]->name);
        mx_printstr(", strength: ");
        mx_printint(tarr[i]->strength);
        mx_printstr(", power: ");
        mx_printint(tarr[i]->power);
        mx_printchar('\n');
    }

    return 0;
}
