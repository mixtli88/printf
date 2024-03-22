/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:46:21 by mabril            #+#    #+#             */
/*   Updated: 2024/03/21 19:47:18 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int	ft_putstr(char *c, int count);
int	ft_putchar(char c, int count);
int	ft_puthexatit(unsigned long long num, int count);
int	ft_unsigne(unsigned int i, int count);
int	ft_putnrb(int i, int count);
int	ft_puthexaup(unsigned long long num, int count);
int	ft_memo(unsigned long long num, int count);

#endif