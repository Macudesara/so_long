/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sara <mde-sara@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:51:47 by mde-sara          #+#    #+#             */
/*   Updated: 2024/03/13 15:18:35 by mde-sara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_extension(char *arg)
{
	int	i;

	i = ft_strlen(arg);
	if (arg[i - 4] != '.' || arg[i - 3] != 'b'
		|| arg[i - 2] != 'e' || arg[i - 1] != 'r')
		return (1);
	return (0);
}

int	ft_error(t_data *data, char *message)
{
	int	i;

	i = 0;
	if (!data->map)
		exit (1);
	if (data->map)
	{
		while (data->map[i])
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
	ft_printf("Error\n%s", message);
	exit (1);
}

void	ft_check_errors(t_data *data)
{
	if (data->row == data->col)
		ft_error(data, "the map is not a rectangle\n");
	if (data->row > 26 || data->col > 56)
		ft_error(data, "map too big\n");
	if (ft_check_epc01(data) == 1)
		ft_error(data, "letters do not match\n");
	if (ft_check_wall_top_bottom(data) == 1
		|| ft_check_wall_first_last(data) == 1)
		ft_error(data, "error on map walls\n");
	if (ft_get_p_position(data) == 1)
		ft_error(data, "error in the position of p\n");
	if (ft_count_coins_c(data) == 0)
		ft_error(data, "no c found\n");
	if (ft_flood_fill(data) == 1)
		ft_error(data, "error filling the map\n");
}
