#include "../inc/list.h"

int main(int argc, char *argv[]) {
    if (argc < 3 || argc > 5) {
        mx_printerr("usage: ./playlist [file] [command] [args]\n");
        exit(0);
    }

    if (mx_strcmp(argv[2], "add") == 0 && argc == 5) {
        int file = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
        char *current = argv[3];
        if (file < 0) {
            mx_printerr("ERROR\n");
            exit(0);
        }

        while(*current) write(file, current++, 1);
        write(file, " - ", 3);

        current = argv[4];
        while(*current) write(file, current++, 1);
        write(file, "\n", 1);

        if (close(file) < 0) {
            mx_printerr("ERROR\n");
            exit(0);            
        }

    }
    else if (mx_strcmp(argv[2], "print") == 0 && argc == 3) {
        int file = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
        if (file < 0) {
            mx_printerr("ERROR\n");
            exit(0);
        }
        int count_of_max = 0, count = 1;
        char buf;
      
        while (read(file, &buf, 1)) if (buf == '\n') count_of_max++;

        if (close(file) < 0) {
            mx_printerr("ERROR\n");
            exit(0);            
        }
        file = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
        if (file < 0) {
            mx_printerr("ERROR\n");
            exit(0);
        }

        mx_printstr("0. ");        
        while (read(file, &buf, 1)) {
            if (buf == '\n' && count < count_of_max) {
                mx_printchar('\n');
                mx_printint(count++);
                mx_printstr(". ");
                continue;
            }
            write(1, &buf, 1);
        }
        if (close(file) < 0) {
            mx_printerr("ERROR\n");
            exit(0);            
        }
    }
    
    else if (mx_strcmp(argv[2], "remove") == 0 && argc == 4) {
        int file = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
        if (file < 0) {
            mx_printerr("ERROR\n");
            exit(0);
        }
        int ind = mx_atoi(argv[3]);
        int count_of_max = 0, count_of_symbols = 0, count = 0;
        char buf;
      
        while (read(file, &buf, 1)) {
            if (buf == '\n') count_of_max++;
            if (ind == count_of_max) continue;
            count_of_symbols++;
        }
        if (close(file) < 0) {
            mx_printerr("ERROR\n");
            exit(0);            
        }
        if (ind < 0 || ind >= count_of_max) {
            mx_printerr("ERROR\n");
            exit(0);            
        }
        char *arr = (char*)malloc(count_of_symbols);
        file = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
        if (file < 0) {
            mx_printerr("ERROR\n");
            exit(0);
        }
        int i = 0;
        while (read(file, &buf, 1)) {
            if (buf == '\n') count++;
            if (ind == count) continue;
            arr[i++] = buf;
        }
        while (arr[i]) arr[i++] = '\0';
        if (close(file) < 0) {
            mx_printerr("ERROR\n");
            exit(0);            
        }
        if (remove(argv[1]) < 0) {
            mx_printerr("ERROR\n");
            exit(0);                                
        }
        file = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
        if (ind == 0) write(file, arr + 1, mx_strlen(arr + 1));
        else write(file, arr, mx_strlen(arr));
        if (close(file) < 0) {
            mx_printerr("ERROR\n");
            exit(0);            
        }
        free(arr);
        arr = NULL;
    }   
    else if (mx_strcmp(argv[2], "sort") == 0 && argc == 4) {
        if (mx_strcmp(argv[3], "artist") == 0) {
            int file = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
            if (file < 0) {
                mx_printerr("ERROR\n");
                exit(0);
            }
            int count_of_max = 0;
            char buf;
        
            while (read(file, &buf, 1)) if (buf == '\n') count_of_max++;

            if (close(file) < 0) {
                mx_printerr("ERROR\n");
                exit(0);            
            }
            file = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
            if (file < 0) {
                mx_printerr("ERROR\n");
                exit(0);
            }
            int *current = (int*)malloc((count_of_max + 1) * 4);
            for (int i = 0; i < count_of_max; i++) {
                current[i] = 1;
                while (read(file, &buf, 1)) {
                    if (buf == '\n') {  
                        break;
                    }
                    current[i]+=1;
                }
            }
            current[count_of_max] = '\n';
            if (close(file) < 0) {
                mx_printerr("ERROR\n");
                exit(0);            
            }
            char **arr = (char**)malloc(count_of_max * 8);
            for (int i = 0; i < count_of_max; i++) {
                arr[i] = (char*)malloc(current[i]);
            }
            file = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
            if (file < 0) {
                mx_printerr("ERROR\n");
                exit(0);
            }
            int j = 0;
            for (int i = 0; i < count_of_max; i++) {
                while (read(file, &buf, 1)) {
                    if (buf == '\n') break;
                    arr[i][j++] = buf;
                }
                j = 0;
            }
            if (close(file) < 0) {
                mx_printerr("ERROR\n");
                exit(0);            
            }
            t_list *myList = NULL;
            t_list *currentList = myList;
            for (int i = 0; i < count_of_max; i++) {
                mx_push_back(&myList, arr[i]);
            }
            mx_sort_list(myList, cmp);

            if (remove(argv[1]) < 0) {
                mx_printerr("ERROR\n");
                exit(0);                                
            }
            currentList = myList; 
            file = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);

            for (int i = 0; i < count_of_max; i++) {         
                write(file, (char*)(currentList -> data), mx_strlen((char*)(currentList -> data)));
                buf = '\n';
                write(file, &buf, 1);
                currentList = currentList -> next;
            }


            if (close(file) < 0) {
                mx_printerr("ERROR\n");
                exit(0);            
            }

            mx_clear_list(&myList);
            for (int i = 0; i < count_of_max; i++) {
                free(arr[i]);
                arr[i] = NULL;
            }
            free(arr);
            arr = NULL;
            free(current);
            current = NULL;
        }

        else if (mx_strcmp(argv[3], "name") == 0) {
            int file = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
            if (file < 0) {
                mx_printerr("ERROR\n");
                exit(0);
            }
            int count_of_max = 0;
            char buf;
        
            while (read(file, &buf, 1)) if (buf == '\n') count_of_max++;

            if (close(file) < 0) {
                mx_printerr("ERROR\n");
                exit(0);            
            }

            file = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
            if (file < 0) {
                mx_printerr("ERROR\n");
                exit(0);
            }
            int *current = (int*)malloc(count_of_max * 4);
            int *start_ind = (int*)malloc(count_of_max * 4);
            bool isT = true;
            for (int i = 0; i < count_of_max; i++) {
                isT = true;
                current[i] = 1;
                start_ind[i] = 2;
                while (read(file, &buf, 1)) {
                    if (buf == '\n') {
                        break;
                    }
                    current[i]++;
                    if (buf != '-' && isT) start_ind[i]++;
                    if (buf == '-') {
                        isT = false;
                    }
                }
            }
            if (close(file) < 0) {
                mx_printerr("ERROR\n");
                exit(0);            
            }

            char **arr = (char**)malloc(count_of_max * 8);
            for (int i = 0; i < count_of_max; i++) 
                arr[i] = (char*)malloc(current[i]);

            file = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
            if (file < 0) {
                mx_printerr("ERROR\n");
                exit(0);
            }
            int j = 0;
            for (int i = 0; i < count_of_max; i++) {
                while (read(file, &buf, 1)) {
                    if (buf == '\n') break;
                    arr[i][j++] = buf;
                }
                j = 0;
            }
         
            if (close(file) < 0) {
                mx_printerr("ERROR\n");
                exit(0);            
            }
            for (int i = 0; i < count_of_max; i++) {
                for (int j = 0; j < count_of_max - 1; j++) {
                    if (mx_strcmp_2(&arr[j][start_ind[j]], &arr[j + 1][start_ind[j + 1]]) > 0 ) {
                        char *data = arr[j]; 
                        arr[j] = arr[j + 1]; 
                        arr[j + 1] = data;
                        int at = start_ind[j];
                        start_ind[j] = start_ind[j + 1];
                        start_ind[j + 1] = at;
                    }
                }
            }


            if (remove(argv[1]) < 0) {
                mx_printerr("ERROR\n");
                exit(0);                                
            }

            file = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);

            for (int i = 0; i < count_of_max; i++) {         
                write(file, arr[i], mx_strlen(arr[i]));
                buf = '\n';
                write(file, &buf, 1);
            }


            if (close(file) < 0) {
                mx_printerr("ERROR\n");
                exit(0);            
            }
            for (int i = 0; i < count_of_max; i++) {
                free(arr[i]);
                arr[i] = NULL;
            }
            free(arr);
            arr = NULL;
            free(current);
            current = NULL;            
        }
        else {
            mx_printerr("ERROR\n");
            exit(0);            
        }

    }
    else {
        mx_printerr("ERROR\n");
        exit(0);
    }

    return 0;
}
