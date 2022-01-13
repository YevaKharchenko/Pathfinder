#include "pathfinder.h"

void mx_clean_input_data(t_data *input) 
{
    mx_del_strarr(&(input->islands));
    free_array(input->input_dist, input->isl_num);
    free_array(input->matrix, input->isl_num);
    free(input);
}
