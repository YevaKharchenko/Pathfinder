#include "libmx.h"

void free_array(int **arr, int isl_num) 
{
    for(int i = 0; i < isl_num; i++) 
    {
        free(arr[i]);
        arr[i] = NULL;
    }
    free(arr);
    arr = NULL;
}
