#include "pathfinder.h"

//check number of command line arguments
void mx_check_args(int argc) 
{
    if (argc != 2) 
    {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(0);
    }
}

void mx_check_valid_file(const char *file) 
{
    int fd = open(file, O_RDONLY);
    char *str_file = NULL;
    if (fd == -1)                       //check for file existence
    {
        mx_printerr("error: file ");
        mx_printerr(file);
        mx_printerr(" does not exist\n");
        exit(0);
    }
    
    else if (mx_read_line(&str_file, 1, '\n', fd) == -1) // check if file is empty
    {
        mx_printerr("error: file ");
        mx_printerr(file);
        mx_printerr(" is empty\n");
        exit(0);
    }
    mx_strdel(&str_file);
    close(fd);
}

// print error if line is invalide
void mx_print_line_is_invalid(int line_num) 
{
    mx_printerr("error: line ");
    mx_printerr(mx_itoa(line_num));
    mx_printerr(" is not valid\n");
    exit(0);
}

// check is first line digit
void mx_check_first_line(char *line) 
{
    for (int i = 0; line[i]; i++) 
    {
        if (!mx_isdigit(line[i])) 
        {
            mx_print_line_is_invalid(1);
        }
    }
}
bool mx_valid_route_chars(int c)
{
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == '-')
    {
        return true;
    }
    return false;
}

// // check valide line
void mx_check_line(t_line *split, int line_num) 
{
    for (int n = 0; n < 2; n++)
    {
        if (!split->island[n] || !split->island[n])   //check if isn`t empty strings
        {
            mx_print_line_is_invalid(line_num);
        }
        for (int i = 0; split->island[n][i] != '\0'; i++)// check is name of islands consists of valide letters
        {
            if (!mx_isalpha(split->island[n][i]))
            {
                mx_print_line_is_invalid(line_num);
            }
        }
    }
    for (int i = 0; split->isl_route[0][i] != '\0'; i++)  // check if line have invalid chars
    {
        if (!mx_valid_route_chars(split->isl_route[0][i]))
        {
            mx_print_line_is_invalid(line_num);
        }
        if (split->isl_route[0][i] == '-' && split->isl_route[0][i + 1] == '-') // check if line have more them one '-'
        {
            mx_print_line_is_invalid(line_num); 
        }
    }
    if (!mx_strcmp(split->island[0], split->island[1]))   // check duplicate names
    {
        mx_print_line_is_invalid(line_num);
    } 
    for (int i = 0; split->isl_route[1][i] != '\0'; i++) // check is distance valide (digits)
    {
        if (!mx_isdigit(split->isl_route[1][i]))
        {
            mx_print_line_is_invalid(line_num);
        }
    }
    if (mx_atoi(split->isl_route[1]) <= 0)                // check non-negative distances
    {
        mx_print_line_is_invalid(line_num);
    }
}

// check number of islands
void mx_check_islands_num(int num, int max_num, bool last_isl) 
{
    if (last_isl == false)
    {
        if (num > max_num) 
        {
            mx_printerr("error: invalid number of islands\n");
            exit(0);
        }
    }
    if(last_isl == true)
    {
        if (num < max_num) 
        {
            mx_printerr("error: invalid number of islands\n");
            exit(0);
        }
    }
} 

// check for duplicate bridges
void mx_check_duplicates_bridges(int dist) 
{
    if (dist != INT_MAX) 
    {
        mx_printerr("error: duplicate bridges\n");
        exit(0);
    }
}

//check sum of all bridges
void mx_check_sum_of_all_bridges(int *sum_of_bridges, int dist) 
{
    if (INT_MAX - *sum_of_bridges < dist) 
    {
        mx_printerr("error: sum of bridges lengths is too big\n");
        exit(0);
    }
    *sum_of_bridges += dist;
}
