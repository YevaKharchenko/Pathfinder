#include "libmx.h"

t_list *mx_create_node(void* data)
{
    void* ptr = malloc(sizeof(t_list));
    t_list* node = (t_list*)ptr;
    node->data = data;
    node->next = NULL;
    return node;
}
