#include "pathfinder.h"

int main(int argc, char **argv) 
{
    mx_check_args(argc);
    t_data *input = mx_fill_input_data(argv[1]); 
    mx_floyd_warshall_algorithm(input);
    mx_print_solution(input);
    mx_clean_input_data(input);
    return 0;
}
