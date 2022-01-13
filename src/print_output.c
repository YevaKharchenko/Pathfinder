#include "pathfinder.h"

void mx_print_border(void) 
{
    for (int i = 0; i < 40; i++)
    {
        mx_printchar('=');
    }
    mx_printchar('\n');
}

void mx_print_path(char **islands_array, int *route) 
{
    mx_printstr("Path: ");
    mx_printstr(islands_array[route[1]]);
    mx_printstr(" -> ");
    mx_printstr(islands_array[route[0]]);
    mx_printchar('\n');
}

void mx_print_route(t_data *input) 
{
    mx_printstr("Route: ");
    for (int i = 1; i < input->pointer + 1;) 
    {
        mx_printstr(input->islands[input->weights[i]]);
        i++;
        if (i < input->pointer + 1) { mx_printstr(" -> "); }
    }
    mx_printchar('\n');
}

void mx_print_distance(t_data *input) 
{
    mx_printstr("Distance: ");
    int current_cum = 0, total_sum = 0;
    for (int i = 1; i < input->pointer; i++) 
    {
        current_cum = input->input_dist[input->weights[i]][input->weights[i + 1]];
        mx_printint(current_cum);
        total_sum  += current_cum;
        if (i < input->pointer - 1) 
        {
            mx_printstr(" + ");
        }
        else if (i > 1) 
        {
            mx_printstr(" = ");
            mx_printint(total_sum);
        }
    }
    mx_printchar('\n');
}

void mx_find_shortest_route(t_data *input) 
{
    int y = input->weights[input->pointer];
    int x = input->weights[0];

    for (int k = 0; k < input->isl_num; k++) 
    {
        if (input->weights[input->pointer] == input->weights[0] && k > 0) break;
        else if (k != input->weights[input->pointer] && input->input_dist[y][k] == input->matrix[y][x] - input->matrix[k][x])
        {
            input->pointer++;
            input->weights[input->pointer] = k;
            mx_find_shortest_route(input);
            input->pointer--;
        }
    }
    if (input->weights[input->pointer] != input->weights[0]) return;
    mx_print_border();
    mx_print_path(input->islands, input->weights);
    mx_print_route(input);
    mx_print_distance(input);
    mx_print_border();
}

void mx_print_solution(t_data *input) 
{
    input->weights = (int *) malloc(sizeof(int) * (input->isl_num + 1));

    for (int i = 0; i < input->isl_num; i++) 
    {
        for (int j = i + 1; j < input->isl_num; j++) 
        {
            input->pointer = 1;
            input->weights[0] = j;
            input->weights[1] = i;
            mx_find_shortest_route(input);
        }
    }
    free(input->weights);
}
