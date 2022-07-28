#include "../inc/list.h"

t_list *mx_create_node(void *data) {
    t_list *node = (t_list*)malloc(16);
    node->next = NULL;
    node->data = data;
    return node;
}
