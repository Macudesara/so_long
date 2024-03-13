/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sara <mde-sara@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:11:41 by mde-sara          #+#    #+#             */
/*   Updated: 2024/03/13 15:33:42 by mde-sara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_img_fondo(t_data *data, int w, int h)
{
	mlx_put_image_to_window(data->mlx_cont, data->mlx_wind,
		data->img_fondo, w, h);
}

void	ft_put_img_personaje(t_data *data, int w, int h)
{
	mlx_put_image_to_window(data->mlx_cont, data->mlx_wind,
		data->img_p, w, h);
}

void	ft_put_img_collectable(t_data *data, int w, int h)
{
	mlx_put_image_to_window(data->mlx_cont, data->mlx_wind,
		data->img_c, w, h);
}

void	ft_put_img_exit(t_data *data, int w, int h)
{
	mlx_put_image_to_window(data->mlx_cont, data->mlx_wind,
		data->img_e, w, h);
}

void	ft_put_img_in_map(t_data *data, int w, int h)
{
	if (data->map[data->y][data->x] == '1')
	{
		ft_put_img_fondo(data, w, h);
		mlx_put_image_to_window(data->mlx_cont, data->mlx_wind,
			data->img_1, w, h);
	}
	else if (data->map[data->y][data->x] == 'o')
		ft_put_img_fondo(data, w, h);
	else if (data->map[data->y][data->x] == 'p')
	{
		ft_put_img_fondo(data, w, h);
		ft_put_img_personaje(data, w, h);
	}
	else if (data->map[data->y][data->x] == 'c')
	{
		ft_put_img_fondo(data, w, h);
		ft_put_img_collectable(data, w, h);
	}
	else if (data->map[data->y][data->x] == 'E')
	{
		ft_put_img_fondo(data, w, h);
		ft_put_img_exit(data, w, h);
	}
}
