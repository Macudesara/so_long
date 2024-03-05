/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protoprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sara <mde-sara@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:27:42 by mde-sara          #+#    #+#             */
/*   Updated: 2023/09/06 13:15:00 by mde-sara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static void	ft_count(const char *s, va_list args, int *count, int i)
{
	while (s[++i] && *count > -1)
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == 'c')
				ft_printf_char(va_arg(args, int), count);
			else if (s[i] == 's')
				ft_printf_str(va_arg(args, char *), count);
			else if (s[i] == 'p')
				ft_printf_hexaptr(va_arg(args, void *), count);
			else if (s[i] == 'd' || s[i] == 'i')
				ft_printf_i_d(va_arg(args, int), count, "0123456789");
			else if (s[i] == 'u')
				ft_printf_unsig(va_arg(args, unsigned int), count);
			else if (s[i] == 'x')
				ft_printf_hexalow(va_arg(args, unsigned int), count);
			else if (s[i] == 'X')
				ft_printf_hexaup(va_arg(args, unsigned int), count);
			else if (s[i] == '%')
				ft_printf_char('%', count);
		}
		else
			ft_printf_char(s[i], count);
	}
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, s);
	ft_count(s, args, &count, -1);
	if (count == -1)
		return (-1);
	va_end(args);
	return (count);
}
