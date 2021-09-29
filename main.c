/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:31:23 by chael-ha          #+#    #+#             */
/*   Updated: 2021/09/29 14:37:11 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	char	**s;

	if (argc > 2)
		ft_put_error("too much arguments\n", &mlx);
	s = ft_readmap(argv[1], &mlx);
	if (!s)
		ft_put_error("Error reading the map!\n", &mlx);
	mlx.win.mlx_ptr = mlx_init();
	mlx.win.win_ptr = mlx_new_window(mlx.win.mlx_ptr, mlx.win.width,
			mlx.win.height, "./so_long");
	mlx.screen_img.img = mlx_new_image(mlx.win.mlx_ptr, mlx.win.width,
			mlx.win.height);
	mlx.screen_img.addr = mlx_get_data_addr(mlx.screen_img.img,
			&mlx.screen_img.bits_per_pixel, &mlx.screen_img.line_length,
			&mlx.screen_img.endian);
	ft_load_ressources(&mlx);
	draw_map(&mlx);
	mlx_hook(mlx.win.win_ptr, 2, 1L << 0, key_press, &mlx);
	mlx_hook(mlx.win.win_ptr, 17, 1L << 0, ft_exit, &mlx);
	mlx_loop(mlx.win.mlx_ptr);
}
