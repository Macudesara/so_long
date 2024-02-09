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
    data->map = NULL;
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
    ft_check_errors(&data); // continuar aqui
}
