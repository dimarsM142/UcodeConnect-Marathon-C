#include "../inc/list.h"

void mx_push_index(t_list **list, void *data, int index){
    if (*list == NULL || list == NULL) {
        *list = mx_create_node(data);
        return;
    }
    if (index < 1) {
        mx_push_front(list, data);
        return;
    }
    int count = 0;
    t_list *temp_count = *list;
    while (temp_count) {
        temp_count = temp_count -> next;
        count++;
    }
    if (index >= count) {
        mx_push_back(list, data);
        return;
    }
    t_list *temp = *list;
    t_list *temp_2 = NULL;
    for (int i = 0; i < index; i++) {
        temp_2 = temp;
        temp = temp -> next;
    }
    temp_2 -> next = mx_create_node(data);
    temp_2 -> next -> next = temp; 
}

