#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) 
{
    int right = 0;
    int left = size - 1;
    int mid = (right + left) / 2;
  
    while (right <= left)
    {
        *count = *count + 1;
        
        if (mx_strcmp(arr[mid], s) == 0)
            return mid;
        
        else if (mx_strcmp(arr[mid], s) < 0)
            right = mid + 1;
            
        else
            left = mid - 1;
        mid = (right + left) / 2;
    }
    *count = 0;
    return -1;
}
