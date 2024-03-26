/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:52:43 by mabril            #+#    #+#             */
/*   Updated: 2024/03/26 08:51:02 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	funtions(char c, va_list arg, int count)
{
	if (c == 'c')
		count = ft_putchar((char)va_arg(arg, int), count);
	if (c == 's')
		count = ft_putstr(va_arg(arg, char *), count);
	if (c == 'd' || c == 'i')
		count = ft_putnrb(va_arg(arg, int), count);
	if (c == 'u')
		count = ft_unsigne(va_arg(arg, unsigned int), count);
	if (c == 'x')
		count = ft_puthexatit(va_arg(arg, unsigned int), count);
	if (c == 'X')
		count = ft_puthexaup(va_arg(arg, unsigned int), count);
	if (c == '%')
		count = ft_putchar('%', count);
	if (c == 'p')
	{
		count = ft_putstr("0x", count);
		count = ft_memo(va_arg(arg, unsigned long ), count);
	}
	return (count);
}

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
			count = funtions(str[i + 1], arg, count);
			i++;
		}
		else
		{
			count = ft_putchar(str[i], count);
		}
		i++;
	}
	va_end(arg);
	return (count);
}

// int	main(void)
// {
// 	int		yo;
// 	int		ya;
// 	char	*str;

// 	ya = 0;
// 	yo = 0;
// 	str = NULL;
// 	ya = printf("x = %x\n", -7897895);
// 	printf("Le nb de caracteres ecris est %d\n", ya);
// 	yo = ft_printf("x = %x\n", -7897895);
// 	printf("Le nb de caracteres ecris est %d\n", yo);
// 	printf("\n\n");
// 	ya = printf("X = %X\n", -7897895);
// 	printf("Le nb de caracteres ecris est %d\n", ya);
// 	yo = ft_printf("X = %X\n", -7897895);
// 	printf("Le nb de caracteres ecris est %d\n", yo);
// 	printf("\n\n");
// 	ya = printf("P =%p\n", &str);
// 	printf("Le nb de caracteres ecris est %d\n", ya);
// 	yo = ft_printf("P =%p\n", &str);
// 	printf("Le nb de caracteres ecris est %d\n", yo);
// 	printf("\n\n");
// 	ya = printf("C =%c\n", 'c');
// 	printf("Le nb de caracteres ecris est %d\n", ya);
// 	yo = ft_printf("C =%c\n", 'c');
// 	printf("Le nb de caracteres ecris est %d\n", yo);
// 	printf("\n\n");
// 	ya = printf("S=%s\n", str);
// 	printf("Le nb de caracteres ecris est %d\n", ya);
// 	yo = ft_printf("S=%s\n", str);
// 	printf("Le nb de caracteres ecris est %d\n", yo);
// 	printf("\n");
// 	ya = printf("I = %i\n", 125);
// 	printf("Le nb de caracteres ecris est %d\n", ya);
// 	yo = ft_printf("I = %i\n", 125);
// 	printf("Le nb de caracteres ecris est %d\n", yo);
// 	printf("\n");
// 	ya = printf("D = %d\n", -123);
// 	printf("Le nb de caracteres ecris est %d\n", ya);
// 	yo = ft_printf("D = %d\n", -123);
// 	printf("Le nb de caracteres ecris est %d\n", yo);
// 	ya = printf("u = %u\n", 2147483647);
// 	printf("Le nb de caracteres ecris est %d\n", ya);
// 	yo = ft_printf("u = %u\n", 2147483647);
// 	printf("Le nb de caracteres ecris est %d\n", yo);
// 	ya = printf("percent = %%\n");
// 	printf("Le nb de caracteres ecris est %d\n", ya);
// 	yo = ft_printf("percent = %%\n");
// 	printf("Le nb de caracteres ecris est %d\n", yo);
// 	return (0);
// }
// int	main(void)
// {
// 	char	*s;
// • %c Imprime un solo carácter.
// • %s Imprime una string (como se define por defecto en C).
// • %p El puntero void * dado como argumento se imprime en formato hexadecimal.
// • %d Imprime un número decimal (base 10).
// • %i Imprime un entero en base 10.
// • %u Imprime un número decimal (base 10) sin signo.
// • %x Imprime un número hexadecimal (base 16) en minúsculas.
// • %X Imprime un número hexadecimal (base 16) en mayúsculas.
// • % % para imprimir el símbolo del porcentaje.