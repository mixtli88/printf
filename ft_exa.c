/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:13:24 by mabril            #+#    #+#             */
/*   Updated: 2024/03/18 23:57:12 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_putlowexa(int num, int count)
{
	long	nb;
	int		i;
	char	*base;

	base = "0123456789abcdef";
	nb = num;
	if (nb > 15)
		ft_putlowexa(nb / 16, count);
	nb = nb % 16;
	write(1, &base[nb], 1);
	count++;
	
	return (count);
}

// int	main(void)
// {
// 	int	t;
// 	int	count;

// 	t = 3456;
// 	count = 0;
// 	ft_putlowexa(t, count);
// 	write(1, "\n", 1);
// 	return (0);
// }