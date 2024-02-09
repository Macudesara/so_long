/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sara <mde-sara@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:09:31 by mde-sara          #+#    #+#             */
/*   Updated: 2023/09/28 11:13:45 by mde-sara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>

void	ft_printf_char(char c, int *count)
{
	if (write(1, &c, 1) == -1)
	{
		*count = -1;
		return ;
	}
	(*count)++;
}

/*int	main(void)
{
	int	resultado;
	int	count = 0;

	resultado = printf("%c", 'f');
	printf("Cantidad de caracteres impresos: %d\n", resultado);

	ft_printf_char('f', &count);
    printf("Cantidad de caracteres impresos: %d\n", count);
	return (0);
}*/
