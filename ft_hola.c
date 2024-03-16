/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hola.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:59:29 by mabril            #+#    #+#             */
/*   Updated: 2024/03/13 19:39:27 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putstr(char *str);

int	ft_printf_test(char const *str, ...)
{
	int		i;
	va_list	arg;

	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 's')
			{
				ft_putstr(va_arg(arg, char *));
			}
			i++;
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	return (0);
}

int	main(void)
{
	char	*t;

	t = "hola bb";
	ft_printf_test("Esta es mi funcion %s\n", t);
	printf("Esta es la verdadera funcion %s", t);
	return (0);
}
