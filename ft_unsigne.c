/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigne.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:31:43 by mabril            #+#    #+#             */
/*   Updated: 2024/03/21 11:04:34 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigne(unsigned int i, int count)
{
	long	nb;

	nb = i;
	if (nb > 9)
		count = ft_unsigne((nb / 10), count);
	nb = (nb % 10) + '0';
	write(1, &nb, 1);
	count++;
	return (count);
}

// int	main(void)
// {
// 	unsigned int	n;
// 	int				p;

// 	n = 12345;
// 	p = 0;
// 	ft_unsigne(n, p);
// }
