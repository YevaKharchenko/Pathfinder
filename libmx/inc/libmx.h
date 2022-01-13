#pragma once

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include <limits.h>

#if defined(__APPLE__)
#include <malloc/malloc.h>
#define mx_malloc_size(x) malloc_size(x)
#elif defined(_WIN64) || defined(_WIN32)
#include <malloc.h>
#define mx_malloc_size(x) _msize(x)
#elif defined(__linux__)
#include <malloc.h>
#define mx_malloc_size(x) malloc_usable_size(x)
#endif

//Utils pack
int mx_sqrt(int x);
bool mx_isdigit(int c);
bool mx_isalpha(int c);
void *mx_itoa(int n);
int mx_atoi(const char *str);
char *reverse(char *str);
void mx_printint(int n);
void mx_printchar(char c);
void mx_printerr(const char* s);
void mx_printstr(const char *s);
char *mx_nbr_to_hex(unsigned long nbr);
unsigned long mx_hex_to_nbr(const char *hex);
int mx_bubble_sort(int *arr, int size);
int mx_quicksort(int *arr, int left, int right);
double mx_pow(double n, unsigned int pow);
void mx_print_strarr(char **arr, const char *delim);
void mx_foreach(const int *arr, int size, void(*f)(int));
int mx_binary_search(char **arr, int size, const char *s, int *count);

// Strings pack
int mx_strlen(const char* s);
void mx_swap_char(char *s1, char* s2);
char* mx_strcpy(char *dst, const char *src);
char *mx_strchr(const char *s, int c);
int mx_strcmp(const char *s1, const char *s2);
int mx_strncmp(const char *s1, const char *s2, int n);
char* mx_strcat(char* restrict s1, const char* restrict s2);
char* mx_strnew(const int size);
char* mx_strdup(const char *str);
char *mx_strndup(const char *s1, size_t n);
char *mx_strjoin(char const *s1, char const *s2);
void mx_strdel(char **str);
void mx_del_strarr(char ***arr);
char *mx_file_to_str(const char *file);
int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd);
char* mx_strncpy(char *dst, const char *src, int len);
void mx_str_reverse(char *s);
char* mx_strstr(const char *s1, const char *s2);
int mx_count_words(const char *str, char c);
int mx_count_substr(const char* str, const char *sub);
int mx_get_char_index(const char *str, char c);
int mx_get_substr_index(const char *str, const char *sub);
char *mx_strtrim(const char *str);
char *mx_del_extra_spaces(const char *str);
bool mx_isspace(char c);
char **mx_strsplit(char const *s, char c);
void free_array(int **arr, int isl_num);
char *mx_replace_substr(char *str, const char *sub, const char *replace);

// Memory pack
void *mx_memset(void *b, int c, size_t len);
void free_array(int **arr, int isl_num);
void *mx_memcpy(void *restrictdst, const void *restrictsrc, size_t n);
int mx_memcmp(const void *s1, const void *s2, size_t n);
void *mx_memmove(void *dst, const void *src, size_t len);
void *mx_realloc(void *ptr, size_t size);
void *mx_memrchr(const void *s, int c, size_t n);
void *mx_memccpy(void *restrictdst, const void *restrictsrc, int c, size_t n);
void *mx_memchr(const void *s, int c, size_t n);
void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len);

typedef struct s_list
{
    void* data;
    struct s_list* next;
}             t_list;


//List pack
t_list* mx_create_node(void *data);
void mx_push_front(t_list** list, void* data);
void mx_push_back(t_list** list, void* data);
void mx_pop_front(t_list **head);
void mx_pop_back(t_list **list);
void mx_push_index(t_list **list, void *data, int index);
void mx_pop_index(t_list **list, int index);
int mx_list_size(t_list *list);
