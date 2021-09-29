/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:47:06 by chael-ha          #+#    #+#             */
/*   Updated: 2021/09/29 16:39:38 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int	ft_success(t_mlx *mlx)
{
	mlx_clear_window(mlx->win.mlx_ptr, mlx->win.win_ptr);
	mlx_put_image_to_window(mlx->win.mlx_ptr, mlx->win.win_ptr,
		mlx->screen_img.img, 0, 0);
	mlx_string_put(mlx->win.mlx_ptr, mlx->win.win_ptr, mlx->win.width / 2,
		mlx->win.height / 2, 0x008000, "YOU WIN!");
	mlx->player.exit6 = 1;
	return (0);
}

int	ft_move_player(t_mlx *mlx, int var_1, int var_2)
{
	if (mlx->lines[mlx->player.y + var_1][mlx->player.x + var_2] == 'E' &&
		mlx->player.collect_ate != mlx->collectible)
		return (0);
	if (mlx->lines[mlx->player.y + var_1][mlx->player.x + var_2] == 'E' &&
		mlx->player.collect_ate == mlx->collectible)
		return (ft_success(mlx));
	if (mlx->lines[mlx->player.y + var_1][mlx->player.x + var_2] == 'C')
		mlx->player.collect_ate++;
	if (mlx->lines[mlx->player.y + var_1][mlx->player.x + var_2] != '1')
	{
		mlx->lines[mlx->player.y + var_1][mlx->player.x + var_2] = 'P';
		mlx->lines[mlx->player.y][mlx->player.x] = '0';
		mlx->player.x = mlx->player.x + var_2;
		mlx->player.y = mlx->player.y + var_1;
		mlx->player.player_count++;
	}
	return (1);
}
