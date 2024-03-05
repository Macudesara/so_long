/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sara <mde-sara@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:41:03 by mde-sara          #+#    #+#             */
/*   Updated: 2024/02/09 10:41:07 by mde-sara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_ini_data(t_data *data)
{
    data->col = 0;
    data->row = 0;
    data->x = 0;
    data->y = 0;
    data->map = NULL;
    data->pos_x = 0;
    data->pos_y = 0;
    data->coins = 0;
    data->coins_flood = 0;
    data->flood_fill_check = 0;
}

int main(int argc, char **argv)
{
    t_data  data;
    int i;

    if (argc != 2)
        return (1);
    ft_ini_data(&data);
    i = ft_strlen(argv[1]);
    if (argv[1][i - 4] != '.' || argv[1][i - 3] != 'b' || argv[1][i - 2] != 'e' || argv[1][i - 1] != 'r')
        ft_error(&data, "error in the extension. Must be <.ber>\n");
    ft_read_map(argv, &data);
    ft_check_errors(&data);
    data.mlx_cont = mlx_init();
    if (!data.mlx_cont)
        return (1);
    data.mlx_wind = mlx_new_window(data.mlx_cont, (data.col * 40), data.row * 40, "So_long");
    if (!data.mlx_wind)
    {
        free(data.mlx_cont);
        return (1);
    }
    ft_load_images(&data);
    ft_make_map(&data);
    mlx_loop(data.mlx_cont);
}
