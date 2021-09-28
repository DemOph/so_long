/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 17:20:40 by chael-ha          #+#    #+#             */
/*   Updated: 2021/09/28 18:06:45 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

size_t	ft_strlenght(char const *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void		ft_putstr(char *s)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (i < ft_strlenght(s))
		ft_putchar(s[i++]);
}
