#include "so_long.h"

int ft_esc(t_data *data)
{
    int i;

    i = 0;

    mlx_destroy_window(data->mlx_cont, data->mlx_wind);
    free(data->mlx_cont);
    while (data->map[i])
    {
        free(data->map[i]);
        i++;
    }
    free(data->map);
    if (data->coins == data->coins_flood)
        ft_endgame();
    return (0);
}

int ft_up(t_data *data)
{
    int flag;
    
    flag = 0;
    if (data->map[data->pos_y][data->pos_x] != 'E')
        data->map[data->pos_y][data->pos_x] = 'o';
    if (data->map[data->pos_y - 1][data->pos_x] == '1')
        return (1);
    data->pos_y -= 1;
    if (data->map[data->pos_y][data->pos_x] == 'c')
        data->collected_coins++;
    else if (data->map[data->pos_y][data->pos_x] == 'E')
    {    
        if (data->collected_coins == data->coins)
            ft_esc(data);
        flag = 1;
    }
    data->map[data->pos_y][data->pos_x] = 'p';
    ft_make_map(data);
    if (flag == 1)
            data->map[data->pos_y][data->pos_x] = 'E';
    return 0;
}

int ft_down(t_data *data)
{
    int flag;
    
    flag = 0;
    if (data->map[data->pos_y][data->pos_x] != 'E')
        data->map[data->pos_y][data->pos_x] = 'o';
    if (data->map[data->pos_y + 1][data->pos_x] == '1')
        return (1);
    data->pos_y += 1;
    if (data->map[data->pos_y][data->pos_x] == 'c')
        data->collected_coins++;
    else if (data->map[data->pos_y][data->pos_x] == 'E')
    {    
        if (data->collected_coins == data->coins)
            ft_esc(data);
        flag = 1;
    }
    data->map[data->pos_y][data->pos_x] = 'p';
    ft_make_map(data);
    if (flag == 1)
            data->map[data->pos_y][data->pos_x] = 'E';
    return 0;
}

int ft_right(t_data *data)
{
    int flag;
    
    flag = 0;
    if (data->map[data->pos_y][data->pos_x] != 'E')
        data->map[data->pos_y][data->pos_x] = 'o';
    if (data->map[data->pos_y][data->pos_x + 1] == '1')
        return (1);
    data->pos_x += 1;
    if (data->map[data->pos_y][data->pos_x] == 'c')
        data->collected_coins++;
    else if (data->map[data->pos_y][data->pos_x] == 'E')
    {    
        if (data->collected_coins == data->coins)
            ft_esc(data);
        flag = 1;
    }
    data->map[data->pos_y][data->pos_x] = 'p';
    ft_make_map(data);
    if (flag == 1)
            data->map[data->pos_y][data->pos_x] = 'E';
    return 0;
}

int ft_left(t_data *data)
{
    int flag;
    
    flag = 0;
    if (data->map[data->pos_y][data->pos_x] != 'E')
        data->map[data->pos_y][data->pos_x] = 'o';
    if (data->map[data->pos_y][data->pos_x - 1] == '1')
        return (1);
    data->pos_x -= 1;
    if (data->map[data->pos_y][data->pos_x] == 'c')
        data->collected_coins++;
    else if (data->map[data->pos_y][data->pos_x] == 'E')
    {    
        if (data->collected_coins == data->coins)
            ft_esc(data);
        flag = 1;
    }
    data->map[data->pos_y][data->pos_x] = 'p';
    ft_make_map(data);
    if (flag == 1)
            data->map[data->pos_y][data->pos_x] = 'E';
    return 0;
}