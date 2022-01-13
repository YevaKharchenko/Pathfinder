#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr)
{
    int count = 0, print_char = 0;
    unsigned long tmp = 0;
    char tmp_num[16];
    char *hex_num = NULL;
    
    while (nbr != 0) 
    {
    
        tmp = nbr % 16;
        if (tmp < 10) 
        {
            tmp_num[count] = tmp + 48;
            count++;
           
        }
        else 
        {
            tmp_num[count] = tmp + 87;
            count++;
        }
         nbr = nbr / 16;
    }
    
    hex_num = mx_strnew(count);
    
    for (int i = count - 1;  i >= 0; i--)
    {
        hex_num[print_char] = tmp_num[i];
        print_char++;
    }
        
    return hex_num;
}
