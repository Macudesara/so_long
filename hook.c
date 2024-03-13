/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sara <mde-sara@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:54:33 by mde-sara          #+#    #+#             */
/*   Updated: 2024/03/13 16:00:38 by mde-sara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *data)
{
	int	flag;

	flag = 0;
	if (keycode == 53)
	{
		ft_printf("\nYou have pressed the ESC key\n");
		ft_printf("The game is over\n");
		ft_esc(data, 1);
	}
	else if ((keycode == 126 || keycode == 13) && (ft_up(data) == 0))
		data->movements++;
	else if ((keycode == 125 || keycode == 1) && (ft_down(data) == 0))
		data->movements++;
	else if ((keycode == 124 || keycode == 2) && (ft_right(data) == 0))
		data->movements++;
	else if ((keycode == 123 || keycode == 0) && (ft_left(data) == 0))
		data->movements++;
	ft_printf("Number of movements: %d\n", data->movements);
	return (0);
}
