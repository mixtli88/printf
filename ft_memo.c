/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:13:24 by mabril            #+#    #+#             */
/*   Updated: 2024/03/20 17:07:53 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_memo(long long int num, int count)
{
	long	nb;
	char	*base;

	base = "0123456789abcdef";
	nb = num;
	if (nb > 15)
		count = count + ft_memo(nb / 16, count);
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
// 	ft_memo(t, count);
// 	return (0);
// }
