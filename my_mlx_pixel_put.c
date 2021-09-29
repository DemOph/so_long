/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:03:16 by chael-ha          #+#    #+#             */
/*   Updated: 2021/09/29 14:25:55 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	my_mlx_pixel_put(t_texture *text, int x, int y, int color)
{
	char	*dst;

	dst = text->addr + (y * text->line_length + x * (text->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
