#include "list.h"

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *a, void *b)) {
    if (cmp == NULL || list == NULL) {
        return list;
    }
    int count_of_list = 0;
    t_list *current = list;
    while (current) {
        current = current -> next;
        count_of_list++;
    }
    for (int i = 0; i < count_of_list; i++) {
        current = list;
        for (int j = 0; j < count_of_list - 1; j++) {
            if (cmp(current -> temp, current -> next -> temp)) {
                void *temp = current -> temp; 
                current -> temp = current -> next -> temp; 
                current -> next -> temp = temp;     
            }
            current = current -> next;
        }
    }
    return list;
}
