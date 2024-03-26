/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:52:43 by mabril            #+#    #+#             */
/*   Updated: 2024/03/26 10:54:10 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	recurs(char c, va_list arg)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(arg, int));
	if (c == 's')
		count += ft_putstr(va_arg(arg, char *));
	if (c == 'd' || c == 'i')
		count += ft_putnrb(va_arg(arg, int));
	if (c == 'u')
		count += ft_unsigne(va_arg(arg, unsigned int));
	if (c == 'x')
		count += ft_puthexatit(va_arg(arg, unsigned int));
	if (c == 'X')
		count += ft_puthexaup(va_arg(arg, unsigned int));
	if (c == '%')
		count += ft_putchar('%');
	if (c == 'p')
	{
		count += ft_putstr("0x");
		count += ft_memo(va_arg(arg, unsigned long));
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!str)
		return (-1);
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
			count += recurs(str[++i], arg);
		else
		{
			ft_putchar(str[i]);
			count++;
		}
		++i;
	}
	va_end(arg);
	return (count);
}
