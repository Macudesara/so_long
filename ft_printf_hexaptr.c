/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexaptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sara <mde-sara@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:55:26 by mde-sara          #+#    #+#             */
/*   Updated: 2023/09/28 14:49:59 by mde-sara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>

/*void	ft_printf_str(char *str, int *count)
{
	if (!str)
		str = "(null)";
	while (*str)
		if (write(1, str++, 1) == -1)
    {
      *count = -1;
      return ;
    }
		  (*count)++;
}
void	ft_printf_hexalow(unsigned long long int num, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (num >= 16)
	{
		ft_printf_hexalow(num / 16, count);
		if (*count == -1)
		{
			*count = -1;
			return ;
		}
	}
	if (write(1, &base[num % 16], 1) == -1)
	{
		*count == -1;
		return ;
	}
	(*count)++;
}*/

void	ft_printf_hexaptr(void *ptr, int *count)
{
	unsigned long	hexa;

	hexa = (unsigned long)ptr;
	ft_printf_str("0x", count);
	if ((*count) == -1)
	{
		(*count) = -1;
		return ;
	}
	ft_printf_hexalow(hexa, count);
	if ((*count) == -1)
	{
		(*count) = -1;
		return ;
	}
}

/*int	main(void)
{
    int count = 0;
    void *ptr = (void *)0x12345678;

    printf("Usando printf:\n");
    int result = printf("%p", ptr);
    printf("\nCantidad de caracteres impresos por 
		ft_printf_hexaptr: %d\n", result);

    printf("\nUsando ft_printf_hexaptr:\n");
    ft_printf_hexaptr(ptr, &count);
    printf("\nCantidad de caracteres impresos por 
		ft_printf_hexaptr: %d\n", count);

    return (0);
}*/
