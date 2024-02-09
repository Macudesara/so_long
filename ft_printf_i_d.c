/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sara <mde-sara@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:26:15 by mde-sara          #+#    #+#             */
/*   Updated: 2023/09/28 11:20:30 by mde-sara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>

void	ft_printf_i_d(long long int num, int *count, char *base)
{
	if (num < 0)
	{
		if (write(1, "-", 1) == -1)
		{
			(*count) = -1;
			return ;
		}
		num = -num;
		(*count)++;
	}
	if (num >= 10)
	{
		ft_printf_i_d(num / 10, count, base);
		if ((*count) == -1)
		{
			(*count) = -1;
			return ;
		}
	}
	if (write(1, &base[num % 10], 1) == -1)
	{
		(*count) = -1;
		return ;
	}
	(*count)++;
}

/*int	main(void)
{
    int count = 0;
    long long int    n;

    n = UINT_MAX;
    int result = printf("%li", n);
    printf("(%%i and d) Prints an integer in base 10 (ASCII): %i\n", result);
    ft_printf_i_d(n, &count);
    printf("(%%i and d) Funcion created: %i\n", count);
}*/
