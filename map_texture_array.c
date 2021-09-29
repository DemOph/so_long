/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_texture_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:40:15 by chael-ha          #+#    #+#             */
/*   Updated: 2021/09/29 14:35:15 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	map_texture_array(t_mlx *mlx, t_texture *text)
{
	t_texture	mapped_texture;
	float		ratio_x;
	float		ratio_y;
	int			i;
	int			j;

	ratio_x = (float)text->img_width / (float)SIZE;
	ratio_y = (float)text->img_height / (float)SIZE;
	i = -1;
	mapped_texture.img = mlx_new_image(mlx->win.mlx_ptr, SIZE, SIZE);
	mapped_texture.addr = mlx_get_data_addr(mapped_texture.img,
			&mapped_texture.bits_per_pixel, &mapped_texture.line_length,
			&mapped_texture.endian);
	while (++i < SIZE)
	{
		j = -1;
		while (++j < SIZE)
			my_mlx_pixel_put(&mapped_texture, i, j,
				((int *)text->addr)[(int)(j * ratio_y) *text->img_width
				+ (int)(i * ratio_x)]);
	}
	mlx_destroy_image(mlx->win.mlx_ptr, text->img);
	(*text) = mapped_texture;
}
