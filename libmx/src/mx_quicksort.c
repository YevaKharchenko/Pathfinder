#include "libmx.h"

static int partition(int *arr, int left, int right, int *swaps) 
{
	int tmp;
	int r = right;
	int l = left;
	int pivot = arr[right];

	while (l < r) 
    {
		while (arr[l] < pivot) 
            l++;
		while (arr[r] >= pivot  && r > left) 
            r--;
		if (l < r) 
        {
			tmp = arr[l];
			arr[l] = arr[r];
			arr[r] = tmp;
			(*swaps)++;
		}
	}
	if (arr[right] < arr[l]) 
    {
		tmp = arr[l];
		arr[l] = arr[right];
		arr[right] = tmp;
		(*swaps)++; 
	}
	return r;
}

int mx_quicksort(int *arr, int left, int right) 
{
	int swaps = 0;
	int pivot;
	if (arr == NULL) 
    {
		return -1;
	}
	if (left < right) 
    {
		pivot = partition(arr, left, right, &swaps);
		swaps += mx_quicksort(arr, left, pivot);
		swaps += mx_quicksort(arr, pivot + 1 , right);
	}
	return swaps;
}
