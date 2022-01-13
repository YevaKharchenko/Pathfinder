#include "libmx.h"

char *mx_strtrim(const char *str)
{
    char *new_string = NULL;
    int end = mx_strlen(str) - 1;
    int start = 0;
    
    if(str == NULL)
    {
        return NULL;
    }    
    while (str[start] != '\0' && mx_isspace(str[start]))
    {
        start++;
    }
    while (end >= 0 && mx_isspace(str[end]))
    {
        end--;
    }
    
    if(start > end)
    {
        char *str_space = mx_strnew(1);
        str_space[0] = '\0';
        return str_space;
    }
    new_string = mx_strnew(end - start + 2);
    if(new_string ==  NULL)
    {
        return NULL;
    }
    new_string = mx_strncpy(new_string, str + start, end - start + 1);
    new_string[end - start + 1] = '\0';
    
    return new_string;
}
