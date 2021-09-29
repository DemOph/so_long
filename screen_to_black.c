/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_to_black.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:00:26 by chael-ha          #+#    #+#             */
/*   Updated: 2021/09/29 14:25:28 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	screen_to_black(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < mlx->win.height)
	{
		j = 0;
		while (j < mlx->win.width)
		{
			my_mlx_pixel_put(&mlx->screen_img, j, i, 0x00000000);
			j++;
		}
		i++;
	}
}
