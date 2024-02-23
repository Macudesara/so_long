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
	int		line_posi;
	int		i_posi;
	void	mlx_cont;
	void	mlx_wind;
}				t_data;

void    ft_ini_data(t_data *data);
void    ft_read_map(char **argv, t_data *data);
void    ft_get_size_map(int fd, t_data *data);
void    ft_memory_map(t_data *data, int fd);
int     ft_error(t_data *data, char *message);
void    ft_check_errors(t_data *data);
int 	ft_check_epc01(t_data *data);
int		ft_get_p_position(t_data *data);
int		ft_check_wall_top_bottom(t_data *data);
int		ft_check_wall_first_last(t_data *data);
int		ft_count_coins_c(t_data *data);