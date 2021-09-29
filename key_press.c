/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 11:36:29 by chael-ha          #+#    #+#             */
/*   Updated: 2021/09/29 14:48:37 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int	ft_move(int keycode, t_mlx *mlx, int k)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == RIGHT_KEY && !mlx->player.exit6)
		k = ft_move_player(mlx, 0, 1);
	if (keycode == DOWN_KEY && !mlx->player.exit6)
		k = ft_move_player(mlx, 1, 0);
	if (keycode == UP_KEY && !mlx->player.exit6)
		k = ft_move_player(mlx, -1, 0);
	if (keycode == LEFT_KEY && !mlx->player.exit6)
		k = ft_move_player(mlx, 0, -1);
	return (k);
}

int	key_press(int keycode, t_mlx *mlx)
{
	int	k;

	k = 0;
	ft_putstr("\nplayer collect ate = ");
	ft_putnbr(mlx->player.collect_ate);
	if (keycode == LEFT_KEY || keycode == RIGHT_KEY || keycode == DOWN_KEY
		|| keycode == UP_KEY)
	{
		ft_putstr("\nplayer count =");
		ft_putnbr(mlx->player.player_count);
	}
	k = ft_move(keycode, mlx, k);
	if (k && !mlx->player.exit6)
	{
		screen_to_black(mlx);
		mlx_put_image_to_window(mlx->win.mlx_ptr, mlx->win.win_ptr,
			mlx->screen_img.img, 0, 0);
	}
	if (!mlx->player.exit6)
		draw_map(mlx);
	return (0);
}
