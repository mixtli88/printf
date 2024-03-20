/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:52:43 by mabril            #+#    #+#             */
/*   Updated: 2024/03/19 01:09:11 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_putstr(char *c, int count);
int		ft_putchar(char c, int count);
int		ft_putlowexa(int num, int count);
int		ft_putupeXa(int num, int count);
int		ft_putnrb(int i, int count);

int	ft_printf(char const *str, ...)
{
	int		i;
	int		count;
	va_list	arg;

	i = 0;
	count = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'c')
				count = count + ft_putchar((char)va_arg(arg, int), count);
			if (str[i + 1] == 's')
				count = count + ft_putstr(va_arg(arg, char *), count);
			if (str[i + 1] == 'p')
			{
				count += ft_putstr("0x", count);
				count += ft_putlowexa(va_arg(arg, int), count);
			}
			if (str[i + 1] == 'd' || str[i + 1] == 'i')
				count = count + ft_putnrb(va_arg(arg, int), count);
			// 	if(str[i + 1] == 'u')
			// 	{
			// 	}
			if(str[i + 1] == 'x')
					count = count + ft_putlowexa(va_arg(arg, int), count);
			if(str[i + 1] == 'X')
				count = count + ft_putupeXa(va_arg(arg, int), count);
			if(str[i + 1] == '%')
				count = count + ft_putchar('%', count);
				
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
	char	c; 

	c = 'm';
	s = "hola mi kio";
	s1 = "hola mi maicol";
	ft_printf("como el prototype %s et %s %d %x %X %c %% %p \n", s, s1, 3456, 3456, 6558, c, "k");
	printf("como el real function %s okok %d %x %X %c %% %p\n", s, 3456, 3456, 6558, c, "9");
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