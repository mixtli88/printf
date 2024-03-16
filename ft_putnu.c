/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:31:43 by mabril            #+#    #+#             */
/*   Updated: 2024/03/15 10:25:59 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putnrb(int i, int count)
{
	long	nb;

	nb = i;
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
		count++;
	}
	if (nb > 9)
		count = count + ft_putnrb((nb / 10), count);
	nb = (nb % 10) + '0';
	write(1, &nb, 1);
	count++;
	return (count);
}

int	main(void)
{
	int	n;
	int	p;

	n = 12345;
	p = 0;
	ft_putnrb(n, p);
}
