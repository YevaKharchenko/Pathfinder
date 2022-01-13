#include "libmx.h"

int mx_bubble_sort(int *arr, int size) 
{
    int temp;
    int count = 0;
    
    for (int f = 0; f < size - 1; f++) 
    {
        for (int s = 0; s < size - f - 1; s++) 
        {
           if (arr[s] > arr[s+1])
           {
               temp = arr[s];
               arr[s] = arr[s + 1];
               arr[s + 1] = temp;
               count++;
           }
        }
    }
    return count;
}
