#include "libmx.h"

char* mx_replace_substr(char *str, const char *sub, const char *replace)
{
    if (!str || !sub || !replace)
    {
        return NULL;
    }
    int sub_len = mx_strlen(sub);
    int replace_len = mx_strlen(replace);
    int count = mx_count_substr(str, sub);

        if (count > 0) 
        {
            char *result_string = mx_strnew(mx_strlen(str) + (replace_len - sub_len) * count);
            int i = 0;
            while(*str)
            {
                if (*str == *sub && mx_strncmp(str, sub, sub_len) == 0) 
                {
                    mx_strncpy(result_string + i, replace, replace_len);
                    str += sub_len;
                    i += replace_len;
                }
                else
                    result_string[i++] = *str++;
            return result_string;
            }
        }
    return str;
}
