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

int    ft_error(t_data *data, char *message)
{
    int i;

    i = 0;
    // if()
    // {
    //     free();
    // }
    ft_printf("Error\n%s", message);
    exit(1);
}
