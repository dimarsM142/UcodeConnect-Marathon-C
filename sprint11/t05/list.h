#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct s_list{
    int *data;
    struct s_list *next;
}   t_list;

t_list *mx_create_node(void *data);
void mx_push_front(t_list **list, void *data);
void mx_push_back(t_list **list, void *data);
void mx_pop_back(t_list **list);
void mx_pop_front(t_list **list);
int mx_list_size(t_list *list);


#endif
