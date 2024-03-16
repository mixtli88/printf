/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:52:43 by mabril            #+#    #+#             */
/*   Updated: 2024/03/15 09:58:37 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

void ft_putstr(char *c);
void ft_putchar(char c);

int ft_printf(char const *str, ...)
{
	int i;
	int resut;
	
	i = 0;
	va_list arg;
	
	va_start(arg, str);
	
	while (str[i])
	{
		if (str[i] == '%' )
		{
			// if (str[i + 1] == 'c')
			// { 
			// 	resut = resut + ft_putchar(arg,str);
			// }
			if(str[i + 1] == 's')
			{
				// resut = resut + 
				ft_putstr(va_arg(arg, char *));
			}
		// 	if(str[i + 1] == 'p')
		// 	{
				
		// 	}
		// 	if(str[i + 1] == 'd')
		// 	{
		// 	}
		// 	if(str[i + 1] == 'i')
		// 	{
		// 	}
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
	va_end (arg);
	return (0);
}

int main(void)
{
	char *s= "hola mi kio";
	char *s1 = "hole mi maicol";
	
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