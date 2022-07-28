#include "list.h"

void mx_clear_list(t_list **list) {
    if (*list == NULL || list == NULL) 
        return;
    t_list *current;
    while (*list) {
        current = *list;
        if ((*list)->next) {
            *list = (*list)->next;
            free(current);
        } else {
            free(current);
            *list = NULL;
            return;
        }
    }
}
