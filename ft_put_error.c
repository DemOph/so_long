/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:35:12 by chael-ha          #+#    #+#             */
/*   Updated: 2021/09/29 16:37:47 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int	delete_game(t_mlx *mlx)
{
	int	i;

	i = 0;
	if (mlx->lines)
	{
		while (mlx->lines[i])
		{
			free(mlx->lines[i]);
			i++;
		}
		free(mlx->lines);
	}
	exit(EXIT_SUCCESS);
}

void	ft_put_error(char *str, t_mlx *mlx)
{
	ft_putstr(str);
	delete_game(mlx);
}
