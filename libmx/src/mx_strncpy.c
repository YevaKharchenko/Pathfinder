#include "libmx.h"

char *mx_strncpy(char *dst, const char *src, int len)
{
    char* copy_string = dst;
    
    for (int i = 0; i < len; i++)
    {
        *dst = *src;
        dst++;
        src++;
        if (*src == '\0')
        {
            for (i += 1; i < len; i++)
            {
            *dst = '\0';
            dst++;
            }
        }
    }
    return copy_string;
}
