/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:25:09 by chael-ha          #+#    #+#             */
/*   Updated: 2021/09/21 18:14:19 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#define FALSE	0
#define TRUE	1
#define	WINDOW_WIDTH	
#define	WINDOW_HEIGHT	1080
#define SIZE 42

int isGameRunning = FALSE;

typedef struct		s_window
{
	int				width;
	int				heigth;
	char			*title;
	void			*mlx_ptr;
	void			*win_ptr;
}                   t_window;

typedef	struct		s_mlx
{
	t_window		win;
	int				player;
	int				collectible;
	int				exi;
	char			**lines;
	int				max_x;
	int				max_y;
	int				nb_map_char;
}					t_mlx;



void 		init_param(t_mlx *mlx)
{
	mlx->max_x = 0;
	mlx->max_y= 0;
	mlx->nb_map_char = 0;
	mlx->player = 0;
	mlx->collectible = 0;
	mlx->exi = 0;
}