#include "libmx.h"

void mx_printint(int n) 
{
	char integer[11];
	int count = 0;
	
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return;
	}
	if (n == 0) 
	{
		mx_printchar('0');
		return;
	}
	if (n < 0) 
	{
		n = -n;
		mx_printchar('-');
	}

	while (n != 0) 
	{				
		integer[count] = n % 10 + '0';
		n = n/10;
		count++;
	}
	
	for (int character = count-1; character >= 0; character--)
	{
		mx_printchar(integer[character]);
	}
}
