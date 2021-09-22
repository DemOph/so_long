/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:23:52 by chael-ha          #+#    #+#             */
/*   Updated: 2021/09/17 14:23:57 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		n;
	long	nb;
	long	val;

	i = 0;
	n = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		n = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		val = nb;
		nb = ((nb * 10) + (str[i++] - 48) * n);
		if (n == 1 && val > nb)
			return (-1);
		if (n == -1 && val < nb)
			return (0);
	}
	return (nb);
}
