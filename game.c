/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sara <mde-sara@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:57:20 by mde-sara          #+#    #+#             */
/*   Updated: 2024/03/13 16:00:06 by mde-sara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_instructions(void)
{
	ft_printf("\n Project made by mde-sara 🏑\n");
	ft_printf("\n   	  ⚽️ Welcome back to the 2022 world cup final ⚽️ \n");
	ft_printf("\n Today, you'll have the oportunity to play for ");
	ft_printf("Argentina 🤩 national team with Messi\n");
	ft_printf("---------------------------------");
	ft_printf("-----------------------------------------------------------\n");
	ft_printf("				Press W or ↑ to go UP!\n");
	ft_printf("				Press S or ↓ to go DOWN!\n");
	ft_printf("				Press A or ← to go LEFT!\n");
	ft_printf("				Press D or → to go RIGHT!\n");
	ft_printf("---------------------------------");
	ft_printf("-----------------------------------------------------------\n");
	ft_printf("	💙 Collect all the Ballon d'Or and reach the world cup to WIN ");
	ft_printf("the game! 💙\n");
	ft_printf("\n			      Good luck CHAMPION 🏆\n\n");
}

void	ft_endgame(void)
{
	ft_printf("\n	     	    	🏆 YOU EARNED THE 3RD START ⭐️\n");
	ft_printf("			        CONGRATULATIONS\n");
}

void	ft_load_images(t_data *data)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	data->img_fondo = mlx_xpm_file_to_image(data->mlx_cont, "images/fondo.xpm",
			&w, &h);
	data->img_1 = mlx_xpm_file_to_image(data->mlx_cont, "images/pared.xpm",
			&w, &h);
	data->img_p = mlx_xpm_file_to_image(data->mlx_cont, "images/personaje.xpm",
			&w, &h);
	data->img_c = mlx_xpm_file_to_image(data->mlx_cont,
			"images/coleccionable.xpm", &w, &h);
	data->img_e = mlx_xpm_file_to_image(data->mlx_cont, "images/exit.xpm",
			&w, &h);
}

void	ft_make_map(t_data *data)
{
	int	width;
	int	height;

	data->y = 0;
	width = 0;
	height = 0;
	while (data->y < data->row)
	{
		data->x = 0;
		width = 0;
		while (data->x <= data->col)
		{
			ft_put_img_in_map(data, width, height);
			data->x++;
			width += 50;
		}
		data->y++;
		height += 50;
	}
}
