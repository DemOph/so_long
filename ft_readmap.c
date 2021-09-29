/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:25:00 by chael-ha          #+#    #+#             */
/*   Updated: 2021/09/29 18:57:03 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int	check_tmp(char **tmp, int j, char **lines)
{
	if (tmp)
	{
		while (tmp[j])
		{
			lines[j] = tmp[j];
			j++;
		}
	}
	free(tmp);
	return (j);
}

char	**get_map_lines(char **lines, char **tmp, int fd)
{
	char	*s;
	int		i;
	int		j;
	int		ret;

	ret = 1;
	i = 1;
	while (ret)
	{
		ret = get_next_line(fd, &s);
		tmp = lines;
		j = 0;
		lines = malloc((i + 1) * sizeof(char *));
		j = check_tmp(tmp, j, lines);
		lines[j++] = s;
		lines[j] = NULL;
		i++;
	}
	return (lines);
}

void	check_map_necessities(int i, int j, t_mlx *mlx)
{
	if (mlx->lines[i][j] == 'P')
	{
		mlx->player.player_count++;
		mlx->player.x = j;
		mlx->player.y = i;
	}
	else if (mlx->lines[i][j] == 'C')
		mlx->collectible++;
	else if (mlx->lines[i][j] == 'E')
		mlx->exi++;
}

int	check_map(char **map, t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'P' && map[i][j] != 'C' && map[i][j] != 'E'
					&& map[i][j] != '1' && map[i][j] != '0')
				ft_put_error("map contain weird characters!", mlx);
			if (map[i][j] != '0' && map[i][j] != '1')
				check_map_necessities(i, j, mlx);
			j++;
			mlx->nb_map_char++;
		}
		i++;
	}
	return (mlx->nb_map_char);
}

char	**ft_readmap(char *filename, t_mlx *mlx)
{
	int		fd;
	char	**tmp;

	tmp = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_put_error("MAP FILE IS NOWHERE TO BE FOUND", mlx);
	mlx->lines = get_map_lines(mlx->lines, tmp, fd);
	close(fd);
	init_param(mlx);
	check_map(mlx->lines, mlx);
	mlx->max_x = countx(mlx->lines);
	mlx->max_y = county(mlx->lines);
	mlx->win.height = mlx->max_x * SIZE;
	mlx->win.width = mlx->max_y * SIZE;
	is_map_valid(mlx);
	return (mlx->lines);
}
