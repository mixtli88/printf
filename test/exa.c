/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exa.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:13:24 by mabril            #+#    #+#             */
/*   Updated: 2024/03/15 11:17:30 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_putexa(int num, int count)
{
	long	nb;
	int		i;
	char	*base;

	base = "0123456789abcdef";
	nb = num;
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
		count++;
	}
	if (nb > 9)
		count = count + ft_putexa(nb / 16, count);
	nb = nb % 16 + '0';
	write(1, base[nb - 1], 1);
	count++;
	return (count);
}

int	main(void)
{
	int	t;
	int	count;

	t = 3456;
	count = 0;
	ft_putexa(t, count);
	return (0);
}
