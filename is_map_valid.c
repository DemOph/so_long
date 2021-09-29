/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:49:02 by chael-ha          #+#    #+#             */
/*   Updated: 2021/09/29 18:58:44 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	is_map_rectang(t_mlx *mlx)
{
	if ((countx(mlx->lines) * county(mlx->lines)) != (mlx->nb_map_char))
		ft_put_error("Map is not rectangular!\n", mlx);
}

void	is_map_closed(t_mlx *mlx)
{
	int tmp;
	int i;

	i = 0;
	tmp = mlx->max_y;
	while(--tmp >= 0)
		if(mlx->lines[0][tmp] && mlx->lines[0][tmp] != '1')
			ft_put_error("Map not closed!\n", mlx);

	tmp = mlx->max_y;
	while(--tmp >= 0)
		if(mlx->lines[mlx->max_x - 1][tmp] &&
				mlx->lines[mlx->max_x - 1][tmp] != '1')
			ft_put_error("Map not closed!\n", mlx);

	i = 0;
	while (i < mlx->max_x)
		if (mlx->lines[i][0] &&
				mlx->lines[i++][0] != '1')
			ft_put_error("Map not closed!\n", mlx);

	i = 0;
	while (i < mlx->max_x)
		if (mlx->lines[i][mlx->max_y - 1] &&
				mlx->lines[i++][mlx->max_y - 1] != '1')
			ft_put_error("Map not closed!\n", mlx);
}

void	is_map_valid(t_mlx *mlx)
{
	is_map_rectang(mlx);
	if (!mlx->player.player_count || !mlx->collectible || !mlx->exi)
		ft_put_error("Map is invalid!\n", mlx);
	is_map_closed(mlx);
}
