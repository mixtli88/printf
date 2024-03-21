/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:52:43 by mabril            #+#    #+#             */
/*   Updated: 2024/03/21 11:03:47 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	va_list	arg;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'c')
				count = ft_putchar((char)va_arg(arg, int), count);
			if (str[i + 1] == 's')
				count = ft_putstr(va_arg(arg, char *), count);
			if (str[i + 1] == 'd' || str[i + 1] == 'i')
				count = ft_putnrb(va_arg(arg, int), count);
			if (str[i + 1] == 'u')
				count = ft_unsigne(va_arg(arg, unsigned int), count);
			if (str[i + 1] == 'x')
				count = ft_puthexatit(va_arg(arg, long long int), count);
			if (str[i + 1] == 'X')
				count = ft_puthexaup(va_arg(arg, long long int), count);
			if (str[i + 1] == '%')
				count = ft_putchar('%', count);
			if (str[i + 1] == 'p')
			{
				count = ft_putstr("0x", count);
				count = ft_memo((long long int)va_arg(arg, char *), count);
			}
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			count++;
		}
		i++;
	}
	va_end(arg);
	return (count);
}

// int	main(void)
// {
// 	char	*s;
// 	char	*t;

// 	s = " %%";
// 	t = "hole mi maicol";
// 	printf("nbr de caractere : %d", ft_printf("%d", -10));
// 	printf("\n");
// 	printf("nbr de caractere : %d", printf("%d", -10));
// }
// • %c Imprime un solo carácter.
// • %s Imprime una string (como se define por defecto en C).
// • %p El puntero void * dado como argumento se imprime en formato hexadecimal.
// • %d Imprime un número decimal (base 10).
// • %i Imprime un entero en base 10.
// • %u Imprime un número decimal (base 10) sin signo.
// • %x Imprime un número hexadecimal (base 16) en minúsculas.
// • %X Imprime un número hexadecimal (base 16) en mayúsculas.
// • % % para imprimir el símbolo del porcentaje.