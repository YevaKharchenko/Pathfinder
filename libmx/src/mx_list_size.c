#include "libmx.h"

int mx_list_size(t_list *list)
{
    t_list *tmp = list;
    int count = 0;
    while(tmp != NULL)
    {
        tmp = tmp->next;
        count++;
    }
    return count++;
}
