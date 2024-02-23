/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sara <mde-sara@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:51:47 by mde-sara          #+#    #+#             */
/*   Updated: 2024/02/09 10:51:48 by mde-sara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
//reemplazar printf

int    ft_error(t_data *data, char *message)
{
    int i;

    i = 0;
    // if()
    // {
    //     free();
    // }
    //ft_printf("Error\n%s", message);
    printf("Error\n%s", message);
    return (1);
}

void    ft_check_errors(t_data *data)
{
    if (ft_check_epc01(data) == 1)
        ft_error(data, "letters do not match\n");
    if (ft_check_wall_top_bottom(data) == 1 || ft_check_wall_first_last(data) == 1)
        ft_error(data, "error on map walls\n");
    if (ft_get_p_position(data) == 1)
        ft_error(data, "error in the position of p\n");
    if (ft_count_coins_c(data) == 0)
        ft_error(data, "no c found\n");
    if (ft_flood_fill(data) != 1)
		ft_error(data, "error filling the map\n");
}
