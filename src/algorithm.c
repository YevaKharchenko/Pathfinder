#include "pathfinder.h"

void mx_floyd_warshall_algorithm(t_data *input) 
{
    for (int k = 0; k < input->isl_num; k++) 
    {
        for (int y = 0; y < input->isl_num; y++) 
        {
            for (int x = 0; x < input->isl_num; x++) 
            {
                if (input->matrix[y][k] != INT_MAX && input->matrix[k][x] != INT_MAX && 
                    input->matrix[y][x] > input->matrix[y][k] + input->matrix[k][x]) 
                {
                    input->matrix[y][x] = input->matrix[y][k] + input->matrix[k][x];
                }
            }
        }
    }
}
