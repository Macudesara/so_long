/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsig.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sara <mde-sara@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:29:13 by mde-sara          #+#    #+#             */
/*   Updated: 2023/09/22 09:56:11 by mde-sara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>

void	ft_printf_unsig(unsigned int num, int *count)
{
	char	*base;

	base = "0123456789";
	if (num > 9)
	{
		ft_printf_unsig(num / 10, count);
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
    int    count = 0;
    int num = -17;

    int result = printf("%u", num);
    printf("(%%u) Unsigned decimal integer: %u\n", result);
    ft_printf_unsig(num, &count);
    printf("(%%u) Unsigned decimal integer: %u\n", count);
    return (0);
}*/
