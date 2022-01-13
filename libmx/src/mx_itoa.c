#include "libmx.h"

char *reverse(char *str)
{
    char tmp, *src, *dst;
    size_t len = mx_strlen(str);
    if (str != NULL)
    {
        if (len > 1) 
        {
            src = str;
            dst = src + len - 1;
            while (src < dst) 
            {
                tmp = *src;
                *src++ = *dst;
                *dst-- = tmp;
            }
        }
    }
    return str;
}

void *mx_itoa(int n)
{
    char *s = mx_strnew(11);
    int i = 0;
    int sign = 1;;

    if (n == -2147483648)
    {
        return mx_strcpy(s,"-2147483648");
    }
    if (n == 0)
    {
        return mx_strcpy(s,"0");
    }
    if (n < 0)     
    {
        n = -n;
        sign = -1;
    }

    while(n)   
    {      
        s[i++] = n % 10 + '0';
        n /= 10;      
    } 

    if (sign < 0)
    {
        s[i++] = '-';
    }
    reverse(s);
    s[i] = '\0';
    return s;
}
