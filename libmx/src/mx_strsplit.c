#include "libmx.h"

char **mx_strsplit(char const *s, char c)
{
    if (!s)
        return NULL;
        
    int num_words = mx_count_words(s, c);
    char **arr = malloc((num_words + 1) * sizeof(char*));
    int num_char = 0;
    
    for (int i = 0; i < num_words; i++)
    {
        
        while (*s == c)
            s++;
           
        const char *word_first_char = s;
        num_char = 0;
        
        while (*s != c && *s != '\0')
        {
            s++;
            num_char++;
        }
        
        char *word = malloc(num_char + 1);
        word = mx_strncpy(word, word_first_char, num_char);
        
        word[num_char] = '\0';
        arr[i] = word;
    }
    arr[num_words] = NULL;
    return arr;
}
