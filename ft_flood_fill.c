#include "so_long.h"
#include <stdio.h>

void    ft_fill(t_data *data, int pos_x, int pos_y)
{
    if ((pos_y < 0 || pos_y >= data->row || pos_x < 0 || pos_x >= data->col || 
        data->map[pos_y][pos_x] != '0') && (data->map[pos_y][pos_x] != 'C' && 
        data->map[pos_y][pos_x] != 'P' && data->map[pos_y][pos_x] != 'E'))
        return ;
    if (data->map[pos_y][pos_x] == '0')
        data->map[pos_y][pos_x] = 'o';
    else if (data->map[pos_y][pos_x] == 'P')
        data->map[pos_y][pos_x] = 'p';
    else if (data->map[pos_y][pos_x] == 'C')
    {

        data->map[pos_y][pos_x] = 'c';
        if (data->coins > data->coins_flood)
            data->coins_flood++;
    }
    else if (data->map[pos_y][pos_x] == 'E')
        data->flood_fill_check = 1;
    ft_fill(data, pos_x - 1, pos_y);
	ft_fill(data, pos_x + 1, pos_y);
	ft_fill(data, pos_x, pos_y - 1);
	ft_fill(data, pos_x, pos_y + 1);
}

int    ft_flood_fill(t_data *data)
{
    int begin_x;
    int begin_y;

    begin_x = data->pos_x;
    begin_y = data->pos_y;
    ft_fill(data, begin_x, begin_y);
    if (data->coins != data->coins_flood)
        ft_error(data, "error with the number of coins\n");
    if (data->flood_fill_check != 1)
        ft_error(data, "couldn't find the exit\n");
    return (0);
}