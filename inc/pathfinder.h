#include "libmx.h"

typedef struct  s_data 
{
    int isl_num;
    char **islands;
    int **matrix;
    int **input_dist;
    int pointer;
    int *weights;
}               t_data;

typedef struct  s_line 
{
    char **isl_route;
    char **island;
}               t_line;

t_data *mx_fill_input_data(char *file);
void mx_clean_input_data(t_data *input);
void mx_print_solution(t_data *input);

// errors pack
void mx_check_args(int argc);
void mx_check_valid_file(const char *file);
void mx_check_first_line(char *line);
void mx_check_line(t_line *split, int line_num);
void mx_check_islands_num(int num, int max_num, bool last_isl);
void mx_check_duplicates_bridges(int dist);
void mx_check_sum_of_all_bridges(int *sum_of_bridges, int dist);
