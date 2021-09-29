/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:45:33 by chael-ha          #+#    #+#             */
/*   Updated: 2021/09/29 16:45:45 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	init_param(t_mlx *mlx)
{
	mlx->max_x = 0;
	mlx->max_y = 0;
	mlx->nb_map_char = 0;
	mlx->player.player_count = 0;
	mlx->collectible = 0;
	mlx->exi = 0;
	mlx->player.collect_ate = 0;
	mlx->player.exit6 = 0 ;
}
