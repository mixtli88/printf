/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:52:43 by mabril            #+#    #+#             */
/*   Updated: 2024/03/21 20:38:13 by mabril           ###   ########.fr       */
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
				count = ft_puthexatit(va_arg(arg, unsigned long long), count);
			if (str[i + 1] == 'X')
				count = ft_puthexaup(va_arg(arg, unsigned long long), count);
			if (str[i + 1] == '%')
				count = ft_putchar('%', count);
			if (str[i + 1] == 'p')
			{
				count = ft_putstr("0x", count);
				count = ft_memo(va_arg(arg, unsigned long long), count);
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
// 	char	*t;

// 	s = " %%";
// 	t = "hole mi maicol";
// 	// printf("nbr de caractere : %d\n", ft_printf("%p", (void *)-14523));
// 	// printf("\n");
// 	// printf("nbr de caractere : %d\n", printf("%p", (void *)-145253));
// 	printf("%p.vx&^Kp%d&iBx+`%p.f2f<K0Ot%pc\t`-_%xaS7%XY%ioB\v",
//		(void *)8508981653396230473, 689155424, (void *)3273163114108609292,
//	(void *)-8857547745261571269, -1305046457, 1212328054, 755451723);
// 	printf("%p.vx&^Kp%d&iBx]+`%p.f2f<K0Ot%pc\t`-_{%xaS7[%XY%ioB\v[",
//		(void *)8508981653396230473, 689155424, (void *)3273163114108609292,
//		(void *)-8857547745261571269, -1305046457, 1212328054, 755451723);
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