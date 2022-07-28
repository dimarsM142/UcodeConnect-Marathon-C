#include "list.h"

t_list *mx_create_node(void *data) {
    if (!data) 
        return NULL;
    t_list *newNode = (t_list*)malloc(16);
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}
