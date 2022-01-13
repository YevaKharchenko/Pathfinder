#include "libmx.h"

void mx_pop_index(t_list **list, int index)
{
    t_list *node = *list;
    t_list *temp_node = *list;
    
    if (index <= 0)
    {
        mx_pop_front(list);
    }
    else 
    {
        for(int i = 0; i < index; i++)
        {
            temp_node = node;
            if (node->next == NULL)
            {
                mx_pop_back(list);
                return;
            }
            node = node->next;
        }
       temp_node->next = node->next;
       free(node);
    }
}
