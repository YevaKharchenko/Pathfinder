#include "pathfinder.h"

//get num of island 
int num_of_island(int fd) 
{
    char *char_num = NULL;
    mx_read_line(&char_num, 10, '\n', fd);
    mx_check_first_line(char_num); // check is first line digit
    int num = mx_atoi(char_num);
    mx_strdel(&char_num);
    return num;
}

//check if island is in array
bool mx_is_island_in_array(char *island, char **islands_array) 
{
    for (int i = 0; islands_array[i] != NULL; i++)
    {
        if (!mx_strcmp(island, islands_array[i]))
        {
            return 0;
        }
    }
    return 1;
}

//get island index
int mx_get_index_of_island(char **islands_array, char *island_name) 
{
    for (int i = 0; islands_array[i] != NULL; i++) 
    {
        if (!mx_strcmp(islands_array[i], island_name))
        {
            return i;
        }
    }
    return -1;
}

int mx_found_dublicates(char **islands_array, char *island_name) 
{
    for (int i = 0; islands_array[i] != NULL; i++) 
    {
        if (mx_strcmp(islands_array[i], island_name) == 0)
        {
            return i;
        }
    }
    return -1;
}
// add island to array
void add_island(t_data *input, char **line, int *count) 
{
    if (mx_is_island_in_array(line[0], input->islands) == 1) // check is primary isl in array
    {
        input->islands[*count] = mx_strdup(line[0]);
        (*count)++;
    }
    if (mx_is_island_in_array(line[1], input->islands) == 1) // check is dest isl in array
    {
        input->islands[*count] = mx_strdup(line[1]);
        (*count)++;
    }
}

void matrix_pre_fill(int isl_num, int **matrix)
{
    for (int y = 0; y < isl_num; y++) 
    {
        for (int x = 0; x < isl_num; x++) 
        {
            if (y == x) { matrix[y][x] = 0; }
            else { matrix[y][x] = INT_MAX; }
        }
    }
}

void matrix_fill(t_data *input, char *distanse, char **islands, int *sum_of_briges) 
{
    int x = mx_get_index_of_island(input->islands, islands[0]);
    int y = mx_get_index_of_island(input->islands, islands[1]);
    int dist = mx_atoi(distanse); 
    int d1 = mx_found_dublicates(input->islands, islands[0]);
    int d2 = mx_found_dublicates(input->islands, islands[1]);
    mx_check_duplicates_bridges(input->matrix[d1][d2]);
    mx_check_sum_of_all_bridges(sum_of_briges, dist);
    input->matrix[x][y] = dist;
    input->matrix[y][x] = dist;
}

void mx_input_dist(t_data *input)
{
    for (int i = 0; i < input->isl_num; i++)
    {
        for (int j = 0; j < input->isl_num; j++)
        {
            input->input_dist[i][j] = input->matrix[i][j];
        }
    }
}

// read data from file and fill structure 
void read_data(t_data *input, int fd, char *file) 
{
    char *line = NULL;
    int count = 0, sum_of_briges = 0;
    char *str_file = mx_file_to_str(file);
    int buf_size = mx_strlen(str_file);
    int total_line_num = mx_count_words(str_file, '\n');    // count total line num
    free(str_file);
    t_line *split = malloc(sizeof(t_line));
    for (int line_num = 2;  line_num <= total_line_num; line_num++) 
    {
        mx_read_line(&line, buf_size, '\n', fd);
        buf_size -= mx_strlen(line);
        split->isl_route = mx_strsplit(line, ',');      //split line (rout and distanse)
        split->island = mx_strsplit(split->isl_route[0], '-'); //split line (islands "primary" and "destination")
        mx_strdel(&line);
        mx_check_line(split, line_num); 
        add_island(input, split->island, &count);
        mx_check_islands_num(count, input->isl_num, false);
        matrix_fill(input, split->isl_route[1], split->island, &sum_of_briges);
        mx_input_dist(input);
        mx_del_strarr(&split->isl_route);
        mx_del_strarr(&split->island);
    }
    mx_check_islands_num(count, input->isl_num, true);
    free(split);
}

t_data *mx_fill_input_data(char *file) 
{
    mx_check_valid_file(file);                   //check for file existence and check if file is empty
    int fd = open(file, O_RDONLY);
    t_data *input = malloc(sizeof(t_data));      //allocate input structure
    input->isl_num = num_of_island(fd);         // get num of islands

    //initialize arrays of given isl_num
    input->input_dist = malloc((sizeof(int*)) * input->isl_num);    // matrux filled with given distances between islands
    input->matrix = malloc((sizeof(int*)) * input->isl_num);        // matrix filled with all distances between islands
    input->islands = malloc((input->isl_num + 1) * sizeof(char*));  // strings array with names of islands

    for (int i = 0; i <= input->isl_num; i++)
    {
        input->islands[i] = NULL;
    }
    for (int i = 0; i < input->isl_num; i++) 
    {
        input->matrix[i] = malloc((sizeof(int)) * input->isl_num);
        input->input_dist[i] = malloc((sizeof(int)) * input->isl_num);        
    }
    matrix_pre_fill(input->isl_num, input->matrix);
    read_data(input, fd, file);
    close(fd);
    return input;
}
