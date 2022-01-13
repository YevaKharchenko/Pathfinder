#include "libmx.h"

char *mx_strnew(const int size)
{   
    if(size >= 0)
    {
        char *new_string = (char*)malloc(size + 1);
        for(int i = 0; i <= size; i++)
        {
            new_string[i] = '\0';
        }
        return new_string;
    }
    return NULL;
}
