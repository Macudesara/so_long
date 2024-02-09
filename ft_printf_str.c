/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sara <mde-sara@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:13:30 by mde-sara          #+#    #+#             */
/*   Updated: 2023/09/28 11:21:22 by mde-sara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>

void	ft_printf_str(char *str, int *count)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		if (write(1, str++, 1) == -1)
		{
			(*count) = -1;
			return ;
		}
		(*count)++;
	}
}

/*int main(void)
{
    int count = 0;
    char str [] = "Hello word!\n"

    printf("Usando printf:\n");
    int resultado = printf("%s", str);
    printf("Cantidad de caracteres impresos por printf: %d\n", resultado);

    printf("\nUsando ft_printf_str:\n");
    ft_printf_str(str, &count);
    printf("Cantidad de caracteres impresos por ft_printf_str: %d\n", count);

    return 0;
}*/
