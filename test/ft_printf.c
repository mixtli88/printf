/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:52:43 by mabril            #+#    #+#             */
/*   Updated: 2024/03/15 10:46:17 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putstr(char *c);
int		ft_putchar(char c, int count);

int	ft_printf(char const *str, ...)
{
	int		i;
	va_list	arg;

	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'c')
				count = count + ft_putchar(va_arg(arg, char), count);
			if (str[i + 1] == 's')
				count = count + ft_putstr(va_arg(arg, char *), count);
			if (str[i + 1] == 'p')
			{
			}
			if (str[i + 1] == 'd' || str[i + 1] == 'i')
				count = count + ft_putnum(va_arg(arg, char *), count);
			// 	if(str[i + 1] == 'u')
			// 	{
			// 	}
			// 	if(str[i + 1] == 'x')
			// 	{
			// 	}
			// 	if(str[i + 1] == 'X')
			// 	{
			// 	}
			// 	if(str[i + 1] == '%')
			// 	{
			// 	}
			i++;
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	va_end(arg);
	return (count);
}

int	main(void)
{
	char	*s;
	char	*s1;

	s = "hola mi kio";
	s1 = "hole mi maicol";
	ft_printf("como el prototype %s et %s\n", s, s1);
	printf("como el real function %sokok\n", s);
}
// • %c Imprime un solo carácter.
// • %s Imprime una string (como se define por defecto en C).
// • %p El puntero void * dado como argumento se imprime en formato hexadecimal.
// • %d Imprime un número decimal (base 10).
// • %i Imprime un entero en base 10.
// • %u Imprime un número decimal (base 10) sin signo.
// • %x Imprime un número hexadecimal (base 16) en minúsculas.
// • %X Imprime un número hexadecimal (base 16) en mayúsculas.
// • % % para imprimir el símbolo del porcentaje.