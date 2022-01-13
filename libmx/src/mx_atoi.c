#include <libmx.h>

int mx_atoi(const char *str) 
{
    int i = 0;
    int sign = 1;
    long result = 0;

    while (mx_isspace(str[i])) 
        i++;
        
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (str[i] == '+') 
        i++;
        
    while (mx_isdigit(str[i])) 
    {
        result = (result * 10) + str[i] -'0';
        i++;
        if (result < 0 && sign == -1) // if (result < 0) {return sign == 1 ? -1 : 0;}
            return 0;
        if (result < 0 && sign == 1)
            return -1;
    }
        
    return result * sign;
}
