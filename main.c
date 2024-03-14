/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sara <mde-sara@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:41:03 by mde-sara          #+#    #+#             */
/*   Updated: 2024/03/13 14:54:22 by mde-sara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)str + i) = (unsigned char)c;
		i++;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.map = NULL;
	if (argc != 2 || ft_check_extension(argv[1]) == 1)
		ft_error(&data, "error in the extension. Must be <.ber>\n");
	ft_memset(&data, '\0', sizeof(data));
	ft_read_map(argv, &data);
	ft_check_errors(&data);
	data.mlx_cont = mlx_init();
	if (!data.mlx_cont)
		return (1);
	data.mlx_wind = mlx_new_window(data.mlx_cont, (data.col * 50),
			data.row * 50, "18/12/2022");
	if (!data.mlx_wind)
	{
		free(data.mlx_cont);
		return (1);
	}
	ft_load_images(&data);
	ft_make_map(&data);
	ft_instructions();
	mlx_key_hook(data.mlx_wind, key_hook, &data);
	mlx_hook(data.mlx_wind, 17, 0, &ft_esc, &data);
	mlx_loop(data.mlx_cont);
}
