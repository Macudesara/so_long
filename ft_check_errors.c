/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sara <mde-sara@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:35:44 by mde-sara          #+#    #+#             */
/*   Updated: 2024/02/12 10:35:47 by mde-sara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int		ft_count_coins_c(t_data *data)
{
    int	i;
	int	lines;

	lines = 1;
	while (lines < data->row)
	{
		i = 0;
		while (i < data->col)
		{
			if (data->map[lines][i] == 'C')
				data->coins++;
			i++;
		}
		lines++;
	}
    return (data->coins);
}

int		ft_get_p_position(t_data *data)
{
    int i;
    int lines;
    int flag;

    i = 0;
    lines = 1;
    while (lines < data->row)
    {
        i = 0;
        while (i < data->col)
        {
            if (data->map[lines][i] == 'P')
            {
                data->pos_y = lines;
                data->pos_x = i;
                flag = 0;
            }
            i++;
        }
        lines++;
    }
    if (flag != 0)
        return (1);
    return (0);
}

int ft_check_wall_first_last(t_data *data)
{
    int y;
    int x;

    y = 0;
    x = data->col - 2;
    while (y < data->row - 1)
    {
        if ((data->map[y][0]) != '1')
            return (1);
        y++;
    }
    y = 0;
    while (y < data->row - 1)
    {
        if (data->map[y][x] != '1')
            return (1);
        y++;
    }
    return (0);
}

int ft_check_wall_top_bottom(t_data *data)
{
    int y;
    int x;

    x = 0;
    y = data->row - 1;
    while (x < data->col - 1)
    {
        if (data->map[0][x] != '1')
            return (1);
        x++;
    }
    x = 0;
    while (x < data->col - 1)
    {
        if (data->map[y][x] != '1')
            return (1);
        x++;
    }
    return (0);
}

int ft_check_epc01(t_data *data)
{
    int e;
    int p;
    int y;
    int x;

    e = 0;
    p = 0;
    y = -1;
    while (++y < data->row)
    {
        x = -1;
        while (++x < (data->col - 1))
        {
            if (!ft_strchr("EPC01", data->map[y][x]))
                return (1);
            else if (data->map[y][x] == 'E')
                e++;
            else if (data->map[y][x] == 'P')
                p++;
        }
    }
    if (e > 1 || p > 1 || e < 1 || p < 1)
        return (1);
    return (0);
}
