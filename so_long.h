/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sara <mde-sara@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:12:37 by mde-sara          #+#    #+#             */
/*   Updated: 2024/02/09 11:12:39 by mde-sara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_data
{
	int		col;
	int		row;
	int		coins;
    char    **map;
}				t_data;

void    ft_ini_data(t_data *data);
void    ft_read_map(char **argv, t_data *data);
void    ft_get_size_map(int fd, t_data *data);
void    ft_memory_map(t_data *data, int fd);
int     ft_error(t_data *data, char *message);