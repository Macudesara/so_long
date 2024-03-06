/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sara <mde-sara@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:47:36 by mde-sara          #+#    #+#             */
/*   Updated: 2024/02/09 14:47:41 by mde-sara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
//reemplazar printf

void    ft_memory_map(t_data *data, int fd)
{
    int i;

    i = 0;
    data->map = malloc(sizeof(char *) * (data->row + 1));
    if (!data->map)
        ft_error(data, "error creating malloc\n");
    while (data->row - i)
    {
        data->map[i] = get_next_line(fd);
        if (!data->map[i])
            ft_error(data, "error with map content\n");
        i++;
    }
    data->map[i] = NULL;
}

void    ft_get_size_map(int fd, t_data *data)
{
    char    *y;

    y = get_next_line(fd);
	if (!y)
		ft_error(data, "error when reading the map\n");
    data->row = 1;
    while (y[data->col] != '\0' && y[data->col] != '\n')
        data->col++;
    while (y)
    {
        free (y);
        y = get_next_line(fd);
        if (!y)
            return ;
        data->row++;
    }
}

void    ft_read_map(char **argv, t_data *data)
{
    int fd;

    fd = 0;
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        ft_error(data, "error when opening the map\n");
    ft_get_size_map(fd, data);
    close(fd);
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        ft_error(data, "error when opening the map\n");
    ft_memory_map(data, fd);
    close(fd);
}
