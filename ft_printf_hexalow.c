/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexalow.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sara <mde-sara@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:19:54 by mde-sara          #+#    #+#             */
/*   Updated: 2023/09/22 09:49:56 by mde-sara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>

void	ft_printf_hexalow(unsigned long long int num, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (num >= 16)
	{
		ft_printf_hexalow(num / 16, count);
		if ((*count) == -1)
		{
			(*count) = -1;
			return ;
		}
	}
	if (write(1, &base[num % 16], 1) == -1)
	{
		(*count) = -1;
		return ;
	}
	(*count)++;
}

/*int	main(void)
{
	unsigned long long int num = LONG_MIN;
    int count = 0;
    int result;

    result = printf("%lx", num);
    printf("(x) Unsigned hexadecimal integer(lowercase): %lu\n", result);
    ft_printf_hexalow(num, &count);
    printf("(x) Unsigned hexadecimal integer(lowercase): %lu\n", count);
    return (0);
}*/
