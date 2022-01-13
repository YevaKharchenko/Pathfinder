#include "libmx.h"

char *mx_del_extra_spaces(const char *str)
{
     if (!str)
        return NULL;
    
    char *first_string = mx_strtrim(str);
    int first_len = mx_strlen(first_string); 
    char *result_string = mx_strnew(first_len);
    int res_i = 0;
    
    for(int i = 0; i < first_len; i++)
    {
        if (!mx_isspace(first_string[i]))
        {
            result_string[res_i] = first_string[i];
            res_i++;
        }
        if (mx_isspace(first_string[i]))
        {
            if (!mx_isspace(first_string[i - 1]))
            {
                result_string[res_i] = ' ';
                res_i++;
            }
        }
    }
    int result_len = res_i;
    result_string[result_len] = '\0';
    free(first_string);
    
    return result_string;
}
