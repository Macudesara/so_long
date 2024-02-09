/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexaup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sara <mde-sara@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:41:10 by mde-sara          #+#    #+#             */
/*   Updated: 2023/09/22 09:53:21 by mde-sara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>

void	ft_printf_hexaup(long long int num, int *count)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (num >= 16)
	{
		ft_printf_hexaup(num / 16, count);
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
    unsigned long long int num = -5644;
    int count = 0;
    int result;

    result = printf("%lX", num);
    printf("(x) Unsigned hexadecimal integer(uppercase): %lu\n", result);
    ft_printf_hexaup(num, &count);
    printf("(x) Unsigned hexadecimal integer(uppercase): %lu\n", count);
    return (0);
}*/
