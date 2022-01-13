#include "libmx.h"

int mx_strncmp(const char* s1, const char* s2, int n) 
{
    if(!n)
	{
        return 0;
	}
	while (*s1 && n && ( *s1 == *s2 )) 
    {
		s1++;
		s2++;
		n--;
	}
	return (int)(*s1) - (int)(*s2);
}
