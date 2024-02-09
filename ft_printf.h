/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sara <mde-sara@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:31:55 by mde-sara          #+#    #+#             */
/*   Updated: 2023/09/28 14:48:55 by mde-sara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *s, ...);
void	ft_printf_char(char c, int *count);
void	ft_printf_hexalow(unsigned long long int num, int *count);
void	ft_printf_hexaptr(void *ptr, int *count);
void	ft_printf_hexaup(long long int num, int *count);
void	ft_printf_i_d(long long int num, int *count, char *base);
void	ft_printf_str(char *str, int *count);
void	ft_printf_unsig(unsigned int num, int *count);

#endif
