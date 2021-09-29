/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:43:40 by chael-ha          #+#    #+#             */
/*   Updated: 2021/09/29 16:43:26 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int	ft_load_texture(char *path, t_texture *text, t_mlx *mlx)
{
	text->img = mlx_xpm_file_to_image(mlx->win.mlx_ptr, path, &text->img_width,
			&text->img_height);
	if (!text->img)
		ft_put_error("Couldn't load the texture a zayn \\-/\n", mlx);
	text->addr = mlx_get_data_addr(text->img,
			&text->bits_per_pixel, &text->line_length, &text->endian);
	return (1);
}

void	ft_load_ressources(t_mlx *mlx)
{
	mlx->w_text.relative_path
		= "/Users/chael-ha/Desktop/texture/textures/grass.xpm";
	ft_load_texture(mlx->w_text.relative_path, &mlx->w_text, mlx);
	mlx->p_text.relative_path
		= "/Users/chael-ha/Desktop/so_long/textures/mc.xpm";
	ft_load_texture(mlx->p_text.relative_path, &mlx->p_text, mlx);
	mlx->c_text.relative_path
		= "/Users/chael-ha/Desktop/ft_cub 2/textures/bit.xpm";
	ft_load_texture(mlx->c_text.relative_path, &mlx->c_text, mlx);
	mlx->exit_text.relative_path
		= "/Users/chael-ha/Desktop/so_long/textures/exit.xpm";
	ft_load_texture(mlx->exit_text.relative_path, &mlx->exit_text, mlx);
	map_texture_array(mlx, &mlx->w_text);
	map_texture_array(mlx, &mlx->p_text);
	map_texture_array(mlx, &mlx->c_text);
	map_texture_array(mlx, &mlx->exit_text);
}
