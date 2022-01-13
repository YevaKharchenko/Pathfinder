#include "libmx.h"

// int mx_count_words(const char *str, char c)
// {
//     if (str == NULL)
//     {
//         return -1;
//     }
//     bool check = false;
//     int count = 0;
    
//     while (*str != '\0') 
//     {
//         if(*str != c && !check) 
//         {
//             check = true;
//             count++;
//         }
//         if(*str == c)
//         {
//             check = false;
//         }
//         str++;
//     }
//     return count;
// }
int mx_count_words(const char *str, char c)
{
	int count = 0;
	int i = 0;

	while (str[i]) 
    {
		if (str[i] != c) 
        {
            count++;
        }
		while (str[i] != c && str[i] != '\0') 
        {
            i++;
        }
		if (str[i] == c) 
        {
            i++;
        }
	}
	return count;
}
