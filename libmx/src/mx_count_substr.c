#include "libmx.h"

int mx_count_substr(const char *str, const char *sub)
{
    if (!str || !sub) { return -1; }

    if (mx_strcmp(sub, "") == 0) { return 0; }

    int result = 0;

    if (mx_strlen(str) >= mx_strlen(sub))
    {
        for (bool is_sub; (str = mx_strchr(str, *sub)); str += is_sub ? 1 : mx_strlen(sub))
        {
            if ((is_sub = mx_strncmp(str, sub, mx_strlen(sub))) == 0)
                result++;
        }
        return result;
    }
    return str && sub ? 0 : -1;
}
