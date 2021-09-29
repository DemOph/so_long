/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:54:25 by chael-ha          #+#    #+#             */
/*   Updated: 2021/09/29 16:36:42 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	draw_map(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->lines[i])
	{
		j = 0;
		while (mlx->lines[i][j])
		{
			if (mlx->lines[i][j] == '1')
				mlx_put_image_to_window(mlx->win.mlx_ptr, mlx->win.win_ptr,
					mlx->w_text.img, j * SIZE, i * SIZE);
			else if (mlx->lines[i][j] == 'P')
				mlx_put_image_to_window(mlx->win.mlx_ptr, mlx->win.win_ptr,
					mlx->p_text.img, j * SIZE, i * SIZE);
			else if (mlx->lines[i][j] == 'C')
				mlx_put_image_to_window(mlx->win.mlx_ptr, mlx->win.win_ptr,
					mlx->c_text.img, j * SIZE, i * SIZE);
			else if (mlx->lines[i][j] == 'E')
				mlx_put_image_to_window(mlx->win.mlx_ptr, mlx->win.win_ptr,
					mlx->exit_text.img, j * SIZE, i * SIZE);
			j++;
		}
		i++;
	}
}
