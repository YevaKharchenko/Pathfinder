#include "libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2)
{
    int i = mx_strlen(s1);
    int n = 0;
    while (s2[n] != '\0')
    {
        s1[i] = s2[n];
        i++;
        n++;
    }
    s1[i] = '\0';
    return s1;
}
