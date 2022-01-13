#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex)
{
    unsigned long result = 0;
    int count = 0;
    for (int i = mx_strlen(hex) - 1; i >= 0; i--)
    {
        unsigned long digit = 0;
        if (hex[i] >= 'A' && hex[i] <= 'F')
            digit = hex[i] - 'A' + 10;
        if (hex[i] >= 'a' && hex[i] <= 'f' )
            digit = hex[i] - 'a' + 10;
        if (hex[i] >= '0' && hex[i] <= '9')
            digit = hex[i] - '0';
        digit = digit << 4 * count;
        result += digit;
        count++;
    }
    return result;
}
