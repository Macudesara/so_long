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
    //ft_printf("%d\n", data->movements);
    if (data->coins == data->coins_flood)
        ft_endgame();
    return (0);
}

int ft_up(t_data *data)
{
    if (data->map[data->pos_y - 1][data->pos_x] == '1')
        return (1);
    if (data->map[data->pos_y - 1][data->pos_x] == 'c')
        data->collected_coins++;
    else if (data->map[data->pos_y - 1][data->pos_x] == 'E')
    {
        if (data->collected_coins == data->coins)
            ft_esc(data);
        data->map[data->pos_y][data->pos_x] = 'o';
        data->map[--data->pos_y][data->pos_x] = 'e';
        // data->map[data->pos_y][data->pos_x] = 'p';
        // data->map[data->pos_y][++data->pos_x] = 'e';
        return (0);
    }
    else if (data->map[data->pos_y - 1][data->pos_x] == 'e')
        data->map[data->pos_y][data->pos_x] = 'E';
    else if (data->map[data->pos_y - 1][data->pos_x] != 'o')
        return (1);
    if (data->map[data->pos_y][data->pos_x] == 'e')
        data->map[data->pos_y][data->pos_x] = 'E';
    else
        data->map[data->pos_y][data->pos_x] = 'o';
    data->pos_y -= 1;
    data->map[data->pos_y][data->pos_x] = 'p';
    return (0);
}

int ft_down(t_data *data)
{
    if (data->map[data->pos_y + 1][data->pos_x] == '1')
        return (1);
    if (data->map[data->pos_y + 1][data->pos_x] == 'c')
        data->collected_coins++;
    else if (data->map[data->pos_y + 1][data->pos_x] == 'E')
    {
        if (data->collected_coins == data->coins)
            ft_esc(data);
        data->map[data->pos_y][data->pos_x] = 'o';
        data->map[++data->pos_y][data->pos_x] = 'e';
        // data->map[data->pos_y][data->pos_x] = 'p';
        // data->map[data->pos_y][++data->pos_x] = 'e';
        return (0);
    }
    else if (data->map[data->pos_y + 1][data->pos_x] == 'e')
        data->map[data->pos_y][data->pos_x] = 'E';
    else if (data->map[data->pos_y + 1][data->pos_x] != 'o')
        return (1);
    if (data->map[data->pos_y][data->pos_x] == 'e')
        data->map[data->pos_y][data->pos_x] = 'E';
    else
        data->map[data->pos_y][data->pos_x] = 'o';
    data->pos_y += 1;
    data->map[data->pos_y][data->pos_x] = 'p';
    return (0);
}

int ft_right(t_data *data)
{
    if (data->map[data->pos_y][data->pos_x + 1] == '1')
        return (1);
    if (data->map[data->pos_y][data->pos_x + 1] == 'c')
        data->collected_coins++;
    else if (data->map[data->pos_y][data->pos_x + 1] == 'E')
    {
        if (data->collected_coins == data->coins)
            ft_esc(data);
        else
        {
            data->map[data->pos_y][data->pos_x] = 'o';
            data->map[data->pos_y][++data->pos_x] = 'e';
            // data->map[data->pos_y][data->pos_x] = 'p';
            // data->map[data->pos_y][data->pos_x] = 'e';
        }
        //return (0);
    }
    else if (data->map[data->pos_y][data->pos_x + 1] == 'e')
        data->map[data->pos_y][data->pos_x] = 'E';
    else if (data->map[data->pos_y][data->pos_x + 1] != 'o')
        return (1);
    if (data->map[data->pos_y][data->pos_x] == 'e')
        data->map[data->pos_y][data->pos_x] = 'E';
    else
        data->map[data->pos_y][data->pos_x] = 'o';
    data->pos_x += 1;
    data->map[data->pos_y][data->pos_x] = 'p';
    return (0);
}

int ft_left(t_data *data)
{
    if (data->map[data->pos_y][data->pos_x - 1] == '1')
        return (1);
    if (data->map[data->pos_y][data->pos_x - 1] == 'c')
        data->collected_coins++;
    else if (data->map[data->pos_y][data->pos_x - 1] == 'E')
    {
        if (data->collected_coins == data->coins)
            ft_esc(data);
        data->map[data->pos_y][data->pos_x] = 'o';
        data->map[data->pos_y][--data->pos_x] = 'e';
        // data->map[data->pos_y][data->pos_x] = 'p';
        // data->map[data->pos_y][++data->pos_x] = 'e';
        return (0);
    }
    else if (data->map[data->pos_y][data->pos_x - 1] == 'e')
        data->map[data->pos_y][data->pos_x] = 'E';
    else if (data->map[data->pos_y][data->pos_x - 1] != 'o')
        return (1);
    if (data->map[data->pos_y][data->pos_x] == 'e')
        data->map[data->pos_y][data->pos_x] = 'E';
    else
        data->map[data->pos_y][data->pos_x] = 'o';
    data->pos_x -= 1;
    data->map[data->pos_y][data->pos_x] = 'p';
    return (0);
}