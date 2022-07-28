#include "../inc/list.h"

void mx_pop_index(t_list **list, int index) {
    if (!*list) { 
        return;
    }
    t_list *temp = *list;
    t_list *temp_2 = NULL;
    if (index < 1 || temp -> next == NULL) {
        *list = temp -> next;
        free(temp);
        temp = NULL;
        return;
    }
    for (int i = 0; i < index; i++) {
        if (temp -> next == NULL)
            break;
        temp_2 = temp;
        temp = temp -> next;
    }
    temp_2 -> next = temp -> next;
    free(temp);
    temp = NULL;
    return;
}
