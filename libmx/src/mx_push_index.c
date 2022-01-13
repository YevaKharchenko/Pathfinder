#include "libmx.h"

void mx_push_index(t_list **list, void *data, int index)
{
    t_list *node = *list;
    t_list *new_node_mid = NULL;
    
    if (index <= 0)
    {
        mx_push_front(list, data);
    }
    else 
    {
        for(int i = 0; i < index - 1; i++)
        {
            if (node->next == NULL)
            {
                mx_push_back(list, data);
                return;
            }
            node = node->next;
        }
        new_node_mid = mx_create_node(data);
        new_node_mid->next = node->next;
        node->next = new_node_mid;
    }
}
