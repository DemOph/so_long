/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:39:38 by chael-ha          #+#    #+#             */
/*   Updated: 2021/09/27 19:28:08 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long nb;

	nb = n;
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			ft_putchar('2');
			ft_putnbr(147483648);
			return ;
		}
		nb = (-1) * nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar(nb % 10 + '0');
}
